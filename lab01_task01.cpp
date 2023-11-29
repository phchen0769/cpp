#include <iostream>
#include <thread>

using namespace std;

int globalVariable = 0;

void increase() {
    while (globalVariable < 1000) {
        globalVariable++;
    }
}

void decrease() {
    while (globalVariable > -1000) {
        globalVariable--;
    }
}

int main() {
    thread thread1(increase);
    thread thread2(decrease);
    
    thread1.join();
    thread2.join();
    
    cout << "Final value: " << globalVariable << endl;
    
    return 0;
}