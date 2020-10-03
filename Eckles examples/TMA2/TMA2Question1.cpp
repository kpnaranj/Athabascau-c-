//: TMA2Question1.cpp

/* 
   Title: TMA2Question1.cpp
   Description: 
   
   Write a program to manage DVD rental in a video rental store. Create an abstract data type that 
   represents a DVD in this store. Consider all the data and operations that may be necessary for 
   the DVD type to work well within a rental management system. Include a print() member function 
   that displays all the information about the DVD. Test your data type by creating an array of ten 
   DVD instances and filling them using information read from a test input file that you create. 
   Display the DVD information.

   Date: March 28, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Notes: I adapt and create new members for learning purposes, my goal was to create a simple sofware 
   service that can read previous information of clients, change information and add new information. 
   The activity delivery is: 'Question1.h' and 'Question1.cpp'. The rest 'Question1B.h' 'Question1B.cpp' are
   used as practice to create a more complex project and effectively understand topics such as classes, 
   pointers to functions and allocation of memory. I would appreciate feedback of my additional implementations
   
   Program Purpose: 
 		Measure level of understanding when creating object classes to effectively allocate memory in strings
 		using arrays and member functions 
 		Also, use learning material to create effective data types that can access private members and read 
 		information
 
 	Compile: g++ Question1.cpp  Question1B.cpp TMA2Question1.cpp -o TMA2Question1.exe
 	Makefile: make 
 	Execution: ./TMA2Question1.exe

 	Classes: DVD
 	Type definition: 
 	uint - unsigned int - used to short nomenclature of members 
 	
 	Variables: 
 	In Question1.h:
 	private:
 	userName - string - private member used to store clients information of a text file
	movieTitle - string - private member used to store movie title of a text file
	movieGenre - string - private member used to store movie genre of a text file 
	movieYear - string - private member used to store movie year of a text file 
	movieRentStart - string - private meber used to store start of rent of movie of a text file
	movieRentEnd - string - private member used to store end of rent of movie from a text file 
	movieCost - string - private member used to store the cost of movie in a file
	
	public:
	DVD() - constructor - To initialize private members of DVD when an object class is created 
	~DVD()- destructor - To deallocate memory of private members when an object class is deleted
	getName() - string - To access private member 'username' and return a string value
	getTitle() - string - To access private member 'movieTitle' and return a string value
	getGenre() - string - To access private member 'movieYear' and return a string value
	getYear() - string - To access private member 'movieYear' and return a string value
	getStart() - string - To access private member 'movieRentStart' and return  a string value
	getEnd() - string - To access private member 'movieEndStart' and return a string value
	getCost() - string - To access private member 'movieCost' and return a string value
	getDates() - void - To access private members 'movieRentStart' & 'movieRentEnd'and return a string value
	print(uint ...) - void - Member function to print return values of other member functions
	user - uint - Unsigned integer to search for user in print value
	setFunctions(string ..., uint ...) - member function to store memory from user and text files 
	info - string - parameter used to pass text information of user changes in the program
	change - uint - parameter used to find member function and change their values
	
	Notes:
	1) The use of uint 'user' in 'print()' is an addition, for common example uint is not needed since print is 
	stored directly from the text and users are given in order, for this case uint is used to interact with the 
	user for information that was changed 
	2) A constructor DVD could have beed added as DVD(string, string, ..) for new variables instead of setFunctions(), 
	I decided to add this version for convenience of second implementation 
	3) The use of getDates() is an optional feature, it could have beend added in print, its use is for convenience
	of second implementation
	
	In Question1.cpp
	return and definition of member function and private members 
	
	**(Alternately)************************************************************************************************
	In Question1B.cpp:
	Initialization and declaration of member functions and private members 
	isWorking - bool - used to go through a swicth statement and return false once the process has been completed
	
	In Question1B.h:
	dvd[] - DVD - class object passed by reference to change values of string in functions 
	user - uint - unsigned integer used to search number of user
	temp - uint& - unsigned integer used to determine the change number in switch statemt that needs to be change
	select - uint& - unsigned integer used for user to change or select menu and other commands 
	validation(DVD ...,uint ..., uint& ...) - void - used to allocate information of DVD that needs to be changed or added
	validate(uint &...) - void - used to verify that the entered information is not a string for numbers input 
	menu() - void - content menu template to display at the beginning of the text
	frame() - void - '/' lines to reference different steps of the client 
	clean() - void - function that cleans a invalid command
	accept(uint &...) void - function that displays content if wrong information was displayed  
	
	***************************************************************************************************************
	
	In TMA2Question1.cpp:
	sizeDVD - const uint - used to keep requirements of assignment in size for 10 users 
	dvd - DVD* - DVD object class with member functions to add content in the class by dinamically allocating new class
	counter - uint - unsigned int used to track number of clients after actions are added 
	temp - uint - (discuss in Question1B.h) used to select the number of option to store memory
	valid - uint - optional - unsigned int  used to track the changes the user has changed or added in the private strings
	command - uint - used to select menu options and store input values entered by the user
	info - string - used to store content input given by the user to DVD class 
	nLine - string - used to navegate throught a first txt. document and store it in a private member from DVD class
	nLine2 - string - used to navegate through a second txt. document and store it in a private member from DVD class
	isWorking - bool - used in while loop to repeat actions of storage and menu for the user 
	available - uint - optional - used as a tracker of a value entered by the user in case the user wants to keep the 
	information added in a class previously 
	input1 - ifstream - used to open text document "NamesRent.txt " and read content 
	input2 - ifstream - used to open text document "VideoAvailable.txt" and read content 
	read - ifstream - used to show text document "VideoAvailable.txt" without storing a string previously
	selection - uint - used to store values entered by the user in the movie selection 
	
	External Files:
	NamesRent - txt - text document that contains 10 user information used to add information in dvd class 
	VideoAvailable - txt - text document that contains 10 movie information used to add information in dvd class and allow user
	add personal information
	
	TEST PLAN
	
	Normal case(without additional options): 
	>"Loading ..."
	>Menu screen and framework is displayed
	>"Welcome to S&S videos, please choose one of the following actions"
	>"1.Show lists of clients in the store"
	>"2.Exit" (second option is additional case)
	>User enter 1 
	>"Here list of clients: "
	>A list of 10 clients is displayed Ex.
	         User #1
		User: Peter_Hard
		Title of movie: The_Godfather
		Year of movie: (1972)
		Genre of the movie: Crime
		Cost of the movie/month: 12,00
		Start of Rent: 1/26/2017
		End of Rent: 6/21/2017
		
		User #2 ....User#3 .... User #10 
		
		Please select other options to continue
	>While loop returns to Menu option 
	>"Loading..."(steps 1,2,3 and 4 are repeated)
	>User enters 2 (with options is alternative 3)
	>"You press 3 for exit, thanks"
	>Memory is freeing 
	>Program finishes (return 0)	
	
	Normal case(with additional implementation):
	>"Loading ..."
	>Menu screen and framework is displayed
	>"Welcome to S&S videos, please choose one of the following actions"
	>"1.Show lists of clients in the store"
	>"2.Change/add clients of the list" 
	>"3.Exit"
	>User press 1
	>(Normal case (without additional options) happends)
	>User returns to menu option 
	>User enters 2
	>"Please select a number from 1 to 10 to change client or
	  information you want to update" 
	>User enters 1 to change user #1
	>"Please add a client's name"
	>User enters name ex. "Kevin"
	>"Now please select start date of rent of the movie, ex. 3/26/2019"
	>User enters start date of rent ex. "4/1/2019" (user can add a different format if desired)
	>"Now please select the date of return, date should be greater than start date, ex. 3/29/2019"
	>User enters end date of rent ex. "7/24/2019" 
	>Clients information is displayed for verification 
	>"You selected :"
		"Name: " Kevin
		"Start Rent: " 3/19/2019
		"Finish Rent: " 7/24/2019
	>"Press n to change values or enter to continue" (for bad case)
	>User presses enter
	>A list of videos is pisplayed 
	>"Here the list of videos"
	>1. The_Godfather (1972) Crime 12,00
	 2. Schindler's_List (1993) Biografy 10,00
	 3 . .....
	 10 ......
	>"Choose the movie you want"
	>User enters value number ex . 1
	>User changes are displayed ex.
		User #1 
	 User: Kevin
	 Title of the movie: The_Godfather
	 Year of the movie: (1972)
	 Genre of the movie: Crime
	 Cost of the movie/month: 12,00
	 Start of Rent: 3/19/2019
	 End of the Rent: 7/24/2019
	>"You can see changes with option 1 for user# 1 or make changes with option 2"
	>"Thanks for prefering us!!!, have a nice day"
	>Menu option is displayed
	>User enters 1 
	>(If a user was enter previously)ex. "The user #1 was previously added,
	 	do you want to keep the informaton? (y/n).."
	>User presses y
	>List of clients is displayed withouth changing user 1 info
	>Menu option is displayed
	>User presses 3 
	>"You press 3 for exit, thanks"
	
	Notes: This has a similar format if user press 2 first and then 1 
	
	Bad case(nonsense & wrong value) at the beginnning
	>Option menu is displayed
	>User enters "5" (not supported)
	>"Invalid command, you will be redirected to menu"
	>Menu option is displayed again
	>user presses "sscdcdcd"
	>"Invalid command, you will be redirected to menu"
	>Menu option is displayed
	>User decides use supported values 
	>User enters either 1 or 3
	>Normal cases lines
	
	Bad case (nonsense & wrong value) after pressing 2 in menu options
	>"Press select a number from 1 to 10 ...."
	
		Wrong value:
	>User enters 12
	>"Incorrect output, you will be redirected to menu" 
	Nonsense:
	>User retuns to menu option 
	
		Nonsense:
	>User enters sdadadsd
	>"You have not enter a value"
	>"Incorrect output, you will be redirected to menu"
	
	>Normal cases lines
	
	Bad case (nonsense & wrong value) after displayed of movies
	>"Here the list of videos:"
	>List of videos displayed 
	>"Choose the movie you want"
	
		Wrong values:
	>User presses "321"
	>Incorrect output, please add a value again (while loop that will proceed only if user press a valid number)
	
	
		Nonsense:
	>User presses "dcsv"
	>You have not entered a value
	>Incorrect output, press add a value again (while loop will proceed only with valid number)
	
	>User press a proper number 
	>Normal cases lines
	
	Notes: 
	1. After the second option is displayed and user call twice option 1, the user information will be updated 
	2. User changes options for start and end date needs verification of the user itself, the option of change
	values is added to change oprions if are needed
	3. Clean option was used with additional implementation taken from: 
	https://stackoverflow.com/questions/3876107/while-loop-loops-infinitely-when-wrong-input-is-entered
	4. Frame option is a optional implementation to act as a framework of the program and determine each step of
	the program 
	
	Discussion: 
   	
	This program shows the users that rented a movie and displays their information, additional implementation
	allows the user or the Rental saler to change the information of a previous user. The use of different techniques 
	learned in Unit 5-6-7 where implemented here, for an effective programming design
 */

