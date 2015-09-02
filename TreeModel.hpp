#pragma once

#include "stdafx.hpp"

class TreeItem
{
public:
	explicit TreeItem(const QList<QVariant> &data, TreeItem *parentItem = 0);
	~TreeItem();

	void appendChild(TreeItem *child);

	TreeItem *child(int row);
	int childCount() const;
	int columnCount() const;
	QVariant data(int column) const;
	int row() const;
	TreeItem *parentItem();

private:
	QList<TreeItem*> m_childItems;
	QList<QVariant> m_itemData;
	TreeItem *m_parentItem;
};

class TreeModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	explicit TreeModel(const QString &data, QObject *parent = 0);
	~TreeModel();

	QVariant data(const QModelIndex &index, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	QModelIndex parent(const QModelIndex &index) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;

private:
	void setupModelData(const QStringList &lines, TreeItem *parent);

	TreeItem *rootItem;
};
