# 焦点错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 150001 节点无法获得焦点

**错误信息**

This component is not focusable.

**错误描述**

当前节点无法获得焦点。

**可能原因**

节点默认无法获焦、开发者通过focusable等属性方法设置节点无法获焦等。

**处理步骤**

NA

## 150002 祖先节点无法获得焦点

**错误信息**

This component has an unfocusable ancestor.

**错误描述**

当前节点对应的祖先节点中存在无法获焦节点。

**可能原因**

祖先节点默认无法获焦、开发者通过focusable等属性方法设置祖先节点无法获焦等。

**处理步骤**

NA

## 150003 节点不存在

**错误信息**

The component doesn't exist, is currently invisible, or has been disabled.

**错误描述**

传入的id指向不存在、未挂树或者不可见节点。

**可能原因**

传入id错误、节点已经被销毁等。

**处理步骤**

NA
