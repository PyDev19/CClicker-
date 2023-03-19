#ifndef CLICKER_HPP
#define CLICKER_HPP

#include <Windows.h>
#include <tuple>

using namespace std;

class Clicker {
    private:
        bool started, exit, printed_1, printed_2, printed_3, click;
        INPUT input;

    public:
        Clicker();
        void mouse_clicker(char start_key, char stop_key, char exit_key, int button, float delay);
};

#endif