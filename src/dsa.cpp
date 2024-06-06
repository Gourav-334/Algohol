/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */

#ifndef DSA_CPP_
	#define DSA_CPP_



#include "dsa.hpp"



//class BST

structures::BST::BST()
{
	std::cout << "A new BST is created." << std::endl;
}





void structures::BST::insert(int input)
{
	temp = head; temp2 = head; comp = 0;

	std::cout << std::endl;
	std::cout << "_____________________________________________________________";
	std::cout << std::endl << std::endl;

	if (temp==nullptr)
	{
		m = new node;

		head = m; temp = m;

		temp -> value = input;
		temp -> left = nullptr; temp -> right = nullptr;

		std::cout << temp -> value << " -> ";
	}

	else if (temp!=nullptr)
	{
		std::cout << temp -> value << " -> ";

		while (comp==0)
		{
			if (input==temp->value)
			{
				if (temp->right==nullptr)
				{
					m = new node;

					temp -> right = m; m -> value = input;
					m -> left = nullptr; m -> right = nullptr;
				}

				else if ((temp->right!=nullptr)and(temp->right->value==input)) 
				{
					temp = temp -> right;
				}

				else if ((temp->right!=nullptr)and(temp->right->value>input))
				{
					m = new node;

					m -> value = input;
					m -> left = nullptr; m -> right = temp -> right;

					temp -> right = m;
				}

				comp = 1;
			}

			else if ((input<temp->value)and(temp->left==nullptr))
			{
				m = new node;

				m -> value = input; temp -> left = m;
				temp -> left -> left = nullptr; temp -> left -> right = nullptr;
				temp = temp -> left;
				
				comp = 1;
			}

			else if ((input<temp->value)and(temp->left!=nullptr))
			{
				temp = temp -> left;
			}

			else if ((input>temp->value)and(temp->right==nullptr))
			{
				m = new node;

				m -> value = input; temp -> right = m;
				temp -> right -> left = nullptr; temp -> right -> right = nullptr;
				temp = temp -> right;

				comp = 1;
			}

			else if ((input>temp->value)and(temp->right!=nullptr))
			{
				temp = temp -> right;
			}

			else
			{
				std::cout << std::endl << "Fatal error code: 1" << std::endl << std::endl;
				comp = 1;
			}

			std::cout << temp -> value << " -> ";
		}
	}

	std::cout << "nullptr" << std::endl << std::endl;
	std::cout << "BST node inserted successfully!" << std::endl;

	std::cout << "_____________________________________________________________";
	std::cout << std::endl << std::endl;
}





