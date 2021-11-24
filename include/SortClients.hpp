#ifndef SORTCLIENTS
#define SORTCLIENTS

#include "Client.hpp"

namespace SortClients
{
    void merge(Client* client_array, int begin, int middle, int end);
    void merge_sort(Client* client_array, int begin, int end);
};

#endif