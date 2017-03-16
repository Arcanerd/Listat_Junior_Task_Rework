#include "stdafx.h"

#include "primeThread.h"
#include "utilityFunctions.h"

#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <math.h>

static const unsigned int DEFAULT_NCORES = 4;

primeThread::primeThread(std::shared_ptr<theQueue> &_sp_queue):
	sp_queue(_sp_queue),
	ncores(0)
{
}

primeThread::~primeThread()
{
	for (auto &t : threads) {
		if (t.joinable())
			t.join();
	}
}

void primeThread::ignite()
{
	ncores = std::max(std::thread::hardware_concurrency(), DEFAULT_NCORES);
	for(unsigned int i = 0; i < ncores; ++i)
		threads.emplace_back(std::thread(&primeThread::run, this));
	scounter.set_nintervals(sp_queue->get_number_of_intervals());
}

void primeThread::run()
{
	while (!sp_queue->is_empty())
		generate_primes(sp_queue->get_interval());
	scounter.increment();
}

void primeThread::generate_primes(cinterval &_intrvl)
{
	std::vector<int> result;

	if (_intrvl.low >= _intrvl.high)
		throw std::out_of_range("Error! interval low greater or equal to interval high");

	int num = _intrvl.low;
	do {
		if (myUtilities::is_prime(num))
			result.emplace_back(num);
		++num;
	} while (num <= _intrvl.high);
	
	std::lock_guard<std::mutex> primes_guard(primes_vec_mutex);
	primes.emplace_back(result);
}
void primeThread::stop()
{
	for (auto &t : threads) {
		if (t.joinable())
			t.join();
	}
}

void  primeThread::wait()
{
	scounter.wait_signal();
}

std::vector<std::vector<int>> primeThread::get_primes() const
{
	return primes;
}