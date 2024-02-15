/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */

#ifndef ML_HPP_
	#define ML_HPP_

#ifdef __cplusplus



#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

namespace regressions
{
	//Here, SimLinReg stands for "Simple Linear Regression"
	class SimLinReg
	{
		private:
			float a,b,x,y;
			int n=0,found=0,count=0;
			float sum_x,sum_y,sum_xy,sum_x_s,sum_y_s;

			typedef struct Node {float x,y; struct Node *prev,*next;} node;

			node *m=NULL, *head=NULL, *trav=NULL;

		public:
			void add(float x, float y);
			void remove(float x, float y);
			void find(float x, float y);
			int predict(char axis, float input);
	};
}



#endif

#endif

/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */