/**
 * Name : Elmar Blume
 * Student Number: 516099
 */

#include <iostream>
#include "string/String.h"

int main() {
    String str{"Alice"};
    String str2{" and Bob"};
    String with_bob = concat(str, str2);
    std::cout << str.c_str() << '\n';
    std::cout << str2.c_str() << '\n';
    std::cout << with_bob.c_str() << '\n';


    str.append(str2);
    str = str2;
    std::cout << str.c_str() << '\n';
    std::cout << str2.c_str() << '\n';


    String alice = str.substr(0, 5);
    String cious = str.substr(5);
    String m{"c"};
    std::cout << str.contains(m) << '\n';

    String search{"ice"};
    std::cout << str.find(search) << '\n'; // 2
    std::cout << str.find(search, 21); // 20

    return 0;
}
