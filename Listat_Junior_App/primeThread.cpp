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
{}

void primeThread::ignite()
{
	std::thread sp_thread_1;
	std::thread sp_thread_2;

	sp_thread_1 = std::thread(&primeThread::run, this);
	sp_thread_2 = std::thread(&primeThread::run, this);
	
	if (sp_thread_1.joinable())
		sp_thread_1.join();

	if (sp_thread_2.joinable())
		sp_thread_2.join();		
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
	
	std::lock_guard<std::mutex> primes_guard(primes_mutex);
	primes.emplace_back(result);
}

std::vector<std::vector<int>> primeThread::get_primes() const
{
	return primes;
}