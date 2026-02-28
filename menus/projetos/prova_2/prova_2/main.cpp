
/* CRONOMETRO DE 6 SEGUNDOS QUE MUDA DE COR, O "06" GIRA COM CONTROLE DE TECLADO */



#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
         
GLint largura, altura;                          //largura e altura da minha janela

GLfloat r = 0, g = 0, b = 0;              // variáveis para controle de cor (inicia em preto)
int submenucor;                           //variável para o submenu

int selected = 1;                               // variável de controle para saber se estamos controlando os dois elementos (A ou 1) ou apenas um (B ou 2)
GLfloat aspecto, angulo, rotacao;
// aspecto: variável para controlar windowsize; angulo: para projeção/perspectiva; rotação: para o objeto.

//Material do objeto (material branco) (parâmetros)
GLfloat object_ambient[]   = {0.3, 0.0, 0.0, 1.0};
GLfloat object_difusa[]    = {0.0, 1.0, 0.0, 1.0};
GLfloat object_especular[] = {1.0, 0.9, 0.9, 1.0};
GLfloat object_emissao[]   = {0.0, 0.0, 0.0, 0.0};
GLfloat object_brilho[]    = {20.0};

//Informações sobre a luz (parâmetros)
GLfloat cor_luz_ativa[]    = {1.0, 1.0, 0.0, 1.0};
GLfloat cor_luz0[]         = {1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz_amb[]      = {0.1, 0.1, 0.1, 1.0};
GLfloat posicao_luz0[]     = {8.0, 8.0, 15.0,1.0};

GLfloat width, height;
static int segundos = -90; //ponteiro
static int timer = -100;// ponteiro

int ligacor = 0;
int posicaoluz = 0;


//controla a iluminaçao
void init(void)
{
   /* Cria as matrizes responsáveis pelo
      controle de luzes na cena */
GLfloat ambiente[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat difusa[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat especular[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat posicao[] = { 0.0, 3.0, 2.0, 0.0 };
GLfloat lmodelo_ambiente[] = { 0.2, 0.2, 0.2, 1.0 };
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);
   /* Cria e configura a Luz para a cena */
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, difusa);
    glLightfv(GL_LIGHT0, GL_POSITION, posicao);
    glLightfv(GL_LIGHT0, GL_SPECULAR, especular);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodelo_ambiente);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}
void desenhaObjetos(void)
{
     glClear(GL_COLOR_BUFFER_BIT);              //buffer padrão (limpa a tela toda vez que a função é chamada)
    GLfloat posicao[] = { 0.0, 3.0, 2.0, 0.0 };
      /*
        Limpa o buffer de pixels e
        determina a cor padrão dos objetos.
    */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glColor3f (1.0, 1.0, 1.0);
      /* Armazena o estado anterior para
         rotação da posição da luz */
      glPushMatrix () ;
    glRotated ((GLdouble) posicaoluz, 1.0, 0.0, 0.0);
    glLightfv (GL_LIGHT0, GL_POSITION, posicao);
      glPopMatrix(); // Posição da Luz
    /* Armazena a situação atual da pilha de matrizes */ glPushMatrix();
          glRotatef ((GLfloat) segundos, 0.0, 0.0, 1.0);
          glTranslatef (2.0, 0.0, 0.0);
        glPopMatrix();
                                  //insere a matriz de transformação corrente na pilha
    
     
       
    //ponteiro
        glPushMatrix();
        glColor3f(r,g,b);
        glRotatef ((GLfloat) segundos, 0.0, 0.0, -0.5);
       // glRotatef(rotA, 0,0,1);                 //rotaciona os dois elementos juntos
        glTranslatef(1,0,0);                    //translada o objeto no eixo x
        glScalef(3, 0.2, 0.2);             //escalona nosso cubo para ele virar um paralelepípedo
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    
   
    //-
        glPushMatrix();
        glColor3f(0,0,0);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(3.5,0,0);
        glScalef(1, 0.1, 0.2);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    
    //----
        glPushMatrix();
        glColor3f(0,0,0);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(-3.5,0,0);
        glScalef(1, 0.1, 0.2);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    
    
    //---
        glPushMatrix();
        glColor3f(0,0,0);
       
        glTranslatef(0,3.5,0);
        glRotatef(90,0,1,0);
        glScalef(1, 0.1, 0.2);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
      
    //--
        glPushMatrix();
        glColor3f(0,0,0);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(0,-3.5,0);
        glRotatef(90,0,1,0);
        glScalef(1, 0.1, 0.2);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
        
    //rapido
        glPushMatrix();
        glColor3f(0,0,0);
        glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(1,0,0);
        glScalef(3, 0.1, 0.2);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
        
   //relogio
        glPushMatrix();
    glRotatef(posicaoluz, 0, 1, 0); //adiciona cor a nossa forma
        glRotatef(180,0,1,1);
        glColor3f(r,g,b);
        glutSolidTorus(0.4,5,70,30);
   
        glPopMatrix();
  
    //vidro
    glPushMatrix();
        glColor4f(r, g, b, 0.3);
    glScaled(1.08, 0.48, 1);
    glTranslatef(0, 1.89, 1);
        glutSolidSphere(5,60,30);
    glPopMatrix();
   
    //0
        glPushMatrix();
        glColor3f(r,g,b);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(-6,-5.6,0);
        glRotatef(90,0,1,0);
        glScalef(1, 0.8, 0.2);
    glRotatef(rotacao, 0, 0, 1);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    //0
        glPushMatrix();
        glColor3f(r,g,b);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(-5.4,-5.6,0);
        glRotatef(90,0,1,0);
        glScalef(1, 0.8, 0.2);
    glRotatef(rotacao, 0, 0, 1);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
   
    
    //0
        glPushMatrix();
        glColor3f(r,g,b);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(-5.6,-4.8,0);
        
        glScalef(0.6, 0, 0.3);
    glRotatef(rotacao, 0, 0, 1);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    //0
        glPushMatrix();
        glColor3f(r,g,b);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(-5.7,-6.4,0);
        glScalef(0.7, 0, 0.3);
    glRotatef(rotacao, 0, 0, 1);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    
    //6
        glPushMatrix();
        glColor3f(r,g,b);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(-4.8,-5.6,0);
        glRotatef(90,0,1,0);
        glScalef(1, 0.8, 0.2);
    glRotatef(rotacao, 0, 0, 1);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    
    //06
    glPushMatrix();
        glColor3f(r,g,b);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(-4.5,-6.4,0);
        glScalef(0.7, 0, 0.3);
    glRotatef(rotacao, 0, 0, 1);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    //06
    glPushMatrix();
        glColor3f(r,g,b);
   
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(-4.5,-5.7,0);
        glScalef(0.7, 0, 0.3);
    glRotatef(rotacao, 0, 0, 1);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    
    //06
    glPushMatrix();
        glColor3f(r,g,b);
       // glRotatef ((GLfloat) timer, 0.0, 0.0, -1.0);
        glTranslatef(-4.2,-6,0);
    glRotatef(90,0,1,0);
        glScalef(0.7, 0, 0.3);
    glRotatef(rotacao, 0, 0, 1);
        glutSolidCube(1);                  //cria uma forma 3d sólida
        glPopMatrix();
    
     glutSwapBuffers();
    //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers)
}

//inicializa
void inicializa (void)
{
    glClearColor(1,1,1,0);
    angulo = 1.5;
    //inicializa com valor 1 nosso ângulo
    glEnable(GL_DEPTH_TEST);        //habilita o depth-buffering
    glEnable(GL_LIGHTING);          //habilita o uso de iluminaçã
    glEnable(GL_LIGHT0);            //habilita a luz de número 0
    glEnable(GL_BLEND);                                    //ativa as funções de BLEND
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    r = 1;                        //atribui valores as variáveis de cor
    g = 0;                        //atribui valores as variáveis de cor
    b = 0;
}

//chama as cores
void escolheCor(int opcao){                //verifica a opção escolhida
    switch(opcao){
        case 0:                           //caso  o valor de opção for 0 pinta de vermelho
            r = 1;                        //atribui valores as variáveis de cor
            g = 0;                        //atribui valores as variáveis de cor
            b = 0;                        //atribui valores as variáveis de cor
        break;
        case 1:                           //caso  o valor de opção for 1 pinta de verde
            r = 0;                        //atribui valores as variáveis de cor
            g = 1;                        //atribui valores as variáveis de cor
            b = 0;                        //atribui valores as variáveis de cor
        break;
        case 2:                           //caso  o valor de opção for 2 pinta de azul
            r = 0;                        //atribui valores as variáveis de cor
            g = 0;                        //atribui valores as variáveis de cor
            b = 1;                        //atribui valores as variáveis de cor
        break;
    }
    glutPostRedisplay();                  //chama a função desenha toda vez que for necessária
}

//cria o sub menu
void menuCor(){
    submenucor = glutCreateMenu(escolheCor);               //cria um novo menu pop-up
    glutAddMenuEntry("Vermelho", 0);                       //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("Verde", 1);                          //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("Azul", 2);                           //adiciona uma entrada de menu na parte inferior do menu atual
}

//cria o menu
void criaMenu(){
    menuCor();                                             //Chama a função que cria o submenu cor
    glutCreateMenu(0);                                     //cria um novo menu pop-up (no caso, o principal, onde estarão adicionados os outros submenus)
    glutAddSubMenu("Escolha a Cor", submenucor);
    //adiciona um gatilho de submenu à parte inferior do menu atual
    glutAddSubMenu("Cronometrar", timer);
    glutAttachMenu(GLUT_RIGHT_BUTTON);                      //anexa um botão do mouse para a janela

}

void gerenciaMouse(int botao, int estado, int x, int y){      //Parâmetros de entrada da função: (int button, int state, int x, int y).  Os parâmetros x e y indicam a localização do mouse no momento que o evento ocorreu.
    if(botao == GLUT_RIGHT_BUTTON)                             //se o botão do mouse clicado for o esquerdo
        if(estado == GLUT_DOWN){                              //O parâmetro state pode ser GLUT_UP ou GLUT_DOWN.
            criaMenu();
            //chama a função que cria o menu
            
        }
    glutPostRedisplay();                                      //chama a função desenha toda vez que for necessária
}

void projetaPlano(void){
    glMatrixMode(GL_PROJECTION);                    //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();                               //carrega a projeção
    gluPerspective(angulo, aspecto, 0.1, 500);      //função que estabelece os parâmetros da Projeção Perspectiva, atualizando a matriz de projeção perspectiva.
    glMatrixMode(GL_MODELVIEW);                     //projeção do tipo modelo
    glLoadIdentity();                               //carrega a identidade de projeção de modelo
    gluLookAt(0, 300, 300, 0, 0, 0, 0, 1, 0);       //define a transformação de visualização, através dos argumentos é possível indicar a posição da câmera (para onde ela está direcionada).
}
void teclasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){                                         //escolhe a tecla pressionada
        case GLUT_KEY_RIGHT: static_cast<void>((rotacao+=3)),posicao_luz0[1]+=2;              //rotaciona nosso objeto sentido horário
            break;
        case GLUT_KEY_LEFT: static_cast<void>(rotacao-=3),posicao_luz0[1]-=2;               //rotaciona nosso objeto sentido anti-horário
            break;
    }
    projetaPlano();                                        //chama a função projetaPlano
    glutPostRedisplay();                                   //redesenha a cena que está na janela
}

