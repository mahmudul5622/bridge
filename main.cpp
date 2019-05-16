#include <windows.h>
#include <GL/glut.h>
float p,l1=0.0,l2=0.0,s,q=0.0,c1=0.0,c2=0.0,x=0.0,w=0.0,y,m;
GLfloat angle=45.0;
int speed=30,t=0;


void initialization()
{
    glClearColor(1,1,1,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-55.0,55.0,-60.0,60.0,-50.0,50.0);
}
void sea()
{
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.50,1.0);
    glVertex2f(-55.0,60.0);
    glVertex2f(55.0,60.0);
    glVertex2f(55.0,-60.0);
    glVertex2f(-55.0,-60.0);
	glEnd();

}
void water()
{
    	glPushMatrix();
  glTranslatef(0,w,0);

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_LINES);
        for(p=0;p<1000;p=p+5)
            for(s=0;s<1000;s=s+2)
                glVertex2f(-55.0+s,-60.0+p);
                glVertex2f(-50.0+s,-60.0+p);
        glEnd();
        glPopMatrix();
}

void bridge()
{
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
        glVertex2d(25.0,-5.0);
        glVertex2d(25.0,20.0); //bridge right side
        glVertex2d(60.0,20.0);
        glVertex2d(60.0,-5.0);
    glEnd();

        glColor3f(0.3,0.3,0.3);
        glBegin(GL_POLYGON);
            glVertex2d(39.0,-13.0);
            glVertex2d(35.0,-5.0); //bridge pilar right side
            glVertex2d(50.0,-5.0);
            glVertex2d(46.0,-13.0);
            glVertex2d(46.0,-20.0);
            glVertex2d(39.0,-20.0);
        glEnd();

            glColor3f(0.5,0.5,0.5);
            glBegin(GL_QUADS);
                glVertex2d(-25.0,-5.0);
                glVertex2d(-25.0,20.0); //bridge left side
                glVertex2d(-60.0,20.0);
                glVertex2d(-60.0,-5.0);
            glEnd();

                glColor3f(0.3,0.3,0.3);
                glBegin(GL_POLYGON);
                    glVertex2d(-39.0,-13.0);
                    glVertex2d(-35.0,-5.0); //bridge pilar left side
                    glVertex2d(-50.0,-5.0);
                    glVertex2d(-46.0,-13.0);
                    glVertex2d(-46.0,-20.0);
                    glVertex2d(-39.0,-20.0);
                glEnd();
}

void bridge_lift_tools()
{
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(0.0+l1,-5.0+l2);
        glVertex2d(25.0,-5.0); //bridge lift part 1 right
        glVertex2d(25.0,20.0);
        glVertex2d(0.0+l1,20.0+l2);
    glEnd();


        glColor3f(0.5,0.5,0.5);
        glBegin(GL_POLYGON);
            glVertex2d(0.0-l1,-5.0+l2);
            glVertex2d(0.0-l1,20.0+l2);
            glVertex2d(-25.0,20.0); //bridge lift part 2 left
            glVertex2d(-25.0,-5.0);
        glEnd();
}

