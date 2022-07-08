#include "Repo.h"

FileRepo::FileRepo(string file) {
	filename = file;
	load_from_file();
}

double to_nr(string str) {
    int ip, fp, l;
    ip = fp = 0;
    l = 1;
    bool point = false;
    for (auto ch : str) {
        if (ch == '.') {
            point = true;
        }
        else if ('0' <= ch && ch <= '9') {
            if (!point) {
                ip = ip * 10 + (ch - '0');
            }
            else {
                fp = fp * 10 + (ch - '0');
                l = l * 10;
            }
        }
    }
    return (double)ip + (double)fp / l;
}

void FileRepo::load_from_file() {
    ifstream fin(filename);
    string line;
    while (getline(fin, line)) {
        stringstream s_line(line);
        string buffer;
        vector<string> all;
        while (getline(s_line, buffer, ';')) {
            all.push_back(buffer);
        }
        add_elev(Elev(all[0], all[1], all[2], all[3], to_nr(all[4])));
    }
}

void FileRepo::add_elev(Elev el) {
    e.push_back(el);
    
}

vector<Elev>& FileRepo::get_all()
{
    return e;
}


void FileRepo::del(int poz) {
    e.erase((e.begin() + poz));
}

