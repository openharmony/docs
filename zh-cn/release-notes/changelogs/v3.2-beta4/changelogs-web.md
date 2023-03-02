# web子系统ChangeLog

OpenHarmony 3.2.9.1 sp8版本相较于OpenHarmony 3.2.8.1版本，web的API变更如下

## cl.web.1 删除无用错误码

web子系统webviewController接口存在变更：

 - 去除forward，backward和backOrForward接口的@throws { BusinessError } 17100007 - Invalid back or forward operation.
 - 去除zoom，zoomIn和zoomOut接口的@throws { BusinessError } 17100009 - Cannot zoom in or zoom out.

开发者需要根据以下说明对应用进行适配。


**变更影响**

影响已发布的JS接口，应用无需进行适配即可在新版本SDK环境正常编译通过。

**关键的接口/组件变更**

涉及接口: forward, backward, backOrForward, zoom, zoomIn, zoomOut;
涉及组件: web;

**适配指导**

无需适配
        
## cl.web.2 setWebController入参修改

已发布的部分web子系统controller迁移至webviewController，老的webController做废弃处理。从API9开始做出以下变更：
setWebController入参由老controller替换为新的webviewController

**变更影响**

基于此前版本开发的应用，需适配变更js接口的入参，否则会影响原有功能。

**关键的接口/组件变更**

- 涉及接口

  setWebController(controller: WebviewController): void;

- 变更前：

```js
setWebController(controller: WebController): void;
```

- 变更后：

```js
setWebController(controller: WebviewController): void;
```

**适配指导**

示例代码如下：
变更前：
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

变更后：
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

## cl.web.3 getUnfilterendLinkUrl接口名修改

getUnfilterendLinkUrl接口拼写错误，应改为getUnfilteredLinkUrl

**变更影响**

基于此前版本开发的应用，需适配变更js接口名，否则会影响原有功能。

**关键的接口/组件变更**

- 涉及接口

  getUnfilteredLinkUrl(): string;

- 变更前：

```js
getUnfilterendLinkUrl(): string;
```

- 变更后：

```js
getUnfilteredLinkUrl(): string;
```

**适配指导**

基于此前版本开发的应用，需适配变更js接口名，使用新的接口名替换旧的接口名，否则会影响原有功能。