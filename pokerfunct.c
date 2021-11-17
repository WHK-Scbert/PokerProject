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
        strcpy(temp.suiteSpellOut, "Spades");
    }
    else if (suite == 1)
    {
        temp.suite = 'H';
        strcpy(temp.suiteSpellOut, "Hearts");
    }
    else if (suite == 2)
    {
        temp.suite = 'D';
        strcpy(temp.suiteSpellOut, "Diamonds");
    }
    else
    {
        temp.suite = 'C';
        strcpy(temp.suiteSpellOut, "Clubs");
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
    Card *royalFlush = sortCard(card1, card2, card3, card4, card5);
    if ((royalFlush[0].trueValue == 1) && (royalFlush[1].trueValue == 10) && (royalFlush[2].trueValue == 11) && (royalFlush[3].trueValue == 12) && (royalFlush[4].trueValue == 13))
    {
        if ((card1.suite == card2.suite) && (card1.suite == card3.suite) && (card1.suite == card4.suite) && (card1.suite == card5.suite))
        {
            return 99; //RoyalFlush
        }
        else
        {
            return 2; //Royal Straight
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
    }
    else
    {
        counter = 0;
    }

    for (int i = 1; i < 3; i++)
    {
        if (ThreeOfKindCheckArray[i].trueValue == ThreeOfKindCheckArray[i + 1].trueValue)
        {
            counter++;
        }
    }
    if (counter == 2)
    {
        return 6; // Three of kinds
    }
    else
    {
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
    }
    else
    {
        counter = 0;
    }

    //Check for pairs
    int numPairs = 0;
    Card *pairsCheckArray = sortCard(card1, card2, card3, card4, card5);
    for (int i = 0; i < 4; i++)
    {
        if (pairsCheckArray[i].trueValue == pairsCheckArray[i + 1].trueValue)
        {
            numPairs++;
        }
    }
    if (numPairs == 2)
    {
        return 8;
    }
    else if (numPairs == 1)
    {
        bool isJack = false;
        for (int i = 0; i < 4; i++)
        {
            if (pairsCheckArray[i].trueValue == pairsCheckArray[i + 1].trueValue)
            {
                if (pairsCheckArray[i].trueValue >= 10)
                {
                    isJack = true;
                }
            }
        }
        if (isJack)
        {
            return 9;
        }
        else
        {
            return 7;
        }
    }

    return 10;
    /*
    //Check for a High card
    if(pairsCheckArray[4].trueValue >= 11 || pairsCheckArray[4].trueValue == 0){
        return 9;//Jack or higher
    }else{
        return 10;//Lower than Jack
    }
    */
}

void UpdateBankroll(int *bankroll, int amount)
{
    *bankroll += amount;
}

void printHandRank(int handRank)
{
    switch (handRank)
    {
    case 99:
        printf("Royal Flush !!!");
        break;
    case 98:
        printf("Royal Straight !!!");
        break;
    case 1:
        printf("Flush");
        break;
    case 2:
        printf("Straight");
        break;
    case 3:
        printf("Straight Flush");
        break;
    case 4:
        printf("Four of a kind");
        break;
    case 5:
        printf("Full House");
        break;
    case 6:
        printf("Three of a kind");
        break;
    case 7:
        printf("One pair");
        break;
    case 8:
        printf("Two pair");
        break;
    case 9:
        printf("Jack or higher");
        break;
    case 10:
        printf("Junk");
        break;
    }
    printf("\n");
}

int checkPayout(int handRank, int bet)
{
    switch (handRank)
    {
    case 99:
        return 251 * bet;
        break;
    case 1:
        return 7 * bet;
        break;
    case 2:
        return 5 * bet;
        break;
    case 3:
        return 51 * bet;
        break;
    case 4:
        return 26 * bet;
        break;
    case 5:
        return 10 * bet;
        break;
    case 6:
        return 4 * bet;
        break;
    case 7:
        return 0;
        break;
    case 8:
        return 2 * bet;
        break;
    case 9:
        return 1 * bet;
        break;

    default:
        return 0;
        break;
    }
}

int deal(vector *decks, int *deckSize)
{
    //random a card

    int card = rand() % *deckSize;

    //update the deck
    //printf("%d\n", *vector_at(decks,card));
    //vector_erase(decks, card);
    //printf("%d\n", *vector_at(decks,card));
    *deckSize -= 1;

    return card;
}

Card realDealCard(vector *deck, int *deckSize)
{
    int card = deal(deck, deckSize);
    int test = *vector_at(deck, card);
    vector_erase(deck, card);
    //printf("Test deal: %d\n", test);
    Card tester = cardChecks(test);
    //printf("Card: %c %c \n", tester.value, tester.suite);
    return tester;
}

bool CheckRecord(char filename[], int MemberNumber);

int registerPlayer(char filename[], Player player);

void RunSim(int handRank, vector* deck, int* deckSize, int turnPlayed)
{
    Card *cards;
    cards = (Card *)malloc(5 * sizeof(Card));
    for (int i = 0; i < 5; i++)
    {
        //int dealingCard = deal(&deck, &deckSize);
        //cards[i] = cardChecks(dealingCard);
        cards[i] = realDealCard(deck, deckSize);
    }
    printf("Hand %d: %c %s, %c %s, %c %s, %c %s, %c %s\n", turnPlayed, cards[0].value, cards[0].suiteSpellOut, cards[1].value, cards[1].suiteSpellOut, cards[2].value, cards[2].suiteSpellOut, cards[3].value, cards[3].suiteSpellOut, cards[4].value, cards[4].suiteSpellOut);
    if(handRank == checkHand(cards[0], cards[1], cards[2], cards[3], cards[4])) //base case
    {
        printf("It takes %d rounds to get a ", turnPlayed);
        printHandRank(handRank);
    }else{
        
        vector_resize(deck, 0);
        *deckSize = 52;
        for (unsigned int i = 0; i < 52; i++)
        {
            vector_insert(deck, i, i);
            //printf("%d\n", *vector_at(&deck,i));
        }
        RunSim(handRank,deck,deckSize,turnPlayed+1);
    }
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