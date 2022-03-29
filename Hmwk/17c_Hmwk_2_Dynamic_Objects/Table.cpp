/* 
 * File:   Table.cpp
 * Author: Michael Cooper
 * Created on March 28th, 2028, 2:00 PM
 */

#include "Table.h"
Table::Table(unsigned int rows,unsigned int cols){
    szRow=rows;
    szCol=cols;
    columns=new RowAray*[cols];
    for(int col=0;col<cols;col++){
        columns[col]=new RowAray(rows);
    }
}

Table::Table(const Table &a){
    //Student to supply
    szRow = a.getSzRow();
    szCol = a.getSzCol();
    columns = new RowAray*[a.getSzCol()];
    for(int col =0; col<a.getSzCol(); col++) {
        columns[col] = new RowAray(a.getSzRow());
        for(int row=0; row < a.getSzRow(); row++) {
            int val = a.getData(row, col);
            columns[col]->setData(row, val);
        }
    }
}

Table::~Table(){
    //Student to supply
    for(int i = 0; i < getSzCol(); i++)
        delete columns[i];
    delete[] columns;
}

int Table::getData(int row,int col)const{
    //Student to supply
    return columns[col]->getData(row);
}

void Table::setData(int row,int col,int val){
    //Student to supply
    columns[col]->setData(row, val);
}