/** Poker.h
 * =========================================================== 
 * Name: Chanon Mallanoo
 * Section: M6
 * Project: Poker
 * Purpose: Create a simple video poker game
 
 **/
#ifndef pokerfunct
#define pokerfunct

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct 
{
    char value;
    char suite;
    int trueValue;
}Card;

Card cardChecks(int card);
void UpdateBankroll(int* bankroll, int amount); 
int deal(int decks[]);
void addScore(int card, int* value);
typedef struct blackjackfuncts
{
    char names[20];
    int age;
    int bankroll;
    int turnsPlayed;
    int result; //Loss or gain in total

}Player;

void switchValue(Card Card);

Card* sortCard(Card card1, Card card2,Card card3,Card card4,Card card5);

int checkHand(Card card1, Card card2,Card card3,Card card4,Card card5); // return hand rank

void Record(char filename[], Player playerName);

int checkPayout(int computerScore, int playerScore);


//recursion with base case: computer got >=17



























// struct and typedef declaration for Vector ADT
typedef struct vector_struct {
    int* elements;
    unsigned int size;
} vector;

/** ----------------------------------------------------------
 * vector_create() - initialize vector with specified size
 * @param v is a pointer to a struct of type vector
 * @param vectorSize is the size of the vector to initialize
 * ----------------------------------------------------------
 */
void vector_create(vector* v, unsigned int vectorSize);

/** ----------------------------------------------------------
 * vector_destroy() - destroy the vector pointed to by v
 * @param v is a pointer to a struct of type vector
 * ----------------------------------------------------------
 */
void vector_destroy(vector* v);

/** ----------------------------------------------------------
 * vector_resize() - resize an existing vector
 * @param v is a pointer to a struct of type vector
 * @param vectorSize is the size of the new vector
 * ----------------------------------------------------------
 */
void vector_resize(vector* v, unsigned int vectorSize);

/** ----------------------------------------------------------
 * vector_at() - determine the address of a specific element
 * @param v is a pointer to a struct of type vector
 * @param index specified vector element
 * @return int* a pointer to the location of the specified element
 * ----------------------------------------------------------
 */
int* vector_at(vector* v, unsigned int index);

/** ----------------------------------------------------------
 * vector_insert() - insert a value at a specified index
 * @param v is a pointer to a struct of type vector
 * @param index is the location to insert the new value
 * @param value the new value to insert into the vector
 * ----------------------------------------------------------
 */
void vector_insert(vector* v, unsigned int index, int value);

/** ----------------------------------------------------------
 * vector_push_back() - insert new value at the end of the vector
 * @param v is a pointer to a struct of type vector
 * @param value new value to insert at the end of the vector
 * ----------------------------------------------------------
 */
void vector_push_back(vector* v, int value);

/** ----------------------------------------------------------
 * vector_erase() - iremove value from specified index
 * @param v is a pointer to a struct of type vector
 * @param index location in vector to remove value
 * ----------------------------------------------------------
 */
void vector_erase(vector* v, unsigned int index);

/** ----------------------------------------------------------
 * vector_size() - return number of elements in vector
 * @param v is a pointer to a struct of type vector
 * @return number of elements in vector
 * ----------------------------------------------------------
 */
int vector_size(vector* v);

#endif