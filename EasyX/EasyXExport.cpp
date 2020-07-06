#include "pch.h"
#include "EasyXDynamic.h"
#include "EasyX.h"

HWND easyx::initgraph(int width, int height, int flag)
{
	return ::initgraph(width, height, flag);
}
void easyx::closegraph()
{
	return ::closegraph();
}

void easyx::cleardevice()
{
	return ::cleardevice();
}
void easyx::setcliprgn(HRGN hrgn)
{
	return ::setcliprgn(hrgn);
}
void easyx::clearcliprgn()
{
	return ::clearcliprgn();
}
void easyx::getlinestyle(LINESTYLE* pstyle)
{
	return ::getlinestyle(pstyle);
}
void easyx::setlinestyle(const LINESTYLE* pstyle)
{
	return ::setlinestyle(pstyle);
}
void easyx::setlinestyle(int style, int thickness, const DWORD* puserstyle, DWORD userstylecount)
{
	return ::setlinestyle(style, thickness, puserstyle, userstylecount);
}
void easyx::getfillstyle(FILLSTYLE* pstyle)
{
	return ::getfillstyle(pstyle);
}
void easyx::setfillstyle(const FILLSTYLE* pstyle)
{
	return ::setfillstyle(pstyle);
}
void easyx::setfillstyle(int style, long hatch, IMAGE* ppattern)
{
	return ::setfillstyle(style, hatch, ppattern);
}
void easyx::setfillstyle(BYTE* ppattern8x8)
{
	return ::setfillstyle(ppattern8x8);
}

void easyx::setorigin(int x, int y)
{
	return ::setorigin(x, y);
}
void easyx::getaspectratio(float* pxasp, float* pyasp)
{
	return ::getaspectratio(pxasp, pyasp);
}
void easyx::setaspectratio(float xasp, float yasp)
{
	return ::setaspectratio(xasp, yasp);
}

int easyx::getrop2()
{
	return ::getrop2();
}
void easyx::setrop2(int mode)
{
	return ::setrop2(mode);
}
int easyx::getpolyfillmode()
{
	return ::getpolyfillmode();
}
void easyx::setpolyfillmode(int mode)
{
	return ::setpolyfillmode(mode);
}

void easyx::graphdefaults()
{
	return ::graphdefaults();
}

COLORREF easyx::getlinecolor()
{
	return ::getlinecolor();
}
void easyx::setlinecolor(COLORREF color)
{
	return ::setlinecolor(color);
}
COLORREF easyx::gettextcolor()
{
	return ::gettextcolor();
}
void easyx::settextcolor(COLORREF color)
{
	return ::settextcolor(color);
}

COLORREF easyx::getfillcolor()
{
	return ::getfillcolor();
}

void easyx::setfillcolor(COLORREF color)
{
	return ::setfillcolor(color);
}

COLORREF easyx::getbkcolor()
{
	return ::getbkcolor();
}



void easyx::setbkcolor(COLORREF color)
{
	return ::setbkcolor(color);
}

int  easyx::getbkmode()
{
	return ::getbkmode();
}

void easyx::setbkmode(int mode)
{
	return ::setbkmode(mode);
}

COLORREF easyx::RGBtoGRAY(COLORREF rgb)
{
	return ::RGBtoGRAY(rgb);
}
void easyx::RGBtoHSL(COLORREF rgb, float* H, float* S, float* L)
{
	return ::RGBtoHSL(rgb, H, S, L);
}
void easyx::RGBtoHSV(COLORREF rgb, float* H, float* S, float* V)
{
	return ::RGBtoHSV(rgb, H, S, V);
}
COLORREF easyx::HSLtoRGB(float H, float S, float L)
{
	return ::HSLtoRGB(H, S, L);
}
COLORREF easyx::HSVtoRGB(float H, float S, float V)
{
	return ::HSVtoRGB(H, S, V);
}


COLORREF easyx::getpixel(int x, int y)
{
	return ::getpixel(x, y);
}

void easyx::putpixel(int x, int y, COLORREF color)
{
	return ::putpixel(x, y, color);
}


void easyx::moveto(int x, int y)
{
	return ::moveto(x, y);
}

void easyx::moverel(int dx, int dy)
{
	return ::moverel(dx, dy);
}


void easyx::line(int x1, int y1, int x2, int y2)
{
	return ::line(x1, y1, x2, y2);
}

