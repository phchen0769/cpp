#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <random>

using namespace std;

list<int> myList;
mutex mtx;

void appendRandomValue() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);

    while (myList.size() < 10) {
        int randomValue = dis(gen);

        lock_guard<mutex> lock(mtx);
        myList.push_back(randomValue);
    }
}

void printListContents() {
    while (myList.size() < 10) {
        lock_guard<mutex> lock(mtx);
        for (const auto& value : myList) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    thread thread1(appendRandomValue);
    thread thread2(printListContents);
    
    thread1.join();
    thread2.join();
    
    return 0;
}