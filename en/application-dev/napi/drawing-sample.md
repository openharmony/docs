# Drawing and Display Sample

## Overview
You have learned how to call the APIs provided by **NativeDrawing** to draw 2D graphics in [Drawing Development](drawing-guidelines.md). In this topic, you will learn how to display 2D graphics on the screen by using the capabilities provided by **NativeWindow** and **\<XComponent>**.

## How to Develop

The following walks you through on how to use the canvas and brush of the **NativeDrawing** module to draw a basic 2D graphic, write the graphics content to the buffer provided by **NativeWindow**, and flush the buffer to the graphics queue. During this process, the **\<XComponent>** is used to connect the C++ code layer to the ArkTS layer so that the drawing and display logic is called at the ArkTS layer to display the graphic on the screen.

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**:
```txt
libace_napi.z.so
libace_ndk.z.so
libnative_window.so
libnative_drawing.so
```

**Including Header Files**
```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include "napi/native_api.h"
#include <native_window/external_window.h>
#include <native_drawing/drawing_bitmap.h>
#include <native_drawing/drawing_color.h>
#include <native_drawing/drawing_canvas.h>
#include <native_drawing/drawing_pen.h>
#include <native_drawing/drawing_brush.h>
#include <native_drawing/drawing_path.h>
#include <cmath>
#include <algorithm>
#include <stdint.h>
#include <sys/mman.h>
```

1. Obtain an **OHNativeWindow** instance as the carrier for displaying the graphic.

    1. Add an **\<XComponent>** to the .ets file.
        ```ts
        XComponent({ id: 'xcomponentId', type: 'surface', libraryname: 'entry'})
        ```
    2. Obtain **NativeXComponent** at the native C++ layer.
        ```c++
        // Obtain the ID of the <XComponent>.
        char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
        uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
        napi_value exportInstance = nullptr;
        // Parse the attribute of the wrapped NativeXComponent pointer.
        napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);
        OH_NativeXComponent *nativeXComponent = nullptr;
        // Use the napi_unwrap API to parse the NativeXComponent instance pointer.
        napi_unwrap(env, exportInstance, reinterpret_cast<void**>(&nativeXComponent));
        ```
     3. Define **OH_NativeXComponent_Callback**.
        ```c++
        // Declare a NativeXComponent callback.
        OH_NativeXComponent_Callback callback;
        // Register the OnSurfaceCreated callback function.
        callback.OnSurfaceCreated = OnSurfaceCreatedCB;
        ```
     4. Register **OH_NativeXComponent_Callback** with **NativeXComponent**.
        ```c++
        // Register the callback function and implement the drawing and display logic in it. When the <XComponent> at the ArkTS layer is called, the logic is invoked through the callback function.
        OH_NativeXComponent_RegisterCallback(nativeXComponent, &callback);
        ```

2. Obtain the **OHNativeWindow** instance, which is used as the carrier for displaying the graphic.
    1. Set the attributes of an **OHNativeWindowBuffer** by using **OH_NativeWindow_NativeWindowHandleOpt**.
        ```c++
        // Obtain an OHNativeWindow instance.
        OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
    
        // Set the width and height of the OHNativeWindowBuffer.
        int32_t code = SET_BUFFER_GEOMETRY;
        uint64_t width;
        uint64_t height;
        int32_t ret = OH_NativeXComponent_GetXComponentSize(component, window, &width, &height);
        // The nativeWindow instance is obtained from the callback in the previous step.
        ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, width, height);
        // Set the step of the OHNativeWindowBuffer.
        code = SET_STRIDE;
        int32_t stride = 0x8;
    
        ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, stride);
        ```
    2. Request an **OHNativeWindowBuffer** from the graphics queue.
        ```c++
        OHNativeWindowBuffer* buffer = nullptr;
        int fenceFd;
        // Obtain the OHNativeWindowBuffer instance by calling OH_NativeWindow_NativeWindowRequestBuffer.
        OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &buffer, &fenceFd);
        // Obtain the buffer handle by calling OH_NativeWindow_GetBufferHandleFromNative.
        BufferHandle* bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(buffer);
        ```
    3. Map memory.
        ```c++
        // Use mmap() to obtain the memory virtual address of the buffer handle.
        uint8_t *mappedAddr = static_cast<uint8_t *>(mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0));
        if (mappedAddr == MAP_FAILED) {
            // mmap failed
        }
        ```
    
3. Use the APIs provided by **NativeDrawing** to draw a pentagon-shaped 2D graphic. For details, see [Drawing Development](drawing-guidelines.md).

4. Use the APIs provided by **NativeWindow** to display the 2D graphic on the screen.
    1. Write the drawing content to the **OHNativeWindowBuffer**.
        ```c++
        uint8_t *bitmapAddr = static_cast<uint8_t *>(OH_Drawing_BitmapGetPixels(cBitmap));
        std::copy(bitmapAddr, bitmapAddr + (width * height * 4), mappedAddr);
        ```
    2. Flush the **OHNativeWindowBuffer** to the graphics queue.
        ```c++
        // Set the refresh region. If Rect in Region is a null pointer or rectNumber is 0, all contents in the OHNativeWindowBuffer are changed.
        Region region{nullptr, 0};
        // Flush the buffer to the consumer through OH_NativeWindow_NativeWindowFlushBuffer, for example, by displaying it on the screen.
        OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, fenceFd, region);
        ```
    3. Unmap memory.
        ```c++
        // Unmap the memory when the memory is no longer required.
        int result = munmap(mappedAddr, bufferHandle->size);
        if (result == -1) {
            // munmap failed
        }
        ```

    The figure below shows the display effect of the graphic.
    
    ![Drawing](figures/drawing.png)
    
