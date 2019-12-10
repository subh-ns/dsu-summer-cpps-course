#include <stdio.h>
#include <stdlib.h>
#include <string.h>      //string functions
#include<ctype.h>          

//typedef struct to define what's in the phonebook
typedef struct PhoneBookContacts
{
	char Name[20];
	char Surname[20];
	char PhoneNumber[20];
	char email[20];
}phone;

//Function prototypes
void AddEntry (phone[]);
void DeleteEntry (phone[]);
void PrintEntry (phone[]);
int isEmpty();
int counter = 0; //Global counter variable used to keep track of number of contacts
int main ()
{
	phone phonebook[20]; //Phonebook instance
	char userChoice; //Variable to use to select switch case choice
	do
	{
		printf ("***************\n");
		printf ("Please enter a command:\n");
		printf("'A': Add an entry\n");
		printf("'D': Delete an entry\n");
		printf("'P': Print the phonebook\n");
		printf("'Q': Quit\n");
		printf ("***************\n");
		scanf(" %c", &userChoice);  //Stores switch case choice into variable 'userChoice'
		switch(userChoice)
		{
			// Add Contact
			case 'a':case'A':
					AddEntry(phonebook);
					break;
			//Remove Contact	
			case 'd':case 'D':
					if(isEmpty()==1)
						printf("The Phonebook is already empty.\n");
					else
						DeleteEntry (phonebook);
					break;
			//Print Contacts
			case 'p':case 'P':
					if(isEmpty()==1)
						printf("The phonebook is empty. Please add new contacts to print.\n");
					else
						PrintEntry(phonebook);
					break;
			//Quit
			case 'q':case 'Q':
					printf("Phonebook will now quit.\n");
					exit(0);
			default:
				printf("The input is invalid. Please try again.\n");
		}			
	}while(userChoice!='Q'||userChoice!='q');
}
int isEmpty()
{
	if(counter<=0)
		return 1;
	else
		return 0;
}
//Function Definition to Add Contacts to the Phonebook
void AddEntry (phone phonebook[]) 
{
	int phone_digit=0,check,len;
	counter++; //global counter increase
	printf("\nFirst Name: ");
	scanf("%s", phonebook[counter-1].Name); //counter-1 b/c arrays start at 0
	printf("Last Name: ");
	scanf("%s", phonebook[counter-1].Surname);
	printf("Phone Number (XXX-XXX-XXXX): ");
	scanf("%s",phonebook[counter-1].PhoneNumber);
	printf("Email: ");
	scanf("%s",phonebook[counter-1].email);
	printf("\n%s added to phonebook\n", phonebook[counter-1].Name); 	
}

void DeleteEntry (phone phonebook[])
{
	int x = 0,check;
	char deleteName[20];  // Temp string to compare to existing phonebook
	char deleteSurname[20];  //temp string
	char nullStr[20] = {"\0"};  // empty string to remove phonenumber
	printf("\nEnter name: ");
	scanf("%s", deleteName); //place into temp string
	printf("Enter Surname: ");
	scanf("%s", deleteSurname); //place into temp string
	for (x = 0; x < counter; x++)
	{
		if (strcmp(deleteName, phonebook[x].Name) == 0 && strcmp(deleteSurname,phonebook[x].Surname)==0) //compare deleteName to phonebook.Name
		{
				check=1;
				break;
		}			
		else
		{
			check=0;
			continue;
		}	
	}
	if(check==1)
	{
		strcpy(phonebook[x].Name, nullStr); //Put null into Name
		strcpy(phonebook[x].Surname, nullStr); //Null into Surname
		strcpy(phonebook[x].PhoneNumber, nullStr); //Null into PhoneNumber
		strcpy(phonebook[x].email,nullStr);//Null into email
		printf("Contact removed from phonebook.\n");
		counter--;
	}
	else
	{
		printf("Invalid entry. Please try again.\n");
	}
}
// Function to print contacts
void PrintEntry(phone phonebook[]) 
{
	int x = 0;
	printf("\nPhonebook entries:\n");
	for ( x = 0; x < counter; x++) 
	{
		printf("\n(%d)\n", x+1); //Show contact number
		printf("Name: %s %s\n", phonebook[x].Name, phonebook[x].Surname); //Name
		printf("Number: %s\n", phonebook[x].PhoneNumber); //Number
		printf("Email: %s\n",phonebook[x].email);//E-mail
	}
}




