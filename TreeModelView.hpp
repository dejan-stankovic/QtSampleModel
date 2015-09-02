#pragma once

#include "stdafx.hpp"

class TreeModelView : public QMainWindow
{
	Q_OBJECT
public:
	explicit TreeModelView(QWidget *parent = 0);

	void setModel(QAbstractItemModel *model);
private:
	QSplitter *splitter;

	QLineEdit *edit;
	QTreeView *tree;
	QTableView *table;
	QListView *list;

	QSortFilterProxyModel *filter;
};
