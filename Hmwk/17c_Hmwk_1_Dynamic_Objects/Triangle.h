#include "RowAray.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle{
    private:
        int szRow;
        RowAray **records;
    public:
        Triangle(int);  //Student to Complete
        ~Triangle();    //Student to Complete
        int getSzRow(){return szRow;}
        int getData(int,int);  //Student to Complete
};

#endif /* TRIANGLE_H */

