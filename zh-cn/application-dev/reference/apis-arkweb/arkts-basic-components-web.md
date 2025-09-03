# 组件描述
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

提供具有网页显示能力的Web组件，[@ohos.web.webview](arkts-apis-webview.md)提供Web控制能力。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

该模块提供以下Web组件网页显示相关的常用功能：

- [ClientAuthenticationHandler](./arkts-basic-components-web-ClientAuthenticationHandler.md)：客户端证书请求事件。
- [ConsoleMessage](./arkts-basic-components-web-ConsoleMessage.md)：控制台信息。
- [ControllerHandler](./arkts-basic-components-web-ControllerHandler.md)：新建Web组件的WebviewController对象。
- [DataResubmissionHandler](./arkts-basic-components-web-DataResubmissionHandler.md)：表单数据操作对象。
- [EventResult](./arkts-basic-components-web-EventResult.md)：同层事件消费结果。
- [FileSelectorParam](./arkts-basic-components-web-FileSelectorParam.md)：Web组件获取文件对象。
- [FileSelectorResult](./arkts-basic-components-web-FileSelectorResult.md)：Web组件文件选择结果。
- [FullScreenExitHandler](./arkts-basic-components-web-FullScreenExitHandler.md)：Web组件退出全屏的操作对象。
- [HttpAuthHandler](./arkts-basic-components-web-HttpAuthHandler.md)：HttpAuth认证请求相关操作功能对象。
- [JsGeolocation](./arkts-basic-components-web-JsGeolocation.md)：地理位置信息权限功能。
- [JsResult](./arkts-basic-components-web-JsResult.md)：弹窗操作。
- [PermissionRequest](./arkts-basic-components-web-PermissionRequest.md)：权限请求。
- [ScreenCaptureHandler](./arkts-basic-components-web-ScreenCaptureHandler.md)：屏幕捕获相关权限操作。
- [SslErrorHandler](./arkts-basic-components-web-SslErrorHandler.md)：SSL错误事件操作功能。
- [WebContextMenuParam](./arkts-basic-components-web-WebContextMenuParam.md)：长按或鼠标右键弹出菜单信息。
- [WebContextMenuResult](./arkts-basic-components-web-WebContextMenuResult.md)：控制长按或鼠标右键弹出菜单。
- [WebCookie](./arkts-basic-components-web-WebCookie.md)：当前应用中Web组件的Cookie管理操作。
- [WebKeyboardController](./arkts-basic-components-web-WebKeyboardController.md)：控制自定义键盘。
- [WebResourceError](./arkts-basic-components-web-WebResourceError.md)：资源管理错误。
- [WebResourceRequest](./arkts-basic-components-web-WebResourceRequest.md)：资源获取请求。
- [WebResourceResponse](./arkts-basic-components-web-WebResourceResponse.md)：资源获取响应。

## 需要权限

访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

## 子组件

无

## 接口

Web(value: WebOptions)

> **说明：**
>
> 不支持转场动画。
>
> 同一页面的多个Web组件，必须绑定不同的WebviewController。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型                                     | 必填   | 说明                                     |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| value        | [WebOptions](./arkts-basic-components-web-i.md#weboptions)   | 是    | 定义Web选项。 |

**示例：**

加载在线网页。

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
      }
    }
  }
  ```

隐私模式Webview加载在线网页。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

Web组件同步渲染模式。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, renderMode: RenderMode.SYNC_RENDER })
      }
    }
  }
  ```

Web组件指定共享渲染进程。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller1: webview.WebviewController = new webview.WebviewController();
    controller2: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller1, sharedRenderProcessToken: "111" })
        Web({ src: 'www.w3.org', controller: this.controller2, sharedRenderProcessToken: "111" })
      }
    }
  }
  ```

加载本地网页。

通过$rawfile方式加载。
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 通过$rawfile加载本地资源文件。
        Web({ src: $rawfile("index.html"), controller: this.controller })
      }
    }
  }
  ```

通过resources协议加载，适用Webview加载带有"#"路由的链接。

使用 `resource://rawfile/` 协议前缀可以避免常规 `$rawfile` 方式在处理带有"#"路由链接时的局限性。当URL中包含"#"号时，"#"后面的内容会被视为锚点（fragment）。
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 通过resource协议加载本地资源文件。
        Web({ src: "resource://rawfile/index.html#home", controller: this.controller })
      }
    }
  }
  ```

在“src\main\resources\rawfile”文件夹下创建index.html：
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<body>
<div id="content"></div>

<script>
	function loadContent() {
	  var hash = window.location.hash;
	  var contentDiv = document.getElementById('content');

	  if (hash === '#home') {
		contentDiv.innerHTML = '<h1>Home Page</h1><p>Welcome to the Home Page!</p>';
	  } else {
		contentDiv.innerHTML = '<h1>Default Page</h1><p>This is the default content.</p>';
	  }
	}

	// 加载界面
	window.addEventListener('load', loadContent);

	// 当hash变化时，更新界面
	window.addEventListener('hashchange', loadContent);
</script>
</body>
</html>
```

加载沙箱路径下的本地资源文件，需要开启应用中文件系统的访问[fileAccess](./arkts-basic-components-web-attributes.md#fileaccess)权限。

1. 通过构造的单例对象GlobalContext获取沙箱路径。

   ```ts
   // GlobalContext.ets
   export class GlobalContext {
     private constructor() {}
     private static instance: GlobalContext;
     private _objects = new Map<string, Object>();

     public static getContext(): GlobalContext {
       if (!GlobalContext.instance) {
         GlobalContext.instance = new GlobalContext();
       }
       return GlobalContext.instance;
     }

     getObject(value: string): Object | undefined {
       return this._objects.get(value);
     }

     setObject(key: string, objectClass: Object): void {
       this._objects.set(key, objectClass);
     }
   }
   ```

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   let url = 'file://' + GlobalContext.getContext().getObject("filesDir") + '/index.html';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController();

     build() {
       Column() {
         // 加载沙箱路径文件。
         Web({ src: url, controller: this.controller })
         .fileAccess(true)
       }
     }
   }
   ```

2. 修改EntryAbility.ets。

   以filesDir为例，获取沙箱路径。若想获取其他路径，请参考[应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。

   ```ts
   // xxx.ets
   import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
       // 通过在GlobalContext对象上绑定filesDir，可以实现UIAbility组件与UI之间的数据同步。
       GlobalContext.getContext().setObject("filesDir", this.context.filesDir);
       console.log("Sandbox path is " + GlobalContext.getContext().getObject("filesDir"));
     }
   }
   ```

   加载的html文件。

   ```html
   <!-- index.html -->
   <!DOCTYPE html>
   <html>
       <body>
           <p>Hello World</p>
       </body>
   </html>
   ```