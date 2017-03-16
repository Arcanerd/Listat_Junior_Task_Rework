#pragma once
#include "theQueue.h"
#include "synCounter.h"

#include <thread>
#include <mutex>
#include <memory>

class primeThread
{
public:
	primeThread() {};
	primeThread(std::shared_ptr<theQueue> _sp_queue);
	~primeThread();

	void ignite();
	void stop();
	void wait();

	std::vector<std::vector<int>> get_primes() const;

private:
	synCounter scounter;
	unsigned int ncores;
	std::vector<std::thread> threads;
	
	std::mutex primes_vec_mutex;
	std::shared_ptr<theQueue> sp_queue;	
	std::vector<std::vector<int>> primes;
	
	void run();
	void generate_primes(cinterval &_intrvl);
};

