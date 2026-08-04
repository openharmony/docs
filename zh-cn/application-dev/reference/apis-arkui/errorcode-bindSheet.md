# 半模态错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 120001 内容节点对应半模态页面错误

**错误信息**

The bindSheetContent is incorrect.

**错误描述**

输入的bindSheetContent错误，请确保bindSheetContent为有效的内容节点定义（取值原则见对应API文档中bindSheetContent参数说明），系统会产生此错误码。

**可能原因**

bindSheetContent为空或类型不符合要求。

**处理步骤**

1. 检查输入的bindSheetContent是否正确。
2. 确保传入的内容节点为有效的Builder或CustomBuilder实例。
3. 确保内容节点已正确注册和构建。

## 120002 内容节点对应半模态页面已存在

**错误信息**

The bindSheetContent already exists.

**错误描述**

调用bindSheet等半模态相关接口时，若内容节点对应的半模态页面已存在，该接口将返回此错误码。

**可能原因**

内容节点对应的半模态页面当前已显示，此时若重复打开，会报此错误码。

**处理步骤**

若需重新打开同一bindSheetContent对应的半模态页面，请先关闭已打开的半模态页面，再重新打开。

## 120003 无法找到内容节点对应的半模态页面

**错误信息**

The bindSheetContent cannot be found.

**错误描述**

内容节点对应的半模态页面未被打开。

**可能原因**

内容节点对应的半模态页面当前未显示，此时若调用接口来关闭或更新半模态页面，会报此错误码。必须先打开半模态页面后，才能调用关闭或更新接口。

**处理步骤**

请确保内容节点对应的半模态页面已处于打开状态后再调用关闭或更新接口；并检查输入的bindSheetContent是否存在，是否已被正确注册。

## 120004 指定的targetId不存在

**错误信息**

The targetId does not exist.

**错误描述**

targetId应为非负数的有效节点标识符，且其对应节点须处于有效生命周期内。当无法通过targetId查找到对应的节点时，方法将返回该错误码。

**可能原因**

targetId是无效的（取值原则：必须为非负整数），或者其对应的节点已销毁。

**处理步骤**

1. 检查targetId是否为非负数，若为负数请使用有效的targetId组件标识。
2. 检查targetId对应的节点是否有效，若节点已销毁请重新创建或更换其他有效节点。建议结合组件生命周期回调（如onAppear/onDisappear）确认节点未销毁后再使用targetId调用半模态相关接口。

## 120005 指定的targetId对应的节点未挂载在组件树上

**错误信息**

The node of targetId is not in the component tree.

**错误描述**

当将半模态页面指定为EMBEDDED模式时，指定的targetId对应的节点未挂载在组件树上，方法将返回该错误码。

**可能原因**

当将半模态页面指定为EMBEDDED模式时，指定的targetId对应的节点未挂载在组件树上。

**处理步骤**

等待targetId对应的节点挂载上树后，再调用方法；或者将SheetMode设置为OVERLAY模式。EMBEDDED模式要求targetId对应节点已挂载在节点树上且为page或NavDestination节点的子节点；OVERLAY模式无此限制。

## 120006 指定的targetId对应的节点并不是page节点或NavDestination节点的子节点

**错误信息**

The node of targetId is not a child of the page node or NavDestination node.

**错误描述**

当将半模态页面指定为EMBEDDED模式时，若指定的targetId对应的节点并不是page节点或NavDestination节点的子节点，方法将返回该错误码。

**可能原因**

当将半模态页面指定为EMBEDDED模式（即半模态页面嵌入在父组件布局中显示，需要从父节点向上查找page或NavDestination节点）时，无法从targetId对应节点向上查找到page节点或NavDestination节点。

**处理步骤**

更换一个可查找到page节点或NavDestination节点的targetId；或者将半模态页面指定为OVERLAY模式。
