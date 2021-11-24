#ifndef SHOPLIST
#define SHOPLIST

#include "Shop.hpp"

class ShopList
{
private:
    Shop* list;
    int size;
public:
    ShopList(int size);
    void insert(int id, int store, int lat, int lng);
    Shop* get(int index);
    int length();
    ~ShopList();
};


#endif