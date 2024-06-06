/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */

#ifndef ML_CPP_
	#define ML_CPP_



#include "ml.hpp"



//Class SimLinReg

regressions::SimLinReg::SimLinReg()
{
	std::cout << "A new simple linear regression model space is generated." << std::endl;
}





void regressions::SimLinReg::add(float x, float y)
{
	trav = m;

	m = new node;

	if (n==0)
	{
		head = m;

		m -> prev = nullptr; m -> next = nullptr;
	}

	else if (n>0)
	{
		trav -> next = m;
		m -> prev = trav; m -> next = nullptr;
	}

	m -> x = x; m -> y = y;

	n++;

	trav = head;

	std::cout << "(" << x << "," << y << ") added to the dataset successfully!";
	std::cout << std::endl;
}





void regressions::SimLinReg::remove(float x, float y)
{
	while (trav->next!=nullptr)
	{
		if ((trav->x==x)and(trav->y==y))
		{
			if ((trav->prev==nullptr)and(trav->next!=nullptr))
			{
				trav -> next -> prev = nullptr; head = head -> next;

				delete trav;
			}

			else if ((trav->prev!=nullptr)and(trav->next!=nullptr))
			{
				trav -> prev -> next = trav -> next;
				trav -> next -> prev = trav -> prev;

				delete trav;
			}

			else {std::cerr << "Unknown removal condition 1!";}

			n--;

			found = 1;

			std::cout << "(" << x << "," << y << ") removed from the dataset successfully!";
			std::cout << std::endl;

			break;
		}

		else if ((trav->x!=x)or(trav->y!=y)) {trav = trav -> next;}

		else {std::cerr << "Pair matching issue 1!";}
	}

	if ((found==0)and((trav->x==x)and(trav->y==y)))
	{
		if ((trav->prev==nullptr)and(trav->next==nullptr)) {delete trav;}

		else if ((trav->prev!=nullptr)and(trav->next==nullptr))
		{
			trav -> prev -> next = nullptr;

			delete trav;
		}

		else {std::cerr << "Pair matching issue 2!";}

		n--;

		found = 1;

		std::cout << "(" << x << "," << y << ") removed from the dataset successfully!";
		std::cout << std::endl;
	}

	else if ((found==0)and((trav->x!=x)or(trav->y!=y)))
	{
		std::cout << "Pair (" << x << "," << y << ") not found in your dataset.";
		std::cout << std::endl;
	}

	else if (found==1) {found = 0;}

	else {std::cerr << "Unknown removal condition 2!";}

	trav = head;
}





void regressions::SimLinReg::find(float x, float y)
{
	while (trav->next!=nullptr)
	{
		if ((trav->x==x)and(trav->y==y))
		{
			found = 1;

			std::cout << "Pair (" << x << "," << y << ") found in your dataset!";
			std::cout << std::endl;

			break;
		}

		else if ((trav->x!=x)or(trav->y!=y)) {trav = trav -> next;}

		else {std::cerr << "Pair matching issue 1!";}
	}

	if ((found==0)and((trav->x==x)and(trav->y==y)))
	{
		found = 1;

		std::cout << "Pair (" << x << "," << y << ") found in your dataset!";
		std::cout << std::endl;
	}

	else if ((found==0)and((trav->x!=x)or(trav->y!=y)))
	{
		std::cout << "Pair (" << x << "," << y << ") not found in your dataset.";
		std::cout << std::endl;
	}

	else if (found==1) {found = 0;}

	else {std::cerr << "Unknown removal condition 2!";}

	trav = head;
}





void regressions::SimLinReg::import(std::string file)
{
	std::cout << "Inside import()!" << std::endl;
}





//extract dataset





int regressions::SimLinReg::predict(char axis, float input)
{
	sum_x = 0; sum_y = 0; sum_xy = 0; sum_x_s = 0; sum_y_s = 0;

	while (trav->next!=nullptr)
	{
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

	b = ((n*sum_xy)-(sum_x*sum_y))/((n*sum_x_s)-(sum_x*sum_x));
	a = (sum_y-(b*sum_x))/n;

	if (axis=='x')
	{
		y = input;

		x = (y-a)/b; x = abs(x);
		std::cout << "For \'y\' = " << y << ", \'x\' must be " << x << std::endl;

		return y;
	}

	else if (axis=='y')
	{
		x = input;

		y = a+(b*x); y = abs(y);
		std::cout << "For \'x\' = " << x << ", \'y\' must be " << y << std::endl;
		
		return x;
	}

	else
	{
		std::cerr << "Unknown axis used in prediction!";
	}
}





void regressions::SimLinReg::display()
{
	while (trav->next!=nullptr)
	{
		status();

		trav = trav -> next;
	}

	status();

	trav = head;
}





void regressions::SimLinReg::status()
{
	std::cout << "x: " << trav -> x << std::endl << "y: " << trav -> y << std::endl;
	std::cout << "Prev: " << trav -> prev << std::endl;
	std::cout << "Curr: " << trav << std::endl;
	std::cout << "Next: " << trav -> next << std::endl;
	std::cout << std::endl << std::endl;
}





regressions::SimLinReg::~SimLinReg()
{	
	while (head->next!=nullptr) {remove(head->x, head->y);}

	remove(head->x, head->y);

	std::cout << "The simple linear regression model has been deleted." << std::endl;
}



#endif

/* Copyright (C) 2024, Gourav Kumar Mallick
This software is licensed under "MIT License"
Please refer to the documentations for more legal information on this. */