# Vulkan模块


## 概述

提供OpenHarmony平台扩展的Vulkan能力，扩展了使用OHNativeWindow创建Vulkan Surface的能力，以及获取OH_NativeBuffer和OH_NativeBuffer属性的能力。

\@syscap SystemCapability.Graphic.Vulkan

**起始版本：**

10


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [vulkan_ohos.h](vulkan__ohos_8h.md) | 定义了OpenHarmony平台扩展的Vulkan接口。<br/>引用文件：&lt;vulkan/vulkan.h&gt;<br/>库：libvulkan.so  |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) | 包含创建Vulkan Surface时必要的参数。 |
| [VkNativeBufferUsageOHOS](_vk_native_buffer_usage_o_h_o_s.md) | 提供OpenHarmony NativeBuffer用途的说明。 |
| [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) | 包含了NativeBuffer的属性。 |
| [VkNativeBufferFormatPropertiesOHOS](_vk_native_buffer_format_properties_o_h_o_s.md) | 包含了NativeBuffer的一些格式属性。 |
| [VkImportNativeBufferInfoOHOS](_vk_import_native_buffer_info_o_h_o_s.md) | 包含了OH_NativeBuffer结构体的指针。 |
| [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) | 用于从Vulkan内存中获取OH_NativeBuffer。 |
| [VkExternalFormatOHOS](_vk_external_format_o_h_o_s.md) | 表示外部定义的格式标识符。 |


### 宏定义

