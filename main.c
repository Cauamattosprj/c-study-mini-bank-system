#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void accountLogin(void) {
    char loginTry[20]; // Assuming the loginTry is a string
    char loginInfo[50];

    printf("WELCOME TO CBank...");
    FILE *fp;
    fp = fopen("userinfo.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Login (CPF): ");
    scanf("%s", loginTry);
    printf("%s", loginTry);
    fgetw(fp, "accountnumber: %s", loginInfo);
    printf("\nRead from file: %s\n", loginInfo);

    fclose(fp);
};


void createAccount(void) {
    struct accountInfo {
    int day, month, year;
    char phoneNumber[15];
    char CPF[12];
    char firstName[20];
    char lastName[20];
    char fatherName[20];
    char motherName[20];
    char adress[50];
    char accountNumber[20];
    };

    struct accountLogin {
    char username[50];
    char password[50];
    };
    
    struct accountLogin p1;

    FILE *fp, *fu;
    struct accountInfo u1;

    fp = fopen("userinfo.txt", "a+");
    if (fp == NULL) {
        printf("Error");
    }    

    // Personal data for account creation
    system("cls");
    printf("!!!!!CREATE ACCOUNT!!!!!\n");

    printf("FIRST NAME: ");
    scanf("%s", &u1.firstName);
    fprintf(fp, "first name: %s\n", u1.firstName);

    printf("LAST NAME: ");
    scanf("%s", &u1.lastName);
    fprintf(fp, "lastName: %s\n", u1.lastName);


    printf("!!!!!BIRTHDAY!!!!!\n");
    printf("DAY: ");
    scanf("%d", &u1.day);
    fprintf(fp, "day of birth: %d\n", u1.day);

    printf("MONTH: ");
    scanf("%d", &u1.month);
    fprintf(fp, "month of birth: %d\n", u1.month);

    printf("YEAR: ");
    scanf("%d", &u1.year);
    fprintf(fp, "year of birth: %d\n", u1.year);

    printf("CPF: ");
    scanf("%s", &u1.CPF);
    fprintf(fp, "CPF: %s\n", u1.CPF);

    printf("FATHER NAME: ");
    scanf("%s", &u1.fatherName);
    fprintf(fp, "father name: %s\n", u1.fatherName);

    printf("MOTHER NAME: ");
    scanf("%s", &u1.motherName);
    fprintf(fp, "mother name: %s\n", u1.motherName);

    printf("ADRESS: ");
    scanf("%s", &u1.adress);
    fprintf(fp, "adress: %s\n", u1.adress);


    printf("Your account has been sucessfully created.\nNow choose you password:\nPassword: ");
    scanf("%s", &p1.password);
    fprintf(fp, "password: %s\n", p1.password);

    sprintf(p1.username, u1.CPF);
    fprintf(fp, "username: %s\n", p1.username);



    // Generate an account number
    system("cls");
    srand(time(NULL));
    sprintf(u1.accountNumber, "2406%d%d%d-%d", rand() % 9, rand() % 9, rand() % 9, rand() % 9);
    printf("Account sucessfully created. \nYour account number is: %s\n", u1.accountNumber);
    fprintf(fp, "account number: %s\n", u1.accountNumber);
    
    fprintf(fp, "EOF\n\n\n\n------------------------------");

    fclose(fp);
};

void bankMenu(void) {
    int userOption;

    printf("WELCOME TO CBank...\nOPTIONS: \nLogin (1)\nCreate a new account (2) \n");
    scanf("%d", &userOption);

    switch (userOption) {
        case 1:
        accountLogin();
        break;

        case 2:
        createAccount();
        break;

        default:
        printf("Invalid option. Please, try again.");
    }
}

int main(void){
    bankMenu();  
};