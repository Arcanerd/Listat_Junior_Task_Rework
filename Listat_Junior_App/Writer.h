#pragma once
#include "AbstractWriter.h"
#include "primeThread.h"
#include <iostream>
#include <fstream>

class Writer :
	public AbstractWriter
{

private:
	std::string filepath;
	std::vector<std::vector<int>> ints_to_write;

public:
	Writer(std::string _filepath, std::vector<std::vector<int>> &data);
	virtual ~Writer() = default;
	
	std::string get_filepath() const;
	void set_filepath(std::string path);
	virtual void write();
};

