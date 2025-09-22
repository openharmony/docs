# vulkan_ohos.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @andrew1993-->
<!--Designer: @ext4FAT1-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The file declares the Vulkan interfaces extended by OpenHarmony.

**File to include**: <vulkan/vulkan_ohos.h>

**Library**: libvulkan.so

**Since**: 10

**Related module**: [Vulkan](capi-vulkan.md)

## Summary

### Structs

| Name                                                                                     | typedef Keyword                        | Description                              |
|-----------------------------------------------------------------------------------------|------------------------------------|----------------------------------|
| [VkSurfaceCreateInfoOHOS](capi-vulkan-vksurfacecreateinfoohos.md)                       | VkSurfaceCreateInfoOHOS            | Describes the parameters required for creating a Vulkan surface.       |
| [VkNativeBufferUsageOHOS](capi-vulkan-vknativebufferusageohos.md)                       | VkNativeBufferUsageOHOS            | Describes the usage of the NativeBuffer.|
| [VkNativeBufferPropertiesOHOS](capi-vulkan-vknativebufferpropertiesohos.md)             | VkNativeBufferPropertiesOHOS       | Describes the properties of the NativeBuffer.             |
| [VkNativeBufferFormatPropertiesOHOS](capi-vulkan-vknativebufferformatpropertiesohos.md) | VkNativeBufferFormatPropertiesOHOS | Describes the format properties of the NativeBuffer.         |
| [VkImportNativeBufferInfoOHOS](capi-vulkan-vkimportnativebufferinfoohos.md)             | VkImportNativeBufferInfoOHOS       | Describes the pointer to an OH_NativeBuffer struct.       |
| [VkMemoryGetNativeBufferInfoOHOS](capi-vulkan-vkmemorygetnativebufferinfoohos.md)       | VkMemoryGetNativeBufferInfoOHOS    | Used to obtain an OH_NativeBuffer from the Vulkan memory.  |
| [VkExternalFormatOHOS](capi-vulkan-vkexternalformatohos.md)                             | VkExternalFormatOHOS               | Describes an externally defined format.                   |
| [NativeWindow](capi-vulkan-nativewindow.md)                                             | OHNativeWindow                     | Describes a native window.                           |
| [OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)                                   | -                                  | Describes the OH_NativeBuffer struct.                                |

### Macros

| Name| Description|
| -- | -- |
| VK_OHOS_surface 1 | Surface extension macro definition of OpenHarmony.<br>**Since**: 10|
| VK_OHOS_SURFACE_SPEC_VERSION      1 | Surface extension version of OpenHarmony.<br>**Since**: 10|
| VK_OHOS_SURFACE_EXTENSION_NAME    "VK_OHOS_surface" | Surface extension name of OpenHarmony.<br>**Since**: 10|
| VK_OHOS_external_memory 1 | External memory extension macro definition of OpenHarmony.<br>**Since**: 10|
| VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION 1 | External memory extension version of OpenHarmony.<br>**Since**: 10|
| VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME "VK_OHOS_external_memory" | External memory extension name of OpenHarmony.<br>**Since**: 10|

### Functions

