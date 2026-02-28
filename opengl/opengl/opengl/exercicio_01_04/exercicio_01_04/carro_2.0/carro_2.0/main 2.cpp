#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>


GLint y = 0;
GLint x = 40;
GLint direcao = 1;

void rua(){
    glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
    
        glVertex2f(30.0,  30.0);
        glVertex2f(30.0, -45.0);
        glVertex2f(45, -45);
        glVertex2f(45, 45);
        glVertex2f(-35.0, 30.0);
        glVertex2f(-35.0, 45);
        glVertex2f(45, 45);
        
   

    glEnd();


}

void meiofio(){
    glBegin(GL_LINES);
        glColor3f(1 ,0.86 ,0.35);
        glVertex2f(30,-45);
        glVertex2f(30,30);
        glVertex2f(30,30);
        glVertex2f(-35,30);
        glVertex2f(45,-45);
        glVertex2f(45,45);
        glVertex2f(45,45);
        glVertex2f(-35,45);
        glVertex2f(-35,45);
        glVertex2f(-35,30);
        glVertex2f(30,-45);
        glVertex2f(45,-45);
    glEnd();
}


void pontoY(){
    glPointSize(20);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(1, 0,0);              //adiciona cor
        glVertex2f(x,y);       //desenha um ponto na coordenada x, y, onde y vai ser a variável que criamos para deslocar o ponto neste eixo
    glEnd();
}



void timerPonto(int passo){                //função timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
     if (direcao ==1){
        y+=1;
        if(y == 40){
            direcao = 2;
        }
    }

    else if (direcao == 2){
        x-=1;                     //decrementa nosso moveponto até o limite estipulado
        if(x == -30){             //se move ponto for igual ao nosso limite inferior máximo no eixo y-
            direcao = 3;                  //começa a subir no eixo y, quando chegar no limite de -90y
        }
    }
   else if(direcao == 3){
        y-=1;
        if(y == 35){
            direcao = 4;
        }
    }

    else if (direcao == 4){
        x+=1;
        if(x == 35){
            direcao = 5;
        }
    }
    else if (direcao == 5){
        y -=1;
        if (y == -40)
            direcao = 6;
    }
    else if (direcao == 6){
        x +=1;
        if(x == 40){
            direcao =1;
        }
    }



    glutPostRedisplay();                 //chama a função desenha toda vez que for necessária
    glutTimerFunc(30,timerPonto,1);      //precisamos chamar a função timer toda vez, Ele executa essa função timer e entra aqui novamente. Até eu querer sair da função timer (neste caso, não queremos sair)
}






void pontilhado(){
    glColor3f(1, 0.86, 0.35);
    glLineWidth(4);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glBegin(GL_LINES);
    glVertex2f(37.5, -37.5);
    glVertex2f(37.5, 37.5);
    glVertex2f(37.5, 37.5);
    glVertex2f(-27.5, 37.5);

    glEnd();
    glDisable(GL_LINE_STIPPLE);


}


void desenhaObjetos(void){                 //função de desenho
    glClear(GL_COLOR_BUFFER_BIT);         //buffer padrão; limpa a tela toda vez que a função é chamada
    glMatrixMode(GL_PROJECTION);          //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();      //carrega a projeção
    gluOrtho2D(-50,50,-50,50);            //define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);           //projeção do tipo modelo
    glLoadIdentity();                     //carrega essa identidade de projeção de modelo

                             //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();
        rua();
    glPopMatrix();
    
    glPushMatrix();
        meiofio();
    glPopMatrix();
    
    glPushMatrix();
        pontilhado();
    glPopMatrix();
    
    glPushMatrix();
        pontoY();
    glPopMatrix();
    
    
    glutSwapBuffers();


glFlush();                                //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                    //double buffer, pois single ficaria piscando, uma vez que ele tem que desenhar e redesenhar | sistema de cores RGB
    glutInitWindowSize(800,600);                                    //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);    //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
glutCreateWindow("Exemplo Timer");                              //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                                //função de callback - chama a função desenhaObjetos
    glutTimerFunc(30,timerPonto,1);                                // três valores disponíveis (tempo (milissegundos) a o nome da função e valor padrão para retorno)
    glClearColor(0.75, 0.75 ,0.75,0);                                          //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                 //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                                       //retorna zero
}
