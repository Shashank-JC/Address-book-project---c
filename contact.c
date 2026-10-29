#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include <ctype.h>

void listContacts(AddressBook *addressBook) 
{
  for(int i = 0; i < addressBook->contactCount - 1; i++)
    {
        for(int j = 0; j < addressBook->contactCount - i - 1; j++)
        {
            if(strcmp(addressBook->contacts[j].name,
                      addressBook->contacts[j + 1].name) > 0)
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }  
printf("\n-------------------------List of all contact-----------------------------\n");
printf("\n-----------------------------------------------------------------------------\n");
printf("%-5s %-20s %-15s %-30s\n",
       "Sl.No", "Name", "Mobile Number", "Email");
printf("-----------------------------------------------------------------------------\n");
for(int i = 0; i < addressBook->contactCount; i++)    // listing the saved contact
{
   printf("%-5d %-20s %-15s %-30s\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
                                                                                                        
}
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
   
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    char str[20];
    int flag = 1, attempt = 0;
    
    while(flag  && (addressBook->contactCount)<MAX_CONTACTS)
    {
        printf("\n-----------------------------------------------------------------------------\n");
        printf("Enter the name\n");    //creating contact name
        attempt = 0;

        while(attempt < 3)
        {
            scanf(" %[^\n]", str);

            if(strlen(str) < 3)
            {
                printf("Name must contain at least 3 character\n");
                attempt++;
                continue;
            }

            int i = 0;
            int valid = 1;

            while(str[i] != '\0')
            {
                if(isalpha(str[i]) == 0 && str[i] != ' ')
                {
                    printf("Name must contain only alphabets\n");
                    attempt++;
                    valid = 0;
                    break;
                }
                i++;
            }

            if(valid)
            {
                break;
            }
        }
        
        if(attempt == 3)
        {
            printf("Attempt is completed\n");   //if 3 attempt is completed it print attempt is completed
            return;
        }

        strcpy(addressBook->contacts[addressBook->contactCount].name, str);
        printf("-----------------------------------------------------------------------------\n");
        printf("Enter the mobile no\n");      
        attempt=0;
        while(attempt<3)
        {
            scanf("%s",str);         //creating contact phone number
            if(strlen(str)!=10)
            {
                printf("Phone number must contain exactly 10 digits\n");
                attempt++;
                continue;
            }
            if((str[0]>='6'&&str[0]<='9')==0)
            {
                printf("First digit must be between 6 and 9\n");
                attempt++;
                continue;
            }
            int i=0;
            int valid = 1;
            while(str[i]!='\0')
            {
            if(isdigit(str[i])==0)
            {
                printf("Other than digit any other character not allowed in phone number\n");
                attempt++;
                valid=0;
                 break;
            }
            i++;
           }
            if(valid==0)
            continue;
           int check=0;
           for(int i=0; i<addressBook->contactCount; i++)
           {
                if(strcmp(str,addressBook->contacts[i].phone)==0)
                {
                    printf("Already same phone number is exist\n");
                    attempt++;
                    check=1;
                    break;
                }
           }
           if(check==0)
           break;
        
            
           
        }

       if(attempt == 3)
        {
            printf("Attempt is completed\n");  //if 3 attempt is completed it print attempt is completed
            return;
        } 
       strcpy(addressBook->contacts[addressBook->contactCount].phone, str); 
       printf("-----------------------------------------------------------------------------\n");
       printf("Enter the email\n");
       attempt=0;
       while(attempt<3)
       {
          scanf(" %[^\n]", str);  // creating contact email
          int i=0,check=0;
          if(str[0]=='@'||str[0]=='.')
          {
          printf("@ or . not the first character\n");
          attempt++;
          continue;
          }
          while(str[i]!='\0')

          {
             
             if(isdigit(str[i])==0 && islower(str[i])==0 && str[i] != '@' && str[i] != '.')
             {
                printf("Email must contain only lowercase and digit\n");
                attempt++;
                check=1;
                break;
             }
            i++;
          }
          if(check==1)
          {
            continue;
          }
           i=0;
           int at=0,dot=0,index,dotindex;
          while(str[i]!='\0')
          {
             if(str[i]=='@')
             {
                at++;
                index=i;
             }  
             if(str[i]=='.')
             {
                dot++;
                dotindex=i;
             }
            i++;
          }
          if(at!=1)
          {
              printf("Email id must contain at least one @\n");
              attempt++;
              continue;
          }
          if(dot!=1)
          {
            printf("Email id must contain at least one .\n");
              attempt++;
              continue;
          }
          if(dotindex<index)
          {
            printf(" . must be appear after @ symbol\n");
            attempt++;
            continue;
          }
          i=index;
          if(str[i+1]=='.')
          {
            printf("There must be at least one character between @ and .\n");
            attempt++;
            continue;
          }
          if(str[dotindex+1]=='\0')
          {
            printf("The email ends with something after the final .\n");
            attempt++;
            continue;
          }
          if((str[dotindex+1]=='c'&&str[dotindex+2]=='o'&&str[dotindex+3]=='m')==0)
          {
            printf("The email ends with com after .\n");
            attempt++;
            continue;
          }
          if(str[dotindex+4]!='\0')
          {
            printf("No extra character after the domain\n");
            attempt++;
            continue;
          }
           int check1=0;
           for(int i=0; i<addressBook->contactCount; i++)
           {
                if(strcmp(str,addressBook->contacts[i].email)==0)
                {
                    printf("Already same email is exist\n");
                    attempt++;
                    check1=1;
                    break;
                }
           }
           if(check1==0)
           break;
       }
       if(attempt == 3)
        {
            printf("Attempt is completed\n");  //if 3 attempt is completed it print attempt is completed
            return;
        } 
       strcpy(addressBook->contacts[addressBook->contactCount].email, str);  
        printf("-----------------------------------------------------------------------------\n");
        addressBook->contactCount++;
        printf("Contact created successfully.........\n");
        printf("\n-----------------------------------------------------------------------------\n");
        printf("If you want to add another: if Yes ->1/No ->0\n");
        scanf("%d", &flag);
        printf("-----------------------------------------------------------------------------\n");
    }
}
void searchContact(AddressBook *addressBook, int searchCriteria) 
{
    char str[20];
   if(searchCriteria==1)
   {
    printf("-----------------------------------------------------------------------------\n");
   printf("Enter the name\n");    // searching contact details based on menu choice
   scanf(" %[^\n]",str);
   printf("-----------------------------------------------------------------------------\n");
   }
   if(searchCriteria==2)
   {
    printf("-----------------------------------------------------------------------------\n");
   printf("Enter the phone number\n");
   scanf(" %[^\n]",str);
   printf("-----------------------------------------------------------------------------\n");
   }
   if(searchCriteria==3)
   {
    printf("-----------------------------------------------------------------------------\n");
   printf("Enter the email\n");
   scanf("  %[^\n]",str);
   printf("-----------------------------------------------------------------------------\n");
   }
   if(searchCriteria==4)
   {
    return;     // if menu choice is 4 it exit from the search function
   }
   int index,i=0,dupli=0;
   while(i<addressBook->contactCount)
   {
      index=0;
      if(searchCriteria==1)
      {
      if(strcmp(str,addressBook->contacts[i].name)==0)
      {
         index=1;           // searching contact details using strcmp
      }
      }
      if(searchCriteria==2)
      {
      if(strcmp(str,addressBook->contacts[i].phone)==0)
      {
        index=1;
      }
      }
      if(searchCriteria==3)
      {
      if(strcmp(str,addressBook->contacts[i].email)==0)
      {
          index=1;
      }
      }
      if(index==1)
      {
        printf("\n------------------contact found------------------------\n");
        printf("\n-----------------------------------------------------------------------------\n");
        printf("%-5s %-20s %-15s %-30s\n",
       "Sl.No", "Name", "Mobile Number", "Email");
        printf("---------------------------------------------------------------------------------\n");
       printf("%-5d %-20s %-15s %-30s\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
           printf("-----------------------------------------------------------------------------\n");
           printf("Index = %d\n",i);
           printf("-----------------------------------------------------------------------------\n");
        dupli++;
     }
      i++;
   }
   if(dupli==0)
   {
    printf("There is no contact found\n");
    return;
   }
   if(dupli>1)
   {
     while(1)    //if user enter contact present more than one giving option to enter which index you want to search
     {
        printf("Enter which index you want\n");
        scanf("%d",&i);
        if(searchCriteria==1)
        {
            if(strcmp(str,addressBook->contacts[i].name)==0)  // checking user given index is correct or not
            {
               break;                       // if it correct index printing contact based on choice
            }
            else
            {
               printf("Enter the valid matched index\n");
               continue;
            }
        }
        if(searchCriteria==2)
        {
            if(strcmp(str,addressBook->contacts[i].phone)==0)
            {
            break;
            }
            else
            {
               printf("Enter the valid matched index\n");
               continue;
            }
        }
       if(searchCriteria==3)
        {
            if(strcmp(str,addressBook->contacts[i].email)==0)
            {
            break;
            }
            else
            {
               printf("Enter the valid matched index\n");
               continue;
            }
        }
   }
        printf("\n-----------------------------------------------------------------------------\n");
          printf("%-5s %-20s %-15s %-30s\n",
       "Sl.No", "Name", "Mobile Number", "Email");
         printf("-----------------------------------------------------------------------------\n");
        printf("%-5d %-20s %-15s %-30s\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
  
}
}

void editContact(AddressBook *addressBook, int editChoice)
{
    char str[20];
    int index1;      // editing contact details using menu choice
   if(editChoice==1)
   {
   printf("\n----------------------------------------------------------------------------------\n");
   printf("Enter the name\n");
   scanf(" %[^\n]",str);
   printf("----------------------------------------------------------------------------------\n");
   }
   if(editChoice==2)
   {
    printf("\n----------------------------------------------------------------------------------\n");
   printf("Enter the phone number\n");
   scanf(" %[^\n]",str);
   printf("----------------------------------------------------------------------------------\n");
   }
   if(editChoice==3)
   {
    printf("\n----------------------------------------------------------------------------------\n");
   printf("Enter the email\n");
   scanf("  %[^\n]",str);
   printf("----------------------------------------------------------------------------------\n");
   }
   if(editChoice==4)
   {
     return;
   }
   int index,i=0,dupli=0;
   while(i<addressBook->contactCount)
   {
      index=0;
      if(editChoice==1)
      {
      if(strcmp(str,addressBook->contacts[i].name)==0)
      {
         index=1;
         index1=i;
      }
      }
      if(editChoice==2)
      {
      if(strcmp(str,addressBook->contacts[i].phone)==0)
      {
        index=1;
        index1=i;
      }
      }
      if(editChoice==3)
      {
      if(strcmp(str,addressBook->contacts[i].email)==0)
      {
          index=1;
          index1=i;
      }
      }
      if(index==1)
      {
        printf("\n------------------contact found------------------------\n");
        printf("\n-----------------------------------------------------------------------------\n");
        printf("%-5s %-20s %-15s %-30s\n",
       "Sl.No", "Name", "Mobile Number", "Email");
        printf("---------------------------------------------------------------------------------\n");
       printf("%-5d %-20s %-15s %-30s\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
           printf("-----------------------------------------------------------------------------\n");
           printf("Index = %d\n",i);
           printf("-----------------------------------------------------------------------------\n");
        dupli++;
        }
        i++;
      }
      
   
   if(dupli==0)
   {
    printf("There is no contact found\n");
    return;
   }
   if(dupli>1)
   {              // if any duplicate found asking user to enter index 
     while(1)
     {
        printf("Enter which index you want\n");
        scanf("%d",&i);
        index1=i;
        if(editChoice==1)
        {
            if(strcmp(str,addressBook->contacts[i].name)==0)   // comparing given index is correct or not
            {
            break;
            }
            else
            {
               printf("Enter the valid matched index\n");
               continue;
            }
        }
        if(editChoice==2)
        {
            if(strcmp(str,addressBook->contacts[i].phone)==0)
            {
            break;
            }
            else
            {
               printf("Enter the valid matched index\n");
               continue;
            }
        }
    

       if(editChoice==3)
        {
            if(strcmp(str,addressBook->contacts[i].email)==0)
            {
            break;
            }
            else
            {
               printf("Enter the valid matched index\n");
               continue;
            }
        }

  
    }
     printf("\n-----------------------------------------------------------------------------\n");
          printf("%-5s %-20s %-15s %-30s\n",
       "Sl.No", "Name", "Mobile Number", "Email");
         printf("-----------------------------------------------------------------------------\n");
        printf("%-5d %-20s %-15s %-30s\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
}
    char str1[20];
    int attempt;
    if(editChoice==1)
    {
       attempt = 0;

        while(attempt < 3)
        {
            printf("\n--------------------------------------------------------------------------------\n");
            printf("Enter the new name\n");
            scanf(" %[^\n]", str1);           // validating new editing contact 
            printf("--------------------------------------------------------------------------------\n");
            if(strlen(str1) < 3)
            {
                printf("Name must contain at least 3 character\n");
                attempt++;
                continue;
            }

            int i = 0;
            int valid = 1;

            while(str1[i] != '\0')
            {
                if(isalpha(str1[i]) == 0 && str1[i] != ' ')
                {
                    printf("Name must contain only alphabets\n");
                    attempt++;
                    valid = 0;
                    break;
                }
                i++;
            }

            if(valid)
            {
                break;
            }
        }
        
        if(attempt == 3)
        {
            printf("Attempt is completed\n");
            return;
        }

    }
     if(editChoice==2)
    {
       attempt=0;
        while(attempt<3)
        {
            printf("\n--------------------------------------------------------------------------------\n");
            printf("Enter the new phone number\n");
            scanf("%s",str1);
            printf("--------------------------------------------------------------------------------\n");
            if(strlen(str1)!=10)
            {
                printf("Phone number must contain exactly 10 digits\n");
                attempt++;
                continue;
            }
            if((str1[0]>='6'&&str1[0]<='9')==0)
            {
                printf("First digit must be between 6 and 9\n");
                attempt++;
                continue;
            }
            int i=0;
            int valid = 1;
            while(str1[i]!='\0')
            {
            if(isdigit(str1[i])==0)
            {
                printf("Other than digit any other character not allowed in phone number\n");
                attempt++;
                valid=0;
                 break;
            }
            i++;
           }
            if(valid==0)
                continue;
                int check=0;
           for(int i=0; i<addressBook->contactCount; i++)
           {
                if(strcmp(str1,addressBook->contacts[i].phone)==0)
                {
                    printf("Already same phone number is exist\n");
                    attempt++;
                    check=1;
                    break;
                }
           }
           if(check==0)
           break;

        }

       if(attempt == 3)
        {
            printf("Attempt is completed\n");
            return;
        } 
    }
     if(editChoice==3)
    {
       attempt=0;
       while(attempt<3)
       {
        printf("\n--------------------------------------------------------------------------------\n");
        printf("Enter the new email\n");
          scanf(" %[^\n]", str1);
          printf("--------------------------------------------------------------------------------\n");
          int i=0,check=0;
          if(str1[0]=='@'||str1[0]=='.')
          {
          printf("@ or . not the first character\n");
          attempt++;
          continue;
          }
          while(str1[i]!='\0')

          {
             if(isdigit(str1[i])==0 && islower(str1[i])==0 && str1[i] != '@' && str1[i] != '.')
             {
                printf("Email must contain only lowercase and digit\n");
                attempt++;
                check=1;
                break;
             }
            i++;
          }
          if(check==1)
          {
            continue;
          }
           i=0;
           int at=0,dot=0,index,dotindex;
          while(str1[i]!='\0')
          {
             if(str1[i]=='@')
             {
                at++;
                index=i;
             }  
             if(str1[i]=='.')
             {
                dot++;
                dotindex=i;
             }
            i++;
          }
          if(at!=1)
          {
              printf("Email id must contain at least one @\n");
              attempt++;
              continue;
          }
          if(dot!=1)
          {
            printf("Email id must contain at least one .\n");
              attempt++;
              continue;
          }
          if(dotindex<index)
          {
            printf(" . must be appear after @ symbol\n");
            attempt++;
            continue;
          }
          i=index;
          if(str1[i+1]=='.')
          {
            printf("There must be at least one character between @ and .\n");
            attempt++;
            continue;
          }
          if(str1[dotindex+1]=='\0')
          {
            printf("The email ends with something after the final .\n");
            attempt++;
            continue;
          }
          if((str1[dotindex+1]=='c'&&str1[dotindex+2]=='o'&&str1[dotindex+3]=='m')==0)
          {
            printf("The email ends with com after .\n");
            attempt++;
            continue;
          }
          if(str1[dotindex+4]!='\0')
          {
            printf("No extra character after the domain\n");
             attempt++;
            continue;
          }
          int check1=0;
           for(int i=0; i<addressBook->contactCount; i++)
           {
                if(strcmp(str1,addressBook->contacts[i].email)==0)
                {
                    printf("Already same email is exist\n");
                    attempt++;
                    check1=1;
                    break;
                }
           }
           if(check1==0)
           break;
       }
       if(attempt == 3)
        {
            printf("Attempt is completed\n");
            return;
        } 
       
    }
      if(editChoice==1)
      {
      strcpy(addressBook->contacts[index1].name,str1); 
      printf("Name updated successfully \n"); 
      }                                                 // editing contact with new contact
      if(editChoice==2)
      {
      strcpy(addressBook->contacts[index1].phone,str1);
      printf("Phone number updated successfully \n"); 
      }
      if(editChoice==3)
      {
      strcpy(addressBook->contacts[index1].email,str1);
      printf("Email updated successfully \n"); 
      }
    }
void deleteContact(AddressBook *addressBook,int deletechoice)
{
  char str[20];
  int index1;         // deleting contact based on user entered choice
   if(deletechoice==1)
   {
   printf("Enter the name\n");
   scanf(" %[^\n]",str);
   }
   if(deletechoice==2)
   {
   printf("Enter the phone number\n");
   scanf(" %[^\n]",str);
   }
   if(deletechoice==3)
   {
   printf("Enter the email\n");
   scanf("  %[^\n]",str);
   }
   if(deletechoice==4)
   {
       return;
   }
   
   int index,i=0,dupli=0;
   while(i<addressBook->contactCount)
   {
      index=0;                     // searching contact
      if(deletechoice==1)
      {
      if(strcmp(str,addressBook->contacts[i].name)==0)
      {
         index=1;
      }
      }
      if(deletechoice==2)
      {
      if(strcmp(str,addressBook->contacts[i].phone)==0)
      {
        index=1;
      }
      }
      if(deletechoice==3)
      {
      if(strcmp(str,addressBook->contacts[i].email)==0)
      {
          index=1;
      }
      }
      if(index==1)
      {
        printf("\n------------------contact found------------------------\n");
        printf("\n-----------------------------------------------------------------------------\n");
        printf("%-5s %-20s %-15s %-30s\n",
       "Sl.No", "Name", "Mobile Number", "Email");
        printf("---------------------------------------------------------------------------------\n");
       printf("%-5d %-20s %-15s %-30s\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
           printf("-----------------------------------------------------------------------------\n");
           printf("Index = %d\n",i);
           printf("-----------------------------------------------------------------------------\n");
        dupli++;
        index1=i;
        }
        i++;
      }
      
   if(dupli==0)
   {
    printf("There is no contact found\n");
    return;
   }
   if(dupli>1)
   {                   // if duplicate found asking user to enter particular index
     while(1)
     {
        printf("Enter which index you want\n");
        scanf("%d",&i);
        index1=i;
        if(deletechoice==1)
        {
            if(strcmp(str,addressBook->contacts[i].name)==0)   // checking index is correct or not
            {
            break;
            }
            else
            {
               printf("Enter the valid matched index\n");
               continue;
            }
        }
        if(deletechoice==2)
        {
            if(strcmp(str,addressBook->contacts[i].phone)==0)
            {
            break;
            }
            else
            {
               printf("Enter the valid matched index\n");
               continue;
            }
        }
       if(deletechoice==3)
        {
            if(strcmp(str,addressBook->contacts[i].email)==0)
            {
            break;
            }
            else
            {
               printf("Enter the valid matched index\n");
               continue;
            }
        }
   }	
    printf("\n-----------------------------------------------------------------------------\n");
          printf("%-5s %-20s %-15s %-30s\n",
       "Sl.No", "Name", "Mobile Number", "Email");
         printf("-----------------------------------------------------------------------------\n");
        printf("%-5d %-20s %-15s %-30s\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
           index1=i;
}
int k=0;
  printf("Are you want to delete contact\n yes-->1\n No -->0");
  int option;
  scanf("%d",&option);
  if(option==0)
  {
    return;
  }
  for(int j=0; j<addressBook->contactCount; j++)
  {
     if(j!=index1)                      // deleting contacts
     {
     strcpy(addressBook->contacts[k].name,addressBook->contacts[j].name);
     strcpy(addressBook->contacts[k].phone,addressBook->contacts[j].phone);
     strcpy(addressBook->contacts[k].email,addressBook->contacts[j].email);
     k++;
     }
  }
  addressBook->contactCount--;
  printf("Contact deleted successfully.......\n");
  printf("-------------------------------------------------------------------------------------------\n");
}
