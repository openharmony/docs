# Base DDK


## 概述

提供基础API，包括创建共享内存、共享内存映射、取消共享内存映射、销毁共享内存。

**系统能力：** SystemCapability.Driver.DDK.Extension

**起始版本：** 

12

## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ddk_api.h](ddk_api.md) | 声明主机侧访问输入设备的HID DDK接口。 <br/>引用文件：&lt;base/ddk_api.h&gt; <br/>库： libddk_base.z.so | 
| [ddk_types.h](ddk_types.md) | 提供HID DDK中的枚举变量与结构体定义。<br/>引用文件：&lt;base/ddk_types.h&gt; <br/>库： libddk_base.z.so | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [DDK_Ashmem](_ddk_ashmem.md) | 共享内存。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DDK_RetCode](#ddk_retcode) | Base DDK 错误码定义。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_DDK_CreateAshmem](#oh_ddk_createashmem) (const uint8_t *name, [DDK_Ashmem](_ddk_ashmem.md) \*\*ashmem) | 创建共享内存。  | 
| [OH_DDK_MapAshmem](#oh_ddk_mapashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem, const uint8_t ashmemMapType) | 共享内存映射。  | 
| [OH_DDK_UnmapAshmem](#oh_ddk_unmapashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem) | 取消共享内存映射。  | 
| [OH_DDK_DestroyAshmem](#oh_ddk_destroyashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem) | 销毁共享内存。  | 


## 枚举类型说明


### DDK_RetCode


```
enum DDK_RetCode
```

**描述:**

Base DDK 错误码定义。

| 枚举值 | 描述 |
| -------- | -------- |
| DDK_SUCCESS | 操作成功。 |
| DDK_FAILED | 操作失败。 |
| DDK_INVALID_PARAMETER | 非法参数。 |
| DDK_INVALID_OPERATION | 非法操作。 |
| DDK_NULL_PTR | 空指针异常。 |


## 函数说明


### OH_DDK_CreateAshmem()


```
DDK_RetCode OH_DDK_CreateAshmem(const uint8_t *name, uint32_t size, DDK_Ashmem **ashmem);
```

**描述:**

创建共享内存。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| name | 指向要创建的共享内存的指针。 |
| size | 共享内存对应的缓冲区大小。 |
| ashmem | 指向创建的共享内存的指针。 |

**返回:**

- [DK_SUCCESS](#ddk_retcode) 表示调用接口成功。
- [DDK_INVALID_PARAMETER](#ddk_retcode) 表示入参name为空指针，size的大小为0或者入参ashmem为空指针。
- [DDK_FAILURE](#ddk_retcode) 表示创建共享内存失败或者创建结构体DDK_Ashmem失败。


### OH_DDK_MapAshmem()


```
DDK_RetCode OH_DDK_MapAshmem(DDK_Ashmem *ashmem, const uint8_t ashmemMapType);
```

**描述:**

映射共享内存。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| ashmem | 要映射的共享内存指针。 |
| ashmemMapType | 共享内存的保护权限值。 |

**返回:**

- [DK_SUCCESS](#ddk_retcode) 表示调用接口成功。
- [DDK_NULL_PTR](#ddk_retcode) 表示入参ashmem为空指针。
- [DDK_FAILURE](#ddk_retcode) 表示共享内存的文件描述符无效。
- [DDK_INVALID_OPERATION](#ddk_retcode) 表示调用接口MapAshmem失败。


### OH_DDK_UnmapAshmem()


```
DDK_RetCode OH_DDK_UnmapAshmem(DDK_Ashmem *ashmem);
```

**描述:**

取消共享内存的映射。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
|  ashmem | 要取消映射的共享内存指针。 |

**返回:**

- [DK_SUCCESS](#ddk_retcode) 表示调用接口成功。
- [DDK_NULL_PTR](#ddk_retcode) 表示入参ashmem为空指针。
- [DDK_FAILURE](#ddk_retcode) 表示共享内存的文件描述符无效。

### OH_DDK_DestroyAshmem()


```
DDK_RetCode OH_DDK_DestroyAshmem(DDK_Ashmem *ashmem);
```

**描述:**

销毁创建的共享内存。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
|  ashmem | 要销毁的共享内存指针。 |

**返回:**

- [DK_SUCCESS](#ddk_retcode) 表示调用接口成功。
- [DDK_NULL_PTR](#ddk_retcode) 表示入参ashmem为空指针。
- [DDK_FAILURE](#ddk_retcode) 表示共享内存的文件描述符无效。