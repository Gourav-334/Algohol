/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */

#ifndef ML_CPP_
	#define ML_CPP_



#include "ml.hpp"

//Adding data to dataset
void regressions::SimLinReg::add(float x, float y)
{
	trav = m;
	m = (node*)malloc(sizeof(node));

	if(n>0) {trav -> next = m; m -> prev = trav; m -> next = NULL;}
	if(n==0) {head = m;}

	m -> x = x; m -> y = y;
	n++;

	trav = head;

	printf("(%f,%f) added to the dataset successfully!\n", x,y);
}










//Removing data from dataset
void regressions::SimLinReg::remove(float x, float y)
{
	while (trav->next!=NULL)
	{
		if ((trav->x==x)&&(trav->y==y))
		{
			if ((trav->prev==NULL)&&(trav->next!=NULL))
				{trav -> next -> prev = NULL; free(trav);}

			else if ((trav->prev!=NULL)&&(trav->next!=NULL))
			{
				trav -> prev -> next = trav -> next;
				trav -> next -> prev = trav -> prev;
				free(trav);
			}

			else {perror("Unknown removal condition 1!");}

			n--; found = 1;
			printf("Data (%f,%f) removed from dataset successfully!\n", x,y);

			break;
		}

		else if ((trav->x!=x)||(trav->y!=y)) {trav = trav -> next;}
		else {perror("Pair matching issue 1!");}
	}

	if ((found==0)&&((trav->x==x)&&(trav->y==y)))
	{
		if ((trav->prev==NULL)&&(trav->next==NULL)) {free(trav);}

		else if ((trav->prev!=NULL)&&(trav->next==NULL))
				{trav -> prev -> next = NULL; free(trav);}

		else {perror("Pair matching issue 2!");}

		n--; found = 1;
		printf("Data (%f,%f) removed from dataset successfully!\n", x,y);
	}

	else if ((found==0)&&((trav->x!=x)||(trav->y!=y)))
		{printf("Pair (%f,%f) not found in your dataset.\n", x,y);}

	else if (found==1) {found = 0;}
	else {perror("Unknown removal condition 2!");}

	trav = head;
}










void regressions::SimLinReg::find(float x, float y)
{
	while (trav->next!=NULL)
	{
		if ((trav->x==x)&&(trav->y==y))
		{
			found = 1;
			printf("Pair (%f,%f) found in your dataset!\n", x,y);

			break;
		}

		else if ((trav->x!=x)||(trav->y!=y)) {trav = trav -> next;}
		else {perror("Pair matching issue 1!");}
	}

	if ((found==0)&&((trav->x==x)&&(trav->y==y)))
	{
		found = 1;
		printf("Pair (%f,%f) found in your dataset!\n", x,y);
	}

	else if ((found==0)&&((trav->x!=x)||(trav->y!=y)))
		{printf("Pair (%f,%f) not found in your dataset.\n", x,y);}

	else if (found==1) {found = 0;}
	else {perror("Unknown removal condition 2!");}

	trav = head;
}










//Predicting the next outcome as per available dataset.
int regressions::SimLinReg::predict(char axis, float input)
{
	while (trav->next!=NULL)
	{
		sum_x = 0; sum_y = 0; sum_xy = 0; sum_x_s = 0; sum_y_s = 0;
		sum_x += trav -> x; sum_y += trav -> y;
		sum_xy += (trav -> x)*(trav -> y);
		sum_x_s += (trav -> x)*(trav -> x);
		sum_y_s += (trav -> y)*(trav -> y);

		trav = trav -> next;
	}

	sum_x += trav -> x; sum_y += trav -> y;
	sum_xy += (trav -> x)*(trav -> y);
	sum_x_s += (trav -> x)*(trav -> x);
	sum_y_s += (trav -> y)*(trav -> y);

	trav = head;

	a = ((n*sum_xy)-(sum_x*sum_y))/((n*sum_x_s)-(sum_x*sum_x));
	b = (sum_y-(b*sum_x))/n;

	if (axis=='x')
	{
		y = input;

		x = (y-a)/b; x = abs(x);
		printf("For \'y\' = %f, \'x\' must be %f\n", y,x);

		return y;
	}

	else if (axis=='y')
	{
		x = input;

		y = a+(b*x); y = abs(y);
		printf("For \'x\' = %f, \'y\' must be %f\n", x,y);
		
		return x;
	}

	else {perror("Unknown axis used in prediction!"); return NULL;}
}



#endif

/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */