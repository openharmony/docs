# OpenGL ES

OpenGL is a cross-platform graphics API that specifies a standard software interface for 3D graphics processing hardware. [OpenGL ES](https://www.khronos.org/opengles/) is a flavor of the OpenGL specification intended for embedded devices. OpenHarmony now supports OpenGL ES 3.2.

## Supported Capabilities

OpenGL ES 3.2

## Symbols Exported from the Standard Library

[OpenGL ES 3.2 Symbols Exported](openglesv3-symbol.md)

## Introducing OpenGL

To use OpenGL capabilities, you must add related dynamic link libraries (DLLs) and header files.

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**.

```txt
libace_ndk.z.so
libace_napi.z.so
libGLESv3.so
libEGL.so
```

**Including Header Files**

```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>
#include <GLES3/gl3.h>
```

## References

To use the OpenGL ES API in your application development, familiarize yourself with the NDK development process and the **XComponent** usage, which are described in the following topics:

- [Getting Started with the NDK](../../napi/ndk-development-overview.md)

- [Node-API](./napi.md)

- [XComponentNode](../apis-arkui/js-apis-arkui-xcomponentNode.md)

- [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)

## OpenGL ES Extensions

- To obtain the official reference document for OpenGL ES extensions, visit [Khronos OpenGL ES Registry](https://registry.khronos.org/OpenGL/index_es.php).
- You can call **glGetString** to query the extensions supported by the chip. Before calling **glGetString**, you must initialize the context. The following is an example:

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
strTest = (char *)glGetString(GL_EXTENSIONS); // The return value of strTest lists all extensions supported, separated by spaces.
bool isHave = strTest.find("GL_OES_matrix_palette") != -1 ?
    true :
    false; // Check whether an extension exists. If yes, the value of isHave is true. If no, the value of isHave is false.
```

## Example

```cpp
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    // Initialize EGL.
    EGLDisplay display;
    EGLConfig config;
    EGLContext context;
    EGLSurface surface;
    EGLint numConfigs;
    EGLint majorVersion;
    EGLint minorVersion;

    // Initialize the EGL display.
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(display, &majorVersion, &minorVersion);

    // Configure EGL.
    EGLint attribs[] = {
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
        EGL_BLUE_SIZE, 6,
        EGL_GREEN_SIZE, 8,
        EGL_RED_SIZE, 8,
        EGL_NONE
    };
    eglChooseConfig(display, attribs, &config, 1, &numConfigs);

    // Create an EGL context.
    EGLint contextAttribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 3,
        EGL_NONE
    };

    // Create an EGL surface.
    surface = eglCreateWindowSurface(display, config, nativeWindow, NULL);

    context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs);

    // Bind the EGL context to the surface.
    eglMakeCurrent(display, surface, surface, context);

    // Set the viewport.
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Clear the color buffer.
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Define vertex data.
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f, // Lower left corner.
         0.5f, -0.5f, 0.0f, // Lower right corner.
         0.0f, 0.5f, 0.0f // Top.
    };

    // Create and bind a Vertex Buffer Object (VBO).
    GLuint VAO[0];
    GLuint VBO;
    glGenVertexArrays(1, VAO);
	glBindVertexArray(VAO[0]);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create a shader program.
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
    // Create a vertex shader.
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    // Create a fragment shader.
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    // Create a shader program.
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Use the shader program.
    glUseProgram(shaderProgram);

    // Bind the vertex data.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Draw a triangle.
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Swap the buffers.
    eglSwapBuffers(display, surface);

    // Clear the resources.
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteBuffers(1, &VBO);

    // Wait for exit.
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();

    // Clear EGL.
    eglDestroyContext(display, context);
    eglDestroySurface(display, surface);
    eglTerminate(display);

    return 0;
}

```

This example uses EGL to create a render surface, which can be a window surface, pbuffer, or pixmap. The following explains every step in detail.

### Using eglGetDisplay to Obtain an EGL Display Connection
```cpp
EGLDisplay eglGetDisplay(EGLNativeDisplayType display_id);
```

The **eglGetDisplay** function returns an **EGLDisplay** object, which represents the connection to an EGL display. If no connection is available, **EGL_NO_DISPLAY** is returned.

The **display_id** parameter indicates the local display type of the display. The **EGLNativeDisplayType** parameter is the window display type, which has different definitions on different platforms. If you just want to use the default display, use **EGL_DEFAULT_DISPLAY** without explicitly specifying **display_id**.

### Using eglInitialize to Initialize the EGL Display Connection
Call **eglInitialize** to initialize the EGL display connection obtained.
```cpp
EGLBoolean eglInitialize(EGLDisplay display, // EGL display connection.
                         EGLint *majorVersion, // Major version number of the EGL implementation. The value may be NULL.
                         EGLint *minorVersion);// Minor version number of the EGL implementation. The value may be NULL.
```
The function is used to initialize the internal data structure of the EGL, return the EGL version numbers, and save them in **majorVersion** and **minorVersion**.
If the initialization is successful, **EGL_TRUE** is returned. Otherwise, **EGL_FALSE** is returned. You can also call **EGLint eglGetError()** to query the EGL error status.

- **EGL_BAD_DISPLAY**: The specified EGL display is invalid.

- **EGL_NOT_INITIALIZED**: EGL cannot be initialized.

### Using eglChooseConfig to Determine the Rendering Configuration
After the EGL display connection is initialized, determine the type and configuration of the available surface in either of the following ways:
- Specify a set of required configurations and use **eglChooseConfig** to enable EGL to recommend the optimal configuration.
Generally, you can use this method because it is easier to obtain the optimal configuration.

    ```cpp
    EGLBoolean eglChooseConfig(EGLDisplay dpy, // Handle to the EGL display connection for which configurations are selected.
                        const EGLint *attrib_list, // An integer array of pointers to attributes. Each element in the array consists of an attribute name (for example, EGL_RED_SIZE) and attribute value, and the array is terminated with EGL_NONE. An example attribute array is {EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8, EGL_NONE}.
                           EGLConfig *configs, // An array of pointers to the selected configurations. The eglChooseConfig function selects the configurations that match the attributes from the available configurations and stores them in this array.
                           EGLint config_size,// Size of the configs array.
                           EGLint *num_config); // Number of configurations that match the attributes.
    ```

    ```cpp
    // Here, the following attributes are used:
    EGLint attribs[] = {EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,  // The renderable type is OpenGL ES 3.
                        EGL_BLUE_SIZE, 6, // The number of bits in the blue buffer is 6.
                        EGL_GREEN_SIZE, 8, // The number of bits in the green buffer is 8.
                        EGL_RED_SIZE, 8, // The number of bits in the red buffer is 8.
                        EGL_NONE};
    eglChooseConfig(display, attribs, &config, 1, &numConfigs);
    ```
    In this example, the number of bits in the blue buffer is 6. To use six bits to represent the blue value 200 in the case of 8-bit RGB (ranging from 0 to 255), use the following formula for calculation: 64 x 200/256, where 64 is the maximum value that can be represented by six bits (2^6 = 64). After **eglChooseConfig** is called, the configurations that match the attributes are returned and stored in the **config** array. In the sample code, **config_size** is set to **1**, indicating that the size of the **config** array is 1. Only one set of configurations can be stored, but that's enough. **numconfigs** specifies the number of configurations that match the attributes. In this way, the desired **config** array is obtained.

- Use **eglGetConfigs** to query all supported configurations and use **eglGetConfigAttrib** to filter the desired ones.
  The following describes how to use this method to obtain the desired configurations.

  ```cpp
  #include <EGL/egl.h>
  #include <iostream>
  #include <vector>
  int main() {
      // Initialize EGL.
      EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
      eglInitialize(display, nullptr, nullptr);
  
      // Obtain all the configurations.
      EGLint numConfigs;
      eglGetConfigs(display, nullptr, 0, &numConfigs);
      std::vector<EGLConfig> configs(numConfigs);
      eglGetConfigs(display, configs.data(), numConfigs, &numConfigs);
  
      // Select a proper configuration.
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
  
      // If no configuration is selected, print the error information and exit.
      if (!chosenConfig) {
          std::cerr << "Failed to find a suitable EGL configuration." << std::endl;
          return 1;
      }
      return 0;
  }
  ```

  ```cpp
  EGLBoolean eglGetConfigs(EGLDisplay display, // Handle to the EGL display connection for which configurations are selected.
                           EGLConfig *configs, // Array for storing the obtained configurations.
                           EGLint config_size, // Size of the configs array.
                           EGLint *num_config); // Number of available configurations.
  ```
  
   The **eglGetConfigs** function can be used in either of the following ways:
  
  - If a null pointer is passed in to **configs**, **EGL_TRUE** is returned and the number of available configurations obtained is saved in **num_config**. In this case, **configs** can be initialized based on the number to store the configurations. For details, see the preceding code.
  - If **configs** is configured to accept all configurations, all configurations obtained are saved in **configs**. You can filter them as required and store the desired ones.
  
  ```cpp
  // Select a proper configuration.
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
  
  The preceding code snippet traverses each configuration in **configs** and uses **eglGetConfigAttrib** to query the value of a specific attribute in the configuration, save the value in the fourth parameter, check whether the configuration is the desired one, and if yes, save the configuration. If the call is successful, **EGL_TRUE** is returned. Otherwise, **EGL_FALSE** is returned. In the latter case, you can use **eglGetError** to obtain the failure cause. If **EGL_BAD ATTRIBUTE** is returned, the attribute is invalid.
  
  ```cpp
  EGLBoolean eglGetConfigAttrib(EGLDisplay display, // Handle to the EGL display connection for which configurations are selected.
                                     EGLConfig config, // EGL configuration to query.
                                     EGLint attribute, // Attribute identifier of the EGLint type, indicating the attribute to query.
                                     EGLint *value); // Pointer to the variable of the EGLint type, which is used to store the attribute value obtained.
  ```


