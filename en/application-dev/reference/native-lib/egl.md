# EGL

[EGL](https://registry.khronos.org/EGL/sdk/docs/man/) is an interface between Khronos rendering APIs (such as [OpenGLES](https://registry.khronos.org/OpenGL-Refpages/es3/) or OpenVG) and the underlying window system. OpenHarmony supports EGL.

## Introducing EGL

To use EGL capabilities, include the following header file:

```cpp
#include <EGL/egl.h>
```

Add the following dynamic link library to **CMakeLists.txt**:

```
libEGL.so
```

To call the EGL extended APIs, include the following header file and add the macro definition to **CMakeLists.txt**:
```
#include <EGL/eglext.h>
EGL_EGLEXT_PROTOTYPES
```

## Supported APIs

Currently, OpenHarmony supports the EGL APIs listed in the topic below. The supported APIs will be continuously updated as the version evolves.

 

[EGL Symbols Exported from Native APIs](egl-symbol.md)
