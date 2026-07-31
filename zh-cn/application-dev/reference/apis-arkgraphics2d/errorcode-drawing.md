# 图形绘制与显示错误码
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

图形绘制与显示错误码定义了图形2D绘制过程中的异常情况，包括参数校验、文件操作等方面的错误标识。开发者可通过这些错误码快速定位和排查绘制相关的问题，提高开发调试效率。适用于使用ArkGraphics 2D进行图形绘制的场景。

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 25900001 参数值异常

**错误信息**

Parameter error. Possible causes: Incorrect parameter range.

**错误描述**

当参数值超出参数范围要求时，系统会报此错误码。

**可能原因**

参数值超出接口调用范围会报错，如枚举值超出定义范围。

**处理步骤**

在定义接口参数前，确保参数值符合接口参数要求。

## 25900002 文件未找到

**错误信息**

File not found. The specified file does not exist or the path is incorrect.

**错误描述**

文件未找到。指定的文件不存在或者路径不正确。

**可能原因**

1. 文件路径错误或文件并不存在。
2. 文件路径大小写不匹配。

**处理步骤**

1. 检查文件路径格式是否正确，确认文件存在于指定位置。
2. 核对文件路径与实际文件名的大小写是否完全一致。

## 25900003 打开文件失败

**错误信息**

Failed to open file. The file cannot be opened due to permission or I/O issues.

**错误描述**

打开文件失败。由于权限或I/O问题，无法打开文件。

**可能原因**

1. 没有文件读取权限。
2. 文件被其他进程占用锁定。

**处理步骤**

1. 验证文件权限设置，确认当前用户对文件具有读取权限。
2. 确保文件未被其他进程占用。

## 25900004 文件定位失败

**错误信息**

File seek failed. The system failed to reposition the file read pointer.

**错误描述**

文件定位失败。系统无法重新定位文件读取指针。

**可能原因**

文件类型不支持随机访问（如pipe、socket）。

**处理步骤**

确保文件类型支持随机访问。

## 25900005 获取文件大小失败

**错误信息**

Failed to get the file size. The system was unable to obtain the file size information.

**错误描述**

获取文件大小失败。系统无法获取文件大小信息。

**可能原因**

文件类型不支持获取大小（如pipe、socket）。

**处理步骤**

确保文件类型支持大小查询。

## 25900006 读取文件失败

**错误信息**

Failed to read file. The file could not be read completely or contains unreadable data.

**错误描述**

读取文件失败，文件无法完整读取或包含不可读数据。

**可能原因**

1. 文件I/O错误。
2. 内存不足导致读取失败。

**处理步骤**

1. 确保磁盘或存储设备正常。
2. 确保有足够内存进行读取。

## 25900007 文件为空

**错误信息**

Empty file. The specified file is empty.

**错误描述**

指定文件为空。

**可能原因**

文件大小为0字节。

**处理步骤**

检查文件大小属性，确认文件内容不为空（大小大于0字节）。

## 25900008 文件损坏

**错误信息**

Corrupted file. The file content is invalid, damaged, or an index out of bounds occurs when accessing TTC/OTC files, making it impossible to parse.

**错误描述**

文件损坏。文件内容无效、损坏或者访问TTC/OTC文件时index越界，无法解析。

**可能原因**

1. 文件格式不正确。
2. 文件内容损坏。
3. TTC/OTC文件超出索引。

**处理步骤**

1. 确保文件格式符合预期。
2. 确保文件内容正常。
3. 确保index在TTC/OTC支持范围内。