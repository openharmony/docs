# Class (SslErrorHandler)

Web组件返回的SSL错误通知事件用户处理功能对象。示例代码参考[onSslErrorEventReceive事件](./arkts-basic-components-web-events.md#onsslerroreventreceive9)。

> **说明：**
>
> - 本模块接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## constructor<sup>9+</sup>

constructor()

SslErrorHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## handleCancel<sup>9+</sup>

handleCancel(): void

通知Web组件取消此请求。

**系统能力：** SystemCapability.Web.Webview.Core

## handleConfirm<sup>9+</sup>

handleConfirm(): void

通知Web组件继续使用SSL证书。

**系统能力：** SystemCapability.Web.Webview.Core