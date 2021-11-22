#include "../include/ShopList.hpp"


ShopList::ShopList(int size)
{
    this->size = size;
    this->list = new Shop[size];
}

void ShopList::insert(int id, int store, int lat, int lng)
{
    Shop* new_shop = new Shop();
    new_shop->id = id;
    new_shop->avilable_products = store;
    new_shop->scheduled_products = 0;
    new_shop->selected_clients_ids = new int[store];
    new_shop->location[0] = lat; 
    new_shop->location[1] = lng; 

    this->list[id] = *new_shop;
}

Shop* ShopList::get(int id)
{
    return &this->list[id];
}

int ShopList::length()
{
    return this->size;
}

ShopList::~ShopList()
{
    for(int i = 0; i < this->size; i++)
        delete[] this->list[i].selected_clients_ids;
    delete[] this->list;
}
