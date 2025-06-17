# Class (MediaSourceInfo)

表示媒体源的信息。

> **说明：**
>
> - 本模块接口从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## 属性

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
| type<sup>12+</sup> | [SourceType](./arkts-apis-webview-e.md#sourcetype12) | 是 | 媒体源的类型。 |
| source<sup>12+</sup> | string | 是 | 媒体源地址。 |
| format<sup>12+</sup> | string | 是 | 媒体源格式， 可能为空， 需要使用者自己去判断格式。 |
