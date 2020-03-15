#pragma once

namespace Functions
{
	bool InfAmmo[18] = { false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false };
	bool FOVlastdead[18] = { false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false };

	int G_Client(int clientIndex) { return Offsets::G_Client_s + (clientIndex * Offsets::G_ClientSize); }
	int G_Entity(int clientIndex) { return Offsets::G_Entity + (clientIndex * Offsets::G_EntitySize); }

	opd_s Com_sprintf_t = { Offsets::com_sprintf, TOC };
	int(*Com_sprintf)(char *dest, int size, const char *fmt, ...) = (int(*)(char*, int, char const *, ...))&Com_sprintf_t;

	opd_s SV = { Offsets::SV_GameSendServerCommand, TOC };
	void(*SV_GSSC)(int client, int type, char* cmd) = (void(*)(int, int, char*))&SV;


	opd_s gs = { Offsets::Dvar_GetString, TOC };
	const char*(*Dvar_GetString)(const char* Dvar) = (const char*(*)(const char*))&gs;

	bool inGame()
	{
		if (*reinterpret_cast<char*>(Offsets::cl_InGame) != 1) return false;
		return true;
	}

	bool IsDead(int client)
	{
		return *(bool*)(G_Client(client) + 0x3313);
	}

	void iPrintlnBold(int client, char* text)
	{
		char buf[100];
		strcpy(buf, "c \"");
		strcat(buf, text);
		SV_GSSC(client, 0, buf);
	}

	void iPrintln(int client, char* text)
	{
		char buf[100];
		strcpy(buf, "f \"");
		strcat(buf, text);
		SV_GSSC(client, 0, buf);
	}

	void SetVision(int client, char* Vision)
	{
		char buf[100];
		strcpy(buf, "j \"");
		strcat(buf, Vision);
		SV_GSSC(client, 0, buf);
	}

	void SetFOV(int client, char* fov)
	{
		char buf[100];
		char text[100];

		// Send Server Command
		strcpy(buf, "q  cg_fov \"");
		strcat(buf, fov);
		SV_GSSC(client, 0, buf);

		// iPrintln
		strcpy(text, "^7FOV: ^2 ");
		strcat(text, fov);
		iPrintln(client, text);
	}

	void LoopFOV(int client)
	{
		if (IsDead(client) == FOVlastdead[client] && Enabled[client][0][4])
		{
			FOVlastdead[client] = false;
		}

		else if (IsDead(client) == FOVlastdead[client] && Enabled[client][0][4])
		{
			FOVlastdead[client] = true;
			sleep(2000);
			SetFOV(client, "95");
		}
	}

	void SetThirdPerson(int client, bool enabled)
	{
		if (enabled)
		{
			SV_GSSC(client, 0, "q cg_thirdPerson 1");
		}

		else
		{
			SV_GSSC(client, 0, "q cg_thirdPerson 0");
		}
	}

	void KickWithMessage(int client, char* Message)
	{
		char buf[100];
		strcpy(buf, "r \"");
		strcat(buf, Message);
		SV_GSSC(client, 0, buf);
	}

	void GodMode(int client, bool enabled)
	{
		if (enabled)
		{
			*reinterpret_cast<char*>(0x0FCA41E + (0x280 * client)) = 0xFF;
			iPrintln(client, "^7God mode: ^2On");
		}

		else
		{
			*reinterpret_cast<char*>(0x0FCA41E + (0x280 * client)) = 0x00;
			iPrintln(client, "^7God mode: ^1Off");
		}
	}

	void UFOMode(int client, bool enabled)
	{
		if (enabled)
		{
			*reinterpret_cast<char*>(0x0110d87f + (0x3980 * client)) = 0x02;
			iPrintln(client, "^7UFO mode: ^2On");
		}

		else
		{
			*reinterpret_cast<char*>(0x0110d87f + (0x3980 * client)) = 0x00;
			iPrintln(client, "^7UFO mode: ^1Off");
		}
	}

	void InfiniteAmmo(int client, bool enabled)
	{

		InfAmmo[client] = enabled;
		if (enabled)
		{
			iPrintln(client, "^7Infinite Ammo: ^2On");
			*reinterpret_cast<char*>(0x0110a6ab + (0x3980 * client)) = 0xFF;
			*reinterpret_cast<char*>(0x0110a693 + (0x3980 * client)) = 0xFF;
			*reinterpret_cast<char*>(0x0110a6b7 + (0x3980 * client)) = 0xFF;
			*reinterpret_cast<char*>(0x0110a69f + (0x3980 * client)) = 0xFF;
		}

		else
		{
			iPrintln(client, "^7Infinite Ammo: ^1Off");
			*reinterpret_cast<char*>(0x0110a6ab + (0x3980 * client)) = 0x64;
			*reinterpret_cast<char*>(0x0110a693 + (0x3980 * client)) = 0x64;
			*reinterpret_cast<char*>(0x0110a6b7 + (0x3980 * client)) = 0x64;
			*reinterpret_cast<char*>(0x0110a69f + (0x3980 * client)) = 0x64;
		}
	}

	void LoopInfAmmo(int client)
	{
		if (InfAmmo[client])
		{
			*reinterpret_cast<char*>(0x0110a6ab + (0x3980 * client)) = 0xFF;
			*reinterpret_cast<char*>(0x011a693 + (0x3980 * client)) = 0xFF;
			*reinterpret_cast<char*>(0x0110a6b7 + (0x3980 * client)) = 0xFF;
			*reinterpret_cast<char*>(0x0110a69f + (0x3980 * client)) = 0xFF;
		}
	}

