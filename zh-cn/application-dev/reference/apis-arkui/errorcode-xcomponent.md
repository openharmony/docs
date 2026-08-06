# XComponent组件错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)。

## 103501 XComponent无效状态

**错误信息**

当前XComponent处于无效状态，方法调用失败。

**错误描述**

当前XComponent处于无效状态，方法调用失败。

**可能原因**

调用XComponent相关方法时，XComponent尚未完成初始化或持有的Surface已被销毁或释放，导致当前处于无效状态。

**处理步骤**

1. 确认XComponent已完成加载并初始化完成后再调用相关方法。
2. 检查XComponent持有的Surface是否已被销毁或释放，若已失效请重新创建XComponent实例后再调用。
