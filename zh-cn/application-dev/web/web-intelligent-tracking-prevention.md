# 使用智能防跟踪功能


Web组件支持智能防跟踪功能，即跟踪型网站作为三方插入别的网页时，其发送的网络请求禁止携带cookie。

- 通过调用[enableIntelligentTrackingPrevention](../reference/apis-arkweb/js-apis-webview.md#enableintelligenttrackingprevention12)接口使能或者关闭相应Web组件的智能防跟踪功能，默认情况下该功能未启用。

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

- 通过调用[isIntelligentTrackingPreventionEnabled](../reference/apis-arkweb/js-apis-webview.md#isintelligenttrackingpreventionenabled12)接口判断当前Web组件是否开启了智能防跟踪功能。

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

- 通过调用[onIntelligentTrackingPreventionResult](../reference/apis-arkweb/ts-basic-components-web.md#onintelligenttrackingpreventionresult12)接口，以回调的方式异步获取拦截的跟踪型网站的域名和访问的网站域名信息。

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

同时，智能防跟踪功能提供了一组接口，用于设置需要绕过智能防跟踪功能的域名列表。这些接口设置的域名列表是整个应用生效，而非某个Web组件。

- 通过调用[addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#addintelligenttrackingpreventionbypassinglist12)接口设置需要绕过智能防跟踪功能的域名列表。

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

- 通过调用[removeIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#removeintelligenttrackingpreventionbypassinglist12)接口移除通过[addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#addintelligenttrackingpreventionbypassinglist12)接口设置的部分域名列表。

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

- 通过调用[clearIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#clearintelligenttrackingpreventionbypassinglist12)接口清除通过[addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#addintelligenttrackingpreventionbypassinglist12)接口设置的所有域名。

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
