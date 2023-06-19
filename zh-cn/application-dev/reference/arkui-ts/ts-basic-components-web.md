# Web

提供具有网页显示能力的Web组件，[@ohos.web.webview](../apis/js-apis-webview.md)提供web控制能力。

> **说明：**
>
> - 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## 需要权限
访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[权限申请声明](../../security/accesstoken-guidelines.md)。

## 子组件

无

## 接口

Web(options: { src: ResourceStr, controller: WebviewController | WebController})

> **说明：**
>
> 不支持转场动画。
> 同一页面的多个web组件，必须绑定不同的WebviewController。

**参数：**

| 参数名        | 参数类型                                     | 必填   | 参数描述    |
| ---------- | ---------------------------------------- | ---- | ------- |
| src        | [ResourceStr](ts-types.md)               | 是    | 网页资源地址。如果加载应用包外沙箱路径的本地资源文件，请使用file://沙箱文件路径。 |
| controller | [WebviewController<sup>9+</sup>](../apis/js-apis-webview.md#webviewcontroller) \| [WebController](#webcontroller) | 是    | 控制器。从API Version 9开始，WebController不再维护，建议使用WebviewController替代。 |
 
**示例：**

  加载在线网页
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

  加载本地网页
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
      }
    }
  }
  ```

  加载沙箱路径下的本地资源文件

  1.通过[globalthis](../../application-models/uiability-data-sync-with-ui.md#uiability和page之间使用globalthis)获取沙箱路径。
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  let url = 'file://' + globalThis.filesDir + '/index.html'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        // 加载沙箱路径文件。
        Web({ src: url, controller: this.controller })
      }
    }
  }
  ```

  2.修改EntryAbility.ts。
  以filesDir为例，获取沙箱路径。若想获取其他路径，请参考[应用开发路径](../../application-models/application-context-stage.md#获取应用开发路径)。
  ```ts
  // xxx.ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import web_webview from '@ohos.web.webview';

  export default class EntryAbility extends UIAbility {
      onCreate(want, launchParam) {
          // 通过在globalThis对象上绑定filesDir，可以实现UIAbility组件与UI之间的数据同步。
          globalThis.filesDir = this.context.filesDir
          console.log("Sandbox path is " + globalThis.filesDir)
      }
  }
  ```

  加载的html文件。
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
      <body>
          <p>Hello World</p>
      </body>
  </html>
  ```

## 属性

通用属性仅支持[width](ts-universal-attributes-size.md#属性)、[height](ts-universal-attributes-size.md#属性)、[padding](ts-universal-attributes-size.md#属性)、[margin](ts-universal-attributes-size.md#属性)、[border](ts-universal-attributes-border.md#属性)。

### domStorageAccess

domStorageAccess(domStorageAccess: boolean)

设置是否开启文档对象模型存储接口（DOM Storage API）权限，默认未开启。

**参数：**

| 参数名              | 参数类型    | 必填   | 默认值   | 参数描述                                 |
| ---------------- | ------- | ---- | ----- | ------------------------------------ |
| domStorageAccess | boolean | 是    | false | 设置是否开启文档对象模型存储接口（DOM Storage API）权限。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .domStorageAccess(true)
      }
    }
  }
  ```

### fileAccess

fileAccess(fileAccess: boolean)

设置是否开启应用中文件系统的访问，默认启用。[$rawfile(filepath/filename)](../../quick-start/resource-categories-and-access.md)中rawfile路径的文件不受该属性影响而限制访问。

**参数：**

| 参数名        | 参数类型    | 必填   | 默认值  | 参数描述                   |
| ---------- | ------- | ---- | ---- | ---------------------- |
| fileAccess | boolean | 是    | true | 设置是否开启应用中文件系统的访问，默认启用。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .fileAccess(true)
      }
    }
  }
  ```

### imageAccess

imageAccess(imageAccess: boolean)

设置是否允许自动加载图片资源，默认允许。

**参数：**

| 参数名         | 参数类型    | 必填   | 默认值  | 参数描述            |
| ----------- | ------- | ---- | ---- | --------------- |
| imageAccess | boolean | 是    | true | 设置是否允许自动加载图片资源。 |

**示例：**
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .imageAccess(true)
      }
    }
  }
  ```

### javaScriptProxy

javaScriptProxy(javaScriptProxy: { object: object, name: string, methodList: Array\<string\>,
    controller: WebviewController | WebController})

注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。所有参数不支持更新。

**参数：**

| 参数名        | 参数类型                                     | 必填   | 默认值  | 参数描述                      |
| ---------- | ---------------------------------------- | ---- | ---- | ------------------------- |
| object     | object                                   | 是    | -    | 参与注册的对象。只能声明方法，不能声明属性。    |
| name       | string                                   | 是    | -    | 注册对象的名称，与window中调用的对象名一致。 |
| methodList | Array\<string\>                          | 是    | -    | 参与注册的应用侧JavaScript对象的方法。  |
| controller | [WebviewController<sup>9+</sup>](../apis/js-apis-webview.md#webviewcontroller) \| [WebController](#webcontroller) | 是    | -    | 控制器。从API Version 9开始，WebController不再维护，建议使用WebviewController替代。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    testObj = {
      test: (data1, data2, data3) => {
        console.log("data1:" + data1)
        console.log("data2:" + data2)
        console.log("data3:" + data3)
        return "AceString"
      },
      toString: () => {
        console.log('toString' + "interface instead.")
      }
    }
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          .javaScriptProxy({
            object: this.testObj,
            name: "objName",
            methodList: ["test", "toString"],
            controller: this.controller,
        })
      }
    }
  }
  ```

### javaScriptAccess

javaScriptAccess(javaScriptAccess: boolean)

设置是否允许执行JavaScript脚本，默认允许执行。

**参数：**

| 参数名              | 参数类型    | 必填   | 默认值  | 参数描述                |
| ---------------- | ------- | ---- | ---- | ------------------- |
| javaScriptAccess | boolean | 是    | true | 是否允许执行JavaScript脚本。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
      }
    }
  }
  ```

### mixedMode

mixedMode(mixedMode: MixedMode)

设置是否允许加载超文本传输协议（HTTP）和超文本传输安全协议（HTTPS）混合内容，默认不允许加载HTTP和HTTPS混合内容。

**参数：**

| 参数名       | 参数类型                        | 必填   | 默认值            | 参数描述      |
| --------- | --------------------------- | ---- | -------------- | --------- |
| mixedMode | [MixedMode](#mixedmode枚举说明) | 是    | MixedMode.None | 要设置的混合内容。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State mode: MixedMode = MixedMode.All
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .mixedMode(this.mode)
      }
    }
  }
  ```

### onlineImageAccess

onlineImageAccess(onlineImageAccess: boolean)

设置是否允许从网络加载图片资源（通过HTTP和HTTPS访问的资源），默认允许访问。

**参数：**

| 参数名               | 参数类型    | 必填   | 默认值  | 参数描述             |
| ----------------- | ------- | ---- | ---- | ---------------- |
| onlineImageAccess | boolean | 是    | true | 设置是否允许从网络加载图片资源。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onlineImageAccess(true)
      }
    }
  }
  ```

### zoomAccess

zoomAccess(zoomAccess: boolean)

设置是否支持手势进行缩放，默认允许执行缩放。

**参数：**

| 参数名        | 参数类型    | 必填   | 默认值  | 参数描述          |
| ---------- | ------- | ---- | ---- | ------------- |
| zoomAccess | boolean | 是    | true | 设置是否支持手势进行缩放。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .zoomAccess(true)
      }
    }
  }
  ```

### overviewModeAccess

overviewModeAccess(overviewModeAccess: boolean)

设置是否使用概览模式加载网页，默认使用该方式。

**参数：**

| 参数名                | 参数类型    | 必填   | 默认值  | 参数描述            |
| ------------------ | ------- | ---- | ---- | --------------- |
| overviewModeAccess | boolean | 是    | true | 设置是否使用概览模式加载网页。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .overviewModeAccess(true)
      }
    }
  }
  ```

### databaseAccess

databaseAccess(databaseAccess: boolean)

设置是否开启数据库存储API权限，默认不开启。

**参数：**

| 参数名            | 参数类型    | 必填   | 默认值   | 参数描述              |
| -------------- | ------- | ---- | ----- | ----------------- |
| databaseAccess | boolean | 是    | false | 设置是否开启数据库存储API权限。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .databaseAccess(true)
      }
    }
  }
  ```

### geolocationAccess

geolocationAccess(geolocationAccess: boolean)

设置是否开启获取地理位置权限，默认开启。

**参数：**

| 参数名               | 参数类型    | 必填   | 默认值  | 参数描述            |
| ----------------- | ------- | ---- | ---- | --------------- |
| geolocationAccess | boolean | 是    | true | 设置是否开启获取地理位置权限。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .geolocationAccess(true)
      }
    }
  }
  ```

### mediaPlayGestureAccess

mediaPlayGestureAccess(access: boolean)

设置有声视频播放是否需要用户手动点击，静音视频播放不受该接口管控，默认需要。

**参数：**

| 参数名    | 参数类型    | 必填   | 默认值  | 参数描述              |
| ------ | ------- | ---- | ---- | ----------------- |
| access | boolean | 是    | true | 设置有声视频播放是否需要用户手动点击。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State access: boolean = true
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .mediaPlayGestureAccess(this.access)
      }
    }
  }
  ```

### multiWindowAccess<sup>9+</sup>

multiWindowAccess(multiWindow: boolean)

设置是否开启多窗口权限，默认不开启。
使能多窗口权限时，需要实现onWindowNew事件，示例代码参考[onWindowNew事件](#onwindownew9)。

**参数：**

| 参数名         | 参数类型    | 必填   | 默认值   | 参数描述         |
| ----------- | ------- | ---- | ----- | ------------ |
| multiWindow | boolean | 是    | false | 设置是否开启多窗口权限。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
        .multiWindowAccess(false)
      }
    }
  }
  ```

### horizontalScrollBarAccess<sup>9+</sup>

horizontalScrollBarAccess(horizontalScrollBar: boolean)

设置是否显示横向滚动条，包括系统默认滚动条和用户自定义滚动条。默认显示。

**参数：**

| 参数名         | 参数类型    | 必填   | 默认值   | 参数描述         |
| ----------- | ------- | ---- | ----- | ------------ |
| horizontalScrollBar | boolean | 是    | true | 设置是否显示横向滚动条。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .horizontalScrollBarAccess(true)
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
      <title>Demo</title>
      <style>
        body {
          width:3000px;
          height:3000px;
          padding-right:170px;
          padding-left:170px;
          border:5px solid blueviolet
        }
      </style>
  </head>
  <body>
  Scroll Test
  </body>
  </html>
  ```

### verticalScrollBarAccess<sup>9+</sup>

verticalScrollBarAccess(verticalScrollBar: boolean)

设置是否显示纵向滚动条，包括系统默认滚动条和用户自定义滚动条。默认显示。

**参数：**

| 参数名         | 参数类型    | 必填   | 默认值   | 参数描述         |
| ----------- | ------- | ---- | ----- | ------------ |
| verticalScrollBarAccess | boolean | 是    | true | 设置是否显示纵向滚动条。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .verticalScrollBarAccess(true)
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
      <title>Demo</title>
      <style>
        body {
          width:3000px;
          height:3000px;
          padding-right:170px;
          padding-left:170px;
          border:5px solid blueviolet
        }
      </style>
  </head>
  <body>
  Scroll Test
  </body>
  </html>
  ```

