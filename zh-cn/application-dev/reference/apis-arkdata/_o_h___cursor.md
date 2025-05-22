# OH_Cursor


## 概述

表示结果集。

提供通过查询数据库生成的数据库结果集的访问方法。

**起始版本：** 10

**相关模块：**[RDB](_r_d_b.md)

**所在头文件：**[oh_cursor.h](oh__cursor_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [id](_r_d_b.md#id-15)                                       | OH_Cursor结构体的唯一标识符。                                |
| [getColumnCount](_r_d_b.md#getcolumncount) | 函数指针，获取结果集中的列数。  |
| [getColumnType](_r_d_b.md#getcolumntype) | 函数指针，根据指定的列索引获取列类型。  |
| [getColumnIndex](_r_d_b.md#getcolumnindex) | 函数指针，根据指定的列名获取列索引。  |
| [getColumnName](_r_d_b.md#getcolumnname) | 函数指针，根据指定的列索引获取列名。  |
| [getRowCount](_r_d_b.md#getrowcount) | 函数指针，获取结果集中的行数。  |
| [goToNextRow](_r_d_b.md#gotonextrow) | 函数指针，转到结果集的下一行。  |
| [getSize](_r_d_b.md#getsize) | 函数指针，当结果集中列的数据类型是BLOB或者TEXT时，获取其值所需的内存。  |
| [getText](_r_d_b.md#gettext) | 函数指针，以字符串形式获取当前行中指定列的值。  |
| [getInt64](_r_d_b.md#getint64) | 函数指针，以int64_t形式获取当前行中指定列的值。  |
| [getReal](_r_d_b.md#getreal) | 函数指针，以double形式获取当前行中指定列的值。  |
| [getBlob](_r_d_b.md#getblob) | 函数指针，以字节数组的形式获取当前行中指定列的值。  |
| [isNull](_r_d_b.md#isnull-12) | 函数指针，检查当前行中指定列的值是否为null。  |
| [destroy](_r_d_b.md#destroy-14) | 函数指针，关闭结果集。  |
| [getAsset](_r_d_b.md#getasset) | 函数指针，以资产的形式获取当前行中指定列的值。  |
| [getAssets](_r_d_b.md#getassets) | 函数指针，以资产数组的形式获取当前行中指定列的值。  |
