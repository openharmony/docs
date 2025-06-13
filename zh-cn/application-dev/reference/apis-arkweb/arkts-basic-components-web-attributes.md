# 属性

通用属性仅支持[aspectRatio](../apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#aspectratio)、[backdropBlur](../apis-arkui/arkui-ts/ts-universal-attributes-background.md#backdropblur)、[backgroundColor](../apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor)、[bindContentCover](../apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover)、[bindContextMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu8)、[bindMenu ](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu)、[bindSheet](../apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)、[borderColor](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#bordercolor)、[borderRadius](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderradius)、[borderStyle](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderstyle)、[borderWidth](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderwidth)、[clip](../apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#clip)、[constraintSize](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#constraintsize)、[defaultFocus](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#defaultfocus9)、[focusable](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#focusable)、[tabIndex](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#tabindex9)、[groupDefaultFocus](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#groupdefaultfocus9)、[displayPriority](../apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#displaypriority)、[enabled](../apis-arkui/arkui-ts/ts-universal-attributes-enable.md#enabled)、[flexBasis](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexbasis)、[flexShrink](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexshrink)、[layoutWeight](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#layoutweight)、[id](../apis-arkui/arkui-ts/ts-universal-attributes-component-id.md)、[gridOffset](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md)、[gridSpan](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md)、[useSizeType](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md)、[height](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#height)、[touchable](../apis-arkui/arkui-ts/ts-universal-attributes-click.md)、[margin](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#margin)、[markAnchor](../apis-arkui/arkui-ts/ts-universal-attributes-location.md#markanchor)、[offset](../apis-arkui/arkui-ts/ts-universal-attributes-location.md#offset)、[width](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#width)、[zIndex](../apis-arkui/arkui-ts/ts-universal-attributes-z-order.md#zindex)、[visibility](../apis-arkui/arkui-ts/ts-universal-attributes-visibility.md#visibility)、[scale](../apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#scale)、[translate](../apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#translate)、[responseRegion](../apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md#responseregion)、[size](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#size)、[opacity](../apis-arkui/arkui-ts/ts-universal-attributes-opacity.md#opacity)、[shadow](../apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow)、[sharedTransition](../apis-arkui/arkui-ts/ts-transition-animation-shared-elements.md)、[transition](../apis-arkui/arkui-ts/ts-transition-animation-component.md)。

> **说明：**
>
> - 该组件从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## domStorageAccess

domStorageAccess(domStorageAccess: boolean)

设置是否开启文档对象模型存储接口（DOM Storage API）权限。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型    | 必填   | 说明                                 |
| ---------------- | ------- | ---- | ------------------------------------ |
| domStorageAccess | boolean | 是    | 设置是否开启文档对象模型存储接口（DOM Storage API）权限。<br>true表示开启文档对象模型存储接口权限，false表示不开启文档对象模型存储接口权限。<br>默认值：false。 |

> **说明：**
>
> - 网页中使用到文档对象模型存储接口（DOM Storage API），需将其设置为true，才可正常加载网页。

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .domStorageAccess(true)
      }
    }
  }
  ```

## fileAccess

fileAccess(fileAccess: boolean)

设置是否开启应用中文件系统的访问。[$rawfile(filepath/filename)](../../quick-start/resource-categories-and-access.md)中rawfile路径的文件不受该属性影响而限制访问。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型    | 必填   | 说明                   |
| ---------- | ------- | ---- | ---------------------- |
| fileAccess | boolean | 是    | 设置是否开启应用中文件系统的访问。<br>true表示启动应用中文件系统的访问。false表示不启用应用中文件系统的访问。<br>API version 11及以前：默认值：true。<br>API version 12及以后：默认值：false，同时，当fileAccess为false的时候，仅只读资源目录`/data/storage/el1/bundle/entry/resources/resfile`里面的file协议资源依然可以访问，不受fileAccess管控。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .fileAccess(true)
      }
    }
  }
  ```

## imageAccess

imageAccess(imageAccess: boolean)

设置是否允许自动加载图片资源。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名         | 类型    | 必填   | 说明            |
| ----------- | ------- | ---- | --------------- |
| imageAccess | boolean | 是    | 设置是否允许自动加载图片资源。<br>true表示设置允许自动加载图片资源，false表示设置不允许自动加载图片资源。<br>默认值：true。 |

**示例：**
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .imageAccess(true)
      }
    }
  }
  ```

## javaScriptProxy

javaScriptProxy(javaScriptProxy: JavaScriptProxy)

将javaScriptProxy中的ArkTS对象注册到Web组件中，该对象将使用JavaScriptProxy中指定的名称注册到网页的所有框架中，包括所有iframe，这使得JavaScript可以调用javaScriptProxy中ArkTS对象的方法。

> **说明：**
>
> javaScriptProxy接口需要和deleteJavaScriptRegister接口配合使用，防止内存泄漏。
> javaScriptProxy对象的所有参数不支持更新。
> 注册javaScriptProxy对象时，同步与异步列表请至少选择一项不为空，可同时注册两类方法。
> 此接口只支持注册一个对象，若需要注册多个对象请使用[registerJavaScriptProxy<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#registerjavascriptproxy)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型                                     | 必填   | 说明                                     |
| ---------- | ---------------------------------------- | ---- |---------------------------------------- |
| javaScriptProxy     | [JavaScriptProxy](./arkts-basic-components-web-i.md#javascriptproxy12)                                   | 是    |  参与注册的对象。只能声明方法，不能声明属性。                   |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  class TestObj {
    constructor() {
    }

    test(data1: string, data2: string, data3: string): string {
      console.log("data1:" + data1);
      console.log("data2:" + data2);
      console.log("data3:" + data3);
      return "AceString";
    }

    asyncTest(data: string): void {
      console.log("async data:" + data);
    }

    toString(): void {
      console.log('toString' + "interface instead.");
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    testObj = new TestObj();
    build() {
      Column() {
        Button('deleteJavaScriptRegister')
          .onClick(() => {
            try {
              this.controller.deleteJavaScriptRegister("objName");
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          .javaScriptProxy({
            object: this.testObj,
            name: "objName",
            methodList: ["test", "toString"],
            asyncMethodList: ["asyncTest"],
            controller: this.controller,
        })
      }
    }
  }
  ```

## javaScriptAccess

javaScriptAccess(javaScriptAccess: boolean)

设置是否允许执行JavaScript脚本。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型    | 必填   | 说明                |
| ---------------- | ------- | ---- | ------------------- |
| javaScriptAccess | boolean | 是    | 是否允许执行JavaScript脚本。<br>true表示允许执行JavaScript脚本，false表示不允许执行JavaScript脚本。<br>默认值：true。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
      }
    }
  }
  ```

## overScrollMode<sup>11+</sup>

overScrollMode(mode: OverScrollMode)

设置Web过滚动模式。当过滚动模式开启时，当用户在Web根页面上滑动到边缘时，Web会通过弹性动画弹回界面，根页面上的内部页面不会触发回弹。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                                    | 必填   | 说明               |
| ---- | --------------------------------------- | ---- | ------------------ |
| mode | [OverScrollMode](./arkts-basic-components-web-e.md#overscrollmode11) | 是    | 设置Web的过滚动模式为关闭或开启。<br>默认值：`OverScrollMode.NEVER`，表示关闭过滚动模式。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: OverScrollMode = OverScrollMode.ALWAYS;
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .overScrollMode(this.mode)
      }
    }
  }
  ```

## mixedMode

mixedMode(mixedMode: MixedMode)

设定当安全源尝试从非安全源加载资源时的行为，默认值为 MixedMode.None，即禁止安全源从非安全源加载内容。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明      |
| --------- | --------------------------- | ---- | --------- |
| mixedMode | [MixedMode](./arkts-basic-components-web-e.md#mixedmode) | 是    | 要设置的混合内容。<br>默认值：`MixedMode.None`，表示不允许安全来源（secure origin）加载不安全来源（insecure origin）的内容。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: MixedMode = MixedMode.All;
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .mixedMode(this.mode)
      }
    }
  }
  ```

## onlineImageAccess

onlineImageAccess(onlineImageAccess: boolean)

设置是否允许从网络加载图片资源（通过HTTP和HTTPS访问的资源）。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型    | 必填   | 说明             |
| ----------------- | ------- | ---- | ---------------- |
| onlineImageAccess | boolean | 是    | 设置是否允许从网络加载图片资源。<br>true表示设置允许从网络加载图片资源，false表示设置不允许从网络加载图片资源。<br>默认值：true。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onlineImageAccess(true)
      }
    }
  }
  ```

## zoomAccess

zoomAccess(zoomAccess: boolean)

