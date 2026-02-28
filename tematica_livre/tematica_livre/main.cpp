#define GL_SILENCE_DEPRECATION//biblioteca que permite todas as chamadas da API openGL
#include <GLUT/glut.h>                 //biblioteca que permite a manipulação de janelas
#include <math.h>                   //conjunto de funções para operações matemáticas

GLfloat r = 0, g = 0, b = 0;              // variáveis para controle de cor (inicia em preto)
int submenucor;
GLint x,y;
GLint direcao = 1, maximo=1;
GLfloat movex = 0;
int movex_2 , movey ;
//Função que adiciona linhas para montar um plano cartesiano


void casa(){
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    
        glVertex2f(-30, 0);
        glVertex2f(-15, -15);
    
        glVertex2f(-15, -51);
        glVertex2f(-47, -51);
        glVertex2f(-47, -15);
        glVertex2f(-15, -51);
        glVertex2f(-30, 0);

    glEnd();
}
void beradas(){
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex2f(-47, -51);
        glVertex2f(-43, -51);
        glVertex2f(-43, -25);
        glVertex2f(-47, -25);
        
    glEnd();
    
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    
        glVertex2f(-36,-51);
        glVertex2f(-34, -37);
        glVertex2f(-34, -23);
        glVertex2f(-36,-25);
    
    glEnd();
    
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    
        glVertex2f(-17, -37);
        glVertex2f(-17, -23);
        glVertex2f(-15, -23);
        glVertex2f(-15, -37);
    
    glEnd();
    
}
void teto(){
    glColor3d(1, 0, 0);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(-30, 5);
    
        glVertex2f(-47, -15);
        glVertex2f(-15, -15);

    glEnd();
}
void janela(){
    glColor3d(1 ,0.98 ,0.8);
    glBegin(GL_QUADS);
       
        glVertex2f(-34, -23);
        glVertex2f(-34, -37);

    glColor3d(r, g, b);
    
        glVertex2f(-17, -37);
        glVertex2f(-17, -23);
    
    glEnd();
    
}
void corpo(){
    glLineWidth(8);               //adiciona espessura a linha desenhada
    glColor3f(0,0,0);             //adiciona cor às linhas
    glBegin(GL_LINES);
        glVertex2f(-30, -43);
        glVertex2f(-30, -30);
        
        glVertex2f(-30, -43); //perna1
        glVertex2f(-32, -51);
        
        glVertex2f(-30, -43);  //perna2
        glVertex2f(-28, -51);
        
        glVertex2f(-30, -39);
        glVertex2f(-26, -30);
        
        glVertex2f(-30, -35.5);
        glVertex2f(-33, -44);
    
    glEnd();
}
void corpo_janela(){
    glLineWidth(8);               //adiciona espessura a linha desenhada
    glColor3f(0,0,0);             //adiciona cor às linhas
    glBegin(GL_LINES);
       
        glVertex2f(-30, -37);
        glVertex2f(-30, -30);
        

        glVertex2f(-30, -37);
        glVertex2f(-26, -30);
    
    glEnd();
}
void porta(){
    glColor3f(1, 0.86, 0.35);
    glBegin(GL_QUADS);
       
        glVertex2f(-43,-51);
        glVertex2f(-36,-51);
        glVertex2f(-36,-25);
        glVertex2f(-43,-25);

    glEnd();

}
void chao(){
    glColor3f(0.13, 0.55 ,0.13);        //adiciona cor ao poligono
    glBegin(GL_QUADS);
     
        glVertex2f(-60,-40);
        glVertex2f(60,-40);
        glVertex2f(60,-60);
        glVertex2f(-60,-60);
    glEnd();
}
void tronco(){
    glColor3f(0.89 ,0.45 ,0.36);
    glBegin(GL_QUADS);
    
        glVertex2f(15,-52);
        glVertex2f(15,-24);
        glVertex2f(20,-24);
        glVertex2f(20,-52);
    
    glEnd();
   
}

void sol(){
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        
    
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;
            
            
            glVertex2f (-10+9*cos(theta), 40+9*sin(theta));       //adiciona a posição
            
            glColor3d(1 ,0.55 ,0);
        }
    glEnd();
}

