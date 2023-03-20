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
    Colors* colors = new  Colors;

    colors->enable_vtp();

    std::tie(start_key, stop_key, exit_key) = prompts(key);
    std::tie(button_int, button_name) = key -> get_mouse("Button to be autoclicked (press any mouse button): ");
    delete key;
    
    delay = colors->color_input_print("Delay between clicks (in seconds): ", colors->PREFERRED_PROMPT_COLOR, delay, colors->PREFERRED_INPUT_COLOR);

    delay *= 1000;

    std::cout << "\n" << std::endl;
    colors->color_print("Autoclicker start key is: ", colors->PREFERRED_PROCESS_STARTING_COLOR, start_key);
    colors->color_print("Autoclicker stop key is: ", colors->PREFERRED_PROCESS_STARTING_COLOR, stop_key);
    colors->color_print("Autoclicker exit key is: ", colors->PREFERRED_PROCESS_STARTING_COLOR, exit_key);
    colors->color_print("Mouse button to be autoclicked is: ", colors->PREFERRED_PROCESS_STARTING_COLOR, button_name);
    colors->color_print("Delay between mouse clicks is: ", colors->PREFERRED_PROCESS_STARTING_COLOR, delay/1000);
    delete colors;
    std::cout << "\n" << std::endl;

    clicker -> mouse_clicker(start_key, stop_key, exit_key, button_int, delay);
    delete clicker;

    Sleep(1000);

    return '0';
}