### Using eglCreateWindowSurface to Create a Window Surface

After obtaining the EGL configurations that meet the rendering requirements, use **eglCreateWindowSurface** to create a window surface.
```cpp
EGLSurface eglCreateWindowSurface(EGLDisplay dpy, // EGL display connection to be associated with the window surface.
                                  EGLConfig config, // EGL configuration of the window surface to create.
                                  EGLNativeWindowType win, // Parameter of the EGLNativeWindowType type. It is the handle or identifier of the window and is used to associate with the EGL surface.
                                  const EGLint *attrib_list); // Pointer to the EGL attribute list. It specifies the attributes of the window surface. It is an integer array terminating with EGL_NONE.
```
The following values can be passed in to **attrib_list** of **eglCreateWindowSurface**:

```cpp
EGL_RENDER_BUFFER EGL_SINGLE_BUFFER or EGL_BACK_BUFFER
EGL_SINGLE_BUFFER // There is only one render buffer on the EGL surface. After the rendering is complete, the content in the render buffer is directly displayed on the screen. As a result, screen flickering or tearing may occur.
EGL_BACK_BUFFER // There are a front buffer and a back buffer. After the rendering is complete, the content in the render buffer is first rendered to the back buffer, and then the content in the back buffer is displayed on the screen by means of buffer swapping. In this way, screen flickering or tearing can be avoided. 
// The default value is EGL_BACK_BUFFER. If this parameter is set to null, the default value is used.
```
The possible causes of a failure to call **eglCreateWindowSurface** are as follows:

- **EGL_BAD_MATCH**: The window attributes do not match the EGL configuration. This may be because the EGL configuration does not support rendering to the window (the **EGL_SURFACE_TYPE** attribute is not set to **EGL_WINDOW_BIT**).

