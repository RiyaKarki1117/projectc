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
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define FILE_PATH "D:\\Riya\\pro.txt"
#define MAX_MOVIES 50
#define MAX_CINEMA_HALLS 10
#define MAX_SHOWTIMES_PER_HALL 20 // Max showtimes per hall
#define MAX_TOTAL_SHOWTIMES MAX_CINEMA_HALLS * MAX_SHOWTIMES_PER_HALL
#define MAX_STRING_LENGTH 100 // For movie titles, names, etc.
#define MAX_SEAT_ROWS 10
#define MAX_SEAT_COLS 20
// Filenames for data persistence
#define FILENAME_MOVIES "movies.txt"
#define FILENAME_HALLS "cinema_halls.txt"
#define FILENAME_SHOWTIMES "showtimes.txt"
#define FILENAME_SEATS "seats.txt" // To store seat availability
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
    while (1) {
        printf("Enter New Email:\n");
        fgets(email, sizeof(email), stdin);
        remove_newline(email);

        if (!isValidEmail(email)) {
            printf("Invalid email format. Please try again.\n");
        } else {
            break;
        }
    }

    // Password validation (min 8, max 12 characters)
    while (1) {
        printf("Enter New Password (8-12 characters):\n");
        fgets(password, sizeof(password), stdin);
        remove_newline(password);

        size_t len = strlen(password);
        if (len < 8 || len > 12) {
            printf("Password must be between 8 and 12 characters. Try again.\n");
        } else {
            break;
        }
    }

    FILE *fp = fopen(FILE_PATH, "w");
    if (fp == NULL) 
    {
        printf("Error opening file for writing.\n");
        return;
    }

<<<<<<< HEAD
    fprintf(fp, "%s\n%s\n", email, password);
=======
    fprintf(fp, "%s\n%s\n", email, password));
>>>>>>> f026bdfe1b6cbef87c5697e31d7637c5dbcabeea
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
<<<<<<< HEAD
// Define seat types (could be read from config, but fixed for simplicity)
typedef enum {
    SEAT_TYPE_STANDARD,
    SEAT_TYPE_PREMIUM,
    SEAT_TYPE_COUNT // Utility to know how many types there are
} SeatType;

// --- Structures ---

typedef struct {
    int id;
    char title[MAX_STRING_LENGTH];
    char genre[MAX_STRING_LENGTH];
    int duration_minutes;
    char rating[10]; // e.g., PG-13, R
} Movie;

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    int rows;
    int cols;
    // Prices for different seat types within this hall (e.g., price[0] for Standard, price[1] for Premium)
    double prices[SEAT_TYPE_COUNT];
    // Map seat rows to types (e.g., row 0-5 Standard, 6-9 Premium)
    // This simplifies seat type definition per hall.
    int premium_start_row; // Rows from 0 to premium_start_row-1 are Standard
                           // Rows from premium_start_row to rows-1 are Premium
} CinemaHall;

typedef struct {
    int id;
    int movie_id;       // Links to a Movie
    int hall_id;        // Links to a CinemaHall
    char date[20];      // e.g., "2025-07-15"
    char time[10];      // e.g., "18:00"
    char seats[MAX_SEAT_ROWS][MAX_SEAT_COLS]; // '0' for available, '1' for booked
} Showtime;

// --- Global Arrays and Counters ---
Movie movies[MAX_MOVIES];
int movie_count = 0;

CinemaHall halls[MAX_CINEMA_HALLS];
int hall_count = 0;

Showtime showtimes[MAX_TOTAL_SHOWTIMES];
int showtime_count = 0;

// --- Function Prototypes ---

// Utility
void clear_input_buffer();
int get_next_id(const char* type);
void display_main_menu();
const char* get_seat_type_name(SeatType type);

// File Operations
void load_movies();
void save_movies();
void load_halls();
void save_halls();
void load_showtimes();
void save_showtimes();
void save_seat_availability(int showtime_id);
void load_seat_availability(int showtime_id); // Called by load_showtimes

// Movie Management
void add_movie();
void view_movies();
Movie* find_movie_by_id(int id);

// Cinema Hall Management
void add_cinema_hall();
void view_cinema_halls();
CinemaHall* find_hall_by_id(int id);

// Showtime Management
void add_showtime();
void view_showtimes();
void view_showtimes_for_movie(int movie_id);
void view_showtime_details(Showtime* st); // Displays hall layout
Showtime* find_showtime_by_id(int id);

