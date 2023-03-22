#include <GL/glut.h>
float angle = 0;///step02-1 宣告 global 全域變數angle

void drawHand()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景

    glPushMatrix();///右上手臂
        glTranslatef(0.25,0,0);
        glRotatef( angle, 0, 0, 1 );
        glTranslatef(0.25,0,0);
        drawHand();

        glPushMatrix();///右下手臂
            glTranslatef(0.25,0,0);
            glRotatef( angle, 0, 0, 1 );
            glTranslatef(0.25,0,0);
            drawHand();
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();///左上手臂
        glTranslatef(-0.25,0,0);
        glRotatef( angle, 0, 0, 1 );
        glTranslatef(-0.25,0,0);
        drawHand();

        glPushMatrix();///左下手臂
            glTranslatef(-0.25,0,0);
            glRotatef( angle, 0, 0, 1 );
            glTranslatef(-0.25,0,0);
            drawHand();
        glPopMatrix();

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
