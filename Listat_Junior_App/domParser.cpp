#include "stdafx.h"
#include "DOMParser.h"
#include "ReturnCodes.h"
#include "utilityFunctions.h"

const std::string root_opening_tag = "<root>";
const std::string interval_openig_tag = "<interval>";
const std::string Intervals_Openig_Tag = "<intervals>";
const std::string Intervals_Closing_Tag = "</intervals>";


domParser::domParser(std::string &_filepath):
	filepath(_filepath)
{
}

STATUS::OPENING_STATUS domParser::read()
{
	std::ifstream file;
	std::string input;

	//check file;

	bool file_incorrect = true;

	file.open(filepath, std::ifstream::in);
	if (file.fail()) {
		std::cout << "ERROR! Could not open the file!" << std::endl;
		return STATUS::OPENING_STATUS::COULD_NOT_OPEN;
	}
	else {

		std::getline(file, input);
		if (input == root_opening_tag) {
			file_incorrect = false;
			root = std::shared_ptr<domNode>(new domNode(input));
			root->set_next(nullptr);
		}
		else
			return STATUS::OPENING_STATUS::WRONG_STRUCTURE;
	}
	
	//read intervals from file
	do {
		std::getline(file, input);
		input = myUtilities::trime(input);
		if (input == Intervals_Openig_Tag) {
			do {
				std::getline(file, input);
				input = myUtilities::trime(input);
				if (input == interval_openig_tag) {
					int low = 0, high = 0;

					std::getline(file, input);
					input = myUtilities::trime(input);
					low = myUtilities::extract_bound(input);

					std::getline(file, input);
					input = myUtilities::trime(input);
					high = myUtilities::extract_bound(input);

					cinterval interval(low, high);
					std::string tag = interval_openig_tag;
					std::shared_ptr<domNode> new_spnode(new domNode(tag, root, interval));
					root->append_sybling(new_spnode);
					
					std::getline(file, input);
					input = myUtilities::trime(input);
				}
			} while (input != Intervals_Closing_Tag && file.good());
		}
		//TODO: avoid redundant reading after intervals read?
	} while (file.good());
	
	file.close();
	return STATUS::OPENING_STATUS::EVERYTHING_OK;
}


std::shared_ptr<domNode> domParser::get_root() const
{
	return root;
}
const char* domParser::get_filepath()
{
	return filepath.c_str();
};
void domParser::set_filepath(std::string &_path)
{
	filepath = _path;
}
std::shared_ptr<theQueue> domParser::get_data()
{
	std::shared_ptr<theQueue> ret_queue;
	ret_queue = std::make_shared<theQueue>(this->get_root());
	return ret_queue;
}