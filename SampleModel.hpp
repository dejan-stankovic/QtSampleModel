#pragma once

#include "global.hpp"

class SampleModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	SampleModel();
	~SampleModel();

	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	QModelIndex parent(const QModelIndex &child) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

private:
	QMap<int, QString> masters;

	enum {
		ColumnActions = 0,
		ColumnControls,
	};

	QTimer dataUpdater;
	QTimer dataChangedNofifier;

private slots:
	void onDataUpdate();
	void onDataChangedNotify();
};

class SampleModelView : public QMainWindow
{
	Q_OBJECT
public:
	SampleModelView();
	~SampleModelView();

private:
	QListView *list;
	QTreeView *tree;

	SampleModel *model;
};
