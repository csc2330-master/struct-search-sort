#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::stringstream;
using std::setw;

struct Car{
    char make[20];
    unsigned int year;
};

void ReadCar(istream& input, Car& car);
void WriteCar(ostream& output, const Car& car);
int main() {
    stringstream cars(
            "Toyota 2023\n"
            "Mazda 2022\n"
            "Tesla 2025\n"
            "Honda 2021\n"
            "Hyundai 2001");
    Car data[5];
    size_t SIZE = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < SIZE; ++i) {
        ReadCar(cars, data[i]);
    }

    for (int i = 0; i < SIZE; ++i) {
        WriteCar(cout, data[i]);
    }


    return 0;
}

void ReadCar(istream& input, Car& car){
    input >> car.make >> car.year;
}
void WriteCar(ostream& output, const Car& car){
    output << setw(23) << car.make << setw(6) << car.year << endl;
}
/*
 * How to create a struct, and the concept
 * How to create an array of structs
 * How to use stringstream to have a stream of test data
 * How to do functions that read and write from streams
 */