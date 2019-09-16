#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct to define what's in the phonebook
typedef struct PhoneBookContacts
{
    char Name[20];
    char Surname[20];
    char PhoneNumber[20];
} phone;

//Function prototypes
void AddEntry (phone[]);
void DeleteEntry (phone[]);
void PrintEntry (phone[]);
void Sort (phone[]);
int counter = 0; //Global counter variable used to keep track of number of contacts

//Begin main function
int main (void)
{
    phone phonebook[20]; //Phonebook instance
    char userChoice; //Variable to use to select menu choice

    while (userChoice != 'Q') {
        printf ("***************\n");
        printf ("Please enter a command:\n");
        printf("'A': Add an entry\n");
        printf("'D': Delete an entry\n");
        printf("'S': Sort entries\n");
        printf("'P': Print the phonebook\n");
        printf("'Q': Quit\n");
        printf ("***************\n");

        scanf("%s", &userChoice);  //Stores menu choice into variable userChoice

        // Add Contact
        if (userChoice == 'A')
            AddEntry(phonebook);

        //Remove Contact
        if (userChoice == 'D')
            DeleteEntry (phonebook);

        //Print Contacts
        if (userChoice == 'P')
            PrintEntry(phonebook);

        //Sort Contacts
        if (userChoice == 'S')
            Sort(phonebook);

        //Quit
        if (userChoice == 'Q') {
            printf("Phonebook will now quit.");
            return 0;
        }
    }
}

//Function Definition to Add Contacts to the Phonebook
void AddEntry (phone phonebook[]) {
    counter++; //global counter increase

    printf("\nFirst Name: ");
    scanf("%s", phonebook[counter-1].Name); //counter-1 b/c arrays start at 0

    printf("Last Name: ");
    scanf("%s", phonebook[counter-1].Surname);

    printf("Phone Number (XXX-XXX-XXXX): ");
    scanf("%s", phonebook[counter-1].PhoneNumber);

    printf("\n%s added to phonebook\n", phonebook[counter-1].Name); //tell user friend added
}

void DeleteEntry (phone phonebook[])
{
    int x = 0;
    char deleteName[20];  // Temp string to compare to existing phonebook
    char deleteSurname[20];  //temp string
    char nullStr[20] = {"\0"};  // empty string to remove phonenumber

    printf("\nEnter name: ");
    scanf("%s", deleteName); //place into temp string
    printf("Enter Surname: ");
    scanf("%s", deleteSurname); //place into temp string

    for (x = 0; x < counter; x++)
    {
        if (strcmp(deleteName, phonebook[x].Name) == 0) //compare deleteName to phonebook.Name
        {
            for (x = 0; x < counter; x++)
            {
                if (strcmp(deleteSurname, phonebook[x].Surname) == 0) //If deleteSurname matches phonebook.Surname
                {
                    strcpy(phonebook[x].Name, nullStr); //Put null into Name
                    strcpy(phonebook[x].Surname, nullStr); //Null into Surname
                    strcpy(phonebook[x].PhoneNumber, nullStr); //Null into PhoneNumber
                    printf("Contact removed from phonebook.\n");
                    counter--;
                    break;
                }
            }

        }
        else printf("Invalid entry--try again.\n");
    }
}

// Function def to print contacts
void PrintEntry (phone phonebook[]) {
    int x = 0;
    printf("\nPhonebook entries:\n");

    for ( x = 0; x < counter; x++) {
        printf("\n(%d)\n", x+1); //Show contact number
        printf("Name: %s %s\n", phonebook[x].Name, phonebook[x].Surname); //Name
        printf("Number: %s\n", phonebook[x].PhoneNumber); //Number
    }
}

void Sort (phone phonebook[]) {
    phone temp;
    int i;  int j;

    for (i=0; i<19; i++) {
        for (j=i+1; j<19; j++) {
            if (strcmp(phonebook[i].Surname, phonebook[j].Surname) > 0) {
                temp=phonebook[i];
                phonebook[i]=phonebook[j];
                phonebook[j]=temp;
            }
        }
    }
}
