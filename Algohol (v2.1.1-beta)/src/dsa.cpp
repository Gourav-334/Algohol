/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */

#ifndef DSA_CPP_
	#define DSA_CPP_



#include "dsa.hpp"

//class BST
void structures::BST::insert(int input)
{
	temp = head; temp2 = head; comp = 0;
	printf("\n");
	printf("_____________________________________________________________\n\n");

	if (temp==NULL)
	{
		m = (node*)malloc(sizeof(node));
		head = m; temp = m;
		temp -> value = input;
		temp -> left = NULL; temp -> right = NULL;
		printf("%d -> ", temp -> value);
	}

	else if (temp!=NULL)
	{
		printf("%d -> ", temp -> value);

		while (comp==0)
		{
			if (input==temp->value)
			{
				if (temp->right==NULL)
				{
					m = (node*)malloc(sizeof(node));
					temp -> right = m; m -> value = input;
					m -> left = NULL; m -> right = NULL;
				}

				else if ((temp->right!=NULL)&&(temp->right->value==input)) 
					{temp = temp -> right;}

				else if ((temp->right!=NULL)&&(temp->right->value>input))
				{
					m = (node*)malloc(sizeof(node));
					m -> value = input;
					m -> left = NULL; m -> right = temp -> right;
					temp -> right = m;
				}

				comp = 1;
			}

			else if ((input<temp->value)&&(temp->left==NULL))
			{
				m = (node*)malloc(sizeof(node)); m -> value = input;
				temp -> left = m;
				temp -> left -> left = NULL; temp -> left -> right = NULL;
				temp = temp -> left;
				
				comp = 1;
			}

			else if ((input<temp->value)&&(temp->left!=NULL))
				{temp = temp -> left;}

			else if ((input>temp->value)&&(temp->right==NULL))
			{
				m = (node*)malloc(sizeof(node));
				m -> value = input; temp -> right = m;
				temp -> right -> left = NULL; temp -> right -> right = NULL;
				temp = temp -> right;

				comp = 1;
			}

			else if ((input>temp->value)&&(temp->right!=NULL))
				{temp = temp -> right;}

			else {printf("\nFatal error code: 1\n\n"); comp = 1;}

			printf("%d -> ", temp -> value);
		}
	}

	printf("NULL\n\nBST node inserted successfully!");
	printf("\n_____________________________________________________________\n\n");
}





