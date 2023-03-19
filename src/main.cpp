#include <iostream>
#include <string>
#include <Windows.h>

#include "key/key.hpp"
#include "clicker/clicker.hpp"
#include "prompts/prompts.hpp"
#include "colors/colors.hpp"

int main() {
    char start_key, stop_key, exit_key;
    int button_int; 
    const char* button_name;
    float delay;

    Key* key = new Key;
    Clicker* clicker = new Clicker;
    Colors colors;

    colors.enable_vtp();

    std::tie(start_key, stop_key, exit_key) = prompts(key);
    std::tie(button_int, button_name) = key -> get_mouse("Button to be autoclicked (press any mouse button): ");
    delete key;
    
    std::cout << "Delay between clicks (in seconds): ";
    std::cin >> delay;

    delay *= 1000;

    std::cout << "\n" << std::endl;
    std::cout << "Autoclicker start key is: " << start_key << std::endl;
    std::cout << "Autoclicker stop key is: " << stop_key << std::endl;
    std::cout << "Program exit key is: " << exit_key << std::endl;
    std::cout << "Mouse button to be autoclicked is: " << button_name << std::endl;
    std::cout << "Delay between clicks is: " << delay/1000 << " seconds" << std::endl;
    std::cout << "\n" << std::endl;

    clicker -> mouse_clicker(start_key, stop_key, exit_key, button_int, delay);
    delete clicker;

    Sleep(1000);

    return '0';
}