void structures::BST::remove(int input)
{
	std::cout << "_____________________________________________________________";
	std::cout << std::endl << std::endl;

	temp = head; temp2 = head; comp = 0;

	while (comp==0)
	{   
		if (input==temp->value)
		{
			if ((temp->left==nullptr)and(temp->right==nullptr)) 
			{
				delete temp;

				temp = nullptr; head = nullptr;
				comp = 1;
			}

			else if ((temp->left==nullptr)and(temp->right!=nullptr))
			{
				head = head -> right;
				
				delete temp;
				comp = 1;
			}

			else if ((temp->left!=nullptr)and(temp->right==nullptr))
			{
				head = head -> left;

				delete temp;
				comp = 1;
			}

			else if ((temp->left!=nullptr)and(temp->right!=nullptr))
			{
				if (temp->right->left==nullptr)
				{
					temp -> right -> left = head -> left;
					head = temp -> right;

					delete temp;
					comp = 1;
				}

				else if (temp->right->left!=nullptr)
				{
					temp = temp -> right;

					while (temp->left!=nullptr) {temp = temp -> left;}

					head -> value = temp -> value;

					delete temp;
					comp = 1;
				}

				else
				{
					std::cout << std::endl << "Fatal error code: 2";
					std::cout << std::endl << std::endl;

					comp = 1;
				}
			}

			else
			{
				std::cout << std::endl << "Fatal error code: 3";
				std::cout << std::endl << std::endl;

				comp = 1;
			}
		}

		else if ((input<temp->value)and(input==temp->left->value))
		{
			if ((temp->left->left==nullptr)and(temp->left->right==nullptr))
			{
				temp = temp -> left;

				delete temp;
				comp = 1;
			}

			else if (((temp->left->left==nullptr)and(temp->left->right!=nullptr))or
				((temp->left->left!=nullptr)and(temp->left->right!=nullptr)))
			{
				if (temp->left->right->left==nullptr)
				{
					m = temp -> left; temp -> left = m -> right;

					delete m;
					comp = 1;
				}

				else if (temp->left->right->left!=nullptr)
				{
					temp2 = temp -> left; temp = temp -> left -> right;
					
					while (temp->left!=nullptr)
					{
						if (temp->left->left==nullptr) {m = temp;}

						temp = temp ->left;
					}

					temp2 -> value = temp -> value; m -> left = nullptr;

					delete temp;
					comp = 1;
				}

				else
				{
					std::cout << std::endl << "Fatal error code: 4";
					std::cout << std::endl << std::endl;

					comp = 1;
				}
			}

			else if ((temp->left->left!=nullptr)and(temp->left->right==nullptr))
			{
				if (temp->left->left->right==nullptr)
				{
					m = temp -> left; temp -> left = m -> left;

					delete m;
					comp = 1;
				}

				else if (temp->left->left->right!=nullptr)
				{
					temp2 = temp -> left; temp = temp -> left -> left;

					while (temp->right!=nullptr)
					{
						if (temp->right->right==nullptr) {m = temp;}

						temp = temp -> right;
					}

					temp2 -> value = temp -> value; m -> right = nullptr;

					delete temp;
					comp = 1;
				}

				else
				{
					std::cout << std::endl << "Fatal error code: 5";
					std::cout << std::endl << std::endl;

					comp = 1;
				}
			}
		}

		else if ((input<temp->value)and(input!=temp->left->value))
		{
			temp = temp -> left;
		}

		else if ((input>temp->value)and(input==temp->right->value))
		{
			if ((temp->right->left==nullptr)and(temp->right->right==nullptr))
			{
				m = temp -> right; temp -> right = nullptr;

				delete m;
				comp = 1;
			}

			else if (((temp->right->left==nullptr)and(temp->right->right!=nullptr))or
				((temp->right->left!=nullptr)and(temp->right->right!=nullptr)))
			{
				if (temp->right->right->left==nullptr)
				{
					m = temp -> right; temp -> right = m -> right;

					delete m;
					comp = 1;
				}

				else if (temp->right->right->left!=nullptr)
				{
					temp2 = temp -> right; temp = temp -> right -> right;

					while (temp->left!=nullptr)
					{
						if (temp->left->left==nullptr) {m = temp;}

						temp = temp -> left;
					}
          
					temp2 -> value = temp -> value; m -> left = nullptr;

					delete temp;
					comp = 1;
				}

				else
				{
					std::cout << std::endl << "Fatal error code: 6";
					std::cout << std::endl << std::endl;

					comp = 1;
				}
			}

			else if ((temp->right->left!=nullptr)and(temp->right->right==nullptr))
			{
				if (temp->right->left->right==nullptr)
				{
					m = temp -> right; temp -> right = temp -> right -> left;

					delete m;
					comp = 1;
				}

				else if (temp->right->left->right!=nullptr)
				{
					temp2 = temp -> right; temp = temp -> right -> left;

					while (temp->right!=nullptr)
					{
						if (temp->right->right!=nullptr) {m = temp;}

						temp = temp -> right;
					}

					temp2 -> value = temp -> value; m -> right = nullptr;

					delete temp;
					comp = 1;
				}

				else
				{
					std::cout << std::endl << "Fatal error code: 7";
					std::cout << std::endl << std::endl;

					comp = 1;
				}
			}

			else
			{
				std::cout << std::endl << "Fatal error code: 8";
				std::cout << std::endl << std::endl;

				comp = 1;
			}
		}

		else if ((input>temp->value)and(input!=temp->right->value))
		{
			std::cout << "WRONG: 1";

			temp = temp -> right;
		}

		else
		{
			std::cout << std::endl << "Fatal error code: 9";
			std::cout << std::endl << std::endl;

			comp = 1;
		}
	}

	temp = head;

	std::cout << "nullptr" << std::endl << std::endl;
	std::cout << "BST node removed successfully!" << std::endl;

	std::cout << "_____________________________________________________________";
	std::cout << std::endl << std::endl;
}





