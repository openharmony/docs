# Web

>![icon-note.gif](public_sys-resources/icon-note.gif) **说明：** 
>该组件从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供具有网页显示能力的 Web 组件。

## 权限列表

ohos.permission.INTERNET

ohos.permission.READ_USER_STORAGE

## 子组件

无

## 接口

-   Web\(options: {src: string, controller?: WebController}\)

    表1 options 参数说明

    | 参数名     | 参数类型                        | 必填 | 默认值 | 参数描述       |
    | ---------- | ------------------------------- | ---- | ------ | -------------- |
    | src        | string                          | 是   | -      | 网页资源地址。 |
    | controller | [WebController](#WebController) | 否   | -      | 控制器。       |


> ![icon-note.gif](public_sys-resources/icon-note.gif)**说明：**
>
> - 一个页面只支持一个 Web 组件，全屏显示，页面中的其他组件会被 Web 组件遮挡；
> - 不支持转场动画；
> - 只支持加载 rawfile 目录下的 html 文件，不支持远程资源。

## 属性

| 名称               | 参数类型    | 默认值   | 描述                                       |
| ---------------- | ------- | ----- | ---------------------------------------- |
| javaScriptAccess | boolean | false | 是否允许执行 JavaScript 脚本，当设置为 false 时，不允许执行。 |
| fileAccess       | boolean | false | 启用或禁用 Web 中可通过 file 方式访问应用中的本地文件，当设置为 false 时，禁用。 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> 不支持通用属性。

## 事件

不支持通用事件。

| 名称                                                         | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onPageEnd(callback: (event?: { url: string }) => void)       | <p>网页加载结束时触发该回调。<br/>url：Web 引擎返回的 URL。</p> |
| onPageStart(callback: (event?: {url: string }) => void)      | <p>网页加载时触发该回调。<br/>url：Web 引擎返回的 URL。</p>  |
| onProgressChange(callback: (event?: { newProgress: number }) => void) | <p>网页加载进度变化时触发该回调。<br/>newProgress：加载进度，取值范围为0到100的整数。</p> |
| onTitleReceive(callback: (event?: { title: string }) => void) | <p>网页主页面标题更改时触发该回调。<br/>title：标题内容。</p> |
| onGeolocationHide(callback: () => void)                      | <p>调用onGeolocationShow()时发出的地理位置权限请求被取消后触发该回调。<br/>开发者可以在该回调中实现隐藏相关UI界面的逻辑。</p> |
| onGeolocationShow(callback: (event?: { origin: string, geolocation: JsGeolocation }) => void) | <p>应用尝试使用地理位置时触发该回调，并向用户请求权限。<br/>-origin：尝试获取地理位置的Web内容的来源。<br/>-geolocation：用于请求地理位置权限。</p> |

### JsGeolocation 对象说明

用于请求地理位置权限。

- 接口

  | 接口名称                                                     | 功能描述                                                     |
  | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | invoke(origin: string, allow: boolean, retain: boolean): void | <p>通知系统用户是否批准该应用使用地理位置权限。<br/>-origin：尝试获取地理位置的Web内容的来源。<br/>-allow：用户是否批准该应用使用地理位置权限。true: 允许访问，false: 不允许访问。<br/>-retain：是否允许将地理位置权限状态保存到系统中。true: 允许，false: 不允许。</p> |

## WebController

Web 组件的控制器。

### 创建对象

```
webController: WebController = new WebController()
```

### runJavaScript

runJavaScript(script: string): void

执行 JavaScript 脚本。

- 参数

  | 参数名    | 参数类型   | 必填   | 默认值  | 参数描述           |
  | ------ | ------ | ---- | ---- | -------------- |
  | script | string | 是    | -    | JavaScript 脚本。 |

### loadUrl

loadUrl(url: string): void

加载 URL。

- 参数

  | 参数名  | 参数类型   | 必填   | 默认值  | 参数描述       |
  | ---- | ------ | ---- | ---- | ---------- |
  | url  | string | 是    | -    | 需要加载的 URL。 |


## 示例

```
// webComponent.ets
@Entry
@Component
struct WebComponent {
  @State javaScriptAccess: boolean = true;
  @State fileAccess: boolean = true;
  controller: WebController = new WebController();
  build() {
    Column() {
      Web({ src: $rawfile('index.html'), controller: this.controller })
      .javaScriptAccess(this.javaScriptAccess)
      .fileAccess(this.fileAccess)
      .onPageEnd(e => {
        // test() 在 index.html 中已定义
        this.controller.runJavaScript('test()');
        console.log("url: ", e.url);
      })
    }
  }
}
```
```
<!-- index.html -->
<!DOCTYPE html>
<html>
<meta charset="utf-8">
<body>
    Hello world!
</body>
<script type="text/javascript">
	function test() {
		console.log('Ark WebComponent');
	}
</script>
</html>
```

![](figures/Web.png)