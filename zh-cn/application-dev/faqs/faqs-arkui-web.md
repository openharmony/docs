# Web开发常见问题

## Web组件的onUrlLoadIntercept返回结果是否影响onInterceptRequest

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

Web组件的onUrlLoadIntercept的不同返回结果对应不同的操作：

-   onUrlLoadIntercept返回true则直接拦截URL请求。
-   onUrlLoadIntercept返回false走onInterceptRequest回调。

**参考链接**

[onUrlloadIntercept](../reference/arkui-ts/ts-basic-components-web.md#onurlloadintercept)

## 为什么Web组件的onKeyEvent键盘事件不生效

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

Web组件设置onKeyEvent监听键盘事件，键盘按下或抬起该事件不触发。

**解决措施**

onKeyEvent为通用事件，当前Web组件不支持通用事件。Web组件监听键盘事件可以使用onInterceptKeyEvent回调函数。

**参考链接**

[onInterceptKeyEvent](../reference/arkui-ts/ts-basic-components-web.md#oninterceptkeyevent9)

## onInterceptRequest拦截URL并自定义HTML文件，页面加载失败

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

onInterceptRequest拦截页面Web的src的链接后返回自定义HTML，但是自定义HTML文件里面的script标签里的内容没有加载。

**解决措施**

设置拦截器时，如果只设置setResponseData，内核将无法识别到这是个HTML文件，需要同时设置setResponseEncoding、setResponseMimeType、setResponseHeader等参数。

**代码示例**

```
Web({ src: 'www.example.com', controller: this.controller })
  .onInterceptRequest((event) => {
    console.log('url:' + event.request.getRequestUrl())
    this.responseweb = new WebResourceResponse();
    var head1:Header = {
      headerKey:"Connection",
      headerValue:"keep-alive"
    }
    var length = this.heads.push(head1)
    this.responseweb.setResponseHeader(this.heads)
    this.responseweb.setResponseData(this.webdata)
    this.responseweb.setResponseEncoding('utf-8')
    this.responseweb.setResponseMimeType('text/html')
    this.responseweb.setResponseCode(200)
    this.responseweb.setReasonMessage('OK')
    return this.responseweb
})
```

**参考链接**

[WebResourceResponse](../reference/arkui-ts/ts-basic-components-web.md#webresourceresponse)

## 如何在ArkTS代码中执行HTML内的JS函数

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

通过WebviewController中runJavaScript方法异步执行JavaScript脚本，并通过回调方式获取执行结果。

>**说明：** 
>runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

**参考链接**

[runJavaScript](../reference/apis/js-apis-webview.md#runjavascript)

## 使用Web组件加载本地网页时，如何在本地网页中调用ArkTS中的函数

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

1.  准备一个html文件，例如：

    ```
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Document</title>
    </head>
    <body>
        <h1>标题</h1>
        <h5 id="h5"></h5>
        <h5 id = "h6"></h5>
        <button onclick="handleFromH5">调用Arkts的方法</button>
        <script type="text/javascript">
            function handleFromH5(){
                let result = window.objName.test();
                document.getElementById('h6').innerHTML = result;
            }
        </script>
    </body>
    </html>
    ```

2.  在ArkTs中使用JavaScriptProxy方法将ArkTs里的对象注册到H5的window对象中，然后在h5中使用window对象调用该方法。比如下面例子，在ArkTs中将testObj这个对象以别名objName注册到h5的window对象上，在上面的h5中就可以使用window.objName去访问这个对象。

    ```
    // xxx.ets
    import web_webview from '@ohos.web.webview'
    @Entry
    @Component
    struct Index {
      @State message: string = 'Hello World'
      controller: web_webview.WebviewController = new web_webview.WebviewController()
      testObj = {
        test: (data1, data2, data3) => {
          console.log("data1:" + data1);
          console.log("data2:" + data2);
          console.log("data3:" + data3);
          return "AceString";
        },
        toString: () => {
          console.log('toString' + "interface instead.");
        }
      }
      build() {
        Row() {
          Column() {
            Web({ src:$rawfile('index.html'), controller:this.controller })
              .javaScriptAccess(true)
              .javaScriptProxy({
                object: this.testObj,
                name: "objName",
                methodList: ["test", "toString"],
                controller: this.controller,
             })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```


**参考链接**

[javaScriptProxy](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy)

## Web组件domStorageAccess属性设置

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

设置是否开启文档对象模型存储接口（DOM Storage API）权限，默认未开启，控制web网页中localStorage的使用，对sessionStorage未做控制

**参考链接**

[domStorageAccess](../reference/arkui-ts/ts-basic-components-web.md#domstorageaccess)
