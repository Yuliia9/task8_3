
/**
* @file			task8_3.cpp
* @brief		Program simulates the work of credit league
*				league gives to user their debit/credit and takes from them credit
*
* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/


#include "stdafx.h"
#include "task8_3.h"
#include "League.h"
using std::cout;
using std::cin;

#define ERROR 0
#define SUCCESS 1
#define CASH 1000000



int main(void)
{
	Interface();
	char str[10];
	bool retCode;
	unsigned int num;
	do
	{
		cout << "Enter how many clients will be in league: ";
		cin >> str;
		retCode = Is_posit_digit(str);
		if (!retCode)
		{
			puts("Please check if you entered positive digit number.");
		}
	} 
	while (!retCode);

	num = atoi(str);
	if (num > CASH)
	{
		puts("Sorry, but there is no enough money for so many clients. Come in better times;)");
		return 0;
	}
	League league(CASH, num);

	do 
	{
		unsigned char command;
		cout << "Enter your command ( p - start one work cycle of league, e - exit) : ";
		cin >> command;
		if (command == 'e')
		{
			return 0;
		}
		else if (command == 'p')
		{
			retCode = league.WorkCycle(CASH, num);
			if (retCode == ERROR)
			{
				cout << "Sorry, credit league got bankrupt :(";
				return 0;
			}
		}
	} 
	while (true);

	return 0;
}


void Interface(void)
{
	puts("------------------------------------------------------------------------");
	puts("Welcome to the first console credit league! ");
	puts("League can give to your clients deposit and credit, \nbut credit should be returned on another clients visit for credit!");
	puts("Program made by Yuliia Lyubchik.");
	puts("------------------------------------------------------------------------\n");
}


bool Is_posit_digit(char* str)
{
	if (str == NULL)
	{
		return ERROR;
	}
	char* psubstr;
	char key[] = "0123456789";
	psubstr = strpbrk(str, key);
	if (psubstr == NULL)
	{
		return ERROR;
	}
	int shift = 0;
	while (psubstr != NULL)
	{
		if (psubstr != (str + shift))
		{
			return ERROR;
		}
		psubstr = strpbrk(psubstr + 1, key);
		shift++;
	}
	return SUCCESS;
}