### password

password(password: boolean)

设置是否应保存密码。该接口为空接口。

### cacheMode

cacheMode(cacheMode: CacheMode)

设置缓存模式。

**参数：**

| 参数名       | 参数类型                        | 必填   | 默认值               | 参数描述      |
| --------- | --------------------------- | ---- | ----------------- | --------- |
| cacheMode | [CacheMode](#cachemode枚举说明) | 是    | CacheMode.Default | 要设置的缓存模式。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State mode: CacheMode = CacheMode.None
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .cacheMode(this.mode)
      }
    }
  }
  ```

### textZoomAtio<sup>(deprecated)</sup>

textZoomAtio(textZoomAtio: number)

设置页面的文本缩放百分比，默认为100%。

从API version 9开始不再维护，建议使用[textZoomRatio<sup>9+</sup>](#textzoomratio9)代替。

**参数：**

| 参数名           | 参数类型   | 必填   | 默认值  | 参数描述            |
| ------------- | ------ | ---- | ---- | --------------- |
| textZoomAtio | number | 是    | 100  | 要设置的页面的文本缩放百分比。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State atio: number = 150
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .textZoomAtio(this.atio)
      }
    }
  }
  ```

### textZoomRatio<sup>9+</sup>

textZoomRatio(textZoomRatio: number)

设置页面的文本缩放百分比，默认为100%。

**参数：**

| 参数名           | 参数类型   | 必填   | 默认值  | 参数描述            |
| ------------- | ------ | ---- | ---- | --------------- |
| textZoomRatio | number | 是    | 100  | 要设置的页面的文本缩放百分比。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State atio: number = 150
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .textZoomRatio(this.atio)
      }
    }
  }
  ```

### initialScale<sup>9+</sup>

initialScale(percent: number)

设置整体页面的缩放百分比，默认为100%。

**参数：**

| 参数名     | 参数类型   | 必填   | 默认值  | 参数描述            |
| ------- | ------ | ---- | ---- | --------------- |
| percent | number | 是    | 100  | 要设置的整体页面的缩放百分比。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State percent: number = 100
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .initialScale(this.percent)
      }
    }
  }
  ```

### userAgent

userAgent(userAgent: string)

设置用户代理。

**参数：**

| 参数名       | 参数类型   | 必填   | 默认值  | 参数描述      |
| --------- | ------ | ---- | ---- | --------- |
| userAgent | string | 是    | -    | 要设置的用户代理。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State userAgent:string = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.71 Safari/537.36'
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .userAgent(this.userAgent)
      }
    }
  }
  ```

### blockNetwork<sup>9+</sup>

blockNetwork(block: boolean)

设置Web组件是否阻止从网络加载资源。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述                            |
| ------ | -------- | ---- | ------ | ----------------------------------- |
| block  | boolean  | 是   | false  | 设置Web组件是否阻止从网络加载资源。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State block: boolean = true
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .blockNetwork(this.block)
      }
    }
  }
  ```

### defaultFixedFontSize<sup>9+</sup>

defaultFixedFontSize(size: number)

设置网页的默认等宽字体大小。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述                     |
| ------ | -------- | ---- | ------ | ---------------------------- |
| size   | number   | 是   | 13     | 设置网页的默认等宽字体大小，单位px。输入值的范围为-2^31到2^31-1，实际渲染时超过72的值按照72进行渲染，低于1的值按照1进行渲染。  |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State fontSize: number = 16
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .defaultFixedFontSize(this.fontSize)
      }
    }
  }
  ```

### defaultFontSize<sup>9+</sup>

defaultFontSize(size: number)

设置网页的默认字体大小。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述                 |
| ------ | -------- | ---- | ------ | ------------------------ |
| size   | number   | 是   | 16     | 设置网页的默认字体大小，单位px。输入值的范围为-2^31到2^31-1，实际渲染时超过72的值按照72进行渲染，低于1的值按照1进行渲染。  |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State fontSize: number = 13
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .defaultFontSize(this.fontSize)
      }
    }
  }
  ```

### minFontSize<sup>9+</sup>

minFontSize(size: number)

设置网页字体大小最小值。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述                 |
| ------ | -------- | ---- | ------ | ------------------------ |
| size   | number   | 是   | 8      | 设置网页字体大小最小值，单位px。输入值的范围为-2^31到2^31-1，实际渲染时超过72的值按照72进行渲染，低于1的值按照1进行渲染。  |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State fontSize: number = 13
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .minFontSize(this.fontSize)
      }
    }
  }
  ```

### minLogicalFontSize<sup>9+</sup>

minLogicalFontSize(size: number)

设置网页逻辑字体大小最小值。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述                 |
| ------ | -------- | ---- | ------ | ------------------------ |
| size   | number   | 是   | 8      | 设置网页逻辑字体大小最小值，单位px。输入值的范围为-2^31到2^31-1，实际渲染时超过72的值按照72进行渲染，低于1的值按照1进行渲染。  |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State fontSize: number = 13
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .minLogicalFontSize(this.fontSize)
      }
    }
  }
  ```


### webFixedFont<sup>9+</sup>

webFixedFont(family: string)

设置网页的fixed font字体库。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值    | 参数描述                     |
| ------ | -------- | ---- | --------- | ---------------------------- |
| family | string   | 是   | monospace | 设置网页的fixed font字体库。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "monospace"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webFixedFont(this.family)
      }
    }
  }
  ```

### webSansSerifFont<sup>9+</sup>

webSansSerifFont(family: string)

设置网页的sans serif font字体库。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值     | 参数描述                          |
| ------ | -------- | ---- | ---------- | --------------------------------- |
| family | string   | 是   | sans-serif | 设置网页的sans serif font字体库。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "sans-serif"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webSansSerifFont(this.family)
      }
    }
  }
  ```

### webSerifFont<sup>9+</sup>

webSerifFont(family: string)

设置网页的serif font字体库。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述                     |
| ------ | -------- | ---- | ------ | ---------------------------- |
| family | string   | 是   | serif  | 设置网页的serif font字体库。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "serif"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webSerifFont(this.family)
      }
    }
  }
  ```

### webStandardFont<sup>9+</sup>

webStandardFont(family: string)

设置网页的standard font字体库。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值     | 参数描述                        |
| ------ | -------- | ---- | ---------- | ------------------------------- |
| family | string   | 是   | sans serif | 设置网页的standard font字体库。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "sans-serif"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webStandardFont(this.family)
      }
    }
  }
  ```

### webFantasyFont<sup>9+</sup>

webFantasyFont(family: string)

设置网页的fantasy font字体库。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值  | 参数描述                       |
| ------ | -------- | ---- | ------- | ------------------------------ |
| family | string   | 是   | fantasy | 设置网页的fantasy font字体库。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "fantasy"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webFantasyFont(this.family)
      }
    }
  }
  ```

### webCursiveFont<sup>9+</sup>

webCursiveFont(family: string)

设置网页的cursive font字体库。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值  | 参数描述                       |
| ------ | -------- | ---- | ------- | ------------------------------ |
| family | string   | 是   | cursive | 设置网页的cursive font字体库。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State family: string = "cursive"
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webCursiveFont(this.family)
      }
    }
  }
  ```

### darkMode<sup>9+</sup>

darkMode(mode: WebDarkMode)

设置Web深色模式，默认关闭。当深色模式开启时，Web将启用媒体查询prefer-color-scheme中网页所定义的深色样式，若网页未定义深色样式，则保持原状。如需开启强制深色模式，建议配合[forceDarkAccess](#forcedarkaccess9)使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值  | 参数描述                       |
| ------ | ----------- | ---- | --------------- | ------------------ |
|  mode  | [WebDarkMode](#webdarkmode9枚举说明) | 是   | WebDarkMode.Off | 设置Web的深色模式为关闭、开启或跟随系统。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State mode: WebDarkMode = WebDarkMode.On
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .darkMode(this.mode)
      }
    }
  }
  ```

### forceDarkAccess<sup>9+</sup>

forceDarkAccess(access: boolean)

设置网页是否开启强制深色模式。默认关闭。该属性仅在[darkMode](#darkmode9)开启深色模式时生效。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值  | 参数描述                       |
| ------ | ------- | ---- | ----- | ------------------ |
| access | boolean | 是   | false | 设置网页是否开启强制深色模式。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State mode: WebDarkMode = WebDarkMode.On
    @State access: boolean = true
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .darkMode(this.mode)
          .forceDarkAccess(this.access)
      }
    }
  }
  ```

### tableData

tableData(tableData: boolean)

设置是否应保存表单数据。该接口为空接口。

### wideViewModeAccess

wideViewModeAccess(wideViewModeAccess: boolean)

设置web是否支持html中meta标签的viewport属性。该接口为空接口。

### pinchSmooth<sup>9+</sup>

pinchSmooth(isEnabled: boolean)

设置网页是否开启捏合流畅模式，默认不开启。

**参数：**

| 参数名    | 参数类型 | 必填 | 默认值 | 参数描述                   |
| --------- | -------- | ---- | ------ | -------------------------- |
| isEnabled | boolean  | 是   | false  | 网页是否开启捏合流畅模式。 |

**示例：**

  ```ts
// xxx.ets
import web_webview from '@ohos.web.webview'
@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController()
  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .pinchSmooth(true)
    }
  }
}
  ```

## 事件

不支持通用事件。

### onAlert

