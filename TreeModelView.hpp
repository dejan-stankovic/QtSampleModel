#pragma once

#include "stdafx.hpp"

class RecursiveFilterProxy : public KRecursiveFilterProxyModel
{
    Q_OBJECT
public:
    RecursiveFilterProxy(QObject *parent = 0) : KRecursiveFilterProxyModel(parent) {}

    void setRootIndex(const QModelIndex &root) { rootIndex = root; }
    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const;

private:
    QModelIndex rootIndex;
};

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

	RecursiveFilterProxy *filter;
};
