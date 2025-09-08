# tensor.h

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## Overview

Provides tensor-related APIs, which can be used to create tensors and modify tensor information. These APIs are non-thread-safe.

**File to include**: <mindspore/tensor.h>

**Library**: libmindspore_lite_ndk.so

**System capability**: SystemCapability.Ai.MindSpore

**Since**: 9

**Related module**: [MindSpore](capi-mindspore.md)

## Summary

### Structs

| Name| typedef Keyword                                                | Description|
|----|------------------------------------------------------------|----|
| void *   | [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) | Defines the handle of a tensor object.  |
| void *   | [OH_AI_AllocatorHandle](capi-mindspore-oh-ai-allocatorhandle.md)  | Defines the handle of the memory allocator.  |

### Functions

| Name| Description|
| -- | -- |
| [OH_AI_API OH_AI_TensorHandle OH_AI_TensorCreate(const char *name, OH_AI_DataType type, const int64_t *shape,size_t shape_num, const void *data, size_t data_len)](#oh_ai_tensorcreate) | Creates a tensor object.|
| [OH_AI_API void OH_AI_TensorDestroy(OH_AI_TensorHandle *tensor)](#oh_ai_tensordestroy) | Destroys a tensor object.|
| [OH_AI_API OH_AI_TensorHandle OH_AI_TensorClone(OH_AI_TensorHandle tensor)](#oh_ai_tensorclone) | Clones a tensor.|
| [OH_AI_API void OH_AI_TensorSetName(OH_AI_TensorHandle tensor, const char *name)](#oh_ai_tensorsetname) | Sets the tensor name.|
| [OH_AI_API const char *OH_AI_TensorGetName(const OH_AI_TensorHandle tensor)](#oh_ai_tensorgetname) | Obtains the tensor name.|
| [OH_AI_API void OH_AI_TensorSetDataType(OH_AI_TensorHandle tensor, OH_AI_DataType type)](#oh_ai_tensorsetdatatype) | Sets the data type of a tensor.|
| [OH_AI_API OH_AI_DataType OH_AI_TensorGetDataType(const OH_AI_TensorHandle tensor)](#oh_ai_tensorgetdatatype) | Obtains the tensor type.|
| [OH_AI_API void OH_AI_TensorSetShape(OH_AI_TensorHandle tensor, const int64_t *shape, size_t shape_num)](#oh_ai_tensorsetshape) | Sets the tensor shape.|
| [OH_AI_API const int64_t *OH_AI_TensorGetShape(const OH_AI_TensorHandle tensor, size_t *shape_num)](#oh_ai_tensorgetshape) | Obtains the tensor shape.|
| [OH_AI_API void OH_AI_TensorSetFormat(OH_AI_TensorHandle tensor, OH_AI_Format format)](#oh_ai_tensorsetformat) | Sets the tensor data format.|
| [OH_AI_API OH_AI_Format OH_AI_TensorGetFormat(const OH_AI_TensorHandle tensor)](#oh_ai_tensorgetformat) | Obtains the tensor data format.|
| [OH_AI_API void OH_AI_TensorSetData(OH_AI_TensorHandle tensor, void *data)](#oh_ai_tensorsetdata) | Sets the tensor data.|
| [OH_AI_API const void *OH_AI_TensorGetData(const OH_AI_TensorHandle tensor)](#oh_ai_tensorgetdata) | Obtains the pointer to tensor data.|
| [OH_AI_API void *OH_AI_TensorGetMutableData(const OH_AI_TensorHandle tensor)](#oh_ai_tensorgetmutabledata) | Obtains the pointer to variable tensor data. If the data is empty, memory will be allocated.|
| [OH_AI_API int64_t OH_AI_TensorGetElementNum(const OH_AI_TensorHandle tensor)](#oh_ai_tensorgetelementnum) | Obtains the number of tensor elements.|
| [OH_AI_API size_t OH_AI_TensorGetDataSize(const OH_AI_TensorHandle tensor)](#oh_ai_tensorgetdatasize) | Obtains the number of bytes of the tensor data.|
| [OH_AI_API OH_AI_Status OH_AI_TensorSetUserData(OH_AI_TensorHandle tensor, void *data, size_t data_size)](#oh_ai_tensorsetuserdata) | Sets the tensor as the user data. This function allows you to reuse user data as the model input, which helps to reduce data copy by one time.<br> > **NOTE**<br>The user data is type of external data for the tensor and is not automatically released when the tensor is destroyed. The caller needs to release the data separately. In addition, the caller must ensure that the user data is valid during use of the tensor.|
| [OH_AI_API OH_AI_AllocatorHandle OH_AI_TensorGetAllocator(OH_AI_TensorHandle tensor)](#oh_ai_tensorgetallocator) | Obtains a memory allocator. The allocator is responsible for allocating memory for tensors.|
| [OH_AI_API OH_AI_Status OH_AI_TensorSetAllocator(OH_AI_TensorHandle tensor, OH_AI_AllocatorHandle allocator)](#oh_ai_tensorsetallocator) | Sets the memory allocator. The allocator is responsible for allocating memory for tensors.|

## Function Description

### OH_AI_TensorCreate()

```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorCreate(const char *name, OH_AI_DataType type, const int64_t *shape,size_t shape_num, const void *data, size_t data_len)
```

**Description**

Creates a tensor object.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Tensor name.|
| [OH_AI_DataType](capi-data-type-h.md#oh_ai_datatype) type | Tensor data type.|
| const int64_t *shape | Tensor dimension array.|
| size_t shape_num | Length of the tensor dimension array.|
| const void *data | Data pointer.|
| size_t data_len | Data length.|

**Returns**

| Type                              | Description|
|----------------------------------| -- |
| OH_AI_API [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) | Handle of the tensor object.|

### OH_AI_TensorDestroy()

```
OH_AI_API void OH_AI_TensorDestroy(OH_AI_TensorHandle *tensor)
```

**Description**

Destroys a tensor object.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) *tensor | Level-2 pointer to the tensor handle.|

### OH_AI_TensorClone()

```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorClone(OH_AI_TensorHandle tensor)
```

**Description**

Clones a tensor.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Pointer to the tensor to clone.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) | Handle of the new tensor object.|

### OH_AI_TensorSetName()

```
OH_AI_API void OH_AI_TensorSetName(OH_AI_TensorHandle tensor, const char *name)
```

**Description**

Sets the tensor name.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|
| const char *name | Tensor name.|

### OH_AI_TensorGetName()

```
OH_AI_API const char *OH_AI_TensorGetName(const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the tensor name.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API const char * | Tensor name.|

### OH_AI_TensorSetDataType()

```
OH_AI_API void OH_AI_TensorSetDataType(OH_AI_TensorHandle tensor, OH_AI_DataType type)
```

**Description**

Sets the data type of a tensor.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|
| [OH_AI_DataType](capi-data-type-h.md#oh_ai_datatype) type | Data type. For details, see [OH_AI_DataType](capi-data-type-h.md#oh_ai_datatype).|

### OH_AI_TensorGetDataType()

```
OH_AI_API OH_AI_DataType OH_AI_TensorGetDataType(const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the tensor type.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|

**Returns**

| Type                                                            | Description|
|----------------------------------------------------------------| -- |
| OH_AI_API [OH_AI_DataType](capi-data-type-h.md#oh_ai_datatype) | Tensor data type.|

### OH_AI_TensorSetShape()

```
OH_AI_API void OH_AI_TensorSetShape(OH_AI_TensorHandle tensor, const int64_t *shape, size_t shape_num)
```

**Description**

Sets the tensor shape.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|
| const int64_t *shape | Shape array.|
| size_t shape_num | Length of the tensor shape array.|

### OH_AI_TensorGetShape()

```
OH_AI_API const int64_t *OH_AI_TensorGetShape(const OH_AI_TensorHandle tensor, size_t *shape_num)
```

**Description**

Obtains the tensor shape.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|
| size_t *shape_num | Length of the tensor shape array.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API const int64_t * | Shape array.|

### OH_AI_TensorSetFormat()

```
OH_AI_API void OH_AI_TensorSetFormat(OH_AI_TensorHandle tensor, OH_AI_Format format)
```

**Description**

Sets the tensor data format.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|
| [OH_AI_Format](capi-format-h.md#oh_ai_format) format | Tensor data format.|

### OH_AI_TensorGetFormat()

```
OH_AI_API OH_AI_Format OH_AI_TensorGetFormat(const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the tensor data format.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|

**Returns**

| Type                                                     | Description|
|---------------------------------------------------------| -- |
| OH_AI_API [OH_AI_Format](capi-format-h.md#oh_ai_format) | Tensor data format.|

### OH_AI_TensorSetData()

```
OH_AI_API void OH_AI_TensorSetData(OH_AI_TensorHandle tensor, void *data)
```

**Description**

Sets the tensor data.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|
| void *data | Data pointer.|

### OH_AI_TensorGetData()

```
OH_AI_API const void *OH_AI_TensorGetData(const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the pointer to tensor data.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API const void * | Pointer to tensor data.|

### OH_AI_TensorGetMutableData()

```
OH_AI_API void *OH_AI_TensorGetMutableData(const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the pointer to variable tensor data. If the data is empty, memory will be allocated.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API void * | Pointer to tensor data.|

### OH_AI_TensorGetElementNum()

```
OH_AI_API int64_t OH_AI_TensorGetElementNum(const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the number of tensor elements.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API int64_t | Number of tensor elements.|

### OH_AI_TensorGetDataSize()

```
OH_AI_API size_t OH_AI_TensorGetDataSize(const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the number of bytes of the tensor data.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API size_t | Number of bytes of the tensor data.|

### OH_AI_TensorSetUserData()

```
OH_AI_API OH_AI_Status OH_AI_TensorSetUserData(OH_AI_TensorHandle tensor, void *data, size_t data_size)
```

**Description**

Sets the tensor as the user data. This function allows you to reuse user data as the model input, which helps to reduce data copy by one time.<br>> **NOTE**<br>The user data is type of external data for the tensor and is not automatically released when the tensor is destroyed. The caller needs to release the data separately. In addition, the caller must ensure that the user data is valid during use of the tensor.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|
| void *data | Start address of user data.|
| size_t data_size | Length of the user data length.|

**Returns**

| Type                                                     | Description|
|---------------------------------------------------------| -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Execution status code. The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_TensorGetAllocator()

```
OH_AI_API OH_AI_AllocatorHandle OH_AI_TensorGetAllocator(OH_AI_TensorHandle tensor)
```

**Description**

Obtains a memory allocator. The allocator is responsible for allocating memory for tensors.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|

**Returns**

| Type                                 | Description|
|-------------------------------------| -- |
| OH_AI_API [OH_AI_AllocatorHandle](capi-mindspore-oh-ai-allocatorhandle.md) | Handle of the memory allocator.|

### OH_AI_TensorSetAllocator()

```
OH_AI_API OH_AI_Status OH_AI_TensorSetAllocator(OH_AI_TensorHandle tensor, OH_AI_AllocatorHandle allocator)
```

**Description**

Sets the memory allocator. The allocator is responsible for allocating memory for tensors.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) tensor | Handle of the tensor object.|
| [OH_AI_AllocatorHandle](capi-mindspore-oh-ai-allocatorhandle.md) allocator | Handle of the memory allocator.|

**Returns**

| Type                                                     | Description|
|---------------------------------------------------------| -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Execution status code. The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|
