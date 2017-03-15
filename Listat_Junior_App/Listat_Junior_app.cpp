// Listat_Junior_app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AbstractReader.h"
#include "domParser.h"
#include "primeThread.h"
#include "Writer.h"

std::string get_input(int argc, char** argv);

int main(int argc, char** argv)
{
	std::string filepath = get_input(argc, argv);

	std::shared_ptr<AbstractReader<theQueue>> parser(new domParser (filepath));
	parser->read();
	std::shared_ptr<theQueue> queue = parser->get_data();

	primeThread primes_calc(queue);
	primes_calc.ignite();
	std::string write_path = parser->get_filepath();
	primes_calc.wait();
	std::shared_ptr<AbstractWriter> writer(new Writer(write_path, primes_calc.get_primes()));
	writer->write();

	std::cout << "Done!" << std::endl;

    return 0;
}

std::string get_input(int argc, char** argv) {
	if (argc == 1)
		return "example.xml";
	else if (argc == 2)
		return argv[1];
	else {
		std::cout << "Error! Too many arguments!" << std::endl;
		std::cout << "Please specify filepath manualy: ";

		std::string manual_path;
		std::cin >> manual_path;
		return manual_path;
	}
}