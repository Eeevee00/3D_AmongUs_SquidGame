#include <stdint.h>

typedef uint32_t DWORD;   // DWORD = unsigned 32 bit value

#if defined(__APPLE__)

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <mach/mach_time.h>
#include <math.h>

#define WINDOW_WIDTH  1920
#define WINDOW_HEIGHT 1080
#define PI 3.1415926535897932384626433832795
#define FPS    30

#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

//Scene1(Liyi)
bool visibleS1_1 = false;
bool visibleS1_2 = false;
//==========================

//Scene2(Joey)
float direction = 1;
float walkX_2 = 0;
float walkY_2 = 0;

float walkX_late_2 = 0;
float walkY_late_2 = 0;

float walkX_big_2 = 0;
float walkY_big_2 = 0;

float dy_big_2 = 10;

float dx_2 = 15;
float dy_2 = 0;

bool visibleS2_1 = FALSE;
bool visibleS2_2 = FALSE;
//==========================

//Scene3(Kek)
float walkXs3 = 0;
float walkYs3 = 0;
float dxS3 = 15;
float dyS3 = 15;
//==========================

//Scene 4(Ivan)
float walkXs4a = 0;
float walkYs4a = 0;
float walkXs4b = 0;
float walkYs4b = 0;
float walkXs4c = 0;
float walkYs4c = 0;

float dxS4a = 25;
float dyS4a = 0;
float dxS4b = 25;
float dyS4b = 0;
float dxS4c = 25;
float dyS4c = 0;
//==========================

//Scene5(Eve)
float walkX_S5 = 0;
float walkY_S5 = 0;

float dx_S5 = 30;
float dy_S5 = 0;

bool visibleS5_1 = false;
bool visibleS5_2 = false;
bool visibleS5_3 = false;
//==========================


//Scene6(SooHao)
float walkXs6 = 0;
float walkYs6 = 0;
float walkX3s6 = 0;

float walkX_lates6 = 0;
float walkY_lates6 = 0;
float dxs6 = 35;
float dx2s6 = 20;
float dys6 = 0;
GLfloat angle = 270.0f;
//==========================


//Global
void init() {
    /* set clear color to black */
    glClearColor(0.74902, 0.847059, 0.847059, 1.0);

    /* set up standard orthogonal view with clipping */
    /* box as cube of side 2 centered at origin */
    /* This is default view and these statement could be removed */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(60, (float)WINDOW_WIDTH/WINDOW_HEIGHT, 0.01f, 100.0f);
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

void drawCircle(int x, int y, int r, int n) {
    double inc = (2 * PI) / n;
    glBegin(GL_POLYGON);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        glVertex2d(r * cos(theta) + x, r * sin(theta) + y);
    }
    glEnd();
}

void
drawAmongUs(float x1, float y1, float x2, float y2, int lbr, int lbg, int lbb, int dbr, int dbg, int dbb, float ScaleX,
            float ScaleY) {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * (x1 + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * (x1 + x2), ScaleY * ((y1 - 90) + y2));

    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * (y1 + y2));

    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 100) + y2));

    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 130) + y2));

    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 140) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 - 140) + y2));

    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 140) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 140) + y2));

    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 130) + y2));

    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 130) + y2));

    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 110) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 110) + y2));

    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));

    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 30) + y2));

    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 30) + y2));

    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 20) + y2));

    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 10) + y2));

    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));

    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 20) + y2));

    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 30) + y2));

    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 160) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 160) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 10) + y2));

    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 40) + y2));

    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 40) + y2));

    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 50) + y2));

    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 50) + y2));

    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 70) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 70) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 60) + y2));
    glEnd();

    //light blue shade
    glBegin(GL_POLYGON);
    glColor3ub(lbr, lbg, lbb);
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 20) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 40) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 40) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 - 40) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 60) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 60) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 80) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 50) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 50) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 70) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 70) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 80) + y2));
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 20) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 20) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 30) + y2));
    glEnd();

    //dark blue shade
    glBegin(GL_POLYGON);
    glColor3ub(dbr, dbg, dbb);
    glVertex2f(ScaleX * ((x1 + 20) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 20) + x2), ScaleY * ((y1 - 30) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 - 130) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 - 40) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 40) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 - 130) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 60) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 60) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 130) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 100) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 100) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 70) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 70) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 130) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 50) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 50) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 70) + y2));
    glEnd();

    //light gray shade
    glBegin(GL_POLYGON);
    glColor3ub(152, 168, 171);
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * (y1 + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * (y1 + y2));
    glEnd();

    //dark gray shade
    glBegin(GL_POLYGON);
    glColor3ub(87, 102, 107);
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * (y1 + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 20) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    // inside eyes white shade
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 + 20) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 + 10) + y2));
    glEnd();
}


//Scene1(LiYi)

void drawHill_1(float position_x, float position_y, float Hill_ScaleX, float Hill_ScaleY) {
    ///Hill
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(Hill_ScaleX * (70) + position_x, Hill_ScaleY * (70) + position_y);
    glVertex2i(Hill_ScaleX * (200) + position_x, Hill_ScaleY * (225) + position_y);
    glVertex2i(Hill_ScaleX * (330) + position_x, Hill_ScaleY * (70) + position_y);

    glEnd();

    ///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.56, 0.3);
    glVertex2i(Hill_ScaleX * (200) + position_x, Hill_ScaleY * (225) + position_y);
    glVertex2i(Hill_ScaleX * (230) + position_x, Hill_ScaleY * (190) + position_y);
    glVertex2i(Hill_ScaleX * (220) + position_x, Hill_ScaleY * (180) + position_y);
    glVertex2i(Hill_ScaleX * (200) + position_x, Hill_ScaleY * (190) + position_y);
    glVertex2i(Hill_ScaleX * (190) + position_x, Hill_ScaleY * (180) + position_y);
    glVertex2i(Hill_ScaleX * (170) + position_x, Hill_ScaleY * (190) + position_y);

    glEnd();
}

void draw_1(int x, int x1, int y, int y1, float r, float g, float b) {
    glColor3ub(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + x1, y);
    glVertex2i(x + x1, y + y1);
    glVertex2i(x, y + y1);
    glEnd();
}

void drawLine_1(int x, int x1, int y, int y1, int r, int g, int b, int w) {
    glColor3ub(r, g, b);
    glLineWidth(w);
    glBegin(GL_LINES);
    glVertex2i(x, y);
    glVertex2i(x1, y1);
    glEnd();
}

void drawTextBubble_1(float position_x, float position_y, float ScaleX, float ScaleY) {
    //left wall
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 80 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 80 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 110 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glEnd();

    //bottom wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 110 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 110 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glEnd();

    //right wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 550 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 550 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 280 + position_y);
    glEnd();

    //top wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glEnd();

    //inner filling
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 100 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 130 + position_y);
    glEnd();

}

void display_1(void) {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);

    // draw board
    draw_1(180, 1540, 400, 590, 0, 0, 0);
    draw_1(200, 1500, 420, 550, 20, 70, 1);

    // draw duster
    draw_1(1600, 75, 430, 20, 0, 0, 0);
    draw_1(1610, 55, 420, 10, 255, 255, 255);

    // draw chalk
    draw_1(1530, 50, 420, 5, 255, 255, 255);

    if (visibleS1_1) {
        // draw bubble
        drawTextBubble_1(640, 250, 1.0, 0.9);

        // draw mountain
        drawHill_1(920, 360, 0.4, 0.55);

        // draw ?
        draw_1(1065, 62, 480, 20, 0, 0, 0);
        draw_1(1120, 22, 450, 50, 0, 0, 0);
        draw_1(1090, 52, 440, 20, 0, 0, 0);
        draw_1(1090, 20, 415, 25, 0, 0, 0);
        draw_1(1090, 20, 390, 15, 0, 0, 0);
    }

    if (visibleS1_2) {
        // draw amazing emoji 1
        drawLine_1(530, 540, 350, 345, 255, 165, 0, 4);
        drawLine_1(545, 545, 350, 360, 255, 165, 0, 4);
        drawLine_1(550, 560, 345, 350, 255, 165, 0, 4);
        drawLine_1(543, 533, 340, 335, 255, 165, 0, 4);
        drawLine_1(557, 547, 335, 340, 255, 165, 0, 4);

        //draw amazing emoji 2
        drawLine_1(660, 681, 350, 350, 255, 215, 0, 3);
        drawLine_1(670, 670, 340, 360, 255, 215, 0, 3);
        drawLine_1(661, 678, 340, 360, 255, 215, 0, 3);
        drawLine_1(661, 678, 360, 340, 255, 215, 0, 3);

        // draw amazing emoji 5
        drawLine_1(1230, 1240, 350, 345, 255, 165, 0, 4);
        drawLine_1(1245, 1245, 350, 360, 255, 165, 0, 4);
        drawLine_1(1250, 1260, 345, 350, 255, 165, 0, 4);
        drawLine_1(1243, 1233, 340, 335, 255, 165, 0, 4);
        drawLine_1(1257, 1247, 335, 340, 255, 165, 0, 4);
    }


    // draw among us
    drawAmongUs(480, 250, 0, 0, 61, 98, 219, 34, 61, 148, 1, 1);        //blue
    drawAmongUs(640, 250, 0, 0, 230, 180, 193, 226, 143, 173, 1, 1);    //pink
    drawAmongUs(800, 250, 0, 0, 112, 155, 107, 84, 113, 59, 1, 1);    //green
    drawAmongUs(960, 250, 0, 0, 242, 219, 39, 242, 188, 34, 1, 1);    //yellow
    drawAmongUs(1120, 250, 0, 0, 167, 27, 20, 91, 15, 8, 1, 1);        //red
    drawAmongUs(1280, 250, 0, 0, 190, 76, 20, 136, 57, 16, 1, 1);    //brown

    /* flush GL buffers */
    glFlush();

    glutSwapBuffers();
}