onAlert(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

网页触发alert()告警弹窗时触发回调。

**参数：**

| 参数名     | 参数类型                  | 参数描述            |
| ------- | --------------------- | --------------- |
| url     | string                | 当前显示弹窗所在网页的URL。 |
| message | string                | 弹窗中显示的信息。       |
| result  | [JsResult](#jsresult) | 通知Web组件用户操作行为。  |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 当回调返回true时，应用可以调用系统弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。当回调返回false时，web组件暂不支持触发默认弹窗。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onAlert((event) => {
            console.log("event.url:" + event.url)
            console.log("event.message:" + event.message)
            AlertDialog.show({
              title: 'onAlert',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.result.handleCancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  event.result.handleConfirm()
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>
  <body>
    <h1>WebView onAlert Demo</h1>
    <button onclick="myFunction()">Click here</button>
    <script>
      function myFunction() {
        alert("Hello World");
      }
    </script>
  </body>
  </html>
  ```

### onBeforeUnload

onBeforeUnload(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

刷新或关闭场景下，在即将离开当前页面时触发此回调。刷新或关闭当前页面应先通过点击等方式获取焦点，才会触发此回调。

**参数：**

| 参数名     | 参数类型                  | 参数描述            |
| ------- | --------------------- | --------------- |
| url     | string                | 当前显示弹窗所在网页的URL。 |
| message | string                | 弹窗中显示的信息。       |
| result  | [JsResult](#jsresult) | 通知Web组件用户操作行为。  |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 当回调返回true时，应用可以调用系统弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。当回调返回false时，web组件暂不支持触发默认弹窗。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onBeforeUnload((event) => {
            console.log("event.url:" + event.url)
            console.log("event.message:" + event.message)
            AlertDialog.show({
              title: 'onBeforeUnload',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.result.handleCancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  event.result.handleConfirm()
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>
  <body onbeforeunload="return myFunction()">
    <h1>WebView onBeforeUnload Demo</h1>
    <a href="https://www.example.com">Click here</a>
    <script>
      function myFunction() {
        return "onBeforeUnload Event";
      }
    </script>
  </body>
  </html>
  ```

### onConfirm

onConfirm(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

网页调用confirm()告警时触发此回调。

**参数：**

| 参数名     | 参数类型                  | 参数描述            |
| ------- | --------------------- | --------------- |
| url     | string                | 当前显示弹窗所在网页的URL。 |
| message | string                | 弹窗中显示的信息。       |
| result  | [JsResult](#jsresult) | 通知Web组件用户操作行为。  |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 当回调返回true时，应用可以调用系统弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件。当回调返回false时，web组件暂不支持触发默认弹窗。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onConfirm((event) => {
            console.log("event.url:" + event.url)
            console.log("event.message:" + event.message)
            AlertDialog.show({
              title: 'onConfirm',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.result.handleCancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  event.result.handleConfirm()
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>

  <body>
    <h1>WebView onConfirm Demo</h1>
    <button onclick="myFunction()">Click here</button>
    <p id="demo"></p>
    <script>
      function myFunction() {
        let x;
        let r = confirm("click button!");
        if (r == true) {
          x = "ok";
        } else {
          x = "cancel";
        }
        document.getElementById("demo").innerHTML = x;
      }
    </script>
  </body>
  </html>
  ```

### onPrompt<sup>9+</sup>

onPrompt(callback: (event?: { url: string; message: string; value: string; result: JsResult }) => boolean)

**参数：**

| 参数名     | 参数类型                  | 参数描述            |
| ------- | --------------------- | --------------- |
| url     | string                | 当前显示弹窗所在网页的URL。 |
| message | string                | 弹窗中显示的信息。       |
| result  | [JsResult](#jsresult) | 通知Web组件用户操作行为。  |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 当回调返回true时，应用可以调用系统弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件。当回调返回false时，web组件暂不支持触发默认弹窗。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onPrompt((event) => {
            console.log("url:" + event.url)
            console.log("message:" + event.message)
            console.log("value:" + event.value)
            AlertDialog.show({
              title: 'onPrompt',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.result.handleCancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  event.result.handlePromptConfirm(event.value)
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!--index.html-->
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
  </head>

  <body>
    <h1>WebView onPrompt Demo</h1>
    <button onclick="myFunction()">Click here</button>
    <p id="demo"></p>
    <script>
      function myFunction() {
        let message = prompt("Message info", "Hello World");
        if (message != null && message != "") {
          document.getElementById("demo").innerHTML = message;
        }
      }
    </script>
  </body>
  </html>
  ```

### onConsole

onConsole(callback: (event?: { message: ConsoleMessage }) => boolean)

通知宿主应用JavaScript console消息。

**参数：**

| 参数名     | 参数类型                              | 参数描述      |
| ------- | --------------------------------- | --------- |
| message | [ConsoleMessage](#consolemessage) | 触发的控制台信息。 |

**返回值：**

| 类型      | 说明                                  |
| ------- | ----------------------------------- |
| boolean | 当返回true时，该条消息将不会再打印至控制台，反之仍会打印至控制台。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onConsole((event) => {
            console.log('getMessage:' + event.message.getMessage())
            console.log('getSourceId:' + event.message.getSourceId())
            console.log('getLineNumber:' + event.message.getLineNumber())
            console.log('getMessageLevel:' + event.message.getMessageLevel())
            return false
          })
      }
    }
  }
  ```

### onDownloadStart

onDownloadStart(callback: (event?: { url: string, userAgent: string, contentDisposition: string, mimetype: string, contentLength: number }) => void)

通知主应用开始下载一个文件。

**参数：**

| 参数名                | 参数类型          | 参数描述                                |
| ------------------ | ------------- | ----------------------------------- |
| url                | string        | 文件下载的URL。                           |
| userAgent          | string        | 用于下载的用户代理。                           |
| contentDisposition | string        | 服务器返回的 Content-Disposition响应头，可能为空。 |
| mimetype           | string        | 服务器返回内容媒体类型（MIME）信息。                |
| contentLength      | contentLength | 服务器返回文件的长度。                         |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onDownloadStart((event) => {
            console.log('url:' + event.url)
            console.log('userAgent:' + event.userAgent)
            console.log('contentDisposition:' + event.contentDisposition)
            console.log('contentLength:' + event.contentLength)
            console.log('mimetype:' + event.mimetype)
          })
      }
    }
  }
  ```

### onErrorReceive

onErrorReceive(callback: (event?: { request: WebResourceRequest, error: WebResourceError }) => void)

网页加载遇到错误时触发该回调。出于性能考虑，建议此回调中尽量执行简单逻辑。在无网络的情况下，触发此回调。

**参数：**

| 参数名     | 参数类型                                     | 参数描述            |
| ------- | ---------------------------------------- | --------------- |
| request | [WebResourceRequest](#webresourcerequest) | 网页请求的封装信息。      |
| error   | [WebResourceError](#webresourceerror)    | 网页加载资源错误的封装信息 。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onErrorReceive((event) => {
            console.log('getErrorInfo:' + event.error.getErrorInfo())
            console.log('getErrorCode:' + event.error.getErrorCode())
            console.log('url:' + event.request.getRequestUrl())
            console.log('isMainFrame:' + event.request.isMainFrame())
            console.log('isRedirect:' + event.request.isRedirect())
            console.log('isRequestGesture:' + event.request.isRequestGesture())
            console.log('getRequestHeader_headerKey:' + event.request.getRequestHeader().toString())
            let result = event.request.getRequestHeader()
            console.log('The request header result size is ' + result.length)
            for (let i of result) {
              console.log('The request header key is : ' + i.headerKey + ', value is : ' + i.headerValue)
            }
          })
      }
    }
  }
  ```

### onHttpErrorReceive

onHttpErrorReceive(callback: (event?: { request: WebResourceRequest, response: WebResourceResponse }) => void)

网页加载资源遇到的HTTP错误（响应码>=400)时触发该回调。

**参数：**

| 参数名     | 参数类型                                     | 参数描述            |
| ------- | ---------------------------------------- | --------------- |
| request | [WebResourceRequest](#webresourcerequest) | 网页请求的封装信息。      |
| response | [WebResourceResponse](#webresourceresponse)    | 资源响应的封装信息。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onHttpErrorReceive((event) => {
            console.log('url:' + event.request.getRequestUrl())
            console.log('isMainFrame:' + event.request.isMainFrame())
            console.log('isRedirect:' + event.request.isRedirect())
            console.log('isRequestGesture:' + event.request.isRequestGesture())
            console.log('getResponseData:' + event.response.getResponseData())
            console.log('getResponseEncoding:' + event.response.getResponseEncoding())
            console.log('getResponseMimeType:' + event.response.getResponseMimeType())
            console.log('getResponseCode:' + event.response.getResponseCode())
            console.log('getReasonMessage:' + event.response.getReasonMessage())
            let result = event.request.getRequestHeader()
            console.log('The request header result size is ' + result.length)
            for (let i of result) {
              console.log('The request header key is : ' + i.headerKey + ' , value is : ' + i.headerValue)
            }
            let resph = event.response.getResponseHeader()
            console.log('The response header result size is ' + resph.length)
            for (let i of resph) {
              console.log('The response header key is : ' + i.headerKey + ' , value is : ' + i.headerValue)
            }
          })
      }
    }
  }
  ```

### onPageBegin

onPageBegin(callback: (event?: { url: string }) => void)


网页开始加载时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。

**参数：**

| 参数名  | 参数类型   | 参数描述      |
| ---- | ------ | --------- |
| url  | string | 页面的URL地址。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onPageBegin((event) => {
            console.log('url:' + event.url)
          })
      }
    }
  }
  ```

### onPageEnd

onPageEnd(callback: (event?: { url: string }) => void)


网页加载完成时触发该回调，且只在主frame触发。

**参数：**

| 参数名  | 参数类型   | 参数描述      |
| ---- | ------ | --------- |
| url  | string | 页面的URL地址。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onPageEnd((event) => {
            console.log('url:' + event.url)
          })
      }
    }
  }
  ```

### onProgressChange

onProgressChange(callback: (event?: { newProgress: number }) => void)

网页加载进度变化时触发该回调。

**参数：**

| 参数名         | 参数类型   | 参数描述                  |
| ----------- | ------ | --------------------- |
| newProgress | number | 新的加载进度，取值范围为0到100的整数。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onProgressChange((event) => {
            console.log('newProgress:' + event.newProgress)
          })
      }
    }
  }
  ```

### onTitleReceive

onTitleReceive(callback: (event?: { title: string }) => void)

网页document标题更改时触发该回调。

**参数：**

| 参数名   | 参数类型   | 参数描述          |
| ----- | ------ | ------------- |
| title | string | document标题内容。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onTitleReceive((event) => {
            console.log('title:' + event.title)
          })
      }
    }
  }
  ```

### onRefreshAccessedHistory

onRefreshAccessedHistory(callback: (event?: { url: string, isRefreshed: boolean }) => void)

加载网页页面完成时触发该回调，用于应用更新其访问的历史链接。

**参数：**

| 参数名         | 参数类型    | 参数描述                                     |
| ----------- | ------- | ---------------------------------------- |
| url         | string  | 访问的url。                                  |
| isRefreshed | boolean | true表示该页面是被重新加载的（调用[refresh<sup>9+</sup>](../apis/js-apis-webview.md#refresh)接口），false表示该页面是新加载的。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onRefreshAccessedHistory((event) => {
            console.log('url:' + event.url + ' isReload:' + event.isRefreshed)
          })
      }
    }
  }
  ```

### onSslErrorReceive<sup>(deprecated)</sup>

onSslErrorReceive(callback: (event?: { handler: Function, error: object }) => void)

通知用户加载资源时发生SSL错误。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[onSslErrorEventReceive<sup>9+</sup>](#onsslerroreventreceive9)替代。

### onFileSelectorShow<sup>(deprecated)</sup>

onFileSelectorShow(callback: (event?: { callback: Function, fileSelector: object }) => void)

调用此函数以处理具有“文件”输入类型的HTML表单，以响应用户按下的“选择文件”按钮。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[onShowFileSelector<sup>9+</sup>](#onshowfileselector9)替代。

### onRenderExited<sup>9+</sup>

onRenderExited(callback: (event?: { renderExitReason: RenderExitReason }) => void)

应用渲染进程异常退出时触发该回调。

**参数：**

| 参数名              | 参数类型                                     | 参数描述             |
| ---------------- | ---------------------------------------- | ---------------- |
| renderExitReason | [RenderExitReason](#renderexitreason枚举说明) | 渲染进程进程异常退出的具体原因。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'chrome://crash/', controller: this.controller })
          .onRenderExited((event) => {
            console.log('reason:' + event.renderExitReason)
          })
      }
    }
  }
  ```

