#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>

GLint moveY = 90;
GLint moveX = -90;
GLint direcaoX = 1;
GLint direcaoY = -1;
GLint paradaX= 60;
GLint paradaY = 10;


void timerPonto(int valor){
    
    if(paradaY==0||paradaX==0){
        
        return;
        
    }
    if(valor == 1){
        if (direcaoX == 1){
            moveX++;
            if (moveX == paradaX) {
                direcaoX = -1;
            }
        }else if (direcaoX == -1){
             moveX--;
             if (moveX == paradaX *(-1)) {
                direcaoX = 1;
                 paradaX--;
            }
        }
        glutPostRedisplay();
        glutTimerFunc(25, timerPonto, 1);

    }else if (valor == 2){
        if (direcaoY == 1){
            moveY++;
            if (moveY == paradaY) {
                direcaoY = -1;
            }
        }else if (direcaoY == -1){
             moveY--;
             if (moveY == paradaY * (-1)) {
                direcaoY = 1;
                 paradaY--;
            }
        }
        glutPostRedisplay();
        glutTimerFunc(7, timerPonto, 2);
    }
}

void ponto(){
    glColor3f(0, 0, 0);
    glPointSize(50);
    glBegin(GL_POINTS);
    glVertex2f(moveX, moveY);
       
    glEnd();
}


void Desenha (void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        ponto();
    glPopMatrix();

    glutSwapBuffers();
}

void Teclas(unsigned char tecla, GLint x, GLint y){
    switch (tecla){
            
        case 'a':
            glutTimerFunc(100, timerPonto, 1);
            glutTimerFunc(100, timerPonto, 2);
            break;
    
           
    }
    Desenha();
}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
    glutCreateWindow("Aplicação em OpenGL");
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclas);
    glClearColor(0.75, 0.75 ,0.75,0);
    glutMainLoop();
    return 0;
}
