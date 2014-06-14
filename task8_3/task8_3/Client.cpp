
/**
*@file		League.cpp
*@brief		Implements methods for Client class that holds information about money that has client
*/
#include "stdafx.h"
#include "Client.h"


/**
* @brief			Constructor without parameters to set fields in class to their default values
* @param	void
*/
Client::Client(void) : credit(0), deposit(0)
{
}

/**
* @brief				Destructor
* @param	void
*/
Client::~Client(void)
{
}


/**
* @brief					Method for giving to client deposit
* @param	[unsigned int]	_deposit - money for client
*			
*@return	void			
*/
void Client::addDeposit(unsigned int _deposit)
{
	deposit += _deposit;
}


/**
* @brief					Method for paying the client's credit
* @param	void	
*
*@return	[unsigned int] Returns the credit from client
*/
unsigned int Client::getCredit(void)
{
	return credit;
}

/**
* @brief					Method for giving to client credit
* @param	[unsigned int]	_credit - money for client
*
*@return	void
*/
void Client::setCredit(unsigned int _credit)
{
	credit += _credit;
}


/**
* @brief					Method for showing the deposit that client has
* @param	void		
*
*@return	[unsigned int] returns the deposit from client
*/
unsigned int Client::getDeposit(void)
{
	return deposit;
}


/**
* @brief			Method for setting the deposit to zero
* @param	void
*
*@return	void		 
*/
void Client::returnDeposit(void)
{
	deposit = 0;
}