void pessoa(){
    glColor3d(0, 0, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        
    
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;
            glVertex2f (-10+2*cos(theta), 40+3*sin(theta));       //adiciona a posição
            
        }
    glEnd();
}
void pessoa_janela(){
    glColor3d(0, 0, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        
    
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;
            glVertex2f (-10+2*cos(theta), 40+3*sin(theta));       //adiciona a posição
            
        }
    glEnd();
}
void folhas(){
    glColor3f(0, 0.39, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+10*cos(theta), 40+15*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}


void timerPonto(int passo){                //função timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
    
    
    if (direcao == 1){
         x-=1;                     //decrementa nosso moveponto até o limite estipulado
         if(x == -40){             //se move ponto for igual ao nosso limite inferior máximo no eixo y-
             direcao = 2;                  //começa a subir no eixo y, quando chegar no limite de -90y
         }
     }

     else if (direcao == 2){
         x+=1;
         if(x == 10){
             direcao = 1;
         }
     }
     
    
    


     glutPostRedisplay();                 //chama a função desenha toda vez que for necessária
    
     glutTimerFunc(100,timerPonto,1);     //precisamos chamar a função timer toda vez, Ele executa essa fun ção timer e entra aqui novamente. Até eu querer sair da função timer (neste caso, não queremos sair)
 }

void macaneta(){
    
    glColor3f(0.24, 0.17 ,0.12);                                        //adiciona cor ao nosso círculo
    
    glBegin(GL_POLYGON);
    //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+1*cos(theta), 40+1.5*sin(theta));
            
        }
    
    
    glEnd();
  
    
}
void nuvem_1(){
    
    glColor3f(0.66, 0.66, 0.66);                                        //adiciona cor ao nosso círculo
    
    glBegin(GL_POLYGON);
    //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 181; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+8*cos(theta)+ (x), 40+9*sin(theta));
            
        }
    
    
    glEnd();
  
    
}

void nuvem_2(){

    glColor3f(0.66, 0.66, 0.66);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 181; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+8*cos(theta)+x, 40+9*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}
void nuvem_3(){

    glColor3f(0.66, 0.66, 0.66);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 181; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+8*cos(theta)+x, 40+9*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}
void nuvem_4(){

    glColor3f(0.66, 0.66, 0.66);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 181; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+8*cos(theta)+x, 40+9*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}
void nuvem_5(){

    glColor3f(0.66, 0.66, 0.66);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 181; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+8*cos(theta)+x, 40+9*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}


void nuvem_6(){

    glColor3f(0.66, 0.66, 0.66);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 181; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+8*cos(theta)+x, 40+9*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}

void passarinhos (){
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    
        glVertex2f(5+movex_2, 20+ movey);
        glVertex2f(8+movex_2, 20+movey);
        glVertex2f(11+movex_2, 17+movey);
    
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    
        glVertex2f(10, 17);
        glVertex2f(15, 20);
        glVertex2f(12, 20);
    
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
        
        glVertex2f(0, 16);
        glVertex2f(-3, 16);
        glVertex2f(2, 13);
    
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
        
        glVertex2f(1, 13);
        glVertex2f(4, 16);
        glVertex2f(7, 16);
    
    glEnd();
}


void escolheCor(int opcao){                //verifica a opção escolhida
    switch(opcao){
        case 0:                           //caso  o valor de opção for 0 pinta de vermelho
            r = 1 ;                        //atribui valores as variáveis de cor
            g = 0.55;                        //atribui valores as variáveis de cor
            b = 0;                        //atribui valores as variáveis de cor
        break;
        case 1:                           //caso  o valor de opção for 1 pinta de verde
            r = 0.99;                        //atribui valores as variáveis de cor
            g =  0.91 ;                        //atribui valores as variáveis de cor
            b =  0.06;                        //atribui valores as variáveis de cor
        break;
        case 2:                           //caso  o valor de opção for 2 pinta de azul
            r = 1;                        //atribui valores as variáveis de cor
            g = 0;                        //atribui valores as variáveis de cor
            b = 0;                        //atribui valores as variáveis de cor
        break;
    }
    glutPostRedisplay();                  //chama a função desenha toda vez que for necessária
}

void menuCor(){
    submenucor = glutCreateMenu(escolheCor);               //cria um novo menu pop-up
    glutAddMenuEntry("27 ºC", 0);                       //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("36 ºC", 1);                          //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("42 ºC", 2);                           //adiciona uma entrada de menu na parte inferior do menu atual
}
void Inicializa(void){
    r = 1 ;                        //atribui valores as variáveis de cor
    g = 0.55;                        //atribui valores as variáveis de cor
    b = 0;
    
}

void criaMenu(){
    menuCor();                                             //Chama a função que cria o submenu cor
    glutCreateMenu(0);                                     //cria um novo menu pop-up (no caso, o principal, onde estarão adicionados os outros submenus)
    glutAddSubMenu("Escolha a Temperatura", submenucor);           //adiciona um gatilho de submenu à parte inferior do menu atual
    glutAttachMenu(GLUT_RIGHT_BUTTON);                      //anexa um botão do mouse para a janela

}
void movimentaMouse(int x, int y){
    movex_2 = x;
    movey = y;

    glutPostRedisplay();
}

