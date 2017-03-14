#include "stdafx.h"
#include "threadWriter.h"



threadWriter::threadWriter(std::string _filepath, std::vector<std::vector<int>> &data) :
	ints(data),
	filepath(_filepath)
{
}


threadWriter::~threadWriter()
{
}

std::string threadWriter::get_filepath() const
{
	return filepath; 
}

void threadWriter::set_filepath(std::string path)
{
	filepath = path;
}

void threadWriter::write()
{
	init();
	write_data();
}

void threadWriter::init()
{

	file.open(get_filepath(), std::ofstream::app);
	while(file.fail()){
		std::cout << "ERROR! Could not open the file for writing!" << std::endl;
		std::cout << "Please specify file: ";
		std::getline(std::cin, filepath);
		file.open(get_filepath(), std::ofstream::app);
	}
}
void threadWriter::write_data()
{
	file << std::endl;
	for (auto vec : ints) {
		for (auto i : vec)
			file << i << ' ';
		file << std::endl << std::endl;
	}
	file.close();
}