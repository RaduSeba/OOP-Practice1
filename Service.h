#pragma once

#include "Repo.h"
#include <algorithm>


class Service:public Observable {

private:
	FileRepo* rp;
	Validator valid;
public:

	Service(FileRepo* r,Validator& val);

	vector<Elev>& get_all_elev();

	void adauga(const string& cod, const string& nume, const string& prenume, const string& clasa, double medie);

	void sortbyclasa(vector<Elev>& res);


};