//Scene2(Joey)
void drawGrass_2(int x, int y) {
    glColor3ub(65, 142, 47);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x - 10, y + 15);
    glVertex2i(x + 10, y + 8);
    glVertex2i(x + 15, y + 25);
    glVertex2i(x + 20, y + 9);
    glVertex2i(x + 30, y + 11);
    glVertex2i(x + 25, y);
    glEnd();
}

void drawGrassGroup_2() {
    drawGrass_2(500, 300);
    drawGrass_2(20, 200);
    drawGrass_2(1000, 250);
    drawGrass_2(1800, 180);
    drawGrass_2(700, 160);
    drawGrass_2(1400, 320);
}

void drawSweatSmiley_2(float position_x, float position_y, float ScaleX, float ScaleY) {
    glColor3ub(114, 159, 191);

    //sweat outer
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 260 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 240 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 230 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 230 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 230 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 230 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 220 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 220 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 230 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 230 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 240 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 260 + position_y);
    glEnd();

    //sweat inner
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 260 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 240 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 230 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 230 + position_y);
    glEnd();


    //face
    glColor3ub(242, 193, 82);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 270 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 270 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 260 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 400 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 400 + position_x, ScaleY * 250 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 250 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 250 + position_y);
    glVertex2f(ScaleX * 410 + position_x, ScaleY * 250 + position_y);
    glVertex2f(ScaleX * 410 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 240 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 420 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 420 + position_x, ScaleY * 220 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 220 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 230 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 230 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 220 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 220 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 230 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 230 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 220 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 220 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 220 + position_y);
    glVertex2f(ScaleX * 430 + position_x, ScaleY * 220 + position_y);
    glVertex2f(ScaleX * 430 + position_x, ScaleY * 170 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 170 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 170 + position_y);
    glVertex2f(ScaleX * 420 + position_x, ScaleY * 170 + position_y);
    glVertex2f(ScaleX * 420 + position_x, ScaleY * 150 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 150 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 150 + position_y);
    glVertex2f(ScaleX * 410 + position_x, ScaleY * 150 + position_y);
    glVertex2f(ScaleX * 410 + position_x, ScaleY * 140 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 140 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 140 + position_y);
    glVertex2f(ScaleX * 400 + position_x, ScaleY * 140 + position_y);
    glVertex2f(ScaleX * 400 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 130 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 120 + position_y);
    glEnd();


    //eyes
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 210 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 210 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 200 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 200 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 210 + position_y);
    glVertex2f(ScaleX * 410 + position_x, ScaleY * 210 + position_y);
    glVertex2f(ScaleX * 410 + position_x, ScaleY * 200 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 200 + position_y);
    glEnd();

    //mouth
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 180 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 180 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 170 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 170 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 170 + position_y);
    glVertex2f(ScaleX * 390 + position_x, ScaleY * 170 + position_y);
    glVertex2f(ScaleX * 390 + position_x, ScaleY * 160 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 160 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 170 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 170 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 160 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 160 + position_y);
    glEnd();
}

void drawQuestionMark_2(float position_x, float position_y, float ScaleX, float ScaleY) {
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 300 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 320 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 320 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 310 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 300 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 270 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 270 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 270 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 270 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 260 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 350 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 250 + position_y);
    glVertex2f(ScaleX * 350 + position_x, ScaleY * 250 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 250 + position_y);
    glVertex2f(ScaleX * 350 + position_x, ScaleY * 250 + position_y);
    glVertex2f(ScaleX * 350 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 240 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 220 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 220 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 200 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 200 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 190 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 190 + position_y);
    glEnd();
}

void drawTextBubble_2(float position_x, float position_y, float ScaleX, float ScaleY) {
    //left wall
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 80 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 80 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 110 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glEnd();

    //bottom wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 110 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 110 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glEnd();

    //right wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 550 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 550 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 280 + position_y);
    glEnd();

    //top wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glEnd();

    //inner filling
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 100 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 130 + position_y);
    glEnd();


}

void drawAmongUsBig_2(float position_x, float position_y, float x2, float y2, float ScaleX, float ScaleY) {
    glColor3f(0.0, 0.0, 0.0);

    //black outline
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 200 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 200 + position_x + x2, ScaleY * 110 + position_y + y2);

    glVertex2f(ScaleX * 190 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 200 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 200 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 190 + position_x + x2, ScaleY * 050 + position_y + y2);

    glVertex2f(ScaleX * 200 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 200 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 020 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 020 + position_y + y2);

    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 010 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 010 + position_y + y2);

    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 020 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 010 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 010 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 020 + position_y + y2);

    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 020 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 020 + position_y + y2);

    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 020 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 020 + position_y + y2);

    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 430 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 430 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 430 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 440 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 440 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 430 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 430 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 430 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 110 + position_y + y2);

    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 190 + position_y + y2);

    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 210 + position_y + y2);

    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 230 + position_y + y2);

    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 260 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 260 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 240 + position_y + y2);

    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 270 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 270 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 250 + position_y + y2);

    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 270 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 270 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 260 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 260 + position_y + y2);

    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 280 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 280 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 270 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 270 + position_y + y2);

    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 270 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 270 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 260 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 260 + position_y + y2);

    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 260 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 260 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 250 + position_y + y2);

    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 240 + position_y + y2);

    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 230 + position_y + y2);

    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 210 + position_y + y2);

    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 190 + position_y + y2);

    //finger
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 020 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 020 + position_y + y2);

    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 80 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 80 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 050 + position_y + y2);

    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 060 + position_y + y2);

    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 050 + position_y + y2);

    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 060 + position_y + y2);

    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 90 + position_y + y2);

    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 110 + position_y + y2);

    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 130 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 130 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 120 + position_y + y2);

    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 100 + position_y + y2);

    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 90 + position_y + y2);

    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 110 + position_y + y2);

    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 300 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 300 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 100 + position_y + y2);

    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 180 + position_y + y2);

    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 120 + position_y + y2);

    glVertex2f(ScaleX * 300 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 300 + position_x + x2, ScaleY * 120 + position_y + y2);

    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 70 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 70 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 50 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 50 + position_y + y2);


    //eye thing
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 230 + position_y + y2);

    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 220 + position_y + y2);

    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 210 + position_y + y2);

    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 220 + position_y + y2);

    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 190 + position_y + y2);

    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 160 + position_y + y2);

    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 150 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 150 + position_y + y2);

    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 210 + position_y + y2);

    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 190 + position_y + y2);

    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 160 + position_y + y2);

    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 150 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 150 + position_y + y2);
    glEnd();

    //Dark red shade
    glColor3ub(136, 57, 16);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 020 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 020 + position_y + y2);

    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 050 + position_y + y2);

    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 060 + position_y + y2);

    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 050 + position_y + y2);

    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 060 + position_y + y2);

    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 430 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 430 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 070 + position_y + y2);

    glVertex2f(ScaleX * 200 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 200 + position_x + x2, ScaleY * 070 + position_y + y2);


    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 060 + position_y + y2);

    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 050 + position_y + y2);


    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 020 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 020 + position_y + y2);

    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 030 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 030 + position_y + y2);

    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 80 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 80 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 80 + position_y + y2);

    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 80 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 80 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 70 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 70 + position_y + y2);

    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 050 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 050 + position_y + y2);

    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 060 + position_y + y2);

    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 100 + position_y + y2);

    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 90 + position_y + y2);
    glEnd();

    //red shade
    glColor3ub(190, 76, 20);
    glBegin(GL_QUADS);

    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 110 + position_y + y2);

    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 100 + position_y + y2);

    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 190 + position_y + y2);

    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 210 + position_y + y2);

    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 230 + position_y + y2);

    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 270 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 270 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 260 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 260 + position_y + y2);

    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 260 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 260 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 250 + position_y + y2);

    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 250 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 240 + position_y + y2);

    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 240 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 230 + position_y + y2);

    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 210 + position_y + y2);

    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 190 + position_y + y2);

    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 420 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 110 + position_y + y2);

    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 410 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 100 + position_y + y2);

    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 400 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 90 + position_y + y2);

    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 150 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 150 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 130 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 130 + position_y + y2);

    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 130 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 130 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 120 + position_y + y2);

    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 130 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 130 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 120 + position_y + y2);

    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 130 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 130 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 90 + position_y + y2);

    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 070 + position_y + y2);

    glVertex2f(ScaleX * 300 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 320 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 300 + position_x + x2, ScaleY * 100 + position_y + y2);

    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 90 + position_y + y2);

    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 060 + position_y + y2);

    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 040 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 040 + position_y + y2);

    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 80 + position_y + y2);
    glVertex2f(ScaleX * 330 + position_x + x2, ScaleY * 80 + position_y + y2);

    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 300 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 300 + position_x + x2, ScaleY * 120 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 120 + position_y + y2);

    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 150 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 150 + position_y + y2);

    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 150 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 150 + position_y + y2);

    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 150 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 150 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 210 + position_x + x2, ScaleY * 110 + position_y + y2);

    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 100 + position_y + y2);
    glVertex2f(ScaleX * 220 + position_x + x2, ScaleY * 100 + position_y + y2);

    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 230 + position_x + x2, ScaleY * 90 + position_y + y2);

    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 070 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 070 + position_y + y2);

    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 110 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 060 + position_y + y2);

    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 060 + position_y + y2);


    glEnd();

    //eyes dark gray
    glColor3ub(97, 97, 97);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 250 + position_x + x2, ScaleY * 190 + position_y + y2);

    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 180 + position_y + y2);

    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 240 + position_x + x2, ScaleY * 160 + position_y + y2);

    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 160 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 160 + position_y + y2);

    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 390 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 180 + position_y + y2);

    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 190 + position_y + y2);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 189, 189);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 180 + position_y + y2);

    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 190 + position_y + y2);

    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 200 + position_y + y2);


    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 260 + position_x + x2, ScaleY * 210 + position_y + y2);

    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 230 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 270 + position_x + x2, ScaleY * 220 + position_y + y2);

    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 210 + position_y + y2);

    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 190 + position_y + y2);

    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 360 + position_x + x2, ScaleY * 180 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 180 + position_y + y2);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 220 + position_y + y2);
    glVertex2f(ScaleX * 340 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 280 + position_x + x2, ScaleY * 210 + position_y + y2);

    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 210 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 290 + position_x + x2, ScaleY * 200 + position_y + y2);

    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 200 + position_y + y2);
    glVertex2f(ScaleX * 350 + position_x + x2, ScaleY * 190 + position_y + y2);
    glVertex2f(ScaleX * 310 + position_x + x2, ScaleY * 190 + position_y + y2);

    glEnd();

    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 90 + position_y + y2);
    glVertex2f(ScaleX * 380 + position_x + x2, ScaleY * 060 + position_y + y2);
    glVertex2f(ScaleX * 370 + position_x + x2, ScaleY * 060 + position_y + y2);


}

