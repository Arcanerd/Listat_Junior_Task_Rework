#include "stdafx.h"

#include "primeThread.h"
#include "utilityFunctions.h"

#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

using namespace myUtilities;


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

std::vector<std::vector<int>> primeThread::get_primes() const
{
	return primes;
}