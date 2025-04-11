#include <cstring>
#include <sstream>
#include <iostream>
#include "my_string.h"
#include "tests/test_ctor.h"
#include "tests/test_all.h"
#include "tests/test_logger.h"

using std::stringstream;

int main() {
    //test_name = "TEST 1 - INPUT LONG STRING";
    my_string str1("apple");
    my_string str2("banana");
    my_string str3("apple");

    printf("%d ", str1 <= str3);
    //printf("%d\n", strcmp(s1.c_str(), input_str.c_str()));
    //std::cout << m1.c_str() << "\n" << std::endl;
    test();

    return 0;
}
