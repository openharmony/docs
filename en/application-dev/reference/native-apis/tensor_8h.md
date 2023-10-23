# tensor.h


## Overview

Provides APIs for creating and modifying tensor information.

**Since:**
9

**Related Modules:**

[MindSpore](_mind_spore.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) | Defines the handle of a tensor object.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_AI_TensorCreate](_mind_spore.md#oh_ai_tensorcreate) (const char \*name, [OH_AI_DataType](_mind_spore.md#oh_ai_datatype) type, const int64_t \*shape, size_t shape_num, const void \*data, size_t data_len) | Creates a tensor object.  | 
| [OH_AI_TensorDestroy](_mind_spore.md#oh_ai_tensordestroy) ([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) \*tensor) | Destroys a tensor object.  | 
| [OH_AI_TensorClone](_mind_spore.md#oh_ai_tensorclone) ([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor) | Clones a tensor.  | 
| [OH_AI_TensorSetName](_mind_spore.md#oh_ai_tensorsetname) ([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor, const char \*name) | Sets the name of a tensor.  | 
| [OH_AI_TensorGetName](_mind_spore.md#oh_ai_tensorgetname) (const [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor) | Obtains the name of a tensor.  | 
| [OH_AI_TensorSetDataType](_mind_spore.md#oh_ai_tensorsetdatatype) ([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor, [OH_AI_DataType](_mind_spore.md#oh_ai_datatype) type) | Sets the data type of a tensor.  | 
| [OH_AI_TensorGetDataType](_mind_spore.md#oh_ai_tensorgetdatatype) (const [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor) | Obtains the data type of a tensor.  | 
| [OH_AI_TensorSetShape](_mind_spore.md#oh_ai_tensorsetshape) ([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor, const int64_t \*shape, size_t shape_num) | Sets the shape of a tensor.  | 
| [OH_AI_TensorGetShape](_mind_spore.md#oh_ai_tensorgetshape) (const [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor, size_t \*shape_num) | Obtains the shape of a tensor.  | 
| [OH_AI_TensorSetFormat](_mind_spore.md#oh_ai_tensorsetformat) ([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor, [OH_AI_Format](_mind_spore.md#oh_ai_format) format) | Sets the tensor data format.  | 
| [OH_AI_TensorGetFormat](_mind_spore.md#oh_ai_tensorgetformat) (const [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor) | Obtains the tensor data format.  | 
| [OH_AI_TensorSetData](_mind_spore.md#oh_ai_tensorsetdata) ([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor, void \*data) | Sets the tensor data.  | 
| [OH_AI_TensorGetData](_mind_spore.md#oh_ai_tensorgetdata) (const [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor) | Obtains the pointer to tensor data.  | 
| [OH_AI_TensorGetMutableData](_mind_spore.md#oh_ai_tensorgetmutabledata) (const [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor) | Obtains the pointer to variable tensor data. If the data is empty, memory will be allocated.  | 
| [OH_AI_TensorGetElementNum](_mind_spore.md#oh_ai_tensorgetelementnum) (const [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor) | Obtains the number of tensor elements.  | 
| [OH_AI_TensorGetDataSize](_mind_spore.md#oh_ai_tensorgetdatasize) (const [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor) | Obtains the number of bytes of the tensor data.  | 
