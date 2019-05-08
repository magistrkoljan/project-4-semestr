#ifndef SCENE3D_H
#define SCENE3D_H

#include <QGLWidget>

class Scene3D : public QGLWidget
{
    private:

    GLfloat xRot;
    GLfloat yRot;
    GLfloat zRot;
    GLfloat zTra;
    GLfloat nSca;

    void drawAxis();
    void defaultScene();
    void my_getArrays();
    void drawFigure();

    void rotate_up();
    void rotate_down();
    void rotate_left();
    void rotate_right();

protected:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void keyPressEvent(QKeyEvent* pe);

   public:
      Scene3D(QWidget* parent = 0);
};
#endif
