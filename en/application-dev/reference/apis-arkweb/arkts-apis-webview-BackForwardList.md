# Interface (BackForwardList)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Defines the backforward list of the current WebView.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this interface are supported since API version 9.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Module to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## Attributes

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Type  | Read-Only| Optional| Description                                                        |
| ------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| currentIndex | number | No  | No  | Index of the current page in the backforward list.                                |
| size         | number | No  | No  | Number of indexes in the backforward list. A maximum of 50 indexes can be stored. If this limit is exceeded, the start records will be overwritten.|

## getItemAtIndex

getItemAtIndex(index: number): HistoryItem

Obtains information about a history item with a specified index in the backforward list.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| index  | number | Yes  | Index of the history item in the backforward list.|

**Returns**

| Type                       | Description        |
| --------------------------- | ------------ |
| [HistoryItem](./arkts-apis-webview-i.md#historyitem) | History item.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State icon: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Button('getBackForwardEntries')
        .onClick(() => {
          try {
            let list = this.controller.getBackForwardEntries();
            let historyItem = list.getItemAtIndex(list.currentIndex);
            console.info("HistoryItem: " + JSON.stringify(historyItem));
            this.icon = historyItem.icon;
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