- **EGL_BAD_CONFIG**: The EGL configuration is not supported by the system.

- **EGL_BAD_NATIVE_WINDOW**: The window handle is invalid.

- **EGL_BAD_ALLOC**: Resources cannot be created for a new EGL window or there is already an EGL configuration associated with the window.



```cpp
EGLint attribList[] = { EGL_RENDER_BUFFER, EGL_BACK_BUFFER, EGL_NONE };
EGLSurface surface = eglCreateWindowSurface(display, config, nativeWindow, attribList);
if (surface == EGL_NO_SURFACE) {
    switch (eglGetError()) {
        case EGL_BAD_MATCH:
            // Check the window and EGL configuration to determine the compatibility, or check whether the EGL configuration supports rendering to the window.
            break;
        case EGL_BAD_CONFIG:
            // Check whether the EGL configuration is valid.
            break;
        case EGL_BAD_NATIVE_WINDOW:
            // Check whether the EGL native window is valid.
            break;
        case EGL_BAD_ALLOC:
            // Resources are insufficient. Handle and rectify the fault.
            break;
        default:
            // Handle other errors.
            break;
    }
}
```
The process of using the **XComponent** to obtain a native window is as follows:
1. Define the **XComponent** and set the **XComponentController** in ArkTS. The **XComponent** is used to embed rendering elements, such as OpenGL or Vulkan, into the UI.
```typescript
Column() {
    XComponent({
        id: 'myXComponent',
        type: XComponentType.SURFACE,
        controller: this.xComponentController
    })
}
```
2. Create an **XComponentController** subclass and implement its callbacks.
```typescript
class MyXComponentController extends XComponentController {
    onSurfaceCreated(surfaceId: string): void {
        console.log(`onSurfaceCreated surfaceId: ${surfaceId}`);
        nativeRender.SetSurfaceId(BigInt(surfaceId));
        // The surface ID will be used to associate with the native window.
    }

    onSurfaceChanged(surfaceId: string, rect: SurfaceRect): void {
        console.log(`onSurfaceChanged surfaceId: ${surfaceId}`);
    }
    
    onSurfaceDestroyed(surfaceId: string): void {
        console.log(`onSurfaceDestroyed surfaceId: ${surfaceId}`);
    }
}
```
3. Use the surface ID to obtain a native window.
The surface ID is generated during the creation of the **XComponent**. In the **onSurfaceCreated** callback, you can use **OH_NativeWindow_CreateNativeWindowFromSurfaceId** to obtain a native window based on the surface ID.
```cpp
napi_value PluginManager::SetSurfaceId(napi_env env, napi_callback_info info)
{
    int64_t surfaceId = ParseId(env, info);
    OHNativeWindow *nativeWindow;
    PluginRender *pluginRender;
    if (windowMap_.find(surfaceId) == windowMap_.end()) {
        OH_NativeWindow_CreateNativeWindowFromSurfaceId(surfaceId, &nativeWindow);
        windowMap_[surfaceId] = nativeWindow;
    }
    if (pluginRenderMap_.find(surfaceId) == pluginRenderMap_.end()) {
        pluginRender = new PluginRender(surfaceId);
        pluginRenderMap_[surfaceId] = pluginRender;
    }
    pluginRender->InitNativeWindow(nativeWindow);
    return nullptr;
}
```
For details about how to use the **XComponent**, see [ArkTS XComponent Usage Example](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/XComponent).
### Using eglCreateContext to Create a Rendering Context

The **eglCreateContext** function is used to create an EGL rendering context and associate it with a specific display and configuration. You can specify a shared context to share status information with an existing OpenGL context. The parameters in the function are described as follows:

