# Web

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供具有页面显示能力的 WebView 组件。

## 权限列表

ohos.permission.INTERNET（使用网络图片）

ohos.permission.READ_USER_STORAGE

## 子组件

无

## 接口

-   Web\(options: {src: string, controller?: WebController}\)

    表1 options 参数说明

    | 参数名        | 参数类型          | 必填   | 默认值  | 参数描述  |
    | ---------- | ------------- | ---- | ---- | ----- |
    | src        | string        | 是    | -    | 网页地址。 |
    | controller | WebController | 否    | -    | 控制器。  |


## 属性

| 名称               | 参数类型    | 默认值   | 描述                                       |
| ---------------- | ------- | ----- | ---------------------------------------- |
| javaScriptAccess | boolean | false | 是否允许执行 JavaScript 脚本，当设置为 false 时，不允许执行。 |
| fileAccess       | boolean | false | 启用或禁用 WebView 中是否能通过 file 方式访问应用中的本地文件，当设置为 false 时，禁用。 |

## 事件

| 名称                                       | 功能描述                 |
| ---------------------------------------- | -------------------- |
| onPageEnd(callback: (event?: { url: string }) => void) | 网页加载结束时触发该回调。        |
| onRequestSelected(callback: () => void)  | 获取 WebView 焦点时触发该回调。 |

## WebController

WebView 组件的控制器。

### 创建对象

```
webController: WebController = new WebController()
```

### webController.runJavaScript

runJavaScript(options: { script: string, callback?: (error, data) => void }): void

执行 JavaScript 脚本。

- 参数

  | 参数名      | 参数类型                  | 必填   | 默认值  | 参数描述                  |
  | -------- | --------------------- | ---- | ---- | --------------------- |
  | script   | string                | 是    | -    | JavaScript 脚本。        |
  | callback | (error, data) => void | 否    | -    | 执行 JavaScript 脚本时的回调。 |

### webController.loadUrl

loadUrl(options: { url: string, headerMap?: Map<string, string> }): void

加载 URL。

- 参数

  | 参数名       | 参数类型                | 必填   | 默认值  | 参数描述       |
  | --------- | ------------------- | ---- | ---- | ---------- |
  | url       | string              | 是    | -    | 需要加载的 URL。 |
  | headerMap | Map<string, string> | 否    | -    | 请求头集合。     |

  ​

## 示例

```
@Entry
@Component
struct WebComponent {
  @State javaScriptAccess: boolean = true;
  @State fileAccess: boolean = true;
  controller: WebController = new WebController();
  
  build() {
    Column() {
      Web(src: 'https://gitee.com/openharmony', controller: this.controller)
      .javaScriptAccess(javaScriptAccess)
      .fileAccess(fileAccess)
      .onRequestSelected(() => {
        // Gitee.initNavbar() 函数定义在网页中
        this.controller.runJavaScript('javascript:Gitee.initNavbar()',
        (err, data) => {
          if (err) {
            console.error('Operation failed. Cause: ', JSON.stringify(err));
            return;
          }
          console.info('Operation successful. Data: ', JSON.stringify(data));
        })
      })
      .onPageEnd((event) => {
        console.log("url: ", event.url);
      })
    }
  }
}
```

