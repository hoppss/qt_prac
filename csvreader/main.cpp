#include "csvreader.h"



int main(){
    CSVReader  cr("motion1",31);

    cout << "total lines: " <<  cr.getAllLineSize() << endl;
    cr.display();

    cout << "\n\n\n";

    cr.processdata(7,100);
    cr.saveToFile("newdata");

    return 0;
}
