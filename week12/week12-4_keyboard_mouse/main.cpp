///week12-4_keyboard_mouse
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL;///step02-2 一開始當按沒開，NULL
FILE * fin = NULL;///step02-2 要讀檔用的指標，一開始也是NULL
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
        if(fout==NULL) fout = fopen("file4.txt" , "w");///step02-2沒開檔就開
        fprintf(fout, "%f %f\n" , teapotX, teapotY);///step02-2要再存座標
    }
    display();
}

void keyboard(unsigned char key, int x, int y)///step02-2 keyboard函式
{
    if(fin==NULL)///step02-2 如果檔案還沒開 fopen() 就開他
    {
        fclose(fout);///前面mouse會開fout指標，所以
        fin = fopen("file4.txt", "r");///step02-2 沒開檔就開
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY);///step02-2 真的讀檔
    display();///step02-2 重畫畫面
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
