#define GL_SILENCE_DEPRECATION//biblioteca que permite todas as chamadas da API openGL
#include <GLUT/glut.h> //biblioteca que permite a manipulação de janelas
#include <Math.h>                   //conjunto de funções para operações matemáticas

void rua(){
    glColor3f(0.47, 0.53, 0.42);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);       //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-60, -60);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(-60, -40);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(60, -40);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(60, -60);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void arvore(){
    glColor3f(0.55, 0.27, 0.07);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(-40, -40);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(-40, -10);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(-35, -10);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(-35, -40);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void circuloArvore(){
    glColor3f(0, 0.39, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+15*cos(theta), 40+15*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}

void maca1(){
    glColor3f(1, 0, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+1*cos(theta), 40+1*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}

void maca2(){
    glColor3f(1, 0, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+1*cos(theta), 40+1*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}

void maca3(){
    glColor3f(1, 0, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+1*cos(theta), 40+1*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}

void maca4(){
    glColor3f(1, 0, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+1*cos(theta), 40+1*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}

void maca5(){
    glColor3f(1, 0, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+1*cos(theta), 40+1*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}

void lua(){
    glColor3f(0.66, 0.66, 0.66);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+3*cos(theta), 40+3*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}

void predio(){
    glColor3f(0.69, 0.88, 0.9);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(-10, -40);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(-10, 40);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(30, 40);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(30, -40);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void janela1(){
    glColor3f(0, 0, 0);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(-5, 25);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(-5, 35);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(5, 35);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(5, 25);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void janela2(){
    glColor3f(0, 0, 0);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(15, 25);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(15, 35);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(25, 35);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(25, 25);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void janela3(){
    glColor3f(0, 0, 0);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(-5, 5);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(-5, 15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(5, 15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(5, 5);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void janela4(){
    glColor3f(0, 0, 0);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(15, 5);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(15, 15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(25, 15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(25, 5);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void janela5(){
    glColor3f(0, 0, 0);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(-5, -15);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(-5, -5);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(5, -5);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(5, -15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void janela6(){
    glColor3f(0, 0, 0);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(15, -15);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(15, -5);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(25, -5);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(25, -15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void porta(){
    glColor3f(0, 0, 0);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(5, -40);    //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(5, -25);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(15, -25);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(15, -40);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);  //buffer padrão (limpa a tela toda vez que a função é chamada)
glMatrixMode(GL_PROJECTION);   //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();              //carrega a projeção
    gluOrtho2D(-60,60,-60,60);     // define o tamanho do plano cartesiano
glMatrixMode(GL_MODELVIEW);    // projeção do tipo modelo
    glLoadIdentity();              // carrega a identidade de projeção de modelo


    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        rua();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        arvore();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
    glTranslated(-27.50, -44, 0);
        circuloArvore();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
    glTranslated(-27.50, -44, 0);
        maca1();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
    glTranslated(-37, -42, 0);
        maca2();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
    glTranslated(-17, -42, 0);
        maca3();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
    glTranslated(-20, -50, 0);
        maca4();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente


    glPushMatrix();      //insere a matriz de transformação corrente na pilha
    glTranslated(-35, -50, 0);
        maca4();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        predio();       //chama a função que desenha o sol
        janela1();
        janela2();
        janela3();
        janela4();
        janela5();
        janela6();
        porta();
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
    glTranslated(60, 10, 0);
        lua();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente



glFlush();          //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)

}
int main(int argc, char *argv[]){
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                                                      //somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                                                      //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
    glutCreateWindow("Introdução ao OpenGL");                                                         //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                                                                  //função de callback - chama a função desenhaObjetos
    glClearColor(0.1,0.1,0.44,0);                                                                            //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                                                   //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                                                                         //retorna zero
}