void easyx::linerel(int dx, int dy)
{
	return ::linerel(dx, dy);
}

void easyx::lineto(int x, int y)
{
	return ::lineto(x, y);
}


void easyx::rectangle(int left, int top, int right, int bottom)
{
	return ::rectangle(left, top, right, bottom);
}

void easyx::fillrectangle(int left, int top, int right, int bottom)
{
	return ::fillrectangle(left, top, right, bottom);
}

void easyx::solidrectangle(int left, int top, int right, int bottom)
{
	return ::solidrectangle(left, top, right, bottom);
}

void easyx::clearrectangle(int left, int top, int right, int bottom)
{
	return ::clearrectangle(left, top, right, bottom);
}


void easyx::circle(int x, int y, int radius)
{
	return ::circle(x, y, radius);
}

void easyx::fillcircle(int x, int y, int radius)
{
	return ::fillcircle(x, y, radius);
}

void easyx::solidcircle(int x, int y, int radius)
{
	return ::solidcircle(x, y, radius);
}

void easyx::clearcircle(int x, int y, int radius)
{
	return ::clearcircle(x, y, radius);
}


void easyx::ellipse(int left, int top, int right, int bottom)
{
	return ::ellipse(left, top, right, bottom);
}

void easyx::fillellipse(int left, int top, int right, int bottom)
{
	return ::fillellipse(left, top, right, bottom);
}

void easyx::solidellipse(int left, int top, int right, int bottom)
{
	return ::solidellipse(left, top, right, bottom);
}

void easyx::clearellipse(int left, int top, int right, int bottom)
{
	return ::clearellipse(left, top, right, bottom);
}


void easyx::roundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight)
{
	return ::roundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
}

void easyx::fillroundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight)
{
	return ::fillroundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
}

void easyx::solidroundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight)
{
	return ::solidroundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
}

void easyx::clearroundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight)
{
	return ::clearroundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
}


void easyx::arc(int left, int top, int right, int bottom, double stangle, double endangle)
{
	return ::arc(left, top, right, bottom, stangle, endangle);
}

void easyx::pie(int left, int top, int right, int bottom, double stangle, double endangle)
{
	return ::pie(left, top, right, bottom, stangle, endangle);
}

void easyx::fillpie(int left, int top, int right, int bottom, double stangle, double endangle)
{
	return ::fillpie(left, top, right, bottom, stangle, endangle);
}

void easyx::solidpie(int left, int top, int right, int bottom, double stangle, double endangle)
{
	return ::solidpie(left, top, right, bottom, stangle, endangle);
}

void easyx::clearpie(int left, int top, int right, int bottom, double stangle, double endangle)
{
	return ::clearpie(left, top, right, bottom, stangle, endangle);
}


void easyx::polyline(const POINT * points, int num)
{
	return ::polyline(points, num);
}

void easyx::polygon(const POINT * points, int num)
{
	return ::polygon(points, num);
}

void easyx::fillpolygon(const POINT * points, int num)
{
	return ::fillpolygon(points, num);
}

void easyx::solidpolygon(const POINT * points, int num)
{
	return ::solidpolygon(points, num);
}

void easyx::clearpolygon(const POINT * points, int num)
{
	return ::clearpolygon(points, num);
}


void easyx::polybezier(const POINT * points, int num)
{
	return ::polybezier(points, num);
}

void easyx::floodfill(int x, int y, COLORREF color, int filltype)
{
	return ::floodfill(x, y, color, filltype);
}


void easyx::outtext(LPCTSTR str)
{
	return ::outtext(str);
}

void easyx::outtext(TCHAR c)
{
	return ::outtext(c);
}

void easyx::outtextxy(int x, int y, LPCTSTR str)
{
	return ::outtextxy(x, y, str);
}

void easyx::outtextxy(int x, int y, TCHAR c)
{
	return ::outtextxy(x, y, c);
}

int easyx::textwidth(LPCTSTR str)
{
	return ::textwidth(str);
}

int easyx::textwidth(TCHAR c)
{
	return ::textwidth(c);
}

int easyx::textheight(LPCTSTR str)
{
	return ::textheight(str);
}

int easyx::textheight(TCHAR c)
{
	return ::textheight(c);
}

int easyx::drawtext(LPCTSTR str, RECT * pRect, UINT uFormat)
{
	return ::drawtext(str, pRect, uFormat);
}

