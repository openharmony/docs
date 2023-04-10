# 上传文件


Web组件支持前端页面选择文件上传功能，应用开发者可以使用[onShowFileSelector()](../reference/arkui-ts/ts-basic-components-web.md#onshowfileselector9)接口来处理前端页面文件上传的请求。


下面的示例中，当用户在前端页面点击文件上传按钮，应用侧在[onShowFileSelector()](../reference/arkui-ts/ts-basic-components-web.md#onshowfileselector9)接口中收到文件上传请求，在此接口中开发者将上传的本地文件路径设置给前端页面。


- 应用侧代码。
  
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    build() {
      Column() {
        // 加载本地local.html页面
        Web({ src: $rawfile('local.html'), controller: this.controller })
          .onShowFileSelector((event) => {
              // 开发者设置要上传的文件路径
             let fileList: Array<string> = [
                'xxx/test.png',
             ]
             event.result.handleFileList(fileList)
             return true;
          })
      }
    }
  }
  ```


- local.html页面代码。
  
  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8">
      <title>Document</title>
  </head>
  
  <body>
  <!-- 点击上传文件按钮 -->
  <input type="file" value="file"></br>
  </body>
  </html>
  ```
