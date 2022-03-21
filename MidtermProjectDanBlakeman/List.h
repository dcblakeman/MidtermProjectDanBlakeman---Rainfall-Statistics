#pragma once
//Daniel Blakeman
//CIS 2207-502
//Midterm Project - Rainfall Statistics

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr = nullptr;
	int itemCount;
	Node<ItemType>* getNodeAt(int position) const;

public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcept);
	void replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);
}; // end LinkedList

