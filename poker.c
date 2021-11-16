/** Poker.h
 * =========================================================== 
 * Name: Chanon Mallanoo
 * Section: M6
 * Project: Poker
 * Purpose: Create a simple video poker game
 
 **/

#include "pokerfunct.h"
int main()
{
    /*
    int* decks = NULL;
    decks = (int*)malloc(sizeof(int) * 52);
    for(int i=0; i<52; i++){
        decks[i] = 1;
    }
    */
    //printf("%d\n", decks[10]);
    
    vector deck;
    vector_create(&deck, 52);
    for(unsigned int i =0; i<52; i++){
        vector_insert(&deck, i, i);
        //printf("%d\n", *vector_at(&deck,i));
    }
    


    int bankroll = 3000;
    UpdateBankroll(&bankroll, -500);
    printf("Check Bank: %d \n", bankroll); //Test UpdateBankroll

    //Test checkCard51
    Card aCard = cardChecks(22);
    printf("CheckCard: %c %c %d\n", aCard.value, aCard.suite, aCard.trueValue);

    //Test sortedCard
    Card card1 = cardChecks(13);
    
    Card card2 = cardChecks(9);
    Card card3 = cardChecks(10);
    Card card4 = cardChecks(11);
    Card card5 = cardChecks(12);
    
    Card* cards= sortCard(card1, card2, card3, card4, card5);

    printf("Check Sort: %c %c, %c %c, %c %c, %c %c, %c %c\n" , cards[0].value, cards[0].suite, cards[1].value, cards[1].suite, cards[2].value, cards[2].suite, cards[3].value, cards[3].suite, cards[4].value, cards[4].suite);

    
    //Test Check hands
    int testCheckHand = checkHand(card1, card2, card3, card4, card5);
    printf("TestCheckHand: %d\n", testCheckHand);
    
    
    







}