#ifndef PLAYER_H
#define PLAYER_H

#include <Windows.h>
#include <iostream>
#include <string>


using std::string;


class Player{
public:

	string firstName;
	string lastName;
	
	int level;
	int experience;
	int strength;
	int agility;
	int health;

	/*
	Name: The Deafult Constructor
	Description: empty Constructor
	Arguments: none
	Returns: none

	*/
	Player(){

		firstName = "";
		lastName = "";
		level = 0;
		experience = 0;
		 
		agility = 0;
		strength = 0;
		health = 0;
	}

	/*
	Name: The Destructor
	Description: destroys the player object
	Arguments: none
	Returns: none
	*/

	~Player(){
	
	
	}


	/*
	Name: The overloaded Constructor
	Description: empty Constructor
	Arguments: the player fields
	Returns: none
	*/
	 Player( string firstName, string lastName, int level, int experience, int strength, int agility, int health )
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->level = level;
	this->experience = experience;
	this->strength = strength;
	this->agility = agility;
	this->health = health;
}

	
	



};
#endif
