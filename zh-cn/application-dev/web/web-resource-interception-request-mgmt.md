# 自定义页面请求响应


Web组件支持在应用拦截到页面请求后自定义响应请求能力。开发者通过[onInterceptRequest()](../reference/arkui-ts/ts-basic-components-web.md#oninterceptrequest9)接口来实现自定义资源请求响应 。自定义请求能力可以用于开发者自定义Web页面响应、自定义文件资源响应等场景。


Web网页上发起资源加载请求，应用层收到资源请求消息。应用层构造本地资源响应消息发送给Web内核。Web内核解析应用层响应信息，根据此响应信息进行页面资源加载。


在下面的示例中，Web组件通过拦截页面请求“https://www.intercept.com/test.html”， 在应用侧代码构建响应资源，实现自定义页面响应场景。


- 前端页面example.html代码。

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8">
      <title>example</title>
  </head>
  <body>
  <!-- 页面资源请求 -->
  <a href="https://www.intercept.com/test.html">intercept test!</a>
  </body>
  </html>
  ```

- 应用侧代码。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    responseResource: WebResourceResponse = new WebResourceResponse()
    // 开发者自定义响应数据
    @State webData: string = '<!DOCTYPE html>\n' +
    '<html>\n'+
    '<head>\n'+
    '<title>intercept test</title>\n'+
    '</head>\n'+
    '<body>\n'+
    '<h1>intercept ok</h1>\n'+
    '</body>\n'+
    '</html>'
    build() {
      Column() {
        Web({ src: $rawfile('example.html'), controller: this.controller })
          .onInterceptRequest((event) => {
            console.info('url:' + event.request.getRequestUrl());
            // 拦截页面请求
            if (event.request.getRequestUrl() !== 'https://www.intercept.com/test.html') {
              return null;
            }
            // 构造响应数据
            this.responseResource.setResponseData(this.webData);
            this.responseResource.setResponseEncoding('utf-8');
            this.responseResource.setResponseMimeType('text/html');
            this.responseResource.setResponseCode(200);
            this.responseResource.setReasonMessage('OK');
            return this.responseResource;
          })
      }
    }
  }
  ```
