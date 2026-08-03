# 注册节点渲染状态监听错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fangzhiyuan1-->
<!--Designer: @fangzhiyuan1-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)。

## 161001 监听渲染状态的节点数超过限制

**错误信息**

The count of nodes monitoring render state is over the limitation.

**错误描述**

监听渲染状态的节点数超过限制。

**可能原因**

调用[on('nodeRenderState')](arkts-apis-uicontext-uiobserver.md#onnoderenderstate20)接口注册节点渲染状态监听时，单个UI实例中注册的监听节点数超过限制。

**处理步骤**

请确保单个UI实例中注册监听渲染状态的节点不超过64个。
