/** Poker.h
 * =========================================================== 
 * Name: Chanon Mallanoo
 * Section: M6
 * Project: Poker
 * Purpose: Create a simple video poker game
 
 **/

#include "pokerfunct.h"

Card cardChecks(int card)
{
    Card temp;
    int value = card % 13;
    if (value == 0)
    {
        temp.value = 'A';
    }
    else if (value == 10)
    {
        temp.value = 'J';
    }
    else if (value == 11)
    {
        temp.value = 'Q';
    }
    else if (value == 12)
    {
        temp.value = 'K';
    }
    else if (value == 9)
    {
        temp.value = 'T'; //Ten
    }
    else
    {
        temp.value = value + 49;
    }
    int suite = card / 13;
    if (suite == 0)
    {
        temp.suite = 'S';
    }
    else if (suite == 1)
    {
        temp.suite = 'H';
    }
    else if (suite == 2)
    {
        temp.suite = 'D';
    }
    else
    {
        temp.suite = 'C';
    }
    temp.trueValue = (card % 13) + 1;
    return temp;
}

Card *sortCard(Card card1, Card card2, Card card3, Card card4, Card card5)
{
    int arrays[5] = {card1.trueValue, card2.trueValue, card3.trueValue, card4.trueValue, card5.trueValue};
    Card Carrays[5] = {card1, card2, card3, card4, card5};
    Card *Sorted;
    Sorted = (Card *)malloc(5 * sizeof(Card));
    for (int a = 0; a < 5; a++)
    {
        int minVal = 999;
        int minIndex = 0;
        for (int i = 0; i < 5; i++)
        {
            if (arrays[i] < minVal)
            {
                minVal = arrays[i];
                minIndex = i;
            }
        }
        Sorted[a] = Carrays[minIndex];
        arrays[minIndex] = 9999;
    }
    return Sorted;
}

int checkHand(Card card1, Card card2, Card card3, Card card4, Card card5)
{
    //Check for Royal Flush
    Card* royalFlush = sortCard(card1, card2, card3, card4, card5);
    if((royalFlush[0].trueValue == 1) && (royalFlush[1].trueValue == 10) && (royalFlush[2].trueValue == 11) && (royalFlush[3].trueValue == 12) && (royalFlush[4].trueValue == 13)){
        if ((card1.suite == card2.suite) && (card1.suite == card3.suite) && (card1.suite == card4.suite) && (card1.suite == card5.suite)){
            return 99; //RoyalFlush
        }
        else{
            return 98; //Royal Straight
        }
    }
    //Set up for Flush and Straight
    Card *straightCheckArray = NULL;
    straightCheckArray = (Card *)malloc(5 * sizeof(Card));
    straightCheckArray = sortCard(card1, card2, card3, card4, card5);
    for (int i = 1; i < 5; i++)
    {
        straightCheckArray[i].trueValue -= i;
    }
    int collecter = 0;
    //Check for flush
    if ((card1.suite == card2.suite) && (card1.suite == card3.suite) && (card1.suite == card4.suite) && (card1.suite == card5.suite))
    {
        collecter += 1;
    }
    //Check for straight (Cards are already sorted in order from low value to high value before inputing into this function)

    if ((straightCheckArray[0].trueValue == straightCheckArray[1].trueValue) && (straightCheckArray[0].trueValue == straightCheckArray[2].trueValue) && (straightCheckArray[0].trueValue == straightCheckArray[3].trueValue) && (straightCheckArray[0].trueValue == straightCheckArray[4].trueValue))
    {
        collecter += 2;
    }
    if (collecter > 0)
    {
        return collecter; //1 for Flush 2 for straight 3 for straight flush
    }

    //Check for Four of kinds===================
    Card *FourOfKindCheckArray = sortCard(card1, card2, card3, card4, card5);
    int counter = 0;

    for (int i = 0; i < 3; i++)
    {
        if (FourOfKindCheckArray[i].trueValue == FourOfKindCheckArray[i + 1].trueValue)
        {
            counter++;
        }
    }

    if (counter == 3)
    {
        return 4; //4 for four of kinds
    }
    else
    {
        counter = 0;
    }

    for (int i = 1; i < 4; i++)
    {
        if (FourOfKindCheckArray[i].trueValue == FourOfKindCheckArray[i + 1].trueValue)
        {
            counter++;
        }
    }

    if (counter == 3)
    {
        return 4; //4 for four of kinds
    }
    else
    {
        counter = 0;
    }
    
    

    //Check for three of a kind=================
    Card *ThreeOfKindCheckArray = sortCard(card1, card2, card3, card4, card5);
    counter = 0;
    for (int i = 0; i < 2; i++)
    {
        if (ThreeOfKindCheckArray[i].trueValue == ThreeOfKindCheckArray[i + 1].trueValue)
        {
            counter++;
        }
    }

    if ((counter == 2) && (ThreeOfKindCheckArray[3].trueValue == ThreeOfKindCheckArray[4].trueValue))
    {
        return 5; // Full House
    }
    else if (counter == 2)
    {
        return 6; //Three of kinds
    }else{
        counter = 0;
    }

    for (int i = 1; i < 3; i++)
    {
        if (ThreeOfKindCheckArray[i].trueValue == ThreeOfKindCheckArray[i + 1].trueValue)
        {
            counter++;
        }
    }
    if(counter == 2){
        return 6;// Three of kinds
    }else{
        counter = 0;
    }

    for (int i = 2; i < 4; i++)
    {
        if (ThreeOfKindCheckArray[i].trueValue == ThreeOfKindCheckArray[i + 1].trueValue)
        {
            counter++;
        }
    }
    if ((counter == 2) && (ThreeOfKindCheckArray[0].trueValue == ThreeOfKindCheckArray[1].trueValue))
    {
        return 5; // Full House
    }
    else if (counter == 2)
    {
        return 6; //Three of kinds
    }else{
        counter = 0;
    }

    //Check for pairs
    int numPairs = 0;
    Card* pairsCheckArray = sortCard(card1, card2, card3, card4, card5);
    for(int i=0; i<4; i++){
        if (pairsCheckArray[i].trueValue == pairsCheckArray[i + 1].trueValue)
        {
            numPairs++;
        }
    }
    switch (numPairs)
    {
    case 1:
        return 7; //7 for one pair
        break;
    case 2:
        return 8; //8 for two pairs
        break;
    default:
        break;
    }

    //Check for a High card
    if(pairsCheckArray[4].trueValue >= 11 || pairsCheckArray[4].trueValue == 0){
        return 9;//Jack or higher
    }else{
        return 10;//Lower than Jack
    }
}

