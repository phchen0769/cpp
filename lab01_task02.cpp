#include <vector> 
#include <mutex> 
#include <thread>

std::vector<int> x; 
std::mutex mutex;

void thread_func1() 
{
	mutex.lock(); 
	x.push_back(0); 
	mutex.unlock();
}

void thread_func2()
{
	mutex.lock();
	x.pop_back();
	mutex.unlock();
}

int main() 
{
	std::thread th1(thread_func1); 
	std::thread th2(thread_func2);

	th1.join();
	th2.join();

	return 0;
}
