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
/**
 * A function that receives an array of cars and outputs all the cars of a given year
 * @param
 * @param
 */
void PrintCarsPerYear(const Car cars[], size_t size, unsigned int year);
void SelectionSort(Car cars[], size_t n);
void ReadCar(istream& input, Car& car);
void WriteCar(ostream& output, const Car& car);
int main() {
    stringstream cars(
            "Toyota 2023\n"
            "Mazda 2022\n"
            "Hyundai 2001\n"
            "Tesla 2025\n"
            "Honda 2021\n");
    Car data[5];
    size_t SIZE = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < SIZE; ++i) {
        ReadCar(cars, data[i]);
    }

    for (int i = 0; i < SIZE; ++i) {
        WriteCar(cout, data[i]);
    }
    cout << "------------------------------" << endl;
    PrintCarsPerYear(data, SIZE, 2001);
    cout << "------------------------------" << endl;
    SelectionSort(data, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        WriteCar(cout, data[i]);
    }
    cout << "------------------------------" << endl;


    return 0;
}
// Time Complexity -- O(n)
void PrintCarsPerYear(const Car cars[], size_t size, unsigned int year){
    for (int i = 0; i < size; ++i) {
        if (cars[i].year == year)
            WriteCar(cout, cars[i]);
    }
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


size_t MinimumPosition(Car cars[], size_t n, size_t start = 0){
    unsigned int minYear = cars[start].year, minPos = start;
    for (int i = start; i < n; ++i) {
        if (cars[i].year < minYear){
            minYear = cars[i].year;
            minPos = i;
        }
    }
    return minPos;
}
void Swap(Car& a, Car& b){
    Car c;
    c.year = a.year;
    strcpy(c.make, a.make);
    a.year = b.year;
    strcpy(a.make, b.make);
    b.year = c.year;
    strcpy(b.make, c.make);
}
void SelectionSort(Car cars[], size_t n){
    for (int i = 0; i < n; ++i) {
        size_t minPos = MinimumPosition(cars, n, i);
        Swap(cars[i], cars[minPos]);
    }
}