void structures::BST::search(int input)
{
	temp = head; temp2 = head; comp = 0;

	while (comp==0)
	{
		if (temp->value==input)
		{
			std::cout << std::endl << "BST node " << input << " found!" << std::endl;

			comp = 1;
			break;
		}

		if ((temp->left==nullptr)and(temp->right==nullptr))
		{
			std::cout << std::endl << "BST node " << input << " not found!" << std::endl;

			comp = 1;
			break;
		}

		else if (input<temp->value) {temp = temp -> left;}

		else if (input>temp->value) {temp = temp -> right;}
	}
}





void structures::BST::status()
{
	std::cout << "Node value: " << temp -> value << std::endl;
	std::cout << "Left address: " << temp -> left << std::endl;
	std::cout << "Right address: " << temp -> right << std::endl << std::endl;
}





structures::BST::~BST()
{
	while (head!=nullptr) {this->remove(head->value);}

	std::cout << "The BST has successfully been deleted." << std::endl;
}










//class LinkedList

structures::LinkedList::LinkedList()
{
	std::cout << "A new LinkedList is created." << std::endl;
}





void structures::LinkedList::create(int n)
{
	m = new ppl;

	head = m; temp = m;

	for (int i=1; i<=n; i++)
	{
		std::cout << "Enter node's value: ";
		std::cin >> temp -> name;

		num++;

		m = new ppl;

		if (i==n) {temp -> next = nullptr;}
		else if (i!=n) {temp -> next = m; temp = temp -> next;}

		else {std::cerr << "LinkedList create() error!";}

	}

	std::cout << std::endl;

	temp = head;
	delete m;
}




void structures::LinkedList::insert(int value, int ins)
{
	m = new ppl;
	m -> name = value;

	if (ins==0)
	{
		m -> next = head;

		head = m; temp = m;

		num++;
	}

	else if ((ins>0)and(ins<=num))
	{
		ins++;

		for (int i=1; i<=num; i++)
		{
			if (i==ins-1)
			{
				m -> next = temp -> next; temp -> next = m;

				num++;
				break;
			}

			else {temp = temp -> next;}
		}

		num++;
		temp = head;
	}

	else {std::cerr << "Invalid position!";}
}





void structures::LinkedList::remove(int del)
{
	if (del==0)
	{
		head = head -> next;

		delete temp;

		temp = head;
		num--;
	}

	else if ((del>0)and(del<=num))
	{
		del++;

		for (int i=1; i<=num; i++)
		{
			if (i==del-1)
			{
				m = temp -> next; temp -> next = temp -> next -> next;

				break;
			}
			
			else {temp = temp -> next;}
		}

		delete m;

		num--;
		temp = head;
	}

	else {std::cerr << "Invalid position!";}
}





void structures::LinkedList::display()
{
	std::cout << "__________________________________________________________________";
	std::cout << std::endl;

	while (temp -> next != nullptr)
	{
		status();

		temp = temp -> next;
	}

	status();

	std::cout << "__________________________________________________________________";
	std::cout << std::endl << std::endl;

	temp = head;
}





void structures::LinkedList::status()
{
	std::cout << "Node value: " << temp -> name << std::endl;
	std::cout << "Next address: " << temp -> next << std::endl << std::endl;
}





structures::LinkedList::~LinkedList()
{
	while (num!=0) {this->remove(num-1);}

	std::cout << "The LinkedList has been deleted.";
}










//class Stack

structures::Stack::Stack()
{
	std::cout << "A new Stack is created." << std::endl;
}