```cpp
EGLContext eglCreateContext(EGLDisplay display, // Type of the EGL display connection for which the context is to be created.
                            EGLConfig config, // Type of the EGL configuration associated with the context.
                            EGLContext shareContext, // Type of the EGL context whose status information is to be shared with the newly created context. If you do not want to share the status information, pass in EGL_NO_CONTEXT.
                            const EGLint *attribList); // Pointer to the attribute list. It specifies the attributes of the context. An attribute list is a series of attribute-value pairs terminating with EGL_NONE.
```
The value of **attribList** in **eglCreateContext** is as follows:
```cpp
EGLint contextAttribs[] = {
    EGL_CONTEXT_CLIENT_VERSION, 3, // Context type related to OpenGL ES version 3.
};
```

If **eglCreateContext** fails to create the rendering context, the possible cause is **EGL_BAD_CONFIG**, which means that the EGL configuration is invalid.

### Using eglMakeCurrent to Attach the EGL Rendering Context to the EGL Surface

```cpp
EGLBoolean eglMakeCurrent(EGLDisplay display, // Handle to the EGL display connection.
                          EGLSurface draw, // Handle to the EGL draw surface.
                          EGLSurface read, // Handle to the EGL read surface. It is used to read pixels. Generally, you can set this parameter to the same value as draw.
                          EGLContext context); // Handle to the EGL rendering context to be attached to the surface.
```

### Using glViewport to Set the Viewport

```cpp
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
```

The **glViewport** function is used to set the viewport and specify the position and size of the OpenGL ES rendering area in the window. The **x** and **y** parameters specify the coordinates of the lower left corner of the viewport in the window. The **width** and **height** parameters specify the width and height of the viewport.

### Using glClearColor to Set the Color Used to Clear the Color Buffer

```cpp
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
```
In the **glClearColor(0.2f, 0.3f, 0.3f, 1.0f)** function, the color used for clearing the color buffer is set to (0.2, 0.3, 0.3). That is, the red component is 0.2, the green component is 0.3, the blue component is 0.3, and the alpha value is 1.0 (opaque).

### Using glClear to Clear Buffers

```cpp
void glClear(GLbitfield mask);
```
The **glClear** function is used to clear a buffer. The **mask** parameter specifies the buffer to clear. It can be a combination of the following values:
- **GL_COLOR_BUFFER_BIT**: clears the color buffer.
- **GL_DEPTH_BUFFER_BIT**: clears the depth buffer.
- **GL_STENCIL_BUFFER_BIT**: clears the stencil buffer.

You can call **glClear(GL_COLOR_BUFFER_BIT)** to clear the color buffer and fill the buffer with the color set by **glClearColor**. Clearing the color buffer is a common operation before you start frame rendering. This operation ensures that each pixel on the screen is initialized to the specified color value. It is also a mandatory preparation for drawing a new frame, similar to painting a background color on the canvas to start a new painting.

### Defining Vertex Data
```cpp
  // Define vertex data.
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f, // Lower left corner.
         0.5f, -0.5f, 0.0f, // Lower right corner.
         0.0f, 0.5f, 0.0f // Top.
    };
```

In OpenGL, Normalized Device Coordinates (NDCs) are usually used to represent the position of a vertex. NDC is a coordinate space in the screen. In this space, the lower left corner is (-1, -1), and the upper right corner is (1, 1). This coordinate space makes the position of the vertex independent of the size and aspect ratio of the screen.
### Managing Vertex Data

You can save the vertex data on the GPU to minimize data transfer between the CPU and GPU.