void idle() {
    DWORD start = mach_absolute_time();
    while (mach_absolute_time() - start < 1000 / FPS);
    if (walkX_2 < 2400) {
        walkX_2 += dx_2;
        walkY_2 += dy_2;
    } else {
        walkX_2 += 0;
        walkY_2 += 0;
    }

    if (walkX_late_2 < 5000) {
        walkX_late_2 += dx_2;
        walkY_late_2 += dy_2;
    } else {
        walkX_late_2 += 0;
        walkY_late_2 += 0;
    }

    if (walkY_big_2 < 2100) {
        if (direction == 1) {
            walkY_big_2 += dy_big_2;
        } else {
            walkY_big_2 -= dy_big_2;
        }
    } else if (walkY_big_2 == 2100) {
        walkY_big_2 += 0.1;
    } else {
        direction = 0;
        walkY_big_2 -= dy_big_2;
    }

    //    if (walkX <0 || walkX > WINDOW_WIDTH) dx *= -1;
    //    if (walkY < 0 || walkY > WINDOW_HEIGHT) dy *= -1;
    glutPostRedisplay();
}

void drawCircle_2(int x, int y, int r, int n) {
    double inc = (2 * PI) / n;
    glBegin(GL_POLYGON);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        glVertex2d(r * cos(theta) + x, r * sin(theta) + y);
    }
    glEnd();
}

