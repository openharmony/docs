# Intelligent Tracking Prevention


The web component supports the intelligent anti-tracing function. That is, when a tracing website is inserted into another web page as a third party, the network request sent by the website cannot carry cookies.

- Invoke the [enableIntelligentTrackingPrevention](../reference/apis-arkweb/js-apis-webview.md#enableintelligenttrackingprevention12) interface to enable or disable the intelligent anti-tracking function of the corresponding web component. By default, this function is disabled.

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

- Invoke the [isIntelligentTrackingPreventionEnabled](../reference/apis-arkweb/js-apis-webview.md#isintelligenttrackingpreventionenabled12) interface to check whether the intelligent anti-tracking function is enabled for the current Web component.

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

- You can call the [onIntelligentTrackingPreventionResult](../reference/apis-arkweb/ts-basic-components-web.md#onintelligenttrackingpreventionresult12) API to asynchronously obtain the domain names of blocked tracing websites and accessed websites in callback mode.

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
        // The onIntelligentTrackingPreventionResult callback is triggered only when the intelligent anti-tracking function is enabled.
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

In addition, the intelligent anti-tracking function provides a group of interfaces for setting the list of domain names that need to bypass the intelligent anti-tracking function. The domain name list set by these interfaces takes effect for the entire application instead of a web component.

- Invoke the [addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#addintelligenttrackingpreventionbypassinglist12) interface to set the list of domain names that need to bypass the intelligent anti-tracking function.

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

- Call the [removeIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#removeintelligenttrackingpreventionbypassinglist12) API to remove the partial domain name list set using the [addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#addintelligenttrackingpreventionbypassinglist12) API.

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

- You can call the [clearIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#clearintelligenttrackingpreventionbypassinglist12) interface to clear all domain names set through the [addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/js-apis-webview.md#addintelligenttrackingpreventionbypassinglist12) interface.

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
<!--no_check-->