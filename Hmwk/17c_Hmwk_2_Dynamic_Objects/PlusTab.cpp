/* File:   PlusTab.cpp
 * Author: Michael Cooper
 * Created on March 28th, 2028, 2:00 PM
 * Table Addition Operator
 */

#include "PlusTab.h"

PlusTab PlusTab::operator+(const PlusTab &a){
    //Student to supply
    PlusTab c(a.getSzRow(), a.getSzCol());
    for(int i = 0; i < a.getSzCol(); i++) {
        for(int j = 0; j < a.getSzRow(); j++) {
            c.setData(j, i, a.getData(j, i) + this->getData(j,i));
        }
    }
    return c;
}