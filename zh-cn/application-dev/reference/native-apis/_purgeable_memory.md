# Purgeable Memory


提供Purgeable Memory Native功能，主要用来开发purgeable应用。


\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory


**起始版本：**


10


## 汇总


### 文件

  | 文件名称 | 描述 | 
| -------- | -------- |
| [purgeable_memory.h](purgeable_memory.md) | 定义获取和使用PurgeableMemory的相关函数。


### 结构体

  | 结构体名称 | 描述 | 
| -------- | -------- |
| [OH_PurgeableMemory](purgeable_memory.md) | 表示Purgeable对象 |  


### 函数

| 函数名称 | 描述 | 
| -------- | -------- |
|OH_PurgeableMemory_Create (size_t size, OH_PurgeableMemory_ModifyFunc func, void \*funcPara) | 创建Purgeable Memory实例，每次调用都会产生一个新的Purgeable Memory实例 |
|bool OH_PurgeableMemory_Destroy(OH_PurgeableMemory \*purgObj)| 将Purgeable memory对象会被析构掉|
|bool OH_PurgeableMemory_BeginRead(OH_PurgeableMemory \*purgObj)|对purgeable对象进行读访问|
|void OH_PurgeableMemory_EndRead(OH_PurgeableMemory \*purgObj)|读操作结束，将Purgeable对象的引用计数减1，当引用计数为0的时候， 该Purgeable memory对象可以被系统回收|
|bool OH_PurgeableMemory_BeginWrite(OH_PurgeableMemory \*purgObj)|通过NativeWindow对象申请一块NativeWindowBuffer，用以内容生产|
|bool OH_PurgeableMemory_BeginWrite(OH_PurgeableMemory \*purgObj)|对purgeable对象进行写访问|
|void OH_PurgeableMemory_EndWrite(OH_PurgeableMemory \*purgObj)|写操作结束，将Purgeable对象的引用计数减1，当引用计数为0的时候，该Purgeable memory对象可以被系统回收|
|void \*OH_PurgeableMemory_GetContent(OH_PurgeableMemory \*purgObj)|获取PurgeableMemory对象内存数据|
|size_t OH_PurgeableMemory_ContentSize(OH_PurgeableMemory \*purgObj)|获取PurgeableMemory对象内存数据大小|
|bool OH_PurgeableMemory_AppendModify(OH_PurgeableMemory \*purgObj, OH_PurgeableMemory_ModifyFunc func, void *funcPara)|添加PurgeableMemory对象的修改方法| 



## 详细描述

## 函数说明


### OH_PurgeableMemory_Create()

```
OH_PurgeableMemory *OH_PurgeableMemory_Create(size_t size, OH_PurgeableMemory_ModifyFunc func, void *funcPara)
```

**描述：**

创建Purgeable Memory实例，每次调用都会产生一个新的Purgeable Memory实例。

\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| size | 参数是描述purgeable对象大小的变量，类型为size_t； | 
| func | 参数是一个指向创建函数OH_PurgeableMemory_ModifyFunc的指针，类型为sptr&lt;OH_PurgeableMemory_ModifyFunc&gt; |
| funcPara | 参数是指向创建函数参数func的指针，类型可自定义 | 

**返回：**

返回一个指针，指向OH_PurgeableMemory的结构体实例。

**起始版本：**

10


### OH_PurgeableMemory_Destroy()

  
```
bool OH_PurgeableMemory_Destroy(OH_PurgeableMemory *purgObj)
```

**描述：**

将Purgeable memory对象会被析构掉。

\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| purgObj | 参数是一个指向待访问的PurgeableMemory对象的指针，类型为sptr&lt;OH_PurgeableMemory&gt; | 

**返回：**

 如果PurgeableMemory内存数据准备好则返回true；如果PurgeableMemory内存数据已被回收且重建失败则返回false。

**起始版本：**

10


