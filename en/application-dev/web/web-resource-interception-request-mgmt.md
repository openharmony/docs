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
  import web_webview from '@ohos.web.webview';

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    responseResource: WebResourceResponse = new WebResourceResponse()
    // Customize a response.
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
            // Intercept the web page request.
            if (event.request.getRequestUrl() !== 'https://www.intercept.com/test.html') {
              return null;
            }
            // Construct a custom response.
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
