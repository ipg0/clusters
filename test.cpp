#include "field.h"
#include "field.cpp"
#include <iostream>

int main(void) {
    Field test_field;
    Cloud ncloud(Point(0, 0), 10, 10, 10);
    test_field.addCloud(ncloud);
    test_field.checkPoints();
    std::cout << "\n\n\n\n\n";
    test_field.addCloud(Cloud(Point(10000, 10000), 10, 10, 10));
    test_field.checkPoints();
    return 0;
}