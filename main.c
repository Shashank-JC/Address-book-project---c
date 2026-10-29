/*Name = SHASHANK J C
  Date = 27/09/2026
  Batch id = 26018f
  ADDRESS BOOK   
  The Address Book is a C-based application used to manage contact information such as names, phone numbers, and email addresses.
It allows users to create, search, edit, delete, and list contacts, with contact data stored in a CSV file for future use.*/
#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\n-----------------------------------------------------------------------------\n");
        printf("Address Book Menu:\n");   //Address book menu displaying for user
        printf("-----------------------------------------------------------------------------\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");    
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("-----------------------------------------------------------------------------\n");
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
            {
            int searchChoice;
            do{
            printf("\n-----------------------------------------------------------------------------\n");
                printf("Select search criteria:\n");   // search menu to search the contact
                printf("-----------------------------------------------------------------------------\n");
                printf("1. Search by name\n");
                printf("2. Search by phone\n");
                printf("3. Search by email\n");
                printf("4. Exit\n");
                printf("-----------------------------------------------------------------------------\n");
                printf("Enter your choice: "); 
                scanf("%d", &searchChoice);
                if((searchChoice>=1&&searchChoice<=4)==0)
                {
                printf("Invalid choice. Please try again.\n");
                continue;
                }
                printf("-----------------------------------------------------------------------------\n");
                searchContact(&addressBook,searchChoice);
            }while(searchChoice!=4);
                break;
        }
            case 3:
            {
             int editChoice;
            do{
            printf("\n-----------------------------------------------------------------------------\n");
            printf("Select edit criteria:\n");       // edit menu to edit the contact
            printf("-----------------------------------------------------------------------------\n");
                printf("1. edit by name\n");
                printf("2. edit by phone\n");
                printf("3. edit by email\n");
                printf("4. Exit\n");
                printf("-----------------------------------------------------------------------------\n");
                printf("Enter your choice: ");
                scanf("%d", &editChoice);
                if((editChoice>=1&&editChoice<=4)==0)
                {
                printf("Invalid choice. Please try again.\n");
                continue;
                }
                printf("-----------------------------------------------------------------------------\n");
                editContact(&addressBook,editChoice);
            }while(editChoice!=4);
                break;
        }
            case 4:
            {
            int deleteChoice;
                do{
                printf("\n-----------------------------------------------------------------------------\n");
                printf("Select delete criteria:\n");    // delete menu to delete the contact
                printf("-----------------------------------------------------------------------------\n");
                printf("1. delete by name\n");
                printf("2. delete by phone\n");
                printf("3. delete by email\n");
                printf("4. Exit\n");
                printf("-----------------------------------------------------------------------------\n");
                printf("Enter your choice: ");
                scanf("%d", &deleteChoice);
                if((deleteChoice>=1&&deleteChoice<=4)==0)
                {
                    printf("Invalid choice. Please try again.\n");
                    continue;
                }
                printf("-----------------------------------------------------------------------------\n");
                deleteContact(&addressBook,deleteChoice);
            }while(deleteChoice!=4);
                break;
        }
            case 5:
               
                listContacts(&addressBook);
                break;
            case 6:
                printf("Saving and Exiting...\n");    // saving the contact to file before programme termination
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");    // choice is not matched to any case it print invalid
        }
    } while (choice != 6);
    
       return 0;
}