void structures::Stack::push(int input)
{
	m = new ppl;

	m -> name = input; m -> next = nullptr;

	if (num==0) {head = m;}

	else if (num>=1)
	{
		while (temp->next != nullptr) {temp = temp -> next;}

		temp -> next = m;
	}

	else {std::cerr << "Stack push() error!";}

	num++;
	temp = head;
}





void structures::Stack::pop()
{
	if (num>1)
	{
		while (temp->next->next != nullptr) {temp = temp -> next;}

		delete temp->next;

		num--;

		temp -> next = nullptr;
		temp = head;
	}

	else if (num==1) {delete temp; num--;}

	else if (num==0) {std::cout << "Stack underflow!" << std::endl;}

	else {std::cerr << "Stack pop() error!";}
}





void structures::Stack::peek()
{
	if (num>=1)
	{
		std::cout << "__________________________________________________________________";
		std::cout << std::endl;

		while (temp -> next != nullptr) {temp = temp -> next;}

		status();

		std::cout << "__________________________________________________________________";
		std::cout << std::endl << std::endl;

		temp = head;
	}

	else if (num==0) {std::cout << "No node present!" << std::endl;}

	else {std::cerr << "Stack peek() error!";}
}





void structures::Stack::display()
{
	if (num>0)
	{
		std::cout << "__________________________________________________________________";
		std::cout << std::endl;

		while (temp -> next != nullptr)
		{
			status();

			temp = temp -> next;
		}

		status();

		std::cout << "__________________________________________________________________";
		std::cout << std::endl << std::endl;

		temp = head;
	}

	else if (num==0) {std::cout << "No node present!" << std::endl;}

	else {std::cerr << "Stack display() error!";}
}





void structures::Stack::status()
{
	std::cout << "Node value: " << temp -> name << std::endl;
	std::cout << "Next address: " << temp -> next << std::endl << std::endl;
}





structures::Stack::~Stack()
{
	while (num!=0) {this->pop();}

	std::cout << "The Stack has been deleted.";
}










//class Queue

structures::Queue::Queue()
{
	std::cout << "A new Queue is created." << std::endl;
}





void structures::Queue::queue(int input)
{
	m = new ppl;

	m -> name = input; m -> next = nullptr;

	if (num==0) {head = m;}

	else if (num>=1)
	{
		while (temp->next != nullptr) {temp = temp -> next;}

		temp -> next = m;
	}

	else {std::cerr << "Queue queue() error!";}

	num++;
	temp = head;
}





void structures::Queue::dequeue()
{
	if (num>0)
	{
		head = head -> next;

		delete temp;

		temp = head;
		num--;
	}

	else if (num==0) {std::cout << "Empty queue!" << std::endl;}

	else {std::cerr << "Queue dequeue() error!";}
}





void structures::Queue::peek()
{
	if (num>=1)
	{
		std::cout << "__________________________________________________________________";
		std::cout << std::endl;

		while (temp -> next != nullptr) {temp = temp -> next;}

		status();

		std::cout << "__________________________________________________________________";
		std::cout << std::endl << std::endl;

		temp = head;
	}

	else if (num==0) {std::cout << "No node present!";}

	else {std::cerr << "Queue peek() error!";}
}





void structures::Queue::display()
{
	if (num>0)
	{
		std::cout << "__________________________________________________________________";
		std::cout << std::endl;

		while (temp -> next != nullptr)
		{
			status();

			temp = temp -> next;
		}

		status();

		std::cout << "__________________________________________________________________";
		std::cout << std::endl << std::endl;

		temp = head;
	}

	else if (num==0) {std::cout << "No node present!" << std::endl;}

	else {std::cerr << "Queue display() error!";}
}





void structures::Queue::status()
{
	std::cout << "Node value: " << temp -> name << std::endl;
	std::cout << "Next address: " << temp -> next << std::endl << std::endl;
}





structures::Queue::~Queue()
{
	while (num!=0) {this->dequeue();}

	std::cout << "The Queue has been deleted.";
}










//Linear searching
template <typename T>

