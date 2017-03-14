#pragma once

#include <string>
#include <iostream>
#include <fstream>

class AbstractWriter
{
private:	

public:
	
	virtual ~AbstractWriter() = default;
	virtual void write() = 0;
};

