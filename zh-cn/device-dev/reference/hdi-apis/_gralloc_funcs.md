# GrallocFuncs


## 概述

显示内存驱动接口结构体，定义显示内存驱动接口函数指针。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| (\*&nbsp;[AllocMem](#allocmem)&nbsp;)(const&nbsp;[AllocInfo](_alloc_info.md)&nbsp;\*info,&nbsp;BufferHandle&nbsp;\*\*handle) | int32_t<br/>显示内存分配。 | 
| (\*&nbsp;[FreeMem](#freemem)&nbsp;)(BufferHandle&nbsp;\*handle) | void<br/>显示内存释放。 | 
| (\*&nbsp;[Mmap](#mmap)&nbsp;)(BufferHandle&nbsp;\*handle) | void&nbsp;\*<br/>显示内存映射，将内存映射到对应的进程地址空间中。 | 
| (\*&nbsp;[MmapYUV](#mmapyuv)&nbsp;)(BufferHandle&nbsp;\*handle,&nbsp;YUVDescInfo&nbsp;\*info) | void&nbsp;\*<br/>YUV&nbsp;内存映射。 | 
| (\*&nbsp;[MmapCache](#mmapcache)&nbsp;)(BufferHandle&nbsp;\*handle) | void&nbsp;\*<br/>显示内存映射，将内存映射为&nbsp;cache&nbsp;内存到对应的进程地址空间中。 | 
| (\*&nbsp;[Unmap](#unmap)&nbsp;)(BufferHandle&nbsp;\*handle) | int32_t<br/>内存反映射，将内存进行反映射。 | 
| (\*&nbsp;[FlushCache](#flushcache)&nbsp;)(BufferHandle&nbsp;\*handle) | int32_t<br/>刷新cache，刷新cache里的内容到内存并且使cache里的内容无效。 | 
| (\*&nbsp;[FlushMCache](#flushmcache)&nbsp;)(BufferHandle&nbsp;\*handle) | int32_t<br/>刷新Mmap映射的cache，刷新Mmap映射的cache里的内容到内存并且使cache里的内容无效。 | 
| (\*&nbsp;[InvalidateCache](#invalidatecache)&nbsp;)(BufferHandle&nbsp;\*handle) | int32_t<br/>使cache中的内容无效用以存储更新内存内容。 | 
| (\*&nbsp;[IsSupportedAlloc](#issupportedalloc)&nbsp;)(uint32_t&nbsp;num,&nbsp;const&nbsp;[VerifyAllocInfo](_verify_alloc_info.md)&nbsp;\*infos,&nbsp;bool&nbsp;\*supporteds) | int32_t<br/>检测给定的VerifyAllocInfo数组信息能否申请内存成功。 | 


## 类成员变量说明


### AllocMem

  
```
int32_t(* GrallocFuncs::AllocMem) (const AllocInfo *info, BufferHandle **handle)
```

**描述:**

显示内存分配。

根据GUI图形系统传递的参数分配内存，分配的内存根据类型可分为共享内存、cache内存和非cache内存等。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| info | 输入参数，指示申请内存AllocInfo信息. | 
| handle | 输入参数，指向申请的内存handle指针。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### FlushCache

  
```
int32_t(* GrallocFuncs::FlushCache) (BufferHandle *handle)
```

**描述:**

刷新cache，刷新cache里的内容到内存并且使cache里的内容无效。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输出参数，待刷新cache的handle指针。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### FlushMCache

  
```
int32_t(* GrallocFuncs::FlushMCache) (BufferHandle *handle)
```

**描述:**

刷新Mmap映射的cache，刷新Mmap映射的cache里的内容到内存并且使cache里的内容无效。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输出参数，待刷新cache的handle指针。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### FreeMem

  
```
void(* GrallocFuncs::FreeMem) (BufferHandle *handle)
```

**描述:**

显示内存释放。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待释放的内存handle指针。 | 

**返回:**

成功返回有效地址，失败返回NULL。


### InvalidateCache

  
```
int32_t(* GrallocFuncs::InvalidateCache) (BufferHandle *handle)
```

**描述:**

使cache中的内容无效用以存储更新内存内容。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输出参数，待无效cache的handle指针。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### IsSupportedAlloc

  
```
int32_t(* GrallocFuncs::IsSupportedAlloc) (uint32_t num, const VerifyAllocInfo *infos, bool *supporteds)
```

**描述:**

检测给定的VerifyAllocInfo数组信息能否申请内存成功。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| num | 输入参数，VerifyAllocInfo数组个数。 | 
| infos | 输出参数，VerifyAllocInfo数组首地址。 | 
| supporteds | 输出参数，supporteds数组首地址,&nbsp;表示能否申请成功。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### Mmap

  
```
void *(* GrallocFuncs::Mmap) (BufferHandle *handle)
```

**描述:**

显示内存映射，将内存映射到对应的进程地址空间中。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待映射内存handle指针。 | 

**返回:**

成功返回有效地址，失败返回NULL。


### MmapCache

  
```
void *(* GrallocFuncs::MmapCache) (BufferHandle *handle)
```

**描述:**

显示内存映射，将内存映射为 cache 内存到对应的进程地址空间中。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输出参数，待映射内存&nbsp;handle&nbsp;指针。 | 

**返回:**

成功返回有效地址，失败返回 NULL。


### MmapYUV

  
```
void *(* GrallocFuncs::MmapYUV) (BufferHandle *handle, YUVDescInfo *info)
```

**描述:**

YUV 内存映射。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输出参数，指示内存映射的输出缓存。 | 
| info | 输出参数，指示内存映射的YUVDescInfo信息。 | 

**返回:**

成功返回有效地址，失败返回 NULL。


### Unmap

  
```
int32_t(* GrallocFuncs::Unmap) (BufferHandle *handle)
```

**描述:**

内存反映射，将内存进行反映射。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输出参数，待反映射内存handle指针。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。
