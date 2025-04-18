# tensor.h


## 概述

提供了张量相关的接口，可用于创建和修改张量信息，该接口是非线程安全的。

**引用文件：** <mindspore/tensor.h>

**库：** libmindspore_lite_ndk.so

**系统能力：** SystemCapability.Ai.MindSpore

**起始版本：** 9

**相关模块：** [MindSpore](_mind_spore.md)


## 汇总


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) | 指向张量对象句柄。 |
| [OH_AI_AllocatorHandle](_mind_spore.md#oh_ai_allocatorhandle) | 指向内存分配器对象句柄。 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_AI_TensorCreate](_mind_spore.md#oh_ai_tensorcreate) (const char \*name, OH_AI_DataType type, const int64_t \*shape, <br/>size_t shape_num, const void \*data, size_t data_len) | 创建一个张量对象。 |
| [OH_AI_TensorDestroy](_mind_spore.md#oh_ai_tensordestroy) (OH_AI_TensorHandle \*tensor) | 释放张量对象。 |
| [OH_AI_TensorClone](_mind_spore.md#oh_ai_tensorclone) (OH_AI_TensorHandle tensor) | 深拷贝一个张量。 |
| [OH_AI_TensorSetName](_mind_spore.md#oh_ai_tensorsetname) (OH_AI_TensorHandle tensor, const char \*name) | 设置张量的名称。 |
| [OH_AI_TensorGetName](_mind_spore.md#oh_ai_tensorgetname) (const OH_AI_TensorHandle tensor) | 获取张量的名称。 |
| [OH_AI_TensorSetDataType](_mind_spore.md#oh_ai_tensorsetdatatype) (OH_AI_TensorHandle tensor, OH_AI_DataType type) | 设置张量的数据类型。 |
| [OH_AI_TensorGetDataType](_mind_spore.md#oh_ai_tensorgetdatatype) (const OH_AI_TensorHandle tensor) | 获取张量类型。 |
| [OH_AI_TensorSetShape](_mind_spore.md#oh_ai_tensorsetshape) (OH_AI_TensorHandle tensor, <br/>const int64_t \*shape, size_t shape_num) | 设置张量的形状。 |
| [OH_AI_TensorGetShape](_mind_spore.md#oh_ai_tensorgetshape) (const OH_AI_TensorHandle tensor, size_t \*shape_num) | 获取张量的形状。 |
| [OH_AI_TensorSetFormat](_mind_spore.md#oh_ai_tensorsetformat) (OH_AI_TensorHandle tensor, OH_AI_Format format) | 设置张量数据的排列方式。 |
| [OH_AI_TensorGetFormat](_mind_spore.md#oh_ai_tensorgetformat) (const OH_AI_TensorHandle tensor) | 获取张量数据的排列方式。 |
| [OH_AI_TensorSetData](_mind_spore.md#oh_ai_tensorsetdata) (OH_AI_TensorHandle tensor, void \*data) | 设置张量的数据。 |
| [OH_AI_TensorGetData](_mind_spore.md#oh_ai_tensorgetdata) (const OH_AI_TensorHandle tensor) | 获取张量数据的指针。 |
| [OH_AI_TensorGetMutableData](_mind_spore.md#oh_ai_tensorgetmutabledata) (const OH_AI_TensorHandle tensor) | 获取可变的张量数据指针。如果数据为空则会开辟内存。 |
| [OH_AI_TensorGetElementNum](_mind_spore.md#oh_ai_tensorgetelementnum) (const OH_AI_TensorHandle tensor) | 获取张量元素数量。 |
| [OH_AI_TensorGetDataSize](_mind_spore.md#oh_ai_tensorgetdatasize) (const OH_AI_TensorHandle tensor) | 获取张量中的数据的字节数大小。 |
| [OH_AI_TensorSetUserData](_mind_spore.md#oh_ai_tensorsetuserdata) ([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor, void \*data, size_t data_size) | 设置张量为用户自行管理的数据。此接口常用于复用用户数据作为模型输入，可减少一次数据拷贝。 |
| [OH_AI_TensorGetAllocator](_mind_spore.md#oh_ai_tensorgetallocator)([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor) | 获取内存分配器。 |
| [OH_AI_TensorSetAllocator](_mind_spore.md#oh_ai_tensorsetallocator)([OH_AI_TensorHandle](_mind_spore.md#oh_ai_tensorhandle) tensor, [OH_AI_AllocatorHandle](_mind_spore.md#oh_ai_allocatorhandle) allocator) | 设置内存分配器。 |
