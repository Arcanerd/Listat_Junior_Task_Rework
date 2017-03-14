#pragma once

struct cinterval
{
	int low;
	int high;

	cinterval(int _low = 0, int _high = 0) :
		low(_low),
		high(_high)
	{};
};