void drawRoundTree_2(float x, float y, float con_x, float ScaleX, float ScaleY) {

    // Tree trunk
    glColor3ub(45, 19, 0);
    glBegin(GL_POLYGON);
    glVertex2i(ScaleX * (x - 10 + con_x), ScaleY * (y - 65));
    glVertex2i(ScaleX * (x + 10 + con_x), ScaleY * (y - 65));
    glVertex2i(ScaleX * (x + 20 + con_x), ScaleY * (y - 150));
    glVertex2i(ScaleX * (x - 20 + con_x), ScaleY * (y - 150));
    glEnd();

    // Tree leaf
    glColor3ub(37, 65, 23);
    drawCircle_2(ScaleX * (x + con_x), ScaleY * (y), ScaleX * 30, 100);
    drawCircle_2(ScaleX * (x - 20 + con_x), ScaleY * (y - 30), ScaleX * 30, 100);
    drawCircle_2(ScaleX * (x + 20 + con_x), ScaleY * (y - 30), ScaleX * 30, 100);
    drawCircle_2(ScaleX * (x + 50 + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
    drawCircle_2(ScaleX * (x + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
    drawCircle_2(ScaleX * (x - 45 + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
}

void drawTreeRow_2() {
    // Tree row 1
    for (int j = 0; j < 1900; j += 110) {
        drawRoundTree_2(50, 300, j, 2.5, 2.5);
    }
}

void drawGround_2() {
    glColor3ub(206, 152, 108);
    glBegin(GL_POLYGON);
    glVertex2i(0, 400);
    glVertex2i(WINDOW_WIDTH, 400);
    glVertex2i(WINDOW_WIDTH, 0);
    glVertex2i(0, 0);
    glEnd();
}

void drawGate_2(float position_x, float position_y, float Gate_ScaleX, float Gate_ScaleY) {


    //top horizontal
    glColor3ub(145, 19, 19);
    glBegin(GL_QUADS);
    glVertex2f(Gate_ScaleX * (200 + position_x), Gate_ScaleY * (200 + position_y));
    glVertex2f(Gate_ScaleX * (350 + position_x), Gate_ScaleY * (200 + position_y));
    glVertex2f(Gate_ScaleX * (350 + position_x), Gate_ScaleY * (190 + position_y));
    glVertex2f(Gate_ScaleX * (200 + position_x), Gate_ScaleY * (190 + position_y));
    glEnd();

    //2nd top horizontal
    glBegin(GL_QUADS);
    glVertex2f(Gate_ScaleX * (210 + position_x), Gate_ScaleY * (190 + position_y));
    glVertex2f(Gate_ScaleX * (340 + position_x), Gate_ScaleY * (190 + position_y));
    glVertex2f(Gate_ScaleX * (340 + position_x), Gate_ScaleY * (180 + position_y));
    glVertex2f(Gate_ScaleX * (210 + position_x), Gate_ScaleY * (180 + position_y));
    glEnd();

    //left pillar
    glBegin(GL_QUADS);
    glVertex2f(Gate_ScaleX * (200 + position_x), Gate_ScaleY * (160 + position_y));
    glVertex2f(Gate_ScaleX * (350 + position_x), Gate_ScaleY * (160 + position_y));
    glVertex2f(Gate_ScaleX * (350 + position_x), Gate_ScaleY * (150 + position_y));
    glVertex2f(Gate_ScaleX * (200 + position_x), Gate_ScaleY * (150 + position_y));
    glEnd();

    //right pillar
    glBegin(GL_QUADS);
    glVertex2f(Gate_ScaleX * (220 + position_x), Gate_ScaleY * (180 + position_y));
    glVertex2f(Gate_ScaleX * (230 + position_x), Gate_ScaleY * (180 + position_y));
    glVertex2f(Gate_ScaleX * (230 + position_x), Gate_ScaleY * (60 + position_y));
    glVertex2f(Gate_ScaleX * (220 + position_x), Gate_ScaleY * (60 + position_y));
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(Gate_ScaleX * (320 + position_x), Gate_ScaleY * (180 + position_y));
    glVertex2f(Gate_ScaleX * (330 + position_x), Gate_ScaleY * (180 + position_y));
    glVertex2f(Gate_ScaleX * (330 + position_x), Gate_ScaleY * (60 + position_y));
    glVertex2f(Gate_ScaleX * (320 + position_x), Gate_ScaleY * (60 + position_y));
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(Gate_ScaleX * (200 + position_x), Gate_ScaleY * (160 + position_y));
    glVertex2f(Gate_ScaleX * (350 + position_x), Gate_ScaleY * (160 + position_y));
    glVertex2f(Gate_ScaleX * (350 + position_x), Gate_ScaleY * (150 + position_y));
    glVertex2f(Gate_ScaleX * (200 + position_x), Gate_ScaleY * (150 + position_y));
    glEnd();

    //bottom slab
    //left
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);
    glVertex2f(Gate_ScaleX * (210 + position_x), Gate_ScaleY * (60 + position_y));
    glVertex2f(Gate_ScaleX * (240 + position_x), Gate_ScaleY * (60 + position_y));
    glVertex2f(Gate_ScaleX * (240 + position_x), Gate_ScaleY * (50 + position_y));
    glVertex2f(Gate_ScaleX * (210 + position_x), Gate_ScaleY * (50 + position_y));
    glEnd();

    //right
    glBegin(GL_QUADS);
    glVertex2f(Gate_ScaleX * (310 + position_x), Gate_ScaleY * (60 + position_y));
    glVertex2f(Gate_ScaleX * (340 + position_x), Gate_ScaleY * (60 + position_y));
    glVertex2f(Gate_ScaleX * (340 + position_x), Gate_ScaleY * (50 + position_y));
    glVertex2f(Gate_ScaleX * (310 + position_x), Gate_ScaleY * (50 + position_y));
    glEnd();

    //middle pillar
    glBegin(GL_QUADS);
    glVertex2f(Gate_ScaleX * (270 + position_x), Gate_ScaleY * (180 + position_y));
    glVertex2f(Gate_ScaleX * (280 + position_x), Gate_ScaleY * (180 + position_y));
    glVertex2f(Gate_ScaleX * (280 + position_x), Gate_ScaleY * (160 + position_y));
    glVertex2f(Gate_ScaleX * (270 + position_x), Gate_ScaleY * (160 + position_y));
    glEnd();


    //inner road
    glBegin(GL_QUADS);
    glColor3ub(130, 75, 29);
    glVertex2f(Gate_ScaleX * (250 + position_x), Gate_ScaleY * (90 + position_y));
    glVertex2f(Gate_ScaleX * (300 + position_x), Gate_ScaleY * (90 + position_y));
    glVertex2f(Gate_ScaleX * (310 + position_x), Gate_ScaleY * (60 + position_y));
    glVertex2f(Gate_ScaleX * (240 + position_x), Gate_ScaleY * (60 + position_y));
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(130, 75, 29);
    glVertex2f(Gate_ScaleX * (240 + position_x), Gate_ScaleY * (60 + position_y));
    glVertex2f(Gate_ScaleX * (310 + position_x), Gate_ScaleY * (60 + position_y));
    glVertex2f(Gate_ScaleX * (310 + position_x), Gate_ScaleY * (50 + position_y));
    glVertex2f(Gate_ScaleX * (240 + position_x), Gate_ScaleY * (50 + position_y));
    glEnd();


}

void drawTextBubble_Where_Brown_2() {
    if (visibleS2_1) {
        drawTextBubble_2(830, 230, 1, 1);
        drawQuestionMark_2(1030, 228, .8, .8);
        drawAmongUs(2320, 885, 0, 0, 190, 76, 20, 136, 57, 16, .5, .5);

    }
}

void drawTextBubble_Sorry_Im_Late_2() {
    if (visibleS2_2) {

        drawTextBubble_2(320, 230, 1, 1);
        drawSweatSmiley_2(450, 275, .8, .8);

    }
}

void drawHill_2(float position_x, float position_y, float Hill_ScaleX, float Hill_ScaleY) {

    ///Hill
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(Hill_ScaleX * (70) + position_x, Hill_ScaleY * (70) + position_y);
    glVertex2i(Hill_ScaleX * (200) + position_x, Hill_ScaleY * (225) + position_y);
    glVertex2i(Hill_ScaleX * (330) + position_x, Hill_ScaleY * (70) + position_y);

    glEnd();

    ///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);

    glVertex2i(Hill_ScaleX * (200) + position_x, Hill_ScaleY * (225) + position_y);
    glVertex2i(Hill_ScaleX * (230) + position_x, Hill_ScaleY * (190) + position_y);
    glVertex2i(Hill_ScaleX * (220) + position_x, Hill_ScaleY * (180) + position_y);
    glVertex2i(Hill_ScaleX * (200) + position_x, Hill_ScaleY * (190) + position_y);
    glVertex2i(Hill_ScaleX * (190) + position_x, Hill_ScaleY * (180) + position_y);
    glVertex2i(Hill_ScaleX * (170) + position_x, Hill_ScaleY * (190) + position_y);

    glEnd();


}

void display2() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawTreeRow_2();


    drawGround_2();
    drawGrassGroup_2();
    drawGate_2(190, 25, 3.5, 3.5);
    drawHill_2(1514, 365, .5, .5);
    drawHill_2(1580, 372, .4, .4);
    drawAmongUs(-1200, 650, walkX_2, walkY_2, 61, 98, 219, 34, 61, 148, .5, .5);
    drawAmongUs(-1000, 650, walkX_2, walkY_2, 230, 180, 193, 226, 143, 173, .5, .5);
    drawAmongUs(-800, 650, walkX_2, walkY_2, 112, 155, 107, 84, 113, 59, .5, .5);
    drawAmongUs(-600, 650, walkX_2, walkY_2, 242, 219, 39, 242, 188, 34, .5, .5);
    drawAmongUs(-400, 650, walkX_2, walkY_2, 167, 27, 20, 91, 15, 8, .5, .5);
    drawAmongUs(-4000, 650, walkX_late_2, walkY_late_2, 190, 76, 20, 136, 57, 16, .5, .5);
    drawAmongUsBig_2(80, -2000, walkX_big_2, walkY_big_2, 1, 1);
    drawTextBubble_Where_Brown_2();
    drawTextBubble_Sorry_Im_Late_2();

    //glutIdleFunc(idle);

    /* flush GL buffers */
    glFlush();
    glutSwapBuffers();
}

//Scene3(Kek)
void drawRoundTree3(int x, int y, int con_x) {

    // Tree trunk
    glColor3ub(45, 19, 0);
    glBegin(GL_POLYGON);
    glVertex2i(x - 10 + con_x, y - 65 + con_x);
    glVertex2i(x + 10 + con_x, y - 65 + con_x);
    glVertex2i(x + 20 + con_x, y - 150 + con_x);
    glVertex2i(x - 20 + con_x, y - 150 + con_x);
    glEnd();

    // Tree leaf
    glColor3ub(37, 65, 23);
    drawCircle(x + con_x, y + con_x, 30, 100);
    drawCircle(x - 20 + con_x, y - 30 + con_x, 30, 100);
    drawCircle(x + 20 + con_x, y - 30 + con_x, 30, 100);
    drawCircle(x + 50 + con_x, y - 65 + con_x, 30, 100);
    drawCircle(x + con_x, y - 65 + con_x, 30, 100);
    drawCircle(x - 45 + con_x, y - 65 + con_x, 30, 100);
}

void drawTreeRow3() {
    // Tree row 1
    for (int j = 0; j < 1100; j += 100) {
        drawRoundTree3(200, 200, j);
    }

    // Tree row 2
    for (int j = 0; j < 1100; j += 100) {
        drawRoundTree3(100, 300, j);
    }
    // Tree row 3
    for (int j = 0; j < 1100; j += 100) {
        drawRoundTree3(0, 400, j);
    }

    // Tree row 4
    for (int j = 0; j < 1100; j += 100) {
        drawRoundTree3(-100, 500, j);
    }

    // Tree row 5
    for (int j = 0; j < 1100; j += 100) {
        drawRoundTree3(-200, 600, j);
    }

    // Tree row 6
    for (int j = 0; j < 1100; j += 100) {
        drawRoundTree3(-300, 700, j);
    }
}

void drawWalkway3() {
    glColor3ub(182, 146, 116);
    glBegin(GL_POLYGON);
    glVertex2i(200, 0);
    glVertex2i(1250, WINDOW_HEIGHT);
    glVertex2i(2000, WINDOW_HEIGHT);
    glVertex2i(1600, 0);
    glEnd();
}

void drawSignBoard3() {

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(1680, 530);
    glVertex2i(1700, 525);
    glVertex2i(1700, 80);
    glVertex2i(1680, 100);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(1540, 520);
    glVertex2i(1860, 360);
    glVertex2i(1860, 180);
    glVertex2i(1540, 340);
    glEnd();

    glColor3ub(194, 197, 204);
    glBegin(GL_QUADS);
    glVertex2i(1550, 500);
    glVertex2i(1850, 350);
    glVertex2i(1850, 200);
    glVertex2i(1550, 350);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(1600, 410);
    glVertex2i(1780, 320);
    glVertex2i(1780, 300);
    glVertex2i(1600, 390);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(1600, 430);
    glVertex2i(1600, 370);
    glVertex2i(1580, 410);
    glEnd();

}

void drawGrass3(int x, int y) {
    glColor3ub(65, 142, 47);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x - 10, y + 15);
    glVertex2i(x + 10, y + 8);
    glVertex2i(x + 15, y + 25);
    glVertex2i(x + 20, y + 9);
    glVertex2i(x + 30, y + 11);
    glVertex2i(x + 25, y);
    glEnd();

}

void drawManyGrass3(float val_x, float val_y) {
    drawGrass3(1000 + val_x, 510 + val_y);
    drawGrass3(1600 + val_x, 430 + val_y);
    drawGrass3(1100 + val_x, 230 + val_y);
    drawGrass3(1200 + val_x, 310 + val_y);
    drawGrass3(1340 + val_x, 555 + val_y);
    drawGrass3(1400 + val_x, 730 + val_y);
    drawGrass3(1503 + val_x, 600 + val_y);
    drawGrass3(1430 + val_x, 820 + val_y);
}

void display3() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawTreeRow3();
    drawWalkway3();
    drawGrass3(1000, 500);
    drawManyGrass3(0, 0);
    drawManyGrass3(100, 40);
    drawManyGrass3(300, 100);
    drawManyGrass3(-200, 50);
    drawManyGrass3(350, 50);
    drawManyGrass3(-50, 50);
    drawManyGrass3(500, -300);
    drawManyGrass3(-500, -300);


    drawAmongUs(700, 200, walkXs3, walkYs3, 61, 98, 219, 34, 61, 148, 0.6, 0.6);
    drawAmongUs(900, 200, walkXs3, walkYs3, 230, 180, 193, 226, 143, 173, 0.6, 0.6);
    drawAmongUs(1100, 200, walkXs3, walkYs3, 112, 155, 107, 84, 113, 59, 0.6, 0.6);
    drawAmongUs(850, 500, walkXs3, walkYs3, 242, 219, 39, 242, 188, 34, 0.6, 0.6);
    drawAmongUs(1050, 500, walkXs3, walkYs3, 167, 27, 20, 91, 15, 8, 0.6, 0.6);
    drawAmongUs(1250, 500, walkXs3, walkYs3, 190, 76, 20, 136, 57, 16, 0.6, 0.6);



    /* flush GL buffers */
    glFlush();
    glutSwapBuffers();
}

//Scene4(Ivan)
void drawRoundTree4(int x, int y, int con_x, float ScaleX, float ScaleY) {
    // Tree trunk
    glColor3ub(45, 19, 0);
    glBegin(GL_POLYGON);
    glVertex2i(ScaleX * (x - 10 + con_x), ScaleY * (y - 65));
    glVertex2i(ScaleX * (x + 10 + con_x), ScaleY * (y - 65));
    glVertex2i(ScaleX * (x + 20 + con_x), ScaleY * (y - 150));
    glVertex2i(ScaleX * (x - 20 + con_x), ScaleY * (y - 150));
    glEnd();

    // Tree leaf
    glColor3ub(37, 65, 23);
    drawCircle(ScaleX * (x + con_x), ScaleY * (y), ScaleX * 30, 100);
    drawCircle(ScaleX * (x - 20 + con_x), ScaleY * (y - 30), ScaleX * 30, 100);
    drawCircle(ScaleX * (x + 20 + con_x), ScaleY * (y - 30), ScaleX * 30, 100);
    drawCircle(ScaleX * (x + 50 + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
    drawCircle(ScaleX * (x + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
    drawCircle(ScaleX * (x - 45 + con_x), ScaleY * (y - 65), ScaleX * 30, 100);


}

void drawTreeRow4() {
    // Tree upper row 1
    for (int j = 0; j < 1050; j += 105) {
        drawRoundTree4(-50, 730, j, 1.5, 1.5);
    }
    // Tree upper row 2
    for (int j = 0; j < 910; j += 130) {
        drawRoundTree4(0, 630, j, 1.5, 1.5);
    }

    // Tree lower row 1
    for (int j = 0; j < 910; j += 130) {
        drawRoundTree4(0, 250, j, 1.5, 1.5);
    }

    // Tree lower row 1
    for (int j = 0; j < 910; j += 130) {
        drawRoundTree4(0, 250, j, 1.5, 1.5);
    }

    // Tree standalone
    drawRoundTree4(510, 800, 500, 1.5, 1.5);
    drawRoundTree4(450, 180, 450, 1.5, 1.5);

}

void drawWalkway4() {
    glColor3ub(182, 146, 116);

    //middle
    glBegin(GL_POLYGON);

    glVertex2i(0, 725);
    glVertex2i(WINDOW_WIDTH, 725);
    glVertex2i(WINDOW_WIDTH, 425);
    glVertex2i(0, 425);
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glVertex2i(1200, 725);
    glVertex2i(WINDOW_WIDTH - 50, WINDOW_HEIGHT + 100);
    glVertex2i(WINDOW_WIDTH + 75, WINDOW_HEIGHT);
    glVertex2i(1700, 725);

    glEnd();

    //bottom
    glBegin(GL_POLYGON);
    glVertex2i(1200, 425);
    glVertex2i(1700, 425);
    glVertex2i(WINDOW_WIDTH + 200, 50);
    glVertex2i(1900, -50);

    glEnd();
}

void drawGrass4(int x, int y) {

    glColor3ub(0, 154, 23);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x - 10, y + 15);
    glVertex2i(x + 10, y + 8);
    glVertex2i(x + 15, y + 25);
    glVertex2i(x + 20, y + 9);
    glVertex2i(x + 30, y + 11);
    glVertex2i(x + 25, y);
    glEnd();

}

void drawManyGrass4(float val_x, float val_y) {
    drawGrass4(100 + val_x, 600 + val_y);
    drawGrass4(150 + val_x, 480 + val_y);
    drawGrass4(200 + val_x, 510 + val_y);
    drawGrass4(300 + val_x, 600 + val_y);
    drawGrass4(400 + val_x, 450 + val_y);
    drawGrass4(500 + val_x, 500 + val_y);
    drawGrass4(610 + val_x, 560 + val_y);
    drawGrass4(700 + val_x, 640 + val_y);
    drawGrass4(760 + val_x, 530 + val_y);
    drawGrass4(830 + val_x, 450 + val_y);
    drawGrass4(910 + val_x, 572 + val_y);
    drawGrass4(1000 + val_x, 555 + val_y);
    drawGrass4(1060 + val_x, 450 + val_y);
    drawGrass4(1150 + val_x, 666 + val_y);
    drawGrass4(1203 + val_x, 600 + val_y);
    drawGrass4(1430 + val_x, 480 + val_y);
    drawGrass4(1380 + val_x, 680 + val_y);
    drawGrass4(1440 + val_x, 700 + val_y);
    drawGrass4(1540 + val_x, 600 + val_y);
    drawGrass4(1580 + val_x, 730 + val_y);
    drawGrass4(1380 + val_x, 420 + val_y);
    drawGrass4(1540 + val_x, 333 + val_y);
    drawGrass4(1500 + val_x, 367 + val_y);
    drawGrass4(1600 + val_x, 700 + val_y);
    drawGrass4(1630 + val_x, 650 + val_y);
    drawGrass4(1690 + val_x, 870 + val_y);
    drawGrass4(1690 + val_x, 316 + val_y);
    drawGrass4(1700 + val_x, 800 + val_y);
    drawGrass4(1730 + val_x, 900 + val_y);
    drawGrass4(1730 + val_x, 280 + val_y);
    drawGrass4(1500 + val_x, 280 + val_y);
    drawGrass4(1695 + val_x, 260 + val_y);
    drawGrass4(1760 + val_x, 233 + val_y);
    drawGrass4(1720 + val_x, 522 + val_y);
    drawGrass4(1695 + val_x, 457 + val_y);
    drawGrass4(1800 + val_x, 450 + val_y);
    drawGrass4(1833 + val_x, 488 + val_y);
    drawGrass4(1883 + val_x, 542 + val_y);
    drawGrass4(1883 + val_x, 604 + val_y);

}

void display4() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawTreeRow4();
    drawWalkway4();
    drawManyGrass4(0, 0);
    drawManyGrass4(-100, 37);

    drawAmongUs(0, 1000 - 150, walkXs4b, walkYs4b, 112, 155, 107, 84, 113, 59, 0.6, 0.6);           //green
    drawAmongUs(170, 1050 - 150, walkXs4b, walkYs4b, 230, 180, 193, 226, 143, 173, 0.6, 0.6);     //pink
    drawAmongUs(50, 1225 - 150, walkXs4c, walkYs4c, 190, 76, 20, 136, 57, 16, 0.6, 0.6);        //orange
    drawAmongUs(-150, 1150 - 150, walkXs4a, walkYs4a, 242, 219, 39, 242, 188, 34, 0.6, 0.6);      //yellow
    drawAmongUs(-100, 1380 - 150, walkXs4a, walkYs4a, 167, 27, 20, 91, 15, 8, 0.6, 0.6);          //red
    drawAmongUs(200, 1380 - 150, walkXs4a, walkYs4a, 61, 98, 219, 34, 61, 148, 0.6, 0.6);         //blue=
    //glutIdleFunc(idle4);

    /* flush GL buffers */
    glFlush();
    glutSwapBuffers();
}

//Scene5(Eve)
void drawCircle_S5(int x, int y, int r, int n) {
    double inc = (2 * PI) / n;
    glBegin(GL_POLYGON);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        glVertex2d(r * cos(theta) + x, r * sin(theta) + y);
    }
    glEnd();
}

void drawRoundTree_S5(float x, float y, float con_x, float ScaleX, float ScaleY) {

    // Tree trunk
    glColor3ub(45, 19, 0);
    glBegin(GL_POLYGON);
    glVertex2i(ScaleX * (x - 10 + con_x), ScaleY * (y - 65));
    glVertex2i(ScaleX * (x + 10 + con_x), ScaleY * (y - 65));
    glVertex2i(ScaleX * (x + 20 + con_x), ScaleY * (y - 150));
    glVertex2i(ScaleX * (x - 20 + con_x), ScaleY * (y - 150));
    glEnd();

    // Tree leaf
    glColor3ub(37, 65, 23);
    drawCircle_S5(ScaleX * (x + con_x), ScaleY * (y), ScaleX * 30, 100);
    drawCircle_S5(ScaleX * (x - 20 + con_x), ScaleY * (y - 30), ScaleX * 30, 100);
    drawCircle_S5(ScaleX * (x + 20 + con_x), ScaleY * (y - 30), ScaleX * 30, 100);
    drawCircle_S5(ScaleX * (x + 50 + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
    drawCircle_S5(ScaleX * (x + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
    drawCircle_S5(ScaleX * (x - 45 + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
}

void drawTreeRow_S5() {
    // Tree row 1
    for (int j = 0; j < 1900; j += 110) {
        drawRoundTree_S5(50, 300, j, 2.5, 2.5);
    }
}

void drawGround_S5() {
    glColor3ub(206, 152, 108);
    glBegin(GL_POLYGON);
    glVertex2i(0, 400);
    glVertex2i(WINDOW_WIDTH, 400);
    glVertex2i(WINDOW_WIDTH, 0);
    glVertex2i(0, 0);
    glEnd();
}

void drawGrass_S5(int x, int y) {
    //glColor3ub(0, 0, 0);
    glColor3ub(65, 142, 47);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x - 10, y + 15);
    glVertex2i(x + 10, y + 8);
    glVertex2i(x + 15, y + 25);
    glVertex2i(x + 20, y + 9);
    glVertex2i(x + 30, y + 11);
    glVertex2i(x + 25, y);
    glEnd();

}

void drawGrasses_S5() {
    drawGrass_S5(200, 300);
    drawGrass_S5(776, 264);
    drawGrass_S5(1423, 153);
    drawGrass_S5(532, 315);
    drawGrass_S5(2854, 253);
    drawGrass_S5(1382, 285);
    drawGrass_S5(735, 158);
    drawGrass_S5(1525, 196);
    drawGrass_S5(948, 253);
    drawGrass_S5(1824, 285);
    drawGrass_S5(357, 158);
    drawGrass_S5(2255, 196);
}

void drawTextBubble_S5(float position_x, float position_y, float ScaleX, float ScaleY) {
    //left wall
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 80 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 80 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 110 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glEnd();

    //bottom wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 110 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 110 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glEnd();

    //right wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 550 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 550 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 280 + position_y);
    glEnd();

    //top wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glEnd();

    //inner filling
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 100 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 130 + position_y);
    glEnd();

}

void drawQuestionMark_S5(float position_x, float position_y, float ScaleX, float ScaleY) {
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 300 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 320 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 320 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 310 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 310 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 300 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 380 + position_x, ScaleY * 270 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 270 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 270 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 270 + position_y);
    glVertex2f(ScaleX * 370 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 260 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 350 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 260 + position_y);
    glVertex2f(ScaleX * 360 + position_x, ScaleY * 250 + position_y);
    glVertex2f(ScaleX * 350 + position_x, ScaleY * 250 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 250 + position_y);
    glVertex2f(ScaleX * 350 + position_x, ScaleY * 250 + position_y);
    glVertex2f(ScaleX * 350 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 240 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 240 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 220 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 220 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 200 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 200 + position_y);
    glVertex2f(ScaleX * 340 + position_x, ScaleY * 190 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 190 + position_y);
    glEnd();
}

void drawRedX_S5(float position_x, float position_y, float ScaleX, float ScaleY) {
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0, .0, .0);
    glVertex2f(position_x, position_y);
    glVertex2f(position_x + 50, position_y + 50);
    glVertex2f(position_x + 50, position_y);
    glVertex2f(position_x, position_y + 50);

    glEnd();
}

void drawEyes_S5(float position_x, float position_y, float ScaleX, float ScaleY) {
    //glColor3f(1.0, 0.0, 0.0);

    // Big eye
    glBegin(GL_POLYGON);
    double inc = (2 * PI) / 50;
    glColor3ub(106, 194, 194);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        glVertex2d(position_x + (18 * cos(theta) + 100), position_y + (40 * sin(theta) + 100));
    }
    glEnd();

    // Middle eye
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        glVertex2d(10 * cos(theta) + position_x + 95, 12 * sin(theta) + position_y + 100);
    }
    glEnd();

    // Small eye
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        glVertex2d(3 * cos(theta) + position_x + 90, 5 * sin(theta) + position_y + 100);
    }
    glEnd();
}

void display5() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawTreeRow_S5();
    drawGround_S5();
    drawGrasses_S5();

    if (visibleS5_1) {
        //red
        drawTextBubble_S5(200, 320, 0.8, 0.8);                                         //red text
        drawAmongUs(1500, 1650, 0, 0, 230, 180, 193, 226, 143, 173, 0.3, 0.3);      // SMALL pink
        drawAmongUs(1700, 1650, 0, 0, 112, 155, 107, 84, 113, 59, 0.3, 0.3);        // SMALL green
        drawAmongUs(1900, 1650, 0, 0, 190, 76, 20, 136, 57, 16, 0.3, 0.3);          // SMALL orange
    }

    if (visibleS5_2) {
        //yellow
        drawTextBubble_S5(650, 120, 0.8, 0.8);                                         //yellow text
        drawRedX_S5(920, 260, 0.5, 0.65);
        drawEyes_S5(920, 190, 0.5, 0.65);                                               // left eye
        drawEyes_S5(950, 190, 0.5, 0.65);                                               // right eye
    }

    if (visibleS5_3) {
        //blue
        drawTextBubble_S5(1100, 230, 0.8, 0.8);                                        //blue text
        drawQuestionMark_S5(1210, 265, 0.5, 0.5);
        drawQuestionMark_S5(1260, 265, 0.5, 0.5);
        drawQuestionMark_S5(1310, 265, 0.5, 0.5);
    }

    drawAmongUs(-1650, 650, walkX_S5, walkY_S5, 167, 27, 20, 91, 15, 8, 0.5, 0.5);        // red
    drawAmongUs(-800, 250, walkX_S5, walkY_S5, 242, 219, 39, 242, 188, 34, 0.5, 0.5);    // yellow
    drawAmongUs(100, 500, walkX_S5, walkY_S5, 61, 98, 219, 34, 61, 148, 0.5, 0.5);       // blue

    //glutIdleFunc(idle);
    /* flush GL buffers */
    glFlush();
    glutSwapBuffers();
}

//Scene6(SooHao)
void drawRoundTrees6(float x, float y, float con_x, float ScaleX, float ScaleY) {

    // Tree trunk
    glColor3ub(45, 19, 0);
    glBegin(GL_POLYGON);
    glVertex2i(ScaleX * (x - 10 + con_x), ScaleY * (y - 65));
    glVertex2i(ScaleX * (x + 10 + con_x), ScaleY * (y - 65));
    glVertex2i(ScaleX * (x + 20 + con_x), ScaleY * (y - 150));
    glVertex2i(ScaleX * (x - 20 + con_x), ScaleY * (y - 150));
    glEnd();

    // Tree leaf
    glColor3ub(37, 65, 23);
    drawCircle(ScaleX * (x + con_x), ScaleY * (y), ScaleX * 30, 100);
    drawCircle(ScaleX * (x - 20 + con_x), ScaleY * (y - 30), ScaleX * 30, 100);
    drawCircle(ScaleX * (x + 20 + con_x), ScaleY * (y - 30), ScaleX * 30, 100);
    drawCircle(ScaleX * (x + 50 + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
    drawCircle(ScaleX * (x + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
    drawCircle(ScaleX * (x - 45 + con_x), ScaleY * (y - 65), ScaleX * 30, 100);
}

void drawTreeRows6() {
    // Tree row 1
    for (int j = 0; j < 1900; j += 110) {
        drawRoundTrees6(50, 300, j, 2.5, 2.5);
    }
}

void drawGrounds6() {
    glColor3ub(206, 152, 108);
    glBegin(GL_POLYGON);
    glVertex2i(0, 400);
    glVertex2i(WINDOW_WIDTH, 400);
    glVertex2i(WINDOW_WIDTH, 0);
    glVertex2i(0, 0);
    glEnd();
}

void drawGrasss6(int x, int y) {
    //glColor3ub(0, 0, 0);
    glColor3ub(65, 142, 47);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x - 10, y + 15);
    glVertex2i(x + 10, y + 8);
    glVertex2i(x + 15, y + 25);
    glVertex2i(x + 20, y + 9);
    glVertex2i(x + 30, y + 11);
    glVertex2i(x + 25, y);
    glEnd();

}

void drawGrassess6() {
    drawGrasss6(400, 300);
    drawGrasss6(576, 264);
    drawGrasss6(523, 153);
    drawGrasss6(432, 315);
    drawGrasss6(1854, 253);
    drawGrasss6(1482, 285);
    drawGrasss6(1735, 158);
    drawGrasss6(1525, 196);
}

void drawAmongUsDeads6(float x1, float y1, float x2, float y2, int lbr, int lbg, int lbb, int dbr, int dbg, int dbb,
                       float ScaleX, float ScaleY) {

    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(1200.0f, 750.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * (x1 + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * (x1 + x2), ScaleY * ((y1 - 90) + y2));

    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * (y1 + y2));

    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 100) + y2));

    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 130) + y2));

    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 140) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 - 140) + y2));

    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 140) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 140) + y2));

    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 130) + y2));

    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 130) + y2));

    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 110) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 110) + y2));

    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));

    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 30) + y2));

    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 30) + y2));

    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 20) + y2));

    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 10) + y2));

    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));

    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 20) + y2));

    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 30) + y2));

    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 160) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 160) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 10) + y2));

    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 40) + y2));

    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 40) + y2));

    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 50) + y2));

    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 50) + y2));

    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 70) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 70) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 60) + y2));
    glEnd();

    //light blue shade
    glBegin(GL_POLYGON);
    glColor3ub(lbr, lbg, lbb);
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 60) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 20) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 50) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 40) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 40) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 40) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 - 40) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 60) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 60) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 80) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 50) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 50) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 70) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 70) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 80) + y2));
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 20) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 20) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 30) + y2));
    glEnd();

    //dark blue shade
    glBegin(GL_POLYGON);
    glColor3ub(dbr, dbg, dbb);
    glVertex2f(ScaleX * ((x1 + 20) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 30) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 90) + y2));
    glVertex2f(ScaleX * ((x1 + 10) + x2), ScaleY * ((y1 - 30) + y2));
    glVertex2f(ScaleX * ((x1 + 20) + x2), ScaleY * ((y1 - 30) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 40) + x2), ScaleY * ((y1 - 130) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 - 40) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 40) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 50) + x2), ScaleY * ((y1 - 130) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 60) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 60) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 60) + x2), ScaleY * ((y1 - 130) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 100) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 100) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 80) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 100) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 120) + x2), ScaleY * ((y1 - 70) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 70) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 130) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 50) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 50) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 130) + y2));
    glVertex2f(ScaleX * ((x1 + 130) + x2), ScaleY * ((y1 - 70) + y2));
    glEnd();

    //light gray shade
    glBegin(GL_POLYGON);
    glColor3ub(152, 168, 171);
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * (y1 + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * (y1 + y2));
    glEnd();

    //dark gray shade
    glBegin(GL_POLYGON);
    glColor3ub(87, 102, 107);
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * (y1 + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 70) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 20) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 20) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 80) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * (y1 + y2));
    glVertex2f(ScaleX * ((x1 + 150) + x2), ScaleY * ((y1 - 10) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 - 10) + y2));
    glEnd();

    // inside eyes white shade
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 30) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 100) + x2), ScaleY * ((y1 + 20) + y2));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 20) + y2));
    glVertex2f(ScaleX * ((x1 + 140) + x2), ScaleY * ((y1 + 10) + y2));
    glVertex2f(ScaleX * ((x1 + 110) + x2), ScaleY * ((y1 + 10) + y2));
    glEnd();
    glPopMatrix();
}

