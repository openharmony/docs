# 使用智能防跟踪功能


Web组件支持智能防跟踪功能，即当跟踪型网站作为第三方插入到其他网页时，其发送的网络请求将禁止携带cookie。

- 通过调用[enableIntelligentTrackingPrevention](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#enableintelligenttrackingprevention12)接口启用或关闭Web组件的智能防跟踪功能。默认情况下，该功能未启用。

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
        Button('enableIntelligentTrackingPrevention')
          .onClick(() => {
            try {
              this.controller.enableIntelligentTrackingPrevention(true);
              console.log("enableIntelligentTrackingPrevention: true");
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

- 调用[isIntelligentTrackingPreventionEnabled](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#isintelligenttrackingpreventionenabled12)接口，判断Web组件是否开启了智能防跟踪功能。

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
        Button('isIntelligentTrackingPreventionEnabled')
          .onClick(() => {
            try {
              let result = this.controller.isIntelligentTrackingPreventionEnabled();
              console.log("result: " + result);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

- 通过[onIntelligentTrackingPreventionResult](../reference/apis-arkweb/arkts-basic-components-web-events.md#onintelligenttrackingpreventionresult12)接口将被拦截的跟踪型域名及其触发网站的域名回调给应用。

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
        // 需要打开智能防跟踪功能，才会触发onIntelligentTrackingPreventionResult回调
        Button('enableIntelligentTrackingPrevention')
          .onClick(() => {
            try {
              this.controller.enableIntelligentTrackingPrevention(true);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .onIntelligentTrackingPreventionResult((details) => {
            console.log("onIntelligentTrackingPreventionResult: [websiteHost]= " + details.host +
              ", [trackerHost]=" + details.trackerHost);
          })
      }
    }
  }
  ```

智能防跟踪功能提供了一组接口，用于设置绕过该功能的域名列表。这些接口设置的域名列表适用于整个应用，而非特定的Web组件。

- 调用[addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#addintelligenttrackingpreventionbypassinglist12)接口设置绕过域名列表。

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
        Button('addIntelligentTrackingPreventionBypassingList')
          .onClick(() => {
            try {
              let hostList = ["www.test1.com", "www.test2.com", "www.test3.com"];
              webview.WebviewController.addIntelligentTrackingPreventionBypassingList(hostList);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

- 调用[removeIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#removeintelligenttrackingpreventionbypassinglist12)接口删除部分绕过域名列表。

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
        Button('removeIntelligentTrackingPreventionBypassingList')
          .onClick(() => {
            try {
              let hostList = [ "www.test1.com", "www.test2.com" ];
              webview.WebviewController.removeIntelligentTrackingPreventionBypassingList(hostList);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

- 调用[clearIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#clearintelligenttrackingpreventionbypassinglist12)接口清除所有绕过域名列表。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Button('clearIntelligentTrackingPreventionBypassingList')
          .onClick(() => {
            webview.WebviewController.clearIntelligentTrackingPreventionBypassingList();
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```
