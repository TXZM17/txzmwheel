#ifndef __TXZM_TIMER__
#define __TXZM_TIMER__
#include <chrono>
#include <string>
#include <iostream>

namespace txzm
{
class Timer
{
public:
    Timer() : _begin(std::chrono::high_resolution_clock::now()) {}

    void reset() { _begin = std::chrono::high_resolution_clock::now(); }
 
    //ƒ¨»œ ‰≥ˆ∫¡√Î
    int64_t elapsed() const
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _begin).count();
    }
 
    //Œ¢√Î
    int64_t elapsed_micro() const
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - _begin).count();
    }
 
    //ƒ…√Î
    int64_t elapsed_nano() const
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - _begin).count();
    }
 
    //√Î
    int64_t elapsed_seconds() const
    {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - _begin).count();
    }
 
    //∑÷
    int64_t elapsed_minutes() const
    {
        return std::chrono::duration_cast<std::chrono::minutes>(std::chrono::high_resolution_clock::now() - _begin).count();
    }
 
    // ±
    int64_t elapsed_hours() const
    {
        return std::chrono::duration_cast<std::chrono::hours>(std::chrono::high_resolution_clock::now() - _begin).count();
    }

	//¥Ú”°
	void print_elapsed(const std::string &tag = "from begin") const
	{
		std::cout << tag << " has elapsed " << elapsed() << " milliseconds" << std::endl; 
	}
 
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _begin;
};
}

#endif