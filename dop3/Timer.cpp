#include <chrono>
#include <iostream>

using namespace std;

long fibonacci(unsigned n) 
{
	return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

template <typename T> class Timer
{
public:
	static void reset();
	static T elapsed_nanoseconds();
	static T elapsed_microseconds();
	static T elapsed_milliseconds();
	static T elapsed_seconds();
	static T elapsed_minutes();
private:
	typedef chrono::high_resolution_clock clock_;
	static chrono::time_point<clock_> beg_;
};
template <typename T> void Timer<T>::reset()
{
	beg_ = clock_::now();
}
template <typename T> T Timer<T>::elapsed_nanoseconds()
{
	return chrono::duration_cast<chrono::duration<T, nano>>(clock_::now() - beg_).count();
}
template <typename T> T Timer<T>::elapsed_microseconds()
{
	return chrono::duration_cast<chrono::duration<T, micro>>(clock_::now() - beg_).count();
}
template <typename T> T Timer<T>::elapsed_milliseconds()
{
	return chrono::duration_cast<chrono::duration<T, milli>>(clock_::now() - beg_).count();
}
template <typename T> T Timer<T>::elapsed_seconds()
{
	return chrono::duration_cast<chrono::duration<T>>(clock_::now() - beg_).count();
}
template <typename T> T Timer<T>::elapsed_minutes()
{
	return chrono::duration_cast<chrono::duration<T, ratio<60>>>(clock_::now() - beg_).count();
}
template<typename T> chrono::time_point<chrono::high_resolution_clock> Timer<T>::beg_ = chrono::high_resolution_clock::now();

int main() 
{
	Timer<double>::reset();
	std::cout << "f(42) = " << fibonacci(42) << '\n';
	std::cout << "nanoseconds " << Timer<double>::elapsed_nanoseconds() << std::endl;
	std::cout << "microseconds " << Timer<double>::elapsed_microseconds() << std::endl;
	std::cout << "seconds " << Timer<double>::elapsed_milliseconds() << std::endl;
	std::cout << "nanoseconds " << Timer<double>::elapsed_seconds() << std::endl;
	std::cout << "minutes " << Timer<double>::elapsed_minutes() << std::endl;
}