void drawTextBubbles6(float position_x, float position_y, float ScaleX, float ScaleY) {
    //left wall
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 80 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 80 + position_y);
    glVertex2f(ScaleX * 280 + position_x, ScaleY * 80 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 110 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glEnd();

    //bottom wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 110 + position_y);
    glVertex2f(ScaleX * 330 + position_x, ScaleY * 110 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glEnd();

    //right wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 550 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 550 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 280 + position_y);
    glEnd();

    //top wall
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 300 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glEnd();

    //inner filling
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 290 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 320 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 100 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 100 + position_y);
    glVertex2f(ScaleX * 310 + position_x, ScaleY * 90 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 90 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 300 + position_x, ScaleY * 120 + position_y);
    glVertex2f(ScaleX * 290 + position_x, ScaleY * 120 + position_y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 280 + position_y);
    glVertex2f(ScaleX * 540 + position_x, ScaleY * 130 + position_y);
    glVertex2f(ScaleX * 530 + position_x, ScaleY * 130 + position_y);
    glEnd();

}

void drawBloodBGs6() {
    double inc = (2 * PI) / 50;
    glColor3ub(121, 25, 18);
    glBegin(GL_POLYGON);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        // 860 is x position
        // 210 is y position
        // 950 & 200 is the radius
        //  +100 i forget edy
        glVertex2d(1250 + (100 * cos(theta) + 100), 150 + (50 * sin(theta) + 100));
    }
    glEnd();
}

