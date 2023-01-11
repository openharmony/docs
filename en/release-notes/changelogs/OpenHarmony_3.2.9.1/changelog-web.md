# Web Subsystem ChangeLog

This document describes the web API changes in OpenHarmony 3.2.9.1 SP8 when compared with OpenHarmony 3.2.8.1.

## cl.web.1 Deletion of Unnecessary Error Codes

APIs in the webviewController component of the web subsystem are changed:

 - Deleted **@throws { BusinessError } 17100007 - Invalid back or forward operation** from the **forward**, **backward**, and **backOrForward** APIs.
 - Deleted **@throws { BusinessError } 17100009 - Cannot zoom in or zoom out** from the **zoom**, **zoomIn**, and **zoomOut** APIs.

You need to adapt your application based on the following information.

**Change Impacts**

Released JS APIs are affected. The application can be properly compiled in the SDK environment of the new version, without any adaptation.

**Key API/Component Changes**

Involved APIs: **forward**, **backward**, **backOrForward**, **zoom**, **zoomIn**, and **zoomOut**
Involved component: web

**Adaptation Guide**

No adaptation is required.        
## cl.web.2 setWebController Input Parameter Changes

Some released web controllers are migrated to the webviewController, and the original webController is deprecated. The following changes are made in API version 9 and later:
The input parameter of **setWebController** is replaced by the new **webviewController**.

**Change Impacts**

Input parameters of JS APIs need to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.

**Key API/Component Changes**

- Involved API:

  setWebController(controller: WebviewController): void;

- Before change:

```js
setWebController(controller: WebController): void;
```

- After change:

```js
setWebController(controller: WebviewController): void;
```

**Adaptation Guide**

The sample code is as follows:

Before change:

```js
// xxx.ets
@Entry
@Component
struct WebComponent {
  controller:WebController = new WebController()
  build() {
    Column() {
      Web({ src:'www.example.com', controller: this.controller })
      .multiWindowAccess(true)
      .onWindowNew((event) => {
        console.log("onWindowNew...")
        var popController: WebController = new WebController()
        event.handler.setWebController(popController)
      })
    }
  }
}
```

After change:
```js
// xxx.ets
@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController()
  build() {
    Column() {
      Web({ src:'www.example.com', controller: this.controller })
      .multiWindowAccess(true)
      .onWindowNew((event) => {
        console.log("onWindowNew...")
        var popController: web_webview.WebviewController = new web_webview.WebviewController()
        event.handler.setWebController(popController)
      })
    }
  }
}
```

## cl.web.3 getUnfilterendLinkUrl API Name Change

The **getUnfilterendLinkUrl** API is misspelled and should be changed to **getUnfilteredLinkUrl**.

**Change Impacts**

The JS API name needs to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.

**Key API/Component Changes**

- Involved API:

  getUnfilteredLinkUrl(): string;

- Before change:

```js
getUnfilterendLinkUrl(): string;
```

- After change:

```js
getUnfilteredLinkUrl(): string;
```

**Adaptation Guide**

The JS API name needs to be adapted for applications developed based on earlier versions. The new API name is used to replace the original one. Otherwise, relevant functions will be affected.
