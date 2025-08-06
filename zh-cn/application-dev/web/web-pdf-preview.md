# 使用Web组件的PDF文档预览能力
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @Yuan_ss-->
<!--SE: @qiu-gongkai-->
<!--TSE: @ghiker-->

Web组件支持在网页中预览PDF。应用通过Web组件的[src](../reference/apis-arkweb/arkts-basic-components-web-i.md#weboptions)参数和[loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl)接口加载PDF文档。具体场景包括：网络PDF文档、应用沙箱内PDF文档和本地PDF文档。

若涉及网络文档获取，需在module.json5中配置网络访问权限。添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md#在配置文件中声明权限)。

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```

## 通过不同的方式加载PDF文档

在下面的示例中，Web组件创建时指定默认加载的网络PDF文档`https://www.example.com/test.pdf`。使用时需替换为真实可访问地址。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ 
      	src: 
      	"https://www.example.com/test.pdf", 					// 方式一 加载网络PDF文档
      	// this.getUIContext().getHostContext()!.filesDir + "/test.pdf", // 方式二 加载本地应用沙箱内PDF文档
      	// "resource://rawfile/test.pdf", 						// 方式三 本地PDF文档 (格式一)
      	// $rawfile('test.pdf'), 								// 方式三 本地PDF文档 (格式二)
      	controller: this.controller 
      })
        .domStorageAccess(true)
    }
  }
}
```

PDF预览页面会根据用户操作使用`window.localStorage`记录侧导航栏的展开状态，因此需要开启文档对象模型存储[domStorageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#domstorageaccess)权限:

  ```
  Web().domStorageAccess(true)
  ```

在创建Web组件时，指定默认加载的PDF文档。默认PDF文档加载完成后，若需变更Web组件显示的PDF文档，通过调用[loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl)接口加载指定的PDF文档。[Web组件](../reference/apis-arkweb/arkts-basic-components-web.md)的第一个参数变量src不能通过状态变量（例如：@State）动态更改地址，如需更改，请通过[loadUrl()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#loadurl)重新加载。

包含三种PDF文档加载预览场景：
- 预览加载网络PDF文档。

  ```ts
  Web({ 
    src: "https://www.example.com/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```
- 预览加载应用沙箱内PDF文档需要开启文件系统的[fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess)权限。

  ```ts
  Web({ 
    src: this.getUIContext().getHostContext()!.filesDir + "/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
    .fileAccess(true)
  ```
- 预览加载本地PDF文档。

  ```ts
  Web({ 
    src: "resource://rawfile/test.pdf",            // 格式一 加载本地PDF文档
    // src: $rawfile('test.pdf'),                  // 格式二 加载本地PDF文档
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```

## 通过配置PDF文件预览参数，控制打开预览时页面状态

当前支持如下参数: 

| 语法		| 描述 |
| --------- | ---------- |
| nameddest=destination 	|  指定PDF文档中的命名目标。 |
| page=pagenum 	| 使用整数指定文档中的页码，文档第一页的pagenum值为1。| 
| zoom=scale    zoom=scale,left,top	| 使用浮点或整数值设置缩放和滚动系数。例如：缩放值100表示缩放值为100%。 向左和向上滚动值位于坐标系中，0,0 表示可见页面的左上角，无论文档如何旋转。 |
| toolbar=1 \| 0 	| 打开或关闭顶部工具栏。 | 
| navpanes=1 \| 0 	| 打开或关闭侧边导航窗格。 | 
| pdfbackgroundcolor=color 	| 指定PDF文档背景色，color为标准的六位十六进制RGB（取值范围为000000~ffffff，例如白色为：ffffff）。 |


URL示例:
```
https://example.com/test.pdf#nameddest=Chapter6  
https://example.com/test.pdf#page=3  
https://example.com/test.pdf#zoom=50  
https://example.com/test.pdf#page=3&zoom=200,250,100  
https://example.com/test.pdf#toolbar=0  
https://example.com/test.pdf#navpanes=0  
https://example.com/test.pdf#pdfbackgroundcolor=ffffff
```

## PDF文档预览回调功能

PDF文档预览支持两种回调功能：加载成功/失败回调和滚动预览到底回调。

在下面的示例中，Web组件创建时指定默认加载的网络PDF文档`https://www.example.com/test.pdf`。使用时需替换为真实可访问地址。

- 加载成功/失败回调。
  ```ts
  Web({ 
    src: 'https://www.example.com/test.pdf',
    controller: this.controller 
  })
    .onPdfLoadEvent(
      (eventInfo: OnPdfLoadEvent) => {
        console.info(`Load event callback called. url: ${eventInfo.url}, result: ${eventInfo.result}.`)
      }
    )
  ```

- 滚动预览到底回调。
  ```ts
  Web({ 
    src: 'https://www.example.com/test.pdf',
    controller: this.controller 
  })
    .onPdfScrollAtBottom(
      (eventInfo: OnPdfScrollEvent) => {
        console.info(`Scroll at bottom callback called. url: ${eventInfo.url}.`)
      }
    ) 
  ```

<!--RP1--><!--RP1End-->