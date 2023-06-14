#include <iostream>
#include <windows.h>
#include <tuple>

#include "clicker.hpp"
#include "colors.hpp"

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
    Colors* color = new Colors;

    while (true) {
        if (printed_1 != true) {
            color->color_print("Autoclicker Running", color->PREFERRED_PROCESS_ENDING_COLOR, "");
            std::cout << "\n" << std::endl;
            printed_1 = true;
        }

        if (GetAsyncKeyState(start_key) & 0x8000 && started == false) {
            if (printed_2 != true) {
                color->color_print("Autoclicker Started", color->PREFERRED_PROCESS_STARTING_COLOR, "");
                printed_2 = true;
            }
            printed_3 = false;

			click = true;
            started = true;
		} else if (GetAsyncKeyState(stop_key) & 0x8000 && started == true) {
            if (printed_3 != true) {
                color->color_print("Autoclicker Stopped", color->PREFERRED_PROCESS_ENDING_COLOR, "");
                printed_3 = true;
            }
            printed_2 = false;

            click = false;
            started = false;
		} else if (GetAsyncKeyState(exit_key) & 0x8000) {
            color->color_print("Exiting Program", color->PREFERRED_ERROR_COLOR, "");
            click = false;
            break;
        }

		if (click == true) {
            switch (button) {
                case 1:
                    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                    break;
                case 2:
                    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
                    break;
                case 4:
                    input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
                    break;
            }
			SendInput(1, &input, sizeof(INPUT));

            switch (button) {
                case 1:
                    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                    break;
                case 2:
                    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
                    break;
                case 4:
                    input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
                    break;
            }
            SendInput(1, &input, sizeof(INPUT));

            Sleep(delay);
		}
    }

    delete color;
};
