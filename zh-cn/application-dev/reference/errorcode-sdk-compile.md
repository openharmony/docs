# SDK编译校验错误码
<!--Kit: Common-->
<!--Subsystem: Common-->
<!--Owner: @fang-jinxu-->
<!--Designer: @majiajun518-->
<!--Tester: @RayShih-->
<!--Adviser: @fang-jinxu-->

## 11706006 接口不支持卡片工程 

**错误信息**

XXX can't support form application.

**错误描述**

接口不支持在卡片工程中使用。

**可能原因**

该接口不支持卡片能力。

**处理步骤**

更换方案，调用其他接口。

## 11706007 接口不支持跨平台使用

**错误信息**

XXX can't support crossplatform application.

**错误描述**

接口不支持跨平台使用。

**可能原因**

该接口暂不支持跨平台能力。

**处理步骤**

更换方案，调用其他接口。

## 11706008 FA模型接口在Stage工程中使用

**错误信息**

This API is used only in FA Mode, but the current Mode is Stage.

**错误描述**

当前为Stage工程，但使用的接口为FA模型接口。

**可能原因**

错误的使用当前工程不支持的模型接口。

**处理步骤**

更换为Stage工程支持的接口。

## 11706009 Stage模型接口在FA工程中使用

**错误信息**

This API is used only in Stage Mode, but the current Mode is FA.

**错误描述**

当前为FA工程，但使用的接口为Stage工程接口。

**可能原因**

错误的使用当前工程不支持的模型接口。

**处理步骤**

更换为FA模型支持的接口。

## 11706010 接口不支持在原子化服务中使用

**错误信息**

XXX can't support atomicservice application.

**错误描述**

接口不支持在原子化服务中使用。

**可能原因**

该接口暂不支持原子化服务能力。

**处理步骤**

更换方案，调用其他接口。


<!--RP1--><!--RP1End-->