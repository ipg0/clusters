#include "field.h"
#include <cstring>

Field::Field(const Field &_field) { 
    quantity = _field.quantity;
    points = new Point[quantity];
    memcpy(points, _field.points, quantity * sizeof(Point));
}

Field::Field(std::istream &input) {
    points = nullptr;
    quantity = 0;
    Point currentPoint;
    size_t currentPosition = 0;
    double currentNumber = 0;
    while(input.get() != '[');
    while(input.peek() != ']') {
        if(input.get() == ':') {
            input >> currentNumber;
            switch(currentPosition++) {
            case 0:
                currentPoint.x = currentNumber;
                break;
            case 1:
                currentPoint.y = currentNumber;
                break;
            case 2:
                currentPoint.clusterMark = static_cast<size_t>(currentNumber);
                points = static_cast<Point *>(realloc(points, ++quantity * sizeof(Point)));
                points[quantity - 1] = currentPoint;
                currentPosition = 0;
            }
        }
    }
} // this is terrible but it should work, not a general JSON parser anyway.

void Field::addCloud(Cloud cloud) {
    points = static_cast<Point *>(realloc(points, quantity + cloud.getQuantity() * sizeof(Point)));
    memcpy(points + quantity, cloud.getPoints(), cloud.getQuantity() * sizeof(Point));
    quantity += cloud.getQuantity();
}

void Field::write(std::ostream &output) {
    output << '[';
    for(size_t i = 0; i < quantity; i++) {
        output << "{\n\t\"x\": " << points[i].x
            << ",\n\t\"y\": " << points[i].y
            << ",\n\t\"clusterMark\": " << points[i].clusterMark << "\n}";
        if(i != quantity - 1)
            output << ", ";
    }
    output << ']';
}
