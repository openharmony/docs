# Developing User-Agent

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!--RP1-->
<!-- md-trans-meta sourceCommit=95d707f76a454a7ac9a469c434369c3b8ffcfeb1 translatedAt=2026-08-14T03:44:45.953Z pushedAt=2026-08-14T07:55:30.260Z -->

User-Agent (UA) is a special string that contains key information such as the device type, operating system, and version. In web development, UA is used by the server to identify the source device of the request and its features, so that the server can provide custom content and services. If UAs cannot be correctly identified on a page, multiple exceptions may occur. For example, a page layout optimized for a mobile device may be displayed in disorder on a desktop device, and vice versa. In addition, some browser functionalities or CSS attributes are supported only in specific browser versions. If a page cannot successfully identify the UA, rendering problems or logic errors may occur.

## Default User-Agent Structure

- String format

  ```ts
  Mozilla/5.0 ({DeviceType}; {OSName} {OSVersion}) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/{ChromeCompatibleVersion}.0.0.0 Safari/537.36 ArkWeb/{ArkWeb VersionCode} {DeviceCompat} {Extension}
  ```

- Example

  ```ts
  Mozilla/5.0 (Phone; OpenHarmony 5.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36  ArkWeb/4.1.6.1 Mobile
  ```

- Fields

  | Field                 | Description                                                        |
  | --------------------- | ------------------------------------------------------------ |
  | DeviceType            | Device type.<br>The value can be:<br>- **Phone**<br>- **Tablet**<br>- **PC** (2-in-1 device)|
  | OSName                | OS name.<br>Default value: **OpenHarmony**                 |
  | OSVersion             | Base operating system version, two digits in the format M.S.<br>For example, the value for OpenHarmony-6.1.0.31 is 6.1       |
  | ChromeCompatibleVersion | Version number compatible with the Chrome major version, evolving from version 114.<br>For the corresponding value, see [Constraints](./web-component-overview.md#constraints). For example, the default Chrome version on OpenHarmony 6.0 is 132        |
  | ArkWeb                | Web kernel name of the OpenHarmony version.<br>Default value: **ArkWeb**            |
  | ArkWeb VersionCode    | ArkWeb version number in the format a.b.c.d.<br>For example, 4.1.6.1         |
  | DeviceCompat          | Forward compatibility field.<br>The default value is Mobile for phones.<br>The default value is empty for other devices                |
  | Extension               | Field that can be extended by a third-party application.<br>When a third-party application uses the **Web** component, UA can be extended. For example, an application information identifier can be added.|

> **NOTE**
>
> - The ArkWeb field in the current default User-Agent is preceded by two spaces.
>
> - According to [RFC 7230 Section 3.2](https://www.rfc-editor.org/info/rfc7230/#section-3.2), a custom User-Agent string must not contain null characters (\0), carriage returns (\r), or line feeds (\n); otherwise, the app crashes.
>
> - Whether the viewport attribute of the meta tag in the frontend HTML page is enabled is determined by whether the User-Agent contains the "Mobile" field. When the User-Agent does not contain the "Mobile" field, the viewport attribute in the meta tag is disabled by default. In this case, you can explicitly set the [metaViewport](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#metaviewport12) attribute to **true** to override the disabled state.
>
> - It is recommended that you use the OpenHarmony keyword to identify whether a device is an OpenHarmony device, and use DeviceType to identify the device type for page display on different devices. (The ArkWeb keyword indicates the web kernel used by the device, and the OpenHarmony keyword indicates the operating system used by the device. Therefore, it is recommended that you use the OpenHarmony keyword to identify whether a device is an OpenHarmony device.)
>
> - The {DistributionOSName} and {DistributionOSVersion} fields are not enabled in versions earlier than API version 15, and are no longer included in the default User-Agent starting from API version 15.

## Custom User-Agent Structure

In the following example, [getUserAgent()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#getuseragent) is used to obtain the default **User-Agent** string, which you can modify or extend as needed.

<!-- @[get_the_current_default_user_agent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsTwo/entry/src/main/ets/pages/UserAgent_one.ets) -->

``` TypeScript
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
            console.info('userAgent: ' + userAgent);
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

In the following example, [setCustomUserAgent()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setcustomuseragent10) is used to set a custom user agent, which overwrites the default user agent. Therefore, you are advised to add the extension field to the end of the default user agent. For example, to develop a third-party application, you can add a specific application identifier while maintaining the original user agent information.

When the **src** of the **Web** component is set to a URL, it is recommended that you set the User-Agent in the [onControllerAttached](../reference/apis-arkweb/arkts-basic-components-web-events.md#oncontrollerattached10) callback event. For details about how to set it, see the example. It is not recommended that you set the User-Agent in the [onLoadIntercept](../reference/apis-arkweb/arkts-basic-components-web-events.md#onloadintercept10) callback event, because the setting may fail with a certain probability. If the User-Agent is not set in the onControllerAttached callback event, an abnormal behavior may occur when setCustomUserAgent is called later, where the loaded page does not match the actually set User-Agent.

When **src** of the **Web** component is set to an empty string, call **setCustomUserAgent** to set **User-Agent** and then use **loadUrl** to load a specific page.

<!-- @[set_up_a_custom_user_agent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsTwo/entry/src/main/ets/pages/UserAgent_two.ets) -->

``` TypeScript
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  // Third-party application information identifier
  @State customUserAgent: string = ' DemoApp';

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .onControllerAttached(() => {
          console.info('onControllerAttached');
          try {
            let userAgent = this.controller.getUserAgent() + this.customUserAgent;
            this.controller.setCustomUserAgent(userAgent);
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
    }
  }
}
```

Since API version 20, you can use the [setAppCustomUserAgent()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setappcustomuseragent20) API to set an application-level custom user agent or use the [setUserAgentForHosts()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setuseragentforhosts20) API to set an application-level custom user agent for a specific website. The custom user agent overwrites the system user agent and takes effect for all **Web** components in the application.

It is recommended that you call the static API [getDefaultUserAgent](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#getdefaultuseragent14) to obtain the default **User-Agent** string, then call **setAppCustomUserAgent** and **setUserAgentForHosts** to set the **User-Agent**, and then create a **Web** component with the specified **src** or load a specific page using **loadUrl**.

<!-- @[set_app_custom_user_agent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsTwo/entry/src/main/ets/pages/UserAgent_four.ets) -->

``` TypeScript
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
      let appUA = defaultUserAgent + ' appUA';    
      webview.WebviewController.setAppCustomUserAgent(appUA);    
      webview.WebviewController.setUserAgentForHosts(    
        appUA,    
        [    
          'www.example.com',    
          'www.baidu.com'    
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

In the following example, [getCustomUserAgent()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#getcustomuseragent10) is used to obtain the custom user agent. 

<!-- @[get_a_custom_user_agent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsTwo/entry/src/main/ets/pages/UserAgent_three.ets) -->

``` TypeScript
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
            console.info('userAgent: ' + this.userAgent);
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## User-Agent API Priority

| API| Priority| Description|
| -------- | -------- | -------- |
| setCustomUserAgent | Highest| Takes effect for the called **Web** component.|
| setUserAgentForHosts | Lower than **setCustomUserAgent**| Takes effect for all **Web** components in the application to access the specified website.|
| setAppCustomUserAgent | Lower than **setUserAgentForHosts**| Takes effect for all **Web** components in the application.|
|  Default UA of ArkWeb| Lowest| Takes effect for all **Web** components in the application. This parameter is read-only and can be obtained using **getDefaultUserAgent**.|

## FAQs

### How do I use User-Agent to identify different OpenHarmony devices?

OpenHarmony devices are identified mainly based on three dimensions in the User-Agent: the system, system version, and device type. It is recommended that you check all the above information to ensure more accurate device identification.

1. Identification based on the OS name

   Use the **{OSName}** field.

   ```ts
   const isOpenHarmony = () => /OpenHarmony/i.test(navigator.userAgent);   
   ```

2. Identification based on the OS version

   Use the **{OSName}** and **{OSVersion}** fields. The format is **OpenHarmony + Version number**.

   ```ts
   const matches = navigator.userAgent.match(/OpenHarmony (\d+\.?\d*)/);  
   matches?.length && Number(matches[1]) > 0;  
   ```

3. Identification based on the device type

    Use the **deviceType** field.

   ```ts
   // Check whether the device is a mobile phone.
   const isPhone = () => /Phone/i.test(navigator.userAgent);

   // Check whether the device is a tablet. 
   const isTablet = () => /Tablet/i.test(navigator.userAgent);
   
   // Check whether the device is a 2-in-1 device. 
   const is2in1 = () => /PC/i.test(navigator.userAgent);
   ```

### How do I simulate the User-Agent of OpenHarmony for frontend debugging?

In Windows, macOS, and Linux, you can use the **User-Agent** rewriting capability provided by DevTools to simulate the OpenHarmony **User-Agent** in Chrome, Edge, and Firefox.

### How do I customize the User-Agent in OpenHarmony to implement HTML5 compatibility?

OpenHarmony provides the [setCustomUserAgent](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setcustomuseragent10) API to customize the **User-Agent**. To adapt to the UA identifier detection (such as Mobile and OpenHarmony) that mobile HTML5 pages usually depend on and ensure that the default UA information is not overwritten, you are advised to perform the following operations: First, obtain the default **User-Agent** string through the [getDefaultUserAgent](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#getdefaultuseragent14) API. Then, append the custom identifier field required for HTML5 compatibility to the end of the string. Finally, call the **setCustomUserAgent** API to set the complete UA string.

### How to solve the UA compatibility problem of HTML5 pages?

Q: Why the web page on a mobile device is displayed in the PC style or the web page on a PC is displayed in the mobile style?

A: The website displays different styles of pages based on different UAs. For mobile devices, set **DeviceCompat** to **Mobile** and **DeviceType** to **Phone**. For PCs, set **DeviceCompat** to **""** and **DeviceType** to **PC**. For tablets, set **DeviceCompat** to **""** and **DeviceType** to **Tablet**.

Q: Why can't I open some web pages or the message "Unsupported browser" is displayed?

A: The web page is not adapted to the OpenHarmony UA. It is necessary for the web page to perform compatibility processing for the **OpenHarmony** identifier.

Q: Why does the page redirect in a loop?

A: The application sets conflicting UA identifiers for the two pages that redirect to each other. As a result, the redirection logic on the server enters an infinite loop. Ensure that the application maintains consistent logic when calling **setUserAgentForHosts** to configure a compatible UA for associated websites, so as to avoid infinite loops in web page redirection logic caused by UA differences.

Q: Why the download link provided by the web page does not match the device platform? For example, the download package for an OpenHarmony device is an APK.

A: The compatibility field in the UA interferes with the server identification. To ensure web page compatibility, some browsers may add non-OpenHarmony operating system names to **User-Agent**. If the parsing logic sequence of the server is improper, the actual device identifier may be ignored. In this case, you are advised to place the OpenHarmony processing logic before the processing logic of other operating systems.

<!--RP1End-->