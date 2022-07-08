#include "UI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    FileRepo* rp=new FileRepo { "seba.txt" };
    Validator valid;
    Service srv{ rp ,valid};

    vector<GUI*>g;

   GUI app{ srv };
    /*for (int i = 0; i < srv.get_all_elev().size(); i++)
    {
        g.push_back(new GUI{ srv });
    }
    for (auto el : g) {
        el->show();
    }*/

   app.show();
   
    return QApplication::exec();
}
