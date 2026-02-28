#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>


#define QUADRADO 1
#define TRIANGULO 2
#define LOSANGO   3

GLfloat r, g, b;
GLint  forma;

// Função que desenha um quadrado
void DesenhaQuadrado(void)
{
     glBegin(GL_QUADS);
               glVertex2f(-5, -5);
               glVertex2f(-5, 5);
               glVertex2f(5, 5);
               glVertex2f(5, -5);
     glEnd();
}

// Função que desenha um triângulo
void DesenhaTriangulo(void)
{
     glBegin(GL_TRIANGLES);
               glVertex2f(-5, -5);
               glVertex2f(0, 5);
               glVertex2f(5, -5);
     glEnd();
}

// Função que desenha um losango
void DesenhaLosango(void)
{
     glBegin(GL_POLYGON);
               glVertex2f(-5, 0);
               glVertex2f(0, 5);
               glVertex2f(5, 0);
               glVertex2f(0, -5);
     glEnd();
}




void Desenha(void)
{   glClear(GL_COLOR_BUFFER_BIT);         //buffer padrão; limpa a tela toda vez que a função é chamada
    glMatrixMode(GL_PROJECTION);          //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();                       //carrega a projeção
    gluOrtho2D(-30,30,-30,30);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     glClear(GL_COLOR_BUFFER_BIT);
     
     
     glColor3f(r,g,b);

     
     switch (forma) {
            case QUADRADO:  DesenhaQuadrado();
                            break;
            case TRIANGULO: DesenhaTriangulo();
                            break;
            case LOSANGO:   DesenhaLosango();
                            break;
     }
     glutSwapBuffers();
}


void Inicializa (void)
{
    glClearColor(1, 1, 1, 0);
  
    forma = QUADRADO;
    r = 0;
    g = 0;
    b = 1;
    
}

void MenuCor(int op)
{
   switch(op) {
            case 0:
                     r = 1;
                     g = 0;
                     b = 0;
                     break;
            case 1:
                     r = 0;
                     g = 1;
                     b = 0;
                     break;
            case 2:
                     r = 0;
                     g = 0;
                     b = 1;
                     break;
    }
    glutPostRedisplay();
}

void MenuFormas(int op)
{
   switch(op) {
            case 0:
                     forma = QUADRADO;
                break;
            case 1:
                    forma  = TRIANGULO;
                break;
            case 2:
                    forma  = LOSANGO;
                break;
    }
    glutPostRedisplay();
}
        
void MenuPrincipal(int op)
{
}
              
void CriaMenu()
{
    int menu,submenu1,submenu2;

    submenu1 = glutCreateMenu(MenuCor);
        glutAddMenuEntry("Vermelho",0);
        glutAddMenuEntry("Verde",1);
        glutAddMenuEntry("Azul",2);

    submenu2 = glutCreateMenu(MenuFormas);
        glutAddMenuEntry("Quadrado",0);
        glutAddMenuEntry("Triângulo",1);
        glutAddMenuEntry("Losango",2);

    menu = glutCreateMenu(MenuPrincipal);
        glutAddSubMenu("Cor",submenu1);
        glutAddSubMenu("Forma",submenu2);
        
    
    glutAttachMenu(GLUT_LEFT_BUTTON);
}
           
void GerenciaMouse(int botao, int estado, int x, int y)
{
    if (botao == GLUT_LEFT_BUTTON)
         if (estado == GLUT_DOWN)
            CriaMenu();
         
    glutPostRedisplay();
}


int main(int argc, char *argv[]){
glutInit(&argc,argv);
{
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(800,600);
        glutInitWindowPosition(320,150);
        glutCreateWindow("Interação com Mouse e Menu");
        glutDisplayFunc(Desenha);
        glClearColor(1,1,1,0);
        glutMouseFunc(GerenciaMouse);
        Inicializa();
        glutMainLoop();
}
}
