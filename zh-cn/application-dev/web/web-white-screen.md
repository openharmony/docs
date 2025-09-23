# 定位与解决Web白屏问题
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc-->
<!--Designer: @LongLie-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

Web页面出现白屏的原因众多，本文列举了若干常见白屏问题的排查步骤，供开发者快速定位。

1. 首先排查权限和网络状态。
2. 通过[使用DevTools工具调试前端页面](web-debugging-with-devtools.md)定位具体报错类型（跨域、资源404、JS异常）。
3. 在复杂布局场景中，排查渲染模式及组件约束条件的问题。
4. 处理H5代码兼容性问题。
5. 从日志中排查生命周期和网络加载相关关键字。

## 检查权限和网络状态
如果应用未开启联网或文件访问权限或者设备网络状态不佳，将导致Web组件加载失败或页面元素缺失，进而引起白屏。
* 验证设备的网络状态，包括是否已连接网络，设备自带的浏览器能否正常访问网页等（在线页面场景）。
* 确保应用已添加网络权限：ohos.permission.INTERNET（在线页面必需）。
  ```
  // 在module.json5中添加相关权限
  "requestPermissions":[
     {
        "name" : "ohos.permission.INTERNET"
     }
  ]
  ```
* 开启相关权限：
    | 名称   | 说明  |                       
    | ----   | -------------------------------- |
    | [domStorageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#domstorageaccess) | DOM Storage API权限，若不开启，无法使用localStorage存储数据，任何调用localStorage的代码都将失效，依赖本地存储的功能会异常。 |
    | [fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess) | ‌若不开启，文件读写功能完全被阻断，依赖文件的模块会崩溃。 | 
    | [imageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#imageaccess) | 设置是否允许自动加载图片资源。 | 
    | [onlineImageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#onlineimageaccess) | 设置是否允许从网络加载图片资源（通过HTTP和HTTPS访问的资源）。 |
    | [javaScriptAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#javascriptaccess) | 设置是否允许执行JavaScript脚本。 | 


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
          .domStorageAccess(true)
          .fileAccess(true)
          .imageAccess(true)
          .onlineImageAccess(true)
          .javaScriptAccess(true)
      }
    }
  }
  ```
* 修改[UserAgent](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setcustomuseragent10)后再观察页面是否恢复正常。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State customUserAgent: string = ' DemoApp';

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
        .onControllerAttached(() => {
          console.info("onControllerAttached");
          try {
            let userAgent = this.controller.getUserAgent() + this.customUserAgent;
            this.controller.setCustomUserAgent(userAgent);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      }
    }
  }
  ```
## 使用DevTools工具进行页面内容验证
在确保网络与权限配置无误后，若仍出现白屏，则应利用DevTools工具调试前端页面以及监听Web相关错误上报接口，来定位具体报错类型。

1. 查阅控制台的错误信息，定位具体的资源加载失败问题。资源加载失败会导致页面元素缺失，布局紊乱，图片和动画效果失效等，严重时可能导致渲染进程崩溃，页面呈现空白。如图所示，依次排查：<br>
  （1）元素是否完整，html元素、结构是否正确。<br> （2）控制台是否有报错。<br>（3）网络里面是否有资源加载时间特别长等。<br>
   ![web-white-devtools](figures/web-white-devtools.PNG)

2. 检查控制台，确认是否存在因MixedContent策略或CORS策略导致的异常，或JS错误等。可参考[解决Web组件本地资源跨域问题](web-cross-origin.md)。为了提高安全性，ArkWeb内核禁止file协议和resource协议访问跨域请求。因此，在使用Web组件加载本地离线资源的时候，Web组件会拦截file协议和resource协议的跨域访问。Web组件无法访问本地跨域资源时，DevTools控制台会显示报错信息：
    ```
    Access to script at 'xxx' from origin 'xxx' has been blocked by CORS policy: Cross origin requests are only supported for protocol schemes:   http, arkweb, data, chrome-extension, chrome, https, chrome-untrusted.
    ```
    有如下两种解决方法：
  
    方法一：

      开发者应使用http或https协议替代file或resource协议，确保Web组件能够成功访问跨域资源。替代的URL域名应为自定义构造，仅限于个人或组织使用，以防止与互联网上的实际域名冲突。此外，开发者需要利用Web组件的[onInterceptRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#oninterceptrequest9)方法，对本地资源进行拦截和相应替换。

      以下结合示例说明如何使用http或者https等协议解决本地资源跨域访问失败的问题。其中，index.html和js/script.js文件置于工程的rawfile目录下。当使用resource协议访问index.html时，js/script.js文件因跨域而被拦截，无法加载。在示例中，使用https:\//www\.example.com/域名替换了原有的resource协议，同时利用onInterceptRequest接口替换资源，确保js/script.js文件可以成功加载，从而解决跨域拦截问题。
    ```ts
    // main/ets/pages/Index.ets
    import { webview } from '@kit.ArkWeb';

    @Entry
    @Component
    struct Index {
      @State message: string = 'Hello World';
      webviewController: webview.WebviewController = new webview.WebviewController();
      // 构造域名和本地文件的映射表
      schemeMap = new Map([
        ["https://www.example.com/index.html", "index.html"],
        ["https://www.example.com/js/script.js", "js/script.js"],
      ])
      // 构造本地文件和构造返回的格式mimeType
      mimeTypeMap = new Map([
        ["index.html", 'text/html'],
        ["js/script.js", "text/javascript"]
      ])

      build() {
        Row() {
          Column() {
            // 针对本地index.html,使用http或者https协议代替file协议或者resource协议，并且构造一个属于自己的域名。
            // 本例中构造www.example.com为例。
            Web({ src: "https://www.example.com/index.html", controller: this.webviewController })
              .javaScriptAccess(true)
              .fileAccess(true)
              .domStorageAccess(true)
              .geolocationAccess(true)
              .width("100%")
              .height("100%")
              .onInterceptRequest((event) => {
                if (!event) {
                  return;
                }
                // 此处匹配自己想要加载的本地离线资源，进行资源拦截替换，绕过跨域
                if (this.schemeMap.has(event.request.getRequestUrl())) {
                  let rawfileName: string = this.schemeMap.get(event.request.getRequestUrl())!;
                  let mimeType = this.mimeTypeMap.get(rawfileName);
                  if (typeof mimeType === 'string') {
                    let response = new WebResourceResponse();
                    // 构造响应数据，如果本地文件在rawfile下，可以通过如下方式设置
                    response.setResponseData($rawfile(rawfileName));
                    response.setResponseEncoding('utf-8');
                    response.setResponseMimeType(mimeType);
                    response.setResponseCode(200);
                    response.setReasonMessage('OK');
                    response.setResponseIsReady(true);
                    return response;
                  }
                }
                return null;
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```

    ```html
    <!-- main/resources/rawfile/index.html -->
    <html>
    <head>
  	  <meta name="viewport" content="width=device-width,initial-scale=1">
    </head>
    <body>
    <script crossorigin src="./js/script.js"></script>
    </body>
    </html>
    ```

    ```js
    // main/resources/rawfile/js/script.js
    const body = document.body;
    const element = document.createElement('div');
    element.textContent = 'success';
    body.appendChild(element);
    ```

    方法二：

    通过[setPathAllowingUniversalAccess](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setpathallowinguniversalaccess12)设置一个路径列表。当使用file协议访问该列表中的资源时，允许进行跨域访问本地文件。此外，一旦设置了路径列表，file协议将仅限于访问列表内的资源(此时，[fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess)的行为将会被此接口行为覆盖)。路径列表中的路径应符合以下任一路径格式：

    1.应用文件目录通过[Context.filesDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context)获取，其子目录示例如下：

    * /data/storage/el2/base/files/example
    * /data/storage/el2/base/haps/entry/files/example

    2.应用资源目录通过[Context.resourceDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context)获取，其子目录示例如下：

    * /data/storage/el1/bundle/entry/resource/resfile
    * /data/storage/el1/bundle/entry/resource/resfile/example

    3.从API version 21开始，还包括了应用缓存目录通过[Context.cacheDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context)获取，其子目录示例如下：

    * /data/storage/el2/base/cache
    * /data/storage/el2/base/haps/entry/cache/example
    * 设置的目录路径中，不允许包含cache/web，否则会抛出异常码401。如果设置目录路径是cache，cache/web也不允许访问。

    4.从API version 21开始，还包括了应用临时目录通过[Context.tempDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context)获取，其子目录示例如下：

    * /data/storage/el2/base/temp
    * /data/storage/el2/base/haps/entry/temp/example

    当路径列表中的任一路径不满足上述条件时，系统将抛出异常码401，并判定路径列表设置失败。如果路径列表设置为空，file协议的可访问范围将遵循[fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess)规则，具体示例如下。

    ```ts
    // main/ets/pages/Index.ets
    import { webview } from '@kit.ArkWeb';
    import { BusinessError } from '@kit.BasicServicesKit';

    @Entry
    @Component
    struct WebComponent {
      controller: WebviewController = new webview.WebviewController();
      uiContext: UIContext = this.getUIContext();

      build() {
        Row() {
          Web({ src: "", controller: this.controller })
            .onControllerAttached(() => {
              try {
                // 设置允许可以跨域访问的路径列表
                this.controller.setPathAllowingUniversalAccess([
                  this.uiContext.getHostContext()!.resourceDir,
                  this.uiContext.getHostContext()!.filesDir + "/example"
                ])
                this.controller.loadUrl("file://" + this.uiContext.getHostContext()!.resourceDir + "/index.html")
              } catch (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
              }
            })
            .javaScriptAccess(true)
            .fileAccess(true)
            .domStorageAccess(true)
        }
      }
    }
    ```

    ```html
    <!-- main/resources/resfile/index.html -->
    <!DOCTYPE html>
    <html lang="en">

    <head>
        <meta charset="utf-8">
        <title>Demo</title>
        <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no,   viewport-fit=cover">
        <script>
  		  function getFile() {
  			  var file = "file:///data/storage/el1/bundle/entry/resources/resfile/js/script.js";
          // 使用file协议通过XMLHttpRequest跨域访问本地js文件。
  			  var xmlHttpReq = new XMLHttpRequest();
  			  xmlHttpReq.onreadystatechange = function(){
  			      console.info("readyState:" + xmlHttpReq.readyState);
  			      console.info("status:" + xmlHttpReq.status);
  				  if(xmlHttpReq.readyState == 4){
  				      if (xmlHttpReq.status == 200) {
                    // 如果ets侧正确设置路径列表，则此处能正常获取资源
  				          const element = document.getElementById('text');
                            element.textContent = "load " + file + " success";
  				      } else {
                    // 如果ets侧不设置路径列表，则此处会触发CORS跨域检查错误
  				          const element = document.getElementById('text');
                            element.textContent = "load " + file + " failed";
  				      }
  				  }
  			  }
  			  xmlHttpReq.open("GET", file);
  			  xmlHttpReq.send(null);
  		  }
        </script>
    </head>

    <body>
    <div class="page">
        <button id="example" onclick="getFile()">loadFile</button>
    </div>
    <div id="text"></div>
    </body>

    </html>
    ```

    ```javascript
    // main/resources/resfile/js/script.js
    const body = document.body;
    const element = document.createElement('div');
    element.textContent = 'success';
    body.appendChild(element);
    ```

3. 查看onErrorReceive、onHttpErrorReceive、onSslErrorEvent、onHttpAuthRequest、onClientAuthenticationRequest等错误上报接口是否有被调用。请根据返回的错误码，对照[网络协议栈错误列表](../reference/apis-arkweb/arkts-apis-netErrorList.md)进行排查。

    | 名称   | 说明  |                       
    | ----   | -------------------------------- |
    | [onErrorReceive](../reference/apis-arkweb/arkts-basic-components-web-events.md#onerrorreceive) | 资源加载失败会上报该回调，比如访问内核不支持的scheme， 会报302(UNKNOWN_URL_SCHEME)。 |
    | [onHttpErrorReceive](../reference/apis-arkweb/arkts-basic-components-web-events.md#onhttperrorreceive) | 服务器返回HTTP错误码，这类问题一般需要跟服务器进行联调。 | 
    | [onHttpAuthRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#onhttpauthrequest9) | 服务器返回407需要端侧提供用户名密码认证，如果不正确处理，可能会导致加载异常、白屏。 | 
    | [onClientAuthenticationRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#onclientauthenticationrequest9) | 服务器向端侧请求证书，如果不正确处理，会导致页面加载异常。 | 
    | [onSslErrorEvent](../reference/apis-arkweb/arkts-basic-components-web-events.md#onsslerrorevent12) | 证书错误，需要应用根据证书错误信息进行排查，是证书配错了？还是过期了。 | 


## 复杂的布局与渲染模式导致白屏
若页面使用了复杂布局或渲染模式，需注意其应用场景和约束条件，不当使用可能导致布局混乱或白屏。
Web组件提供了两种渲染模式，能够根据不同的容器大小进行适配，从而满足使用场景中对容器尺寸的需求，详情见[Web组件渲染模式](web-render-mode.md)。在使用过程中需要注意以下几点：
- 异步渲染模式下（renderMode: [RenderMode](../reference/apis-arkweb/arkts-basic-components-web-e.md#rendermode12).ASYNC_RENDER），Web组件的宽高不能超过7,680px（物理像素），超过会导致白屏。

Web组件提供了自适应页面布局的能力，详情见[ Web组件大小自适应页面内容布局](web-fit-content.md)，使用时也需要注意以下约束条件：
- 配置同步渲染模式：`webSetting({renderingMode: WebRenderingMode.SYNCHRONOUS})`。
- 关闭滚动效果：`webSetting({overScrollMode: OverScrollMode.NEVER})`。
- 此模式下不支持动态调整组件高度，确保页面高度固定。
- 避免在FIT_CONTENT模式下启用键盘避让属性RESIZE_CONTENT，以免导致布局失效。
- css样式`height：<number> vh`和Web组件大小自适应页面布局存在计算冲突，请检查`height：<number> vh`是否是由body节点而内的第一个高度css样式。如以下结构，id为2的dom节点高度将为0，导致白屏。

  ```
  <body>
    <div id = "1">
      <div id = "2" style = "height: 100vh">子dom</div>
      <div id = "3" style = "height: 20px">子dom</div>
    </div>
  </body>
  ```
  解决此白屏问题的参考方案如下：
  - 子dom使用具体高度样式撑开父元素。
    ```
    <body>
      <div id = "1">
        <div id = "2"><div style = "height: 20px"><div/></div>
        <div id = "3" style = "height: 20px">子dom</div>
      </div>
    </body>
    ```
  - 父元素使用实际高度样式。
    ```
    <body>
      <div id = "1">
        <div id = "2" style = "height: 20px">子dom</div>
        <div id = "3" style = "height: 20px">子dom</div>
      </div>
    </body>
    ```

## 处理H5代码兼容性
兼容性问题处理不当也会导致页面白屏。
* 特殊协议拦截。
* 若H5页面调用tel:、mailto:等协议导致白屏，需通过onInterceptRequest拦截并调用系统拨号能力：
   ```c
   .onInterceptRequest((event) => {
       if (event.request.url.startsWith('tel:')) {
           // 调用系统拨号能力
           call.makeCall({ phoneNumber: '123456' });
           return { responseCode: 404 }; // 阻止默认行为
       }
       return null;  
   })
   ```
## 监控内存与生命周期
内存达到阈值会导致渲染进程被终止，从而引发白屏现象；同样，渲染进程创建失败或非正常销毁也会导致白屏。可从日志中排查原因。检查Web组件是否与WebController正确绑定，或是否因过早释放导致白屏。关注日志中与Render进程相关的信息：是否存在内存泄漏使渲染内存不足。关键字“MEMORY_PRESSURE_LEVEL_CRITICAL”表明内存已达到阈值，此情形下Web可能遭遇黑屏、花屏或闪屏等异常状况，需排查是否存在内存泄漏问题。Render进程是否成功启动或异常退出。

下面列举一些日志中的关键字和对应的情况说明：

| 日志关键字   | 说明  |                       
| ----   | -------------------------------- |
| StartRenderProcess failed | 渲染render进程启动失败。 |
| MEMORY_PRESSURE_LEVEL_CRITICAL | 整机内存压力达到阈值，继续使用可能造成黑屏、闪屏白屏等问题。 |
| crashpad SandboxedHandler::HandlerCrash, received signo = xxx | 渲染render进程crash，会造成白屏、Web组件卡死等问题。 |
| SharedContextState context lost via Skia OOM | 共享内存不足，会导致应用闪退、花屏卡死等问题。
| CreateNativeViewGLSurfaceEGLOhos::normal surface | 创建egl surface成功，如果没有该日志打印则会造成白屏问题。|
| INFO: request had no response within 5 seconds | 网络超时。 |
| final url: ***, error_code xxx(net::ERR_XXX) | 主资源加载报错。|

下面说明一下Web组件网络加载过程中的关键日志，正常情况下一个Web组件的加载过程应该包含这些关键节点：
![web-white-page-load](figures/web-white-page-load.PNG)

| 日志关键字   | 说明  |                       
| ----   | -------------------------------- |
| NWebRenderMain start  | 子进程启动。 |
| RendererMain startup 、<br> render thread init | 子进程初始化开始。 |
| event_message: WillProcessNavigationResponse source_id xxx navigation_handle id: xxx| 收到主资源的response。 |
| event_message: commit navigation in main frame, routing_id: 4, url: *** | Commit到子进程。
| RenderFrameImpl::CommitNavigation、<br> event_message: page load start | 子进程收到commit。|
| NWebHandlerDelegate::OnNavigationEntryCommitted、<br> event_message: Commit source_id xxx | 主进程收到DidCommitNavigation。|
| event_message: load_timing_info errpr_code:0,...| 主资源加载完成，以及各阶段耗时。|
| event_message: MarkFirstContentfulPaint| 标记解析到有可显示内容的元素。|
| NWebHandlerDelegate::OnPageVisible| 第一帧展示。|
| NWebHandlerDelegate::OnFirstContentfulPaint| 第一帧有内容展示。|
| event_message: content load finished | 页面解析完成。|
| event_message: page load finished、<br> NWebHandlerDelegate::OnLoadEnd、<br> NWebHandlerDelegate::MainFrame OnLoadEnd、<br> NWebHandlerDelegate::OnFirstMeaningfulPaint | 页面以及子资源加载完成。|

