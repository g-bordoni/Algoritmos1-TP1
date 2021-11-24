#ifndef CLIENTLIST
#define CLIENTLIST

#include "Client.hpp"
#include <string>
#include "SortClients.hpp"

const std::string STATES[] = {"MG", "PR", "SP", "SC", "RJ", "RN", "RS"};
const int BEGIN_STEP_STATES[] = {0, 10};
const std::string PURCHASE_MODES[] = {"DINHEIRO", "DEBITO", "CREDITO"};
const int BEGIN_STEP_PURCHASE_MODES[] = {1, 1};


class ClientList
{
private:
    Client* list;
    int size;
    float calculate_ticket(int age, std::string state, std::string purchase_mode);
public:
    ClientList(int size);
    void insert(int id, int age, int lat, int lng, std::string state, std::string purchase_mode);
    Client* get(int index);
    int length();
    ~ClientList();
};


#endif