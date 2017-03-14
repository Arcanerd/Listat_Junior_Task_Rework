#pragma once
#include "ReturnCodes.h"

class AbstractWriter
{

public:
	
	virtual void write() = 0;
	virtual ~AbstractWriter() = default;
};

