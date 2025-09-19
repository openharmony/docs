# OpenGL ES
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @samhu1989-->
<!--Designer: @shi-yang-2012-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->
OpenGL 是一种跨平台的图形 API，用于为 3D 图形处理硬件指定标准的软件接口。[OpenGL ES](https://www.khronos.org/opengles/) 是 OpenGL 规范的一种形式，适用于嵌入式设备。OpenHarmony 现已支持 OpenGL ES 3.2。

## 支持的能力

OpenGL ES 3.2

## 标准库中导出的符号列表

[native api中导出的OpenGL ES 3.2符号列表](openglesv3-symbol.md)

## 引入OpenGL能力

如果开发者需要使用OpenGL的相关能力，需要添加相关动态链接库和头文件。

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
libace_ndk.z.so
libace_napi.z.so
libGLESv3.so
libEGL.so
```

**头文件**

```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>
#include <GLES3/gl3.h>
```

## 相关参考

针对OpenGL ES的使用和相关开发，需要同步了解NDK的开发过程，以及XComponent组件等的使用。具体可参考:

- [NDK开发参考](../../napi/ndk-development-overview.md)

- [NodeAPI参考](./napi.md)

- [XComponentNode参考](../apis-arkui/js-apis-arkui-xcomponentNode.md)

- [XComponent参考](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)

## OpenGL ES扩展接口

- OpenGL ES扩展接口的官方参考文档：[OpenGL ES扩展接口](https://registry.khronos.org/OpenGL/index_es.php)
- 开发者可以调用`glGetString`查询芯片厂商支持的扩展接口，调用之前务必初始化上下文。具体示例如下：

```c++
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

## 简单示例

```cpp
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    // 初始化 EGL
    EGLDisplay display;
    EGLConfig config;
    EGLContext context;
    EGLSurface surface;
    EGLint numConfigs;
    EGLint majorVersion;
    EGLint minorVersion;

    // 初始化 EGL Display
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(display, &majorVersion, &minorVersion);

    // 配置 EGL
    EGLint attribs[] = {
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
        EGL_BLUE_SIZE, 6,
        EGL_GREEN_SIZE, 8,
        EGL_RED_SIZE, 8,
        EGL_NONE
    };
    eglChooseConfig(display, attribs, &config, 1, &numConfigs);

    // 创建 EGL Context
    EGLint contextAttribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 3,
        EGL_NONE
    };

    // 创建 EGL Surface
    surface = eglCreateWindowSurface(display, config, nativeWindow, NULL);

    context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs);

    // 绑定 EGL Context 和 Surface
    eglMakeCurrent(display, surface, surface, context);

    // 设置视口大小
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // 清除颜色缓冲
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 定义顶点数据
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,  // 左下角
         0.5f, -0.5f, 0.0f,  // 右下角
         0.0f,  0.5f, 0.0f   // 顶部
    };

    // 创建并绑定顶点缓冲对象
    GLuint VAO[0];
    GLuint VBO;
    glGenVertexArrays(1, VAO);
	glBindVertexArray(VAO[0]);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 创建着色器程序
    const char* vertexShaderSource = R"(
        #version 300 es
        precision mediump float;
        layout (location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 300 es
        precision mediump float;
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        }
    )";

    GLuint vertexShader, fragmentShader, shaderProgram;
    // 创建顶点着色器
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    // 创建片段着色器
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    // 创建着色器程序
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // 使用着色器程序
    glUseProgram(shaderProgram);

    // 绑定顶点数据
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // 绘制三角形
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // 交换缓冲区
    eglSwapBuffers(display, surface);

    // 清理
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteBuffers(1, &VBO);

    // 等待退出
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();

    // 清理 EGL
    eglDestroyContext(display, context);
    eglDestroySurface(display, surface);
    eglTerminate(display);

    return 0;
}

```

该示例首先使用了EGL创建了渲染表面，EGL可以用于管理绘图表面(window surface只是一种类型，还有pbuffer、pixmap)。下面详细地解释下每个步骤。

### 使用eglGetDisplay连接渲染目标设备
```cpp
EGLDisplay eglGetDisplay(EGLNativeDisplayType display_id);
```

eglGetDisplay是EGL库中的一个函数，函数返回EGLDisplay对象，它代表了与渲染目标设备的连接，如果显示连接不可用，eglGetDisplay将返回 EGL_NO_DISPLAY，这个错误表示显示连接不可用。

display_id 参数通常是一个表示显示设备的本地显示类型，EGLNativeDisplayType是为了匹配窗口显示类型，在各个平台有不同的定义。如果您只是希望使用默认的显示设备，那么您可以直接使用 EGL_DEFAULT_DISPLAY，而不需要显式地指定 display_id。

### 使用eglInitialize初始化EGL
当成功打开连接之后则需要调用eglInitialize初始化EGL。
```cpp
EGLBoolean eglInitialize(EGLDisplay display, // 指定EGL显示连接
                         EGLint *majorVersion, // 指定EGL实现返回的主版本号，可能为NULL
                         EGLint *minorVersion);// 指定EGL实现返回的次版本号，可能为NULL
```
这个函数用于初始化EGL内部数据结构，将返回EGL的版本号，并将其保存在majorVersion、minorVersion。
如果初始化成功，则返回EGL_TRUE，否则返回EGL_FALSE。另外还可以通过EGLint eglGetError()，查询EGL的错误状态：

- EGL_BAD_DISPLAY：表示没有指定有效的EGLDisplay。

- EGL_NOT_INITIALIZED：表示EGL不能初始化。

### 使用eglChooseConfig确定渲染配置
EGL初始化成功之后，需要确定可用渲染表面的类型和配置，目前支持两种方法：
- 可以指定一组需要的配置，使用eglChooseConfig使EGL推荐最佳配置。
一般情况下使用此种方法，因为这样更容易获得最佳配置。

    ```cpp
    EGLBoolean eglChooseConfig(EGLDisplay dpy,   // EGL显示连接句柄，标识了要进行配置选择的显示连接。
                        const EGLint *attrib_list, // 一个以EGL_NONE结尾的整数数组，用于指定所需配置的属性。属性列表中的每个元素都由属性名称（如EGL_RED_SIZE）和相应的属性值组成。如{EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8, EGL_NONE}。
                           EGLConfig *configs, // 一个用于存储选择配置的指针数组。eglChooseConfig函数将从可用配置中选择适合条件的配置，并将其存储在此数组中。
                           EGLint config_size,// configs数组的大小
                           EGLint *num_config); // 存储满足attrib_list需求，得到的满足需求的实际配置数量。
    ```

    ```cpp
    // 如以上代码所示这里指定所需配置的属性为
    EGLint attribs[] = {EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,  // 指定了渲染类型为 OpenGL ES 3
                        EGL_BLUE_SIZE, 6,   // 指定蓝色缓冲区的位数是6位
                        EGL_GREEN_SIZE, 8,  // 指定绿色缓冲区的位数是8位
                        EGL_RED_SIZE, 8,    // 指定红色缓冲区的位数是8位
                        EGL_NONE};
    eglChooseConfig(display, attribs, &config, 1, &numConfigs);
    ```
    以上示例中，蓝色缓冲区的位数被指定为6位。这意味着在8位RGB（范围从0到255）的情况下，要表示蓝色值200，可以使用6位来表示。具体计算如下：因为6位可以表示的最大数值是2^6= 64，因此需要将8位的数值映射到6位的范围，即使用公式64* 200 / 256进行计算。使用了eglChooseConfig后根据指定的配置属性attribs 将返回满足需求的配置，存放在config中。示例代码config_size传入了1，表明config数组的大小为1。只能保存一组可用配置，但那也是足够的。而numconfigs 保存满足指定配置的所有配置数量。 这样我们得到了满足我们需求的config。

- 也可以使用eglGetConfigs查询支持的所有配置，并使用eglGetConfigAttrib筛选需要的配置。
  以下提供使用此种方法得到满足需求的配置，具体可见示例：

  ```cpp
  #include <EGL/egl.h>
  #include <iostream>
  #include <vector>
  int main() {
      // 初始化 EGL
      EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
      eglInitialize(display, nullptr, nullptr);
  
      // 获取所有配置
      EGLint numConfigs;
      eglGetConfigs(display, nullptr, 0, &numConfigs);
      std::vector<EGLConfig> configs(numConfigs);
      eglGetConfigs(display, configs.data(), numConfigs, &numConfigs);
  
      // 选择合适的配置
      EGLConfig chosenConfig = nullptr;
      for (const auto& config : configs) {
          EGLint redSize, greenSize, blueSize;
          eglGetConfigAttrib(display, config, EGL_RED_SIZE, &redSize);
          eglGetConfigAttrib(display, config, EGL_GREEN_SIZE, &greenSize);
          eglGetConfigAttrib(display, config, EGL_BLUE_SIZE, &blueSize);
          if (redSize == 8 && greenSize == 8 && blueSize == 6) {
              chosenConfig = config;
              break;
          }
      }
  
      // 如果未选择配置，则打印错误信息并退出
      if (!chosenConfig) {
          std::cerr << "Failed to find a suitable EGL configuration." << std::endl;
          return 1;
      }
      return 0;
  }
  ```

  ```cpp
  EGLBoolean eglGetConfigs(EGLDisplay display, // EGL显示连接句柄，标识了要进行配置选择的显示连接。
                           EGLConfig *configs, // 用于保存得到配置的数组
                           EGLint config_size, // configs的数组大小
                           EGLint *num_config);// 得到的EGL所有可用配置数量
  ```
  
   eglGetConfigs接口有以下两种用法：
  
  - 当我们传递configs为nullptr时，接口会返回EGL_TRUE，并将得到的EGL所有可用配置数量保存在num_config中，这时即可根据得到的数量初始化configs来保存这些配置了，具体见如上代码。
  - 当传递configs数组接受所有配置时，将得到所有配置并保存在configs，这样即可得到所有的可用配置，接下来可以根据具体需求筛选一组config保存下来。
  
  ```cpp
  // 选择合适的配置
     EGLConfig chosenConfig = nullptr;
         for (const auto& config : configs) {
             EGLint redSize, greenSize, blueSize;
             eglGetConfigAttrib(display, config, EGL_RED_SIZE, &redSize);
             eglGetConfigAttrib(display, config, EGL_GREEN_SIZE, &greenSize);
             eglGetConfigAttrib(display, config, EGL_BLUE_SIZE, &blueSize);
             if (redSize == 8 && greenSize == 8 && blueSize == 6) {
                 chosenConfig = config;
                 break;
             }
         }
  ```
  
  如上所示遍历configs每个配置 ，使用eglGetConfigAttrib查询该配置下特定属性的值，将该值保存在第4个参数中，并判断值是否是自己需要的，如果需要则保存该配置，以待使用。调用成功则返EGL_TRUE，调用失败则返回EGL_FALSE。 如果返回EGL_FALSE，可以使用eglGetError查询失败的原因，如果返回EGL_BAD ATTRIBUTE则attribute不是有效的属性。
  
  ```cpp
  EGLBoolean eglGetConfigAttrib(EGLDisplay display, //EGL 显示连接句柄，标识了要进行配置选择的显示连接
                                     EGLConfig config,  //EGLConfig 对象，表示要查询的 EGL 配置
                                     EGLint attribute,  //EGLint 类型的属性标识符，表示要查询的属性
                                     EGLint *value);    //指向 EGLint 类型变量的指针，用于存储查询到的属性值。
  ```


### 使用eglCreateWindowSurface创建窗口表面

得到符合渲染需求的EGLConfig之后，可以使用eglCreateWindowSurface创建窗口表面。
```cpp
EGLSurface eglCreateWindowSurface(EGLDisplay dpy, // EGLDisplay对象，表示与窗口表面关联的显示连接。
                                  EGLConfig config, // EGLConfig对象，表示要创建窗口表面的EGL配置。
                                  EGLNativeWindowType win, // EGLNativeWindowType类型的参数，表示窗口的句柄或标识符，用于与EGL表面关联。
                                  const EGLint *attrib_list); // 指向EGL属性列表的指针，用于指定窗口表面的属性。是一个以EGL_NONE结尾的整数数组。
```
eglCreateWindowSurface接受的属性attrib_list的值如下所示：

```cpp
EGL_RENDER_BUFFER EGL_SINGLE_BUFFER或EGL_BACK_BUFFER
EGL_SINGLE_BUFFER // 表示渲染表面将只有一个渲染缓冲区，在绘制完成后，渲染缓冲区中的内容将直接显示到屏幕上，不会进行双缓冲，可能会出现闪烁或撕裂的现象。
EGL_BACK_BUFFER   // 表示渲染表面将具有双缓冲区，即前缓冲区和后缓冲区。在绘制完成后，渲染缓冲区中的内容首先会绘制到后缓冲区，然后通过交换缓冲区的操作将后缓冲区的内容显示到屏幕上，这样可以避免闪烁和撕裂现象。
// 默认情况下是EGL_BACK_BUFFER，当设置为null，则为默认属性。
```
eglCreateWindowSurface创建窗口表面失败的可能如下：

- EGL_BAD_MATCH：表示窗口属性与提供的 EGLConfig 不匹配。这可能是因为EGLConfig不支持渲染到窗口（即EGL_SURFACE_TYPE 属性没有设置为 EGL_WINDOW_BIT）。

- EGL_BAD_CONFIG：如果提供的EGLConfig没有得到系统的支持，则会发生这种错误。

- EGL_BAD_NATIVE_WINDOW：如果提供的窗口句柄无效，则会发生这种错误。

- EGL_BAD_ALLOC：如果eglCreateWindowSurface无法为新的EGL窗口分配资源，或者已经有与提供的窗口关联的EGLConfig，则会发生这种错误。



```cpp
EGLint attribList[] = { EGL_RENDER_BUFFER, EGL_BACK_BUFFER, EGL_NONE };
EGLSurface surface = eglCreateWindowSurface(display, config, nativeWindow, attribList);
if (surface == EGL_NO_SURFACE) {
    switch (eglGetError()) {
        case EGL_BAD_MATCH:
            // 检查窗口和 EGLConfig 属性以确定兼容性，或者验证 EGLConfig 是否支持渲染到窗口
            break;
        case EGL_BAD_CONFIG:
            // 验证提供的 EGLConfig 是否有效
            break;
        case EGL_BAD_NATIVE_WINDOW:
            // 验证提供的 EGLNativeWindow 是否有效
            break;
        case EGL_BAD_ALLOC:
            // 资源不足；处理并恢复
            break;
        default:
            // 处理任何其他错误
            break;
    }
}
```
在使用XComponent获取nativeWindow的过程中，通常涉及以下步骤：
1. 首先需要在ArkTS 中定义XComponent并设置 XComponentController。XComponent组件用于在UI中嵌入渲染内容如OpenGL或Vulkan。
```typescript
Column() {
    XComponent({
        id: 'myXComponent',
        type: XComponentType.SURFACE,
        controller: this.xComponentController
    })
}
```
2. 创建 XComponentController子类，实现回调方法：
```typescript
class MyXComponentController extends XComponentController {
    onSurfaceCreated(surfaceId: string): void {
        console.log(`onSurfaceCreated surfaceId: ${surfaceId}`);
        nativeRender.SetSurfaceId(BigInt(surfaceId));
        // 之后会使用 surfaceId 关联 native window
    }

    onSurfaceChanged(surfaceId: string, rect: SurfaceRect): void {
        console.log(`onSurfaceChanged surfaceId: ${surfaceId}`);
    }
    
    onSurfaceDestroyed(surfaceId: string): void {
        console.log(`onSurfaceDestroyed surfaceId: ${surfaceId}`);
    }
}
```
3. 使用surfaceId获取NativeWindow：
surfaceId是在XComponent创建过程中生成的。在onSurfaceCreated 回调中，可以使用OH_NativeWindow_CreateNativeWindowFromSurfaceId函数通过surfaceId获取nativeWindow。
```cpp
napi_value PluginManager::SetSurfaceId(napi_env env, napi_callback_info info)
{
    int64_t surfaceId = ParseId(env, info);
    OHNativeWindow *nativeWindow;
    PluginRender *pluginRender;
    if (windowMap_.find(surfaceId) == windowMap_.end()) {
        OH_NativeWindow_CreateNativeWindowFromSurfaceId(surfaceId, &nativeWindow);
        windowMap_[surfaceId] = nativeWindow;
    } else {
        return nullptr;
    }
    if (pluginRenderMap_.find(surfaceId) == pluginRenderMap_.end()) {
        pluginRender = new PluginRender(surfaceId);
        pluginRenderMap_[surfaceId] = pluginRender;
    }
    pluginRender->InitNativeWindow(nativeWindow);
    return nullptr;
}
```
<!--Del-->
有关ArkTS XComponent 组件的使用，请参考：[ArkTS XComponent组件使用示例](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/BasicFeature/Native/XComponent/README_zh.md#)。
<!--DelEnd-->

### 使用eglCreateContext创建渲染上下文 

eglCreateContext函数用于创建一个新的EGL上下文，并将其与特定的显示设备（display）和配置（config）关联起来。允许指定共享上下文（shareContext），以便与已经存在的OpenGL上下文共享状态信息。该函数的参数说明如下：

```cpp
EGLContext eglCreateContext(EGLDisplay display, // EGLDisplay类型，表示要创建上下文的EGL显示连接。
                            EGLConfig config,   // EGLConfig类型，表示与上下文关联的EGL配置。
                            EGLContext shareContext, // EGLContext类型，表示要与新创建的上下文共享状态信息的现有上下文。如果不想共享状态信息，可以传递EGL_NO_CONTEXT。
                            const EGLint *attribList); // 指向属性列表的指针，用于指定上下文的属性。属性列表是以EGL_NONE结尾的一系列属性值对。
```
eglCreateContext 的attribList属性列表如下：
```cpp
EGLint contextAttribs[] = {
    EGL_CONTEXT_CLIENT_VERSION, 3, //指定使用的openglES版本3相关的上下文类型
};
```

eglCreateContext 创建渲染上下文失败的可能为：EGL_BAD_CONFIG，即提供的EGLconfig无效。

### 使用eglMakeCurrent将EGL上下文与绘图表面进行关联

```cpp
EGLBoolean eglMakeCurrent(EGLDisplay display, // EGL显示连接的句柄，用于标识渲染设备。
                          EGLSurface draw,    // EGL绘图表面的句柄，指定要渲染到的目标表面。
                          EGLSurface read,    // EGL读取表面的句柄，用于像素读取等操作。通常情况下，可以将其设为与 draw 相同的值。
                          EGLContext context);// 要与指定表面关联的 EGL 上下文的句柄。
```

### 使用glViewport设置视口大小

```cpp
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
```

glViewport函数用于设置视口，指定OpenGL ES渲染区域在窗口的位置和大小。其中x、y指定视口的左下角在窗口中的坐标，width、height参数则指定视口的宽度和高度。

### 使用glClearColor设置清除颜色缓冲区时使用的颜色

```cpp
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
```
`glClearColor(0.2f, 0.3f, 0.3f, 1.0f)`此时设置清除颜色缓冲区时使用的颜色为 (0.2, 0.3, 0.3)，即红色分量为0.2、绿色分量为0.3、蓝色分量为0.3、透明度为1.0（不透明）。

### 使用glClear执行清除操作

```cpp
void glClear(GLbitfield mask);
```
glClear函数用于清除指定的缓冲区。参数mask指定需要清除的缓冲区，可以是以下值的组合：
- GL_COLOR_BUFFER_BIT：清除颜色缓冲区。
- GL_DEPTH_BUFFER_BIT：清除深度缓冲区。
- GL_STENCIL_BUFFER_BIT：清除模板缓冲区。

可调用glClear(GL_COLOR_BUFFER_BIT)清除颜色缓冲区，并用之前glClearColor设置的颜色填充整个缓冲区。清除颜色缓冲区是在开始绘制新帧之前的一个常见操作，这可以确保屏幕上的每个像素都被初始化为指定的颜色值，以便绘制新的图像。也是绘制新帧的准备工作，类似于在画布上涂上底色，以便开始新的绘画。

### 定义顶点数据
```cpp
  // 定义顶点数据
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,  // 左下角
         0.5f, -0.5f, 0.0f,  // 右下角
         0.0f,  0.5f, 0.0f   // 顶部
    };
```

在OpenGL中，通常会使用标准化设备坐标(Normalized Device Coordinates, NDC)来表示顶点的位置。NDC是一个以屏幕为单位的坐标空间，在这个空间中，左下角是(-1, -1)，右上角是(1, 1)。这种坐标范围使得顶点的位置不依赖于屏幕的大小和比例。
### 管理顶点数据

将顶点数据保存在GPU，减少CPU与GPU数据传输次数。

```cpp
GLuint VAO[1];
GLuint VBO;
glGenVertexArrays(1, VAO); // 要生成1个顶点数组对象（VAO) VAO 用于存储生成的顶点数组对象名称的数组
glBindVertexArray(VAO[0]); // 用于绑定顶点数组对象（VAO）到当前OpenGL上下文中。
glGenBuffers(1, &VBO); // 用于生成顶点缓冲对象, 1：要生成的顶点缓冲对象的数量这里设置1个 ，&VBO 指向存储生成的顶点缓冲对象名称的数组的指针。
glBindBuffer(GL_ARRAY_BUFFER, VBO); // void glBindBuffer(GLenum target, GLuint buffer);其中target为指定要绑定的缓冲目标,可为以下值之一：
                                   // GL_ARRAY_BUFFER：用于存储顶点属性数据；
                                  // GL_ELEMENT_ARRAY_BUFFER：用于存储索引数据等其他。
                                 // buffer为要绑定的顶点缓冲对象的名称。
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
```
```cpp
void glBufferData(GLenum target, // target：指定缓冲对象的类型，可为以下值之一：
                                // GL_ARRAY_BUFFER：用于存储顶点属性数据;
                               // GL_ELEMENT_ARRAY_BUFFER：用于存储索引数据。
                  GLsizeiptr size, // 指定要分配的缓冲区的大小（以字节为单位）。
                  const GLvoid* data, // 指定要复制到缓冲区的初始数据。
                  GLenum usage); // 指定缓冲区的预期使用方式，可为以下值之一：
                                // GL_STATIC_DRAW：数据不会或几乎不会被修改，并且被绘制命令多次使用；
                               // GL_DYNAMIC_DRAW：数据会被频繁修改，并且被绘制命令多次使用；
                              // GL_STREAM_DRAW：数据会被修改，并且被绘制命令少量使用。
```

一旦调用glBufferData函数，数据就被复制到了OpenGL的缓冲对象中，并存储在GPU的显存中。这意味着数据可以在GPU上被高效地访问和处理，而无需频繁地从CPU内存传输数据，从而提高了渲染性能。

```cpp
    const char* vertexShaderSource = R"(
        #version 320 es  // 这是指定使用OpenGL ES 3.2版本的着色器语言
        precision mediump float;  // 指定浮点数的精度为中等精度
        layout (location = 0) in vec3 aPos; // 顶点属性变量，名称为aPos，类型为vec3，并且指定它在顶点着色器中的位置索引为0。这个变量aPos接收刚才设置的来自顶点缓冲对象中的顶点数据。每次顶点着色器被调用时，aPos就会被设置为当前处理的顶点的位置属性值。（数据从刚才顶点缓冲对象中获取，且已经存到GPU）
        void main() {
            // gl_Position是opengles内置变量，来指定每个顶点的最终位置，这个位置是经过透视投影变换后的裁剪空间坐标。
            // 在顶点着色器中对gl_Position赋值后，图形渲染管线会将其进行进一步处理，然后将顶点投影到屏幕上的二维坐标。 
            // w为非零值时，顶点坐标会进行透视除法操作，即将 (x, y, z, w) 中的 (x/w, y/w, z/w) 作为最终的裁剪空间坐标。
            // 因此，当w的值为1.0时，透视除法不会对坐标进行任何变换，坐标值保持不变。
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); 
        }
    )";
```
- 片段（Fragment）：是光栅化阶段生成的元素，它代表一个潜在的屏幕像素，包括所有与这个像素相关的信息，比如颜色、深度、模板值等。每个片段会经过片段着色器处理，并最终决定是否写入到帧缓冲区中。
- 片段着色器是一个运行在每个片段上的程序，这里用于计算片段的最终颜色值。片段着色器可以访问插值后的顶点数据，并执行复杂的光照计算、纹理采样等操作。

```cpp

const char* fragmentShaderSource = R"(
    #version 320 es  // 这是指定使用OpenGL ES 3.2版本的着色器语言
    precision mediump float;  // 设置浮点数的精度为中等精度
    out vec4 FragColor;  // 输出片段颜色

    void main() {
        // 这里将每个片段的颜色设置为vec4(1.0f, 0.5f, 0.2f, 1.0f)
        // 其中分别代表红色、绿色、蓝色和alpha值。
        // 这意味着输出的颜色为浅橙色，完全不透明。
        // 这里的颜色不是从顶点着色器经过光栅化线性插值而获得的，而是直接赋值。
        FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    }
)";

```
在 OpenGL ES渲染管线中，以下步骤描述了从顶点数据到最终像素输出的整个过程：

1. 顶点着色器处理。

   首先，将缓冲区中的顶点数据传入顶点着色器程序。在顶点着色器中进行以下操作：
   
   - 矩阵转换：使用用模型视图矩阵（MV矩阵）和投影矩阵（透视矩阵）对顶点位置进行变换。

   - 照明计算：根据光照公式计算顶点的颜色或其他属性。
   
2. 图元装配。

   顶点着色器处理后的顶点数据被送入图元装配阶段：在这个阶段，将顶点数据组装成几何图元，例如点、线段或三角形。

3. 光栅化。

   接下来，进行光栅化，将几何图元（例如三角形）转换为屏幕上的像素集合。这个过程包括插值：如果顶点设置了颜色或其他属性，光栅化阶段会对这些属性进行线性插值，生成片段（像素）数据。

4. 片段着色器处理。 

   光栅化输出的片段数据作为片段着色器的输入变量。在片段着色器中进行以下操作：

   - 光照计算：计算片段的光照效果。

   - 纹理采样：从纹理中获取颜色数据。

   - 颜色混合：结合光照和纹理数据生成新的颜色、深度和屏幕坐标位置等。

5. 逐片段操作。

   片段着色器的输出被送入逐片段操作阶段，包括：

   - 像素归属测试：确定片段是否属于当前绘制的像素区域。

   - 剪裁测试：确定片段是否在可视区域内。

   - 模板测试：使用模板缓冲区进行测试。

   - 深度测试：比较片段的深度值，以确定其是否可见。

   - 混合：将新计算的颜色与帧缓冲区中已有的颜色进行混合。

   - 抖动：减少颜色量化误差，在原始图像上添加小的、随机或有序的噪声，使得颜色的量化误差在空间上被分散，而不是集中在某些特定的区域。

6. 写入帧缓冲区。

  经过上述所有测试和处理后，最终的片段数据被写入帧缓冲区，形成最终显示在屏幕上的图像。

### 创建并使用着色器程序

```cpp
GLuint vertexShader, fragmentShader, shaderProgram;
// 创建顶点着色器
vertexShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
glCompileShader(vertexShader);

// 创建片段着色器
fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
glCompileShader(fragmentShader);

// 创建着色器程序
shaderProgram = glCreateProgram();
glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);
glLinkProgram(shaderProgram);

// 使用着色器程序
glUseProgram(shaderProgram);
```

```cpp
GLuint glCreateShader(GLenum shaderType);
```
glCreateShader用于创建一个指定类型（顶点着色器、片段着色器等）的着色器对象，并返回该对象的句柄。其中shaderType参数指定要创建的着色器类型，可以是GL_VERTEX_SHADER（顶点着色器）或 GL_FRAGMENT_SHADER（片段着色器）等。

```cpp
void glShaderSource(GLuint shader, GLsizei count, const GLchar \**string, const GLint *length);
```

glShaderSource函数用于设置着色器对象的源代码。其中各参数含义如下：

- shader：要设置源代码的着色器对象的标识符。
- count：源代码字符串的数量。
- string：指向源代码字符串的指针数组。
- length：指向包含每个源代码字符串长度的整数数组，可以为nullptr，表示每个字符串都以null结尾。

```cpp
void glCompileShader(GLuint shader);
```

glCompileShader函数用于编译指定的着色器对象，其中shader参数是要编译的着色器对象的标识符。

```cpp
GLuint glCreateProgram(void);
```

glCreateProgram函数用于创建一个新的着色器程序对象，该函数返回一个新创建的着色器程序对象的标识符。

```cpp
void glAttachShader(GLuint program, GLuint shader);
```

glAttachShader函数用于将一个着色器对象附加到一个着色器程序对象上，参数program是目标着色器程序对象的标识符，参数shader是要附加的着色器对象的标识符。

```cpp
void glLinkProgram(GLuint program);
```

glLinkProgram函数用于链接一个着色器程序对象，将附加到该程序对象的着色器链接成一个可执行的渲染管线。

参数program是要链接的着色器程序对象的标识符。链接着色器程序时，OpenGL将会执行以下操作：将各个着色器对象中的代码合并成一个可执行的渲染管线。执行连接器优化，以优化渲染管线的性能。并将Uniform变量和Uniform块的信息进行绑定。

```cpp
void glUseProgram(GLuint program);
```
glUseProgram函数用于激活指定的着色器程序对象。在调用glUseProgram 之后，所有的渲染调用将会使用该着色器程序进行处理。

在使用glCompileShader时可以使用以下代码检查是否正常。

```cpp
// 编译着色器
glCompileShader(shader);

// 检查编译状态
glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

if (!compiled)
{
    GLint infoLen = 0;

    // 获取着色器信息日志的长度
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

    if ( infoLen > 1 )
    {
        // 分配存储信息日志的内存
        char *infoLog = malloc(sizeof(char) * infoLen);

        // 获取并打印着色器信息日志
        glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
        esLogMessage("Error compiling shader:\n%s\n", infoLog);

        // 释放分配的内存
        free(infoLog);
    }

    // 删除编译失败的着色器
    glDeleteShader(shader);
    return 0;
}
```

在使用glLinkProgram可使用如下代码检查是否正常。

```cpp
// 链接程序对象
glLinkProgram(programObject);

// 检查链接状态
glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

if (!linked)
{
    GLint infoLen = 0;

    // 获取程序对象信息日志的长度
    glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

    if (infoLen > 1)
    {
        // 分配存储信息日志的内存
        char *infoLog = malloc(sizeof(char) * infoLen);

        // 获取并打印程序对象的信息日志
        glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
        esLogMessage("Error linking program:\n%s\n", infoLog);

        // 释放分配的内存
        free(infoLog);
    }

    // 删除链接失败的程序对象
    glDeleteProgram(programObject);
    return FALSE;
}
```

### 确定顶点属性数组的配置

包括顶点属性在缓冲区中的布局和格式。

```cpp
void glVertexAttribPointer(GLuint index, // 指定要修改的顶点数组的起始索引，索引它与顶点着色器中的属性变量绑定。（layout (location = 0) in vec3 aPos;）
                           GLint size,  // 指定每个顶点属性的分量个数
                           GLenum type, // 指定每个顶点属性分量的类型
                           GLboolean normalized, // 指定在访问顶点数据时是否将其映射到[0, 1]或[-1, 1]范围内
                           GLsizei stride, // 指定顶点属性之间的偏移量,如果是精密性排列可以设置为0
                           const void *offset);//属性在缓冲区中的偏移量，允许在缓冲区中指定一个位置开始读取数据。
```

```cpp
void glEnableVertexAttribArray(GLuint index);
```

glEnableVertexAttribArray 函数用于启用指定索引的顶点属性数组。例如，调用glEnableVertexAttribArray(0)可以启用位置索引为 0 的顶点属性数组，这与顶点着色器程序中的 layout (location = 0) in vec3 aPos 相关联。

在示例代码中，glVertexAttribPointer 的第一个参数index对应顶点着色器中aPos的location，即位置 0。其他参数设置了顶点属性的格式，告诉 OpenGL 该属性包含 3 个组件（x、y、z），数据类型为 GL_FLOAT，并且每个顶点数据的第一个属性从偏移量 0 开始。

glBindBuffer函数绑定当前的顶点缓冲对象（VBO），glBufferData将顶点数据传输到 GPU 中，而glVertexAttribPointer 说明了如何解释这些数据。在使用顶点缓冲对象（VBO）时，顶点数据通常存储在缓冲区中，但这些数据不会自动传递给顶点着色器。相反，我们需要通过顶点属性指针告诉 OpenGL ES如何解释这些数据。glEnableVertexAttribArray用于启用指定位置的顶点属性数组。例如，启用位置0的顶点属性数组，可以调用 glEnableVertexAttribArray(0)。


### 绘制图元并显示

```cpp
void glDrawArrays(GLenum mode, // 参数指定要绘制的图元的类型，比如GL_TRIANGLES表示绘制三角形。
                  GLint first,// 参数指定要绘制的顶点数组的起始索引。
                  GLsizei count  // 参数指定要绘制的顶点数量
                  );
```

glDrawArrays函数用于根据当前绑定的顶点数组和顶点属性以及其他设置来绘制图元。

```cpp
EGLBoolean eglSwapBuffers(EGLDisplay dpy, // EGL显示连接
                          EGLSurface surface); // 要交换其缓冲区的EGL表面
```

eglSwapBuffers函数用于交换前后缓冲区的内容，并将渲染结果显示在屏幕上。

<!--RP1--><!--RP1End-->

## 相关实例

针对OpenGL ES的使用和相关开发，有以下相关实例可供参考：

- [简易Native C++示例](https://gitcode.com/openharmony/codelabs/tree/master/NativeAPI/NativeTemplateDemo)
- [Native XComponent组件的使用](https://gitcode.com/openharmony/codelabs/tree/master/NativeAPI/XComponent)