# Class (WebKeyboardController)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

控制自定义键盘的输入、删除、关闭等操作。示例代码参考[onInterceptKeyboardAttach](./arkts-basic-components-web-events.md#oninterceptkeyboardattach12)。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## constructor<sup>12+</sup>

constructor()

WebKeyboardController的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## insertText<sup>12+</sup>

insertText(text: string): void

Web输入框中插入字符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | -------- | ---- | --------------------- |
| text | string | 是 | 向Web输入框插入字符。 |

## deleteForward<sup>12+</sup>

deleteForward(length: number): void

从后往前删除Web输入框中指定长度的字符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                                                                   |
| ------ | -------- | ---- |------------------------------------------------------------------------------------------------------|
| length | number   | 是   | 从后往前删除Web输入框中指定长度的字符。<br>取值范围：[-2147483648 , 2147483647]，当参数值大于字符长度时，默认删除光标前面所有字符；参数值为负数时，不执行删除操作。 |

## deleteBackward<sup>12+</sup>

deleteBackward(length: number): void

从前往后删除Web输入框中指定长度的字符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | -------- | ---- | ------------------------ |
| length | number   | 是   | 从前往后删除Web输入框中指定长度的字符。<br>取值范围：[-2147483648 , 2147483647]，当参数值大于字符长度时，默认删除光标后面所有字符；参数值为负数时，不执行删除操作。 |

## sendFunctionKey<sup>12+</sup>

sendFunctionKey(key: number): void

插入功能按键，目前仅支持Enter键类型，取值见[EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                   |
| ------ | -------- | ---- | ------------------------------------------ |
| key    | number   | 是   | 向Web输入框传递功能键，目前仅支持Enter键。 |

## close<sup>12+</sup>

close(): void

关闭自定义键盘。

**系统能力：** SystemCapability.Web.Webview.Core