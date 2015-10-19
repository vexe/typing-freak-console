#include "TouchTyping.h"



//-------------------------------------------------------------------
void TouchTyping::knowTheNumberOfCharacters()
{
	fin.seekg(0 , ios::end); // seeking the file pointer to the end of the file.	
	numberOfCharacters = (int)fin.tellg(); 
}
//-------------------------------------------------------------------
int TouchTyping::inBetweenWrodsCounter(string word)
{
	if(word.size() <= 4) return 0;
	int numberOfSplits = 0;
	for(int i = 0; i < word.size(); i++){
		if(i == word.size()-1) break;
		if(
			(isupper(word[i]) && islower(word[i+1])) || (word[i] == '.' && word[i+1] != 'h' && (word[i+2] != '>' && word[i+2] != '"' ))
			|| (word[i] == '-' && word[i+1] == '>') 
			|| (word[i] == ':' && word[i+1] == ':') || (word[i] == '(' && isalpha(word[i+1]))
			|| (word[i] != ' ' && word[i+1] == '"' && isalpha(word[i+2])) || (word[i] == '[' && isalpha(word[i+1]))
			|| word[i] == '_'
		  )
			numberOfSplits++;
	}

	return numberOfSplits+1;
}
//-------------------------------------------------------------------
void TouchTyping::knowTheNumberOfWords()
{
	numberOfWords = 0;
	fin.seekg(0);
		while(!fin.eof()){
			string temp;
			fin >> temp;
			if(temp.size() > 1)
				if((temp.size() == 2 && (isalpha(temp[0]) && isalpha(temp[1])) || (temp.size() > 2 && temp.size() <= 4) && (temp != "")))
					numberOfWords++;
				else
					numberOfWords += inBetweenWrodsCounter(temp);
		}
}
//-------------------------------------------------------------------
bool TouchTyping::hasExtension(const string &_fileName)
{
	if(_fileName.size() <= 4) return false; // cuz the smallest name of a file with a .txt extension is something like: a.txt (5 letters long).
	int begPos = _fileName.size()-4; // Extension Beginning Position, remember that the extension is the last four characters in the _fileName (considering that it's a .txt windows extension)
	if(_fileName[begPos] == '.' && _fileName[begPos+1] == 't' && _fileName[begPos+2] == 'x' && _fileName[begPos+3] == 't')
		return true;
	return false;
}
//-------------------------------------------------------------------
void TouchTyping::addExtension(string &_fileName)
{
	_fileName.push_back('.');
	_fileName.push_back('t');
	_fileName.push_back('x');
	_fileName.push_back('t');
}
//-------------------------------------------------------------------
void TouchTyping::setTextFile(string _fileName){
	static bool opened_a_FileBefore = false;
	// we don't wanna close something that doesn't hasn't been open before, that's why we needed the opened_a_FileBefore. 
	// this happens in the first time the user picks his source text file.
	if(opened_a_FileBefore) 
		fin.close();
	if(!hasExtension(_fileName)) // if the user typed the file name without the .txt
		addExtension(_fileName);
	fin.open(_fileName);
	if(fin.good())
	{
		sourceFileName= _fileName;
		getTextFromFile();
		knowTheNumberOfCharacters();
		knowTheNumberOfWords();
		opened_a_FileBefore = true;
		openedFileSuccessfully = true;
		cout << "\n\t\t   File Opened Successfully.\n";
	}
	else{
		cout << "\n\t\t   Error Opening File.\n";
		openedFileSuccessfully = false;
	}
	cout << "\n\t\t   Press any key to continue...";
	_getch();
}
//-------------------------------------------------------------------
void TouchTyping::backSpaceVisualTrick()
{
	consoleScreenCoord = getConosleScreenCursorCoord();
	gotoXY(--consoleScreenCoord.X , consoleScreenCoord.Y);
	cout << " ";
	gotoXY(consoleScreenCoord.X , consoleScreenCoord.Y);
}
//-------------------------------------------------------------------
void TouchTyping::gotoXY(const int &x, const int &y)
{
	COORD __coord;
	__coord.X = x;
	__coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , __coord);
}
//-------------------------------------------------------------------
COORD TouchTyping::getConosleScreenCursorCoord()
{
	CONSOLE_SCREEN_BUFFER_INFO __cursorInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE) , &__cursorInfo);
	return __cursorInfo.dwCursorPosition;
}
//-------------------------------------------------------------------
void TouchTyping::fixSpaceProblemInTheEndOfLines()
{
	for(int i = 0; i < text.size(); i++)
		if(text[i] == '\n')
		{
			for(int k = i-1; text[k] == ' '; k--)
				text.erase(text.begin() + k); // removing any found unnecessary spaces in the end.
		}
}
//-------------------------------------------------------------------
void TouchTyping::printReportToScreen()
{
	cout << endl << "X==========================================X" << endl;
	cout << "\n        FILE NAME: " << sourceFileName << endl;
	cout << "\n\tMISTAKES MADE: " << getNumberOfMistakes() << "\n";
	cout << "\n\tTIME NEEDED: " << getTotalTimeTakenToFinish() << " Seconds.\n";
	cout << "\n\tCHARCTERS IN FILE: " << getNumberOfCharactersIfTheFile() << "\n";
	cout << setprecision(3) << "\n\tSPEED(CPS): " << getCPS() << "\n";
	cout << "\n\tWORDS IN FILE: " << getNumberOfWordsInTheFile() << "\n";
	cout << setprecision(4) << "\n\tSPEED(WPM): " << getWPM() << "\n";
	cout << setprecision(4) <<"\n\tCORRECTNESS PERCENTAGE: " << getCorrectnessPercentage() << "%\n";
	cout << setprecision(3) <<"\n\tMISTAKE PERCENTAGE: " << getMistakePercentage() << "%\n";
	cout << endl << "X==========================================X" << endl;
}
//-------------------------------------------------------------------
void TouchTyping::printReportToFile()
{
	time_t now;
	time(&now); // this sets the 'now' to the current time.
	fout.open(reportFileName , ios::app); // ios::app appends the new report after the last reports.

	fout << endl << "X==========================================X" << endl;
	fout << "\n\tFILE NAME: " << sourceFileName << endl;
	fout << "\n\tDATE-TIME: " << ctime(&now) << endl; // ctime prints the time in a human-readable fashion.
	fout << "\n\tMISTAKES MADE: " << getNumberOfMistakes() << "\n";
	fout << "\n\tTIME NEEDED: " << getTotalTimeTakenToFinish() << " Seconds.\n";
	fout << setprecision(3) << "\n\tSPEED(CPS): " << getCPS() << "\n";
	fout << setprecision(4) << "\n\tSPEED(WPM): " << getWPM() << "\n";
	fout << "\n\tWORDS IN FILE: " << getNumberOfWordsInTheFile() << "\n";
	fout << "\n\tCHARCTERS IN FILE: " << getNumberOfCharactersIfTheFile() << "\n";
	fout << setprecision(4) <<"\n\tCORRECTNESS PERCENTAGE: " << getCorrectnessPercentage() << "%\n";
	fout << setprecision(3) <<"\n\tMISTAKE PERCENTAGE: " << getMistakePercentage() << "%\n";
	fout << endl << "X==========================================X" << endl;
}
//-------------------------------------------------------------------
void TouchTyping::printMenu()
{
	cout << "\n\n\n\n\t\t* xXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXx *\n";
	cout << "\t\t|                                     |";
	cout << "\n\t\t|   1- Start Typing.                  |\n";
	cout << "\t\t|                                     |";
	cout << "\n\t\t|   2- Set Source File Name.          |\n";
	cout << "\t\t|                                     |";
	if(wannaMakeSound)
		cout << "\n\t\t|   3- Disable Sound.                 |\n";
	else
		cout << "\n\t\t|   3- Enable Sound.                  |\n";
	cout << "\t\t|                                     |";
	cout << "\n\t\t|   4- Clear Report File.             |\n";
	cout << "\t\t|                                     |";
	cout << "\n\t\t|   5- Exit.                          |\n";
	cout << "\t\t|                                     |";
    cout << "\n\t\t* xXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXx *\n";
}
//-------------------------------------------------------------------
void TouchTyping::startTyping()
{
	hasTypingSucceeded = false; 
	if(text.size() <= 0){cout << "No Source Text File Selected.\n"; return;}
	fixSpaceProblemInTheEndOfLines(); 
	bool quit = false;
	typingIndex = 0;
	bool isFirstTime = true;
	COORD beginningPoint = 	getConosleScreenCursorCoord(); // read further and you know why we needed this.
	while(!quit && typingIndex != text.size())
	{
		currentLetter = _getch();
		if(isFirstTime) {start = clock(); isFirstTime = false;} // this is just to make sure that the timer will start when the user hits something on the keyboard.
		if(currentLetter == ctrl_Z) quit = true; // ctrl_Z == ctrl + z
		else if(currentLetter == '\r') // when dealing with getch() the 'enter' button is not '\n' it's '\r' instead, if you wanna get '\n' press ctrl+j instead of enter.
		{
			char temp = text[typingIndex];
			if(temp != '\n'){ // mistakenly typed enter (not in the end of the line)
				cout << char(7);
				numberOfMistakes++;
			}

			//storing the position of the cursor when the user typed enter in the newLineTracker.
			consoleScreenCoord = getConosleScreenCursorCoord();
			newLinesTracker.push_back(consoleScreenCoord);
			cout << endl; 
			typingIndex++;
			}
		else if(currentLetter == backspace)  // pressed the backspace character.
		{
			consoleScreenCoord = getConosleScreenCursorCoord();
			// if the cursor is at a beginning of a line, and the user wanna type backspace to get back up to the end of the above line.
			// but this would allow the user to get up to the original text and delete it !! which is very rude !
			// that's why we said: consoleScreenCoord.Y > beginningPoint.Y.
			if((consoleScreenCoord.X == 0) && (consoleScreenCoord.Y > beginningPoint.Y)) 
			{
				gotoXY(newLinesTracker.back().X , newLinesTracker.back().Y);
				newLinesTracker.pop_back();
			}
			else
			{
				backSpaceVisualTrick();
			}
			typingIndex--;
		}
		else if(currentLetter == text[typingIndex]) { cout << currentLetter; typingIndex++;}// if the right key is pressed go to the next letter in the text.
		else { // if the wrong key is pressed.
			numberOfMistakes++;
			cout << currentLetter;
			if(wannaMakeSound)
				cout << char(7); // beep :P
			consoleScreenCoord = getConosleScreenCursorCoord();
			while(true) // forcing him to press backspace and delete the wrong letter pressed and Write the right letter.
			{
				gotoXY(consoleScreenCoord.X , consoleScreenCoord.Y); // this is just to keep the cursor holding its position.
				currentLetter = _getch();
				if(currentLetter == backspace){
					backSpaceVisualTrick();
					break;
				}
				if(currentLetter == ctrl_Z){
					quit = true;
					break;
				}
			}
		}
	}
	end = clock();
	if(currentLetter != ctrl_Z){
		cout << "\n\n\n\t\t DONE !\n";
		totalTimeTakenToFinish = difftime(float(end), float(start)) / CLOCKS_PER_SEC; // CLOCKS_PER_SEC == 1000 this is just to convert from system time I think to seconds.
	    hasTypingSucceeded = true;
	}
}
//-------------------------------------------------------------------
