#include "Triangle.h"

Triangle::Triangle(int rows){
    //Student to complete
    szRow = rows;
    records = new RowAray*[rows];
    for(int i = 0; i < rows; i++)
        records[i] = new RowAray(i+1);
}

Triangle::~Triangle(){
    //Student to complete
    for(int i = 0; i < szRow; i++) {
        delete records[i];
    }
    delete[] records;
}

int Triangle::getData(int row,int col){
    //Student to complete
    return records[row]->getData(col);
}