void UpdateBankroll(int *bankroll, int amount)
{
    *bankroll += amount;
}

int deal(int decks[])
{
    //random a card
    //update the deck
    //return the drawn card note that 0 represents an Ace
    return -1; //This is just a test
}

void addScore(int card, int *value)
{
    //update score from card's value
    //Ace is 11 by default unless the total value exceeds 21, which makes its value become 1
    //This function is
}

void storeData(char filename[], Player playerName)
{
    FILE *outFile = fopen(filename, "a");
    fprintf(outFile, "Name: %s\nAge: %d\nBankroll: %d\nTurnsPlayed: %d\nResult: %d\n", playerName.names, playerName.age, playerName.bankroll, playerName.turnsPlayed, playerName.result);
}

void vector_create(vector *v, unsigned int vectorSize)
{
    int i;

    if (v == NULL)
        return;

    v->elements = (int *)malloc(vectorSize * sizeof(int));
    ;
    v->size = vectorSize;
    for (i = 0; i < v->size; ++i)
    {
        v->elements[i] = 0;
    }
}

void vector_destroy(vector *v)
{
    if (v == NULL)
        return;

    free(v->elements);
    v->elements = NULL;
    v->size = 0;
}

void vector_resize(vector *v, unsigned int vectorSize)
{
    int oldSize;
    int i;

    if (v == NULL)
        return;

    oldSize = v->size;
    v->elements = (int *)realloc(v->elements, vectorSize * sizeof(int));
    v->size = vectorSize;
    for (i = oldSize; i < v->size; ++i)
    {
        v->elements[i] = 0;
    }
}

int *vector_at(vector *v, unsigned int index)
{
    if (v == NULL || index >= v->size)
        return NULL;

    return &(v->elements[index]);
}

void vector_insert(vector *v, unsigned int index, int value)
{
    int i;

    if (v == NULL || index > v->size)
        return;

    vector_resize(v, v->size + 1);
    for (i = v->size - 1; i > index; --i)
    {
        v->elements[i] = v->elements[i - 1];
    }
    v->elements[index] = value;
}

void vector_push_back(vector *v, int value)
{
    vector_insert(v, v->size, value);
}

void vector_erase(vector *v, unsigned int index)
{
    int i;

    if (v == NULL || index >= v->size)
        return;

    for (i = index; i < v->size - 1; ++i)
    {
        v->elements[i] = v->elements[i + 1];
    }
    vector_resize(v, v->size - 1);
}

int vector_size(vector *v)
{
    if (v == NULL)
        return -1;

    return v->size;
}