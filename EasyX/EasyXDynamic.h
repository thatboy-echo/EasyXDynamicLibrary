#pragma once

#include <windows.h>
#include <tchar.h>

#ifdef EASYX_EXPORTS
#define EASYX_API __declspec(dllexport)
#else
#define EASYX_API __declspec(dllimport)
#endif // EASYX_EXPORTS

#ifndef __cplusplus
#error EasyX Dynamic Library is only for C++
#endif

#ifndef EASYX_EXPORTS
#ifdef UNICODE
#pragma comment(lib,"EasyXDw.lib")
#else
#pragma comment(lib,"EasyXDa.lib")
#endif
#endif // !EASYX_EXPORTS

// EasyX Window Properties
#define EW_SHOWCONSOLE		1		// Show console window
#define EW_NOCLOSE			2		// Disable the close button
#define EW_NOMINIMIZE		4		// Disable the minimize button
#define EW_DBLCLKS			8		// Support double-click events

// ��ɫ
#define	BLACK			0
#define	BLUE			0xAA0000
#define	GREEN			0x00AA00
#define	CYAN			0xAAAA00
#define	RED				0x0000AA
#define	MAGENTA			0xAA00AA
#define	BROWN			0x0055AA
#define	LIGHTGRAY		0xAAAAAA
#define	DARKGRAY		0x555555
#define	LIGHTBLUE		0xFF5555
#define	LIGHTGREEN		0x55FF55
#define	LIGHTCYAN		0xFFFF55
#define	LIGHTRED		0x5555FF
#define	LIGHTMAGENTA	0xFF55FF
#define	YELLOW			0x55FFFF
#define	WHITE			0xFFFFFF

// ������ɫת����
#define BGR(color)	( (((color) & 0xFF) << 16) | ((color) & 0xFF00FF00) | (((color) & 0xFF0000) >> 16) )

class EASYX_API IMAGE;

// �����ߵ���ʽ
class EASYX_API LINESTYLE
{
public:
	LINESTYLE();
	LINESTYLE(const ::LINESTYLE& style);
	LINESTYLE& operator = (const LINESTYLE& style);			// ��ֵ��������غ���
	virtual ~LINESTYLE();

	DWORD	style;
	DWORD	thickness;
	DWORD* puserstyle;
	DWORD	userstylecount;
};

class EASYX_API FILLSTYLE
{
public:
	FILLSTYLE();
	FILLSTYLE(const FILLSTYLE& style);
	FILLSTYLE& operator = (const FILLSTYLE& style);			// ��ֵ��������غ���
	virtual ~FILLSTYLE();

	int			style;			// �����ʽ
	long		hatch;			// ���ͼ����ʽ
	IMAGE* ppattern;		// ���ͼ��
};

// ����ͼ�����
class EASYX_API IMAGE
{
public:
	int getwidth() const;	// ��ȡ����Ŀ��
	int getheight() const;	// ��ȡ����ĸ߶�

private:
	int width, height;		// ����Ŀ��
	HBITMAP m_hBmp;
	HDC m_hMemDC;
	int m_MemCurX;			// ��ǰ��X����
	int m_MemCurY;			// ��ǰ��Y����
	float m_data[6];
	COLORREF	m_LineColor;		// ��ǰ������ɫ
	COLORREF	m_FillColor;		// ��ǰ�����ɫ
	COLORREF	m_TextColor;		// ��ǰ������ɫ
	COLORREF	m_BkColor;			// ��ǰ������ɫ
	DWORD* m_pBuffer;			// ��ͼ�����ڴ�

	LINESTYLE	m_LineStyle;		// ������ʽ
	FILLSTYLE	m_FillStyle;		// �����ʽ

	virtual void SetDefault();						// ����ΪĬ��״̬

public:
	IMAGE(int _width = 0, int _height = 0);			// ����ͼ��
	IMAGE(const IMAGE& img);						// �������캯��
	IMAGE& operator = (const IMAGE& img);			// ��ֵ��������غ���
	virtual ~IMAGE();
	virtual void Resize(int _width, int _height);	// �����ߴ�
};

