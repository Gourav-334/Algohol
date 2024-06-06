/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */

#ifndef DSA_HPP_
	#define DSA_HPP_

#ifdef __cplusplus



#ifdef SHARED
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT __declspec(dllimport)
#endif



#include <iostream>



namespace structures
{
	class EXPORT BST
	{
		private:

			typedef struct Node {int value; struct Node*left; struct Node*right;} node;

			node*m = NULL; node*temp = NULL; node*temp2 = NULL; node*head = NULL;

			int input,comp,brk=0;

		public:

			BST();
			void insert(int input);
			void remove(int input);
			void search(int input);
			void status();
			~BST();
	};

	class EXPORT LinkedList
	{
		private:

			typedef struct people {int name; struct people*next;} ppl;

			int n, ins, del, num = 0, brk = 0;

			ppl*m = NULL; ppl*head = NULL; ppl*temp = NULL;

		public:

			LinkedList();
			void create(int n);
			void insert(int value, int ins);
			void remove(int del);
			void display();
			void status();
			~LinkedList();
	};

	class EXPORT Stack
	{
		private:

			typedef struct people {int name; struct people*next;} ppl;

			int n, num = 0, brk = 0;

			ppl*m = NULL; ppl*head = NULL; ppl*temp = NULL;

		public:

			Stack();
			void push(int input);
			void pop();
			void peek();
			void display();
			void status();
			~Stack();
	};

	class EXPORT Queue
	{
		private:

			typedef struct people {int name; struct people*next;} ppl;

			int n, choice, num = 0, brk = 0;

			ppl*m = NULL; ppl*head = NULL; ppl*temp = NULL;

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
	extern __declspec(dllexport) T linSearch(T f, T *arr, int n);

	template <typename T>
	extern __declspec(dllexport) T binSearch(T f, T *arr, int n);
}

namespace sort
{
	template <typename T>
	extern __declspec(dllexport) void bubble(T arr[], int n);

	template <typename T>
	extern __declspec(dllexport) void bucket(T arr[], int n);

	template <typename T>
	extern __declspec(dllexport) void insertion(T arr[], int n);

	template <typename T>
	extern __declspec(dllexport) void merge(T arr[], int n);

	template <typename T>
	extern __declspec(dllexport) void quick(T arr[], int n, int low=0, int high=0, bool flag=false);

	template <typename T>
	extern __declspec(dllexport) void radix(T arr[], int n);

	template <typename T>
	extern __declspec(dllexport) void selection(T arr[], int n);

	template <typename T>
	extern __declspec(dllexport) void shell(T arr[], int n);
}

#endif

#endif

/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */