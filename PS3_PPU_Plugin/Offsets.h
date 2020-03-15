#pragma once

namespace Offsets
{
        enum Address
        {
                G_HudElems = 0xF0E10C,
                cl_InGame = 0x018d4c64,
                G_Client_s = 0x110A280,
                G_ClientSize = 0x3980,
                G_Entity = 0xFCA280,
                G_EntitySize = 0x280,
                LocalPlayerName = 0x1BBBC2C,
                ClientName = 0x110A280 + 0x338C,
                FreezeClient = 0x110A280 + 0x35FF,
                SV_GameSendServerCommand = 0x228FA8,
                LevelTime = 0xFC3DB0,
                Teleport = 0x0110A29C,
                G_SoundAliasIndex = 0x001BEBDC,
                Dvar_GetBool = 0x00291060,
                Dvar_GetString = 0x002911A8,
                com_sprintf = 0x00298874,
        };
}