// �����Ϣ
// ֧��������Ϣ��
//		WM_MOUSEMOVE		����ƶ�
//		WM_MOUSEWHEEL		�����ֲ���
//		WM_LBUTTONDOWN		�������
//		WM_LBUTTONUP		�������
//		WM_LBUTTONDBLCLK	���˫��
//		WM_MBUTTONDOWN		�м�����
//		WM_MBUTTONUP		�м�����
//		WM_MBUTTONDBLCLK	�м�˫��
//		WM_RBUTTONDOWN		�Ҽ�����
//		WM_RBUTTONUP		�Ҽ�����
//		WM_RBUTTONDBLCLK	�Ҽ�˫��
struct EASYX_API MOUSEMSG
{
	UINT uMsg;				// ��ǰ�����Ϣ
	bool mkCtrl;			// Ctrl ���Ƿ���
	bool mkShift;			// Shift ���Ƿ���
	bool mkLButton;			// �������Ƿ���
	bool mkMButton;			// ����м��Ƿ���
	bool mkRButton;			// ����Ҽ��Ƿ���
	short x;				// ��ǰ��� x ����
	short y;				// ��ǰ��� y ����
	short wheel;			// �����ֹ���ֵ (120 �ı���)
};

/// <summary>
/// EasyX��̬�⵼�������ռ�
/// </summary>
namespace easyx
{

#ifndef EASYX_STALIB_COMPAT
	// ��ɫ
	enum : DWORD
	{
		Black = 0
		, Blue = 0XAA0000
		, Green = 0X00AA00
		, Cyan = 0XAAAA00
		, Red = 0X0000AA
		, Magenta = 0XAA00AA
		, Brown = 0X0055AA
		, Lightgray = 0XAAAAAA
		, Darkgray = 0X555555
		, Lightblue = 0XFF5555
		, Lightgreen = 0X55FF55
		, Lightcyan = 0XFFFF55
		, Lightred = 0X5555FF
		, Lightmagenta = 0XFF55FF
		, Yellow = 0X55FFFF
		, White = 0XFFFFFF
	};

	// EasyX Window Properties
	enum : int
	{
		EW_Default = 0
		, EW_ShowConsole = 1		// Show console window
		, EW_Noclose = 2		// Disable the close button
		, EW_Nominimize = 4		// Disable the minimize button
		, EW_Dblclks = 8		// Support double-click events
	};

#endif

	// ��ͼģʽ��غ���

	EASYX_API HWND initgraph(int width, int height, int flag = 0);	// ��ʼ��ͼ�λ���
	EASYX_API void closegraph();										// �ر�ͼ�λ���

	// ��ͼ��������

	EASYX_API void cleardevice();					// ����
	EASYX_API void setcliprgn(HRGN hrgn);			// ���õ�ǰ��ͼ�豸�Ĳü���
	EASYX_API void clearcliprgn();				// ����ü�������Ļ����

	EASYX_API void getlinestyle(LINESTYLE* pstyle);						// ��ȡ��ǰ������ʽ
	EASYX_API void setlinestyle(const LINESTYLE* pstyle);					// ���õ�ǰ������ʽ
	EASYX_API void setlinestyle(int style, int thickness = 1, const DWORD* puserstyle = nullptr, DWORD userstylecount = 0);	// ���õ�ǰ������ʽ
	EASYX_API void getfillstyle(FILLSTYLE* pstyle);						// ��ȡ��ǰ�����ʽ
	EASYX_API void setfillstyle(const FILLSTYLE* pstyle);					// ���õ�ǰ�����ʽ
	EASYX_API void setfillstyle(int style, long hatch = 0, IMAGE* ppattern = nullptr);		// ���õ�ǰ�����ʽ
	EASYX_API void setfillstyle(BYTE* ppattern8x8);						// ���õ�ǰ�����ʽ

	EASYX_API void setorigin(int x, int y);							// ��������ԭ��
	EASYX_API void getaspectratio(float* pxasp, float* pyasp);		// ��ȡ��ǰ��������
	EASYX_API void setaspectratio(float xasp, float yasp);			// ���õ�ǰ��������

