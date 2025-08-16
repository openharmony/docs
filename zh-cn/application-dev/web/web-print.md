# 使用Web组件打印前端页面
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhang-yinglie-->
<!--Designer: @handyohos-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Web组件打印html页面时可通过W3C标准协议接口和应用接口两种方式实现。

使用打印功能前，请在module.json5中配置相关权限，添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md#在配置文件中声明权限)。

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.PRINT"
      }
    ]
  ```

## 使用W3C标准协议接口拉起打印
通过创建打印适配器，拉起打印应用，并对当前Web页面内容进行渲染，渲染后生成的PDF文件信息通过fd传递给打印框架。W3C标准协议接口window.print()方法用于打印当前页面或弹出打印对话框。该方法没有任何参数，只需要在JavaScript中调用即可。

可通过前端css样式控制是否打印，例如@media print。再通过web加载该html页面的方式运行。

- print.html页面代码。

  示例一：

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
                  <p style="text-align: center;">This is a test page for printing</p>
              </b>
              <hr color="#00cc00" width="95%">
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
  
  示例二（iframe嵌套页面的方式）：


  ```html
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>iframe嵌套页面打印</title>
  </head>
  <body>
      <button id="printIframe">打印iframe嵌套页面</button>

      <script>
          function setPrint() {
              const closePrint = () => {
                  document.body.removeChild(this);
              };
              this.contentWindow.onbeforeunload = closePrint;
              this.contentWindow.onafterprint = closePrint;
              this.contentWindow.print();
          }

          document.getElementById("printIframe").addEventListener("click", () => {
              const hideFrame = document.createElement("iframe");
              hideFrame.onload = setPrint;
              hideFrame.style.display = "none"; // 隐藏 iframe
              hideFrame.src = "example.pdf";
              document.body.appendChild(hideFrame);
          });

      </script>
  </body>
  </html>
  ```

- 应用侧代码。

  ```ts
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct Index {
    controller: webview.WebviewController = new webview.WebviewController();

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

## 通过调用应用侧接口拉起打印
应用侧通过调用[createWebPrintDocumentAdapter](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createwebprintdocumentadapter11)创建打印适配器，通过将适配器传入打印的print接口调起打印。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError, print } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('createWebPrintDocumentAdapter')
        .onClick(() => {
          try {
            let webPrintDocadapter = this.controller.createWebPrintDocumentAdapter('example.pdf');
            print.print('example_job_id', webPrintDocadapter, null, this.getUIContext().getHostContext());
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```