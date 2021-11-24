#include "../include/StableMatcher.hpp"

int StableMatcher::distance (int* shop, int* client)
{
    int delta_x = abs(shop[0] - client[0]);
    int delta_y = abs(shop[1] - client[1]);
    int optimized_path = (delta_x > delta_y) ? delta_x : delta_y;

    return optimized_path;
}


void StableMatcher::match (ShopList* shop_list, ClientList* client_list, int grid_size)
{
    Client* client;
    Shop* shop;
    int minimum_distance;
    int shop_client_distance;

    int m, n;
    for (m = 0; m < client_list->length(); m++)
    {
        minimum_distance = grid_size;
        client = client_list->get(m);

        for (n = 0; n < shop_list->length(); n++)
        {
            shop = shop_list->get(n);

            if (shop->scheduled_products == shop->avilable_products) continue;

            shop_client_distance = StableMatcher::distance(shop->location, client->location);
            if (minimum_distance > shop_client_distance)
            {
                client->designated_shop_id = n;
                minimum_distance = shop_client_distance;
            }
                
        }

        if (client->designated_shop_id < 0)
            continue;

        shop = shop_list->get(client->designated_shop_id);
        shop->selected_clients_ids[shop->scheduled_products] = client->id;
        shop->scheduled_products += 1;
    }
}