void drawExclamationMarks6(float x, float y, float scaleX, float scaleY) {
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(scaleX * (x), scaleY * (y));
    glVertex2f(scaleX * (x + 200), scaleY * (y));
    glVertex2f(scaleX * (x + 150), scaleY * (y - 400));
    glVertex2f(scaleX * (x + 50), scaleY * (y - 400));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(scaleX * (x + 55), scaleY * (y - 450));
    glVertex2f(scaleX * (x + 145), scaleY * (y - 450));
    glVertex2f(scaleX * (x + 140), scaleY * (y - 550));
    glVertex2f(scaleX * (x + 60), scaleY * (y - 550));
    glEnd();
}

void display3AmongUsWalks6() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawTreeRows6();

    drawGrounds6();
    drawGrassess6();


    drawBloodBGs6();
    drawAmongUsDeads6(900, 300, 0, 0, 61, 98, 219, 34, 61, 148, 0.5, 0.5);//blue dead
    drawAmongUs(2000, 600, 0, walkYs6, 167, 27, 20, 91, 15, 8, 0.5, 0.5); //red
    drawAmongUs(2300, 600, 0, walkYs6, 242, 219, 39, 242, 188, 34, 0.5, 0.5);//yellow
    drawAmongUs(0, 600, walkX3s6, walkYs6, 230, 180, 193, 226, 143, 173, 0.5, 0.5); //pink
    drawAmongUs(-200, 600, walkX3s6, walkYs6, 112, 155, 107, 84, 113, 59, 0.5, 0.5);//green
    drawAmongUs(-400, 600, walkX3s6, walkYs6, 190, 76, 20, 136, 57, 16, 0.5, 0.5);//orange

    //glutIdleFunc(idle);

    /* flush GL buffers */
    glFlush();
    glutSwapBuffers();
}

