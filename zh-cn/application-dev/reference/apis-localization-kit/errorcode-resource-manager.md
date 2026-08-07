# 资源管理错误码

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 9001001 无效的资源ID

**错误信息**

Invalid resource ID.

**错误描述**

无效的资源ID。

**可能原因**

1. 传入的资源ID为无效值，如`-1`。
2. 传入的资源ID在当前HAP/HSP包中不存在。

**处理步骤**

1. 排查是否为以下场景：HAR模块开启[混淆配置](../../quick-start/har-package.md#混淆配置)、中间码HAR、字节码HAR、跨HAP/HSP包。这四种场景下通过`$r('app.xxx.xxx').id`获取的资源ID为`-1`，推荐使用[getStringByName()](js-apis-resource-manager.md#getstringbyname9)等方法通过名称获取资源。
2. 检查传入的资源ID在HAP/HSP包中是否存在。可以参考[restool工具](../../tools/restool.md)的dump命令，先输出HAP/HSP的资源信息，然后在输出结果中搜索是否存在传入的资源ID。

## 9001002 根据当前资源ID未找到匹配的资源

**错误信息**

No matching resource is found based on the resource ID.

**错误描述**

根据当前资源ID未找到匹配的资源。

**可能原因**

1. 传入资源ID有误。
2. 传入的资源ID对应的资源类型与当前调用的接口不匹配。比如想要获取string资源，调用的接口为getStringSync，而传入的资源ID为`$r('app.integer.xxx').id`，两者类型不匹配。
3. 资源引用解析失败，当前资源引用了一个不存在的资源。

**处理步骤**

1. 检查传入的资源ID是否符合预期。
2. 检查传入的资源ID对应的资源类型与调用的接口类型是否匹配。
3. 检查传入的资源ID所对应的资源是否引用了不存在的资源。

## 9001003 无效的资源名称

**错误信息**

Invalid resource name.

**错误描述**

无效的资源名称。

**可能原因**

传入的资源名称在当前HAP/HSP包中不存在。

**处理步骤**

检查传入的资源名称在HAP/HSP包中是否存在。可以参考[restool工具](../../tools/restool.md)的dump命令，先输出HAP/HSP的资源信息，然后在输出结果中搜索是否存在传入的资源名称。

## 9001004 根据当前资源名称未找到匹配的资源

**错误信息**

No matching resource is found based on the resource name.

**错误描述**

根据当前资源名称未找到匹配的资源。

**可能原因**

1. 传入的资源名称有误。
2. 传入的资源名称对应的资源类型与当前调用的接口不匹配。比如想要获取string资源，调用的接口为getStringByName，而传入的资源名称为integer类型资源的名称，两者类型不匹配。
3. 资源引用解析失败，当前资源引用了一个不存在的资源。

**处理步骤**

1. 检查传入的资源名称是否符合预期。
2. 检查传入的资源名称对应的资源类型与调用的接口类型是否匹配。
3. 检查传入的资源名称所对应的资源是否引用了不存在的资源。

## 9001005 无效的相对路径

**错误信息**

Invalid relative path.

**错误描述**

无效的相对路径。

**可能原因**

传入的rawfile相对路径有误，与rawfile资源的实际相对路径不一致。

**处理步骤**

检查传入的rawfile相对路径是否符合预期。

## 9001006 资源存在循环引用

**错误信息**

The resource is referenced cyclically.

**错误描述**

资源存在循环引用。

**可能原因**

资源存在循环引用，导致解析引用次数超过20次。

**处理步骤**

检查使用`$string:xxx`、`$integer:xxx`等方式引用其他资源时是否存在循环引用的情况。

## 9001007 根据当前ID获取的资源格式化失败

**错误信息**

Failed to format the resource obtained based on the resource ID.

**错误描述**

根据当前ID获取的资源格式化失败。

**可能原因**

1. 格式化参数的类型不在支持范围内。
2. 格式化参数的数量与占位符数量不一致。
3. 格式化参数的类型与占位符类型不匹配。

**处理步骤**

1. 检查格式化参数的类型是否在支持的范围内。
2. 检查格式化参数的数量与占位符的数量是否一致。
3. 检查格式化参数的类型与占位符的类型是否一致。

## 9001008 根据当前名称获取的资源格式化失败

**错误信息**

Failed to format the resource obtained based on the resource name.

**错误描述**

根据当前名称获取的资源格式化失败。

**可能原因**

1. 格式化参数的类型不在支持范围内。
2. 格式化参数的数量与占位符数量不一致。
3. 格式化参数的类型与占位符类型不匹配。

**处理步骤**

1. 检查格式化参数的类型是否在支持的范围内。
2. 检查格式化参数的数量与占位符的数量是否一致。
3. 检查格式化参数的类型与占位符的类型是否一致。

## 9001009 获取系统资源管理对象失败

**错误信息**

Failed to access the system resource.

**错误描述**

获取系统资源管理对象失败。

**可能原因**

系统资源没有加载到应用进程的沙箱路径。

**处理步骤**

检查应用进程的[应用沙箱目录](../../../application-dev/file-management/app-sandbox-directory.md)下是否包含系统资源。

## 9001010 无效的overlay路径

**错误信息**

Invalid overlay path.

**错误描述**

无效的overlay路径。

**可能原因**

1. 传入的overlay路径不存在。
2. 传入的overlay路径当前应用无访问权限。比如该路径不在当前应用的安装路径或者其他可访问的路径下。

**处理步骤**

1. 检查overlay路径是否正确。
2. 检查应用进程的[应用沙箱目录](../../../application-dev/file-management/app-sandbox-directory.md)下是否包含传入的overlay路径。