#pragma once
#include "AbstractWriter.h"
#include "primeThread.h"
#include <iostream>
#include <fstream>

class threadWriter ://in fact where is thread in your writer?
	public AbstractWriter
{

private:
	std::string filepath;
	std::ofstream file;//try yo minimize number of class members
	std::vector<std::vector<int>> ints;//it is hard to imagine much more general naming!! :)

	void init();
	virtual void write_data();

public:
	threadWriter(std::string _filepath, std::vector<std::vector<int>> &data);
	virtual ~threadWriter() = default;
	
	std::string get_filepath() const;
	void set_filepath(std::string path);
	virtual void write();
};