```cpp
GLuint VAO[1];
GLuint VBO;
glGenVertexArrays(1, VAO); // Generate Vertex Array Object (VAO) names. In this example, one VBO is generated.
glBindVertexArray(VAO[0]); // Bind the VAO to the current OpenGL context.
glGenBuffers(1, &VBO); // Generate VBO names. The first parameter indicates the number of VBO names to generate, and it is set to 1 in this example. The passed-in value &VBO is the pointer to the array that stores the generated VBO names.
glBindBuffer(GL_ARRAY_BUFFER, VBO); // void glBindBuffer(GLenum target, GLuint buffer), where target indicates the buffer to be bound and can be one of the following values:
                                   // GL_ARRAY_BUFFER: stores vertex attribute data.
                                  // GL_ELEMENT_ARRAY_BUFFER: stores index data and other data.
                                 // buffer is the name of the VBO to be bound.
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
```
```cpp
void glBufferData(GLenum target, // target specifies the type of the buffer object. The value can be one of the following:
                                // GL_ARRAY_BUFFER: stores vertex attribute data.
                               // GL_ELEMENT_ARRAY_BUFFER: stores index data.
                  GLsizeiptr size, // Size (in bytes) of the buffer to be allocated.
                  const GLvoid* data, // Pointer to the initial data to be copied to the buffer.
                  GLenum usage); // Expected buffer usage mode. The value can be one of the following:
                                // GL_STATIC_DRAW: The data is not or almost not modified and is used many times as the source for the drawing commands.
                               // GL_DYNAMIC_DRAW: The data is frequently modified and used many times as the source for the drawing commands.
                              // GL_STREAM_DRAW: The data is modified and is seldom used as the source for the drawing commands.
```

Once the **glBufferData** function is called, the data is copied to the OpenGL buffer object and stored in the GPU memory. This means that data can be efficiently accessed and processed on the GPU without frequent data transfer with the CPU memory.

```cpp
    const char* vertexShaderSource = R"(
        #version 320 es // Shader of OpenGL ES 3.2 is used.
        precision mediump float; // The floating point number uses the medium precision.
        layout (location = 0) in vec3 aPos; // Vertex attribute variable. The variable name is aPos, the type is vec3, and the index in the vertex shader is 0. This variable receives the vertex data from the VBO. Each time the vertex shader is called, aPos is set to the position of the currently processed vertex. (The data is obtained from the VBO and stored in the GPU.)
        void main() {
            // gl_Position, a built-in variable of OpenGL ES, specifies the final position of each vertex. The position is the coordinates in the clip space after perspective projection transformation.
            // After a value is assigned to gl_Position in the vertex shader, the rendering pipeline further processes the vertex and projects the vertex to the two-dimensional coordinates on the screen.
            // When w is a non-zero value, perspective division is performed on the vertex coordinates. That is, (x/w, y/w, z/w) in (x, y, z, w) is used as the final coordinates in the clip space.
            // Therefore, when the value of w is 1.0, perspective division does not change the coordinates.
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); 
        }
    )";
```
- Fragment is an element generated by rasterization. It represents a potential screen pixel, including all information related to the pixel, such as the color, depth, and stencil value. Each fragment is processed by a fragment shader, which also determines whether to write the fragment to the frame buffer.
- A fragment shader runs on each fragment. In this example, it is used to calculate the final color value of the fragment. It can access the interpolated vertex data and perform complex operations such as lighting calculation and texture sampling.

```cpp

const char* fragmentShaderSource = R"(
    #version 320 es // Shader of OpenGL ES 3.2 is used.
    precision mediump float; // The floating point number uses the medium precision.
    out vec4 FragColor; // Color of the output fragment.

    void main() {
        // Set the color of each fragment to vec4(1.0f, 0.5f, 0.2f, 1.0f),
        // indicating the red, green, blue, and alpha values, respectively.
        // This means that the output color is light orange, completely opaque.
        // The color here is not obtained from the vertex shader through rasterization by linear interpolation. It is directly assigned.
        FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    }
)";

```
In the OpenGL ES rendering pipeline, the following steps describe the entire process from vertex data to pixel output:

1. Vertex shader processing

   The vertex data in the buffer is passed into the vertex shader program and undergone the following processing:
   
   - Matrix transformation: uses the model view (MV) matrix and projection matrix to transform the vertex position.

   - Lighting calculation: calculates the color or other attributes of vertices based on the lighting formula.
   
2. Primitive assembly

   In the primitive assembly phase, the vertex data is assembled into geometric primitive, such as points, line segments, or triangles.

