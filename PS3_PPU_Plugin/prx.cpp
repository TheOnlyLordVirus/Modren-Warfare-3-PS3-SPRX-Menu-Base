//Sony
#include <sys/prx.h>
#include <sys/syscall.h>
#include <sys/ppu_thread.h>
#include <sys/sys_time.h>
#include <sys/time_util.h>
#include <sys/process.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/return_code.h>
#include <sys/prx.h>
#include <sys/paths.h>
#include <cellstatus.h>
#include <cell/error.h>
#include <string.h>
 
//C-Headers (converted)
#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <cstdarg>
#include <cassert>
#include <cstddef>
#include <cmath>
#include <ctime>
 
//C++ Std Lib
#include <typeinfo>
#include <vector>
 
//C-Headers
#include <pthread.h>
#include <locale.h>
 
//Project Headers
#include "Dialogs.h"
#include "PS3.h"
#include "Offsets.h"
#include "HudsFunc.h"
#include "Buttons.h"
#include "Huds.h"
#include "Functions.h"

// Main Thread
void Main_Thread(uint64_t arg)
{
	sleep(20000);

	for (;;)
	{
		if (Functions::inGame)
		{
			if (menuLoaded)
			{
				for (int i = 0; i < 18; ++i)
				{
					// Looping Function Check
					Functions::LoopInfAmmo(i);
					Functions::LoopFOV(i);

					// Button Press Check
					if (menuOpen[i])
					{
						// Select
						if (Buttons::DetectBtn(i, Buttons::Square))
						{
							// Main Menu
							if (MenuIndex[i] == 0)
							{
								// Sub Menu 1
								if (ScrollBarPos[0][i] == 0)
								{
									MenuIndex[i] = 1;
									SubMenu1(i);
									ResetScroll(i);
								}

								// Sub Menu 2
								else if (ScrollBarPos[0][i] == 1)
								{
									MenuIndex[i] = 2;
									SubMenu2(i);
									ResetScroll(i);
								}

								// Sub Menu 3
								else if (ScrollBarPos[0][i] == 2)
								{
									MenuIndex[i] = 3;
									SubMenu3(i);
									ResetScroll(i);
								}

								// Sub Menu 4
								else if (ScrollBarPos[0][i] == 3)
								{
									MenuIndex[i] = 4;
									SubMenu4(i);
									ResetScroll(i);
								}

								// Sub Menu 5
								else if (ScrollBarPos[0][i] == 4)
								{
									MenuIndex[i] = 5;
									SubMenu5(i);
									ResetScroll(i);
								}

								// Sub Menu 6
								else if (ScrollBarPos[0][i] == 5)
								{
									MenuIndex[i] = 6;
									SubMenu6(i);
									ResetScroll(i);
								}

								// Sub Menu 7
								else if (ScrollBarPos[0][i] == 6)
								{
									MenuIndex[i] = 7;
									SubMenu7(i);
									ResetScroll(i);
								}

								// Sub Menu 8
								else if (ScrollBarPos[0][i] == 7)
								{
									MenuIndex[i] = 8;
									SubMenu8(i);
									ResetScroll(i);
								}

								// Sub Menu 9
								else if (ScrollBarPos[0][i] == 8)
								{
									MenuIndex[i] = 9;
									SubMenu9(i);
									ResetScroll(i);
								}

								// Sub Menu 10
								else if (ScrollBarPos[0][i] == 9)
								{
									MenuIndex[i] = 10;
									SubMenu10(i);
									ResetScroll(i);
								}
							}

							// Mods Menu
							else if (MenuIndex[i] == 1)
							{
								// God Mode
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][0][0])
								{
									Enabled[i][0][0] = true;
									Functions::GodMode(i, true);
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									Enabled[i][0][0] = false;
									Functions::GodMode(i, false);
								}

								// UFO Mode
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][0][1])
								{
									Enabled[i][0][1] = true;
									Functions::UFOMode(i, true);
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									Enabled[i][0][1] = false;
									Functions::UFOMode(i, false);
								}

								// Infinite Ammo
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][0][2])
								{
									Enabled[i][0][2] = true;
									Functions::InfiniteAmmo(i, true);
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									Enabled[i][0][2] = false;
									Functions::InfiniteAmmo(i, false);
								}

								// Dvar Test
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][0][3])
								{
									Enabled[i][0][3] = true;
									Functions::Dvar(i, true);
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][0][3] = false;
									Functions::Dvar(i, false);
								}

								// FOV
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][0][4])
								{
									Enabled[i][0][4] = true;
									Functions::SetFOV(i, "95");
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][0][4] = false;
									Functions::SetFOV(i, "65");
								}

								// Third Person
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][0][5])
								{
									Enabled[i][0][5] = true;
									Functions::SetThirdPerson(i, true);
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][0][5] = false;
									Functions::SetThirdPerson(i, false);
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][0][6])
								{
									Enabled[i][0][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][0][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][0][7])
								{
									Enabled[i][0][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][0][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][0][8])
								{
									Enabled[i][0][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][0][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][0][9])
								{
									Enabled[i][0][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][0][9] = false;
								}
							}

							// Lobby Menu
							else if (MenuIndex[i] == 2)
							{
								// Super Jump
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][1][0])
								{
									for (int j = 0; j < 18; j++)
									{
										Enabled[j][1][0] = true;
									}

									Functions::SuperJump(true);
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									for (int j = 0; j < 18; j++)
									{
										Enabled[j][1][0] = false;
									}

									Functions::SuperJump(false);
								}

								// Super Speed
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][1][1])
								{
									if (Enabled[i][1][2])
									{
										for (int j = 0; j < 18; j++)
										{
											// If Freeze Lobby is set to true, set it to false
											Enabled[j][1][2] = false;
										}
									}

									for (int j = 0; j < 18; j++)
									{
										Enabled[j][1][1] = true;
									}

									Functions::SuperSpeed(true);
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									for (int j = 0; j < 18; j++)
									{
										Enabled[j][1][1] = false;
									}
									Functions::SuperSpeed(false);
								}

								// Freeze Lobby
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][1][2])
								{
									if (Enabled[i][1][1])
									{
										for (int j = 0; j < 18; j++)
										{
											// If super speed is set to true, set it to false
											Enabled[j][1][1] = false;
										}
									}

									for (int j = 0; j < 18; j++)
									{
										Enabled[j][1][2] = true;
									}

									Functions::FreezeLobby(true);
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									for (int j = 0; j < 18; j++)
									{
										Enabled[j][1][2] = false;
									}
									Functions::FreezeLobby(false);
								}

								// Option 4
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][1][3])
								{
									Enabled[i][1][3] = true;
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][1][3] = false;
								}

								// Option 5
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][1][4])
								{
									Enabled[i][1][4] = true;
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][1][4] = false;
								}

								// Option 6
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][1][5])
								{
									Enabled[i][1][5] = true;
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][1][5] = false;
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][1][6])
								{
									Enabled[i][1][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][1][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][1][7])
								{
									Enabled[i][1][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][1][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][1][8])
								{
									Enabled[i][1][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][1][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][1][9])
								{
									Enabled[i][1][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][1][9] = false;
								}
							}

							//Sub Menu 3
							else if (MenuIndex[i] == 3)
							{
								// Option 1
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][2][0])
								{
									Enabled[i][2][0] = true;
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									Enabled[i][2][0] = false;
								}

								// Option 2
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][2][1])
								{
									Enabled[i][2][1] = true;
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									Enabled[i][2][1] = false;
								}

								// Option 3
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][2][2])
								{
									Enabled[i][2][2] = true;
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									Enabled[i][2][2] = false;
								}

								// Option 4
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][2][3])
								{
									Enabled[i][2][3] = true;
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][2][3] = false;
								}

								// Option 5
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][2][4])
								{
									Enabled[i][2][4] = true;
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][2][4] = false;
								}

								// Option 6
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][2][5])
								{
									Enabled[i][2][5] = true;
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][2][5] = false;
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][2][6])
								{
									Enabled[i][2][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][2][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][2][7])
								{
									Enabled[i][2][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][2][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][2][8])
								{
									Enabled[i][2][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][2][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][2][9])
								{
									Enabled[i][2][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][2][9] = false;
								}
							}

							//Sub Menu 4
							else if (MenuIndex[i] == 4)
							{
								// Option 1
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][3][0])
								{
									Enabled[i][3][0] = true;
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									Enabled[i][3][0] = false;
								}

								// Option 2
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][3][1])
								{
									Enabled[i][3][1] = true;
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									Enabled[i][3][1] = false;
								}

								// Option 3
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][3][2])
								{
									Enabled[i][3][2] = true;
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									Enabled[i][3][2] = false;
								}

								// Option 4
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][3][3])
								{
									Enabled[i][3][3] = true;
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][3][3] = false;
								}

								// Option 5
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][3][4])
								{
									Enabled[i][3][4] = true;
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][3][4] = false;
								}

								// Option 6
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][3][5])
								{
									Enabled[i][3][5] = true;
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][3][5] = false;
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][3][6])
								{
									Enabled[i][3][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][3][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][3][7])
								{
									Enabled[i][3][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][3][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][3][8])
								{
									Enabled[i][3][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][3][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][3][9])
								{
									Enabled[i][3][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][3][9] = false;
								}
							}

							//Sub Menu 5
							else if (MenuIndex[i] == 5)
							{
								// Option 1
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][4][0])
								{
									Enabled[i][4][0] = true;
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									Enabled[i][4][0] = false;
								}

								// Option 2
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][4][1])
								{
									Enabled[i][4][1] = true;
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									Enabled[i][4][1] = false;
								}

								// Option 3
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][4][2])
								{
									Enabled[i][4][2] = true;
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									Enabled[i][4][2] = false;
								}

								// Option 4
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][4][3])
								{
									Enabled[i][4][3] = true;
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][4][3] = false;
								}

								// Option 5
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][4][4])
								{
									Enabled[i][4][4] = true;
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][4][4] = false;
								}

								// Option 6
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][4][5])
								{
									Enabled[i][4][5] = true;
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][4][5] = false;
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][4][6])
								{
									Enabled[i][4][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][4][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][4][7])
								{
									Enabled[i][4][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][4][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][4][8])
								{
									Enabled[i][4][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][4][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][4][9])
								{
									Enabled[i][4][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][4][9] = false;
								}
							}

							//Sub Menu 6
							else if (MenuIndex[i] == 6)
							{
								// Option 1
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][5][0])
								{
									Enabled[i][5][0] = true;
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									Enabled[i][5][0] = false;
								}

								// Option 2
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][5][1])
								{
									Enabled[i][5][1] = true;
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									Enabled[i][5][1] = false;
								}

								// Option 3
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][5][2])
								{
									Enabled[i][5][2] = true;
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									Enabled[i][5][2] = false;
								}

								// Option 4
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][5][3])
								{
									Enabled[i][5][3] = true;
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][5][3] = false;
								}

								// Option 5
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][5][4])
								{
									Enabled[i][5][4] = true;
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][5][4] = false;
								}

								// Option 6
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][5][5])
								{
									Enabled[i][5][5] = true;
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][5][5] = false;
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][5][6])
								{
									Enabled[i][5][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][5][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][5][7])
								{
									Enabled[i][5][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][5][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][5][8])
								{
									Enabled[i][5][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][5][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][5][9])
								{
									Enabled[i][5][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][5][9] = false;
								}
							}

							//Sub Menu 7
							else if (MenuIndex[i] == 7)
							{
								// Option 1
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][6][0])
								{
									Enabled[i][6][0] = true;
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									Enabled[i][6][0] = false;
								}

								// Option 2
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][6][1])
								{
									Enabled[i][6][1] = true;
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									Enabled[i][6][1] = false;
								}

								// Option 3
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][6][2])
								{
									Enabled[i][6][2] = true;
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									Enabled[i][6][2] = false;
								}

								// Option 4
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][6][3])
								{
									Enabled[i][6][3] = true;
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][6][3] = false;
								}

								// Option 5
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][6][4])
								{
									Enabled[i][6][4] = true;
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][6][4] = false;
								}

								// Option 6
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][6][5])
								{
									Enabled[i][6][5] = true;
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][6][5] = false;
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][6][6])
								{
									Enabled[i][6][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][6][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][6][7])
								{
									Enabled[i][6][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][6][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][6][8])
								{
									Enabled[i][6][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][6][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][6][9])
								{
									Enabled[i][6][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][6][9] = false;
								}
							}

							//Sub Menu 8
							else if (MenuIndex[i] == 8)
							{
								// Option 1
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][7][0])
								{
									Enabled[i][7][0] = true;
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									Enabled[i][7][0] = false;
								}

								// Option 2
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][7][1])
								{
									Enabled[i][7][1] = true;
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									Enabled[i][7][1] = false;
								}

								// Option 3
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][7][2])
								{
									Enabled[i][7][2] = true;
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									Enabled[i][7][2] = false;
								}

								// Option 4
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][7][3])
								{
									Enabled[i][7][3] = true;
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][7][3] = false;
								}

								// Option 5
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][7][4])
								{
									Enabled[i][7][4] = true;
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][7][4] = false;
								}

								// Option 6
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][7][5])
								{
									Enabled[i][7][5] = true;
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][7][5] = false;
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][7][6])
								{
									Enabled[i][7][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][7][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][7][7])
								{
									Enabled[i][7][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][7][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][7][8])
								{
									Enabled[i][7][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][7][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][7][9])
								{
									Enabled[i][7][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][7][9] = false;
								}
							}

							//Sub Menu 9
							else if (MenuIndex[i] == 9)
							{
								// Option 1
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][8][0])
								{
									Enabled[i][8][0] = true;
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									Enabled[i][8][0] = false;
								}

								// Option 2
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][8][1])
								{
									Enabled[i][8][1] = true;
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									Enabled[i][8][1] = false;
								}

								// Option 3
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][8][2])
								{
									Enabled[i][8][2] = true;
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									Enabled[i][8][2] = false;
								}

								// Option 4
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][8][3])
								{
									Enabled[i][8][3] = true;
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][8][3] = false;
								}

								// Option 5
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][8][4])
								{
									Enabled[i][8][4] = true;
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][8][4] = false;
								}

								// Option 6
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][8][5])
								{
									Enabled[i][8][5] = true;
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][8][5] = false;
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][8][6])
								{
									Enabled[i][8][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][8][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][8][7])
								{
									Enabled[i][8][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][8][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][8][8])
								{
									Enabled[i][8][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][8][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][8][9])
								{
									Enabled[i][8][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][8][9] = false;
								}
							}

							//Sub Menu 10
							else if (MenuIndex[i] == 10)
							{
								// Option 1
								if (ScrollBarPos[0][i] == 0 && !Enabled[i][9][0])
								{
									Enabled[i][9][0] = true;
								}

								else if (ScrollBarPos[0][i] == 0)
								{
									Enabled[i][9][0] = false;
								}

								// Option 2
								else if (ScrollBarPos[0][i] == 1 && !Enabled[i][9][1])
								{
									Enabled[i][9][1] = true;
								}

								else if (ScrollBarPos[0][i] == 1)
								{
									Enabled[i][9][1] = false;
								}

								// Option 3
								else if (ScrollBarPos[0][i] == 2 && !Enabled[i][9][2])
								{
									Enabled[i][9][2] = true;
								}

								else if (ScrollBarPos[0][i] == 2)
								{
									Enabled[i][9][2] = false;
								}

								// Option 4
								else if (ScrollBarPos[0][i] == 3 && !Enabled[i][9][3])
								{
									Enabled[i][9][3] = true;
								}

								else if (ScrollBarPos[0][i] == 3)
								{
									Enabled[i][9][3] = false;
								}

								// Option 5
								else if (ScrollBarPos[0][i] == 4 && !Enabled[i][9][4])
								{
									Enabled[i][9][4] = true;
								}

								else if (ScrollBarPos[0][i] == 4)
								{
									Enabled[i][9][4] = false;
								}

								// Option 6
								else if (ScrollBarPos[0][i] == 5 && !Enabled[i][9][5])
								{
									Enabled[i][9][5] = true;
								}

								else if (ScrollBarPos[0][i] == 5)
								{
									Enabled[i][9][5] = false;
								}

								// Option 7
								else if (ScrollBarPos[0][i] == 6 && !Enabled[i][9][6])
								{
									Enabled[i][9][6] = true;
								}

								else if (ScrollBarPos[0][i] == 6)
								{
									Enabled[i][9][6] = false;
								}

								// Option 8
								else if (ScrollBarPos[0][i] == 7 && !Enabled[i][9][7])
								{
									Enabled[i][9][7] = true;
								}

								else if (ScrollBarPos[0][i] == 7)
								{
									Enabled[i][9][7] = false;
								}

								// Option 9
								else if (ScrollBarPos[0][i] == 8 && !Enabled[i][9][8])
								{
									Enabled[i][9][8] = true;
								}

								else if (ScrollBarPos[0][i] == 8)
								{
									Enabled[i][9][8] = false;
								}

								// Option 10
								else if (ScrollBarPos[0][i] == 9 && !Enabled[i][9][9])
								{
									Enabled[i][9][9] = true;
								}

								else if (ScrollBarPos[0][i] == 9)
								{
									Enabled[i][9][9] = false;
								}
							}
							sleep(200);
						}

						// Go back
						if (Buttons::DetectBtn(i, Buttons::R3))
						{
							// If we are at the main menu, close
							// else go back to the main menu
							if (MenuIndex[i] == 0)
							{
								menuOpen[i] = false;
								CloseMenu(i);
							}

							else
							{
								MenuIndex[i] = 0;
								ResetScroll(i);
								MainMenu(i);
							}
							sleep(200);
						}

						// Scroll up
						if (Buttons::DetectBtn(i, Buttons::Up))
						{
							MoveScroll(i, 1);
							sleep(200);
						}

						// Scroll down
						if (Buttons::DetectBtn(i, Buttons::Down))
						{
							MoveScroll(i, 0);
							sleep(200);
						}
					}

					else
					{
						// Open
						if (Buttons::DetectBtn(i, Buttons::Up))
						{
							OpenMenu(i);
							menuOpen[i] = true;
							SetTypewriter(i, "Despicable V1", /*Icon*/1, /*Font*/3, /*FontScale*/3, /*X*/200, /*Y*/35, 0, Normal, 200, 7000, 1000, /*R*/255, /*G*/255, /*B*/255, /*A*/255, /*R*/0, /*G*/255, /*B*/230, /*A*/255);
							Functions::iPrintlnBold(i, "^6Made By: ^5Lord Virus");
							sleep(200);
						}

						// Hud Debug
						if (Buttons::DetectBtn(i, Buttons::Down))
						{
							Functions::iPrintlnBold(i, "^1HUD DEBUG (TEST)");
							HudElem_DestroyAll();
							sleep(1000);
							StoreHuds();
						}
					}
				}
			}

			else
			{
				// Host Lazer
				*reinterpret_cast<char*>(0x000b6703) = 0x01;
				sleep(5000);
				StoreHuds();
				menuLoaded = true;
			}
		}

		else
		{
			menuLoaded = false;
			sleep(10000);
		}
	}
}

sys_ppu_thread_t MW3;

// Ignore Intelli-sense
SYS_MODULE_INFO(MW3, 0, 1, 1);
SYS_MODULE_START(MW3_entry);

SYS_LIB_DECLARE_WITH_STUB( LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME );
SYS_LIB_EXPORT( MW3_export_function, LIBNAME );

// An exported function is needed to generate the project's PRX stub export library
extern "C" int MW3_export_function(void)
{
    return CELL_OK;
}

extern "C" int MW3_entry(void)
{
	// Create a thread
	create_thread(Main_Thread, 0x4AA, 0x7000, "Thread", MW3);

	// Welcome message
	console_write("\n\nDispicable has been initialized.\n\n");
	Dialog::msgdialog_mode = Dialog::MODE_STRING_OK;
	Dialog::Show("Dispicable v1 has been loaded!\nCreated By: Lord Virus\n");

    return SYS_PRX_RESIDENT;
}
