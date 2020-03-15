#pragma once

union color_s
{
        struct
        {
                int8_t r;            
                int8_t g;            
                int8_t b;      
                int8_t a;  
        };
        int32_t rgba;
};
 
struct hudelem_s
{
        int type;
        float X;
        float Y;
        float Z;
        int targetEntNum;
        float fontScale;
        float fromFontScale;
        int fontScaleStartTime;
        int fontScaleTime;
        int font;
        int alignOrg;
        int alignScreen;
        color_s color;
        color_s fromColor;
        int fadeStartTime;
        int fadeTime;
        int label;
        int Width;
        int Height;
        int materialIndex;
        int fromWidth;
        int fromHeight;
        int scaleStartTime;
        int scaleTime;
        float fromX;
        float fromY;
        int fromAlignOrg;
        int fromAlignScreen;
        int moveStartTime;
        int moveTime;
        int time;
        int duration;
        float value;
        int text;
        float sort;
        color_s glowColor;
        int fxBirthTime;
        int fxLetterTime;
        int fxDecayStartTime;
        int fxDecayDuration;
        int soundID;
        int flags;
};
 
struct game_hudelem_s
{
        hudelem_s elem;
        int clientNum;
        int team;
        int archived;
};
 
int G_LocalizedStringIndex(const char* Text)
{
        opd_s Localized = { 0x001BE6CC, TOC };
        int(*LocalizedStringIndex)(const char* Text) = (int(*)(const char*))&Localized;
        return LocalizedStringIndex(Text);
}
 
opd_s GMI = { 0x001BE744, TOC };
int(*GetMaterialIndex)(const char* Material) = (int(*)(const char*))&GMI;
 
game_hudelem_s* HudElem_Alloc()
{
        for (int i = 0; i < 1024; i++)
        {
                game_hudelem_s* elem = (game_hudelem_s*)(0x00F0E10C + (i * 0xB4));
                if (!elem->elem.type) return elem;
        }
        return (game_hudelem_s*)-1;
}
 
enum TypewriterTextTypes
{
        Normal = 0x800,
        Classic = 0x4000
};
 
int GetLevelTime()
{
        return *(int*)Offsets::LevelTime;
}
 
game_hudelem_s* setShader(int clientIndex, int Shader, int Width, int Height, float X, float Y, int Allign = 5, unsigned char R = 0, unsigned char G = 0, unsigned char B = 0, unsigned char A = 0)
{
        game_hudelem_s* elem = HudElem_Alloc();
        elem->clientNum = clientIndex;
        elem->elem.type = 4;
        *(int*)0x00F3B198 = 1;
        elem->elem.materialIndex = Shader;
        *(int*)0x00F3B198 = 0;
        elem->elem.Width = Width;
        elem->elem.Height = Height;
        elem->elem.X = X;
        elem->elem.Y = Y;
        elem->elem.alignOrg = Allign;
        elem->elem.color.r = R;
        elem->elem.color.g = G;
        elem->elem.color.b = B;
        elem->elem.color.a = A;
        return elem;
}
 
game_hudelem_s* setText(int clientIndex, const char* Text, int Font, float FontScale, float X, float Y, int Allign, unsigned char R = 0, unsigned char G = 0, unsigned char B = 0, unsigned char A = 0, unsigned char glowR = 0, unsigned char glowG = 0, unsigned char glowB = 0, unsigned char glowA = 0)
{
        game_hudelem_s* Elem = HudElem_Alloc();
        Elem->clientNum = clientIndex;
        Elem->elem.type = 1;
        Elem->elem.text = G_LocalizedStringIndex(Text);
        Elem->elem.font = Font;
        Elem->elem.fontScale = FontScale;
        if (Allign != 0)
        { Elem->elem.alignOrg = 5; Elem->elem.alignScreen = Allign; Elem->elem.X = X; Elem->elem.Y = Y; }
        else
        { Elem->elem.X = X; Elem->elem.Y = Y; }
        Elem->elem.color.r = R;
        Elem->elem.color.g = G;
        Elem->elem.color.b = B;
        Elem->elem.color.a = A;
        Elem->elem.glowColor.r = glowR;
        Elem->elem.glowColor.g = glowG;
        Elem->elem.glowColor.b = glowB;
        Elem->elem.glowColor.a = glowA;
        return Elem;
}
 
void ChangeText(game_hudelem_s* elemIndex, const char* Text)
{
        elemIndex->elem.text = G_LocalizedStringIndex(Text);
}
 
void MoveOverTime(game_hudelem_s* elemIndex, short time, float X, float Y)
{
        elemIndex->elem.fromX = elemIndex->elem.X;
        elemIndex->elem.fromY = elemIndex->elem.Y;
        elemIndex->elem.moveStartTime = GetLevelTime();
        elemIndex->elem.moveTime = time;
        elemIndex->elem.X = X;
        elemIndex->elem.Y = Y;
}
 
