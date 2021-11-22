#ifndef STABLEMATCHER
#define STABLEMATCHER

#include "Client.hpp"
#include "ClientList.hpp"
#include "Shop.hpp"
#include "ShopList.hpp"

namespace StableMatcher
{
    int distance (int* shop, int* client);
    void match (ShopList* shop_list, ClientList* client_list, int grid_size);
}


# endif