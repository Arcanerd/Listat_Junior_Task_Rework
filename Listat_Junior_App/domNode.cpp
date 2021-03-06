#include "stdafx.h"
#include "domNode.h"


void domNode::set_closing_tag()
{
	if (this->get_tag() == "<low>")
		closing_tag = "<high>";
	else
		closing_tag.insert(1,1,'/');
}

domNode::domNode() {}
//global
domNode::domNode(std::string &_tag, spNode &_next, spNode &_parent, spNode &_sybling, cinterval &_interval):
	tag(_tag),
	closing_tag(_tag),
	next(_next),
	parent(_parent),
	sybling(_sybling),
	interval(_interval)
{
	set_closing_tag();
}
//for root
domNode::domNode(std::string &_tag):
	domNode(_tag, spNode(nullptr), spNode(nullptr), spNode(nullptr), (cinterval (0,0)))
{}
//for noninterval basic
domNode::domNode(std::string &_tag, spNode &_parent):
	domNode(_tag, spNode(nullptr), _parent, spNode(nullptr), (cinterval(0, 0)))
{}
//for noninterval
domNode::domNode(std::string &_tag, spNode &_next, spNode &_parent, spNode &_sybling):
	domNode(_tag, _next, _parent, _sybling, (cinterval(0, 0)))
{}
//for interval
domNode::domNode(std::string &_tag, spNode &_parent, cinterval &_interval):
	domNode(_tag, spNode(nullptr), _parent, spNode(nullptr), _interval)
{}

void domNode::set_tag(const std::string &_tag) { tag = _tag; };
void domNode::set_next(const spNode &_next) { next = _next; }
void domNode::set_parent(const spNode &_parent) { parent = _parent; }
void domNode::set_sybling(const spNode &_sybling) { sybling = _sybling; }
void domNode::set_interval(const cinterval &_interval) { interval = _interval; }

void domNode::append_sybling(const spNode &_lastsybling)
{
	if (this->get_sybling() == nullptr) {
		this->set_sybling(_lastsybling);
	}
	else {
		this->get_sybling()->append_next(_lastsybling);
	}
}
void domNode::append_next(const spNode &_lastnext)
{
	if (this->get_next() == nullptr) {
		this->set_next(_lastnext);
	}
	else {
		this->get_next()->append_next(_lastnext);
	}
}

std::string domNode::get_tag() const { return tag; };
std::string domNode::get_closing_tag() const { return closing_tag; };
domNode::spNode domNode::get_next() const { return next; }
domNode::spNode domNode::set_parent() const { return parent; }
domNode::spNode domNode::get_sybling() const { return sybling; }
cinterval domNode::get_interval() const { return interval; }
