#include<iostream>
#include<string>
#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>//image library
#include<allegro5\allegro_font.h>//text
#include<allegro5\allegro_ttf.h>//fonts
#include<allegro5\allegro_primitives.h>//primitives
#include<allegro5\allegro_acodec.h>//sound/audio library
#include<allegro5\allegro_audio.h>//sound/audio library
using namespace std;

class computer;


class player
{
private:
	int noofplayers, noofcards;
	bool turn;
	int cardsavailable[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	string cards[21] = {}, envelope[3] = {}, deck[21] = {};
	//cards
	string suspects[6] = { "Mr. Green","Col. Mustard","Dr. Orchid","Mrs. Peacock","Prof. Plum","Miss. Scarlet" };
	string places[9] = { "Study", "Lounge","Library","Kitchen","Hall","Dining Room","Conservatory","Billiard Room","Ballroom" };
	string weapons[6] = { "Candlestick","Dagger","Lead Pipe","Revolver","Rope","Wrench" };
	string suggest[3];
	int total;
public:
	player()
	{
		noofcards = 0;
		noofplayers = 0;
		turn = false;
		total = 0;
	}
	friend class computer;

	void makeenvelope();
	string showenvelope(int x);

	void showcards();//checker
	void setnoofplayers(int);
	int getnoofplayers();
	int getnoofcards();
	void setnoofcards(int x);
	void dealcards(computer& c1, computer& c2, computer& c3, computer& c4);
	string getavailablecards(int x) {
		return deck[cardsavailable[x]];
	}
	string getcardname(int x);

	void setsuggestionlist(string x, int i);
	string getsuggestionlist(int x);
};

//class for computerized players
class computer
{
private:
	int noofcards;
	int ID;
	string cards[9] = {}, suggestionlist[3] = {};
public:
	friend class player;
	
	computer()
	{
	}
	computer(int x) {
		noofcards = 0;
		ID = x;
	}
	void makesuggestion(player p);//passign player p to use deck intead of copying deck of player to computer
	int getnoofcards();
	void setnoofcards(int x);
	void setcard(int x, string n) {
		cards[x] = n;
	}
	void showcards(int i);
	string getcardname(int x);
	string getsuggestionlist(int x);
};
