#include <iostream>
#include <string>
#include <tuple>
#include <Windows.h>
#include <cmath>

#include "key/key.hpp"
#include "clicker/clicker.hpp"
#include "prompts/prompts.hpp"
#include "colors/colors.hpp"

using namespace std;

int main() {
    tuple<char, char, char> keys;
    tuple<int, const char*> button;
    float delay;

    Key* key;
    Clicker clicker;
    Colors colors;

    colors.enable_vtp();

    keys = prompts(key);
    button = key -> get_mouse("Button to be autoclicked (press any mouse button): ");
    delete(key);
    
    cout << "Delay between clicks (in seconds): ";
    cin >> delay;

    delay *= 1000;

    cout << delay << endl;

    cout << "\n" << endl;
    cout << "Autoclicker start key is: " << get<0>(keys) << endl;
    cout << "Autoclicker stop key is: " << get<1>(keys) << endl;
    cout << "Program exit key is: " << get<2>(keys) << endl;
    cout << "Mouse button to be autoclicked is: " << get<1>(button) << endl;
    cout << "Delay between clicks is: " << delay/1000 << " seconds" << endl;
    cout << "\n" << endl;

    clicker.mouse_clicker(get<0>(keys), get<1>(keys), get<2>(keys), get<0>(button), delay);

    Sleep(1000);

    return '0';
}