T search::linSearch(T f, T *arr, int n)
{
	int j=0, found=0;

	for (int i=0; i<n; i++)
	{
		if (arr[i]==f)
		{
			std::cout << f << " found at index " << i;

			j = i; found = 1;

			break;
		}
	}

	if (found==0) {std::cout << f << " not found in the array.";}

	return j;
}





//Binary searching
template <typename T>

T search::binSearch(T f, T *arr, int n)
{
	int found=0, start=0, end=n-1;

	for (int i=start; i<=end; i++)
	{
		n = (start + end)/2;

		if (arr[n]==f)
		{
			std::cout << f << " found at index " << n;

			found = 1;

			break;
		}
		
		else if (f<arr[n]) {end = n-1;}

		else if (f>arr[n]) {start = n+1;}

		else {std::cout << "Error code 1.";}
	}

	if (found==0) {std::cout << std::endl << f << " not found!" << std::endl;}

	return n;
}










//Bubble sorting
template <typename T>

void sort::bubble(T arr[], int n)
{
	T temp;

	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<n-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
			}
		}
	}
}










//Bucket sorting
template <typename T>

void sort::bucket(T arr[], int n)
{
	int d = 1, arr2[n], arr3[n], flag = 0;

    for (int j=0; j<n; j++) {arr2[j] = arr[j];}
    for (int j=0; j<n; j++) {arr3[j] = arr[j];}

    while (flag == 0)
    {
    	for (int j=0; j<n; j++) {arr2[j] = arr3[j] % 10;}
    	
    	int temp;

		for (int i=0; i<n-1; i++)
		{
			if (arr2[i]<=arr2[i+1]) {continue;}

			if (arr2[i]>arr2[i+1])
			{
				temp = arr2[i]; arr2[i] = arr2[i+1]; arr2[i+1] = temp;
				temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
				temp = arr3[i]; arr3[i] = arr3[i+1]; arr3[i+1] = temp;

				i -= 2;
			}
		}

    	for (int j=0; j<n; j++) {arr3[j] /= 10;}

    	for (int j=0; j<n; j++)
    	{
    		if (arr3[j] != 0) {break;}

    		else if (j==n-1) {flag = 1;}
    	}

    	d++;
    }
}










//Insertion sorting
template <typename T>

void sort::insertion(T arr[], int n)
{
	T temp;

	for (int i=0; i<n-1; i++)
	{
		if (arr[i]<=arr[i+1]) {continue;}

		if (arr[i]>arr[i+1])
		{
			temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;

			i -= 2;
		}
	}
}










//Merge sorting
template <typename T>

void sort::merge(T arr[], int n)
{
	T temp;

	int part = 2, low = 0, high = part-1, flag = 0;

	while (flag != 1)
	{
		if (part > n)
		{
			part = n; low = 0; high = part-1;

			for (int i=low; i<high; i++)
			{
				if (arr[i]<=arr[i+1]) {continue;}

				if (arr[i]>arr[i+1])
				{
					temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;

					if (i-1 >= low) {i -= 2;}
				}
			}

			flag = 1;
		}

		else if (n-1-high >= part)
		{
			for (int i=low; i<high; i++)
			{
				if (arr[i]<=arr[i+1]) {continue;}

				if (arr[i]>arr[i+1])
				{
					temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;

					if (i-1 >= low) {i -= 2;}
				}
			}

			low += part; high += part;
		}

		else if (n-1-high < part)
		{
			for (int i=low; i<high; i++)
			{
				if (arr[i]<=arr[i+1]) {continue;}

				if (arr[i]>arr[i+1])
				{
					temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;

					if (i-1 >= low) {i -= 2;}
				}
			}

			low += part; high = n-1;

			if (low < n)
			{
				for (int i=low; i<high; i++)
				{
					if (arr[i]<=arr[i+1]) {continue;}

					if (arr[i]>arr[i+1])
					{
						temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;

						if (i-1 >= low) {i -= 2;}
					}
				}
			}

			part *= 2;

			low = 0; high = part-1;
		}
	}
}










