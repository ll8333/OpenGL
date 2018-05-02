//#include "GL/glew.h"
#include "widget.h"
GLuint vShader = 0;
GLuint fShader = 0;
GLuint glsl=0;
GLint linked;

GLfloat vertices[] = {
    0.5f, 0.5f, 0.0f,   // 右上角
    0.5f, -0.5f, 0.0f,  // 右下角
    -0.5f, -0.5f, 0.0f, // 左下角
    -0.5f, 0.5f, 0.0f   // 左上角
};

GLuint indices[] = { // 注意索引从0开始!
    0, 1, 3, // 第一个三角形
    1, 2, 3  // 第二个三角形
};


Widget::Widget(QWidget *parent)
    : QGLWidget(parent)
{
}

Widget::~Widget()
{
    
}

void Widget::initializeGL()
{
//    glewInit();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    initTexture();
}

void Widget::initTexture()
{
    GLchar const *vShaderStr =
            "attribute vec4 vPosition;    \n"
            "void main()                  \n"
            "{                            \n"
            "   gl_Position = vPosition;  \n"
            "}                            \n";

    GLchar const *fShaderStr =
            "precision mediump float;\n"\
            "void main()                                  \n"
            "{                                            \n"
            "  gl_FragColor = vec4 ( 1.0, 0.3, 0.0, 1.0 );\n"
            "}                                            \n";

    glsl = glCreateProgram();
    vShader = glCreateShader(GL_VERTEX_SHADER);
    fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vShader, 1,&vShaderStr, NULL);
    glCompileShader(vShader);
    glShaderSource(fShader, 1,&fShaderStr, NULL);
    glCompileShader(fShader);
    glAttachShader(glsl,vShader);
    glAttachShader(glsl,fShader);
    glLinkProgram(glsl);

}


void Widget::paintGL()
{
    glUseProgram(glsl);

    glVertexAttribPointer (0,3,GL_FLOAT,GL_FALSE,0,vertices);
    glEnableVertexAttribArray (0);

    glDrawArrays(GL_TRIANGLES,0,3);

    glDeleteShader(vShader);
    glDeleteShader(fShader);
    glUseProgram(0);
}