| 名称 | 描述 |
| -------- | -------- |
| [VK_OHOS_surface](#vk_ohos_surface)   1 | OpenHarmony平台Surface扩展宏定义。 |
| [VK_OHOS_SURFACE_SPEC_VERSION](#vk_ohos_surface_spec_version)   1 | OpenHarmony平台Surface扩展版本号。 |
| [VK_OHOS_SURFACE_EXTENSION_NAME](#vk_ohos_surface_extension_name)   "VK_OHOS_surface" | OpenHarmony平台Surface扩展名。 |
| [VK_OHOS_external_memory](#vk_ohos_external_memory)   1 | OpenHarmony平台external_memory扩展宏定义。 |
| [VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION](#vk_ohos_external_memory_spec_version)   1 | OpenHarmony平台external_memory扩展版本号。 |
| [VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME](#vk_ohos_external_memory_extension_name)   "VK_OHOS_external_memory" | OpenHarmony平台external_memory扩展名。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OHNativeWindow](#ohnativewindow) | OH本地窗口。 |
| [VkSurfaceCreateFlagsOHOS](#vksurfacecreateflagsohos) | 用于Vulkan Surface创建时使用到的VkFlags类型位掩码，预留的标志类型。 |
| [VkSurfaceCreateInfoOHOS](#vksurfacecreateinfoohos) | 包含创建Vulkan Surface时必要的参数。 |
| VkResult ([VKAPI_PTR *PFN_vkCreateSurfaceOHOS](#pfn_vkcreatesurfaceohos)) (VkInstance instance, const [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) \*pCreateInfo, const VkAllocationCallbacks \*pAllocator, VkSurfaceKHR \*pSurface) | 创建Vulkan Surface的函数指针定义。 |
| [VkNativeBufferUsageOHOS](#vknativebufferusageohos) | 提供OpenHarmony NativeBuffer用途的说明。 |
| [VkNativeBufferPropertiesOHOS](#vknativebufferpropertiesohos) | 包含了NativeBuffer的属性。 |
| [VkNativeBufferFormatPropertiesOHOS](#vknativebufferformatpropertiesohos) | 包含了NativeBuffer的一些格式属性。 |
| [VkImportNativeBufferInfoOHOS](#vkimportnativebufferinfoohos) | 包含了OH_NativeBuffer结构体的指针。 |
| [VkMemoryGetNativeBufferInfoOHOS](#vkmemorygetnativebufferinfoohos) | 用于从Vulkan内存中获取OH_NativeBuffer。 |
| [VkExternalFormatOHOS](#vkexternalformatohos) | 表示外部定义的格式标识符。 |
| VkResult ([VKAPI_PTR *PFN_vkGetNativeBufferPropertiesOHOS](#pfn_vkgetnativebufferpropertiesohos)) (VkDevice device, const struct OH_NativeBuffer \*buffer, [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) \*pProperties) | 获取OH_NativeBuffer属性的函数指针定义。 |
| VkResult ([VKAPI_PTR *PFN_vkGetMemoryNativeBufferOHOS](#pfn_vkgetmemorynativebufferohos)) (VkDevice device, const [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) \*pInfo, struct OH_NativeBuffer \*\*pBuffer) | 获取OH_NativeBuffer的函数指针定义。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| VKAPI_ATTR VkResult VKAPI_CALL [vkCreateSurfaceOHOS](#vkcreatesurfaceohos) (VkInstance instance, const [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) \*pCreateInfo, const VkAllocationCallbacks \*pAllocator, VkSurfaceKHR \*pSurface) | 创建Vulkan Surface。 | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkGetNativeBufferPropertiesOHOS](#vkgetnativebufferpropertiesohos) (VkDevice device, const struct OH_NativeBuffer \*buffer, [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) \*pProperties) | 获取OH_NativeBuffer属性。 | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkGetMemoryNativeBufferOHOS](#vkgetmemorynativebufferohos) (VkDevice device, const [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) \*pInfo, struct OH_NativeBuffer \*\*pBuffer) | 获取OH_NativeBuffer。 | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkGetSwapchainGrallocUsageOHOS](#vkgetswapchaingrallocusageohos) (VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t \*grallocUsage) | 根据给定的Vulkan设备、图像格式和图像使用标志, 返回适当的Gralloc(内存分配器)使用标志。 | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkAcquireImageOHOS](#vkacquireimageohos) (VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence) | 用于获取交换链图像的所有权, 并将外部信号的Fence导入到VkSemaphore对象和VkFence对象中。 | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkQueueSignalReleaseImageOHOS](#vkqueuesignalreleaseimageohos) (VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore \*pWaitSemaphores, VkImage image, int32_t \*pNativeFenceFd) | 当前图像使用完毕后，通过该函数向系统硬件缓冲区发出释放信号, 以便其他组件可以访问该图像。 | 


### 变量

| 名称 | 描述 |
| -------- | -------- |
| [VkSurfaceCreateInfoOHOS::sType](#stype-17) | 结构体类型。 |
| [VkSurfaceCreateInfoOHOS::pNext](#pnext-17) | 下一级结构体指针。 |
| [VkSurfaceCreateInfoOHOS::flags](#flags) | 预留的标志类型参数。 |
| [VkSurfaceCreateInfoOHOS::window](#window) | OHNativeWindow指针。 |
| [VkNativeBufferUsageOHOS::sType](#stype-27) | 结构体类型。 |
| [VkNativeBufferUsageOHOS::pNext](#pnext-27) | 下一级结构体指针。 |
| [VkNativeBufferUsageOHOS::OHOSNativeBufferUsage](#ohosnativebufferusage) | NativeBuffer的用途说明。 |
| [VkNativeBufferPropertiesOHOS::sType](#stype-37) | 结构体类型。 |
| [VkNativeBufferPropertiesOHOS::pNext](#pnext-37) | 下一级结构体指针。 |
| [VkNativeBufferPropertiesOHOS::allocationSize](#allocationsize) | 占用的内存大小。 |
| [VkNativeBufferPropertiesOHOS::memoryTypeBits](#memorytypebits) | 内存类型。 |
| [VkNativeBufferFormatPropertiesOHOS::sType](#stype-47) | 结构体类型。 |
| [VkNativeBufferFormatPropertiesOHOS::pNext](#pnext-47) | 下一级结构体指针。 |
| [VkNativeBufferFormatPropertiesOHOS::format](#format) | 格式说明。 |
| [VkNativeBufferFormatPropertiesOHOS::externalFormat](#externalformat-12) | 外部定义的格式标识符。 |
| [VkNativeBufferFormatPropertiesOHOS::formatFeatures](#formatfeatures) | 描述了与externalFormat对应的能力。 |
| [VkNativeBufferFormatPropertiesOHOS::samplerYcbcrConversionComponents](#samplerycbcrconversioncomponents) | 表示一组VkComponentSwizzle。 |
| [VkNativeBufferFormatPropertiesOHOS::suggestedYcbcrModel](#suggestedycbcrmodel) | 色彩模型。 |
| [VkNativeBufferFormatPropertiesOHOS::suggestedYcbcrRange](#suggestedycbcrrange) | 色彩数值范围。 |
| [VkNativeBufferFormatPropertiesOHOS::suggestedXChromaOffset](#suggestedxchromaoffset) | X色度偏移。 |
| [VkNativeBufferFormatPropertiesOHOS::suggestedYChromaOffset](#suggestedychromaoffset) | Y色度偏移。 |
| [VkImportNativeBufferInfoOHOS::sType](#stype-57) | 结构体类型。 |
| [VkImportNativeBufferInfoOHOS::pNext](#pnext-57) | 下一级结构体指针。 |
| [VkImportNativeBufferInfoOHOS::buffer](#buffer) | OH_NativeBuffer结构体的指针。 |
| [VkMemoryGetNativeBufferInfoOHOS::sType](#stype-67) | 结构体类型。 |
| [VkMemoryGetNativeBufferInfoOHOS::pNext](#pnext-67) | 下一级结构体指针。 |
| [VkMemoryGetNativeBufferInfoOHOS::memory](#memory) | VkDeviceMemory对象。 |
| [VkExternalFormatOHOS::sType](#stype-77) | 结构体类型。 |
| [VkExternalFormatOHOS::pNext](#pnext-77) | 下一级结构体指针。 |
| [VkExternalFormatOHOS::externalFormat](#externalformat-22) | 外部定义的格式标识符。 |


## 宏定义说明


### VK_OHOS_external_memory


```
#define VK_OHOS_external_memory   1
```

**描述:**

OpenHarmony平台external_memory扩展宏定义。


### VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME


```
#define VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME   "VK_OHOS_external_memory"
```

**描述:**

OpenHarmony平台external_memory扩展名。


### VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION


```
#define VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION   1
```

**描述:**

OpenHarmony平台external_memory扩展版本号。


### VK_OHOS_surface


```
#define VK_OHOS_surface   1
```

**描述:**

OpenHarmony平台Surface扩展宏定义。


### VK_OHOS_SURFACE_EXTENSION_NAME


```
#define VK_OHOS_SURFACE_EXTENSION_NAME   "VK_OHOS_surface"
```

**描述:**

OpenHarmony平台Surface扩展名。


### VK_OHOS_SURFACE_SPEC_VERSION


```
#define VK_OHOS_SURFACE_SPEC_VERSION   1
```

**描述:**

OpenHarmony平台Surface扩展版本号。


## 类型定义说明


### OHNativeWindow


```
typedef struct NativeWindow OHNativeWindow
```

**描述:**

OH本地窗口。


### PFN_vkCreateSurfaceOHOS


```
typedef VkResult(VKAPI_PTR * PFN_vkCreateSurfaceOHOS) (VkInstance instance, const VkSurfaceCreateInfoOHOS *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSurfaceKHR *pSurface)
```

**描述:**

创建Vulkan Surface的函数指针定义。

\@syscap SystemCapability.Graphic.Vulkan

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| instance | Vulkan实例。 |
| pCreateInfo | 一个VkSurfaceCreateInfoOHOS结构体的指针，包含创建Vulkan Surface时必要的参数。 |
| pAllocator | 用户自定义内存分配的回调函数，如果不需要可以传入NULL，接口会使用默认的内存分配函数。 |
| pSurface | 出参，用于接收创建的Vulkan Surface，类型为VkSurfaceKHR。 |

**返回:**

返回一个VkResult类型的错误码，返回值为VK_SUCCESS表示执行成功。


### PFN_vkGetMemoryNativeBufferOHOS


```
typedef VkResult(VKAPI_PTR * PFN_vkGetMemoryNativeBufferOHOS) (VkDevice device, const VkMemoryGetNativeBufferInfoOHOS *pInfo, struct OH_NativeBuffer **pBuffer)
```

**描述:**

获取OH_NativeBuffer的函数指针定义。

\@syscap SystemCapability.Graphic.Vulkan

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device | VkDevice对象。 |
| pInfo | VkMemoryGetNativeBufferInfoOHOS结构体对象。 |
| pBuffer | 用于接收获取到的OH_NativeBuffer。 |

**返回:**

返回一个VkResult类型的错误码，返回值为VK_SUCCESS表示执行成功。


### PFN_vkGetNativeBufferPropertiesOHOS


```
typedef VkResult(VKAPI_PTR * PFN_vkGetNativeBufferPropertiesOHOS) (VkDevice device, const struct OH_NativeBuffer *buffer, VkNativeBufferPropertiesOHOS *pProperties)
```

**描述:**

获取OH_NativeBuffer属性的函数指针定义。

\@syscap SystemCapability.Graphic.Vulkan

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device | VkDevice对象。 |
| buffer | OH_NativeBuffer结构体指针。 |
| pProperties | 用于接收OH_NativeBuffer属性的结构体。 |

**返回:**

返回一个VkResult类型的错误码，返回值为VK_SUCCESS表示执行成功。


### VkExternalFormatOHOS


```
typedef struct VkExternalFormatOHOS VkExternalFormatOHOS
```

**描述:**

表示外部定义的格式标识符。


### VkImportNativeBufferInfoOHOS


```
typedef struct VkImportNativeBufferInfoOHOS VkImportNativeBufferInfoOHOS
```

**描述:**

包含了OH_NativeBuffer结构体的指针。


### VkMemoryGetNativeBufferInfoOHOS


```
typedef struct VkMemoryGetNativeBufferInfoOHOS VkMemoryGetNativeBufferInfoOHOS
```

**描述:**

用于从Vulkan内存中获取OH_NativeBuffer。


### VkNativeBufferFormatPropertiesOHOS


```
typedef struct VkNativeBufferFormatPropertiesOHOS VkNativeBufferFormatPropertiesOHOS
```

**描述:**

包含了NativeBuffer的一些格式属性。


### VkNativeBufferPropertiesOHOS


```
typedef struct VkNativeBufferPropertiesOHOS VkNativeBufferPropertiesOHOS
```

**描述:**

包含了NativeBuffer的属性。


### VkNativeBufferUsageOHOS


```
typedef struct VkNativeBufferUsageOHOS VkNativeBufferUsageOHOS
```

**描述:**

提供OpenHarmony NativeBuffer用途的说明。


### VkSurfaceCreateFlagsOHOS


```
typedef VkFlags VkSurfaceCreateFlagsOHOS
```

**描述:**

用于Vulkan Surface创建时使用到的VkFlags类型位掩码，预留的标志类型。


### VkSurfaceCreateInfoOHOS


```
typedef struct VkSurfaceCreateInfoOHOS VkSurfaceCreateInfoOHOS
```

**描述:**

包含创建Vulkan Surface时必要的参数。


## 函数说明


### vkAcquireImageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireImageOHOS (VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence )
```

**描述**

用于获取交换链图像的所有权, 并将外部信号的Fence导入到VkSemaphore对象和VkFence对象中。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| device | VkDevice对象。 | 
| image | 要获取的Vulkan图像。 | 
| nativeFenceFd | 原生Fence的文件描述符。 | 
| semaphore | 表示图像可用状态的Vulkan Semaphore(信号量)。 | 
| fence | 用于在图像获取完成时进行同步的Vulkan Fence。 | 

**返回：**

返回一个VkResult类型的错误码，具体返回类型如下：
返回VK_SUCCESS，表示执行成功。
返回VK_ERROR_OUT_OF_HOST_MEMORY，表示主机内存不足。

### vkCreateSurfaceOHOS()


```
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSurfaceOHOS (VkInstance instance, const VkSurfaceCreateInfoOHOS * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface )
```

**描述:**

创建Vulkan Surface。

\@syscap SystemCapability.Graphic.Vulkan

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| instance | Vulkan实例。 |
| pCreateInfo | 一个VkSurfaceCreateInfoOHOS结构体的指针，包含创建Vulkan Surface时必要的参数。 |
| pAllocator | 用户自定义内存分配的回调函数，如果不需要可以传入NULL，接口会使用默认的内存分配函数。 |
| pSurface | 出参，用于接收创建的Vulkan Surface，类型为VkSurfaceKHR。 |

**返回:**

返回一个VkResult类型的错误码，具体返回类型如下：
返回VK_SUCCESS，表示执行成功。
返回VK_ERROR_OUT_OF_HOST_MEMORY，表示分配VkSurfaceKHR内存失败。
返回VK_ERROR_SURFACE_LOST_KHR，表示操作NativeWindow失败。


### vkGetMemoryNativeBufferOHOS()


```
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryNativeBufferOHOS (VkDevice device, const VkMemoryGetNativeBufferInfoOHOS * pInfo, struct OH_NativeBuffer ** pBuffer )
```

**描述:**

获取OH_NativeBuffer。

\@syscap SystemCapability.Graphic.Vulkan

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device | VkDevice对象。 |
| pInfo | VkMemoryGetNativeBufferInfoOHOS结构体对象。 |
| pBuffer | 用于接收获取到的OH_NativeBuffer。 |

**返回:**

返回一个VkResult类型的错误码，具体返回类型如下：
返回VK_SUCCESS，表示执行成功。
返回VK_ERROR_OUT_OF_HOST_MEMORY，表示pInfo入参异常，或获取的pBuffer异常。

### vkGetNativeBufferPropertiesOHOS()


```
VKAPI_ATTR VkResult VKAPI_CALL vkGetNativeBufferPropertiesOHOS (VkDevice device, const struct OH_NativeBuffer * buffer, VkNativeBufferPropertiesOHOS * pProperties )
```

**描述:**

获取OH_NativeBuffer属性。

\@syscap SystemCapability.Graphic.Vulkan

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device | VkDevice对象。 |
| buffer | OH_NativeBuffer结构体指针。 |
| pProperties | 用于接收OH_NativeBuffer属性的结构体。 |

**返回:**

返回一个VkResult类型的错误码，具体返回类型如下：
返回VK_SUCCESS，表示执行成功。
返回VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR，表示入参存在异常。
返回VK_ERROR_OUT_OF_DEVICE_MEMORY，表示设备内存不足。


### vkGetSwapchainGrallocUsageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainGrallocUsageOHOS (VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t* grallocUsage )
```

**描述**

根据给定的Vulkan设备、图像格式和图像使用标志, 返回适当的Gralloc(内存分配器)使用标志。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| device | VkDevice对象。 | 
| format | 图像格式。 | 
| imageUsage | 图像使用标志。 | 
| grallocUsage | 出参, 返回Gralloc(内存分配器)使用标志。 | 

**返回：**

返回一个VkResult类型的错误码，具体返回类型如下：
返回VK_SUCCESS，表示执行成功。
返回VK_ERROR_INITIALIZATION_FAILED，表示入参异常。

### vkQueueSignalReleaseImageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSignalReleaseImageOHOS (VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int32_t* pNativeFenceFd )
```

**描述**

当前图像使用完毕后，通过该函数向系统硬件缓冲区发出释放信号, 以便其他组件可以访问该图像。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| queue | Vulkan队列的句柄。 | 
| waitSemaphoreCount | 等待Semaphore(信号量)的数量。 | 
| pWaitSemaphores | 指向等待Semaphore(信号量)数组的指针。 | 
| images | 要释放的Vulkan图像句柄。 | 
| pNativeFenceFd | 指向Fence的文件描述符的指针。 | 

**返回：**

返回一个VkResult类型的错误码，具体返回类型如下：
返回VK_SUCCESS，表示执行成功。
返回VK_ERROR_DEVICE_LOST，表示Vulkan设备链接丢失。
返回VK_ERROR_OUT_OF_HOST_MEMORY，表示主机内存不足。

## 变量说明


### allocationSize


```
VkDeviceSize VkNativeBufferPropertiesOHOS::allocationSize
```

**描述:**

占用的内存大小。


### buffer


```
struct OH_NativeBuffer* VkImportNativeBufferInfoOHOS::buffer
```

**描述:**

OH_NativeBuffer结构体的指针。


### externalFormat [1/2]


```
uint64_t VkNativeBufferFormatPropertiesOHOS::externalFormat
```

**描述:**

外部定义的格式标识符。


### externalFormat [2/2]


```
uint64_t VkExternalFormatOHOS::externalFormat
```

**描述:**

外部定义的格式标识符。


### flags


```
VkSurfaceCreateFlagsOHOS VkSurfaceCreateInfoOHOS::flags
```

**描述:**

预留的标志类型参数。


### format


```
VkFormat VkNativeBufferFormatPropertiesOHOS::format
```

**描述:**

格式说明。


### formatFeatures


```
VkFormatFeatureFlags VkNativeBufferFormatPropertiesOHOS::formatFeatures
```

**描述:**

描述了与externalFormat对应的能力。


### memory


```
VkDeviceMemory VkMemoryGetNativeBufferInfoOHOS::memory
```

**描述:**

VkDeviceMemory对象。


### memoryTypeBits


```
uint32_t VkNativeBufferPropertiesOHOS::memoryTypeBits
```

**描述:**

内存类型。


### OHOSNativeBufferUsage


```
uint64_t VkNativeBufferUsageOHOS::OHOSNativeBufferUsage
```

**描述:**

NativeBuffer的用途说明。


### pNext [1/7]


```
const void* VkSurfaceCreateInfoOHOS::pNext
```

**描述:**

下一级结构体指针。


### pNext [2/7]


```
void* VkNativeBufferUsageOHOS::pNext
```

**描述:**

下一级结构体指针。


### pNext [3/7]


```
void* VkNativeBufferPropertiesOHOS::pNext
```

**描述:**

下一级结构体指针。


### pNext [4/7]


```
void* VkNativeBufferFormatPropertiesOHOS::pNext
```

**描述:**

下一级结构体指针。


### pNext [5/7]


```
const void* VkImportNativeBufferInfoOHOS::pNext
```

**描述:**

下一级结构体指针。


### pNext [6/7]


```
const void* VkMemoryGetNativeBufferInfoOHOS::pNext
```

**描述:**

下一级结构体指针。


### pNext [7/7]


```
void* VkExternalFormatOHOS::pNext
```

**描述:**

下一级结构体指针。


### samplerYcbcrConversionComponents


```
VkComponentMapping VkNativeBufferFormatPropertiesOHOS::samplerYcbcrConversionComponents
```

**描述:**

表示一组VkComponentSwizzle。


### sType [1/7]


```
VkStructureType VkSurfaceCreateInfoOHOS::sType
```

**描述:**

结构体类型。


### sType [2/7]


```
VkStructureType VkNativeBufferUsageOHOS::sType
```

**描述:**

结构体类型。


### sType [3/7]


```
VkStructureType VkNativeBufferPropertiesOHOS::sType
```

**描述:**

结构体类型。


### sType [4/7]


```
VkStructureType VkNativeBufferFormatPropertiesOHOS::sType
```

**描述:**

结构体类型。


### sType [5/7]


```
VkStructureType VkImportNativeBufferInfoOHOS::sType
```

**描述:**

结构体类型。


### sType [6/7]


```
VkStructureType VkMemoryGetNativeBufferInfoOHOS::sType
```

**描述:**

结构体类型。


### sType [7/7]


```
VkStructureType VkExternalFormatOHOS::sType
```

**描述:**

结构体类型。


### suggestedXChromaOffset


```
VkChromaLocation VkNativeBufferFormatPropertiesOHOS::suggestedXChromaOffset
```

**描述:**

X色度偏移。


### suggestedYcbcrModel


```
VkSamplerYcbcrModelConversion VkNativeBufferFormatPropertiesOHOS::suggestedYcbcrModel
```

**描述:**

色彩模型。


### suggestedYcbcrRange


```
VkSamplerYcbcrRange VkNativeBufferFormatPropertiesOHOS::suggestedYcbcrRange
```

**描述:**

色彩数值范围。


### suggestedYChromaOffset


```
VkChromaLocation VkNativeBufferFormatPropertiesOHOS::suggestedYChromaOffset
```

**描述:**

Y色度偏移。


### window


```
OHNativeWindow* VkSurfaceCreateInfoOHOS::window
```

**描述:**

OHNativeWindow指针。
