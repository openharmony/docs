# 维测日志错误码

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @BruceZong-->
<!--Designer: @gcw_qzKyUhyU-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 21300001 指定文件不存在

**错误信息**

The specified file does not exist.

**错误描述**

在调用拷贝、移动、删除接口进行文件操作时，指定类型日志中不存在指定文件名的文件。

**可能原因**

1.文件名称传递错误。
2.传入的文件名在物理设备上不存在。

**处理步骤**

检查传入的文件名称是否正确。
