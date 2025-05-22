# 使用Web组件的PDF文档预览能力

Web组件提供了在网页中预览PDF的能力。应用通过Web组件的[src](../reference/apis-arkweb/ts-basic-components-web.md#web)参数和[loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl)接口加载PDF文档。根据PDF文档来源分为四种场景：网络PDF文档、应用沙箱内PDF文档、应用内resource资源PDF文档和本地PDF文档。

若涉及网络文档获取，需在module.json5中配置网络访问权限，添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md)。

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```


在下面的示例中，Web组件创建时指定默认加载的网络PDF文档 `www.example.com/test.pdf`，该地址为示例，使用时需替换为真实可访问地址:

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
      	// "resource://rawfile/test.pdf", 						// 方式三 应用内resource资源PDF文档
      	// $rawfile('test.pdf'), 								// 方式四 本地PDF文档
      	controller: this.controller 
      })
        .domStorageAccess(true)
    }
  }
}
```

由于PDF预览页面会根据用户操作使用`window.localStorage`记录侧导航栏的展开状态，因此需要开启文档对象模型存储[domStorageAccess](../reference/apis-arkweb/ts-basic-components-web.md#domstorageaccess)权限:

  ```
  Web().domStorageAccess(true)
  ```

在Web组件创建时，指定默认加载的PDF文档。在默认PDF文档加载完成后，如果需要变更此Web组件显示的PDF文档，可以通过调用[loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl)接口加载指定的PDF文档。[Web组件](../reference/apis-arkweb/ts-basic-components-web.md#web)的第一个参数变量src不能通过状态变量（例如：@State）动态更改地址，如需更改，请通过[loadUrl()](../reference/apis-arkweb/js-apis-webview.md#loadurl)重新加载。

包含四种PDF文档加载预览场景:
- 预览加载网络PDF文档。

  ```ts
  Web({ 
    src: "https://www.example.com/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```
- 预览加载应用沙箱内PDF文档，需要开启应用中文件系统的访问[fileAccess](../reference/apis-arkweb/ts-basic-components-web.md#fileaccess)权限。

  ```ts
  Web({ 
    src: this.getUIContext().getHostContext()!.filesDir + "/test.pdf",
    controller: this.controller 
  })
    .domStorageAccess(true)
    .fileAccess(true)
  ```
- 预览加载应用内PDF资源文档

  ```ts
  Web({ 
    src: "resource://rawfile/test.pdf", // 或 $rawfile('test.pdf')
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```
- 预览加载本地PDF文档，`$rawfile('test.pdf')`形式无法指定下面介绍的预览参数。

  ```ts
  Web({ 
    src: $rawfile('test.pdf'),
    controller: this.controller 
  })
    .domStorageAccess(true)
  ```

此外，通过配置PDF文件预览参数，可以控制打开预览时页面状态。

当前支持如下参数: 

| 语法		| 描述 |
| --------- | ---------- |
| nameddest=destination 	|  指定PDF文档中的命名目标。 |
| page=pagenum 	| 使用整数指定文档中的页码，文档第一页的pagenum值为1。| 
| zoom=scale    zoom=scale,left,top	| 使用浮点或整数值设置缩放和滚动系数。例如：缩放值100表示缩放值为100%。 向左和向上滚动值位于坐标系中，0,0 表示可见页面的左上角，无论文档如何旋转。 |
| toolbar=1 \| 0 	| 打开或关闭顶部工具栏。 | 
| navpanes=1 \| 0 	| 打开或关闭侧边导航窗格。 | 


URL示例:  
```
https://example.com/test.pdf#Chapter6  
https://example.com/test.pdf#page=3  
https://example.com/test.pdf#zoom=50  
https://example.com/test.pdf#page=3&zoom=200,250,100  
https://example.com/test.pdf#toolbar=0  
https://example.com/test.pdf#navpanes=0  
```
<!--RP1--><!--RP1End-->