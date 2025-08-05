# Class (SslErrorHandler)

Implements an **SslErrorHandler** object to handle SSL error notification events returned by the **Web** component. For details about the sample code, see the [onSslErrorEvent](./arkts-basic-components-web-events.md#onsslerrorevent12) event.

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>9+</sup>

constructor()

Constructs a **SslErrorHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

## handleCancel<sup>9+</sup>

handleCancel(): void

Cancels this request.

**System capability**: SystemCapability.Web.Webview.Core

## handleConfirm<sup>9+</sup>

handleConfirm(): void

Continues using the SSL certificate.

**System capability**: SystemCapability.Web.Webview.Core

## handleCancel<sup>20+</sup>

handleCancel(abortLoading: boolean): void

Cancels this request and determines whether to stop loading based on the **abortLoading** parameter.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type| Mandatory | Description            |
| --------------- | -------- | ----  |------- |
| abortLoading    | boolean  | Yes   | Whether to stop loading the page after the request is canceled.<br>The value **true** means to stop loading the page, and **false** means to continue loading the page.<br>The default value is **false**.|
