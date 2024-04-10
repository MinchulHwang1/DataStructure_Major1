///*
//* FILE : f2.cpp
//* PROJECT : Focused 2
//* PROGRAMMER : Minchul Hwang
//* FIRST VERSION : 2023-01-16
//* Description : This project originates from focused 1.
//				From focused 1, the function has a condition that can be changed.
//				The user's input can be received indefinitely, and if a . is entered at any position,
//				the input is terminated and the data received up to the previous time is output.
//				Dynamic allocation is included in the information received and the information stored in the structure.
//* The functions in this file are used to struct - createNewNode(), fillFlightInfo(), printFlightInfo(), struct - deleteAllNode(), and clearNewLine()
//*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#include<string.h>
//
//#define kDestinationString 30
//#define kDateSting 30
//#define kContinue 1
//#define kTable 72
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//
//
//typedef struct FlightInfo {
//	char destination[kDestinationString];
//	char date[kDateSting];
//	float fare;
//	struct FlightInfo* next;
//} node;
//
//node* createFareNode(node* newHead);
//node* sortDestinationNode(node* newHead);
//int fillFlightInfo(node* pFlight);
//void printFlightInfo(node* arrFlight);
//node* deleteAllNode(node* head);
//void clearLine(char* string);
//int getFloat(float* pNumber);
//
//int main() {
//
//
//	node* flight_fare = NULL;
//	node* flight_destination = NULL;
//	flight_fare = createFareNode(flight_fare);
//	//printFlightInfo(flight_fare);
//	flight_destination = sortDestinationNode(flight_fare);
//
//	//printFlightInfo(flight_fare);
//	printFlightInfo(flight_destination);
//	flight_fare = deleteAllNode(flight_fare);
//
//	return 0;
//}
//
//
///*
//* Function : struct - createNewNode()
//* Description : This function is a function that creates a new structure node.
//*				Nodes can be created indefinitely, as many times as the user wishes.
//* Parameters : node* newHead : This is a head pointer created whenever a new node is created.
//* Returns : newHead - Pointer to the first node created among the created nodes.
//*/
//node* createFareNode(node* newHead) {
//	while (kContinue) {
//		node* allocFlightInfo = NULL;
//		node* fareTail = NULL;
//		node* fareHead = NULL;
//		int checkPoint = 0;											//checking value which insert is '.'
//		allocFlightInfo = (node*)malloc(sizeof(node));				//create new node and allocation of memory
//
//		if (allocFlightInfo == NULL) {
//			printf("No allocated memory\n");
//			return newHead;
//		}
//
//		checkPoint = fillFlightInfo(allocFlightInfo);
//
//		//Node check
//		if (newHead == NULL)
//		{
//			newHead = allocFlightInfo;
//		}
//		else if (newHead->fare >= allocFlightInfo->fare) {
//			allocFlightInfo->next = newHead;
//			newHead = allocFlightInfo;
//		}
//		else {
//			fareHead = newHead;
//			fareTail = newHead->next;
//
//			while (fareTail != NULL) {
//				if (fareTail->fare >= allocFlightInfo->fare) {
//					break;
//				}
//				fareHead = fareTail;
//				fareTail = fareTail->next;
//
//			}
//			allocFlightInfo->next = fareTail;
//			fareHead->next = allocFlightInfo;
//		}
//
//		if (checkPoint == 1) {					//break when '.' has been inserted
//			break;
//		}
//	}
//
//	return newHead;
//}
//
//node* sortDestinationNode(node* newHead) {
//	node* sortDestination = NULL;
//	node* desHead = NULL;
//	node* desTail = NULL;
//	desHead = sortDestination = newHead;
//	desTail = desHead->next;
//	sortDestination = (node*)malloc(sizeof(node));
//
//	if (sortDestination == NULL) {
//		printf("No allocated memory\n");
//		return newHead;
//	}
//
//	if (desHead > desTail) {
//		sortDestination = newHead;
//		while (desTail->next = NULL) {
//			sortDestination = desHead;
//			desHead = desTail;
//			desTail->next = sortDestination;
//			sortDestination = sortDestination->next;
//
//		}
//	}
//
//	newHead = sortDestination;
//	return newHead;
//}
//
///*
//* Function : fillFlightInfo()
//* Description : This function receives data from the user and stores them in the created node structure.
//* Parameters : node* pFlight - Node pointer created by createNewNode
//* Returns : None
//*/
//int fillFlightInfo(node* pFlight) {
//
//	printf("Please Input destination : ");
//	fgets(pFlight->destination, sizeof(pFlight->destination), stdin);
//	clearLine(pFlight->destination);
//
//	if (strcmp(pFlight->destination, ".") == NULL) {
//		pFlight = NULL;
//		return 1;
//	}
//
//	printf("Please Input Flight date : ");
//	fgets(pFlight->date, sizeof(pFlight->date), stdin);
//	clearLine(pFlight->date);
//
//	if (strcmp(pFlight->date, ".") == NULL) {
//		pFlight = NULL;
//		return 1;
//	}
//
//	float getFare = 0.00;
//	printf("Please Input Flight fare : ");
//	getFloat(&getFare);
//	pFlight->fare = getFare;
//
//	pFlight->next = NULL;				//empty next structure
//	return 0;
//}
//
//
///*
//* Function : printFlightInfo()
//* Description : This function outputs the data stored in the structure.
//* Parameters : FlightInfo arrFlight[] : A structure that stores data values ​​entered by the user.
//* Returns : None
//*/
//void printFlightInfo(node* arrFlight) {
//	int i = 0;
//	char table[kTable] = {};
//
//	table[0] = ' ';
//	printf("\n");
//	printf("\n");
//
//	for (i = 1; i < kTable; i++)
//		table[i] = '-';
//	for (i = 0; i < kTable; i++)
//		printf("%c", table[i]);
//	printf("\n");
//
//	printf("%c%44s", '|', "Flight Schedule");
//	printf("%28c\n", '|');
//
//	for (i = 0; i < kTable; i++)
//		printf("%c", table[i]);
//	printf("\n");
//
//	printf("%c%25s%11c", '|', "* Destination *", '|');
//	printf("%21s%15c\n", "* Date *", '|');
//
//	for (i = 0; i < kTable; i++)
//		printf("%c", table[i]);
//	printf("\n");
//
//	node* ptr = arrFlight;
//	ptr = ptr->next;
//	arrFlight = ptr;
//
//	while (arrFlight != NULL) {
//
//		printf("|%-35s", arrFlight->destination);
//		printf("    %0.2f   ", arrFlight->fare);
//		printf("|%-35s|\n", arrFlight->date);
//		arrFlight = arrFlight->next;
//
//	}
//
//	for (i = 0; i < kTable; i++)
//		printf("%c", table[i]);
//	printf("\n");
//}
//
//
///*
//* Function : clearNewLine()
//* Description : If the received data is blank or contains \n, it is removed.
//*				In focused1, I cut \n right away from the accepted data, but in this assignment, it was impossible, so I got it from practice.
//* Parameters : char* str - the pointer has string from user
//* Returns : None
//*/
//void clearLine(char* string) {
//	char* searchNewLine = strchr(string, '\n');
//	if (searchNewLine != NULL)
//	{
//		*searchNewLine = '\0';
//	}
//}
//
//
///*
//* Function : struct - deleteAllNode()
//* Description : This function deletes all created node structures.
//* Parameters : node* head - Address of the first node in the created node structure
//* Returns : NULL
//*/
//node* deleteAllNode(node* head) {
//	node* curNode = NULL;
//	node* ptr = head;
//
//	while (ptr != NULL) {
//		curNode = ptr;
//		ptr = ptr->next;
//		free(curNode);
//	}
//	return NULL;
//}
//
//int getFloat(float* pNumber)
//{
//	/* the array is 121 bytes in size; we'll see in a later lecture how we can improve this code */
//	char record[121] = { 0 }; /* record stores the string */
//	int number = 0;
//
//	/* use fgets() to get a string from the keyboard */
//	fgets(record, 121, stdin);
//	/* extract the number from the string; sscanf() returns a number
//	* corresponding with the number of items it found in the string */
//
//	if (sscanf(record, "%f", pNumber) != 1)
//	{
//		/* if the user did not enter a number recognizable by
//		* the system, set number to 0 */
//		number = 0;
//	}
//
//	return number;
//}
