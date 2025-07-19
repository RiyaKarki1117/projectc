#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "D:\\Riya\\pro.txt"
#define ROWS 5
#define COLS 6
 int i=0,j=0;
 char row,col;
// Removing newline character
void remove_newline(char *str) 
{
    str[strcspn(str, "\n")] = '\0';
}

// Email validation
int isValidEmail(const char *email) 
{
    const char *at = strchr(email, '@');
    if (at == NULL || at == email) 
	{
	    return 0;		
	}
    const char *dot = strchr(at, '.');
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

    FILE *fp = fopen(FILE_PATH, "a+"); 
    if (!fp) 
	{
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
        rewind(fp); 
        while (fgets(line, sizeof(line), fp)) 
		{
            char stored_email[50];
            sscanf(line, "%[^,],%*s", stored_email); 
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

    while (1) 
	{
        printf("Enter New Password (8-12 characters):\n");
        fgets(password, sizeof(password), stdin);
        remove_newline(password);
        size_t len = strlen(password);
        if (len < 8 || len > 12) 
		{
            printf("Password must be between 8 and 12 characters. Try again.\n");
        } 
		else 
		{
		  break;
		}
    }
    fprintf(fp, "%s,%s\n", email, password);
    fclose(fp);
    printf("Sign Up successful!\n\n");
}

// Login function
int login() 
{
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

    while (fgets(line, sizeof(line), fp)) 
	{
        char stored_email[50], stored_password[50];
        sscanf(line, "%[^,],%s", stored_email, stored_password);

        if (strcmp(email, stored_email) == 0 && strcmp(password, stored_password) == 0) 
		{
            found = 1;
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

// making a structure variable
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
    initializeMovieFiles();
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
			   return 1;
            }
            break;
        case 2:
            if (login() != 0) 
			{
			   return 1;
            }
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

// Initialize seat files
void initializeMovieFiles() 
{
    for (i = 1; i <= 5; i++) 
	{
        char filename[20];
        sprintf(filename, "movie%d.txt", i);
        FILE *fp = fopen(filename, "a");
        if (fp) fclose(fp);
    }
    return 0;
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

// Booking ticket
void booking(int c) 
{
    loadMovieData(&ticket, c);
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
//Booking seat
    char userSeat[4];
    while (1) 
	{
        printf("\nChoose a seat code to book (e.g., A1, B4): ");
        scanf("%s", userSeat);
        if (strlen(userSeat) < 2 || strlen(userSeat) > 3 || userSeat[0] < 'A' || userSeat[0] > 'E' || atoi(&userSeat[1]) < 1 || atoi(&userSeat[1]) > 6) 
			{
            printf("Invalid seat code.\n");
            continue;
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
        case 1: strcpy(movie->moviename, "Avengers"); strcpy(movie->time, "3:00 PM"); movie->price = 650; 
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
int isSeatBooked(int movieChoice, const char *seatCode) 
{
    char filename[20];
    sprintf(filename, "movie%d.txt", movieChoice);
    FILE *fp = fopen(filename, "r");
    if (!fp) 
	{
		return 0;
	}
    char booked[4];
    while (fscanf(fp, "%s", booked) != EOF) 
	{
        if (strcmp(booked, seatCode) == 0) 
		{
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// writing booked seat into file
void bookSeat(int movieChoice, const char *seatCode) 
{
    char filename[20];
    sprintf(filename, "movie%d.txt", movieChoice);
    FILE *fp = fopen(filename, "a");
    if (!fp) 
	{
		printf("Error booking seat.\n");
        return;
    }
    fprintf(fp, "%s\n", seatCode);
    fclose(fp);
}

