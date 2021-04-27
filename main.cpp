#define _WCHAR_T_DEFINED
#define _STDCALL_SUPPORTED
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>     
#define PI 3.14159265

int WAY;
int X1, Y1, X2, Y2, X3, Y3, X4, Y4,X5,Y5;

void midpoint_line(int x1, int y1, int x2, int y2)///�е㻭�߷�
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
		m = (float)x / (x1 - x2);//б��
	xNext = x1, yNext = y1;
	glBegin(GL_POINTS);///���㺯��,ֻ����������,
	glVertex2i(xNext, yNext);///����x,y���л���
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
			glBegin(GL_POINTS);///���㺯��,ֻ����������,
			glVertex2i(xNext, yNext);///����x,y���л���
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
			glBegin(GL_POINTS);///���㺯��,ֻ����������,
			glVertex2i(xNext, yNext);///����x,y���л���
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
			glBegin(GL_POINTS);///���㺯��,ֻ����������,
			glVertex2i(xNext, yNext);///����x,y���л���
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
			glBegin(GL_POINTS);///���㺯��,ֻ����������,
			glVertex2i(xNext, yNext);///����x,y���л���

			glEnd();
		}
	}
}


void display(void)///����һ��û�в����ĺ�����������һ������
{
	glClear(GL_COLOR_BUFFER_BIT); ///ˢ�»���,�ڴ����г���
	
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
	glFlush();///��������������
}

int main(int argc, char* argv[])
{
	printf("ѡ�����㷨��\n");
	printf("�е㻭���㷨\n");
	printf("��ѡ��(2)");
	while (1)
	{
		scanf_s("%d", &WAY);
		if (WAY != 1 && WAY != 2)
		{
			printf("����������������룺");
			continue;
		}
		break;
	}
		printf("�����������\n������300��x���꣩ 300��y���꣩ 50�������� 10(�߳�)\n���ڱ������룺");

		glutInit(&argc, argv);///glut�ĳ�ʼ��
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(600, 600);///���ڵĴ�С500x500

		glutInitWindowPosition(0, 0);///���崰�ڵ�λ��,����Ļ�����0����,��Ļ��������0����
		if (WAY == 2)
		{
			glutCreateWindow("�е㻭���㷨���ƶ����");
		}
		glClearColor(1.0, 1.0, 1.0, 0.0); ///����1.0�ǰ�ɫ����,����0.0�Ǻ�ɫ����
		glColor3f(0, 0, 1);
		gluOrtho2D(0, 1000.0, 0, 1000.0);///�ڴ����ڽ�����άֱ������ϵ,x1,x2,y1,y2
		glutDisplayFunc(display);///�ڴ�������ʾdiaplay
		glutMainLoop();
	return 0;
}

