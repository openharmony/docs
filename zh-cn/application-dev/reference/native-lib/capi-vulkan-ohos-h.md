# vulkan_ohos.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @andrew1993-->
<!--Designer: @ext4FAT1-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

定义了OpenHarmony平台扩展的Vulkan接口。

**引用文件：** <vulkan/vulkan_ohos.h>

**库：** libvulkan.so

**起始版本：** 10

**相关模块：** [Vulkan](capi-vulkan.md)

## 汇总

### 结构体

| 名称                                                                                      | typedef关键字                         | 描述                               |
|-----------------------------------------------------------------------------------------|------------------------------------|----------------------------------|
| [VkSurfaceCreateInfoOHOS](capi-vulkan-vksurfacecreateinfoohos.md)                       | VkSurfaceCreateInfoOHOS            | 包含创建Vulkan Surface时必要的参数。        |
| [VkNativeBufferUsageOHOS](capi-vulkan-vknativebufferusageohos.md)                       | VkNativeBufferUsageOHOS            | 提供OpenHarmony NativeBuffer用途的说明。 |
| [VkNativeBufferPropertiesOHOS](capi-vulkan-vknativebufferpropertiesohos.md)             | VkNativeBufferPropertiesOHOS       | 包含了NativeBuffer的属性。              |
| [VkNativeBufferFormatPropertiesOHOS](capi-vulkan-vknativebufferformatpropertiesohos.md) | VkNativeBufferFormatPropertiesOHOS | 包含了NativeBuffer的一些格式属性。          |
| [VkImportNativeBufferInfoOHOS](capi-vulkan-vkimportnativebufferinfoohos.md)             | VkImportNativeBufferInfoOHOS       | 包含了OH_NativeBuffer结构体的指针。        |
| [VkMemoryGetNativeBufferInfoOHOS](capi-vulkan-vkmemorygetnativebufferinfoohos.md)       | VkMemoryGetNativeBufferInfoOHOS    | 用于从Vulkan内存中获取OH_NativeBuffer。   |
| [VkExternalFormatOHOS](capi-vulkan-vkexternalformatohos.md)                             | VkExternalFormatOHOS               | 表示外部定义的格式标识符。                    |
| [NativeWindow](capi-vulkan-nativewindow.md)                                             | OHNativeWindow                     | 本地窗口。                            |
| [OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)                                   | -                                  | OH_NativeBuffer结构体声明。                                 |

### 宏定义

| 名称 | 描述 |
| -- | -- |
| VK_OHOS_surface 1 | OpenHarmony平台Surface扩展宏定义。<br>**起始版本：** 10 |
| VK_OHOS_SURFACE_SPEC_VERSION      1 | OpenHarmony平台Surface扩展版本号。<br>**起始版本：** 10 |
| VK_OHOS_SURFACE_EXTENSION_NAME    "VK_OHOS_surface" | OpenHarmony平台Surface扩展名。<br>**起始版本：** 10 |
| VK_OHOS_external_memory 1 | OpenHarmony平台external_memory扩展宏定义。<br>**起始版本：** 10 |
| VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION 1 | OpenHarmony平台external_memory扩展版本号。<br>**起始版本：** 10 |
| VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME "VK_OHOS_external_memory" | OpenHarmony平台external_memory扩展名。<br>**起始版本：** 10 |

### 函数

