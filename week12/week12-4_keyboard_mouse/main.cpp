///week12-4_keyboard_mouse
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL;///step02-2 �@�}�l����S�}�ANULL
FILE * fin = NULL;///step02-2 �nŪ�ɥΪ����СA�@�}�l�]�ONULL
float teapotX=0, teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}

void mouse (int button, int state, int x, int y)
{
    if(state==GLUT_DOWN)
    {
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        if(fout==NULL) fout = fopen("file4.txt" , "w");///step02-2�S�}�ɴN�}
        fprintf(fout, "%f %f\n" , teapotX, teapotY);///step02-2�n�A�s�y��
    }
    display();
}

void keyboard(unsigned char key, int x, int y)///step02-2 keyboard�禡
{
    if(fin==NULL)///step02-2 �p�G�ɮ��٨S�} fopen() �N�}�L
    {
        fclose(fout);///�e��mouse�|�}fout���СA�ҥH
        fin = fopen("file4.txt", "r");///step02-2 �S�}�ɴN�}
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY);///step02-2 �u��Ū��
    display();///step02-2 ���e�e��
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}
