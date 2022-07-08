#include "UI.h"


void GUI::init_GUI() {

	setLayout(lyMain);

	QWidget* w_left = new QWidget;
	QVBoxLayout* l_left = new QVBoxLayout;
	w_left->setLayout(l_left);

	lst_view->setUniformItemSizes(true);
	
	l_left->addWidget(lst_view);


	QWidget* wdg = new QWidget;
	QHBoxLayout* lay = new QHBoxLayout;
	wdg->setLayout(lay);

	addd = new QPushButton("Adauga elev");
	sort1 = new QPushButton("sorteaza dupa clasa");
	//sort2= new QPushButton("Sorteaza dupa medie");

	lay->addWidget(addd);
	lay->addWidget(sort1);
	//lay->addWidget(sort2);

	l_left->addWidget(wdg);

	QWidget* w_right = new QWidget;
	QVBoxLayout* lay_right = new QVBoxLayout;
	w_right->setLayout(lay_right);

	QWidget* form = new QWidget;
	QFormLayout* lay_form = new QFormLayout;
	form->setLayout(lay_form);

	QLabel* lbl_nume = new QLabel("Nume");
	QLabel* lbl_prenume = new QLabel("Prenume");
	QLabel* lbl_clasa = new QLabel("Clasa");
	QLabel* lbl_medie = new QLabel("Medie");

	txtNume = new QLineEdit;
	txtPrenume = new QLineEdit;
	txtClasa = new QLineEdit;
	txtMedie = new QLineEdit;
	

	lay_form->addRow(lbl_nume, txtNume);
	lay_form->addRow(lbl_prenume, txtPrenume);
	lay_form->addRow(lbl_clasa, txtClasa);
	lay_form->addRow(lbl_medie, txtMedie);

	lay_right->addWidget(form);

	reset = new QPushButton("Reset");

	gnew = new QPushButton("GUI nou");

	lay_right->addWidget(reset);
	lay_right->addWidget(gnew);

	lyMain->addWidget(w_left);
	lyMain->addWidget(w_right);
	//lyMain->addWidget(w_left);

}

void GUI::connectSignalSlots() {

	QObject::connect(lst_view->selectionModel(), &QItemSelectionModel::selectionChanged, [=]() {

		auto sel = lst_view->selectionModel();
		if (sel->selectedIndexes().empty()) {
			txtNume->setText("");
			txtPrenume->setText("");
			txtClasa->setText("");
			txtMedie->setText("");
		}

		auto sel_index = sel->selectedIndexes().at(0).row();
			auto elem = act_list[sel_index];
			auto nume = lst_view->model()->data(lst_view->model()->index(sel_index, 0), Qt::DisplayRole).toString();
			lb_index = sel_index;
			txtNume->setText(nume);
			txtPrenume->setText(QString::fromStdString(elem.getPrenume()));
			txtClasa->setText(QString::fromStdString(elem.getClasa()));
			txtMedie->setText(QString::number(elem.getMedie()));

		});


	QObject::connect(sort1, &QPushButton::clicked, [=]() {
		vector<Elev> ele;
		ele.resize(srv.get_all_elev().size());
		srv.sortbyclasa(ele);
		reloadList(ele);
		});


	QObject::connect(addd, &QPushButton::clicked, this, &GUI::addElev);

	QObject::connect(gnew, &QPushButton::clicked, [=]() {
		auto wind = new GUI{ srv };
		g.push_back(wind);
		wind->show();


		});





}


void GUI::reloadList(vector<Elev>& d) {

	act_list = d;
	model->setElev(d);
}


void GUI::addElev() {
	try {
		srv.adauga("111111", txtNume->text().toStdString(), txtPrenume->text().toStdString(), txtClasa->text().toStdString(), txtMedie->text().toInt());
		reloadList(srv.get_all_elev());
	}
	catch (ValidationException& ve) {
		QMessageBox::warning(this, "Warning", "elev invalid");
	}

}