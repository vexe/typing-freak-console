#include <iomanip> // this is for the setpressision() function in the cout.
#include <ctime>   // this is for counting the difference in time between the beginning and the end of the typing.
#include <vector>
#include <fstream> // for files stuff.
#include <conio.h> 
#include <string>
#include <windows.h> // for the stuff in the gotoXY() and getConosleScreenCursorCoord() functions.
#include <iostream>
using namespace std;
#pragma once

class TouchTyping
{
private:
	string text; // this is where the text in the file will be stored in.
	ifstream fin;
	ofstream fout;
	string sourceFileName;
	string reportFileName;
	char backspace;
	char ctrl_Z;
	COORD consoleScreenCoord; // this is a point that represents the position of the cursor in the console screen.(COORD is a struct that has int X and int Y)
	int typingIndex; // this will get incremented each time the user types a right character.
	char currentLetter; // this is where the user input will be stored in and compared with elemnts of the string 'text'
	vector<COORD> newLinesTracker; // each time the user hits enter, this vector will store the coordinates of the position he hitted enter from.
	int numberOfMistakes;
	float totalTimeTakenToFinish;
	bool wannaMakeSound;
	bool openedFileSuccessfully;
	bool hasTypingSucceeded;
	clock_t start; // clock_t is a typedef to long. this will signal the beginning of the time.
	clock_t end;
	int numberOfCharacters; // the size of the file.
	int numberOfWords;
	//-------------------------------------------------------------------
	/*
	try this code: 
	char c;
	while(true)
	{
		c = getch(); // getch() will immedaitely store the value entered by the user without pressing enter.
		cout << c; // or putch(c);
	{
	now write a little bit, then hit backspace, what will happen ?
	you will be able to delete what you wrote, but visually it will remain there untill you write above it, this is cuz you print it with cout or putch.
	this is the problem that the following method fixes.
	*/
	void backSpaceVisualTrick(); 
	//-------------------------------------------------------------------
	// this sets the consoleScreenCursor Coordinates to x , y.
	void gotoXY(const int &x, const int &y);
	//-------------------------------------------------------------------
	// this will return a point representing the current position of the consoleCursor.
	COORD getConosleScreenCursorCoord();
	//-------------------------------------------------------------------
	// this will compute the size of the source file (how many characters in it) and assign it to the variable numberOfCharacters.
	void knowTheNumberOfCharacters();
	//-------------------------------------------------------------------
	// this is the main alogorithm in counting the number of words in the file.
	int inBetweenWrodsCounter(string word);
	//-------------------------------------------------------------------
	// this will try to get the best and most accurate result in counting the words in the file.
	void knowTheNumberOfWords();
	//-------------------------------------------------------------------
	// this will load the text script from the source file to the string variable 'text'.
	void getTextFromFile()
	{
		text.assign(istreambuf_iterator<char>(fin) , istreambuf_iterator<char>()); // zero is passed by default to istreambuf_iterator<char>() 
	}
	//-------------------------------------------------------------------
	/*
	Sometimes when the user writes his own text in a file, he might forget a space character in the end of the line before the newLine character '\n'
	now, when he starts typing and reaches the end, now there is a space then a '\n'
	but he won't notice that till he hits enter and gets a beep cuz he didn't wirte the right character which was a space, 
	he will be pissed off for what happened .. :@:@:@:@
	the following method fixes this problem.
	*/
	void fixSpaceProblemInTheEndOfLines();
	//-------------------------------------------------------------------

public:	
	TouchTyping()
	{
		consoleScreenCoord.X = consoleScreenCoord.Y = 0;
		numberOfMistakes = 0;
		numberOfWords = 0;
		wannaMakeSound = true;
		openedFileSuccessfully = false;
		reportFileName = "Report.txt";
		backspace = char(8);
		ctrl_Z = char(26);
	}
	//-------------------------------------------------------------------
	// this is in case the user wanna change the source file.
	void setTextFile(string _fileName);
	//-------------------------------------------------------------------
	void printText(){cout << text << "\n\n";}
	//-------------------------------------------------------------------
	void printReportToScreen();
	//-------------------------------------------------------------------
	void printReportToFile();
	//-------------------------------------------------------------------
	void clearReportFile(){fout.open(reportFileName);}
	//-------------------------------------------------------------------
	void printMenu();
	//-------------------------------------------------------------------
	bool hasExtension(const string &_fileName);
	//-------------------------------------------------------------------
	void addExtension(string &_fileName);
	//-------------------------------------------------------------------
	void startTyping();
	//-------------------------------------------------------------------
	void setSound(bool b){wannaMakeSound = b;}
	bool getSound(){return wannaMakeSound;}
	//-------------------------------------------------------------------
	bool OpenedFileSuccessfully(){return openedFileSuccessfully;}
	bool HasTypingSucceeded(){return hasTypingSucceeded;}
	//-------------------------------------------------------------------
	int getNumberOfMistakes()const{return numberOfMistakes;}
	float getCPS()const{return (numberOfCharacters / totalTimeTakenToFinish);} // returns the number of characters typed in 1 second.
	float getWPM()const{return (numberOfWords / (totalTimeTakenToFinish/60));} // returns the number of words typed in 1 minute.
	float getTotalTimeTakenToFinish()const{return totalTimeTakenToFinish;}
	int getNumberOfWordsInTheFile()const{return numberOfWords;}
	int getNumberOfCharactersIfTheFile(){return numberOfCharacters;}
	float getCorrectnessPercentage()const{return (100 * (float(numberOfCharacters-numberOfMistakes) / numberOfCharacters));}
	float getMistakePercentage()const{return (100 * (float(numberOfMistakes) / numberOfCharacters));}
	//-------------------------------------------------------------------
};

