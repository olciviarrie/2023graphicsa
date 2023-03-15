#include <GL/glut.h>
float angle = 0;///step02-1 宣告 global 全域變數angle
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景

    glColor3f(0,1,0);
    glPushMatrix(); ///備份矩陣
        glTranslatef(0.8,0,0);
        glRotatef( angle, 0, 0, 1 ); ///改對z軸轉
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///還原矩陣

    glColor3f(1,0,0);
    glPushMatrix(); ///備份矩陣
        glRotatef( angle, 0, 0, 1 ); ///改對z軸轉
        glTranslatef(0.8,0,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();

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
