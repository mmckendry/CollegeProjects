#include <iostream>
#include <windows.h>
#include <string.h>
#include "Hashes.h"
#include "DLinkedlist.h"
#include "Array.h"
#include "player.h"
#include "item.h"
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <conio.h>
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

//using std::string;
using namespace std;

	string username = "";
	string password = "";
	
	string charFName = "";
	string charLName = "";
	int charLevel = 0;
	int charExp= 0;
	int charAgility = 0;
	int charStrength = 0;
	int charHealth = 0;

	

void readIn();
 void writeOut();
 void printPlayer();
 void intro();
 void next();
 void refreshScreen();
 int quit();
 int play();
 void menu();
 void createUser();
 void getUser();
 void theGame();
 void gameMap();
 void printAtt();
void setCusor(int, int);
void chrtPos();
void sote();
void soteP();
void objective();
void battle();
void death();
int win();

int main(){

	long int Hash;
	int size;

	Player* e1 = new Player("mad", "king",1, 220, 7, 5, 5);
	Player* e2 = new Player("forrest", "troll", 3, 400, 4, 4, 9);
	Player* e3 = new Player("lame", "donkey", 1, 40, 2, 2, 2);


	
	Item* i2 = new Item("Eye of the beast", "The Eye of the beast slain at the river");

	DLinkedList<Player>* enemyList = new DLinkedList<Player>;
	enemyList->Append(*e1);
	enemyList->Append(*e2);
	enemyList->Append(*e3);

	refreshScreen();
	
	string filename; 
	string mArray[5];
	mArray[0] = "hurr durr";

	//battle();
	menu();

}



void menu(){
	cout << "'Consulates of War'" << endl;
	cout << "" << endl;
	cout << "Welcome, Please pick one of the following options" << endl;

	cout << "1. Intro" << endl;
	cout << "2. Play the Game" << endl;
	cout << "3. Quit the game" << endl;

int myChoice = 0;
cin >>(myChoice);

	if (myChoice > 4 || myChoice <= 0  ){
		refreshScreen();
		cout << "\nERROR MENATAL DEFICIENCY DETECTED; please enter a valid selection" <<endl;
		cout << "(a number between 1 and 4) " << endl; 
		Sleep(3000);
		menu();
	}
	else{
		switch(myChoice){
		case 1: cout <<"\nYou have selected the intro:\n";
			intro();
			break;
		case 2: cout <<"\nYou have selected Play the Game\n";
			play();
			Sleep(30000);
			break;
		
		case 3: 
			quit();
			break;
		}
	}

	
	


	//switch 
}

