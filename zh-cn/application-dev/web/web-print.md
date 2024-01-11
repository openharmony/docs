# 打印能力

Web组件打印html页面时可通过W3C标准协议接口和应用接口两种方式实现。开发者在使用该能力时，需配置[ohos.permission.PRINT](../security/AccessToken/declare-permissions.md)打印权限。

## 使用W3C标准协议接口拉起打印
通过创建打印适配器，拉起打印应用，并对当前Web页面内容进行渲染，渲染后生成的PDF文件信息通过fd传递给打印框架。W3C标准协议接口window.print()方法用于打印当前页面或弹出打印对话框。该方法没有任何参数，只需要在JavaScript中调用即可。

可通过前端css样式控制是否打印，例如@media print。再通过web加载该html页面的方式运行。

- print.html页面代码。

  ```html
  <!DOCTYPE html>
  <html>

  <head>
      <meta charset="utf-8">
      <title>printTest</title>
      <style>
          @media print {
              h1 {
                  display: none;
              }
          }
      </style>
  </head>

  <body>
      <div>
          <h1><b>
                  <center>This is a test page for printing</center>
              </b>
              <hr color=#00cc00 width=95%>
          </h1>
          <button class="Button Button--outline" onclick="window.print();">Print</button>
          <p> content content content </p>
          <div id="printableTable">
              <table>
                  <thead>
                      <tr>
                          <td>Thing</td>
                          <td>Chairs</td>
                      </tr>
                  </thead>
                  <tbody>
                      <tr>
                          <td>1</td>
                          <td>blue</td>
                      </tr>
                      <tr>
                          <td>2</td>
                          <td>green</td>
                      </tr>
                  </tbody>
              </table>
          </div>
          <p> content content content </p>
          <p> content content content </p>
      </div>
  </body>
  ```

- 应用侧代码。

  ```ts
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct Index {

    controller: web_webview.WebviewController = new web_webview.WebviewController();

    build() {
      Row() {
        Column() {
          Web({ src: $rawfile("print.html"), controller: this.controller })
            .javaScriptAccess(true)
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

## 通过调用应用侧接口拉起打印。
应用侧通过调用[createWebPrintDocumentAdapter](../reference/apis/js-apis-webview.md#createwebprintdocumentadapter)创建打印适配器，通过将适配器传入打印的[print](../reference/apis/js-apis-print.md#print11-2)接口调起打印。

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
import business_error from '@ohos.base'
import print from '@ohos.print'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('createWebPrintDocumentAdapter')
        .onClick(() => {
          try {
            let webPrintDocadapter = this.controller.createWebPrintDocumentAdapter('example.pdf');
            print.print('example_jobid', webPrintDocadapter, null, getContext());
          } catch (error) {
            let e: business_error.BusinessError = error as business_error.BusinessError;
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```