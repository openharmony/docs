#  Web Subsystem Changelog

Compared with earlier versions, OpenHarmony 4.0.7.3 has the following API changes in its web subsystem:

## cl.web.1 New Input Parameter Type of the setResponseData API

Added the input parameter type **Resource** for the **setResponseData** API.

**Change Impact**

In the scenario where a HAP file is not decompressed, the file path in the HAP does not exist. Under this scenario, to access resources in the HAP file, you must use the input parameter **data:Resource** instead of **data:number**.

**Key API/Component Changes**

- Involved APIs:

  setResponseData

- Before change: 

  ```
  setResponseData(data: string | number)
  ```

- After change:

  ```
  setResponseData(data: string | number | Resource)
  ```

**Adaptation Guide**

When a HAP file is decompressed, open the hold the FD of the target resource file, and then transfer the resource response data to the kernel through **setResponseData(data:number)**.

```
// xxx.ets
import web_webview from '@ohos.web.webview'
import fileio from '@ohos.fileio';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController()
  responseweb: WebResourceResponse = new WebResourceResponse()
  heads: Header[] = new Array()

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .onInterceptRequest((event) => {
          console.log('url:' + event.request.getRequestUrl())
          var head1:Header = {
            headerKey:"Connection",
            headerValue:"keep-alive"
          }
          var head2:Header = {
            headerKey:"Cache-Control",
            headerValue:"no-cache"
          }
          var length = this.heads.push(head1)
          length = this.heads.push(head2)
          this.responseweb.setResponseHeader(this.heads)
          this.responseweb.setResponseEncoding('utf-8')
          this.responseweb.setResponseMimeType('text/html')
          this.responseweb.setResponseCode(200)
          this.responseweb.setReasonMessage('OK')

          //// fd scheme --start
          // '/xxx/.../test.html' is the local path of the file.
          // @ts-ignore
          let fd = fileio.openSync('/xxx/.../test.html', 0o102, 0o666)
          this.responseweb.setResponseData(fd)
          //// fd scheme --end

          return this.responseweb
        })
    }
  }
}
```

When a HAP file is decompressed, the file path in the HAP does not exist. In this case, transfer the resource response data to the kernel through **setResponseData(data:Resource)**.

```
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController()
  responseweb: WebResourceResponse = new WebResourceResponse()
  heads: Header[] = new Array()

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .onInterceptRequest((event) => {
          console.log('url:' + event.request.getRequestUrl())
          var head1:Header = {
            headerKey:"Connection",
            headerValue:"keep-alive"
          }
          var head2:Header = {
            headerKey:"Cache-Control",
            headerValue:"no-cache"
          }
          var length = this.heads.push(head1)
          length = this.heads.push(head2)
          this.responseweb.setResponseHeader(this.heads)
          this.responseweb.setResponseEncoding('utf-8')
          this.responseweb.setResponseMimeType('text/html')
          this.responseweb.setResponseCode(200)
          this.responseweb.setReasonMessage('OK')
          
          //// Resource scheme --start
          // Specify the target file in the rawfile directory of the HAP file.
          this.responseweb.setResponseData($rawfile('test.html'))
          //// Resource scheme --end

          return this.responseweb
        })
    }
  }
}
```
