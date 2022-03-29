
#ifndef ROWARAY_H
#define ROWARAY_H

class RowAray{
    private:
        int size;
        int *rowData;
        int mrkRand(int);
    public:
        RowAray(int);   //Student to Complete
        ~RowAray();     //Student to Complete
        int getSize(){return size;}
        int getData(int i){return rowData[i];}
};

#endif /* ROWARAY_H */