设置是否支持手势进行缩放。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型    | 必填   | 说明          |
| ---------- | ------- | ---- | ------------- |
| zoomAccess | boolean | 是    | 设置是否支持手势进行缩放。<br>true表示设置支持手势进行缩放，false表示设置不支持手势进行缩放。<br>默认值：true。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .zoomAccess(true)
      }
    }
  }
  ```

## overviewModeAccess

overviewModeAccess(overviewModeAccess: boolean)

设置是否使用概览模式加载网页，即缩小内容以适应屏幕宽度。当前仅支持移动设备。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名                | 类型    | 必填   | 说明            |
| ------------------ | ------- | ---- | --------------- |
| overviewModeAccess | boolean | 是    | 设置是否使用概览模式加载网页。<br>true表示设置使用概览模式加载网页，false表示设置不使用概览模式加载网页。<br>默认值：true。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .overviewModeAccess(true)
      }
    }
  }
  ```

## databaseAccess

databaseAccess(databaseAccess: boolean)

设置是否开启数据库存储API权限。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名            | 类型    | 必填   | 说明              |
| -------------- | ------- | ---- | ----------------- |
| databaseAccess | boolean | 是    | 设置是否开启数据库存储API权限。<br>true表示设置开启数据库存储API权限，false表示设置不开启数据库存储API权限。<br>默认值：false。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .databaseAccess(true)
      }
    }
  }
  ```

## geolocationAccess

geolocationAccess(geolocationAccess: boolean)

设置是否开启获取地理位置权限。具体使用方式参考[管理位置权限](../../web/web-geolocation-permission.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型    | 必填   | 说明            |
| ----------------- | ------- | ---- | --------------- |
| geolocationAccess | boolean | 是    | 设置是否开启获取地理位置权限。<br>true表示设置开启获取地理位置权限，false表示设置不开启获取地理位置权限。<br>默认值：true。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .geolocationAccess(true)
      }
    }
  }
  ```

## mediaPlayGestureAccess<sup>9+</sup>

mediaPlayGestureAccess(access: boolean)

设置有声视频的自动播放是否需要用户手动点击，静音视频播放不受该接口管控。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型    | 必填   | 说明                |
| ------ | ------- | ---- | ------------------- |
| access | boolean | 是    | 设置有声视频的自动播放是否需要用户手动点击。<br>true表示设置有声视频的自动播放需要用户手动点击，false表示设置有声视频的自动播放不需要用户手动点击，能自动播放。<br>默认值：true。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State access: boolean = true;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .mediaPlayGestureAccess(this.access)
      }
    }
  }
  ```

## multiWindowAccess<sup>9+</sup>

multiWindowAccess(multiWindow: boolean)

设置是否开启多窗口权限。
使能多窗口权限时，需要实现onWindowNew事件，示例代码参考[onWindowNew事件](./arkts-basic-components-web-events.md#onwindownew9)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名         | 类型    | 必填   | 说明         |
| ----------- | ------- | ---- | ------------ |
| multiWindow | boolean | 是    | 设置是否开启多窗口权限。<br>true表示设置开启多窗口权限，false表示设置不开启多窗口权限。<br>默认值：false。 |

## horizontalScrollBarAccess<sup>9+</sup>

horizontalScrollBarAccess(horizontalScrollBar: boolean)

设置是否显示横向滚动条，包括系统默认滚动条和用户自定义滚动条。

> **说明：**
>
> - 通过@State变量控制横向滚动条的隐藏/显示后，需要调用[controller.refresh()](./arkts-apis-webview-WebviewController.md#refresh)生效。
> - 通过@State变量频繁动态改变时，建议切换开关变量和Web组件一一对应。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名                 | 类型    | 必填   | 说明         |
| ------------------- | ------- | ---- | ------------ |
| horizontalScrollBar | boolean | 是    | 设置是否显示横向滚动条。<br>true表示设置显示横向滚动条，false表示设置不显示横向滚动条。<br>默认值：true。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State isShow: boolean = true;
    @State btnMsg: string ="隐藏滚动条";
  
    build() {
      Column() {
        // 通过@State变量改变横向滚动条的隐藏/显示后，需调用this.controller.refresh()后生效
        Button('refresh')
          .onClick(() => {
            if(this.isShow){
              this.isShow = false;
              this.btnMsg="显示滚动条";
            }else{
              this.isShow = true;
              this.btnMsg="隐藏滚动条";
            }
            try {
              this.controller.refresh();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          }).height("10%").width("40%")
        Web({ src: $rawfile('index.html'), controller: this.controller }).height("90%")
          .horizontalScrollBarAccess(this.isShow)
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
      <meta name="viewport" id="viewport" content="width=device-width,initial-scale=1.0">
      <title>Demo</title>
      <style>
          body {
            width:3000px;
            height:6000px;
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

## verticalScrollBarAccess<sup>9+</sup>

verticalScrollBarAccess(verticalScrollBar: boolean)

设置是否显示纵向滚动条，包括系统默认滚动条和用户自定义滚动条。

> **说明：**
>
> - 通过@State变量控制纵向滚动条的隐藏/显示后，需要调用controller.refresh()生效。
> - 通过@State变量频繁动态改变时，建议切换开关变量和Web组件一一对应。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型    | 必填   | 说明         |
| ----------------- | ------- | ---- | ------------ |
| verticalScrollBar | boolean | 是    | 设置是否显示纵向滚动条。<br>true表示设置显示纵向滚动条，false表示设置不显示纵向滚动条。<br>默认值：true。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State isShow: boolean = true;
    @State btnMsg: string ="隐藏滚动条";
  
    build() {
      Column() {
        // 通过@State变量改变横向滚动条的隐藏/显示后，需调用this.controller.refresh()后生效
        Button(this.btnMsg)
          .onClick(() => {
            if(this.isShow){
              this.isShow = false;
              this.btnMsg="显示滚动条";
            }else{
              this.isShow = true;
              this.btnMsg="隐藏滚动条";
            }
            try {
              this.controller.refresh();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          }).height("10%").width("40%")
        Web({ src: $rawfile('index.html'), controller: this.controller }).height("90%")
          .verticalScrollBarAccess(this.isShow)
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
      <meta name="viewport" id="viewport" content="width=device-width,initial-scale=1.0">
      <title>Demo</title>
      <style>
          body {
            width:3000px;
            height:6000px;
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

## cacheMode

cacheMode(cacheMode: CacheMode)

设置缓存模式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明      |
| --------- | --------------------------- | ---- | --------- |
| cacheMode | [CacheMode](./arkts-basic-components-web-e.md#cachemode) | 是    | 要设置的缓存模式。<br>默认值：`CacheMode.Default`。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: CacheMode = CacheMode.None;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .cacheMode(this.mode)
      }
    }
  }
  ```

## copyOptions<sup>11+</sup>

copyOptions(value: CopyOptions)

设置剪贴板复制范围选项。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明      |
| --------- | --------------------------- | ---- | --------- |
| value | [CopyOptions](../apis-arkui/arkui-ts/ts-appendix-enums.md#copyoptions9) | 是    | 要设置的剪贴板复制范围选项。<br>默认值：`CopyOptions.LocalDevice`。 |

**示例：**

  ```ts
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .copyOptions(CopyOptions.None)
    }
  }
}
  ```

## textZoomRatio<sup>9+</sup>

textZoomRatio(textZoomRatio: number)

设置页面的文本缩放百分比。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名           | 类型   | 必填   | 说明                             |
| ------------- | ------ | ---- | -------------------------------- |
| textZoomRatio | number | 是    | 要设置的页面的文本缩放百分比。<br>取值为整数，范围为(0, 2147483647]。<br>默认值：100。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State ratio: number = 150;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .textZoomRatio(this.ratio)
      }
    }
  }
  ```

## initialScale<sup>9+</sup>

initialScale(percent: number)

设置整体页面的缩放百分比。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填   | 说明                          |
| ------- | ------ | ---- | ----------------------------- |
| percent | number | 是    | 要设置的整体页面的缩放百分比。<br>取值范围：(0, 1000]。<br>默认值：100。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State percent: number = 100;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .initialScale(this.percent)
      }
    }
  }
  ```

## blockNetwork<sup>9+</sup>

blockNetwork(block: boolean)

设置Web组件是否阻止从网络加载资源。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填   | 说明                |
| ----- | ------- | ---- | ------------------- |
| block | boolean | 是    | 设置Web组件是否阻止从网络加载资源。<br>true表示设置Web组件阻止从网络加载资源，false表示设置Web组件不阻止从网络加载资源。<br>默认值：false。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State block: boolean = true;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .blockNetwork(this.block)
      }
    }
  }
  ```

## defaultFixedFontSize<sup>9+</sup>

defaultFixedFontSize(size: number)

设置网页的默认等宽字体大小。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | 是    | 设置网页的默认等宽字体大小，单位px。<br>输入值的范围为-2^31到2^31-1，实际渲染时超过72px的值按照72px进行渲染，低于1px的值按照1px进行渲染。<br>默认值：13。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State fontSize: number = 16;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .defaultFixedFontSize(this.fontSize)
      }
    }
  }
  ```

