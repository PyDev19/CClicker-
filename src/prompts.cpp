#include <tuple>

#include "prompts.hpp"
#include "classes/key.hpp"

using namespace std;

tuple<char, char, char> prompts(Key key) {
    char start_key = key.get_key("Key to start autoclicker (press any key): ");

    char stop_key = key.get_key("Key to stop autoclicker (press any key): ");

    char exit_key = key.get_key("Key to exit program (press any key): ");

    return {start_key, stop_key, exit_key};
}
