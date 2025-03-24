# Developing UserAgent
<!--RP1-->
UserAgent (UA) is a special string that contains key information such as the device type, operating system, and version. If a page cannot correctly identify the UA, exceptions in the page layout, rendering, and logic may occur.

## Default UserAgent Structure

- String format

  ```ts
  Mozilla/5.0 ({DeviceType}; {OSName} {OSVersion}; {DistributionOSName} {DistributionOSVersion}) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/{ChromeCompatibleVersion}.0.0.0 Safari/537.36 ArkWeb/{ArkWeb VersionCode} {DeviceCompat} {Extension}
  ```

- Example

  Mozilla/5.0 (Phone; OpenHarmony 5.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/4.1.6.1 Mobile

- Fields

  | Field                 | Description                                                        |
  | --------------------- | ------------------------------------------------------------ |
  | DeviceType            | Device type.<br>The value can be:<br>- **Phone**<br>- **Tablet**<br>- **PC** (2-in-1 device)|
  | OSName                | OS name.<br>Default value: **OpenHarmony**                 |
  | OSVersion             | OS version. The value is a two-digit number, in M.S format.<br>You can obtain the value by extracting the first two digits of the version number from the system parameter **const.ohos.fullname**.<br>Default value: **5.0**      |
  | DistributionOSName    | Distribution OS name.                                        |
  | DistributionOSVersion | Distribution OS version. The value is a two-digit number, in M.S format.<br>You can obtain the value by extracting the first two digits of the version number from the system parameter **const.product.os.dist.apiname**. Use **const.product.os.dist.version** if **const.product.os.dist.apiname** is empty.<br>Default value: **5.0**    |
  | ChromeCompatibleVersion | The version that is compatible with the main Chrome version. The earliest version is 114.<br>Default value: **114**           |
  | ArkWeb                | Web kernel name of the OpenHarmony version.<br>Default value: **ArkWeb**            |
  | ArkWeb VersionCode    | ArkWeb version number, in the format of a.b.c.d.<br>Default value: **4.1.6.1**        |
  | DeviceCompat          | Forward compatibility settings.<br>Default value: **Mobile**                         |
  | Extension               | Field that can be extended by a third-party application.<br>When a third-party application uses the **Web** component, UA can be extended. For example, an application information identifier can be added.|

> **NOTE**
>
> - Currently, the **viewport** parameter of the **meta** tag on the frontend HTML page is enabled or disabled based on whether **UserAgent** contains the **Mobile** field. If **UserAgent** does not contain the **Mobile** field, the **viewport** attribute in the **meta** tag is disabled by default. In this case, you can explicitly set [metaViewport](../reference/apis-arkweb/ts-basic-components-web.md#metaviewport12) to **true** to enable the **viewport** attribute.
>
> - You are advised to use the **OpenHarmony** keyword to identify whether a device is an OpenHarmony device, and use the **DeviceType** keyword to identify the device type for page display on different devices. (The **ArkWeb** keyword indicates the web kernel of the device, and the **OpenHarmony** keyword indicates the operating system of the device.)

## Custom UserAgent Structure

In the following example, [getUserAgent()](../reference/apis-arkweb/js-apis-webview.md#getuseragent) is used to obtain the default **UserAgent** string, which you can modify or extend as needed.

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

In the following example, [setCustomUserAgent()](../reference/apis-arkweb/js-apis-webview.md#setcustomuseragent10) is used to set a custom user agent, which overwrites the default user agent. You are advised to add the extension field to the end of the default user agent.

When **src** of the **Web** component is set to a URL, set **UserAgent** in **onControllerAttached**. For details, see the following example. You are not advised to set **UserAgent** in **onLoadIntercept**. Otherwise, the setting may fail occasionally. When **UserAgent** is not set in **onControllerAttached** and **setCustomUserAgent** is called, the loaded page may be inconsistent with the custom **UserAgent**.

When **src** of the **Web** component is set to an empty string, call **setCustomUserAgent** to set **UserAgent** and then use **loadUrl** to load a specific page.

```ts
// xxx.ets
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

In the following example, [getCustomUserAgent()](../reference/apis-arkweb/js-apis-webview.md#getcustomuseragent10) is used to obtain the custom user agent.

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

## FAQs

### How do I use UserAgent to identify different OpenHarmony devices?

OpenHarmony devices can be identified based on the OS name, OS version, and device type in **UserAgent**. You are advised to check all of them to ensure accurate device identification.

1. Identification based on the OS name

   Use the **{OSName}** field.

   ```ts
   const isOpenHarmony = () => /OpenHarmony/i.test(navigator.userAgent);   
   ```

2. Identification based on the OS version

   Use the **{OSName}** and **{OSVersion}** fields. The format is **OpenHarmony + Version number**.

   ```ts
   const matches = navigator.userAgent.match(/OpenHarmony (\d+\.?\d*)/);  
   matches?.length && Number(matches[1]) >= 5;  
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

### How do I simulate the UserAgent of OpenHarmony for frontend debugging?

In Windows, macOS, and Linux, you can use the **UserAgent** rewriting capability provided by DevTools to simulate the OpenHarmony **UserAgent** in Chrome, Edge, and Firefox.
<!--RP1End-->
