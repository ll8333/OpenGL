#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>

class Widget : public QGLWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void initTexture();

protected:
    void initializeGL();
    void paintGL();
private:

};

#endif // WIDGET_H
