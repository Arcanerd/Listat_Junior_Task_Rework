#pragma once

#include "stdafx.h"
#include "domNode.h"

namespace myUtilities
{
	bool is_prime(int _num);
	
	std::string remove_insignificant_spaces(std::string &_inspstr);
	std::string extrcat_tag(std::string &_str);
	int extract_bound(std::string &_str);
	void print_out(std::shared_ptr<domNode> &root, int grade = 0);
}