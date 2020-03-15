#pragma once

namespace
{
	game_hudelem_s* Background[18];
	game_hudelem_s* ScrollBar[18];
	game_hudelem_s* Title[18];
	game_hudelem_s* SubTitle[18];
	game_hudelem_s* Options[18][10];

	bool Enabled[18][10][10];
	bool menuOpen[18];
	bool menuLoaded;
	int MenuIndex[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int ScrollBarPos[2][18] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90 },
	};
}

// Happens when the match is first loaded
void StoreHuds()
{
	for (int i = 0; i < 18; i++)
	{
		Background[i] = setShader(i, 1, /*W*/1000, /*H*/1000, /*X*/1000, /*Y*/0, 0, /*R*/0, /*G*/0, /*B*/0, /*A*/150);;
		ScrollBar[i] = setShader(i, 1, /*W*/1000, /*H*/17.5, /*X*/1000, /*Y*/90, 0, /*R*/0, /*G*/255, /*B*/140, /*A*/200);
		Title[i] = setText(i, "TheTitle", /*Font*/3, /*FontScale*/3, /*X*/1000, /*Y*/20, 0, /*R*/255, /*G*/255, /*B*/255, /*A*/255, /*R*/0, /*G*/255, /*B*/230, /*A*/255);
		SubTitle[i] = setText(i, "SubTitle", /*Font*/3, /*FontScale*/2, /*X*/1000, /*Y*/50, 0, /*R*/255, /*G*/255, /*B*/255, /*A*/255, /*R*/0, /*G*/255, /*B*/230, /*A*/255);

		int Y = 66;
		for (int j = 0; j < 10; j++)
		{
			Y += 20;
			// Instantiate a default option
			Options[i][j] = setText(/*Client*/i, "Option", /*Font*/3, /*FontScale*/2, /*X*/1000, /*Y*/80, 0, /*R*/255, /*G*/255, /*B*/255, /*A*/255, /*R*/140, /*G*/0, /*B*/255, /*A*/255);

			for (int k = 0; k < 10; k++)
			{
				// All mods are disabled
				Enabled[i][j][k] = false;
			}
		}
	}
}

////////
//Menus//
//////////
void MainMenu(int client)
{
	// Title
	ChangeText(Title[client], "Despicable");
	// Sub Title
	ChangeText(SubTitle[client], "Main Menu");
	// Main Menu
	ChangeText(Options[client][0], "Mods Menu");
	ChangeText(Options[client][1], "Lobby Menu");
	ChangeText(Options[client][2], "Sub Menu 3");
	ChangeText(Options[client][3], "Sub Menu 4");
	ChangeText(Options[client][4], "Sub Menu 5");
	ChangeText(Options[client][5], "Sub Menu 6");
	ChangeText(Options[client][6], "Sub Menu 7");
	ChangeText(Options[client][7], "Sub Menu 8");
	ChangeText(Options[client][8], "Sub Menu 9");
	ChangeText(Options[client][9], "Verification Menu");
}

void SubMenu1(int client)
{
	ChangeText(SubTitle[client], "Mods Menu");
	//
	ChangeText(Options[client][0], "God Mode");
	ChangeText(Options[client][1], "UFO Mode");
	ChangeText(Options[client][2], "Infinite Ammo");
	ChangeText(Options[client][3], "Dvar Test");
	ChangeText(Options[client][4], "Pro Mod");
	ChangeText(Options[client][5], "Third Person");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}


void SubMenu2(int client)
{
	ChangeText(SubTitle[client], "Lobby Menu");
	//
	ChangeText(Options[client][0], "Super Jump");
	ChangeText(Options[client][1], "Super Speed");
	ChangeText(Options[client][2], "Freeze Lobby");
	ChangeText(Options[client][3], "Option 4");
	ChangeText(Options[client][4], "Option 5");
	ChangeText(Options[client][5], "Option 6");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}

void SubMenu3(int client)
{
	ChangeText(SubTitle[client], "Sub Menu 3");
	//
	ChangeText(Options[client][0], "Option 1");
	ChangeText(Options[client][1], "Option 2");
	ChangeText(Options[client][2], "Option 3");
	ChangeText(Options[client][3], "Option 4");
	ChangeText(Options[client][4], "Option 5");
	ChangeText(Options[client][5], "Option 6");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}

void SubMenu4(int client)
{
	ChangeText(SubTitle[client], "Sub Menu 4");
	//
	ChangeText(Options[client][0], "Option 1");
	ChangeText(Options[client][1], "Option 2");
	ChangeText(Options[client][2], "Option 3");
	ChangeText(Options[client][3], "Option 4");
	ChangeText(Options[client][4], "Option 5");
	ChangeText(Options[client][5], "Option 6");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}

void SubMenu5(int client)
{
	ChangeText(SubTitle[client], "Sub Menu 5");
	//
	ChangeText(Options[client][0], "Option 1");
	ChangeText(Options[client][1], "Option 2");
	ChangeText(Options[client][2], "Option 3");
	ChangeText(Options[client][3], "Option 4");
	ChangeText(Options[client][4], "Option 5");
	ChangeText(Options[client][5], "Option 6");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}

