/* 
 * File:     BankSystem.h
 * Author:   Ibrahem Ahmed Ibrahem
 * https://www.linkedin.com/in/ibrahemahmedibrahem/
 * mecha.ibrahemahmed@gmail.com
 * Created on June 7, 2023
 */

#include "BankSystem.h"

int main()
{
    
    
    // Initializing variables and data structures 
    for (int i=49; i>=0; i--) {
        sprintf(User[i].name, "User%d", i+1);   // Setting user name
        User[i].balance = 1000;                 // Setting initial balance
        User[i].account_number = 202301 + i;    // Setting account number
        User[i].pin = 201 + i;                  // Setting PIN
        User[i].NodeLink = ListHead;            // Assigning node link to the head of the list
        ListHead = &User[i];                    // Updating ListHead to point to the current user
        } 
    

    printf("==========================================\n");
    printf("================== Hello =================\n");
    printf("=========== Welcome in our Bank ==========\n");
    printf("==========================================\n");
    printf("1 -> Admin    : \n");
    printf("2 -> User : \n");
    printf("\nUser Choice : ");
    scanf("%d",&mode);                   
    Sleep(500);                                 // Pausing the program for 500 milliseconds
    system("cls");                              // Clearing the screen

    if (mode == 1){                             // Admin mode

    while (loginTrials>0){                      // Loop for login trials
    printf("Enter your Password : ");
    scanf("%d",&Adminpassword);
    printf("Enter your ID : ");
    scanf("%d",&AdminID);
    if (Adminpassword == 123456 && AdminID == 2023999 ){
                                                // Successful login
        printf("==========================================\n");
        printf("============== Hello Admin ===============\n");
        printf("========== Admin Interface Mode ==========\n");
        printf("==========================================\n");
        Sleep(1000);
        system("cls");
        break;
    }
    else {
        printf("Wrong ID or Passrword , try again!!\n");
        loginTrials--;  
        if (loginTrials == 0){
        printf("Sorry , Try Again later!! \n");
        printf("Quit from application \n");
        exit(1);}
        else {}
    }
}
    while(1)
    {                                              // Admin interface loop
        printf("==================================\n");
        printf("-> 1) Open New Client Account \n");
        printf("-> 2) Remove Client for the system \n");
        printf("-> 3) Display All Data \n");
        printf("-> 4) Display Account Data \n");
        printf("-> 5) Number of Accounts\n");
        printf("-> 6) Quit from application \n");
        printf("==================================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &userChoice);

        switch(userChoice)
        {
        case 1:
            CreatAccount(&ListHead);
            break;
        case 2:
            RemoveAccount(ListHead);
            break;
        case 3:
            DisplayAccountsData(ListHead);
            break;
        case 4:
            DisplayUserData(ListHead,mode);
        break;
        case 5:
            printf("Number of Accounts: %d\n",Accounts);
        break;
        case 6:
            printf("Quit from application \n");
            exit(1);                        // Exiting the program
            break;
        default:
            printf("Choice out of range !!\n");
            break;
        }
    }
}
    else if (mode == 2) {                             // User mode

    
    struct Node *currentUser = NULL;

    printf("Enter your Password: ");
    scanf("%d", &userPassword);
    printf("Enter your ID: ");
    scanf("%d", &userID);

    // Find the user with the provided ID
    currentUser = ListHead;
    while (currentUser != NULL) {
        if (currentUser->pin == userPassword && currentUser->account_number == userID) {
            break;
        }
        currentUser = currentUser->NodeLink;
    }

    if (currentUser != NULL) {                       // User menu
        
        printf("==========================================\n");
        printf("================ Hello User ===============\n");
        printf("============== User Interface =============\n");
        printf("==========================================\n");

        while (1) {
            printf("-> 1) Deposit Money\n");
            printf("-> 2) Withdraw Money\n");
            printf("-> 3) Change Password\n");
            printf("-> 4) Display Your Data\n");
            printf("-> 5) Quit from application\n");
            printf("\nUser Choice: ");
            scanf("%d", &userChoice);

            switch (userChoice) {
                case 1:
                    DepositMoney(currentUser,userID);
                    break;
                case 2:
                    WithdrawMoney(currentUser,userID);
                    break;
                case 3:
                    ChangePassword(currentUser,userID,userPassword);
                    break;
                case 4:
                    DisplayUserData(currentUser,mode);
                    break;
                case 5:
                    printf("Quit from application\n");
                    exit(1);
                default:
                    printf("Choice out of range!!\n");
                    break;
            }
        }
    } else {
        printf("Invalid ID or Password. Please try again later!\n");
    }
}

    else {printf("Invalid choice , please try again later !!\n");}
    return 0;
}


/**
 * @brief Function To Dispay all node by Admain
 * @param List
 * @return void  
 */
void DisplayAccountsData(struct Node *List) {
    struct Node *TempNode = List; 
    printf("Accounts Data:\n");
    if(NULL == TempNode)
    {
    printf("No Accounts on your DataBase !! \n");
    }
    else{
    while(TempNode != NULL)
    {
        printf("User Number: %s, Balance: %f, Account Number: %d,NodePtr: %p\n", TempNode->name, TempNode->balance, TempNode->account_number,TempNode->NodeLink);
        TempNode = TempNode->NodeLink;
        }
     } }

 /**
 * @brief Function To Dispay user node
 * @param List
 * @return void  
 */
void DisplayUserData(struct Node* List, uint8 mode)
{
    uint32 pin;
    uint32 ID;
    struct Node* currentNode = List;
    struct Node* TempNode = List;

    if (NULL == TempNode) {
        printf("Create New Account : \n");
        CreatAccount(&List);
    }
    else {
        system("cls");
        
        if (mode == 1) {
            printf("Enter Account Number: ");
            scanf("%d", &ID);
            if ((ID >= 202301) && (ID <= (202300 + Accounts))) {
                while (currentNode != NULL) {
                    if (currentNode->account_number == ID) {
                        system("cls");
                        printf("==========================================\n");
                        printf("================= Hello ==================\n");
                        printf("============= Account Details ============\n");
                        printf("==========================================\n");

                        printf("User Number: %s, Balance: %f, Account Number: %d\n", currentNode->name, currentNode->balance, currentNode->account_number);
                        break;
                    }
                    else {
                        /* No thing */
                    }
                    currentNode = currentNode->NodeLink;
                }
                if (currentNode == NULL) {
                    printf("Account not found.\n");
                }
                else {
                    /* No thing */
                }
            }
            else {
                printf("Invalid ID Number\n");
            }
        }
        else if (mode == 2) {
            while (currentNode != NULL) {
                    system("cls");
                    printf("==========================================\n");
                    printf("================= Hello ==================\n");
                    printf("============= Account Details ============\n");
                    printf("==========================================\n");

                    printf("User Number: %s, Balance: %f, Account Number: %d\n", currentNode->name, currentNode->balance, currentNode->account_number);
                    break;
                
                currentNode = currentNode->NodeLink;
            }
            if (currentNode == NULL) {
                printf("Account not found or invalid PIN.\n");
            }
        }
        else {
            printf("Invalid mode.\n");
        }
    }
}

/* Section : Functions Declarations */
/**
 * @brief Function To creat new node by Admain
 * @param List
 * @return void  
 */
void CreatAccount(struct Node** List)
{
    struct Node* TempNode = NULL;
    struct Node* LastNode = NULL;

    TempNode = (struct Node*)malloc(sizeof(struct Node));

    if (NULL != TempNode) {
        system("cls");

        printf("Enter your name: ");
        scanf("%s", TempNode->name);

        printf("Enter your account number: ");
        scanf("%d", &TempNode->account_number);

        printf("Enter User Balance: ");
        scanf("%f", &TempNode->balance);

        printf("Enter your PIN: ");
        scanf("%d", &TempNode->pin);
        Accounts++;

        TempNode->NodeLink = NULL;

        if (NULL == *List) /* Linked list is empty */
        {
            *List = TempNode;
            ListHead = TempNode; /* set the first node to be the head of the list */
        }
        else /* Linked list is not empty */
        {
            LastNode = *List;
            while (LastNode->NodeLink != NULL) {
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = TempNode;
            ListHead = *List; /* reset the ListHead to the first node */
        }
    }
    else {
        /* No thing */
    }
}


/**
 * @brief Function To remove node by Admain
 * @param List
 * @return void  
 */
void RemoveAccount(struct Node *List) {
    uint32 NodePosition;
    printf("Enter Account Number: ");
    scanf("%i", &NodePosition);

    struct Node *currentNode = List;
    struct Node *prevNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->account_number == NodePosition) {
            if (prevNode == NULL) {
                List = currentNode->NodeLink; // Update the head of the list
            } else {
                prevNode->NodeLink = currentNode->NodeLink;
            }
            Accounts--;
            free(currentNode);
            printf("Account removed successfully.\n");
            
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->NodeLink;
    }

    printf("Account not found.\n");
    
}

 /**
 * @brief Function To do operations on the balance of the user
 * @param List
 * @return void  
 */
void DepositMoney(struct Node *List , uint32 ID){
    float AmountOfMoney;
    struct Node* currentNode = List;
    printf("How much Money do you want to desposit?\n");
    printf("Enter the money $ :");
    scanf("%f",&AmountOfMoney);
     while (currentNode != NULL) {
        if (currentNode->account_number == ID) { 
          currentNode->balance = (float)(currentNode->balance) + AmountOfMoney;
           printf("You have charged your balance with : %0.3f$\n",AmountOfMoney);
           printf("Your current balance is : %0.3f$\n",currentNode->balance);
           break;
        }
        
        break;
        currentNode = currentNode->NodeLink;
     } 
}

 /**
 * @brief Function To do operations on the balance of the user
 * @param List
 * @return void  
 */
void WithdrawMoney(struct Node *List, uint32 ID){
    float AmountOfMoney;
    struct Node* currentNode = List;
    printf("How much Money do you want to withdraw?\n");
    printf("Enter the money $ :");
    scanf("%f",&AmountOfMoney);
    while (currentNode != NULL) {
        if (currentNode->account_number == ID) { 
           currentNode->balance = (float)(currentNode->balance) - AmountOfMoney;
           printf("You have withdrew from balance by : %0.3f$\n",AmountOfMoney);
           printf("Your current balance is : %0.3f$\n",currentNode->balance);
           break;
        }
        
        currentNode = currentNode->NodeLink;
     }
}

 /**
 * @brief Function To do operations on the pin of the user
 * @param List
 * @return void  
 */
void ChangePassword(struct Node *List, uint32 ID , uint32 PIN){
    uint32 OldPassword;
    uint32 NewPassword;
    struct Node* currentNode = List;
    printf("Enter Your Old PAssword: ");
    scanf("%d",&OldPassword);
    if (OldPassword != PIN){
        printf("Wrong Password , Try again");
    }
    else {
        printf("Enter Your New PAssword: ");
        scanf("%d",&NewPassword);
        while (currentNode != NULL) {
            if (currentNode->account_number == ID && currentNode->pin == OldPassword ) { 
            currentNode->pin = NewPassword;
            break;
            }
            
            currentNode = currentNode->NodeLink;
        }
        printf("You changed your password successfully!!\n");}
        }