void displayBubble3s6() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawTreeRows6();

    drawGrounds6();
    drawGrassess6();
    //    drawTextBubble(200, 320, 0.8, 0.8);
    drawTextBubbles6(500, 280, 0.8, 0.8);
    drawExclamationMarks6(7900, 4700, 0.1, 0.1);
    drawExclamationMarks6(8300, 4700, 0.1, 0.1);
    drawExclamationMarks6(8700, 4700, 0.1, 0.1);
    //    drawQuestionMark(750, 360, 0.5, 0.5);
    //    drawQuestionMark(800, 360, 0.5, 0.5);
    //    drawQuestionMark(850, 360, 0.5, 0.5);

    drawBloodBGs6();
    drawAmongUsDeads6(900, 300, 0, 0, 61, 98, 219, 34, 61, 148, 0.5, 0.5);//blue dead
    drawAmongUs(2000, 600, 0, 0, 167, 27, 20, 91, 15, 8, 0.5, 0.5); //red
    drawAmongUs(2300, 600, 0, 0, 242, 219, 39, 242, 188, 34, 0.5, 0.5);//yellow
    drawAmongUs(1800, 600, 0, 0, 230, 180, 193, 226, 143, 173, 0.5, 0.5); //pink
    drawAmongUs(1600, 600, 0, 0, 112, 155, 107, 84, 113, 59, 0.5, 0.5);//green
    drawAmongUs(1400, 600, 0, 0, 190, 76, 20, 136, 57, 16, 0.5, 0.5);//orange

    //glutIdleFunc(idle);

    /* flush GL buffers */
    glFlush();
    glutSwapBuffers();
}

void displayBubbles6() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawTreeRows6();

    drawGrounds6();
    drawGrassess6();

    drawTextBubbles6(980, 280, 0.8, 0.8);
    drawExclamationMarks6(12500, 4700, 0.1, 0.1);
    drawExclamationMarks6(13000, 4700, 0.1, 0.1);
    drawExclamationMarks6(13500, 4700, 0.1, 0.1);


    drawBloodBGs6();
    drawAmongUsDeads6(900, 300, 0, 0, 61, 98, 219, 34, 61, 148, 0.5, 0.5); // blue
    drawAmongUs(2300, 600, 0, 0, 242, 219, 39, 242, 188, 34, 0.5, 0.5); //yellow
    drawAmongUs(2000, 600, 0, 0, 167, 27, 20, 91, 15, 8, 0.5, 0.5);//red

    /* flush GL buffers */
    glFlush();
    glutSwapBuffers();
}

void displays6() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawTreeRows6();
    drawGrounds6();
    drawGrassess6();
    drawBloodBGs6();
    drawAmongUsDeads6(900, 300, 0, 0, 61, 98, 219, 34, 61, 148, 0.5, 0.5); // blue
    drawAmongUs(-1700, 600, walkXs6, walkYs6, 242, 219, 39, 242, 188, 34, 0.5, 0.5); //yellow
    drawAmongUs(-2000, 600, walkXs6, walkYs6, 167, 27, 20, 91, 15, 8, 0.5, 0.5); // red
    /* flush GL buffers */
    glFlush();
    glutSwapBuffers();
}

//Scene7(LiYi)
void drawBlueBG_7() {
    double inc = (2 * PI) / 50;
    glColor3ub(106, 194, 194);
    glBegin(GL_POLYGON);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        glVertex2d(860 + (950 * cos(theta) + 100), 200 + (200 * sin(theta) + 100));
    }
    glEnd();
}

void write_7_1(int x, int x1, int y, int y1, float r) {
    glColor3f(r, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + x1, y);
    glVertex2i(x + x1, y + y1);
    glVertex2i(x, y + y1);
    glEnd();
}

void writeL_7(int x) {
    write_7_1(x, 50, 650, 200, 1.0);
    write_7_1(x, 125, 650, 50, 1.0);
}

void drawWords_7() {
    glColor3f(1.0, 0.0, 0.0);
    // word: K
    write_7_1(400, 50, 650, 200, 1.0);

    glBegin(GL_POLYGON);
    glVertex2i(400, 750);
    glVertex2i(400 + 60, 750);
    glVertex2i(400 + 160, 750 + 100);
    glVertex2i(400 + 100, 750 + 100);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(400 + 100, 650);
    glVertex2i(400 + 160, 650);
    glVertex2i(400 + 60, 750);
    glVertex2i(400, 750);
    glEnd();

    // word: I
    write_7_1(600, 50, 650, 200, 1.0);

    // word: L
    writeL_7(700);
    writeL_7(875);

    // word: E
    write_7_1(1050, 50, 650, 200, 1.0);
    write_7_1(1050, 125, 650, 50, 1.0);
    write_7_1(1050, 125, 725, 50, 1.0);
    write_7_1(1050, 125, 800, 50, 1.0);

    // word: R
    write_7_1(1225, 50, 650, 200, 1.0);
    write_7_1(1225, 125, 725, 50, 1.0);
    write_7_1(1225, 125, 800, 50, 1.0);
    write_7_1(1310, 45, 725, 125, 1.0);

    glBegin(GL_POLYGON);
    glVertex2i(1225 + 100, 650);
    glVertex2i(1225 + 160, 650);
    glVertex2i(1225 + 60, 750);
    glVertex2i(1225, 750);
    glEnd();

    // word: ?
    write_7_1(1405, 125, 800, 50, 1.0);
    write_7_1(1485, 45, 750, 100, 1.0);
    write_7_1(1460, 70, 740, 35, 1.0);
    write_7_1(1440, 40, 700, 75, 1.0);
    write_7_1(1440, 40, 650, 30, 1.0);
}

