# oh_cursor.h


## 概述

提供通过查询数据库生成的数据库结果集的访问方法。

结果集是指用户调用关系型数据库查询接口之后返回的结果集合，提供了多种灵活的数据访问方式，以便用户获取各项数据。

**引用文件：** <database/rdb/oh_cursor.h>

**库：** libnative_rdb_ndk.z.so

**起始版本：** 10

**相关模块：**[RDB](_r_d_b.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_Cursor](_o_h___cursor.md) | 表示结果集。  |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef struct [OH_Cursor](_o_h___cursor.md) [OH_Cursor](_r_d_b.md#oh_cursor) | 表示结果集。 | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int [OH_Cursor_GetFloatVectorCount](_r_d_b.md#oh_cursor_getfloatvectorcount) ([OH_Cursor](_o_h___cursor.md) \*cursor, int32_t columnIndex, size_t \*length) | 获取当前行中指定列的浮点数数组大小。 | 
| int [OH_Cursor_GetFloatVector](_r_d_b.md#oh_cursor_getfloatvector) ([OH_Cursor](_o_h___cursor.md) \*cursor, int32_t columnIndex, float \*val, size_t inLen, size_t \*outLen) | 以浮点数数组的形式获取当前行中指定列的值。 | 
