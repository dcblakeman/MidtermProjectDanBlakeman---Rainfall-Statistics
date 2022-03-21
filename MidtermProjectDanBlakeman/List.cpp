//Daniel Blakeman
//CIS 2207-502
//Midterm Project - Rainfall Statistics
#include "List.h"
#include<assert.h>
#include<iostream>
#include<string>

using namespace std;

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	//Debugging check of precondition
	assert((position >= 1) && (position <= itemCount));

	//Count from the beginning of the chain
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();

	return curPtr;
}

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	//Point to nodes in the original chain
	Node<ItemType>* origChainPtr = aList.headPtr;
	if (origChainPtr == nullptr)
		headPtr = nullptr; //original list is empty
	else
	{
		//Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		//Point to first node in new chain
		Node<ItemType>* newChainPtr = headPtr;

		//Advance original chain pointer
		origChainPtr = origChainPtr->getNext();

		//Copy remaining nodes
		while (origChainPtr != nullptr)
		{
			//Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			//Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node <ItemType>(nextItem);

			//Link new node to the end of new chain
			newChainPtr->setNext(newNodePtr);

			//Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			//Advance original chain pointer
			origChainPtr = origChainPtr->getNext();
		}//end while
		newChainPtr->setNext(nullptr); //Flag end of chain
	}//end if
}//end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}//end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	if (headPtr == nullptr)
		return true;
	else
		return false;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		//Create a new node containing the new entry
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		
		//Attach new node to chain
		if (newPosition == 1)
		{
			//Insert new node at beginning of chain
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			//Find node that will be before new node
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

			//Insert new node after node to which prevPtr points
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}//end if

		itemCount++; // increase count of entries
	}//end if
	return ableToInsert;
}//end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			//Remove the first node in the chain
			curPtr = headPtr; //Save pointer to node
			headPtr = headPtr->getNext();
		}
		else
		{
			//Find node that is befor the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			//Point to node to remove
			curPtr = prevPtr->getNext();

			//Disconnect indicated node from chain by connecting the preior node with the one after
			prevPtr->setNext(curPtr->getNext());
		}//end if

		//Return node to system
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;

		itemCount--; //Decrease count of entries
	}//end if
	return ableToRemove;
}// end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
	//Enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcept(message));
	}//end if
}//end getEntry

template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept)
{
	//Enforce precondition
	
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	
	if (ableToReplace)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->setItem(newEntry);
	}
	else
	{  
		string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcept(message));
	}//end if
}

