#include <tuple>

#include "prompts.hpp"
#include "key.hpp"

std::tuple<char, char, char> prompts(Key* key) {
    char start_key, stop_key, exit_key = '\0';

    start_key = key->get_key("Key to start autoclicker (press any key): ");
    stop_key = key->get_key("Key to stop autoclicker (press any key): ");
    exit_key = key->get_key("Key to exit program (press any key): ");

    return {start_key, stop_key, exit_key};
}
