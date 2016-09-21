#include <iostream>
using namespace std;

template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data,Node* next=nullptr,Node* prev=nullptr){
			data_ = data;
			next_ = next;
			prev_ = prev;
		}
	};
	Node* head_;
	Node* tail_;
public:
	DList(){
		head_ = tail_ = nullptr;
	}
	void push_front(const T& data){
		// make a node
		Node* nn = new Node(data, head_);
		
		if(head_ != nullptr){ //if the linked list not empty
			// head of the previous node
			head_ -> prev_ = nn; //the previous pointer of the node
		}
		else{
			tail_ = nn; //if the linked list is empty, the tail also has to point to nn (the only node)
		}
			
		//now head is = the new inserted node
		head_ = nn;
	}
	void push_back(const T& data);
	void pop_front();
	void pop_back(){
		if(head_){ //check if linked list is not empty
			if(head_ != tail_){ //if there's more than one node in the list
				tail_ = tail_ -> prev; // tail will be equal to the previous one
				delete tail_ -> next; //delete the present tail
				tail_ -> next = nullptr;
			}	
			else{
				delete tail_;
				head_ = tail_ = nullptr;
			}			
		}
		
	}
	void print() const{
	}
};

