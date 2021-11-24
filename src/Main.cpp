#include "../include/StableMatcher.hpp"
#include "../include/ShopList.hpp"
#include "../include/Shop.hpp"
#include "../include/ClientList.hpp"
#include "../include/Client.hpp"
#include <string>
#include <iostream>
#include <fstream>


std::string* split (std::string original, int expected_size)
{
/*
    Split a string in an array of length equals to the expected size
*/
    std::string space = " ";
    int original_size = original.size();
    int current_index = 0;

    std::string* splited_result = new std::string[expected_size];
    std::string character;
    std::string splited_word = "";
    for (int i = 0; i < original_size; i++)
    {
        character = original[i];
        if (space.compare(character) == 0)
        {
            splited_result[current_index] = splited_word;
            splited_word = "";
            current_index++;
            continue;
        }
        splited_word.append(character);
        
    }
    splited_result[current_index] = splited_word;
    return splited_result;
}


int main (int argc, char* argv[])
{
    std::string filename(argv[1]);
    std::fstream input_file(filename);

    if (!input_file.is_open())
        throw "ERROR: Openning file has failed.";
    
    std::string line;

    std::getline(input_file, line);
    std::string* grid_line = split(line, 2);

    std::getline(input_file, line);
    ShopList shop_list = ShopList(std::stoi(line));

    std::string* insert_variables;
    for (int i = 0; std::getline(input_file, line) && i < shop_list.length(); i++)
    {
        insert_variables = split(line, 3);
        shop_list.insert(i, std::stoi(insert_variables[0]), std::stoi(insert_variables[1]), std::stoi(insert_variables[2]));
        delete[] insert_variables;
    }

    ClientList client_list = ClientList(std::stoi(line));

    for (int j = 0; std::getline(input_file, line) && j < client_list.length(); j++)
    {
        insert_variables = split(line, 5);
        client_list.insert(j, std::stoi(insert_variables[0]), std::stoi(insert_variables[3]), std::stoi(insert_variables[4]), insert_variables[1], insert_variables[2]);
        delete[] insert_variables;
    }

    input_file.close();

    int grid_larger_size = (grid_line[0] > grid_line[1]) ? std::stoi(grid_line[0]) : std::stoi(grid_line[1]);
    StableMatcher::match(&shop_list, &client_list, grid_larger_size);
    delete[] grid_line;

    Shop* shop;
    for (int i = 0; i < shop_list.length(); i++)
    {
        shop = shop_list.get(i);
        std::cout << shop->id << std::endl;
        for (int k = 0; k < shop->scheduled_products; k++)
        {   
            if (k == 0) std::cout << shop->selected_clients_ids[k];
            else std::cout << " " << shop->selected_clients_ids[k];
        }
        std::cout << std::endl;
    }


    return 0;
}
