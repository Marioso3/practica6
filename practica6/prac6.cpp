//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Sotres Cataño Mario   ***********//
//*************		Visual Studio 2015					******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna_tierra = 0;
int planeta = 0;

float camaraZ = 0.0;
float camaraX = 0.0;
float angleY = 0.0f;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara
	//glRotatef(angleY, 1.0, 0.0, 0.0);
	glPushMatrix();
		glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
		glutWireSphere(2, 20, 20);  //Draw Sun (radio,H,V);
	glPopMatrix();
	glPushMatrix();

	//Mercurio
	glPushMatrix();
		glColor3f(0.545, 0.271, 0.075);
		glRotatef(planeta * 3, 0.0, 1.0, 1.0);
		glTranslated(2.5,0.2,0.2);
		glRotatef(mercurio, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glutWireSphere(0.3, 10, 10);  //Draw Sun (radio,H,V);
	glPopMatrix();

	//Venus
	glPushMatrix();
		glColor3f(0.957, 0.643, 0.376);
		glRotatef(planeta * (-3), 0.0, 0.0, 1.0);
		glTranslated(3.5, 0.2, 0.2);
		glRotatef(venus, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glutWireSphere(0.4, 10, 10);  //Draw Sun (radio,H,V);
	glPopMatrix();

	//Tierra
	glPushMatrix();
		glColor3f(0.118, 0.565, 1.000);
		glRotatef(planeta * 5, 0.0, 1.0, 0.0);
		glTranslated(5.5, 0.2, 0.2);
		//(5.5,0.2,0.2)
		glPushMatrix();
			glRotatef(tierra, 0.0, 1.0,0.0);	//El Sol gira sobre su eje
			glutWireSphere(0.6, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();
		//Luna
		glColor3f(0.753, 0.753, 0.753);
		glRotatef(luna_tierra, 0.0, 1.0, 0.0);	//Traslación de la Luna 
		glTranslated(1.2, 0.2, 0.2);
		glRotatef(planeta*2, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glutWireSphere(0.2, 10, 10);  //Draw Sun (radio,H,V);
	glPopMatrix();

	//Marte
	glPushMatrix();
		glColor3f(0.698, 0.133, 0.133);
		glRotatef(planeta * -3, 0.0, 1.0, 0.5);
		glTranslated(8.0, 0.2, 0.2);
		glRotatef(planeta*3, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glutWireSphere(0.35, 10, 10);  //Draw Sun (radio,H,V);
	glPopMatrix();

	//Jupiter
	glPushMatrix();
		glColor3f(1.000, 0.855, 0.725);
		glRotatef(planeta * -4, 0.0, 0.5, 1.0);
		glTranslated(10.0, 0.2, 0.2);
		glPushMatrix();
			glRotatef(planeta*3, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glutWireSphere(0.7, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();
		glPushMatrix();
			//Luna 1
			glColor3f(0.753, 0.753, 0.753);
			glRotatef(planeta*3, 0.0, 1.0, 0.0);	//Traslación de la Luna 
			glTranslated(1.1, 0.2, 0.2);
			glRotatef(planeta * 2, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glutWireSphere(0.2, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();

		glPushMatrix();
			//Luna 2
			glColor3f(0.753, 0.753, 0.753);
			glRotatef(planeta * 3, 1.0, 0.0, 0.0);	//Traslación de la Luna 
			glTranslated(0.0, 1.0, 0.2);
			glRotatef(planeta * 2, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glutWireSphere(0.2, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();

	glPopMatrix();

	//Saturno
	glPushMatrix();
		glColor3f(1.000, 0.627, 0.478);
		glRotatef(planeta * 3, 0.0, 0.5, 0.5);
		glTranslated(14.0, 0.2, 0.2);
		glPushMatrix();
			glRotatef(planeta * 3, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glutWireSphere(0.6, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();

		glPushMatrix();
			//Luna 1
			glColor3f(0.753, 0.753, 0.753);
			glRotatef(planeta * 3, 0.0, 1.0, 0.0);	//Traslación de la Luna 
			glTranslated(1.9, 0.2, 0.2);
			glRotatef(planeta * (-2), 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glutWireSphere(0.2, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();

		glPushMatrix();
		//Luna 2
		glColor3f(0.753, 0.753, 0.753);
		glRotatef(planeta * 3, 1.0, 0.0, 0.0);	//Traslación de la Luna 
		glTranslated(0.0, 1.8, 0.2);
		glRotatef(planeta * (-2), 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glutWireSphere(0.2, 10, 10);  //Draw Sun (radio,H,V);
		glPopMatrix();

		glPushMatrix();
		//Anillo 1
			glRotatef(90, 0.0, 0.0, 1.0);
			glRotatef(planeta*(-1), 0.0, 1.0, 0.0);
			glColor3f(1.000, 0.980, 0.804);
			glutSolidTorus(0.1,0.9,10,10);
		glPopMatrix();

		glPushMatrix();
		//Anillo 2
			glRotatef(90, 0.0, 0.0, 1.0);
			glRotatef(planeta * (-1), 0.0, 1.0, 0.0);
			glColor3f(1.000, 0.498, 0.314);
			glutSolidTorus(0.1, 1.0, 10, 10);
		glPopMatrix();

	glPopMatrix();

	//Urano
	glPushMatrix();
		glColor3f(0.275, 0.510, 0.706);
		glRotatef(planeta * -3, 0.0, 1.0, 0.5);
		glTranslated(17.5, 0.2, 0.2);
		glRotatef(planeta * 3, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glutWireSphere(0.4, 10, 10);  //Draw Sun (radio,H,V);
	glPopMatrix();

	//Neptuno
	glPushMatrix();
		glColor3f(0.000, 0.000, 0.804);
		glRotatef(planeta * (4), 0.0, 0.0, 1.0);
		glTranslated(19.0, 0.2, 0.2);
		glRotatef(planeta * 3, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glutWireSphere(0.35, 10, 10);  //Draw Sun (radio,H,V);
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();

}

void animacion() //Esta función sirve que se mueva automático el Sol
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime() //GetTickCount() sirve para que funcione a la misma velocidad en 
									//cualquier máquina
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;

		mercurio = (mercurio - 8) % 360;

		dwLastUpdateTime = dwCurrentTime;

		venus = (venus + 4) % 360;

		dwLastUpdateTime = dwCurrentTime;

		tierra = (tierra - 7) % 360;

		dwLastUpdateTime = dwCurrentTime;

		luna_tierra = (luna_tierra + 8) % 360;

		dwLastUpdateTime = dwCurrentTime;

		planeta = (planeta + 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay(); //Vuelve a dibujar la figura
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleY += 2.0f;
		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleY -= 2.0f;
		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion); //Cuando no esté oprimiendo nada se va a llamar a la función animación
	glutMainLoop();          // 

	return 0;
}