// Booking
void book_ticket();

// --- Main Function ---
int main() {
    // Load existing data at startup
    load_movies();
    load_halls();
    load_showtimes(); // This will also load individual seat data

    int choice;
    do {
        display_main_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer(); // Clear buffer after reading int

        switch (choice) {
            case 1: add_movie(); break;
            case 2: view_movies(); break;
            case 3: add_cinema_hall(); break;
            case 4: view_cinema_halls(); break;
            case 5: add_showtime(); break;
            case 6: view_showtimes(); break;
            case 7: book_ticket(); break;
            case 0: printf("Exiting Movie Ticketing System. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
        printf("\n"); // Newline for better readability between menu loops
    } while (choice != 0);

    return 0;
}
=======
    printf("\n** Movie Ticket Booking System **\n");
        displaymovie();
        int mchoice;
        printf("\nEnter the movie number you want to book: ");
        scanf("%d", &mchoice);
        book(mchoice);
   // fclose(fp);
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
>>>>>>> f026bdfe1b6cbef87c5697e31d7637c5dbcabeea

// --- Function Implementations ---

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_next_id(const char* type) {
    int max_id = 0;
    if (strcmp(type, "movie") == 0) {
        for (int i = 0; i < movie_count; i++) if (movies[i].id > max_id) max_id = movies[i].id;
    } else if (strcmp(type, "hall") == 0) {
        for (int i = 0; i < hall_count; i++) if (halls[i].id > max_id) max_id = halls[i].id;
    } else if (strcmp(type, "showtime") == 0) {
        for (int i = 0; i < showtime_count; i++) if (showtimes[i].id > max_id) max_id = showtimes[i].id;
    }
    return max_id + 1;
}

void display_main_menu() {
    printf("--- Movie Ticketing System ---\n");
    printf("1. Add New Movie\n");
    printf("2. View All Movies\n");
    printf("3. Add New Cinema Hall\n");
    printf("4. View All Cinema Halls\n");
    printf("5. Add New Showtime\n");
    printf("6. View All Showtimes\n");
    printf("7. Book Ticket\n");
    printf("0. Exit\n");
    printf("------------------------------\n");
}

const char* get_seat_type_name(SeatType type) {
    switch (type) {
        case SEAT_TYPE_STANDARD: return "Standard";
        case SEAT_TYPE_PREMIUM: return "Premium";
        default: return "Unknown";
    }
}

// --- File Operations ---

void load_movies() {
    FILE *file = fopen(FILENAME_MOVIES, "r");
    if (file == NULL) { printf("No movie data. Starting fresh.\n"); return; }
    movie_count = 0;
    while (movie_count < MAX_MOVIES &&
           fscanf(file, "%d,%[^,],%[^,],%d,%[^\n]\n",
                  &movies[movie_count].id, movies[movie_count].title,
                  movies[movie_count].genre, &movies[movie_count].duration_minutes,
                  movies[movie_count].rating) == 5) {
        movie_count++;
    }
    fclose(file);
    printf("Loaded %d movies.\n", movie_count);
}

void save_movies() {
    FILE *file = fopen(FILENAME_MOVIES, "w");
    if (file == NULL) { printf("Error: Could not open %s for writing.\n", FILENAME_MOVIES); return; }
    for (int i = 0; i < movie_count; i++) {
        fprintf(file, "%d,%s,%s,%d,%s\n",
                movies[i].id, movies[i].title, movies[i].genre,
                movies[i].duration_minutes, movies[i].rating);
    }
    fclose(file);
    printf("Saved %d movies.\n", movie_count);
}

void load_halls() {
    FILE *file = fopen(FILENAME_HALLS, "r");
    if (file == NULL) { printf("No cinema hall data. Starting fresh.\n"); return; }
    hall_count = 0;
    while (hall_count < MAX_CINEMA_HALLS &&
           fscanf(file, "%d,%[^,],%d,%d,%lf,%lf,%d\n",
                  &halls[hall_count].id, halls[hall_count].name,
                  &halls[hall_count].rows, &halls[hall_count].cols,
                  &halls[hall_count].prices[SEAT_TYPE_STANDARD],
                  &halls[hall_count].prices[SEAT_TYPE_PREMIUM],
                  &halls[hall_count].premium_start_row) == 7) {
        hall_count++;
    }
    fclose(file);
    printf("Loaded %d cinema halls.\n", hall_count);
}

void save_halls() {
    FILE *file = fopen(FILENAME_HALLS, "w");
    if (file == NULL) { printf("Error: Could not open %s for writing.\n", FILENAME_HALLS); return; }
    for (int i = 0; i < hall_count; i++) {
        fprintf(file, "%d,%s,%d,%d,%.2f,%.2f,%d\n",
                halls[i].id, halls[i].name, halls[i].rows, halls[i].cols,
                halls[i].prices[SEAT_TYPE_STANDARD], halls[i].prices[SEAT_TYPE_PREMIUM],
                halls[i].premium_start_row);
    }
    fclose(file);
    printf("Saved %d cinema halls.\n", hall_count);
}

// Function to generate a filename for seat availability for a specific showtime
char* get_seat_filename(int showtime_id) {
    static char filename[MAX_STRING_LENGTH]; // static to avoid returning pointer to local var
    sprintf(filename, "seats_showtime_%d.txt", showtime_id);
    return filename;
}

void save_seat_availability(int showtime_id) {
    Showtime* st = find_showtime_by_id(showtime_id);
    if (!st) return;

    CinemaHall* hall = find_hall_by_id(st->hall_id);
    if (!hall) return;

    FILE *file = fopen(get_seat_filename(showtime_id), "w");
    if (file == NULL) {
        printf("Error: Could not open seat file %s for writing.\n", get_seat_filename(showtime_id));
        return;
    }

    for (int i = 0; i < hall->rows; i++) {
        for (int j = 0; j < hall->cols; j++) {
            fprintf(file, "%c", st->seats[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void load_seat_availability(int showtime_id) {
    Showtime* st = find_showtime_by_id(showtime_id);
    if (!st) return;

    CinemaHall* hall = find_hall_by_id(st->hall_id);
    if (!hall) return;

    FILE *file = fopen(get_seat_filename(showtime_id), "r");
    if (file == NULL) {
        // If file doesn't exist, initialize all seats as available ('0')
        for (int i = 0; i < hall->rows; i++) {
            for (int j = 0; j < hall->cols; j++) {
                st->seats[i][j] = '0';
            }
        }
        save_seat_availability(showtime_id); // Save the newly initialized seats
        return;
    }

    // Load seat data from file
    for (int i = 0; i < hall->rows; i++) {
        for (int j = 0; j < hall->cols; j++) {
            char seat_char;
            if (fscanf(file, "%c", &seat_char) != 1) {
                // Handle error if file format is wrong or incomplete
                printf("Error loading seat data for showtime %d. Initializing seats.\n", showtime_id);
                for (int r = 0; r < hall->rows; r++) {
                    for (int c = 0; c < hall->cols; c++) {
                        st->seats[r][c] = '0'; // Reset if error
                    }
                }
                fclose(file);
                save_seat_availability(showtime_id);
                return;
            }
            st->seats[i][j] = seat_char;
        }
        fscanf(file, "\n"); // Consume newline character
    }
    fclose(file);
}

void load_showtimes() {
    FILE *file = fopen(FILENAME_SHOWTIMES, "r");
    if (file == NULL) { printf("No showtime data. Starting fresh.\n"); return; }
    showtime_count = 0;
    while (showtime_count < MAX_TOTAL_SHOWTIMES &&
           fscanf(file, "%d,%d,%d,%[^,],%[^\n]\n",
                  &showtimes[showtime_count].id,
                  &showtimes[showtime_count].movie_id,
                  &showtimes[showtime_count].hall_id,
                  showtimes[showtime_count].date,
                  showtimes[showtime_count].time) == 5) {
        // After loading basic showtime info, load its specific seat availability
        load_seat_availability(showtimes[showtime_count].id);
        showtime_count++;
    }
    fclose(file);
    printf("Loaded %d showtimes.\n", showtime_count);
}

void save_showtimes() {
    FILE *file = fopen(FILENAME_SHOWTIMES, "w");
    if (file == NULL) { printf("Error: Could not open %s for writing.\n", FILENAME_SHOWTIMES); return; }
    for (int i = 0; i < showtime_count; i++) {
        fprintf(file, "%d,%d,%d,%s,%s\n",
                showtimes[i].id,
                showtimes[i].movie_id,
                showtimes[i].hall_id,
                showtimes[i].date,
                showtimes[i].time);
        // Also save seat availability for each showtime
        save_seat_availability(showtimes[i].id);
    }
    fclose(file);
    printf("Saved %d showtimes.\n", showtime_count);
}


// --- Movie Management ---

void add_movie() {
    if (movie_count >= MAX_MOVIES) { printf("Maximum movies reached.\n"); return; }
    Movie new_movie;
    new_movie.id = get_next_id("movie");
    printf("\n--- Add New Movie ---\n");
    printf("Enter movie title: ");
    fgets(new_movie.title, MAX_STRING_LENGTH, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = 0;

    printf("Enter genre: ");
    fgets(new_movie.genre, MAX_STRING_LENGTH, stdin);
    new_movie.genre[strcspn(new_movie.genre, "\n")] = 0;

    printf("Enter duration in minutes: ");
    while (scanf("%d", &new_movie.duration_minutes) != 1 || new_movie.duration_minutes <= 0) {
        printf("Invalid duration. Enter positive number: "); clear_input_buffer();
    }
    clear_input_buffer();

    printf("Enter rating (e.g., G, PG, PG-13, R): ");
    fgets(new_movie.rating, 10, stdin);
    new_movie.rating[strcspn(new_movie.rating, "\n")] = 0;

    movies[movie_count++] = new_movie;
    save_movies();
    printf("Movie '%s' added successfully with ID %d.\n", new_movie.title, new_movie.id);
}

void view_movies() {
    if (movie_count == 0) { printf("No movies available.\n"); return; }
    printf("\n--- Available Movies ---\n");
    printf("ID\tTitle\t\tGenre\t\tDuration (min)\tRating\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < movie_count; i++) {
        printf("%d\t%-15s\t%-15s\t%d\t\t%s\n",
               movies[i].id, movies[i].title, movies[i].genre,
               movies[i].duration_minutes, movies[i].rating);
    }
    printf("------------------------------------------------------\n");
}

Movie* find_movie_by_id(int id) {
    for (int i = 0; i < movie_count; i++) if (movies[i].id == id) return &movies[i];
    return NULL;
}

// --- Cinema Hall Management ---

void add_cinema_hall() {
    if (hall_count >= MAX_CINEMA_HALLS) { printf("Maximum cinema halls reached.\n"); return; }
    CinemaHall new_hall;
    new_hall.id = get_next_id("hall");
    printf("\n--- Add New Cinema Hall ---\n");
    printf("Enter hall name: ");
    fgets(new_hall.name, MAX_STRING_LENGTH, stdin);
    new_hall.name[strcspn(new_hall.name, "\n")] = 0;

    printf("Enter number of rows (max %d): ", MAX_SEAT_ROWS);
    while (scanf("%d", &new_hall.rows) != 1 || new_hall.rows <= 0 || new_hall.rows > MAX_SEAT_ROWS) {
        printf("Invalid number of rows. Enter a positive number up to %d: ", MAX_SEAT_ROWS); clear_input_buffer();
    }
    clear_input_buffer();

    printf("Enter number of columns (max %d): ", MAX_SEAT_COLS);
    while (scanf("%d", &new_hall.cols) != 1 || new_hall.cols <= 0 || new_hall.cols > MAX_SEAT_COLS) {
        printf("Invalid number of columns. Enter a positive number up to %d: ", MAX_SEAT_COLS); clear_input_buffer();
    }
    clear_input_buffer();

    printf("Enter price for %s seats: ", get_seat_type_name(SEAT_TYPE_STANDARD));
    while (scanf("%lf", &new_hall.prices[SEAT_TYPE_STANDARD]) != 1 || new_hall.prices[SEAT_TYPE_STANDARD] <= 0) {
        printf("Invalid price. Enter a positive number: "); clear_input_buffer();
    }
    clear_input_buffer();

    // Default Premium price is 1.25x Standard, but can be customized
    new_hall.prices[SEAT_TYPE_PREMIUM] = new_hall.prices[SEAT_TYPE_STANDARD] * 1.25;
    printf("Enter price for %s seats (default %.2f): ", get_seat_type_name(SEAT_TYPE_PREMIUM), new_hall.prices[SEAT_TYPE_PREMIUM]);
    char confirm_default;
    printf("Press Enter to accept default, or 'c' to customize: ");
    scanf(" %c", &confirm_default);
    if (confirm_default == '\n' || confirm_default == 'c' || confirm_default == 'C') { // Handle immediate newline or 'c'
         clear_input_buffer(); // Consume remaining newline if 'c' was pressed
         if (confirm_default == 'c' || confirm_default == 'C') {
             printf("Enter custom price for %s seats: ", get_seat_type_name(SEAT_TYPE_PREMIUM));
             while (scanf("%lf", &new_hall.prices[SEAT_TYPE_PREMIUM]) != 1 || new_hall.prices[SEAT_TYPE_PREMIUM] <= 0) {
                 printf("Invalid price. Enter a positive number: "); clear_input_buffer();
             }
             clear_input_buffer();
         }
    } else { // Handle any other non-newline character entered
         clear_input_buffer();
    }

    printf("Enter the starting row number for Premium seats (0 to %d). Rows before this are Standard. Enter %d for all Standard: ", new_hall.rows -1, new_hall.rows);
    while (scanf("%d", &new_hall.premium_start_row) != 1 || new_hall.premium_start_row < 0 || new_hall.premium_start_row > new_hall.rows) {
        printf("Invalid row. Enter a number between 0 and %d: ", new_hall.rows); clear_input_buffer();
    }
    clear_input_buffer();

    halls[hall_count++] = new_hall;
    save_halls();
    printf("Cinema Hall '%s' added successfully with ID %d.\n", new_hall.name, new_hall.id);
}

void view_cinema_halls() {
    if (hall_count == 0) { printf("No cinema halls available.\n"); return; }
    printf("\n--- Available Cinema Halls ---\n");
    printf("ID\tName\t\tRows\tCols\tStandard Price\tPremium Price\tPremium Start Row\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < hall_count; i++) {
        printf("%d\t%-15s\t%d\t%d\t%.2f\t\t%.2f\t\t%d\n",
               halls[i].id, halls[i].name, halls[i].rows, halls[i].cols,
               halls[i].prices[SEAT_TYPE_STANDARD], halls[i].prices[SEAT_TYPE_PREMIUM],
               halls[i].premium_start_row);
    }
    printf("-----------------------------------------------------------------------------------------------------\n");
}

CinemaHall* find_hall_by_id(int id) {
    for (int i = 0; i < hall_count; i++) if (halls[i].id == id) return &halls[i];
    return NULL;
}

// --- Showtime Management ---

void add_showtime() {
    if (showtime_count >= MAX_TOTAL_SHOWTIMES) { printf("Maximum showtimes reached.\n"); return; }
    printf("\n--- Add New Showtime ---\n");
    view_movies();
    if (movie_count == 0) { printf("Cannot add showtime: No movies. Add a movie first.\n"); return; }

    Showtime new_showtime;
    new_showtime.id = get_next_id("showtime");

    int movie_id_input;
    Movie *selected_movie = NULL;
    printf("Enter Movie ID for this showtime: ");
    while (scanf("%d", &movie_id_input) != 1 || (selected_movie = find_movie_by_id(movie_id_input)) == NULL) {
        printf("Invalid Movie ID. Enter valid Movie ID: "); clear_input_buffer();
    }
    clear_input_buffer();
    new_showtime.movie_id = movie_id_input;

    view_cinema_halls();
    if (hall_count == 0) { printf("Cannot add showtime: No halls. Add a hall first.\n"); return; }

    int hall_id_input;
    CinemaHall *selected_hall = NULL;
    printf("Enter Cinema Hall ID for this showtime: ");
    while (scanf("%d", &hall_id_input) != 1 || (selected_hall = find_hall_by_id(hall_id_input)) == NULL) {
        printf("Invalid Hall ID. Enter valid Hall ID: "); clear_input_buffer();
    }
    clear_input_buffer();
    new_showtime.hall_id = hall_id_input;

    printf("Enter date (YYYY-MM-DD): ");
    fgets(new_showtime.date, 20, stdin);
    new_showtime.date[strcspn(new_showtime.date, "\n")] = 0;

    printf("Enter time (HH:MM - 24hr format): ");
    fgets(new_showtime.time, 10, stdin);
    new_showtime.time[strcspn(new_showtime.time, "\n")] = 0;

    // Initialize all seats in the new showtime as available ('0')
    // This will be saved to its own seat file
    for (int i = 0; i < selected_hall->rows; i++) {
        for (int j = 0; j < selected_hall->cols; j++) {
            new_showtime.seats[i][j] = '0'; // '0' for available, '1' for booked
        }
    }

    showtimes[showtime_count] = new_showtime; // Assign the newly created showtime
    showtime_count++; // Increment count *after* assigning

    save_showtimes(); // This will save the new showtime and its initial seat layout
    printf("Showtime for '%s' in '%s' on %s at %s added successfully with ID %d.\n",
           selected_movie->title, selected_hall->name, new_showtime.date, new_showtime.time, new_showtime.id);
}

void view_showtimes() {
    if (showtime_count == 0) { printf("No showtimes available.\n"); return; }
    printf("\n--- All Showtimes ---\n");
    printf("ID\tMovie Title\t\tHall Name\tDate\t\tTime\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < showtime_count; i++) {
        Movie *m = find_movie_by_id(showtimes[i].movie_id);
        CinemaHall *h = find_hall_by_id(showtimes[i].hall_id);
        const char* movie_title = (m != NULL) ? m->title : "Unknown Movie";
        const char* hall_name = (h != NULL) ? h->name : "Unknown Hall";
        printf("%d\t%-20s\t%-15s\t%-10s\t%-5s\n",
               showtimes[i].id, movie_title, hall_name,
               showtimes[i].date, showtimes[i].time);
    }
    printf("-------------------------------------------------------------------\n");
}

void view_showtimes_for_movie(int movie_id) {
    int found_any = 0;
    printf("\n--- Showtimes for Movie ID %d ---\n", movie_id);
    printf("ID\tHall Name\tDate\t\tTime\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < showtime_count; i++) {
        if (showtimes[i].movie_id == movie_id) {
            CinemaHall *h = find_hall_by_id(showtimes[i].hall_id);
            const char* hall_name = (h != NULL) ? h->name : "Unknown Hall";
            printf("%d\t%-15s\t%-10s\t%-5s\n",
                   showtimes[i].id, hall_name, showtimes[i].date, showtimes[i].time);
            found_any = 1;
        }
    }
    if (!found_any) { printf("No showtimes found for this movie.\n"); }
    printf("----------------------------------------------\n");
}

void view_showtime_details(Showtime* st) {
    if (!st) return;

    CinemaHall* hall = find_hall_by_id(st->hall_id);
    if (!hall) { printf("Associated hall not found for this showtime.\n"); return; }

    printf("\n--- Seat Availability for %s on %s at %s (%s) ---\n",
           find_movie_by_id(st->movie_id)->title, st->date, st->time, hall->name);
    printf("Legend: X = Booked, O = Available\n");
    printf("       (Standard: O, Premium: O_P)\n");

    printf("  "); // Spacer for row numbers
    for (int j = 0; j < hall->cols; j++) {
        printf("%-2d ", j + 1); // Column headers
    }
    printf("\n");

    for (int i = 0; i < hall->rows; i++) {
        printf("%c ", 'A' + i); // Row letters
        for (int j = 0; j < hall->cols; j++) {
            if (st->seats[i][j] == '1') {
                printf("X  "); // Booked seat
            } else {
                if (i < hall->premium_start_row) { // Standard seat
                    printf("O  ");
                } else { // Premium seat
                    printf("O_P");
                }
            }
        }
        printf("\n");
    }
    printf("----------------------------------------------------------------\n");
    printf("Seat Prices:\n");
    printf("  %s: %.2f\n", get_seat_type_name(SEAT_TYPE_STANDARD), hall->prices[SEAT_TYPE_STANDARD]);
    if (hall->premium_start_row < hall->rows) { // Only show premium if there are premium seats
        printf("  %s: %.2f\n", get_seat_type_name(SEAT_TYPE_PREMIUM), hall->prices[SEAT_TYPE_PREMIUM]);
    }
    printf("----------------------------------------------------------------\n");
}

Showtime* find_showtime_by_id(int id) {
    for (int i = 0; i < showtime_count; i++) if (showtimes[i].id == id) return &showtimes[i];
    return NULL;
}

// --- Booking ---

void book_ticket() {
    printf("\n--- Book a Ticket ---\n");
    if (movie_count == 0 || showtime_count == 0 || hall_count == 0) {
        printf("System not fully set up (no movies, halls, or showtimes).\n");
        return;
    }

    view_movies();
    int chosen_movie_id;
    Movie *selected_movie = NULL;
    printf("Enter the ID of the movie you want to watch: ");
    while (scanf("%d", &chosen_movie_id) != 1 || (selected_movie = find_movie_by_id(chosen_movie_id)) == NULL) {
        printf("Invalid Movie ID. Please enter a valid Movie ID: "); clear_input_buffer();
    }
    clear_input_buffer();

    view_showtimes_for_movie(chosen_movie_id);
    int chosen_showtime_id;
    Showtime *selected_showtime = NULL;
    int showtime_exists_for_movie = 0;
    for (int i = 0; i < showtime_count; i++) {
        if (showtimes[i].movie_id == chosen_movie_id) { showtime_exists_for_movie = 1; break; }
    }
    if (!showtime_exists_for_movie) {
        printf("No showtimes available for '%s'. Cannot proceed.\n", selected_movie->title); return;
    }

    printf("Enter the ID of the showtime you want to book: ");
    while (scanf("%d", &chosen_showtime_id) != 1 || (selected_showtime = find_showtime_by_id(chosen_showtime_id)) == NULL || selected_showtime->movie_id != chosen_movie_id) {
        printf("Invalid Showtime ID or showtime not for selected movie. Enter valid Showtime ID: "); clear_input_buffer();
    }
    clear_input_buffer();

    CinemaHall *hall = find_hall_by_id(selected_showtime->hall_id);
    if (!hall) { printf("Error: Hall not found for this showtime.\n"); return; }

    view_showtime_details(selected_showtime);

    int num_tickets;
    printf("How many tickets do you want to book? ");
    while (scanf("%d", &num_tickets) != 1 || num_tickets <= 0) {
        printf("Invalid number. Enter a positive integer: "); clear_input_buffer();
    }
    clear_input_buffer();

    double total_price = 0.0;
    int tickets_booked_successfully = 0;

    for (int i = 0; i < num_tickets; i++) {
        char row_char;
        int col;
        printf("Enter seat (e.g., A5, B10) for ticket %d: ", i + 1);
        if (scanf(" %c%d", &row_char, &col) != 2) { // Note the space before %c to consume leftover newline
            printf("Invalid format. Skipping this ticket.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        int row = toupper(row_char) - 'A';
        col--; // Adjust to 0-indexed column

        if (row < 0 || row >= hall->rows || col < 0 || col >= hall->cols) {
            printf("Seat %c%d is out of bounds. Skipping this ticket.\n", row_char, col + 1);
            continue;
        }

        if (selected_showtime->seats[row][col] == '1') {
            printf("Seat %c%d is already booked. Skipping this ticket.\n", row_char, col + 1);
            continue;
        }

        // Book the seat
        selected_showtime->seats[row][col] = '1';
        tickets_booked_successfully++;

        double ticket_price;
        if (row < hall->premium_start_row) {
            ticket_price = hall->prices[SEAT_TYPE_STANDARD];
            printf("Booked seat %c%d (%s) for %.2f.\n", row_char, col + 1, get_seat_type_name(SEAT_TYPE_STANDARD), ticket_price);
        } else {
            ticket_price = hall->prices[SEAT_TYPE_PREMIUM];
            printf("Booked seat %c%d (%s) for %.2f.\n", row_char, col + 1, get_seat_type_name(SEAT_TYPE_PREMIUM), ticket_price);
        }
        total_price += ticket_price;
    }

    if (tickets_booked_successfully > 0) {
        printf("\n--- Booking Summary ---\n");
        printf("Movie: %s\n", selected_movie->title);
        printf("Showtime: %s at %s in %s\n", selected_showtime->date, selected_showtime->time, hall->name);
        printf("Tickets booked: %d\n", tickets_booked_successfully);
        printf("Total Price: %.2f\n", total_price);

        char confirm;
        printf("Confirm final purchase? (y/n): ");
        scanf(" %c", &confirm);
        clear_input_buffer();

        if (confirm == 'y' || confirm == 'Y') {
            save_showtimes(); // Save the updated seat availability
            printf("Purchase successful! Enjoy your movie!\n");
        } else {
            printf("Purchase cancelled. Reverting seat selections (NOT YET IMPLEMENTED FOR SIMPLICITY).\n");
            // In a real system, you'd revert the '1' to '0' for seats selected but not confirmed.
            // For simplicity, this example does not revert. Re-running the program will reflect previous state.
        }
    } else {
        printf("No tickets were successfully booked.\n");
    }
}

    return 0;
}
/*
