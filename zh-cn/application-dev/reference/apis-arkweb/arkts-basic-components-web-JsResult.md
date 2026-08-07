# Class (JsResult)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

JsResult是Web组件在处理JavaScript弹窗事件时返回的结果处理对象，适用于开发者拦截并自定义处理`window.alert`、`window.confirm`、`window.prompt`等弹窗场景。开发者可在[onAlert](./arkts-basic-components-web-events.md#onalert)、[onConfirm](./arkts-basic-components-web-events.md#onconfirm)或[onPrompt](./arkts-basic-components-web-events.md#onprompt9)等事件回调中，通过该对象向Web组件反馈用户的确认、取消或输入内容等操作结果，从而控制弹窗的后续行为。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 8开始支持。
>
> - 示例效果请以真机运行为准。

## constructor

constructor()

JsResult的构造函数。用于处理JavaScript弹窗事件。

**系统能力：** SystemCapability.Web.Webview.Core

## handleCancel

handleCancel(): void

通知Web组件用户取消弹窗操作。

**系统能力：** SystemCapability.Web.Webview.Core

## handleConfirm

handleConfirm(): void

通知Web组件用户确认弹窗操作。

**系统能力：** SystemCapability.Web.Webview.Core

## handlePromptConfirm<sup>9+</sup>

handlePromptConfirm(result: string): void

通知Web组件用户确认弹窗操作并传递对话框内容。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明        |
| ------ | ------ | ---- | ----------- |
| result | string | 是    | 用户输入的对话框内容。 |