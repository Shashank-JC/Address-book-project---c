#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  FILE* fp = fopen("text.csv","w");
  for(int i=0; i<addressBook->contactCount; i++)
  {                                                    // saving the contacts to file
    fprintf(fp,"%s,",addressBook->contacts[i].name);
    fprintf(fp,"%s,",addressBook->contacts[i].phone);
    fprintf(fp,"%s\n",addressBook->contacts[i].email);
  }
  fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE* fp = fopen("text.csv","r");
     if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }                                  // loading the contacts from the file
    int i = 0;

    while (fscanf(fp, "%[^,],%[^,],%[^\n]\n",
                  addressBook->contacts[i].name,
                  addressBook->contacts[i].phone,
                  addressBook->contacts[i].email) == 3)
    {
        i++;
    }
    addressBook->contactCount = i;

    fclose(fp);   
}
