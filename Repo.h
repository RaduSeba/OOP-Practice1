#pragma once
#include"Elevi.h"
#include"Observer.h"
#include <fstream>
#include <sstream>

class FileRepo:public Observable {
private:
	vector<Elev> e;
	string filename;
	void load_from_file();

public:

	FileRepo(string file);

	void add_elev(Elev el);

	vector<Elev>& get_all();

	void del(int poz);

};


class DuplicateElev {

private:
	string mesaj;

public:
	DuplicateElev(string m) :mesaj{ m } {};

	string getMessage() {
		return mesaj;
	}



};