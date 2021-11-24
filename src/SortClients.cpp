#include "../include/Client.hpp"
#include "../include/SortClients.hpp"


void SortClients::merge (Client* client_array, int begin, int middle, int end)
{
    int left_array_size = middle - begin + 1;
    int right_array_size = end - middle;
    Client* left_array = new Client[left_array_size];
    Client* right_array = new Client[right_array_size];

    int i,j,k;
    for (i = 0; i < left_array_size; i++)
        left_array[i] = client_array[begin + i];
    for (j = 0; j < right_array_size; j++)
        right_array[j] = client_array[middle + j + 1];

    i = 0; j =0;
    k = begin;
    while (i < left_array_size && j < right_array_size)
    {
        if (left_array[i].ticket >= right_array[j].ticket)
        {
            client_array[k] = left_array[i];
            i++;
        } 
        else 
        {
            client_array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < left_array_size)
    {
        client_array[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_array_size)
    {
        client_array[k] = right_array[j];
        j++;
        k++;
    }

    delete[] left_array;
    delete[] right_array;   
}

void SortClients::merge_sort (Client* client_array, int begin, int end)
{
    if (begin < end)
    {
        int medium = (begin + end) / 2;
        SortClients::merge_sort (client_array, begin, medium);
        SortClients::merge_sort (client_array, medium + 1, end);
        SortClients::merge (client_array, begin, medium, end);
    }
}
