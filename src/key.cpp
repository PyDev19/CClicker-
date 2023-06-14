#include <iostream>
#include <conio.h>
#include <windows.h>
#include <tuple>

#include "key.hpp"
#include "colors.hpp"

char Key::get_key(const char* prompt) {
    Colors* color = new Colors;
    char user_input = '\0';
    
    std::cout << color->PREFERRED_PROMPT_COLOR << prompt;

    user_input = _getch();

    std::cout << color->PREFERRED_INPUT_COLOR << char(toupper(user_input)) << color->RESET << std::endl;

    delete color;

    return char(toupper(user_input));
}

std::tuple<int, const char*> Key::get_mouse(const char* prompt) {
    Colors* color = new Colors;

    std::cout << color->PREFERRED_PROMPT_COLOR << prompt;

    int user_input;
    const char* button_name;

    while (true) {
        if (GetAsyncKeyState(VK_LBUTTON)) {
            user_input = VK_LBUTTON;
            button_name = "Left Mouse Button";
            std::cout << color->PREFERRED_INPUT_COLOR << button_name << color->RESET << std::endl;
            delete color;
            break;
        
        } else if (GetAsyncKeyState(VK_RBUTTON)) {
            user_input = VK_RBUTTON;
            button_name = "Right Mouse Button";
            std::cout << color->PREFERRED_INPUT_COLOR << button_name << color->RESET << std::endl;
            delete color;
            break;
        
        } else if (GetAsyncKeyState(VK_MBUTTON)) {
            user_input = VK_MBUTTON;
            button_name = "Middle Mouse Button";
            std::cout << color->PREFERRED_INPUT_COLOR << button_name << color->RESET << std::endl;
            delete color;
            break;
        }
    }

    return {user_input, button_name};
}
