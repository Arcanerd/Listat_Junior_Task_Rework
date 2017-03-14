#include "stdafx.h"
#include "DOMParser.h"

//in general try to use the constructors only to construct an instance (invariant) withoud business logic or tricky initialization
//e.g. how will you know that file.fail() if you exclude interaction with user here?
domParser::domParser(std::string _filepath):
	filepath(_filepath)
{
	//check file;
	bool file_incorrect = true;
	// many developers consider do as a bad style. not so bad as goto but ...
	do {
		
		file.open(filepath, std::ifstream::in);

		if (file.fail()) {
			std::cout << "ERROR! Could not open the file!" << std::endl;
			std::cout << "Please specify file: ";
			std::getline(std::cin, filepath);//pay attention how are you going to write a unit test to this part of code
		}

		else {
			std::getline(file, input);
			//any constant should be moved in the to of cpp file and properly named
			// only meaningful and distinctive names of constants should be present inside source code
			if (input == "<root>") {
				file_incorrect = false;
				root = std::shared_ptr<domNode>(new domNode(input));
				root->set_next(nullptr);
			}
		}
	} while (file.fail() || file_incorrect);


	//read file build tree
	assert(simple_parse() == true);//in general it is an error because assert are excluded in release build!!!

	file.close();
}


const char* domParser::get_filepath() 
{
	return filepath.c_str();
};
void domParser::set_filepath(std::string _path)
{
	filepath = _path;
}
std::shared_ptr<theQueue> domParser::get_data()
{
	return get_intervals();
}

 void domParser::read()
{
}

bool domParser::simple_parse()
{
	bool intervals_closed = false;
	do {
		std::getline(file, input);
		input = remove_insignificant_spaces(input);
		if(input == "<intervals>"){
			do {
				std::getline(file, input);
				input = remove_insignificant_spaces(input);
				if (input == "<interval>") {
					int low, high;// code styles of production code very often require initialization of any variable.
					
					std::getline(file, input);
					input = remove_insignificant_spaces(input);
					low = extract_bound(input);

					std::getline(file, input);
					input = remove_insignificant_spaces(input);
					high = extract_bound(input);

					cinterval interval(low, high);
					std::string tag = "interval";
					std::shared_ptr<domNode> new_spnode(new domNode(tag, root, interval));
					root->append_sybling(new_spnode);
				}
			} while (input != "</intervals>");
			intervals_closed = true;
		}
	} while (file.good() && intervals_closed);
	
	if(!file.good() && intervals_closed == false)
		return false;
	else return true;
}
std::shared_ptr<domNode> domParser::get_root()
{
	return root;
}

std::shared_ptr<theQueue> domParser::get_intervals()
{
	std::shared_ptr<theQueue> ret_queue = std::make_shared<theQueue>(this->get_root());
	return ret_queue;
}

//friends
//this operation usually called trim
std::string remove_insignificant_spaces(std::string &_inspstr)//param isn't const
{
	//for me it is preferable to return at once. it allows to keep less details of the context in mind
	//compare:
	//if (_inspstr.empty())
	//	return _inspstr;

	//const std::size_t begin = _inspstr.find_first_not_of(' ');
	//const std::size_t end = _inspstr.find_last_not_of(' ');
	//const std::size_t contentLength = end - begin;
	//const bool isInvalidInput = contentLength > 1;
	//if (isInvalidInput)
	//	return "\n";
	//const std::string trimmed = _inspstr.substr(begin, contentLength);
	//return trimmed;

	if (_inspstr.size()) {//use _inspstr.empty()
		std::size_t begin = _inspstr.find_first_not_of(' ');
		std::size_t end = _inspstr.find_last_not_of(' ');
		//what happen if _inspstr doesn't contains any ' ' or only one?
		std::string result(_inspstr, begin, end - begin + 1);

		if (result.size())
			return result;
		else
			return "\n";
	}

	else
		return _inspstr;

}
std::string extrcat_tag(std::string & _str)
{
	std::string extracted(_str, 0, _str.find(' '));
	return extracted;
}
int extract_bound(std::string &_str)
{

	size_t begin = _str.find_first_of(' ');
	size_t end = _str.find_last_of('<');
	std::string numstr(_str, begin, end - begin);
	return std::stoi(numstr);	
}
void print_out(std::shared_ptr<domNode> &root, int grade)
{
	++grade;
	std::string tab(grade,' ');

	std::cout << tab << root->get_tag()
		<<' '
		<< root->get_interval().low
		<< ':'
		<< root->get_interval().high
		<<std::endl;
	if (root->get_sybling() != nullptr)
		print_out(root->get_sybling(), grade);
	if (root->get_next() != nullptr)
		print_out(root->get_next(), grade);
	std::cout << tab << root->get_closing_tag() << std::endl;
}