## defaultFontSize<sup>9+</sup>

defaultFontSize(size: number)

设置网页的默认字体大小。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | 是    | 设置网页的默认字体大小，单位px。<br>输入值的范围为-2^31到2^31-1，实际渲染时超过72px的值按照72px进行渲染，低于1px的值按照1px进行渲染。<br>默认值：16。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State fontSize: number = 13;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .defaultFontSize(this.fontSize)
      }
    }
  }
  ```

## minFontSize<sup>9+</sup>

minFontSize(size: number)

设置网页字体大小最小值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | 是    | 设置网页字体大小最小值，单位px。<br>输入值的范围为-2^31到2^31-1，实际渲染时超过72px的值按照72px进行渲染，低于1px的值按照1px进行渲染。<br>默认值：8。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State fontSize: number = 13;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .minFontSize(this.fontSize)
      }
    }
  }
  ```

## minLogicalFontSize<sup>9+</sup>

minLogicalFontSize(size: number)

设置网页逻辑字体大小最小值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | 是    | 设置网页逻辑字体大小最小值，单位px。<br>输入值的范围为-2^31到2^31-1，实际渲染时超过72px的值按照72px进行渲染，低于1px的值按照1px进行渲染。<br>默认值：8。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State fontSize: number = 13;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .minLogicalFontSize(this.fontSize)
      }
    }
  }
  ```

## webFixedFont<sup>9+</sup>

webFixedFont(family: string)

设置网页的fixed font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| family | string | 是    | 设置网页的fixed font字体库。<br>默认值：monospace。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "monospace";

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webFixedFont(this.family)
      }
    }
  }
  ```

## webSansSerifFont<sup>9+</sup>

webSansSerifFont(family: string)

设置网页的sans-serif font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| family | string | 是    | 设置网页的sans-serif font字体库。<br>默认值：sans-serif。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "sans-serif";

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webSansSerifFont(this.family)
      }
    }
  }
  ```

## webSerifFont<sup>9+</sup>

webSerifFont(family: string)

设置网页的serif font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| family | string | 是    | 设置网页的serif font字体库。<br>默认值：serif。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "serif";

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webSerifFont(this.family)
      }
    }
  }
  ```

## webStandardFont<sup>9+</sup>

webStandardFont(family: string)

设置网页的standard font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| family | string | 是    | 设置网页的standard font字体库。<br>默认值：sans-serif。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "sans-serif";

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webStandardFont(this.family)
      }
    }
  }
  ```

## webFantasyFont<sup>9+</sup>

webFantasyFont(family: string)

设置网页的fantasy font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| family | string | 是    | 设置网页的fantasy font字体库。<br>默认值：fantasy。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "fantasy";

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webFantasyFont(this.family)
      }
    }
  }
  ```

## webCursiveFont<sup>9+</sup>

webCursiveFont(family: string)

设置网页的cursive font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| family | string | 是    | 设置网页的cursive font字体库。<br>默认值：cursive。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State family: string = "cursive";

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .webCursiveFont(this.family)
      }
    }
  }
  ```

## darkMode<sup>9+</sup>

darkMode(mode: WebDarkMode)

设置Web深色模式。当深色模式开启时，Web将启用媒体查询prefers-color-scheme中网页所定义的深色样式，若网页未定义深色样式，则保持原状。如需开启强制深色模式，建议配合[forceDarkAccess](#forcedarkaccess9)使用。深色模式具体用法可参考[Web深色模式适配](../../web/web-set-dark-mode.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                             | 必填   | 说明                     |
| ---- | -------------------------------- | ---- | ------------------------ |
| mode | [WebDarkMode](./arkts-basic-components-web-e.md#webdarkmode9) | 是    | 设置Web的深色模式为关闭、开启或跟随系统。<br>默认值：`WebDarkMode.Off`。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: WebDarkMode = WebDarkMode.On;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .darkMode(this.mode)
      }
    }
  }
  ```

## forceDarkAccess<sup>9+</sup>

forceDarkAccess(access: boolean)

设置网页是否开启强制深色模式。该属性仅在[darkMode](#darkmode9)开启深色模式时生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型    | 必填   | 说明            |
| ------ | ------- | ---- | --------------- |
| access | boolean | 是    | 设置网页是否开启强制深色模式。<br>true表示设置网页开启强制深色模式，false表示设置网页不开启强制深色模式。<br>默认值：false。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State mode: WebDarkMode = WebDarkMode.On;
    @State access: boolean = true;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .darkMode(this.mode)
          .forceDarkAccess(this.access)
      }
    }
  }
  ```

## pinchSmooth<sup>9+</sup>

pinchSmooth(isEnabled: boolean)

设置网页是否开启捏合流畅模式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型    | 必填   | 说明          |
| --------- | ------- | ---- | ------------- |
| isEnabled | boolean | 是    | 网页是否开启捏合流畅模式。<br>true表示设置网页开启捏合流畅模式，false表示设置网页不开启捏合流畅模式。<br>默认值：false。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .pinchSmooth(true)
      }
    }
  }
  ```

## allowWindowOpenMethod<sup>10+</sup>

allowWindowOpenMethod(flag: boolean)

设置网页是否可以通过JavaScript自动打开新窗口。

