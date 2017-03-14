#pragma once

#include <memory>

template <class T>
class AbstractReader
{

public:
	virtual void read() = 0;
	virtual const char* get_filepath() = 0;
	virtual std::shared_ptr<T> get_data() = 0;	

	virtual ~AbstractReader() = default;

};

