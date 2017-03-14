#pragma once

#include <string>
#include <iostream>
#include <fstream>

class AbstractWriter
{
private:	

public:
	AbstractWriter();
	virtual ~AbstractWriter();
	virtual void write() = 0;
};

