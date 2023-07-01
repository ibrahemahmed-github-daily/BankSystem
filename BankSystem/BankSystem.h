/* 
 * File:     BankSystem.h
 * Author:   Ibrahem Ahmed Ibrahem
 * https://www.linkedin.com/in/ibrahemahmedibrahem/
 * mecha.ibrahemahmed@gmail.com
 * Created on June 7, 2023
 */
#ifndef _BANKSYSTEM_H
#define _BANKSYSTEM_H


/* Section : Includes */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* Section : Macros Declarations */
#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
/*********************************/
#define CPU_TYPE (CPU_TYPE_32)
/*********************************/
#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;

typedef float float32;
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;

typedef float float32;
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;

typedef float float32;
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_8)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef float float32;

#endif
/***************************************/

/* Section : Macros Functions Declarations */


/* Section : Data Types Declarations */

struct Node {
    char name[10];
    float balance;
    int account_number;
    int pin;
    struct Node *NodeLink;
};

/* Section : Functions Declarations */
/**
 * @brief Function To creat new node by Admain
 * @param List
 * @return void  
 */
void CreatAccount(struct Node **List);
/**
 * @brief Function To remove node by Admain
 * @param List
 * @return void  
 */
void RemoveAccount(struct Node *List);
/**
 * @brief Function To Dispay all node by Admain
 * @param List
 * @return void  
 */
void DisplayAccountsData(struct Node *List);/**
 /**
 * @brief Function To Dispay user node
 * @param List
 * @return void  
 */
void DisplayUserData (struct Node *List,uint8 mode);
 /**
 * @brief Function To do operations on the balance of the user
 * @param List
 * @return void  
 */
void DepositMoney(struct Node *List, uint32 ID);
 /**
 * @brief Function To do operations on the balance of the user
 * @param List
 * @return void  
 */
void WithdrawMoney(struct Node *List, uint32 ID);
 /**
 * @brief Function To do operations on the pin of the user
 * @param List
 * @return void  
 */
void ChangePassword(struct Node *List, uint32 ID , uint32 PIN);

/*********************************/

struct Node User[100];
struct Node *ListHead = NULL;  
uint32 Accounts = 50;
uint32 Adminpassword = 123456;
uint32 AdminID = 2023999;
uint32 loginTrials = 3;
uint32 userChoice = 0 ;
uint8  mode;
uint32 userID = 0;
uint32 userPassword = 0;
#endif // _BANKSYSTEM_H
