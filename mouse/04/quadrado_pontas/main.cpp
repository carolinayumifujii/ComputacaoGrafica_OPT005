#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
#include <stdio.h>

int movex = 0, movey = 0;
int a_1 = 200, a_2 = 150, a_3 = 200, a_4 = 450, a_5 = 600, a_6 = 450, a_7 = 600, a_8 = 150 ;


void ponto(){

    glBegin(GL_POLYGON);

        glColor3f(1,0,0);
        glVertex2f(a_1, a_2);
        glVertex2f(a_3, a_4);
        glVertex2f(a_5, a_6);
        glVertex2f(a_7, a_8);



    glEnd();

}



void desenhaObjetos(void){

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0,800,600,0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

        ponto();

    glPopMatrix();

    glutSwapBuffers();

}



void movimentaMouse(int x, int y){

    movex = x;
    movey = y;
  printf("X: %d, Y: %d\n", movex, movey);


    glutPostRedisplay();


}

void gerenciaMouse(int botao, int estado, int x, int y){

  if (botao == GLUT_LEFT_BUTTON){
    
      if(estado == GLUT_DOWN){
        glutPassiveMotionFunc(movimentaMouse);

        a_1 = x;
        a_2 = y;
         printf("clique esquerdo:(%d , %d)\n",x, y);
    }
  }
    
    
    
   if (botao == GLUT_RIGHT_BUTTON){

     if (estado == GLUT_DOWN){
        glutPassiveMotionFunc(movimentaMouse);
        
         a_7 = x;
         a_8 = y;
        printf("clique direito:(%d , %d)\n",x, y);
     }
   }

    
    
   if (botao == GLUT_MIDDLE_BUTTON){
        printf("clique do scroll:(%d , %d)\n",x, y);
     
    if (estado == GLUT_DOWN){
        glutPassiveMotionFunc(movimentaMouse);
         
           a_3 = x;
           a_4 = y;
           a_5 = x;
           a_6 = y;

     }
   }

   if (botao == GLUT_MIDDLE_BUTTON){
    
    if (estado == GLUT_UP){
        glutPassiveMotionFunc(movimentaMouse);
           a_3 = 200;
           a_4 = 450;
           a_5 = 600;
           a_6 = 450;

     }
   }


  glutPostRedisplay();

}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);{

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(800,800);
        glutInitWindowPosition(320,150);
        glutCreateWindow("Função Mouse - Interação");
        glutDisplayFunc(desenhaObjetos);
        glutMouseFunc(gerenciaMouse);
        glClearColor(0.56,0.93,0.56,0);
        glutMainLoop();

    return 0;
    }
}
