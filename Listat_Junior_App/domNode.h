#pragma once
#include "stdafx.h"

class domNode
{
	typedef std::shared_ptr<domNode> spNode;

public:

	domNode();
	//global
	domNode(std::string &_tag, spNode &_next, spNode &_sybling, spNode &_parent, cinterval &_interval);
	//for root
	domNode(std::string &_tag);
	//for noninterval basic
	domNode(std::string &_tag, spNode &_parent);
	//for noninterval
	domNode(std::string &_tag, spNode &_next, spNode &_parent, spNode &_sybling);
	//for interval
	domNode(std::string &_tag, spNode &_parent, cinterval &_interval);

	~domNode() = default;

	void set_tag(const std::string _tag);
	void set_next(const spNode &_next);
	void set_parent(const spNode &_parent);
	void set_sybling(const spNode &_sybling);
	void set_interval(const cinterval &_interval);

	void append_sybling(const spNode &_lastsybling);
	void append_next(const spNode &_lastnext);

	std::string get_tag() const;
	std::string get_closing_tag() const;
	spNode get_next() const;
	spNode set_parent() const;
	spNode get_sybling() const;
	cinterval get_interval() const;

private:
	void set_closing_tag();

private:
	std::string tag;
	std::string closing_tag;
	spNode next;
	spNode parent;
	spNode sybling;
	cinterval interval;
};

