# 定位网页加载问题
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

Web页面加载失败问题复杂多样，本文详细列举常见问题的排查方法，供开发者快速定位。

## 检查权限和网络状态
如果应用未开启联网或文件访问权限或者设备网络状态不佳，将导致Web组件加载失败。
* 确认设备网络状态：检查设备是否连接网络，验证内置浏览器能否正常访问网页（适用于在线页面场景）。
* 添加网络权限：确保应用已声明 ohos.permission.INTERNET 权限（在线页面必需）。

    <!-- @[INTERNET](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebWriteScreenIssue/entry/src/main/module.json5) -->
    
    ``` JSON5
    "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ],
    ```

* 开启相关权限：
    | 名称   | 说明  |
    | ----   | -------------------------------- |
    | [domStorageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#domstorageaccess) | 设置是否开启文档对象模型存储接口（DOM Storage API）权限，若不开启，无法使用localStorage存储数据，任何调用localStorage的代码都将失效，依赖本地存储的功能会异常。 |
    | [fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess) | ‌设置是否开启应用中文件系统的访问。若不开启，文件读写功能完全被阻断，依赖文件的模块会崩溃。 |
    | [imageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#imageaccess) | 设置是否允许自动加载图片资源。 |
    | [onlineImageAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#onlineimageaccess) | 设置是否允许从网络加载图片资源（通过HTTP和HTTPS访问的资源）。 |
    | [javaScriptAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#javascriptaccess) | 设置是否允许执行JavaScript脚本。 |

    <!-- @[OpenPermissions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebWriteScreenIssue/entry/src/main/ets/pages/OpenPermissions.ets) -->
    
    ``` TypeScript
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

## 使用DevTools工具进行页面内容验证
跨域错误、Service Worker请求失败一般会报ERR_FAILED，如果出现ERR_FAILED需要通过[使用DevTools工具调试前端页面](web-debugging-with-devtools.md)定位具体报错类型（跨域、资源404、JS异常）。
1. 检查控制台，确认是否存在因Mixed Content策略或CORS策略导致的异常，或JS错误等。可参考[解决Web组件本地资源跨域问题](web-cross-origin.md)。为了提高安全性，ArkWeb内核禁止file协议和resource协议访问跨域请求。因此，在使用Web组件加载本地离线资源的时候，Web组件会拦截file协议和resource协议的跨域访问。Web组件无法访问本地跨域资源时，DevTools控制台会显示报错信息：
    ```txt
    Access to script at 'xxx' from origin 'xxx' has been blocked by CORS policy: Cross origin requests are only supported for protocol schemes:   http, arkweb, data, chrome-extension, chrome, https, chrome-untrusted.
    ```
   如果确认页面资源是可信的，可以通过以下两种方法规避跨域检查：
  
    **方法一：**

      开发者应使用HTTP或HTTPS协议替代file或resource协议，确保Web组件能够成功访问跨域资源。替代的URL域名应为自定义构造，仅限于个人或组织使用，以防止与互联网上的实际域名冲突。此外，开发者需要利用Web组件的[onInterceptRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#oninterceptrequest9)方法，对本地资源进行拦截和相应替换。

      以下结合示例说明如何使用HTTP或HTTPS等协议解决本地资源跨域访问失败的问题。其中，index.html和js/script.js文件置于工程的rawfile目录下。当使用resource协议访问index.html时，js/script.js文件因跨域而被拦截，无法加载。在示例中，使用https:\//www\.example.com/域名替换了原有的resource协议，同时利用onInterceptRequest接口替换资源，确保js/script.js文件可以成功加载，从而解决跨域拦截问题。
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
            // 针对本地index.html,使用HTTP或HTTPS协议代替file协议或者resource协议，并且构造一个属于自己的域名。
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
    <!DOCTYPE html>
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

    **方法二（解决本地资源跨域问题）：**

    通过[setPathAllowingUniversalAccess](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setpathallowinguniversalaccess12)设置一个路径列表。当使用file协议访问该列表中的资源时，允许进行跨域访问本地文件。此外，一旦设置了路径列表，file协议将仅限于访问列表内的资源（此时，[fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess)的行为将会被此接口行为覆盖）。
    
    setPathAllowingUniversalAccess放开目录的跨域访问限制是一个高风险操作。基于最小权限原则，当前el1、el2放开的路径是固定的，路径列表中的路径应符合以下任一路径格式：

    1. 应用文件目录通过[Context.filesDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#属性)获取，其子目录示例如下：

       * /data/storage/el2/base/files/example
       * /data/storage/el2/base/haps/entry/files/example

    2. 应用资源目录通过[Context.resourceDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#属性)获取，其子目录示例如下：

       * /data/storage/el1/bundle/entry/resources/resfile
       * /data/storage/el1/bundle/entry/resources/resfile/example

    3. 从API version 21开始，还包括了应用缓存目录通过[Context.cacheDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#属性)获取，其子目录示例如下：

       * /data/storage/el2/base/cache
       * /data/storage/el2/base/haps/entry/cache/example
       * 设置的目录路径中，不允许包含cache/web，否则会抛出异常码401。如果设置目录路径是cache，cache/web也不允许访问。

    4. 从API version 21开始，还包括了应用临时目录通过[Context.tempDir](../reference/apis-ability-kit/js-apis-inner-application-context.md#属性)获取，其子目录示例如下：

       * /data/storage/el2/base/temp
       * /data/storage/el2/base/haps/entry/temp/example

    当路径列表中的任一路径不满足上述条件时，系统将抛出异常码401，并判定路径列表设置失败。如果路径列表设置为空，file协议的可访问范围将遵循[fileAccess](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#fileaccess)规则，具体示例如下。

    <!-- @[SetPath](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebWriteScreenIssue/entry2/src/main/ets/pages/SetPath.ets) -->
    
    ``` TypeScript
    import { webview } from '@kit.ArkWeb';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    @Entry
    @Component
    struct WebComponent {
      controller: WebviewController = new webview.WebviewController();
      uiContext: UIContext = this.getUIContext();
    
      build() {
        Row() {
          Web({ src: '', controller: this.controller })
            .onControllerAttached(() => {
              try {
                // 设置允许可以跨域访问的路径列表
                this.controller.setPathAllowingUniversalAccess([
                  this.uiContext.getHostContext()!.resourceDir,
                  this.uiContext.getHostContext()!.filesDir + '/example'
                ])
                this.controller.loadUrl('file://' + this.uiContext.getHostContext()!.resourceDir + '/index.html')
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

    HTML示例代码：
    ```html
    <!-- main/resources/resfile/index.html -->
    <!DOCTYPE html>
    <html lang="en">

    <head>
        <meta charset="utf-8">
        <title>Demo</title>
        <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no, viewport-fit=cover">
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


## 通过回调查看错误信息
查看onErrorReceive、onHttpErrorReceive、onSslErrorEvent、onHttpAuthRequest、onClientAuthenticationRequest等错误上报接口是否有被调用。请根据返回的错误码，对照[网络协议栈错误列表](../reference/apis-arkweb/arkts-apis-netErrorList.md)进行排查。

| 名称   | 说明                                                       |                       
| ----   |----------------------------------------------------------|
| [onErrorReceive](../reference/apis-arkweb/arkts-basic-components-web-events.md#onerrorreceive) | 资源加载失败会上报该回调，比如访问内核不支持的scheme，会报302(UNKNOWN_URL_SCHEME)。 |
| [onHttpErrorReceive](../reference/apis-arkweb/arkts-basic-components-web-events.md#onhttperrorreceive) | 服务器返回HTTP错误码，这类问题通常需要与服务器进行联调。                           | 
| [onHttpAuthRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#onhttpauthrequest9) | 服务器返回407需要端侧提供用户名密码认证，如果不正确处理，可能会导致加载异常、白屏。              | 
| [onClientAuthenticationRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#onclientauthenticationrequest9) | 服务器向端侧请求证书，如果不正确处理，会导致页面加载异常。                            | 
| [onSslErrorEvent](../reference/apis-arkweb/arkts-basic-components-web-events.md#onsslerrorevent12) | 证书错误，需要应用根据证书错误信息进行排查，证书是否配置有误，或证书是否过期。                  | 


## 网页User-Agent适配问题定位
网页加载异常，使用DevTools切换Android或Windows User-Agent后重新加载页面查看是否可以恢复正常。
1. 默认User-Agent：Mozilla/5.0 (Phone;OpenHarmony 6.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/132.0.0.0 Safari/537.36 ArkWeb/6.0.0.42 Mobile。
2. 通过inspect打开网页，查看网络，选择任一请求链接，查看请求标头中的User-Agent信息。
3. 对比应用的自定义User-Agent和ArkWeb默认User-Agent，查看应用自定义User-Agent是否携带OpenHarmony标识。若加载失败时未携带标识，则设置自定义User-Agent携带OpenHarmony标识查看是否能加载成功；若加载失败时携带了OpenHarmony标识，则设置自定义User-Agent携带Android等其他标识查看是否能加载成功，若加载成功则说明第三方网站未适配OpenHarmony，应推动第三方做适配。 如果需要修改User-Agent，去勾选“使用浏览器默认设置”。 选择自定义User-Agent，输入自己的User-Agent即可。
4. 修改[UserAgent](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setcustomuseragent10)后再观察页面是否恢复正常。

 <!-- @[ChangeUserAgent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/WebWriteScreenIssue/entry/src/main/ets/pages/ChangeUserAgent.ets) -->
 
 ``` TypeScript
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
           console.info('onControllerAttached');
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


## Cookie常见问题定位
* 若Cookie的SameSite属性未显式指定，默认值为Lax。此时，Cookie仅在用户直接导航至源站点时发送，不会在跨站请求（如通过第三方链接跳转）中传递。若需允许跨站请求携带Cookie，需将SameSite设置为None，必须同时设置Secure属性，确保Cookie仅通过HTTPS协议加密传输，防止在HTTP明文连接中被窃取或篡改。
* 排查[putAcceptThirdPartyCookieEnabled](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#putacceptthirdpartycookieenabled)是否使能。若未使能，需设置[putAcceptThirdPartyCookieEnabled](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#putacceptthirdpartycookieenabled)为true，使web组件实例允许发送和接收第三方Cookie。Cookie每30s周期性保存到磁盘中，设置Cookie后，30s内退出应用可能会导致Cookie没有及时落盘而丢失。此时可以使用接口[saveCookieAsync](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#savecookieasync)进行强制落盘（PC/2in1和Tablet设备不会持久化session cookie，即使调用saveCookieAsync，也不会将session cookie写入磁盘）。