void bridge_lines()
{

                    glColor3f(1.0,1.0,0.0);
                    glBegin(GL_QUADS);
                        glVertex2d(25.0,-4.0);
                        glVertex2d(60.0,-4.0);
                        glLineWidth(8);
                        glVertex2d(60.0,-3.0); //bridge yellow line front right side
                        glVertex2d(25.0,-3.0);
                    glEnd();

                        glBegin(GL_QUADS);
                        glColor3f(1.0,1.0,0.0);
                        glVertex2d(-25.0,-4.0);
                        glVertex2d(-60.0,-4.0);
                        glVertex2d(-60.0,-3.0); //bridge yellow line front left side
                        glVertex2d(-25.0,-3.0);
                    glEnd();

                        glColor3f(1.0,1.0,0.0);
                        glBegin(GL_QUADS);
                            glVertex2d(25.0,19.0);
                            glVertex2d(60.0,19.0);
                            glVertex2d(60.0,18.5); //bridge yellow line back right side
                            glVertex2d(25.0,18.5);
                        glEnd();

                        glColor3f(1.0,1.0,0.0);
                        glBegin(GL_QUADS);
                            glVertex2d(-25.0,19.0);
                            glVertex2d(-60.0,19.0);
                            glVertex2d(-60.0,18.5); //bridge yellow line back right side
                            glVertex2d(-25.0,18.5);
                        glEnd();

                            for(m=0;m<40;m+=5)
                            {
                                glColor3f(1.0,1.0,1.0);
                                glBegin(GL_QUADS);
                                    glVertex2d(27.0+m,7.0);
                                    glVertex2d(30.0+m,7.0);
                                    glVertex2d(30.0+m,8.0); //bridge middle white line right
                                    glVertex2d(27.0+m,8.0);
                                glEnd();
                            }

                            for(m=0;m<40;m+=5)
                            {
                                glColor3f(1.0,1.0,1.0);
                                glBegin(GL_QUADS);
                                    glVertex2d(-27.0-m,7.0);
                                    glVertex2d(-30.0-m,7.0);
                                    glVertex2d(-30.0-m,8.0); //bridge middle white line right
                                    glVertex2d(-27.0-m,8.0);
                                glEnd();
                            }
                      /*  glColor3f(0.0,0.0,0.0);
                        glBegin(GL_QUADS);
                            glVertex2d(-60.0,-6.0);
                            glVertex2d(60.0,-6.0);
                            glVertex2d(60.0,-5.0); //bridge middle white line right
                            glVertex2d(-60.0,-5.0);
                        glEnd(); */
}

void bridge_up_pilar()
{
    glPushMatrix();
                glColor3f(0.0,0.0,0.0);
            glBegin(GL_QUADS);
                glVertex2d(52.0,-5.0);
                glVertex2d(53.0,-5.0);
                glVertex2d(53.0,45.0); //bridge up pilar 1 right
                glVertex2d(52.0,45.0);
            glEnd();

                glColor3f(0.0,0.0,0.0);
                glBegin(GL_QUADS);
                    glVertex2d(50.0,20.0);
                    glVertex2d(51.0,20.0);
                    glVertex2d(51.0,55.0); //bridge up pilar 2 left
                    glVertex2d(50.0,55.0);
                glEnd();

                    glColor3f(0.0,0.0,0.0);
                    glBegin(GL_QUADS);
                        glVertex2d(-52.0,-5.0);
                        glVertex2d(-53.0,-5.0);
                        glVertex2d(-53.0,45.0); //bridge up pilar 1 left
                        glVertex2d(-52.0,45.0);
                    glEnd();

                        glColor3f(0.0,0.0,0.0);
                        glBegin(GL_QUADS);
                            glVertex2d(-50.0,20.0);
                            glVertex2d(-51.0,20.0);
                            glVertex2d(-51.0,55.0); //bridge up pilar 2 left
                            glVertex2d(-50.0,55.0);
                        glEnd();
glLineWidth(2);
                        glColor3f(0.0,0.0,0.0);
                            glBegin(GL_LINES);
                                glVertex2d(52.0,45.0);
                                glVertex2d(0.5+l1,-5.0+l2);
                                glVertex2d(52.0,44.5); //bridge rope 1 right
                                glVertex2d(1.0+l1,-5.0+l2);
                            glEnd();

                                glColor3f(0.0,0.0,0.0);
                                glBegin(GL_LINES);
                                    glVertex2d(51.0,55.0);
                                    glVertex2d(0.5+l1,19.0+l2);
                                    glVertex2d(51.0,54.5); //bridge rope 2 right
                                    glVertex2d(1.0+l1,19.0+l2);
                                glEnd();

                            glColor3f(0.0,0.0,0.0);
                            glBegin(GL_LINES);
                                glVertex2d(-52.0,45.0);
                                glVertex2d(-0.5-l1,-5.0+l2);
                                glVertex2d(-52.0,44.5); //bridge rope 1 left
                                glVertex2d(-1.0-l1,-5.0+l2);
                            glEnd();

                        glColor3f(0.0,0.0,0.0);
                        glBegin(GL_LINES);
                            glVertex2d(-51.0,55.0);
                            glVertex2d(-0.5-l1,19.0+l2);
                            glVertex2d(-51.0,54.5); //bridge rope 2 left
                            glVertex2d(-1.0-l1,19.0+l2);
                        glEnd();
glPopMatrix();
}

