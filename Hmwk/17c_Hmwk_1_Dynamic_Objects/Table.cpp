#include "Table.h"

Table::Table(int rows,int cols){
    //Student to complete
    szRow = rows;
    szCol = cols;
    records = new RowAray*[szRow];
    for(int i = 0; i < szRow; i++) {
        records[i] = new RowAray(cols);
    }
}

Table::~Table(){
    //Student to complete
    for(int i = 0; i < szRow; i++) {
        delete records[i];
    }
    delete[] records;
}

int Table::getData(int row,int col){
   //Student to complete
   return records[row]->getData(col);
}