### onShowFileSelector<sup>9+</sup>

onShowFileSelector(callback: (event?: { result: FileSelectorResult, fileSelector: FileSelectorParam }) => boolean)

调用此函数以处理具有“文件”输入类型的HTML表单，以响应用户按下的“选择文件”按钮。

**参数：**

| 参数名          | 参数类型                                     | 参数描述              |
| ------------ | ---------------------------------------- | ----------------- |
| result       | [FileSelectorResult](#fileselectorresult9) | 用于通知Web组件文件选择的结果。 |
| fileSelector | [FileSelectorParam](#fileselectorparam9) | 文件选择器的相关信息。       |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 当返回值为true时，用户可以调用系统提供的弹窗能力。当回调返回false时，web组件暂不支持触发默认弹窗。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onShowFileSelector((event) => {
            AlertDialog.show({
              title: event.fileSelector.getTitle(),
              message: 'isCapture:' + event.fileSelector.isCapture() + " mode:" + event.fileSelector.getMode() + 'acceptType:' + event.fileSelector.getAcceptType(),
              confirm: {
                value: 'upload',
                action: () => {
                  let fileList: Array<string> = [
                    '/data/storage/el2/base/test',
                  ]
                  event.result.handleFileList(fileList)
                }
              },
              cancel: () => {
                let fileList: Array<string> = []
                event.result.handleFileList(fileList)
              }
            })
            return true
          })
      }
    }
  }
  ```

### onResourceLoad<sup>9+</sup>

onResourceLoad(callback: (event: {url: string}) => void)

通知Web组件所加载的资源文件url信息。

**参数：**

| 参数名  | 参数类型   | 参数描述           |
| ---- | ------ | -------------- |
| url  | string | 所加载的资源文件url信息。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onResourceLoad((event) => {
            console.log('onResourceLoad: ' + event.url)
          })
      }
    }
  }
  ```

### onScaleChange<sup>9+</sup>

onScaleChange(callback: (event: {oldScale: number, newScale: number}) => void)

当前页面显示比例的变化时触发该回调。

**参数：**

| 参数名      | 参数类型   | 参数描述         |
| -------- | ------ | ------------ |
| oldScale | number | 变化前的显示比例百分比。 |
| newScale | number | 变化后的显示比例百分比。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onScaleChange((event) => {
            console.log('onScaleChange changed from ' + event.oldScale + ' to ' + event.newScale)
          })
      }
    }
  }
  ```

### onUrlLoadIntercept

onUrlLoadIntercept(callback: (event?: { data:string | WebResourceRequest }) => boolean)

当Web组件加载url之前触发该回调，用于判断是否阻止此次访问。默认允许加载。

**参数：**

| 参数名  | 参数类型                                     | 参数描述      |
| ---- | ---------------------------------------- | --------- |
| data | string / [WebResourceRequest](#webresourcerequest) | url的相关信息。 |

**返回值：**

| 类型      | 说明                       |
| ------- | ------------------------ |
| boolean | 返回true表示阻止此次加载，否则允许此次加载。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onUrlLoadIntercept((event) => {
            console.log('onUrlLoadIntercept ' + event.data.toString())
            return true
          })
      }
    }
  }
  ```

### onInterceptRequest<sup>9+</sup>

onInterceptRequest(callback: (event?: { request: WebResourceRequest}) => WebResourceResponse)

当Web组件加载url之前触发该回调，用于拦截url并返回响应数据。

**参数：**

| 参数名     | 参数类型                                     | 参数描述        |
| ------- | ---------------------------------------- | ----------- |
| request | [WebResourceRequest](#webresourcerequest) | url请求的相关信息。 |

**返回值：**

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| [WebResourceResponse](#webresourceresponse) | 返回响应数据则按照响应数据加载，无响应数据则返回null表示按照原来的方式加载。 |

**示例：**

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

### onHttpAuthRequest<sup>9+</sup>

onHttpAuthRequest(callback: (event?: { handler: HttpAuthHandler, host: string, realm: string}) => boolean)

通知收到http auth认证请求。

**参数：**

| 参数名     | 参数类型                                 | 参数描述             |
| ------- | ------------------------------------ | ---------------- |
| handler | [HttpAuthHandler](#httpauthhandler9) | 通知Web组件用户操作行为。   |
| host    | string                               | HTTP身份验证凭据应用的主机。 |
| realm   | string                               | HTTP身份验证凭据应用的域。  |

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 返回false表示此次认证失败，否则成功。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    httpAuth: boolean = false

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onHttpAuthRequest((event) => {
            AlertDialog.show({
              title: 'onHttpAuthRequest',
              message: 'text',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.cancel()
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  this.httpAuth = event.handler.isHttpAuthInfoSaved()
                  if (this.httpAuth == false) {
                    web_webview.WebDataBase.saveHttpAuthCredentials(
                      event.host,
                      event.realm,
                      "2222",
                      "2222"
                    )
                    event.handler.cancel()
                  }
                }
              },
              cancel: () => {
                event.handler.cancel()
              }
            })
            return true
          })
      }
    }
  }
  ```
### onSslErrorEventReceive<sup>9+</sup>

onSslErrorEventReceive(callback: (event: { handler: SslErrorHandler, error: SslError }) => void)

通知用户加载资源时发生SSL错误。

**参数：**

| 参数名     | 参数类型                                 | 参数描述           |
| ------- | ------------------------------------ | -------------- |
| handler | [SslErrorHandler](#sslerrorhandler9) | 通知Web组件用户操作行为。 |
| error   | [SslError](#sslerror9枚举说明)           | 错误码。           |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onSslErrorEventReceive((event) => {
            AlertDialog.show({
              title: 'onSslErrorEventReceive',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.handleConfirm()
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.handleCancel()
                }
              },
              cancel: () => {
                event.handler.handleCancel()
              }
            })
            return true
          })
      }
    }
  }
  ```

### onClientAuthenticationRequest<sup>9+</sup>

onClientAuthenticationRequest(callback: (event: {handler : ClientAuthenticationHandler, host : string, port : number, keyTypes : Array<string>, issuers : Array<string>}) => void)

通知用户收到SSL客户端证书请求事件。

**参数：**

| 参数名      | 参数类型                                     | 参数描述            |
| -------- | ---------------------------------------- | --------------- |
| handler  | [ClientAuthenticationHandler](#clientauthenticationhandler9) | 通知Web组件用户操作行为。  |
| host     | string                                   | 请求证书服务器的主机名。    |
| port     | number                                   | 请求证书服务器的端口号。    |
| keyTypes | Array<string>                            | 可接受的非对称秘钥类型。    |
| issuers  | Array<string>                            | 与私钥匹配的证书可接受颁发者。 |

  **示例：**
  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onClientAuthenticationRequest((event) => {
            AlertDialog.show({
              title: 'onClientAuthenticationRequest',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.confirm("/system/etc/user.pk8", "/system/etc/chain-user.pem")
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.cancel()
                }
              },
              cancel: () => {
                event.handler.ignore()
              }
            })
            return true
          })
      }
    }
  }
  ```

### onPermissionRequest<sup>9+</sup>

onPermissionRequest(callback: (event?: { request: PermissionRequest }) => void)

通知收到获取权限请求。

**参数：**

| 参数名     | 参数类型                                     | 参数描述           |
| ------- | ---------------------------------------- | -------------- |
| request | [PermissionRequest](#permissionrequest9) | 通知Web组件用户操作行为。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onPermissionRequest((event) => {
            AlertDialog.show({
              title: 'title',
              message: 'text',
              primaryButton: {
                value: 'deny',
                action: () => {
                  event.request.deny()
                }
              },
              secondaryButton: {
                value: 'onConfirm',
                action: () => {
                  event.request.grant(event.request.getAccessibleResource())
                }
              },
              cancel: () => {
                event.request.deny()
              }
            })
          })
      }
    }
  }
  ```

### onContextMenuShow<sup>9+</sup>

onContextMenuShow(callback: (event?: { param: WebContextMenuParam, result: WebContextMenuResult }) => boolean)

长按特定元素（例如图片，链接）或鼠标右键，跳出菜单。

**参数：**

| 参数名    | 参数类型                                     | 参数描述        |
| ------ | ---------------------------------------- | ----------- |
| param  | [WebContextMenuParam](#webcontextmenuparam9) | 菜单相关参数。     |
| result | [WebContextMenuResult](#webcontextmenuresult9) | 菜单相应事件传入内核。 |

**返回值：**

| 类型      | 说明                       |
| ------- | ------------------------ |
| boolean | 自定义菜单返回true，默认菜单返回false。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onContextMenuShow((event) => {
            console.info("x coord = " + event.param.x())
            console.info("link url = " + event.param.getLinkUrl())
            return true
        })
      }
    }
  }
  ```

### onScroll<sup>9+</sup>

onScroll(callback: (event: {xOffset: number, yOffset: number}) => void)

通知网页滚动条滚动位置。

**参数：**

| 参数名     | 参数类型   | 参数描述         |
| ------- | ------ | ------------ |
| xOffset | number | 以网页最左端为基准，水平滚动条滚动所在位置。 |
| yOffset | number | 以网页最上端为基准，竖直滚动条滚动所在位置。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
        .onScroll((event) => {
            console.info("x = " + event.xOffset)
            console.info("y = " + event.yOffset)
        })
      }
    }
  }
  ```

### onGeolocationShow

onGeolocationShow(callback: (event?: { origin: string, geolocation: JsGeolocation }) => void)

通知用户收到地理位置信息获取请求。

**参数：**

| 参数名         | 参数类型                            | 参数描述           |
| ----------- | ------------------------------- | -------------- |
| origin      | string                          | 指定源的字符串索引。     |
| geolocation | [JsGeolocation](#jsgeolocation) | 通知Web组件用户操作行为。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .geolocationAccess(true)
        .onGeolocationShow((event) => {
          AlertDialog.show({
            title: 'title',
            message: 'text',
            confirm: {
              value: 'onConfirm',
              action: () => {
                event.geolocation.invoke(event.origin, true, true)
              }
            },
            cancel: () => {
              event.geolocation.invoke(event.origin, false, true)
            }
          })
        })
      }
    }
  }
  ```

### onGeolocationHide

onGeolocationHide(callback: () => void)

通知用户先前被调用[onGeolocationShow](#ongeolocationshow)时收到地理位置信息获取请求已被取消。

**参数：**

| 参数名      | 参数类型       | 参数描述                 |
| -------- | ---------- | -------------------- |
| callback | () => void | 地理位置信息获取请求已被取消的回调函数。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .geolocationAccess(true)
        .onGeolocationHide(() => {
          console.log("onGeolocationHide...")
        })
      }
    }
  }
  ```

