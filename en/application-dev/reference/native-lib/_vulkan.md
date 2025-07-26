# Vulkan Module


## Overview

The **Vulkan** module provides Vulkan capabilities extended by OpenHarmony. It provides extended APIs for creating a Vulkan surface using **OHNativeWindow** and obtaining **OH_NativeBuffer **and **OH_NativeBuffer** properties.

\@syscap SystemCapability.Graphic.Vulkan

**Since**

10


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [vulkan_ohos.h](vulkan__ohos_8h.md) | Declares the Vulkan interfaces extended by OpenHarmony.<br>File to include: &lt;vulkan/vulkan.h&gt;<br>Library: libvulkan.so |


### Structs

| Name| Description|
| -------- | -------- |
| [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) | Defines the parameters required for creating a Vulkan surface.|
| [VkNativeBufferUsageOHOS](_vk_native_buffer_usage_o_h_o_s.md) | Defines the usage of a **NativeBuffer**.|
| [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) | Defines the properties of a **NativeBuffer**.|
| [VkNativeBufferFormatPropertiesOHOS](_vk_native_buffer_format_properties_o_h_o_s.md) | Defines the format properties of a **NativeBuffer**.|
| [VkImportNativeBufferInfoOHOS](_vk_import_native_buffer_info_o_h_o_s.md) | Defines the pointer to an **OH_NativeBuffer** struct.|
| [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) | Defines a struct used to obtain an **OH_NativeBuffer** from the Vulkan memory.|
| [VkExternalFormatOHOS](_vk_external_format_o_h_o_s.md) | Defines an externally defined format.|


### Macros

