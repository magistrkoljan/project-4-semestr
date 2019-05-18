#ifndef SCENE3D_H
#define SCENE3D_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "tetgen.h"
#include "grav_calc.h"

class Scene3D : public QOpenGLWidget, protected QOpenGLFunctions
{
    private:

    GLfloat xRot;
    GLfloat yRot;
    GLfloat zRot;
    GLfloat zTra;
    GLfloat nSca;
    GLfloat R;

    tetgenio in, out;
    tetgenbehavior behavior;
    std::ifstream fin;

    struct Arrow
    {
        GLfloat x1 = 1.0;
        GLfloat y1 = 1.0;
        GLfloat z1 = 1.0;

        GLfloat x2 = 0.8;
        GLfloat y2 = 0.8;
        GLfloat z2 = 0.8;
    };
    Arrow grav_Arrow;

    QPoint ptrMousePosition;
    
    void scale_plus();
    void scale_minus();
    void rotate_up();
    void rotate_down();
    void rotate_left();
    void rotate_right();
    void translate_down();
    void translate_up();

    void drawArrow();
    void drawAxis();
    void defaultScene();
    void my_getArrays();
    void drawFigure();
    void CalcPoint();

protected:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);

    void keyPressEvent(QKeyEvent* pe);
    void mousePressEvent(QMouseEvent* pe);
    void wheelEvent(QWheelEvent* pe);
    void mouseMoveEvent(QMouseEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);


   public:
      Scene3D(QWidget* parent = 0);
      int flag_arr, flag_pnt, flag_ans;
      REAL p[3], v[3];
      void paintGL();
};
#endif
