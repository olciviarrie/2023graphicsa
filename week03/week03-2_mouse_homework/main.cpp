#include <GL/glut.h>
#include <stdio.h>
float X=0,Y=0;///step02-2 �Q��global�ܼ�,�b��Ƥ����ǭ�(�j�g��)
void display()
{
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(-0.180,0.172);
        glVertex2f(-0.252,0.252);
        glVertex2f(-0.300,0.304);
        glVertex2f(-0.356,0.320);
        glVertex2f(-0.420,0.340);
        glVertex2f(-0.544,0.260);
        glVertex2f(-0.532,0.132);
        glVertex2f(-0.504,0.068);
        glVertex2f(-0.432,-0.016);
        glVertex2f(-0.324,-0.100);
        glVertex2f(-0.252,-0.180);
        glVertex2f(-0.124,-0.208);
        glVertex2f(-0.052,-0.164);
        glVertex2f(0.036,-0.096);
        glVertex2f(0.092,-0.012);
        glVertex2f(0.152,0.084);
        glVertex2f(0.168,0.152);
        glVertex2f(0.184,0.236);
        glVertex2f(0.172,0.304);
        glVertex2f(0.112,0.328);
        glVertex2f(0.068,0.340);
        glVertex2f(0.012,0.332);
        glVertex2f(-0.032,0.288);
        glVertex2f(-0.096,0.232);
        glVertex2f(-0.136,0.196);
        glVertex2f(-0.168,0.168);
    }
    glEnd();

    glutSwapBuffers();
}


void mouse (int button, int state, int x, int y)///�p�g��
{
    float X = (x-250)/250.0;
    float Y =-(y-250)/250.0;///�f�Z:��@�b,���@�b,y�[�t��
    if(state==GLUT_DOWN){///�u�����Umouse,�~�L�X�{��
        printf(" glVertex2f(%.3f,%.3f);\n",X,Y);
    }
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///step02-1 ��mouse�禡����

    glutMainLoop();
}
