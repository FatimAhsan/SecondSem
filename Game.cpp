
//all placements of bitmaps made according to 1920 x 1080 display 


#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include"Header1.h"

#include<allegro5\allegro.h>
using namespace std;

void startgame(int screenno);

template<class C>
void blitcards(string(C::* func)(int), C& a, int y, int x, int cycle)//function for blitting cards on screen as it is used many times
{
	ALLEGRO_BITMAP* mrgreen, * col, * drorchid, * peacock, * profplum, * scarlet, * study, * lounge, * library, * kitchen, * hall, * diningRoom, * conservatory, * billiardRoom, * ballroom, * candlestick, * dagger, * leadPipe, * revolver, * rope, * wrench;


	//cards
	mrgreen = al_load_bitmap("mrgreen.png");
	col = al_load_bitmap("col.png");
	drorchid = al_load_bitmap("orchid.png");
	peacock = al_load_bitmap("peacock.png");
	profplum = al_load_bitmap("profplum.png");
	scarlet = al_load_bitmap("scarlet.png");
	study = al_load_bitmap("study.png");
	lounge = al_load_bitmap("lounge.png");
	library = al_load_bitmap("library.png");
	kitchen = al_load_bitmap("kitchen.png");
	hall = al_load_bitmap("hall.png");
	diningRoom = al_load_bitmap("dining room.png");
	conservatory = al_load_bitmap("conservatory.png");
	billiardRoom = al_load_bitmap("billiard.png");
	ballroom = al_load_bitmap("ballroom.png");
	candlestick = al_load_bitmap("candle.png");
	dagger = al_load_bitmap("dagger.png");
	leadPipe = al_load_bitmap("lead pipe.png");
	revolver = al_load_bitmap("revolver.png");
	rope = al_load_bitmap("rope.png");
	wrench = al_load_bitmap("wrench.png");

	int i;
	string name;
	for (i = 0; i < cycle; i++)
	{
		name = (a.*func)(i);
		if (name == "Mr. Green")
			al_draw_bitmap(mrgreen, (i * 200) + x, y, 0);
		else if (name == "Col. Mustard")
			al_draw_bitmap(col, (i * 200) + x, y, 0);
		else if (name == "Dr. Orchid")
			al_draw_bitmap(drorchid, (i * 200) + x, y, 0);
		else if (name == "Mrs. Peacock")
			al_draw_bitmap(peacock, (i * 200) + x, y, 0);
		else if (name == "Prof. Plum")
			al_draw_bitmap(profplum, (i * 200) + x, y, 0);
		else if (name == "Miss. Scarlet")
			al_draw_bitmap(scarlet, (i * 200) + x, y, 0);
		else if (name == "Study")
			al_draw_bitmap(study, (i * 200) + x, y, 0);
		else if (name == "Lounge")
			al_draw_bitmap(lounge, (i * 200) + x, y, 0);
		else if (name == "Library")
			al_draw_bitmap(library, (i * 200) + x, y, 0);
		else if (name == "Kitchen")
			al_draw_bitmap(kitchen, (i * 200) + x, y, 0);
		else if (name == "Hall")
			al_draw_bitmap(hall, (i * 200) + x, y, 0);
		else if (name == "Dining Room")
			al_draw_bitmap(diningRoom, (i * 200) + x, y, 0);
		else if (name == "Conservatory")
			al_draw_bitmap(conservatory, (i * 200) + x, y, 0);
		else if (name == "Billiard Room")
			al_draw_bitmap(billiardRoom, (i * 200) + x, y, 0);
		else if (name == "Ballroom")
			al_draw_bitmap(ballroom, (i * 200) + x, y, 0);
		else if (name == "Candlestick")
			al_draw_bitmap(candlestick, (i * 200) + x, y, 0);
		else if (name == "Dagger")
			al_draw_bitmap(dagger, (i * 200) + x, y, 0);
		else if (name == "Lead Pipe")
			al_draw_bitmap(leadPipe, (i * 200) + x, y, 0);
		else if (name == "Revolver")
			al_draw_bitmap(revolver, (i * 200) + x, y, 0);
		else if (name == "Rope")
			al_draw_bitmap(rope, (i * 200) + x, y, 0);
		else if (name == "Wrench")
			al_draw_bitmap(wrench, (i * 200) + x, y, 0);
	}
}