> **说明：**
>
> - 该属性仅在[javaScriptAccess](#javascriptaccess)开启时生效。
> - 该属性在[multiWindowAccess](#multiwindowaccess9)开启时打开新窗口，关闭时打开本地窗口。
> - 该属性的默认值与系统属性`persist.web.allowWindowOpenMethod.enabled`保持一致，如果未设置系统属性则默认值为false。
> - 通过`hdc shell param get persist.web.allowWindowOpenMethod.enabled` 检查是否开启系统属性`persist.web.allowWindowOpenMethod.enabled`。若属性值为1代表开启系统属性；若属性值为0或不存在，代表未开启系统属性，可通过命令`hdc shell param set persist.web.allowWindowOpenMethod.enabled 1` 开启系统属性。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型    | 必填    | 说明                      |
| ---- | ------- | ---- | ------------------------- |
| flag | boolean | 是    | <br>true表示网页可以通过JavaScript自动打开新窗口，该属性为false时，用户行为仍可通过JavaScript自动打开新窗口，但非用户行为不能通过JavaScript自动打开新窗口。<br>此处的用户行为是指，在用户对Web组件进行点击等操作后，同时在5秒内请求打开新窗口（window.open）的行为。<br>默认值与系统属性关联，当系统属性`persist.web.allowWindowOpenMethod.enabled`为true时，默认值为true，如果未设置系统属性则默认值为false。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // 在同一page页有两个Web组件。在WebComponent新开窗口时，会跳转到NewWebViewComp。
  @CustomDialog
  struct NewWebViewComp {
    controller?: CustomDialogController;
    webviewController1: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: "", controller: this.webviewController1 })
          .javaScriptAccess(true)
          .multiWindowAccess(false)
          .onWindowExit(() => {
            console.info("NewWebViewComp onWindowExit");
            if (this.controller) {
              this.controller.close();
            }
          })
      }
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    dialogController: CustomDialogController | null = null;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .javaScriptAccess(true)
          // 需要使能multiWindowAccess
          .multiWindowAccess(true)
          .allowWindowOpenMethod(true)
          .onWindowNew((event) => {
            if (this.dialogController) {
              this.dialogController.close();
            }
            let popController: webview.WebviewController = new webview.WebviewController();
            this.dialogController = new CustomDialogController({
              builder: NewWebViewComp({ webviewController1: popController })
            })
            this.dialogController.open();
            // 将新窗口对应WebviewController返回给Web内核。
            // 若不调用event.handler.setWebController接口，会造成render进程阻塞。
            // 如果没有创建新窗口，调用event.handler.setWebController接口时设置成null，通知Web没有创建新窗口。
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

## mediaOptions<sup>10+</sup>

mediaOptions(options: WebMediaOptions)

设置Web媒体播放的策略，其中包括：Web中的音频在重新获焦后能够自动续播的有效期、应用内多个Web实例的音频是否独占。

> **说明：**
>
> - 同一Web实例中的多个音频均视为同一音频。
> - 该媒体播放策略将同时管控有声视频。
> - 建议为所有Web组件设置相同的[audioExclusive](./arkts-basic-components-web-i.md#webmediaoptions10)值。
> - 音视频互相打断在应用内和应用间生效，续播只在应用间生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                  | 必填   | 说明                                     |
| ------- | ------------------------------------- | ---- | ---------------------------------------- |
| options | [WebMediaOptions](./arkts-basic-components-web-i.md#webmediaoptions10) | 是    | 设置Web的媒体策略。<br>属性参数更新后需重新播放音频方可生效。<br>默认值：`{resumeInterval: 0, audioExclusive: true}` |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State options: WebMediaOptions = {resumeInterval: 10, audioExclusive: true};

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .mediaOptions(this.options)
      }
    }
  }
  ```

## javaScriptOnDocumentStart<sup>11+</sup>

javaScriptOnDocumentStart(scripts: Array\<ScriptItem>)

将JavaScript脚本注入到Web组件中，当指定页面或者文档开始加载时，该脚本将在其来源与scriptRules匹配的任何页面中执行。

> **说明：**
>
> - 该脚本将在页面的任何JavaScript代码之前运行，并且DOM树此时可能尚未加载、渲染完毕。
>
> - 该脚本按照字典序执行，非数组本身顺序，若需数组本身顺序，建议使用[runJavaScriptOnDocumentStart](#runjavascriptondocumentstart15)接口。
>
> - 不建议与[runJavaScriptOnDocumentStart](#runjavascriptondocumentstart15)同时使用。
>
> - 内容相同的脚本多次注入时将被静默去重，不展示，不提醒，使用首次注入时的scriptRules。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                | 必填   | 说明               |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | 是    | 需要注入的ScriptItem数组。 |

**ets示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct Index {
      controller: webview.WebviewController = new webview.WebviewController();
      private localStorage: string =
          "if (typeof(Storage) !== 'undefined') {" +
          "   localStorage.setItem('color', 'Red');" +
          "}";
      @State scripts: Array<ScriptItem> = [
          { script: this.localStorage, scriptRules: ["*"] }
      ];

      build() {
          Column({ space: 20 }) {
              Web({ src: $rawfile('index.html'), controller: this.controller })
                  .javaScriptAccess(true)
                  .domStorageAccess(true)
                  .backgroundColor(Color.Grey)
                  .javaScriptOnDocumentStart(this.scripts)
                  .width('100%')
                  .height('100%')
          }
      }
  }
  ```
**HTML示例：**

```html
<!-- index.html -->
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
  </head>
  <body style="font-size: 30px;" onload='bodyOnLoadLocalStorage()'>
      Hello world!
      <div id="result"></div>
  </body>
  <script type="text/javascript">
    function bodyOnLoadLocalStorage() {
      if (typeof(Storage) !== 'undefined') {
        document.getElementById('result').innerHTML = localStorage.getItem('color');
      } else {
        document.getElementById('result').innerHTML = 'Your browser does not support localStorage.';
      }
    }
  </script>
</html>
```

## javaScriptOnDocumentEnd<sup>11+</sup>

javaScriptOnDocumentEnd(scripts: Array\<ScriptItem>)

将JavaScript脚本注入到Web组件中，当指定页面或者文档加载完成时，该脚本将在其来源与scriptRules匹配的任何页面中执行。

> **说明：**
>
> - 该脚本将在页面的任何JavaScript代码之后运行，并且DOM树此时已经加载、渲染完毕。
>
> - 该脚本按照字典序执行，非数组本身顺序。
>
> - 不建议与[runJavaScriptOnDocumentEnd](#runjavascriptondocumentend15)同时使用。
>
> - 内容相同的脚本多次注入时将被静默去重，不展示，不提醒，使用首次注入时的scriptRules。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                | 必填   | 说明               |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | 是    | 需要注入的ScriptItem数组 |

**示例：**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  private jsStr: string =
    "window.document.getElementById(\"result\").innerHTML = 'this is msg from javaScriptOnDocumentEnd'";
  @State scripts: Array<ScriptItem> = [
    { script: this.jsStr, scriptRules: ["*"] }
  ];

  build() {
    Column({ space: 20 }) {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .domStorageAccess(true)
        .backgroundColor(Color.Grey)
        .javaScriptOnDocumentEnd(this.scripts)
        .width('100%')
        .height('100%')
    }
  }
}
  ```

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
</head>
<body style="font-size: 30px;">
Hello world!
<div id="result">test msg</div>
</body>
</html>
```

## runJavaScriptOnDocumentStart<sup>15+</sup>

runJavaScriptOnDocumentStart(scripts: Array\<ScriptItem>)

将JavaScript脚本注入到Web组件中，当指定页面或者文档开始加载时，该脚本将在其来源与scriptRules匹配的任何页面中执行。

> **说明：**
>
> - 该脚本将在页面的任何JavaScript代码之前运行，并且DOM树此时可能尚未加载、渲染完毕。
>
> - 该脚本按照数组本身顺序执行。
>
> - 不建议与[javaScriptOnDocumentStart](#javascriptondocumentstart11)同时使用。
>
> - 内容相同的脚本多次注入时将被静默去重，不展示，不提醒，使用首次注入时的scriptRules。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                | 必填   | 说明               |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | 是    | 需要注入的ScriptItem数组 |

**ets示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct Index {
      controller: webview.WebviewController = new webview.WebviewController();
      private localStorage: string =
          "if (typeof(Storage) !== 'undefined') {" +
          "   localStorage.setItem('color', 'Red');" +
          "}";
      @State scripts: Array<ScriptItem> = [
          { script: this.localStorage, scriptRules: ["*"] }
      ];

      build() {
          Column({ space: 20 }) {
              Web({ src: $rawfile('index.html'), controller: this.controller })
                  .javaScriptAccess(true)
                  .domStorageAccess(true)
                  .backgroundColor(Color.Grey)
                  .runJavaScriptOnDocumentStart(this.scripts)
                  .width('100%')
                  .height('100%')
          }
      }
  }
  ```
**HTML示例：**

```html
<!-- index.html -->
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
  </head>
  <body style="font-size: 30px;" onload='bodyOnLoadLocalStorage()'>
      Hello world!
      <div id="result"></div>
  </body>
  <script type="text/javascript">
    function bodyOnLoadLocalStorage() {
      if (typeof(Storage) !== 'undefined') {
        document.getElementById('result').innerHTML = localStorage.getItem('color');
      } else {
        document.getElementById('result').innerHTML = 'Your browser does not support localStorage.';
      }
    }
  </script>
</html>
```

## runJavaScriptOnDocumentEnd<sup>15+</sup>

runJavaScriptOnDocumentEnd(scripts: Array\<ScriptItem>)

将JavaScript脚本注入到Web组件中，当指定页面或者文档加载完成时，该脚本将在其来源与scriptRules匹配的任何页面中执行。

> **说明：**
>
> - 该脚本将在页面的任何JavaScript代码之后运行，并且DOM树此时已经加载、渲染完毕。
>
> - 该脚本按照数组本身顺序执行。
>
> - 不建议与[javaScriptOnDocumentEnd](#javascriptondocumentend11)同时使用。
>
> - 内容相同的脚本多次注入时将被静默去重，不展示，不提醒，使用首次注入时的scriptRules。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                | 必填   | 说明               |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | 是    | 需要注入的ScriptItem数组 |

**示例：**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  private jsStr: string =
    "window.document.getElementById(\"result\").innerHTML = 'this is msg from runJavaScriptOnDocumentEnd'";
  @State scripts: Array<ScriptItem> = [
    { script: this.jsStr, scriptRules: ["*"] }
  ];

  build() {
    Column({ space: 20 }) {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .domStorageAccess(true)
        .backgroundColor(Color.Grey)
        .runJavaScriptOnDocumentEnd(this.scripts)
        .width('100%')
        .height('100%')
    }
  }
}
  ```

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
</head>
<body style="font-size: 30px;">
Hello world!
<div id="result">test msg</div>
</body>
</html>
```

## runJavaScriptOnHeadEnd<sup>15+</sup>

runJavaScriptOnHeadEnd(scripts: Array\<ScriptItem>)

将JavaScript脚本注入到Web组件中，当页面DOM树head标签解析完成时，该脚本将在其来源与scriptRules匹配的任何页面中执行。

> **说明：**
>
> - 该脚本按照数组本身顺序执行。
>
> - 内容相同的脚本多次注入时将被静默去重，不展示，不提醒，使用首次注入时的scriptRules。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                | 必填   | 说明               |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](./arkts-basic-components-web-i.md#scriptitem11)> | 是    | 需要注入的ScriptItem数组 |

**示例：**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  private jsStr: string =
    "window.document.getElementById(\"result\").innerHTML = 'this is msg from runJavaScriptOnHeadEnd'";
  @State scripts: Array<ScriptItem> = [
    { script: this.jsStr, scriptRules: ["*"] }
  ];

  build() {
    Column({ space: 20 }) {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .domStorageAccess(true)
        .backgroundColor(Color.Grey)
        .runJavaScriptOnHeadEnd(this.scripts)
        .width('100%')
        .height('100%')
    }
  }
}
  ```

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
</head>
<body style="font-size: 30px;">
Hello world!
<div id="result">test msg</div>
</body>
</html>
```

## layoutMode<sup>11+</sup>

layoutMode(mode: WebLayoutMode)

设置Web布局模式。

> **说明：**
>
> 目前只支持两种Web布局模式，分别为Web布局跟随系统（`WebLayoutMode.NONE`）和Web组件高度基于前端页面高度的自适应网页布局（`WebLayoutMode.FIT_CONTENT`）。
>
> Web组件高度基于前端页面自适应布局有如下限制：
> - 如果Web组件宽或长度超过7680px，请在Web组件创建的时候指定`RenderMode.SYNC_RENDER`模式，否则会整个白屏。
> - Web组件创建后不支持动态切换layoutMode模式
> - Web组件宽高规格：指定`RenderMode.SYNC_RENDER`模式时，分别不超过50万px；指定`RenderMode.ASYNC_RENDER`模式时，分别不超过7680px。
> - 频繁更改页面宽高会触发Web组件重新布局，影响体验。
> - 不支持瀑布流网页（下拉到底部加载更多）。
> - 不支持宽度自适应，仅支持高度自适应（不支持vh单位）。
> - 由于高度自适应网页高度，您无法通过修改组件高度属性来修改组件高度。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                                  | 必填   | 说明                  |
| ---- | ------------------------------------- | ---- | --------------------- |
| mode | [WebLayoutMode](./arkts-basic-components-web-e.md#weblayoutmode11) | 是    | 设置web布局模式，跟随系统或自适应布局。<br>默认值：`WebLayoutMode.NONE。` |

**示例：**

  1、指明layoutMode为`WebLayoutMode.FIT_CONTENT`模式，为避免默认渲染模式下(`RenderMode.ASYNC_RENDER`)视口高度超过7680px导致页面渲染出错，需要显式指明渲染模式(`RenderMode.SYNC_RENDER`)。
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    mode: WebLayoutMode = WebLayoutMode.FIT_CONTENT;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, renderMode: RenderMode.SYNC_RENDER })
          .layoutMode(this.mode)
      }
    }
  }
  ```

  2、指明layoutMode为`WebLayoutMode.FIT_CONTENT`模式，为避免嵌套滚动场景下，Web滚动到边缘时会优先触发过滚动的过界回弹效果影响用户体验，建议指定[overScrollMode](#overscrollmode11)为`OverScrollMode.NEVER`。
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    layoutMode: WebLayoutMode = WebLayoutMode.FIT_CONTENT;
    @State overScrollMode: OverScrollMode = OverScrollMode.NEVER;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, renderMode: RenderMode.SYNC_RENDER })
          .layoutMode(this.layoutMode)
          .overScrollMode(this.overScrollMode)
      }
    }
  }
  ```

## nestedScroll<sup>11+</sup>

nestedScroll(value: NestedScrollOptions | NestedScrollOptionsExt)

调用以设置嵌套滚动选项。

> **说明：**
>
> - 可以设置上下左右四个方向，或者设置向前、向后两个方向的嵌套滚动模式，实现与父组件的滚动联动。
> - 支持嵌套滚动的容器：[Grid](../apis-arkui/arkui-ts/ts-container-grid.md)、[List](../apis-arkui/arkui-ts/ts-container-list.md)、[Scroll](../apis-arkui/arkui-ts/ts-container-scroll.md)、[Swiper](../apis-arkui/arkui-ts/ts-container-swiper.md)、[Tabs](../apis-arkui/arkui-ts/ts-container-tabs.md)、[WaterFlow](../apis-arkui/arkui-ts/ts-container-waterflow.md)、[Refresh](../apis-arkui/arkui-ts/ts-container-refresh.md)、[bindSheet](../apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)。
> - 支持嵌套滚动的输入事件：使用手势、鼠标、触控板。
> - 嵌套滚动场景下，由于Web滚动到边缘时会优先触发过滚动的过界回弹效果，建议设置[overScrollMode](#overscrollmode11)为`OverScrollMode.NEVER`，避免影响此场景的用户体验。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                     | 必填   | 说明             |
| ----- | ---------------------------------------- | ---- | ---------------- |
| value | [NestedScrollOptions](../apis-arkui/arkui-ts/ts-container-scrollable-common.md#nestedscrolloptions10对象说明) \| [NestedScrollOptionsExt](./arkts-basic-components-web-i.md#nestedscrolloptionsext14)<sup>14+</sup> | 是    | 可滚动组件滚动时的嵌套滚动选项。<br> value为NestedScrollOptions（向前、向后两个方向）类型时，scrollForward、scrollBackward默认滚动选项为`NestedScrollMode.SELF_FIRST`。 <br> value为NestedScrollOptionsExt（上下左右四个方向）类型时，scrollUp、scrollDown、scrollLeft、scrollRight默认滚动选项为[NestedScrollMode.SELF_FIRST](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10)。|

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .nestedScroll({
            scrollForward: NestedScrollMode.SELF_FIRST,
            scrollBackward: NestedScrollMode.SELF_FIRST,
          })
      }
    }
  }
  ```
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController()
    build() {
      Scroll(){
        Column() {
          Text("嵌套Web")
            .height("25%")
            .width("100%")
            .fontSize(30)
            .backgroundColor(Color.Yellow)
          Web({ src: $rawfile('index.html'),
                controller: this.controller })
            .nestedScroll({
              scrollUp: NestedScrollMode.SELF_FIRST,
              scrollDown: NestedScrollMode.PARENT_FIRST,
              scrollLeft: NestedScrollMode.SELF_FIRST,
              scrollRight: NestedScrollMode.SELF_FIRST,
            })
        }
      }
    }
  }
  ```
  加载的html文件。
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
      <meta name="viewport" id="viewport" content="width=device-width, initial-scale=1.0">
      <style>
          .blue {
            background-color: lightblue;
          }
          .green {
            background-color: lightgreen;
          }
          .blue, .green {
          font-size:16px;
          height:200px;
          text-align: center;       /* 水平居中 */
          line-height: 200px;       /* 垂直居中（值等于容器高度） */
          }
      </style>
  </head>
  <body>
  <div class="blue" >webArea</div>
  <div class="green">webArea</div>
  <div class="blue">webArea</div>
  <div class="green">webArea</div>
  <div class="blue">webArea</div>
  <div class="green">webArea</div>
  <div class="blue">webArea</div>
  </body>
  </html>
  ```