### onFullScreenEnter<sup>9+</sup>

onFullScreenEnter(callback: (event: { handler: FullScreenExitHandler }) => void)

通知开发者web组件进入全屏模式。

**参数：**

| 参数名     | 参数类型                                     | 参数描述           |
| ------- | ---------------------------------------- | -------------- |
| handler | [FullScreenExitHandler](#fullscreenexithandler9) | 用于退出全屏模式的函数句柄。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    handler: FullScreenExitHandler = null
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .onFullScreenEnter((event) => {
          console.log("onFullScreenEnter...")
          this.handler = event.handler
        })
      }
    }
  }
  ```

### onFullScreenExit<sup>9+</sup>

onFullScreenExit(callback: () => void)

通知开发者web组件退出全屏模式。

**参数：**

| 参数名      | 参数类型       | 参数描述          |
| -------- | ---------- | ------------- |
| callback | () => void | 退出全屏模式时的回调函数。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    handler: FullScreenExitHandler = null
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .onFullScreenExit(() => {
          console.log("onFullScreenExit...")
          this.handler.exitFullScreen()
        })
        .onFullScreenEnter((event) => {
          this.handler = event.handler
        })
      }
    }
  }
  ```

### onWindowNew<sup>9+</sup>

onWindowNew(callback: (event: {isAlert: boolean, isUserTrigger: boolean, targetUrl: string, handler: ControllerHandler}) => void)

使能multiWindowAccess情况下，通知用户新建窗口请求。
若不调用event.handler.setWebController接口，会造成render进程阻塞。
如果不需要打开新窗口，在调用event.handler.setWebController接口时须设置成null。

**参数：**

| 参数名           | 参数类型                                     | 参数描述                       |
| ------------- | ---------------------------------------- | -------------------------- |
| isAlert       | boolean                                  | true代表请求创建对话框，false代表新标签页。 |
| isUserTrigger | boolean                                  | true代表用户触发，false代表非用户触发。   |
| targetUrl     | string                                   | 目标url。                     |
| handler       | [ControllerHandler](#controllerhandler9) | 用于设置新建窗口的WebviewController实例。  |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  
  //在同一page页有两个web组件。在WebComponent新开窗口时，会跳转到NewWebViewComp。
  @CustomDialog
  struct NewWebViewComp {
  controller: CustomDialogController
  webviewController1: web_webview.WebviewController
  build() {
      Column() {
        Web({ src: "", controller: this.webviewController1 })
          .javaScriptAccess(true)
          .multiWindowAccess(false)
          .onWindowExit(()=> {
            console.info("NewWebViewComp onWindowExit")
            this.controller.close()
          })
        }
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    dialogController: CustomDialogController = null
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          //需要使能multiWindowAccess
          .multiWindowAccess(true)
          .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close()
            }
            let popController:web_webview.WebviewController = new web_webview.WebviewController()
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({webviewController1: popController})
            })
            this.dialogController.open()
            //将新窗口对应WebviewController返回给Web内核。
            //如果不需要打开新窗口请调用event.handler.setWebController接口设置成null。
            //若不调用event.handler.setWebController接口，会造成render进程阻塞。
            event.handler.setWebController(popController)
          })
      }
    }
  }
  ```

### onWindowExit<sup>9+</sup>

onWindowExit(callback: () => void)

通知用户窗口关闭请求。

**参数：**

| 参数名      | 参数类型       | 参数描述         |
| -------- | ---------- | ------------ |
| callback | () => void | 窗口请求关闭的回调函数。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
        .onWindowExit(() => {
          console.log("onWindowExit...")
        })
      }
    }
  }
  ```

### onSearchResultReceive<sup>9+</sup>

onSearchResultReceive(callback: (event?: {activeMatchOrdinal: number, numberOfMatches: number, isDoneCounting: boolean}) => void): WebAttribute

回调通知调用方网页页内查找的结果。

**参数：**

| 参数名                | 参数类型    | 参数描述                                     |
| ------------------ | ------- | ---------------------------------------- |
| activeMatchOrdinal | number  | 当前匹配的查找项的序号（从0开始）。                       |
| numberOfMatches    | number  | 所有匹配到的关键词的个数。                            |
| isDoneCounting     | boolean | 当次页内查找操作是否结束。该方法可能会回调多次，直到isDoneCounting为true为止。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
     	  .onSearchResultReceive(ret => {
            console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
              "[total]" + ret.numberOfMatches + "[isDone]"+ ret.isDoneCounting)
          })
      }
    }
  }
  ```

### onDataResubmitted<sup>9+</sup>

onDataResubmitted(callback: (event: {handler: DataResubmissionHandler}) => void)

设置网页表单可以重新提交时触发的回调函数。

**参数：**

| 参数名  | 参数类型                                             | 参数描述               |
| ------- | ---------------------------------------------------- | ---------------------- |
| handler | [DataResubmissionHandler](#dataresubmissionhandler9) | 表单数据重新提交句柄。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onDataResubmitted((event) => {
          console.log('onDataResubmitted')
          event.handler.resend();
        })
      }
    }
  }
  ```

### onPageVisible<sup>9+</sup>

onPageVisible(callback: (event: {url: string}) => void)

设置旧页面不再呈现，新页面即将可见时触发的回调函数。

**参数：**

| 参数名 | 参数类型 | 参数描述                                          |
| ------ | -------- | ------------------------------------------------- |
| url    | string   | 旧页面不再呈现，新页面即将可见时新页面的url地址。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onPageVisible((event) => {
          console.log('onPageVisible url:' + event.url)
        })
      }
    }
  }
  ```

### onInterceptKeyEvent<sup>9+</sup>

onInterceptKeyEvent(callback: (event: KeyEvent) => boolean)

设置键盘事件的回调函数，该回调在被Webview使用前触发。

**参数：**

| 参数名 | 参数类型                                                | 参数描述             |
| ------ | ------------------------------------------------------- | -------------------- |
| event  | [KeyEvent](ts-universal-events-key.md#keyevent对象说明) | 触发的KeyEvent事件。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 回调函数通过返回boolean类型值来决定是否继续将该KeyEvent传入Webview内核。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onInterceptKeyEvent((event) => {
          if (event.keyCode == 2017 || event.keyCode == 2018) {
            console.info(`onInterceptKeyEvent get event.keyCode ${event.keyCode}`)
            return true;
          }
          return false;
        })
      }
    }
  }
  ```

### onTouchIconUrlReceived<sup>9+</sup>

onTouchIconUrlReceived(callback: (event: {url: string, precomposed: boolean}) => void)

设置接收到apple-touch-icon url地址时的回调函数。

**参数：**

| 参数名      | 参数类型 | 参数描述                           |
| ----------- | -------- | ---------------------------------- |
| url         | string   | 接收到的apple-touch-icon url地址。 |
| precomposed | boolean  | 对应apple-touch-icon是否为预合成。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.baidu.com', controller: this.controller })
         .onTouchIconUrlReceived((event) => {
          console.log('onTouchIconUrlReceived:' + JSON.stringify(event))
        })
      }
    }
  }
  ```

### onFaviconReceived<sup>9+</sup>

onFaviconReceived(callback: (event: {favicon: image.PixelMap}) => void)

设置应用为当前页面接收到新的favicon时的回调函数。

**参数：**

| 参数名  | 参数类型                                       | 参数描述                            |
| ------- | ---------------------------------------------- | ----------------------------------- |
| favicon | [PixelMap](../apis/js-apis-image.md#pixelmap7) | 接收到的favicon图标的PixelMap对象。 |

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  import image from "@ohos.multimedia.image"
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    @State icon: image.PixelMap = undefined;
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onFaviconReceived((event) => {
          console.log('onFaviconReceived');
          this.icon = event.favicon;
        })
      }
    }
  }
  ```

### onRequestSelected

onRequestSelected(callback: () => void)

