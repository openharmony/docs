# Customizing Page Request Responses


The **Web** component supports customization of the response to intercepted page requests. You can call [onInterceptRequest()](../reference/arkui-ts/ts-basic-components-web.md#oninterceptrequest9) to customize web page responses, file resource responses, etc.  


When a resource loading request is initiated on a web page, the application layer will receive the request. The application layer then constructs a local resource response and sends it to the web kernel. On receiving the response, the web kernel parses the response and loads page resources accordingly.


In the following example, the **Web** component intercepts the web page request **https://www.intercept.com/test.html** and constructs a custom response in the application code.


- Code of the **example.html** page:

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8">
      <title>example</title>
  </head>
  <body>
  <!-- Page resource request ->
  <a href="https://www.intercept.com/test.html">intercept test!</a>
  </body>
  </html>
  ```

- Application code:

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    responseweb: WebResourceResponse = new WebResourceResponse()
    heads:Header[] = new Array()
    @State webdata: string = "<!DOCTYPE html>\n" +
    "<html>\n"+
    "<head>\n"+
    "<title>intercept test</title>\n"+
    "</head>\n"+
    "<body>\n"+
    "<h1>intercept test</h1>\n"+
    "</body>\n"+
    "</html>"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onInterceptRequest((event) => {
            if (event) {
              console.log('url:' + event.request.getRequestUrl())
            }
            let head1:Header = {
              headerKey:"Connection",
              headerValue:"keep-alive"
            }
            let head2:Header = {
              headerKey:"Cache-Control",
              headerValue:"no-cache"
            }
            let length = this.heads.push(head1)
            length = this.heads.push(head2)
            this.responseweb.setResponseHeader(this.heads)
            this.responseweb.setResponseData(this.webdata)
            this.responseweb.setResponseEncoding('utf-8')
            this.responseweb.setResponseMimeType('text/html')
            this.responseweb.setResponseCode(200)
            this.responseweb.setReasonMessage('OK')
            return this.responseweb
          })
      }
    }
  }
  ```