### OH_PurgeableMemory_BeginRead()

  
```
bool OH_PurgeableMemory_BeginRead(OH_PurgeableMemory *purgObj)
```

**描述：**

开始读取PurgeableMemory对象。检查PurgeableMemory是否被回收，若被回收则调用重建方法进行重建。

\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| purgObj | 参数是一个指向待访问的PurgeableMemory对象的指针，类型为sptr&lt;OH_PurgeableMemory&gt; | 

**返回**

 如果PurgeableMemory内存数据准备好则返回ture；如果PurgeableMemory内存数据已被回收且重建失败则返回false。

**起始版本：**

10


### OH_PurgeableMemory_EndRead()

  
```
void OH_PurgeableMemory_EndRead(OH_PurgeableMemory *purgObj)
```

**描述：**

结束读取PurgeableMemory对象。表示系统可回收该PurgeableMemory对象内存数据。

\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| purgObj | 参数是一个指向待访问的PurgeableMemory对象的指针，类型为sptr&lt;OH_PurgeableMemory&gt; | 

**起始版本：**

10


### OH_PurgeableMemory_BeginWrite()

  
```
bool OH_PurgeableMemory_BeginWrite(OH_PurgeableMemory *purgObj)
```

**描述：**

开始修改PurgeableMemory对象。检查PurgeableMemory是否被回收，若被回收则调用重建方法进行重建。

\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| purgObj | 参数是一个指向待访问的PurgeableMemory对象的指针，类型为sptr&lt;OH_PurgeableMemory&gt; |

**返回：**

 如果PurgeableMemory内存数据准备好则返回ture；如果PurgeableMemory内存数据已被回收且重建失败则返回false。

**起始版本：**

10


### OH_PurgeableMemory_EndWrite()

  
```
void OH_PurgeableMemory_EndWrite(OH_PurgeableMemory *purgObj)
```

**描述：**

结束修改PurgeableMemory对象。表示系统可回收该PurgeableMemory对象内存数据。

\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| purgObj | 参数是一个指向待访问的PurgeableMemory对象的指针，类型为sptr&lt;OH_PurgeableMemory&gt; | 

**起始版本：**

10


### OH_PurgeableMemory_GetContent()

  
```
void *OH_PurgeableMemory_GetContent(OH_PurgeableMemory *purgObj)
```

**描述：**

获取PurgeableMemory对象内存数据

\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| purgObj | 参数是一个指向待访问的PurgeableMemory对象的指针，类型为sptr&lt;OH_PurgeableMemory&gt; | 

**返回：**

返回PurgeableMemory对象内存地址。

**起始版本：**

10


### OH_PurgeableMemory_ContentSize()

  
```
size_t OH_PurgeableMemory_ContentSize(OH_PurgeableMemory *purgObj)
```

**描述：**

获取PurgeableMemory对象内存数据大小。

\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| purgObj | 参数是一个指向待访问的PurgeableMemory对象的指针，类型为sptr&lt;OH_PurgeableMemory&gt; | 

**返回：**

返回PurgeableMemory对象内存数据大小，类型为size_t。

**起始版本：**

10


### OH_PurgeableMemory_AppendModify()

  
```
bool OH_PurgeableMemory_AppendModify(OH_PurgeableMemory *purgObj, OH_PurgeableMemory_ModifyFunc func, void *funcPara)
```

**描述：**

添加PurgeableMemory对象的修改方法,保证重建的数据是最新的数据。

\@syscap SystemCapability.CommonLibrary.Memory.PurgeableMemory

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| size | 参数是描述purgeable对象大小的变量，类型为size_t； | 
| func | 参数是一个指向创建函数OH_PurgeableMemory_ModifyFunc的指针，类型为sptr&lt;OH_PurgeableMemory_ModifyFunc&gt; |
| funcPara | 参数是指向创建函数参数func的指针，类型可自定义 | 

**返回：**

设置成功返回true,否则返回false。

**起始版本：**

10