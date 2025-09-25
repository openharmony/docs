# Lifecycle
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @mayaolll-->
<!--Designer: @jiangdayuan-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

## Application Lifecycle

You can define the following application lifecycle functions in the app.js file.

  | Attribute | Type | Description | Called When | 
| -------- | -------- | -------- | -------- |
| onCreate | () => void | Listens for application creation. | The application is created. |
| onShow<sup>6+</sup> | () => void | Listens for whether the application is running in the foreground. | The application is running in the foreground. | 
| onHide<sup>6+</sup> | () => void | Listens for whether the application is running in the background. | The application is running in the background. | 
| onDestroy | () => void | Listens for application uninstallation. | The application exits. | 

## Page Lifecycle

You can define the following page lifecycle functions in the .js file of the page.

| Attribute | Type | Description | Called When |
| -------- | -------- | -------- | -------- |
| onInit | () => void | Listens for page initialization. | Page initialization is complete. This function is called only once in the page lifecycle. |
| onReady | () => void | Listens for page creation. | A page is created. This function is called only once in the page lifecycle. |
| onShow | () => void | Listens for page display. | The page is displayed. |
| onHide | () => void | Listens for page disappearance. | The page disappears. |
| onDestroy | () => void | Listens for page destruction. | The page is destroyed. |
| onBackPress | () => boolean | Listens for the back button action. | The back button is touched.<br/>- true means that the page processes the return logic.<br/>- false means that the default return logic is used.<br/>- If no value is returned, the default return logic is used. |
| onActive()<sup>5+</sup> | () => void | Listens for page activation. | The page is activated. |
| onInactive()<sup>5+</sup> | () => void | Listens for page suspension. | The page is suspended. |
| onNewRequest()<sup>5+</sup> | () => void | Listens for a new FA request. | The FA has been started and a new request is received. |

 The lifecycle functions of page A are called in the following sequence:
- Open page A: onInit() -> onReady() -> onShow()

- Open page B on page A: onHide()

- Go back to page A from page B: onShow()

- Exit page A: onBackPress() -> onHide() -> onDestroy()

- Hide page A: onInactive() -> onHide()

- Show background page A on the foreground: onShow() -> onActive()

![en-us_image_0000001267887881](figures/en-us_image_0000001267887881.png)

