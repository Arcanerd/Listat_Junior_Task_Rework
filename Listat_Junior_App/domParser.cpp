#include "stdafx.h"
#include "DOMParser.h"
#include "ReturnCodes.h"
#include "utilityFunctions.h"

using namespace myUtilities;
//in general try to use the constructors only to construct an instance (invariant) withoud business logic or tricky initialization
//e.g. how will you know that file.fail() if you exclude interaction with user here?

const std::string root_opening_tag = "<root>";
const std::string interval_openig_tag = "<interval>";
const std::string Intervals_Openig_Tag = "<intervals>";
const std::string Intervals_Closing_Tag = "</intervals>";


domParser::domParser(std::string _filepath):
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
	bool intervals_closed = false;
	do {
		std::getline(file, input);
		input = remove_insignificant_spaces(input);
		if (input == Intervals_Openig_Tag) {
			do {
				std::getline(file, input);
				input = remove_insignificant_spaces(input);
				if (input == interval_openig_tag) {
					int low = 0, high = 0;

					std::getline(file, input);
					input = remove_insignificant_spaces(input);
					low = extract_bound(input);

					std::getline(file, input);
					input = remove_insignificant_spaces(input);
					high = extract_bound(input);

					cinterval interval(low, high);
					std::string tag = interval_openig_tag;
					std::shared_ptr<domNode> new_spnode(new domNode(tag, root, interval));
					root->append_sybling(new_spnode);
				}
			} while (input != Intervals_Closing_Tag);
			intervals_closed = true;
		}
	} while (file.good() && intervals_closed);

	if (!file.good() && intervals_closed == false) {
		return STATUS::OPENING_STATUS::WRONG_STRUCTURE;
		file.close();
	}
	file.close();
	return STATUS::OPENING_STATUS::EVERYTHING_OK;
}


std::shared_ptr<domNode> domParser::get_root()
{
	return root;
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
	std::shared_ptr<theQueue> ret_queue;
	ret_queue = std::make_shared<theQueue>(this->get_root());
	return ret_queue;
}