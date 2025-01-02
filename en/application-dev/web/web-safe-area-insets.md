# Calculating and Adjusting Safe Area Insets

## Overview
Safe area is the display area of the page, which is not overlapped with the non-safe area (such as the status bar and navigation bar) set by the system by default. This ensures that the application UI is displayed in the safe area. However, when the immersive mode is enabled for the **Web** component, the web page element may overlap with the status bar or navigation bar. As shown in figure 1, the area delimited by the red dotted box is the safe area, and the top status bar, notch area, and bottom navigation bar are defined as non-secure area. When the immersive effect is enabled for the **Web** component, the bottom element in the web page overlaps with the navigation bar.

**Figure 1** Elements at the bottom of a web page overlap with the navigation bar when the immersive effect is enabled for the **Web** component

![web-safe-area](figures/arkweb_safearea2.png)

The **Web** component provides the capability of using W3C CSS to calculate and adjust the safe area insets, so that the web page can be properly displayed on a device with an irregular shaped screen in the immersive mode. You can use this capability to avoid overlapping with page elements. The ArkWeb kernel continuously monitors the locations and sizes of the **Web** component and system safe area, and calculates the safe area for the current **Web** component and the proper distance to avoid in each direction based on the overlapping area.

## Scenario

### Enabling the Immersive Mode for the Web Component

You can use [expandSafeArea](../reference/apis-arkui/arkui-ts/ts-universal-attributes-expand-safe-area.md) to enable the immersive mode.

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

### Setting the Layout of the Web Page in a Viewport

Use **viewport-fit** to control the display of a web page in the safe area. The default value is **auto**, which is the same as **contain**, indicating that the viewport contains all web page content, that is, all web page content is displayed in the safe area. If the value is set to **cover**, the web page content covers the viewport. That is, the web page content may overlap the status bar and navigation bar. In this case, you need to adjust the safe area insets to avoid overlapping with web page elements

```
<meta name='viewport' content='viewport-fit=cover'>
```
### Avoiding Overlapping with Web Page Elements

To avoid overlapping with web page elements, you need to pass the variables defined by user code to the CSS function **env()**, so that the content can be placed in the safe area of the viewport. The **safe-area-inset-*** value defined in the specification ensures that the content can be completely displayed even in a non-rectangular screen. The syntax is as follows:
```
/* Use safe-area-inset-* to set the distance to keep in the upper, right, bottom, and left directions. */
env(safe-area-inset-top);
env(safe-area-inset-right);
env(safe-area-inset-bottom);
env(safe-area-inset-left);

/* Based on fallback, use safe-area-inset-* to set the distance in four directions. */
/* For details about the length unit, see https://developer.mozilla.org/en-US/docs/Web/CSS/length */.
env(safe-area-inset-top, 20px);
env(safe-area-inset-right, 1em);
env(safe-area-inset-bottom, 0.5vh);
env(safe-area-inset-left, 1.4rem);
```

>  **NOTE**
>
> **safe-area-inset-*** consists of four environment variables, which define the top, right, bottom, and left of the rectangle in the edge of the visible window. This ensures that the content can be placed safely and is not cut off by the non-rectangular display area. In a rectangular viewport (such as the display of a 2-in-1 device), the values of these variables are zero. For a non-rectangular display (such as a circular watch face and a mobile device screen), all content is displayed in a rectangular area formed by the four values set by the user agent.

Different from other CSS attributes, the name of attribute defined by the user agent is case sensitive. In addition, **env()** must be used together with **viewport-fit=cover**.

In some shopping websites, absolute elements in the tab form are used at the bottom of the home page. These absolute elements need to be avoided in the immersive mode to prevent them from overlapping with the system navigation bar, as shown in Figure 2.
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

**Figure 2** Elements at the bottom of the web page avoiding the navigation bar when the immersive mode is enabled for the **Web** component

![web-safe-area](figures/arkweb_safearea1.png)