当Web组件获得焦点时触发该回调。

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onRequestSelected(() => {
            console.log('onRequestSelected')
          })
      }
    }
  }
  ```

## ConsoleMessage

Web组件获取控制台信息对象。示例代码参考[onConsole事件](#onconsole)。

### getLineNumber

getLineNumber(): number

获取ConsoleMessage的行数。

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 返回ConsoleMessage的行数。 |

### getMessage

getMessage(): string

获取ConsoleMessage的日志信息。

**返回值：**

| 类型     | 说明                     |
| ------ | ---------------------- |
| string | 返回ConsoleMessage的日志信息。 |

### getMessageLevel

getMessageLevel(): MessageLevel

获取ConsoleMessage的信息级别。

**返回值：**

| 类型                                | 说明                     |
| --------------------------------- | ---------------------- |
| [MessageLevel](#messagelevel枚举说明) | 返回ConsoleMessage的信息级别。 |

### getSourceId

getSourceId(): string

获取网页源文件路径和名字。

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回网页源文件路径和名字。 |

## JsResult

Web组件返回的弹窗确认或弹窗取消功能对象。示例代码参考[onAlert事件](#onalert)。

### handleCancel

handleCancel(): void

通知Web组件用户取消弹窗操作。

### handleConfirm

handleConfirm(): void

通知Web组件用户确认弹窗操作。

### handlePromptConfirm<sup>9+</sup>

handlePromptConfirm(result: string): void

通知Web组件用户确认弹窗操作及对话框内容。

**参数：**

| 参数名    | 参数类型   | 必填   | 默认值  | 参数描述        |
| ------ | ------ | ---- | ---- | ----------- |
| result | string | 是    | -    | 用户输入的对话框内容。 |

## FullScreenExitHandler<sup>9+</sup>

通知开发者Web组件退出全屏。示例代码参考[onFullScreenEnter事件](#onfullscreenenter9)。

### exitFullScreen<sup>9+</sup>

exitFullScreen(): void

通知开发者Web组件退出全屏。

## ControllerHandler<sup>9+</sup>

设置用户新建web组件的的WebviewController对象。示例代码参考[onWindowNew事件](#onwindownew9)。

### setWebController<sup>9+</sup>

setWebController(controller: WebviewController): void

设置WebviewController对象，如果不需要打开新窗口请设置为null。

**参数：**

| 参数名        | 参数类型          | 必填   | 默认值  | 参数描述                      |
| ---------- | ------------- | ---- | ---- | ------------------------- |
| controller | [WebviewController](../apis/js-apis-webview.md#webviewcontroller) | 是    | -    | 新建web组件的的WebviewController对象，如果不需要打开新窗口请设置为null。 |

## WebResourceError

web组件资源管理错误信息对象。示例代码参考[onErrorReceive事件](#onerrorreceive)。

### getErrorCode

getErrorCode(): number

获取加载资源的错误码。

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 返回加载资源的错误码。 |

### getErrorInfo

getErrorInfo(): string

获取加载资源的错误信息。

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 返回加载资源的错误信息。 |

## WebResourceRequest

web组件获取资源请求对象。示例代码参考[onErrorReceive事件](#onerrorreceive)。

### getRequestHeader

getResponseHeader() : Array\<Header\>

获取资源请求头信息。

**返回值：**

| 类型                         | 说明         |
| -------------------------- | ---------- |
| Array\<[Header](#header)\> | 返回资源请求头信息。 |

### getRequestUrl

getRequestUrl(): string

获取资源请求的URL信息。

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源请求的URL信息。 |

### isMainFrame

isMainFrame(): boolean

判断资源请求是否为主frame。

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否为主frame。 |

### isRedirect

isRedirect(): boolean

判断资源请求是否被服务端重定向。

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否被服务端重定向。 |

### isRequestGesture

isRequestGesture(): boolean

获取资源请求是否与手势（如点击）相关联。

**返回值：**

| 类型      | 说明                   |
| ------- | -------------------- |
| boolean | 返回资源请求是否与手势（如点击）相关联。 |

### getRequestMethod<sup>9+</sup>

getRequestMethod(): string

获取请求方法。

**返回值：**

| 类型      | 说明                   |
| ------- | -------------------- |
| string | 返回请求方法。 |

## Header

Web组件返回的请求/响应头对象。

| 名称          | 类型     | 描述            |
| ----------- | ------ | ------------- |
| headerKey   | string | 请求/响应头的key。   |
| headerValue | string | 请求/响应头的value。 |


## WebResourceResponse

web组件资源响应对象。示例代码参考[onHttpErrorReceive事件](#onhttperrorreceive)。

### getReasonMessage

getReasonMessage(): string

获取资源响应的状态码描述。

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源响应的状态码描述。 |

### getResponseCode

getResponseCode(): number

获取资源响应的状态码。

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 返回资源响应的状态码。 |

### getResponseData

getResponseData(): string

获取资源响应数据。

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| string | 返回资源响应数据。 |

### getResponseEncoding

getResponseEncoding(): string

获取资源响应的编码。

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回资源响应的编码。 |

### getResponseHeader

getResponseHeader() : Array\<Header\>

获取资源响应头。

**返回值：**

| 类型                         | 说明       |
| -------------------------- | -------- |
| Array\<[Header](#header)\> | 返回资源响应头。 |

### getResponseMimeType

getResponseMimeType(): string

获取资源响应的媒体（MIME）类型。

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| string | 返回资源响应的媒体（MIME）类型。 |

### setResponseData<sup>9+</sup>

setResponseData(data: string | number)

设置资源响应数据。

**参数：**

| 参数名 | 参数类型         | 必填 | 默认值 | 参数描述                                                     |
| ------ | ---------------- | ---- | ------ | ------------------------------------------------------------ |
| data   | string \| number | 是   | -      | 要设置的资源响应数据。string表示输入类型是字符串，number表示输入类型是文件句柄。 |

### setResponseEncoding<sup>9+</sup>

setResponseEncoding(encoding: string)

设置资源响应的编码。

**参数：**

| 参数名      | 参数类型   | 必填   | 默认值  | 参数描述         |
| -------- | ------ | ---- | ---- | ------------ |
| encoding | string | 是    | -    | 要设置的资源响应的编码。 |

### setResponseMimeType<sup>9+</sup>

setResponseMimeType(mimeType: string)

设置资源响应的媒体（MIME）类型。

**参数：**

| 参数名      | 参数类型   | 必填   | 默认值  | 参数描述                 |
| -------- | ------ | ---- | ---- | -------------------- |
| mimeType | string | 是    | -    | 要设置的资源响应的媒体（MIME）类型。 |

### setReasonMessage<sup>9+</sup>

setReasonMessage(reason: string)

设置资源响应的状态码描述。

**参数：**

| 参数名    | 参数类型   | 必填   | 默认值  | 参数描述            |
| ------ | ------ | ---- | ---- | --------------- |
| reason | string | 是    | -    | 要设置的资源响应的状态码描述。 |

### setResponseHeader<sup>9+</sup>

setResponseHeader(header: Array\<Header\>)

设置资源响应头。

**参数：**

| 参数名    | 参数类型                       | 必填   | 默认值  | 参数描述       |
| ------ | -------------------------- | ---- | ---- | ---------- |
| header | Array\<[Header](#header)\> | 是    | -    | 要设置的资源响应头。 |

### setResponseCode<sup>9+</sup>

setResponseCode(code: number)

设置资源响应的状态码。

**参数：**

| 参数名  | 参数类型   | 必填   | 默认值  | 参数描述          |
| ---- | ------ | ---- | ---- | ------------- |
| code | number | 是    | -    | 要设置的资源响应的状态码。 |

### setResponseIsReady<sup>9+</sup>

setResponseIsReady(IsReady: boolean)

设置资源响应数据是否已经就绪。

**参数：**

| 参数名  | 参数类型 | 必填 | 默认值 | 参数描述                   |
| ------- | -------- | ---- | ------ | -------------------------- |
| IsReady | boolean  | 是   | true   | 资源响应数据是否已经就绪。 |

## FileSelectorResult<sup>9+</sup>

通知Web组件的文件选择结果。示例代码参考[onShowFileSelector事件](#onshowfileselector9)。

### handleFileList<sup>9+</sup>

handleFileList(fileList: Array\<string\>): void

通知Web组件进行文件选择操作。

**参数：**

| 参数名      | 参数类型            | 必填   | 默认值  | 参数描述         |
| -------- | --------------- | ---- | ---- | ------------ |
| fileList | Array\<string\> | 是    | -    | 需要进行操作的文件列表。 |

## FileSelectorParam<sup>9+</sup>

web组件获取文件对象。示例代码参考[onShowFileSelector事件](#onshowfileselector9)。

### getTitle<sup>9+</sup>

getTitle(): string

获取文件选择器标题。

**返回值：**

| 类型     | 说明       |
| ------ | -------- |
| string | 返回文件选择器标题。 |

### getMode<sup>9+</sup>

getMode(): FileSelectorMode

获取文件选择器的模式。

**返回值：**

| 类型                                       | 说明          |
| ---------------------------------------- | ----------- |
| [FileSelectorMode](#fileselectormode枚举说明) | 返回文件选择器的模式。 |

### getAcceptType<sup>9+</sup>

getAcceptType(): Array\<string\>

获取文件过滤类型。

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<string\> | 返回文件过滤类型。 |

### isCapture<sup>9+</sup>

isCapture(): boolean

获取是否调用多媒体能力。

**返回值：**

| 类型      | 说明           |
| ------- | ------------ |
| boolean | 返回是否调用多媒体能力。 |

## HttpAuthHandler<sup>9+</sup>

Web组件返回的http auth认证请求确认或取消和使用缓存密码认证功能对象。示例代码参考[onHttpAuthRequest事件](#onhttpauthrequest9)。

### cancel<sup>9+</sup>

cancel(): void

通知Web组件用户取消HTTP认证操作。

### confirm<sup>9+</sup>

confirm(userName: string, pwd: string): boolean

使用用户名和密码进行HTTP认证操作。

**参数：**

| 参数名      | 参数类型   | 必填   | 默认值  | 参数描述       |
| -------- | ------ | ---- | ---- | ---------- |
| userName | string | 是    | -    | HTTP认证用户名。 |
| pwd      | string | 是    | -    | HTTP认证密码。  |

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 认证成功返回true，失败返回false。 |

### isHttpAuthInfoSaved<sup>9+</sup>

isHttpAuthInfoSaved(): boolean

通知Web组件用户使用服务器缓存的帐号密码认证。

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 存在密码认证成功返回true，其他返回false。 |

## SslErrorHandler<sup>9+</sup>

Web组件返回的SSL错误通知事件用户处理功能对象。示例代码参考[onSslErrorEventReceive事件](#onsslerroreventreceive9)。

### handleCancel<sup>9+</sup>

handleCancel(): void

通知Web组件取消此请求。

### handleConfirm<sup>9+</sup>

handleConfirm(): void

通知Web组件继续使用SSL证书。

## ClientAuthenticationHandler<sup>9+</sup>

Web组件返回的SSL客户端证书请求事件用户处理功能对象。示例代码参考[onClientAuthenticationRequest事件](#onclientauthenticationrequest9)。

### confirm<sup>9+</sup>

confirm(priKeyFile : string, certChainFile : string): void

通知Web组件使用指定的私钥和客户端证书链。

**参数：**

| 参数名           | 参数类型   | 必填   | 参数描述               |
| ------------- | ------ | ---- | ------------------ |
| priKeyFile    | string | 是    | 存放私钥的文件，包含路径和文件名。  |
| certChainFile | string | 是    | 存放证书链的文件，包含路径和文件名。 |

### cancel<sup>9+</sup>

cancel(): void

通知Web组件取消相同host和port服务器发送的客户端证书请求事件。同时，相同host和port服务器的请求，不重复上报该事件。

### ignore<sup>9+</sup>

ignore(): void

通知Web组件忽略本次请求。

## PermissionRequest<sup>9+</sup>

Web组件返回授权或拒绝权限功能的对象。示例代码参考[onPermissionRequest事件](#onpermissionrequest9)。

### deny<sup>9+</sup>

deny(): void

拒绝网页所请求的权限。

### getOrigin<sup>9+</sup>

getOrigin(): string

获取网页来源。

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 当前请求权限网页的来源。 |

### getAccessibleResource<sup>9+</sup>

getAccessibleResource(): Array\<string\>

获取网页所请求的权限资源列表，资源列表类型参考[ProtectedResourceType](#protectedresourcetype9枚举说明)。

**返回值：**

| 类型              | 说明            |
| --------------- | ------------- |
| Array\<string\> | 网页所请求的权限资源列表。 |

### grant<sup>9+</sup>

grant(resources: Array\<string\>): void

对网页访问的给定权限进行授权。

**参数：**

| 参数名       | 参数类型            | 必填   | 默认值  | 参数描述          |
| --------- | --------------- | ---- | ---- | ------------- |
| resources | Array\<string\> | 是    | -    | 授予网页请求的权限的资源列表。 |

## ContextMenuSourceType<sup>9+</sup>枚举说明
| 名称                   | 描述         |
| -------------------- | ---------- |
| None        | 其他事件来源。  |
| Mouse       | 鼠标事件。  |
| LongPress   | 长按事件。  |

## ContextMenuMediaType<sup>9+</sup>枚举说明

| 名称           | 描述          |
| ------------ | ----------- |
| None      | 非特殊媒体或其他媒体类型。 |
| Image     | 图片。     |

## ContextMenuInputFieldType<sup>9+</sup>枚举说明

| 名称           | 描述          |
| ------------ | ----------- |
| None      | 非输入框。       |
| PlainText | 纯文本类型，包括text、search、email等。   |
| Password  | 密码类型。     |
| Number    | 数字类型。     |
| Telephone | 电话号码类型。 |
| Other     | 其他类型。     |

## ContextMenuEditStateFlags<sup>9+</sup>枚举说明

| 名称         | 描述         |
| ------------ | ----------- |
| NONE         | 不可编辑。   |
| CAN_CUT      | 支持剪切。   |
| CAN_COPY     | 支持拷贝。   |
| CAN_PASTE    | 支持粘贴。   |
| CAN_SELECT_ALL  | 支持全选。 |

## WebContextMenuParam<sup>9+</sup>

实现长按页面元素或鼠标右键弹出来的菜单信息。示例代码参考[onContextMenuShow事件](#oncontextmenushow9)。

### x<sup>9+</sup>

x(): number

弹出菜单的x坐标。

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| number | 显示正常返回非负整数，否则返回-1。 |

### y<sup>9+</sup>

y(): number

弹出菜单的y坐标。

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| number | 显示正常返回非负整数，否则返回-1。 |

### getLinkUrl<sup>9+</sup>

getLinkUrl(): string

获取链接地址。

**返回值：**

| 类型     | 说明                        |
| ------ | ------------------------- |
| string | 如果长按位置是链接，返回经过安全检查的url链接。 |

### getUnfilteredLinkUrl<sup>9+</sup>

getUnfilteredLinkUrl(): string

获取链接地址。

**返回值：**

| 类型     | 说明                    |
| ------ | --------------------- |
| string | 如果长按位置是链接，返回原始的url链接。 |

### getSourceUrl<sup>9+</sup>

getSourceUrl(): string

获取sourceUrl链接。

**返回值：**

| 类型     | 说明                       |
| ------ | ------------------------ |
| string | 如果选中的元素有src属性，返回src的url。 |

### existsImageContents<sup>9+</sup>

existsImageContents(): boolean

是否存在图像内容。

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 长按位置中有图片返回true，否则返回false。 |

### getMediaType<sup>9+</sup>

getMediaType(): ContextMenuMediaType

获取网页元素媒体类型。

**返回值：**

| 类型                                       | 说明          |
| ---------------------------------------- | ----------- |
| [ContextMenuMediaType](#contextmenumediatype9枚举说明) | 网页元素媒体类型。 |

### getSelectionText<sup>9+</sup>

getSelectionText(): string

获取选中文本。

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| string | 菜单上下文选中文本内容，不存在则返回空。 |

### getSourceType<sup>9+</sup>

getSourceType(): ContextMenuSourceType

获取菜单事件来源。

**返回值：**

| 类型                                       | 说明          |
| ---------------------------------------- | ----------- |
| [ContextMenuSourceType](#contextmenusourcetype9枚举说明) | 菜单事件来源。 |

### getInputFieldType<sup>9+</sup>

getInputFieldType(): ContextMenuInputFieldType

获取网页元素输入框类型。

**返回值：**

| 类型                                       | 说明          |
| ---------------------------------------- | ----------- |
| [ContextMenuInputFieldType](#contextmenuinputfieldtype9枚举说明) | 输入框类型。 |

### isEditable<sup>9+</sup>

isEditable(): boolean

获取网页元素是否可编辑标识。

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 网页元素可编辑返回true，不可编辑返回false。 |

### getEditStateFlags<sup>9+</sup>

getEditStateFlags(): number

获取网页元素可编辑标识。

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| number | 网页元素可编辑标识，参照[ContextMenuEditStateFlags](#contextmenueditstateflags9枚举说明)。 |

## WebContextMenuResult<sup>9+</sup>

实现长按页面元素或鼠标右键弹出来的菜单所执行的响应事件。示例代码参考[onContextMenuShow事件](#oncontextmenushow9)。

### closeContextMenu<sup>9+</sup>

closeContextMenu(): void

不执行WebContextMenuResult其他接口操作时，需要调用此接口关闭菜单。

### copyImage<sup>9+</sup>

copyImage(): void

WebContextMenuParam有图片内容则复制图片。

### copy<sup>9+</sup>

copy(): void

执行与此上下文菜单相关的拷贝操作。

### paste<sup>9+</sup>

paste(): void

执行与此上下文菜单相关的粘贴操作。

### cut<sup>9+</sup>

cut(): void

执行与此上下文菜单相关的剪切操作。

### selectAll<sup>9+</sup>

selectAll(): void

执行与此上下文菜单相关的全选操作。

## JsGeolocation

Web组件返回授权或拒绝权限功能的对象。示例代码参考[onGeolocationShow事件](#ongeolocationshow)。

### invoke

invoke(origin: string, allow: boolean, retain: boolean): void

设置网页地理位置权限状态。

**参数：**

| 参数名    | 参数类型    | 必填   | 默认值  | 参数描述                                     |
| ------ | ------- | ---- | ---- | ---------------------------------------- |
| origin | string  | 是    | -    | 指定源的字符串索引。                               |
| allow  | boolean | 是    | -    | 设置的地理位置权限状态。                             |
| retain | boolean | 是    | -    | 是否允许将地理位置权限状态保存到系统中。可通过[GeolocationPermissions<sup>9+</sup>](../apis/js-apis-webview.md#geolocationpermissions)接口管理保存到系统的地理位置权限。 |

## MessageLevel枚举说明

| 名称    | 描述    |
| ----- | :---- |
| Debug | 调试级别。 |
| Error | 错误级别。 |
| Info  | 消息级别。 |
| Log   | 日志级别。 |
| Warn  | 警告级别。 |

## RenderExitReason枚举说明

onRenderExited接口返回的渲染进程退出的具体原因。

| 名称                         | 描述                |
| -------------------------- | ----------------- |
| ProcessAbnormalTermination | 渲染进程异常退出。         |
| ProcessWasKilled           | 收到SIGKILL，或被手动终止。 |
| ProcessCrashed             | 渲染进程崩溃退出，如段错误。    |
| ProcessOom                 | 程序内存不足。           |
| ProcessExitUnknown         | 其他原因。             |

## MixedMode枚举说明

| 名称         | 描述                                 |
| ---------- | ---------------------------------- |
| All        | 允许加载HTTP和HTTPS混合内容。所有不安全的内容都可以被加载。 |
| Compatible | 混合内容兼容性模式，部分不安全的内容可能被加载。           |
| None       | 不允许加载HTTP和HTTPS混合内容。               |

## CacheMode枚举说明
| 名称      | 描述                                   |
| ------- | ------------------------------------ |
| Default | 使用未过期的cache加载资源，如果cache中无该资源则从网络中获取。 |
| None    | 加载资源使用cache，如果cache中无该资源则从网络中获取。     |
| Online  | 加载资源不使用cache，全部从网络中获取。               |
| Only    | 只从cache中加载资源。                        |

## FileSelectorMode枚举说明
| 名称                   | 描述         |
| -------------------- | ---------- |
| FileOpenMode         | 打开上传单个文件。  |
| FileOpenMultipleMode | 打开上传多个文件。  |
| FileOpenFolderMode   | 打开上传文件夹模式。 |
| FileSaveMode         | 文件保存模式。    |

 ## HitTestType枚举说明

| 名称            | 描述                       |
| ------------- | ------------------------ |
| EditText      | 可编辑的区域。                  |
| Email         | 电子邮件地址。                  |
| HttpAnchor    | 超链接，其src为http。           |
| HttpAnchorImg | 带有超链接的图片，其中超链接的src为http。 |
| Img           | HTML::img标签。             |
| Map           | 地理地址。                    |
| Phone         | 电话号码。                    |
| Unknown       | 未知内容。                    |

## SslError<sup>9+</sup>枚举说明

onSslErrorEventReceive接口返回的SSL错误的具体原因。

| 名称           | 描述          |
| ------------ | ----------- |
| Invalid      | 一般错误。       |
| HostMismatch | 主机名不匹配。     |
| DateInvalid  | 证书日期无效。     |
| Untrusted    | 证书颁发机构不受信任。 |

## ProtectedResourceType<sup>9+</sup>枚举说明

| 名称        | 描述            | 备注                         |
| --------- | ------------- | -------------------------- |
| MidiSysex | MIDI SYSEX资源。 | 目前仅支持权限事件上报，MIDI设备的使用还未支持。 |

## WebDarkMode<sup>9+</sup>枚举说明
| 名称      | 描述                                   |
| ------- | ------------------------------------ |
| Off     | Web深色模式关闭。                     |
| On      | Web深色模式开启。                     |
| Auto    | Web深色模式跟随系统。                 |

## DataResubmissionHandler<sup>9+</sup>

通过DataResubmissionHandler可以重新提交表单数据或取消提交表单数据。

### resend<sup>9+</sup>

resend(): void

重新发送表单数据。

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onDataResubmitted((event) => {
          console.log('onDataResubmitted')
          event.handler.resend();
        })
      }
    }
  }
  ```

