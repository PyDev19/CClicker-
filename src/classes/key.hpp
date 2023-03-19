#ifndef KEY_HPP
#define KEY_HPP

#include <tuple>
using namespace std;

class Key {
    public:
        char get_key(const char* prompt);
        tuple<int, const char*> get_mouse(const char* prompt);
};

#endif
