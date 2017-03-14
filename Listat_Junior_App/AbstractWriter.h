#pragma once

class AbstractWriter
{

public:
	
	virtual void write() = 0;
	virtual ~AbstractWriter() = default;
};