### cancel<sup>9+</sup>

cancel(): void

取消重新发送表单数据。

**示例：**

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src:'www.example.com', controller: this.controller })
         .onDataResubmitted((event) => {
          console.log('onDataResubmitted')
          event.handler.cancel();
        })
      }
    }
  }
  ```

  ## WebController

通过WebController可以控制Web组件各种行为。一个WebController对象只能控制一个Web组件，且必须在Web组件和WebController绑定后，才能调用WebController上的方法。

从API version 9开始不再维护，建议使用[WebviewController<sup>9+</sup>](../apis/js-apis-webview.md#webviewcontroller)代替。

### 创建对象

```
webController: WebController = new WebController()
```

### getCookieManager<sup>9+</sup>

getCookieManager(): WebCookie

获取web组件cookie管理对象。

**返回值：**

| 类型        | 说明                                       |
| --------- | ---------------------------------------- |
| WebCookie | web组件cookie管理对象，参考[WebCookie](#webcookiedeprecated)定义。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('getCookieManager')
          .onClick(() => {
            let cookieManager = this.controller.getCookieManager()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### requestFocus<sup>(deprecated)</sup>

requestFocus()

使当前web页面获取焦点。

从API version 9开始不再维护，建议使用[requestFocus<sup>9+</sup>](../apis/js-apis-webview.md#requestfocus)代替。

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('requestFocus')
          .onClick(() => {
            this.controller.requestFocus()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessBackward<sup>(deprecated)</sup>

accessBackward(): boolean

当前页面是否可后退，即当前页面是否有返回历史记录。

从API version 9开始不再维护，建议使用[accessBackward<sup>9+</sup>](../apis/js-apis-webview.md#accessbackward)代替。

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 可以后退返回true,否则返回false。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('accessBackward')
          .onClick(() => {
            let result = this.controller.accessBackward()
            console.log('result:' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessForward<sup>(deprecated)</sup>

accessForward(): boolean

当前页面是否可前进，即当前页面是否有前进历史记录。

从API version 9开始不再维护，建议使用[accessForward<sup>9+</sup>](../apis/js-apis-webview.md#accessforward)代替。

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 可以前进返回true,否则返回false。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('accessForward')
          .onClick(() => {
            let result = this.controller.accessForward()
            console.log('result:' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessStep<sup>(deprecated)</sup>

accessStep(step: number): boolean

当前页面是否可前进或者后退给定的step步。

从API version 9开始不再维护，建议使用[accessStep<sup>9+</sup>](../apis/js-apis-webview.md#accessstep)代替。

**参数：**

| 参数名  | 参数类型   | 必填   | 默认值  | 参数描述                  |
| ---- | ------ | ---- | ---- | --------------------- |
| step | number | 是    | -    | 要跳转的步数，正数代表前进，负数代表后退。 |

**返回值：**

| 类型      | 说明        |
| ------- | --------- |
| boolean | 页面是否前进或后退 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State steps: number = 2

    build() {
      Column() {
        Button('accessStep')
          .onClick(() => {
            let result = this.controller.accessStep(this.steps)
            console.log('result:' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### backward<sup>(deprecated)</sup>

backward(): void

按照历史栈，后退一个页面。一般结合accessBackward一起使用。

从API version 9开始不再维护，建议使用[backward<sup>9+</sup>](../apis/js-apis-webview.md#backward)代替。

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('backward')
          .onClick(() => {
            this.controller.backward()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### forward<sup>(deprecated)</sup>

forward(): void

按照历史栈，前进一个页面。一般结合accessForward一起使用。

从API version 9开始不再维护，建议使用[forward<sup>9+</sup>](../apis/js-apis-webview.md#forward)代替。

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('forward')
          .onClick(() => {
            this.controller.forward()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteJavaScriptRegister<sup>(deprecated)</sup>

deleteJavaScriptRegister(name: string)

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。删除后立即生效，无须调用[refresh](#refreshdeprecated)接口。

从API version 9开始不再维护，建议使用[deleteJavaScriptRegister<sup>9+</sup>](../apis/js-apis-webview.md#deletejavascriptregister)代替。

**参数：**

| 参数名  | 参数类型   | 必填   | 默认值  | 参数描述                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| name | string | 是    | -    | 注册对象的名称，可在网页侧JavaScript中通过此名称调用应用侧JavaScript对象。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State name: string = 'Object'

    build() {
      Column() {
        Button('deleteJavaScriptRegister')
          .onClick(() => {
            this.controller.deleteJavaScriptRegister(this.name)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getHitTest<sup>(deprecated)</sup>

getHitTest(): HitTestType

获取当前被点击区域的元素类型。

从API version 9开始不再维护，建议使用[getHitTest<sup>9+</sup>](../apis/js-apis-webview.md#gethittest)代替。

**返回值：**

| 类型                              | 说明          |
| ------------------------------- | ----------- |
| [HitTestType](#hittesttype枚举说明) | 被点击区域的元素类型。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('getHitTest')
          .onClick(() => {
            let hitType = this.controller.getHitTest()
            console.log("hitType: " + hitType)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### loadData<sup>(deprecated)</sup>

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string })

baseUrl为空时，通过”data“协议加载指定的一段字符串。

当baseUrl为”data“协议时，编码后的data字符串将被Web组件作为”data"协议加载。

当baseUrl为“http/https"协议时，编码后的data字符串将被Web组件以类似loadUrl的方式以非编码字符串处理。

从API version 9开始不再维护，建议使用[loadData<sup>9+</sup>](../apis/js-apis-webview.md#loaddata)代替。

**参数：**

| 参数名        | 参数类型   | 必填   | 默认值  | 参数描述                                     |
| ---------- | ------ | ---- | ---- | ---------------------------------------- |
| data       | string | 是    | -    | 按照”Base64“或者”URL"编码后的一段字符串。              |
| mimeType   | string | 是    | -    | 媒体类型（MIME）。                              |
| encoding   | string | 是    | -    | 编码类型，具体为“Base64"或者”URL编码。                |
| baseUrl    | string | 否    | -    | 指定的一个URL路径（“http”/“https”/"data"协议），并由Web组件赋值给window.origin。 |
| historyUrl | string | 否    | -    | 历史记录URL。非空时，可被历史记录管理，实现前后后退功能。当baseUrl为空时，此属性无效。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('loadData')
          .onClick(() => {
            this.controller.loadData({
              data: "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>",
              mimeType: "text/html",
              encoding: "UTF-8"
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### loadUrl<sup>(deprecated)</sup>

loadUrl(options: { url: string | Resource, headers?: Array\<Header\> })

使用指定的http头加载指定的URL。

通过loadUrl注入的对象只在当前document有效，即通过loadUrl导航到新的页面会无效。

而通过registerJavaScriptProxy注入的对象，在loadUrl导航到新的页面也会有效。

从API version 9开始不再维护，建议使用[loadUrl<sup>9+</sup>](../apis/js-apis-webview.md#loadurl)代替。

**参数：**

| 参数名     | 参数类型                       | 必填   | 默认值  | 参数描述           |
| ------- | -------------------------- | ---- | ---- | -------------- |
| url     | string                     | 是    | -    | 需要加载的 URL。     |
| headers | Array\<[Header](#header)\> | 否    | []   | URL的附加HTTP请求头。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('loadUrl')
          .onClick(() => {
            this.controller.loadUrl({ url: 'www.example.com' })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### onActive<sup>(deprecated)</sup>

onActive(): void

调用此接口通知Web组件进入前台激活状态。

从API version 9开始不再维护，建议使用[onActive<sup>9+</sup>](../apis/js-apis-webview.md#onactive)代替。

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('onActive')
          .onClick(() => {
            this.controller.onActive()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### onInactive<sup>(deprecated)</sup>

onInactive(): void

调用此接口通知Web组件进入未激活状态。

从API version 9开始不再维护，建议使用[onInactive<sup>9+</sup>](../apis/js-apis-webview.md#oninactive)代替。

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('onInactive')
          .onClick(() => {
            this.controller.onInactive()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### zoom<sup>(deprecated)</sup>
zoom(factor: number): void

调整当前网页的缩放比例。

从API version 9开始不再维护，建议使用[zoom<sup>9+</sup>](../apis/js-apis-webview.md#zoom)代替。

**参数：**

| 参数名    | 参数类型   | 必填   | 参数描述                           |
| ------ | ------ | ---- | ------------------------------ |
| factor | number | 是    | 基于当前网页所需调整的相对缩放比例，正值为放大，负值为缩小。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State factor: number = 1

    build() {
      Column() {
        Button('zoom')
          .onClick(() => {
            this.controller.zoom(this.factor)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### refresh<sup>(deprecated)</sup>

refresh()

调用此接口通知Web组件刷新网页。

从API version 9开始不再维护，建议使用[refresh<sup>9+</sup>](../apis/js-apis-webview.md#refresh)代替。

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('refresh')
          .onClick(() => {
            this.controller.refresh()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### registerJavaScriptProxy<sup>(deprecated)</sup>

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> })

注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。注册后，须调用[refresh](#refreshdeprecated)接口生效。

从API version 9开始不再维护，建议使用[registerJavaScriptProxy<sup>9+</sup>](../apis/js-apis-webview.md#registerjavascriptproxy)代替。

**参数：**

| 参数名        | 参数类型            | 必填   | 默认值  | 参数描述                                     |
| ---------- | --------------- | ---- | ---- | ---------------------------------------- |
| object     | object          | 是    | -    | 参与注册的应用侧JavaScript对象。只能声明方法，不能声明属性 。其中方法的参数和返回类型只能为string，number，boolean |
| name       | string          | 是    | -    | 注册对象的名称，与window中调用的对象名一致。注册后window对象可以通过此名字访问应用侧JavaScript对象。 |
| methodList | Array\<string\> | 是    | -    | 参与注册的应用侧JavaScript对象的方法。                 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Index {
    controller: WebController = new WebController()
    testObj = {
      test: (data) => {
        return "ArkUI Web Component"
      },
      toString: () => {
        console.log('Web Component toString')
      }
    }
    build() {
      Column() {
        Row() {
          Button('Register JavaScript To Window').onClick(() => {
            this.controller.registerJavaScriptProxy({
              object: this.testObj,
              name: "objName",
              methodList: ["test", "toString"],
            })
          })
        }
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .javaScriptAccess(true)
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
      <meta charset="utf-8">
      <body>
          Hello world!
      </body>
      <script type="text/javascript">
      function htmlTest() {
          str = objName.test("test function")
          console.log('objName.test result:'+ str)
      }
  </script>
  </html>

  ```

