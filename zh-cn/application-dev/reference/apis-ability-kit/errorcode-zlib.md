# zlib子系统错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](errorcode-universal.md)。

## 900001 传入的源文件错误

**错误信息**

The input source file is invalid.

**错误描述**

当调用compressFile或decompressFile接口时，传入源文件无效。

**可能原因**

当调用compressFile接口时，传入的待压缩的文件不存在；当调用decompressFile接口时，传入的待解压缩的文件不存在。

**处理步骤**

1. 检查源文件是否存在。
2. 检查源文件的后缀是否为.zip。
3. 检查待压缩的文件路径是否存在，并且路径是否在正确的沙箱路径下。

## 900002 传入的目标文件错误

**错误信息**

The input destination file is invalid.

**错误描述**

当调用compressFile或decompressFile接口时，传入目标文件无效。

**可能原因**

1. 当调用compressFile接口时，传入的目标文件路径无效，如不存在的沙箱路径。
2. 当调用decompressFile接口时，传入的目标目录不存在。

**处理步骤**

1. 检查目标文件路径是否正确，如果不正确，填写正确的沙箱路径。
2. 检查目标文件目录是否存在，如果不存在，新建这个路径。

## 900003 传入的源文件格式错误或者已损坏

**错误信息**

The input source file is not ZIP format or damaged.

**错误描述**

当调用decompressFile接口时，传入源文件的压缩格式有误或者已损坏。


**可能原因**

1. 当调用decompressFile接口时，传入的源文件压缩格式有误。
2. 当调用decompressFile接口时，传入的源文件不完整或已损坏。

**处理步骤**

1. 检查源文件压缩格式是否为ZIP格式。
2. 检查源文件是否完整，如果是网络下载的，需要确保文件下载完成后再调用decompress接口。