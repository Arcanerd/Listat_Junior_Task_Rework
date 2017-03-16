#include "stdafx.h"
#include "synCounter.h"

synCounter::synCounter():
	nintervals(0),
	counter(0)
{}
synCounter::synCounter(size_t _nintervals):
	nintervals(_nintervals),
	counter(0)
{
}

void synCounter::increment()
{
	std::lock_guard<std::mutex> guard(sync_mutex);
	++counter;
	if (counter >= nintervals)
		sent_signal();
}

void synCounter::sent_signal()
{
	sync_condvar.notify_one();
}

void synCounter::wait_signal()
{
	std::unique_lock<std::mutex> ulock(sync_mutex);
	sync_condvar.wait(ulock);
}

void synCounter::set_nintervals(size_t _nintervasls)
{
	nintervals = _nintervasls;
}