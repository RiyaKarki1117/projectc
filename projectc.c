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
void remove_newline(char *str) 
{
    str[strcspn(str, "\n")] = '\0';//string complement span counts how many character from str1 is not in str2
}

// Validate email
int isValidEmail(const char *email) 
{
    const char *at = strchr(email, '@');
    if (at == NULL || at == email) 
	{
	    return 0;		
	}
    const char *dot = strchr(at, '.');//strchr (string function that searches for the first occurence of character in string)
    if (dot == NULL || dot == at + 1 || dot[1] == '\0') 
	{
		return 0;
	}
    if (strchr(dot + 1, '.') != NULL) 
	{
		return 0;
	}
    return 1;
}

// Signup function
void signUp() 
{
    char email[50], password[50], line[100];
    int exists = 0;

    printf("------Sign Up------\n");

    FILE *fp = fopen(FILE_PATH, "a+"); // Open for reading + appending
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    while (1) 
	{
        printf("Enter New Email:\n");
        fgets(email, sizeof(email), stdin);
        remove_newline(email);
        if (!isValidEmail(email)) 
		{
            printf("Invalid email format. Try again.\n");
            continue;
        }

        // Check if email already exists
        rewind(fp); // Move the file pointer to the beginning of the already opened file
        while (fgets(line, sizeof(line), fp)) 
		{
            char stored_email[50];
            sscanf(line, "%[^,],%*s", stored_email); // sscanf is used for parsing formatted input from a string
            // %[^,],%*s" format string It tells sscanf what pattern to look for in line
            if (strcmp(email, stored_email) == 0) 
			{
                exists = 1;
                break;
            }
        }
        if (exists)
	    {
            printf("Email already registered. Try another.\n");
            fclose(fp);
            return;
        }
	    else
	    {
            break;
        }
    }

    while (1) //This loop runs until you explicitly break out of it (when a valid password is entered)
	{
        printf("Enter New Password (8-12 characters):\n");
        fgets(password, sizeof(password), stdin);//Reads the password input from user and stores it in the password array.
        remove_newline(password);

        size_t len = strlen(password);//Calculates the length of the password (excluding \0)
        if (len < 8 || len > 12) 
		{
            printf("Password must be between 8 and 12 characters. Try again.\n");
        } 
		else 
		{
		  break;//If the password length is valid, exits the while loop by calling break
		}
    }
    fprintf(fp, "%s,%s\n", email, password);//Writes the email and password pair to the file
    fclose(fp);
    printf("Sign Up successful!\n\n");
}

