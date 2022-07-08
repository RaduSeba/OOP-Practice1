#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Elev {
private:
	string cod;
	string nume;
	string prenume;
	string clasa;
	double medie;
public:


	Elev() = default;

	Elev(string c, string n, string p, string cl, double m) :cod{ c }, nume{ n }, prenume{ p }, clasa{ cl }, medie{ m }{};


	string getCod() const{
		return cod;
	}

	string getNume() const {
		return nume;


	}

	string getPrenume() const {
		return prenume;
	}

	string getClasa() const {
		return clasa;
	}

	double getMedie() const {
		return medie;
	}



};


class ValidationException {

public:

	vector<string> msg;
	explicit ValidationException(const vector<string>& errors) :msg{ errors } {};
	friend ostream& operator<<(ostream& out, const ValidationException& ex);
};

ostream& operator<<(ostream& out, const ValidationException& ex);


class Validator {
public:

	static void validate(const string& c, const string& n, const string& p, const string& cl, const double& m);
};


bool has_letters(const string& s);
string toMyString(vector<string> msg);
bool cmpClasa(const Elev& e1, const Elev& e2);