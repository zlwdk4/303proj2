#pragma once
#include <list>

//does the list update when an item's priotity changes

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
			queList.sort();
		}

		numItems++;
	}

	void pop()
	{
		if (numItems == 0)
			return;
		queList.pop_back();
		numItems--;
	}
	Item_Type& top()
	{
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