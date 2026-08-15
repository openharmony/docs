# About This Kit

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @kurli1-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=214dbbb9f70f3bd6331e1162daebb110a88ce31d translatedAt=2026-08-14T03:44:05.235Z pushedAt=2026-08-14T07:22:32.974Z -->

## When to Use

ArkWeb provides **Web** components to display web page content in apps. You can use the components in the following scenarios:

- Web page integration: Apps can use **Web** components to embed web page content to reduce development costs and improve development and O&M efficiency.

- Web browsing: Browser apps can use **Web** components to open third-party web pages, browse web pages in traceless mode, and set advertisement blocking.

- Applet: Host applications of applets can use **Web** components to render the pages of the applets, implement same-layer rendering, and take over video playback.

## Available Capabilities

The **Web** component provides various capabilities for you to control web pages, including:

- Web page loading: declarative loading and off-screen loading of web pages.

- Lifecycle management: component lifecycle status change and web page loading status change notification.

- Common attributes and events: [User-Agent development guide](./web-default-userAgent.md), [cookie and data storage management](./web-cookie-and-data-storage-mgmt.md), fonts and [Web dark mode adaptation](./web-set-dark-mode.md), permission management, and more.

- Interaction with the application UI: The custom text selection menu, context menu, and file upload page can interact with the application UI.

- Apps interact with web pages through JavaScriptProxy.

- Security and privacy: traceless browsing mode, advertisement blocking, and Secure Shield mode.

- Maintenance and debugging capability: [DevTools](web-debugging-with-devtools.md) for debugging, crashpad for collecting crash information of the Web component, <!--RP2--><!--RP2End-->and troubleshooting white screen issues on web pages.

- Other advanced capabilities: same-layer rendering with system components, network and media playback takeovers, <!--RP1--><!--RP1End-->and custom input method for **Web** component text boxes.

## Required Permissions

To access online web pages through the **Web** component, you must add the network permission ohos.permission.INTERNET. For details about how to request the permission, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

  ```ts
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```

## Constraints

- You can obtain the support for W3C standards based on the ArkWeb kernel version at related websites. For example, https://developer.mozilla.org/en-US/ and https://webassembly.org/features/.

- Web kernel version: ArkWeb is developed based on the Google Chromium kernel. The following table lists the mapping between the system version and the Chromium version.

  | System Version | Chromium Version |
  | --- | --- |
  | OpenHarmony 4.0 and earlier | M99 |
  | OpenHarmony 4.1-5.1 | M114 |
  | OpenHarmony 6.0 | M132 (default, recommended; see [M114->M132 Migration Guide](https://gitcode.com/openharmony-tpc/chromium_src/blob/master/web/ReleaseNote/ArkWeb_114_132.md))<br>M114 (optional; if your app needs to switch to this kernel, see [M114 Kernel Adaptation Guide on OpenHarmony 6.0](https://gitcode.com/openharmony-tpc/chromium_src/blob/master/web/ReleaseNote/CompatibleWithLegacyWebEngine_6.0.md)) |
  | OpenHarmony 6.1 | M132 |
  | OpenHarmony 7.0 | M144 (default, recommended; see [M132->M144 Migration Guide](https://gitcode.com/openharmony-tpc/chromium_src/blob/master/web/ReleaseNote/ArkWeb_132_144.md))<br>M132 (optional; if your app needs to switch to this kernel, see [M132 Kernel Adaptation Guide on OpenHarmony 7.0](https://gitcode.com/openharmony-tpc/chromium_src/blob/master/web/ReleaseNote/CompatibleWithLegacyWebEngine_7.0.md)) |

<!--RP3--><!--RP3End-->

<!--RP4--><!--RP4End-->

## Samples

The following samples are provided to help you better understand how to develop **Web** components:

- [Using Web Components (ArkTS) (API9)](https://gitcode.com/openharmony/codelabs/tree/master/ETSUI/WebCookie)

- [Using Web Components to Develop Lottery Applets (ArkTS) (API9)](https://gitcode.com/openharmony/codelabs/tree/master/ETSUI/WebComponent)