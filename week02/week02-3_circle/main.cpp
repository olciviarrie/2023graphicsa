///week02-3
#include <GL/glut.h>
#include <math.h>
void myCircle(float r , float x , float y)
{
    glBegin(GL_POLYGON);///step02-1開始畫多邊形
        for(float a=0 ; a<2*3.141592653589793238462632383279 ; a+=0.01)
        {
            glVertex2f( r*cos(a)+x , r*sin(a)+y);
        }
	glEnd();
}
void display()
{
    glColor3f(1,0,1); myCircle(0.6,0,0);///正中間

    glColor3f(1,0,0); myCircle(0.3 , 0.5 , 0.5);///正中間
    glColor3f(0,1,0); myCircle(0.3 ,-0.5 , 0.5);///正中間
    glColor3f(1,1,0); myCircle(0.3 ,-0.5 ,-0.5);///正中間
    glColor3f(0,0,1); myCircle(0.3 , 0.5 ,-0.5);///正中間

	glutSwapBuffers();///請glut把畫面swap送到顯示的地方
}
int main(int argc,char*argv[])
{
	glutInit(&argc,argv);///把glut開起來
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	///上面這行把顯示的模式設定好
	glutCreateWindow("GLUT Shapes");///要開視窗
	glutDisplayFunc(display);///要顯示的對應函式
	glutMainLoop();///最後用main函式壓在最後
}
