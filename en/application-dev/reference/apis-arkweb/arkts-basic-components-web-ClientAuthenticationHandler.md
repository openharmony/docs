# Class (ClientAuthenticationHandler)

Implements a **ClientAuthenticationHandler** object returned by the **Web** component. For details about the sample code, see [onClientAuthenticationRequest](./arkts-basic-components-web-events.md#onclientauthenticationrequest9).

> **NOTE**
>
> - This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor<sup>9+</sup>

constructor()

Constructs a **ClientAuthenticationHandler**.

**System capability**: SystemCapability.Web.Webview.Core

## confirm<sup>9+</sup>

confirm(priKeyFile : string, certChainFile : string): void

Uses the specified private key and client certificate chain.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name          | Type  | Mandatory  | Description              |
| ------------- | ------ | ---- | ------------------ |
| priKeyFile    | string | Yes   | Full path for storing the private key file. |
| certChainFile | string | Yes   | Full path for storing the certificate chain file.|

## confirm<sup>10+</sup>

confirm(authUri : string): void

Instructs the **Web** component to use the specified credentials (obtained from the certificate management module).

> **NOTE**
>
> The **ohos.permission.ACCESS_CERT_MANAGER** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory  | Description   |
| ------- | ------ | ---- | ------- |
| authUri | string | Yes   | Key value of the credentials.|

## cancel<sup>9+</sup>

cancel(): void

Cancels the client certificate request sent by the same host and port server. No additional event will be reported for requests from the same host and port server.

**System capability**: SystemCapability.Web.Webview.Core

## ignore<sup>9+</sup>

ignore(): void

Ignores this request.

**System capability**: SystemCapability.Web.Webview.Core
