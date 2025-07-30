# Intelligent Tracking Prevention


The **Web** component supports the intelligent tracking prevention feature. That is, when a tracking website is inserted into another web page as a third party, the network request sent by the website cannot carry cookies.

- Call the [enableIntelligentTrackingPrevention](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#enableintelligenttrackingprevention12) API to enable or disable the intelligent tracking prevention feature of the **Web** component. By default, this functionality is disabled.

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

- Call the [isIntelligentTrackingPreventionEnabled](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#isintelligenttrackingpreventionenabled12) API to check whether the intelligent tracking prevention feature is enabled for the **Web** component.

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

- Call the [onIntelligentTrackingPreventionResult](../reference/apis-arkweb/arkts-basic-components-web-events.md#onintelligenttrackingpreventionresult12) API to return the blocked tracking domain name and the domain name of the triggered website to the application.

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
        // The onIntelligentTrackingPreventionResult callback is triggered only when the intelligent tracking prevention feature is enabled.
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

The intelligent tracking prevention feature provides a group of APIs for setting the list of domain names that bypass this feature. The domain name list set by these APIs applies to the application rather than a specific **Web** component.

- Call the [addIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#addintelligenttrackingpreventionbypassinglist12) API to set the bypass domain name list.

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

- Call the [removeIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#removeintelligenttrackingpreventionbypassinglist12) API to delete some domain names in the bypass list.

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

- Call the [clearIntelligentTrackingPreventionBypassingList](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#clearintelligenttrackingpreventionbypassinglist12) API to clear the bypass domain name list.

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
