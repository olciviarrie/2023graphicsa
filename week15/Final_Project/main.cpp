#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4]={1,1,1,1};///��show[i]�M�w�n���n���
int ID=3;///0:�Y 1:���� 2:�W���u 3:�U���u
FILE * fout = NULL;
FILE * fin = NULL;
float teapotX=0,teapotY=0;
float angle[20] = {};
void keyboard (unsigned char key, int x, int y){
    if (key=='0') ID = 0;
    if (key=='1') ID = 1;
    if (key=='2') ID = 2;
    if (key=='3') ID = 3;
    if (key=='s'){
        if (fin == NULL) fout = fopen("motion.txt","w");
        for(int i=0;i<20;i++)
        {
            fprintf(fout,"%.2f ",angle[i]);
        }
        fprintf(fout,"\n");
    }
    else if(key=='r'){
        if (fin == NULL) fout = fopen("motion.txt","w");
        for(int i=0;i<20;i++)
        {
            fscanf(fin,"%f",&angle[i]);
        }
        glutPostRedisplay();
    }

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2, 0.2, 0.2);///week13-02-2
        if(body==NULL){
            head=glmReadOBJ("model/head.obj");
            body=glmReadOBJ("model/body.obj");
            uparmR=glmReadOBJ("model/uparmR.obj");
            lowarmR=glmReadOBJ("model/lowarmR.obj");
            ///glmUnitize(body);///week13-02-1�o�椧��|��
        }
        if(ID==0) glColor3f(1,0,0);///��w���A�]����
        else glColor3f(1,1,1);
        if (show[0]) glmDraw(head, GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);///��w���A�]����
        else glColor3f(1,1,1);
        if (show[1]) glmDraw(body, GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(-1.200000, +0.453333, 0);
            glRotatef(angle[2], 0, 0, 1);
            ///glTranslatef(teapotX, teapotY, 0);
            glTranslatef(1.200000, -0.453333, 0);

            if(ID==2) glColor3f(1,0,0);///��w���A�]����
            else glColor3f(1,1,1);
            if (show[2]) glmDraw(uparmR, GLM_MATERIAL);
            glPushMatrix();
            glTranslatef(-1.946666, +0.180001, 0);
            //glTranslatef(teapotX, teapotY, 0);
            glRotatef(angle[3], 0, 0, 1);
            glTranslatef(1.946666, -0.180001, 0);
            if(ID==3) glColor3f(1,0,0);///��w���A�]����
            else glColor3f(1,1,1);
            if (show[3]) glmDraw(lowarmR, GLM_MATERIAL);
        glPopMatrix();
        glPopMatrix();


    glPopMatrix();
    glColor3f(0,1,0);///��p�����b�����I���Ѧ�
    glutSolidTeapot(0.02);///��p�����b�����I���Ѧ�
    glutSwapBuffers();
}
int oldX=0, oldY=0;///week13-03-2
void motion(int x, int y){
    teapotX += (x -oldX)/150.0;
    teapotY -= (y -oldY)/150.0;
    angle[ID] += (x - oldX);
    oldX = x;
    oldY = y;
    ///angle = x;
    printf("glTranslatef(%f, %f, 0);\n",teapotX,teapotY);
    glutPostRedisplay();

}

void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        teapotX = (x-150)/150.0;///teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;///teapotY = (150-y)/150.0;
        oldX = x;
        oldY = y;
        ///angle = x;
        if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 �S�}��,�N�}
        fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 �n�A�s�y��
    }
    display();
}
///void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard�禡
///{
    ///if(fin==NULL){ ///step02-2 �p�G�ɮ��٨S fopen(), �N�}��
        ///fclose(fout); ///�e��mouse�|�}fout����, �ҥH�n����
        ///fin = fopen("file4.txt", "r"); ///step02-2 �S�}��,�N�}
   /// }
    ///fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 �u��Ū��
    ///display(); ///step02-2 ���e�e��
///}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard); ///step02-2 keyboard�n�����o(�}�ɡBŪ��)

    glutMainLoop();
}