#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
	node* prev;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
		prev = NULL;
    }
};

class double_ll{
	public:

	node* head = NULL;

	void insert_front(int data){
		node* new_node = new node(data);
		
		if(head == NULL){
			head = new_node;
			return;
		}

		new_node->next = head;
		new_node->prev = NULL;

		if(head != NULL){
			head->prev = new_node;
		}
		head = new_node;
	}

	void insert_back(int data){
		node* new_node = new node(data);

		if(head == NULL){
			head = new_node;
			return;
		}

		node* last = head;

		while(last->next != NULL){
			last=last->next;
		}
		last->next = new_node;
		new_node->prev = last;
	}

	void insert_before(node* position, int data){
		node* new_node = new node(data);

		if(position == NULL){
			insert_front(data);
			return;
		}

		new_node->prev = position -> prev;
		new_node->next = position;
		position->prev = new_node;

		if(position==head){
			head = position;
		}
	}

	void insert_after(node* position,int data)
    {
        node*new_node=new node(data);
          
          if(position==NULL)
          {
            insert_back(data);
            return;
          }

          new_node->next=position->next;
          new_node->prev=position;
          position->next=new_node;
    }

	void remove_front(){
		node* current = head;

		head = current->next;
		head->prev = NULL;
		free(current);
	}

	void remove_back(){
		
		node*temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        node*i=temp->prev;
        i->next=NULL;
        free(temp);
	}

	//void remove_midle(int position){
	// 	node* current = head;

	// 	if(current == NULL){
	// 		return;
	// 	}

	// 	if(position == 0){
	// 		if(head->next == head){
	// 			free(head);
	// 			return;
	// 		}
	// 		remove_front();
	// 		return;
	// 	}
	// 	while (current->next != head)
	// 	{
	// 		current = current->next;
	// 	}

	// 	node* temp1 = current->prev;
	// 	node* temp2 = current->prev;


	// }

	// void remove_middle(node* &node){
	// 	node->prev->next = node->next;
  	// 	node->next->prev = node->prev;
  	// 	free(node);
	// }

	void remove_middle(int x)
    {
       node*i=head;

       while(i!=NULL)
       {
          if(i->data==x)
          {
            break;
          }
          i=i->next;
       }

       if(i==NULL)
       {
        return;
       }

       node*temp1=i->prev;
       node*temp2=i->next;

       temp1->next=temp2;
       temp2->prev=temp1;

       free(i);
    }

	void print()
    {
        node*i=head;

        while(i!=NULL)
        {
            cout<<i->data<<" ";
            i=i->next;
        }
        cout<<endl;
    }
};

int main(){
	double_ll a;

	a.insert_front(1);a.print();
	a.insert_front(3);a.print();
	a.insert_front(5);

	a.print();

	a.insert_back(7);
	a.insert_back(11);
	a.insert_back(22);
	a.print();
	a.insert_back(9);
	a.print();

	//a.insert_after(3, 29);
	a.remove_front();
	a.print();

	a.remove_back();
	a.print();

	a.remove_middle(7);
	a.print();

	return 0;
}