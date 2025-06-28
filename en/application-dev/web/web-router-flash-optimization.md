# Optimizing the Page Flash During the Redirection
When an application uses a router such as the **Navigation** component to navigate to a **Web** component page, the bottom of the page may flash during web page loading, which affects user experience.

## Causes

When a router such as the **Navigation** component is used to navigate to a **Web** component page, the application determines whether to hide the native navigation bar on the application side based on the callback notification of the web page. If it decides to hide the native navigation bar, the layout of the **Web** component is adjusted accordingly. The layout adjustment process can be simplified into the following four phases:
![web-router-flash-optimization.png](figures/web-router-flash-optimization.png)
Description of the four phases in the figure (from left to right):

1. The application is routed to the web page. The top of the page is the native navigation bar, and the bottom is the **Web** component. In this case, the web page can be loaded properly.

2. During web page loading, the system invokes a callback to notify the application to hide the native navigation bar and switch to the navigation bar on the web page. In this case, the native navigation bar is hidden, and the layout of the **Web** component is adjusted accordingly. The background color of the **Web** component is initially displayed at the bottom of the page. Assume that the background color is gray.

3. The web page continues to be loaded and displayed based on the new size. The background color of the HTML web page is presented first, which is assumed to be white.

4. Finally, the web page content is completely loaded, and the complete HTML web page content is displayed.

In the preceding process, if the background color of the **Web** component is different from that of the web page, there is a possibility that the **Web** component flashes during the redirection. The flash probability depends on the complexity of the web page and network conditions.

## Optimization

Set the background color of the **Web** component to be the same as the background color of the web page to avoid visual flash and improve user experience. For example, you can set the background color of the **Web** component to white, as shown in the preceding figure.

In similar cases, for example, when the default background color of the **Web** component is white, if the background color of the web page is gray, the web page may flash white when the application navigates to a new web page. To solve this problem, set the background color of the **Web** component to gray.

Example of setting the background color of the **Web** component to gray (the default background color is white):
  ```ts
      Web({ src: $rawfile('xxx.html'),  controller: this.webController})
        .backgroundColor(Color.Gray)
  ```
