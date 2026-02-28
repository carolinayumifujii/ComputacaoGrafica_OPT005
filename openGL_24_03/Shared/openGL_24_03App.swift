#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>                 //biblioteca que permite a manipulação de janelas
#include <Math.h>                   //conjunto de funções para operações matemáticas

//Função que adiciona linhas para montar um plano cartesiano
void cartesiano(){
    glLineWidth(1);               //adiciona espessura a linha desenhada
    glColor3f(0,0,0);             //adiciona cor às linhas
    glBegin(GL_LINES);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-20.0, 0.0);   //desenha uma linha no eixo -50x até o ponto do eixo 50x
        glVertex2f(50, 0.0);
        glVertex2f(0.0, -50.0);   //desenha uma linha no eixo -50y até o ponto do eixo 50y
        glVertex2f(0, 50);
    glEnd();
}


void estrela1(){
    glColor3f(0, 0, 1);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);       //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(2, 5);
        glVertex2f(4, 6);
        glVertex2f(8, 5);
     glEnd();
}
void estrela2(){
    glColor3f(0, 0, 1);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(5, 5);
        glVertex2f(6, 6);
        glVertex2f(4, 6);
     glEnd();
}

void estrela3(){
    glColor3f(0, 0, 1);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(6, 6);
        glVertex2f(8, 5);
        glVertex2f(6, 4);
     glEnd();
}

void estrela4(){
    glColor3f(0, 0, 1);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(6, 4);
        glVertex2f(5, 2);//adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(4, 4);
    glEnd();
}

void estrela5(){
    glColor3f(0, 0, 1);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(4,6);
        glVertex2f(6,6);
        glVertex2f(6,4);
        glVertex2f(4,4);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
             //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
            //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono



           //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono

    glEnd();
}

void diamante(){
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex2f(-10,5);
        glVertex2f(-9, 7);
        glVertex2f((-7.5),7);
        glVertex2f(-6,7);
        glVertex2f(-5,5);
        glVertex2f(-7,2);

    glEnd();

}

void nuvem(){
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(3,-9);
        glVertex2f(2,-8);
        glVertex2f(3,-7);
        glVertex2f(4,-5);
        glVertex2f(5,-6);
        glVertex2f(6,-5);
        glVertex2f(7,-6);
        glVertex2f(8,-5);
        glVertex2f(9,-6);
        glVertex2f(10,-5);
        glVertex2f(13,-8);
        glVertex2f(12,-9);

    glEnd();
}

void tempo1(){
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(-9,-3);
        glVertex2f(-5,-3);
        glVertex2f(-7,-7);

    glEnd();

}

void tempo2(){
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(-10,-11);
        glVertex2f(-5,-11);
        glVertex2f(-7,-7);

    glEnd();
}


void circulo(){
    glColor3f(1, 0.84, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+5*cos(theta), 40+5*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}



//Função de desenho
void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);  //buffer padrão (limpa a tela toda vez que a função é chamada)
    glMatrixMode(GL_PROJECTION);   //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();              //carrega a projeção
    gluOrtho2D(-60,60,-60,60);     // define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);    // projeção do tipo modelo
    glLoadIdentity();              // carrega a identidade de projeção de modelo

    glPushMatrix();       //insere a matriz de transformação corrente na pilha
        cartesiano();     //chama a função que desenha o plano cartesiano
    glPopMatrix();        //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente


    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        glTranslatef(20,2,0);  // translada nosso polígono
        circulo();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        estrela1();      //chama a função que desenha um poligono
    glPopMatrix();


    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        estrela2();      //chama a função que desenha um poligono
    glPopMatrix();

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        estrela3();      //chama a função que desenha um poligono
    glPopMatrix();

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        estrela4();      //chama a função que desenha um poligono
    glPopMatrix();

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        estrela5();      //chama a função que desenha um poligono
    glPopMatrix();



    glPushMatrix();
        diamante();
    glPopMatrix();

    glPushMatrix();
        tempo1();
    glPopMatrix();

    glPushMatrix();
        tempo2();
    glPopMatrix();

    glPushMatrix();
        nuvem();
    glPopMatrix();



    glFlush();          //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)

}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                                                      //somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                                                      //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
    glutCreateWindow("Introdução ao OpenGL");                                                         //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                                                                  //função de callback - chama a função desenhaObjetos
    glClearColor(1,1,1,0);                                                                            //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                                                   //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                                                                         //retorna zero
}
