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
		for (int i = 3; i <= _num / i; i += 2) {
			if (_num%i == 0)
				return false;
		}
		return true;
	};

	//friends
	//this operation usually called trim

	{
		//for me it is preferable to return at once. it allows to keep less details of the context in mind
		//compare:

			return _inspstr;

	}
	std::string extrcat_tag(std::string & _str)
	{
		std::string extracted(_str, 0, _str.find('>')+1);
		return extracted;
	}
	int extract_bound(std::string &_str)
	{

		size_t begin = _str.find_first_of('>')+1;
		size_t end = _str.find_last_of('<');
		std::string numstr(_str, begin, end - begin);
		return std::stoi(numstr);
	}
	void print_out(std::shared_ptr<domNode> &root, int grade)
	{
		++grade;
		std::string tab(grade, ' ');

		std::cout << tab << root->get_tag()
			<< ' '
			<< root->get_interval().low
			<< ':'
			<< root->get_interval().high
			<< std::endl;
		if (root->get_sybling() != nullptr)
			print_out(root->get_sybling(), grade);
		if (root->get_next() != nullptr)
			print_out(root->get_next(), grade);
		std::cout << tab << root->get_closing_tag() << std::endl;
	}
}