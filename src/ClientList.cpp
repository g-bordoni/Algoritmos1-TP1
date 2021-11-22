#include "../include/ClientList.hpp"


ClientList::ClientList(int size)
{
    this->size = size;
    this->list = new Client[size];
}

float ClientList::calculate_ticket(int age, std::string state, std::string purchase_mode)
{
    int score_purchase = BEGUIN_STEP_PURCHASE_MODES[0];
    int score_state = BEGUIN_STEP_STATES[0];

    int interator = 0;
    while (purchase_mode.compare(PURCHASE_MODES[interator]) != 0)
    {
        score_purchase += BEGUIN_STEP_PURCHASE_MODES[1];
        interator++;
    }

    interator = 0;
    while (state.compare(STATES[interator]) != 0)
    {
        score_state += BEGUIN_STEP_STATES[1];
        interator++;
    }

    return (float(abs(60 - age) + score_state)) / float(score_purchase);
}

void ClientList::insert(int id, int age, int lat, int lng, std::string state, std::string purchase_mode)
{
    Client* new_client = new Client();
    new_client->id = id;
    new_client->ticket = this->calculate_ticket(age, state, purchase_mode);
    new_client->designated_shop_id = -1;
    new_client->location[0] = lat; 
    new_client->location[1] = lng; 

    this->list[id] = *new_client;

    if (id == (this->size - 1))
        SortClients::merge_sort (this->list, 0, id);
}

Client* ClientList::get(int id)
{
    return &this->list[id];
}

int ClientList::length()
{
    return this->size;
}

ClientList::~ClientList()
{
    delete[] this->list;
}
