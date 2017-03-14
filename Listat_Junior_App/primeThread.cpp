#include "stdafx.h"

#include "primeThread.h"

#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>


primeThread::primeThread(std::shared_ptr<theQueue> _sp_queue):
	sp_queue(_sp_queue)
{
}

primeThread::~primeThread()
{
	if (sp_thread.joinable())
		sp_thread.join();
}

void primeThread::ignite()
{
	sp_thread = std::thread(&primeThread::run, this);
	
	if (sp_thread.joinable())
		sp_thread.join();
}

void primeThread::run()
{
	while (!sp_queue->is_empty())
		generate_primes(sp_queue->get_interval());

}

void primeThread::generate_primes(cinterval &_intrvl)
{
	std::vector<int> result;

	if (_intrvl.low >= _intrvl.high)
		throw std::out_of_range("Error! interval low greater or equal to interval high");

	int num = _intrvl.low;
	do {
		if (is_prime(num))
			result.emplace_back(num);
		++num;
	} while (num <= _intrvl.high);
	
	primes.emplace_back(result);
}

bool primeThread::is_prime(int _num) {

	if (_num == 1 || _num == 2 || _num == 3)
		return true;

	else if (_num % 2 == 0)
		return false;
	//try divide for i
	for (int i = 3; i <= _num / 3; i += 2) {
		if (_num%i == 0)
			return false;
	}
	return true;
}


std::vector<std::vector<int>> primeThread::get_primes() const
{
	return primes;
}