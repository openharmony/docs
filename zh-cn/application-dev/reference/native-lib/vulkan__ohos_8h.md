# vulkan_ohos.h


## 概述

定义了OpenHarmony平台扩展的Vulkan接口。引用文件：&lt;vulkan/vulkan.h&gt;。

**起始版本：**

10

**相关模块：**

[Vulkan](_vulkan.md)


## 汇总


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
| [VK_OHOS_surface](_vulkan.md#vk_ohos_surface)   1 | OpenHarmony平台Surface扩展宏定义。 |
| [VK_OHOS_SURFACE_SPEC_VERSION](_vulkan.md#vk_ohos_surface_spec_version)   1 | OpenHarmony平台Surface扩展版本号。 |
| [VK_OHOS_SURFACE_EXTENSION_NAME](_vulkan.md#vk_ohos_surface_extension_name)   "VK_OHOS_surface" | OpenHarmony平台Surface扩展名。 |
| [VK_OHOS_external_memory](_vulkan.md#vk_ohos_external_memory)   1 | OpenHarmony平台external_memory扩展宏定义。 |
| [VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION](_vulkan.md#vk_ohos_external_memory_spec_version)   1 | OpenHarmony平台external_memory扩展版本号。 |
| [VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME](_vulkan.md#vk_ohos_external_memory_extension_name)   "VK_OHOS_external_memory" | OpenHarmony平台external_memory扩展名。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OHNativeWindow](_vulkan.md#ohnativewindow) | OH本地窗口。 |
| [VkSurfaceCreateFlagsOHOS](_vulkan.md#vksurfacecreateflagsohos) | 用于Vulkan Surface创建时使用到的VkFlags类型位掩码，预留的标志类型。 |
| [VkSurfaceCreateInfoOHOS](_vulkan.md#vksurfacecreateinfoohos) | 包含创建Vulkan Surface时必要的参数。 |
| VkResult ([VKAPI_PTR *PFN_vkCreateSurfaceOHOS](_vulkan.md#pfn_vkcreatesurfaceohos)) (VkInstance instance, const [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) \*pCreateInfo, const VkAllocationCallbacks \*pAllocator, VkSurfaceKHR \*pSurface) | 创建Vulkan Surface的函数指针定义。 |
| [VkNativeBufferUsageOHOS](_vulkan.md#vknativebufferusageohos) | 提供OpenHarmony NativeBuffer用途的说明。 |
| [VkNativeBufferPropertiesOHOS](_vulkan.md#vknativebufferpropertiesohos) | 包含了NativeBuffer的属性。 |
| [VkNativeBufferFormatPropertiesOHOS](_vulkan.md#vknativebufferformatpropertiesohos) | 包含了NativeBuffer的一些格式属性。 |
| [VkImportNativeBufferInfoOHOS](_vulkan.md#vkimportnativebufferinfoohos) | 包含了OH_NativeBuffer结构体的指针。 |
| [VkMemoryGetNativeBufferInfoOHOS](_vulkan.md#vkmemorygetnativebufferinfoohos) | 用于从Vulkan内存中获取OH_NativeBuffer。 |
| [VkExternalFormatOHOS](_vulkan.md#vkexternalformatohos) | 表示外部定义的格式标识符。 |
| VkResult ([VKAPI_PTR *PFN_vkGetNativeBufferPropertiesOHOS](_vulkan.md#pfn_vkgetnativebufferpropertiesohos)) (VkDevice device, const struct OH_NativeBuffer \*buffer, [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) \*pProperties) | 获取OH_NativeBuffer属性的函数指针定义。 |
| VkResult ([VKAPI_PTR *PFN_vkGetMemoryNativeBufferOHOS](_vulkan.md#pfn_vkgetmemorynativebufferohos)) (VkDevice device, const [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) \*pInfo, struct OH_NativeBuffer \*\*pBuffer) | 获取OH_NativeBuffer的函数指针定义。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [vkCreateSurfaceOHOS](_vulkan.md#vkcreatesurfaceohos) (VkInstance instance, const [VkSurfaceCreateInfoOHOS](_vk_surface_create_info_o_h_o_s.md) \*pCreateInfo, const VkAllocationCallbacks \*pAllocator, VkSurfaceKHR \*pSurface) | 创建Vulkan Surface。 |
| [vkGetNativeBufferPropertiesOHOS](_vulkan.md#vkgetnativebufferpropertiesohos) (VkDevice device, const struct OH_NativeBuffer \*buffer, [VkNativeBufferPropertiesOHOS](_vk_native_buffer_properties_o_h_o_s.md) \*pProperties) | 获取OH_NativeBuffer属性。 |
| [vkGetMemoryNativeBufferOHOS](_vulkan.md#vkgetmemorynativebufferohos) (VkDevice device, const [VkMemoryGetNativeBufferInfoOHOS](_vk_memory_get_native_buffer_info_o_h_o_s.md) \*pInfo, struct OH_NativeBuffer \*\*pBuffer) | 获取OH_NativeBuffer。 |
