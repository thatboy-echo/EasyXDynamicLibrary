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

// 颜色
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

// 定义颜色转换宏
#define BGR(color)	( (((color) & 0xFF) << 16) | ((color) & 0xFF00FF00) | (((color) & 0xFF0000) >> 16) )

class EASYX_API IMAGE;

// 定义线的样式
class EASYX_API LINESTYLE
{
public:
	LINESTYLE();
	LINESTYLE(const ::LINESTYLE& style);
	LINESTYLE& operator = (const LINESTYLE& style);			// 赋值运算符重载函数
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
	FILLSTYLE& operator = (const FILLSTYLE& style);			// 赋值运算符重载函数
	virtual ~FILLSTYLE();

	int			style;			// 填充形式
	long		hatch;			// 填充图案样式
	IMAGE* ppattern;		// 填充图像
};

// 定义图像对象
class EASYX_API IMAGE
{
public:
	int getwidth() const;	// 获取对象的宽度
	int getheight() const;	// 获取对象的高度

private:
	int width, height;		// 对象的宽高
	HBITMAP m_hBmp;
	HDC m_hMemDC;
	int m_MemCurX;			// 当前点X坐标
	int m_MemCurY;			// 当前点Y坐标
	float m_data[6];
	COLORREF	m_LineColor;		// 当前线条颜色
	COLORREF	m_FillColor;		// 当前填充颜色
	COLORREF	m_TextColor;		// 当前文字颜色
	COLORREF	m_BkColor;			// 当前背景颜色
	DWORD* m_pBuffer;			// 绘图区的内存

	LINESTYLE	m_LineStyle;		// 画线样式
	FILLSTYLE	m_FillStyle;		// 填充样式

	virtual void SetDefault();						// 设置为默认状态

public:
	IMAGE(int _width = 0, int _height = 0);			// 创建图像
	IMAGE(const IMAGE& img);						// 拷贝构造函数
	IMAGE& operator = (const IMAGE& img);			// 赋值运算符重载函数
	virtual ~IMAGE();
	virtual void Resize(int _width, int _height);	// 调整尺寸
};

// 鼠标消息
// 支持如下消息：
//		WM_MOUSEMOVE		鼠标移动
//		WM_MOUSEWHEEL		鼠标滚轮拨动
//		WM_LBUTTONDOWN		左键按下
//		WM_LBUTTONUP		左键弹起
//		WM_LBUTTONDBLCLK	左键双击
//		WM_MBUTTONDOWN		中键按下
//		WM_MBUTTONUP		中键弹起
//		WM_MBUTTONDBLCLK	中键双击
//		WM_RBUTTONDOWN		右键按下
//		WM_RBUTTONUP		右键弹起
//		WM_RBUTTONDBLCLK	右键双击
struct EASYX_API MOUSEMSG
{
	UINT uMsg;				// 当前鼠标消息
	bool mkCtrl;			// Ctrl 键是否按下
	bool mkShift;			// Shift 键是否按下
	bool mkLButton;			// 鼠标左键是否按下
	bool mkMButton;			// 鼠标中键是否按下
	bool mkRButton;			// 鼠标右键是否按下
	short x;				// 当前鼠标 x 坐标
	short y;				// 当前鼠标 y 坐标
	short wheel;			// 鼠标滚轮滚动值 (120 的倍数)
};

/// <summary>
/// EasyX动态库导出函数空间
/// </summary>
namespace easyx
{

#ifndef EASYX_STALIB_COMPAT
	// 颜色
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

	// 绘图模式相关函数

	EASYX_API HWND initgraph(int width, int height, int flag = 0);	// 初始化图形环境
	EASYX_API void closegraph();										// 关闭图形环境

	// 绘图环境设置

	EASYX_API void cleardevice();					// 清屏
	EASYX_API void setcliprgn(HRGN hrgn);			// 设置当前绘图设备的裁剪区
	EASYX_API void clearcliprgn();				// 清除裁剪区的屏幕内容

