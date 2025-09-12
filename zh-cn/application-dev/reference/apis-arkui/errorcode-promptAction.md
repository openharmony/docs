# 弹窗错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyi0309-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 100001 内部错误

**错误信息**

Internal error.

**错误描述**

当出现了开发者无法解决的内部异常错误时，会报此错误码，并具体描述内部错误类型。

**可能原因**

未成功获取渲染引擎，解析参数失败等。

**处理步骤**

NA

## 103301 自定义弹窗内容节点错误

**错误信息**

The ComponentContent is incorrect.

> **说明：**
>
> 当接口是[openCustomDialog](arkts-apis-uicontext-promptaction.md#opencustomdialog12)、[openCustomDialogWithController](arkts-apis-uicontext-promptaction.md#opencustomdialogwithcontroller18)、[closeCustomDialog](arkts-apis-uicontext-promptaction.md#closecustomdialog12)和[updateCustomDialog](arkts-apis-uicontext-promptaction.md#updatecustomdialog12)时，返回的错误信息为Dialog content error. The ComponentContent is incorrect.

**错误描述**

自定义弹窗内容节点错误，无法渲染显示。

**可能原因**

使用自定义弹窗时，若传入的自定义组件节点为空或其他错误，将无法正常渲染显示。

**处理步骤**

NA

## 103302 内容节点对应自定义弹窗已存在

**错误信息**

The ComponentContent already exists.

**错误描述**

内容节点对应的自定义弹窗当前已处于弹出打开状态。

**可能原因**

内容节点对应的自定义弹窗已弹出显示，此时若重复打开，会报此错误码。

**处理步骤**

NA

## 103303 无法找到内容节点对应的自定义弹窗

**错误信息**

The ComponentContent cannot be found.

> **说明：**
>
> 当接口是[closeCustomDialog](arkts-apis-uicontext-promptaction.md#closecustomdialog12)和[updateCustomDialog](arkts-apis-uicontext-promptaction.md#updatecustomdialog12)时，返回的错误信息为Dialog content not found. The ComponentContent cannot be found.

**错误描述**

内容节点对应的自定义弹窗当前未被弹出打开。

**可能原因**

内容节点对应的自定义弹窗未弹出显示，此时若调用关闭或更新自定义弹窗的接口，会报此错误码。

**处理步骤**

NA

## 103304 指定的targetId不存在

**错误信息**

The targetId does not exist.

**错误描述**

当无法通过targetId查找到对应的节点时，方法将返回该错误码。

**可能原因**

targetId无效，或者对应的节点已销毁。

**处理步骤**

NA

## 103305 指定的targetId对应的节点未挂载在节点树上

**错误信息**

The node of targetId is not in the component tree.

**错误描述**

指定的targetId对应的节点未挂载在节点树上时，方法将返回该错误码。

**可能原因**

指定的targetId对应的节点未挂载在节点树上。

**处理步骤**

NA

## 103401 无法找到对应的文本提示框

**错误信息**

Cannot find the toast. 

**错误描述**

对应的文本提示框未弹出或已关闭。

**可能原因**

当文本提示框未弹出或已经关闭时，调用关闭文本提示框接口会报此错误码。

**处理步骤**

NA
