#include "stdafx.h"
#include "Writer.h"



Writer::Writer(std::string &_filepath, std::vector<std::vector<int>> &data) :
	ints_to_write(data),
	filepath(_filepath)
{
}

std::string Writer::get_filepath() const
{
	return filepath; 
}

void Writer::set_filepath(std::string &path)
{
	filepath = path;
}

void Writer::write()
{
	std::ofstream file;
	
	//opening
	file.open(get_filepath(), std::ofstream::app);
	if (file.fail()) {
		std::cout << "ERROR! Could not open the file for writing!" << std::endl;
		return;
	}
	
	//writing
	file << std::endl;
	for (auto vec : ints_to_write) {
		for (auto i : vec)
			file << i << ' ';
		file << std::endl << std::endl;
	}

	file.close();
}