#pragma once
//main requirement to interface classes: exlude includes as much as possible
// try to do so
#include "theQueue.h"
#include <memory>

class theQueue;

class AbstractReader
{

public:
	AbstractReader();//it looks like redundant
	virtual  std::shared_ptr<theQueue> get_intervals() = 0;
	virtual std::string get_filepath() const { return std::string(""); };//move to cpp for avoiding problem when it used in many libraries
	virtual ~AbstractReader();//= default
};

