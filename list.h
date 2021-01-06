#ifndef list_h
#define list_h

struct ListItem
{
	int year;
	double flow;
};

struct Node
{
	ListItem item;
	Node *next;
};

class FlowList
{
	
public:
	FlowList();
	FlowList(const FlowList& source);
	FlowList& operator =(const FlowList& rhs);
	~FlowList();

	void insert(int yr, double flw);
	void print() const;
	int size()const;
	double average()const;
	bool member(int yr) const;
	Node *head() const;
	void remove(int itemA);

private:
	Node *headM;
	void copy(const FlowList& source);
	void destroy();
};

#endif