# zlib子系统错误码

## 900001 传入的源文件错误

**错误信息**

The input source file is invalid.

**错误描述**

当调用compressFile或decompressFile接口时，传入源文件无效。

**可能原因**

当调用compressFile接口时，传入的待压缩的文件不存在；当调用decompressFile接口时，传入的待解压缩的文件不存在。

**处理步骤**

1. 检查源文件是否存在。
2. 检查待压缩的文件路径是否存在，并且路径是否在正确的沙箱路径下。

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