int main()
{
	int screenno = 0;//0 = menu, 1= intro,  2  = choose no of players screen , 3 = actual game, 4 = how to play

	startgame(screenno);

	return 0;
}

void startgame(int screenno) {

	ALLEGRO_EVENT_QUEUE* queue;//init queue

	ALLEGRO_DISPLAY* display = NULL;//init display
	ALLEGRO_DISPLAY_MODE disp_data;

	al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
	ALLEGRO_BITMAP* bg,*close;//iniit bitmap
	ALLEGRO_BITMAP* start;
	ALLEGRO_BITMAP* how;
	ALLEGRO_BITMAP* playerno;
	ALLEGRO_BITMAP* file;
	ALLEGRO_BITMAP* letter;
	ALLEGRO_BITMAP* frontarrow, * screen3, * notes, *makeoptions,*choose;
	//ALLEGRO_BITMAP* mrgreen, * col, * drorchid, * peacock, * profplum, * scarlet, * study, * lounge, * library, * kitchen, * hall, * diningRoom, * conservatory, * billiardRoom, * ballroom, * candlestick, * dagger, * leadPipe, * revolver, * rope, * wrench;


	ALLEGRO_SAMPLE* sample = NULL;//game music
	ALLEGRO_SAMPLE_INSTANCE* sampleinstance = NULL;


	al_init();//start prog


	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
	al_set_new_display_flags(ALLEGRO_WINDOWED);//game window type
	display = al_create_display(disp_data.width, disp_data.height);


	//audio
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);
	sample = al_load_sample("game.mp3");

	//init queue for events
	queue = al_create_event_queue();

	al_install_keyboard();
	al_install_mouse();

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_mouse_event_source());

	al_init_image_addon();//image load init

	//load all bitmaps
	
	bg = al_load_bitmap("bg.png");
	close = al_load_bitmap("close.png");
	start = al_load_bitmap("start.png");
	how = al_load_bitmap("howtoplaydetails.png");
	playerno = al_load_bitmap("playerno.png");
	file = al_load_bitmap("file.png");
	letter = al_load_bitmap("letter.png");
	frontarrow = al_load_bitmap("frontarrow.png");
	screen3 = al_load_bitmap("screen3.1.png");
	makeoptions = al_load_bitmap("makeoptions.png");
	notes = al_load_bitmap("notes.png");
	choose = al_load_bitmap("choose.png");


	//init addons
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	ALLEGRO_FONT* font = al_load_font("VINERITC.ttf", 40, NULL);//init font

	//make one player object and list of computer objects 
	player p;
	computer c[] = { computer(1),computer(2),computer(3), computer(4) };

	al_play_sample(sample, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);//play bg sound

	ALLEGRO_MOUSE_STATE state;
	ALLEGRO_EVENT ev;

	//variables for running the loop and controoling what we see on screen
	bool running = true, howtoplayopened = false, letteropened = false, dealcards = false, makesuggestion = false, makeaccusation = false, cardschosen = false, correctacccusation = false,turn = true ,makesuggest = true, isMouseClicked = false;
	int threecardschosen = 1, circle1x = 0, circle1y = -100, circle2x = 0, circle2y = -100, circle3x = 0, circle3y = -100;//circle variables control the card selection graphic
	
	int i, j, k, l = 1, m = 0;//for loop controllers

	//start loop for the game
	while (running)
	{
		al_flush_event_queue(queue);

		al_wait_for_event(queue, &ev);//add events to queue

		al_get_mouse_state(&state);//get mouse state

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)//close prog
		{
			running = false;
			break;
		}
		else if (al_mouse_button_down(&state, 1) && state.x >= 1840 && state.y < 80)// X button on the left corner
		{
			running = false;
			break;
		}

		//-----------------------------------------------------------------------------------------

		if (screenno == 0)
		{
			al_draw_bitmap(bg, 0, 0, 0);
			al_draw_bitmap(start, 650, 300, 0);

			//variables that need to be same every time start button is pressed
			letteropened = false;
			dealcards = false;
			makesuggestion = false;
			makeaccusation = false;
			cardschosen = false;
			correctacccusation = false;
			threecardschosen = 1;
			turn = true;


			//mouse coordinates found by MPos
			if (howtoplayopened == false)
			{
				if (al_mouse_button_down(&state, 1) && state.x > 850 && state.x <= 1060
					&& state.y > 320 and state.y < 370)
				{
					screenno = 1;
				}
				else if (al_mouse_button_down(&state, 1) && state.x > 870 && state.x <= 1020
					&& state.y > 400 and state.y < 500)
				{
					running = false;
					break;
				}
				else if (al_mouse_button_down(&state, 1) && state.x > 680 && state.x <= 1210
					&& state.y > 540 and state.y < 590)
				{
					howtoplayopened = true;
				}
			}
			else
			{
				al_draw_bitmap(how, 320, 200, 0);
				if (al_mouse_button_down(&state, 1) && state.x > 1580 && state.x <= 1630
					&& state.y > 206 and state.y < 240)
				{
					howtoplayopened = false;
				}
			}
			al_draw_bitmap(close, 1840, 0, 0);
			al_flip_display();
		}

		//-----------------------------------------------------------------------------------------

		else if (screenno == 1)
		{
			al_draw_bitmap(bg, 0, 0, 0);
			al_draw_bitmap(file, 700, 200, 0);
			al_draw_textf(font, al_map_rgb(255, 255, 255), 200, 200, NULL, "\"I have arrived at the crime scene... Let me see the file I got, to see if I missed anything.\"");

			if (letteropened == false && al_mouse_button_down(&state, 1) && state.x > 700 && state.x <= 1125 && state.y > 200 and state.y < 918)
			{
				letteropened = true;
			}
			else if (letteropened == true)
			{
				al_draw_bitmap(letter, 700, 200, 0);
				al_draw_bitmap(frontarrow, 900, 700, 0);
				if (al_mouse_button_down(&state, 1) && state.x > 930 && state.x <= 1045 && state.y > 700 and state.y < 775)
				{
					screenno = 2;
				}
			}
			else if (al_mouse_button_down(&state, 1) && state.x <= 200 && state.y < 130)
			{
				screenno = 0;
			}
			al_draw_bitmap(frontarrow, 0, 0, ALLEGRO_FLIP_HORIZONTAL);
			al_draw_bitmap(close, 1840, 0, 0);
			al_flip_display();
		}

		//-----------------------------------------------------------------------------------------

		else if (screenno == 2)//player number selection screen
		{
			al_draw_bitmap(bg, 0, 0, 0);
			al_draw_bitmap(playerno, 650, 300, 0);

			if (al_mouse_button_down(&state, 1) && state.x > 756 && state.x <= 800 && state.y > 550 and state.y < 585)//player selects 2
			{
				p.setnoofplayers(2);
				screenno = 3;
			}
			else if (al_mouse_button_down(&state, 1) && state.x > 880 && state.x <= 910 && state.y > 550 and state.y < 585)//player selects 3
			{
				p.setnoofplayers(3);
				screenno = 3;
			}
			else if (al_mouse_button_down(&state, 1) && state.x > 1010 && state.x <= 1050 && state.y > 550 and state.y < 585)//player selects 4
			{
				p.setnoofplayers(4);
				screenno = 3;
			}
			else if (al_mouse_button_down(&state, 1) && state.x > 1150 && state.x <= 1180 && state.y > 550 and state.y < 585)//player selects 5
			{
				p.setnoofplayers(5);
				screenno = 3;
			}
			else if (al_mouse_button_down(&state, 1) && state.x <= 200 && state.y < 130)
			{
				screenno = 1;
			}
			al_draw_bitmap(frontarrow, 0, 0, ALLEGRO_FLIP_HORIZONTAL);
			al_draw_bitmap(close, 1840, 0, 0);
			al_flip_display();
		}

		//-----------------------------------------------------------------------------------------

		else if (screenno == 3) // actual game 
		{
			al_draw_bitmap(screen3, 0, 0, 0);
			
			if (al_mouse_button_down(&state, 1) && state.x <= 200 && state.y < 130)
			{
				screenno = 0;
			}
			
			//----------------------------------------------------------------------------------------------
			if (dealcards == false)//using bool dealcards so cards are only dealt once in while loop
			{

				p.makeenvelope();

				p.dealcards(c[0], c[1], c[2], c[3]);

				p.showcards();


				//deal cards to computerized player according to their number
				int computercards = (21 - p.getnoofcards() - 3) / (p.getnoofplayers() - 1);
				c[0].showcards(computercards);
				c[1].showcards(computercards);
				c[2].showcards(computercards);
				c[3].showcards(computercards);

				c[0].setnoofcards(computercards);
				c[1].setnoofcards(computercards);
				c[2].setnoofcards(computercards);
				c[3].setnoofcards(computercards);

				dealcards = true;

			}
			//----------------------------------------------------------------------------------------------
			//cards are dealt, now we blit the players cards on screen

			blitcards(&player::getcardname, p, 850, 10, 9);

			//now we start game by player choosing either make suggestion or make accusation button, then the computerized player take turns

			if (turn == true)
			{
				if (makesuggestion == false && makeaccusation == false) {
					al_draw_bitmap(makeoptions, 400, 50, 0);
					if (al_mouse_button_down(&state, 1) && state.x > 420 && state.x <= 924 && state.y > 77 && state.y < 116)//mouse positions again found by MPOS
					{
						makesuggestion = true;
						cout << "\nmakesuggestion" << makesuggestion;

					}
					else if (al_mouse_button_down(&state, 1) && state.x > 420 && state.x <= 924 && state.y > 161 && state.y < 200)
					{
						makeaccusation = true;
					}
				}

				else if (makesuggestion == true || makeaccusation == true)
				{
					if (cardschosen == false)
					{
						al_draw_bitmap(choose, 400, 0, 0);
						al_flip_display();
						//player choose cards to accuse/ suugest
						if (threecardschosen <= 3)
						{
							if (al_mouse_button_down(&state, 1) && state.x > 427 && state.x <= 530 && state.y > 111 and state.y < 236)//mouse positions again found by MPOS
							{
								p.setsuggestionlist("Mr. Green", threecardschosen - 1);
								if (threecardschosen == 1)
								{
									circle1x = 427; circle1y = 111;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 427; circle2y = 111;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 427; circle3y = 111;
								}
								
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 535 && state.x <= 630 && state.y > 111 and state.y < 236)
							{
								p.setsuggestionlist("Col. Mustard", threecardschosen - 1);
								if (threecardschosen == 1)
								{
									circle1x = 535; circle1y = 111;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 535; circle2y = 111;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 535; circle3y = 111;
								}

								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 640 && state.x <= 740 && state.y > 111 and state.y < 236)
							{
								p.setsuggestionlist("Dr. Orchid", threecardschosen - 1);
								if (threecardschosen == 1)
								{
									circle1x = 640; circle1y = 111;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 640; circle2y = 111;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 640; circle3y = 111;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 755 && state.x <= 855 && state.y > 111 and state.y < 236)
							{
								p.setsuggestionlist("Mrs. Peacock", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 755; circle1y = 111;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 755; circle2y = 111;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 755; circle3y = 111;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 860 && state.x <= 960 && state.y > 111 and state.y < 236)
							{
								p.setsuggestionlist("Prof. Plum", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 860; circle1y = 111;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 860; circle2y = 111;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 860; circle3y = 111;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 970 && state.x <= 1070 && state.y > 111 and state.y < 236)
							{
								p.setsuggestionlist("Miss. Scarlet", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 970; circle1y = 111;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 970; circle2y = 111;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 970; circle3y = 111;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 420 && state.x <= 520 && state.y > 290 and state.y < 430)
							{
								p.setsuggestionlist("Candlestick", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 420; circle1y = 290;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 420; circle2y = 290;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 420; circle3y = 290;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 530 && state.x <= 640 && state.y > 290 and state.y < 430)
							{
								p.setsuggestionlist("Dagger", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 530; circle1y = 290;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 530; circle2y = 290;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 530; circle3y = 290;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 640 && state.x <= 740 && state.y > 290 and state.y < 430)
							{
								p.setsuggestionlist("Lead Pipe", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 640; circle1y = 290;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 640; circle2y = 290;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 640; circle3y = 290;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 760 && state.x <= 860 && state.y > 290 and state.y < 430)
							{
								p.setsuggestionlist("Revolver", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 760; circle1y = 290;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 760; circle2y = 290;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 760; circle3y = 290;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 870 && state.x <= 970 && state.y > 290 and state.y < 430)
							{
								p.setsuggestionlist("Rope", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 870; circle1y = 290;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 870; circle2y = 290;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 870; circle3y = 290;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 980 && state.x <= 1070 && state.y > 290 and state.y < 430)
							{
								p.setsuggestionlist("Wrench", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 980; circle1y = 290;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 980; circle2y = 290;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 980; circle3y = 290;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 420 && state.x <= 520 && state.y > 490 and state.y < 620)
							{
								p.setsuggestionlist("Ballroom", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 420; circle1y = 490;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 420; circle2y = 490;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 420; circle3y = 490;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 550 && state.x <= 650 && state.y > 490 and state.y < 620)
							{
								p.setsuggestionlist("Billiard Room", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 550; circle1y = 490;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 550; circle2y = 490;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 550; circle3y = 490;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 680 && state.x <= 780 && state.y > 490 and state.y < 620)
							{
								p.setsuggestionlist("Conservatory", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 680; circle1y = 490;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 680; circle2y = 490;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 680; circle3y = 490;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 620 && state.x <= 920 && state.y > 490 and state.y < 620)
							{
								p.setsuggestionlist("Dining Room", threecardschosen - 1);
								if (threecardschosen == 1)
								{
									circle1x = 620; circle1y = 490;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 620; circle2y = 490;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 620; circle3y = 490;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 950 && state.x <= 1060 && state.y > 490 and state.y < 620)
							{
								p.setsuggestionlist("Hall", threecardschosen - 1);
								if (threecardschosen == 1)
								{
									circle1x = 950; circle1y = 490;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 950; circle2y = 490;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 950; circle3y = 490;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 480 && state.x <= 580 && state.y > 635 and state.y < 770)
							{
								p.setsuggestionlist("Kitchen", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 480; circle1y = 635;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 480; circle2y = 635;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 480; circle3y = 635;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 520 && state.x <= 720 && state.y > 635 and state.y < 770)
							{
								p.setsuggestionlist("Library", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 520; circle1y = 635;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 520; circle2y = 635;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 520; circle3y = 635;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 750 && state.x <= 860 && state.y > 635 and state.y < 770)
							{
								p.setsuggestionlist("Lounge", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 750; circle1y = 635;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 750; circle2y = 635;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 750; circle3y = 635;
								}
								threecardschosen++;
							}
							else if (al_mouse_button_down(&state, 1) && state.x > 880 && state.x <= 990 && state.y > 635 and state.y < 770)
							{
								p.setsuggestionlist("Study", threecardschosen - 1); 
								if (threecardschosen == 1)
								{
									circle1x = 880; circle1y = 635;
								}
								else if (threecardschosen == 2)
								{
									circle2x = 880; circle2y = 635;
								}
								else if (threecardschosen == 3)
								{
									circle3x = 880; circle3y = 635;
								}
								threecardschosen++;
							}

							al_draw_filled_circle(circle1x + 13, circle1y + 10, 20, al_map_rgba(0, 100, 0, 250));//display selection circles
							al_draw_filled_circle(circle2x + 13, circle2y + 10, 20, al_map_rgba(0, 100, 0, 250));
							al_draw_filled_circle(circle3x + 13, circle3y + 10, 20, al_map_rgba(0, 100, 0, 250));
							al_flip_display();

						}

						if (threecardschosen > 3)
							cardschosen = true;
					}
					else if (cardschosen == true)
					{
						//displaying chosen cards
						blitcards(&player::getsuggestionlist, p, 100, 500, 3);

						//game seuqence if player made an accusation
						if (makeaccusation == true)
						{
							al_draw_textf(font, al_map_rgb_f(1, 1, 1), 400, 0, 0, "You have accused: ");
							al_draw_textf(font, al_map_rgb_f(1, 1, 1), 400, 300, 0, "The real kiler was: ");

							blitcards(&player::showenvelope, p, 400, 500, 3);


							for (i = 0; i < 3; i++)
							{
								if (p.getsuggestionlist(i) == p.showenvelope(i))
								{
									correctacccusation = true;
								}
								else
									correctacccusation = false;
							}

							if (correctacccusation)
							{
								al_draw_textf(font, al_map_rgb_f(1, 1, 1), 400, 700, 0, "You caught the killer! ");
							}
							else
							{
								al_draw_textf(font, al_map_rgb_f(1, 1, 1), 200, 600, 0, "Your accusation was not correct. You have been taken off the case. Better luck next time!");
								al_draw_textf(font, al_map_rgb(255, 255, 255), 600, 700, NULL, "....Click Here To Continue...");
								if (al_mouse_button_down(&state, 1) && state.x > 650 && state.x <= 1075 && state.y > 700 and state.y < 720)
								{
									threecardschosen = 0;
									cardschosen = false;
									makesuggestion = false;
									circle1x = 0, circle1y = -100, circle2x = 0, circle2y = -100, circle3x = 0, circle3y = -100;
									screenno = 0;
								}
							}
						}

						//game sequence if player made a suggestion
						else if (makesuggestion)
						{
							//checking suggestionlist with cards of computerized players
							for (i = 0; i < 3; i++)//loop for every card in suggestionlist
							{
								for (j = 0; j < 3; j++)//loop for every computerized player
								{
									for (k = 0; k < c[j].getnoofcards(); k++)//loop for every player card
									{
										if (p.getsuggestionlist(i) == c[j].getcardname(k))
										{
											al_draw_textf(font, al_map_rgb(255, 255, 255), 400, (i * 100) + 300, NULL, "Evidence from your teammates suggests card %d selected is wrong", i + 1);
										}
									}
								}
							}
							al_draw_textf(font, al_map_rgb(255, 255, 255), 600, 700, NULL, "....Click Here To Continue...");
							if (al_mouse_button_down(&state, 1) && state.x > 650 && state.x <= 1075 && state.y > 700 and state.y < 720)
							{
								threecardschosen = 0;
								cardschosen = false;
								makesuggestion = false;
								circle1x = 0, circle1y = -100, circle2x = 0, circle2y = -100, circle3x = 0, circle3y = -100;
								turn = false;
								continue;
							}
						}
					}

				}
			}
			if (turn == false)
			{
				//loop for every player to make a suggestion
				if (makesuggest == true)
				{
					c[m].makesuggestion(p);
					isMouseClicked = false;
					makesuggest = false;

				}

				al_draw_textf(font, al_map_rgb(255, 255, 255), 400, 50, NULL, "Teammate %d made a suggestion.", l);
				blitcards(&computer::getsuggestionlist, c[m], 120, 500, 3);

				//checking suggestionlist with cards of computerized players
				for (i = 0; i < 3; i++)//loop for every card in suggestionlist
				{
					for (j = 0; j < 3; j++)//loop for every computerized player
					{
						for (k = 0; k < c[j].getnoofcards(); k++)//loop for every player card
						{
							if (c[m].getsuggestionlist(i) == c[j].getcardname(k))
							{
								al_draw_textf(font, al_map_rgb(255, 255, 255), 400, (i * 100) + 300, NULL, "Evidence from your other teammates suggests card %d selected is wrong", i + 1);
							}
						}
					}

				}
				al_draw_textf(font, al_map_rgb(255, 255, 255), 600, 700, NULL, "....Click Here To Continue...");


				if (al_mouse_button_down(&state, 1) && state.x > 650 && state.x <= 1075 && state.y > 700 and state.y < 730 && makesuggest == false)
				{
					makesuggest = true;
					l++;
					m++;
				}
				if (m == p.getnoofplayers() - 1)
				{
					if (al_mouse_button_down(&state, 1) && state.x > 650 && state.x <= 1075 && state.y > 700 and state.y < 720)
					{
						l = 1;
						m = 0;
						turn = true;
					}
				}


			}
			al_flip_display();
		}
		al_flip_display();
	}
}

