#pragma once
namespace STATUS
{
	//for files openig, reading, etc.
	enum class OPENING_STATUS : char {
		EVERYTHING_OK = 0,
		COULD_NOT_OPEN,
		WRONG_STRUCTURE
	};
}