| Name| Description|
| -------- | -------- |
| [VK_OHOS_surface](#vk_ohos_surface)   1 | Surface extension macro definition of OpenHarmony.|
| [VK_OHOS_SURFACE_SPEC_VERSION](#vk_ohos_surface_spec_version)   1 | Surface extension version of OpenHarmony.|
| [VK_OHOS_SURFACE_EXTENSION_NAME](#vk_ohos_surface_extension_name)   "VK_OHOS_surface" | Surface extension name of OpenHarmony.|
| [VK_OHOS_external_memory](#vk_ohos_external_memory)   1 | External memory extension macro definition of OpenHarmony.|
| [VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION](#vk_ohos_external_memory_spec_version)   1 | External memory extension version of OpenHarmony.|
| [VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME](#vk_ohos_external_memory_extension_name)   "VK_OHOS_external_memory" | External memory extension name of OpenHarmony.|


### Types

| Name| Description|
| -------- | -------- |
| [OHNativeWindow](#ohnativewindow) | Defines an **OHNativeWindow**.|
| [VkSurfaceCreateFlagsOHOS](#vksurfacecreateflagsohos) | Defines the bit mask of the VkFlags type used for the creation of a Vulkan surface. It is a reserved flag type.|
| [VkSurfaceCreateInfoOHOS](#vksurfacecreateinfoohos) | Defines the parameters required for creating a Vulkan surface.|
| VkResult ([VKAPI_PTR *PFN_vkCreateSurfaceOHOS](#pfn_vkcreatesurfaceohos)) (VkInstance instance, const [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) \*pCreateInfo, const VkAllocationCallbacks \*pAllocator, VkSurfaceKHR \*pSurface) | Defines the function pointer for creating a Vulkan surface.|
| [VkNativeBufferUsageOHOS](#vknativebufferusageohos) | Defines the usage of a **NativeBuffer**.|
| [VkNativeBufferPropertiesOHOS](#vknativebufferpropertiesohos) | Defines the properties of a **NativeBuffer**.|
| [VkNativeBufferFormatPropertiesOHOS](#vknativebufferformatpropertiesohos) | Defines the format properties of a **NativeBuffer**.|
| [VkImportNativeBufferInfoOHOS](#vkimportnativebufferinfoohos) | Defines the pointer to an **OH_NativeBuffer** struct.|
| [VkMemoryGetNativeBufferInfoOHOS](#vkmemorygetnativebufferinfoohos) | Defines a struct used to obtain an **OH_NativeBuffer** from the Vulkan memory.|
| [VkExternalFormatOHOS](#vkexternalformatohos) | Defines an externally defined format.|
| VkResult ([VKAPI_PTR *PFN_vkGetNativeBufferPropertiesOHOS](#pfn_vkgetnativebufferpropertiesohos)) (VkDevice device, const struct OH_NativeBuffer \*buffer, [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) \*pProperties) | Defines a function pointer used to obtain **OH_NativeBuffer** properties.|
| VkResult ([VKAPI_PTR *PFN_vkGetMemoryNativeBufferOHOS](#pfn_vkgetmemorynativebufferohos)) (VkDevice device, const [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) \*pInfo, struct OH_NativeBuffer \*\*pBuffer) | Defines a function pointer used to obtain an **OH_NativeBuffer** instance.|


### Functions

| Name| Description|
| -------- | -------- |
| VKAPI_ATTR VkResult VKAPI_CALL [vkCreateSurfaceOHOS](#vkcreatesurfaceohos) (VkInstance instance, const [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) \*pCreateInfo, const VkAllocationCallbacks \*pAllocator, VkSurfaceKHR \*pSurface) | Creates a Vulkan surface.| 
| VKAPI_ATTR VkResult VKAPI_CALL [vkGetNativeBufferPropertiesOHOS](#vkgetnativebufferpropertiesohos) (VkDevice device, const struct OH_NativeBuffer \*buffer, [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) \*pProperties) | Obtains the properties of an **OH_NativeBuffer** instance.| 
| VKAPI_ATTR VkResult VKAPI_CALL [vkGetMemoryNativeBufferOHOS](#vkgetmemorynativebufferohos) (VkDevice device, const [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) \*pInfo, struct OH_NativeBuffer \*\*pBuffer) | Obtains an **OH_NativeBuffer** instance.| 
| VKAPI_ATTR VkResult VKAPI_CALL [vkGetSwapchainGrallocUsageOHOS](#vkgetswapchaingrallocusageohos) (VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t \*grallocUsage) | Returns the appropriate gralloc usage flag based on the given Vulkan device, image format, and image usage flag.| 
| VKAPI_ATTR VkResult VKAPI_CALL [vkAcquireImageOHOS](#vkacquireimageohos) (VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence) | Obtains the ownership of the swap chain image and imports the fence of the external signal to the VkSemaphore and VkFence objects.| 
| VKAPI_ATTR VkResult VKAPI_CALL [vkQueueSignalReleaseImageOHOS](#vkqueuesignalreleaseimageohos) (VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore \*pWaitSemaphores, VkImage image, int32_t \*pNativeFenceFd) | Sends a signal to the system hardware buffer to release an image once it is no longer needed so that other components can access it.| 


### Variables

| Name| Description|
| -------- | -------- |
| [VkSurfaceCreateInfoOHOS::sType](#stype-17) | Struct type.|
| [VkSurfaceCreateInfoOHOS::pNext](#pnext-17) | Pointer to the next-level struct.|
| [VkSurfaceCreateInfoOHOS::flags](#flags) | Reserved flag type.|
| [VkSurfaceCreateInfoOHOS::window](#window) | Pointer to an **OHNativeWindow** instance.|
| [VkNativeBufferUsageOHOS::sType](#stype-27) | Struct type.|
| [VkNativeBufferUsageOHOS::pNext](#pnext-27) | Pointer to the next-level struct.|
| [VkNativeBufferUsageOHOS::OHOSNativeBufferUsage](#ohosnativebufferusage) | Usage of a **NativeBuffer**.|
| [VkNativeBufferPropertiesOHOS::sType](#stype-37) | Struct type.|
| [VkNativeBufferPropertiesOHOS::pNext](#pnext-37) | Pointer to the next-level struct.|
| [VkNativeBufferPropertiesOHOS::allocationSize](#allocationsize) | Size of the occupied memory.|
| [VkNativeBufferPropertiesOHOS::memoryTypeBits](#memorytypebits) | Memory type.|
| [VkNativeBufferFormatPropertiesOHOS::sType](#stype-47) | Struct type.|
| [VkNativeBufferFormatPropertiesOHOS::pNext](#pnext-47) | Pointer to the next-level struct.|
| [VkNativeBufferFormatPropertiesOHOS::format](#format) | Format properties.|
| [VkNativeBufferFormatPropertiesOHOS::externalFormat](#externalformat-12) | Externally defined format.|
| [VkNativeBufferFormatPropertiesOHOS::formatFeatures](#formatfeatures) | Features of the externally defined format.|
| [VkNativeBufferFormatPropertiesOHOS::samplerYcbcrConversionComponents](#samplerycbcrconversioncomponents) | A group of VkComponentSwizzles.|
| [VkNativeBufferFormatPropertiesOHOS::suggestedYcbcrModel](#suggestedycbcrmodel) | Color model.|
| [VkNativeBufferFormatPropertiesOHOS::suggestedYcbcrRange](#suggestedycbcrrange) | Color value range.|
| [VkNativeBufferFormatPropertiesOHOS::suggestedXChromaOffset](#suggestedxchromaoffset) | X chrominance offset.|
| [VkNativeBufferFormatPropertiesOHOS::suggestedYChromaOffset](#suggestedychromaoffset) | Y chrominance offset.|
| [VkImportNativeBufferInfoOHOS::sType](#stype-57) | Struct type.|
| [VkImportNativeBufferInfoOHOS::pNext](#pnext-57) | Pointer to the next-level struct.|
| [VkImportNativeBufferInfoOHOS::buffer](#buffer) | Pointer to an **OH_NativeBuffer** struct.|
| [VkMemoryGetNativeBufferInfoOHOS::sType](#stype-67) | Struct type.|
| [VkMemoryGetNativeBufferInfoOHOS::pNext](#pnext-67) | Pointer to the next-level struct.|
| [VkMemoryGetNativeBufferInfoOHOS::memory](#memory) | **VkDeviceMemory** instance.|
| [VkExternalFormatOHOS::sType](#stype-77) | Struct type.|
| [VkExternalFormatOHOS::pNext](#pnext-77) | Pointer to the next-level struct.|
| [VkExternalFormatOHOS::externalFormat](#externalformat-22) | Externally defined format.|


## Macro Description


### VK_OHOS_external_memory


```
#define VK_OHOS_external_memory   1
```

**Description**

External memory extension macro definition of OpenHarmony.


### VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME


```
#define VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME   "VK_OHOS_external_memory"
```

**Description**

External memory extension name of OpenHarmony.


### VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION


```
#define VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION   1
```

**Description**

External memory extension version of OpenHarmony.


### VK_OHOS_surface


```
#define VK_OHOS_surface   1
```

**Description**

Surface extension macro definition of OpenHarmony.


### VK_OHOS_SURFACE_EXTENSION_NAME


```
#define VK_OHOS_SURFACE_EXTENSION_NAME   "VK_OHOS_surface"
```

**Description**

Surface extension name of OpenHarmony.


### VK_OHOS_SURFACE_SPEC_VERSION


```
#define VK_OHOS_SURFACE_SPEC_VERSION   1
```

**Description**

Surface extension version of OpenHarmony.


## Type Description


### OHNativeWindow


```
typedef struct NativeWindow OHNativeWindow
```

**Description**

Defines an **OHNativeWindow**.


### PFN_vkCreateSurfaceOHOS


```
typedef VkResult(VKAPI_PTR * PFN_vkCreateSurfaceOHOS) (VkInstance instance, const VkSurfaceCreateInfoOHOS *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSurfaceKHR *pSurface)
```

**Description**

Defines the function pointer for creating a Vulkan surface.

\@syscap SystemCapability.Graphic.Vulkan

**Parameters**

| Name| Description|
| -------- | -------- |
| instance | **Vulkan** instance.|
| pCreateInfo | Pointer to the **VkSurfaceCreateInfoOHOS** struct, including the parameters required for creating a Vulkan surface.|
| pAllocator | Pointer to a callback function for custom memory allocation. If custom memory allocation is not required, pass in **NULL**, and the default memory allocation function is used.|
| pSurface | Pointer to the Vulkan surface created. The type is **VkSurfaceKHR**.|

**Returns**

Returns **VK_SUCCESS** if the execution is successful; returns an error code of the VkResult type otherwise.


### PFN_vkGetMemoryNativeBufferOHOS


```
typedef VkResult(VKAPI_PTR * PFN_vkGetMemoryNativeBufferOHOS) (VkDevice device, const VkMemoryGetNativeBufferInfoOHOS *pInfo, struct OH_NativeBuffer **pBuffer)
```

**Description**

Defines a function pointer used to obtain an **OH_NativeBuffer** instance.

\@syscap SystemCapability.Graphic.Vulkan

**Parameters**

| Name| Description|
| -------- | -------- |
| device | **VkDevice** instance.|
| pInfo | Pointer to a **VkMemoryGetNativeBufferInfoOHOS** struct.|
| pBuffer | Pointer to the **OH_NativeBuffer** obtained.|

**Returns**

Returns **VK_SUCCESS** if the execution is successful; returns an error code of the VkResult type otherwise.


### PFN_vkGetNativeBufferPropertiesOHOS


```
typedef VkResult(VKAPI_PTR * PFN_vkGetNativeBufferPropertiesOHOS) (VkDevice device, const struct OH_NativeBuffer *buffer, VkNativeBufferPropertiesOHOS *pProperties)
```

**Description**

Defines a function pointer used to obtain **OH_NativeBuffer** properties.

\@syscap SystemCapability.Graphic.Vulkan

**Parameters**

| Name| Description|
| -------- | -------- |
| device | **VkDevice** instance.|
| buffer | Pointer to an **OH_NativeBuffer** struct.|
| pProperties | Pointer to the struct holding the properties of **OH_NativeBuffer**.|

**Returns**

Returns **VK_SUCCESS** if the execution is successful; returns an error code of the VkResult type otherwise.


### VkExternalFormatOHOS


```
typedef struct VkExternalFormatOHOS VkExternalFormatOHOS
```

**Description**

Defines an externally defined format.


### VkImportNativeBufferInfoOHOS


```
typedef struct VkImportNativeBufferInfoOHOS VkImportNativeBufferInfoOHOS
```

**Description**

Defines the pointer to an **OH_NativeBuffer** struct.


### VkMemoryGetNativeBufferInfoOHOS


```
typedef struct VkMemoryGetNativeBufferInfoOHOS VkMemoryGetNativeBufferInfoOHOS
```

**Description**

Defines a struct used to obtain an **OH_NativeBuffer** from the Vulkan memory.


### VkNativeBufferFormatPropertiesOHOS


```
typedef struct VkNativeBufferFormatPropertiesOHOS VkNativeBufferFormatPropertiesOHOS
```

**Description**

Defines the format properties of a **NativeBuffer**.


### VkNativeBufferPropertiesOHOS


```
typedef struct VkNativeBufferPropertiesOHOS VkNativeBufferPropertiesOHOS
```

**Description**

Defines the properties of a **NativeBuffer**.


### VkNativeBufferUsageOHOS


```
typedef struct VkNativeBufferUsageOHOS VkNativeBufferUsageOHOS
```

**Description**

Defines the usage of a **NativeBuffer**.


### VkSurfaceCreateFlagsOHOS


```
typedef VkFlags VkSurfaceCreateFlagsOHOS
```

**Description**

Defines the bit mask of the VkFlags type used for the creation of a Vulkan surface. It is a reserved flag type.


### VkSurfaceCreateInfoOHOS


```
typedef struct VkSurfaceCreateInfoOHOS VkSurfaceCreateInfoOHOS
```

**Description**

Defines the parameters required for creating a Vulkan surface.


## Function Description


### vkAcquireImageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireImageOHOS (VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence )
```

**Description**

Obtains the ownership of the swap chain image and imports the fence of the external signal to the VkSemaphore and VkFence objects.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| device | **VkDevice** instance.| 
| image | Vulkan image to obtain.| 
| nativeFenceFd | File descriptor of the native fence.| 
| semaphore | Vulkan semaphore indicating that the image is available.| 
| fence | Vulkan fence used for synchronization when the image acquisition is complete.| 

**Returns**

Returns an error code of the VkResult type.
- Returns **VK_SUCCESS** if the operation is successful.
- Returns **VK_ERROR_OUT_OF_HOST_MEMORY** if the host memory is insufficient.
### vkCreateSurfaceOHOS()


```
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSurfaceOHOS (VkInstance instance, const VkSurfaceCreateInfoOHOS * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface )
```

**Description**

Creates a Vulkan surface.

\@syscap SystemCapability.Graphic.Vulkan

**Parameters**

| Name| Description|
| -------- | -------- |
| instance | **Vulkan** instance.|
| pCreateInfo | Pointer to the **VkSurfaceCreateInfoOHOS** struct, including the parameters required for creating a Vulkan surface.|
| pAllocator | Pointer to a callback function for custom memory allocation. If custom memory allocation is not required, pass in **NULL**, and the default memory allocation function is used.|
| pSurface | Pointer to the Vulkan surface created. The type is **VkSurfaceKHR**.|

**Returns**

Returns an error code of the VkResult type.
- Returns **VK_SUCCESS** if the operation is successful.
- Returns **VK_ERROR_OUT_OF_HOST_MEMORY** if the VkSurfaceKHR memory fails to be allocated.
- Returns **VK_ERROR_SURFACE_LOST_KHR** if the NativeWindow operation fails.


### vkGetMemoryNativeBufferOHOS()


```
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryNativeBufferOHOS (VkDevice device, const VkMemoryGetNativeBufferInfoOHOS * pInfo, struct OH_NativeBuffer ** pBuffer )
```

**Description**

Obtains an **OH_NativeBuffer** instance.

\@syscap SystemCapability.Graphic.Vulkan

**Parameters**

| Name| Description|
| -------- | -------- |
| device | **VkDevice** instance.|
| pInfo | Pointer to a **VkMemoryGetNativeBufferInfoOHOS** struct.|
| pBuffer | Pointer to the **OH_NativeBuffer** obtained.|

**Returns**

Returns an error code of the VkResult type.
- Returns **VK_SUCCESS** if the operation is successful.
- Returns **VK_ERROR_OUT_OF_HOST_MEMORY** if the input parameter **pInfo** is abnormal or the obtained **pBuffer** is abnormal.

### vkGetNativeBufferPropertiesOHOS()


```
VKAPI_ATTR VkResult VKAPI_CALL vkGetNativeBufferPropertiesOHOS (VkDevice device, const struct OH_NativeBuffer * buffer, VkNativeBufferPropertiesOHOS * pProperties )
```

**Description**

Obtains the properties of an **OH_NativeBuffer** instance.

\@syscap SystemCapability.Graphic.Vulkan

**Parameters**

| Name| Description|
| -------- | -------- |
| device | **VkDevice** instance.|
| buffer | Pointer to an **OH_NativeBuffer** struct.|
| pProperties | Pointer to the struct holding the properties of **OH_NativeBuffer**.|

**Returns**

Returns an error code of the VkResult type.
- Returns **VK_SUCCESS** if the operation is successful.
- Returns **VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR** if an input parameter is abnormal.
- Returns **VK_ERROR_OUT_OF_DEVICE_MEMORY** if the device memory is insufficient.


### vkGetSwapchainGrallocUsageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainGrallocUsageOHOS (VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t* grallocUsage )
```

**Description**

Returns the appropriate gralloc usage flag based on the given Vulkan device, image format, and image usage flag.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| device | **VkDevice** instance.| 
| format | Image format.| 
| imageUsage | Image use flag.| 
| grallocUsage | Pointer to the gralloc usage flag.| 

**Returns**

Returns an error code of the VkResult type.
- Returns **VK_SUCCESS** if the operation is successful.
- Returns **VK_ERROR_INITIALIZATION_FAILED** if an input parameter is abnormal.

### vkQueueSignalReleaseImageOHOS()

```
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSignalReleaseImageOHOS (VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int32_t* pNativeFenceFd )
```

**Description**

Sends a signal to the system hardware buffer to release an image once it is no longer needed so that other components can access it.

**System capability**: SystemCapability.Graphic.Vulkan

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| queue | Handle to the Vulkan queue.| 
| waitSemaphoreCount | Number of semaphores to wait on.| 
| pWaitSemaphores | Pointer to the array of semaphores to wait on.| 
| images | Handle to the Vulkan image to be released.| 
| pNativeFenceFd | Pointer to the file descriptor of the fence.| 

**Returns**

Returns an error code of the VkResult type.
- Returns **VK_SUCCESS** if the operation is successful.
- Returns **VK_ERROR_DEVICE_LOST** if the Vulkan device link is lost.
- Returns **VK_ERROR_OUT_OF_HOST_MEMORY** if the host memory is insufficient.

## Variable Description


### allocationSize


```
VkDeviceSize VkNativeBufferPropertiesOHOS::allocationSize
```

**Description**

Size of the occupied memory.


### buffer


```
struct OH_NativeBuffer* VkImportNativeBufferInfoOHOS::buffer
```

**Description**

Pointer to an **OH_NativeBuffer** struct.


### externalFormat [1/2]


```
uint64_t VkNativeBufferFormatPropertiesOHOS::externalFormat
```

**Description**

Externally defined format.


### externalFormat [2/2]


```
uint64_t VkExternalFormatOHOS::externalFormat
```

**Description**

Externally defined format.


### flags


```
VkSurfaceCreateFlagsOHOS VkSurfaceCreateInfoOHOS::flags
```

**Description**

Reserved flag type.


### format


```
VkFormat VkNativeBufferFormatPropertiesOHOS::format
```

**Description**

Format properties.


### formatFeatures


```
VkFormatFeatureFlags VkNativeBufferFormatPropertiesOHOS::formatFeatures
```

**Description**

Features of the externally defined format.


### memory


```
VkDeviceMemory VkMemoryGetNativeBufferInfoOHOS::memory
```

**Description**

**VkDeviceMemory** instance.


### memoryTypeBits


```
uint32_t VkNativeBufferPropertiesOHOS::memoryTypeBits
```

**Description**

Memory type.


### OHOSNativeBufferUsage


```
uint64_t VkNativeBufferUsageOHOS::OHOSNativeBufferUsage
```

**Description**

Usage of a **NativeBuffer**.


### pNext [1/7]


```
const void* VkSurfaceCreateInfoOHOS::pNext
```

**Description**

Pointer to the next-level struct.


### pNext [2/7]


```
void* VkNativeBufferUsageOHOS::pNext
```

**Description**

Pointer to the next-level struct.


### pNext [3/7]


```
void* VkNativeBufferPropertiesOHOS::pNext
```

**Description**

Pointer to the next-level struct.


### pNext [4/7]


```
void* VkNativeBufferFormatPropertiesOHOS::pNext
```

**Description**

Pointer to the next-level struct.


### pNext [5/7]


```
const void* VkImportNativeBufferInfoOHOS::pNext
```

**Description**

Pointer to the next-level struct.


### pNext [6/7]


```
const void* VkMemoryGetNativeBufferInfoOHOS::pNext
```

**Description**

Pointer to the next-level struct.


### pNext [7/7]


```
void* VkExternalFormatOHOS::pNext
```

**Description**

Pointer to the next-level struct.


### samplerYcbcrConversionComponents


```
VkComponentMapping VkNativeBufferFormatPropertiesOHOS::samplerYcbcrConversionComponents
```

**Description**

A group of VkComponentSwizzles.


### sType [1/7]


```
VkStructureType VkSurfaceCreateInfoOHOS::sType
```

**Description**

Struct type.


### sType [2/7]


```
VkStructureType VkNativeBufferUsageOHOS::sType
```

**Description**

Struct type.


### sType [3/7]


```
VkStructureType VkNativeBufferPropertiesOHOS::sType
```

**Description**

Struct type.


### sType [4/7]


```
VkStructureType VkNativeBufferFormatPropertiesOHOS::sType
```

**Description**

Struct type.


### sType [5/7]


```
VkStructureType VkImportNativeBufferInfoOHOS::sType
```

**Description**

Struct type.


### sType [6/7]


```
VkStructureType VkMemoryGetNativeBufferInfoOHOS::sType
```

**Description**

Struct type.


### sType [7/7]


```
VkStructureType VkExternalFormatOHOS::sType
```

**Description**

Struct type.


### suggestedXChromaOffset


```
VkChromaLocation VkNativeBufferFormatPropertiesOHOS::suggestedXChromaOffset
```

**Description**

X chrominance offset.


### suggestedYcbcrModel


```
VkSamplerYcbcrModelConversion VkNativeBufferFormatPropertiesOHOS::suggestedYcbcrModel
```

**Description**

Color model.


### suggestedYcbcrRange


```
VkSamplerYcbcrRange VkNativeBufferFormatPropertiesOHOS::suggestedYcbcrRange
```

**Description**

Color value range.


### suggestedYChromaOffset


```
VkChromaLocation VkNativeBufferFormatPropertiesOHOS::suggestedYChromaOffset
```

**Description**

Y chrominance offset.


### window


```
OHNativeWindow* VkSurfaceCreateInfoOHOS::window
```

**Description**

Pointer to an **OHNativeWindow** instance.
