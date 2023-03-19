#include <iostream>
#include <string>
#include <Windows.h>

#include "key/key.hpp"
#include "clicker/clicker.hpp"
#include "prompts/prompts.hpp"
#include "colors/colors.hpp"

using namespace std;

int main() {
    char start_key, stop_key, exit_key;
    int button_int; 
    const char* button_name;
    float delay;

    Key* key = new Key;
    Clicker clicker;
    Colors colors;

    colors.enable_vtp();

    tie(start_key, stop_key, exit_key) = prompts(key);
    tie(button_int, button_name) = key -> get_mouse("Button to be autoclicked (press any mouse button): ");
    delete key;
    
    cout << "Delay between clicks (in seconds): ";
    cin >> delay;

    delay *= 1000;

    cout << "\n" << endl;
    cout << "Autoclicker start key is: " << start_key << endl;
    cout << "Autoclicker stop key is: " << stop_key << endl;
    cout << "Program exit key is: " << exit_key << endl;
    cout << "Mouse button to be autoclicked is: " << button_name << endl;
    cout << "Delay between clicks is: " << delay/1000 << " seconds" << endl;
    cout << "\n" << endl;

    clicker.mouse_clicker(start_key, stop_key, exit_key, button_int, delay);

    Sleep(1000);

    return '0';
}