int easyx::drawtext(TCHAR c, RECT * pRect, UINT uFormat)
{
	return ::drawtext(c, pRect, uFormat);
}


void easyx::settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace)
{
	return ::settextstyle(nHeight, nWidth, lpszFace);
}
void easyx::settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut)
{
	return ::settextstyle(nHeight, nWidth, lpszFace, nEscapement, nOrientation, nWeight, bItalic, bUnderline, bStrikeOut);
}
void easyx::settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut, BYTE fbCharSet, BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily)
{
	return ::settextstyle(nHeight, nWidth, lpszFace, nEscapement, nOrientation, nWeight, bItalic, bUnderline, bStrikeOut, fbCharSet, fbOutPrecision, fbClipPrecision, fbQuality, fbPitchAndFamily);
}
void easyx::settextstyle(const LOGFONT * font)
{
	return ::settextstyle(font);
}

void easyx::gettextstyle(LOGFONT * font)
{
	return ::gettextstyle(font);
}




	// 图像处理函数
void easyx::loadimage(IMAGE * pDstImg, LPCTSTR pImgFile, int nWidth, int nHeight, bool bResize)
{
	return ::loadimage(pDstImg, pImgFile, nWidth, nHeight, bResize);
}

void easyx::loadimage(IMAGE * pDstImg, LPCTSTR pResType, LPCTSTR pResName, int nWidth, int nHeight, bool bResize)
{
	return ::loadimage(pDstImg, pResType, pResName, nWidth, nHeight, bResize);
}

void easyx::saveimage(LPCTSTR pImgFile, IMAGE * pImg)
{
	return ::saveimage(pImgFile, pImg);
}

void easyx::getimage(IMAGE * pDstImg, int srcX, int srcY, int srcWidth, int srcHeight)
{
	return ::getimage(pDstImg, srcX, srcY, srcWidth, srcHeight);
}

void easyx::putimage(int dstX, int dstY, const IMAGE * pSrcImg, DWORD dwRop)
{
	return ::putimage(dstX, dstY, pSrcImg, dwRop);
}

void easyx::putimage(int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE * pSrcImg, int srcX, int srcY, DWORD dwRop)
{
	return ::putimage(dstX, dstY, dstWidth, dstHeight, pSrcImg, srcX, srcY, dwRop);
}

void easyx::rotateimage(IMAGE* dstimg, IMAGE* srcimg, double radian, COLORREF bkcolor, bool autosize, bool highquality)
{
	return ::rotateimage(dstimg, srcimg, radian, bkcolor, autosize, highquality);
}
void easyx::Resize(IMAGE * pImg, int width, int height)
{
	return ::Resize(pImg, width, height);
}

DWORD* easyx::GetImageBuffer(IMAGE * pImg)
{
	return ::GetImageBuffer(pImg);
}

IMAGE* easyx::GetWorkingImage()
{
	return ::GetWorkingImage();
}

void easyx::SetWorkingImage(IMAGE * pImg)
{
	return ::SetWorkingImage(pImg);
}

HDC easyx::GetImageHDC(IMAGE * pImg)
{
	return ::GetImageHDC(pImg);
}
int easyx::getwidth()
{
	return ::getwidth();
}

int easyx::getheight()
{
	return ::getheight();
}

int easyx::getx()
{
	return ::getx();
}

int easyx::gety()
{
	return ::gety();
}


void easyx::BeginBatchDraw()
{
	return ::BeginBatchDraw();
}

void easyx::FlushBatchDraw()
{
	return ::FlushBatchDraw();
}

void easyx::FlushBatchDraw(int left, int top, int right, int bottom)
{
		return ::FlushBatchDraw(left, top, right, bottom);
}

void easyx::EndBatchDraw()
{
	return ::EndBatchDraw();
}

void easyx::EndBatchDraw(int left, int top, int right, int bottom)
{
	return ::EndBatchDraw(left, top, right, bottom);
}


HWND easyx::GetHWnd()
{
	return ::GetHWnd();
}

TCHAR* easyx::GetEasyXVer()
{
	return ::GetEasyXVer();
}


	// 获取用户输入
bool easyx::InputBox(LPTSTR pString, int nMaxCount, LPCTSTR pPrompt, LPCTSTR pTitle, LPCTSTR pDefault, int width, int height, bool bOnlyOK)
{
	return ::InputBox(pString, nMaxCount, pPrompt, pTitle, pDefault, width, height, bOnlyOK);
}

