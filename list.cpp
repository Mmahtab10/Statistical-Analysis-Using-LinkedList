#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList()
: headM(0)
{
}

FlowList::FlowList(const FlowList& source)
{
	copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
	if (this != &rhs) 
		{ 
			destroy(); 
			//destroy function in line 26
			copy(rhs);
			//copy function in line 163
		}
   return *this;
}

void FlowList::destroy()
{
   Node *current = headM;

   while( 0!=current)
   {
    	Node* delete_me = current;
    	current = current->next;
    	delete delete_me;
   }
   headM = 0;
}

FlowList::~FlowList()
{
   if(headM == 0)return;
   destroy(); 
   //destroy function in line 26
}

void FlowList::print() const
{
	cout << endl << "Year\tCar crash deaths\n" << endl;
    if (head() != 0) {
        cout << head()->item.year << ",\t";
        cout << head()->item.flow << endl;

        for (const Node* p = head()->next; p != 0; p = p->next)
        {
            cout << p->item.year << "  ";
        	cout << "  " << p->item.flow << "\t" << endl;
        }
    }
    cout << " \n";
}

bool FlowList::member(int yr) const
{
	for(Node *ptr = head(); ptr!=0 ; ptr = ptr->next)
	{
		if(ptr->item.year == yr)
		{
			return true;
		}
	}
	return false;
}

void FlowList::insert(int yr, double flw)
{
	//create node
	Node *new_node = new Node;
	new_node->item.year = yr;
	new_node->item.flow = flw;

	if(0==head() || yr < head()->item.year)
	{
		if(head() != 0 && flw == head()->item.flow) return;
		new_node->next = head();
		headM = new_node;
	}
	else
	{
		Node *before = head();
		Node *after = head()->next;

		while(after!=0 && yr > after->item.year)
		{
			if(after != 0 && flw == after->item.flow) return;
			before = after;
			after = after->next;
		}
		new_node->next = after;
		before->next = new_node;
	}
}

int FlowList::size()const
{
	int count = 0;

	for ( Node* ptr = head(); ptr != 0; ptr = ptr->next) {
	 	 ++count;
	 }

	 return count;
}

Node *FlowList::head() const
{
	return headM;
}


double FlowList::average() const
{
	double sum = 0; int count = 0;
	for ( Node* ptr = head(); ptr != 0; ptr = ptr->next) {
	 	 sum = sum + ptr->item.flow;
	 	 ++count;
	 }

	return (sum/count);
}

void FlowList::remove(const int itemA)
{
    // if list is empty, do nothing
    if (head() == 0 || itemA < head()->item.year)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == head()->item.year) {
        doomed_node = head();
        headM = head()->next;
    }
    else {
        Node *before = head();
        Node *maybe_doomed = head()->next;
        while(maybe_doomed != 0 && itemA != maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if(maybe_doomed == 0){
				cout << endl << itemA << " Not Found!!";
				return; }

		if (maybe_doomed != 0 && maybe_doomed->item.year == itemA) {   
			doomed_node = maybe_doomed;   
			before->next = maybe_doomed->next;   
		}   
	}	    
  delete doomed_node;
}

void FlowList::copy(const FlowList& source)
{
	if(source.headM == 0)
		{
			headM = 0;
			return;
		}

		headM = new Node;
		Node *newest_node = headM;
		const Node *source_node = source.headM;

		while(true) 
		{
			newest_node->item = source_node->item;
			source_node = source_node->next;

			if(source_node == 0)
				break;

			newest_node->next = new Node;
			newest_node = newest_node->next;
		}
		newest_node->next = 0;
}