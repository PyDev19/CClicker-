#include <iostream>
#include <Windows.h>
#include <tuple>

#include "clicker.hpp"

using namespace std;

Clicker::Clicker() {
    started = false;
    exit = false;

    printed_1 = false;
    printed_2 = false;
    printed_3 = false;

    click = false;

    input = {0};
};

void Clicker::mouse_clicker(char start_key, char stop_key, char exit_key, int button, float delay) {
    input.type = INPUT_MOUSE;

    while (true) {
        if (printed_1 != true) {
            cout << "Autoclicker Running" << endl;
            printed_1 = true;
        }

        if (GetAsyncKeyState(start_key) & 0x8000 && started == false) {
            if (printed_2 != true) {
                cout << "Autoclicker Started" << endl;
                printed_2 = true;
            }
            printed_3 = false;

			click = true;
            started = true;
		} else if (GetAsyncKeyState(stop_key) & 0x8000 && started == true) {
            if (printed_3 != true) {
                cout << "Autoclicker Stopped" << endl;
                printed_3 = true;
            }
            printed_2 = false;

            click = false;
            started = false;
		} else if (GetAsyncKeyState(exit_key) & 0x8000) {
            cout << "Exiting Program" << endl;
            click = false;
            break;
        }

		if (click == true) {
            if (button == 1) {
                input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            
            } else if (button == 2) {
                input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
            
            } else if (button == 4) {
                input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
            }
			SendInput(1, &input, sizeof(INPUT));

            if (button == 1) {
                input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            
            } else if (button == 2) {
                input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
            
            } else if (button == 4) {
                input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
            }
            SendInput(1, &input, sizeof(INPUT));

            Sleep(delay);
		}
    }
};
