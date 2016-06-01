// CSCI 216 Fundamentals of Programming II Spring 2015
// Program #1: Getting started
// Author: Tomas Ochoa
// Date Due: 26 January 2015
//
// This object of this program is to do some simple file processing. The program will first 
// ask the user to input a file name. If it doesn't exist it will continue to ask the user
// to enter a file name until one that exists is found or exited manually. The program then
// takes the first and last number in the file and finds the average between them. The results
// are then printed

//neccearry header files
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	//Declaration for the file object and name of the file
	//user wants
	fstream dataFile;
	char name[50];

	//gets the name of the file the user wants 
	cout << "What file should I use? ";
	cin  >> name;
	dataFile.open(name, ios::in || ios::binary);

	//Check if it exists
	//If it doesnt exist keep asking user for a correct file
	if (dataFile.fail())
	{
		do
		{
			cout << "That file does not exist!" << endl 
												<< endl
				 << "What file should I use? ";
			cin  >> name;
			dataFile.open(name, ios::in | ios::binary);

		} while (dataFile.fail());
	}

	//Declaration for variables needed to see how many
	//items are in the file. Set to one because we automatically 
	//take the first item before loop, which would then not account 
	//for it
	int	itemCount = 1;

	//Variables for the first and last number
	double firstNum = 0,
		   lastNum  = 0;

	//Variable to store the average of the first and second number
	double avg = 0;

	//since we're already at the beggining of the file, simply set
	//firstNum to the first item of the file
	dataFile >> firstNum;

	//This loop counts the number of items in the file
	while (!dataFile.eof())
	{
		//Everytime the loop iterates the variable lastNum changes acording
		//to the current iteration. By the time its at the end of the file, the
		//lastNum will be set to the last number in the file, which is what we
		//want
		dataFile >> lastNum;
		itemCount++;
	}
	//Once reached to this point clear the screen for better legibility
	system("CLS");

	//calculate the avg
	avg = ((firstNum + lastNum) / 2);

	//displays the info
	cout << "For the file "				 << name								<< endl
																				<< endl
		<< "There are "					 << itemCount << " numbers in the file" << endl
		<< "The first number is:       " << firstNum							<< endl
		<< "The last number is:        " << lastNum								<< endl
		<< "The average of the two is: " << setprecision(8) << avg				<< endl;

	//Close the file
	dataFile.close();
	system("Pause");
	return 0;
}

/*

	***********************************************************
	IF "data1.txt" IS INPUTED:
	***********************************************************

	For the file data1.txt

	There are 10000 numbers in the file
	The first number is:	   195650
	The last number is:        887747
	The average of the two is: 541698.5
	Press any key to continue...


	***********************************************************
	IF DIFFERENT THINGS RATHER THAN AN EXISTING FILE 
	IS INPUTEDID:
	***********************************************************

	What File should I use? sdasd
	That file does not exist!

	What File should I use? data
	That file does not exist!

	What File should I use? data7.txt
	That file does not exist!

	What File should I use? data1
	That file does not exist!

	What file should I use?

	(will continue to ask unless a file exists or closed manually)

	************************************************************
	IF "data3.txt" IS INPUTED:
	***********************************************************

	For the file data3.txt

	There are 100000 numbers in the file
	The first number is:       195650
	The last number is:        922741
	The average of the two is: 559195.5
	Press any key to continue...

*/
