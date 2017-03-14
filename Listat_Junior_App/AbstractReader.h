#pragma once

class AbstractReader
{

public:
	virtual void read() = 0;
	virtual ~AbstractReader() = default;

};

