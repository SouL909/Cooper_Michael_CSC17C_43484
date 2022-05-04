
#ifndef TABLE_H
#define	TABLE_H

#include "RowAray.h"

template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template<class T>
inline Table<T>::Table(unsigned int rows,unsigned int cols){
    //Student to correct/complete
    szRow=rows;
    szCol=cols;
    columns=new RowAray<T>*[cols];
    for(int col=0;col<cols;col++)
        columns[col]=new RowAray<T>(rows);
}

template<class T>
inline Table<T>::Table(const Table &a){
    //Student to correct/complete
    szRow=a.getSzRow();
    szCol=a.getSzCol();
    columns=new RowAray<T>*[a.getSzCol()];
    for(int col=0; col<a.getSzCol(); col++){
        columns[col] = new RowAray<T>(a.getSzRow());
        for(int row=0; row < a.getSzRow(); row++){
            T val = a.getData(row, col);
            columns[col]->setData(row, val);
        }
    }
}

template<class T>
inline Table<T>::~Table(){
    //Student to correct/complete
    for(int i = 0; i < getSzCol(); i++)
        delete columns[i];
    delete[] columns;
}

template<class T>
inline T Table<T>::getData(int row,int col)const{
    //Student to correct/complete
    return columns[col]->getData(row);
}

template<class T>
inline void Table<T>::setData(int row,int col,T val){
    //Student to correct/complete
    columns[col]->setData(row, val);
}

template<class T>
inline Table<T> Table<T>::operator+(const Table<T> &a){
    //Student to correct/complete
    Table<T> c(a.getSzRow(), a.getSzCol());
    for(int i = 0; i < a.getSzCol(); i++) {
        for(int j = 0; j < a.getSzRow(); j++) {
            c.setData(j, i, a.getData(j, i) + this->getData(j,i));
        }
    }
    return c;
}

#endif	/* TABLE_H */