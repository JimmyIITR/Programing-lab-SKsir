#include<iostream>
using namespace std;

template<typename T>
class DynamicArray{
	public:
        	T *arr = NULL;
        	int size;
        	DynamicArray(){
            	this->size = 0;
        }

        ~DynamicArray(){
            free_memory();
        }

        int len();
        void push_back(T ele);
        void display_all();
        void insert_at_loc(int loc,T ele);
        void pop_back();
        void delete_at_loc(int loc);
        bool find(T key);
        void free_memory();
};

template<typename T> int DynamicArray<T> :: len(){
    return size;
}

template<typename T> void DynamicArray<T> ::  push_back(T ele){
        if(this->arr == NULL){
        this->arr = new T[1];
        arr[0] = ele;
        this->size=1;
    }
    else{
        T *copyArray = new T[this->size+1];
        for(int i=0;i<this->size;i++)
            copyArray[i] = arr[i];
        copyArray[this->size] = ele;
        delete[] this->arr;
        this->arr = new T[this->size+1];
        for(int i=0;i<=this->size;i++)
            this->arr[i] = copyArray[i];
        this->size++;
        delete[] copyArray;
        }
    }

template<typename T> void DynamicArray<T> :: display_all(){
        for(int i=0;i<this->size;i++)
            cout<<this->arr[i]<<" ";
        cout<<endl;
    }

template<typename T> void DynamicArray<T> :: insert_at_loc(int loc,T ele){
        T *copyArray = new T[this->size+1];
        for(int i=0;i<=loc-1;i++)
            copyArray[i] = this->arr[i];
        copyArray[loc] = ele;
        for(int i=loc;i<this->size;i++)
            copyArray[i+1] = this->arr[i];
        delete [] this->arr;
        this->arr = new T[this->size+1];
        for(int i=0;i<=this->size;i++)
            this->arr[i] = copyArray[i];
        this->size++;
        delete[] copyArray;
    }
    
template<typename T> void DynamicArray<T> :: pop_back(){
	this->delete_at_loc(this->size - 1);
}

template<typename T> void DynamicArray<T> :: delete_at_loc(int loc){
        if(loc >= size)
            return;
        if(size == 0)
            return;

        T *copyArray = new T[this->size - 1];
        for(int i=0;i<=loc-1;i++)
            copyArray[i] = this->arr[i];
        for(int i=loc+1;i<this->size;i++)
            copyArray[i-1] = this->arr[i];
        delete[] this->arr;
        this->arr = new T[this->size - 1];
        this->size--;
        for(int i=0;i<this->size;i++) 
            this->arr[i] = copyArray[i];
        delete[] copyArray;
    }

template<typename T> bool DynamicArray<T> :: find(T key){
    for(int i=0;i<size;i++){
        if(arr[i] == key)
            return true;
    }
    return false;
}

template<typename T> void DynamicArray<T> :: free_memory(){
        delete [] this->arr;
        this->arr = NULL;
}
