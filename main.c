#include <stdio.h>
#include <stdlib.h>

struct User {
    char userName[100];
    int identification;
    int passWord;
};

void createAccount() {
    struct User newUser;

    printf("Enter your username: \n");
    scanf("%s", newUser.userName);

    printf("Enter your ID Number: \n");
    scanf("%d", &newUser.identification);

    printf("Enter your password: \n");
    scanf("%d", &newUser.passWord);

    FILE *fclient;
    fclient = fopen("clientlist.txt", "a");

    if (fclient == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    fprintf(fclient, "%s %d %d\n", newUser.userName, newUser.identification, newUser.passWord);

    fclose(fclient);
    printf("Account created successfully.\n");
}

void displayDetails(struct User user) {
    printf("Username: %s\n", user.userName);
    printf("ID Number: %d\n", user.identification);
    printf("Password: %d\n", user.passWord);
}

void editDetails(struct User *user, int choice) {
    switch (choice) {
        case 1:
            printf("Enter new username: ");
            scanf("%s", user->userName);
            break;
        case 2:
            printf("Enter new password: ");
            scanf("%d", &user->passWord);
            break;
        case 3:
            printf("Enter new ID Number: ");
            scanf("%d", &user->identification);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void writeToFile(struct User user) {
    FILE *file = fopen("user_details.txt", "a");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    fprintf(file, "%s %d %d\n", user.userName, user.identification, user.passWord);
    fclose(file);
}

int main() {
    int userChoice, choice, option;

    printf("Hello! Welcome to 79 & Sons Bank.\n");
    printf("Please select the desired service.\n");
    printf("1. To create account as a new user.\n2. To send money\n3. To withdraw cash\n4. To deposit\n5. To query for Transaction Statement (last 5 transactions)\n");

    scanf("%d", &userChoice);

    switch (userChoice) {
        case 1:
            createAccount();
            break;
        // Add cases for other services as needed
        default:
            printf("You have selected an invalid choice!\n");
    }

    printf("Menu:\n");
    printf("1. View User Details\n");
    printf("2. Edit Details\n");
    printf("3. Exit\n");

    scanf("%d", &option);

    switch (option) {
       FILE *file = fopen("user_details.txt", "r");

        case 1:

            if (file == NULL) {
                printf("Error opening the file.\n");
                return 1;
            }

            struct User user;

            // Read and display details
            while (fscanf(file, "%s %d %d", user.userName, &user.identification, &user.passWord) == 3) {
                displayDetails(user);
                printf("\n");
            }

            fclose(file);
            break;

        case 2:
            printf("Kindly select details you want to edit.\n");
            printf("1. Username\n2. Password\n3. ID Number\n");
            scanf("%d", &choice);

            FILE *editFile = fopen("user_details.txt", "r+");

            if (editFile == NULL) {
                printf("Error opening the file.\n");
                return 1;
            }

            struct User editUser;

            // Assuming you have a specific user record to edit, you need to search for that record in the file
            // You can use a loop with fscanf to read records and compare with the user you want to edit
            // If found, you can call the editDetails function passing the user and the choice of what to edit

            // For example:
            while (fscanf(editFile, "%s %d %d", editUser.userName, &editUser.identification, &editUser.passWord) == 3) {
                // Check if this is the user you want to edit
                // For simplicity, let's assume you want to edit the first user in the file
                editDetails(&editUser, choice);

                // You might want to break after editing the user
                break;
            }

            fclose(editFile);
            break;

        case 3:
            // Add code for exit or other options
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
