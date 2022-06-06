#include"Header1.h"
using namespace std;

// player class
void player::makeenvelope()
{
	srand(time(NULL));
	int i1, i2, i3,i;
	i1 = rand() % 6;
	envelope[0] = suspects[i1];
	for (i = i1; i < 6; i++)//removing the cards of envelope from respective piles
	{
		suspects[i] = suspects[i + 1];
	}
	i2 = rand() % 6;
	envelope[1] = weapons[i2];
	for (i = i1; i < 6; i++)//removing the cards of envelope from respective piles
	{
		weapons[i] = weapons[i + 1];
	}
	
	i3 = rand() % 9;
	envelope[2] = places[i3];
	for (i = i1; i < 9; i++)//removing the cards of envelope from respective piles
	{
		places[i] = places[i + 1];
	}
}
string player::showenvelope(int x) {
	return envelope[x];
}
void player::dealcards(computer &c1, computer& c2, computer &c3, computer& c4)
{
	srand(time(NULL));
	if (getnoofplayers() == 2)//divide cards evenly between players
	{
		setnoofcards(9);
	}
	else if (getnoofplayers() == 3)
	{
		setnoofcards(6);
	}
	else if (getnoofplayers() == 4)
	{
		setnoofcards(6);
	}
	else if (getnoofplayers() == 5)
	{
		setnoofcards(4);
	}


	int x,i,j;

	//----------------------------------------------------------------

	//join all remaining cards after making the envelope
	for (x = 0; x < 5; x++)
		deck[x] = suspects[x];
	for (x = 5; x < 10; x++)
		deck[x] = weapons[x - 5];
	for (x = 10; x < 18; x++)
		deck[x] = places[x - 10];

	//----------------------------------------------------------------
	// **Logic used to deal the deck**
	// 	   cardsavailable[] has numbers 0 to 17, meaning 18 cards lefts after giving 3 to envelope
	// 	   we shuffle this list completely and assign the first group of numbers to player , the next group to the next computerized players
	// 
	// 	   eg no of players = 3
	// 
	// 	     0 1 2 3 4 5 |6 7 8 9 10 11| 12 13 14 15 16 17    
	//       ----------- |             |  -----------------  
	// 	      player     ------------    computer player2
	//                  computer player1
	//   the cards will be assigned by passing the cardavailable no to deck[] and equating this to cards[]
	//
	// 
	 //shuffle cardsavailable
	for (i = 17; i > 0; --i)
	{
		//get swap index
		j = rand() % i;
		//swap p[i] with p[j]
		int temp = cardsavailable[i];
		cardsavailable[i] = cardsavailable[j];
		cardsavailable[j] = temp;
	}


	//assign cards to player from deck
	//copy first n elements from deck[cardsavailable] to cards[]
	for (i = 0; i < noofcards; ++i)
		cards[i] = deck[cardsavailable[i]];

	//assinging cards to computer players
	int computercards = (21 - noofcards - 3) / (noofplayers - 1);//whole deck - players cards - cards in envelop / total no of computerized players
	i = 0;
	while (i < noofplayers - 1)
	{
		if (i == 0) {

			for (j = 0; j < computercards; j++)
			{
				int y = cardsavailable[j + noofcards];
				c1.cards[j] = deck[y];
				cout << deck[cardsavailable[j + noofcards]] << " " << c1.cards[j] << endl;
			}
		}
		else if (i == 1) {
			for (j = 0; j < computercards; j++)
			{
				c2.cards[j] = deck[cardsavailable[j + noofcards + computercards]];
			}
		}
		else if (i == 2) {
			for (j = 0; j < computercards; j++)
			{
				c3.cards[j] = deck[cardsavailable[j + noofcards + computercards + computercards]];
			}
		}
		else if (i == 3) {
			for (j = 0; j < computercards; j++)
			{
				c4.cards[j] = deck[cardsavailable[j + noofcards + computercards + computercards + computercards]];
			}
		}
		i++;
	}
}
int player::getnoofcards() {
	return noofcards;
}
void player::setnoofcards(int x) {
	noofcards = x;
}
int player::getnoofplayers() {
	return noofplayers;
}
void player::setnoofplayers(int x) {
	noofplayers = x;
}
void player::showcards() {
	int x;
	for (x = 0; x < noofcards; x++)
	{
		cout << x << "player card: " << cards[x] << endl;
	}
}
string player::getcardname(int x) {
	return cards[x];
}
void player::setsuggestionlist(string x,int i)
{
	suggest[i] = x;
}
string player::getsuggestionlist(int x)
{
	return suggest[x];
}


//computer class
int computer::getnoofcards()
{
	return noofcards;
}
void computer::showcards(int i) {
	int x;
	cout << ID << endl;
	for (x = 0; x < i; x++)
	{
		cout << "cardc: " << cards[x] << endl;
	}
	cout << "end id" << ID << endl;
}
string computer::getcardname(int x) {
	return cards[x];
}
void computer::setnoofcards(int x)
{
	noofcards = x;
}
void computer::makesuggestion(player p)
{
	int i,j;
	//shuffle cards
	for (i = 17; i > 0; --i)
	{
		//get swap index
		j = rand() % i;
		//swap p[i] with p[j]
		string temp = p.deck[i];
		p.deck[i] = p.deck[j];
		p.deck[j] = temp;
	}
	suggestionlist[0] = p.deck[0];
	suggestionlist[1] = p.deck[1];
	suggestionlist[2] = p.deck[2];
}
string computer::getsuggestionlist(int x)
{
	return suggestionlist[x];
}
