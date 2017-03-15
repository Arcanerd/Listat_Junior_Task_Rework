#include "stdafx.h"
#include "theQueue.h"


theQueue::theQueue(std::shared_ptr<domNode> &root)
{
	if (root->get_sybling() != nullptr) {
		fill_intrvls(root->get_sybling());
		finish = intrvls.size() - 1;
		start = 0;
	}
}

void theQueue::fill_intrvls(std::shared_ptr<domNode> &node)
{
	intrvls.emplace_back(node->get_interval());
	if (node->get_next() != nullptr)
		fill_intrvls(node->get_next());
}

cinterval theQueue::pop_back_interval()
{
	--finish;
	return(intrvls.at(finish + 1));
}

cinterval theQueue::pop_front_interval()
{
	++start;
	return(intrvls.at((start-1)));
}

cinterval theQueue::get_interval()
{
	std::lock_guard<std::mutex> guard(intrvls_mutex);
	return pop_front_interval();
}

bool theQueue::is_empty() const 
{
	std::lock_guard<std::mutex> guard(intrvls_mutex);
	return (start > finish);
}