3. Rasterization

   Rasterization is performed to convert a geometric primitive (for example, a triangle) into a set of pixels on the screen. This process includes interpolation. Specifically, if a color or other attributes are set for a vertex, linear interpolation is performed on these attributes in the rasterization phase to generate fragment (pixel) data.

4. Fragment shader processing

   The fragment data output by rasterization is used as the input variable of the fragment shader. The following operations are carried out in the fragment shader:

   - Lighting calculation: calculates the lighting effect of a fragment.

   - Texture sampling: obtains color data from textures.

   - Color mixing: generates new colors, depths, and screen coordinates based on lighting and texture data.

5. Fragment-by-fragment processing

   The output of the fragment shader is then undergone fragment-by-fragment processing as follows:

   - Pixel ownership test: determines whether the fragment belongs to the current pixel area to draw.

   - Scissor test: determines whether the fragment is in the visible area.

   - Stencil test: uses the stencil buffer for test.

   - Depth-buffer test: compares the depth values of the fragment to determine whether it visible.

   - Blending: combines the newly calculated color with the existing color in the frame buffer.

   - Dithering: reduces color quantization errors by applying small, random, or ordered noise to the original image to distribute these quantization errors.

6. Writing the frame to the buffer

  After all the preceding tests and processing, the final fragment data is written into the frame buffer and displayed as an image on the screen.

### Creating and Using a Shader Program

```cpp
GLuint vertexShader, fragmentShader, shaderProgram;
// Create a vertex shader.
vertexShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
glCompileShader(vertexShader);

// Create a fragment shader.
fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
glCompileShader(fragmentShader);

// Create a shader program.
shaderProgram = glCreateProgram();
glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);
glLinkProgram(shaderProgram);

// Use the shader program.
glUseProgram(shaderProgram);
```

```cpp
GLuint glCreateShader(GLenum shaderType);
```
The **glCreateShader** function is used to create a shader object of a specified type and return a handle to the object. The **shaderType** parameter specifies the type of shader to create, which can be **GL_VERTEX_SHADER** (vertex shader) or **GL_FRAGMENT_SHADER** (fragment shader).

```cpp
void glShaderSource(GLuint shader, GLsizei count, const GLchar \**string, const GLint *length);
```

The **glShaderSource** function is used to set the source code of the shader object. The following parameters are available in the function:

- **shader**: identifier of the shader object for which the source code is set.
- **count**: number of source code strings.
- **string**: array of pointers to the source code strings.
- **length**: pointer to an integer array that contains the length of each source code string. The value can be a null pointer, indicating that each string ends with **null**.

```cpp
void glCompileShader(GLuint shader);
```

The **glCompileShader** function is used to compile a shader object, where the **shader** parameter is the identifier of the target shader object.

```cpp
GLuint glCreateProgram(void);
```

The **glCreateProgram** function is used to create a shader program object and return the object identifier.

```cpp
void glAttachShader(GLuint program, GLuint shader);
```

The **glAttachShader** function is used to attach a shader object to a shader program object. The **program** parameter is the identifier of the target shader program object, and the **shader** parameter is the identifier of the target shader object.

```cpp
void glLinkProgram(GLuint program);
```

The **glLinkProgram** function is used to link a shader program object, that is, to link the shader attached to the program object to an executable rendering pipeline.

The **program** parameter is the identifier of the target shader program object. After the shader program is linked, OpenGL merges the code in each individual shader object into an executable rendering pipeline, performs connector optimization to optimize the performance of the rendering pipeline, and binds the **Uniform** variable to the information about the Uniform block.

```cpp
void glUseProgram(GLuint program);
```
The **glUseProgram** function is used to activate a shader program object. After **glUseProgram** is called, all rendering calls are processed using the activated shader program.

You can use the following code to check whether the call of **glCompileShader** is normal:

```cpp
// Compile the shader.
glCompileShader(shader);

// Check the compilation status.
glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

if (!compiled)
{
    GLint infoLen = 0;

    // Obtain the length of the shader information log.
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

    if ( infoLen > 1 )
    {
        // Allocate the memory for storing the information log.
        char *infoLog = malloc(sizeof(char) * infoLen);

        // Obtain and print the shader information log.
        glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
        esLogMessage("Error compiling shader:\n%s\n", infoLog);

        // Release the allocated memory.
        free(infoLog);
    }

    // Delete the shader that fails to be compiled.
    glDeleteShader(shader);
    return 0;
}
```

You can use the following code to check whether the call of **glLinkProgram** is normal:

```cpp
// Link the program object.
glLinkProgram(programObject);

// Check the linking status.
glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

if (!linked)
{
    GLint infoLen = 0;

    // Obtain the length of the program object information log.
    glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

    if (infoLen > 1)
    {
        // Allocate the memory for storing the information log.
        char *infoLog = malloc(sizeof(char) * infoLen);

        // Obtain and print the information log of the program object.
        glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
        esLogMessage("Error linking program:\n%s\n", infoLog);

        // Release the allocated memory.
        free(infoLog);
    }

    // Delete the program object that fails to be linked.
    glDeleteProgram(programObject);
    return FALSE;
}
```

### Determining the Configuration of the Vertex Attribute Array

Determine the layout and format of the vertex attributes in the buffer.

```cpp
void glVertexAttribPointer(GLuint index, // Start index of the vertex array. The index is bound to the attribute variable in the vertex shader. (layout (location = 0) in vec3 aPos;)
                           GLint size, // Number of components of each vertex attribute.
                           GLenum type, // Type of each component.
                           GLboolean normalized, // Whether to map the vertex data to [0, 1] or [-1, 1] when accessing the data.
                           GLsizei stride, // Stride between the vertex attributes. For precision arrangement, set this parameter to 0.
                           const void *offset); // Offset of the attribute in the buffer. It is the position from which data reading starts in the buffer.
```

```cpp
void glEnableVertexAttribArray(GLuint index);
```

The **glEnableVertexAttribArray** function is used to enable an array of vertex attributes with a specified index. For example, call **glEnableVertexAttribArray(0)** to enable an array of vertex attributes with index 0. This array is associated with layout (location = 0) in vec3 aPos in the vertex shader program.

In the sample code, the first parameter **index** of **glVertexAttribPointer** corresponds to **aPos** in the vertex shader, that is, position 0. The other parameters set the format of the vertex attribute, telling OpenGL that the attribute contains three components (x, y, and z), the data type is GL_FLOAT, and the first attribute of each vertex starts from offset 0.

The **glBindBuffer** function binds the current VBO, **glBufferData** transfers vertex data to the GPU, and **glVertexAttribPointer** describes how to interpret the data. When using the VBO, vertex data is usually stored in a buffer. It is not automatically passed to the vertex shader. Therefore, the vertex attribute pointer is required to tell OpenGL ES how to interpret the data. The **glEnableVertexAttribArray** function is used to enable an array of vertex attributes at a specified position. For example, to enable an array of vertex properties at position 0, you can call **glEnableVertexAttribArray(0)**.


### Drawing and Displaying Graphics

```cpp
void glDrawArrays(GLenum mode, // Type of the graphic to draw. For example, GL_TRIANGLES indicates that a triangle will be drawn.
                  GLint first, // Start index of the vertex array to draw.
                  GLsizei count // Number of vertices to draw.
                  );
```

The **glDrawArrays** function is used to draw graphics based on the currently bound vertex array, vertex attributes, and other settings.

```cpp
EGLBoolean eglSwapBuffers(EGLDisplay dpy, // EGL display connection.
                          EGLSurface surface); // EGL surface whose buffers are to be swapped.
```

The **eglSwapBuffers** function is used to swap the front and back buffers and display the rendering result on the screen.
