#pragma once
#include "theQueue.h"

#include <thread>
#include <mutex>

class primeThread
{
	
private:
	std::shared_ptr<theQueue> sp_queue;
	std::mutex primes_mutex;
	std::vector<std::vector<int>> primes;
	
	void run();
	void generate_primes(cinterval &_intrvl);

public:

	primeThread() {};
	primeThread(std::shared_ptr<theQueue> _sp_queue);
	~primeThread();

	void ignite();

	std::vector<std::vector<int>> get_primes() const;	
};