void structures::BST::remove(int input)
{
	printf("_____________________________________________________________\n\n");
	temp = head; temp2 = head; comp = 0;

	while (comp==0)
	{
	    printf("%d -> ", temp -> value);
	    
		if (input==temp->value)
		{
			if ((temp->left==NULL)&&(temp->right==NULL)) 
				{free(temp); temp = NULL; head = NULL; comp = 1;}

			else if ((temp->left==NULL)&&(temp->right!=NULL))
				{head = head -> right; free(temp); comp = 1;}

			else if ((temp->left!=NULL)&&(temp->right==NULL))
				{head = head -> left; free(temp); comp = 1;}

			else if ((temp->left!=NULL)&&(temp->right!=NULL))
			{
				if (temp->right->left==NULL)
				{
					temp -> right -> left = head -> left;
					head = temp -> right; free(temp); comp = 1;
				}

				else if (temp->right->left!=NULL)
				{
					temp = temp -> right;
					while (temp->left!=NULL) {temp = temp -> left;}
					head -> value = temp -> value; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 2\n\n"); comp = 1;}
			}

			else {printf("\nFatal error code: 3\n\n"); comp = 1;}
		}

		else if ((input<temp->value)&&(input==temp->left->value))
		{
			if ((temp->left->left==NULL)&&(temp->left->right==NULL))
				{temp = temp -> left; free(temp); comp = 1;}

			else if (((temp->left->left==NULL)&&(temp->left->right!=NULL))||
				((temp->left->left!=NULL)&&(temp->left->right!=NULL)))
			{
				if (temp->left->right->left==NULL)
					{m = temp -> left; temp -> left = m -> right; free(m); comp = 1;}

				else if (temp->left->right->left!=NULL)
				{
					temp2 = temp -> left; temp = temp -> left -> right;
					
					while (temp->left!=NULL)
						{if (temp->left->left==NULL) {m = temp;} temp = temp ->left;}

					temp2 -> value = temp -> value; m -> left = NULL; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 4\n\n"); comp = 1;}
			}

			else if ((temp->left->left!=NULL)&&(temp->left->right==NULL))
			{
				if (temp->left->left->right==NULL)
					{m = temp -> left; temp -> left = m -> left; free(m); comp = 1;}

				else if (temp->left->left->right!=NULL)
				{
					temp2 = temp -> left; temp = temp -> left -> left;

					while (temp->right!=NULL)
						{if (temp->right->right==NULL) {m = temp;} temp = temp -> right;}

					temp2 -> value = temp -> value; m -> right = NULL; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 5\n\n"); comp = 1;}
			}
		}

		else if ((input<temp->value)&&(input!=temp->left->value)) {temp = temp -> left;}

		else if ((input>temp->value)&&(input==temp->right->value))
		{
			if ((temp->right->left==NULL)&&(temp->right->right==NULL))
				{m = temp -> right; temp -> right = NULL; free(m); comp = 1;}

			else if (((temp->right->left==NULL)&&(temp->right->right!=NULL))||
				((temp->right->left!=NULL)&&(temp->right->right!=NULL)))
			{
				if (temp->right->right->left==NULL)
					{m = temp -> right; temp -> right = m -> right; free(m); comp = 1;}

				else if (temp->right->right->left!=NULL)
				{
					temp2 = temp -> right; temp = temp -> right -> right;

					while (temp->left!=NULL)
						{if (temp->left->left==NULL) {m = temp;} temp = temp -> left;}
          
					temp2 -> value = temp -> value; m -> left = NULL; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 6\n\n"); comp = 1;}
			}

			else if ((temp->right->left!=NULL)&&(temp->right->right==NULL))
			{
				if (temp->right->left->right==NULL)
					{m = temp -> right; temp -> right = temp -> right -> left; free(m); comp = 1;}

				else if (temp->right->left->right!=NULL)
				{
					temp2 = temp -> right; temp = temp -> right -> left;

					while (temp->right!=NULL)
						{if (temp->right->right!=NULL) {m = temp;} temp = temp -> right;}

					temp2 -> value = temp -> value; m -> right = NULL; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 7\n\n"); comp = 1;}
			}

			else {printf("\nFatal error code: 8\n\n"); comp = 1;}
		}

		else if ((input>temp->value)&&(input!=temp->right->value))
			{printf("WRONG: 1"); temp = temp -> right;}

		else {printf("\nFatal error code: 9\n\n"); comp = 1;}
		printf("%d -> ", temp -> value);
	}

	printf("NULL\n\nBST node removed successfully!");
	printf("\n_____________________________________________________________\n\n");
}





void structures::BST::search(int input)
{
	temp = head; temp2 = head; comp = 0;

	while (comp==0)
	{
		if (temp->value==input) {printf("\nBST node %d found!\n", input); comp = 1; break;}

		if ((temp->left==NULL)&&(temp->right==NULL))
			{printf("\nBST node %d not found!\n", input); comp = 1; break;}

		else if (input<temp->value) {temp = temp -> left;}
		else if (input>temp->value) {temp = temp -> right;}
	}
}










//class LinkedList
void structures::LinkedList::create(int n)
{
	m = (ppl*)malloc(sizeof(ppl)); head = m; temp = m;

	for (int i=1; i<=n; i++)
	{
		printf("Enter node's value: "); scanf("%d", &temp -> name); num++;
		m = (ppl*)malloc(sizeof(ppl));
		if (i==n) {temp -> next = NULL;}
		else if (i!=n) {temp -> next = m; temp = temp -> next;}
	} printf("\n"); temp = head; free(m);
}





void structures::LinkedList::insert(int value, int ins)
{
	m = (ppl*)malloc(sizeof(ppl));
	m -> name = value;

	if (ins==0)
	{
		m -> next = head;
		head = m; temp = m;
		num++;
	}

	else if ((ins>0)&&(ins<=num))
	{
		ins++;
		for (int i=1; i<=num; i++)
		{
			if (i==ins-1) {m -> next = temp -> next; temp -> next = m; num++; break;}
			else {temp = temp -> next;}
		} num++; temp = head;
	}

	else {printf("Invalid position!\n");}
}





void structures::LinkedList::remove(int del)
{
	if (del==0) {head = head -> next; free(temp); temp = head;}

	else if ((del>0)&&(del<=num))
	{
		del++;
		for (int i=1; i<=num; i++)
		{
			if (i==del-1) {m = temp -> next; temp -> next = temp -> next -> next; break;}
			else {temp = temp -> next;}
		} free(m); num--; temp = head;
	}

	else {printf("Invalid position!\n");}
}





void structures::LinkedList::display()
{
	printf("__________________________________________________________________\n");
	while (temp -> next != NULL)
	{
		printf("Node value: %d\nNext address: %d\n\n", temp -> name, temp -> next);
		temp = temp -> next;
	} printf("Node value: %d\nNext address: %d\n\n", temp -> name, temp -> next);
	printf("__________________________________________________________________\n\n");
	temp = head;
}










//class Stack
void structures::Stack::push(int input)
{
	m = (ppl*)malloc(sizeof(ppl)); m -> name = input; m -> next = NULL;

	if (num==0) {head = m;}

	else if (num>=1)
	{
		while (temp->next != NULL) {temp = temp -> next;}
		temp -> next = m;
	}

	num++; temp = head;
}





void structures::Stack::pop()
{
	if (num>1)
	{
		while (temp->next->next != NULL) {temp = temp -> next;}
		free(temp->next); num--; temp -> next = NULL; temp = head;
	}

	else if (num==1) {free(temp); num--;}

	else if (num==0) {printf("Stack underflow!\n");}
}





void structures::Stack::peek()
{
	if (num>=1)
	{
		printf("__________________________________________________________________\n");
		while (temp -> next != NULL) {temp = temp -> next;}
		printf("Node value: %d\nNext address: %d\n\n", temp -> name, temp -> next);
		printf("__________________________________________________________________\n\n");
		temp = head;
	}

	else if (num==0) {printf("No node present!\n");}
}





void structures::Stack::display()
{
	if (num>0)
	{
		printf("__________________________________________________________________\n");
		while (temp -> next != NULL)
		{
			printf("Node value: %d\nNext address: %d\n\n", temp -> name, temp -> next);
			temp = temp -> next;
		} printf("Node value: %d\nNext address: %d\n\n", temp -> name, temp -> next);
		printf("__________________________________________________________________\n\n");
		temp = head;
	}

	else if (num==0) {printf("No node present!\n");}
}










//class Queue
void structures::Queue::queue(int input)
{
	m = (ppl*)malloc(sizeof(ppl)); m -> name = input; m -> next = NULL;

	if (num==0) {head = m;}

	else if (num>=1)
	{
		while (temp->next != NULL) {temp = temp -> next;}
		temp -> next = m;
	}

	num++; temp = head;
}





void structures::Queue::dequeue()
{
	if (num>0) {head = head -> next; free(temp); temp = head; num--;}
	else if (num==0) {printf("Empty queue!\n");}
}





void structures::Queue::peek()
{
	if (num>=1)
	{
		printf("__________________________________________________________________\n");
		while (temp -> next != NULL) {temp = temp -> next;}
		printf("Node value: %d\nNext address: %d\n\n", temp -> name, temp -> next);
		printf("__________________________________________________________________\n\n");
		temp = head;
	}

	else if (num==0) {printf("No node present!\n");}
}





void structures::Queue::display()
{
	if (num>0)
	{
		printf("__________________________________________________________________\n");
		while (temp -> next != NULL)
		{
			printf("Node value: %d\nNext address: %d\n\n", temp -> name, temp -> next);
			temp = temp -> next;
		} printf("Node value: %d\nNext address: %d\n\n", temp -> name, temp -> next);
		printf("__________________________________________________________________\n\n");
		temp = head;
	}

	else if (num==0) {printf("No node present!\n");}
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
			cout << f << " found at index " << i;
			j = i; found = 1;
			break;
		}
	}

	if (found==0) {cout << f << " not found in the array.";}

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
			cout << f << " found at index " << n;
			found = 1; break;
		}
		
		else if (f<arr[n]) {end = n - 1;}
		else if (f>arr[n]) {start = n + 1;}

		else {printf("Error code 1.");}
	}

	if (found==0) {cout << endl << f << " not found!" << endl;}

	return n;
}










//Bubble sorting
template <typename T>
void sort::bubble(T arr[], int n)
{
	int temp;

	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<n-i-1; j++)
		{
			if (arr[j]>arr[j+1]) {temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;}
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
    	for (int j=0; j<n; j++) {if (arr3[j] != 0) {break;} else if (j==n-1) {flag = 1;}}
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

			part *= 2; low = 0; high = part-1;
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
    T arr2[n]; for (int i=0; i<n; i++) {arr2[i] = arr[i];}

    for (int i=low; i<=high-1; i++)
    {
        if (arr2[i] <= pivot) {arr[left] = arr2[i]; left++; l++;}
        else if (arr2[i] > pivot) {arr[right] = arr2[i]; right--; r++;}
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
    	for (int j=0; j<n; j++) {if (arr3[j] != 0) {break;} else if (j==n-1) {flag = 1;}}
    	d++;
    }
}










//Selection sorting
template <typename T>
void sort::selection(T arr[], int n)
{
	T s; int f,k,temp;
	
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
					temp = arr[i]; arr[i] = arr[i+(n/2)]; arr[i+(n/2)] = temp;
				}
			}
		}

		if (n%2==1)
		{
			if (i+1+(n/2)<n)
			{
				if (arr[i]>arr[i+1+(n/2)])
				{
					temp = arr[i]; arr[i] = arr[i+1+(n/2)]; arr[i+1+(n/2)] = temp;
				}
			}
		}
	}

	for (int i=0; i<n-2; i++)
	{
		if (arr[i]<=arr[i+2]) {i++; continue;}

		if (arr[i]>arr[i+2])
		{
			temp = arr[i]; arr[i] = arr[i+2]; arr[i+2] = temp;
			i -= 3;
		}
	}

	for (int i=1; i<n-2; i++)
	{
		if (arr[i]<=arr[i+2]) {i++; continue;}

		if (arr[i]>arr[i+2])
		{
			temp = arr[i]; arr[i] = arr[i+2]; arr[i+2] = temp;
			i -= 3;
		}
	}

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



#endif

/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */