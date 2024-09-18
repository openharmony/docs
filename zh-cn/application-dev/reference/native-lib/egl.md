
# EGL

EGL 是Khronos渲染API (如OpenGL ES 或 OpenVG) 与底层原生窗口系统之间的接口。OpenHarmony 现已支持 EGL。

## 引入EGL能力

如果开发者需要使用EGL相关功能，首先请添加头文件：

```cpp
#include <EGL/egl.h>
```

其次在CMakeLists.txt中添加以下动态链接库：

```
libEGL.so
```

如果需要调用EGL扩展接口，需要额外添加头文件并且在CMakeLists.txt中添加宏定义：
```
#include <EGL/eglext.h>
EGL_EGLEXT_PROTOTYPES
```

## 支持的接口说明

OpenHarmony目前支持EGL部分接口，支持的接口会随着版本演进，持续更新。

目前支持的接口如下：

[native api中导出的EGL符号列表](egl-symbol.md)