void readIn(){
		

  string line;
  ifstream myfile ("c:/tmp/example.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;
	  Sleep(2000);
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
}

void writeOut(){

 ofstream myfile ("c:/tmp/example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
	 
}

void printPlayer(){
	
	string line;
  ifstream myfile ("c:/tmp/player.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;
	  Sleep(2000);
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 



}

void intro(){

	
  string line;
  ifstream myfile ("c:/tmp/intro.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;
	  Sleep(2000);
    }
    myfile.close();
	menu();
  }

  else cout << "Unable to open file"; 
	
}

void next(){
	cout << "Press enter to continue" << endl;
	getchar();
}

void refreshScreen(){
	system("cls");
}

int quit(){
	cout <<"\nYou have selected quit\nPress enter to Quit the game";
	next();
	return 0;

}

int play(){
	refreshScreen();
	int log = 0;
	cout << "please log in to continue\n Not played before? create a profile!" << endl;
	cout << "" << endl; 

	cout << "1. Log in" << endl;
		cout << "2. new profile" << endl;

		cin >>(log);

		if(log == 1){
			getUser();
		}
		else if(log == 2){
			createUser();
		}
		else{
			cout << "non vaild option, self destruct...." << endl;
			Sleep(2000);
			return 0;
		}
}

void createUser(){
	
	ofstream myfile ("c:/tmp/users.txt");
  if (myfile.is_open())
  {
	 cout << "please enter a username:" << endl;
		 cin >>(username);
		

		cout << "please enter a password: " << endl;
		cin >>(password);
	myfile << username << endl;
	myfile << password << endl;;
    myfile.close();
	theGame();

  }
  else cout << "Unable to open file";

}

void getUser(){
	
	string line;
	
  ifstream myfile ("c:/tmp/existingUsers.txt");
  if (myfile.is_open())
  {
    

		string myArray[2];

		for(int i = 0; i < 2 ; ++i)
        {
            myfile >> myArray[i];
		}
   

		 cout << "please enter a username:" << endl;
		 cin >>(username);
		
		cout << "please enter a password: " << endl;
		cin >>(password);

	 
		for(int i = 0; i < 2 ; ++i)
        {
            if(username == myArray[0] && password == myArray[1]){
				theGame();
			}

			//if(password == myArray[1]){
			//	cout << "found" << endl;
			//}

			else{
				play();
			}
		



	   getline (myfile,line);
		
	   
      cout << line << endl;
	  Sleep(2000);
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
}

void theGame(){
	int addAtt= 0;
	int aPoints = 19;


	int exp = 0;
	int level = 0;
	int agil = 0;
	int strn = 0;
	int health = 0;


	string myArray[7];
	
	refreshScreen();
	 string line;
  ofstream myfile ("c:/tmp/player.txt");
  if (myfile.is_open())
 {
    

	Player* character = new Player("","", 1, 0, 1, 1, 1);
	refreshScreen();
	cout << "Character creation" << endl;
	
	cout << "What is the name of your hero?" << endl;
	cin >> (charFName);
	character->firstName = charFName;
	
	cout << "the last name of your hero?" << endl;
	cin >> (charLName);
	character->lastName = charLName;
	
	for(int i = 0; i < 19 ; i++){
		while(aPoints != 0){
		refreshScreen();
		aPoints --;
	cout << "Please select 1,2 or 3 to add to you players attributes" << endl;
	//printAtt();
	cout << "points: " << aPoints << endl;
	cout << "Name: " << character->firstName << endl;
	cout << "Surname: " << character->lastName << endl;
	cout << "Level: " << character->level << endl;
	cout << "experience: " << character->experience << endl;
	cout << "Agility: " << character->agility << endl;
	cout << "Strength: " << character->strength << endl;
	cout << "Health: " << character->health << endl;

	
	exp = character->experience;
	level= character->level;
	 agil = character->agility;
	 strn = character->strength;
	 health = character->health;
         
	cin >> (addAtt);
	getchar();

	switch(addAtt){
	case 1:
		character->agility ++;
		refreshScreen();
		//printAtt();
	
		break;

	case 2: 
		character->strength ++;
		refreshScreen();
	
		//printAtt();
		break;

	case 3:
		character->health ++;
		refreshScreen();
		
		//printAtt();
		break;

	}
	
	}
	}


	myfile << charFName << endl;
	myfile << charLName <<endl;
	myfile << exp <<endl;
	myfile << level <<endl;
	myfile << agil <<endl;
	myfile << strn <<endl;
	myfile << health <<endl;


   myfile.close();


 
//printAtt();
   chrtPos();
  }

  

  else{ 
	  
	  cout << "Unable to open file"; 
	}

}


void printAtt(){
		//string myArray[7];
	string line;
  ifstream myfile ("c:/tmp/player.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {

		

		//for(int i = 0; i < 7 ; ++i)
  //      {
  //          myfile >> myArray[i];
		//}


		//for(int i = 0; i < 7; i++){
		//	cout << myArray[i] << endl;
		//}
    
	  getline (myfile,line);
      cout << line << endl;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 


}

void gameMap(){

	//string line;
 // ifstream myfile ("c:/tmp/map.txt");
 // if (myfile.is_open())
 // {
 //   while ( myfile.good() )
 //   {
 //     getline (myfile,line);
 //     cout << line << endl;
	//  Sleep(2000);
 //   }
 //   myfile.close();
 // }

 // else cout << "Unable to open file"; 


		cout << "use WASD to move!" << endl;
	cout << "===================================================" << endl;
	cout << "||||||||||||||||||||||       ||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "     |||||||||||||||||||| |||||||||||||||||||||    " << endl;
	cout << "                                                   " << endl;
	cout << "     |||||||||||||||||||| |||||||||||||||||||||    " << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||||| |||||||||||||||||||||||||" << endl;
	cout << "||||||||||||||||||||||       ||||||||||||||||||||||" << endl;
	cout << "===================================================" << endl;



}

void setCursor(int x, int y){
	COORD coord = {x, y};
	SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord );
}

void chrtPos(){
	int x = 25, y = 9;
	refreshScreen();
	gameMap();
	setCursor(x, y);
	cout<< "*" ;
	do {
		int ch = getch();
		switch(ch){

		case UP:

			y--;
			refreshScreen();
			gameMap();
			setCursor(x, y);
			cout<< "*";


			break;

		case DOWN:

			y++;
			refreshScreen();
			gameMap();
			setCursor(x, y);
			cout<< "*";

			break;

		case LEFT:

			x--;
			refreshScreen();
			gameMap();
			setCursor(x, y);
			cout << "*" ;

			break;

		case RIGHT:

			x++;
			refreshScreen();
			gameMap();
			setCursor(x, y);
			cout << "*" ;

			break;
		}
	

		if(x == 0 && y == 9){
			menu();
		}
		else if (x == 50 && y ==9){
			menu();
		}

		else if (x == 25 && y == 16){
			menu();
		}

		else if (x == 25 && y == 2){
			
			sote();
			next();
			

		}

		else{
		}

	}while(x !=44 || y !=8   );
	
}

void gameMap2(){

	refreshScreen();
		cout << "meet the king (0) " << endl;
	cout << "===================================================" << endl;
	cout << "|     ,             |    0   |                     |" << endl;
	cout << "|                   |        |           .         |" << endl;
	cout << "|                   ---    ---                     |" << endl;
	cout << "|         -                                        |" << endl;
	cout << "|__                                                |" << endl;
	cout << "|  |                                               |" << endl;
	cout << "|__|                                               |" << endl;
	cout << "|                                                  | " << endl;
	cout << "|     .                                     ,      |" << endl;
	cout << "|                 -                                |" << endl;
	cout << "|                                               __ |" << endl;
	cout << "|                                              |   |" << endl;
	cout << "|          .                     ~             |__ |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|     .        ,         ^                         |" << endl;
	cout << "===================================================" << endl;



}


void sote(){

	refreshScreen();	
  string line;
  ifstream myfile ("c:/tmp/sote.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;
	  Sleep(2000);
    }
    myfile.close();
	next();
	gameMap2();
	Sleep(2000);
	objective();
  }

  else cout << "Unable to open file"; 
	
}


void soteP(){
int x = 25, y = 16;
int count = 0;

	refreshScreen();
	gameMap2();
	setCursor(x, y);
	cout<< "*" ;

	do{
		int kl = getch();
		switch(kl){


		case UP:
			y--;
			refreshScreen();
			gameMap2();
			setCursor(x, y);
			cout<< "*";
			break;

		case DOWN:
			y++;
			refreshScreen();
			gameMap2();
			setCursor(x, y);
			cout<< "*";
			break;

		case LEFT:
			x--;
			refreshScreen();
			gameMap2();
			setCursor(x, y);
			cout<< "*";
			break;

		case RIGHT:
			x++;
			count++;
			refreshScreen();
			gameMap2();
			setCursor(x, y);
			cout<< "*";
			break;

			if(count = 10){
				cout << "here" << endl;
				
				objective();
			}

			else{
			}

		}

	}while(count < 10 );


	



}

void objective(){

	refreshScreen();	
  string line;
  ifstream myfile ("c:/tmp/objective.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;
	  Sleep(2000);
    }
    myfile.close();
	next();
	battle();
  }

  else cout << "Unable to open file"; 
	
}

void battle(){

	refreshScreen();
	 string line;
  ifstream myfile ("c:/tmp/player.txt");
  if (myfile.is_open())
 {
	Player* e1 = new Player("mad", "king",1, 220, 7, 5, 5);
	Player* e2 = new Player("forrest", "troll", 3, 400, 4, 4, 9);
	Player* e3 = new Player("lame", "donkey", 1, 40, 2, 2, 2);
	
	DLinkedList<Player>* enemyList = new DLinkedList<Player>;
	enemyList->Append(*e1);
	enemyList->Append(*e2);
	enemyList->Append(*e3);


	string myArray[7];
	
	
    for(int i = 0; i < 7 ; i++){
	
		myfile >> myArray[i];
	}



	string playerName;
	string playerLName;
	string playerAgility;
	string playerStrength;
	string playerHealth;

	playerName = myArray[0];
	playerLName = myArray[1];
	playerAgility = myArray[4];
	playerStrength = myArray[5];
	playerHealth = myArray[6];




	int enemyAgility = e1->agility;
	int enemyStrength = e1->strength;
	int enemyHealth = e1->health;

	int eDamage = 0;
	int pDamage = 0;

	
	
	int pHealth;
	istringstream ( playerHealth ) >> pHealth;
	int pStrength;
	istringstream ( playerStrength ) >> pStrength;
	int eHealth;
	istringstream ( enemyHealth ) >> eHealth;
	int eStrength;
	istringstream ( enemyStrength ) >> eStrength;
	eHealth = 5;
	eStrength = 5;
	
	
	do {
		refreshScreen();
	cout << " " << endl;
	cout << " Prepare for battle!" << endl;

	cout << "						Enemy Name: " << e1->firstName << " " << e1->lastName << endl; 
	cout << "						Enemy Agility: " << enemyAgility << endl;
	cout << "						Enemy Strength: " << eStrength << endl;
	cout << "						Enemy Health: " << eHealth << endl;;

	



	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "Player Name: " << playerName << " " << playerLName << endl ; 
	cout << "Player Agility: " << playerAgility << endl;
	cout << "Player Strength: " << pStrength << endl;
	cout << "Player Health: " << pHealth << endl;;
	
	cout << " " << endl;
	cout << " " << endl;
  

	int choice;

 cout << "What do you want to do?" << endl;
 cout << "1. Fight    2. Inventory   3. Run" << endl;

 cin >> (choice);

 switch(choice){
 case 1: 
	 cout << "you hack and slash at the king, you manage to connect!" << endl;
		Sleep(2000);
	  //playerStrength;
	 
	 pDamage = pStrength/2;
		eHealth = eHealth - pDamage;

		

		cout << "The mad king is quick and he comes back at you with furious strength, You are hit" <<endl;
		Sleep(2000);

		eDamage = eStrength/2;
		pHealth = pHealth - eDamage;

	 break;

 case 2:
	 cout << " you have nothing yet save for the sword in your hand" << endl;
	 Sleep(2000);
	 break;

 case 3:
	 cout << "you cant escape he is blocking the door!" << endl;
	 Sleep(2000);
	 break;
 }
  

 if(pHealth < 0){
 
	death();

 }

 else{
 }
  
}while(eHealth > 0);
  
  
  
  win();
  
  
  
  }

  else {
	  cout << "The file cannot be opened" << endl;


}
}

void death(){
	int proceed; 
	cout << "You died! you put up a valiant effort but alas you were no match fro the king!" << endl;
	  cout << "would you like to continue?\n 1. Yes 2.No " << endl;

	  cin >> (proceed);

	  if (proceed == 1){
		  battle();
	  }

	  else{
		  quit();
	  }
}

int win(){
	cout << "after a long battle you have cast down your enemy and smote his bloody ruin across the floor " << endl;
	cout << "You take his signit ring off of his cold fingers and place it in your pack" << endl;

	Sleep(2000);
	return 0;

	Item* i1 = new Item("King's signit ring", "a ring bearing the seal of the king of the hilltop people");
	
	/*string name = *i1->itemName;
	string desc = *i1->itemDescrip;

	
	ofstream myfile ("c:/tmp/example.txt");
  if (myfile.is_open())
  {
	  myfile << name << desc;
   
    myfile.close();
  }
  else cout << "Unable to open file";*/
	 
}
	
	