	EASYX_API int getrop2();						// ��ȡǰ���Ķ�Ԫ��դ����ģʽ
	EASYX_API void setrop2(int mode);				// ����ǰ���Ķ�Ԫ��դ����ģʽ
	EASYX_API int getpolyfillmode();				// ��ȡ��������ģʽ
	EASYX_API void setpolyfillmode(int mode);		// ���ö�������ģʽ

	EASYX_API void graphdefaults();				// �������л�ͼ����ΪĬ��ֵ

	EASYX_API COLORREF getlinecolor();			// ��ȡ��ǰ������ɫ
	EASYX_API void setlinecolor(COLORREF color);	// ���õ�ǰ������ɫ
	EASYX_API COLORREF gettextcolor();			// ��ȡ��ǰ������ɫ
	EASYX_API void settextcolor(COLORREF color);	// ���õ�ǰ������ɫ
	EASYX_API COLORREF getfillcolor();			// ��ȡ��ǰ�����ɫ
	EASYX_API void setfillcolor(COLORREF color);	// ���õ�ǰ�����ɫ
	EASYX_API COLORREF getbkcolor();				// ��ȡ��ǰ��ͼ����ɫ
	EASYX_API void setbkcolor(COLORREF color);	// ���õ�ǰ��ͼ����ɫ
	EASYX_API int  getbkmode();					// ��ȡ�������ģʽ
	EASYX_API void setbkmode(int mode);			// ���ñ������ģʽ

	// ��ɫģ��ת������
	EASYX_API COLORREF RGBtoGRAY(COLORREF rgb);
	EASYX_API void RGBtoHSL(COLORREF rgb, float* H, float* S, float* L);
	EASYX_API void RGBtoHSV(COLORREF rgb, float* H, float* S, float* V);
	EASYX_API COLORREF HSLtoRGB(float H, float S, float L);
	EASYX_API COLORREF HSVtoRGB(float H, float S, float V);

	// ��ͼ����

	EASYX_API COLORREF getpixel(int x, int y);				// ��ȡ�����ɫ
	EASYX_API void putpixel(int x, int y, COLORREF color);	// ����

	EASYX_API void moveto(int x, int y);						// �ƶ���ǰ��(��������)
	EASYX_API void moverel(int dx, int dy);					// �ƶ���ǰ��(�������)

	EASYX_API void line(int x1, int y1, int x2, int y2);		// ����
	EASYX_API void linerel(int dx, int dy);					// ����(���������)
	EASYX_API void lineto(int x, int y);						// ����(����������)

	EASYX_API void rectangle(int left, int top, int right, int bottom);	// ������
	EASYX_API void fillrectangle(int left, int top, int right, int bottom);	// ��������(�б߿�)
	EASYX_API void solidrectangle(int left, int top, int right, int bottom);	// ��������(�ޱ߿�)
	EASYX_API void clearrectangle(int left, int top, int right, int bottom);	// ��վ�������

	EASYX_API void circle(int x, int y, int radius);		// ��Բ
	EASYX_API void fillcircle(int x, int y, int radius);		// �����Բ(�б߿�)
	EASYX_API void solidcircle(int x, int y, int radius);		// �����Բ(�ޱ߿�)
	EASYX_API void clearcircle(int x, int y, int radius);		// ���Բ������

	EASYX_API void ellipse(int left, int top, int right, int bottom);	// ����Բ
	EASYX_API void fillellipse(int left, int top, int right, int bottom);	// �������Բ(�б߿�)
	EASYX_API void solidellipse(int left, int top, int right, int bottom);	// �������Բ(�ޱ߿�)
	EASYX_API void clearellipse(int left, int top, int right, int bottom);	// �����Բ������

	EASYX_API void roundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight);		// ��Բ�Ǿ���
	EASYX_API void fillroundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight);		// �����Բ�Ǿ���(�б߿�)
	EASYX_API void solidroundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight);		// �����Բ�Ǿ���(�ޱ߿�)
	EASYX_API void clearroundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight);		// ���Բ�Ǿ�������

	EASYX_API void arc(int left, int top, int right, int bottom, double stangle, double endangle);	// ����Բ��(��ʼ�ǶȺ���ֹ�Ƕ�Ϊ������)
	EASYX_API void pie(int left, int top, int right, int bottom, double stangle, double endangle);	// ����Բ����(��ʼ�ǶȺ���ֹ�Ƕ�Ϊ������)
	EASYX_API void fillpie(int left, int top, int right, int bottom, double stangle, double endangle);	// �������Բ����(�б߿�)
	EASYX_API void solidpie(int left, int top, int right, int bottom, double stangle, double endangle);	// �������Բ����(�ޱ߿�)
	EASYX_API void clearpie(int left, int top, int right, int bottom, double stangle, double endangle);	// �����Բ��������

	EASYX_API void polyline(const POINT* points, int num);								// ��������������
	EASYX_API void polygon(const POINT* points, int num);								// �������
	EASYX_API void fillpolygon(const POINT* points, int num);								// �����Ķ����(�б߿�)
	EASYX_API void solidpolygon(const POINT* points, int num);								// �����Ķ����(�ޱ߿�)
	EASYX_API void clearpolygon(const POINT* points, int num);								// ��ն��������

	EASYX_API void polybezier(const POINT* points, int num);									// ������������
	EASYX_API void floodfill(int x, int y, COLORREF color, int filltype = FLOODFILLBORDER);	// �������

	// ������غ���

	EASYX_API void outtext(LPCTSTR str);					// �ڵ�ǰλ������ַ���
	EASYX_API void outtext(TCHAR c);						// �ڵ�ǰλ������ַ�
	EASYX_API void outtextxy(int x, int y, LPCTSTR str);	// ��ָ��λ������ַ���
	EASYX_API void outtextxy(int x, int y, TCHAR c);		// ��ָ��λ������ַ�
	EASYX_API int textwidth(LPCTSTR str);					// ��ȡ�ַ���ռ�õ����ؿ�
	EASYX_API int textwidth(TCHAR c);						// ��ȡ�ַ�ռ�õ����ؿ�
	EASYX_API int textheight(LPCTSTR str);				// ��ȡ�ַ���ռ�õ����ظ�
	EASYX_API int textheight(TCHAR c);					// ��ȡ�ַ�ռ�õ����ظ�
	EASYX_API int drawtext(LPCTSTR str, RECT* pRect, UINT uFormat);	// ��ָ����������ָ����ʽ����ַ���
	EASYX_API int drawtext(TCHAR c, RECT* pRect, UINT uFormat);		// ��ָ����������ָ����ʽ����ַ�

	// ���õ�ǰ������ʽ(�������)
	//		nHeight: �ַ���ƽ���߶ȣ�
	//		nWidth: �ַ���ƽ�����(0 ��ʾ����Ӧ)��
	//		lpszFace: �������ƣ�
	//		nEscapement: �ַ�������д�Ƕ�(��λ 0.1 ��)��
	//		nOrientation: ÿ���ַ�����д�Ƕ�(��λ 0.1 ��)��
	//		nWeight: �ַ��ıʻ���ϸ(0 ��ʾĬ�ϴ�ϸ)��
	//		bItalic: �Ƿ�б�壻
	//		bUnderline: �Ƿ��»��ߣ�
	//		bStrikeOut: �Ƿ�ɾ���ߣ�
	//		fbCharSet: ָ���ַ�����
	//		fbOutPrecision: ָ�����ֵ�������ȣ�
	//		fbClipPrecision: ָ�����ֵļ������ȣ�
	//		fbQuality: ָ�����ֵ����������
	//		fbPitchAndFamily: ָ���Գ��淽ʽ�������������ϵ�С�
	EASYX_API void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace);
	EASYX_API void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut);
	EASYX_API void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut, BYTE fbCharSet, BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily);
	EASYX_API void settextstyle(const LOGFONT* font);	// ���õ�ǰ������ʽ
	EASYX_API void gettextstyle(LOGFONT* font);		// ��ȡ��ǰ������ʽ

	// ͼ������
	EASYX_API void loadimage(IMAGE* pDstImg, LPCTSTR pImgFile, int nWidth = 0, int nHeight = 0, bool bResize = false);					// ��ͼƬ�ļ���ȡͼ��(bmp/gif/jpg/png/tif/emf/wmf/ico)
	EASYX_API void loadimage(IMAGE* pDstImg, LPCTSTR pResType, LPCTSTR pResName, int nWidth = 0, int nHeight = 0, bool bResize = false);	// ����Դ�ļ���ȡͼ��(bmp/gif/jpg/png/tif/emf/wmf/ico)
	EASYX_API void saveimage(LPCTSTR pImgFile, IMAGE* pImg = nullptr);																		// ����ͼ��(bmp/gif/jpg/png/tif)
	EASYX_API void getimage(IMAGE* pDstImg, int srcX, int srcY, int srcWidth, int srcHeight);												// �ӵ�ǰ��ͼ�豸��ȡͼ��
	EASYX_API void putimage(int dstX, int dstY, const IMAGE* pSrcImg, DWORD dwRop = SRCCOPY);												// ����ͼ����Ļ
	EASYX_API void putimage(int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE* pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY);		// ����ͼ����Ļ(ָ�����)
	EASYX_API void rotateimage(IMAGE* dstimg, IMAGE* srcimg, double radian, COLORREF bkcolor = BLACK, bool autosize = false, bool highquality = true);// ��תͼ��
	EASYX_API void Resize(IMAGE* pImg, int width, int height);	// ������ͼ�豸�Ĵ�С
	EASYX_API DWORD* GetImageBuffer(IMAGE* pImg = nullptr);			// ��ȡ��ͼ�豸���Դ�ָ��
	EASYX_API IMAGE* GetWorkingImage();							// ��ȡ��ǰ��ͼ�豸
	EASYX_API void SetWorkingImage(IMAGE* pImg = nullptr);			// ���õ�ǰ��ͼ�豸
	EASYX_API HDC GetImageHDC(IMAGE* pImg = nullptr);				// ��ȡ��ͼ�豸���(HDC)

	// ��������

	EASYX_API int getwidth();			// ��ȡ��ͼ�����
	EASYX_API int getheight();		// ��ȡ��ͼ���߶�
	EASYX_API int getx();				// ��ȡ��ǰ x ����
	EASYX_API int gety();				// ��ȡ��ǰ y ����

	EASYX_API void BeginBatchDraw();	// ��ʼ��������
	EASYX_API void FlushBatchDraw();	// ִ��δ��ɵĻ�������
	EASYX_API void FlushBatchDraw(int left, int top, int right, int bottom);	// ִ��ָ��������δ��ɵĻ�������
	EASYX_API void EndBatchDraw();	// �����������ƣ���ִ��δ��ɵĻ�������
	EASYX_API void EndBatchDraw(int left, int top, int right, int bottom);	// �����������ƣ���ִ��ָ��������δ��ɵĻ�������

	EASYX_API HWND GetHWnd();								// ��ȡ��ͼ���ھ��(HWND)
	EASYX_API TCHAR* GetEasyXVer();						// ��ȡ EasyX ��ǰ�汾

	// ��ȡ�û�����
	EASYX_API bool InputBox(LPTSTR pString, int nMaxCount, LPCTSTR pPrompt = nullptr, LPCTSTR pTitle = nullptr, LPCTSTR pDefault = nullptr, int width = 0, int height = 0, bool bOnlyOK = true);

	EASYX_API bool MouseHit();			// ����Ƿ���������Ϣ
	EASYX_API MOUSEMSG GetMouseMsg();		// ��ȡһ�������Ϣ�����û�У��͵ȴ�
	EASYX_API void FlushMouseMsgBuffer();	// ��������Ϣ������
}
// �������
#ifdef EASYX_STALIB_COMPAT
using namespace easyx;
#endif // EASYX_STALIB_COMPAT
