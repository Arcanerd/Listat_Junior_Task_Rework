#pragma once
#include "AbstractReader.h"
#include "domNode.h"
#include "theQueue.h"
#include "ReturnCodes.h"

class theQueue;

class domParser :
	public AbstractReader <theQueue>
{

public:
	domParser(std::string _filepath);
	~domParser() = default;

	virtual STATUS::OPENING_STATUS read() override;

	std::shared_ptr<domNode> get_root();
	virtual const char* get_filepath() override;
	void set_filepath(std::string _path);
	virtual std::shared_ptr<theQueue> get_data() override;

private:
	std::string filepath;
	std::shared_ptr<domNode> root;
};