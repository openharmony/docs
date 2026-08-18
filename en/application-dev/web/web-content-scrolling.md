# Implementing Content Scrolling

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=d866e238748ac7aac315cd2cec8b8c1b4d92d6a3 translatedAt=2026-08-14T03:43:13.386Z pushedAt=2026-08-14T07:25:00.728Z -->

A web page can scroll only when its content height or width exceeds the visible area. Web page scrolling can be performed in several ways, including using external devices, calling ArkTS side interfaces, and calling JS side interfaces.

## Using External Devices

You can control web page scrolling through the touchscreen, touchpad, and mouse wheel in the following ways.

+ Through the touchscreen, you can swipe up, down, left, or right with a single finger to scroll the web page.

+ Through the touchpad, you can swipe up, down, left, or right on the laptop to scroll the web page.

+ Control web page scrolling through the mouse wheel: you can scroll up and down with the mouse wheel to control page scrolling.

## Calling ArkTS APIs

+ [scrollTo](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#scrollto): scrolls the page to a specified absolute position within a specified period.

  Return to the top of the page.

  <!-- @[scrollTo_ArkTS_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebScrollDemo/entry/src/main/ets/pages/WebScrollDemo.ets) -->

  ``` TypeScript
  this.webController.scrollTo(0, 0);
  ```

+ [scrollBy](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#scrollby): scrolls the page by a specified offset within a specified period.

  This API can be used to control the scrolling of **Web** components in nested scrolling. For details, see [Distributing Scrolling Offsets Through the Parent Scroll Component](web-nested-scrolling.md#distributing-scrolling-offsets-through-the-parent-scroll-component)

+ [pageUp](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#pageup): scrolls up the Web component content by half of the viewport or jumps to the top of the page, controlled by the `top` input parameter.

+ [pageDown](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#pagedown): scrolls down the Web component content by half of the viewport or jumps to the bottom of the page, controlled by the `bottom` input parameter.

## Calling JS APIs

+ **scrollBy**: scrolls by a certain distance relative to the current position (a positive number is downward/rightward, and a negative number is upward/leftward).

  ```javascript
  window.scrollBy(deltaX, deltaY);// deltaX is the distance to scroll the element along the horizontal axis, and deltaY is the distance to scroll the element along the vertical axis.
  ```

  Progressive scrolling (such as the **Read more** button).

  ```javascript
  document.getElementById("read-more").addEventListener("click", ()=>{
    window.scrollBy(0, 300);
  })
  ```

+ **scrollTo**: scrolls the page to the absolute coordinate position.

  ```javascript
  window.scrollTo(x, y);// x is the horizontal coordinate (in pixels) of the upper-left corner of the window after scrolling, and y is the vertical coordinate (in pixels) of the upper-left corner of the window after scrolling.
  ```

  (1) Return to the top of the page.

  ```javascript
  window.scrollTo(0, 0);
  ```

  (2) Jump to a specific position on the page.

  ```javascript
  window.scrollTo(0, 500); // Scroll to a fixed pixel position (for example, 500px).
  ```

## Scrolling to the Top by Tapping the Status Bar

When the web page is not at the top or is being flung downward, you can use the [backToTop](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#backtotop22) method to return to the top of the web page. After it is enabled, tapping the status bar interrupts the fling and scrolls the web page to the top.

+ The sample code is as follows:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .backToTop(true)
      }
    }
  }
  ```

The loaded HTML file:

  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
      <meta name="viewport" id="viewport" content="width=device-width, initial-scale=1.0">
      <style>
          .blue {
            background-color: lightblue;
          }
          .green {
            background-color: lightgreen;
          }
          .blue, .green {
           font-size:16px;
           height:200px;
           text-align: center;       /* Horizontally centered */
           line-height: 200px;       /* Vertically centered (the height matches the container height) */
          }
      </style>
  </head>
  <body>
  <div class="blue" >webArea</div>
  <div class="green">webArea</div>
  <div class="blue">webArea</div>
  <div class="green">webArea</div>
  <div class="blue">webArea</div>
  <div class="green">webArea</div>
  <div class="blue">webArea</div>
  <div class="green">webArea</div>
  <div class="blue">webArea</div>
  </body>
  </html>
  ```

+ Effect<br>

![backToTop](figures/backToTop.gif)