void gerenciaMouse(int botao, int estado, int x, int y){      //Parâmetros de entrada da função: (int button, int state, int x, int y).  Os parâmetros x e y indicam a localização do mouse no momento que o evento ocorreu.
    if(botao == GLUT_RIGHT_BUTTON)  {                           //se o botão do mouse clicado for o direito
        if(estado == GLUT_DOWN){                              //O parâmetro state pode ser GLUT_UP ou GLUT_DOWN.
            criaMenu();
            
          if (botao == GLUT_LEFT_BUTTON)                                 ///Três valores são válidos para o parâmetro button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON e GLUT_RIGHT_BUTTON.
                if(estado == GLUT_DOWN){                                   //O parâmetro state pode ser GLUT_UP ou GLUT_DOWN.
                    glutMotionFunc(movimentaMouse);
             //chama a função que cria o menu
                    glutPostRedisplay();
        }
    glutPostRedisplay();
//Função de desenho
        }}}
/*void gerenciaMouse_2(int botao, int estado, int x, int y){           //Parâmetros de entrada da função: (int button, int state, int x, int y).  Os parâmetros x e y indicam a localização do mouse no momento que o evento ocorreu.
    if (botao == GLUT_LEFT_BUTTON)                                 ///Três valores são válidos para o parâmetro button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON e GLUT_RIGHT_BUTTON.
        if(estado == GLUT_UP){                                   //O parâmetro state pode ser GLUT_UP ou GLUT_DOWN.
            glutMotionFunc(movimentaMouse);                        //glutMotionFunc  define o movimento para a janela atual. O retorno de chamada de movimento para uma janela é chamado quando o mouse se move dentro da janela enquanto um ou mais botões do mouse são pressionados.
        }
    glutPostRedisplay();                                           //chama a função desenha toda vez que for necessária
}*/
void setasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){
        case GLUT_KEY_LEFT: movex--;               // move nosso objeto para a esquerda
        break;
        case GLUT_KEY_RIGHT: movex++;              // move nosso objeto para a direita
        break;
        
    }
    glutPostRedisplay();
}
            
void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();              //carrega a projeção
    gluOrtho2D(-60,60,-60,60);     // define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);    // projeção do tipo modelo
    glLoadIdentity();
    glColor3f(r, g, b);


    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        chao();
    
   // glTranslatef(-20, -70, 0);
   // glTranslatef(movex,0,0);
     //   pessoa();
    glPopMatrix();

    
    glPushMatrix();
        glTranslatef(movex,0,0);
        corpo();
    glPopMatrix();
    
    
    glPushMatrix();
        casa();
  
        janela();
    glTranslatef(movex,0,0);
    corpo_janela();
    glTranslatef(-20, -70, 0);
    
    pessoa();
    glPopMatrix();
    
    
    
    glPushMatrix();
        teto();
    glPopMatrix();
   
    glPushMatrix();
    
    glPopMatrix();
    
    
   
    glPushMatrix();
        nuvem_1();
    glTranslatef(30,2,0);
        nuvem_2();
        glTranslatef(-10, 0, 0);
        nuvem_3();
    glPopMatrix();
    
    

    glPushMatrix();
        glTranslatef(-10, 0, 0);
        nuvem_4();
    glPopMatrix();
    
    
    
    glPushMatrix();
        glTranslatef(40,2,0);
        glColor3f(r, g, b);
        sol();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(50, -10, 0);
        nuvem_5();
        glTranslatef(10, 0, 0);
        nuvem_6();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(movex,0,0);
    corpo_janela();
    glTranslatef(-20, -70, 0);
    
        //pessoa();
    pessoa_janela();
    glPopMatrix();
   
    glPushMatrix();
   // glTranslatef(movex,0,0);
   // corpo();
    glPopMatrix();
    
    
    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        tronco();
        porta();
    beradas();
  //  glTranslatef(movex,movey,0);
    passarinhos();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(28,-60,0);
        folhas();
    glPopMatrix();
   
    glPushMatrix();
       // porta();
    glTranslatef(-31,-80,0);
    macaneta();
    glPopMatrix();

    glutSwapBuffers();
    glFlush();

}


    int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                                                      //somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                                                      //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
    glutCreateWindow("Introdução ao OpenGL");                                                         //permite a criação de uma janela
        glutDisplayFunc(desenhaObjetos);
        glutTimerFunc(100,timerPonto,1);
        glutSpecialFunc(setasDirecionais);
        glutMouseFunc(gerenciaMouse);
       //glutMouseFunc(gerenciaMouse_2);
        Inicializa();
    glClearColor(0.68, 0.85, 0.9,0);
    glutMainLoop();                                                                                   //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                                                                         //retorna zero
}
