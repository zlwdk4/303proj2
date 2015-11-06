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
		//queList.sort(); // find max    not sort
		list<Item_Type>::iterator iter = queList.begin(), curMax = queList.begin();
		for (iter; iter != queList.end(); iter++) {
			if (*iter < *curMax)
				continue;
			else
				curMax = iter;
		}
		queList.erase(curMax);
	//	queList.pop_back();
		//numItems--;
	}
	Item_Type& top()
	{
		//queList.sort();   // find max    not sort
		
		//return queList.back();

		list<Item_Type>::iterator iter = queList.begin(), curMax = queList.begin();
		for (iter; iter != queList.end(); iter++) {
			if (*iter < *curMax)
				continue;
			else
				curMax = iter;
		}
		return *curMax;
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