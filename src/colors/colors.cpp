#include <iostream>
#include <Windows.h>
#include "colors.hpp"

void Colors::enable_vtp() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hConsole, &dwMode);
    SetConsoleMode(hConsole, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void Colors::color_print(const char* prompt, const char* color, const char* variable) {
    const char* COLOR = nullptr;
    
    if (color == PREFERRED_PROMPT_COLOR) {
        COLOR = PREFERRED_PROMPT_COLOR;
    } else if (color == PREFERRED_INPUT_COLOR) {
        COLOR = PREFERRED_INPUT_COLOR;
    } else if (color == PREFERRED_PROCESS_STARTING_COLOR) {
        COLOR = PREFERRED_PROCESS_STARTING_COLOR;
    } else if (color == PREFERRED_PROCESS_ENDING_COLOR) {
        COLOR = PREFERRED_PROCESS_ENDING_COLOR;
    } else if (color == PREFERRED_ERROR_COLOR) {
        COLOR = PREFERRED_ERROR_COLOR;
    } else {
        std::cout << PREFERRED_ERROR_COLOR << "Please select one of the preffered colors from colors class" << RESET << std::endl;
    }

    if (variable == "") {
        delete variable;
        std::cout << COLOR << prompt << RESET << std::endl;
    } else {
        std::cout << COLOR << prompt << variable << RESET << std::endl;
    }
}

void Colors::color_print(const char* prompt, const char* color, char variable) {
    const char* COLOR = nullptr;
    
    if (color == PREFERRED_PROMPT_COLOR) {
        COLOR = PREFERRED_PROMPT_COLOR;
    } else if (color == PREFERRED_INPUT_COLOR) {
        COLOR = PREFERRED_INPUT_COLOR;
    } else if (color == PREFERRED_PROCESS_STARTING_COLOR) {
        COLOR = PREFERRED_PROCESS_STARTING_COLOR;
    } else if (color == PREFERRED_PROCESS_ENDING_COLOR) {
        COLOR = PREFERRED_PROCESS_ENDING_COLOR;
    } else if (color == PREFERRED_ERROR_COLOR) {
        COLOR = PREFERRED_ERROR_COLOR;
    } else {
        std::cout << PREFERRED_ERROR_COLOR << "Please select one of the preffered colors from colors class" << RESET << std::endl;
    }

    if (variable == '\0') {
        std::cout << COLOR << prompt << RESET << std::endl;
    } else {
        std::cout << COLOR << prompt << variable << RESET << std::endl;
    }
}

void Colors::color_print(const char* prompt, const char* color, float variable) {
    const char* COLOR = nullptr;
    
    if (color == PREFERRED_PROMPT_COLOR) {
        COLOR = PREFERRED_PROMPT_COLOR;
    } else if (color == PREFERRED_INPUT_COLOR) {
        COLOR = PREFERRED_INPUT_COLOR;
    } else if (color == PREFERRED_PROCESS_STARTING_COLOR) {
        COLOR = PREFERRED_PROCESS_STARTING_COLOR;
    } else if (color == PREFERRED_PROCESS_ENDING_COLOR) {
        COLOR = PREFERRED_PROCESS_ENDING_COLOR;
    } else if (color == PREFERRED_ERROR_COLOR) {
        COLOR = PREFERRED_ERROR_COLOR;
    } else {
        std::cout << PREFERRED_ERROR_COLOR << "Please select one of the preffered colors from colors class" << RESET << std::endl;
    }

    if (variable == 0) {
        std::cout << COLOR << prompt << RESET << std::endl;
    } else {
        std::cout << COLOR << prompt << variable << RESET << std::endl;
    }
}

float Colors::color_input_print(const char* prompt, const char* color, float variable, const char* input_color) {
    const char* COLOR = nullptr;
    const char* INPUT_COLOR = nullptr;

    if (color == PREFERRED_PROMPT_COLOR) {
        COLOR = PREFERRED_PROMPT_COLOR;
    } else if (color == PREFERRED_INPUT_COLOR) {
        COLOR = PREFERRED_INPUT_COLOR;
    } else if (color == PREFERRED_PROCESS_STARTING_COLOR) {
        COLOR = PREFERRED_PROCESS_STARTING_COLOR;
    } else if (color == PREFERRED_PROCESS_ENDING_COLOR) {
        COLOR = PREFERRED_PROCESS_ENDING_COLOR;
    } else if (color == PREFERRED_ERROR_COLOR) {
        COLOR = PREFERRED_ERROR_COLOR;
    } else {
        std::cout << PREFERRED_ERROR_COLOR << "Please select one of the preffered colors from colors class" << RESET << std::endl;
    }

    if (input_color == PREFERRED_PROMPT_COLOR) {
        INPUT_COLOR = PREFERRED_PROMPT_COLOR;
    } else if (input_color == PREFERRED_INPUT_COLOR) {
        INPUT_COLOR = PREFERRED_INPUT_COLOR;
    } else if (input_color == PREFERRED_PROCESS_STARTING_COLOR) {
        INPUT_COLOR = PREFERRED_PROCESS_STARTING_COLOR;
    } else if (input_color == PREFERRED_PROCESS_ENDING_COLOR) {
        INPUT_COLOR = PREFERRED_PROCESS_ENDING_COLOR;
    } else if (input_color == PREFERRED_ERROR_COLOR) {
        INPUT_COLOR = PREFERRED_ERROR_COLOR;
    } else {
        std::cout << PREFERRED_ERROR_COLOR << "Please select one of the preffered colors from colors class" << RESET << std::endl;
    }

    std::cout << COLOR << prompt << INPUT_COLOR;
    std::cin >> variable; std::cout << RESET;

    return variable;
}
