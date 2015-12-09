#include <iostream>

struct Node
{
		int data;
		Node *next;
		Node *prev;
};

class Queue
{
		public:
				~Queue();
				Queue();
				bool isEmpty();
				void push(int item);
				int pop();

		private:
				Node *head;
				Node *tail;
				Node *curr;
				int size;
};

Queue::Queue()
{
		head = new Node;
		tail = new Node;
		curr = NULL;

		head -> next = tail;
		head -> prev = NULL;
		tail -> next = NULL;
		tail -> prev = head;

		size = 0;
}

bool Queue::isEmpty()
{
		if(size==0)
				return true;

		return false;
}

void Queue::push(int item)
{
		Node *newNode=new Node;

		newNode -> prev = tail -> prev;
		newNode -> next = tail;
		newNode -> data = item;

		tail->prev->next=newNode;
		tail->prev=newNode;

		size++;
}

int Queue::pop()
{
		int item;

		if(isEmpty())
		{
				//true
				std::cout<<"queue is empty. So I can't pop item"<<std::endl;
				return 0;
		}

		curr=head->next;

		head->next=curr->next;
		head->next->prev=head;

		item=curr->data;
		delete curr;
		curr=NULL;

		size--;

		return item;

}

Queue::~Queue()
{
		Node *temp;

		curr=head;
	
		while(curr!=NULL)
		{
				temp=curr->next;

				delete curr;
				curr=temp;
		}
}

int main()
{
		Queue *q=new Queue();

		for(int i=0;i<10;i++)
		{
				q->push(i);
		}

		for(int i=0;i<5;i++)
		{
				std::cout<<q->pop()<<std::endl;
		}

		for(int i=0;i<5;i++)
		{
				q->push(i+10);
		}

		for(int i=0;i<5;i++)
		{
				std::cout<<q->pop()<<std::endl;
		}
}