## enableNativeEmbedMode<sup>11+</sup>

enableNativeEmbedMode(mode: boolean)

设置是否开启同层渲染功能。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                      | 必填   | 说明             |
| ----- | ---------------------------------------- | ---- | ---------------- |
| mode |  boolean | 是    | 是否开启同层渲染功能。<br>true表示开启同层渲染功能，false表示不开启同层渲染功能。<br>默认值：false。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .enableNativeEmbedMode(true)
      }
    }
  }
  ```
## forceDisplayScrollBar<sup>14+</sup>

forceDisplayScrollBar(enabled: boolean)


设置滚动条是否常驻。在常驻状态下，当页面大小超过一页时，滚动条出现且不消失。

全量展开模式下不支持滚动条常驻，即layoutMode为WebLayoutMode.FIT_CONTENT模式时，参数enabled为false。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型 | 必填 | 说明           |
| ------- | -------- | ---- | ------------------ |
| enabled | boolean  | 是   | 滚动条是否常驻。<br>true表示滚动条常驻，false表示滚动条不常驻。<br>默认值：false。 |


**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .forceDisplayScrollBar(true)
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
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Demo</title>
      <style>
        body {
          width:2560px;
          height:2560px;
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
## registerNativeEmbedRule<sup>12+</sup>

registerNativeEmbedRule(tag: string, type: string)

注册使用同层渲染的HTML标签名和类型。标签名仅支持使用"object"和"embed"。标签类型只能使用ASCII可显示字符。

若指定类型与W3C定义的object或embed标准类型重合，ArkWeb内核将其识别为非同层标签。

本接口同样受enableNativeEmbedMode接口控制，在未使能同层渲染时本接口无效。在不使用本接口的情况下，ArkWeb内核默认将"native/"前缀类型的embed标签识别为同层标签。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明             |
|------|--------| ---- |------------------|
| tag  | string | 是    | 标签名。             |
| type | string | 是   | 标签类型，内核使用前缀匹配此参数。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .enableNativeEmbedMode(true)
          .registerNativeEmbedRule("object", "application/view")
      }
    }
  }
  ```
