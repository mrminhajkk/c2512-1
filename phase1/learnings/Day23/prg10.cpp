#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine started." << endl;
    }
};

class Car {
private:
    Engine engine;  // Engine object as a data member of Car

public:
    void startCar() {
        engine.start();  // Car has an engine, so we can start the engine
        cout << "Car started." << endl;
    }
};

int main() {
    Car car;
    car.startCar();  // Start the car, which starts the engine
    return 0;
}
