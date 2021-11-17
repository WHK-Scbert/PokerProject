/** Poker.h
 * =========================================================== 
 * Name: Chanon Mallanoo
 * Section: T1
 * Project: Video Poker
 * Purpose: Create a simple video poker game
 
 **/

#include "pokerfunct.h"
int main()
{
    srand(time(NULL));
    /*
    int* decks = NULL;
    decks = (int*)malloc(sizeof(int) * 52);
    for(int i=0; i<52; i++){
        decks[i] = 1;
    }
    
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
    Card card1 = cardChecks(0);
    
    Card card2 = cardChecks(3);
    Card card3 = cardChecks(10);
    Card card4 = cardChecks(23);
    Card card5 = cardChecks(27);
    
    Card* cards= sortCard(card1, card2, card3, card4, card5);

    printf("Check Sort: %c %c, %c %c, %c %c, %c %c, %c %c\n" , cards[0].value, cards[0].suite, cards[1].value, cards[1].suite, cards[2].value, cards[2].suite, cards[3].value, cards[3].suite, cards[4].value, cards[4].suite);

    
    //Test Check hands
    int testCheckHand = checkHand(card1, card2, card3, card4, card5);
    printf("TestCheckHand: %d\n", testCheckHand);
    
    //Test Print Hand

    printf("TestPrintHandRank: ");
    printHandRank(testCheckHand);
    printf("\n");

    //Test CheckPayOut

    printf("TestCheckPayOut: %d\n", checkPayout(testCheckHand,50));
    
    */

    vector deck;
    vector_create(&deck, 0);
    int deckSize = 52;
    for (unsigned int i = 0; i < 52; i++)
    {
        vector_insert(&deck, i, i);
        //printf("%d\n", *vector_at(&deck,i));
    }
    /*
    printf("*****Welcome to USAFA Video Poker*****\n");
    printf("Please Enter Your Cadet Reward Number: \n");
    int memberNumber = 0;
    Player newPlayer;
    Player player;
    scanf("%d", &memberNumber);
    if (CheckRecord("namelist.txt", memberNumber))
    {
        printf("You are all set. Enjoy !\n");
        player = pullPlayer(memberNumber);
    }
    else
    {
        printf("You are not in the system right now. Do you want to apply for Cadet Reward membership [Y/N]: \n");
        char decision;
        scanf(" %c", &decision);
        switch (decision)
        {
        case 'Y':

            printf("Please Enter Your Name: ");
            scanf("%[^\n]%*c", newPlayer.names);
            printf("Please Enter Your Age: ");
            scanf("%d", &newPlayer.age);
            printf("How much money you want to buy in: ");
            scanf("%d", &newPlayer.balance);
            newPlayer.memberNumber = 111111;
            printf("Your Cadet Reward Number is : %d", newPlayer.memberNumber);
            printf("You are all set.");

        default:
            printf("Enjoy our casino\n");
            player = newPlayer;
            break;
        }
    }
    */
    Player player;
    player.balance = 2000;
    printf("Pick one of the following options: 1. Player Video Poker 2. Run simulation\n");
    int options = 0;
    scanf("%d", &options);
    if (options == 1)
    {
        //play
        bool stop = false;
        while (!stop)
        {
            printf("You have %d $ right now. Do you want to buy in more? [Y/N] : ", player.balance);
            char decision;
            int money;
            scanf(" %c", &decision);
            switch (decision)
            {
            case 'Y':
                printf("Enter the amount of money: ");
                scanf("%d", &money);
                player.balance += money;
                printf("Now You have %d $\n", player.balance);
            default:
                printf("Enjoy\n");
                break;
            }
            Card *cards;
            cards = (Card *)malloc(5 * sizeof(Card));
            for (int i = 0; i < 5; i++)
            {
                //int dealingCard = deal(&deck, &deckSize);
                //cards[i] = cardChecks(dealingCard);
                cards[i] = realDealCard(&deck, &deckSize);
            }
            printf("Place your bet: ");
            int bet;
            scanf("%d", &bet);
            player.balance -= bet;
            printf("Your hand: %c %s, %c %s, %c %s, %c %s, %c %s\n", cards[0].value, cards[0].suiteSpellOut, cards[1].value, cards[1].suiteSpellOut, cards[2].value, cards[2].suiteSpellOut, cards[3].value, cards[3].suiteSpellOut, cards[4].value, cards[4].suiteSpellOut);
            printf("How many cards you want to change: ");
            int numChange = 0;
            scanf("%d", &numChange);
            
            for(int i=0; i<numChange; i++){
                int index;
                printf("Enter the index of the card one at a time: ");
                scanf("%d", &index);
                index--;
                //cards[index] = cardChecks(deal(&deck, &deckSize));
                cards[index] = realDealCard(&deck, &deckSize);
            }
            printf("\nYour new hand: %c %s, %c %s, %c %s, %c %s, %c %s\n", cards[0].value, cards[0].suiteSpellOut, cards[1].value, cards[1].suiteSpellOut, cards[2].value, cards[2].suiteSpellOut, cards[3].value, cards[3].suiteSpellOut, cards[4].value, cards[4].suiteSpellOut);
            int HandRank = checkHand(cards[0], cards[1], cards[2], cards[3], cards[4]);
            printHandRank(HandRank);
            int payOut = checkPayout(HandRank, bet);
            player.balance += payOut;
            printf("You make %d this round. Now you have %d left.\n", payOut, player.balance);
            printf("Do you want to continue? [Y/N]: ");
            char Again;
            scanf(" %c", &Again);
            switch(Again){
                case 'N':
                    stop = true;
                    //Save Data
                    break;
                default:
                    break;
            }
        }
    }
    else if (options == 2)
    {
        //Recurse simulation
        printf("Hand Rank Code 99-RoyalFLush, 1-Flush, 2-Straight, 3-SF, 4-FOK, 5-FH, 6-TOK, 7-OP, 8-TP, 9-JackOrHigher\n");
        printf("Enter you desired hand rank to run the sim: ");
        int handRank = 0;
        scanf("%d", &handRank);
        RunSim(handRank,&deck, &deckSize, 1);

    }
    
   //Test deal
   
//     vector deck;
//     vector_create(&deck, 0);
//     int deckSize = 52;
//     for(unsigned int i =0; i<52; i++){
//         vector_insert(&deck, i, i);
//         //printf("%d\n", *vector_at(&deck,i));
//     }
   
//    for(int i=0; i< 10; i++){
//        Card play = realDealCard(&deck, &deckSize);
//        printf("%c %c\n", play.value, play.suite);
//    }
    return 0;
}
