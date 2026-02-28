#define GL_SILENCE_DEPRECATION
        
 //biblioteca que permite todas as chamadas da API openGL


#include <GLUT/glut.h>                 //bibliotecao que permite a manipulação de janelas

#include <math.h>                   //conjunto de funções para operações matemáticas



GLfloat escala=1;                  // variável para escala
GLfloat rotacao=0;                 // variável para rotação
GLfloat movex = 0, movey = 0;      // variáveis de movimentação para x e y



void quadrado(){

    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).

        glColor3f(0,1,0);          //adiciona cor ao quadrado
        glVertex2f(-2,-2);         //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(-2,2);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(2,2);           //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(2,-2);          //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado

    glEnd();

}

void rua(){
    glLineWidth(1);               //adiciona espessura a linha desenhada
    glColor3f(0,0,0);             //adiciona cor às linhas
    glBegin(GL_LINES);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f( 10.0,-50.0);   //desenha uma linha no eixo -50x até o ponto do eixo 50x
        glVertex2f( 10.0, 10.0);
        glVertex2f( 10.0, 10.0);
        glVertex2f(-50.0,10.0);
        glVertex2f(30.0, -50.0);
        glVertex2f(30.0,30.0);
        glVertex2f(30.0, 30.0);
        glVertex2f(-50.0, 30.0);


    glEnd();

}

void pontilhados (){
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1, 0.55, 0);

        glVertex2f(20.0, -40.0);
        glVertex2f(20.0, -30.0);
        glVertex2f(20.0, -20.0);
        glVertex2f(20.0, -10.0);
        glVertex2f(20.0, 0.0);
        glVertex2f(20.0, 10.0);
        glVertex2f(20.0, 20.0);

        glVertex2f(10.0, 20.0);
        glVertex2f(-10.0, 10.0);
        glVertex2f(-10.0, 20.0);
        glVertex2f(-20.0, 20.0);
        glVertex2f(-30.0, 20.0);

    glEnd();
}



void desenhaObjeto(void){                 //função de desenho

    glClear(GL_COLOR_BUFFER_BIT);         //buffer padrão; limpa a tela toda vez que a função é chamada
    glMatrixMode(GL_PROJECTION);          //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();                       //carrega a projeção
    gluOrtho2D(-50,50,-50,50);            //define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);           //projeção do tipo modelo
    glLoadIdentity();                     //carrega essa identidade de projeção de modelo

    glPushMatrix();
        rua();
    glPopMatrix();

    glPushMatrix();
        pontilhados();
    glPopMatrix();


    glPushMatrix();
        glTranslatef(movex, movey,0);
        glRotatef(rotacao,0 , 0, 1);
        glScalef(escala, escala, 0);         //insere a matriz de transformação corrente na pilha
        quadrado();                           // chama a função que desenha um quadrado

    glPopMatrix();                            //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente
    glFlush();                                //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)

}



/*função que atriui valores as nossas variáveis de escala e rotação (dependendo da tecla pressionada) */

void teclas(unsigned char tecla, GLint x, GLint y){
    switch (tecla){
        case '+': escala++;
        break;
        case '-': escala--;
        break;
        case '1': rotacao-=10;
        break;
        case '2': rotacao+=10;
        break;

    }
    glutPostRedisplay();            //redesenha a cena que está na janela

}



/*função que atriui valores as nossas variáveis de movimentação x e y (dependendo da tecla pressionada) */

void setasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){

        case GLUT_KEY_LEFT: movex--;
        break;

        case GLUT_KEY_RIGHT: movex++;
        break;

        case GLUT_KEY_DOWN: movey--;
        break;

        case GLUT_KEY_UP: movey++;
        break;
    }
    glutPostRedisplay();

}



int main(int argc, char *argv[]){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                        // somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                        // define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,         // medidas usadas para posicionar a janela no meio

                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);        // da tela - isso depende da resolução do monitor

    glutCreateWindow("Exemplo - Teclado");                              // permite a criação de uma janela
    glutDisplayFunc(desenhaObjeto);                                     // função de callback - chama a função Desenha
    glutKeyboardFunc(teclas);
    glutSpecialFunc(setasDirecionais);
    //teclas                                         // Chamada da função teclado (cada pressionamento gera uma chamada do teclado)

    //teclas especiais                                 // Chamada da função teclado especial (para quando as teclas direcionais são pressionadas)

    glClearColor(1,1,1,0);                                              // informa a cor de fundo da tela

    glutMainLoop();                                                     // loop infinito - escuta as informações do sistema até encerrar a aplicação

    return 0;                                                           // retorna zero

}

