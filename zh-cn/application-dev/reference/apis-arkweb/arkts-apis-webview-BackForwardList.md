# Interface (BackForwardList)

当前Webview的历史信息列表。

> **说明：**
>
> - 本模块接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## 属性

**系统能力：** SystemCapability.Web.Webview.Core

| 名称         | 类型   | 只读 | 可选 | 说明                                                         |
| ------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| currentIndex | ArkTS1.1: number<br>ArkTS1.2: int | 否   | 否   | 当前在页面历史列表中的索引。                                 |
| size         | ArkTS1.1: number<br>ArkTS1.2: int | 否   | 否   | 历史列表中索引的数量，最多保存50条，超过时起始记录会被覆盖。 |

## getItemAtIndex

ArkTS1.1: getItemAtIndex(index: number): HistoryItem

ArkTS1.2: getItemAtIndex(index: int): HistoryItem

获取历史列表中指定索引的历史记录项信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| index  | ArkTS1.1: number<br>ArkTS1.2: int | 是   | 指定历史列表中的索引。 |

**返回值：**

| 类型                        | 说明         |
| --------------------------- | ------------ |
| [HistoryItem](./arkts-apis-webview-i.md#historyitem) | 历史记录项。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

ArkTS1.1示例：
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

ArkTS1.2示例：
```ts
// xxx.ets
import webview from '@ohos.web.webview';
import { Text, Entry, Column, Component, BusinessError, Button, Web, ClickEvent } from '@ohos.arkui.component';
import type image from '@ohos.multimedia.image';
import { State } from '@ohos.arkui.stateManagement';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController(undefined);
  @State icon: image.PixelMap | undefined = undefined;

  build() {
    Column(undefined) {
      Button('getBackForwardEntries')
        .onClick((e: ClickEvent) => {
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