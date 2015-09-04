#include "stdafx.hpp"

#include "TreeModel.hpp"
#include "TreeModelView.hpp"

TreeModelView::TreeModelView(QWidget *parent)
	: QMainWindow(parent)
{
	splitter = new QSplitter(Qt::Vertical);

	edit = new QLineEdit;
	splitter->addWidget(edit);

	tree = new QTreeView;
	splitter->addWidget(tree);

	list = new QListView;
	splitter->addWidget(list);

	table = new QTableView;
	splitter->addWidget(table);

	setCentralWidget(splitter);

	filter = new KRecursiveFilterProxyModel(this);
	filter->setFilterRole(Qt::DisplayRole);
	filter->setFilterKeyColumn(-1);
	filter->setFilterCaseSensitivity(Qt::CaseInsensitive);

	connect(edit, SIGNAL(textChanged(const QString &)), filter, SLOT(setFilterFixedString(const QString &)));
}

void TreeModelView::setModel(QAbstractItemModel *model)
{
	filter->setSourceModel(model);

	tree->setModel(filter);
	tree->expandAll();

	KSelectionProxyModel *proxy = new KSelectionProxyModel(tree->selectionModel(), this);
	proxy->setSourceModel(filter);
	proxy->setFilterBehavior(KSelectionProxyModel::FilterBehavior::SubTreesWithoutRoots);

	list->setModel(proxy);
	table->setModel(proxy);

	tree->setRootIndex(filter->index(0, 0, QModelIndex()));
}
