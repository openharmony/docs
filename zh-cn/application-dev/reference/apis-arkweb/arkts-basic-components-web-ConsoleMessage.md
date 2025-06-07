# Class (ConsoleMessage)

Web组件获取控制台信息对象。示例代码参考[onConsole事件](./arkts-basic-components-web-events.md#onconsole)。

> **说明：**
>
> - 本模块接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## constructor

constructor(message: string, sourceId: string, lineNumber: number, messageLevel: MessageLevel)

ConsoleMessage的构造函数。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[constructor](#constructor9)代替。

**系统能力：** SystemCapability.Web.Webview.Core

## constructor<sup>9+</sup>

constructor()

ConsoleMessage的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## getLineNumber

getLineNumber(): number

获取ConsoleMessage的行数。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 返回ConsoleMessage的行数。 |

## getMessage

getMessage(): string

获取ConsoleMessage的日志信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                     |
| ------ | ---------------------- |
| string | 返回ConsoleMessage的日志信息。 |

## getMessageLevel

getMessageLevel(): MessageLevel

获取ConsoleMessage的信息级别。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                | 说明                     |
| --------------------------------- | ---------------------- |
| [MessageLevel](./arkts-basic-components-web-e.md#messagelevel) | 返回ConsoleMessage的信息级别。 |

## getSourceId

getSourceId(): string

获取网页源文件路径和名字。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回网页源文件路径和名字。 |