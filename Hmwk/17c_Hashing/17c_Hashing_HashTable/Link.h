#ifndef LINK_H
#define LINK_H

template<class T>
struct Link{
    T data;     //Some type of data
    Link<T> *lnkNext; //Next Link in the chain
    Link<T> *lnkPrev; //Prev Link in the chain
};

#endif // LINK_H