	void Dvar(int client, bool enabled)
	{
		if (enabled)
		{
			SV_GSSC(client, 0, "q  7");
			iPrintln(client, "^7Dvar: ^2On");
		}

		else
		{
			SV_GSSC(client, 0, "q reset cg_gun_x");
			iPrintln(client, "^7Dvar: ^1Off");
		}
	}

	void SuperJump(bool enabled)
	{
		if (enabled)
		{
			*reinterpret_cast<char*>(0x000019780) = 0x44, 0xF9, 0xC0;
			iPrintln(-1, "^7Super Jump: ^2On");
		}

		else
		{
			*reinterpret_cast<char*>(0x000019780) = 0x42, 0x9C, 0x00;
			iPrintln(-1, "^7Super Jump: ^1Off");
		}
	}

	void SuperSpeed(bool enabled)
	{
		if (enabled)
		{
			*reinterpret_cast<char*>(0x00173BB2) = 0x02;
			iPrintln(-1, "^7Super Speed: ^2On");
		}

		else
		{
			*reinterpret_cast<char*>(0x00173BB2) = 0x00;
			iPrintln(-1, "^7Super Speed: ^1Off");
		}
	}

	void FreezeLobby(bool enabled)
	{
		if (enabled)
		{
			*reinterpret_cast<char*>(0x00173BB2) = 0x00;
			*reinterpret_cast<char*>(0x00173BB3) = 0x00;
			iPrintln(-1, "^7Lobby: ^5Frozen");
		}

		else
		{
			*reinterpret_cast<char*>(0x00173BB2) = 0x00;
			*reinterpret_cast<char*>(0x00173BB3) = 0xBE;
			iPrintln(-1, "^7Lobby: ^2Unfrozen");
		}
	}

	//////////
	//Aim bot//
	////////////
	/*

	bool CheckTeam(int Client, int OtherClient)
	{
		int Attacker = *(int*)(G_Client(Client) + 0x33D7);
		int Victim = *(int*)(G_Client(OtherClient) + 0x33D7);
		if (Attacker == Victim)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool CheckIfLiving(int client)
	{
		if (*(char*)(G_Entity(client) + 0x19F) != 0)
		{
			return true;
		}
		else return false;
	}

	bool ClientIsInGame(int clientIndex)
	{
		if (*(int*)G_Client(clientIndex) != 0)
			return true;
		else return false;
	}

	struct Vec3
	{
		float x, y, z;
	};

	Vec3 Difference;
	Vec3 GetVec(Vec3 Attacker, Vec3 Target)
	{
		Difference.x = (Target.x - Attacker.x);
		Difference.y = (Target.y - Attacker.y);
		Difference.z = (Target.z - Attacker.z);
		return Difference;
	}

	float dx, dy, dz;
	float Get3dDistance(Vec3 c1, Vec3 c2)
	{
		float dx = c2.x - c1.x;
		float dy = c2.y - c1.y;
		float dz = c2.z - c1.z;

		return sqrt((float)((dx * dx) + (dy * dy) + (dz * dz)));
	}

	Vec3 vec;
	Vec3 GetPlayerOrigin(int Client)
	{
		vec = *(Vec3*)(G_Client(Client) + 0x1C);
		return vec;
	}

	Vec3 VecV;
	Vec3 GetPlayerOriginVictim(int Client)
	{
		VecV = *(Vec3*)(G_Client(Client) + 0x1C);
		VecV.z -= 24;
		return VecV;
	}

	int Nearest;
	int GetNearestPlayer(int Client)
	{
		float MaxDistance = 99999999;
		for (int i = 0; i < 12; i++)
		{
			Vec3 Attacker = GetPlayerOrigin(Client);
			Vec3 Vic = GetPlayerOrigin(i);
			float ActualDistance = Get3dDistance(Attacker, Vic);
			if ((i != Client) && CheckIfLiving(i) && ClientIsInGame(i))
			{
				if (cstrcmp(Functions::Dvar_GetString("ui_gametype"), "dm") == 0)
				{
					if (ActualDistance < MaxDistance)
					{
						Nearest = i;
						MaxDistance = ActualDistance;
					}
				}
				else
				{
					if (!CheckTeam(Client, i))
					{
						if (ActualDistance < MaxDistance)
						{
							Nearest = i;
							MaxDistance = ActualDistance;
						}
					}
				}
			}
		}
		return Nearest;
	}

	float angles[3];
	float* vectoangles(Vec3 Angles)
	{
		float forward;
		float yaw, pitch;
		float PI = 3.1415926535897931;
		if (Angles.x == 0 && Angles.y == 0)
		{
			yaw = 0;
			if (Angles.z > 0) pitch = 90.00;
			else pitch = 270.00;
		}
		else
		{
			if (Angles.x != -1) yaw = (float)(atan2((double)Angles.y, (double)Angles.x) * 180.00 / PI);
			else if (Angles.y > 0) yaw = 90.00;
			else yaw = 270;
			if (yaw < 0) yaw += 360.00;

			forward = (float)sqrt((double)(Angles.x * Angles.x + Angles.y * Angles.y));
			pitch = (float)(atan2((double)Angles.z, (double)forward) * 180.00 / PI);
			if (pitch < 0) pitch += 360.00;
		}
		angles[0] = -pitch;
		angles[1] = yaw;
		angles[2] = 0;

		return angles;
	}

	opd_s Setangles_t = { 0x001767E0, TOC };
	void(*SetClientViewAnlges)(int Ent, float* Angles) = (void(*)(int, float*))&Setangles_t;

	void SetViewAngles(int Client)
	{
		int Victim = GetNearestPlayer(Client);
		float* Angles = vectoangles(GetVec(GetPlayerOrigin(Client), GetPlayerOriginVictim(Victim)));
		SetClientViewAnlges(G_Entity(Client), Angles);
	}
	*/
}

