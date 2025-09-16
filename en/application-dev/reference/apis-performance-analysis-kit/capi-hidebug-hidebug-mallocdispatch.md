# HiDebug_MallocDispatch

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the struct types of the replaceable/restorable **HiDebug_MallocDispatch** table of the application process.

**Since**: 20

**Related module**: [HiDebug](capi-hidebug.md)

**Header file**: [hidebug_type.h](capi-hidebug-type-h.md)

## Summary

### Member Function

| Name| Description|
| -- | -- |
| [void* (\*malloc)(size_t)](#malloc) | Pointer to the custom **malloc** function.|
| [void* (\*calloc)(size_t, size_t)](#calloc) | Pointer to the custom **calloc** function.|
| [void* (\*realloc)(void*, size_t)](#realloc) | Pointer to the custom **realloc** function.|
| [void (\*free)(void*)](#free) | Pointer to the custom **free** function.|
| [void* (\*mmap)(void*, size_t, int, int, int, off_t)](#mmap) | Pointer to the custom **mmap** function.|
| [int (\*munmap)(void*, size_t)](#munmap) | Pointer to the custom **munmap** function.|

## Member Function Description

### malloc()

```
void* (*malloc)(size_t)
```

**Description**

Pointer to the custom **malloc** function.

### calloc()

```
void* (*calloc)(size_t, size_t)
```

**Description**

Pointer to the custom **calloc** function.

### realloc()

```
void* (*realloc)(void*, size_t)
```

**Description**

Pointer to the custom **realloc** function.

### free()

```
void (*free)(void*)
```

**Description**

Pointer to the custom **free** function.

### mmap()

```
void* (*mmap)(void*, size_t, int, int, int, off_t)
```

**Description**

Pointer to the custom **mmap** function.

### munmap()

```
int (*munmap)(void*, size_t)
```

**Description**

Pointer to the custom **munmap** function.
