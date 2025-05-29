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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "D:\\Riya\\pro.txt"

void remove_newline(char *str) {
    //str[strcspn(str, "\n")] = '\0';
}

void signUp() {
    char email[50];
    char password[50];

    printf("------Sign Up------\n");
    printf("Enter New Email:\n");
    //fgets(email, sizeof(email), stdin);
    //remove_newline(email);

    printf("Enter New Password:\n");
    //fgets(password, sizeof(password), stdin);
    //remove_newline(password);

    FILE *fp = fopen(FILE_PATH, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(fp, "%s\n%s\n", email, password);
    fclose(fp);

    printf("Sign Up successful!\n\n");
}

int login() {
    char email[50];
    char password[50];
    char stored_email[50];
    char stored_password[50];

    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL) {
        printf("No account found. Please sign up first.\n");
        return 1;
    }

    fgets(stored_email, sizeof(stored_email), fp);
    //remove_newline(stored_email);

    fgets(stored_password, sizeof(stored_password), fp);
    //remove_newline(stored_password);
    fclose(fp);

    printf("------Log in------\n");

    printf("Enter Email:\n");
    //fgets(email, sizeof(email), stdin);
    //remove_newline(email);

    if (strcmp(email, stored_email) != 0) {
        printf("Incorrect email\n");
        return 1;
    }

    printf("Enter Password:\n");
    //fgets(password, sizeof(password), stdin);
    //remove_newline(password);

    if (strcmp(password, stored_password) != 0) {
        printf("Password incorrect\n");
        return 1;
    }

    printf("Login successful!\n");
    return 0;
}

int main() {
    int choice;

    printf("1. Sign Up\n");
    printf("2. Log In\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    //getchar();  // To consume the newline character left by scanf

    switch (choice) {
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

