#pragma once
#include <list>


template<typename Item_Type>
class PriorityQueue
{
public:
	void push(Item_Type itemToBePushed)
	{
		if (numItems == 0)
		{
			queList.push_front(itemToBePushed);
			
		}
		else
		{
			queList.push_front(itemToBePushed);
		}

		numItems++;
	}

	void pop()
	{
		if (numItems == 0)
			return;
		queList.sort();
		queList.pop_back();
		numItems--;
	}
	Item_Type& top()
	{
		queList.sort();
		return queList.back();
	}
	bool empty() {
		if (numItems == 0)
			return true;
		else return false;
	}

private:
	list<Item_Type> queList;
	size_t numItems;
};