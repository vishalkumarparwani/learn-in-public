#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX_PRODUCTS 200
#define MAX_USERS 85

struct cartItem
{
    char productName[65];
    float price;
    int quantity;
};

struct cartItem viewCart[MAX_PRODUCTS];
int itemCount = 0;

void logIn(char usernameInput[], char usernameExist[][250], char passwordInput[], char passwordExist[][250]);
void signIn(char usernameExist[][250], char passwordExist[][250]);
void deleteAccount(char usernameInput[], char usernameExist[][250], char passwordInput[], char passwordExist[][250]);
void addProductAndCalc(int *category, int *sub_category, int *input_item, float *totalCost);
void viewCartContent();

void viewCartContent()
{
    printf("\nProducts in the cart:\n");

    if (itemCount == 0)
    {
        printf("Your cart is empty.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++)
    {
        printf("Product Name: %s\n", viewCart[i].productName);
        printf("Product Price: %.1f\n", viewCart[i].price);
        printf("Product Quantity: %d\n\n", viewCart[i].quantity);
    }
}

int main()
{
    system("color 0A");

    char usernameExist[MAX_USERS][250] = {"user1", "user2", "abc"};
    char passwordExist[MAX_USERS][250] = {"pass1", "pass2", "123"};

    char usernameInput[80] = {0};
    char passwordInput[80] = {0};

    int optionPortal;
    int mainOption;
    int cartOption;
    int category = 0;
    int sub_category = 0;
    int input_item = 0;
    float totalCost = 0.0;
    char choice = 'y';

    while (1)
    {
        printf("\n----- WELCOME TO THE ONLINE SHOPPING SYSTEM -----\n");
        printf("1. Admin Portal.\n");
        printf("2. Customer Portal.\n");
        printf("3. Exit.\n");
        scanf("%d", &optionPortal);

        switch (optionPortal)
        {
        case 1:
            printf("\n----- Admin Portal -----\n\n");
            printf("1. Log-in.\n");
            printf("2. Sign-in.\n");
            printf("3. Delete Account.\n");
            printf("4. Accounts information.\n");
            printf("5. Exit.\n");
            scanf("%d", &mainOption);

            switch (mainOption)
            {
            case 1:
                logIn(usernameInput, usernameExist, passwordInput, passwordExist);

                if (strlen(usernameInput) > 0)
                {
                    printf("\n1. Buy Product.\n");
                    printf("2. View Product.\n");
                    printf("3. Main Menu.\n");
                    scanf("%d", &cartOption);

                    if (cartOption == 1)
                    {
                        choice = 'y';
                        while (choice == 'y' || choice == 'Y')
                        {
                            addProductAndCalc(&category, &sub_category, &input_item, &totalCost);
                            printf("\nTotal Cost: $%.2f.\n", totalCost);
                            printf("Do you want to add another item? (y/n): ");
                            scanf(" %c", &choice);
                        }

                        printf("\nWhat would you like to do next?\n");
                        printf("1. View Cart\n");
                        printf("2. Return to Main Menu\n");

                        int nextAction;
                        scanf("%d", &nextAction);

                        if (nextAction == 1)
                        {
                            viewCartContent();
                        }
                    }
                    else if (cartOption == 2)
                    {
                        viewCartContent();
                    }
                    else if (cartOption == 3)
                    {
                        /* returning to main menu, nothing else to do here */
                    }
                    else
                    {
                        printf("\nInvalid Option.\n");
                    }
                }
                else
                {
                    printf("\nLogin failed. Returning to Admin portal.\n");
                }
                break;

            case 2:
                signIn(usernameExist, passwordExist);
                break;

            case 3:
                printf("\nEnter username to delete: ");
                scanf("%79s", usernameInput);
                printf("Enter password to delete: ");
                scanf("%79s", passwordInput);
                deleteAccount(usernameInput, usernameExist, passwordInput, passwordExist);
                break;

            case 4:
                for (int i = 0; i < MAX_USERS; i++)
                {
                    if (usernameExist[i][0] == '\0')
                    {
                        continue;
                    }
                    printf("Username: %s\n", usernameExist[i]);
                    printf("Password: %s\n\n", passwordExist[i]);
                }
                break;

            case 5:
                printf("\nExiting the system.\n");
                return 0;

            default:
                printf("\nInvalid Input. Please try again.\n");
                break;
            }
            break;

        case 2:
            printf("\n----- Customer Portal -----\n\n");
            printf("1. Log-in.\n");
            printf("2. Sign-in.\n");
            printf("3. Delete Account.\n");
            printf("4. Exit.\n");
            scanf("%d", &mainOption);

            switch (mainOption)
            {
            case 1:
                logIn(usernameInput, usernameExist, passwordInput, passwordExist);

                if (strlen(usernameInput) > 0)
                {
                    printf("\n1. Buy Product.\n");
                    printf("2. View Product.\n");
                    printf("3. Main Menu.\n");
                    scanf("%d", &cartOption);

                    if (cartOption == 1)
                    {
                        choice = 'y';
                        while (choice == 'y' || choice == 'Y')
                        {
                            addProductAndCalc(&category, &sub_category, &input_item, &totalCost);
                            printf("\nTotal Cost: $%.2f.\n", totalCost);
                            printf("Do you want to add another item? (y/n): ");
                            scanf(" %c", &choice);
                        }

                        printf("\nWhat would you like to do next?\n");
                        printf("1. View Cart\n");
                        printf("2. Return to Main Menu\n");

                        int nextAction;
                        scanf("%d", &nextAction);

                        if (nextAction == 1)
                        {
                            viewCartContent();
                        }
                    }
                    else if (cartOption == 2)
                    {
                        viewCartContent();
                    }
                    else if (cartOption == 3)
                    {
                        /* returning to main menu, nothing else to do here */
                    }
                    else
                    {
                        printf("\nInvalid Option.\n");
                    }
                }
                else
                {
                    printf("\nLogin failed. Returning to Customer portal.\n");
                }
                break;

            case 2:
                signIn(usernameExist, passwordExist);
                break;

            case 3:
                printf("\nEnter your username and password to delete your account.\n\n");
                printf("Enter username to delete: ");
                scanf("%79s", usernameInput);
                printf("Enter password to delete: ");
                scanf("%79s", passwordInput);
                deleteAccount(usernameInput, usernameExist, passwordInput, passwordExist);
                break;

            case 4:
                printf("\nExiting the system.\n");
                return 0;

            default:
                printf("\nInvalid Input. Please try again.\n");
                break;
            }
            break;

        case 3:
            printf("\nExiting...\n");
            return 0;

        default:
            printf("\nInvalid option.\n");
            break;
        }
    }

    return 0;
}

void deleteAccount(char usernameInput[], char usernameExist[][250], char passwordInput[], char passwordExist[][250])
{
    char choice = 'y';
    int trial = 3;

    while (trial > 0)
    {
        int userFound = 0;

        for (int i = 0; i < MAX_USERS; i++)
        {
            if (usernameExist[i][0] == '\0')
            {
                continue;
            }
            if (strcmp(usernameInput, usernameExist[i]) == 0 && strcmp(passwordInput, passwordExist[i]) == 0)
            {
                userFound = 1;
                usernameExist[i][0] = '\0';
                passwordExist[i][0] = '\0';
                printf("\nAccount with username %s deleted successfully.\n", usernameInput);
                break;
            }
        }

        if (!userFound)
        {
            trial--;
            printf("\nInvalid username or password.");
            printf("\nYou have %d trials left.\n", trial);
        }

        if (trial > 0 && !userFound)
        {
            printf("\nDo you want to retry? (y/n): ");
            scanf(" %c", &choice);

            if (choice != 'y' && choice != 'Y')
            {
                printf("\nExiting the deletion process.\n");
                break;
            }

            printf("Enter username: ");
            scanf("%79s", usernameInput);
            printf("Enter password: ");
            scanf("%79s", passwordInput);
        }
        else
        {
            break;
        }
    }

    if (trial == 0)
    {
        printf("\nYou have exceeded the maximum number of trials. Exiting the deletion process.\n");
    }
}

void logIn(char usernameInput[], char usernameExist[][250], char passwordInput[], char passwordExist[][250])
{
    int trial = 3;
    int loggedin = 0;

    while (trial > 0 && !loggedin)
    {
        printf("\nEnter username: ");
        scanf("%79s", usernameInput);
        printf("Enter password: ");
        scanf("%79s", passwordInput);

        for (int i = 0; i < MAX_USERS; i++)
        {
            if (usernameExist[i][0] == '\0')
            {
                continue;
            }
            if (strcmp(usernameInput, usernameExist[i]) == 0 && strcmp(passwordInput, passwordExist[i]) == 0)
            {
                loggedin = 1;
                printf("\nWelcome, %s!\n", usernameExist[i]);
                return;
            }
        }

        trial--;
        if (!loggedin)
        {
            printf("\nInvalid username or password. %d trials remaining.\n", trial);
        }
    }

    if (!loggedin)
    {
        usernameInput[0] = '\0';
        printf("\nLogin failed. Returning to the main menu.\n");
    }
}

void signIn(char usernameExist[][250], char passwordExist[][250])
{
    char newUsername[250];
    char newPassword[250];
    int i = 0;

    while (i < MAX_USERS && usernameExist[i][0] != '\0')
    {
        i++;
    }

    if (i < MAX_USERS)
    {
        printf("\nEnter username: ");
        scanf("%249s", newUsername);
        printf("Enter password: ");
        scanf("%249s", newPassword);

        strcpy(usernameExist[i], newUsername);
        strcpy(passwordExist[i], newPassword);

        printf("\nYou have signed in successfully.\n");
    }
    else
    {
        printf("\nCannot create a new account, the system is full.\n");
    }
}

void addProductAndCalc(int *category, int *sub_category, int *input_item, float *totalCost)
{
    if (itemCount >= MAX_PRODUCTS)
    {
        printf("\nCart is full, cannot add more items.\n");
        return;
    }

    int qty = 0;
    float price = 0;

    printf("\n----- Categories -----\n");
    printf("1. Food.\n");
    printf("2. Electronics.\n");
    printf("3. Stationary & Office Supplies.\n");
    printf("Enter category number: ");
    scanf("%d", category);

    if (*category < 1 || *category > 3)
    {
        printf("\nInvalid category.\n");
        return;
    }

    switch (*category)
    {
    case 1:
        printf("\n----- Food Categories -----\n");
        printf("1. Dairy.\n");
        printf("2. Meat.\n");
        printf("3. SeaFood.\n");
        printf("4. Grains.\n");
        printf("5. Fruits.\n");
        printf("6. Vegetables.\n");
        printf("7. Nuts & Seeds.\n");
        scanf("%d", sub_category);

        switch (*sub_category)
        {
        case 1:
            printf("1. Milk----$0.9.\n");
            printf("2. Cheese----$4.3.\n");
            printf("3. Yogurt----$1.5.\n");
            printf("4. Butter----$4.\n");
            printf("5. Cream----$3.7.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 0.9f; strcpy(viewCart[itemCount].productName, "Milk"); }
            else if (*input_item == 2) { price = 4.3f; strcpy(viewCart[itemCount].productName, "Cheese"); }
            else if (*input_item == 3) { price = 1.5f; strcpy(viewCart[itemCount].productName, "Yogurt"); }
            else if (*input_item == 4) { price = 4.0f; strcpy(viewCart[itemCount].productName, "Butter"); }
            else if (*input_item == 5) { price = 3.7f; strcpy(viewCart[itemCount].productName, "Cream"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 2:
            printf("1. Chicken----$5.2.\n");
            printf("2. Lamb----$8.3.\n");
            printf("3. Turkey----$6.6.\n");
            printf("4. Goat----$8.5.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 5.2f; strcpy(viewCart[itemCount].productName, "Chicken"); }
            else if (*input_item == 2) { price = 8.3f; strcpy(viewCart[itemCount].productName, "Lamb"); }
            else if (*input_item == 3) { price = 6.6f; strcpy(viewCart[itemCount].productName, "Turkey"); }
            else if (*input_item == 4) { price = 8.5f; strcpy(viewCart[itemCount].productName, "Goat"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 3:
            printf("1. Salmon----$3.1.\n");
            printf("2. Tuna----$3.4.\n");
            printf("3. Shrimp----$10.\n");
            printf("4. Cod----$3.1.\n");
            printf("5. Lobster----$11.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 3.1f; strcpy(viewCart[itemCount].productName, "Salmon"); }
            else if (*input_item == 2) { price = 3.4f; strcpy(viewCart[itemCount].productName, "Tuna"); }
            else if (*input_item == 3) { price = 10.0f; strcpy(viewCart[itemCount].productName, "Shrimp"); }
            else if (*input_item == 4) { price = 3.1f; strcpy(viewCart[itemCount].productName, "Cod"); }
            else if (*input_item == 5) { price = 11.0f; strcpy(viewCart[itemCount].productName, "Lobster"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 4:
            printf("1. Rice----$2 per kg.\n");
            printf("2. Wheat----$0.8 per kg.\n");
            printf("3. Oats----$1.3 per kg.\n");
            printf("4. Corn----$1.5 per kg.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 2.0f; strcpy(viewCart[itemCount].productName, "Rice"); }
            else if (*input_item == 2) { price = 0.8f; strcpy(viewCart[itemCount].productName, "Wheat"); }
            else if (*input_item == 3) { price = 1.3f; strcpy(viewCart[itemCount].productName, "Oats"); }
            else if (*input_item == 4) { price = 1.5f; strcpy(viewCart[itemCount].productName, "Corn"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 5:
            printf("1. Apple----$2 per kg.\n");
            printf("2. Banana----$1.6 per kg.\n");
            printf("3. Orange----$3 per kg.\n");
            printf("4. Mango----$3 per kg.\n");
            printf("5. Grapes----$2.7 per kg.\n");
            printf("6. Pineapple----$3.1 per kg.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 2.0f; strcpy(viewCart[itemCount].productName, "Apple"); }
            else if (*input_item == 2) { price = 1.6f; strcpy(viewCart[itemCount].productName, "Banana"); }
            else if (*input_item == 3) { price = 3.0f; strcpy(viewCart[itemCount].productName, "Orange"); }
            else if (*input_item == 4) { price = 3.0f; strcpy(viewCart[itemCount].productName, "Mango"); }
            else if (*input_item == 5) { price = 2.7f; strcpy(viewCart[itemCount].productName, "Grapes"); }
            else if (*input_item == 6) { price = 3.1f; strcpy(viewCart[itemCount].productName, "Pineapple"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 6:
            printf("1. Carrot----$1.3 per kg.\n");
            printf("2. Potato----$2.1 per kg.\n");
            printf("3. Peas----$1.3 per kg.\n");
            printf("4. Broccoli----$2.4 per kg.\n");
            printf("5. Spinach----$2.1 per kg.\n");
            printf("6. Cauliflower----$2.4 per kg.\n");
            printf("7. Celery----$1.3 per kg.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 1.3f; strcpy(viewCart[itemCount].productName, "Carrot"); }
            else if (*input_item == 2) { price = 2.1f; strcpy(viewCart[itemCount].productName, "Potato"); }
            else if (*input_item == 3) { price = 1.3f; strcpy(viewCart[itemCount].productName, "Peas"); }
            else if (*input_item == 4) { price = 2.4f; strcpy(viewCart[itemCount].productName, "Broccoli"); }
            else if (*input_item == 5) { price = 2.1f; strcpy(viewCart[itemCount].productName, "Spinach"); }
            else if (*input_item == 6) { price = 2.4f; strcpy(viewCart[itemCount].productName, "Cauliflower"); }
            else if (*input_item == 7) { price = 1.3f; strcpy(viewCart[itemCount].productName, "Celery"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 7:
            printf("1. Almonds----$2.6 per kg.\n");
            printf("2. Walnuts----$1.7 per kg.\n");
            printf("3. Sunflower Seeds----$2.3 per kg.\n");
            printf("4. Chia Seeds----$1.2 per kg.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 2.6f; strcpy(viewCart[itemCount].productName, "Almonds"); }
            else if (*input_item == 2) { price = 1.7f; strcpy(viewCart[itemCount].productName, "Walnuts"); }
            else if (*input_item == 3) { price = 2.3f; strcpy(viewCart[itemCount].productName, "Sunflower Seeds"); }
            else if (*input_item == 4) { price = 1.2f; strcpy(viewCart[itemCount].productName, "Chia Seeds"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        default:
            printf("\nInvalid sub-category.\n");
            return;
        }
        break;

    case 2:
        printf("\n----- Electronics -----\n");
        printf("1. Smartphone.\n");
        printf("2. Laptop.\n");
        printf("3. GPU.\n");
        scanf("%d", sub_category);

        switch (*sub_category)
        {
        case 1:
            printf("1. Apple iPhone----$1100.\n");
            printf("2. SAMSUNG----$900.\n");
            printf("3. Huawei----$470.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 1100.0f; strcpy(viewCart[itemCount].productName, "Apple iPhone"); }
            else if (*input_item == 2) { price = 900.0f; strcpy(viewCart[itemCount].productName, "SAMSUNG"); }
            else if (*input_item == 3) { price = 470.0f; strcpy(viewCart[itemCount].productName, "Huawei"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 2:
            printf("1. Apple Macbook Pro----$2600.\n");
            printf("2. Dell----$400.\n");
            printf("3. Lenovo----$740.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 2600.0f; strcpy(viewCart[itemCount].productName, "Apple Macbook Pro"); }
            else if (*input_item == 2) { price = 400.0f; strcpy(viewCart[itemCount].productName, "Dell"); }
            else if (*input_item == 3) { price = 740.0f; strcpy(viewCart[itemCount].productName, "Lenovo"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 3:
            printf("1. NVIDIA----$1600.\n");
            printf("2. AMD----$800.\n");
            printf("3. Intel ARC----$650.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 1600.0f; strcpy(viewCart[itemCount].productName, "NVIDIA"); }
            else if (*input_item == 2) { price = 800.0f; strcpy(viewCart[itemCount].productName, "AMD"); }
            else if (*input_item == 3) { price = 650.0f; strcpy(viewCart[itemCount].productName, "Intel ARC"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        default:
            printf("\nInvalid sub-category.\n");
            return;
        }
        break;

    case 3:
        printf("\n----- Stationery & Office Supplies -----\n");
        printf("1. Pen.\n");
        printf("2. Pencil.\n");
        printf("3. Notebook.\n");
        scanf("%d", sub_category);

        switch (*sub_category)
        {
        case 1:
            printf("1. Dollar Pen----$1.2.\n");
            printf("2. Signature Pen----$1.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 1.2f; strcpy(viewCart[itemCount].productName, "Dollar Pen"); }
            else if (*input_item == 2) { price = 1.0f; strcpy(viewCart[itemCount].productName, "Signature Pen"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 2:
            printf("1. Graphite Pencil----$0.2.\n");
            printf("2. Colored Pencil----$0.4.\n");
            printf("3. Mechanical Pencil----$3.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 0.2f; strcpy(viewCart[itemCount].productName, "Graphite Pencil"); }
            else if (*input_item == 2) { price = 0.4f; strcpy(viewCart[itemCount].productName, "Colored Pencil"); }
            else if (*input_item == 3) { price = 3.0f; strcpy(viewCart[itemCount].productName, "Mechanical Pencil"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        case 3:
            printf("1. Hardcover Notebook----$3.2.\n");
            printf("2. Pocket Notebook----$1.5.\n");
            printf("3. Leather Notebook----$4.\n");
            scanf("%d", input_item);

            if (*input_item == 1) { price = 3.2f; strcpy(viewCart[itemCount].productName, "Hardcover Notebook"); }
            else if (*input_item == 2) { price = 1.5f; strcpy(viewCart[itemCount].productName, "Pocket Notebook"); }
            else if (*input_item == 3) { price = 4.0f; strcpy(viewCart[itemCount].productName, "Leather Notebook"); }
            else { printf("\nInvalid value.\n"); return; }
            break;

        default:
            printf("\nInvalid sub-category.\n");
            return;
        }
        break;

    default:
        printf("\nInvalid category.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &qty);

    viewCart[itemCount].quantity = qty;
    viewCart[itemCount].price = price;
    *totalCost += viewCart[itemCount].price * viewCart[itemCount].quantity;

    printf("\nItem '%s' added to cart successfully.\n", viewCart[itemCount].productName);

    itemCount++;
}
