#pragma once
#include "AbstractReader.h"
#include "domNode.h"

class theQueue;

class domParser :
	public AbstractReader
{
private:
	
	std::string filepath;
	std::ifstream file;
	std::string input;

	std::shared_ptr<domNode> root;

public:
	domParser(std::string _filepath);
	~domParser() = default;

	virtual void read();
	bool simple_parse();

	std::shared_ptr<domNode> get_root();

	virtual std::string get_filepath() const;
	void set_filepath(std::string _path);

	virtual std::shared_ptr<theQueue> get_intervals();//use c++11 override
	//supporting routing should be placed inside anonymous namespace

	friend std::string remove_insignificant_spaces(std::string &_inspstr); //why is it declared as friend but private/protected members of domParser class isn't used inside?
	friend std::string extrcat_tag(std::string &_str);
	friend int extract_bound(std::string &_str);
	friend void print_out(std::shared_ptr<domNode> &root, int grade = 0);
};