#pragma once
#include <QAbstractTableModel>
#include "Elevi.h"
#include <vector>

using namespace std;

class MyListModel :public QAbstractListModel {
	vector<Elev> dis;
public:
	MyListModel(const vector<Elev>& d) : dis{ d } {}



	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return dis.size();
	}


	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override {
		if (role == Qt::DisplayRole) {
			auto cod = dis[index.row()].getCod();
			auto nume = dis[index.row()].getNume();
			return QString::fromStdString(cod) +" "+ QString::fromStdString(nume);
		}
		return QVariant{};
	}

	void setElev(vector<Elev>& d) {
		dis = d;
		auto topIndex = createIndex(0, 0);
		auto botIndex = createIndex(rowCount(), 0);
		emit dataChanged(topIndex, botIndex);
	}


};
