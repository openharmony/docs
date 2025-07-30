# Functions

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Module to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## webview.once

once(type: string, callback: Callback\<void\>): void

Registers a one-time callback for web events of the specified type. Currently, only **webInited** is supported. This callback is triggered when the Web engine initialization is complete.

When the first **Web** component is loaded in an application, the web engine is initialized. When other **Web** components are loaded in the same application, **once()** is not triggered. When the first **Web** component is loaded after the last **Web** component is destroyed in the application, the web engine will be initialized again.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type             | Mandatory| Description                 |
| ------- | ---------------- | ---- | -------------------- |
| type     | string          | Yes  | Web event type. The value can be **"webInited"**, indicating completion of web initialization.     |
| callback | Callback\<void\> | Yes  | Callback to register.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                 |
| -------- | ----------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.   |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

webview.once("webInited", () => {
  console.log("configCookieSync");
  webview.WebCookieManager.configCookieSync("https://www.example.com", "a=b");
})

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
