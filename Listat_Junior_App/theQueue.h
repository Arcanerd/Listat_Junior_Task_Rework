#pragma once

#include "stdafx.h"
#include "domNode.h"
#include <mutex>

//add comments what is intent of creating this class
class theQueue
{
	mutable std::mutex intrvls_mutex;
	std::vector<cinterval> intrvls;

	size_t finish;
	size_t start;
	
	void fill_intrvls(std::shared_ptr<domNode> &node);
	cinterval pop_back_interval();
	cinterval pop_front_interval();

public:
	//theQueue();
	theQueue(std::shared_ptr<domNode> &root);

	~theQueue() = default;

	cinterval get_interval();
	size_t get_number_of_intervals() const;
	bool is_empty() const;
};