	EASYX_API void getlinestyle(LINESTYLE* pstyle);						// 获取当前画线样式
	EASYX_API void setlinestyle(const LINESTYLE* pstyle);					// 设置当前画线样式
	EASYX_API void setlinestyle(int style, int thickness = 1, const DWORD* puserstyle = nullptr, DWORD userstylecount = 0);	// 设置当前画线样式
	EASYX_API void getfillstyle(FILLSTYLE* pstyle);						// 获取当前填充样式
	EASYX_API void setfillstyle(const FILLSTYLE* pstyle);					// 设置当前填充样式
	EASYX_API void setfillstyle(int style, long hatch = 0, IMAGE* ppattern = nullptr);		// 设置当前填充样式
	EASYX_API void setfillstyle(BYTE* ppattern8x8);						// 设置当前填充样式

	EASYX_API void setorigin(int x, int y);							// 设置坐标原点
	EASYX_API void getaspectratio(float* pxasp, float* pyasp);		// 获取当前缩放因子
	EASYX_API void setaspectratio(float xasp, float yasp);			// 设置当前缩放因子

	EASYX_API int getrop2();						// 获取前景的二元光栅操作模式
	EASYX_API void setrop2(int mode);				// 设置前景的二元光栅操作模式
	EASYX_API int getpolyfillmode();				// 获取多边形填充模式
	EASYX_API void setpolyfillmode(int mode);		// 设置多边形填充模式

	EASYX_API void graphdefaults();				// 重置所有绘图设置为默认值

	EASYX_API COLORREF getlinecolor();			// 获取当前线条颜色
	EASYX_API void setlinecolor(COLORREF color);	// 设置当前线条颜色
	EASYX_API COLORREF gettextcolor();			// 获取当前文字颜色
	EASYX_API void settextcolor(COLORREF color);	// 设置当前文字颜色
	EASYX_API COLORREF getfillcolor();			// 获取当前填充颜色
	EASYX_API void setfillcolor(COLORREF color);	// 设置当前填充颜色
	EASYX_API COLORREF getbkcolor();				// 获取当前绘图背景色
	EASYX_API void setbkcolor(COLORREF color);	// 设置当前绘图背景色
	EASYX_API int  getbkmode();					// 获取背景混合模式
	EASYX_API void setbkmode(int mode);			// 设置背景混合模式

	// 颜色模型转换函数
	EASYX_API COLORREF RGBtoGRAY(COLORREF rgb);
	EASYX_API void RGBtoHSL(COLORREF rgb, float* H, float* S, float* L);
	EASYX_API void RGBtoHSV(COLORREF rgb, float* H, float* S, float* V);
	EASYX_API COLORREF HSLtoRGB(float H, float S, float L);
	EASYX_API COLORREF HSVtoRGB(float H, float S, float V);

	// 绘图函数

	EASYX_API COLORREF getpixel(int x, int y);				// 获取点的颜色
	EASYX_API void putpixel(int x, int y, COLORREF color);	// 画点

	EASYX_API void moveto(int x, int y);						// 移动当前点(绝对坐标)
	EASYX_API void moverel(int dx, int dy);					// 移动当前点(相对坐标)

	EASYX_API void line(int x1, int y1, int x2, int y2);		// 画线
	EASYX_API void linerel(int dx, int dy);					// 画线(至相对坐标)
	EASYX_API void lineto(int x, int y);						// 画线(至绝对坐标)

	EASYX_API void rectangle(int left, int top, int right, int bottom);	// 画矩形
	EASYX_API void fillrectangle(int left, int top, int right, int bottom);	// 画填充矩形(有边框)
	EASYX_API void solidrectangle(int left, int top, int right, int bottom);	// 画填充矩形(无边框)
	EASYX_API void clearrectangle(int left, int top, int right, int bottom);	// 清空矩形区域

	EASYX_API void circle(int x, int y, int radius);		// 画圆
	EASYX_API void fillcircle(int x, int y, int radius);		// 画填充圆(有边框)
	EASYX_API void solidcircle(int x, int y, int radius);		// 画填充圆(无边框)
	EASYX_API void clearcircle(int x, int y, int radius);		// 清空圆形区域