## defaultTextEncodingFormat<sup>12+</sup>

defaultTextEncodingFormat(textEncodingFormat: string)

设置网页的默认字符编码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| textEncodingFormat | string | 是    | 默认字符编码。默认值："UTF-8"。 |

  **示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          // 设置高
          .height(500)
          .defaultTextEncodingFormat("UTF-8")
          .javaScriptAccess(true)
      }
    }
  }
  ```

```html

<!doctype html>
<html>
<head>
    <meta name="viewport" content="width=device-width" />
    <title>My test html5 page</title>
</head>
<body>
    hello world, 你好世界!
</body>
</html>
```
## metaViewport<sup>12+</sup>

metaViewport(enabled: boolean)

设置meta标签的viewport属性是否可用。

> **说明：**
>
> - 如果设备为2in1，不支持viewport属性。设置为true或者false均不会解析viewport属性，进行默认布局。
> - 如果设备为Tablet，设置为true或false均会解析meta标签viewport-fit属性。当`viewport-fit=cover`时，可通过CSS属性获取安全区域大小。
> - 当前通过User-Agent中是否含有"Mobile"字段来判断是否开启前端HTML页面中meta标签的viewport属性。当User-Agent中不含有"Mobile"字段时，meta标签中viewport属性默认关闭，此时可通过显性设置metaViewport属性为true来覆盖关闭状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                         |
| ------ | -------- | ---- | -------------------------------- |
| enabled | boolean  | 是   | 是否支持meta标签的viewport属性。<br>true表示支持meta标签的viewport属性，将解析viewport属性，并根据viewport属性布局。<br>false表示不支持meta标签的viewport属性，将不解析viewport属性，进行默认布局。<br>默认值：true。 |

**示例：**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .metaViewport(true)
    }
  }
}
  ```

```html
<!doctype html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <p>hello world, 你好世界!</p>
</body>
</html>
```

## textAutosizing<sup>12+</sup>

textAutosizing(textAutosizing: boolean)

设置使能文本自动调整大小。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| textAutosizing | boolean | 是    | 文本自动调整大小。<br>true表示文本自动调整大小，false表示文本不自动调整大小。<br>默认值：true。 |

  **示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .textAutosizing(false)
      }
    }
  }
  ```
## enableNativeMediaPlayer<sup>12+</sup>

enableNativeMediaPlayer(config: NativeMediaPlayerConfig)

开启[应用接管网页媒体播放功能](../../web/app-takeovers-web-media.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明 |
| ---- | ------ | ---- | ---------------------|
| config | [NativeMediaPlayerConfig](./arkts-basic-components-web-i.md#nativemediaplayerconfig12) | 是    | enable: 是否开启该功能。<br/> shouldOverlay: 该功能开启后， 应用接管网页视频的播放器画面是否覆盖网页内容。<br>默认值：`{enable: false, shouldOverlay: false}`。|

  **示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .enableNativeMediaPlayer({enable: true, shouldOverlay: false})
      }
    }
  }
  ```

## onAdsBlocked<sup>12+</sup>

onAdsBlocked(callback: OnAdsBlockedCallback)

一个页面发生广告过滤后，通过此回调接口通知过滤的详细信息。由于页面可能随时发生变化并不断产生网络请求，为了减少通知频次、降低对页面加载过程的影响，仅在页面加载完成时进行首次通知，此后发生的过滤将间隔1秒钟上报，无广告过滤则无通知。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnAdsBlockedCallback](./arkts-basic-components-web-t.md#onadsblockedcallback12) | 是 | 广告过滤的回调。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    @State totalAdsBlockCounts: number = 0;
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'https://www.example.com', controller: this.controller })
        .onAdsBlocked((details: AdsBlockedDetails) => {
          if (details) {
            console.log(' Blocked ' + details.adsBlocked.length + ' in ' + details.url);
            let adList: Array<string> = Array.from(new Set(details.adsBlocked));
            this.totalAdsBlockCounts += adList.length;
            console.log('Total blocked counts :' + this.totalAdsBlockCounts);
          }
        })
      }
    }
  }
  ```

## keyboardAvoidMode<sup>12+</sup>

keyboardAvoidMode(mode: WebKeyboardAvoidMode)

Web组件自定义软件键盘避让模式。

当UIContext设置的键盘避让模式为[KeyboardAvoidMode.RESIZE](../apis-arkui/js-apis-arkui-UIContext.md#keyboardavoidmode11)模式时，该接口功能不生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型                              | 必填   | 说明          |
| ------------------- | ------------------------------   | ------ | ------------- |
| mode | [WebKeyboardAvoidMode](./arkts-basic-components-web-e.md#webkeyboardavoidmode12) | 是     | Web软键盘避让模式。<br>嵌套滚动场景下不推荐使用web软键盘避让，包括RESIZE_VISUAL与RESIZE_CONTENT。<br>默认值：`WebKeyboardAvoidMode.RESIZE_CONTENT`避让行为。|

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State avoidMode: WebKeyboardAvoidMode = WebKeyboardAvoidMode.RESIZE_VISUAL;

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
        .keyboardAvoidMode(this.avoidMode)
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
    <title>测试网页</title>
  </head>
  <body>
    <input type="text" placeholder="Text">
  </body>
  </html>
  ```

## editMenuOptions<sup>12+</sup>

editMenuOptions(editMenu: EditMenuOptions)

Web组件自定义文本选择菜单。

用户可以通过该属性设置自定义的文本菜单。

