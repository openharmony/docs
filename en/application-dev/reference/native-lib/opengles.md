# OpenGL ES

OpenGL is a cross-platform software interface for 3D graphics processing. [OpenGL ES](https://www.khronos.org/opengles/) is a OpenGL specification for embedded devices. OpenHarmony supports OpenGL ES 3.2.

## Supported Capabilities

OpenGL ES 3.2

## Symbols Exported from the Standard Library

[OpenGL ES 3.2 Symbols Exported from Native APIs](openglesv3-symbol.md)

## OpenGL ES Extended APIs

- To obtain the official reference document for OpenGL ES extended APIs, visit [Khronos OpenGL ES Registry](https://registry.khronos.org/OpenGL/index_es.php).
- You can call **glGetString** to query the extended APIs supported by the chip. Before calling **glGetString**, you must initialize the context. The following is an example:

``` Language: C++
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
strTest = (char *)glGetString(GL_EXTENSIONS); // The return value of strTest lists all extended APIs, separated by spaces.
bool isHave = strTest.find("GL_OES_matrix_palette") != -1 ?
    true :
    false; // Check whether an extended API exists. If yes, the value of isHave is true. If no, the value of isHave is false.
```
