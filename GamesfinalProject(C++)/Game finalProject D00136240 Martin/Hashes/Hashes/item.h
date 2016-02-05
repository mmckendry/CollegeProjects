#ifndef ITEM_H
#define ITEM_H

#include <Windows.h>
#include <iostream>
#include <string>


class Item{
public:
	string itemName;
	string itemDescrip;
	

	Item(){

		itemName;
		itemDescrip;
		
	}

	~Item(){
	
	}

	Item(string itemName, string itemDescrip){
		this->itemName = itemName;
		this->itemDescrip = itemDescrip;
		
	}


	
};
#endif
