#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

GLfloat aspecto, angulo, rotacao;
// aspecto: variável para controlar windowsize; angulo: para projeção/perspectiva; rotação: para o objeto.

//Material do objeto (material branco) (parâmetros)
GLfloat object_ambient[]   = {0, 0.0, 0.0, 1.0};
GLfloat object_difusa[]    = {0.0, 1.0, 0.0, 1.0};
GLfloat object_especular[] = {1.0, 1, 1, 1.0};
GLfloat object_emissao[]   = {0.0, 0.0, 0.0, 0.0};
GLfloat object_brilho[]    = {10};

//Informações sobre a luz (parâmetros)
GLfloat cor_luz_ativa[]    = {1.0, 1.0, 0.0, 1.0};
GLfloat cor_luz0[]         = {1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz_amb[]      = {0, 0, 0, 1.0};
GLfloat posicao_luz0[]     = {30, 80, 40.0,1.0};

GLfloat width, height;   //largura e altura

void desenhaObjetos(void){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);              //buffer padrão (limpa a tela toda vez que a função é chamada)
  

  
    glPushMatrix();                                                          //insere a matriz de transformação corrente na pilha
       // glTranslatef(posicao_luz0[0],posicao_luz0[1],posicao_luz0[2]);       //tranlada nosso ponto de luz
        glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz0);                     //Define os parâmetros da luz de número 0
        glMaterialfv(GL_FRONT, GL_EMISSION, cor_luz_ativa);                  //define a concentração do brilho
        glutSolidSphere(10,100,100);                                        //cria uma forma 3d sólida
    glPopMatrix();
    
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_AMBIENT, object_ambient);                     //especifica os parâmetros materiais para o modelo de iluminação
    glMaterialfv(GL_FRONT, GL_DIFFUSE, object_difusa);                      //especifica os parâmetros materiais para o modelo de iluminação
    glMaterialfv(GL_FRONT, GL_SPECULAR, object_especular);                  //especifica os parâmetros materiais para o modelo de iluminação
    glMaterialfv(GL_FRONT, GL_EMISSION, object_emissao);                    //especifica os parâmetros materiais para o modelo de iluminação
    glMaterialfv(GL_FRONT, GL_SHININESS, object_brilho);                    //especifica os parâmetros materiais para o modelo de iluminação

    
    //BOLA DE BAIXO
    glPushMatrix();
        glTranslatef(0,-40,0);
        glColor3f(1, 1, 1);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 0, 1, 0);            //realiza a rotação em todos os eixos
        glutSolidSphere(40,60,30);              //cria uma forma 3d sólida
        glColor3f(0,1,0);
    glPopMatrix();
    
    
    //BOLA MEIO
     glPushMatrix();
        glColor3f(1, 1, 1);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 0, 1, 0);            //realiza a rotação em todos os eixos
        glutSolidSphere(30,60,30);              //cria uma forma 3d sólida
        glColor3f(0,1,0);                       //adiciona cor a nossa forma
     glPopMatrix();                             //retira a matriz do topo da pilha e torna
    
    
   //nariz
    glPushMatrix();
         glTranslatef(0,43,2);//insere a matriz de transformação corrente na pilha
         glColor3f(1, 0.27, 0);                       //adiciona cor a nossa forma
         glRotatef(rotacao, 0, 1, 0);
        glutSolidCone(5,40,10,10);
     glPopMatrix();
    
    
    //BOLA EM CIMA
    glPushMatrix();
        glTranslatef(0,42,0);
        glColor3f(1, 1, 1);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 0, 1, 0);            //realiza a rotação em todos os eixos
        glutSolidSphere(20,60,30);
    glPopMatrix();
   
    //olho esquerdo
    glPushMatrix();
        glColor3f(0, 0, 0);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 0, 1, 0);
        glTranslatef(-7,47,19);//realiza a rotação em todos os eixos
        glutSolidSphere(2,60,30);               //cria uma forma 3d de arame
    glPopMatrix();
    
    //olho direito
    glPushMatrix();
        glColor3f(0, 0, 0);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 0, 1, 0);            //realiza a rotação em todos os eixos
        glTranslatef(7,47,19);
        glutSolidSphere(2,60,30);                //cria uma forma 3d de arame
    glPopMatrix();
    
    //BOTÃO
    glPushMatrix();
        glColor3f(0, 0, 0);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 0, 1, 0);            //realiza a rotação em todos os eixos
        glTranslatef(0,0,30);
        glutSolidSphere(2,60,30);               //cria uma forma 3d de arame
    glPopMatrix();
    
    //BOTÃO
    glPushMatrix();
        glColor3f(0, 0, 0);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 0, 1, 0);            //realiza a rotação em todos os eixos
        glTranslatef(0,9,29);
        glutSolidSphere(2,60,30);              //cria uma forma 3d sólida
    glPopMatrix();
    
    //BOTÃO
    glPushMatrix();
        glColor3f(0, 0, 0);                       //adiciona cor a nossa forma
        glRotatef(rotacao, 0, 1, 0);            //realiza a rotação em todos os eixos
        glTranslatef(0,18,24.5);
        glutSolidSphere(2,60,30);
    glPopMatrix();
   
    //CACHECOL
    glPushMatrix();                                   //adiciona cor a nossa forma
        glRotatef(180,0,1,1);
        glRotatef(rotacao, 0, 0, 1);
        glTranslatef(0,0,24);
        glColor3f(1,0,0);
        glutSolidTorus(6,20,20,20);
        glColor3f(1,1,0);
        glutWireTorus(6,20,20,40);//cria uma forma 3d sólida
    glPopMatrix();
   
    //BASE DO GLOBO
    glPushMatrix();                                   //adiciona cor a nossa forma
        glRotatef(180,0,1,1);
        glRotatef(rotacao, 0, 0, 1);
        glTranslatef(0,0,-70);
        glColor3f(0.24, 0.17, 0.12);
        glutSolidTorus(10,40,40,80);
    glPopMatrix();
    
    //GLOBO DE NEVE
    glPushMatrix();
        glColor4f(0, 0, 1, 0.5);                         //adiciona cor a nossa forma
        glRotatef(rotacao, 0, 1, 0);            //realiza a rotação em todos os eixos
        glutSolidSphere(88,60,30);
    glPopMatrix();
   
 
    
     glutSwapBuffers();                                               //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers)
}


