# zlib子系统错误码

## 401 参数检查错误

**错误信息**

The parameter invalid.

**错误描述**

当调用zlib的compress及decompress接口时，若传入参数的类型或者范围不匹配，会报此错误码。

**可能原因**

1. 入参类型错误不匹配，如传入的文件路径类型不是strinf。
2. 入参范围不匹配，如传入的options中包含的枚举不存在。

**处理步骤**

检查入参类型和范围是否匹配。

## 900001 传入的源文件错误

**错误信息**

The input source file is invalid.

**错误描述**

当调用compress或decompress接口时，传入源文件无效。

**可能原因**

当调用compress接口时，传入的待压缩的文件不存在；当调用decompress接口时，传入的待解压缩的文件不存在。

**处理步骤**

检查源文件是否存在。

## 900002 传入的目标文件错误

**错误信息**

The input destination file is invalid.

**错误描述**

当调用compress或decompress接口时，传入目标文件无效。

**可能原因**

1. 当调用compress接口时，传入的目标文件路径无效，如不存在的沙箱路径。
2. 当调用decompress接口时，传入的目标目录不存在。

**处理步骤**

1. 检查目标文件路径是否正确，不正确填写正确的沙箱路径。
2. 检查目标文件目录是否存在，不存在新建这个路径。