void SubMenu6(int client)
{
	ChangeText(SubTitle[client], "Sub Menu 6");
	//
	ChangeText(Options[client][0], "Option 1");
	ChangeText(Options[client][1], "Option 2");
	ChangeText(Options[client][2], "Option 3");
	ChangeText(Options[client][3], "Option 4");
	ChangeText(Options[client][4], "Option 5");
	ChangeText(Options[client][5], "Option 6");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}

void SubMenu7(int client)
{
	ChangeText(SubTitle[client], "Sub Menu 7");
	//
	ChangeText(Options[client][0], "Option 1");
	ChangeText(Options[client][1], "Option 2");
	ChangeText(Options[client][2], "Option 3");
	ChangeText(Options[client][3], "Option 4");
	ChangeText(Options[client][4], "Option 5");
	ChangeText(Options[client][5], "Option 6");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}

void SubMenu8(int client)
{
	ChangeText(SubTitle[client], "Sub Menu 8");
	//
	ChangeText(Options[client][0], "Option 1");
	ChangeText(Options[client][1], "Option 2");
	ChangeText(Options[client][2], "Option 3");
	ChangeText(Options[client][3], "Option 4");
	ChangeText(Options[client][4], "Option 5");
	ChangeText(Options[client][5], "Option 6");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}

void SubMenu9(int client)
{
	ChangeText(SubTitle[client], "Sub Menu 9");
	//
	ChangeText(Options[client][0], "Option 1");
	ChangeText(Options[client][1], "Option 2");
	ChangeText(Options[client][2], "Option 3");
	ChangeText(Options[client][3], "Option 4");
	ChangeText(Options[client][4], "Option 5");
	ChangeText(Options[client][5], "Option 6");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}

void SubMenu10(int client)
{
	ChangeText(SubTitle[client], "Verification Menu");
	//
	ChangeText(Options[client][0], "Option 1");
	ChangeText(Options[client][1], "Option 2");
	ChangeText(Options[client][2], "Option 3");
	ChangeText(Options[client][3], "Option 4");
	ChangeText(Options[client][4], "Option 5");
	ChangeText(Options[client][5], "Option 6");
	ChangeText(Options[client][6], "Option 7");
	ChangeText(Options[client][7], "Option 8");
	ChangeText(Options[client][8], "Option 9");
	ChangeText(Options[client][9], "Option 10");
}

///

void ResetScroll(int client)
{
	// Reset Scrollbar Position
	ScrollBarPos[0][client] = 0;
	ScrollBarPos[1][client] = 90;
	MoveOverTime(ScrollBar[client], 100, /*X*/500, /*Y*/90);
}

// Open The Menu
void OpenMenu(int client)
{
	// Change the text to fit the main menu
	MainMenu(client);

	// Move Background Hud Elems (Menu Background)
	MoveOverTime(Background[client], 800, /*X*/500, /*Y*/0);
	MoveOverTime(ScrollBar[client], 800, /*X*/500, /*Y*/90);
	MoveOverTime(Title[client], 800, /*X*/525, /*Y*/20);
	MoveOverTime(SubTitle[client], 800, /*X*/560, /*Y*/50);

	// Reset Scrollbar Position
	ScrollBarPos[0][client] = 0;
	ScrollBarPos[1][client] = 90;

	// Move Text
	int Y = 66;
	for(int i = 0; i < 10; ++i)
	{
		Y += 20;
		MoveOverTime(Options[client][i], 800, 520, Y);
	}
}

// Close the menu
void CloseMenu(int client)
{
	// Move the menu off screen
	MoveOverTime(Background[client], 800, /*X*/1000, /*Y*/0);
	MoveOverTime(ScrollBar[client], 800, /*X*/1000, /*Y*/ScrollBarPos[1][client]);
	MoveOverTime(Title[client], 800, /*X*/1000, /*Y*/20);
	MoveOverTime(SubTitle[client], 800, /*X*/1000, /*Y*/50);
	
	// Move text off screen
	int Y = 66;
	for(int i = 0; i < 10; ++i)
	{
		Y += 20;
		MoveOverTime(Options[client][i], 800, /*X*/1000, /*Y*/Y);
	}
}

// Keep track of the scrollbar
void MoveScroll(int client, int button)
{
	// Up
	if(button == 1 && ScrollBarPos[0][client] > 0)
	{
		ScrollBarPos[0][client]--;
		ScrollBarPos[1][client] -= 20;
		MoveOverTime(ScrollBar[client], 100, /*X*/500, /*Y*/ScrollBarPos[1][client]);
	}

	// Down
	else if(button == 0 && ScrollBarPos[0][client] < 9)
	{
		ScrollBarPos[0][client]++;
		ScrollBarPos[1][client] += 20;
		MoveOverTime(ScrollBar[client], 100, /*X*/500, /*Y*/ScrollBarPos[1][client]);
	}

	// Go to top
	else if(button == 1 && ScrollBarPos[0][client] == 0)
	{
		ScrollBarPos[0][client] = 9;
		ScrollBarPos[1][client] += 180;
		MoveOverTime(ScrollBar[client], 100, /*X*/500, /*Y*/ScrollBarPos[1][client]);
	}

	// Go to bottom
	else if(button == 0 && ScrollBarPos[0][client] == 9)
	{
		ScrollBarPos[0][client] = 0;
		ScrollBarPos[1][client] -= 180;
		MoveOverTime(ScrollBar[client], 100, /*X*/500, /*Y*/ScrollBarPos[1][client]);
	}
}