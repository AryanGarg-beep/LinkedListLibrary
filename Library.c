#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
  char name[50];
  char phone[15];
  struct Account *next;
} Account;

typedef struct Book {
  char bookName[100];
  char SKU[20];
  struct Book *next;
} Book;

int isNumeric(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit((unsigned char)str[i])) {
      return 0;
    }
  }
  return 1;
}

Account *createAccount(char name[], char phone[]) {
  Account *newAcc = (Account *)malloc(sizeof(Account));
  if (newAcc != NULL) {
    strcpy(newAcc->name, name);
    strcpy(newAcc->phone, phone);
    newAcc->next = NULL;
  }
  return newAcc;
}

void addAccount(Account **head, Account *newAcc) {
  if (*head == NULL) {
    *head = newAcc;
  } else {
    Account *temp = *head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = newAcc;
  }
}

void printAccounts(Account *head) {
  printf("\nAccounts:\n");
  while (head != NULL) {
    printf("Name: %s, Phone: %s\n", head->name, head->phone);
    head = head->next;
  }
}

Book *createBook(char bookName[], char SKU[]) {
  Book *newBook = (Book *)malloc(sizeof(Book));
  if (newBook != NULL) {
    strcpy(newBook->bookName, bookName);
    strcpy(newBook->SKU, SKU);
    newBook->next = NULL;
  }
  return newBook;
}

void issueBook(Book **head, Book *newBook) {
  if (*head == NULL) {
    *head = newBook;
  } else {
    Book *temp = *head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = newBook;
  }
}

void printBooks(Book *head) {
  printf("\nBooks:\n");
  while (head != NULL) {
    printf("Book: %s, SKU: %s\n", head->bookName, head->SKU);
    head = head->next;
  }
}

int main() {
  Account *accounts = NULL;
  Book *books = NULL;
  int choice;
  char name[50], phone[15], bookName[100], SKU[20];

  while (1) {
    printf("\nLibrary System Menu:\n");
    printf("1. Add Account\n");
    printf("2. Print Accounts\n");
    printf("3. Issue Book\n");
    printf("4. Print Books\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
    case 1:
      printf("Enter account name: ");
      scanf("%[^\n]", name);
      getchar();
      printf("Enter account phone: ");
      scanf("%s", phone);
      getchar();
      if (!isNumeric(phone)) {
        printf("Invalid input\n");
        break;
      }
      addAccount(&accounts, createAccount(name, phone));
      break;
    case 2:
      printAccounts(accounts);
      break;
    case 3:
      printf("Enter book name: ");
      scanf("%[^\n]", bookName);
      getchar();
      printf("Enter book SKU: ");
      scanf("%s", SKU);
      getchar();
      if (!isNumeric(SKU)) {
        printf("Invalid input\n");
        break;
      }
      issueBook(&books, createBook(bookName, SKU));
      break;
    case 4:
      printBooks(books);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
