# User-Agent开发指导
<!--RP1-->
User-Agent（简称UA）是一个特殊的字符串，包含设备类型、操作系统及版本等关键信息。在Web开发中，这个字符串使服务器能够识别请求的来源设备及其特性，从而根据这些信息提供定制化的内容和服务。如果页面无法正确识别UA，可能会导致多种异常情况。例如，为移动设备优化的页面布局可能会在桌面设备上显示错乱，反之亦然。此外，某些特定的浏览器功能或CSS样式可能仅在特定的浏览器版本中受支持，如果页面无法根据UA字符串做出正确的判断，就可能导致渲染问题或逻辑错误。

## 默认User-Agent结构

- 默认User-Agent定义

  ```ts
  Mozilla/5.0 ({DeviceType}; {OSName} {OSVersion}) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/{ChromeCompatibleVersion}.0.0.0 Safari/537.36  ArkWeb/{ArkWeb VersionCode} {DeviceCompat} {扩展区}
  ```

- 举例说明

  ```ts
  Mozilla/5.0 (Phone; OpenHarmony 5.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36  ArkWeb/4.1.6.1 Mobile
  ```

- 字段说明

  | 字段                  | 含义                                                         |
  | --------------------- | ------------------------------------------------------------ |
  | DeviceType            | 当前的设备类型。<br>取值范围：<br>- Phone：手机<br>- Tablet：平板设备<br>-  PC：2in1设备 |
  | OSName                | 基础操作系统名称。<br>默认取值：OpenHarmony                  |
  | OSVersion             | 基础操作系统版本，两位数字，M.S。<br>通过系统参数const.ohos.fullname解析版本号得到，取版本号部分M.S前两位。<br>默认取值：例如5.0       |
  | ChromeCompatibleVersion | 兼容Chrome主版本的版本号，从114版本开始演进。<br>默认取值：114            |
  | ArkWeb                | OpenHarmony版本Web内核名称。<br>默认取值：ArkWeb             |
  | ArkWeb VersionCode    | ArkWeb版本号，格式a.b.c.d。<br>默认取值：例如4.1.6.1         |
  | DeviceCompat          | 前向兼容字段。<br>默认取值：Mobile                          |
  | 扩展区                | 三方应用可以扩展的字段。<br>三方应用使用ArkWeb组件时，可以做UA扩展，例如加入APP相关信息标识。 |

> **说明：**
>
> - 当前默认User-Agent的ArkWeb字段前有两个空格。
>
> - 当前通过User-Agent中是否含有"Mobile"字段来判断是否开启前端HTML页面中meta标签的viewport属性。当User-Agent中不含有"Mobile"字段时，meta标签中viewport属性默认关闭，此时可通过显性设置[metaViewport](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#metaviewport12)属性为true来覆盖关闭状态。
>
> - 建议通过OpenHarmony关键字识别是否是OpenHarmony设备，同时可以通过DeviceType识别设备类型用于不同设备上的页面显示（ArkWeb关键字表示设备使用的web内核，OpenHarmony关键字表示设备使用的操作系统，因此推荐通过OpenHarmony关键字识别是否是OpenHarmony设备）。
>
> - {DistributionOSName}和{DistributionOSVersion}字段在API version 15之前的版本中未启用，从API version 15版本开始不在默认User-Agent中体现。

## 自定义User-Agent结构

在下面的示例中，通过调用[getUserAgent()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#getuseragent)接口获取当前默认的用户代理（User-Agent）字符串。这一接口提供的默认User-Agent信息为开发者提供了基础，使开发者能够基于这个默认信息进行定制或扩展。

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

以下示例通过[setCustomUserAgent()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setcustomuseragent10)接口设置自定义用户代理，但请注意，此操作会覆盖系统的用户代理。因此，我们建议将扩展字段追加在默认用户代理的末尾，比如三方应用程序的开发场景，可以在系统默认用户代理字符串的末尾追加特定的APP标识，这样既能保留原有用户代理信息，又能增加自定义的应用识别信息。

当Web组件src设置了url时，建议在onControllerAttached回调事件中设置User-Agent，设置方式请参考示例。不建议将User-Agent设置在onLoadIntercept回调事件中，会概率性出现设置失败。如果未在onControllerAttached回调事件中设置User-Agent。再调用setCustomUserAgent方法时，可能会出现加载的页面与实际设置User-Agent不符的异常现象。

当Web组件src设置为空字符串时，建议先调用setCustomUserAgent方法设置User-Agent，再通过loadUrl加载具体页面。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  // 三方应用相关信息标识
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

从API version 20开始，可通过[setAppCustomUserAgent()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setappcustomuseragent20)接口设置应用级自定义用户代理，或者通过[setUserAgentForHosts()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setuseragentforhosts20)对特定网站设置应用级自定义用户代理，覆盖系统的用户代理，应用内所有Web组件生效。

建议在Web组件创建前调用setAppCustomUserAgent，setUserAgentForHosts方法设置User-Agent，再创建指定src的Web组件或通过loadUrl加载具体页面。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  aboutToAppear(): void {
    try {
      webview.WebviewController.initializeWebEngine();
      let defaultUserAgent = webview.WebviewController.getDefaultUserAgent();
      let appUA = " appUA";
      webview.WebviewController.setUserAgentForHosts(
        appUA,
        [
          "www.example.com",
          "www.baidu.com"
        ]
      );
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

在下面的示例中，通过[getCustomUserAgent()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#getcustomuseragent10)接口获取自定义用户代理。

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

## 相关User-Agent接口优先级

| 接口名称 | 优先级 | 说明 |
| -------- | -------- | -------- |
| setCustomUserAgent | 最高 | 对调用的Web组件生效。|
| setUserAgentForHosts | 低于setCustomUserAgent | 对应用中所有Web组件访问指定网站生效。|
| setAppCustomUserAgent | 低于setUserAgentForHosts | 对应用中所有Web组件生效。 |
|  ArkWeb默认UA | 最低 | 对应用中所有Web组件生效，只读，通过getDefaultUserAgent获取。|

## 常见问题

### 如何通过User-Agent来识别OpenHarmony操作系统中不同设备

OpenHarmony设备的识别主要通过User-Agent中的系统、系统版本和设备类型三个维度来判断。建议同时检查系统、系统版本和设备类型，以确保更准确的设备识别。

1. 系统识别

   通过User-Agent中的{OSName}字段识别OpenHarmony系统。

   ```ts
   const isOpenHarmony = () => /OpenHarmony/i.test(navigator.userAgent);   
   ```

2. 系统版本识别

   通过User-Agent中的{OSName}和{OSVersion}字段识别OpenHarmony系统及系统版本。格式为：OpenHarmony + 版本号。

   ```ts
   const matches = navigator.userAgent.match(/OpenHarmony (\d+\.?\d*)/);  
   matches?.length && Number(matches[1]) >= 5;  
   ```

3. 设备类型识别

    通过deviceType字段来识别不同设备类型。

   ```ts
   // 检测是否为手机设备
   const isPhone = () => /Phone/i.test(navigator.userAgent);

   // 检测是否为平板设备  
   const isTablet = () => /Tablet/i.test(navigator.userAgent);
   
   // 检测是否为2in1设备  
   const is2in1 = () => /PC/i.test(navigator.userAgent);
   ```

### 如何模拟OpenHarmony操作系统的User-Agent进行前端调试

在Windows/Mac/Linux等操作系统中，可以通过Chrome/Edge/Firefox等浏览器DevTools提供的User-Agent复写能力，模拟OpenHarmony User-Agent。
<!--RP1End-->