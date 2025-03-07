# Intelligent Tracking Prevention


The **Web** component supports the intelligent tracking prevention. That is, when a tracking website is inserted into another web page as a third party, the network request sent by the website cannot carry cookies.

- Invoke the [enableIntelligentTrackingPrevention](../reference/apis-arkweb/js-apis-webview.md#enableintelligenttrackingprevention12) API to enable or disable the intelligent tracking prevention of a **Web** component. By default, this prevention is disabled.

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

- Invoke the [isIntelligentTrackingPreventionEnabled](../reference/apis-arkweb/js-apis-webview.md#isintelligenttrackingpreventionenabled12) API to check whether the intelligent tracking prevention is enabled for the **Web **component.

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

- You can call the [onIntelligentTrackingPreventionResult](../reference/apis-arkweb/ts-basic-components-web.md#onintelligenttrackingpreventionresult12) API to asynchronously obtain the domain names of intercepted tracking websites and accessed websites.

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
        // The onIntelligentTrackingPreventionResult callback is triggered only when the intelligent tracking prenvention is enabled.
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

In addition, the intelligent tracking prevention functionality provides APIs for setting the list of domain names that need to bypass the intelligent tracking prevention. The domain name list set by these APIs applies to the entire application instead of a single **Web** component.

- Invoke the [addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#addintelligenttrackingpreventionbypassinglist12) API to set the list of domain names that need to bypass the intelligent tracking prevention.

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

- Invoke the [removeIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#removeintelligenttrackingpreventionbypassinglist12) API to remove the partial domain name list set using the [addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#addintelligenttrackingpreventionbypassinglist12) API.

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

- Invoke the [clearIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#clearintelligenttrackingpreventionbypassinglist12) API to clear all domain names set using the [addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#addintelligenttrackingpreventionbypassinglist12) API.

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
