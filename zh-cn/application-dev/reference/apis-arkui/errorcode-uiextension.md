# UIExtension错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 1011 扩展Ability启动失败

**错误信息**

Failed to start the UIExtension ability.

**错误描述**

扩展Ability启动失败，请检查扩展Ability的Want参数。

**可能原因**

1. Want参数配置错误；
2. type类型不一致，具体请参考EmbeddedComponent组件[接口](arkui-ts/ts-container-embedded-component.md#接口)；
3. 提供方应用未安装；

**处理步骤**

检查Want参数配置、应用是否安装等。

## 1012 扩展Ability切后台失败

**错误信息**

Failed to switch the UIExtension ability to the background.

**错误描述**

扩展Ability切后台失败。

**可能原因**

扩展Ability切后台失败，可能原因包括但不限于：

1. Ability生命周期状态异常；

2. 系统资源不足。若仍无法定位，需根据AMS（Ability Manager Service）日志具体分析。

**处理步骤**

根据AMS（Ability Manager Service）日志进行分析。

## 1013 扩展Ability销毁失败

**错误信息**

Failed to destroy the UIExtension ability.

**错误描述**

扩展Ability销毁失败。

**可能原因**

扩展Ability销毁失败，可能原因包括但不限于：

1. Ability生命周期回调执行异常；

2. 资源释放过程中发生错误。若仍无法定位，需根据AMS（Ability Manager Service）日志具体分析。

**处理步骤**

根据AMS（Ability Manager Service）日志进行分析。

## 100011 未注册同步回调

**错误信息**

No callback has been registered to respond to this request.

**错误描述**

扩展Ability未注册同步回调。

**可能原因**

组件使用方调用sendSync接口向被拉起的Ability发送数据前，扩展Ability未注册同步回调监听。

**处理步骤**

1. 在扩展Ability中注册同步回调监听；
2. 组件使用方需调用sendSync接口向被拉起的Ability发送数据。

## 100012 数据发送失败

**错误信息**

Transferring data failed.

**错误描述**

数据发送失败。

**可能原因**

数据发送失败，可能原因包括但不限于：

1. 发送的数据量超过限制；

2. 数据序列化失败；

3. 跨进程通信通道异常。若仍无法定位，需根据AMS（Ability Manager Service）日志具体分析。

**处理步骤**

根据AMS（Ability Manager Service）日志进行分析。

## 100013 禁止嵌套

**错误信息**

Cascading UIExtension components is not allowed.

**错误描述**

UIExtension组件不允许嵌套使用；在特定页面布局或组件复用等场景下可能意外出现UIExtension组件间嵌套，此时会触发此错误码。

**可能原因**

可能存在UIExtension组件间嵌套。

**处理步骤**

请确认UIExtension组件规格，避免在组件复用、条件渲染、动态加载等场景下产生意外嵌套。

## 100014 Ability退出异常

**错误信息**

The UIExtension ability exited unexpectedly.

**错误描述**

扩展Ability退出异常。

**可能原因**

扩展Ability退出异常，可能原因包括但不限于：

1. Ability生命周期回调执行异常导致非正常退出；

2. 资源释放过程中发生未捕获异常。若仍无法定位，需根据AMS（Ability Manager Service）日志具体分析。

**处理步骤**

根据AMS（Ability Manager Service）日志进行分析。

## 100015 生命周期超时

**错误信息**

The lifecycle of the UIExtension ability has timed out.

**错误描述**

扩展Ability生命周期超时。

**可能原因**

扩展Ability生命周期超时，可能原因包括但不限于：

1. 生命周期回调中执行了耗时操作导致超时；

2. 主线程阻塞导致生命周期回调无法及时执行。若仍无法定位，需根据AMS（Ability Manager Service）日志具体分析。

**处理步骤**

根据AMS（Ability Manager Service）日志进行分析。

## 100016 Key事件处理超时

**错误信息**

Key event processing by the UIExtension ability has timed out.

**错误描述**

扩展Ability处理Key事件超时。

**可能原因**

扩展Ability处理Key事件超时，可能原因包括但不限于：

1. Key事件处理回调中执行了耗时操作导致超时；

2. 主线程阻塞导致事件处理无法及时完成。若仍无法定位，需根据AMS（Ability Manager Service）日志具体分析。

**处理步骤**

根据AMS（Ability Manager Service）日志进行分析。

## 100018 扩展Ability启动失败

**错误信息**

Start ui extension ability failed, please check the want of UIextensionAbility.

**错误描述**

设置onTerminated回调场景下，扩展Ability启动失败，请检查扩展Ability的Want参数。

**可能原因**

1. Want参数配置错误；
2. type类型不一致，具体请参考EmbeddedComponent组件[接口](arkui-ts/ts-container-embedded-component.md#接口)；
3. 提供方应用未安装；
4. 设备类型不支持；

**处理步骤**

检查Want参数配置、应用是否安装、当前能力是否支持此设备类型等。

## 100019 扩展Ability切后台失败

**错误信息**

background ui extension ability failed, please check AMS log.

**错误描述**

设置onTerminated回调场景下，扩展Ability切后台失败。

**可能原因**

扩展Ability切后台失败，需根据AMS（Ability Manager Service）日志具体分析。

**处理步骤**

根据AMS（Ability Manager Service）日志进行分析。

## 100020 扩展Ability销毁失败（onTerminated场景）

**错误信息**

terminate ui extension ability failed, please check AMS log.

**错误描述**

设置onTerminated回调场景下，扩展Ability销毁失败。

**可能原因**

扩展Ability销毁失败，需根据AMS（Ability Manager Service）日志具体分析。

**处理步骤**

根据AMS（Ability Manager Service）日志进行分析。

## 100021 透明节点检测

**错误信息**

Transparent node is detected in the UIExtension ability.

**错误描述**

扩展Ability存在透明节点。

**可能原因**

检测到扩展Ability存在透明节点，可能导致事件分发阻塞。

**处理步骤**

移除透明节点，或调整组件透明度设置，避免阻塞事件。