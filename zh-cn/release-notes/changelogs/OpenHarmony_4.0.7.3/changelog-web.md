# web子系统ChangeLog

OpenHarmony 4.0.7.3 版本相较于OpenHarmony 之前的版本，web的API变更如下。

## cl.web.1 setResponseData接口参数新增

**变更影响**

setResponseData(data: string | number | Resource)，新增入参类型`Resource`

在应用hap不解压场景，应用hap中的文件路径已不存在。当需要读取hap包内资源时，通过使用入参`data:Resource`替代`data:number`，实现对本应用下的资源访问。


**关键的接口/组件变更**

- 涉及接口

  setResponseData

- 变更前：

  ```ts
  setResponseData(data: string | number)
  ```

- 变更后：

  ```ts
  setResponseData(data: string | number | Resource)
  ```

**适配指导**

应用hap解压时，打开并持有资源文件fd，最后通过`setResponseData(data:number)`将资源响应数据传递给内核。

```ts
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

          //// fd方案 --start
          // '/xxx/.../test.html'为文件的本地路径
          // @ts-ignore
          let fd = fileio.openSync('/xxx/.../test.html', 0o102, 0o666)
          this.responseweb.setResponseData(fd)
          //// fd方案 --end

          return this.responseweb
        })
    }
  }
}
```

应用hap不解压时，应用hap中的文件路径已不存在，通过`setResponseData(data:Resource)`将资源响应数据传递给内核。
```ts
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
          
          //// Resource方案 --start
          // 指定hap包中rawfile目录下的目标文件
          this.responseweb.setResponseData($rawfile('test.html'))
          //// Resource方案 --end

          return this.responseweb
        })
    }
  }
}
```
