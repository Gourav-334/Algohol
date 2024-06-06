/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */

#ifndef ML_HPP_
	#define ML_HPP_

#ifdef __cplusplus



#include <iostream>
#include <cmath>



/* "SimLinReg" stands for "Simple linear regression". */



namespace regressions
{
	class SimLinReg
	{
		private:

			float a,b,x,y;
			int n=0,found=0,count=0;
			float sum_x,sum_y,sum_xy,sum_x_s,sum_y_s;

			typedef struct Node {float x,y; struct Node *prev=nullptr,*next=nullptr;} node;

			node *m=nullptr, *head=nullptr, *trav=nullptr;

		public:

			SimLinReg();
			void add(float x, float y);
			void remove(float x, float y);
			void find(float x, float y);
			void import(std::string file);
			// void extract(char *file);
			int predict(char axis, float input);
			void display();
			void status();
			~SimLinReg();
	};
}



#endif

#endif

/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */