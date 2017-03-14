// Listat_Junior_app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AbstractReader.h"
#include "domParser.h"
#include "primeThread.h"
#include "threadWriter.h"

std::string get_input(int argc, char** argv);

int main(int argc, char** argv)
{
	std::string filepath = get_input(argc, argv);


	std::shared_ptr<AbstractReader<theQueue>> parser(new domParser (filepath));
	std::shared_ptr<theQueue> queue = parser->get_data();

	primeThread primes_calc(queue);//how to start calculation in 4 threads?
	primes_calc.ignite();//inside we stops main thread when falls into join(). Where is calculation in separate thread if we must wait for completing?

	std::string write_path = parser->get_filepath();
	std::shared_ptr<AbstractWriter> writer(new threadWriter(write_path, primes_calc.get_primes()));
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
		//it looks like you choose another error handling strategy - writing error messages!
		//throw std::out_of_range::exception("Error! Too many arguments!");
	}
}