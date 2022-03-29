#include "RowAray.h"

#ifndef TABLE_H
#define TABLE_H

class Table{
    private:
        int szRow;
        int szCol;
        RowAray **records;
    public:
        Table(int,int);  //Student to Complete
        ~Table();        //Student to Complete
        int getSzRow(){return szRow;}
        int getSzCol(){return szCol;}
        int getData(int,int); //Student to Complete
};

#endif /* TABLE_H */

