# OpenGL

[OpenGL](https://www.khronos.org/opengl/)是一种跨平台的图形API，用于为3D图形处理硬件指定标准的软件接口。OpenHarmony现已支持OpenGL 3.0。

## 支持的能力

从API version 20开始，支持使用OpenGL 3.0。

## 标准库中导出的符号列表

[native api中导出的OpenGL 3.0符号列表](opengl-symbol.md)

## OpenGL扩展接口及示例

OpenGL扩展接口及使用，可参考[OpenGL ES扩展接口](opengles.md#opengl-es扩展接口)。

相关接口使用示例，可参考[OpenGL ES简单示例](opengles.md#简单示例)。

## 引入OpenGL能力

如果开发者需要使用OpenGL的相关能力，需要添加相关动态链接库和头文件。

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
libace_ndk.z.so
libace_napi.z.so
libGLv4.so
libEGL.so
```

**头文件**

```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>
#include <GL/gl.h>
#include <GL/glcorearb.h>
```
**修改app.json5配置文件**
```c++
“appEnvironments”: [
 {
   "name":"NEED_OPENGL",
   "value": "1"
 }
],
```


## 相关参考

针对OpenGL的使用和相关开发，需要同步了解NDK的开发过程，以及XComponent组件等的使用。具体可参考:

- [NDK开发参考](../../napi/ndk-development-overview.md)

- [NodeAPI参考](./napi.md)

- [XComponentNode参考](../apis-arkui/js-apis-arkui-xcomponentNode.md)

- [XComponent参考](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)