//faz o ponteiro girar 360º
void spinDisplay(void)
{
    segundos = (segundos + 1) % 360;
    timer = (timer + 2) % 360;
    glutPostRedisplay();
}


//controla o mouse
void mouse(int button, int state, int x, int y)
{
   if (button== GLUT_LEFT_BUTTON)
       if (state == GLUT_DOWN){
            glutIdleFunc(spinDisplay);
       }
        if(button == GLUT_RIGHT_BUTTON)                             //se o botão do mouse clicado for o esquerdo
                if(state == GLUT_DOWN){                              //O parâmetro state pode ser GLUT_UP ou GLUT_DOWN.
                    criaMenu();
      
} }


void alteraTamanhoJanela(GLsizei w, GLsizei h){     //faz o controle do tamanho das viewports (padrão de parâmetros, altura e largura) (800x600 no glutInitWindowSize)
    glViewport(0, 0, w, h);                         //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
    largura = w;                                    //altura eu mantenho a mesma, pois não vou dividir a janela.
    altura = h;                                     //largura eu mantenho a mesma, pois não vou dividir a janela.
    aspecto = (float)largura / altura;              //largura dividida pela altura (utilizada para controlar a largura da janela automaticamente, independente de eu alterar a windowsize) (faz com que as janelas tenham a mesma proporção em cada viewport)
    projetaPlano();                                 //chama a função projetaPlano
}





/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char *argv[]){
glutInit(&argc,argv);
{
     glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);   //somente um double buffer | sistema de cores RGB
     glutInitWindowSize(800,600);                   //define o tamanho da janela
     glutInitWindowPosition(300,120);               //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
     glutCreateWindow("*** CRONÔMETRO 6 SEGUNDOS ***");           //permite a criação de uma janela
    init();
    glutDisplayFunc(desenhaObjetos);               //função de callback - chama a função desenhaObjetos
    glutSpecialFunc(teclasDirecionais);            //chama a função que escuta nossas teclas direcionais
    glutMouseFunc(mouse);
   //  glutKeyboardFunc(teclas);                      // Chamada da função teclado (cada pressionamento gera uma chamada do teclado)
     glutReshapeFunc(alteraTamanhoJanela);          //função que altera o tamanho da janela, redesenha o tamanho da janela
  //  glutMouseFunc(gerenciaMouse);
     inicializa();                                  //função que inicializa nossas variáveis
     glutMainLoop();                                //loop infinito - escuta as informações do sistema até encerrar a aplicação
     return 0;                                      //retorna zero
}}
