#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
#include <math.h>

//Função que adiciona linhas para montar um plano cartesiano
void cartesiano(){
    glLineWidth(1);               //adiciona espessura a linha desenhada
    glColor3f(0,0,0);             //adiciona cor às linhas
    glBegin(GL_LINES);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-50.0, 0.0);   //desenha uma linha no eixo -50x até o ponto do eixo 50x
        glVertex2f(50, 0.0);
        glVertex2f(0.0, -50.0);   //desenha uma linha no eixo -50y até o ponto do eixo 50y
        glVertex2f(0, 50);
    glEnd();
}


void estrela1(){
    glColor3f(1, 0.55 ,0);
    glBegin(GL_POLYGON);
        glVertex2f(4, 8);
        glVertex2f(8, 10);
        glVertex2f(8, 6);
     glEnd();
}
void estrela2(){
    glColor3f(1, 0.55 ,0);
    glBegin(GL_POLYGON);
        glVertex2f(8, 6);
        glVertex2f(10,2);
        glVertex2f(12, 6);
     glEnd();
}

void estrela3(){
    glColor3f(1, 0.55 ,0);
    glBegin(GL_POLYGON);
        glVertex2f(12, 6);
        glVertex2f(16, 8);
        glVertex2f(12, 10);
     glEnd();
}

void estrela4(){
    glColor3f(1, 0.55 ,0);
    glBegin(GL_POLYGON);
        glVertex2f(12, 10);
        glVertex2f(10,14);
        glVertex2f(8, 10);
    glEnd();
}

void estrela5(){
    glColor3f(1, 0.55 ,0);        //adiciona cor ao poligono
    glBegin(GL_POLYGON);
        glVertex2f(8,10);
        glVertex2f(12,10);
        glVertex2f(12,6);
        glVertex2f(8,6);

    glEnd();
}

void diamante(){
    glColor3f(0, 0, 1);
    glScalef(0.5,0.5,0); // usei a escala para diminuir o diamante pela metade
    glBegin(GL_POLYGON);
        glVertex2f(-20,15);
        glColor3f(0.27, 0.51 ,0.71);
        glVertex2f(-12,6);
        glVertex2f(-5, 15);
        
        glVertex2f(-8,18);
        glVertex2f(-16,18);

    glEnd();

}

void nuvem(){
    glColor3f(0.41,0.41,0.41);
    
    glBegin(GL_POLYGON);
    
        glVertex2f(9,-17);
        glVertex2f(5,-15);
    glColor3f(0.44,0.5,0.56);
        glVertex2f(10,-10);
        glVertex2f(14,-12);
        glVertex2f(20,-8);
    glColor3f(0.44,0.5,0.56);
        glVertex2f(28,-15);
        glVertex2f(28, -10);
        glVertex2f(33,-15);
    glColor3f(0.44,0.5,0.56);
        glVertex2f(30,-17);
        

    glEnd();
}

void tempo1(){
    glColor3f(0 ,0.39 ,0);
    glBegin(GL_POLYGON);
        glVertex2f(-15,-12);
        glVertex2f(-20,-20);
        glVertex2f(-10,-20);

    glEnd();

}

void tempo2(){
    glColor3f(0 ,0.39 ,0);
    glBegin(GL_POLYGON);
        glVertex2f(-20,-5);
        glVertex2f(-10,-5);
        glVertex2f(-15,-13);

    glEnd();
}





void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);  //buffer padrão (limpa a tela toda vez que a função é chamada)
    glMatrixMode(GL_PROJECTION);   //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();              //carrega a projeção
    gluOrtho2D(-60,60,-60,60);     // define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);    // projeção do tipo modelo
    glLoadIdentity();              // carrega a identidade de projeção de modelo

    glPushMatrix();
        cartesiano();
    glPopMatrix();


    glPushMatrix();
              
    glPushMatrix();
        estrela1();
    glPopMatrix();


    glPushMatrix();
        estrela2();
    glPopMatrix();

    glPushMatrix();
        estrela3();
    glPopMatrix();

    glPushMatrix();
        estrela4();
    glPopMatrix();

    glPushMatrix();
        estrela5();
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
    glutInitWindowSize(600,600);                                                                      //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
    glutCreateWindow("Atividade - Introdução ao OpenGL");                                                         //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                                                                  //função de callback - chama a função desenhaObjetos
    glClearColor(1,1,1,0);                                                                            //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                                                   //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                                                                         //retorna zero
}