在[onCreateMenu](../apis-arkui/arkui-ts/ts-text-common.md#oncreatemenu)中，可以修改、增加、删除菜单选项，如果希望不显示文本菜单，需要返回空数组。

在[onMenuItemClick](../apis-arkui/arkui-ts/ts-text-common.md#onmenuitemclick)中，可以自定义菜单选项的回调函数。该函数在菜单选项被点击后触发，并根据返回值决定是否执行系统默认的回调。返回true不执行系统回调，返回false继续执行系统回调。

本接口在与[selectionMenuOptions<sup>(deprecated)</sup>](#selectionmenuoptionsdeprecated)同时使用时，会使selectionMenuOptions<sup>(deprecated)</sup>不生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型                              | 必填   | 说明          |
| ------------------- | ------------------------------   | ------ | ------------- |
| editMenu | [EditMenuOptions](../apis-arkui/arkui-ts/ts-text-common.md#editmenuoptions) | 是     | Web自定义文本菜单选项。<br>菜单项数量，及菜单的content大小、icon图标尺寸，与ArkUI [Menu](../apis-arkui/arkui-ts/ts-basic-components-menu.md)组件保持一致。<br>菜单中系统自带的id枚举值（[TextMenuItemId](../apis-arkui/arkui-ts/ts-text-common.md#textmenuitemid12)）在Web中仅支持CUT、COPY、PASTE、SELECT_ALL四项。<br>onMenuItemClick函数中textRange参数在web中无意义，传入值为-1。|

**示例**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  onCreateMenu(menuItems: Array<TextMenuItem>): Array<TextMenuItem> {
    let items = menuItems.filter((menuItem) => {
      // 过滤用户需要的系统按键
      return (
        menuItem.id.equals(TextMenuItemId.CUT) ||
        menuItem.id.equals(TextMenuItemId.COPY) ||
        menuItem.id.equals((TextMenuItemId.PASTE))
      )
    });
    let customItem1: TextMenuItem = {
      content: 'customItem1',
      id: TextMenuItemId.of('customItem1'),
      icon: $r('app.media.icon')
    };
    let customItem2: TextMenuItem = {
      content: $r('app.string.customItem2'),
      id: TextMenuItemId.of('customItem2'),
      icon: $r('app.media.icon')
    };
    items.push(customItem1);// 在选项列表后添加新选项
    items.unshift(customItem2);// 在选项列表前添加选项

    return items;
  }

  onMenuItemClick(menuItem: TextMenuItem, textRange: TextRange): boolean {
    if (menuItem.id.equals(TextMenuItemId.CUT)) {
      // 用户自定义行为
      console.log("拦截 id：CUT")
      return true; // 返回true不执行系统回调
    } else if (menuItem.id.equals(TextMenuItemId.COPY)) {
      // 用户自定义行为
      console.log("不拦截 id：COPY")
      return false; // 返回false执行系统回调
    } else if (menuItem.id.equals(TextMenuItemId.of('customItem1'))) {
      // 用户自定义行为
      console.log("拦截 id：customItem1")
      return true;// 用户自定义菜单选项返回true时点击后不关闭菜单，返回false时关闭菜单
    } else if (menuItem.id.equals((TextMenuItemId.of($r('app.string.customItem2'))))){
      // 用户自定义行为
      console.log("拦截 id：app.string.customItem2")
      return true;
    }
    return false;// 返回默认值false
  }

  @State EditMenuOptions: EditMenuOptions = { onCreateMenu: this.onCreateMenu, onMenuItemClick: this.onMenuItemClick }

  build() {
    Column() {
      Web({ src: $rawfile("index.html"), controller: this.controller })
        .editMenuOptions(this.EditMenuOptions)
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
      <title>测试网页</title>
  </head>
  <body>
    <h1>editMenuOptions Demo</h1>
    <span>edit menu options</span>
  </body>
</html>
```

## enableHapticFeedback<sup>13+</sup>

enableHapticFeedback(enabled: boolean)

设置Web组件长按文本选择是否开启振动。 需配置"ohos.permission.VIBRATE"。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型        | 必填   | 说明 |
| --------- | ---------   | ------ | ------------- |
| enabled   | boolean | 是  | 是否开启振动。<br>true表示开启振动，false表示不开启振动。<br>默认值：true。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: $rawfile("index.html"), controller: this.controller })
      .enableHapticFeedback(true)
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
      <title>测试网页</title>
  </head>
  <body>
    <h1>enableHapticFeedback Demo</h1>
    <span>enable haptic feedback</span>
  </body>
</html>
```

## bindSelectionMenu<sup>13+</sup>

bindSelectionMenu(elementType: WebElementType, content: CustomBuilder, responseType: WebResponseType, options?: SelectionMenuOptionsExt)

设置自定义选择菜单。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                             | 必填 | 说明                                |
| ------------ | ------------------------------- | ---- | ----------------------------------- |
| elementType     | [WebElementType](./arkts-basic-components-web-e.md#webelementtype13)             | 是   | 菜单的类型。   |
| content      | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)     | 是   | 菜单的内容。   |
| responseType | [WebResponseType](./arkts-basic-components-web-e.md#webresponsetype13)           | 是   | 菜单的响应类型。 |
| options      | [SelectionMenuOptionsExt](./arkts-basic-components-web-i.md#selectionmenuoptionsext13)   | 否   | 菜单的选项。|

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

interface PreviewBuilderParam {
  previewImage: Resource | string | undefined;
  width: number;
  height: number;
}

@Builder function PreviewBuilderGlobal($$: PreviewBuilderParam) {
  Column() {
    Image($$.previewImage)
      .objectFit(ImageFit.Fill)
      .autoResize(true)
  }.width($$.width).height($$.height)
}

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  private result: WebContextMenuResult | undefined = undefined;
  @State previewImage: Resource | string | undefined = undefined;
  @State previewWidth: number = 0;
  @State previewHeight: number = 0;
  uiContext: UIContext = this.getUIContext();

  @Builder
  MenuBuilder() {
    Menu() {
      MenuItem({ content: '复制', })
        .onClick(() => {
          this.result?.copy();
          this.result?.closeContextMenu();
        })
      MenuItem({ content: '全选', })
        .onClick(() => {
          this.result?.selectAll();
          this.result?.closeContextMenu();
        })
    }
  }
  build() {
    Column() {
      Web({ src: $rawfile("index.html"), controller: this.controller })
        .bindSelectionMenu(WebElementType.IMAGE, this.MenuBuilder, WebResponseType.LONG_PRESS,
          {
            onAppear: () => {},
            onDisappear: () => {
              this.result?.closeContextMenu();
            },
            preview: PreviewBuilderGlobal({
              previewImage: this.previewImage,
              width: this.previewWidth,
              height: this.previewHeight
            }),
            menuType: MenuType.PREVIEW_MENU
          })
        .onContextMenuShow((event) => {
            if (event) {
              this.result = event.result;
              if (event.param.getLinkUrl()) {
                return false;
              }
              this.previewWidth = this.uiContext!.px2vp(event.param.getPreviewWidth());
              this.previewHeight = this.uiContext!.px2vp(event.param.getPreviewHeight());
              if (event.param.getSourceUrl().indexOf("resource://rawfile/") == 0) {
                this.previewImage = $rawfile(event.param.getSourceUrl().substr(19));
              } else {
                this.previewImage = event.param.getSourceUrl();
              }
              return true;
            }
            return false;
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
      <title>测试网页</title>
  </head>
  <body>
    <h1>bindSelectionMenu Demo</h1>
    <img src="./img.png" >
  </body>
</html>
```

## blurOnKeyboardHideMode<sup>14+</sup>

blurOnKeyboardHideMode(mode: BlurOnKeyboardHideMode)

设置当软键盘收起时Web元素失焦模式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                                    | 必填   | 说明               |
| ---- | --------------------------------------- | ---- | ------------------ |
| mode | [BlurOnKeyboardHideMode](./arkts-basic-components-web-e.md#bluronkeyboardhidemode14) | 是    | 设置当软键盘收起时Web元素失焦关闭或开启。默认值：`BlurOnKeyboardHideMode.SILENT`。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State blurMode: BlurOnKeyboardHideMode = BlurOnKeyboardHideMode.BLUR;
    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .blurOnKeyboardHideMode(this.blurMode)
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
      <title>测试网页</title>
  </head>
  <body>
    <h1>blurOnKeyboardHideMode Demo</h1>
    <input type="text" id="input_a">
    <script>
      const inputElement = document.getElementById('input_a');
      inputElement.addEventListener('blur', function() {
        console.log('Input has lost focus');
      });
    </script>
  </body>
</html>
```

## enableFollowSystemFontWeight<sup>18+</sup>

enableFollowSystemFontWeight(follow: boolean)

设置Web组件是否开启字重跟随系统设置变化。

> **说明：**
>
> 目前该能力只支持前端文本元素跟随变化，暂不支持canvas元素、内嵌docx和pdf格式中的文本跟随变化。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                             | 必填 | 说明                                |
| ------------ | ------------------------------- | ---- | ----------------------------------- |
| follow | boolean | 是    | 设置Web组件是否开启字重跟随系统设置变化。<br>true表示字重跟随系统设置中的字体粗细变化，系统设置改变时字重跟随变化。false表示字重不再跟随系统设置中的字体粗细变化，系统设置改变时维持当前字重不变。<br>默认值：false。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    build() {
      Column() {
        Web({ src: "www.example.com", controller: this.controller })
          .enableFollowSystemFontWeight(true)
      }
    }
  }
  ```

## optimizeParserBudget<sup>15+</sup>

optimizeParserBudget(optimizeParserBudget: boolean)

设置是否开启分段解析HTML优化。

ArkWeb内核在解析HTML文档结构时采取分段解析策略，旨在避免过多占用主线程资源，并使网页具有渐进式加载能力。ArkWeb内核默认使用解析时间作为分段点，当单次解析时间超过阈值时，会中断解析，随后进行布局和渲染操作。

开启优化后，ArkWeb内核将不仅检查解析时间是否超出限制，还会额外判断解析的Token（HTML文档的最小解析单位，例如`<div>`、`attr="xxx"`等）数量是否超过内核规定的阈值，并下调此阈值。当页面的FCP(First Contentful Paint 首次内容绘制）触发时会恢复成默认的中断判断逻辑。这将使得网页在FCP到来之前的解析操作更频繁，从而提高首帧内容被提前解析完成并进入渲染阶段的可能性，同时有效缩减首帧渲染的工作量，最终实现FCP时间提前。

由于页面的FCP触发时会恢复成默认分段解析逻辑，因此分段解析HTML优化仅对每个Web组件加载的首个页面生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型    | 必填   | 说明                   |
| ---------- | ------- | ---- | ---------------------- |
| optimizeParserBudget | boolean | 是    | 设置开启分段解析HTML优化。<br>true表示使用解析个数代替解析时间作为HTML分段解析的分段点，并减少每段解析的个数上限。false表示使用解析时间作为HTML分段解析的分段点。<br>默认值：false。 |


**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .optimizeParserBudget(true)
      }
    }
  }
  ```

## enableWebAVSession<sup>18+</sup>

enableWebAVSession(enabled: boolean)

设置是否支持应用对接到播控中心。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型 | 必填 | 说明           |
| ------- | -------- | ---- | ------------------ |
| enabled | boolean  | 是   | 设置是否支持应用对接到播控中心。<br>true表示支持应用对接到播控中心，false表示不支持应用对接到播控中心。<br>默认值：true。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .enableWebAVSession(true)
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
      <title>视频播放页面</title>
  </head>
  <body>
      <h1>视频播放</h1>
      <video id="testVideo" controls>
          // 在resources的rawfile目录中放置任意一个mp4媒体文件，并将其命名为example.mp4
          <source src="example.mp4" type="video/mp4">
      </video>
  </body>
  </html>
  ```

## nativeEmbedOptions<sup>16+</sup>

nativeEmbedOptions(options?: EmbedOptions)

设置同层渲染相关配置，该属性仅在[enableNativeEmbedMode](#enablenativeembedmode11)开启时生效，不支持动态修改。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                             | 必填 | 说明                                |
| ------------ | ------------------------------- | ---- | ----------------------------------- |
| options | [EmbedOptions](./arkts-basic-components-web-i.md#embedoptions16) | 否    | 同层渲染相关配置，默认值：`{supportDefaultIntrinsicSize: false}`。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    options: EmbedOptions = {supportDefaultIntrinsicSize: true};

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .enableNativeEmbedMode(true)
          .nativeEmbedOptions(this.options)
      }
    }
  }
  ```
加载的html文件
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
      <title>同层渲染固定大小测试html</title>
  </head>
  <body>
  <div>
      <embed id="input" type = "native/view" style = "background-color:red"/>
  </div>
  </body>
  </html>
  ```
## enableDataDetector<sup>20+</sup>

enableDataDetector(enable: boolean)

设置是否识别网页文本特殊实体。该接口依赖设备底层具备文本识别能力，否则设置无效。

当enableDataDetector设置为true，同时不设置dataDetectorConfig属性时，默认识别所有类型的实体，所识别实体的color和decoration会被更改为如下样式：
<!--code_no_check-->
```ts
color: '#ff007dff'
decoration:{
  type: TextDecorationType.Underline,
  color: '#ff007dff',
  style: TextDecorationStyle.SOLID
}
```

目前仅在页面加载完成后触发一次全文实体识别，实体识别的筛选规则为如下：

- 不处理输入框内、可编辑区域内的文本实体。
- 不处理<a></a>标签内的文本实体。
- 不处理跨域iframe内、两层及以上嵌套iframe内的文本实体。
- 跨节点的实体不会被识别。如`<div>星</div><div>期六</div>`。


网页中文本实体处理后，会转变成超链接的形式，触摸点击或鼠标左键点击实体，会根据实体类型弹出对应的实体操作菜单。触摸长按、触摸拖拽、鼠标右键、鼠标拖拽会执行超链接的默认逻辑。

页面文本元素的计算样式存在`user-select:none`时，或页面Javascript拦截了select事件时，实体菜单中“选择文本”的选项无效，但仍可以复制实体文本。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：** 

| 参数名 | 类型    | 必填 | 说明                              |
| ------ | ------- | ---- | --------------------------------- |
| enable  | boolean | 是   | 是否启用Web文本识别，true表示启用，false表示不启用。<br/>默认值：false |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .enableDataDetector(true)
      }
    }
  }
  ```
加载的html文件
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
      <title>enableDataDetector示例</title>
  </head>
  <body>
      <p> 电话：400-123-4567 </p>
      <p> 邮箱：example@example.com </p>
  </body>
  </html>
  ```

## dataDetectorConfig<sup>20+</sup>

dataDetectorConfig(config: TextDataDetectorConfig)

设置文本识别配置。

需配合[enableDataDetector](#enabledatadetector20)一起使用，设置enableDataDetector为true时，dataDetectorConfig的配置才能生效。

当两个实体A、B重叠时，按以下规则保留实体：

1. 若A&nbsp;⊂&nbsp;B，则保留B，反之则保留A。

2. 当A&nbsp;⊄&nbsp;B且B&nbsp;⊄&nbsp;A时，若A.start&nbsp;<&nbsp;B.start，则保留A，反之则保留B。


**系统能力：** SystemCapability.Web.Webview.Core

**参数：** 

| 参数名 | 类型                                                        | 必填 | 说明                                                         |
| ------ | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [TextDataDetectorConfig](../apis-arkui/arkui-ts/ts-text-common.md#textdatadetectorconfig11对象说明) | 是   | 文本识别配置。|

> **说明：** 
> 
> TextDataDetectorConfig中的onDetectResultUpdate在Web组件中不支持，设置的回调不会调用。

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .enableDataDetector(true)
          .dataDetectorConfig({
            types: [
              TextDataDetectorType.PHONE_NUMBER,
              TextDataDetectorType.EMAIL
            ],
            color: Color.Red,
            decoration: {
              type: TextDecorationType.LineThrough,
              color: Color.Green,
              style: TextDecorationStyle.WAVY
            }
          })
      }
    }
  }
  ```
加载的html文件
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
      <title>dataDetectorConfig示例</title>
  </head>
  <body>
      <p> 电话：400-123-4567 </p>
      <p> 邮箱：12345678901@example.com </p>
      <p> 网址：www.example.com（此项不识别）</p>
  </body>
  </html>
  ```

## password<sup>(deprecated)</sup>

password(password: boolean)

设置是否应保存密码。该接口为空接口。

> **说明：**
>
> 从API version 10开始废弃，并且不再提供新的接口作为替代。

**系统能力：** SystemCapability.Web.Webview.Core

## textZoomAtio<sup>(deprecated)</sup>

textZoomAtio(textZoomAtio: number)

设置页面的文本缩放百分比。

**系统能力：** SystemCapability.Web.Webview.Core

从API version 9开始不再维护，建议使用[textZoomRatio<sup>9+</sup>](#textzoomratio9)代替。

**参数：**

| 参数名          | 类型   | 必填  | 说明                             |
| ------------ | ------ | ---- | -------------------------------- |
| textZoomAtio | number | 是   | 要设置的页面的文本缩放百分比。<br>取值范围为正整数。<br>默认值：100。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State ratio: number = 150
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .textZoomAtio(this.ratio)
      }
    }
  }
  ```

## userAgent<sup>(deprecated)</sup>

userAgent(userAgent: string)

设置用户代理。

> **说明：**
>
> 从API version 8开始支持，从API version 10开始废弃。建议使用[setCustomUserAgent](./arkts-apis-webview-WebviewController.md#setcustomuseragent10)<sup>10+</sup>替代。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型   | 必填   | 说明      |
| --------- | ------ | ---- | --------- |
| userAgent | string | 是    | 要设置的用户代理。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State userAgent:string = 'Mozilla/5.0 (Phone; OpenHarmony 5.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/4.1.6.1 Mobile DemoApp';

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .userAgent(this.userAgent)
      }
    }
  }
  ```

## tableData<sup>(deprecated)</sup>

tableData(tableData: boolean)

设置是否应保存表单数据。该接口为空接口。

> **说明：**
>
> 从API version 10开始废弃，并且不再提供新的接口作为替代。

**系统能力：** SystemCapability.Web.Webview.Core

## wideViewModeAccess<sup>(deprecated)</sup>

wideViewModeAccess(wideViewModeAccess: boolean)

设置web是否支持html中meta标签的viewport属性。该接口为空接口。

> **说明：**
>
> 从API version 10开始废弃，并且不再提供新的接口作为替代。

**系统能力：** SystemCapability.Web.Webview.Core

## selectionMenuOptions<sup>(deprecated)</sup>

selectionMenuOptions(expandedMenuOptions: Array\<ExpandedMenuItemOptions>)

Web组件自定义菜单扩展项接口，允许用户设置扩展项的文本内容、图标、回调方法。

该接口只支持选中纯文本，当选中内容包含图片及其他非文本内容时，action信息中会显示乱码。

> **说明：**
>
> 从API version 12开始支持，从API version 20开始废弃。建议使用[editMenuOptions<sup>12+</sup>](#editmenuoptions12)替代。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型                                                         | 必填   | 说明          |
| ------------------- | ----------------------------------------------------------    | ---- | ------------- |
| expandedMenuOptions | Array<[ExpandedMenuItemOptions](./arkts-basic-components-web-i.md#expandedmenuitemoptions12)> | 是    | 扩展菜单选项。<br/>菜单项数量，及菜单的content大小、startIcon图标尺寸，与ArkUI [Menu](../apis-arkui/arkui-ts/ts-basic-components-menu.md)组件保持一致。|

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State menuOptionArray: Array<ExpandedMenuItemOptions> = [
      {content: 'Apple', startIcon: $r('app.media.icon'), action: (selectedText) => {
        console.info('select info ' + selectedText.toString());
      }},
      {content: '香蕉', startIcon: $r('app.media.icon'), action: (selectedText) => {
        console.info('select info ' + selectedText.toString());
      }}
    ];

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
        .selectionMenuOptions(this.menuOptionArray)
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
    <title>测试网页</title>
  </head>
  <body>
    <h1>selectionMenuOptions Demo</h1>
    <span>selection menu options</span>
  </body>
  </html>
  ```