| 名称                                                                                                                                                                                                                     | typedef关键字              | 描述                          |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------|-----------------------------|
| [VkResult (VKAPI_PTR *PFN_vkCreateSurfaceOHOS)(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)](#pfn_vkcreatesurfaceohos)            | PFN_vkCreateSurfaceOHOS | 创建Vulkan Surface的函数指针定义。    |
| [VKAPI_ATTR VkResult VKAPI_CALL vkCreateSurfaceOHOS(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)](#vkcreatesurfaceohos)           | -                       | 创建Vulkan Surface。           |
| [VkResult (VKAPI_PTR *PFN_vkGetNativeBufferPropertiesOHOS)(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties)](#pfn_vkgetnativebufferpropertiesohos)                    | PFN_vkGetNativeBufferPropertiesOHOS    |  获取OH_NativeBuffer属性的函数指针定义。 |
| [VkResult (VKAPI_PTR *PFN_vkGetMemoryNativeBufferOHOS)(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer)](#pfn_vkgetmemorynativebufferohos)                             | PFN_vkGetMemoryNativeBufferOHOS             |  获取OH_NativeBuffer的函数指针定义。 |
| [VKAPI_ATTR VkResult VKAPI_CALL vkGetNativeBufferPropertiesOHOS(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties)](#vkgetnativebufferpropertiesohos)                   | -                       | 获取OH_NativeBuffer属性。 |
| [VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryNativeBufferOHOS(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer)](#vkgetmemorynativebufferohos)                            | -                       | 获取OH_NativeBuffer。 |
| [VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainGrallocUsageOHOS(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t* grallocUsage)](#vkgetswapchaingrallocusageohos)                               | -                       | 根据给定的Vulkan设备、图像格式和图像使用标志, 返回适当的Gralloc(内存分配器)使用标志。 |
| [VKAPI_ATTR VkResult VKAPI_CALL vkAcquireImageOHOS(VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence)](#vkacquireimageohos)                                                  | -                       | 用于获取交换链图像的所有权, 并将外部信号的Fence导入到VkSemaphore对象和VkFence对象中。 |
| [VKAPI_ATTR VkResult VKAPI_CALL vkQueueSignalReleaseImageOHOS(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int32_t* pNativeFenceFd)](#vkqueuesignalreleaseimageohos) | -                       | 当前图像使用完毕后，通过该函数向系统硬件缓冲区发出释放信号, 以便其他组件可以访问该图像。 |

## 函数说明

###  PFN_vkCreateSurfaceOHOS()

```
typedef VkResult (VKAPI_PTR *PFN_vkCreateSurfaceOHOS)(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
```

**描述**

创建Vulkan Surface的函数指针定义。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| VkInstance instance | Vulkan实例。 |
| [const VkSurfaceCreateInfoOHOS](capi-vulkan-vksurfacecreateinfoohos.md)* pCreateInfo | 一个VkSurfaceCreateInfoOHOS结构体的指针，包含创建Vulkan Surface时必要的参数。 |
| const VkAllocationCallbacks*   pAllocator | 用户自定义内存分配的回调函数，如果不需要可以传入NULL，接口会使用默认的内存分配函数。 |
| VkSurfaceKHR* pSurface | 出参，用于接收创建的Vulkan Surface，类型为VkSurfaceKHR。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| VkResult  | 返回一个VkResult类型的错误码，返回值为VK_SUCCESS表示执行成功。 |

### vkCreateSurfaceOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSurfaceOHOS(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
```

**描述**

创建Vulkan Surface。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| VkInstance instance | Vulkan实例。 |
| [const VkSurfaceCreateInfoOHOS](capi-vulkan-vksurfacecreateinfoohos.md)* pCreateInfo | 一个VkSurfaceCreateInfoOHOS结构体的指针，包含创建Vulkan Surface时必要的参数。 |
| const VkAllocationCallbacks* pAllocator | 用户自定义内存分配的回调函数，如果不需要可以传入NULL，接口会使用默认的内存分配函数。 |
| VkSurfaceKHR* pSurface | 出参，用于接收创建的Vulkan Surface，类型为VkSurfaceKHR。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| VkResult  | 返回一个VkResult类型的错误码，具体返回类型如下：<br> 返回VK_SUCCESS，表示执行成功。<br> 返回VK_ERROR_OUT_OF_HOST_MEMORY，表示分配VkSurfaceKHR内存失败。<br> 返回VK_ERROR_SURFACE_LOST_KHR，表示操作NativeWindow失败。 |

### PFN_vkGetNativeBufferPropertiesOHOS()

```
typedef VkResult (VKAPI_PTR *PFN_vkGetNativeBufferPropertiesOHOS)(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties)
```

**描述**

获取OH_NativeBuffer属性的函数指针定义。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10


**参数：**

| 参数项                                                                    | 描述 |
|------------------------------------------------------------------------| -- |
| VkDevice device                                                        | VkDevice对象。 |
| const [struct OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)* buffer | OH_NativeBuffer结构体指针。 |
| [VkNativeBufferPropertiesOHOS](capi-vulkan-vknativebufferpropertiesohos.md)* pProperties                          | 用于接收OH_NativeBuffer属性的结构体。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| VkResult | 返回一个VkResult类型的错误码，返回值为VK_SUCCESS表示执行成功。 |

### PFN_vkGetMemoryNativeBufferOHOS()

```
typedef VkResult (VKAPI_PTR *PFN_vkGetMemoryNativeBufferOHOS)(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer)
```

**描述**

获取OH_NativeBuffer的函数指针定义。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| VkDevice device | VkDevice对象。 |
| [const VkMemoryGetNativeBufferInfoOHOS](capi-vulkan-vkmemorygetnativebufferinfoohos.md)* pInfo | VkMemoryGetNativeBufferInfoOHOS结构体对象。 |
| [struct OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)** pBuffer | 用于接收获取到的OH_NativeBuffer。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| VkResult | 返回一个VkResult类型的错误码，返回值为VK_SUCCESS表示执行成功。 |

### vkGetNativeBufferPropertiesOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkGetNativeBufferPropertiesOHOS(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties)
```

**描述**

获取OH_NativeBuffer属性。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| VkDevice device | VkDevice对象。 |
| const [struct OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)* buffer | OH_NativeBuffer结构体指针。 |
| [VkNativeBufferPropertiesOHOS](capi-vulkan-vknativebufferpropertiesohos.md)* pProperties | 用于接收OH_NativeBuffer属性的结构体。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| VkResult | 返回一个VkResult类型的错误码，具体返回类型如下：<br> 返回VK_SUCCESS，表示执行成功。<br> 返回VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR，表示入参存在异常。<br> 返回VK_ERROR_OUT_OF_DEVICE_MEMORY，表示设备内存不足。 |

### vkGetMemoryNativeBufferOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryNativeBufferOHOS(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer)
```

**描述**

获取OH_NativeBuffer。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| VkDevice device | VkDevice对象。 |
| [const VkMemoryGetNativeBufferInfoOHOS](capi-vulkan-vkmemorygetnativebufferinfoohos.md)* pInfo | VkMemoryGetNativeBufferInfoOHOS结构体对象。 |
| [struct OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)** pBuffer | 用于接收获取到的OH_NativeBuffer。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| VkResult | 返回一个VkResult类型的错误码，具体返回类型如下：<br> 返回VK_SUCCESS，表示执行成功。<br> 返回VK_ERROR_OUT_OF_HOST_MEMORY，表示pInfo入参异常，或获取的pBuffer异常。 |

### vkGetSwapchainGrallocUsageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainGrallocUsageOHOS(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t* grallocUsage)
```

**描述**

根据给定的Vulkan设备、图像格式和图像使用标志, 返回适当的Gralloc(内存分配器)使用标志。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| VkDevice device | VkDevice对象。 |
| VkFormat format | 图像格式。 |
| VkImageUsageFlags imageUsage | 图像使用标志。 |
| uint64_t* grallocUsage | 出参, 返回Gralloc(内存分配器)使用标志。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| VkResult | 返回一个VkResult类型的错误码，具体返回类型如下：<br> 返回VK_SUCCESS，表示执行成功。<br> 返回VK_ERROR_INITIALIZATION_FAILED，表示入参异常。 |

### vkAcquireImageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireImageOHOS(VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence)
```

**描述**

用于获取交换链图像的所有权, 并将外部信号的Fence导入到VkSemaphore对象和VkFence对象中。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| VkDevice device | VkDevice对象。 |
| VkImage image | 要获取的Vulkan图像。 |
| int32_t nativeFenceFd | 原生Fence的文件描述符。 |
| VkSemaphore semaphore | 表示图像可用状态的Vulkan Semaphore(信号量)。 |
| VkFence fence | 用于在图像获取完成时进行同步的Vulkan Fence。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| VkResult | 返回一个VkResult类型的错误码，具体返回类型如下：<br> 返回VK_SUCCESS，表示执行成功。<br> 返回VK_ERROR_OUT_OF_HOST_MEMORY，表示主机内存不足。 |

### vkQueueSignalReleaseImageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSignalReleaseImageOHOS(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int32_t* pNativeFenceFd)
```

**描述**

当前图像使用完毕后，通过该函数向系统硬件缓冲区发出释放信号, 以便其他组件可以访问该图像。

**系统能力：** SystemCapability.Graphic.Vulkan

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| VkQueue queue | Vulkan队列的句柄。 |
| uint32_t waitSemaphoreCount | 等待Semaphore(信号量)的数量。 |
| const VkSemaphore* pWaitSemaphores | 指向等待Semaphore(信号量)数组的指针。 |
| VkImage image | 要释放的Vulkan图像句柄。 |
| int32_t* pNativeFenceFd | 指向Fence的文件描述符的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| VkResult | 返回一个VkResult类型的错误码，具体返回类型如下：<br> 返回VK_SUCCESS，表示执行成功。<br> 返回VK_ERROR_DEVICE_LOST，表示Vulkan设备链接丢失。<br> 返回VK_ERROR_OUT_OF_HOST_MEMORY，表示主机内存不足。 |


