#include <GL/glut.h>
float angle = 0;///step02-1 宣告 global 全域變數angle
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///step02-2 清背景
    glPushMatrix(); ///step02-1 備份矩陣
        glRotatef( angle, 0, 1, 0 ); ///step02-1 旋轉angle角度
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step02-1 還原矩陣
    glutSwapBuffers();
    angle++;///step02-1 把角度++
}

int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display);///step02-1 有空idle時,就會重劃畫面

    glutMainLoop();
}
