/*first try*/
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *p;
     char email[50];
    char password[50];
    const char correct_email[] = "riyakarki49@gmail.com";
    const char correct_password[] = "applejuice";

	p=fopen("D:\\Riya\\pro.txt","w");
	printf("------Log in------");
	  printf("Enter Email:\n");
    fgets(email, sizeof(email), stdin);
    //email[strcspn(email, "\n")] = '\0';  
    if (strcmp(email, correct_email) != 0) {
        printf("Incorrect email\n");
        return 1;
    }
     printf("Enter Password:\n");
    fgets(password, sizeof(password), stdin);
    //password[strcspn(password, "\n")] = '\0';  // remove newline

    if (strcmp(password, correct_password) != 0) {
        printf("Password incorrect\n");
        return 1;
    }

    printf("Login successful!\n");
    printf("Don't have an account?\n");

    return 0;
}*/
/*worked but didn't use file handling*/
//	while(strcmp(e,email)==0)
//	{
//	   goto next;
//	}
  //  printf("Incorrect email\n");
    //next:
	//printf("\n Enter Password:\n");
//	gets(password);
//		while(strcmp(pass,password)==0)
//	{
//		goto next1;
//	}
//	printf("Password incorrect\n");
//	next1:
//	printf("Don't have an account?");
//	return 0;
//wtf
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "D:\\Riya\\pro.txt"