// Login function
int login() {
    char email[50], password[50], line[100];
    int found = 0;

    printf("------Log in------\n");

    FILE *fp = fopen(FILE_PATH, "r");
    if (!fp) 
	{
        printf("No account found. Please sign up first.\n");
        return 1;
    }

    printf("Enter Email:\n");
    fgets(email, sizeof(email), stdin);
    remove_newline(email);

    printf("Enter Password:\n");
    fgets(password, sizeof(password), stdin);
    remove_newline(password);

    while (fgets(line, sizeof(line), fp)) //loop reads the file line by line,stops when fgets reaches the end of the file
	{
        char stored_email[50], stored_password[50];//temporary character arrays declared to hold email password read from the current line of the file.
        sscanf(line, "%[^,],%s", stored_email, stored_password);// It reads the contents of the line buffer

        if (strcmp(email, stored_email) == 0 && strcmp(password, stored_password) == 0) //checks if the user-entered email matches the one read from the file.
		{
            found = 1;// If both strings match, the found flag is set to 1
            break;
        }
    }
    fclose(fp);
    if (found) 
	{
        printf("Login successful!\n");
        return 0;
    } 
	else 
	{
        printf("Invalid email or password.\n");
        return 1;
    }
}
//making a structure 
struct data 
{
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

int main() 
{
    initializeMovieFiles();//creates the necessary files (movie1.txt etc.) that will store the booked seat data for each movie.
    int choice;
    printf("1. Sign Up\n2. Log In\nChoose an option: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) 
	{
        case 1:
            signUp();
            if (login() != 0) 
			{
			   return 1;//After signing up, this line immediately calls the login() function. returns 0 on success and 1 on failure
               break;
            }
        case 2:
            if (login() != 0) //login function returns 0 when successful so login()!=0 means login wasnt successfull 
			{
			   return 1;
               break;
            }
        default:
            printf("Invalid option\n");
            return 1;
    }
    printf("\n** Movie Ticket Booking System **\n");
    displaymovie();
    int mchoice;
    printf("\nEnter the movie number you want to book: ");
    scanf("%d", &mchoice);
    getchar();//gets the newline character from input buffer
    booking(mchoice);
    return 0;
}

// Initialize seat files
void initializeMovieFiles() 
{
    for (i = 1; i <= 5; i++) 
	{
        char filename[20];
        sprintf(filename, "movie%d.txt", i);//formatted string output
        FILE *fp = fopen(filename, "a");
        if (fp) fclose(fp);
    }
}

// Movie list
void displaymovie() 
{
    printf("\nAvailable movies:\n");
    printf("1. Avengers        Time: 3:00 PM   Price: Rs 650/-\n");
    printf("2. The Conjuring   Time: 6:30 PM   Price: Rs 600/-\n");
    printf("3. Moana           Time: 11:00 AM  Price: Rs 500/-\n");
    printf("4. The Notebook    Time: 2:00 PM   Price: Rs 450/-\n");
    printf("5. Legally Blonde  Time: 4:30 PM   Price: Rs 350/-\n");
}

// Booking flow
void booking(int c) //one integer argument, c, which represents the user's movie choice
{
    loadMovieData(&ticket, c);//fill the structure ticket with the correct movie name, time, and price based on the c(movie choice) value
    printf("\nBooking for: %s\nTime: %s\nPrice: Rs %.2f\n", ticket.moviename, ticket.time, ticket.price);
    printf("\nAvailable seats (A1 to E6):\n");
    char seatCode[4];//character array to temporarily hold each seat code
    for (row = 'A'; row <= 'E'; row++) 
	{
        for (col = 1; col <= 6; col++) 
		{
            sprintf(seatCode, "%c%d", row, col);//combines the current row character (e.g., 'A') and the current col integer (e.g., 1) 
            if (isSeatBooked(c, seatCode))
                printf("[ X ] ");
            else
                printf("[%s] ", seatCode);
        }
        printf("\n");
    }

    char userSeat[4];//Declares a character array to store the seat code the user enters
    while (1) 
	{
        printf("\nChoose a seat code to book (e.g., A1, B4): ");
        scanf("%s", userSeat);
        //atoi function converts a string to an integer declared in the stdlib.h header file
        if (strlen(userSeat) < 2 || strlen(userSeat) > 3 || userSeat[0] < 'A' || userSeat[0] > 'E' || atoi(&userSeat[1]) < 1 || atoi(&userSeat[1]) > 6) 
			{
            printf("Invalid seat code.\n");
            continue;// sends the program back to the beginning of the while loop, prompting the user for input again
        }

        if (isSeatBooked(c, userSeat))
		{
            printf("Seat already booked. Please try another.\n");
        } 
		else 
		{
            bookSeat(c, userSeat);
            printf("Seat %s successfully booked!\n", userSeat);
            break;
        }
    }
}
// Load movie info
void loadMovieData(struct data *movie, int tchoice) 
{
    switch(tchoice) 
	{
        case 1: strcpy(movie->moviename, "Avengers"); strcpy(movie->time, "3:00 PM"); movie->price = 650; //copies "Avengers" into the moviename member of struct movie.
		break;
        case 2: strcpy(movie->moviename, "The Conjuring"); strcpy(movie->time, "6:30 PM"); movie->price = 600; 
		break;
        case 3: strcpy(movie->moviename, "Moana"); strcpy(movie->time, "11:00 AM"); movie->price = 500; 
		break;
        case 4: strcpy(movie->moviename, "The Notebook"); strcpy(movie->time, "2:00 PM"); movie->price = 450; 
		break;
        case 5: strcpy(movie->moviename, "Legally Blonde"); strcpy(movie->time, "4:30 PM"); movie->price = 350; 
		break;
        default: printf("Invalid movie choice.\n");
    }
}


// Check if seat is booked
int isSeatBooked(int movieChoice, const char *seatCode) //movieChoice (an integer like 1, 2, etc.) and seatCode (a string like "A1")
{
    char filename[20];//Declares a character array to store the name of the file (e.g., movie1.txt)
    sprintf(filename, "movie%d.txt", movieChoice);//takes the format string "movie%d.txt" and replaces the %d with the value of movieChoice.
    FILE *fp = fopen(filename, "r");//open the newly created filename in "read" mode
    if (!fp) 
	{
		return 0;
	}
    char booked[4];//hold each seat code read from the file
    while (fscanf(fp, "%s", booked) != EOF) //he loop continues as long as fscanf successfully reads a string.
	{
        if (strcmp(booked, seatCode) == 0) //compares the seat code just read from the file (booked) with the seat code we're looking for
		{
            fclose(fp);
            return 1;//returns 1 to indicate that the seat is booked.
        }
    }
    fclose(fp);
    return 0;//returns 0 to indicate that the seat is not booked
}

// Book a seat
void bookSeat(int movieChoice, const char *seatCode) //takes the movie choice and the seat code string
{
    char filename[20];
    sprintf(filename, "movie%d.txt", movieChoice);//creates the file name based on the movieChoice
    FILE *fp = fopen(filename, "a");//Append mode ensures that any new data written to the file will be added to the end of the file's current content
    if (!fp) 
	{
        printf("Error booking seat.\n");
        return;
    }

    fprintf(fp, "%s\n", seatCode);//writes the seatCode string 
    fclose(fp);
}


