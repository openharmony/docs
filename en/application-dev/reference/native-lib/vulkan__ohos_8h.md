# vulkan_ohos.h


## Overview

The **vulkan_ohos.h** file declares the Vulkan interfaces extended by OpenHarmony.

**File to include**: &lt;vulkan/vulkan.h&gt;

**Since**

10

**Related Modules**

[Vulkan](_vulkan.md)


## Summary


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
| [VK_OHOS_surface](_vulkan.md#vk_ohos_surface)   1 | Surface extension macro definition of OpenHarmony.|
| [VK_OHOS_SURFACE_SPEC_VERSION](_vulkan.md#vk_ohos_surface_spec_version)   1 | Surface extension version of OpenHarmony.|
| [VK_OHOS_SURFACE_EXTENSION_NAME](_vulkan.md#vk_ohos_surface_extension_name)   "VK_OHOS_surface" | Surface extension name of OpenHarmony.|
| [VK_OHOS_external_memory](_vulkan.md#vk_ohos_external_memory)   1 | External memory extension macro definition of OpenHarmony.|
| [VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION](_vulkan.md#vk_ohos_external_memory_spec_version)   1 | External memory extension version of OpenHarmony.|
| [VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME](_vulkan.md#vk_ohos_external_memory_extension_name)   "VK_OHOS_external_memory" | External memory extension name of OpenHarmony.|


### Types

| Name| Description|
| -------- | -------- |
| [OHNativeWindow](_vulkan.md#ohnativewindow) | Defines an **OHNativeWindow**.|
| [VkSurfaceCreateFlagsOHOS](_vulkan.md#vksurfacecreateflagsohos) | Defines the bit mask of the VkFlags type used for the creation of a Vulkan surface. It is a reserved flag type.|
| [VkSurfaceCreateInfoOHOS](_vulkan.md#vksurfacecreateinfoohos) | Defines the parameters required for creating a Vulkan surface.|
| VkResult ([VKAPI_PTR *PFN_vkCreateSurfaceOHOS](_vulkan.md#pfn_vkcreatesurfaceohos)) (VkInstance instance, const [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) \*pCreateInfo, const VkAllocationCallbacks \*pAllocator, VkSurfaceKHR \*pSurface) | Defines the function pointer for creating a Vulkan surface.|
| [VkNativeBufferUsageOHOS](_vulkan.md#vknativebufferusageohos) | Defines the usage of a **NativeBuffer**.|
| [VkNativeBufferPropertiesOHOS](_vulkan.md#vknativebufferpropertiesohos) | Defines the properties of a **NativeBuffer**.|
| [VkNativeBufferFormatPropertiesOHOS](_vulkan.md#vknativebufferformatpropertiesohos) | Defines the format properties of a **NativeBuffer**.|
| [VkImportNativeBufferInfoOHOS](_vulkan.md#vkimportnativebufferinfoohos) | Defines the pointer to an **OH_NativeBuffer** struct.|
| [VkMemoryGetNativeBufferInfoOHOS](_vulkan.md#vkmemorygetnativebufferinfoohos) | Defines a struct used to obtain an **OH_NativeBuffer** from the Vulkan memory.|
| [VkExternalFormatOHOS](_vulkan.md#vkexternalformatohos) | Defines an externally defined format.|
| VkResult ([VKAPI_PTR *PFN_vkGetNativeBufferPropertiesOHOS](_vulkan.md#pfn_vkgetnativebufferpropertiesohos)) (VkDevice device, const struct OH_NativeBuffer \*buffer, [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) \*pProperties) | Defines a function pointer used to obtain **OH_NativeBuffer** properties.|
| VkResult ([VKAPI_PTR *PFN_vkGetMemoryNativeBufferOHOS](_vulkan.md#pfn_vkgetmemorynativebufferohos)) (VkDevice device, const [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) \*pInfo, struct OH_NativeBuffer \*\*pBuffer) | Defines a function pointer used to obtain an **OH_NativeBuffer** instance.|


### Functions

| Name| Description|
| -------- | -------- |
| VKAPI_ATTR VkResult VKAPI_CALL [vkCreateSurfaceOHOS](_vulkan.md#vkcreatesurfaceohos) (VkInstance instance, const [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) \*pCreateInfo, const VkAllocationCallbacks \*pAllocator, VkSurfaceKHR \*pSurface) | Creates a Vulkan surface. | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkGetNativeBufferPropertiesOHOS](_vulkan.md#vkgetnativebufferpropertiesohos) (VkDevice device, const struct OH_NativeBuffer \*buffer, [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) \*pProperties) | Obtains the properties of an **OH_NativeBuffer** instance. | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkGetMemoryNativeBufferOHOS](_vulkan.md#vkgetmemorynativebufferohos) (VkDevice device, const [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) \*pInfo, struct OH_NativeBuffer \*\*pBuffer) | Obtains an **OH_NativeBuffer** instance. | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkGetSwapchainGrallocUsageOHOS](_vulkan.md#vkgetswapchaingrallocusageohos) (VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t \*grallocUsage) | Returns the appropriate gralloc usage flag based on the given Vulkan device, image format, and image usage flag. | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkAcquireImageOHOS](_vulkan.md#vkacquireimageohos) (VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence) | Obtains the ownership of the swap chain image and imports the fence of the external signal to the VkSemaphore and VkFence objects. | 
| VKAPI_ATTR VkResult VKAPI_CALL [vkQueueSignalReleaseImageOHOS](_vulkan.md#vkqueuesignalreleaseimageohos) (VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore \*pWaitSemaphores, VkImage image, int32_t \*pNativeFenceFd) | Sends a signal to the system hardware buffer to release an image once it is no longer needed so that other components can access it. | 
