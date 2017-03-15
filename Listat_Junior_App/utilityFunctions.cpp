#include "stdafx.h"
#include "utilityFunctions.h"

namespace myUtilities
{
	bool is_prime(int _num)
	{
		if (_num == 1 || _num == 2 || _num == 3)
			return true;

		else if (_num % 2 == 0)
			return false;
		//try divide for i
		for (int i = 3; i <= _num / 3; i += 2) {
			if (_num%i == 0)
				return false;
		}
		return true;
	};
}