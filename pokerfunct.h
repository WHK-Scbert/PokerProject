/** Poker.h
 * =========================================================== 
 * Name: Chanon Mallanoo
 * Section: T1
 * Project: Video Poker
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
#include <unistd.h>
// struct and typedef declaration for Vector ADT
typedef struct vector_struct {
    int* elements;
    unsigned int size;
} vector;

typedef struct 
{
    char value;
    char suite;
    char suiteSpellOut[10];
    int trueValue;
}Card;

/** ----------------------------------------------------------
 * cardChecks() - convert card code to an actual card
 * @param card is an integer refering to a card code
 * return a card Struct
 * ----------------------------------------------------------
 */
Card cardChecks(int card); //Make a card code becomes a card

/** ----------------------------------------------------------
 * UpdateBankroll() - Update money
 * @param bankroll is an integer pointer to a variable keeping track of money
 * @param amount is an integer telling how much money to add or subtract
 * ----------------------------------------------------------
 */
void UpdateBankroll(int* bankroll, int amount); 

/** ----------------------------------------------------------
 * deal() - Random a card
 * @param decks is a vector pointer to the current deck
 * @param deckSize is an integer pointer to the current deckSize
 * return a random card code
 * ----------------------------------------------------------
 */
int deal(vector* decks, int* deckSize);

/** ----------------------------------------------------------
 * realDealCard() - Actually deal a card from deal()
 * @param decks is a vector pointer to the current deck
 * @param deckSize is an integer pointer to the current deckSize
 * return a dealt card
 * ----------------------------------------------------------
 */
Card realDealCard(vector *deck, int *deckSize); //Deal and get rid of the dealt card from the deck
typedef struct 
{
    int memberNumber;
    char names[20];
    int age;
    int balance;
    int points;

}Player;


/** ----------------------------------------------------------
 * sortCard() - sort cards in numeric values
 * @param card1-5 - a card struct that has all info about a card
 * return Sorted card array
 * ----------------------------------------------------------
 */
Card* sortCard(Card card1, Card card2,Card card3,Card card4,Card card5);

/** ----------------------------------------------------------
 * checkHand() - check a poker hand (e.g. Royal FLush, Flush, ...)
 * @param card1-5 - a card struct that has all info about a card
 * return poker hand code
 * ----------------------------------------------------------
 */
int checkHand(Card card1, Card card2,Card card3,Card card4,Card card5); // return hand rank

/** ----------------------------------------------------------
 * printHandRank() - print hand rank
 * @param handrank - a hand rank code from checkHand
 * ----------------------------------------------------------
 */
void printHandRank(int handRank); //Print whether the player get pairs/ twopairs/ Straight ...

/** ----------------------------------------------------------
 * checkPayOut() - return how much do we have to pay a player for getting a specific hand
 * @param handrank - a hand rank code from checkHand
 * @param bet is a bet size of each round to be multiplied by payout rate
 * ----------------------------------------------------------
 */
int checkPayout(int handRank, int bet); //Payout rate according to Las Vegas Strip

/** ----------------------------------------------------------
 * CheckRecord() - return true if the player is already in the database
 * @param filename is filename
 * @param MemberNumber is number to be checked against the database
 * @param playerJ is a pointer to a Player struct that tries to play
 * ----------------------------------------------------------
 */
bool CheckRecord(char filename[], int MemberNumber, Player* playerJ);

//Player pullPlayer(int number); Might add this function if our functions are not working well enough

/** ----------------------------------------------------------
 * registerPlayer() - register a new player to the database
 * @param filename is filename
 * @param player is a player struct to be added into the database
 * ----------------------------------------------------------
 */
void registerPlayer(char filename[], Player player);

/** ----------------------------------------------------------
 * updateBalance() - Update balance into the database
 * @param filename is a filename of the database
 * @param newBalance is a new balance to be updated
 * @param playerJ is a pointer to a PLayer Struct that we want to update his balance
 * ----------------------------------------------------------
 */
void updateBalance(char filename[], int newBalance, Player* playerJ);

/** ----------------------------------------------------------
 * RunSim() - Run the simluation until we get a specific hand
 * @param handrank is handrank that we want to get
 * @param deck is a pointer to a vector deck
 * @param deckSize is a deckSize to start with default 52
 * @param turnPlayed is how many times the simulation has been run
 * ----------------------------------------------------------
 */
void RunSim(int handRank, vector* deck, int deckSize, int turnPlayed);





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
