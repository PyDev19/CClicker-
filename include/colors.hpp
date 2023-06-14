#ifndef COLORS_HPP
#define COLORS_HPP

class Colors {
    private:
        /* Normal Colors */
        const char* BLACK = "\033[30m";
        const char* RED = "\033[31m";
        const char* GREEN = "\033[32m";
        const char* YELLOW = "\033[33m";
        const char* BLUE = "\033[34m";
        const char* MAGENTA = "\033[35m";
        const char* CYAN = "\033[36m";
        const char* WHITE = "\033[37m";

        /* BRIGHT Colors*/
        const char* BRIGHT_BLACK = "\033[30;1m";
        const char* BRIGHT_RED = "\033[31;1m";
        const char* BRIGHT_GREEN = "\033[32;1m";
        const char* BRIGHT_YELLOW = "\033[33;1m";
        const char* BRIGHT_BLUE = "\033[34;1m";
        const char* BRIGHT_MAGENTA = "\033[35;1m";
        const char* BRIGHT_CYAN = "\033[36;1m";
        const char* BRIGHT_WHITE = "\033[37;1m";

    public:
        const char* RESET = "\033[0";
        const char* PREFERRED_PROMPT_COLOR = Colors::BLUE;
        const char* PREFERRED_INPUT_COLOR = Colors::YELLOW;
        const char* PREFERRED_PROCESS_STARTING_COLOR = Colors::CYAN;
        const char* PREFERRED_PROCESS_ENDING_COLOR = Colors::GREEN;
        const char* PREFERRED_ERROR_COLOR = Colors::RED;

        void enable_vtp();
        void color_print(const char* prompt, const char* color, const char* variable = "");
        void color_print(const char* prompt, const char* color, char variable = '\0');
        void color_print(const char* prompt, const char* color, float variable = 0);
        float color_input_print(const char* prompt, const char* color, float variable, const char* input_color);
};

#endif