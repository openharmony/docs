# Setting UserAgent

## Default User Agent String

Since API version 11, the default user agent string is as follows for the **Web** component based on the ArkWeb kernel:

Mozilla/5.0 ({deviceType}; {OSName} {OSVersion}) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/{ArkWeb VersionCode} {Mobile}

| Field.              | Description              | Remarks              |
| ------------------ | ------------------ | ------------------ |
| deviceType         | Device type.          | Obtained through the mapping of the system parameter **const.product.devicetype**.|
| OSName             | OS name of the distribution.| Obtained by parsing the system parameter <!--RP1-->**const.product.os.dist.name**<!--RP1End-->.|
| OSVersion          |OS version of the distribution.| Obtained by parsing the system parameter **const.ohos.fullname**.|
| ArkWeb VersionCode | ArkWeb version.      |- |
| Mobile (optional)    | Whether the device is a mobile phone.    |- |

> **NOTE**
>
> - Currently, the **viewport** attribute of the **meta** tag on the frontend HTML page is enabled based on whether **UserAgent** contains the **Mobile** field. If **UserAgent** does not contain the **Mobile** field, the **viewport** attribute in the **meta** tag is disabled by default. In this case, you can explicitly set [metaViewport](../reference/apis-arkweb/ts-basic-components-web.md#metaviewport12) to **true** to enable the **viewport** attribute.

Example:

Mozilla/5.0 (Phone; OpenHarmony <!--RP2-->4.1<!--RP2End-->) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/4.1.6.1 Mobile

You are advised to use the **ArkWeb** keyword to identify whether the device is an OpenHarmony device and whether the web kernel is ArkWeb. You can also use the **deviceType** keyword to identify the device type for page display.

## When to Use

Example of using [getUserAgent()](../reference/apis-arkweb/js-apis-webview.md#getuseragent) to obtain the default user agent, which can be customized:

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('getUserAgent')
        .onClick(() => {
          try {
            let userAgent = this.controller.getUserAgent();
            console.log("userAgent: " + userAgent);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

HTML file to be loaded:
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State ua: string = "";

  aboutToAppear(): void {
    webview.once('webInited', () => {
      try {
        // Customize a user agent on the application side.
        this.ua = this.controller.getUserAgent() + 'xxx';
        this.controller.setCustomUserAgent(this.ua);
      } catch (error) {
        console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
      }
    })
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

In the following example, the custom user agent set through [setCustomUserAgent()](../reference/apis-arkweb/js-apis-webview.md#setcustomuseragent10) overwrites the user agent of the system.
When **src** of the **Web** component is set to a URL, you are advised to set **UserAgent** in **onControllerAttached**. For details, see the following example. You are not advised to set **UserAgent** in **onLoadIntercept**. Otherwise, the setting may fail occasionally. If **UserAgent** is not set in **onControllerAttached**, calling **setCustomUserAgent** may load a page that is inconsistent with the custom user agent.
When **src** of the **Web** component is set to an empty string, you are advised to call **setCustomUserAgent** to set **UserAgent** and then use **loadUrl** to load a specific page.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State customUserAgent: string = 'test';

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
      .onControllerAttached(() => {
        console.log("onControllerAttached");
        try {
          let userAgent = this.controller.getUserAgent() + this.customUserAgent;
          this.controller.setCustomUserAgent(userAgent);
        } catch (error) {
          console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
      })
    }
  }
}
```

Example of obtaining the custom user agent through [getCustomUserAgent()](../reference/apis-arkweb/js-apis-webview.md#getcustomuseragent10):

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State userAgent: string = '';

  build() {
    Column() {
      Button('getCustomUserAgent')
        .onClick(() => {
          try {
            this.userAgent = this.controller.getCustomUserAgent();
            console.log("userAgent: " + this.userAgent);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
<!--RP3--><!--RP3End-->