void boat()
{
    glPushMatrix();
glTranslatef(0,q,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.8,0.0);
        glVertex2d(0.0, -40.0);
        glVertex2d(5.0,-49.0);
        glVertex2d(9.0,-66.0);
        glVertex2d(10.0,-76.0);
        glVertex2d(9.0,-86.0);   // boat body
        //glVertex2d(6.0,-83.0);
        glVertex2d(0.0,-105.0);
        //glVertex2d(-6.0,-83.0);
        glVertex2d(-9.0,-86.0);
        glVertex2d(-10.0,-76.0);
        glVertex2d(-9.0,-66.0);
        glVertex2d(-5.0,-49.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(0.0, -105.0);
        glVertex2d(9.0, -86.0);
        glVertex2d(0.0,-110.0);
        glVertex2d(-9.0,-86.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(0.0, -40.0);
        glVertex2d(4.0,-50.0);
        glVertex2d(8.0,-66.0);
        glVertex2d(9.0,-76.0);
        glVertex2d(8.0,-86.0);   // boat border line strip
        //glVertex2d(6.0,-83.0);
        glVertex2d(0.0,-104.0);
        //glVertex2d(-6.0,-83.0);
        glVertex2d(-8.0,-86.0);
        glVertex2d(-9.0,-76.0);
        glVertex2d(-8.0,-66.0);
        glVertex2d(-4.0,-50.0);
        glVertex2d(0.0, -40.0);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(4.0,-50.0);
        glVertex2d(5.0,-49.0);

        glVertex2d(8.0,-66.0);
        glVertex2d(9.0,-66.0);

        glVertex2d(9.0,-76.0);
        glVertex2d(10.0,-76.0);

        glVertex2d(8.0,-86.0);   // boat border lines
        glVertex2d(9.0,-86.0);

        glVertex2d(0.0,-104.0);
        glVertex2d(0.0,-105.0);

        glVertex2d(-8.0,-86.0);
        glVertex2d(-9.0,-86.0);

        glVertex2d(-9.0,-76.0);
        glVertex2d(-10.0,-76.0);

        glVertex2d(-8.0,-66.0);
        glVertex2d(-9.0,-66.0);

        glVertex2d(-4.0,-50.0);
        glVertex2d(-5.0,-49.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(3.0, -55.0);
        glVertex2d(3.0,-75.0); // boat middle box 1 black
        glVertex2d(-3.0,-75.0);
        glVertex2d(-3.0,-55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.8,0.0);
        glVertex2d(-1.0, -70.0);
        glVertex2d(-1.0,-69.0); // boat middle box 2 yellow
        glVertex2d(2.0,-69.0);
        glVertex2d(2.0,-75.0);
        glVertex2d(-2.0,-75.0);
        glVertex2d(-2.0,-70.0);
    glEnd();

    glPopMatrix();
    glPushMatrix();
}

void car1()
{
    glPushMatrix();
    glTranslated(-c1,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(59.0,4.0);
        glVertex2d(68.0,4.0);
        glVertex2d(68.0,15.0); //car base black
        glVertex2d(59.0,15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
        glVertex2d(60.0,4.5);
        glVertex2d(67.5,4.5);
        glVertex2d(67.5,15.5); //car base 2 red
        glVertex2d(60.0,15.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(60.5,4.8);
        glVertex2d(69.0,4.8);
        glVertex2d(69.0,15.9); //car base 3 black
        glVertex2d(60.5,15.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
        glVertex2d(60.7,5.2);
        glVertex2d(69.0,5.2);
        glVertex2d(69.0,15.9); //car base 4 black
        glVertex2d(60.7,15.9);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(62.0,8.0);
        glVertex2d(62.0,12.0);
        glVertex2d(64.0,12.0);
        glVertex2d(64.0,8.0);
        glVertex2d(66.0,8.0);
        glVertex2d(66.0,12.0);
        glVertex2d(68.0,12.0);
        glVertex2d(68.0,8.0);
        glVertex2d(66.0,8.0); //car up line black
        glVertex2d(66.0,12.0);
        glVertex2d(64.0,12.0);
        glVertex2d(64.0,8.0);
        glVertex2d(62.0,8.0);
    glEnd();
    glPopMatrix();
}

void car2()
{
    glPushMatrix();
    glTranslated(-c2,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(49.0,4.0);
        glVertex2d(58.0,4.0);
        glVertex2d(58.0,15.0); //car base black
        glVertex2d(49.0,15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
        glVertex2d(50.0,4.5);
        glVertex2d(57.5,4.5);
        glVertex2d(57.5,15.5); //car base 2 red
        glVertex2d(50.0,15.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(50.5,4.8);
        glVertex2d(59.0,4.8);
        glVertex2d(59.0,15.9); //car base 3 black
        glVertex2d(50.5,15.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
        glVertex2d(50.7,5.2);
        glVertex2d(59.0,5.2);
        glVertex2d(59.0,15.9); //car base 4 black
        glVertex2d(50.7,15.9);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
        glVertex2d(52.0,8.0);
        glVertex2d(52.0,12.0);
        glVertex2d(54.0,12.0);
        glVertex2d(54.0,8.0);
        glVertex2d(56.0,8.0);
        glVertex2d(56.0,12.0);
        glVertex2d(58.0,12.0);
        glVertex2d(58.0,8.0);
        glVertex2d(56.0,8.0); //car up line black
        glVertex2d(56.0,12.0);
        glVertex2d(54.0,12.0);
        glVertex2d(54.0,8.0);
        glVertex2d(52.0,8.0);
    glEnd();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    sea();
    glPopMatrix();

    glPushMatrix();
    water();
    glPopMatrix();

        glPushMatrix();
        bridge();
        glPopMatrix();

            glPushMatrix();
            bridge_lift_tools();
            glPopMatrix();

                glPushMatrix();
                boat();
                glPopMatrix();

                    glPushMatrix();
                    bridge_lines();
                    glPopMatrix();

            glPushMatrix();
            car1();
            glPopMatrix();

            glPushMatrix();
            car2();
            glPopMatrix();

        glPushMatrix();
        bridge_up_pilar();
        glPopMatrix();

glFlush();
}
void animate()
{
    if(x>10 && x<14)
    {
        c1+=0;     // (c1) red car speed increment
        c2+=0.03;   // (c2) blue car speed increment
        l1+=0.008;    // (l1,l2) lift over bridge part speed increment
        l2+=0.008;
        q+=0.01;     // (q) boat speed increment
        x+=0.003;           // (x) is auto increment
        w-=0.009;  // (w) is auto increment
    }
    else if(x>=14 && x<35)
    {
        l1+=0;
        l2+=0;
        q+=0.01;
        x+=0.003;
        c2+=0.03;
        w-=0.009;
    }
    else if(x>=35 && x<39)
    {
        l1-=0.008;
        l2-=0.008;
        q+=0.01;
        x+=0.003;
        w-=0.009;
    }
    else if(x>=39 && x<54)
    {
        l1-=0;
        l2-=0;
        q+=0.01;
        x+=0.003;
        c1+=0.03;
        w-=0.009;
    }
    else if(x>=54)
    {
        x=0;
        c1=0;
        c2=0;
        q=0;
        l1=0;
        l2=0;
        w=0;
    }

    else
    {
        c1+=0.01;
        c2+=0.03;
        x+=0.003;
        q+=0.01;
        w-=0.009;
    }

        glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("London Bridge by Adullah Al munsur, A.T.M Bodrujjaman, Abu Baker, Tasnim Zaman, Mahmudul Hasan");
    initialization();
    glutDisplayFunc(display);
    glutIdleFunc(animate);



    //timer(0);
    glutMainLoop();
    return 0;
}
