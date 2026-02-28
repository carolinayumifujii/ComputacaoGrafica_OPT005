
/* Exemplo7.c - Marcionílio Barbosa Sobrinho

Programa que apresenta uma variação do Exemplo6.c, com a funcionalidade
de luzes na cena, além de apresentar as características de materiais A posição da Luz pode ser modicada através do botão direito do mouse.
Referência do Código: OpenGL Programming Guide - RedBook planet.c, movelight.c, material.c

 */
 #define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>  // GLUT, include glu.h and gl.h

static int year = 0, day = 0, wire = 0;
int ligacor = 0;
int posicaoluz = 0;
void init(void)
{
   /* Cria as matrizes responsáveis pelo
      controle de luzes na cena */
GLfloat ambiente[] = { 0.2, 0.2, 0.2, 1.0 }; GLfloat difusa[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat especular[] = { 1.0, 1.0, 1.0, 1.0 }; GLfloat posicao[] = { 0.0, 3.0, 2.0, 0.0 };
GLfloat lmodelo_ambiente[] = { 0.2, 0.2, 0.2, 1.0 };
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);
   /* Cria e configura a Luz para a cena */
glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente); glLightfv(GL_LIGHT0, GL_DIFFUSE, difusa); glLightfv(GL_LIGHT0, GL_POSITION, posicao); glLightfv(GL_LIGHT0, GL_SPECULAR, especular); glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodelo_ambiente);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_COLOR_MATERIAL);
}
/*
Função responsável pelo desenho das esferas.
Nesta função também serão aplicadas as tranformações necessárias para o efeito desejado.
*/
void display(void)
{
/* Variáveis para definição da capacidade de brilho do material */ GLfloat semespecular[4]={0.0,0.0,0.0,1.0};
GLfloat especular[] = { 1.0, 1.0, 1.0, 1.0 };
  /* Posição da luz */
  GLfloat posicao[] = { 0.0, 3.0, 2.0, 0.0 };
  /*
    Limpa o buffer de pixels e
    determina a cor padrão dos objetos.
*/
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glColor3f (1.0, 1.0, 1.0);
  /* Armazena o estado anterior para
     rotação da posição da luz */
  glPushMatrix () ;
glRotated ((GLdouble) posicaoluz, 1.0, 0.0, 0.0); glLightfv (GL_LIGHT0, GL_POSITION, posicao);
  glPopMatrix(); // Posição da Luz
/* Armazena a situação atual da pilha de matrizes */ glPushMatrix();
      glRotatef ((GLfloat) year, 0.0, 0.0, 1.0);
      glTranslatef (2.0, 0.0, 0.0);


      glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
      glColor3f (0.0, 0.0, 1.0);
/* Define a propriedade do material */ //refletância do material glMaterialfv(GL_FRONT,GL_SPECULAR, especular);
// Define a concentração do brilho glMateriali(GL_FRONT,GL_SHININESS,20);
/* Se a tecla w for pressionada irá fazer o controle
do tipo de apresentação de sólido ou Wire (aramado) */
      if (wire == 0)
          glutSolidSphere(0.2, 20, 18);
      else
          glutWireSphere(0.2,10, 8);
/*Descarrega a pilha de matrizes até o último glPushMatrix */ glPopMatrix();
    glPushMatrix();
      glColor3f (0.89, 0.79, 0.09);
/* Define a propriedade do material */ //refletância do material glMaterialfv(GL_FRONT,GL_SPECULAR, semespecular);
// Define a concentração do brilho glMateriali(GL_FRONT,GL_SHININESS,100);
      if (wire == 0)
         glutSolidSphere(1.0, 30, 26);
      else
         glutWireSphere(1.0, 20, 16);
    glPopMatrix();
  // Executa os comandos
  glutSwapBuffers();
}
/*
Função responsável pelo desenho da tela
Nesta função são determinados o tipo de Projeção
o modelo de Matrizes e
a posição da câmera
Quando a tela é redimensionada os valores
da visão perspectiva são recalculados com base no novo tamanho da tela assim como o Viewport
*/
void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h); glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); }
/* Função responsável pelo controle de teclado
quando pressionada a tecla d, será executada uma rotação no próprio eixo da esfera menor. Quando pressionada a tecla y
a esfera menor irá rotacionar em torno da esfera maior, em uma órbida determinada na translação na função display()
A tecla w é responsável por determinar se as esferas serão sólidas ou aramadas (wire)
81

*/
void keyboard (unsigned char key, int x, int y)
{
  switch (key) {
      case 'd':
      case 'D':
           day = (day + 10) % 360;
           glutPostRedisplay();
           break;
      case 'Y':
      case 'y':
           year = (year + 5) % 360;
           glutPostRedisplay();
           break;
      case 'w' :
      case 'W' :
           wire = wire == 1 ? 0 : 1;
           glutPostRedisplay();
           break;
      default:
           break;
} }
/*
Esta função é chamada quando o botão esquerdo do
mouse é pressionado, a mesma irá calcular um novo
valor para os valores dos ângulos contidos em year e day
*/
void spinDisplay(void)
{
year = (year + 1) % 360; day =(day+2)%360; glutPostRedisplay();
}
/*
Esta função irá controlar os botões do mouse.
Se pressionado o botão da esquerda ela define
a função spinDisplay como a função de "idle" do GLUT
o comando glutIdelFunc, executa uma determinada função quando nenhum evento estiver ocorrendo. (pressionamento de botões etc.) Quando o botão do meio é pressionado a função de Idle recebe NULL desabilitando a animação
*/
void mouse(int button)
{
  switch (button) {
      case GLUT_LEFT_BUTTON:
           if (GLUT_DOWN)
              glutIdleFunc(spinDisplay);
           break;
      case GLUT_MIDDLE_BUTTON:
           if (GLUT_DOWN)
              glutIdleFunc(0);
           break;
      case GLUT_RIGHT_BUTTON:
           posicaoluz = (posicaoluz + 1) % 360;
           glutPostRedisplay();
           break;
      default:
           break;
} }
/*
 Função principal do programa.
*/int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DEPTH | GLUT_RGB);


glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Exemplo 7 - Propriedades de Materiais"); init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMouseFunc(mouse);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
}
