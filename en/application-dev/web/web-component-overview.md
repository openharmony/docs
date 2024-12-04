# Introduction to ArkWeb

## When to Use

ArkWeb provides **Web** components to display web page content in applications. You can use the components in the following scenarios:
- Web page integration: Applications can use **Web** components to embed web page content to reduce development costs and improve development and operation efficiency. 

- Web browsing: Browser applications can use **Web** components to open third-party web pages, browse web pages in traceless mode, and set advertisement blocking.

- Applet: Host applications of applets can use **Web** components to render the pages of the applets.

## Available Capabilities

The **Web** component provides various capabilities for you to control web pages, including:

- Web page loading: declarative loading and off-screen loading of web pages.

- Lifecycle management: component lifecycle status change and web page loading status change notification.

- Common attributes and events: management of user agent, cookie and storage, font and dark mode, and permission.

- Interaction with the application UI: The custom text selection menu, context menu, and file upload page can interact with the application UI.

- Interaction between applications and web pages through JavaScriptProxy.

- Security and privacy: traceless browsing mode, advertisement blocking, and Secure Shield mode.

- Maintenance and debugging capability: [DevTools](web-debugging-with-devtools.md) for debugging, crashpad for collecting crash information of the **Web** component.

- Other advanced capabilities: same-layer rendering with native components, network and media playback takeover, and custom input method for **Web** component text boxes <!--RP1--><!--RP1End-->.

## Constraints

- **Web** kernel version: ArkWeb is developed based on Chromium M114.

## Samples

The following samples are provided to help you better understand how to develop **Web** components:

- [Using Web Components (ArkTS) (API9)](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/WebCookie)

- [Using Web Components in Developing Lottery Applets (ArkTS) (API9)](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/WebComponent)
