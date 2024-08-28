# Calculating and Adjusting Safe Area Insets

The **Web** component provides the capability of using the W3C and CSS APIs to calculate and adjust the safe area insets, so that the web page can be properly displayed on a device with an irregular shaped screen in the immersive effect.

## Working Principle

The ArkWeb kernel listens for the locations and sizes of the **Web** component and system safe area, and calculates the appropriate distance from the system safe area and adjusts the safe area insets of the current **Web** component to avoid overlapping.

## When to Use

A safe area refers to the display area that is not covered by a status bar, navigation bar, or any other component in the system non-safe area. All the content you develop is placed in the safe area. When the immersive effect is applied to a **Web** component, elements on the web page may overlap with the status bar or navigation bar.

In this case, you can use this capability to avoid overlapping with web page elements.

### Enabling the Immersive Effect of the Web Component

You can use the [expandSafeArea](../reference/apis-arkui/arkui-ts/ts-universal-attributes-expand-safe-area.md) to enable the immersive effect.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .width('100%').height('100%')
          .expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM])
      }
    }
  }
  ```

### Setting the Layout of a Web Page in a Viewport
Use **viewport-fit** to control the display form of the web page in a safe area. The default value is **auto**, which is the same as **contain**, indicating that the viewport contains all web page content, that is, all web page content is displayed in the safe area. If the value is set to **cover**, the web page content covers the viewport. That is, the web page content may overlap the status bar and navigation bar. In this case, you need to adjust the safe area insets to avoid overlapping with web page elements
```
<meta name='viewport' content='viewport-fit=cover'>
```
### Avoiding Overlapping with Web Page Elements

Pass the variables set by user agent in CSS **env()**, so that you can place your web page content in the safe area of the visible window. The **safe-area-inset-*** set in this function is used to display the complete content in a non-rectangular visible window. The example code is as follows:
```
/* Use four environment variables of safe-area-inset-*. */
env(safe-area-inset-top);
env(safe-area-inset-right);
env(safe-area-inset-bottom);
env(safe-area-inset-left);

/* Use four environment variables of safe-area-inset-* based on fallback.*/
/* For details about the length unit, see https://developer.mozilla.org/zh-CN/docs/Web/CSS/length */.
env(safe-area-inset-top, 20px);
env(safe-area-inset-right, 1em);
env(safe-area-inset-bottom, 0.5vh);
env(safe-area-inset-left, 1.4rem);
```
`safe-area-inset-top`, `safe-area-inset-right`, `safe-area-inset-bottom`, `safe-area-inset-left`
> Each **safe-area-inset-*** consists of one of the four environment variables that define the top, right, bottom, and left of the rectangle in the viewport, which ensures that the content would not be cut by a non-rectangular display. For a rectangular viewport, such as a normal 2in1 device display, the value of each variable is 0. For a non-rectangular display (such as a circular watch face, a mobile device screen), all content is visible within the rectangle specified by four variables, whose value are set by the user agent.

Different from other CSS attributes, the name of attribute defined by the user agent is case sensitive. In addition, **env()** must be used together with **viewport-fit=cover**.

In some shopping websites, fix elements in the tab form are used at the bottom of the home page. In the immersive state, these fix elements need to be avoided at the bottom to prevent the fix elements from overlapping with the system navigation bar. The example code is as follows:
```
.tab-bottom {
    padding-bottom: env(safe-area-inset-bottom);
}
```
In addition, **env()** can be used for calculation based on some mathematical calculation functions such as **calc()**, **min()**, **max()**. The example code is as follows:
```
.tab-bottom {
    padding-bottom: max(env(safe-area-inset-bottom), 30px);
}
```
