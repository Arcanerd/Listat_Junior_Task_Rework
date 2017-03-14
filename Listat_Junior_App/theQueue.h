#pragma once

#include "stdafx.h"
#include "domNode.h"

//add comments what is intent of creating this class
//this class simulates queue of 
class theQueue
{
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
	bool is_empty() const;
};

