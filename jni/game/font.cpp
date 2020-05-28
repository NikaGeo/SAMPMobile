#include "../main.h"
#include "font.h"

extern uint16_t *wszTextDrawGXT;

void CFont::AsciiToGxtChar(const char *szASCII, uint16_t *wszGXT)
{
	((void (*)(const char *, uint16_t *))(g_libGTASA + 0x00532D00 + 1))(szASCII, wszGXT);
}

void CFont::PrintString(float fX, float fY, char *szText)
{
	CFont::AsciiToGxtChar(szText, wszTextDrawGXT);
	
	// CMessages::InsertNumberInString
	((void (*)(uint16_t *, int, int, int, int, int, int, uint16_t *))(g_libGTASA + 0x004D213C + 1))(wszTextDrawGXT, -1, -1, -1, -1, -1, -1, wszTextDrawGXT);
	
	((void (*)(float, float, uint16_t *))(g_libGTASA + 0x005353B4 + 1))(fX, fY, wszTextDrawGXT);
}

void CFont::SetColor(CRGBA color)
{
	((void (*)(CRGBA))(g_libGTASA + 0x005336F4 + 1))(color);
}

void CFont::SetDropColor(CRGBA color)
{
	((void (*)(CRGBA))(g_libGTASA + 0x0053387C + 1))(color);
}

void CFont::SetEdge(bool on)
{
	((void (*)(bool))(g_libGTASA + 0x0053394C + 1))(on);
}

void CFont::SetJustify(bool on)
{
	((void (*)(bool))(g_libGTASA + 0x005339D0 + 1))(on);
}

void CFont::SetScale(float fValue) 
{
	((void (*)(float))(g_libGTASA + 0x00533694 + 1))(fValue);
}

void CFont::SetScaleXY(float fValueX, float fValueY) 
{
	*(float *)(g_libGTASA + 0x0099D754) = fValueY;
	*(float *)(g_libGTASA + 0x0099D750) = fValueX;
}

void CFont::SetOrientation(unsigned char ucValue) 
{	
	((void (*)(int))(g_libGTASA + 0x005339E8 + 1))(ucValue);
}

void CFont::SetFontStyle(unsigned char ucValue) 
{
	((void (*)(int))(g_libGTASA + 0x00533748 + 1))(ucValue);
}

void CFont::SetProportional(unsigned char ucValue) 
{
	((void (*)(bool))(g_libGTASA + 0x00533970 + 1))(ucValue);
}

void CFont::SetRightJustifyWrap(float fValue) 
{	
	((void (*)(float))(g_libGTASA + 0x0053384C + 1))(fValue);
}

void CFont::SetBackground(bool enable, bool includeWrap) 
{
	((void (*)(bool, bool))(g_libGTASA + 0x00533988 + 1))(enable, includeWrap);
}

void CFont::SetBackgroundColor(CRGBA uiColor) 
{
	((void (*)(CRGBA))(g_libGTASA + 0x005339A4 + 1))(uiColor);
}

void CFont::SetWrapx(float fValue) 
{
	((void (*)(float))(g_libGTASA + 0x0053381C + 1))(fValue);
}

void CFont::SetCentreSize(float fValue) 
{
	((void (*)(float))(g_libGTASA + 0x00533834 + 1))(fValue);
}

void CFont::SetDropShadowPosition(signed char scValue) 
{
	((void (*)(short))(g_libGTASA + 0x005338DC + 1))(scValue);
}

float CFont::GetHeight(bool unk)
{
	return ((float (*)(bool))(g_libGTASA + 0x005330F0 + 1))(unk);
}

float CFont::GetStringWidth(uint16_t* str)
{
	return ((float (*)(uint16_t*))(g_libGTASA + 0x00534BAC + 1))(str);
}
void CFont::GetTextRect(PRECT rect, float x, float y)
{
	((float (*)(PRECT, float, float, uint16_t *))(g_libGTASA + 0x005352DC + 1))(rect, x, y, wszTextDrawGXT);
}