void MoveShaderXY(game_hudelem_s* elemIndex, float X, float Y)
{
        elemIndex->elem.X = X;
        elemIndex->elem.Y = Y;
}
 
void ScaleOverTime(game_hudelem_s* elemIndex, short time, short width, short height)
{
        elemIndex->elem.fromHeight = elemIndex->elem.Height;
        elemIndex->elem.fromWidth = elemIndex->elem.Width;
        elemIndex->elem.scaleStartTime = GetLevelTime();
        elemIndex->elem.scaleTime= time;
        elemIndex->elem.Width = width;
        elemIndex->elem.Height = height;
}
 
void FontScaleOverTime(game_hudelem_s* elemIndex, float FontSize, short time)
{
        elemIndex->elem.fromFontScale = elemIndex->elem.fontScale;
        elemIndex->elem.fontScaleStartTime = GetLevelTime();
        elemIndex->elem.fontScaleTime = time;
        elemIndex->elem.fontScale = FontSize;
}
 
void FontScale(game_hudelem_s* elemIndex, float FontSize)
{
        elemIndex->elem.fromFontScale = elemIndex->elem.fontScale;
        elemIndex->elem.fontScale = FontSize;
}
 
 
game_hudelem_s* typewriter;
bool typran;
 
void SetTypewriter(int clientIndex, char* Text, int IconType, int Font, float FontSize, float X, float Y, char align, int WriteType = Normal, short Lettertime = 200, short fxDecayStartTime = 7000, short fxDecayDuration = 1000, char R = 255, char G = 255, char B = 255, char A = 255, char GlowR = 255, char GlowG = 255, char GlowB = 255, char GlowA = 0)
{
        if(!typran)
        {
                game_hudelem_s* elemIndex = setText(clientIndex, Text, Font, FontSize, X, Y, align, R, G, B, A, GlowR, GlowG, GlowB, GlowA);
                elemIndex->elem.flags = WriteType;
                elemIndex->elem.fxBirthTime = GetLevelTime();
                elemIndex->elem.fxLetterTime = Lettertime;
                elemIndex->elem.fxDecayStartTime = fxDecayStartTime;
                elemIndex->elem.fxDecayDuration = fxDecayDuration;
                typewriter = elemIndex;
                typran = true;
        }
        else
        {
                game_hudelem_s* elemIndex = typewriter;
                elemIndex->clientNum = clientIndex;
                elemIndex->elem.type = 1;
                elemIndex->elem.text = G_LocalizedStringIndex(Text);
                elemIndex->elem.font = Font;
                elemIndex->elem.fontScale = FontSize;
                if (align != 0)
                { elemIndex->elem.alignOrg = 5; elemIndex->elem.alignScreen = align; elemIndex->elem.X = X; elemIndex->elem.Y = Y; }
                else
                { elemIndex->elem.X = X; elemIndex->elem.Y = Y; }
                elemIndex->elem.color.r = R;
                elemIndex->elem.color.g = G;
                elemIndex->elem.color.b = B;
                elemIndex->elem.color.a = A;
                elemIndex->elem.glowColor.r = GlowR;
                elemIndex->elem.glowColor.g = GlowG;
                elemIndex->elem.glowColor.b = GlowB;
                elemIndex->elem.glowColor.a = GlowA;
                elemIndex->elem.flags = WriteType;
                elemIndex->elem.fxBirthTime = GetLevelTime();
                elemIndex->elem.fxLetterTime = Lettertime;
                elemIndex->elem.fxDecayStartTime = fxDecayStartTime;
                elemIndex->elem.fxDecayDuration = fxDecayDuration;
        }
}
 
game_hudelem_s* typewriter1;
bool Message;
 