void display_7(void) {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);

    // black bg
    write_7_1(0, 1930, 0, 1200, 0.0);

    //set the ellipse to blue
    drawBlueBG_7();

    //draw KILLER?
    drawWords_7();

    //draw among us
    drawAmongUs(525, 370, 0, 0, 230, 180, 193, 226, 143, 173, 1, 1);    //pink
    drawAmongUs(710, 370, 0, 0, 112, 155, 107, 84, 113, 59, 1, 1);    //green
    drawAmongUs(895, 370, 0, 0, 242, 219, 39, 242, 188, 34, 1, 1);    //yellow
    drawAmongUs(1080, 370, 0, 0, 167, 27, 20, 91, 15, 8, 1, 1);        //red
    drawAmongUs(1270, 370, 0, 0, 190, 76, 20, 136, 57, 16, 1, 1);    //brown

    /* flush GL buffers */
    glFlush();
    glutSwapBuffers();
}

void timer(int value) {
    switch (value) {
        case 0: //Scene3(Kek) display
            glutPostRedisplay();
            glutTimerFunc(1000 / 30, timer, 0);
            walkXs3 += dxS3;
            walkYs3 += dyS3;

            break;
        case 1://Scene4(Ivan) display
            glutPostRedisplay();
            glutTimerFunc(1000 / 30, timer, 1);
            //C
            walkXs4c += dxS4c;
            walkYs4c += dyS4c;

            //A
            walkXs4a += dxS4a;
            walkYs4a += dyS4a;

            if (walkXs4a >= 2350 - 220) {
                dyS4a = 7;
                walkYs4a += dyS4a;
            }

            //B
            walkXs4b += dxS4b;
            walkYs4b += dyS4b;

            if (walkXs4b >= 2350 - 220) {
                dyS4b = -7;
                walkYs4b += dyS4b;
            }
            break;

        case 3: //Infront 2 guy walk out (SOOHAO)
            glutPostRedisplay();
            glutTimerFunc(1000 / 30, timer, 3);
            if (walkXs6 < 4000) {
                walkXs6 += dxs6;
                walkYs6 += dys6;
            } else {
                walkXs6 += 0;
                walkYs6 += 0;
            }
            break;

        case 4: //Behind 3 guys walk out
            glutPostRedisplay();
            glutTimerFunc(1000 / 30, timer, 4);

            dxs6 = 35;
            if (walkX3s6 < 1800) {
                walkX3s6 += dxs6;
                walkX3s6 += dys6;
            } else {
                walkX3s6 += 0;
                walkX3s6 += 0;
            }
            break;
        case 5: //among us walk in (JOEY)
            glutPostRedisplay();
            glutTimerFunc(1000 / 30, timer, 5);
            if (walkX_2 < 2400) {
                walkX_2 += dx_2;
                walkY_2 += dy_2;
            } else {
                walkX_2 += 0;
                walkY_2 += 0;
            }

            if (walkX_late_2 < 5000) {
                walkX_late_2 += dx_2;
                walkY_late_2 += dy_2;
            } else {
                walkX_late_2 += 0;
                walkY_late_2 += 0;
            }

            if (walkY_big_2 < 2100) {
                if (direction == 1) {
                    walkY_big_2 += dy_big_2;
                } else {
                    walkY_big_2 -= dy_big_2;
                }
            } else if (walkY_big_2 == 2100) {
                walkY_big_2 += 0.1;
            } else {
                direction = 0;
                walkY_big_2 -= dy_big_2;
            }
            break;

        case 6: //Among us Appear
            glutPostRedisplay();
            glutTimerFunc(1000 / 30, timer, 6);
            if (walkY_big_2 < 2100) {
                if (direction == 1) {
                    walkY_big_2 += dy_big_2;
                } else {
                    walkY_big_2 -= dy_big_2;
                }
            } else if (walkY_big_2 == 2100) {
                walkY_big_2 += 0.1;
            } else {
                direction = 0;
                walkY_big_2 -= dy_big_2;
            }
            break;

        case 7: //first bubble
            visibleS2_1 = true;
            glutPostRedisplay();
            glutTimerFunc(2000, timer, 8);
            break;

        case 8:
            visibleS2_1 = false;
            glutTimerFunc(6200, timer, 9);
            break;

        case 9: //second bubble
            glutPostRedisplay();
            glutTimerFunc(2000, timer, 10);
            visibleS2_2 = true;
            break;

        case 10:
            visibleS2_2 = false;
            break;

        case 11://Animation pop up (LIYI)
            visibleS1_1 = true;
            glutPostRedisplay();
            glutTimerFunc(1000, timer, 12);
            break;

        case 12:
            visibleS1_2 = true;
            visibleS1_1 = false;
            glutPostRedisplay();
            glutTimerFunc(3500, timer, 12);
            break;

        case 13: // Among Us Walk In (EVE)
            glutPostRedisplay();
            glutTimerFunc(1000 / 30, timer, 13);
            if (walkX_S5 < 2400) {
                walkX_S5 += dx_S5;
                walkY_S5 += dy_S5;
            } else {
                walkX_S5 += 0;
                walkY_S5 += 0;
            }
            break;
        case 14:
            visibleS5_1 = true;
            glutPostRedisplay();
            glutTimerFunc(1000, timer, 15);
            break;
        case 15:
            visibleS5_1 = false;
            visibleS5_2 = true;
            glutPostRedisplay();
            glutTimerFunc(1000, timer, 16);
            break;
        case 16:
            visibleS5_2 = false;
            visibleS5_3 = true;
            glutPostRedisplay();
            glutTimerFunc(1000, timer, 17);
            break;
        case 17:
            visibleS5_3 = false;
            glutPostRedisplay();
            glutTimerFunc(1000 / 30, timer, 17);
            walkX_S5 += dx_S5;
            walkY_S5 += dy_S5;
            break;
        default:
            break;
    }
}

void switchDisplay(int value) {
    if (value == 1) //Display Scene 1
    {
        glutDisplayFunc(display_1);
        glutTimerFunc(3000, switchDisplay, 2); //6second
    } else if (value == 2) //Display Scene 1.1
    {
        glutDisplayFunc(display_1);
        glutTimerFunc(1, timer, 11);
        glutTimerFunc(2000, switchDisplay, 3);       //6second
    } else if (value == 3)   //Display Scene 2
    {
        glutDisplayFunc(display2);
        glutTimerFunc(1, timer, 5);
        glutTimerFunc(6200, switchDisplay, 4);       //11second
    } else if (value == 4)   //Display Scene 2.1
    {
        glutDisplayFunc(display2);
        glutTimerFunc(0, timer, 7);
        glutTimerFunc(1, timer, 6);
        glutTimerFunc(10000, switchDisplay, 5);
    } else if (value == 5) {
        glutDisplayFunc(display3);
        glutTimerFunc(1, timer, 0);
        glutTimerFunc(6500, switchDisplay, 6); //9second
    } else if (value == 6) {
        glutDisplayFunc(display4);
        glutTimerFunc(1, timer, 1);
        glutTimerFunc(9500, switchDisplay, 7);
    } else if (value == 7) {
        glutDisplayFunc(display5);
        glutTimerFunc(0, timer, 13);
        glutTimerFunc(8000, switchDisplay, 8);
    } else if (value == 8) {
        glutDisplayFunc(display5);
        glutTimerFunc(1, timer, 14);
        glutTimerFunc(14000, switchDisplay, 9);
    } else if (value == 9) {
        glutDisplayFunc(displays6);
        glutTimerFunc(1, timer, 3);
        glutTimerFunc(15000, switchDisplay, 10);
    } else if (value == 10) {
        glutDisplayFunc(displayBubbles6);
        glutTimerFunc(6000, switchDisplay, 11);
    } else if (value == 11) {
        glutDisplayFunc(display3AmongUsWalks6);
        glutTimerFunc(1, timer, 4);
        glutTimerFunc(11000, switchDisplay, 12);
    } else if (value == 12) {
        glutDisplayFunc(displayBubble3s6);
        glutTimerFunc(1000, switchDisplay, 13);
    } else if (value == 13) {
        glutDisplayFunc(display_7);
        glutTimerFunc(5000, switchDisplay, 14);
    }
}


int main(int argc, char **argv) {
    /* Initialize mode and open a window in upper left corner of screen */
    /* Window title is name of program (arg[0]) */

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("KT34303 Computer Graphics Project Development 1");
    glutDisplayFunc(display_1);
    glutTimerFunc(0, timer, -1);
    glutTimerFunc(0, switchDisplay, 1);

    init();
    glutMainLoop();
}