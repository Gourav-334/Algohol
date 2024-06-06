/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */

#ifndef DSA_HPP_
	#define DSA_HPP_

#ifdef __cplusplus



#include <iostream>



namespace structures
{
	class BST
	{
		private:

			typedef struct Node {int value; struct Node*left; struct Node*right;} node;

			node*m = nullptr; node*temp = nullptr; node*temp2 = nullptr; node*head = nullptr;

			int input,comp,brk=0;

		public:

			BST();
			void insert(int input);
			void remove(int input);
			void search(int input);
			void status();
			~BST();
	};

	class LinkedList
	{
		private:

			typedef struct people {int name; struct people*next;} ppl;

			int n, ins, del, num = 0, brk = 0;

			ppl*m = nullptr; ppl*head = nullptr; ppl*temp = nullptr;

		public:

			LinkedList();
			void create(int n);
			void insert(int value, int ins);
			void remove(int del);
			void display();
			void status();
			~LinkedList();
	};

	class Stack
	{
		private:

			typedef struct people {int name; struct people*next;} ppl;

			int n, num = 0, brk = 0;

			ppl*m = nullptr; ppl*head = nullptr; ppl*temp = nullptr;

		public:

			Stack();
			void push(int input);
			void pop();
			void peek();
			void display();
			void status();
			~Stack();
	};

	class Queue
	{
		private:

			typedef struct people {int name; struct people*next;} ppl;

			int n, choice, num = 0, brk = 0;

			ppl*m = nullptr; ppl*head = nullptr; ppl*temp = nullptr;

		public:

			Queue();
			void queue(int input);
			void dequeue();
			void peek();
			void display();
			void status();
			~Queue();
	};
}

namespace search
{
	template <typename T>
	extern T linSearch(T f, T *arr, int n);

	template <typename T>
	extern T binSearch(T f, T *arr, int n);
}

namespace sort
{
	template <typename T>
	extern void bubble(T arr[], int n);

	template <typename T>
	extern void bucket(T arr[], int n);

	template <typename T>
	extern void insertion(T arr[], int n);

	template <typename T>
	extern void merge(T arr[], int n);

	template <typename T>
	extern void quick(T arr[], int n, int low=0, int high=0, bool flag=false);

	template <typename T>
	extern void radix(T arr[], int n);

	template <typename T>
	extern void selection(T arr[], int n);

	template <typename T>
	extern void shell(T arr[], int n);
}

#endif

#endif

/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */