# OpenGL ES

OpenGL 是一种跨平台的图形 API，用于为 3D 图形处理硬件指定标准的软件接口。[OpenGL ES](https://www.khronos.org/opengles/) 是 OpenGL 规范的一种形式，适用于嵌入式设备。OpenHarmony 现已支持 OpenGL ES 3.2。

## 支持的能力

OpenGL ES 3.2

## 标准库中导出的符号列表

[native api中导出的OpenGL ES 3.2符号列表](openglesv3-symbol.md)

## OpenGL ES扩展接口

- OpenGL ES扩展接口的官方参考文档：[OpenGL ES扩展接口](https://registry.khronos.org/OpenGL/index_es.php)
- 开发者可以调用`glGetString`查询芯片厂商支持的扩展接口，调用之前务必初始化上下文,具体示例如下：

``` 语言：c++
EGLDisplay display;
EGLConfig config;
EGLContext context;
EGLSurface surface;
EGLint majorVersion;
EGLint minorVersion;
EGLNativeWindowType win;
display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
eglInitialize(display, &majorVersion, &minorVersion);
display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
eglInitialize(display, &majorVersion, &minorVersion);
EGLint attribs[] = {
    EGL_RENDERABLE_TYPE,
    EGL_OPENGL_ES2_BIT,
    EGL_BLUE_SIZE, 8,
    EGL_GREEN_SIZE, 8,
    EGL_RED_SIZE, 8,
    EGL_NONE
};
eglChooseConfig(display, attribs, &config, 1, &numConfigs);
context = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);
surface = eglCreatePbufferSurface(display, config, NULL);
eglMakeCurrent(display, surface, surface, context);

char *strTest = new char[1024];
strTest = (char *)glGetString(GL_EXTENSIONS); // 返回值strTest中会列出所有的扩展接口，并且用空格分隔开
bool isHave = strTest.find("GL_OES_matrix_palette") != -1 ?
    true :
    false; // 查询是否有某个扩展接口，有则isHave为true，没有则为false
```