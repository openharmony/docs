# Fitting In the Page Content Layout

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @sinat_22543221-->
<!--Designer: @dzichou-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=ce650f41896ba25021ef970470a55cc36073495b translatedAt=2026-08-14T09:49:14.518Z pushedAt=2026-08-14T09:51:30.576Z -->

When using the adaptive page content layout mode of the **Web** component size, [layoutMode](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#layoutmode11)([WebLayoutMode](../reference/apis-arkweb/arkts-basic-components-web-e.md#weblayoutmode11).FIT_CONTENT), the size of the **Web** component can adapt to the page content.

<!--RP1--><!--RP1End-->

## When to Use

This mode is applicable to the scenario where the **Web** component needs to be expanded based on the web page height and scrolls with other system components. The following are examples:

- Long articles. In this scenario, there are other system components at the same layout level of the **Web** component, such as the comment area and toolbar.

- Home page of a long page. In this scenario, there are other system components at the same layout level of the **Web** component, such as the grid menu.

**System-adaptive web layout**

As shown in Figure 1, the height of the **Web** component is the same as the screen height, and the height of the HTML 5 page is 8000 px, which is greater than the height of the **Web** component. In this case, a scroll bar is displayed in the **Web** component. When the **Web** component is scrolled, a part of the page is hidden, and the screen cannot be fully used to display the web page, resulting in poor user experience, as shown in Figure 2.

| Figure 1 Web layout following the system| Figure 2 Real effect of the web layout|
| --- | --- |
| ![web-fit-content-sample](figures/arkweb-layoutmode-none.png) | ![web-without-fit-content](figures/web-without-fit-content.gif) |

**Content-fitting web layout**

As shown in Figure 3, the height of the **Web** component automatically adapts to the HTML5 page. As shown in the right figure, the height of the **Web** component and the HTML5 page is 8000 px. In this case, no scroll bar is generated in the **Web** component. When a user scrolls the page, other ArkUI components are scrolled at the same time, and the **Web** component is displayed on the entire screen. Figure 4 shows the actual effect.

| Figure 3 Web layout fitting in the page content| Figure 4 Real effect of the web layout|
| --- | --- |
| ![web-fit-content-sample](figures/arkweb-layoutmode-fit-content.png) | ![web-fit-content](figures/web-fit-content.gif) |

## Specifications and Constraints

1. Set the [rendering mode](web-render-mode.md) to [synchronous](web-render-mode.md#synchronous-rendering-mode) to avoid exceptions (white screen and layout errors) caused by the excessive component size.

2. Disable [overScrollMode](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#overscrollmode11). When the overscroll mode is enabled and a user scrolls to the edge of a web page, the **Web** component bounces back with an elastic animation, which conflicts with the rebound of the **Scroll** component and affects the experience.

3. Set [keyboardAvoidMode](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#keyboardavoidmode12) to **RESIZE_CONTENT** to disable this mode.

4. Do not support page zooming.

5. Do not support using the **height** attribute of the **Web** component to change the component height.

6. Support only component height fitting in the page content, but not width fitting.

7. Do not support the waterfall page.

## Sample Code

<!-- @[a_page_that_contains_a_webview_and_text_in_the_comment_section](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebRenderLayout/entry/src/main/ets/pages/FitPageContent.ets) -->

``` TypeScript
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebHeightPage {
  private webviewController: WebviewController = new webview.WebviewController();
  private scroller: Scroller = new Scroller();

  build() {
    Navigation() {
      Column() {
        Scroll(this.scroller) {
          Column() {
            Web({
              src: $rawfile('fit_content.html'),
              controller: this.webviewController,
              renderMode: RenderMode.SYNC_RENDER // Set the synchronous rendering mode.
            })
              .layoutMode (WebLayoutMode.FIT_CONTENT) // Set the Web component size to fit in the page content.
              .overScrollMode (OverScrollMode.NEVER) // Disable the overscroll mode.
            Text('Comments')
              .fontSize(28)
              .fontColor('#FF0F0F')
              .height(100)
              .width('100%')
              .backgroundColor('#f89f0f')
          }
        }
      }
    }
    .title('Title')
  }
}
```

The code for the **fit_content.html** page is as follows:

```html
<!-- fit_content.html -->
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
        <p>ArkWeb provides Web components to display web page content in applications. The common application scenarios are as follows:</p>
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
        <p>The Web component provides various capabilities for controlling web pages, including: </p>
        <ul>
            <li><p>Web page loading: Declarative loading and off-screen loading of web pages. </p></li>
            <li><p>Lifecycle management: Managing the lifecycle of components and notifying web pages of loading status changes. </p></li>
            <li><p>Common attributes and events: User-Agent management, cookie and storage management, font and dark mode management, and permission management. </p>
            </li>
            <li><p>
                Interaction with the application UI: The text selection menu, context menu, and file upload page can be customized to interact with the application UI. </p>
            </li>
            <li><p>Applications can interact with web pages through JavaScriptProxy. </p></li>
            <li><p>Security and privacy: Incognito browsing mode, advertisement blocking, and Advanced Security mode. </p></li>
            <li><p>Maintenance and debugging capability: DevTools debugging and Crashpad (used to collect Web component crash information).
            </p></li>
            <li><p>
                Other advanced capabilities: same-layer rendering with system components, network and media playback takeover, and custom input method for Web component text boxes. </p>
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

## FAQs

### What should I do if the scroll bar still appears in the Web component when FIT_CONTENT is set?

**Possible Causes**

- The height of the internal HTML5 page exceeds 7680 px (physical pixel), but the rendering mode is not set to [synchronous rendering mode](web-render-mode.md#synchronous-rendering-mode).

- The [metaviewport](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#metaviewport12) attribute is not configured.

**Solution**

- Change the rendering mode to [synchronous rendering mode](web-render-mode.md#synchronous-rendering-mode).

- Configure `<meta name="viewport" content="width=device-width, initial-scale=1.0">` on the HTML5 page.

### What should I do if a white screen is displayed or the page disappears after FIT_CONTENT is set?

**Possible Causes**

The height of the DOM node of the core content is 0.

There is a calculation conflict between the CSS style `height: <number> vh` and the adaptive page layout of the **Web** component size. Check whether `height: <number> vh` is the first height CSS style within the body node. In the following structure, the height of the DOM node with the ID 2 will be 0.

```html
<body>
  <div id = "1">
    <div id = "2" style = "height: 100vh">Child DOM</div>
    <div id = "3" style = "height: 20px">Child DOM</div>
  </div>
</body>
```

**Solution**

- Use a specific height style for the child DOM to extend the parent element.

  ```html
  <body>
    <div id = "1">
      <div id = "2"><div style = "height: 20px"></div></div>
      <div id = "3" style = "height: 20px">Child DOM</div>
    </div>
  </body>
  ```

- Use the actual height style for the parent element.

  ```html
  <body>
    <div id = "1">
      <div id = "2" style = "height: 20px">Child DOM</div>
      <div id = "3" style = "height: 20px">Child DOM</div>
    </div>
  </body>
  ```