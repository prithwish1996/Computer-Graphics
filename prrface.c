#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
//int a,b,c,d,ww;
void init()
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-1000,1000,-1000,1000);
}
void setpixel(float x, float y)
{
  glBegin(GL_POINTS);
  glVertex2f(x,y);
  glEnd();
  //glFlush();
}
void setpixel1(double x,double y)
{
  glBegin(GL_POINTS);
  glVertex2d(x,y);
  // glVertex2f(-x,y);
  // glVertex2f(x,-y);
  // glVertex2f(-x,-y);
  // glVertex2f(y,x);
  // glVertex2f(-y,x);
  // glVertex2f(y,-x);
  // glVertex2f(-y,-x);
  glEnd();
  glFlush();
}
void line(int x1,int x2, int y1, int y2, int w)
{
  int x0,xend,dy,dx,p;
  float xx,yy,theta;

  if(x1>x2)
  {
    x0 = x2;
    xend = x1;
  }
  else
  {
    x0 = x1;
    xend = x2;
}
theta = (3.14/180)*w;
xx = x0*cos(theta) - y1*sin(theta);
yy = x0*sin(theta) + y1*cos(theta);
dx = (xend-x0);
dy = (y2 - y1);
p = (2*dy) - dx;
//setpixel(x0,y1);
setpixel(xx,yy);
while(x0<=xend)
{//printf("%d\n",y1);
  ++x0;
  if(p<0)
  p = p + (2*dy);
  else
  {
    ++y1;
     p = p + (2*(dy-dx));
  }
  xx = x0*cos(theta) - y1*sin(theta);
  yy = x0*sin(theta) + y1*cos(theta);
  //setpixel(x0,y1);
  setpixel(xx,yy);
}
glFlush();
}
void circlePara(double rr,double aa, double bb)
{
  int v;
  double x, y;
  double theta, pi=3.14;
  for(v=0; v<=45; v++)
  {
    //setpixel(x,y);
    theta = ((pi)/180)*v;
    x = (rr*cos(theta));
    y = (rr*sin(theta));
    setpixel1(x+aa,y+bb);
    setpixel1(-x+aa,y+bb);
    setpixel1((x+aa),-y+bb);
    setpixel1(-x+aa,-y+bb);
    setpixel1(y+aa,x+bb);
    setpixel1(-y+aa,x+bb);
    setpixel1((y+aa),-x+bb);
    setpixel1(-y+aa,-x+bb);

  }
}
void Disp()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,1.0,0.5);
  glPointSize(4.0);
  line(0,150,0,0,270);
  circlePara(800,0,0);
  circlePara(200, -370,370);
  circlePara(200, 370,370);
  circlePara(100,0,-370);


}
void main(int argc, char** argv)
{
  //printf("Enter x1,x2 & y1,y2 & theta");
  //scanf("%d %d %d %d %d", &a, &b,&c,&d,&ww);
  glutInit(&argc, argv);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Bresenham's Line Drawing");
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  init();
  glutDisplayFunc(Disp);
  glutMainLoop();



}
