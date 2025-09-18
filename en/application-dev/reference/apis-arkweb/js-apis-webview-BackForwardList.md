# Interface (BackForwardList)

Provides the historical information list of the current WebView.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 15.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Modules to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## Properties

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Type  | Read-Only| Optional| Description                                                        |
| ------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| currentIndex | number | No  | No  | Index of the current page in the page history stack.                                |
| size         | number | No  | No  | Number of indexes in the history stack. The maximum value is 50. If this value is exceeded, the earliest index will be overwritten.|

## getItemAtIndex

getItemAtIndex(index: number): HistoryItem

Obtains the page record with the specified index in the history stack.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| index  | number | Yes  | Index of the target page record in the history stack.|

**Return value**

| Type                       | Description        |
| --------------------------- | ------------ |
| [HistoryItem](./js-apis-webview.md#historyitem) | Historical page record.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
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
            console.log("HistoryItem: " + JSON.stringify(historyItem));
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
