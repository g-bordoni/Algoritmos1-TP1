#ifndef CLIENT
#define CLIENT


struct Client
{
    unsigned int id;
    int location[2];
    float ticket;
    int designated_shop_id;
};

#endif