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
 int i=0,j=0;
 char row,col;
// Remove newline character
void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Validate email
int isValidEmail(const char *email) {
    const char *at = strchr(email, '@');
    if (at == NULL || at == email) return 0;
    const char *dot = strchr(at, '.');
    if (dot == NULL || dot == at + 1 || dot[1] == '\0') return 0;
    if (strchr(dot + 1, '.') != NULL) return 0;
    return 1;
}

// Signup function
void signUp() {
    char email[50], password[50], line[100];
    int exists = 0;

    printf("------Sign Up------\n");

    FILE *fp = fopen(FILE_PATH, "a+"); // Open for reading + appending
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    while (1) {
        printf("Enter New Email:\n");
        fgets(email, sizeof(email), stdin);
        remove_newline(email);

        if (!isValidEmail(email)) {
            printf("Invalid email format. Try again.\n");
            continue;
        }

        // Check if email already exists
        rewind(fp); // Move to beginning
        while (fgets(line, sizeof(line), fp)) {
            char stored_email[50];
            sscanf(line, "%[^,],%*s", stored_email); // extract email
            if (strcmp(email, stored_email) == 0) {
                exists = 1;
                break;
            }
        }

        if (exists) {
            printf("Email already registered. Try another.\n");
            fclose(fp);
            return;
        } else {
            break;
        }
    }

    while (1) {
        printf("Enter New Password (8-12 characters):\n");
        fgets(password, sizeof(password), stdin);
        remove_newline(password);

        size_t len = strlen(password);
        if (len < 8 || len > 12) {
            printf("Password must be between 8 and 12 characters. Try again.\n");
        } else break;
    }

    fprintf(fp, "%s,%s\n", email, password);
    fclose(fp);
    printf("Sign Up successful!\n\n");
}

// Login function
int login() {
    char email[50], password[50], line[100];
    int found = 0;

    printf("------Log in------\n");

    FILE *fp = fopen(FILE_PATH, "r");
    if (!fp) {
        printf("No account found. Please sign up first.\n");
        return 1;
    }

    printf("Enter Email:\n");
    fgets(email, sizeof(email), stdin);
    remove_newline(email);

    printf("Enter Password:\n");
    fgets(password, sizeof(password), stdin);
    remove_newline(password);

    while (fgets(line, sizeof(line), fp)) {
        char stored_email[50], stored_password[50];
        sscanf(line, "%[^,],%s", stored_email, stored_password);

        if (strcmp(email, stored_email) == 0 && strcmp(password, stored_password) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("Login successful!\n");
        return 0;
    } else {
        printf("Invalid email or password.\n");
        return 1;
    }
}

struct data {
    char moviename[50];
    char time[10];
    float price;
   
} ticket;

// Function declarations
void displaymovie();
void loadMovieData(struct data *movie, int tchoice);
void initializeMovieFiles();
int isSeatBooked(int movieChoice, const char *seatCode);
void bookSeat(int movieChoice, const char *seatCode);
void booking(int movieChoice);

int main() {
    initializeMovieFiles();
    int choice;
    printf("1. Sign Up\n2. Log In\nChoose an option: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            signUp();
            if (login() != 0) return 1;
            break;
        case 2:
            if (login() != 0) return 1;
            break;
        default:
            printf("Invalid option\n");
            return 1;
    }

    printf("\n** Movie Ticket Booking System **\n");
    displaymovie();
    int mchoice;
    printf("\nEnter the movie number you want to book: ");
    scanf("%d", &mchoice);
    getchar();
    booking(mchoice);

    return 0;
}

// Movie list
void displaymovie() {
    printf("\nAvailable movies:\n");
    printf("1. Avengers        Time: 3:00 PM   Price: Rs 650/-\n");
    printf("2. The Conjuring   Time: 6:30 PM   Price: Rs 600/-\n");
    printf("3. Moana           Time: 11:00 AM  Price: Rs 500/-\n");
    printf("4. The Notebook    Time: 2:00 PM   Price: Rs 450/-\n");
    printf("5. Legally Blonde  Time: 4:30 PM   Price: Rs 350/-\n");
}

// Load movie info
void loadMovieData(struct data *movie, int tchoice) {
    switch(tchoice) {
        case 1: strcpy(movie->moviename, "Avengers"); strcpy(movie->time, "3:00 PM"); movie->price = 650; break;
        case 2: strcpy(movie->moviename, "The Conjuring"); strcpy(movie->time, "6:30 PM"); movie->price = 600; break;
        case 3: strcpy(movie->moviename, "Moana"); strcpy(movie->time, "11:00 AM"); movie->price = 500; break;
        case 4: strcpy(movie->moviename, "The Notebook"); strcpy(movie->time, "2:00 PM"); movie->price = 450; break;
        case 5: strcpy(movie->moviename, "Legally Blonde"); strcpy(movie->time, "4:30 PM"); movie->price = 350; break;
        default: printf("Invalid movie choice.\n");
    }
}

// Init seat files
void initializeMovieFiles() {
    for (i = 1; i <= 5; i++) {
        char filename[20];
        sprintf(filename, "movie%d.txt", i);
        FILE *fp = fopen(filename, "a");
        if (fp) fclose(fp);
    }
}

// Check if seat is booked
int isSeatBooked(int movieChoice, const char *seatCode) {
    char filename[20];
    sprintf(filename, "movie%d.txt", movieChoice);
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;

    char booked[4];
    while (fscanf(fp, "%s", booked) != EOF) {
        if (strcmp(booked, seatCode) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

// Book a seat
void bookSeat(int movieChoice, const char *seatCode) {
    char filename[20];
    sprintf(filename, "movie%d.txt", movieChoice);
    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("Error booking seat.\n");
        return;
    }

    fprintf(fp, "%s\n", seatCode);
    fclose(fp);
}

// Booking flow
void booking(int c) {
    loadMovieData(&ticket, c);
    printf("\nBooking for: %s\nTime: %s\nPrice: Rs %.2f\n", ticket.moviename, ticket.time, ticket.price);

    printf("\nAvailable seats (A1 to E6):\n");
    char seatCode[4];
    for (row = 'A'; row <= 'E'; row++) {
        for (col = 1; col <= 6; col++) {
            sprintf(seatCode, "%c%d", row, col);
            if (isSeatBooked(c, seatCode))
                printf("[ X ] ");
            else
                printf("[%s] ", seatCode);
        }
        printf("\n");
    }

    char userSeat[4];
    while (1) {
        printf("\nChoose a seat code to book (e.g., A1, B4): ");
        scanf("%s", userSeat);

        if (strlen(userSeat) < 2 || strlen(userSeat) > 3 ||
            userSeat[0] < 'A' || userSeat[0] > 'E' ||
            atoi(&userSeat[1]) < 1 || atoi(&userSeat[1]) > 6) {
            printf("Invalid seat code.\n");
            continue;
        }

        if (isSeatBooked(c, userSeat)) {
            printf("Seat already booked. Please try another.\n");
        } else {
            bookSeat(c, userSeat);
            printf("Seat %s successfully booked!\n", userSeat);
            break;
        }
    }
}
