#include "Elevi.h"


ostream& operator<<(ostream& out, const ValidationException& ex)
{
	for (const auto& mess : ex.msg) {
		out << mess << "\n";
	}
	return out;
}

bool has_letters(const string& s) {
	for (auto& ch : s) {
		if ('A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z') {
			return true;
		}
	}
	return false;
}


void Validator::validate(
	const string& c, 
	const string& n,
	const string& p, 
	const string& cl, 
	const double& m
	) {

	vector<string>errors;

	bool cod = has_letters(c);
	if (c.empty()) {
		errors.emplace_back("Codul trebuie sa existe");

	}
	else if (c.size()!=6) {
		errors.emplace_back("Codul trebuie sa aiba 6 cifre");

	}

	bool nume = has_letters(p);
	if (p.empty()) {
		errors.emplace_back("Numele nu poate fi vid");
	}
	if (!nume) {
		errors.emplace_back("Numele nu poate avea doar cifre");
	}
	if (!errors.empty()) {
		throw ValidationException(errors);
	}
}

string toMyString(vector<string> msg) {
	string ans = "";
	for (const auto& mg : msg) {
		ans += mg;
		ans += "\n";
	}
	return ans;
}

bool cmpClasa(const Elev& e1, const Elev& e2) {
	return e1.getClasa() < e2.getClasa();
}