void remove_newline(char *str)
{
    //str[strcspn(str, "\n")] = '\0';

void remove_newline(char *str) 
{
    str[strcspn(str, "\n")] = '\0'; //CHECKOUT
}

void signUp() 
{
    char email[50];
    char password[50];
    printf("------Sign Up------\n");
    printf("Enter New Email:\n");
    //fgets(email, sizeof(email), stdin);
    remove_newline(email);
    printf("Enter New Password:\n");
    //fgets(password, sizeof(password), stdin);
    remove_newline(password);
    fgets(email, sizeof(email), stdin); //CHECKOUT
    remove_newline(email); //CHECKOUT

    printf("Enter New Password:\n");
    fgets(password, sizeof(password), stdin); //CHECKOUT
    remove_newline(password); //CHECKOUT

    FILE *fp = fopen(FILE_PATH, "w");
    if (fp == NULL) 
	{
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(fp, "%s\n%s\n", email, password);
    fclose(fp);
    printf("Sign Up successful!\n\n");
}

int login() 
{
    char email[50];
    char password[50];
    char stored_email[50];
    char stored_password[50];

    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL) 
	{
        printf("No account found. Please sign up first.\n");
        return 1;
    }

    fgets(stored_email, sizeof(stored_email), fp);
    remove_newline(stored_email);

    fgets(stored_password, sizeof(stored_password), fp);
    remove_newline(stored_password);

    remove_newline(stored_email); //CHECKOUT

    fgets(stored_password, sizeof(stored_password), fp);
    remove_newline(stored_password);  //CHECKOUT

    fclose(fp);

    printf("------Log in------\n");

    printf("Enter Email:\n");
    //fgets(email, sizeof(email), stdin);
    remove_newline(email);//ensures the string becomes clean like "abc@example.com" (without \n).
    fgets(email, sizeof(email), stdin); //CHECKOUT
    remove_newline(email);  //CHECKOUT

    if (strcmp(email, stored_email) != 0) 
	{
        printf("Incorrect email\n");
        return 1;
    }

    printf("Enter Password:\n");
    //fgets(password, sizeof(password), stdin);
    remove_newline(password);
    fgets(password, sizeof(password), stdin); //CHECKOUT
    remove_newline(password); //CHECKOUT

    if (strcmp(password, stored_password) != 0)
    {
        printf("Password incorrect\n");
        return 1;
    }

    printf("Login successful!\n");
    return 0;
}

int main()
{
    int choice;
    printf("1. Sign Up\n");
    printf("2. Log In\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    getchar();  // To consume the newline character left by scanf
    switch (choice)
	{
    getchar();  // To consume the newline character left by scanf //CHECKOUT

    switch (choice) 
	{
        case 1:
            signUp();
            login(); // Optional: ask to log in right after sign up
            break;
        case 2:
            login();
            break;
        default:
            printf("Invalid option\n");
            break;
    }
    return 0;
}
*/
//secondddd
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "D:\\Riya\\pro.txt"

// Remove the newline character at the end of a string
void remove_newline(char *str) 
{
    str[strcspn(str, "\n")] = '\0';
}

void signUp() 
{
    char email[50];
    char password[50];

    printf("------Sign Up------\n");

    printf("Enter New Email:\n");
    fgets(email, sizeof(email), stdin);
    remove_newline(email);

    printf("Enter New Password:\n");
    fgets(password, sizeof(password), stdin);
    remove_newline(password);

    FILE *fp = fopen(FILE_PATH, "w");
    if (fp == NULL) 
	{
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(fp, "%s\n%s\n", email, password);
    fclose(fp);
    printf("Sign Up successful!\n\n");
}

int login() 
{
    char email[50];
    char password[50];
    char stored_email[50];
    char stored_password[50];

    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL) 
	{
        printf("No account found. Please sign up first.\n");
        return 1;
    }

    fgets(stored_email, sizeof(stored_email), fp);
    remove_newline(stored_email);

    fgets(stored_password, sizeof(stored_password), fp);
    remove_newline(stored_password);

    fclose(fp);

    printf("------Log in------\n");

    printf("Enter Email:\n");
    fgets(email, sizeof(email), stdin);
    remove_newline(email);

    if (strcmp(email, stored_email) != 0) 
	{
        printf("Incorrect email\n");
        return 1;
    }

    printf("Enter Password:\n");
    fgets(password, sizeof(password), stdin);
    remove_newline(password);

    if (strcmp(password, stored_password) != 0)
    {
        printf("Password incorrect\n");
        return 1;
    }

    printf("Login successful!\n");
    return 0;
}

int main()
{
    int choice;

    printf("1. Sign Up\n");
    printf("2. Log In\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    getchar();  // Consume the newline left by scanf

    switch (choice) 
	{
        case 1:
            signUp();
            login(); // Optional: Prompt to log in after sign-up
            break;
        case 2:
            login();
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define FILE_PATH "D:\\Riya\\pro.txt"
#define ROWS 5
#define COLS 6
int i=0,j=0,c=0,r=0;
char seats[ROWS][COLS];

struct data {
    char moviename[50];
    char time[10];
    float price;
} ticket;

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int isValidEmail(const char *email) {
    const char *at = strchr(email, '@');
    const char *dot = strchr(at ? at : "", '.');
    return (at && at != email && dot && dot > at + 1 && dot[1] != '\0');
}

void signUp() {
    char email[50], password[50];
    printf("------Sign Up------\n");

    while (1) {
        printf("Enter New Email:\n");
        fgets(email, sizeof(email), stdin);
        remove_newline(email);
        if (!isValidEmail(email))
            printf("Invalid email format. Try again.\n");
        else break;
    }

    while (1) {
        printf("Enter New Password (8-12 characters):\n");
        fgets(password, sizeof(password), stdin);
        remove_newline(password);
        if (strlen(password) < 8 || strlen(password) > 12)
            printf("Password must be between 8 and 12 characters.\n");
        else break;
    }

    FILE *fp = fopen(FILE_PATH, "w");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(fp, "%s\n%s\n", email, password);
    fclose(fp);
    printf("Sign Up successful!\n\n");
}

int login() {
    char email[50], password[50], stored_email[50], stored_password[50];

    FILE *fp = fopen(FILE_PATH, "r");
    if (!fp) {
        printf("No account found. Please sign up first.\n");
        return 1;
    }

    fgets(stored_email, sizeof(stored_email), fp);
    remove_newline(stored_email);
    fgets(stored_password, sizeof(stored_password), fp);
    remove_newline(stored_password);
    fclose(fp);

    printf("------Log in------\nEnter Email:\n");
    fgets(email, sizeof(email), stdin);
    remove_newline(email);

    printf("Enter Password:\n");
    fgets(password, sizeof(password), stdin);
    remove_newline(password);

    if (strcmp(email, stored_email) != 0 || strcmp(password, stored_password) != 0) {
        printf("Incorrect email or password\n");
        return 1;
    }

    printf("Login successful!\n");
    return 0;
}

void displayMovies() {
    printf("\nAvailable Movies:\n");
    printf("1. Avengers        3:00 PM   Rs 650\n");
    printf("2. The Conjuring   6:30 PM   Rs 600\n");
    printf("3. Moana           11:00 AM  Rs 500\n");
    printf("4. The Notebook    2:00 PM   Rs 450\n");
    printf("5. Legally Blonde  4:30 PM   Rs 350\n");
}

void loadMovieData(struct data *movie, int tchoice) {
    switch (tchoice) {
        case 1: strcpy(movie->moviename, "Avengers"); strcpy(movie->time, "3:00 PM"); movie->price = 650; break;
        case 2: strcpy(movie->moviename, "The Conjuring"); strcpy(movie->time, "6:30 PM"); movie->price = 600; break;
        case 3: strcpy(movie->moviename, "Moana"); strcpy(movie->time, "11:00 AM"); movie->price = 500; break;
        case 4: strcpy(movie->moviename, "The Notebook"); strcpy(movie->time, "2:00 PM"); movie->price = 450; break;
        case 5: strcpy(movie->moviename, "Legally Blonde"); strcpy(movie->time, "4:30 PM"); movie->price = 350; break;
        default: printf("Invalid choice.\n"); return;
    }
}

void initializeSeats() {
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            seats[i][j] = '_';
}

void displaySeats() {
    printf("\n    ");
    for (c = 1; c <= COLS; c++) printf("%d   ", c);
    printf("\n");

    for (r = 0; r < ROWS; r++) {
        printf("%c ", 'A' + r);
        for (c = 0; c < COLS; c++) {
            printf("[%c] ", seats[r][c]);
        }
        printf("\n");
    }
}

void bookSeat(char *seatID) {
    if (strlen(seatID) < 2 || strlen(seatID) > 3) {
        printf("Invalid seat format. Use A1 to E6.\n");
        return;
    }
    int row = toupper(seatID[0]) - 'A';
    int col = atoi(&seatID[1]) - 1;
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Seat %s does not exist.\n", seatID);
        return;
    }

    if (seats[row][col] == 'X')
        printf("Seat %s already reserved.\n", seatID);
    else {
        seats[row][col] = 'X';
        printf("Seat %s successfully booked.\n", seatID);
    }
}

int main() {
    int choice, ch;
    char input[10];

    printf("1. Sign Up\n2. Log In\nChoose: ");
    scanf("%d", &choice); getchar();

    switch (choice) {
        case 1: signUp(); if (login() != 0) return 1; break;
        case 2: if (login() != 0) return 1; break;
        default: printf("Invalid choice.\n"); return 1;
    }

    printf("\n** Movie Ticket Booking System **\n1. View Movies\n2. Book Seats\nEnter choice: ");
    scanf("%d", &ch); getchar();

    switch (ch) {
        case 1:
            displayMovies();
            printf("Enter movie number: ");
            scanf("%d", &choice); getchar();
            loadMovieData(&ticket, choice);
            printf("Booking: %s at %s for Rs %.2f\n", ticket.moviename, ticket.time, ticket.price);
            break;

        case 2:
            initializeSeats();
            while (1) {
                displaySeats();
                printf("Enter seat (A1-E6) or 'exit': ");
                scanf("%s", input);
                if (strcmp(input, "exit") == 0) break;
                bookSeat(input);
            }
            break;

        default:
            printf("Invalid option.\n");
    }

    printf("Thank you for using the system!\n");
    return 0;
}

