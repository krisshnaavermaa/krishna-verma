#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
int id;
char title[50];
char author[50];
int available;
};

struct Book library[MAX_BOOKS];
int count = 0;

void addBook() {
if(count >= MAX_BOOKS) {
printf("Library full.\n");
return;
}
printf("Enter Book ID: ");
scanf("%d", &library[count].id);
printf("Enter Title: ");
getchar();
fgets(library[count].title, 50, stdin);
library[count].title[strcspn(library[count].title, "\n")] = 0;
printf("Enter Author: ");
fgets(library[count].author, 50, stdin);
library[count].author[strcspn(library[count].author, "\n")] = 0;
library[count].available = 1;
count++;
printf("Book added successfully.\n");
}

void displayBooks() {
if(count == 0) {
printf("No books in library.\n");

return;
}
printf("\nID\tTitle\tAuthor\tAvailability\n");
for(int i=0; i<count; i++) {
printf("%d\t%s\t%s\t%s\n", library[i].id, library[i].title, library[i].author,
library[i].available ? "Available" : "Issued");
}
}

void issueBook() {
if(count == 0) {
printf("No books to issue.\n");
return;
}
int id;
printf("Enter Book ID to issue: ");
scanf("%d", &id);
for(int i=0; i<count; i++) {
if(library[i].id == id) {
if(library[i].available) {
library[i].available = 0;
printf("Book issued successfully.\n");
return;
} else {
printf("Book already issued.\n");

return;
}
}
}
printf("Book not found.\n");
}

void returnBook() {
if(count == 0) {
printf("No books in library.\n");
return;
}
int id;
printf("Enter Book ID to return: ");
scanf("%d", &id);
for(int i=0; i<count; i++) {
if(library[i].id == id) {
if(!library[i].available) {
library[i].available = 1;
printf("Book returned successfully.\n");
return;
} else {
printf("This book was not issued.\n");
return;
}

}
}
printf("Book not found.\n");
}
int main() {
int choice;
while(1) {
printf("\nLibrary Management System\n");
printf("1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\n");
printf("Enter Choice: ");
scanf("%d", &choice);
switch(choice) {
case 1: addBook(); break;
case 2: displayBooks(); break;
case 3: issueBook(); break;
case 4: returnBook(); break;
case 5: exit(0);
default: printf("Invalid choice.\n");
}
}
return 0;
}