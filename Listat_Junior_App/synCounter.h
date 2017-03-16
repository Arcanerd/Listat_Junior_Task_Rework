#pragma once
#include <mutex>
#include <condition_variable>

class synCounter
{
public:
	synCounter();
	explicit synCounter(size_t _nintervals);
	~synCounter() = default;

	void increment();
	void sent_signal();
	void wait_signal();
	void set_nintervals(size_t _nintervasls);
	bool is_already_sent() const;

private:
	size_t nintervals;
	size_t counter;

	std::mutex sync_mutex;
	std::condition_variable sync_condvar;
	bool already_sent;

};

