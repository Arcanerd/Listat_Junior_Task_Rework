#pragma once

#include "stdafx.h"
#include "domNode.h"
#include <mutex>

//class intended to simulate a queue of data similar to stack
//provide information about data
//provide safe multithread reading
class theQueue
{
public:
	explicit  theQueue(std::shared_ptr<domNode> &root);
	~theQueue() = default;

	cinterval get_interval();
	size_t get_number_of_intervals() const;
	bool is_empty() const;

private:
	void fill_intrvls(std::shared_ptr<domNode> &node);
	cinterval pop_back_interval();
	cinterval pop_front_interval();

private:
	mutable std::mutex intrvls_mutex;
	std::vector<cinterval> intrvls;

	size_t finish;
	size_t start;
	

};

