# Vulkan Development

## When to Use

Vulkan is a set of graphics APIs for 2D and 3D rendering. To start with, you need to create a **VkSurfaceKHR** instance, which works with the **OHNativeWindow** module to implement buffer recycling.

A **VkSurfaceKHR** instance is obtained through an **OHNativeWindow**, which is obtained from the **XComponent**. Therefore, the **OHNativeWindow** module must be used together with the **XComponent** and **NativeWindow** modules.

## Available APIs

| API                                                      | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| vkCreateSurfaceOHOS (VkInstance instance, const VkSurfaceCreateInfoOHOS\* pCreateInfo, const VkAllocationCallbacks\* pAllocator, VkSurfaceKHR\* pSurface) | Creates a **VkSurfaceKHR** instance.|

For details about the APIs, see [Vulkan](vulkan.md).

## How to Develop

The following steps illustrate how to create a **VkSurfaceKHR** instance.

To use the extended APIs, define the macro **VK_USE_PLATFORM_OHOS** in the **CMakeLists.txt** file.

```txt
ADD_DEFINITIONS(-DVK_USE_PLATFORM_OHOS=1)
```

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**:

```txt
libace_ndk.z.so
libnative_window.so
libvulkan.so
```

> **NOTE**
>
> When the **dlopen** function is used to link the **libvulkan.so** dynamic library in a program, you do not need to add dependencies in CMake. Otherwise, symbol conflicts occur.

**Including Header Files**

```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <native_window/external_window.h>
#include <vulkan/vulkan.h>
```

1. Create a Vulkan instance.

   ```c++
   VkInstance instance = VK_NULL_HANDLE;
   
   VkApplicationInfo appInfo = {};
   appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
   appInfo.pApplicationName = "vulkanExample";
   appInfo.pEngineName = "vulkanExample";
   appInfo.apiVersion = VK_API_VERSION_1_3;
   
   VkInstanceCreateInfo instanceCreateInfo = {};
   instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
   instanceCreateInfo.pNext = NULL;
   instanceCreateInfo.pApplicationInfo = &appInfo;
   
   std::vector<const char *> instanceExtensions = {
       VK_KHR_SURFACE_EXTENSION_NAME,
       VK_OHOS_SURFACE_EXTENSION_NAME // Surface extension.
   };
   instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExtensions.size());
   instanceCreateInfo.ppEnabledExtensionNames = instanceExtensions.data();
   
   vkCreateInstance(&instanceCreateInfo, nullptr, &instance);
   ```

2. Obtain an **OHNativeWindow** instance.

   The **OHNativeWindow** instance is obtained from the **XComponent**. For details about how to use the **XComponent**, see [Custom Rendering (XComponent)](../../ui/napi-xcomponent-guidelines.md).

   1. Add an **XComponent** to **ets/pages/Index.ets**.

      ```ts
      XComponent({
          id: 'xcomponentId',
          type: 'surface',
          libraryname: 'entry'
      })
      .margin({ bottom: 20 })
      .width(360)
      .height(360)
      ```

   2. Obtain an **OHNativeWindow** instance from the **XComponent**.

      ```c++
      // Callback function of the XComponent triggered when a surface is created.
      void OnSurfaceCreatedCB(OH_NativeXComponent *component, void *window) {
          // You can obtain an OHNativeWindow instance from the callback function.
          OHNativeWindow *nativeWindow = static_cast<OHNativeWindow *>(window);
      }
      
      static napi_value Init(napi_env env, napi_value exports) {
          napi_property_descriptor desc[] = {{"add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr}};
          napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
      
          napi_value exportInstance = nullptr;
          OH_NativeXComponent *nativeXComponent = nullptr;
          // Obtain a native XComponent.
          napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);
          napi_unwrap(env, exportInstance, reinterpret_cast<void **>(&nativeXComponent));
          // Obtain the XComponent ID.
          char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
          uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
          OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize);
      
          // Declare an XComponent callback.
          OH_NativeXComponent_Callback callback;
          // Register the OnSurfaceCreated callback function.
          callback.OnSurfaceCreated = OnSurfaceCreatedCB;
          // Register the callback function for the native XComponent.
          OH_NativeXComponent_RegisterCallback(nativeXComponent, &callback);
      
          return exports;
      }
      ```

3. Create a **VkSurfaceKHR** instance.

   ```c++
   VkSurfaceKHR surface = VK_NULL_HANDLE;
   VkSurfaceCreateInfoOHOS surfaceCreateInfo = {};
   surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_SURFACE_CREATE_INFO_OHOS;
   surfaceCreateInfo.window = nativeWindow; // nativeWindow is obtained from the OnSurfaceCreatedCB callback function in the previous step.
   int err = vkCreateSurfaceOHOS(instance, &surfaceCreateInfo, NULL, &surface);
   if (err != VK_SUCCESS) {
       // Creating the surface failed.
   }
   ```

For details about how to use Vulkan, visit the [Vulkan official website](https://www.vulkan.org/).
