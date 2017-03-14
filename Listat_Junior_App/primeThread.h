#pragma once
#include "theQueue.h"

#include <thread>

class primeThread
{

	std::thread sp_thread;
	std::shared_ptr<theQueue> sp_queue;

	std::vector<std::vector<int>> primes;
	
	void run();
	void generate_primes(cinterval &_intrvl);
	bool is_prime(int _num);

public:

	primeThread() {};
	primeThread(std::shared_ptr<theQueue> _sp_queue);
	~primeThread();

	void ignite();

	std::vector<std::vector<int>> get_primes() const;	
};

