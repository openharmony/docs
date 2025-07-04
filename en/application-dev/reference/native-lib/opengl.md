# OpenGL

[OpenGL](https://www.khronos.org/opengl/) is a cross-platform graphics API that specifies a standard software interface for 3D graphics processing hardware. OpenHarmony supports OpenGL 3.0.

## Supported Capabilities

OpenGL 3.0

## Symbols Exported from the Standard Library

[OpenGL 3.0 Symbols Exported from Native APIs](opengl-symbol.md)

## OpenGL Extensions and Examples

For details about the OpenGL extensions and their usage, see [OpenGL ES Extensions](opengles.md#opengl-es-extensions).

For details about how to use these extensions, see [OpenGL ES Example](opengles.md#example).

## Introducing OpenGL

To use OpenGL capabilities, you must add related dynamic link libraries (DLLs) and header files.

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**.

```txt
libace_ndk.z.so
libace_napi.z.so
libGLv4.so
libEGL.so
```

**Including Header Files**

```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>
#include <GL/gl.h>
#include <GL/glcorearb.h>
```
**Modifying the app.json5 Configuration File**
```c++
"appEnvironments": [
 {
   "name":"NEED_OPENGL",
   "value": "1"
 }
],
```


## References

To use the OpenGL API in your application development, familiarize yourself with the NDK development process and the **XComponent** usage, which are described in the following topics:

- [Getting Started with the NDK](../../napi/ndk-development-overview.md)

- [Node-API](./napi.md)

- [XComponentNode](../apis-arkui/js-apis-arkui-xcomponentNode.md)

- [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)
