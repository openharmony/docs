# 拖拽事件错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 190001 数据未取得

**错误信息**

Data not found.

**错误描述**

当开发者调用DragEvent的GetData()接口时，若还未获取到数据，会抛出此错误码。

**可能原因**

DragEvent的数据暂未获取成功。

**处理步骤**

NA

## 190002 获取数据错误

**错误信息**

Data error.

**错误描述**

当开发者调用DragEvent的GetData()接口时，若取得的数据有错误，会抛出此错误码。

**可能原因**

数据获取错误。

**处理步骤**

NA

## 190003 当前阶段不允许操作

**错误信息**

Data error.

**错误描述**

当开发者在非onDrop阶段调用DragEvent的startDataLoading()接口时，系统会抛出此错误码。

**可能原因**

当前所处阶段错误。

**处理步骤**

NA

## 190004 操作失败

**错误信息**

操作失败。

**错误描述**

当前阶段所进行的操作失败时，会抛出此错误码。

**可能原因**

参数错误。

**处理步骤**

NA