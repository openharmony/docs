# Web Development

## How does the return result of onUrlLoadIntercept affect onInterceptRequest in the \<Web> component?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

The operation that follows **onUrlLoadIntercept** is subject to its return result.

-   If **true** is returned, the URL request is intercepted.
-   If **false** is returned , the **onInterceptRequest** callback is performed.

**Reference**

[onUrlloadIntercept](../reference/arkui-ts/ts-basic-components-web.md#onurlloadinterceptdeprecated)

## What should I do if the onKeyEvent event of the \<Web> component is not triggered as expected?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Problem**

The **onKeyEvent** event is set for the **\<Web>** component to listen for keyboard events. However, it is not triggered when a key is pressed or lifted.

**Solution**

Currently, the **\<Web>** component does not support the **onKeyEvent** event. To listen for keyboard events for the **\<Web>** component, you can use the **onInterceptKeyEvent** callback function.

**Reference**

[onInterceptKeyEvent](../reference/arkui-ts/ts-basic-components-web.md#oninterceptkeyevent9)

## What should I do if page loading fails when onInterceptRequest is used to intercept URLs and return the custom HTML file?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Problem**

The **onInterceptRequest** API intercepts URLs specified by **src** and returns the custom HTML file. However, the content in the **script** tag in the HTML file is not loaded.

**Solution**

If only **setResponseData** is set for the interceptor, the kernel cannot identify the HTML file. You must also set parameters such as **setResponseEncoding**, **setResponseMimeType**, and **setResponseHeader** for the kernel to identify the HTML file.

**Example**

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

**Reference**

[WebResourceResponse](../reference/arkui-ts/ts-basic-components-web.md#webresourceresponse)

## How do I execute JS functions in HTML in ArkTS code?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Use the **runJavaScript** API in **WebviewController** to asynchronously execute JavaScript scripts and obtain the execution result in a callback.

>**NOTE**
>
>**runJavaScript** can be invoked only after l**oadUrl** is executed. For example, it can be invoked in **onPageEnd**.

**Reference**

[runJavaScript](../reference/apis/js-apis-webview.md#runjavascript)

## How do I invoke an ArkTS method on a local web page loaded in the \<Web> component?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

1.  Prepare an HTML file. Below is the sample code:

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
        <h1>Title</h1>
        <h5 id="h5"></h5>
        <h5 id = "h6"></h5>
        <button onclick="handleFromH5">Invoke ArkTS method </button>
        <script type="text/javascript">
            function handleFromH5(){
                let result = window.objName.test();
                document.getElementById('h6').innerHTML = result;
            }
        </script>
    </body>
    </html>
    ```

2.  Use the **JavaScriptProxy** API in ArkTs to register the object in ArkTS with the window object of H5, and then use the window object to call the method in H5. In the following example, the **testObj** object in ArkTS is registered with the window object of H5 with the alias **objName**. In H5, **window.objName** can then be used to access the object.

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


**Reference**

[javaScriptProxy](../reference/arkui-ts/ts-basic-components-web.md#javascriptproxy)

## How do I set the domStorageAccess attribute of the \<Web> component?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

The **domStorageAccess** attribute sets whether to enable the DOM Storage API. By default, this feature is disabled.

**Reference**

[domStorageAccess](../reference/arkui-ts/ts-basic-components-web.md#domstorageaccess)

## What should I do if the network status fails to be detected on the HTML page loaded by the \<Web> component?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Problem**

When **window.navigator.onLine** is used on the HTML page to obtain the network status, the value is **false** no matter the network connection is set up or not.

**Solution**

Configure the permission for the application to obtain network information: **ohos.permission.GET\_NETWORK\_INFO**.

**Reference**

[GET\_NETWORK\_INFO](../security/permission-list.md#ohospermissionget_network_info)

## How do I set the UserAgent parameter through string concatenation?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

By default, the value of **UserAgent** needs to be obtained through the WebviewController. Specifically, it is obtained by calling the **getUserAgent** API in a **WebviewController** object after it is bound to the **\<Web>** component. Therefore, to set **UserAgent** through string concatenation before page loading:

1.  Use @State to define the initial **UserAgent** parameter and bind it to the **\<Web>** component.
2.  In the **onUrlLoadIntercept** callback of the **\<Web>** component, use **WebviewController.getUserAgent\(\)** to obtain the default **UserAgent** value and update the UserAgent bound to the **\<Web>** component.

**Example**

```
import web_webview from '@ohos.web.webview'
@Entry
@Component
struct Index {
  private controller: web_webview.WebviewController = new web_webview.WebviewController()
  @State userAgentPa: string = ''
  build() {
    Row() {
      Column() {
        Web({ src: 'http://www.example.com', controller: this.controller }) // Replace the URL with the actual URL.
          .width('100%')
          .userAgent(this.userAgentPa)
          .onUrlLoadIntercept((event) => {
            let userAgent = this.controller.getUserAgent();
            this.userAgentPa = userAgent + ' 111111111'
            return false;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

**Reference**

[userAgent](../reference/arkui-ts/ts-basic-components-web.md#useragentdeprecated), [getUserAgent](../reference/apis/js-apis-webview.md#getuseragent)

## How do I enable the \<Web> component to return to the previous web page following a swipe gesture?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

Override the **onBackPress** API to define the return logic and use **WebviewController** to determine whether to return to the previous web page.

**Example**

```
import web_webview from '@ohos.web.webview';
@Entry
@Component
struct Index {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Web({ src: 'http://www.example.com', controller: this.controller })// Replace the URL with the actual URL.
    }
  }
  onBackPress() {
    // Check whether a specific number of steps forward or backward can be performed on the current page. A positive number indicates forward, and a negative number indicates backward.
    if (this.controller.accessStep(-1)) {
      this.controller.backward(); // Return to the previous web page.
      // Execute the custom return logic.
      return true
    } else {
      // Execute the default return logic to return to the previous page.
      return false
    }
  }
}
```

**Reference**

[accessStep](../reference/apis/js-apis-webview.md#accessstep)
