#pragma once

#include <set>
#include <QWidget>
#include <QListWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QTableWidget>
#include <QPainter>
#include <QSlider>
#include "Service.h"
#include "Model.h"

class GUI : public QWidget,public Observer {

private:

	vector<Elev> act_list;

	Validator v;
	Service srv;

	QListWidget* lst = new QListWidget;

	QListView* lst_view = new QListView;
	MyListModel* model;
	vector<GUI*>g;

	QPushButton* sort1;
	QPushButton* sort2;
	QPushButton* addd;
	QPushButton* reset;
	QPushButton* gnew;

	QHBoxLayout* lyMain = new QHBoxLayout;

	QWidget* opt_but;

	QLineEdit* txtCod;
	QLineEdit* txtNume;
	QLineEdit* txtPrenume;
	QLineEdit* txtClasa;
	QLineEdit* txtMedie;

	int lb_index;

	void init_GUI();
	void connectSignalSlots();
	void reloadList(vector<Elev>& dis);
	void update() override {
		reloadList(srv.get_all_elev());
	}

	void addElev();

public:
	GUI(Service& srv) :srv{ srv } {

		srv.addObs(this);
		init_GUI();
		model = new MyListModel(srv.get_all_elev());
		lst_view->setModel(model);
		connectSignalSlots();
		reloadList(srv.get_all_elev());
		act_list = srv.get_all_elev();
		/*for (int i = 0; i < srv.get_all_elev().size(); i++)
		{
			g.push_back(new GUI{ srv });
			g[i]->show();
		}*/


	}

	~GUI() {
		srv.rmObs(this);
	}



};