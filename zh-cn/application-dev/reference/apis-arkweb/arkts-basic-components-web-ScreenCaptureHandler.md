# Class (ScreenCaptureHandler)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @qq_42700029-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Web组件返回授权或拒绝屏幕捕获功能的对象。示例代码参考[onScreenCaptureRequest事件](./arkts-basic-components-web-events.md#onscreencapturerequest10)。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 10开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## constructor<sup>10+</sup>

constructor()

ScreenCaptureHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## deny<sup>10+</sup>

deny(): void

拒绝网页所请求的屏幕捕获操作。

**系统能力：** SystemCapability.Web.Webview.Core

## getOrigin<sup>10+</sup>

getOrigin(): string

获取网页来源。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 当前请求权限网页的来源。 |

## grant<sup>10+</sup>

grant(config: ScreenCaptureConfig): void

对网页访问的屏幕捕获操作进行授权。

> **说明：**
>
> 需要配置权限：ohos.permission.MICROPHONE。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型                                     | 必填   | 说明    |
| ------ | ---------------------------------------- | ---- | ------- |
| config | [ScreenCaptureConfig](./arkts-basic-components-web-ScreenCaptureHandler.md) | 是   | 屏幕捕获配置。 |