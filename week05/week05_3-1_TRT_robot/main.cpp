#include <GL/glut.h>
float angle = 0;///step02-1 宣告 global 全域變數angle
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景

    glColor3f(0,1,0);
    glPushMatrix(); ///備份矩陣
        glutSolidCube(0.5);

        glPushMatrix();
            glTranslatef(0.25,0.25,0);///移動
            glRotatef( angle, 0, 0, 1 );///旋轉
            glTranslatef(0.25,0.25,0);///移動
///         glTranslatef(0.5,0.5,0);
            glColor3f(1,0,0);
            glutSolidCube(0.5);
        glPopMatrix();

    glPopMatrix(); ///還原矩陣

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