| Name                                                                                                                                                                                                                    | typedef Keyword             | Description                         |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------|-----------------------------|
| [VkResult (VKAPI_PTR *PFN_vkCreateSurfaceOHOS)(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)](#pfn_vkcreatesurfaceohos)            | PFN_vkCreateSurfaceOHOS | Defines the function pointer for creating a Vulkan surface.   |
| [VKAPI_ATTR VkResult VKAPI_CALL vkCreateSurfaceOHOS(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)](#vkcreatesurfaceohos)           | -                       | Creates a Vulkan surface.          |
| [VkResult (VKAPI_PTR *PFN_vkGetNativeBufferPropertiesOHOS)(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties)](#pfn_vkgetnativebufferpropertiesohos)                    | PFN_vkGetNativeBufferPropertiesOHOS    |  Defines a function pointer used to obtain OH_NativeBuffer properties.|
| [VkResult (VKAPI_PTR *PFN_vkGetMemoryNativeBufferOHOS)(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer)](#pfn_vkgetmemorynativebufferohos)                             | PFN_vkGetMemoryNativeBufferOHOS             |  Defines a function pointer used to obtain an OH_NativeBuffer instance.|
| [VKAPI_ATTR VkResult VKAPI_CALL vkGetNativeBufferPropertiesOHOS(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties)](#vkgetnativebufferpropertiesohos)                   | -                       | Obtains the properties of an OH_NativeBuffer instance.|
| [VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryNativeBufferOHOS(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer)](#vkgetmemorynativebufferohos)                            | -                       | Obtains an OH_NativeBuffer instance.|
| [VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainGrallocUsageOHOS(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t* grallocUsage)](#vkgetswapchaingrallocusageohos)                               | -                       | Returns the appropriate gralloc usage flag based on the given Vulkan device, image format, and image usage flag.|
| [VKAPI_ATTR VkResult VKAPI_CALL vkAcquireImageOHOS(VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence)](#vkacquireimageohos)                                                  | -                       | Obtains the ownership of the swap chain image and imports the fence of the external signal to the VkSemaphore and VkFence objects.|
| [VKAPI_ATTR VkResult VKAPI_CALL vkQueueSignalReleaseImageOHOS(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int32_t* pNativeFenceFd)](#vkqueuesignalreleaseimageohos) | -                       | Sends a signal to the system hardware buffer to release an image once it is no longer needed so that other components can access it.|

## Function Description

###  PFN_vkCreateSurfaceOHOS()

```
typedef VkResult (VKAPI_PTR *PFN_vkCreateSurfaceOHOS)(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
```

**Description**

Defines the function pointer for creating a Vulkan surface.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| VkInstance instance | Vulkan instance.|
| [const VkSurfaceCreateInfoOHOS](capi-vulkan-vksurfacecreateinfoohos.md)* pCreateInfo | Pointer to the VkSurfaceCreateInfoOHOS struct, including the parameters required for creating a Vulkan surface.|
| const VkAllocationCallbacks*   pAllocator | Pointer to a callback function for custom memory allocation. If custom memory allocation is not required, pass in NULL, and the default memory allocation function is used.|
| VkSurfaceKHR* pSurface | Pointer to the Vulkan surface created. The type is **VkSurfaceKHR**.|

**Returns**

| Type| Description|
| -- | -- |
| VkResult  | **VK_SUCCESS**. If the operation fails, an error code of the VkResult type is returned.|

### vkCreateSurfaceOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSurfaceOHOS(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
```

**Description**

Creates a Vulkan surface.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| VkInstance instance | Vulkan instance.|
| [const VkSurfaceCreateInfoOHOS](capi-vulkan-vksurfacecreateinfoohos.md)* pCreateInfo | Pointer to the VkSurfaceCreateInfoOHOS struct, including the parameters required for creating a Vulkan surface.|
| const VkAllocationCallbacks* pAllocator | Pointer to a callback function for custom memory allocation. If custom memory allocation is not required, pass in NULL, and the default memory allocation function is used.|
| VkSurfaceKHR* pSurface | Pointer to the Vulkan surface created. The type is **VkSurfaceKHR**.|

**Returns**

| Type| Description|
| -- | -- |
| VkResult  | One of the following error codes of the VkResult type:<br> **VK_SUCCESS**: The operation is successful.<br> **VK_ERROR_OUT_OF_HOST_MEMORY**: The VkSurfaceKHR memory fails to be allocated.<br> **VK_ERROR_SURFACE_LOST_KHR**: The NativeWindow operation fails.|

### PFN_vkGetNativeBufferPropertiesOHOS()

```
typedef VkResult (VKAPI_PTR *PFN_vkGetNativeBufferPropertiesOHOS)(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties)
```

**Description**

Defines a function pointer used to obtain OH_NativeBuffer properties.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10


**Parameters**

| Name                                                                   | Description|
|------------------------------------------------------------------------| -- |
| VkDevice device                                                        | VkDevice object.|
| const [struct OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)* buffer | Pointer to an OH_NativeBuffer struct.|
| [VkNativeBufferPropertiesOHOS](capi-vulkan-vknativebufferpropertiesohos.md)* pProperties                          | Pointer to the struct holding the properties of OH_NativeBuffer.|

**Returns**

| Type| Description|
| -- | -- |
| VkResult | **VK_SUCCESS**. If the operation fails, an error code of the VkResult type is returned.|

### PFN_vkGetMemoryNativeBufferOHOS()

```
typedef VkResult (VKAPI_PTR *PFN_vkGetMemoryNativeBufferOHOS)(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer)
```

**Description**

Defines a function pointer used to obtain an OH_NativeBuffer instance.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| VkDevice device | VkDevice object.|
| [const VkMemoryGetNativeBufferInfoOHOS](capi-vulkan-vkmemorygetnativebufferinfoohos.md)* pInfo | Pointer to a VkMemoryGetNativeBufferInfoOHOS struct.|
| [struct OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)** pBuffer | Pointer to the OH_NativeBuffer obtained.|

**Returns**

| Type| Description|
| -- | -- |
| VkResult | **VK_SUCCESS**. If the operation fails, an error code of the VkResult type is returned.|

### vkGetNativeBufferPropertiesOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkGetNativeBufferPropertiesOHOS(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties)
```

**Description**

Obtains the properties of an OH_NativeBuffer instance.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| VkDevice device | VkDevice object.|
| const [struct OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)* buffer | Pointer to an OH_NativeBuffer struct.|
| [VkNativeBufferPropertiesOHOS](capi-vulkan-vknativebufferpropertiesohos.md)* pProperties | Pointer to the struct holding the properties of OH_NativeBuffer.|

**Returns**

| Type| Description|
| -- | -- |
| VkResult | One of the following error codes of the VkResult type:<br> **VK_SUCCESS**: The operation is successful.<br> **VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR**: An input parameter is abnormal.<br> **VK_ERROR_OUT_OF_DEVICE_MEMORY**: The device memory is insufficient.|

### vkGetMemoryNativeBufferOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryNativeBufferOHOS(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer)
```

**Description**

Obtains an OH_NativeBuffer instance.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| VkDevice device | VkDevice object.|
| [const VkMemoryGetNativeBufferInfoOHOS](capi-vulkan-vkmemorygetnativebufferinfoohos.md)* pInfo | Pointer to a VkMemoryGetNativeBufferInfoOHOS struct.|
| [struct OH_NativeBuffer](capi-vulkan-oh-nativebuffer.md)** pBuffer | Pointer to the OH_NativeBuffer obtained.|

**Returns**

| Type| Description|
| -- | -- |
| VkResult | One of the following error codes of the VkResult type:<br> **VK_SUCCESS**: The operation is successful.<br> **VK_ERROR_OUT_OF_HOST_MEMORY**: The input parameter **pInfo** is abnormal or the obtained **pBuffer** is abnormal.|

### vkGetSwapchainGrallocUsageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainGrallocUsageOHOS(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t* grallocUsage)
```

**Description**

Returns the appropriate gralloc usage flag based on the given Vulkan device, image format, and image usage flag.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| VkDevice device | VkDevice object.|
| VkFormat format | Image format.|
| VkImageUsageFlags imageUsage | Image use flag.|
| uint64_t* grallocUsage | Pointer to the gralloc usage flag.|

**Returns**

| Type| Description|
| -- | -- |
| VkResult | One of the following error codes of the VkResult type:<br> **VK_SUCCESS**: The operation is successful.<br> **VK_ERROR_INITIALIZATION_FAILED**: An input parameter is abnormal.|

### vkAcquireImageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireImageOHOS(VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence)
```

**Description**

Obtains the ownership of the swap chain image and imports the fence of the external signal to the VkSemaphore and VkFence objects.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| VkDevice device | VkDevice object.|
| VkImage image | Vulkan image to obtain.|
| int32_t nativeFenceFd | File descriptor of the native fence.|
| VkSemaphore semaphore | Vulkan semaphore indicating that the image is available.|
| VkFence fence | Vulkan fence used for synchronization when the image acquisition is complete.|

**Returns**

| Type| Description|
| -- | -- |
| VkResult | One of the following error codes of the VkResult type:<br> **VK_SUCCESS**: The operation is successful.<br> **VK_ERROR_OUT_OF_HOST_MEMORY**: The host memory is insufficient.|

### vkQueueSignalReleaseImageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSignalReleaseImageOHOS(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int32_t* pNativeFenceFd)
```

**Description**

Sends a signal to the system hardware buffer to release an image once it is no longer needed so that other components can access it.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| VkQueue queue | Handle to the Vulkan queue.|
| uint32_t waitSemaphoreCount | Number of semaphores to wait on.|
| const VkSemaphore* pWaitSemaphores | Pointer to the array of semaphores to wait on.|
| VkImage image | Handle to the Vulkan image to be released.|
| int32_t* pNativeFenceFd | Pointer to the file descriptor of the fence.|

**Returns**

| Type| Description|
| -- | -- |
| VkResult | One of the following error codes of the VkResult type:<br> **VK_SUCCESS**: The operation is successful.<br> **VK_ERROR_DEVICE_LOST**: The Vulkan device link is lost.<br> **VK_ERROR_OUT_OF_HOST_MEMORY**: The host memory is insufficient.|
