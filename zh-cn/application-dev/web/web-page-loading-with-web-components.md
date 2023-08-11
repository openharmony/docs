# 使用Web组件加载页面


页面加载是Web组件的基本功能。根据页面加载数据来源可以分为三种常用场景，包括加载网络页面、加载本地页面、加载HTML格式的富文本数据。


页面加载过程中，若涉及网络资源获取，需要配置[ohos.permission.INTERNET](../security/accesstoken-guidelines.md)网络访问权限。


## 加载网络页面

开发者可以在Web组件创建的时候指定默认加载的网络页面 。在默认页面加载完成后，如果开发者需要变更此Web组件显示的网络页面，可以通过调用[loadUrl()](../reference/apis/js-apis-webview.md#loadurl)接口加载指定网络网页。


在下面的示例中，在Web组件加载完“www.example.com”页面后，开发者可通过loadUrl接口将此Web组件显示页面变更为“www.example1.com”。



```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            // 点击按钮时，通过loadUrl，跳转到www.example1.com
            this.webviewController.loadUrl('www.example1.com');
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      // 组件创建时，加载www.example.com
      Web({ src: 'www.example.com', controller: this.webviewController})
    }
  }
}
```


## 加载本地页面

将本地页面文件放在应用的rawfile目录下，开发者可以在Web组件创建的时候指定默认加载的本地页面 ，并且加载完成后可通过调用[loadUrl()](../reference/apis/js-apis-webview.md#loadurl)接口变更当前Web组件的页面。


在下面的示例中展示加载本地页面文件的方法：


- 将资源文件放置在应用的resources/rawfile目录下。

    **图1** 资源文件路径  

    ![resource-path](figures/resource-path.png)


- 应用侧代码。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';

  @Entry
  @Component
  struct WebComponent {
    webviewController: web_webview.WebviewController = new web_webview.WebviewController();

    build() {
      Column() {
        Button('loadUrl')
          .onClick(() => {
            try {
              // 点击按钮时，通过loadUrl，跳转到local1.html
              this.webviewController.loadUrl($rawfile("local1.html"));
            } catch (error) {
              console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
            }
          })
        // 组件创建时，通过$rawfile加载本地文件local.html
        Web({ src: $rawfile("local.html"), controller: this.webviewController })
      }
    }
  }
  ```


- local.html页面代码。

  ```html
  <!-- local.html -->
  <!DOCTYPE html>
  <html>
    <body>
      <p>Hello World</p>
    </body>
  </html>
  ```


## 加载HTML格式的文本数据

Web组件可以通过[loadData()](../reference/apis/js-apis-webview.md#loaddata)接口实现加载HTML格式的文本数据。当开发者不需要加载整个页面，只需要显示一些页面片段时，可通过此功能来快速加载页面。



```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            // 点击按钮时，通过loadData，加载HTML格式的文本数据
            this.controller.loadData(
              '<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>',
              'text/html',
              'UTF-8'
            );
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      // 组件创建时，加载www.example.com
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## 相关实例

针对Web组件开发，有以下相关实例可供参考：

- [浏览器（ArkTS）（Full SDK）(API9)](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Release/code/BasicFeature/Web/Browser)