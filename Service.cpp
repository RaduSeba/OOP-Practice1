#include "Service.h"



Service::Service(FileRepo* r,Validator& v) {
	rp = r;
	valid = v;
}

vector<Elev>& Service::get_all_elev() {
	return rp->get_all();
}

void Service::adauga(const string& cod, const string& nume, const string& prenume, const string& clasa, double medie) {

	Validator::validate(cod, nume, prenume, clasa, medie);

	auto d = Elev(cod, nume, prenume, clasa, medie);
	rp->add_elev(d);
	notify();
}

void Service::sortbyclasa(vector<Elev>& res)
{
	res = rp->get_all();
	sort(res.begin(), res.end(), cmpClasa);
}
