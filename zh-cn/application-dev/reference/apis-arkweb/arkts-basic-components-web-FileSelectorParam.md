# Class (FileSelectorParam)

Web组件获取文件对象。示例代码参考[onShowFileSelector事件](./arkts-basic-components-web-events.md#onshowfileselector9)。

> **说明：**
>
> - 本模块接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## constructor<sup>9+</sup>

constructor()

FileSelectorParam的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## getTitle<sup>9+</sup>

getTitle(): string

获取文件选择器标题。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回文件选择器标题。 |

## getMode<sup>9+</sup>

getMode(): FileSelectorMode

获取文件选择器的模式。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明          |
| ---------------------------------------- | ----------- |
| [FileSelectorMode](./arkts-basic-components-web-e.md#fileselectormode9) | 返回文件选择器的模式。 |

## getAcceptType<sup>9+</sup>

getAcceptType(): Array\<string\>

获取文件过滤类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<string\> | 返回文件过滤类型。 |

## isCapture<sup>9+</sup>

isCapture(): boolean

获取是否调用多媒体能力。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明           |
| ------- | ------------ |
| boolean | 返回是否调用多媒体能力。<br>true表示返回调用多媒体能力，false表示返回未调用多媒体能力。 |

## getMimeTypes<sup>18+</sup>

getMimeTypes(): Array\<string\>

获取文件MIME类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<string\> | 返回文件MIME类型。 |