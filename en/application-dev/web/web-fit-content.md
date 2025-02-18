# Fitting In the Page Content Layout

When **layoutMode(WebLayoutMode.FIT_CONTENT)** is used, the size of the **Web** component can automatically fit in the page content.

This mode is applicable to the scenario where the **Web** component needs to be expanded based on the web page height and scrolls with other native components. For example:

- Browsing long articles. In this case, there are other native components at the same layout level of the **Web** component, such as the comment area and toolbar.
- Home page of a long page. In this case, there are other native components at the same layout level of the **Web** component, such as the grid menu.

## Specifications and Constraints

1. Set the [rendering mode](web-render-mode.md) to synchronous to avoid exceptions (white screen and layout errors) caused by the component size exceeding the limit.
2. Disable the [overscroll mode](../reference/apis-arkweb/ts-basic-components-web.md#overscrollmode11). When the overscroll mode is enabled and a user slides to the edge of a web page, the web page is displayed with a spring animation, which conflicts with the rebound effect of the **Scroll** component, affecting user experience.
3. Set the attribute of [keyboard avoidance mode](../reference/apis-arkweb/ts-basic-components-web.md#keyboardavoidmode12) to **RESIZE_CONTENT** to disable this mode.
4. Do not support page zooming.
5. Do not support using the **height** attribute of the **Web** component to change the component height.
6. Support only component height fitting in the page content, but not width fitting.

## When to Use

```typescript
// fit_content_test.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebHeightPage {
  private webviewController: WebviewController = new webview.WebviewController()
  private scroller: Scroller = new Scroller()

  build() {
    Navigation() {
      Column() {
        Scroll(this.scroller) {
          Column() {
            Web({
              src: $rawfile("fit_content.html"),
              controller: this.webviewController,
              renderMode: RenderMode.SYNC_RENDER // Set the synchronous rendering mode.
            })
              .layoutMode (WebLayoutMode.FIT_CONTENT) // Set the Web component size to fit in the page content.
              .overScrollMode (OverScrollMode.NEVER) // Disable the overscroll mode.
            Text('Comments')
              .fontSize(28)
              .fontColor("#FF0F0F")
              .height(100)
              .width("100%")
              .backgroundColor("#f89f0f")
          }
        }

      }
    }
    .title ("Title bar")
  }
}
```

```html
<!--fit_content.html-->
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no">
    <title>Fit-Content</title>
</head>
<body>
<div>
    <div><h2 id="When to use">When to use</h2>
        <p>ArkWeb provides Web components to display web page content in applications. The common application scenarios are as follows:</p>;
        <ul>
            <li><p>
                Web page integration: Applications can use Web components to embed web page content to reduce development costs and improve development and operation efficiency.</p> 
            </li>
            <li><p>
                Web browsing: Browser applications can use Web components to open third-party web pages, browse web pages in traceless mode, and set advertisement blocking.</p>
            </li>
            <li><p>Applet: Host applications of the applet type can use web components to render applet pages. </p></li>
        </ul>
    </div>
    <div><h2 id="Capabilities">Capabilities</h2>
        <p>The Web component provides various capabilities for controlling web pages, including: </p>;
        <ul>
            <li><p>Web page loading: Declarative loading and off-screen loading of web pages. </p></li>
            <li><p>Lifecycle management: Managing the lifecycle of components and notifying web pages of loading status changes. </p></li>
            <li><p>Common attributes and events: UserAgent management, cookie and storage management, font and dark mode management, and permission management. </p>
            </li>
            <li><p>
                Interaction with the application UI: The text selection menu, context menu, and file upload page can be customized to interact with the application UI. </p>
            </li>
            <li><p>Applications can interact with web pages through JavaScriptProxy. </p></li>
            <li><p>Security and privacy: Incognito browsing mode, advertisement blocking, and Advanced Security mode. </p></li>
            <li><p>Maintenance and debugging capability: DevTools debugging and Crashpad (used to collect Web component crash information).
            </p></li>
            <li><p>
                Other advanced capabilities: same-layer rendering with native components, network and media playback takeover, and custom input method for Web component text boxes. </p>
            </li>
        </ul>
    </div>
    <div><h2 id="Constraints">Constraints</h2>
        <ul>
            <li>Web kernel version: ArkWeb is developed based on Chromium M114.</li>
        </ul>
    </div>
</div>
</body>
</html>
```