	EASYX_API void ellipse(int left, int top, int right, int bottom);	// 画椭圆
	EASYX_API void fillellipse(int left, int top, int right, int bottom);	// 画填充椭圆(有边框)
	EASYX_API void solidellipse(int left, int top, int right, int bottom);	// 画填充椭圆(无边框)
	EASYX_API void clearellipse(int left, int top, int right, int bottom);	// 清空椭圆形区域

	EASYX_API void roundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight);		// 画圆角矩形
	EASYX_API void fillroundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight);		// 画填充圆角矩形(有边框)
	EASYX_API void solidroundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight);		// 画填充圆角矩形(无边框)
	EASYX_API void clearroundrect(int left, int top, int right, int bottom, int ellipsewidth, int ellipseheight);		// 清空圆角矩形区域

	EASYX_API void arc(int left, int top, int right, int bottom, double stangle, double endangle);	// 画椭圆弧(起始角度和终止角度为弧度制)
	EASYX_API void pie(int left, int top, int right, int bottom, double stangle, double endangle);	// 画椭圆扇形(起始角度和终止角度为弧度制)
	EASYX_API void fillpie(int left, int top, int right, int bottom, double stangle, double endangle);	// 画填充椭圆扇形(有边框)
	EASYX_API void solidpie(int left, int top, int right, int bottom, double stangle, double endangle);	// 画填充椭圆扇形(无边框)
	EASYX_API void clearpie(int left, int top, int right, int bottom, double stangle, double endangle);	// 清空椭圆扇形区域

	EASYX_API void polyline(const POINT* points, int num);								// 画多条连续的线
	EASYX_API void polygon(const POINT* points, int num);								// 画多边形
	EASYX_API void fillpolygon(const POINT* points, int num);								// 画填充的多边形(有边框)
	EASYX_API void solidpolygon(const POINT* points, int num);								// 画填充的多边形(无边框)
	EASYX_API void clearpolygon(const POINT* points, int num);								// 清空多边形区域

	EASYX_API void polybezier(const POINT* points, int num);									// 画贝塞尔曲线
	EASYX_API void floodfill(int x, int y, COLORREF color, int filltype = FLOODFILLBORDER);	// 填充区域

	// 文字相关函数

	EASYX_API void outtext(LPCTSTR str);					// 在当前位置输出字符串
	EASYX_API void outtext(TCHAR c);						// 在当前位置输出字符
	EASYX_API void outtextxy(int x, int y, LPCTSTR str);	// 在指定位置输出字符串
	EASYX_API void outtextxy(int x, int y, TCHAR c);		// 在指定位置输出字符
	EASYX_API int textwidth(LPCTSTR str);					// 获取字符串占用的像素宽
	EASYX_API int textwidth(TCHAR c);						// 获取字符占用的像素宽
	EASYX_API int textheight(LPCTSTR str);				// 获取字符串占用的像素高
	EASYX_API int textheight(TCHAR c);					// 获取字符占用的像素高
	EASYX_API int drawtext(LPCTSTR str, RECT* pRect, UINT uFormat);	// 在指定区域内以指定格式输出字符串
	EASYX_API int drawtext(TCHAR c, RECT* pRect, UINT uFormat);		// 在指定区域内以指定格式输出字符

	// 设置当前字体样式(详见帮助)
	//		nHeight: 字符的平均高度；
	//		nWidth: 字符的平均宽度(0 表示自适应)；
	//		lpszFace: 字体名称；
	//		nEscapement: 字符串的书写角度(单位 0.1 度)；
	//		nOrientation: 每个字符的书写角度(单位 0.1 度)；
	//		nWeight: 字符的笔画粗细(0 表示默认粗细)；
	//		bItalic: 是否斜体；
	//		bUnderline: 是否下划线；
	//		bStrikeOut: 是否删除线；
	//		fbCharSet: 指定字符集；
	//		fbOutPrecision: 指定文字的输出精度；
	//		fbClipPrecision: 指定文字的剪辑精度；
	//		fbQuality: 指定文字的输出质量；
	//		fbPitchAndFamily: 指定以常规方式描述字体的字体系列。
	EASYX_API void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace);
	EASYX_API void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut);
	EASYX_API void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut, BYTE fbCharSet, BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily);
	EASYX_API void settextstyle(const LOGFONT* font);	// 设置当前字体样式
	EASYX_API void gettextstyle(LOGFONT* font);		// 获取当前字体样式

	// 图像处理函数
	EASYX_API void loadimage(IMAGE* pDstImg, LPCTSTR pImgFile, int nWidth = 0, int nHeight = 0, bool bResize = false);					// 从图片文件获取图像(bmp/gif/jpg/png/tif/emf/wmf/ico)
	EASYX_API void loadimage(IMAGE* pDstImg, LPCTSTR pResType, LPCTSTR pResName, int nWidth = 0, int nHeight = 0, bool bResize = false);	// 从资源文件获取图像(bmp/gif/jpg/png/tif/emf/wmf/ico)
	EASYX_API void saveimage(LPCTSTR pImgFile, IMAGE* pImg = nullptr);																		// 保存图像(bmp/gif/jpg/png/tif)
	EASYX_API void getimage(IMAGE* pDstImg, int srcX, int srcY, int srcWidth, int srcHeight);												// 从当前绘图设备获取图像
	EASYX_API void putimage(int dstX, int dstY, const IMAGE* pSrcImg, DWORD dwRop = SRCCOPY);												// 绘制图像到屏幕
	EASYX_API void putimage(int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE* pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY);		// 绘制图像到屏幕(指定宽高)
	EASYX_API void rotateimage(IMAGE* dstimg, IMAGE* srcimg, double radian, COLORREF bkcolor = BLACK, bool autosize = false, bool highquality = true);// 旋转图像
	EASYX_API void Resize(IMAGE* pImg, int width, int height);	// 调整绘图设备的大小
	EASYX_API DWORD* GetImageBuffer(IMAGE* pImg = nullptr);			// 获取绘图设备的显存指针
	EASYX_API IMAGE* GetWorkingImage();							// 获取当前绘图设备
	EASYX_API void SetWorkingImage(IMAGE* pImg = nullptr);			// 设置当前绘图设备
	EASYX_API HDC GetImageHDC(IMAGE* pImg = nullptr);				// 获取绘图设备句柄(HDC)

	// 其它函数

	EASYX_API int getwidth();			// 获取绘图区宽度
	EASYX_API int getheight();		// 获取绘图区高度
	EASYX_API int getx();				// 获取当前 x 坐标
	EASYX_API int gety();				// 获取当前 y 坐标

	EASYX_API void BeginBatchDraw();	// 开始批量绘制
	EASYX_API void FlushBatchDraw();	// 执行未完成的绘制任务
	EASYX_API void FlushBatchDraw(int left, int top, int right, int bottom);	// 执行指定区域内未完成的绘制任务
	EASYX_API void EndBatchDraw();	// 结束批量绘制，并执行未完成的绘制任务
	EASYX_API void EndBatchDraw(int left, int top, int right, int bottom);	// 结束批量绘制，并执行指定区域内未完成的绘制任务

	EASYX_API HWND GetHWnd();								// 获取绘图窗口句柄(HWND)
	EASYX_API TCHAR* GetEasyXVer();						// 获取 EasyX 当前版本

	// 获取用户输入
	EASYX_API bool InputBox(LPTSTR pString, int nMaxCount, LPCTSTR pPrompt = nullptr, LPCTSTR pTitle = nullptr, LPCTSTR pDefault = nullptr, int width = 0, int height = 0, bool bOnlyOK = true);

	EASYX_API bool MouseHit();			// 检查是否存在鼠标消息
	EASYX_API MOUSEMSG GetMouseMsg();		// 获取一个鼠标消息。如果没有，就等待
	EASYX_API void FlushMouseMsgBuffer();	// 清空鼠标消息缓冲区
}
// 代码兼容
#ifdef EASYX_STALIB_COMPAT
using namespace easyx;
#endif // EASYX_STALIB_COMPAT
