#include "TouchTyping.h"

void skeleton();

int main(){

	TouchTyping *t = new TouchTyping();
	string choice;
	/*
	Why String ?
	because if it was char instead, and the user wanted to mess with the program,
	and enter something like 'MESS' as a choice, 
	then he'll get 4 messages telling him invalid entry try again.
	with string, this is no longer possible.
	*/
	bool quit = false;

	while(!quit)
	{
		system("cls");
		t->printMenu();
		cout << "\n\n\t\t   Make a Choice: ";
		_tryAgain:
		cin >> choice;
		//Why not switch ? cuz switch doesn't accept string.
		if(choice == "1")
		{
			system("cls");
			t->printText();
			t->startTyping();
			if(t->HasTypingSucceeded()){
				t->printReportToScreen();
				t->printReportToFile();
			}
			cout << "\n\nPress AnyKey Followed By Enter To Return To The MainMenu: ";
			string anyKey; cin >> anyKey; 
		}
		else if(choice == "2")
		{
			string fileName;
			cout << "\n\t\t   Enter The FileName: ";
			cin >> fileName;
			t->setTextFile(fileName);
		}
		else if(choice == "3"){
			if(t->getSound() == true) t->setSound(false);
			else t->setSound(true);
		}
		else if(choice == "4"){
			t->clearReportFile();
		}
		else if(choice == "5"){
			quit = true;
			system("cls");
			skeleton();
		}
		else{
			cout << "\n\t\t   Invalid Entry, Try Again: ";
			goto _tryAgain;
		}
	}
	cout << "\n\n\t\t\tPress AnyKey To Exit...";
	_getch();
	return 0;
}

//-----------------------------------------------------------------------------------------------------
void draw(int x, char c){for(int i = 0; i < x; i++) cout << c;}
//-----------------------------------------------------------------------------------------------------
void skeleton(){

	draw(5,'\n'); int n = 1 , haltTime = 10;
	cout << "\t  All Rights Reserved To Code_FreaX, blah blah blah ...\n\n";
	cout << "\t  Thank you For Purchacing Our Free Products :D\n\n";
	cout << "\t  Made By VeXe...\n\n\n";

	/*************1st part*************/
	/*1st line*/
	draw(n,'\t'); Sleep(haltTime); draw(22,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\\');   draw(8,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'\n');
	/*2nd line*/
	draw(n,'\t'); Sleep(haltTime); draw(14,' ');  draw(1,'/'); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(2,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(6,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(2,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'\n');
	/*3rd line*/
	draw(n,'\t'); Sleep(haltTime); draw(13,' ');  draw(1,'/'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'/');  draw(4,' ');  draw(1,'/');  draw(4,' ');  draw(1,'\\');  draw(4,' ');  draw(1,'/');  draw(4,' ');  draw(1,'\\');   draw(4,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'\\');  draw(1,'\n');
	/*4th line*/
	draw(n,'\t'); Sleep(haltTime); draw(12,' ');  draw(1,'/'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'/');  draw(4,' ');  draw(1,'/');  draw(6,' ');  draw(1,'\\');  draw(2,' ');  draw(1,'/');  draw(6,' ');  draw(1,'\\');   draw(4,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'\\');  draw(1,'\n');
	/*5ht line*/
	draw(n,'\t'); Sleep(haltTime); draw(11,' ');  draw(1,'/'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'/');  draw(3,' ');  draw(1,'_');  draw(1,'/');  draw(8,' ');  draw(1,'\\');  draw(1,'/');  draw(8,' ');  draw(1,'\\');  draw(1,'_');   draw(3,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'\\');  draw(1,'\n');
	/*************2nd part*************/
	/*1st line*/
	draw(n,'\t'); Sleep(haltTime); draw(11,' ');  draw(1,'\\');  draw(1,' ');  draw(1,'\\');  draw(2,' '); Sleep(haltTime); draw(1,'/');   draw(4,' '); Sleep(haltTime); draw(3,'_'); Sleep(haltTime); draw(9,' ');  draw(3,'_'); Sleep(haltTime); draw(3,' '); Sleep(haltTime); draw(1,'\\');  draw(2,' ');  draw(1,'/');  draw(1,' ');  draw(1,'/'); Sleep(haltTime); draw(1,'\n');
	/*2nd line*/
	draw(n,'\t'); Sleep(haltTime); draw(12,' ');  draw(1,'\\');  draw(1,' ');  draw(1,'\\'); Sleep(haltTime); draw(1,'/');   draw(5,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(2,'_'); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(2,' '); Sleep(haltTime); draw(3,'_'); Sleep(haltTime); draw(2,' '); Sleep(haltTime); draw(1,'/');  draw(2,'_');  draw(1,'/'); Sleep(haltTime); draw(4,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\n');
	/*3rd line*/
	draw(n,'\t'); Sleep(haltTime); draw(13,' ');  draw(1,'\\');  draw(1,'/');  draw(0,' '); Sleep(haltTime); draw(12,' ');  draw(1,'|'); Sleep(haltTime); draw(1,'_'); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(11,' ');  draw(1,'\\'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\n');
	/*************3rd part*************/
	/*1st line*/
	draw(n,'\t'); Sleep(haltTime); draw(6,' '); Sleep(haltTime); draw(1,'_'); Sleep(haltTime); draw(7,' '); Sleep(haltTime); draw(1,'\\');  draw(6,' '); Sleep(haltTime); draw(15,'_'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'/');  draw(1,'\n');
	/*2nd line*/
	draw(n,'\t'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(7,' '); Sleep(haltTime); draw(1,'\\');  draw(5,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,' ');   draw(1,'\\'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(4,' '); Sleep(haltTime); draw(1,'/');  draw(1,'\n');
	/*3rd line*/
	draw(n,'\t'); Sleep(haltTime); draw(5,'_'); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(8,'_'); Sleep(haltTime); draw(1,'\\');  draw(5,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(11,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(4,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(15,'_'); Sleep(haltTime); draw(1,'\n');
	/*4th line*/
	draw(n,'\t'); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(4,'_'); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(2,' '); Sleep(haltTime); draw(9,'_'); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(9,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(4,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(16,'_'); Sleep(haltTime); draw(1,'>'); Sleep(haltTime); draw(1,'\n');
	/*5th line*/
	draw(n,'\t'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(1,' '); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(10,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(7,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(4,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\n');
	/*6h line*/
	draw(n,'\t'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(1,'_'); Sleep(haltTime); draw(1,'|'); Sleep(haltTime); draw(11,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'_'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(4,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\n');
	/*7th line*/
	draw(n,'\t'); Sleep(haltTime); draw(20,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(3,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(4,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\n');
	/*8th line*/
	draw(n,'\t'); Sleep(haltTime); draw(21,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(5,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(1,'_'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(4,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\n');
	/*the rest of the lines*/
	for(int i=0,k=22,j=5;i<3;i++,k++,j--){
		if(i!=2){
			draw(n,'\t'); Sleep(haltTime); draw(k,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(j*2,' '); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(1,'\n');
		}
		else{
			draw(n,'\t'); Sleep(haltTime); draw(24,' '); Sleep(haltTime); draw(1,'\\'); Sleep(haltTime); draw(6,'_'); Sleep(haltTime); draw(1,'/'); Sleep(haltTime); draw(2,'\n');
		}
	}
}
//-----------------------------------------------------------------------------------------------------