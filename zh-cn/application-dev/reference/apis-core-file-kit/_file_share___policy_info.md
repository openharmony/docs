# FileShare_PolicyInfo


## 概述

需要授予或使能权限URI的策略信息。

**起始版本：** 12

**相关模块：**[FileShare](file_share.md)

**所在头文件：** [oh_file_share.h](oh__file__share_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \* [uri](#uri) | 需要授予或使能权限的URI。 | 
| unsigned int [length](#length) | URI的字节长度。 | 
| unsigned int [operationMode](#operationmode) | 授予或使能权限的URI访问模式。 | 


## 结构体成员变量说明


### length

```
unsigned int FileShare_PolicyInfo::length
```

**描述**

URI的字节长度。


### operationMode

```
unsigned int FileShare_PolicyInfo::operationMode
```

**描述**

授予或使能权限的URI访问模式。

示例：

- FileShare_OperationMode.READ_MODE

- FileShare_OperationMode.WRITE_MODE

- FileShare_OperationMode.READ_MODE | FileShare_OperationMode.WRITE_MODE


### uri

```
char* FileShare_PolicyInfo::uri
```

**描述**

需要授予或使能权限的URI。
