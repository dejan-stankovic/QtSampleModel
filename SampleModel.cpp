#include "global.hpp"

#include "SampleModel.hpp"
#include "moc_SampleModel.cpp"

////////////////////////////////////////////////////////////////////////////////

SampleModel::SampleModel()
{
	for (size_t i = 0; i < 1024; i++)
		masters[i] = QString("Master%1").arg(i);

	dataUpdater.start(1000);
	connect(&dataUpdater, SIGNAL(timeout()), this, SLOT(onDataUpdate()));

	connect(&dataChangedNofifier, SIGNAL(timeout()), this, SLOT(onDataChangedNotify()));
}

SampleModel::~SampleModel()
{
}

QModelIndex SampleModel::index(int row, int column, const QModelIndex &parent) const
{
	printf("index %d %d\n", row, column);

	if (!parent.isValid()) {
		if (column == SampleModel::ColumnActions)
			return createIndex(row, 0, row);
	}
	return QModelIndex();
}

QModelIndex SampleModel::parent(const QModelIndex &child) const
{
	return QModelIndex();
}

int SampleModel::rowCount(const QModelIndex &parent) const
{
	if (!parent.isValid())
		return masters.count();
	return 0;
}

int SampleModel::columnCount(const QModelIndex &parent) const
{
	return 1;
}

QVariant SampleModel::data(const QModelIndex &index, int role) const
{
	if (index.parent().isValid() == false) {
		if (role == Qt::DisplayRole)
			return QVariant(masters[index.row()]);
	}
	return QVariant();
}

bool SampleModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (index.parent().isValid() == false) {
		if (role == Qt::DisplayRole) {
			masters[index.row()] = value.toString();
			if (dataChangedNofifier.isActive() == false)
				dataChangedNofifier.start(1000);
			return true;
		}
	}
	return false;
}

void SampleModel::onDataUpdate()
{
	for (int i = 0; i < masters.count(); i++) {
		QModelIndex idx = index(i, 0, QModelIndex());
		setData(idx, QString("Master%1 -- %2").arg(i).arg(QTime::currentTime().toString()), Qt::DisplayRole);
	}
}

void SampleModel::onDataChangedNotify()
{
	emit dataChanged(QModelIndex(), QModelIndex());
}

////////////////////////////////////////////////////////////////////////////////

SampleModelView::SampleModelView()
{
	model = new SampleModel;

	list = new QListView;
	list->setModel(model);

	tree = new QTreeView;
	tree->setModel(model);

	QSplitter *splitter = new QSplitter;
	splitter->addWidget(list);
	splitter->addWidget(tree);
	setCentralWidget(splitter);
}

SampleModelView::~SampleModelView()
{
}
