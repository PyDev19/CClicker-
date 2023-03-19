#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <tuple>
#include <string>

#include "key.hpp"

using namespace std;

char Key::get_key(const char* prompt) {
    cout << prompt;

    char user_input = _getch();

    cout << char(toupper(user_input)) << endl;

    return char(toupper(user_input));
}

tuple<int, const char*> Key::get_mouse(const char* prompt) {
    cout << prompt;

    int user_input;
    const char* button_name;

    while (true) {
        if (GetAsyncKeyState(VK_LBUTTON)) {
            user_input = VK_LBUTTON;
            button_name = "Left Mouse Button";
            cout << button_name << endl;
            break;
        
        } else if (GetAsyncKeyState(VK_RBUTTON)) {
            user_input = VK_RBUTTON;
            button_name = "Right Mouse Button";
            cout << button_name << endl;
            break;
        
        } else if (GetAsyncKeyState(VK_MBUTTON)) {
            user_input = VK_MBUTTON;
            button_name = "Middle Mouse Button";
            cout << button_name << endl;
            break;
        }
    }

    return {user_input, button_name};
}
