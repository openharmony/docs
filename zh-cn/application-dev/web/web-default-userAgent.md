# 设置UserAgent

## 默认UserAgent定义

从API version 11起，Web组件基于ArkWeb的内核，默认UserAgent定义如下：

Mozilla/5.0 ({deviceType}; {OSName} {OSVersion}; {DistributionOSName} {DistributionOSVersion}) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/{ArkWeb VersionCode} {Mobile}

| 字段               | 含义               | 备注               |
| ------------------ | ------------------ | ------------------ |
| deviceType         | 设备类型           | 通过系统参数const.product.devicetype映射得到。|
| OSName             | 基础操作系统名称 | 通过系统参数const.ohos.fullname解析得到。|
| OSVersion          | 基础操作系统名称 | 通过系统参数const.ohos.fullname解析得到。|
| DistributionOSName          | 发行版操作系统版本 | 通过系统参数<!--RP1-->const.product.os.dist.name<!--RP1End-->得到。|
| DistributionOSVersion          | 发行版操作系统版本 | 通过系统参数const.product.os.dist.apiname解析版本号得到，如果const.product.os.dist.apiname为空，通过系统参数const.product.os.dist.version解析版本号得到。|
| ArkWeb VersionCode | ArkWeb版本号       |- |
| Mobile（可选）     | 是否是手机设备     |- |

举例：

Mozilla/5.0 (Phone; OpenHarmony <!--RP3-->5.0<!--RP3End-->) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/4.1.6.1 Mobile

建议通过ArkWeb关键字识别是否是OpenHarmony设备以及web内核是否为ArkWeb，同时可以通过deviceType识别设备类型用于不同设备上的页面显示。

## 使用场景

在下面的示例中，通过[getUserAgent()](../reference/apis-arkweb/js-apis-webview.md#getuseragent)接口获取当前默认用户代理，支持开发者基于默认的UserAgent去定制UserAgent。

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

加载的html文件。
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
        // 应用侧用法示例，定制UserAgent。
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

在下面的示例中，通过[setCustomUserAgent()](../reference/apis-arkweb/js-apis-webview.md#setcustomuseragent10)接口设置自定义用户代理，会覆盖系统的用户代理。
当Web组件src设置了url时，建议在onControllerAttached回调事件中设置UserAgent，设置方式请参考示例。不建议将UserAgent设置在onLoadIntercept回调事件中，会概率性出现设置失败。如果未在onControllerAttached回调事件中设置UserAgent。再调用setCustomUserAgent方法时，可能会出现加载的页面与实际设置UserAgent不符的异常现象。
当Web组件src设置为空字符串时，建议先调用setCustomUserAgent方法设置UserAgent，再通过loadUrl加载具体页面。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  @State customUserAgent: string = ' DemoApp';

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

在下面的示例中，通过[getCustomUserAgent()](../reference/apis-arkweb/js-apis-webview.md#getcustomuseragent10)接口获取自定义用户代理。

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