### runJavaScript<sup>(deprecated)</sup>

runJavaScript(options: { script: string, callback?: (result: string) => void })

异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

从API version 9开始不再维护，建议使用[runJavaScript<sup>9+</sup>](../apis/js-apis-webview.md#runjavascript)代替。

**参数：**

| 参数名      | 参数类型                     | 必填   | 默认值  | 参数描述                                     |
| -------- | ------------------------ | ---- | ---- | ---------------------------------------- |
| script   | string                   | 是    | -    | JavaScript脚本。                            |
| callback | (result: string) => void | 否    | -    | 回调执行JavaScript脚本结果。JavaScript脚本若执行失败或无返回值时，返回null。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State webResult: string = ''
    build() {
      Column() {
        Text(this.webResult).fontSize(20)
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .onPageEnd(e => {
          this.controller.runJavaScript({
            script: 'test()',
            callback: (result: string)=> {
              this.webResult = result
              console.info(`The test() return value is: ${result}`)
            }})
          console.info('url: ', e.url)
        })
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
    <meta charset="utf-8">
    <body>
        Hello world!
    </body>
    <script type="text/javascript">
    function test() {
        console.log('Ark WebComponent')
        return "This value is from index.html"
    }
    </script>
  </html>
  ```

### stop<sup>(deprecated)</sup>

stop()

停止页面加载。

从API version 9开始不再维护，建议使用[stop<sup>9+</sup>](../apis/js-apis-webview.md#stop)代替。

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('stop')
          .onClick(() => {
            this.controller.stop()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### clearHistory<sup>(deprecated)</sup>

clearHistory(): void

删除所有前进后退记录。

从API version 9开始不再维护，建议使用[clearHistory<sup>9+</sup>](../apis/js-apis-webview.md#clearhistory)代替。

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('clearHistory')
          .onClick(() => {
            this.controller.clearHistory()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

## WebCookie<sup>(deprecated)</sup>

通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有web组件共享一个WebCookie。通过controller方法中的getCookieManager方法可以获取WebCookie对象，进行后续的cookie管理操作。

### setCookie<sup>(deprecated)</sup>

setCookie(): boolean

设置cookie，该方法为同步方法。设置成功返回true，否则返回false。

从API version 9开始不再维护，建议使用[setCookie<sup>9+</sup>](../apis/js-apis-webview.md#setcookie)代替。

**返回值：**

| 类型      | 说明            |
| ------- | ------------- |
| boolean | 设置cookie是否成功。 |

### saveCookie<sup>(deprecated)</sup>

saveCookie(): boolean

将当前存在内存中的cookie同步到磁盘中，该方法为同步方法。

从API version 9开始不再维护，建议使用[saveCookieAsync<sup>9+</sup>](../apis/js-apis-webview.md#savecookieasync)代替。

**返回值：**

| 类型      | 说明                   |
| ------- | -------------------- |
| boolean | 同步内存cookie到磁盘操作是否成功。 |