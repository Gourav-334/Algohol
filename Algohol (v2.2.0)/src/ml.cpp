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










//Checks if a pair exists or not in the dataset.
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










//Importing any file that contains data in it.
void regressions::SimLinReg::import(char *file)
{
	printf("Importing \"%s\"...\n\n", file);

	FILE *fptr;
	fptr = fopen(file, "rb");

	char buff1[32], buff2[32];
	int b1=0, b2=0, buffer=1;
	float pair[2];
	char current;
	bool dot = false;

	if (fptr==NULL) {perror("File can't be found!");}

	else if (fptr!=NULL)
	{
		while (!feof(fptr))
		{
			current = fgetc(fptr);

			switch (buffer)
			{
				case 1:
					if (current==' ') {}

					else if (current==',')
					{
						buff1[b1] = '\n';
						pair[0] = atof(buff1);
						b1 = 0; buffer = 2; dot = false;
					}

					else if (current=='.' && dot==false)
					{
						buff1[b1] = current;
						dot = true; b1++;
					}

					else if (((current!='0')&&(current!='1')&&(current!='2')&&(current!='3')
						&&(current!='4')&&(current!='5')&&(current!='6')&&(current!='7')
						&&(current!='8')&&(current!='9'))||(current=='.' && dot == true))
						{break;}

					else {buff1[b1] = current; b1++;}

					break;


				case 2:
					if (current==' ') {}

					else if (current=='\n' || feof(fptr)!=0)
					{
						buff2[b2] = '\n';
						pair[1] = atof(buff2);
						this -> add(pair[0],pair[1]);

						b2 = 0; buffer = 1; dot = false;
					}

					else if (current=='.' && dot==false)
					{
						buff2[b2] = current;
						dot = true; b2++;
					}

					else if (((current!='0')&&(current!='1')&&(current!='2')&&(current!='3')
						&&(current!='4')&&(current!='5')&&(current!='6')&&(current!='7')
						&&(current!='8')&&(current!='9'))||(current=='.' && dot == true))
						{break;}

					else {buff2[b2] = current; b2++;}

					break;
			}
		}
	}

	else {perror("File pointer error!");}

	fclose(fptr);

	printf("\n\"%s\" successfully imported!\n", file);
}










//Export the data to a file
void regressions::SimLinReg::extract(char *file)
{
	FILE *fptr;
	fptr = fopen(file, "a");

	char buffer[32];

	while (trav->next!=NULL)
	{
		sprintf(buffer, "%f", trav -> x);
		fputs(buffer, fptr);
		fputs(", ", fptr);

		sprintf(buffer, "%f", trav -> y);
		fputs(buffer, fptr);
		fputc('\n', fptr);

		printf("(%f,%f) extracted to \"%s\"\n", trav -> x, trav -> y, file);

		trav = trav -> next;
	}

	sprintf(buffer, "%f", trav -> x);
	fputs(buffer, fptr);
	fputs(", ", fptr);

	sprintf(buffer, "%f", trav -> y);
	fputs(buffer, fptr);
	fputc('\n', fptr);
	fputc('\n', fptr);

	printf("(%f,%f) extracted to \"%s\"\n", trav -> x, trav -> y, file);

	trav = head;
}










//Predicting the next outcome as per available dataset.
int regressions::SimLinReg::predict(char axis, float input)
{
	sum_x = 0; sum_y = 0; sum_xy = 0; sum_x_s = 0; sum_y_s = 0;

	while (trav->next!=NULL)
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