void Inicializa (void){
    glClearColor (0,0,0,1);         //especifica que a cor de fundo da janela será preta
    glEnable(GL_DEPTH_TEST);        //habilita o depth-buffering
    glEnable(GL_LIGHTING);          //habilita o uso de iluminaçã
    glEnable(GL_LIGHT0);
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,2.0};
    GLfloat luzDifusa[4]={1,1,1,1.0};            // "cor"
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};   // "brilho"
    GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

    //Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;

    glClearColor(0,0,1,1);                                    //especifica que a cor de fundo da janela será preta
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
    glEnable(GL_BLEND);                                    //ativa as funções de BLEND
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   //o primeiro argumernto define o peso da cor do novo ponto e o segundo o peso da cor do ponto que já está na tela. Este pesos, em OpenGL, srão sempre uma função do nível de transparência do objeto, ou seja, de seu alfa.
    angulo = 60;                    //inicializa nossa variável angulo
}

void projetaPlano(void){
    glMatrixMode(GL_PROJECTION);                    //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();                               //carrega a projeção
    gluPerspective(angulo, aspecto, 0.4, 500);      //função que estabelece os parâmetros da Projeção Perspectiva, atualizando a matriz de projeção perspectiva.
    glMatrixMode(GL_MODELVIEW);                     //projeção do tipo modelo
    glLoadIdentity();                               //carrega a identidade de projeção de modelo
    gluLookAt(0,80,200, 0,0,0, 0,1,0);              //Especifica posição do observador e do alvo
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){      //faz o controle do tamanho das viewports (padrão de parâmetros, altura e largura) (800x600 no glutInitWindowSize)
    width = w;                                              //largura da janela
    height = h;
    if ( h == 0 ) h = 1;                             //caso altura seja = 0, setamos ela pra 1, pra corrigir eventuais erros
    glViewport(0, 0, w, h);                          //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
    aspecto = (GLfloat)w/(GLfloat)h;                 //largura dividida pela altura (utilizada para controlar a largura da janela automaticamente, independente de eu alterar a windowsize) (faz com que as janelas tenham a mesma proporção em cada viewport)
    projetaPlano();                                  //chama a função projetaPlano
}

/*função que atriui valores as nossas variáveis de movimentação x e y (dependendo da tecla pressionada) */
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

void teclasEspeciais(int tecla, int x, int y){
    switch (tecla){
        case GLUT_KEY_LEFT: posicao_luz0[0]-=0.6;               //move a luz pra esqueda -x
        break;
            
        case GLUT_KEY_RIGHT: posicao_luz0[0]+=0.6;              //move a luz pra direira +x
        break;
       case GLUT_KEY_UP: posicao_luz0[1]+=rotacao;                 //move a luz pra cima  +y
        break;
        case GLUT_KEY_DOWN:    posicao_luz0[1]-=rotacao;               //move a luz pra baixo -y
        break;
    
        case GLUT_KEY_PAGE_DOWN: posicao_luz0[2]-=0.2;          //move a luz pra trás -z
        break;
        case GLUT_KEY_PAGE_UP: posicao_luz0[2]+=0.2;            //move a luz pra frente +z
        break;
   }
   glutPostRedisplay();                                         //redesenha a cena que está na janela
}

int main(int argc, char *argv[]){
glutInit(&argc,argv);
{
     glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);       //somente um double buffer | sistema de cores RGB
    
       //somente um double buffer | sistema de cores RGB
     glutInitWindowSize(800,600);                       //define o tamanho da janela
     glutInitWindowPosition(300,120);                   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
     glutCreateWindow("BONECO NO GLOBO");
        Inicializa();//permite a criação de uma janela
     glutDisplayFunc(desenhaObjetos);                   //função de callback - chama a função desenhaObjetos
     glutSpecialFunc(teclasDirecionais);                //chama a função que escuta nossas teclas direcionais
     glutReshapeFunc(AlteraTamanhoJanela);//função que altera o tamanho da janela, redesenha o tamanho da janela
        Inicializa();                                      //função que inicializa nossas variáveis
     glutMainLoop();                                    //loop infinito - escuta as informações do sistema até encerrar a aplicação
     return 0;                                          //retorna zero
    }
}

