# NodeAdapter错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 106104 适配器未绑定

**错误信息**

A listener is required to add the NodeAdapter.

**错误描述**

NodeAdapter需要添加监听器。

**可能原因**

NodeAdapter未绑定DataChangeListener。

**处理步骤**

NodeAdapter设置listener。

## 106105 适配器已存在

**错误信息**

The NodeAdapter already exists.

**错误描述**

NodeAdapter已经存在。

**可能原因**

NodeAdapter已经存在，不支持添加删除子节点。

**处理步骤**

移除NodeAdapter，或放弃在此处添加删除子节点。

## 106106 子节点已存在

**错误信息**

This component already has a child node.

**错误描述**

组件已经有子节点

**可能原因**

组件已经有子节点，不支持设置NodeAdapter。

**处理步骤**

移除子节点，或放弃在此处设置NodeAdapter。

## 106107 参数下标越界

**错误信息**

This param index is out of range.

**错误描述**

组件事件中index参数超过数组长度限制。

**可能原因**

传入的index参数超出传入的数组长度限制。

**处理步骤**

检查index参数是否超出传入的数组长度限制。

## 106108 数据不存在

**错误信息**

The data does not exist.

**错误描述**

组件事件中不存在该数据。

**可能原因**

试图查找事件中不包含的数据。

**处理步骤**

确认当前事件是否存在想要查询的数据。

## 106109 不支持返回值

**错误信息**

The event has not return value.

**错误描述**

组件事件不支持返回值。

**可能原因**

试图获取事件返回值。

**处理步骤**

确认当前事件是否存在返回值。