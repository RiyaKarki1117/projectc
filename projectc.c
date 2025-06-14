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
#define MAX_SEATS 10

// Remove the newline character at the end of a string
void remove_newline(char *str) 
{
    str[strcspn(str, "\n")] = '\0';
}

// Check if email format is valid
int isValidEmail(const char *email) 
{
    const char *at = strchr(email, '@');
    if (at == NULL || at == email) 
        return 0;  // No '@' or '@' at the start

    const char *dot = strchr(at, '.');
    if (dot == NULL || dot == at + 1 || dot[1] == '\0') 
        return 0;  // No '.' after '@', or directly after '@', or at end

    if (strchr(dot + 1, '.') != NULL) 
        return 0;  // Optional: Disallow multiple '.' after '@'

    return 1;
}

void signUp() 
{
     char email[50];
    char password[50];

    printf("------Sign Up------\n");

    // Email validation
    while (1) 
	{
        printf("Enter New Email:\n");
        fgets(email, sizeof(email), stdin);
        remove_newline(email);

        if (!isValidEmail(email)) 
		{
            printf("Invalid email format. Please try again.\n");
        } 
		else
	    {
            break;
        }
    }

    // Password validation (min 8, max 12 characters)
    while (1)
    {   
        printf("Enter New Password (8-12 characters):\n");
        fgets(password, sizeof(password), stdin);
        remove_newline(password);

        size_t len = strlen(password);
        if (len < 8 || len > 12)
	    {
            printf("Password must be between 8 and 12 characters. Try again.\n");
        } else
	    {
            break;
        }
    }

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
struct data
  {
	  char moviename[50];
	  char time[10];
	  float price;
  }ticket;
//Function Declaration
void displaymovie();
void book(int choice);
void loadMovieData(struct data *movie, int tchoice);
void initializeMovieFiles() ;
int isSeatBooked(int movieChoice, int seatNumber);
void bookSeat(int movieChoice, int seatNumber);
void booking(int movieChoice);
int main()
{
	initializeMovieFiles();
    int choice;
    int seatNumber;
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
    printf("\n** Movie Ticket Booking System **\n");
        displaymovie();
        int mchoice;
        printf("\nEnter the movie number you want to book: ");
        scanf("%d", &mchoice);
//        book(mchoice);
//        displaySeats(mchoice);
//        printf("\nEnter the seat number you want to book: ");
//        scanf("%d",&seatNumber);
//        bookSeat(mchoice,seatNumber);
      booking(mchoice);  // Call the proper booking function

   //fclose(fp);
    return 0;
}
//function definitions
      void displaymovie()
    {
    	printf("\nAvailable movies with its timing and price are displayed below:\n");
        printf("1. Avengers        Time: 3:00 PM   Price: Rs 650/-\n");
        printf("2. The Conjuring   Time: 6:30 PM   Price: Rs 600/-\n");
        printf("3. Moana           Time: 11:00 AM  Price: Rs 500/-\n");
        printf("4. The Notebook    Time: 2:00 PM   Price: Rs 450/-\n");
        printf("5. Legally Blonde  Time: 4:30 PM   Price: Rs 350/-\n");
	}
	//choosing the movie
	void book(int c)
	{
		loadMovieData(&ticket, c);
	    printf("\n");	
	    printf("\nBooking for: %s\n", ticket.moviename);
        printf("Time: %s\n", ticket.time);
        printf("Price: Rs %.2f\n", ticket.price);
	}
		void loadMovieData(struct data *movie, int tchoice)
    {
    // Initialize based on movie choice
    switch(tchoice) 
   	{
        case 1:
            strcpy(movie->moviename, "Avengers");// '->' is a structure pointer operator for eg *movie.moviename means the same as written
            strcpy(movie->time, "3:00 PM");
            movie->price = 650;
            break;
        case 2:
            strcpy(movie->moviename, "The Conjuring");
            strcpy(movie->time, "6:30 PM");
            movie->price = 600;
            break;
        case 3:
            strcpy(movie->moviename, "Moana");
            strcpy(movie->time, "11:00 AM");
            movie->price = 500;
            break;
        case 4:
            strcpy(movie->moviename, "The Notebook");
            strcpy(movie->time, "2:00 PM");
            movie->price = 450;
            break;
        case 5:
            strcpy(movie->moviename, "Legally Blonde");
            strcpy(movie->time, "4:30 PM");
            movie->price = 350;
            break;
        default:
            printf("Invalid movie choice.\n");
    }
   }


// Create seat booking files for each movie
void initializeMovieFiles() 
{
	int i=0;
    for (i = 1; i <= 5; i++) 
	{
		FILE *fp;
        char filename[20];
        sprintf(filename, "movie%d.txt", i);
        fp=fopen(filename, "a");  // Create if not exists
        if (fp) fclose(fp);
    }
}

// Check if a seat is already booked
int isSeatBooked(int movieChoice, int seatNumber) 
{
    char filename[20];
    sprintf(filename, "movie%d.txt", movieChoice);
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;

    int booked;
    while (fscanf(fp, "%d", &booked) != EOF) 
	{
        if (booked == seatNumber) 
		{
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

// Save a booked seat to file
void bookSeat(int movieChoice, int seatNumber) 
{
    char filename[20];
    sprintf(filename, "movie%d.txt", movieChoice);
    FILE *fp = fopen(filename, "a");
    if (!fp)
	{
        printf("Error booking seat.\n");
        return;
    }

    fprintf(fp, "%d\n", seatNumber);
    fclose(fp);
}

// Modified book() function
void booking(int c) 
{
	int i=0;
    loadMovieData(&ticket, c);
    printf("\nBooking for: %s\nTime: %s\nPrice: Rs %.2f\n", ticket.moviename, ticket.time, ticket.price);

    printf("\nAvailable seats (1 to %d):\n", MAX_SEATS);
    for ( i = 1; i <= MAX_SEATS; i++) 
	{
        if (isSeatBooked(c, i))
            printf("[X] ");
        else
            printf("[%d] ", i);
    }

    int seat;
    again:
    printf("\nChoose a seat number to book: ");
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS)
    {
        printf("Invalid seat number.\n");
        return;
    }

    if (isSeatBooked(c, seat)) 
	{
        printf("Seat already booked. Please try another.\n");
        goto again;
    } 
	else 
	{
        bookSeat(c, seat);
        printf("Seat %d successfully booked!\n", seat);
    }
}

