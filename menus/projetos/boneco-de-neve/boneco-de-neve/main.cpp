#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

GLfloat aspecto, angulo, rotacao;               // aspecto: variável para controlar windowsize; angulo: para projeção/perspectiva; rotação: para o objeto.

void desenhaObjetos(void){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);              //buffer padrão (limpa a tela toda vez que a função é chamada)



     glPushMatrix();                            //insere a matriz de transformação corrente na pilha
        glColor3f(0.88, 1, 1);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 1, 1, 1);            //realiza a rotação em todos os eixos
        glutSolidSphere(30,20,20);              //cria uma forma 3d sólida
        glColor3f(0,1,0);                       //adiciona cor a nossa forma

     glPopMatrix();                             //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente


   glPushMatrix();
   glTranslatef(25,25,50);
                       //insere a matriz de transformação corrente na pilha
        glColor3f(1, 1, 0);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 1, 1, 1);            //realiza a rotação em todos os eixos
        glutSolidSphere(3,2,2);              //cria uma forma 3d sólida
        glColor3f(0,1,0);                       //adiciona cor a nossa forma
      //  glutWireSphere(30,20,20);               //cria uma forma 3d de arame
      glPopMatrix();
       glPushMatrix();
   glTranslatef(25,25,25);
                       //insere a matriz de transformação corrente na pilha
        glColor3f(0.88, 1, 1);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 1, 1, 1);            //realiza a rotação em todos os eixos
        glutSolidSphere(20,10,10);              //cria uma forma 3d sólida
        glColor3f(0,1,0);                       //adiciona cor a nossa forma
      //  glutWireSphere(30,20,20);               //cria uma forma 3d de arame
      glPopMatrix();

       glPushMatrix();
   glTranslatef(-35,-35,-35);
                       //insere a matriz de transformação corrente na pilha
        glColor3f(0.88, 1, 1);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 1, 1, 1);            //realiza a rotação em todos os eixos
        glutSolidSphere(40,30,30);              //cria uma forma 3d sólida
        glColor3f(0,1,0);                       //adiciona cor a nossa forma
      //  glutWireSphere(30,20,20);               //cria uma forma 3d de arame
      glPopMatrix();



     glPushMatrix();
      glTranslatef(0,25,20);
        glTranslated(20,0,2) ;                             //insere a matriz de transformação corrente na pilha
        glColor3f(1,0,0);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 1, 1, 1);
                //realiza a rotação em todos os eixos
        glutSolidCone(10,40,20,5);

glPopMatrix();


     glutSwapBuffers();                                               //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers)
}

void Inicializa (void){
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};            // "cor"
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};   // "brilho"
    GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

    //Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;

    glClearColor(0,0,0,1);                                    //especifica que a cor de fundo da janela será preta
    glShadeModel(GL_SMOOTH);                                  //habilita o modelo de colorização de Gouraud
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);       //define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);         //define a concentração do brilho
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);      //ativa o uso da luz ambiente

    //Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    glEnable(GL_COLOR_MATERIAL);    //habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_LIGHTING);          //habilita o uso de iluminação
    glEnable(GL_LIGHT0);            //habilita a luz de número 0
    glEnable(GL_DEPTH_TEST);        //habilita o depth-buffering

    angulo = 60;                    //inicializa nossa variável angulo
}

void projetaPlano(void){
    glMatrixMode(GL_PROJECTION);                    //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();                               //carrega a projeção
    gluPerspective(angulo, aspecto, 0.4, 500);      //função que estabelece os parâmetros da Projeção Perspectiva, atualizando a matriz de projeção perspectiva.
    glMatrixMode(GL_MODELVIEW);                     //projeção do tipo modelo
    glLoadIdentity();                               //carrega a identidade de projeção de modelo
    gluLookAt(0,-40,180, 1,1,1, 1,1,1);              //Especifica posição do observador e do alvo
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){      //faz o controle do tamanho das viewports (padrão de parâmetros, altura e largura) (800x600 no glutInitWindowSize)
    if ( h == 0 ) h = 1;                             //caso altura seja = 0, setamos ela pra 1, pra corrigir eventuais erros
    glViewport(0, 0, w, h);                          //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
    aspecto = (GLfloat)w/(GLfloat)h;                 //largura dividida pela altura (utilizada para controlar a largura da janela automaticamente, independente de eu alterar a windowsize) (faz com que as janelas tenham a mesma proporção em cada viewport)
    projetaPlano();                                  //chama a função projetaPlano
}

/*função que atriui valores as nossas variáveis de movimentação x e y (dependendo da tecla pressionada) */
void teclasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){                                         //escolhe a tecla pressionada
            case GLUT_KEY_RIGHT: rotacao+=3;               //rotaciona nosso objeto sentido horário
            break;
            case GLUT_KEY_LEFT: rotacao-=3;                //rotaciona nosso objeto sentido anti-horário
            break;
    }
    projetaPlano();                                        //chama a função projetaPlano
    glutPostRedisplay();                                   //redesenha a cena que está na janela
}


int main(int argc, char *argv[]){
glutInit(&argc,argv);
{
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);       //somente um double buffer | sistema de cores RGB
     glutInitWindowSize(800,600);                       //define o tamanho da janela
     glutInitWindowPosition(300,120);                   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
     glutCreateWindow("Exemplo Iluminação");            //permite a criação de uma janela
     glutDisplayFunc(desenhaObjetos);                   //função de callback - chama a função desenhaObjetos
     glutSpecialFunc(teclasDirecionais);                //chama a função que escuta nossas teclas direcionais
     glutReshapeFunc(AlteraTamanhoJanela);              //função que altera o tamanho da janela, redesenha o tamanho da janela
     Inicializa();                                      //função que inicializa nossas variáveis
     glutMainLoop();                                    //loop infinito - escuta as informações do sistema até encerrar a aplicação
     return 0;                                          //retorna zero
    }
}
