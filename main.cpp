#define _WCHAR_T_DEFINED
#define _STDCALL_SUPPORTED
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>     
#define PI 3.14159265

int WAY;
int X1, Y1, X2, Y2, X3, Y3, X4, Y4,X5,Y5;

void midpoint_line(int x1, int y1, int x2, int y2)///中点画线法
{
	int x, y, d1, d2, d0, xNext, yNext;
	float m;
	if (x2 < x1)
	{
		d0 = x1, x1 = x2, x2 = d0;
		d0 = y1, y1 = y2, y2 = d0;
	}
	x = y1 - y2, y = x2 - x1;
	if (y == 0)
		m = -1 * x * 100;
	else
		m = (float)x / (x1 - x2);//斜率
	xNext = x1, yNext = y1;
	glBegin(GL_POINTS);///画点函数,只有两个参数,
	glVertex2i(xNext, yNext);///根据x,y进行划线
	//printf("%d %d\n", xNext, yNext);
	glEnd();
	if (m >= 0 && m <= 1)
	{
		d0 = 2 * x + y; d1 = 2 * x, d2 = 2 * (x + y);
		while (xNext < x2)
		{
			if (d0 <= 0)
			{
				xNext++, yNext++, d0 += d2;
			}
			else
			{
				xNext++, d0 += d1;
			}
			glBegin(GL_POINTS);///画点函数,只有两个参数,
			glVertex2i(xNext, yNext);///根据x,y进行划线
			glEnd();
		}
	}
	else if (m <= 0 && m >= -1)
	{
		d0 = 2 * x - y; d1 = 2 * x - 2 * y, d2 = 2 * x;
		while (xNext < x2)
		{
			if (d0 > 0)
			{
				xNext++, yNext--, d0 += d1;
			}
			else
			{
				xNext++, d0 += d2;
			}
			glBegin(GL_POINTS);///画点函数,只有两个参数,
			glVertex2i(xNext, yNext);///根据x,y进行划线
			glEnd();
		}
	}
	else if (m > 1)
	{
		d0 = x + 2 * y; d1 = 2 * (x + y), d2 = 2 * y;
		while (yNext < y2)
		{
			if (d0 > 0)
			{
				xNext++, yNext++, d0 += d1;
			}
			else
			{
				yNext++, d0 += d2;
			}
			glBegin(GL_POINTS);///画点函数,只有两个参数,
			glVertex2i(xNext, yNext);///根据x,y进行划线
			//printf("%d %d\n", xNext, yNext);
			glEnd();
		}
	}
	else
	{
		d0 = x - 2 * y;
		d1 = -2 * y, d2 = 2 * (x - y);
		while (yNext > y2)
		{
			if (d0 <= 0)
			{
				xNext++, yNext--, d0 += d2;
			}
			else
			{
				yNext--, d0 += d1;
			}
			glBegin(GL_POINTS);///画点函数,只有两个参数,
			glVertex2i(xNext, yNext);///根据x,y进行划线

			glEnd();
		}
	}
}


void display(void)///创建一个没有参数的函数来调用上一个函数
{
	glClear(GL_COLOR_BUFFER_BIT); ///刷新缓存,在窗口中出现
	
	if (WAY == 2)
	{
		int ss, sd;
		scanf_s("%d %d %d %d", &X1, &Y1, &ss, &sd);
		X2 = X1;
		Y2 = Y1;
		for (int i = 0; i < ss; i++)
		{
			int s1, s2;
			s1 = X2 + int(sd * sin((360 / ss)*i*PI / 180));
			s2 = Y2 + int(sd * cos((360 / ss)*i*PI / 180));
			midpoint_line(X2, Y2, s1, s2);
			X2 = s1;
			Y2 = s2;
			//sin(param*PI / 180);
		}
		midpoint_line(X2, Y2, X1, Y1);
	}
	glFlush();///清理缓存来处理函数
}

int main(int argc, char* argv[])
{
	printf("选择画线算法：\n");
	printf("中点画线算法\n");
	printf("请选择：(2)");
	while (1)
	{
		scanf_s("%d", &WAY);
		if (WAY != 1 && WAY != 2)
		{
			printf("输入错误，请重新输入：");
			continue;
		}
		break;
	}
		printf("请输入点坐标\n举例：300（x坐标） 300（y坐标） 50（边数） 10(边长)\n请在本处输入：");

		glutInit(&argc, argv);///glut的初始化
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(600, 600);///窗口的大小500x500

		glutInitWindowPosition(0, 0);///定义窗口的位置,在屏幕向左边0像素,屏幕上面向下0像素
		if (WAY == 2)
		{
			glutCreateWindow("中点画线算法绘制多边形");
		}
		glClearColor(1.0, 1.0, 1.0, 0.0); ///三个1.0是白色背景,三个0.0是黑色背景
		glColor3f(0, 0, 1);
		gluOrtho2D(0, 1000.0, 0, 1000.0);///在窗口内建立二维直角坐标系,x1,x2,y1,y2
		glutDisplayFunc(display);///在窗口中显示diaplay
		glutMainLoop();
	return 0;
}

