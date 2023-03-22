#include <GL/glut.h>
float angle = 0;///step02-1 宣告 global 全域變數angle
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景

    ///glutSolidSphere(0.02,30,30);

    glutSolidTeapot(0.3);///身體

    glPushMatrix();///手臂
        glTranslatef(0.49,0.13,0);
        glRotatef( angle, 0, 0, 1 );
        glTranslatef(0.46,-0.05,0);
        glutSolidTeapot( 0.3 );

        glPushMatrix();///手肘
            glTranslatef(0.49,0.13,0);
            glRotatef( angle, 0, 0, 1 );
            glTranslatef(0.46,-0.05,0);
            glutSolidTeapot( 0.3 );
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
    angle++;
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