//Quick sorting
template <typename T>

void sort::quick(T arr[], int n, int low=0, int high=0, bool flag=false)
{
	if (flag==false) {high = n-1;}

	T pivot = arr[high];

	int left = low, right = high, l=0, r=0, exact;
    T arr2[n];

    for (int i=0; i<n; i++) {arr2[i] = arr[i];}

    for (int i=low; i<=high-1; i++)
    {
        if (arr2[i] <= pivot)
        {
        	arr[left] = arr2[i];

        	left++; l++;
        }

        else if (arr2[i] > pivot)
        {
        	arr[right] = arr2[i];

        	right--; r++;
        }
    }

    arr[left] = pivot; exact = left;
    
    if (l>1) {quick(arr,n,low,exact-1,true);}
    if (r>1) {quick(arr,n,exact+1,high,true);}

    else {return;}
}










//Radix sorting
template <typename T>

void sort::radix(T arr[], int n)
{
	int d = 1, arr2[n], arr3[n], flag = 0;

    for (int j=0; j<n; j++) {arr2[j] = arr[j];}
    for (int j=0; j<n; j++) {arr3[j] = arr[j];}

    while (flag == 0)
    {
    	for (int j=0; j<n; j++) {arr2[j] = arr3[j] % 10;}
    	
    	T temp;

		for (int i=0; i<n-1; i++)
		{
			if (arr2[i]<=arr2[i+1]) {continue;}

			if (arr2[i]>arr2[i+1])
			{
				temp = arr2[i]; arr2[i] = arr2[i+1]; arr2[i+1] = temp;
				temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
				temp = arr3[i]; arr3[i] = arr3[i+1]; arr3[i+1] = temp;

				i -= 2;
			}
		}

    	for (int j=0; j<n; j++) {arr3[j] /= 10;}

    	for (int j=0; j<n; j++)
    	{
    		if (arr3[j] != 0) {break;}

    		else if (j==n-1) {flag = 1;}
    	}

    	d++;
    }
}










//Selection sorting
template <typename T>

void sort::selection(T arr[], int n)
{
	T s, temp;
	int f,k;
	
	for (int i=0; i<n; i++)
	{
		f = 0; s = arr[i];

		for (int j=i; j<n; j++)
		{
			if (arr[j]<s) {f = 1; s = arr[j]; k = j;}
		}

		if (f==1) {temp = arr[i]; arr[i] = arr[k]; arr[k] = temp;}
	}
}










//Shell sorting
template <typename T>

void sort::shell(T arr[], int n)
{
	T temp;

	for (int i=0; i<n/2; i++)
	{	
		if (n%2==0)
		{
			if (i+(n/2)<n)
			{
				if (arr[i]>arr[i+(n/2)])
				{
					temp = arr[i];
					arr[i] = arr[i+(n/2)];
					arr[i+(n/2)] = temp;
				}
			}
		}

		if (n%2==1)
		{
			if (i+1+(n/2)<n)
			{
				if (arr[i]>arr[i+1+(n/2)])
				{
					temp = arr[i];
					arr[i] = arr[i+1+(n/2)];
					arr[i+1+(n/2)] = temp;
				}
			}
		}
	}

	for (int i=0; i<n-2; i++)
	{
		if (arr[i]<=arr[i+2]) {i++; continue;}

		if (arr[i]>arr[i+2])
		{
			temp = arr[i];
			arr[i] = arr[i+2];
			arr[i+2] = temp;

			i -= 3;
		}
	}

	for (int i=1; i<n-2; i++)
	{
		if (arr[i]<=arr[i+2]) {i++; continue;}

		if (arr[i]>arr[i+2])
		{
			temp = arr[i];
			arr[i] = arr[i+2];
			arr[i+2] = temp;
			
			i -= 3;
		}
	}

	for (int i=0; i<n-1; i++)
	{
		if (arr[i]<=arr[i+1]) {continue;}

		if (arr[i]>arr[i+1])
		{
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;

			i -= 2;
		}
	}
}



#endif

/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */