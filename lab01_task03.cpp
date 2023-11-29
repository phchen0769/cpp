#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

using namespace std;

const int NUM_PHILOSOPHERS = 5;

vector<mutex> forks(NUM_PHILOSOPHERS);
vector<thread> philosophers(NUM_PHILOSOPHERS);

void philosopher(int philosopherId) {
    int leftFork = philosopherId;
    int rightFork = (philosopherId + 1) % NUM_PHILOSOPHERS;

    while (true) {
        // Thinking
        cout << "Philosopher " << philosopherId << " is thinking." << endl;
        this_thread::sleep_for(chrono::seconds(1));

        // Waiting for forks
        unique_lock<mutex> leftLock(forks[leftFork]);
        unique_lock<mutex> rightLock(forks[rightFork]);

        // Eating
        cout << "Philosopher " << philosopherId << " is eating." << endl;
        this_thread::sleep_for(chrono::seconds(2));

        // Release forks
        leftLock.unlock();
        rightLock.unlock();
    }
}

int main() {
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i] = thread(philosopher, i);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i].join();
    }

    return 0;
}