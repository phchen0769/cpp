#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <thread>

using namespace std;

int x = 10;
int y = 20;

void th_1(void)
{
	x = y - 10;
	cout << x << endl;
	return;
}

void th_2(void)
{
	y = x + 50;
	cout << y << endl;
	return;
}

int main()
{
	std::thread th1(th_1);
	std::thread th2(th_2);
	th1.join(); 
	th2.join();
	return 0;
}
