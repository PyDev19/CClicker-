#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <tuple>

#include "key.hpp"

char Key::get_key(const char* prompt) {
    std::cout << prompt;

    char user_input = _getch();

    std::cout << char(toupper(user_input)) << std::endl;

    return char(toupper(user_input));
}

std::tuple<int, const char*> Key::get_mouse(const char* prompt) {
    std::cout << prompt;

    int user_input;
    const char* button_name;

    while (true) {
        if (GetAsyncKeyState(VK_LBUTTON)) {
            user_input = VK_LBUTTON;
            button_name = "Left Mouse Button";
            std::cout << button_name << std::endl;
            break;
        
        } else if (GetAsyncKeyState(VK_RBUTTON)) {
            user_input = VK_RBUTTON;
            button_name = "Right Mouse Button";
            std::cout << button_name << std::endl;
            break;
        
        } else if (GetAsyncKeyState(VK_MBUTTON)) {
            user_input = VK_MBUTTON;
            button_name = "Middle Mouse Button";
            std::cout << button_name << std::endl;
            break;
        }
    }

    return {user_input, button_name};
}
