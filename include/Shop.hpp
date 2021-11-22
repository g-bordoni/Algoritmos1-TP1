#ifndef SHOP
#define SHOP


struct Shop
{
    unsigned int id;
    int location[2];
    int avilable_products;
    int scheduled_products;
    int* selected_clients_ids;
};



#endif