#include "Question1.h"
#include "Question1B.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Global variables 
const uint sizeDVD = 10;
//Declarations 
int main(){
// Create a dvd list of ten 
	DVD* dvd = new DVD[sizeDVD];
// uint used to track information 
	uint counter{};
	uint temp{};
	uint valid{};
	uint command;
	uint available[sizeDVD]{};
//string used to add information or read a txt file 
	string info{};
	string nLine;
	string nLine2;
//bool used to make while loop work properly 
	bool isWorking = true;
	
// Process 
	
	while(isWorking == true){
	//Read the documents 
		ifstream input1("NamesRent.txt");
		ifstream input2("VideoAvailable.txt");
		ifstream read("VideoAvailable.txt");
	//Confirm the documents are open 	
		if(input1.is_open()&&input2.is_open()){
		cout<<"Loading.."<<endl;	
		}
	//Show menu and add values 
		menu();
		cin>>command;
	//User press option 1 (case required for question 1)
		if(command == 1){
			cout<<"Here list of clients:"<<endl;
			getline(cin,info);
			for (uint i = 1; input1>>nLine; i++){
				temp++;
				/*Optional - User to validate a number entered by user*/
				if(available[counter]!=0&&info!="y"){
					cout<<"The user #"<<counter+1<<" was added for you previously\n"
					<<"do you want to keep the information? (y/n).."<<endl;
					getline(cin,info);
					available[counter]=0;
				}
				
				if(info == "y"&&available[counter]==0){
					valid++;
					if(valid==7){
						info = "n";	
						valid=0;
					}
				}
				/*optional*/
				else{
					dvd[counter].setFunctions(nLine,temp);
				}
				
				//Each 7 lines a word is detected increase the counter a reduce temp to 0
				//Temp stores the value in a switch statement 
				if(i%7 == 0){
					counter ++;
					temp=0;
				}
				
				/*Without implementations 
					dvd[counter].setfunctions(nLine, temp);
					if(i%7 == 0){
					counter ++;
					temp=0;
					}
				*/
			}
			//Print values 
			for(uint i = 0; i < sizeDVD; i++){
				frame();
				dvd[i].print(i);
			}
			cout<<endl;
			cout<<"Please select other option to continue"<<endl;
		}
		
		/*Optional - Used to change or add user info*/
		else if(command == 2){
			frame();
			cout<<"Please select a number from 1 to 10 to change client\n"
				<<" or information you want to update"<<endl;
			//Command change number 
			cin>>command;
			getline(cin, info);
			frame();
			//Command enters only if values are within 1 and 10
			if(command<=10&&command >=1){
				//info is added to change the option by user
				info = "n"; 
				while (info =="n"){
					cout<<"Please add a client's name"<<endl;
					temp = 1;
					
					validation(dvd,command - 1,temp);
					
					frame();
					
					cout<<"Now, please select start date of rent of the movie"
						<<", ex. 3/26/2019"<<endl;
					temp += 5;
					validation(dvd, command - 1, temp);
					
					frame();
					
					cout<<"Now, please select the date of return, date should\n "
						<<"be greater than start date, ex. 3/29/2019"<<endl;
					temp++;
					validation(dvd, command - 1, temp);
					
					frame();
					
					cout<<"You selected:"<<endl;
					cout<<"Name: "<<dvd[command-1].getName()<<"\n"
						<<"Start Rent: "<<dvd[command-1].getStart()<<"\n"
						<<"Finish Rent: "<<dvd[command-1].getEnd()<<endl;
					
					cout<<"Press n to change values or enter to continue"<<endl;
					getline(cin,info);
					frame();
				}
				
				// End while
				
				cout<<"Here the list of videos: "<<endl;
				for (uint i = 1; getline(read,nLine); i++){
					cout<<" "<<i<<". "<<nLine+" "<<endl;
					counter++;
				}
				// Selection used to select movie 
				uint selection;
				cout<<"Choose the movie you want "<<endl;
				cin>>selection;
				
				accept(selection);
			
				frame();
				
				if (command-1==0){
					available[command-1] = command;
				}
				else{
					available[command-1] = command-1;
				}
				
				temp =2;
				for (uint i = 0; input2>>nLine2; i++){
					
					if ((i%4==0&&selection!=0)||(i ==0&&selection!=0)){
						selection --;	
					}

					if(selection==0){
						dvd[command-1].setFunctions(nLine2,temp);
						temp++;
						if((i+1)%4==0){
							break;
						}
					}	
				}
				dvd[command-1].print(command-1);
				frame();
				cout<<"Youn can see changes with option 1 for user# "<<command<<"\n"
					<<"or make changes with option 2\n"
					<<"Thanks for prefering us!!!, have a nice day"<<endl;
				cout<<endl;
				frame();
				cout<<"You will go now to the main menu"<<endl;
			}
			//If an input is invalid
			else{
				validate(command);
				cout<<"Incorrect output, you will be redirected to menu"<<endl;
			}
			
		}
		/*Optional*/
		
		//
		/*Exit option - only way of executing program*/
		else if(command == 3){
			cout<<"You press 3 for exit, thanks"<<endl;
			break;
			frame();
		}
		else {
			clean();
			cout<<"Invalid command, you will be redirected to menu"<<endl;
			
		}
		//To return counter values to 0 and return the while loop
		counter=0;
		temp=0;
	}
	//Freeing memory
	delete []dvd;
	return 0;
}