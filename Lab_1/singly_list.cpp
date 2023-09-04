#include<iostream>
using namespace std;

int size_of_slist;
template<typename T> class Node {
    public:
        T node_data;
        Node *link;
        Node(T data){
            this->node_data = data;
            this->link = NULL;
            size_of_slist++;
        }
};

template<typename T> class SinglyList {
 	public:
     	Node<T> *head,*tail;
 
        SinglyList(){
            head = NULL;
            tail = NULL;
        }
		
	~SinglyList() {
		free_memory();
	}

        void push_back(T data);
        void insert_at_front(T data);
        void insert_at_end(T data);
        void insert_at_loc(int loc,T data);
        void display_all();
        void delete_front();
        void delete_end();
        void delete_at_loc(int loc);
        bool find(T key);
	void free_memory();
};

template<typename T> void SinglyList<T> :: push_back(T data){
    Node<T> *node = new Node<T>(data);
    if(node == NULL){
        cout<<"Heap is full !!!"<<endl;
        return;
    }

    if(head == NULL){
        head = node;
        tail = node;
    }
    else{
        tail->link = node;
         tail = node;
    }
}

template<typename T> void SinglyList<T> :: display_all(){
    Node<T>  *temp_head = head;
    while(temp_head != NULL){
        cout<<temp_head->node_data<<" ";
        temp_head = temp_head->link;
    }
    cout<<endl;
}

template<typename T> void SinglyList<T> :: insert_at_front(T data){
    Node<T> *node = new Node<T>(data);
    if(node == NULL){
        cout << "Heap is full !!! "<<endl;
        return;
    }
    node->link = head;
    head = node;
}

template<typename T> void SinglyList<T> :: insert_at_loc(int loc,T data){
    if(size_of_slist < loc)
        return;

    else if(head == NULL && loc == 0)
        push_back(data);

    else if(head != NULL && loc == 0)
        insert_at_front(data);

    else if(size_of_slist == loc)
        insert_at_end(data);

    else{
        Node<T> *node = new Node<T>(data);
        Node<T> *temp = head;

        if(node == NULL){
            cout<<"Heap is full !!!"<<endl;
            return;
        }
        else{
            int count = 0;
            while(count < loc - 1){
                temp = temp->link;
                count++;
            }
            node->link = temp->link;
            temp->link = node;
        }
    }
}

template<typename T> void SinglyList<T> :: insert_at_end(T data){
    Node<T> *node = new Node<T>(data);
    if(node == NULL){
        cout<<"Heap is full !!!"<<endl;
        return;
    }

    tail->link = node;
    tail = node;
}

template<typename T> void SinglyList<T> :: delete_front(){
    Node<T> *temp = head;
    head = temp->link;
    delete temp;
    temp = NULL;
    size_of_slist--;

    if(size_of_slist == 0){
            head = NULL;
            tail = NULL;
    }

} 

template<typename T> void SinglyList<T> :: delete_end(){
    Node<T> *temp = head;
    if(temp == NULL)
    	return;
    	
    if(temp->link == NULL){
    	this->delete_front();
    }
    	
    else{
    	while(temp->link->link != NULL){
        	temp = temp -> link;
    	}
    }
    Node<T> *lastNode = temp->link;
    temp->link = NULL;
    tail = temp;
    delete lastNode;
    lastNode = NULL;
    size_of_slist--;

    if(size_of_slist == 0){
            head = NULL;
            tail = NULL;
    }

}

template<typename T> void SinglyList<T> :: delete_at_loc(int loc){
    if(loc >= size_of_slist)
        return;

    else if (head != NULL && loc == 0)
        delete_front();

    else if(size_of_slist == loc + 1)
        delete_end();

    else if(head == NULL){
        cout<<" No data for delete"<<endl;
        return;
    }else{
            Node<T> *temp = head;
            int count = 0;
            while(count < loc - 1){
                temp = temp->link;
                count++;
            }
            
            Node<T> *deleting_node = temp->link;
            temp->link = deleting_node->link;
            size_of_slist--;
            delete deleting_node;
            deleting_node = NULL;
        }

    if(size_of_slist == 0){
	    head = NULL;
	    tail = NULL;
    }
} 

template<typename T> bool SinglyList<T> :: find(T key){
    Node<T> *temp = head;
    while(temp != NULL){
        if(temp->node_data == key)
            return true;
        temp = temp->link;
    }
    return false;
}

template<typename T> void SinglyList<T> :: free_memory(){
	Node<T> *temp = head;
	while(temp != NULL){
		Node<T> *free_block = temp;
	        temp = temp->link;
		delete free_block;
		free_block = NULL;
	}	
}
