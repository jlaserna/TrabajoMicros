#include "MundoJuego.h"
#include "glut.h"

Mundo mundo;


//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
//void OnSpecialKeyboardDown(int key, int x, int y);
void onKeyboardUp(unsigned char key, int x, int y);

unsigned char key;
bool keystates[256];

float w = 800;        //Dimensiones inciales de la ventana
float h = 600;

float disRender = 2000;       //Distancia de renderizado

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(w,h);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, w/h, 0.1, disRender);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(onKeyboardUp);
	glutIgnoreKeyRepeat(1);
	//glutSpecialFunc(OnSpecialKeyboardDown); //gestion de los cursores

	mundo.Inicializa();
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	mundo.Dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
/*void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el c�digo de teclado
	mundo.Tecla(key);

	glutPostRedisplay();
}*/

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el c�digo de teclado
	//mundo.tecla(key);
	keystates[key] = true;
	glutPostRedisplay();
}

void onKeyboardUp(unsigned char key, int x, int y)
{
	keystates[key] = false;
	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el c�digo de animacion
	mundo.Mueve();
	mundo.tecla(keystates);
	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

void reshape(int w, int h)		//Funcion que cambia los parametros de perspectiva para 
{								// que al redimensionar la ventana el mundo se dibuje correctamente
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);

	//mundo.setSize(w, h);
}