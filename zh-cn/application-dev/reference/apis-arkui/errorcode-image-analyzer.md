# 图像AI分析错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 110001 AI分析功能不支持

**错误信息**

AI analysis is unsupported.

**错误描述**

当开发者调用startImageAnalyzer()接口时，若当前不支持AI分析功能，会抛出此错误码。

**可能原因**

调用不支持的功能接口。

**处理步骤**

NA

## 110002 AI分析正在进行中

**错误信息**

AI analysis is ongoing.

**错误描述**

当开发者调用startImageAnalyzer()接口时，若上一次的分析还没有结束，会抛出此错误码。

**可能原因**

调用接口时机错误

**处理步骤**

NA

## 110003 AI分析终止，分析内容销毁

**错误信息**

AI analysis is stopped.

**错误描述**

检测到画面变化或调用stopImageAnalyzer()接口，会抛出此错误码。

**可能原因**

调用stopImageAnalyzer()接口。

**处理步骤**

NA