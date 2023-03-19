#ifndef KEY_HPP
#define KEY_HPP

#include <tuple>

class Key {
    public:
        char get_key(const char* prompt);
        std::tuple<int, const char*> get_mouse(const char* prompt);
};

#endif