void SetMessage(int clientIndex, char* Text, char* Text2, int WriteType = Normal, short Lettertime = 200, short fxDecayStartTime = 7000, short fxDecayDuration = 1000, char R = 255, char G = 255, char B = 255, char A = 255, char GlowR = 255, char GlowG = 255, char GlowB = 255, char GlowA = 0)
{
        if(!Message)
        {
                game_hudelem_s* elemIndex1 = setText(clientIndex, Text, 3, 1.5, 325, 130, 1, R, G, B, A, GlowR, GlowG, GlowB, GlowA);
                elemIndex1->elem.flags = WriteType;
                elemIndex1->elem.fxBirthTime = GetLevelTime();
                elemIndex1->elem.fxLetterTime = Lettertime;
                elemIndex1->elem.fxDecayStartTime = fxDecayStartTime;
                elemIndex1->elem.fxDecayDuration = fxDecayDuration;
                typewriter = elemIndex1;
                game_hudelem_s* elemIndex = setText(clientIndex, Text2, 3, 1.5, 325, 150, 1, R, G, B, A, GlowR, GlowG, GlowB, GlowA);
                elemIndex->elem.flags = WriteType;
                elemIndex->elem.fxBirthTime = GetLevelTime();
                elemIndex->elem.fxLetterTime = Lettertime;
                elemIndex->elem.fxDecayStartTime = fxDecayStartTime;
                elemIndex->elem.fxDecayDuration = fxDecayDuration;
                typewriter1 = elemIndex;
                Message = true;
                typran = true;
        }
        else
        {
                game_hudelem_s* elemIndex1 = typewriter;
                elemIndex1->clientNum = clientIndex;
                elemIndex1->elem.type = 1;
                elemIndex1->elem.text = G_LocalizedStringIndex(Text);
                elemIndex1->elem.font = 3;
                elemIndex1->elem.fontScale = 1.5;
                elemIndex1->elem.alignOrg = 5; elemIndex1->elem.alignScreen = 1; elemIndex1->elem.X = 325; elemIndex1->elem.Y = 130;
                elemIndex1->elem.color.r = R;
                elemIndex1->elem.color.g = G;
                elemIndex1->elem.color.b = B;
                elemIndex1->elem.color.a = A;
                elemIndex1->elem.glowColor.r = GlowR;
                elemIndex1->elem.glowColor.g = GlowG;
                elemIndex1->elem.glowColor.b = GlowB;
                elemIndex1->elem.glowColor.a = GlowA;
                elemIndex1->elem.flags = WriteType;
                elemIndex1->elem.fxBirthTime = GetLevelTime();
                elemIndex1->elem.fxLetterTime = Lettertime;
                elemIndex1->elem.fxDecayStartTime = fxDecayStartTime;
                elemIndex1->elem.fxDecayDuration = fxDecayDuration;
                game_hudelem_s* elemIndex = typewriter1;
                elemIndex->clientNum = clientIndex;
                elemIndex->elem.type = 1;
                elemIndex->elem.text = G_LocalizedStringIndex(Text2);
                elemIndex->elem.font = 3;
                elemIndex->elem.fontScale = 1.5;
                elemIndex->elem.alignOrg = 5; elemIndex->elem.alignScreen = 1; elemIndex->elem.X = 325; elemIndex->elem.Y = 150;
                elemIndex->elem.color.r = R;
                elemIndex->elem.color.g = G;
                elemIndex->elem.color.b = B;
                elemIndex->elem.color.a = A;
                elemIndex->elem.glowColor.r = GlowR;
                elemIndex->elem.glowColor.g = GlowG;
                elemIndex->elem.glowColor.b = GlowB;
                elemIndex->elem.glowColor.a = GlowA;
                elemIndex->elem.flags = WriteType;
                elemIndex->elem.fxBirthTime = GetLevelTime();
                elemIndex->elem.fxLetterTime = Lettertime;
                elemIndex->elem.fxDecayStartTime = fxDecayStartTime;
                elemIndex->elem.fxDecayDuration = fxDecayDuration;
        }
}
 
void SetGlow(game_hudelem_s* Text, int GlowR, int GlowG, int GlowB, int GlowA)
{
        Text->elem.glowColor.r = GlowR;
        Text->elem.glowColor.g = GlowG;
        Text->elem.glowColor.b = GlowB;
        Text->elem.glowColor.a = GlowA;
}
 
void FadeOverTime(game_hudelem_s* Elem, int Time, int R, int G, int B, int A)
{
        Elem->elem.fromColor = Elem->elem.color;
        Elem->elem.color.r = R;
        Elem->elem.color.g = G;
        Elem->elem.color.b = B;
        Elem->elem.color.a = A;
        Elem->elem.fadeTime = Time;
        Elem->elem.fadeStartTime = GetLevelTime();
}
 
void FadeOverTime2(game_hudelem_s* Elem, int Time, int R, int G, int B, int A)
{
        Elem->elem.fromColor = Elem->elem.color;
        Elem->elem.color.r = R;
        Elem->elem.color.g = G;
        Elem->elem.color.b = B;
        Elem->elem.color.a = A;
        Elem->elem.fadeTime = Time;
        Elem->elem.fadeStartTime = GetLevelTime();
}
 
void FadeOverTimeGlow(game_hudelem_s* Elem, float Time, int glowR, int glowG, int glowB, int glowA)
{
        Elem->elem.fromColor = Elem->elem.color;
        Elem->elem.glowColor.r = glowR;
        Elem->elem.glowColor.g = glowG;
        Elem->elem.glowColor.b = glowB;
        Elem->elem.glowColor.a = glowA;
        Elem->elem.fadeTime = Time;
        Elem->elem.fadeStartTime = GetLevelTime();
};
 
void HudElem_DestroyAll()
{
        opd_s HDA = { 0x001872E8, TOC };
        void(*HudElemDestroyAll)() = (void(*)())&HDA;
        HudElemDestroyAll();
}