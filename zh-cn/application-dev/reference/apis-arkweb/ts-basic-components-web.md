# Web

提供具有网页显示能力的Web组件，[@ohos.web.webview](js-apis-webview.md)提供web控制能力。

> **说明：**
>
> - 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## 需要权限

访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

## 子组件

无

## 接口

Web(value: WebOptions)

> **说明：**
>
> 不支持转场动画。
>
> 同一页面的多个Web组件，必须绑定不同的WebviewController。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型                                     | 必填   | 说明                                     |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| value        | [WebOptions](#weboptions)   | 是    | 定义Web选项。 |

**示例：**

加载在线网页。

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
      }
    }
  }
  ```

隐私模式Webview加载在线网页。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

Web组件同步渲染模式。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, renderMode: RenderMode.SYNC_RENDER })
      }
    }
  }
  ```

Web组件指定共享渲染进程。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, sharedRenderProcessToken: "111" })
        Web({ src: 'www.w3.org', controller: this.controller, sharedRenderProcessToken: "111" })
      }
    }
  }
  ```

加载本地网页。

通过$rawfile方式加载。
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 通过$rawfile加载本地资源文件。
        Web({ src: $rawfile("index.html"), controller: this.controller })
      }
    }
  }
  ```

通过resources协议加载，适用Webview加载带有"#"路由的链接。
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 通过resource协议加载本地资源文件。
        Web({ src: "resource://rawfile/index.html", controller: this.controller })
      }
    }
  }
  ```

加载沙箱路径下的本地资源文件。

1. 通过构造的单例对象GlobalContext获取沙箱路径。

   ```ts
   // GlobalContext.ets
   export class GlobalContext {
     private constructor() {}
     private static instance: GlobalContext;
     private _objects = new Map<string, Object>();

     public static getContext(): GlobalContext {
       if (!GlobalContext.instance) {
         GlobalContext.instance = new GlobalContext();
       }
       return GlobalContext.instance;
     }

     getObject(value: string): Object | undefined {
       return this._objects.get(value);
     }

     setObject(key: string, objectClass: Object): void {
       this._objects.set(key, objectClass);
     }
   }
   ```

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   let url = 'file://' + GlobalContext.getContext().getObject("filesDir") + '/index.html';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController();

     build() {
       Column() {
         // 加载沙箱路径文件。
         Web({ src: url, controller: this.controller })
       }
     }
   }
   ```

2. 修改EntryAbility.ets。

   以filesDir为例，获取沙箱路径。若想获取其他路径，请参考[应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。

   ```ts
   // xxx.ets
   import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
       // 通过在GlobalContext对象上绑定filesDir，可以实现UIAbility组件与UI之间的数据同步。
       GlobalContext.getContext().setObject("filesDir", this.context.filesDir);
       console.log("Sandbox path is " + GlobalContext.getContext().getObject("filesDir"));
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

## WebOptions

通过[接口](#接口)定义Web选项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 类型                                     | 必填   | 说明                                     |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| src        | string \| [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)   | 是    | 网页资源地址。如果访问本地资源文件，请使用$rawfile或者resource协议。如果加载应用包外沙箱路径的本地资源文件(文件支持html和txt类型)，请使用file://沙箱文件路径。<br>src不能通过状态变量（例如：@State）动态更改地址，如需更改，请通过[loadUrl()](js-apis-webview.md#loadurl)重新加载。 |
| controller | [WebController](#webcontroller) \| [WebviewController<sup>9+</sup>](js-apis-webview.md#webviewcontroller)  | 是    | 控制器。从API Version 9开始，WebController不再维护，建议使用WebviewController替代。 |
| renderMode<sup>12+</sup> | [RenderMode](#rendermode12枚举说明)| 否   | 表示当前Web组件的渲染方式，RenderMode.ASYNC_RENDER表示Web组件自渲染，RenderMode.SYNC_RENDER表示支持Web组件统一渲染能力，默认值RenderMode.ASYNC_RENDER, 该模式不支持动态调整。 |
| incognitoMode<sup>11+</sup> | boolean | 否 | 表示当前创建的webview是否是隐私模式。true表示创建隐私模式的webview, false表示创建正常模式的webview。<br> 默认值：false |
| sharedRenderProcessToken<sup>12+</sup> | string | 否 | 表示当前Web组件指定共享渲染进程的token, 多渲染进程模式下，相同token的Web组件会优先尝试复用与token相绑定的渲染进程。token与渲染进程的绑定发生在渲染进程的初始化阶段。当渲染进程没有关联的Web组件时，其与token绑定关系将被移除。<br> 默认值： ""  |

## 属性

通用属性仅支持[aspectRatio](../apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#aspectratio)、[backdropBlur](../apis-arkui/arkui-ts/ts-universal-attributes-background.md#backdropblur)、[backgroundColor](../apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor)、[bindContentCover](../apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover)、[bindContextMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu8)、[bindMenu ](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu)、[bindSheet](../apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)、[borderColor](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#bordercolor)、[borderRadius](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderradius)、[borderStyle](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderstyle)、[borderWidth](../apis-arkui/arkui-ts/ts-universal-attributes-border.md#borderwidth)、[clip](../apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#clip)、[constraintSize](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#constraintsize)、[defaultFocus](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#defaultfocus9)、[focusable](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#focusable)、[tabIndex](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#tabindex9)、[groupDefaultFocus](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#groupdefaultfocus9)、[focusOnTouch](../apis-arkui/arkui-ts/ts-universal-attributes-focus.md#focusontouch9)、[displayPriority](../apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#displaypriority)、[enabled](../apis-arkui/arkui-ts/ts-universal-attributes-enable.md#enabled)、[flexBasis](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexbasis)、[flexGrow](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexgrow)、[flexShrink](../apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexshrink)、[layoutWeight](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#layoutweight)、[id](../apis-arkui/arkui-ts/ts-universal-attributes-component-id.md)、[gridOffset](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md)、[gridSpan](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md)、[useSizeType](../apis-arkui/arkui-ts/ts-universal-attributes-grid.md)、[height](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#height)、[touchable](../apis-arkui/arkui-ts/ts-universal-attributes-click.md)、[margin](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#margin)、[markAnchor](../apis-arkui/arkui-ts/ts-universal-attributes-location.md#markanchor)、[offset](../apis-arkui/arkui-ts/ts-universal-attributes-location.md#offset)、[width](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#width)、[zIndex](../apis-arkui/arkui-ts/ts-universal-attributes-z-order.md#zindex)、[visibility](../apis-arkui/arkui-ts/ts-universal-attributes-visibility.md#visibility)、[scale](../apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#scale)、[translate](../apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#translate)、[responseRegion](../apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md#responseregion)、[size](../apis-arkui/arkui-ts/ts-universal-attributes-size.md#size)、[stateStyles](../apis-arkui/arkui-ts/ts-universal-attributes-polymorphic-style.md#statestyles)、[opacity](../apis-arkui/arkui-ts/ts-universal-attributes-opacity.md#opacity)、[shadow](../apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow)、[sharedTransition](../apis-arkui/arkui-ts/ts-transition-animation-shared-elements.md)、[transition](../apis-arkui/arkui-ts/ts-transition-animation-component.md)。

### domStorageAccess

domStorageAccess(domStorageAccess: boolean)

设置是否开启文档对象模型存储接口（DOM Storage API）权限，默认未开启。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型    | 必填   | 说明                                 |
| ---------------- | ------- | ---- | ------------------------------------ |
| domStorageAccess | boolean | 是    | 设置是否开启文档对象模型存储接口（DOM Storage API）权限。默认值：false。 |

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

### fileAccess

fileAccess(fileAccess: boolean)

设置是否开启应用中文件系统的访问。[$rawfile(filepath/filename)](../../quick-start/resource-categories-and-access.md)中rawfile路径的文件不受该属性影响而限制访问。

从API version 12开始，fileAccess默认不启用。同时，当fileAccess为false的时候，仅只读资源目录/data/storage/el1/bundle/entry/resources/resfile里面的file协议资源依然可以访问，不受fileAccess管控。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型    | 必填   | 说明                   |
| ---------- | ------- | ---- | ---------------------- |
| fileAccess | boolean | 是    | API version 11及以前：默认为true，启动应用中文件系统的访问。API version 12及以后：默认为false，不启用应用中文件系统的访问。 |

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

### imageAccess

imageAccess(imageAccess: boolean)

设置是否允许自动加载图片资源，默认允许。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名         | 类型    | 必填   | 说明            |
| ----------- | ------- | ---- | --------------- |
| imageAccess | boolean | 是    | 设置是否允许自动加载图片资源。默认值：true。 |

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

### javaScriptProxy

javaScriptProxy(javaScriptProxy: JavaScriptProxy)

注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。所有参数不支持更新。注册对象时，同步与异步方法列表请至少选择一项不为空，可同时注册两类方法。同一方法在同步与异步列表中重复注册，将默认异步调用。此接口只支持注册一个对象，若需要注册多个对象请使用[registerJavaScriptProxy<sup>9+</sup>](js-apis-webview.md#registerjavascriptproxy)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型                                     | 必填   | 说明                                     |
| ---------- | ---------------------------------------- | ---- |---------------------------------------- |
| javaScriptProxy     | [JavaScriptProxy](#javascriptproxy12)                                   | 是    |  参与注册的对象。只能声明方法，不能声明属性。                   |

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

### javaScriptAccess

javaScriptAccess(javaScriptAccess: boolean)

设置是否允许执行JavaScript脚本，默认允许执行。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型    | 必填   | 说明                |
| ---------------- | ------- | ---- | ------------------- |
| javaScriptAccess | boolean | 是    | 是否允许执行JavaScript脚本。默认值：true。 |

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

### overScrollMode<sup>11+</sup>

overScrollMode(mode: OverScrollMode)

设置Web过滚动模式，默认关闭。当过滚动模式开启时，当用户在Web界面上滑动到边缘时，Web会通过弹性动画弹回界面。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                                    | 必填   | 说明               |
| ---- | --------------------------------------- | ---- | ------------------ |
| mode | [OverScrollMode](#overscrollmode11枚举说明) | 是    | 设置Web的过滚动模式为关闭或开启。默认值：OverScrollMode.NEVER。 |

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

### mixedMode

mixedMode(mixedMode: MixedMode)

设置是否允许加载超文本传输协议（HTTP）和超文本传输安全协议（HTTPS）混合内容，默认不允许加载HTTP和HTTPS混合内容。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明      |
| --------- | --------------------------- | ---- | --------- |
| mixedMode | [MixedMode](#mixedmode枚举说明) | 是    | 要设置的混合内容。默认值：MixedMode.None。 |

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

### onlineImageAccess

onlineImageAccess(onlineImageAccess: boolean)

设置是否允许从网络加载图片资源（通过HTTP和HTTPS访问的资源），默认允许访问。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型    | 必填   | 说明             |
| ----------------- | ------- | ---- | ---------------- |
| onlineImageAccess | boolean | 是    | 设置是否允许从网络加载图片资源。默认值：true。 |

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

### zoomAccess

zoomAccess(zoomAccess: boolean)

设置是否支持手势进行缩放，默认允许执行缩放。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型    | 必填   | 说明          |
| ---------- | ------- | ---- | ------------- |
| zoomAccess | boolean | 是    | 设置是否支持手势进行缩放。默认值：true。 |

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

### overviewModeAccess

overviewModeAccess(overviewModeAccess: boolean)

设置是否使用概览模式加载网页，默认使用该方式。当前仅支持移动设备。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名                | 类型    | 必填   | 说明            |
| ------------------ | ------- | ---- | --------------- |
| overviewModeAccess | boolean | 是    | 设置是否使用概览模式加载网页。默认值：true。 |

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

### databaseAccess

databaseAccess(databaseAccess: boolean)

设置是否开启数据库存储API权限，默认不开启。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名            | 类型    | 必填   | 说明              |
| -------------- | ------- | ---- | ----------------- |
| databaseAccess | boolean | 是    | 设置是否开启数据库存储API权限。默认值：false。 |

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

### geolocationAccess

geolocationAccess(geolocationAccess: boolean)

设置是否开启获取地理位置权限，默认开启。具体使用方式参考[管理位置权限](../../web/web-geolocation-permission.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型    | 必填   | 说明            |
| ----------------- | ------- | ---- | --------------- |
| geolocationAccess | boolean | 是    | 设置是否开启获取地理位置权限。默认值：true。 |

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

### mediaPlayGestureAccess<sup>9+</sup>

mediaPlayGestureAccess(access: boolean)

设置有声视频播放是否需要用户手动点击，静音视频播放不受该接口管控，默认需要。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型    | 必填   | 说明                |
| ------ | ------- | ---- | ------------------- |
| access | boolean | 是    | 设置有声视频播放是否需要用户手动点击。默认值：true。 |

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

### multiWindowAccess<sup>9+</sup>

multiWindowAccess(multiWindow: boolean)

设置是否开启多窗口权限，默认不开启。
使能多窗口权限时，需要实现onWindowNew事件，示例代码参考[onWindowNew事件](#onwindownew9)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名         | 类型    | 必填   | 说明         |
| ----------- | ------- | ---- | ------------ |
| multiWindow | boolean | 是    | 设置是否开启多窗口权限。默认值：false。 |

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
        .multiWindowAccess(false)
      }
    }
  }
  ```

### horizontalScrollBarAccess<sup>9+</sup>

horizontalScrollBarAccess(horizontalScrollBar: boolean)

设置是否显示横向滚动条，包括系统默认滚动条和用户自定义滚动条。默认显示。

> **说明：**
>
> - 通过@State变量控制横向滚动条的隐藏/显示后，需要调用controller.refresh()生效。
> - 通过@State变量频繁动态改变时，建议切换开关变量和Web组件一一对应。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名                 | 类型    | 必填   | 说明         |
| ------------------- | ------- | ---- | ------------ |
| horizontalScrollBar | boolean | 是    | 设置是否显示横向滚动条。默认值：true。 |

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

### verticalScrollBarAccess<sup>9+</sup>

verticalScrollBarAccess(verticalScrollBar: boolean)

设置是否显示纵向滚动条，包括系统默认滚动条和用户自定义滚动条。默认显示。

> **说明：**
>
> - 通过@State变量控制纵向滚动条的隐藏/显示后，需要调用controller.refresh()生效。
> - 通过@State变量频繁动态改变时，建议切换开关变量和Web组件一一对应。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型    | 必填   | 说明         |
| ----------------- | ------- | ---- | ------------ |
| verticalScrollBar | boolean | 是    | 设置是否显示纵向滚动条。默认值：true。 |

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

### password<sup>(deprecated)</sup>

password(password: boolean)

设置是否应保存密码。该接口为空接口。

> **说明：**
>
> 从API version 10开始废弃，并且不再提供新的接口作为替代。

**系统能力：** SystemCapability.Web.Webview.Core

### cacheMode

cacheMode(cacheMode: CacheMode)

设置缓存模式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明      |
| --------- | --------------------------- | ---- | --------- |
| cacheMode | [CacheMode](#cachemode枚举说明) | 是    | 要设置的缓存模式。默认值：CacheMode.Default。 |

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

### copyOptions<sup>11+</sup>

copyOptions(value: CopyOptions)

设置剪贴板复制范围选项。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明      |
| --------- | --------------------------- | ---- | --------- |
| value | [CopyOptions](../apis-arkui/arkui-ts/ts-appendix-enums.md#copyoptions9) | 是    | 要设置的剪贴板复制范围选项。默认值：CopyOptions.LocalDevice。 |

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

### textZoomAtio<sup>(deprecated)</sup>

textZoomAtio(textZoomAtio: number)

设置页面的文本缩放百分比，默认为100。

**系统能力：** SystemCapability.Web.Webview.Core

从API version 9开始不再维护，建议使用[textZoomRatio<sup>9+</sup>](#textzoomratio9)代替。

**参数：**

| 参数名          | 类型   | 必填  | 说明                             |
| ------------ | ------ | ---- | -------------------------------- |
| textZoomAtio | number | 是   | 要设置的页面的文本缩放百分比。取值为整数，范围为(0, +∞)。默认值：100。 |

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

设置页面的文本缩放百分比，默认为100。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名           | 类型   | 必填   | 说明                             |
| ------------- | ------ | ---- | -------------------------------- |
| textZoomRatio | number | 是    | 要设置的页面的文本缩放百分比。取值为整数，范围为(0, +∞)。默认值：100。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State atio: number = 150;

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

设置整体页面的缩放百分比，默认为100。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填   | 说明                          |
| ------- | ------ | ---- | ----------------------------- |
| percent | number | 是    | 要设置的整体页面的缩放百分比。默认值：100。 |

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

### userAgent<sup>(deprecated)</sup>

userAgent(userAgent: string)

设置用户代理。

> **说明：**
>
> 从API version 8开始支持，从API version 10开始废弃。建议使用[setCustomUserAgent](js-apis-webview.md#setcustomuseragent10)<sup>10+</sup>替代。

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

### blockNetwork<sup>9+</sup>

blockNetwork(block: boolean)

设置Web组件是否阻止从网络加载资源。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填   | 说明                |
| ----- | ------- | ---- | ------------------- |
| block | boolean | 是    | 设置Web组件是否阻止从网络加载资源。默认值：false。 |

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

### defaultFixedFontSize<sup>9+</sup>

defaultFixedFontSize(size: number)

设置网页的默认等宽字体大小。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | 是    | 设置网页的默认等宽字体大小，单位px。输入值的范围为-2^31到2^31-1，实际渲染时超过72的值按照72进行渲染，低于1的值按照1进行渲染。默认值：13。 |

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

### defaultFontSize<sup>9+</sup>

defaultFontSize(size: number)

设置网页的默认字体大小。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | 是    | 设置网页的默认字体大小，单位px。输入值的范围为-2^31到2^31-1，实际渲染时超过72的值按照72进行渲染，低于1的值按照1进行渲染。默认值：16。 |

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

### minFontSize<sup>9+</sup>

minFontSize(size: number)

设置网页字体大小最小值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | 是    | 设置网页字体大小最小值，单位px。输入值的范围为-2^31到2^31-1，实际渲染时超过72的值按照72进行渲染，低于1的值按照1进行渲染。默认值：8。 |

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

### minLogicalFontSize<sup>9+</sup>

minLogicalFontSize(size: number)

设置网页逻辑字体大小最小值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| size | number | 是    | 设置网页逻辑字体大小最小值，单位px。输入值的范围为-2^31到2^31-1，实际渲染时超过72的值按照72进行渲染，低于1的值按照1进行渲染。默认值：8。 |

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

### webFixedFont<sup>9+</sup>

webFixedFont(family: string)

设置网页的fixed font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                |
| ------ | ------ | ---- | ------------------- |
| family | string | 是    | 设置网页的fixed font字体库。默认值：monospace。 |

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

### webSansSerifFont<sup>9+</sup>

webSansSerifFont(family: string)

设置网页的sans serif font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| family | string | 是    | 设置网页的sans serif font字体库。默认值：sans-serif。 |

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

### webSerifFont<sup>9+</sup>

webSerifFont(family: string)

设置网页的serif font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                |
| ------ | ------ | ---- | ------------------- |
| family | string | 是    | 设置网页的serif font字体库。默认值：serif。 |

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

### webStandardFont<sup>9+</sup>

webStandardFont(family: string)

设置网页的standard font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| family | string | 是    | 设置网页的standard font字体库。默认值：sans serif。 |

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

### webFantasyFont<sup>9+</sup>

webFantasyFont(family: string)

设置网页的fantasy font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| family | string | 是    | 设置网页的fantasy font字体库。默认值：fantasy。 |

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

### webCursiveFont<sup>9+</sup>

webCursiveFont(family: string)

设置网页的cursive font字体库。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| family | string | 是    | 设置网页的cursive font字体库。默认值：cursive。 |

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

### darkMode<sup>9+</sup>

darkMode(mode: WebDarkMode)

设置Web深色模式，默认关闭。当深色模式开启时，Web将启用媒体查询prefers-color-scheme中网页所定义的深色样式，若网页未定义深色样式，则保持原状。如需开启强制深色模式，建议配合[forceDarkAccess](#forcedarkaccess9)使用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                             | 必填   | 说明                   |
| ---- | -------------------------------- | ---- | ---------------------- |
| mode | [WebDarkMode](#webdarkmode9枚举说明) | 是    | 设置Web的深色模式为关闭、开启或跟随系统。默认值：WebDarkMode.Off。 |

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

### forceDarkAccess<sup>9+</sup>

forceDarkAccess(access: boolean)

设置网页是否开启强制深色模式。默认关闭。该属性仅在[darkMode](#darkmode9)开启深色模式时生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型    | 必填   | 说明            |
| ------ | ------- | ---- | --------------- |
| access | boolean | 是    | 设置网页是否开启强制深色模式。默认值：false。 |

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

### tableData<sup>(deprecated)</sup>

tableData(tableData: boolean)

设置是否应保存表单数据。该接口为空接口。

> **说明：**
>
> 从API version 10开始废弃，并且不再提供新的接口作为替代。

**系统能力：** SystemCapability.Web.Webview.Core

### wideViewModeAccess<sup>(deprecated)</sup>

wideViewModeAccess(wideViewModeAccess: boolean)

设置web是否支持html中meta标签的viewport属性。该接口为空接口。

> **说明：**
>
> 从API version 10开始废弃，并且不再提供新的接口作为替代。

**系统能力：** SystemCapability.Web.Webview.Core

### pinchSmooth<sup>9+</sup>

pinchSmooth(isEnabled: boolean)

设置网页是否开启捏合流畅模式，默认不开启。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型    | 必填   | 说明          |
| --------- | ------- | ---- | ------------- |
| isEnabled | boolean | 是    | 网页是否开启捏合流畅模式。默认值：false。 |

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

### allowWindowOpenMethod<sup>10+</sup>

allowWindowOpenMethod(flag: boolean)

设置网页是否可以通过JavaScript自动打开新窗口。

该属性为true时，可通过JavaScript自动打开新窗口。该属性为false时，用户行为仍可通过JavaScript自动打开新窗口，但非用户行为不能通过JavaScript自动打开新窗口。此处的用户行为是指，在用户对Web组件进行点击等操作后，同时在5秒内请求打开新窗口（window.open）的行为。

该属性仅在[javaScriptAccess](#javascriptaccess)开启时生效。

该属性在[multiWindowAccess](#multiwindowaccess9)开启时打开新窗口，关闭时打开本地窗口。

该属性的默认值与系统属性persist.web.allowWindowOpenMethod.enabled 保持一致，如果未设置系统属性则默认值为false。

检查系统配置项persist.web.allowWindowOpenMethod.enabled 是否开启。

通过`hdc shell param get persist.web.allowWindowOpenMethod.enabled` 查看，若配置项为0或不存在，
可通过命令`hdc shell param set persist.web.allowWindowOpenMethod.enabled 1` 开启配置。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型    | 必填    | 说明                      |
| ---- | ------- | ---- | ------------------------- |
| flag | boolean | 是    | 网页是否可以通过JavaScript自动打开窗口。默认值与系统参数关联，当系统参数persist.web.allowWindowOpenMethod.enabled为true时，默认值为true, 否则为false。 |

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
            // 如果不需要打开新窗口请调用event.handler.setWebController接口设置成null。
            // 若不调用event.handler.setWebController接口，会造成render进程阻塞。
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

### mediaOptions<sup>10+</sup>

mediaOptions(options: WebMediaOptions)

设置Web媒体播放的策略，其中包括：Web中的音频在重新获焦后能够自动续播的有效期、应用内多个Web实例的音频是否独占。

> **说明：**
>
> - 同一Web实例中的多个音频均视为同一音频。
> - 该媒体播放策略将同时管控有声视频。
> - 属性参数更新后需重新播放音频方可生效。
> - 建议为所有Web组件设置相同的audioExclusive值。
> - 音视频互相打断在应用内和应用间生效，续播只在应用间生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                  | 必填   | 说明                                     |
| ------- | ------------------------------------- | ---- | ---------------------------------------- |
| options | [WebMediaOptions](#webmediaoptions10) | 是    | 设置Web的媒体策略。其中，resumeInterval的默认值为0表示不自动续播。默认值：{resumeInterval: 0, audioExclusive: true}。 |

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

### javaScriptOnDocumentStart<sup>11+</sup>

javaScriptOnDocumentStart(scripts: Array\<ScriptItem>)

将JavaScript脚本注入到Web组件中，当指定页面或者文档开始加载时，该脚本将在其来源与scriptRules匹配的任何页面中执行。

> **说明：**
>
> - 该脚本将在页面的任何JavaScript代码之前运行，并且DOM树此时可能尚未加载、渲染完毕。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                | 必填   | 说明               |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](#scriptitem11)> | 是    | 需要注入的ScriptItem数组 |

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

### javaScriptOnDocumentEnd<sup>11+</sup>

javaScriptOnDocumentEnd(scripts: Array\<ScriptItem>)

将JavaScript脚本注入到Web组件中，当指定页面或者文档加载完成时，该脚本将在其来源与scriptRules匹配的任何页面中执行。

> **说明：**
>
> - 该脚本将在页面的任何JavaScript代码之后运行，并且DOM树此时已经加载、渲染完毕。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                | 必填   | 说明               |
| ------- | ----------------------------------- | ---- | ------------------ |
| scripts | Array\<[ScriptItem](#scriptitem11)> | 是    | 需要注入的ScriptItem数组 |

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

### layoutMode<sup>11+</sup>

layoutMode(mode: WebLayoutMode)

设置Web布局模式。

> **说明：**
>
> 目前只支持两种Web布局模式，分别为Web布局跟随系统（WebLayoutMode.NONE）和Web组件高度基于前端页面高度的自适应网页布局（WebLayoutMode.FIT_CONTENT）。
>
> Web组件高度基于前端页面自适应布局有如下限制：
> - 如果网页内容宽或长度超过8000px，请在Web组件创建的时候指定RenderMode.SYNC_RENDER模式，否则会整个白屏。
> - Web组件创建后不支持动态切换layoutMode模式
> - Web组件宽高规格：分别不超过50万px。
> - 频繁更改页面宽高会触发Web组件重新布局，影响体验。
> - 不支持瀑布流网页（下拉到底部加载更多）。
> - 仅支持高度自适应，不支持宽度自适应。
> - 由于高度自适应网页高度，您无法通过修改组件高度属性来修改组件高度。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                                  | 必填   | 说明                  |
| ---- | ------------------------------------- | ---- | --------------------- |
| mode | [WebLayoutMode](#weblayoutmode11枚举说明) | 是    | 设置web布局模式，跟随系统或自适应布局。默认值：WebLayoutMode.NONE。 |

**示例：**

  1、指明layoutMode为WebLayoutMode.FIT_CONTENT模式，为避免默认渲染模式下(RenderMode.ASYNC_RENDER)视口高度超过7680px导致页面渲染出错，需要显式指明渲染模式(RenderMode.SYNC_RENDER)。
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

  2、指明layoutMode为WebLayoutMode.FIT_CONTENT模式，为避免嵌套滚动场景下，Web滚动到边缘时会优先触发过滚动的过界回弹效果影响用户体验，建议指定overScrollMode为OverScrollMode.NEVER。
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

### nestedScroll<sup>11+</sup>

nestedScroll(value: NestedScrollOptions | NestedScrollOptionsExt)

调用以设置嵌套滚动选项。

> **说明：**
>
> - 可以设置上下左右四个方向，或者设置向前、向后两个方向的嵌套滚动模式，实现与父组件的滚动联动。
> - value为NestedScrollOptionsExt（上下左右四个方向）类型时，scrollUp、scrollDown、scrollLeft、scrollRight默认滚动选项为[NestedScrollMode.SELF_FIRST](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10)。
> - value为NestedScrollOptions（向前、向后两个方向）类型时，scrollForward、scrollBackward默认滚动选项为NestedScrollMode.SELF_FIRST。
> - 支持嵌套滚动的容器：Grid、List、Scroll、Swiper、Tabs、WaterFlow。
> - 支持嵌套滚动的输入事件：使用手势、鼠标、触控板。
> - 嵌套滚动场景下，由于Web滚动到边缘时会优先触发过滚动的过界回弹效果，建议设置overScrollMode为OverScrollMode.NEVER，避免影响此场景的用户体验。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                     | 必填   | 说明             |
| ----- | ---------------------------------------- | ---- | ---------------- |
| value | [NestedScrollOptions](../apis-arkui/arkui-ts/ts-container-scrollable-common.md#nestedscrolloptions10对象说明) \| [NestedScrollOptionsExt](#nestedscrolloptionsext14对象说明)<sup>14+</sup> | 是    | 可滚动组件滚动时的嵌套滚动选项。 |

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
    <style>
      .blue {
        background-color: lightblue;
      }
      .green {
        background-color: lightgreen;
      }
      .blue, .green {
       width: 100%;
  	 font-size:70px;
  	 height:1000px;
      }
    </style>
  </head>
  <body>
    <div class="blue" align="center" >滚动1</div>
    <div class="green" align="center">滚动2</div>
    <div class="blue" align="center">滚动3</div>
    <div class="green" align="center">滚动4</div>
    <div class="blue" align="center">滚动5</div>
    <div class="green" align="center">滚动6</div>
    <div class="blue" align="center">滚动7</div>
  </body>
  </html>
  ```

### enableNativeEmbedMode<sup>11+</sup>

enableNativeEmbedMode(mode: boolean)

设置是否开启同层渲染功能，默认不开启。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                      | 必填   | 说明             |
| ----- | ---------------------------------------- | ---- | ---------------- |
| mode |  boolean | 是    | 是否开启同层渲染功能。默认值：false。 |

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
### forceDisplayScrollBar<sup>14+</sup>

forceDisplayScrollBar(enabled: boolean)


设置滚动条是否常驻。默认不常驻，在常驻状态下，当页面大小超过一页时，滚动条出现且不消失。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型 | 必填 | 说明           |
| ------- | -------- | ---- | ------------------ |
| enabled | boolean  | 是   | 滚动条是否常驻。默认值：false。 |


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
### registerNativeEmbedRule<sup>12+</sup>

registerNativeEmbedRule(tag: string, type: string)

注册使用同层渲染的HTML标签名和类型。标签名仅支持使用object和embed。标签类型只能使用ASCII可显示字符。

若指定类型与w3c定义的object或embed标准类型重合，ArkWeb内核将其识别为非同层标签。

本接口同样受enableNativeEmbedMode接口控制，在未使能同层渲染时本接口无效。在不使用本接口的情况下，ArkWeb内核默认将"native/"前缀类型的embed标签识别为同层标签。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明             |
|------|--------| ---- |------------------|
| tag  | string | 是    | 标签名。             |
| type | string | 是   | 标签类型,内核使用前缀匹配此参数。 |

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
### defaultTextEncodingFormat<sup>12+</sup>

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
### metaViewport<sup>12+</sup>

metaViewport(enabled: boolean)

设置meta标签的viewport属性是否可用。

> **说明：**
>
> - 设置false不支持meta标签viewport属性，将不解析viewport属性，进行默认布局。
> - 设置true支持meta标签viewport属性，将解析viewport属性，并根据viewport属性布局。
> - 如果设置为异常值将无效。
> - 如果设备为2in1，不支持viewport属性。设置为true或者false均不会解析viewport属性，进行默认布局。
> - 如果设备为平板设备，无论设置为true或者false均会解析meta标签viewport-fit属性。当viewport-fit=cover时，可通过CSS属性获取安全区域大小。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                         |
| ------ | -------- | ---- | -------------------------------- |
| enabled | boolean  | 是   | 是否支持meta标签的viewport属性。默认值：true。 |

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

### textAutosizing<sup>12+</sup>

textAutosizing(textAutosizing: boolean)

设置使能文本自动调整大小。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| textAutosizing | boolean | 是    | 文本自动调整大小。默认值：true。 |

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
### enableNativeMediaPlayer<sup>12+</sup>

enableNativeMediaPlayer(config: NativeMediaPlayerConfig)

开启[应用接管网页媒体播放功能](../../web/app-takeovers-web-media.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明 |
| ---- | ------ | ---- | ---------------------|
| config | [NativeMediaPlayerConfig](#nativemediaplayerconfig12) | 是    | enable: 是否开启该功能。<br/> shouldOverlay: 该功能开启后， 应用接管网页视频的播放器画面是否覆盖网页内容。默认值：{enable: false, shouldOverlay: false}。|

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

### selectionMenuOptions<sup>12+</sup>

selectionMenuOptions(expandedMenuOptions: Array\<ExpandedMenuItemOptions>)

Web组件自定义菜单扩展项接口，允许用户设置扩展项的文本内容、图标、回调方法。

该接口只支持选中纯文本，当选中内容包含图片及其他非文本内容时，action信息中会显示乱码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型                                                         | 必填   | 说明          |
| ------------------- | ----------------------------------------------------------    | ---- | ------------- |
| expandedMenuOptions | Array<[ExpandedMenuItemOptions](#expandedmenuitemoptions12)> | 是    | 扩展菜单选项。<br/>菜单项数量，及菜单的content大小、startIcon图标尺寸，与ArkUI [Menu](../apis-arkui/arkui-ts/ts-basic-components-menu.md)组件保持一致。|

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

### onAdsBlocked<sup>12+</sup>

onAdsBlocked(callback: OnAdsBlockedCallback)

一个页面发生广告过滤后，通过此回调接口通知过滤的详细信息。由于页面可能随时发生变化并不断产生网络请求，为了减少通知频次、降低对页面加载过程的影响，仅在页面加载完成时进行首次通知，此后发生的过滤将间隔1秒钟上报，无广告过滤则无通知。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnAdsBlockedCallback](#onadsblockedcallback12) | 是 | onAdsBlocked的回调。 |

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

### keyboardAvoidMode<sup>12+</sup>

keyboardAvoidMode(mode: WebKeyboardAvoidMode)

Web组件自定义软件键盘避让模式。

当UIContext设置的键盘避让模式为[KeyboardAvoidMode.RESIZE](../apis-arkui/js-apis-arkui-UIContext.md#keyboardavoidmode11)模式时，该接口功能不生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型                              | 必填   | 说明          |
| ------------------- | ------------------------------   | ------ | ------------- |
| mode | [WebKeyboardAvoidMode](#webkeyboardavoidmode12) | 是     | Web软键盘避让模式。<br>默认是WebKeyboardAvoidMode.RESIZE_CONTENT避让行为。<br>嵌套滚动场景下不推荐使用web软键盘避让，包括RESIZE_VISUAL与RESIZE_CONTENT。|

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

### editMenuOptions<sup>12+</sup>

editMenuOptions(editMenu: EditMenuOptions)

Web组件自定义文本选择菜单。

用户可以通过该属性设置自定义的文本菜单。

在[onCreateMenu](../apis-arkui/arkui-ts/ts-text-common.md#oncreatemenu)中，可以修改、增加、删除菜单选项，如果希望不显示文本菜单，需要返回空数组。

在[onMenuItemClick](../apis-arkui/arkui-ts/ts-text-common.md#onmenuitemclick)中，可以自定义菜单选项的回调函数。该函数在菜单选项被点击后触发，并根据返回值决定是否执行系统默认的回调。返回true不执行系统回调，返回false继续执行系统回调。

本接口在与[selectionMenuOptions](#selectionmenuoptions12)同时使用时，会使selectionMenuOptions不生效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型                              | 必填   | 说明          |
| ------------------- | ------------------------------   | ------ | ------------- |
| editMenu | [EditMenuOptions](../apis-arkui/arkui-ts/ts-text-common.md#editmenuoptions对象说明) | 是     | Web自定义文本菜单选项。<br>菜单项数量，及菜单的content大小、icon图标尺寸，与ArkUI [Menu](../apis-arkui/arkui-ts/ts-basic-components-menu.md)组件保持一致。<br>菜单中系统自带的id枚举值（[TextMenuItemId](../apis-arkui/arkui-ts/ts-text-common.md#textmenuitemid12)）在Web中仅支持CUT、COPY、PASTE、SELECT_ALL四项。<br>onMenuItemClick函数中textRange参数在web中无意义，传入值为-1。|

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

### enableHapticFeedback<sup>13+</sup>

enableHapticFeedback(enabled: boolean)

设置Web组件长按文本选择是否开启振动，默认开启。 需配置"ohos.permission.VIBRATE"。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型        | 必填   | 说明 |
| --------- | ---------   | ------ | ------------- |
| enabled   | boolean | 是  | 是否开启振动。默认值：true。 |

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

### bindSelectionMenu<sup>13+</sup>

bindSelectionMenu(elementType: WebElementType, content: CustomBuilder, responseType: WebResponseType, options?: SelectionMenuOptionsExt)

设置自定义选择菜单。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型                             | 必填 | 说明                                |
| ------------ | ------------------------------- | ---- | ----------------------------------- |
| elementType     | [WebElementType](#webelementtype13枚举说明)             | 是   | 菜单的类型。   |
| content      | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)     | 是   | 菜单的内容。   |
| responseType | [WebResponseType](#webresponsetype13枚举说明)           | 是   | 菜单的响应类型。 |
| options      | [SelectionMenuOptionsExt](#selectionmenuoptionsext13)   | 否   | 菜单的选项。|

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
              this.previewWidth = px2vp(event.param.getPreviewWidth());
              this.previewHeight = px2vp(event.param.getPreviewHeight());
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

## 事件

通用事件仅支持[onAppear](../apis-arkui/arkui-ts/ts-universal-events-show-hide.md#onappear)、[onDisAppear](../apis-arkui/arkui-ts/ts-universal-events-show-hide.md#ondisappear)、[onBlur](../apis-arkui/arkui-ts/ts-universal-focus-event.md#onblur)、[onFocus](../apis-arkui/arkui-ts/ts-universal-focus-event.md#onfocus)、[onDragEnd](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragend)、[onDragEnter](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragenter)、[onDragStart](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragstart)、[onDragMove](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragmove)、[onDragLeave](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragleave)、[onDrop](../apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondrop)、[onHover](../apis-arkui/arkui-ts/ts-universal-mouse-key.md#onhover)、[onMouse](../apis-arkui/arkui-ts/ts-universal-mouse-key.md#onmouse)、[onKeyEvent](../apis-arkui/arkui-ts/ts-universal-events-key.md#onkeyevent)、[onTouch](../apis-arkui/arkui-ts/ts-universal-events-touch.md#ontouch)、[onVisibleAreaChange](../apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareachange)。

### onAlert

onAlert(callback: Callback\<OnAlertEvent, boolean\>)

网页触发alert()告警弹窗时触发回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                   | 必填   | 说明            |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnAlertEvent](#onalertevent12), boolean\>                | 是    | 网页触发alert()告警弹窗时触发<br>返回值boolean。当回调返回true时，应用可以调用自定义弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。当回调返回false时，函数中绘制的自定义弹窗无效。 |

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
          .onAlert((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              AlertDialog.show({
                title: 'onAlert',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handleConfirm();
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
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

onBeforeUnload(callback: Callback\<OnBeforeUnloadEvent, boolean\>)

刷新或关闭场景下，在即将离开当前页面时触发此回调。刷新或关闭当前页面应先通过点击等方式获取焦点，才会触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                  | 必填   | 说明            |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnBeforeUnloadEvent](#onbeforeunloadevent12), boolean\>                | 是    | 刷新或关闭场景下，在即将离开当前页面时触发。<br>返回值boolean。当回调返回true时，应用可以调用自定义弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。当回调返回false时，函数中绘制的自定义弹窗无效。 |

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
          .onBeforeUnload((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              AlertDialog.show({
                title: 'onBeforeUnload',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handleConfirm();
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
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

onConfirm(callback: Callback\<OnConfirmEvent, boolean\>)

网页调用confirm()告警时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                  | 必填   | 说明            |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnConfirmEvent](#onconfirmevent12), boolean\>                | 是    | 网页调用confirm()告警时触发<br>返回值boolean。当回调返回true时，应用可以调用自定义弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。当回调返回false时，函数中绘制的自定义弹窗无效。 |

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
          .onConfirm((event) => {
            if (event) {
              console.log("event.url:" + event.url);
              console.log("event.message:" + event.message);
              AlertDialog.show({
                title: 'onConfirm',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handleConfirm();
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
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

onPrompt(callback: Callback\<OnPromptEvent, boolean\>)

网页调用prompt()告警时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                  | 必填   | 说明            |
| ------- | --------------------- | ---- | --------------- |
| callback     | Callback\<[OnPromptEvent](#onpromptevent12), boolean\>                | 是    | 网页调用prompt()告警时触发。<br>返回值boolean。当回调返回true时，应用可以调用自定义弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。当回调返回false时，函数中绘制的自定义弹窗无效。 |

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
          .onPrompt((event) => {
            if (event) {
              console.log("url:" + event.url);
              console.log("message:" + event.message);
              console.log("value:" + event.value);
              AlertDialog.show({
                title: 'onPrompt',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.result.handleCancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    event.result.handlePromptConfirm(event.value);
                  }
                },
                cancel: () => {
                  event.result.handleCancel();
                }
              })
            }
            return true;
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

onConsole(callback: Callback\<OnConsoleEvent, boolean\>)

通知宿主应用JavaScript console消息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                              | 必填   | 说明      |
| ------- | --------------------------------- | ---- | --------- |
| callback | Callback\<[OnConsoleEvent](#onconsoleevent12), boolean\> | 是    | 网页收到JavaScript控制台消息时触发。<br>返回值boolean。当返回true时，该条消息将不会再打印至控制台，反之仍会打印至控制台。 |

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
        Button('onconsole message')
          .onClick(() => {
            this.controller.runJavaScript('myFunction()');
          })
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onConsole((event) => {
            if (event) {
              console.log('getMessage:' + event.message.getMessage());
              console.log('getSourceId:' + event.message.getSourceId());
              console.log('getLineNumber:' + event.message.getLineNumber());
              console.log('getMessageLevel:' + event.message.getMessageLevel());
            }
            return false;
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
  <body>
  <script>
      function myFunction() {
          console.log("onconsole printf");
      }
  </script>
  </body>
  </html>
  ```

### onDownloadStart

onDownloadStart(callback: Callback\<OnDownloadStartEvent\>)

通知主应用开始下载一个文件。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名                | 类型   | 必填   | 说明                                |
| ------------------ | ------ | ---- | ----------------------------------- |
| callback           | Callback\<[OnDownloadStartEvent](#ondownloadstartevent12)\> | 是    | 开始下载时触发。  |

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
          .onDownloadStart((event) => {
            if (event) {
              console.log('url:' + event.url)
              console.log('userAgent:' + event.userAgent)
              console.log('contentDisposition:' + event.contentDisposition)
              console.log('contentLength:' + event.contentLength)
              console.log('mimetype:' + event.mimetype)
            }
          })
      }
    }
  }
  ```

### onErrorReceive

onErrorReceive(callback: Callback\<OnErrorReceiveEvent\>)

网页加载遇到错误时触发该回调。主资源与子资源出错都会回调该接口，可以通过request.isMainFrame来判断是否是主资源报错。出于性能考虑，建议此回调中尽量执行简单逻辑。在无网络的情况下，触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                                     | 必填   | 说明            |
| ------- | ---------------------------------------- | ---- | --------------- |
| callback | Callback\<[OnErrorReceiveEvent](#onerrorreceiveevent12)\> | 是    | 网页收到 Web 资源加载错误时触发。      |

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
          .onErrorReceive((event) => {
            if (event) {
              console.log('getErrorInfo:' + event.error.getErrorInfo());
              console.log('getErrorCode:' + event.error.getErrorCode());
              console.log('url:' + event.request.getRequestUrl());
              console.log('isMainFrame:' + event.request.isMainFrame());
              console.log('isRedirect:' + event.request.isRedirect());
              console.log('isRequestGesture:' + event.request.isRequestGesture());
              console.log('getRequestHeader_headerKey:' + event.request.getRequestHeader().toString());
              let result = event.request.getRequestHeader();
              console.log('The request header result size is ' + result.length);
              for (let i of result) {
                console.log('The request header key is : ' + i.headerKey + ', value is : ' + i.headerValue);
              }
            }
          })
      }
    }
  }
  ```

### onHttpErrorReceive

onHttpErrorReceive(callback: Callback\<OnHttpErrorReceiveEvent\>)

网页加载资源遇到的HTTP错误（响应码>=400)时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型                                     | 必填   | 说明       |
| -------- | ---------------------------------------- | ---- | ---------- |
| callback  | Callback\<[OnHttpErrorReceiveEvent](#onhttperrorreceiveevent12)\> | 是    | 网页收到加载资源加载HTTP错误时触发。 |

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
          .onHttpErrorReceive((event) => {
            if (event) {
              console.log('url:' + event.request.getRequestUrl());
              console.log('isMainFrame:' + event.request.isMainFrame());
              console.log('isRedirect:' + event.request.isRedirect());
              console.log('isRequestGesture:' + event.request.isRequestGesture());
              console.log('getResponseData:' + event.response.getResponseData());
              console.log('getResponseEncoding:' + event.response.getResponseEncoding());
              console.log('getResponseMimeType:' + event.response.getResponseMimeType());
              console.log('getResponseCode:' + event.response.getResponseCode());
              console.log('getReasonMessage:' + event.response.getReasonMessage());
              let result = event.request.getRequestHeader();
              console.log('The request header result size is ' + result.length);
              for (let i of result) {
                console.log('The request header key is : ' + i.headerKey + ' , value is : ' + i.headerValue);
              }
              let resph = event.response.getResponseHeader();
              console.log('The response header result size is ' + resph.length);
              for (let i of resph) {
                console.log('The response header key is : ' + i.headerKey + ' , value is : ' + i.headerValue);
              }
            }
          })
      }
    }
  }
  ```

### onPageBegin

onPageBegin(callback: Callback\<OnPageBeginEvent\>)

网页开始加载时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明      |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnPageBeginEvent](#onpagebeginevent12)\> | 是    | 网页加载开始时触发。 |

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
          .onPageBegin((event) => {
            if (event) {
              console.log('url:' + event.url);
            }
          })
      }
    }
  }
  ```

### onPageEnd

onPageEnd(callback: Callback\<OnPageEndEvent\>)

网页加载完成时触发该回调，且只在主frame触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明      |
| ---- | ------ | ---- | --------- |
| callback  | Callback\<[OnPageEndEvent](#onpageendevent12)\> | 是    | 网页加载结束时触发。 |

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
          .onPageEnd((event) => {
            if (event) {
              console.log('url:' + event.url);
            }
          })
      }
    }
  }
  ```

### onProgressChange

onProgressChange(callback: Callback\<OnProgressChangeEvent\>)

网页加载进度变化时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名         | 类型   | 必填   | 说明                  |
| ----------- | ------ | ---- | --------------------- |
| callback | Callback\<[OnProgressChangeEvent](#onprogresschangeevent12)\> | 是    | 页面加载进度时触发的功能。 |

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
          .onProgressChange((event) => {
            if (event) {
              console.log('newProgress:' + event.newProgress);
            }
          })
      }
    }
  }
  ```

### onTitleReceive

onTitleReceive(callback: Callback\<OnTitleReceiveEvent\>)

网页document标题更改时触发该回调，当H5未设置<title\>元素时会返回对应的URL。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型   | 必填   | 说明          |
| ----- | ------ | ---- | ------------- |
| callback | Callback\<[OnTitleReceiveEvent](#ontitlereceiveevent12)\> | 是    | 定义主应用程序文档标题更改时触发。 |

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
          .onTitleReceive((event) => {
            if (event) {
              console.log('title:' + event.title);
            }
          })
      }
    }
  }
  ```

### onRefreshAccessedHistory

onRefreshAccessedHistory(callback: Callback\<OnRefreshAccessedHistoryEvent\>)

加载网页页面完成时触发该回调，用于应用更新其访问的历史链接。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名         | 类型    | 必填   | 说明                                     |
| ----------- | ------- | ---- | ---------------------------------------- |
| callback         | Callback\<[OnRefreshAccessedHistoryEvent](#onrefreshaccessedhistoryevent12)\>  | 是    | 在网页刷新访问历史记录时触发。                |

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
          .onRefreshAccessedHistory((event) => {
            if (event) {
              console.log('url:' + event.url + ' isReload:' + event.isRefreshed);
            }
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

**系统能力：** SystemCapability.Web.Webview.Core

### onFileSelectorShow<sup>(deprecated)</sup>

onFileSelectorShow(callback: (event?: { callback: Function, fileSelector: object }) => void)

调用此函数以处理具有“文件”输入类型的HTML表单，以响应用户按下的“选择文件”按钮。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[onShowFileSelector<sup>9+</sup>](#onshowfileselector9)替代。

**系统能力：** SystemCapability.Web.Webview.Core

### onRenderExited<sup>9+</sup>

onRenderExited(callback: Callback\<OnRenderExitedEvent\>)

应用渲染进程异常退出时触发该回调。

应用中的一个页面执行了onRenderExited之后所有Web组件都会退出。

应用处理该回调时，可以调用绑定的webviewController相关接口来恢复页面。例如[refresh](js-apis-webview.md#refresh)、[loadUrl](js-apis-webview.md#loadurl)等。

组件生命周期回调详情可参考[Web组件的生命周期](../../web/web-event-sequence.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型                                     | 必填   | 说明             |
| ---------------- | ---------------------------------------- | ---- | ---------------- |
| callback | Callback\<[OnRenderExitedEvent](#onrenderexitedevent12)\> | 是    | 渲染过程退出时触发。 |

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
        Web({ src: 'chrome://crash/', controller: this.controller })
          .onRenderExited((event) => {
            if (event) {
              console.log('reason:' + event.renderExitReason);
            }
          })
      }
    }
  }
  ```
### onRenderProcessNotResponding<sup>12+</sup>

onRenderProcessNotResponding(callback: OnRenderProcessNotRespondingCallback)

渲染进程无响应时触发该回调函数。如果Web组件无法处理输入事件，或者无法在合理的时间范围内导航到新的URL，则认为网页进程无响应，并将触发该回调。

只要网页进程一直无响应，此回调仍可能会持续触发，直到网页进程再次响应，此时[onRenderProcessResponding](#onrenderprocessresponding12)将会触发。

应用可以通过WebviewController接口[terminateRenderProcess](js-apis-webview.md#terminaterenderprocess12)来终止关联的渲染进程，这可能会影响同一渲染进程的其他Web组件。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                                         | 必填   | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [OnRenderProcessNotRespondingCallback](#onrenderprocessnotrespondingcallback12) | 是    | 渲染进程无响应时触发的回调。 |

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
          .onRenderProcessNotResponding((data) => {
            console.log("onRenderProcessNotResponding: [jsStack]= " + data.jsStack +
              ", [process]=" + data.pid + ", [reason]=" + data.reason);
          })
      }
    }
  }
  ```

### onRenderProcessResponding<sup>12+</sup>

onRenderProcessResponding(callback: OnRenderProcessRespondingCallback)

渲染进程由无响应状态变回正常运行状态时触发该回调函数,该回调表明该网页并非真正卡死。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                                         | 必填   | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [OnRenderProcessRespondingCallback](#onrenderprocessrespondingcallback12) | 是    | 渲染进程由无响应状态变回正常运行状态时触发的回调。 |

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
          .onRenderProcessResponding(() => {
            console.log("onRenderProcessResponding again");
          })
      }
    }
  }
  ```

### onShowFileSelector<sup>9+</sup>

onShowFileSelector(callback: Callback\<OnShowFileSelectorEvent, boolean\>)

调用此函数以处理具有“文件”输入类型的HTML表单。如果不调用此函数或返回false，Web组件会提供默认的“选择文件”处理界面。如果返回true，应用可以自定义“选择文件”的响应行为。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型                                     | 必填   | 说明              |
| ------------ | ---------------------------------------- | ---- | ----------------- |
| callback       | Callback\<[OnShowFileSelectorEvent](#onshowfileselectorevent12), boolean\> | 是    | 用于通知Web组件文件选择的结果。<br>返回值boolean。当返回值为true时，用户可以调用系统提供的弹窗能力。当回调返回false时，函数中绘制的自定义弹窗无效。 |

**示例：**

1. 拉起文件选择器。

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { picker } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController()

     build() {
       Column() {
         Web({ src: $rawfile('index.html'), controller: this.controller })
           .onShowFileSelector((event) => {
             console.log('MyFileUploader onShowFileSelector invoked')
             const documentSelectOptions = new picker.DocumentSelectOptions();
             let uri: string | null = null;
             const documentViewPicker = new picker.DocumentViewPicker();
             documentViewPicker.select(documentSelectOptions).then((documentSelectResult) => {
               uri = documentSelectResult[0];
               console.info('documentViewPicker.select to file succeed and uri is:' + uri);
               if (event) {
                 event.result.handleFileList([uri]);
               }
             }).catch((err: BusinessError) => {
               console.error(`Invoke documentViewPicker.select failed, code is ${err.code},  message is ${err.message}`);
             })
             return true;
           })
       }
     }
   }
   ```

2. 拉起图库选择器。

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { picker } from '@kit.CoreFileKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';

   @Entry
   @Component
   export struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController()

     async selectFile(result: FileSelectorResult): Promise<void> {
       let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
       let photoPicker = new photoAccessHelper.PhotoViewPicker();
       // 过滤选择媒体文件类型为IMAGE
       photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
       // 设置最大选择数量
       photoSelectOptions.maxSelectNumber = 5;
       let chooseFile: picker.PhotoSelectResult = await photoPicker.select(photoSelectOptions);
       // 获取选择的文件列表
       result.handleFileList(chooseFile.photoUris);
     }

     build() {
       Column() {
         Web({ src: $rawfile('index.html'), controller: this.controller })
           .onShowFileSelector((event) => {
             if (event) {
               this.selectFile(event.result);
             }
             return true;
           })
       }
     }
   }
   ```

   加载的html文件。
   ```html
   <!DOCTYPE html>
   <html>
   <head>
     <meta name="viewport" content="width=device-width, initial-scale=1.0" charset="utf-8">
   </head>
   <body>
     <form id="upload-form" enctype="multipart/form-data">
       <input type="file" id="upload" name="upload"/>
       </form>
   </body>
   </html>
   ```

### onResourceLoad<sup>9+</sup>

onResourceLoad(callback: Callback\<OnResourceLoadEvent\>)

通知Web组件所加载的资源文件url信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnResourceLoadEvent](#onresourceloadevent12)\> | 是 | 加载url时触发。 |

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
          .onResourceLoad((event) => {
            console.log('onResourceLoad: ' + event.url);
          })
      }
    }
  }
  ```

### onScaleChange<sup>9+</sup>

onScaleChange(callback: Callback\<OnScaleChangeEvent\>)

当前页面显示比例的变化时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScaleChangeEvent](#onscalechangeevent12)\> | 是 | 当前页面显示比例的变化时触发。 |

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
          .onScaleChange((event) => {
            console.log('onScaleChange changed from ' + event.oldScale + ' to ' + event.newScale);
          })
      }
    }
  }
  ```

### onUrlLoadIntercept<sup>(deprecated)</sup>

onUrlLoadIntercept(callback: (event?: { data:string | WebResourceRequest }) => boolean)

当Web组件加载url之前触发该回调，用于判断是否阻止此次访问。默认允许加载。
从API version 10开始不再维护，建议使用[onLoadIntercept<sup>10+</sup>](#onloadintercept10)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | (event?: { data:string \| [WebResourceRequest](#webresourcerequest) }) => boolean | 是 | url的相关信息。返回值：boolean，true表示阻止此次加载，否则允许此次加载。 |

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
          .onUrlLoadIntercept((event) => {
            if (event) {
              console.log('onUrlLoadIntercept ' + event.data.toString());
            }
            return true
          })
      }
    }
  }
  ```

### onInterceptRequest<sup>9+</sup>

onInterceptRequest(callback: Callback<OnInterceptRequestEvent, WebResourceResponse>)

当Web组件加载url之前触发该回调，用于拦截url并返回响应数据。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnInterceptRequestEvent](#oninterceptrequestevent12)\> | 是 | 当Web组件加载url之前触发。<br>返回值[WebResourceResponse](#webresourceresponse)。返回响应数据则按照响应数据加载，无响应数据则返回null表示按照原来的方式加载。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    responseWeb: WebResourceResponse = new WebResourceResponse();
    heads: Header[] = new Array();
    @State webData: string = "<!DOCTYPE html>\n" +
      "<html>\n" +
      "<head>\n" +
      "<title>intercept test</title>\n" +
      "</head>\n" +
      "<body>\n" +
      "<h1>intercept test</h1>\n" +
      "</body>\n" +
      "</html>";

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onInterceptRequest((event) => {
            if (event) {
              console.log('url:' + event.request.getRequestUrl());
            }
            let head1: Header = {
              headerKey: "Connection",
              headerValue: "keep-alive"
            }
            let head2: Header = {
              headerKey: "Cache-Control",
              headerValue: "no-cache"
            }
            // 将新元素追加到数组的末尾，并返回数组的新长度。
            let length = this.heads.push(head1);
            length = this.heads.push(head2);
            console.log('The response header result length is :' + length);
            const promise: Promise<String> = new Promise((resolve: Function, reject: Function) => {
              this.responseWeb.setResponseHeader(this.heads);
              this.responseWeb.setResponseData(this.webData);
              this.responseWeb.setResponseEncoding('utf-8');
              this.responseWeb.setResponseMimeType('text/html');
              this.responseWeb.setResponseCode(200);
              this.responseWeb.setReasonMessage('OK');
              resolve("success");
            })
            promise.then(() => {
              console.log("prepare response ready");
              this.responseWeb.setResponseIsReady(true);
            })
            this.responseWeb.setResponseIsReady(false);
            return this.responseWeb;
          })
      }
    }
  }
  ```

### onHttpAuthRequest<sup>9+</sup>

onHttpAuthRequest(callback: Callback\<OnHttpAuthRequestEvent, boolean\>)

通知收到http auth认证请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnHttpAuthRequestEvent](#onhttpauthrequestevent12), boolean\> | 是 | 当浏览器需要用户的凭据时触发。<br>返回值boolean。返回false表示此次认证失败，否则成功。   |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    httpAuth: boolean = false;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onHttpAuthRequest((event) => {
            if (event) {
              AlertDialog.show({
                title: 'onHttpAuthRequest',
                message: 'text',
                primaryButton: {
                  value: 'cancel',
                  action: () => {
                    event.handler.cancel();
                  }
                },
                secondaryButton: {
                  value: 'ok',
                  action: () => {
                    this.httpAuth = event.handler.isHttpAuthInfoSaved();
                    if (this.httpAuth == false) {
                      webview.WebDataBase.saveHttpAuthCredentials(
                        event.host,
                        event.realm,
                        "2222",
                        "2222"
                      )
                      event.handler.cancel();
                    }
                  }
                },
                cancel: () => {
                  event.handler.cancel();
                }
              })
            }
            return true;
          })
      }
    }
  }
  ```
### onSslErrorEventReceive<sup>9+</sup>

onSslErrorEventReceive(callback: Callback\<OnSslErrorEventReceiveEvent\>)

通知用户加载资源时发生SSL错误，只支持主资源。
如果需要支持子资源，请使用[OnSslErrorEvent](#onsslerrorevent12)接口。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnSslErrorEventReceiveEvent](#onsslerroreventreceiveevent12)\> | 是 | 当网页收到SSL错误时触发。 |

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
          .onSslErrorEventReceive((event) => {
            AlertDialog.show({
              title: 'onSslErrorEventReceive',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.handleConfirm();
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.handleCancel();
                }
              },
              cancel: () => {
                event.handler.handleCancel();
              }
            })
          })
      }
    }
  }
  ```

### onSslErrorEvent<sup>12+</sup>

onSslErrorEvent(callback: OnSslErrorEventCallback)

通知用户加载资源（主资源+子资源）时发生SSL错误，如果只想处理主资源的SSL错误，请用isMainFrame字段进行区分。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnSslErrorEventCallback](#onsslerroreventcallback12) | 是 | 通知用户加载资源时发生SSL错误。 |

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
          .onSslErrorEvent((event: SslErrorEvent) => {
            console.log("onSslErrorEvent url: " + event.url);
            console.log("onSslErrorEvent error: " + event.error);
            console.log("onSslErrorEvent originalUrl: " + event.originalUrl);
            console.log("onSslErrorEvent referrer: " + event.referrer);
            console.log("onSslErrorEvent isFatalError: " + event.isFatalError);
            console.log("onSslErrorEvent isMainFrame: " + event.isMainFrame);
            AlertDialog.show({
              title: 'onSslErrorEvent',
              message: 'text',
              primaryButton: {
                value: 'confirm',
                action: () => {
                  event.handler.handleConfirm();
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.handleCancel();
                }
              },
              cancel: () => {
                event.handler.handleCancel();
              }
            })
          })
      }
    }
  }
  ```

### onClientAuthenticationRequest<sup>9+</sup>

onClientAuthenticationRequest(callback: Callback\<OnClientAuthenticationEvent\>)

通知用户收到SSL客户端证书请求事件。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnClientAuthenticationEvent](#onclientauthenticationevent12)\> | 是 | 当需要用户提供的SSL客户端证书时触发的回调。  |

  **示例：**

  未对接证书管理的双向认证。

  ```ts
  // xxx.ets API9
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

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
                  event.handler.confirm("/system/etc/user.pk8", "/system/etc/chain-user.pem");
                }
              },
              secondaryButton: {
                value: 'cancel',
                action: () => {
                  event.handler.cancel();
                }
              },
              cancel: () => {
                event.handler.ignore();
              }
            })
          })
      }
    }
  }
  ```

  对接证书管理的双向认证。

  1. 构造单例对象GlobalContext。

     ```ts
     // GlobalContext.ets
     export class GlobalContext {
       private constructor() {}
       private static instance: GlobalContext;
       private _objects = new Map<string, Object>();

       public static getContext(): GlobalContext {
         if (!GlobalContext.instance) {
           GlobalContext.instance = new GlobalContext();
         }
         return GlobalContext.instance;
       }

       getObject(value: string): Object | undefined {
         return this._objects.get(value);
       }

       setObject(key: string, objectClass: Object): void {
         this._objects.set(key, objectClass);
       }
     }
     ```


  2. 实现双向认证。

     ```ts
     // xxx.ets API10
     import { webview } from '@kit.ArkWeb';
     import { common, Want, bundleManager } from '@kit.AbilityKit';
     import { BusinessError } from '@kit.BasicServicesKit';
     import { GlobalContext } from '../GlobalContext';

     let uri = "";

     export default class CertManagerService {
       private static sInstance: CertManagerService;
       private authUri = "";
       private appUid = "";

       public static getInstance(): CertManagerService {
         if (CertManagerService.sInstance == null) {
           CertManagerService.sInstance = new CertManagerService();
         }
         return CertManagerService.sInstance;
       }

       async grantAppPm(callback: (message: string) => void) {
         let message = '';
         let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION;
         // 注：com.example.myapplication需要写实际应用名称
         try {
           bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
             console.info('getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(data));
            this.appUid = data.appInfo.uid.toString();
           }).catch((err: BusinessError) => {
             console.error('getBundleInfoForSelf failed. Cause: %{public}s', err.message);
           });
         } catch (err) {
           let message = (err as BusinessError).message;
           console.error('getBundleInfoForSelf failed: %{public}s', message);
         }

         // 注：需要在MainAbility.ts文件的onCreate函数里添加GlobalContext.getContext().setObject("AbilityContext", this.context)
         let abilityContext = GlobalContext.getContext().getObject("AbilityContext") as common.UIAbilityContext
         await abilityContext.startAbilityForResult(
           {
             bundleName: "com.ohos.certmanager",
             abilityName: "MainAbility",
             uri: "requestAuthorize",
             parameters: {
               appUid: this.appUid, // 传入申请应用的appUid
             }
           } as Want)
           .then((data: common.AbilityResult) => {
             if (!data.resultCode && data.want) {
               if (data.want.parameters) {
                 this.authUri = data.want.parameters.authUri as string; // 授权成功后获取返回的authUri
               }
             }
           })
         message += "after grantAppPm authUri: " + this.authUri;
         uri = this.authUri;
         callback(message)
       }
     }

     @Entry
     @Component
     struct WebComponent {
       controller: webview.WebviewController = new webview.WebviewController();
       @State message: string = 'Hello World' // message主要是调试观察使用
       certManager = CertManagerService.getInstance();

       build() {
         Row() {
           Column() {
             Row() {
               // 第一步：需要先进行授权，获取到uri
               Button('GrantApp')
                 .onClick(() => {
                   this.certManager.grantAppPm((data) => {
                     this.message = data;
                   });
                 })
               // 第二步：授权后，双向认证会通过onClientAuthenticationRequest回调将uri传给web进行认证
               Button("ClientCertAuth")
                 .onClick(() => {
                   this.controller.loadUrl('https://www.example2.com'); // 支持双向认证的服务器网站
                 })
             }

             Web({ src: 'https://www.example1.com', controller: this.controller })
               .fileAccess(true)
               .javaScriptAccess(true)
               .domStorageAccess(true)
               .onlineImageAccess(true)

               .onClientAuthenticationRequest((event) => {
                 AlertDialog.show({
                   title: 'ClientAuth',
                   message: 'Text',
                   confirm: {
                     value: 'Confirm',
                     action: () => {
                       event.handler.confirm(uri);
                     }
                   },
                   cancel: () => {
                     event.handler.cancel();
                   }
                 })
               })
           }
         }
         .width('100%')
         .height('100%')
       }
     }
     ```

### onPermissionRequest<sup>9+</sup>

onPermissionRequest(callback: Callback\<OnPermissionRequestEvent\>)

通知收到获取权限请求，需配置"ohos.permission.CAMERA"、"ohos.permission.MICROPHONE"权限。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnPermissionRequestEvent](#onpermissionrequestevent12)\> | 是 | 通知收到获取权限请求触发。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { abilityAccessCtrl } from '@kit.AbilityKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    aboutToAppear() {
      // 配置Web开启调试模式
      webview.WebviewController.setWebDebuggingAccess(true);
      let atManager = abilityAccessCtrl.createAtManager();
      atManager.requestPermissionsFromUser(getContext(this), ['ohos.permission.CAMERA', 'ohos.permission.MICROPHONE'])
        .then((data) => {
          console.info('data:' + JSON.stringify(data));
          console.info('data permissions:' + data.permissions);
          console.info('data authResults:' + data.authResults);
        }).catch((error: BusinessError) => {
        console.error(`Failed to request permissions from user. Code is ${error.code}, message is ${error.message}`);
      })
    }

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onPermissionRequest((event) => {
            if (event) {
              AlertDialog.show({
                title: 'title',
                message: 'text',
                primaryButton: {
                  value: 'deny',
                  action: () => {
                    event.request.deny();
                  }
                },
                secondaryButton: {
                  value: 'onConfirm',
                  action: () => {
                    event.request.grant(event.request.getAccessibleResource());
                  }
                },
                cancel: () => {
                  event.request.deny();
                }
              })
            }
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
  <head>
    <meta charset="UTF-8">
  </head>
  <body>
  <video id="video" width="500px" height="500px" autoplay="autoplay"></video>
  <canvas id="canvas" width="500px" height="500px"></canvas>
  <br>
  <input type="button" title="HTML5摄像头" value="开启摄像头" onclick="getMedia()"/>
  <script>
    function getMedia()
    {
      let constraints = {
        video: {width: 500, height: 500},
        audio: true
      };
      // 获取video摄像头区域
      let video = document.getElementById("video");
      // 返回的Promise对象
      let promise = navigator.mediaDevices.getUserMedia(constraints);
      // then()异步，调用MediaStream对象作为参数
      promise.then(function (MediaStream) {
        video.srcObject = MediaStream;
        video.play();
      });
    }
  </script>
  </body>
  </html>
 ```

### onContextMenuShow<sup>9+</sup>

onContextMenuShow(callback: Callback\<OnContextMenuShowEvent, boolean\>)

长按特定元素（例如图片，链接）或鼠标右键，跳出菜单。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnContextMenuShowEvent](#oncontextmenushowevent12), boolean\> | 是 | 调用时触发的回调，以允许自定义显示上下文菜单。<br>返回值boolean。自定义菜单返回true，触发的自定义菜单无效返回false。     |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { pasteboard } from '@kit.BasicServicesKit';

  const TAG = 'ContextMenu';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    private result: WebContextMenuResult | undefined = undefined;
    @State linkUrl: string = '';
    @State offsetX: number = 0;
    @State offsetY: number = 0;
    @State showMenu: boolean = false;

    @Builder
    // 构建自定义菜单及触发功能接口
    MenuBuilder() {
      // 以垂直列表形式显示的菜单。
      Menu() {
        // 展示菜单Menu中具体的item菜单项。
        MenuItem({
          content: '复制图片',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.copyImage();
            this.showMenu = false;
          })
        MenuItem({
          content: '剪切',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.cut();
            this.showMenu = false;
          })
        MenuItem({
          content: '复制',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.copy();
            this.showMenu = false;
          })
        MenuItem({
          content: '粘贴',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.paste();
            this.showMenu = false;
          })
        MenuItem({
          content: '复制链接',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            let pasteData = pasteboard.createData('text/plain', this.linkUrl);
            pasteboard.getSystemPasteboard().setData(pasteData, (error) => {
              if (error) {
                return;
              }
            })
            this.showMenu = false;
          })
        MenuItem({
          content: '全选',
        })
          .width(100)
          .height(50)
          .onClick(() => {
            this.result?.selectAll();
            this.showMenu = false;
          })
      }
      .width(150)
      .height(300)
    }

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          // 触发自定义弹窗
          .onContextMenuShow((event) => {
            if (event) {
              this.result = event.result
              console.info("x coord = " + event.param.x());
              console.info("link url = " + event.param.getLinkUrl());
              this.linkUrl = event.param.getLinkUrl();
            }
            console.info(TAG, `x: ${this.offsetX}, y: ${this.offsetY}`);
            this.showMenu = true;
            this.offsetX = 250;
            this.offsetY = Math.max(px2vp(event?.param.y() ?? 0) - 0, 0);
            return true;
          })
          .bindPopup(this.showMenu,
            {
              builder: this.MenuBuilder(),
              enableArrow: false,
              placement: Placement.LeftTop,
              offset: { x: this.offsetX, y: this.offsetY },
              mask: false,
              onStateChange: (e) => {
                if (!e.isVisible) {
                  this.showMenu = false;
                  this.result!.closeContextMenu();
                }
              }
            })
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html lang="en">
  <body>
    <h1>onContextMenuShow</h1>
    <a href="http://www.example.com" style="font-size:27px">链接www.example.com</a>
    // rawfile下放任意一张图片命名为example.png
    <div><img src="example.png"></div>
    <p>选中文字鼠标右键弹出菜单</p>
  </body>
  </html>
  ```

### onContextMenuHide<sup>11+</sup>

onContextMenuHide(callback: OnContextMenuHideCallback)

长按特定元素（例如图片，链接）或鼠标右键，隐藏菜单。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | [OnContextMenuHideCallback](#oncontextmenuhidecallback11) | 是 | 菜单相关参数。     |

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
          .onContextMenuHide(() => {
            console.log("onContextMenuHide callback");
          })
      }
    }
  }
  ```

### onScroll<sup>9+</sup>

onScroll(callback: Callback\<OnScrollEvent\>)

通知网页滚动条滚动位置。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScrollEvent](#onscrollevent12)\> | 是 | 当滚动条滑动到指定位置时触发。 |

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
          .onScroll((event) => {
            console.info("x = " + event.xOffset);
            console.info("y = " + event.yOffset);
          })
      }
    }
  }
  ```

### onGeolocationShow

onGeolocationShow(callback: Callback\<OnGeolocationShowEvent\>)

通知用户收到地理位置信息获取请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback      | Callback\<[OnGeolocationShowEvent](#ongeolocationshowevent12)\>  | 是 | 请求显示地理位置权限时触发。     |

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
          .geolocationAccess(true)
          .onGeolocationShow((event) => {
            if (event) {
              AlertDialog.show({
                title: 'title',
                message: 'text',
                confirm: {
                  value: 'onConfirm',
                  action: () => {
                    event.geolocation.invoke(event.origin, true, true);
                  }
                },
                cancel: () => {
                  event.geolocation.invoke(event.origin, false, true);
                }
              })
            }
          })
      }
    }
  }
  ```

  加载的html文件。
  ```html
  <!DOCTYPE html>
  <html>
  <body>
  <p id="locationInfo">位置信息</p>
  <button onclick="getLocation()">获取位置</button>
  <script>
  var locationInfo=document.getElementById("locationInfo");
  function getLocation(){
    if (navigator.geolocation) {
      <!-- 前端页面访问设备地理位置 -->
      navigator.geolocation.getCurrentPosition(showPosition);
    }
  }
  function showPosition(position){
    locationInfo.innerHTML="Latitude: " + position.coords.latitude + "<br />Longitude: " + position.coords.longitude;
  }
  </script>
  </body>
  </html>
  ```

### onGeolocationHide

onGeolocationHide(callback: () => void)

通知用户先前被调用[onGeolocationShow](#ongeolocationshow)时收到地理位置信息获取请求已被取消。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | 是 | 地理位置信息获取请求已被取消的回调函数。 |

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
          .onGeolocationHide(() => {
            console.log("onGeolocationHide...");
          })
      }
    }
  }
  ```

### onFullScreenEnter<sup>9+</sup>

onFullScreenEnter(callback: OnFullScreenEnterCallback)

通知开发者Web组件进入全屏模式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnFullScreenEnterCallback](#onfullscreenentercallback12) | 是 | Web组件进入全屏时的回调信息。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    handler: FullScreenExitHandler | null = null;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onFullScreenEnter((event) => {
            console.log("onFullScreenEnter videoWidth: " + event.videoWidth +
              ", videoHeight: " + event.videoHeight);
            // 应用可以通过 this.handler.exitFullScreen() 主动退出全屏。
            this.handler = event.handler;
          })
      }
    }
  }
  ```

### onFullScreenExit<sup>9+</sup>

onFullScreenExit(callback: () => void)

通知开发者Web组件退出全屏模式。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | 是 | 退出全屏模式时的回调函数。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    handler: FullScreenExitHandler | null = null;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onFullScreenExit(() => {
            console.log("onFullScreenExit...")
            if (this.handler) {
              this.handler.exitFullScreen();
            }
          })
          .onFullScreenEnter((event) => {
            this.handler = event.handler;
          })
      }
    }
  }
  ```

### onWindowNew<sup>9+</sup>

onWindowNew(callback: Callback\<OnWindowNewEvent\>)

使能multiWindowAccess情况下，通知用户新建窗口请求。
若不调用event.handler.setWebController接口，会造成render进程阻塞。
如果不需要打开新窗口，在调用event.handler.setWebController接口时须设置成null。

应用应谨慎的显示新窗口：不要简单的覆盖在原web组件上，防止误导用户正在查看哪个网站，如果应用显示主页的URL，请确保也以相似的方式显示新窗口的URL。否则请考虑完全禁止创建新窗口。

注意：没有可靠的方式判断哪个页面请求了新窗口，该请求可能来自第三方iframe

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | Callback\<[OnWindowNewEvent](#onwindownewevent12)\>           | 是 | 网页要求用户创建窗口时触发的回调。    |

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
            // 如果不需要打开新窗口请调用event.handler.setWebController接口设置成null。
            // 若不调用event.handler.setWebController接口，会造成render进程阻塞。
            event.handler.setWebController(popController);
          })
      }
    }
  }
  ```

### onWindowExit<sup>9+</sup>

onWindowExit(callback: () => void)

通知用户窗口关闭请求。和[onWindowNew](#onwindownew9)一样，从安全角度讲，应用应该确保用户可以知道他们交互的页面已关闭。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | () => void | 是 | 窗口请求关闭的回调函数。 |

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
          .onWindowExit(() => {
            console.log("onWindowExit...");
          })
      }
    }
  }
  ```

### onSearchResultReceive<sup>9+</sup>

onSearchResultReceive(callback: Callback\<OnSearchResultReceiveEvent\>)

回调通知调用方网页页内查找的结果。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnSearchResultReceiveEvent](#onsearchresultreceiveevent12)\>  | 是 | 通知调用方网页页内查找的结果。         |

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
          .onSearchResultReceive(ret => {
            if (ret) {
              console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
                "[total]" + ret.numberOfMatches + "[isDone]" + ret.isDoneCounting);
            }
          })
      }
    }
  }
  ```

### onDataResubmitted<sup>9+</sup>

onDataResubmitted(callback: Callback\<OnDataResubmittedEvent\>)

设置网页表单可以重新提交时触发的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnDataResubmittedEvent](#ondataresubmittedevent12)\> | 是 | 网页表单可以重新提交时触发。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 在网页中点击提交之后，点击refresh按钮可以重新提交时的触发函数。
        Button('refresh')
          .onClick(() => {
            try {
              this.controller.refresh();
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onDataResubmitted((event) => {
            console.log('onDataResubmitted');
            event.handler.resend();
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
  <head>
    <meta charset="utf-8">
  </head>
  <body>
    <form action="http://httpbin.org/post" method="post">
      <input type="text" name="username">
      <input type="submit" name="提交">
    </form>
  </body>
  </html>
 ```

### onPageVisible<sup>9+</sup>

onPageVisible(callback: Callback\<OnPageVisibleEvent\>)

设置旧页面不再呈现，新页面即将可见时触发的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnPageVisibleEvent](#onpagevisibleevent12)\> | 是 | 旧页面不再呈现，新页面即将可见时触发的回调函数。 |

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
          .onPageVisible((event) => {
            console.log('onPageVisible url:' + event.url);
          })
      }
    }
  }
  ```

### onInterceptKeyEvent<sup>9+</sup>

onInterceptKeyEvent(callback: (event: KeyEvent) => boolean)

设置键盘事件的回调函数，该回调在被Webview使用前触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | (event:[KeyEvent](../apis-arkui/arkui-ts/ts-universal-events-key.md#keyevent对象说明)) => boolean | 是 | 触发的KeyEvent事件。返回值：回调函数通过返回boolean类型值来决定是否继续将该KeyEvent传入Webview内核。 |

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
          .onInterceptKeyEvent((event) => {
            if (event.keyCode == 2017 || event.keyCode == 2018) {
              console.info(`onInterceptKeyEvent get event.keyCode ${event.keyCode}`);
              return true;
            }
            return false;
          })
      }
    }
  }
  ```

### onTouchIconUrlReceived<sup>9+</sup>

onTouchIconUrlReceived(callback: Callback\<OnTouchIconUrlReceivedEvent\>)

设置接收到apple-touch-icon url地址时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | Callback\<[OnTouchIconUrlReceivedEvent](#ontouchiconurlreceivedevent12)\>  | 是 | 接收到的apple-touch-icon url地址时触发。 |

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
        Web({ src: 'www.baidu.com', controller: this.controller })
          .onTouchIconUrlReceived((event) => {
            console.log('onTouchIconUrlReceived:' + JSON.stringify(event));
          })
      }
    }
  }
  ```

### onFaviconReceived<sup>9+</sup>

onFaviconReceived(callback: Callback\<OnFaviconReceivedEvent\>)

设置应用为当前页面接收到新的favicon时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnFaviconReceivedEvent](#onfaviconreceivedevent12)\> | 是 | 当前页面接收到新的favicon时触发。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { image } from '@kit.ImageKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State icon: image.PixelMap | undefined = undefined;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onFaviconReceived((event) => {
            console.log('onFaviconReceived');
            this.icon = event.favicon;
          })
      }
    }
  }
  ```

### onAudioStateChanged<sup>10+</sup>

onAudioStateChanged(callback: Callback\<OnAudioStateChangedEvent\>)

设置网页上的音频播放状态发生改变时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnAudioStateChangedEvent](#onaudiostatechangedevent12)\> | 是 | 网页上的音频播放状态发生改变时触发。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State playing: boolean = false;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onAudioStateChanged(event => {
            this.playing = event.playing;
            console.debug('onAudioStateChanged playing: ' + this.playing);
          })
      }
    }
  }
  ```

### onFirstContentfulPaint<sup>10+</sup>

 onFirstContentfulPaint(callback: Callback\<OnFirstContentfulPaintEvent\>)

设置网页首次内容绘制回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback    | Callback\<[OnFirstContentfulPaintEvent](#onfirstcontentfulpaintevent12)\> | 是 | 网页首次内容绘制回调函数。          |

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
          .onFirstContentfulPaint(event => {
            if (event) {
              console.log("onFirstContentfulPaint:" + "[navigationStartTick]:" +
              event.navigationStartTick + ", [firstContentfulPaintMs]:" +
              event.firstContentfulPaintMs);
            }
          })
      }
    }
  }
  ```

### onFirstMeaningfulPaint<sup>12+</sup>

onFirstMeaningfulPaint(callback: [OnFirstMeaningfulPaintCallback](#onfirstmeaningfulpaintcallback12))

设置网页绘制页面主要内容回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnFirstMeaningfulPaintCallback](#onfirstmeaningfulpaintcallback12) | 是 | 网页绘制页面主要内容度量信息的回调。 |

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
          .onFirstMeaningfulPaint((details) => {
            console.log("onFirstMeaningfulPaint: [navigationStartTime]= " + details.navigationStartTime +
              ", [firstMeaningfulPaintTime]=" + details.firstMeaningfulPaintTime);
          })
      }
    }
  }
  ```

### onLargestContentfulPaint<sup>12+</sup>

onLargestContentfulPaint(callback: [OnLargestContentfulPaintCallback](#onlargestcontentfulpaintcallback12))

设置网页绘制页面最大内容回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnLargestContentfulPaintCallback](#onlargestcontentfulpaintcallback12) | 是 | 网页绘制页面最大内容度量信息的回调。 |

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
          .onLargestContentfulPaint((details) => {
            console.log("onLargestContentfulPaint: [navigationStartTime]= " + details.navigationStartTime +
              ", [largestImagePaintTime]=" + details.largestImagePaintTime +
              ", [largestTextPaintTime]=" + details.largestTextPaintTime +
              ", [largestImageLoadStartTime]=" + details.largestImageLoadStartTime +
              ", [largestImageLoadEndTime]=" + details.largestImageLoadEndTime +
              ", [imageBPP]=" + details.imageBPP);
          })
      }
    }
  }
  ```

### onLoadIntercept<sup>10+</sup>

onLoadIntercept(callback: Callback\<OnLoadInterceptEvent, boolean\>)

当Web组件加载url之前触发该回调，用于判断是否阻止此次访问。默认允许加载。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnLoadInterceptEvent](#onloadinterceptevent12), boolean\> | 是 | 截获资源加载时触发的回调。<br>返回值boolean。返回true表示阻止此次加载，否则允许此次加载。 |

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
          .onLoadIntercept((event) => {
            console.log('url:' + event.data.getRequestUrl());
            console.log('isMainFrame:' + event.data.isMainFrame());
            console.log('isRedirect:' + event.data.isRedirect());
            console.log('isRequestGesture:' + event.data.isRequestGesture());
            return true;
          })
      }
    }
  }
  ```

### onRequestSelected

onRequestSelected(callback: () => void)

当Web组件获得焦点时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

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
          .onRequestSelected(() => {
            console.log('onRequestSelected');
          })
      }
    }
  }
  ```
### onScreenCaptureRequest<sup>10+</sup>

onScreenCaptureRequest(callback: Callback\<OnScreenCaptureRequestEvent\>)

通知收到屏幕捕获请求。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnScreenCaptureRequestEvent](#onscreencapturerequestevent12)\> | 是 | 通知收到屏幕捕获请求。 |

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
          .onScreenCaptureRequest((event) => {
            if (event) {
              AlertDialog.show({
                title: 'title: ' + event.handler.getOrigin(),
                message: 'text',
                primaryButton: {
                  value: 'deny',
                  action: () => {
                    event.handler.deny();
                  }
                },
                secondaryButton: {
                  value: 'onConfirm',
                  action: () => {
                    event.handler.grant({ captureMode: WebCaptureMode.HOME_SCREEN });
                  }
                },
                cancel: () => {
                  event.handler.deny();
                }
              })
            }
          })
      }
    }
  }
  ```

### onOverScroll<sup>10+</sup>

onOverScroll(callback: Callback\<OnOverScrollEvent\>)

该接口在网页过度滚动时触发，用于通知网页过度滚动的偏移量。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | Callback\<[OnOverScrollEvent](#onoverscrollevent12)\> | 是 | 网页过度滚动时触发。 |

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
          .onOverScroll((event) => {
            console.info("x = " + event.xOffset);
            console.info("y = " + event.yOffset);
          })
      }
    }
  }
  ```

### onControllerAttached<sup>10+</sup>

onControllerAttached(callback: () => void)

当Controller成功绑定到Web组件时触发该回调，并且该Controller必须为WebviewController，且禁止在该事件回调前调用Web组件相关的接口，否则会抛出js-error异常。
因该回调调用时网页还未加载，无法在回调中使用有关操作网页的接口，例如[zoomIn](js-apis-webview.md#zoomin)、[zoomOut](js-apis-webview.md#zoomout)等，可以使用[loadUrl](js-apis-webview.md#loadurl)、[getWebId](js-apis-webview.md#getwebid)等操作网页不相关的接口。

组件生命周期详情可参考[Web组件的生命周期](../../web/web-event-sequence.md)。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

在该回调中使用loadUrl加载网页
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: '', controller: this.controller })
          .onControllerAttached(() => {
            this.controller.loadUrl($rawfile("index.html"));
          })
      }
    }
  }
  ```

在该回调中使用getWebId
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .onControllerAttached(() => {
            try {
              let id = this.controller.getWebId();
              console.log("id: " + id);
            } catch (error) {
              let code = (error as BusinessError).code;
              let message = (error as BusinessError).message;
              console.error(`ErrorCode: ${code},  Message: ${message}`);
            }
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
      <body>
          <p>Hello World</p>
      </body>
  </html>
  ```

### onNavigationEntryCommitted<sup>11+</sup>

onNavigationEntryCommitted(callback: [OnNavigationEntryCommittedCallback](#onnavigationentrycommittedcallback11))

当网页跳转提交时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnNavigationEntryCommittedCallback](#onnavigationentrycommittedcallback11) | 是 | 网页跳转提交时触发的回调。 |

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
          .onNavigationEntryCommitted((details) => {
            console.log("onNavigationEntryCommitted: [isMainFrame]= " + details.isMainFrame +
              ", [isSameDocument]=" + details.isSameDocument +
              ", [didReplaceEntry]=" + details.didReplaceEntry +
              ", [navigationType]=" + details.navigationType +
              ", [url]=" + details.url);
          })
      }
    }
  }
  ```

### onSafeBrowsingCheckResult<sup>11+</sup>

onSafeBrowsingCheckResult(callback: OnSafeBrowsingCheckResultCallback)

收到网站安全风险检查结果时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback  | [OnSafeBrowsingCheckResultCallback](#onsafebrowsingcheckresultcallback11) | 是 | 收到网站安全风险检查结果时触发的回调。|

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  export enum ThreatType {
    UNKNOWN = -1,
    THREAT_ILLEGAL = 0,
    THREAT_FRAUD = 1,
    THREAT_RISK = 2,
    THREAT_WARNING = 3,
  }

  export class OnSafeBrowsingCheckResultCallback {
    threatType: ThreatType = ThreatType.UNKNOWN;
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onSafeBrowsingCheckResult((callback) => {
            let jsonData = JSON.stringify(callback);
            let json: OnSafeBrowsingCheckResultCallback = JSON.parse(jsonData);
            console.log("onSafeBrowsingCheckResult: [threatType]= " + json.threatType);
          })
      }
    }
  }
  ```

### onNativeEmbedLifecycleChange<sup>11+</sup>

onNativeEmbedLifecycleChange(callback: (event: NativeEmbedDataInfo) => void)

当同层标签生命周期变化时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | (event: [NativeEmbedDataInfo](#nativeembeddatainfo11)) => void | 是 | 同层标签生命周期变化时触发该回调。 |

**示例：**

```ts
// EntryAbility.ets

import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    // API12新增：开启同层渲染BFCache开关
    let features = new webview.BackForwardCacheSupportedFeatures();
    features.nativeEmbed = true;
    features.mediaTakeOver = true;
    webview.WebviewController.enableBackForwardCache(features);
    webview.WebviewController.initializeWebEngine();
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content.');
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    @State embedStatus: string = '';
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 默认行为：点击按钮跳转页面，关闭index页面，使同层标签销毁。
        // API12新增：使能同层渲染所在的页面支持BFCache后，点击按钮跳转页面，关闭index页面，使同层标签进入BFCache。
        Button('Destroy')
        .onClick(() => {
          try {
            this.controller.loadUrl("www.example.com");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

        // API12新增：使能同层渲染所在的页面支持BFCache后，点击按钮返回页面，使同层标签离开BFCache。
        Button('backward')
        .onClick(() => {
          try {
            this.controller.backward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

        // API12新增：使能同层渲染所在的页面支持BFCache后，点击按钮前进页面，使同层标签进入BFCache。
        Button('forward')
        .onClick(() => {
          try {
            this.controller.forward();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })


        // API12新增同层标签进入离开BFCache状态：非http与https协议加载的网页，Web内核不支持进入BFCache;
        // 因此如果要测试ENTER_BFCACHE/LEAVE_BFCACHE状态，需要将index.html放到Web服务器上，使用http或者https协议加载，如：
        // Web({ src: "http://xxxx/index.html", controller: this.controller })
        Web({ src: $rawfile("index.html"), controller: this.controller })
          .enableNativeEmbedMode(true)
          .onNativeEmbedLifecycleChange((event) => {
            // 当加载页面中有同层标签会触发Create。
            if (event.status == NativeEmbedStatus.CREATE) {
              this.embedStatus = 'Create';
            }
            // 当页面中同层标签移动或者缩放时会触发Update。
            if (event.status == NativeEmbedStatus.UPDATE) {
              this.embedStatus = 'Update';
            }
            // 退出页面时会触发Destroy。
            if (event.status == NativeEmbedStatus.DESTROY) {
              this.embedStatus = 'Destroy';
            }
            // 同层标签所在的页面进入BFCache时，会触发Enter BFCache。
            if (event.status == NativeEmbedStatus.ENTER_BFCACHE) {
              this.embedStatus = 'Enter BFCache';
            }
            // 同层标签所在的页面离开BFCache时，会触发Leave BFCache。
            if (event.status == NativeEmbedStatus.LEAVE_BFCACHE) {
              this.embedStatus = 'Leave BFCache';
            }
            console.log("status = " + this.embedStatus);
            console.log("surfaceId = " + event.surfaceId);
            console.log("embedId = " + event.embedId);
            if (event.info) {
              console.log("id = " + event.info.id);
              console.log("type = " + event.info.type);
              console.log("src = " + event.info.src);
              console.log("width = " + event.info.width);
              console.log("height = " + event.info.height);
              console.log("url = " + event.info.url);
            }
          })
      }
    }
  }
  ```

  加载的html文件
  ```
  <!-- index.html -->
  <!Document>
  <html>
  <head>
      <title>同层渲染测试html</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type = "native/button" width="800" height="800" src="test? params1=1?" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

### onNativeEmbedGestureEvent<sup>11+</sup>

onNativeEmbedGestureEvent(callback: (event: NativeEmbedTouchInfo) => void)

当手指触摸到同层标签时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | (event: [NativeEmbedTouchInfo](#nativeembedtouchinfo11)) => void | 是 | 手指触摸到同层标签时触发该回调。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { NodeController, BuilderNode, NodeRenderType, FrameNode, UIContext } from "@kit.ArkUI";

  declare class Params {
    text: string;
    width: number;
    height: number;
  }

  declare class nodeControllerParams {
    surfaceId: string;
    renderType: NodeRenderType;
    width: number;
    height: number;
  }

  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[Params]> | undefined | null;
    private surfaceId_: string = "";
    private renderType_: NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
    private width_: number = 0;
    private height_: number = 0;

    setRenderOption(params: nodeControllerParams) {
      this.surfaceId_ = params.surfaceId;
      this.renderType_ = params.renderType;
      this.width_ = params.width;
      this.height_ = params.height;
    }

    makeNode(uiContext: UIContext): FrameNode | null {
      this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_ });
      this.rootNode.build(wrapBuilder(ButtonBuilder), { text: "myButton", width: this.width_, height: this.height_ });
      return this.rootNode.getFrameNode();
    }

    postEvent(event: TouchEvent | undefined): boolean {
      return this.rootNode?.postTouchEvent(event) as boolean;
    }
  }

  @Component
  struct ButtonComponent {
    @Prop params: Params;
    @State bkColor: Color = Color.Red;

    build() {
      Column() {
        Button(this.params.text)
          .height(50)
          .width(200)
          .border({ width: 2, color: Color.Red })
          .backgroundColor(this.bkColor)

      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  @Builder
  function ButtonBuilder(params: Params) {
    ButtonComponent({ params: params })
      .backgroundColor(Color.Green)
  }

  @Entry
  @Component
  struct WebComponent {
    @State eventType: string = '';
    controller: webview.WebviewController = new webview.WebviewController();
    private nodeController: MyNodeController = new MyNodeController();

    build() {
      Column() {
        Stack() {
          NodeContainer(this.nodeController)
          Web({ src: $rawfile("index.html"), controller: this.controller })
            .enableNativeEmbedMode(true)
            .onNativeEmbedLifecycleChange((embed) => {
              if (embed.status == NativeEmbedStatus.CREATE) {
                this.nodeController.setRenderOption({
                  surfaceId: embed.surfaceId as string,
                  renderType: NodeRenderType.RENDER_TYPE_TEXTURE,
                  width: px2vp(embed.info?.width),
                  height: px2vp(embed.info?.height)
                });
                this.nodeController.rebuild();
              }
            })
            .onNativeEmbedGestureEvent((event) => {
              if (event && event.touchEvent) {
                if (event.touchEvent.type == TouchType.Down) {
                  this.eventType = 'Down'
                }
                if (event.touchEvent.type == TouchType.Up) {
                  this.eventType = 'Up'
                }
                if (event.touchEvent.type == TouchType.Move) {
                  this.eventType = 'Move'
                }
                if (event.touchEvent.type == TouchType.Cancel) {
                  this.eventType = 'Cancel'
                }
                let ret = this.nodeController.postEvent(event.touchEvent)
                if (event.result) {
                  event.result.setGestureEventResult(ret, true);
                }
                console.log("embedId = " + event.embedId);
                console.log("touchType = " + this.eventType);
                console.log("x = " + event.touchEvent.touches[0].x);
                console.log("y = " + event.touchEvent.touches[0].y);
                console.log("Component globalPos:(" + event.touchEvent.target.area.globalPosition.x + "," + event.touchEvent.target.area.globalPosition.y + ")");
                console.log("width = " + event.touchEvent.target.area.width);
                console.log("height = " + event.touchEvent.target.area.height);
              }
            })
        }
      }
    }
  }
  ```
加载的html文件
  ```
  <!-- index.html -->
  <!Document>
<html>
<head>
    <title>同层渲染测试html</title>
    <meta name="viewport">
</head>
<body>
<div>
    <div id="bodyId">
        <embed id="nativeButton" type = "native/button" width="800" height="800" src="test?params1=1?" style = "background-color:red"/>
    </div>
</div>
</body>
</html>
  ```

### onIntelligentTrackingPreventionResult<sup>12+</sup>

onIntelligentTrackingPreventionResult(callback: OnIntelligentTrackingPreventionCallback)

智能防跟踪功能使能时，当追踪者cookie被拦截时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback    | [OnIntelligentTrackingPreventionCallback](#onintelligenttrackingpreventioncallback12) | 是 | 智能防跟踪功能使能时，当追踪者cookie被拦截时触发的回调。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // 需要打开智能防跟踪功能，才会触发onIntelligentTrackingPreventionResult回调
        Button('enableIntelligentTrackingPrevention')
          .onClick(() => {
            try {
              this.controller.enableIntelligentTrackingPrevention(true);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
          .onIntelligentTrackingPreventionResult((details) => {
            console.log("onIntelligentTrackingPreventionResult: [websiteHost]= " + details.host +
              ", [trackerHost]=" + details.trackerHost);
          })
      }
    }
  }
  ```

### onOverrideUrlLoading<sup>12+</sup>

onOverrideUrlLoading(callback: OnOverrideUrlLoadingCallback)

当URL将要加载到当前Web中时，让宿主应用程序有机会获得控制权，回调函数返回true将导致当前Web中止加载URL，而返回false则会导致Web继续照常加载URL。

POST请求不会触发该回调。

iframe加载HTTP(s)协议或about:blank时不会触发该回调，加载非HTTP(s)协议的跳转可以触发。调用loadUrl(String)主动触发的跳转不会触发该回调。

不要使用相同的URL调用loadUrl(String)方法，然后返回true。这样做会不必要地取消当前的加载并重新使用相同的URL开始新的加载。继续加载给定URL的正确方式是直接返回false，而不是调用loadUrl(String)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnOverrideUrlLoadingCallback](#onoverrideurlloadingcallback12) | 是 | onOverrideUrlLoading的回调。 |

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
          .onOverrideUrlLoading((webResourceRequest: WebResourceRequest) => {
            if (webResourceRequest && webResourceRequest.getRequestUrl() == "about:blank") {
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
    <h1>onOverrideUrlLoading Demo</h1>
    <a href="about:blank">Click here</a>// 访问about:blank。
  </body>
  </html>
  ```

### onViewportFitChanged<sup>12+</sup>

onViewportFitChanged(callback: OnViewportFitChangedCallback)

网页meta中viewport-fit配置项更改时触发该回调，应用可在此回调中自适应布局视口。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [OnViewportFitChangedCallback](#onviewportfitchangedcallback12) | 是 | 网页meta中viewport-fit配置项更改时触发的回调。 |

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
          .onViewportFitChanged((data) => {
            let jsonData = JSON.stringify(data);
            let viewportFit: ViewportFit = JSON.parse(jsonData).viewportFit;
            if (viewportFit === ViewportFit.COVER) {
              // index.html网页支持沉浸式布局，可调用expandSafeArea调整web控件布局视口覆盖避让区域(状态栏或导航条)。
            } else if (viewportFit === ViewportFit.CONTAINS) {
              // index.html网页不支持沉浸式布局，可调用expandSafeArea调整web控件布局视口为安全区域。
            } else {
              // 默认值，可不作处理
            }
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
    <head>
      <meta name="viewport" content="width=device-width,viewport-fit=cover">
    </head>
    <body>
      <div style="position: absolute; bottom: 0; margin-bottom: env(safe-area-inset-bottom)"></div>
    </body>
  </html>
  ```

### onInterceptKeyboardAttach<sup>12+</sup>

onInterceptKeyboardAttach(callback: WebKeyboardCallback)

网页中可编辑元素（如input标签）拉起软键盘之前会回调该接口，应用可以使用该接口拦截系统软键盘的弹出，配置应用定制的软键盘（应用根据该接口可以决定使用系统默认软键盘/定制enter键的系统软键盘/全部由应用自定义的软键盘）。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback | [WebKeyboardCallback](#webkeyboardcallback12) | 是 | 拦截网页拉起软键盘回调。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { inputMethodEngine } from '@kit.IMEKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    webKeyboardController: WebKeyboardController = new WebKeyboardController()
    inputAttributeMap: Map<string, number> = new Map([
        ['UNSPECIFIED', inputMethodEngine.ENTER_KEY_TYPE_UNSPECIFIED],
        ['GO', inputMethodEngine.ENTER_KEY_TYPE_GO],
        ['SEARCH', inputMethodEngine.ENTER_KEY_TYPE_SEARCH],
        ['SEND', inputMethodEngine.ENTER_KEY_TYPE_SEND],
        ['NEXT', inputMethodEngine.ENTER_KEY_TYPE_NEXT],
        ['DONE', inputMethodEngine.ENTER_KEY_TYPE_DONE],
        ['PREVIOUS', inputMethodEngine.ENTER_KEY_TYPE_PREVIOUS]
      ])

      /**
       * 自定义键盘组件Builder
       */
      @Builder
      customKeyboardBuilder() {
		  // 这里实现自定义键盘组件，对接WebKeyboardController实现输入、删除、关闭等操作。
        Row() {
          Text("完成")
            .fontSize(20)
            .fontColor(Color.Blue)
            .onClick(() => {
              this.webKeyboardController.close();
            })
          // 插入字符。
          Button("insertText").onClick(() => {
            this.webKeyboardController.insertText('insert ');
          }).margin({
            bottom: 200,
          })
          // 从后往前删除length参数指定长度的字符。
          Button("deleteForward").onClick(() => {
            this.webKeyboardController.deleteForward(1);
          }).margin({
            bottom: 200,
          })
          // 从前往后删除length参数指定长度的字符。
          Button("deleteBackward").onClick(() => {
            this.webKeyboardController.deleteBackward(1);
          }).margin({
            left: -220,
          })
          // 插入功能按键。
          Button("sendFunctionKey").onClick(() => {
            this.webKeyboardController.sendFunctionKey(6);
          })
        }
      }

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .onInterceptKeyboardAttach((KeyboardCallbackInfo) => {
          // option初始化，默认使用系统默认键盘
          let option: WebKeyboardOptions = {
            useSystemKeyboard: true,
          };
          if (!KeyboardCallbackInfo) {
            return option;
          }

          // 保存WebKeyboardController，使用自定义键盘时候，需要使用该handler控制输入、删除、软键盘关闭等行为
          this.webKeyboardController = KeyboardCallbackInfo.controller
          let attributes: Record<string, string> = KeyboardCallbackInfo.attributes
          // 遍历attributes
          let attributeKeys = Object.keys(attributes)
          for (let i = 0; i < attributeKeys.length; i++) {
            console.log('WebCustomKeyboard key = ' + attributeKeys[i] + ', value = ' + attributes[attributeKeys[i]])
          }

          if (attributes) {
            if (attributes['data-keyboard'] == 'customKeyboard') {
              // 根据html可编辑元素的属性，判断使用不同的软键盘，例如这里如果属性包含有data-keyboard，且值为customKeyboard，则使用自定义键盘
              console.log('WebCustomKeyboard use custom keyboard')
              option.useSystemKeyboard = false;
              // 设置自定义键盘builder
              option.customKeyboard = () => {
                this.customKeyboardBuilder()
              }
              return option;
            }

            if (attributes['keyboard-return'] != undefined) {
              // 根据html可编辑元素的属性，判断使用不同的软键盘，例如这里如果属性包含有keyboard-return，使用系统键盘，并且指定系统软键盘enterKey类型
              option.useSystemKeyboard = true;
              let enterKeyType: number | undefined = this.inputAttributeMap.get(attributes['keyboard-return'])
              if (enterKeyType != undefined) {
                option.enterKeyType = enterKeyType
              }
              return option;
            }
          }

          return option;
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

    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width,minimum-scale=1.0,maximum-scale=1.0">
    </head>

    <body>

    <p style="font-size:12px">input标签，原有默认行为：</p>
    <input type="text" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key UNSPECIFIED：</p>
    <input type="text" keyboard-return="UNSPECIFIED" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key GO：</p>
    <input type="text" keyboard-return="GO" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key SEARCH：</p>
    <input type="text" keyboard-return="SEARCH" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key SEND：</p>
    <input type="text" keyboard-return="SEND" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key NEXT：</p>
    <input type="text" keyboard-return="NEXT" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key DONE：</p>
    <input type="text" keyboard-return="DONE" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，系统键盘自定义enterKeyType属性 enter key PREVIOUS：</p>
    <input type="text" keyboard-return="PREVIOUS" style="width: 300px; height: 20px"><br>
    <hr style="height:2px;border-width:0;color:gray;background-color:gray">

    <p style="font-size:12px">input标签，应用自定义键盘：</p>
    <input type="text" data-keyboard="customKeyboard" style="width: 300px; height: 20px"><br>

    </body>

    </html>
  ```

### onNativeEmbedVisibilityChange<sup>12+</sup>

onNativeEmbedVisibilityChange(callback: OnNativeEmbedVisibilityChangeCallback)

网页中同层标签（如Embed标签或Object标签）在视口内的可见性发生变化时会触发该回调。同层标签默认不可见，如果首次进入页面可见则会上报，不可见则不会上报，当同层标签大小由非0值变为0 *0时，不会上报不可见，由0 *0变为非0值时会上报可见。同层标签全部不可见才算不可见，部分可见或全部可见算作可见。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| callback       | [OnNativeEmbedVisibilityChangeCallback](#onnativeembedvisibilitychangecallback12) | 是 | 同层标签可见性变化时触发该回调。 |

**示例：**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { NodeController, BuilderNode, NodeRenderType, FrameNode, UIContext } from "@kit.ArkUI";

  declare class Params {
    text: string;
    width: number;
    height: number;
  }

  declare class nodeControllerParams {
    surfaceId: string;
    renderType: NodeRenderType;
    width: number;
    height: number;
  }

  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[Params]> | undefined | null;
    private surfaceId_: string = "";
    private renderType_: NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
    private width_: number = 0;
    private height_: number = 0;

    setRenderOption(params: nodeControllerParams) {
      this.surfaceId_ = params.surfaceId;
      this.renderType_ = params.renderType;
      this.width_ = params.width;
      this.height_ = params.height;
    }

    makeNode(uiContext: UIContext): FrameNode | null {
      this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_ });
      this.rootNode.build(wrapBuilder(ButtonBuilder), { text: "myButton", width: this.width_, height: this.height_ });
      return this.rootNode.getFrameNode();
    }

    postEvent(event: TouchEvent | undefined): boolean {
      return this.rootNode?.postTouchEvent(event) as boolean;
    }
  }

  @Component
  struct ButtonComponent {
    @Prop params: Params;
    @State bkColor: Color = Color.Red;

    build() {
      Column() {
        Button(this.params.text)
          .height(50)
          .width(200)
          .border({ width: 2, color: Color.Red })
          .backgroundColor(this.bkColor)

      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  @Builder
  function ButtonBuilder(params: Params) {
    ButtonComponent({ params: params })
      .backgroundColor(Color.Green)
  }

  @Entry
  @Component
  struct WebComponent {
    @State embedVisibility: string = '';
    controller: webview.WebviewController = new webview.WebviewController();
    private nodeController: MyNodeController = new MyNodeController();

    build() {
      Column() {
        Stack() {
          NodeContainer(this.nodeController)
          Web({ src: $rawfile("index.html"), controller: this.controller })
            .enableNativeEmbedMode(true)
            .onNativeEmbedLifecycleChange((embed) => {
              if (embed.status == NativeEmbedStatus.CREATE) {
                this.nodeController.setRenderOption({
                  surfaceId: embed.surfaceId as string,
                  renderType: NodeRenderType.RENDER_TYPE_TEXTURE,
                  width: px2vp(embed.info?.width),
                  height: px2vp(embed.info?.height)
                });
                this.nodeController.rebuild();
              }
            })
            .onNativeEmbedVisibilityChange((embed) => {
              if (embed.visibility) {
                this.embedVisibility = 'Visible';
              } else {
                this.embedVisibility = 'Hidden';
              }
              console.log("embedId = " + embed.embedId);
              console.log("visibility = " + embed.visibility);
            })
        }
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
      <title>同层渲染测试html</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type = "native/button" width="800" height="800" src="test?params1=1?" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```

## WebKeyboardCallback<sup>12+</sup>

type WebKeyboardCallback = (keyboardCallbackInfo: WebKeyboardCallbackInfo) => WebKeyboardOptions

拦截网页可编辑元素拉起软键盘的回调，一般在点击网页input标签时触发。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名           | 类型   | 必填   | 说明               |
| ------------- | ------ | ---- | ------------------ |
| keyboardCallbackInfo    | [WebKeyboardCallbackInfo](#webkeyboardcallbackinfo12) | 是    | 拦截网页拉起软键盘回调通知的入参，其中包括[WebKeyboardController](#webkeyboardcontroller12)、可编辑元素的属性。  |

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| [WebKeyboardOptions](#webkeyboardoptions12) | 回调函数通过返回[WebKeyboardOptions](#webkeyboardoptions12)来决定ArkWeb内核拉起不同类型的软键盘。 |

## WebKeyboardCallbackInfo<sup>12+</sup>

拦截网页可编辑元素拉起软键盘的回调入参，其中包括[WebKeyboardController](#webkeyboardcontroller12)、可编辑元素的属性。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ------- | ---- | ---------------------------------------- |
| controller | [WebKeyboardController](#webkeyboardcontroller12)  | 是    | 提供控制自定义键盘的输入、删除、关闭等操作。 |
| attributes | Record<string, string> | 是    | 触发本次软键盘弹出的网页元素属性。

## WebKeyboardOptions<sup>12+</sup>

拦截网页可编辑元素拉起软键盘的回调返回值，可以指定使用的键盘类型，并返回给web内核，以控制拉起不同类型的软键盘；

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ------- | ---- | ---------------------------------------- |
| useSystemKeyboard | boolean  | 是    | 是否使用系统默认软键盘。 |
| enterKeyType | number | 否    | 指定系统软键盘enter键的类型，取值范围见输入框架的定义[EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10)，该参数为可选参数，当useSystemKeyboard为true，并且设置了有效的enterKeyType时候，才有效。|
| customKeyboard | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8) | 否    | 指定自定义键盘组件builder，可选参数，当useSystemKeyboard为false时，需要设置该参数，然后Web组件会拉起该自定义键盘。

## WebKeyboardController<sup>12+</sup>

控制自定义键盘的输入、删除、关闭等操作。示例代码参考[onInterceptKeyboardAttach](#oninterceptkeyboardattach12)。

### insertText<sup>12+</sup>

insertText(text: string): void

插入字符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | -------- | ---- | --------------------- |
| text | string | 是 | 向Web输入框插入字符。 |

### deleteForward<sup>12+</sup>

deleteForward(length: number): void

从后往前删除length参数指定长度的字符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | -------- | ---- | ------------------------ |
| length | number   | 是   | 从后往前删除字符的长度。 |

### deleteBackward12+</sup>

deleteBackward(length: number): void

从前往后删除length参数指定长度的字符。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | -------- | ---- | ------------------------ |
| length | number   | 是   | 从前往后删除字符的长度。 |

### sendFunctionKey<sup>12+</sup>

sendFunctionKey(key: number): void

插入功能按键，目前仅支持enter键类型，取值见[EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                   |
| ------ | -------- | ---- | ------------------------------------------ |
| key    | number   | 是   | 向Web输入框传递功能键，目前仅支持enter键。 |

### close<sup>12+</sup>

close(): void

关闭自定义键盘。

**系统能力：** SystemCapability.Web.Webview.Core

## ConsoleMessage

Web组件获取控制台信息对象。示例代码参考[onConsole事件](#onconsole)。

### getLineNumber

getLineNumber(): number

获取ConsoleMessage的行数。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 返回ConsoleMessage的行数。 |

### getMessage

getMessage(): string

获取ConsoleMessage的日志信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                     |
| ------ | ---------------------- |
| string | 返回ConsoleMessage的日志信息。 |

### getMessageLevel

getMessageLevel(): MessageLevel

获取ConsoleMessage的信息级别。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                | 说明                     |
| --------------------------------- | ---------------------- |
| [MessageLevel](#messagelevel枚举说明) | 返回ConsoleMessage的信息级别。 |

### getSourceId

getSourceId(): string

获取网页源文件路径和名字。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回网页源文件路径和名字。 |

## JsResult

Web组件返回的弹窗确认或弹窗取消功能对象。示例代码参考[onAlert事件](#onalert)。

### handleCancel

handleCancel(): void

通知Web组件用户取消弹窗操作。

**系统能力：** SystemCapability.Web.Webview.Core

### handleConfirm

handleConfirm(): void

通知Web组件用户确认弹窗操作。

**系统能力：** SystemCapability.Web.Webview.Core

### handlePromptConfirm<sup>9+</sup>

handlePromptConfirm(result: string): void

通知Web组件用户确认弹窗操作及对话框内容。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明        |
| ------ | ------ | ---- | ----------- |
| result | string | 是    | 用户输入的对话框内容。 |

## FullScreenExitHandler<sup>9+</sup>

通知开发者Web组件退出全屏。示例代码参考[onFullScreenEnter事件](#onfullscreenenter9)。

### constructor<sup>9+</sup>

constructor()

**系统能力：** SystemCapability.Web.Webview.Core

### exitFullScreen<sup>9+</sup>

exitFullScreen(): void

通知开发者Web组件退出全屏。

**系统能力：** SystemCapability.Web.Webview.Core

## ControllerHandler<sup>9+</sup>

设置用户新建Web组件的WebviewController对象。示例代码参考[onWindowNew事件](#onwindownew9)。

**系统能力：** SystemCapability.Web.Webview.Core

### setWebController<sup>9+</sup>

setWebController(controller: WebviewController): void

设置WebviewController对象，如果不需要打开新窗口请设置为null。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型                                     | 必填 | 说明                                     |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| controller | [WebviewController](js-apis-webview.md#webviewcontroller) | 是  | 新建Web组件的WebviewController对象，如果不需要打开新窗口请设置为null。 |

## WebResourceError

Web组件资源管理错误信息对象。示例代码参考[onErrorReceive事件](#onerrorreceive)。

### getErrorCode

getErrorCode(): number

获取加载资源的错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 返回加载资源的错误码。错误码的含义可以参考[WebNetErrorList](js-apis-netErrorList.md) |

### getErrorInfo

getErrorInfo(): string

获取加载资源的错误信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 返回加载资源的错误信息。 |

## WebResourceRequest

Web组件获取资源请求对象。示例代码参考[onErrorReceive事件](#onerrorreceive)。

### getRequestHeader

getRequestHeader(): Array\<Header\>

获取资源请求头信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                         | 说明         |
| -------------------------- | ---------- |
| Array\<[Header](#header)\> | 返回资源请求头信息。 |

### getRequestUrl

getRequestUrl(): string

获取资源请求的URL信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源请求的URL信息。 |

### isMainFrame

isMainFrame(): boolean

判断资源请求是否为主frame。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否为主frame。 |

### isRedirect

isRedirect(): boolean

判断资源请求是否被服务端重定向。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明               |
| ------- | ---------------- |
| boolean | 返回资源请求是否被服务端重定向。 |

### isRequestGesture

isRequestGesture(): boolean

获取资源请求是否与手势（如点击）相关联。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                   |
| ------- | -------------------- |
| boolean | 返回资源请求是否与手势（如点击）相关联。 |

### getRequestMethod<sup>9+</sup>

getRequestMethod(): string

获取请求方法。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明      |
| ------ | ------- |
| string | 返回请求方法。 |

## Header

Web组件返回的请求/响应头对象。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 类型     | 必填   | 说明            |
| ----------- | ------ | ---- | ------------- |
| headerKey   | string | 是    | 请求/响应头的key。   |
| headerValue | string | 是    | 请求/响应头的value。 |

## WebResourceResponse

Web组件资源响应对象。示例代码参考[onHttpErrorReceive事件](#onhttperrorreceive)。

### getReasonMessage

getReasonMessage(): string

获取资源响应的状态码描述。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 返回资源响应的状态码描述。 |

### getResponseCode

getResponseCode(): number

获取资源响应的状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 返回资源响应的状态码。 |

### getResponseData

getResponseData(): string

获取资源响应数据。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| string | 返回资源响应数据。 |

### getResponseEncoding

getResponseEncoding(): string

获取资源响应的编码。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回资源响应的编码。 |

### getResponseHeader

getResponseHeader() : Array\<Header\>

获取资源响应头。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                         | 说明       |
| -------------------------- | -------- |
| Array\<[Header](#header)\> | 返回资源响应头。 |

### getResponseMimeType

getResponseMimeType(): string

获取资源响应的媒体（MIME）类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| string | 返回资源响应的媒体（MIME）类型。 |

### getResponseDataEx<sup>13+</sup>

getResponseDataEx(): string | number | ArrayBuffer | Resource | undefined

获取资源响应数据，支持多种数据类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

|类型|说明|
|---|---|
|string|返回HTML格式的字符串。|
|number|返回文件句柄。|
|ArrayBuffer|返回二进制数据。|
|[Resource](../apis-arkui/arkui-ts/ts-types.md)|返回`$rawfile`资源。|
|undefined|如果没有可用数据，返回`undefined`。|

### getResponseIsReady<sup>13+</sup>

getResponseIsReady(): boolean

获取响应数据是否已准备就绪。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

|类型|说明|
|---|---|
|boolean|`true`表示响应数据已准备好，`false`表示未准备好。|

### setResponseData<sup>9+</sup>

setResponseData(data: string \| number \| Resource \| ArrayBuffer): void

设置资源响应数据。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型                                     | 必填   | 说明                                     |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| data | string \| number \| [Resource](../apis-arkui/arkui-ts/ts-types.md)<sup>10+</sup> \| ArrayBuffer<sup>11+</sup> | 是    | 要设置的资源响应数据。string表示HTML格式的字符串。number表示文件句柄, 此句柄由系统的Web组件负责关闭。 Resource表示应用rawfile目录下文件资源。 ArrayBuffer表示资源的原始二进制数据。 |

### setResponseEncoding<sup>9+</sup>

setResponseEncoding(encoding: string): void

设置资源响应的编码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型   | 必填   | 说明         |
| -------- | ------ | ---- | ------------ |
| encoding | string | 是    | 要设置的资源响应的编码。 |

### setResponseMimeType<sup>9+</sup>

setResponseMimeType(mimeType: string): void

设置资源响应的媒体（MIME）类型。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型   | 必填   | 说明                 |
| -------- | ------ | ---- | -------------------- |
| mimeType | string | 是   | 要设置的资源响应的媒体（MIME）类型。 |

### setReasonMessage<sup>9+</sup>

setReasonMessage(reason: string): void

设置资源响应的状态码描述。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明            |
| ------ | ------ | ---- | --------------- |
| reason | string | 是   | 要设置的资源响应的状态码描述。 |

### setResponseHeader<sup>9+</sup>

setResponseHeader(header: Array\<Header\>): void

设置资源响应头。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型                       | 必填   | 说明       |
| ------ | -------------------------- | ---- | ---------- |
| header | Array\<[Header](#header)\> | 是   | 要设置的资源响应头。 |

### setResponseCode<sup>9+</sup>

setResponseCode(code: number): void

设置资源响应的状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填   | 说明          |
| ---- | ------ | ---- | ------------- |
| code | number | 是   | 要设置的资源响应的状态码。如果该资源以错误结束，请参考[@ohos.web.netErrorList](js-apis-netErrorList.md)设置相应错误码，避免设置错误码为 ERR_IO_PENDING，设置为该错误码可能会导致XMLHttpRequest同步请求阻塞。 |

### setResponseIsReady<sup>9+</sup>

setResponseIsReady(IsReady: boolean): void

设置资源响应数据是否已经就绪。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    | 必填  | 说明          |
| ------- | ------- | ---- | ------------- |
| IsReady | boolean | 是   | 资源响应数据是否已经就绪。默认值：true。 |

## FileSelectorResult<sup>9+</sup>

通知Web组件的文件选择结果。示例代码参考[onShowFileSelector事件](#onshowfileselector9)。

### handleFileList<sup>9+</sup>

handleFileList(fileList: Array\<string\>): void

通知Web组件进行文件选择操作。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型            | 必填  | 说明         |
| -------- | --------------- | ---- | ------------ |
| fileList | Array\<string\> | 是   | 需要进行操作的文件列表。 |

## FileSelectorParam<sup>9+</sup>

Web组件获取文件对象。示例代码参考[onShowFileSelector事件](#onshowfileselector9)。

### getTitle<sup>9+</sup>

getTitle(): string

获取文件选择器标题。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回文件选择器标题。 |

### getMode<sup>9+</sup>

getMode(): FileSelectorMode

获取文件选择器的模式。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明          |
| ---------------------------------------- | ----------- |
| [FileSelectorMode](#fileselectormode9枚举说明) | 返回文件选择器的模式。 |

### getAcceptType<sup>9+</sup>

getAcceptType(): Array\<string\>

获取文件过滤类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<string\> | 返回文件过滤类型。 |

### isCapture<sup>9+</sup>

isCapture(): boolean

获取是否调用多媒体能力。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明           |
| ------- | ------------ |
| boolean | 返回是否调用多媒体能力。 |

## HttpAuthHandler<sup>9+</sup>

Web组件返回的http auth认证请求确认或取消和使用缓存密码认证功能对象。示例代码参考[onHttpAuthRequest事件](#onhttpauthrequest9)。

### cancel<sup>9+</sup>

cancel(): void

通知Web组件用户取消HTTP认证操作。

**系统能力：** SystemCapability.Web.Webview.Core

### confirm<sup>9+</sup>

confirm(userName: string, password: string): boolean

使用用户名和密码进行HTTP认证操作。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型   | 必填  | 说明       |
| -------- | ------ | ---- | ---------- |
| userName | string | 是   | HTTP认证用户名。 |
| password      | string | 是   | HTTP认证密码。  |

**返回值：**

| 类型      | 说明                    |
| ------- | --------------------- |
| boolean | 认证成功返回true，失败返回false。 |

### isHttpAuthInfoSaved<sup>9+</sup>

isHttpAuthInfoSaved(): boolean

通知Web组件用户使用服务器缓存的账号密码认证。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 存在密码认证成功返回true，其他返回false。 |

## SslErrorHandler<sup>9+</sup>

Web组件返回的SSL错误通知事件用户处理功能对象。示例代码参考[onSslErrorEventReceive事件](#onsslerroreventreceive9)。

### handleCancel<sup>9+</sup>

handleCancel(): void

通知Web组件取消此请求。

**系统能力：** SystemCapability.Web.Webview.Core

### handleConfirm<sup>9+</sup>

handleConfirm(): void

通知Web组件继续使用SSL证书。

**系统能力：** SystemCapability.Web.Webview.Core

## ClientAuthenticationHandler<sup>9+</sup>

Web组件返回的SSL客户端证书请求事件用户处理功能对象。示例代码参考[onClientAuthenticationRequest事件](#onclientauthenticationrequest9)。

### confirm<sup>9+</sup>

confirm(priKeyFile : string, certChainFile : string): void

通知Web组件使用指定的私钥和客户端证书链。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名           | 类型   | 必填   | 说明               |
| ------------- | ------ | ---- | ------------------ |
| priKeyFile    | string | 是    | 存放私钥的文件，包含路径和文件名。  |
| certChainFile | string | 是    | 存放证书链的文件，包含路径和文件名。 |

### confirm<sup>10+</sup>

confirm(authUri : string): void

通知Web组件使用指定的凭据(从证书管理模块获得)。

> **说明：**
>
> 需要配置权限：ohos.permission.ACCESS_CERT_MANAGER。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填   | 说明    |
| ------- | ------ | ---- | ------- |
| authUri | string | 是    | 凭据的关键值。 |

### cancel<sup>9+</sup>

cancel(): void

通知Web组件取消相同host和port服务器发送的客户端证书请求事件。同时，相同host和port服务器的请求，不重复上报该事件。

**系统能力：** SystemCapability.Web.Webview.Core

### ignore<sup>9+</sup>

ignore(): void

通知Web组件忽略本次请求。

**系统能力：** SystemCapability.Web.Webview.Core

## PermissionRequest<sup>9+</sup>

Web组件返回授权或拒绝权限功能的对象。示例代码参考[onPermissionRequest事件](#onpermissionrequest9)。

### deny<sup>9+</sup>

deny(): void

拒绝网页所请求的权限。

**系统能力：** SystemCapability.Web.Webview.Core

### getOrigin<sup>9+</sup>

getOrigin(): string

获取网页来源。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 当前请求权限网页的来源。 |

### getAccessibleResource<sup>9+</sup>

getAccessibleResource(): Array\<string\>

获取网页所请求的权限资源列表，资源列表类型参考[ProtectedResourceType](#protectedresourcetype9枚举说明)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明            |
| --------------- | ------------- |
| Array\<string\> | 网页所请求的权限资源列表。 |

### grant<sup>9+</sup>

grant(resources: Array\<string\>): void

对网页访问的给定权限进行授权。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型            | 必填   | 说明            |
| --------- | --------------- | ---- | --------------- |
| resources | Array\<string\> | 是   | 授予网页请求的权限的资源列表。 |

## ScreenCaptureHandler<sup>10+</sup>

Web组件返回授权或拒绝屏幕捕获功能的对象。示例代码参考[onScreenCaptureRequest事件](#onscreencapturerequest10)。

### deny<sup>10+</sup>

deny(): void

拒绝网页所请求的屏幕捕获操作。

**系统能力：** SystemCapability.Web.Webview.Core

### getOrigin<sup>10+</sup>

getOrigin(): string

获取网页来源。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 当前请求权限网页的来源。 |

### grant<sup>10+</sup>

grant(config: ScreenCaptureConfig): void

对网页访问的屏幕捕获操作进行授权。

> **说明：**
>
> 需要配置权限：ohos.permission.MICROPHONE。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型                                     | 必填   | 说明    |
| ------ | ---------------------------------------- | ---- | ------- |
| config | [ScreenCaptureConfig](#screencaptureconfig10) | 是   | 屏幕捕获配置。 |

## EventResult<sup>12+</sup>

通知Web组件事件消费结果，支持的事件参考[触摸事件的类型](../apis-arkui/arkui-ts/ts-appendix-enums.md#touchtype)。如果应用不消费该事件，则设置为false，事件被Web组件消费。应用消费了该事件，设置为true，Web组件不消费。示例代码参考[onNativeEmbedGestureEvent事件](#onnativeembedgestureevent11)。

### setGestureEventResult<sup>12+</sup>

setGestureEventResult(result: boolean, stopPropagation?: boolean): void

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型 | 必填  | 说明             |
| --------------- | -------- | ----  |------- |
| result          | boolean  | 是    | 是否消费该手势事件。默认值为true。 |
| stopPropagation<sup>14+</sup>| boolean  | 否   | 是否阻止冒泡，在result为true时生效。默认值为true。 |

**示例：**

请参考[onNativeEmbedGestureEvent事件](#onnativeembedgestureevent11)。

## ContextMenuSourceType<sup>9+</sup>枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称       | 值 | 说明         |
| --------- | -- |------------ |
| None      | 0 | 其他事件来源。 |
| Mouse     | 1 | 鼠标事件。   |
| LongPress | 2 | 长按事件。   |

## ContextMenuMediaType<sup>9+</sup>枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称    | 值 | 说明            |
| ----- | -- | ------------- |
| None  | 0 | 非特殊媒体或其他媒体类型。 |
| Image | 1 | 图片。           |

## ContextMenuInputFieldType<sup>9+</sup>枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 值 | 说明                          |
| --------- | -- | --------------------------- |
| None      | 0 | 非输入框。                       |
| PlainText | 1 | 纯文本类型，包括text、search、email等。 |
| Password  | 2 | 密码类型。                       |
| Number    | 3 | 数字类型。                       |
| Telephone | 4 | 电话号码类型。                     |
| Other     | 5 | 其他类型。                       |

## ContextMenuEditStateFlags<sup>9+</sup>枚举说明

支持以按位或的方式使用此枚举。例如，如果需要同时支持CAN_CUT、CAN_COPY和CAN_SELECT_ALL，可使用CAN_CUT | CAN_COPY | CAN_SELECT_ALL或11。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称            | 值 | 说明     |
| -------------- | -- | -------- |
| NONE           | 0 | 不可编辑。 |
| CAN_CUT        | 1 | 支持剪切。 |
| CAN_COPY       | 2 | 支持拷贝。 |
| CAN_PASTE      | 4 | 支持粘贴。 |
| CAN_SELECT_ALL | 8 | 支持全选。 |

## WebContextMenuParam<sup>9+</sup>

实现长按页面元素或鼠标右键弹出来的菜单信息。示例代码参考[onContextMenuShow事件](#oncontextmenushow9)。

### x<sup>9+</sup>

x(): number

弹出菜单的x坐标。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| number | 显示正常返回非负整数，否则返回-1。 |

### y<sup>9+</sup>

y(): number

弹出菜单的y坐标。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| number | 显示正常返回非负整数，否则返回-1。 |

### getLinkUrl<sup>9+</sup>

getLinkUrl(): string

获取链接地址。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                        |
| ------ | ------------------------- |
| string | 如果长按位置是链接，返回经过安全检查的url链接。 |

### getUnfilteredLinkUrl<sup>9+</sup>

getUnfilteredLinkUrl(): string

获取链接地址。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                    |
| ------ | --------------------- |
| string | 如果长按位置是链接，返回原始的url链接。 |

### getSourceUrl<sup>9+</sup>

getSourceUrl(): string

获取sourceUrl链接。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                       |
| ------ | ------------------------ |
| string | 如果选中的元素有src属性，返回src的url。 |

### existsImageContents<sup>9+</sup>

existsImageContents(): boolean

是否存在图像内容。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 长按位置中有图片返回true，否则返回false。 |

### getMediaType<sup>9+</sup>

getMediaType(): ContextMenuMediaType

获取网页元素媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明        |
| ---------------------------------------- | --------- |
| [ContextMenuMediaType](#contextmenumediatype9枚举说明) | 网页元素媒体类型。 |

### getSelectionText<sup>9+</sup>

getSelectionText(): string

获取选中文本。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| string | 菜单上下文选中文本内容，不存在则返回空。 |

### getSourceType<sup>9+</sup>

getSourceType(): ContextMenuSourceType

获取菜单事件来源。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| [ContextMenuSourceType](#contextmenusourcetype9枚举说明) | 菜单事件来源。 |

### getInputFieldType<sup>9+</sup>

getInputFieldType(): ContextMenuInputFieldType

获取网页元素输入框类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明     |
| ---------------------------------------- | ------ |
| [ContextMenuInputFieldType](#contextmenuinputfieldtype9枚举说明) | 输入框类型。 |

### isEditable<sup>9+</sup>

isEditable(): boolean

获取网页元素是否可编辑标识。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 网页元素可编辑返回true，不可编辑返回false。 |

### getEditStateFlags<sup>9+</sup>

getEditStateFlags(): number

获取网页元素可编辑标识。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 网页元素可编辑标识，参照[ContextMenuEditStateFlags](#contextmenueditstateflags9枚举说明)。 |

### getPreviewWidth<sup>13+</sup>

getPreviewWidth(): number

获取预览图的宽。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明       |
| ------ | ----------- |
| number | 预览图的宽。 |

### getPreviewHeight<sup>13+</sup>

getPreviewHeight(): number

获取预览图的高。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明       |
| ------ | ----------  |
| number | 预览图的高。 |

## WebContextMenuResult<sup>9+</sup>

实现长按页面元素或鼠标右键弹出来的菜单所执行的响应事件。示例代码参考[onContextMenuShow事件](#oncontextmenushow9)。

### closeContextMenu<sup>9+</sup>

closeContextMenu(): void

不执行WebContextMenuResult其他接口操作时，需要调用此接口关闭菜单。

**系统能力：** SystemCapability.Web.Webview.Core

### copyImage<sup>9+</sup>

copyImage(): void

WebContextMenuParam有图片内容则复制图片。

**系统能力：** SystemCapability.Web.Webview.Core

### copy<sup>9+</sup>

copy(): void

执行与此上下文菜单相关的拷贝文本操作。

**系统能力：** SystemCapability.Web.Webview.Core

### paste<sup>9+</sup>

paste(): void

执行与此上下文菜单相关的粘贴操作。

**系统能力：** SystemCapability.Web.Webview.Core

### cut<sup>9+</sup>

cut(): void

执行与此上下文菜单相关的剪切操作。

**系统能力：** SystemCapability.Web.Webview.Core

### selectAll<sup>9+</sup>

selectAll(): void

执行与此上下文菜单相关的全选操作。

**系统能力：** SystemCapability.Web.Webview.Core

## JsGeolocation

Web组件返回授权或拒绝权限功能的对象。示例代码参考[onGeolocationShow事件](#ongeolocationshow)。

### constructor

constructor()

**系统能力：** SystemCapability.Web.Webview.Core

### invoke

invoke(origin: string, allow: boolean, retain: boolean): void

设置网页地理位置权限状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型    | 必填  | 说明                                     |
| ------ | ------- | ---- | ---------------------------------------- |
| origin | string  | 是   | 指定源的字符串索引。                               |
| allow  | boolean | 是   | 设置的地理位置权限状态。                             |
| retain | boolean | 是   | 是否允许将地理位置权限状态保存到系统中。可通过[GeolocationPermissions<sup>9+</sup>](js-apis-webview.md#geolocationpermissions)接口管理保存到系统的地理位置权限。 |

## MessageLevel枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称    | 值 | 说明    |
| ----- | -- | ---- |
| Debug | 1 | 调试级别。 |
| Error | 4 | 错误级别。 |
| Info  | 2 | 消息级别。 |
| Log   | 5 | 日志级别。 |
| Warn  | 3 | 警告级别。 |

## RenderExitReason<sup>9+</sup>枚举说明

onRenderExited接口返回的渲染进程退出的具体原因。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                         | 值 | 说明                |
| -------------------------- | -- | ----------------- |
| ProcessAbnormalTermination | 0 | 渲染进程异常退出。         |
| ProcessWasKilled           | 1 | 收到SIGKILL，或被手动终止。 |
| ProcessCrashed             | 2 | 渲染进程崩溃退出，如段错误。    |
| ProcessOom                 | 3 | 程序内存不足。           |
| ProcessExitUnknown         | 4 | 其他原因。             |

## MixedMode枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 值 | 说明                                 |
| ---------- | -- | ---------------------------------- |
| All        | 0 | 允许加载HTTP和HTTPS混合内容。所有不安全的内容都可以被加载。 |
| Compatible | 1 | 混合内容兼容性模式，部分不安全的内容可能被加载。           |
| None       | 2 | 不允许加载HTTP和HTTPS混合内容。               |

## CacheMode枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称      | 值 | 说明                                   |
| ------- | -- | ------------------------------------ |
| Default<sup>9+</sup> | 0 | 使用未过期的cache加载资源，如果cache中无该资源则从网络中获取。 |
| None    | 1 | 加载资源使用cache，如果cache中无该资源则从网络中获取。     |
| Online  | 2 | 加载资源不使用cache，全部从网络中获取。               |
| Only    | 3 | 只从cache中加载资源。                        |

## FileSelectorMode<sup>9+</sup>枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                   | 值 | 说明         |
| -------------------- | -- | ---------- |
| FileOpenMode         | 0 | 打开上传单个文件。  |
| FileOpenMultipleMode | 1 | 打开上传多个文件。  |
| FileOpenFolderMode   | 2 | 打开上传文件夹模式。 |
| FileSaveMode         | 3 | 文件保存模式。    |

 ## HitTestType枚举说明

 **系统能力：** SystemCapability.Web.Webview.Core

| 名称            | 值 | 说明                       |
| ------------- | -- | ------------------------ |
| EditText      | 0 | 可编辑的区域。                  |
| Email         | 1 | 电子邮件地址。                  |
| HttpAnchor    | 2 | 超链接，其src为http。           |
| HttpAnchorImg | 3 | 带有超链接的图片，其中超链接的src为http。 |
| Img           | 4 | HTML::img标签。             |
| Map           | 5 | 地理地址。                    |
| Phone         | 6 | 电话号码。                    |
| Unknown       | 7 | 未知内容。                    |

 ## OverScrollMode<sup>11+</sup>枚举说明

 **系统能力：** SystemCapability.Web.Webview.Core

| 名称     | 值 | 说明          |
| ------ | -- | ----------- |
| NEVER  | 0 | Web过滚动模式关闭。 |
| ALWAYS | 1 | Web过滚动模式开启。 |

## OnContextMenuHideCallback<sup>11+</sup>

上下文菜单自定义隐藏的回调。

## SslError<sup>9+</sup>枚举说明

onSslErrorEventReceive接口返回的SSL错误的具体原因。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 值 | 说明          |
| ------------ | -- | ----------- |
| Invalid      | 0 | 一般错误。       |
| HostMismatch | 1 | 主机名不匹配。     |
| DateInvalid  | 2 | 证书日期无效。     |
| Untrusted    | 3 | 证书颁发机构不受信任。 |

## ProtectedResourceType<sup>9+</sup>枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                          | 值 | 说明            | 备注                         |
| --------------------------- | --------------- | ------------- | -------------------------- |
| MidiSysex                   | TYPE_MIDI_SYSEX | MIDI SYSEX资源。 | 目前仅支持权限事件上报，MIDI设备的使用还未支持。 |
| VIDEO_CAPTURE<sup>10+</sup> | TYPE_VIDEO_CAPTURE | 视频捕获资源，例如相机。  |                            |
| AUDIO_CAPTURE<sup>10+</sup> | TYPE_AUDIO_CAPTURE | 音频捕获资源，例如麦克风。 |                            |
| SENSOR<sup>12+</sup>        | TYPE_SENSOR | 传感器资源，例如加速度传感器。 |                            |

## WebDarkMode<sup>9+</sup>枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称   | 值 | 说明           |
| ---- | -- | ------------ |
| Off  | 0 | Web深色模式关闭。   |
| On   | 1 | Web深色模式开启。   |
| Auto | 2 | Web深色模式跟随系统。 |

## WebCaptureMode<sup>10+</sup>枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明      |
| ----------- | -- | ------- |
| HOME_SCREEN | 0 | 主屏捕获模式。 |

## WebMediaOptions<sup>10+</sup>

Web媒体策略的配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ------- | ---- | ---------------------------------------- |
| resumeInterval | number  | 否    | 被暂停的Web音频能够自动续播的有效期，单位：秒。最长有效期为60秒，由于近似值原因，该有效期可能存在一秒内的误差。 |
| audioExclusive | boolean | 否    | 应用内多个Web实例的音频是否独占。                       |

## ScreenCaptureConfig<sup>10+</sup>

Web屏幕捕获的配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 类型                                      | 必填   | 说明         |
| ----------- | --------------------------------------- | ---- | ---------- |
| captureMode | [WebCaptureMode](#webcapturemode10枚举说明) | 是    | Web屏幕捕获模式。 |

## WebLayoutMode<sup>11+</sup>枚举说明

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                 |
| ----------- | -- | ------------------ |
| NONE        | 0 | Web布局跟随系统。         |
| FIT_CONTENT | 1 | Web基于页面大小的自适应网页布局。 |

## NestedScrollOptionsExt<sup>14+</sup>对象说明

通过NestedScrollOptionsExt可以设置上下左右四个方向的嵌套滚动规则。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型               | 说明                   |
| -------------- | ---------------- | -------------------- |
| scrollUp  | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | 可滚动组件往上滚动时的嵌套滚动选项。 |
| scrollDown | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | 可滚动组件往下滚动时的嵌套滚动选项。 |
| scrollLeft  | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | 可滚动组件往左滚动时的嵌套滚动选项。 |
| scrollRight | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | 可滚动组件往右滚动时的嵌套滚动选项。 |

## DataResubmissionHandler<sup>9+</sup>

通过DataResubmissionHandler可以重新提交表单数据或取消提交表单数据。

### resend<sup>9+</sup>

resend(): void

重新发送表单数据。

**系统能力：** SystemCapability.Web.Webview.Core

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
          .onDataResubmitted((event) => {
            console.log('onDataResubmitted');
            event.handler.resend();
          })
      }
    }
  }
  ```

### cancel<sup>9+</sup>

cancel(): void

取消重新发送表单数据。

**系统能力：** SystemCapability.Web.Webview.Core

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
          .onDataResubmitted((event) => {
            console.log('onDataResubmitted');
            event.handler.cancel();
          })
      }
    }
  }
  ```

  ## WebController

通过WebController可以控制Web组件各种行为。一个WebController对象只能控制一个Web组件，且必须在Web组件和WebController绑定后，才能调用WebController上的方法。

从API version 9开始不再维护，建议使用[WebviewController<sup>9+</sup>](js-apis-webview.md#webviewcontroller)代替。

### 创建对象

<!--code_no_check-->
```ts
let webController: WebController = new WebController()
```

### getCookieManager<sup>(deprecated)</sup>

getCookieManager(): WebCookie

获取Web组件cookie管理对象。

从API version 9开始不再维护，建议使用[getCookie](js-apis-webview.md#getcookiedeprecated)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型        | 说明                                       |
| --------- | ---------------------------------------- |
| WebCookie | Web组件cookie管理对象，参考[WebCookie](#webcookiedeprecated)定义。 |

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

从API version 9开始不再维护，建议使用[requestFocus<sup>9+</sup>](js-apis-webview.md#requestfocus)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

从API version 9开始不再维护，建议使用[accessBackward<sup>9+</sup>](js-apis-webview.md#accessbackward)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

从API version 9开始不再维护，建议使用[accessForward<sup>9+</sup>](js-apis-webview.md#accessforward)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

从API version 9开始不再维护，建议使用[accessStep<sup>9+</sup>](js-apis-webview.md#accessstep)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填  | 说明                  |
| ---- | ------ | ---- | --------------------- |
| step | number | 是   | 要跳转的步数，正数代表前进，负数代表后退。 |

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

backward()

按照历史栈，后退一个页面。一般结合accessBackward一起使用。

从API version 9开始不再维护，建议使用[backward<sup>9+</sup>](js-apis-webview.md#backward)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

forward()

按照历史栈，前进一个页面。一般结合accessForward一起使用。

从API version 9开始不再维护，建议使用[forward<sup>9+</sup>](js-apis-webview.md#forward)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

从API version 9开始不再维护，建议使用[deleteJavaScriptRegister<sup>9+</sup>](js-apis-webview.md#deletejavascriptregister)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填  | 说明                                     |
| ---- | ------ | ---- | ---------------------------------------- |
| name | string | 是   | 注册对象的名称，可在网页侧JavaScript中通过此名称调用应用侧JavaScript对象。 |

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

从API version 9开始不再维护，建议使用[getHitTest<sup>9+</sup>](js-apis-webview.md#gethittest)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

从API version 9开始不再维护，建议使用[loadData<sup>9+</sup>](js-apis-webview.md#loaddata)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型   | 必填   | 说明                                     |
| ---------- | ------ | ---- | ---------------------------------------- |
| data       | string | 是   | 按照”Base64“或者”URL"编码后的一段字符串。              |
| mimeType   | string | 是   | 媒体类型（MIME）。                              |
| encoding   | string | 是   | 编码类型，具体为“Base64"或者”URL编码。                |
| baseUrl    | string | 否   | 指定的一个URL路径（“http”/“https”/"data"协议），并由Web组件赋值给window.origin。 |
| historyUrl | string | 否   | 历史记录URL。非空时，可被历史记录管理，实现前后后退功能。当baseUrl为空时，此属性无效。 |

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

从API version 9开始不再维护，建议使用[loadUrl<sup>9+</sup>](js-apis-webview.md#loadurl)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型                       | 必填  | 说明           |
| ------- | -------------------------- | ---- | -------------- |
| url     | string \| Resource                     | 是  | 需要加载的 URL。     |
| headers | Array\<[Header](#header)\> | 否    | URL的附加HTTP请求头。默认值：[]。 |

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

从API version 9开始不再维护，建议使用[onActive<sup>9+</sup>](js-apis-webview.md#onactive)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

从API version 9开始不再维护，建议使用[onInactive<sup>9+</sup>](js-apis-webview.md#oninactive)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

从API version 9开始不再维护，建议使用[zoom<sup>9+</sup>](js-apis-webview.md#zoom)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                           |
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

从API version 9开始不再维护，建议使用[refresh<sup>9+</sup>](js-apis-webview.md#refresh)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

从API version 9开始不再维护，建议使用[registerJavaScriptProxy<sup>9+</sup>](js-apis-webview.md#registerjavascriptproxy)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名        | 类型            | 必填  | 说明                                     |
| ---------- | --------------- | ---- | ---------------------------------------- |
| object     | object          | 是    | 参与注册的应用侧JavaScript对象。可以声明方法，也可以声明属性，但是不支持h5直接调用。其中方法的参数和返回类型只能为string，number，boolean |
| name       | string          | 是    | 注册对象的名称，与window中调用的对象名一致。注册后window对象可以通过此名字访问应用侧JavaScript对象。 |
| methodList | Array\<string\> | 是    | 参与注册的应用侧JavaScript对象的方法。                 |

**示例：**

  ```ts
  // xxx.ets
  class TestObj {
    constructor() {
    }

    test(): string {
      return "ArkUI Web Component"
    }

    toString(): void {
      console.log('Web Component toString')
    }
  }

  @Entry
  @Component
  struct Index {
    controller: WebController = new WebController()
    testObj = new TestObj();
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

从API version 9开始不再维护，建议使用[runJavaScript<sup>9+</sup>](js-apis-webview.md#runjavascript)代替。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                                     |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| script   | string                   | 是   | JavaScript脚本。                            |
| callback | (result: string) => void | 否   | 回调执行JavaScript脚本结果。JavaScript脚本若执行失败或无返回值时，返回null。 |

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
        .onPageEnd((event) => {
          this.controller.runJavaScript({
            script: 'test()',
            callback: (result: string)=> {
              this.webResult = result
              console.info(`The test() return value is: ${result}`)
            }})
          if (event) {
            console.info('url: ', event.url)
          }
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

从API version 9开始不再维护，建议使用[stop<sup>9+</sup>](js-apis-webview.md#stop)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

从API version 9开始不再维护，建议使用[clearHistory<sup>9+</sup>](js-apis-webview.md#clearhistory)代替。

**系统能力：** SystemCapability.Web.Webview.Core

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

通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有Web组件共享一个WebCookie。通过controller方法中的getCookieManager方法可以获取WebCookie对象，进行后续的cookie管理操作。

### setCookie<sup>(deprecated)</sup>

setCookie()

设置cookie，该方法为同步方法。设置成功返回true，否则返回false。

从API version 9开始不再维护，建议使用[setCookie<sup>9+</sup>](js-apis-webview.md#setcookie)代替。

**系统能力：** SystemCapability.Web.Webview.Core

### saveCookie<sup>(deprecated)</sup>

saveCookie()

将当前存在内存中的cookie同步到磁盘中，该方法为同步方法。

从API version 9开始不再维护，建议使用[saveCookieAsync<sup>9+</sup>](js-apis-webview.md#savecookieasync)代替。

**系统能力：** SystemCapability.Web.Webview.Core

## ScriptItem<sup>11+</sup>

通过[javaScriptOnDocumentStart](#javascriptondocumentstart11)属性注入到Web组件的ScriptItem对象。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 类型             | 必填   | 说明                    |
| ----------- | -------------- | ---- | --------------------- |
| script      | string         | 是    | 需要注入、执行的JavaScript脚本。 |
| scriptRules | Array\<string> | 是   | 一组允许来源的匹配规则。<br>1.如果需要允许所有来源的网址，使用通配符“ * ”。<br>2.如果需要精确匹配，则描述网站地址，如"https:\//www\.example.com"。<br>3.如果模糊匹配网址，可以使用“ * ”通配符替代，如"https://*.example.com"。不允许使用"x. * .y.com"、" * foobar.com"等。<br>4.如果来源是ip地址，则使用规则2。<br>5.对于http/https以外的协议(自定义协议)，不支持使用精确匹配和模糊匹配，且必须以"://"结尾，例如"resource://"。<br>6.一组scriptRule中，如果其中一条不满足以上规则，则整组scriptRule都不生效。 |

## WebNavigationType<sup>11+</sup>

定义navigation类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| UNKNOWN                       | 0 | 未知类型。   |
| MAIN_FRAME_NEW_ENTRY          | 1 | 主文档上产生的新的历史节点跳转。   |
| MAIN_FRAME_EXISTING_ENTRY     | 2 | 主文档上产生的到已有的历史节点的跳转。 |
| NAVIGATION_TYPE_NEW_SUBFRAME  | 4 | 子文档上产生的用户触发的跳转。 |
| NAVIGATION_TYPE_AUTO_SUBFRAME | 5 | 子文档上产生的非用户触发的跳转。 |

## LoadCommittedDetails<sup>11+</sup>

提供已提交跳转的网页的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型                                  | 必填   | 说明                    |
| -----------     | ------------------------------------ | ---- | --------------------- |
| isMainFrame     | boolean                              | 是    | 是否是主文档。 |
| isSameDocument  | boolean                              | 是    | 是否在不更改文档的情况下进行的网页跳转。在同文档跳转的示例：1.参考片段跳转；2.pushState或replaceState触发的跳转；3.同一页面历史跳转。  |
| didReplaceEntry | boolean                              | 是    | 是否提交的新节点替换了已有的节点。另外在一些子文档跳转的场景，虽然没有实际替换已有节点，但是有一些属性发生了变更。  |
| navigationType  | [WebNavigationType](#webnavigationtype11)  | 是    | 网页跳转的类型。       |
| url             | string                               | 是    | 当前跳转网页的URL。          |

## ThreatType<sup>11+</sup>

定义网站风险类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 值 | 说明                   |
| ---------------- | -- | ----------------------|
| THREAT_ILLEGAL  | 0 | 非法网站。              |
| THREAT_FRAUD    | 1 | 欺诈网站。              |
| THREAT_RISK     | 2 | 存在安全风险的网站。      |
| THREAT_WARNING  | 3 | 涉嫌包含不健康内容的网站。 |

## OnNavigationEntryCommittedCallback<sup>11+</sup>

type OnNavigationEntryCommittedCallback = (loadCommittedDetails: [LoadCommittedDetails](#loadcommitteddetails11)) => void

导航条目提交时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| loadCommittedDetails | [LoadCommittedDetails](#loadcommitteddetails11)  | 是 | 提供已提交跳转的网页的详细信息。 |

## OnSafeBrowsingCheckResultCallback<sup>11+</sup>

type OnSafeBrowsingCheckResultCallback = (threatType: ThreatType) => void

网站安全风险检查触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| threatType | [ThreatType](#threattype11)  | 是 | 定义网站threat类型。  |

## FullScreenEnterEvent<sup>12+</sup>

Web组件进入全屏回调事件的详情。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型                                  | 必填   | 说明                    |
| -----------     | ------------------------------------ | ---- | --------------------- |
| handler     | [FullScreenExitHandler](#fullscreenexithandler9) | 是    | 用于退出全屏模式的函数句柄。 |
| videoWidth  | number | 否    | 视频的宽度，单位：px。如果进入全屏的是 `<video>` 元素，表示其宽度；如果进入全屏的子元素中包含 `<video>` 元素，表示第一个子视频元素的宽度；其他情况下，为0。 |
| videoHeight  | number | 否    | 视频的高度，单位：px。如果进入全屏的是 `<video>` 元素，表示其高度；如果进入全屏的子元素中包含 `<video>` 元素，表示第一个子视频元素的高度；其他情况下，为0。 |

## OnFullScreenEnterCallback<sup>12+</sup>

type OnFullScreenEnterCallback = (event: FullScreenEnterEvent) => void

Web组件进入全屏时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| event | [FullScreenEnterEvent](#fullscreenenterevent12)  | 是 | Web组件进入全屏的回调事件详情。 |

## SslErrorEvent<sup>12+</sup>

用户加载资源时发生SSL错误时触发的回调详情。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称     | 类型                                 | 必填   | 说明           |
| ------- | ------------------------------------ | ---- | -------------- |
| handler | [SslErrorHandler](#sslerrorhandler9) | 是    | 通知Web组件用户操作行为。 |
| error   | [SslError](#sslerror9枚举说明)        | 是    | 错误码。           |
| url   | string                                 | 是    | url地址。           |
| originalUrl   | string                         | 是    | 请求的原始url地址。           |
| referrer   | string                            | 是    | referrer url地址。           |
| isFatalError   | boolean                       | 是    | 是否是致命错误。           |
| isMainFrame   | boolean                        | 是    | 是否是主资源。           |


## OnSslErrorEventCallback<sup>12+</sup>

type OnSslErrorEventCallback = (sslErrorEvent: SslErrorEvent) => void

用户加载资源时发生SSL错误时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| sslErrorEvent | [SslErrorEvent](#sslerrorevent12)  | 是 | 用户加载资源时发生SSL错误时触发的回调详情。 |

## NativeEmbedStatus<sup>11+</sup>

定义同层标签生命周期，当加载页面中有同层标签会触发CREATE，同层标签移动或者放大会触发UPDATE，退出页面会触发DESTROY。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| CREATE                        | 0 | 同层标签创建。   |
| UPDATE                        | 1 | 同层标签更新。   |
| DESTROY                       | 2 | 同层标签销毁。 |
| ENTER_BFCACHE<sup>12+</sup>   | 3 | 同层标签进入BFCache。   |
| LEAVE_BFCACHE<sup>12+</sup>   | 4 | 同层标签离开BFCache。 |

## NativeEmbedInfo<sup>11+</sup>

提供同层标签的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                | 类型                                  | 必填   | 说明                        |
|-------------------| ------------------------------------ | ---- |---------------------------|
| id                | string             | 否    | 同层标签的id信息。             |
| type              | string                              | 否    | 同层标签的type信息，统一为小写字符。   |
| src               | string                              | 否    | 同层标签的src信息。            |
| width             | number  | 否    | 同层标签的宽，单位为px。          |
| height            | number                              | 否    | 同层标签的高，单位为px。          |
| url               | string                              | 否    | 同层标签的url信息。            |
| tag<sup>12+</sup> | string              | 否    | 标签名，统一为大写字符。              |
| params<sup>12+</sup>            | Map<string, string> | 否    | object标签包含的param标签键值对列表，该map本质为Object类型，请使用Object提供的方法操作该对象。  |
| position<sup>12+</sup>          | Position            | 否    | 同层标签在屏幕坐标系中相对于Web组件的位置信息，此处区别于标准Position，单位为px。 |

## NativeEmbedDataInfo<sup>11+</sup>

提供同层标签生命周期变化的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型                                  | 必填   | 说明                    |
| -----------     | ------------------------------------ | ---- | --------------------- |
| status     | [NativeEmbedStatus](#nativeembedstatus11)             | 否    | 同层标签生命周期状态。 |
| surfaceId  | string                              | 否    | NativeImage的psurfaceid。  |
| embedId | string                              | 否    | 同层标签的唯一id。  |
| info  | [NativeEmbedInfo](#nativeembedinfo11)  | 否    | 同层标签的详细信息。       |

## NativeEmbedTouchInfo<sup>11+</sup>

提供手指触摸到同层标签的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型                                  | 必填   | 说明                    |
| -----------     | ------------------------------------ | ---- | --------------------- |
| embedId     | string   | 否    | 同层标签的唯一id。 |
| touchEvent  | [TouchEvent](../apis-arkui/arkui-ts/ts-universal-events-touch.md#touchevent对象说明)  | 否    | 手指触摸动作信息。 |
| result<sup>12+</sup>     | [EventResult](#eventresult12)   | 否    | 通知Web组件手势事件的消费结果。 |

## FirstMeaningfulPaint<sup>12+</sup>

提供网页绘制页面主要内容的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                     | 类型   | 必填 | 说明                                   |
| ------------------------ | ------ | ---- | -------------------------------------- |
| navigationStartTime      | number | 否  | 导航条加载时间，单位以微秒表示。       |
| firstMeaningfulPaintTime | number | 否   | 绘制页面主要内容时间，单位以毫秒表示。 |

## OnFirstMeaningfulPaintCallback<sup>12+</sup>

type OnFirstMeaningfulPaintCallback = (firstMeaningfulPaint: [FirstMeaningfulPaint](#firstmeaningfulpaint12)) => void

网页绘制页面度量信息的回调，当网页加载完页面主要内容时会触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| firstMeaningfulPaint | [FirstMeaningfulPaint](#firstmeaningfulpaint12) | 是 | 绘制页面主要内容度量的详细信息。 |

## LargestContentfulPaint<sup>12+</sup>

提供网页绘制页面主要内容的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                      | 类型   | 必填 | 说明                                     |
| ------------------------- | ------ | ---- | ---------------------------------------- |
| navigationStartTime       | number | 否   | 导航条加载时间，单位以微秒表示。         |
| largestImagePaintTime     | number | 否   | 最大图片加载的时间，单位是以毫秒表示。   |
| largestTextPaintTime      | number | 否   | 最大文本加载时间，单位是以毫秒表示。     |
| largestImageLoadStartTime | number | 否   | 最大图片开始加载时间，单位是以毫秒表示。 |
| largestImageLoadEndTime   | number | 否   | 最大图片结束记载时间，单位是以毫秒表示。 |
| imageBPP                  | number | 否   | 最大图片像素位数。                           |

## OnLargestContentfulPaintCallback<sup>12+</sup>

type OnLargestContentfulPaintCallback = (largestContentfulPaint: [LargestContentfulPaint](#largestcontentfulpaint12
)) => void

网页绘制页面最大内容度量信息的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| largestContentfulPaint | [LargestContentfulPaint](#largestcontentfulpaint12) | 是 | 网页绘制页面最大内容度量的详细信息。 |

## IntelligentTrackingPreventionDetails<sup>12+</sup>

提供智能防跟踪拦截的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型                                | 必填   | 说明         |
| ------------- | ------------------------------------| ----- | ------------ |
| host          | string                              | 是     | 网站域名。    |
| trackerHost   | string                              | 是     | 追踪者域名。  |

## OnIntelligentTrackingPreventionCallback<sup>12+</sup>

type OnIntelligentTrackingPreventionCallback = (details: IntelligentTrackingPreventionDetails) => void

当跟踪者cookie被拦截时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| details | [IntelligentTrackingPreventionDetails](#intelligenttrackingpreventiondetails12)  | 是 | 提供智能防跟踪拦截的详细信息。 |

## OnOverrideUrlLoadingCallback<sup>12+</sup>

type OnOverrideUrlLoadingCallback = (webResourceRequest: WebResourceRequest) => boolean

onOverrideUrlLoading的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名              | 类型    | 必填   |  说明 |
| ------------------ | ------- | ---- | ------------- |
| webResourceRequest   |   [WebResourceRequest](#webresourcerequest)   | 是   | url请求的相关信息。|

**返回值：**

| 类型      | 说明                       |
| ------- | ------------------------ |
| boolean | 返回true表示阻止此次加载，否则允许此次加载。 |

## RenderMode<sup>12+</sup>枚举说明

定义Web组件的渲染方式，默认为异步渲染模式。

建议使用异步渲染模式，异步渲染模式有更好的性能和更低的功耗。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| ASYNC_RENDER                        | 0 | Web组件异步渲染模式，ArkWeb组件作为图形surface节点，独立送显，Web组件的宽度最大规格不超过7,680 px（物理像素）。   |
| SYNC_RENDER                        | 1 | Web组件同步渲染模式，ArkWeb组件作为图形canvas节点，跟随系统组件一起送显，可以渲染更长的Web组件内容，Web组件的宽度最大规格不超过500,000 px（物理像素）。   |

## NativeMediaPlayerConfig<sup>12+</sup>

用于[开启应用接管网页媒体播放功能](#enablenativemediaplayer12)的配置信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 必填 | 说明 |
|------|------|------|------|
|  enable  | boolean | 是 | 是否开启该功能。<br/> `true` : 开启  <br/> `false` : 关闭(默认值) |
|  shouldOverlay | boolean | 是 | 开启该功能后， 应用接管网页视频的播放器画面是否覆盖网页内容。<br/> `true` : 是，改变视频图层的高度，使其覆盖网页内容 <br/> `false` : 否(默认值), 不覆盖，跟原视频图层高度一样，嵌入在网页中。 |

## RenderProcessNotRespondingReason<sup>12+</sup>

触发渲染进程无响应回调的原因。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| INPUT_TIMEOUT                  | 0 | 发送给渲染进程的input事件响应超时。   |
| NAVIGATION_COMMIT_TIMEOUT      | 1 | 新的网页加载导航响应超时。   |

## RenderProcessNotRespondingData<sup>12+</sup>

提供渲染进程无响应的详细信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                     | 类型   | 必填 | 说明                                   |
| ------------------------ | ------ | ---- | -------------------------------------- |
| jsStack      | string | 是  | 网页的javaScript调用栈信息。       |
| pid | number | 是   | 网页的进程id。 |
| reason | [RenderProcessNotRespondingReason](#renderprocessnotrespondingreason12) | 是   | 触发渲染进程无响应回调的原因。 |

## OnRenderProcessNotRespondingCallback<sup>12+</sup>

type OnRenderProcessNotRespondingCallback = (data : RenderProcessNotRespondingData) => void

渲染进程无响应时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| data | [RenderProcessNotRespondingData](#renderprocessnotrespondingdata12) | 是 | 渲染进程无响应的详细信息。 |

## OnRenderProcessRespondingCallback<sup>12+</sup>

type OnRenderProcessRespondingCallback = () => void

渲染进程由无响应状态变回正常运行状态时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

## ViewportFit<sup>12+</sup>

网页meta中viewport-fit配置的视口类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| AUTO                  | 0 | 默认值，整个网页可见。   |
| CONTAINS      | 1 | 初始布局视口和视觉视口为适应设备显示屏的最大矩形内。   |
| COVER      | 2| 初始布局视口和视觉视口为设备物理屏幕的外接矩形内。   |

## OnViewportFitChangedCallback<sup>12+</sup>

type OnViewportFitChangedCallback = (viewportFit: ViewportFit) => void

网页meta中viewport-fit配置项更改时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| viewportFit | [ViewportFit](#viewportfit12) | 是 | 网页meta中viewport-fit配置的视口类型。 |

## ExpandedMenuItemOptions<sup>12+</sup>

自定义菜单扩展项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型                                             | 必填    | 说明             |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| content   | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | 是     | 显示内容。     |
| startIcon | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | 否     | 显示图标。     |
| action    | (selectedText: {plainText: string}) => void                                                         | 是     | 选中的文本信息。|

## WebKeyboardAvoidMode<sup>12+</sup>

软键盘避让的模式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称               | 值 | 说明           |
| ------------------ | -- | ------------ |
| RESIZE_VISUAL      | 0 | 软键盘避让时，仅调整可视视口大小，不调整布局视口大小。   |
| RESIZE_CONTENT     | 1 | 默认值，软键盘避让时，同时调整可视视口和布局视口的大小。 |
| OVERLAYS_CONTENT   | 2 | 不调整任何视口大小，不会触发软键盘避让。   |

## OnPageEndEvent<sup>12+</sup>

定义网页加载结束时触发的函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 页面的URL地址。                       |

## OnPageBeginEvent<sup>12+</sup>

定义网页加载开始时触发的函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 页面的URL地址。                       |

## OnProgressChangeEvent<sup>12+</sup>

定义网页加载进度变化时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| newProgress | number | 是 | 新的加载进度，取值范围为0到100的整数。                       |

## OnTitleReceiveEvent<sup>12+</sup>

定义网页document标题更改时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| title | string | 是 | document标题内容。                       |

## OnGeolocationShowEvent<sup>12+</sup>

定义通知用户收到地理位置信息获取请求。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| origin | string | 是 | 指定源的字符串索引。                       |
| geolocation | [JsGeolocation](#jsgeolocation) | 是 | 通知Web组件用户操作行为。                       |

## OnAlertEvent<sup>12+</sup>

定义网页触发alert()告警弹窗时触发回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 当前显示弹窗所在网页的URL。                       |
| message | string | 是 | 弹窗中显示的信息。                       |
| result | [JsResult](#jsresult) | 是 | 通知Web组件用户操作行为。                       |

## OnBeforeUnloadEvent<sup>12+</sup>

定义刷新或关闭场景下，在即将离开当前页面时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 当前显示弹窗所在网页的URL。                       |
| message | string | 是 | 弹窗中显示的信息。                       |
| result | [JsResult](#jsresult) | 是 | 通知Web组件用户操作行为。                       |

## OnConfirmEvent<sup>12+</sup>

定义网页调用confirm()告警时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 当前显示弹窗所在网页的URL。                       |
| message | string | 是 | 弹窗中显示的信息。                       |
| result | [JsResult](#jsresult) | 是 | 通知Web组件用户操作行为。                       |

## OnPromptEvent<sup>12+</sup>

定义网页调用prompt()告警时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | 是 | 当前显示弹窗所在网页的URL。                       |
| message | string | 是 | 弹窗中显示的信息。                       |
| value | string | 是 | 提示对话框的信息。                       |
| result | [JsResult](#jsresult) | 是 | 通知Web组件用户操作行为。                       |

## OnConsoleEvent<sup>12+</sup>

定义通知宿主应用JavaScript console消息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| message | [ConsoleMessage](#consolemessage) | 是 | 触发的控制台信息。                       |

## OnErrorReceiveEvent<sup>12+</sup>

定义网页加载遇到错误时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](#webresourcerequest) | 是 | 网页请求的封装信息。      |
| error   | [WebResourceError](#webresourceerror)    | 是 | 网页加载资源错误的封装信息 。 |

## OnHttpErrorReceiveEvent<sup>12+</sup>

定义网页收到加载资源加载HTTP错误时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](#webresourcerequest) | 是 | 网页请求的封装信息。      |
| response   | [WebResourceResponse](#webresourceresponse)    | 是 | 资源响应的封装信息。 |

## OnDownloadStartEvent<sup>12+</sup>

定义通知主应用开始下载一个文件。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url                | string | 是 | 文件下载的URL。                           |
| userAgent          | string | 是 | 用于下载的用户代理。                          |
| contentDisposition | string | 是 | 服务器返回的 Content-Disposition响应头，可能为空。 |
| mimetype           | string | 是 | 服务器返回内容媒体类型（MIME）信息。                |
| contentLength      | number | 是 | 服务器返回文件的长度。                         |

## OnRefreshAccessedHistoryEvent<sup>12+</sup>

定义网页刷新访问历史记录时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url         | string  | 是 | 访问的url。                                  |
| isRefreshed | boolean | 是 | true表示该页面是被重新加载的（调用[refresh<sup>9+</sup>](js-apis-webview.md#refresh)接口），false表示该页面是新加载的。 |

## OnRenderExitedEvent<sup>12+</sup>

定义渲染过程退出时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| renderExitReason | [RenderExitReason](#renderexitreason9枚举说明) | 是 | 渲染进程异常退出的具体原因。 |

## OnShowFileSelectorEvent<sup>12+</sup>

定义文件选择器结果。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| result       | [FileSelectorResult](#fileselectorresult9) | 是 | 用于通知Web组件文件选择的结果。 |
| fileSelector | [FileSelectorParam](#fileselectorparam9) | 是 | 文件选择器的相关信息。       |

## OnResourceLoadEvent<sup>12+</sup>

定义加载url时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url  | string | 是 | 所加载的资源文件url信息。 |

## OnScaleChangeEvent<sup>12+</sup>

定义当前页面显示比例的变化时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| oldScale | number | 是 | 变化前的显示比例百分比。 |
| newScale | number | 是 | 变化后的显示比例百分比。 |

## OnHttpAuthRequestEvent<sup>12+</sup>

定义通知收到http auth认证请求。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [HttpAuthHandler](#httpauthhandler9) | 是 | 通知Web组件用户操作行为。   |
| host    | string                               | 是 | HTTP身份验证凭据应用的主机。 |
| realm   | string                               | 是 | HTTP身份验证凭据应用的域。  |

## OnInterceptRequestEvent<sup>12+</sup>

定义当Web组件加载url之前触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](#webresourcerequest) | 是 | url请求的相关信息。 |

## OnPermissionRequestEvent<sup>12+</sup>

定义通知收到获取权限请求。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [PermissionRequest](#permissionrequest9) | 是 | 通知Web组件用户操作行为。 |

## OnScreenCaptureRequestEvent<sup>12+</sup>

定义通知收到屏幕捕获请求。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [ScreenCaptureHandler](#screencapturehandler10) | 是 | 通知Web组件用户操作行为。 |

## OnContextMenuShowEvent<sup>12+</sup>

定义调用时触发的回调，以允许自定义显示上下文菜单。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| param  | [WebContextMenuParam](#webcontextmenuparam9) | 是 | 菜单相关参数。     |
| result | [WebContextMenuResult](#webcontextmenuresult9) | 是 | 菜单相应事件传入内核。 |

## OnSearchResultReceiveEvent<sup>12+</sup>

定义通知调用方网页页内查找的结果。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| activeMatchOrdinal | number  | 是 | 当前匹配的查找项的序号（从0开始）。                       |
| numberOfMatches    | number  | 是 | 所有匹配到的关键词的个数。                            |
| isDoneCounting     | boolean | 是 | 当次页内查找操作是否结束。该方法可能会回调多次，直到isDoneCounting为true为止。 |

## OnScrollEvent<sup>12+</sup>

定义滚动条滑动到指定位置时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| xOffset | number | 是 | 以网页最左端为基准，水平滚动条滚动所在位置。 |
| yOffset | number | 是 | 以网页最上端为基准，竖直滚动条滚动所在位置。 |

## OnSslErrorEventReceiveEvent<sup>12+</sup>

定义网页收到SSL错误时触发。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [SslErrorHandler](#sslerrorhandler9) | 是 | 通知Web组件用户操作行为。 |
| error   | [SslError](#sslerror9枚举说明)           | 是 | 错误码。           |

## OnClientAuthenticationEvent<sup>12+</sup>

定义当需要用户提供SSL客户端证书时触发回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler  | [ClientAuthenticationHandler](#clientauthenticationhandler9) | 是 | 通知Web组件用户操作行为。  |
| host     | string                                   | 是 | 请求证书服务器的主机名。    |
| port     | number                                   | 是 | 请求证书服务器的端口号。    |
| keyTypes | Array<string\>                           | 是 | 可接受的非对称秘钥类型。    |
| issuers  | Array<string\>                           | 是 | 与私钥匹配的证书可接受颁发者。 |

## OnWindowNewEvent<sup>12+</sup>

定义网页要求用户创建窗口时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| isAlert       | boolean                                  | 是 | true代表请求创建对话框，false代表新标签页。    |
| isUserTrigger | boolean                                  | 是 | true代表用户触发，false代表非用户触发。      |
| targetUrl     | string                                   | 是 | 目标url。                        |
| handler       | [ControllerHandler](#controllerhandler9) | 是 | 用于设置新建窗口的WebviewController实例。 |

## OnTouchIconUrlReceivedEvent<sup>12+</sup>

定义设置接收到apple-touch-icon url地址时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url         | string  | 是 | 接收到的apple-touch-icon url地址。 |
| precomposed | boolean | 是 | 对应apple-touch-icon是否为预合成。   |

## OnFaviconReceivedEvent<sup>12+</sup>

定义应用为当前页面接收到新的favicon时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| favicon | [PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是 | 接收到的favicon图标的PixelMap对象。 |

## OnPageVisibleEvent<sup>12+</sup>

定义旧页面不再呈现，新页面即将可见时触发的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| url  | string | 是 | 旧页面不再呈现，新页面即将可见时新页面的url地址。 |

## OnDataResubmittedEvent<sup>12+</sup>

定义网页表单可以重新提交时触发的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [DataResubmissionHandler](#dataresubmissionhandler9) | 是 | 表单数据重新提交句柄。 |

## OnAudioStateChangedEvent<sup>12+</sup>

定义网页上的音频播放状态发生改变时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| playing | boolean | 是 | 当前页面的音频播放状态，true表示正在播放，false表示未播放。 |

## OnFirstContentfulPaintEvent<sup>12+</sup>

定义网页首次内容绘制回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| navigationStartTick    | number | 是 | navigation开始的时间，单位以微秒表示。          |
| firstContentfulPaintMs | number | 是 | 从navigation开始第一次绘制内容的时间，单位是以毫秒表示。 |

## OnLoadInterceptEvent<sup>12+</sup>

定义截获资源加载时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| data | [WebResourceRequest](#webresourcerequest) | 是 | url请求的相关信息。 |

## OnOverScrollEvent<sup>12+</sup>

定义网页过度滚动时触发的回调。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| xOffset | number | 是 | 以网页最左端为基准，水平过度滚动的偏移量。 |
| yOffset | number | 是 | 以网页最上端为基准，竖直过度滚动的偏移量。 |

## JavaScriptProxy<sup>12+</sup>

定义要注入的JavaScript对象。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 类型      | 必填   | 说明                                       |
| -------------- | ---- | ---- | ---------------------------------------- |
| object     | object                                   | 是    | 参与注册的对象。只能声明方法，不能声明属性。                   |
| name       | string                                   | 是    | 注册对象的名称，与window中调用的对象名一致。                |
| methodList | Array\<string\>                          | 是    | 参与注册的应用侧JavaScript对象的同步方法。                 |
| controller | [WebController](#webcontroller) \| [WebviewController<sup>9+</sup>](js-apis-webview.md#webviewcontroller) | 是    | -    | 控制器。从API Version 9开始，WebController不再维护，建议使用WebviewController替代。 |
| asyncMethodList<sup>12+</sup>  | Array\<string\>      | 否    | 参与注册的应用侧JavaScript对象的异步方法。异步方法无法获取返回值。   |
| permission<sup>12+</sup>  | string  | 否    | json字符串，默认为空，通过该字符串配置JSBridge的权限管控，可以定义object、method一级的url白名单。<br>示例请参考[前端页面调用应用侧函数](../../web/web-in-page-app-function-invoking.md)。 |

## AdsBlockedDetails<sup>12+</sup>

发生广告拦截时，广告资源信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 类型                                                                           | 必填   | 说明                    |
| ------- | --------------------------------------------------------------------------------  | ---- | ------------------------- |
| url | string  | 是    | 发生广告过滤的页面url。 |
| adsBlocked | Array\<string\>  | 是    | 被过滤的资源的url或dompath标识，被过滤的多个对象url相同则可能出现重复元素。 |

## OnAdsBlockedCallback<sup>12+</sup>

type OnAdsBlockedCallback = (details: AdsBlockedDetails) => void

当页面发生广告过滤时触发此回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名               | 类型                                        | 必填   | 说明                         |
| -------------------- | ----------------------------------------------- | ---- | -------------------------------- |
| details | [AdsBlockedDetails](#adsblockeddetails12) | 是    | 发生广告拦截时，广告资源信息。 |

## NativeEmbedVisibilityInfo<sup>12+</sup>

提供同层标签的可见性信息。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型                                | 必填   | 说明              |
| -------------  | ------------------------------------| ----- | ------------------ |
| visibility     | boolean                             | 是     | 可见性。         |
| embedId        | string                              | 是     | 同层渲染标签的唯一id。  |

## OnNativeEmbedVisibilityChangeCallback<sup>12+</sup>

type OnNativeEmbedVisibilityChangeCallback = (nativeEmbedVisibilityInfo: NativeEmbedVisibilityInfo) => void

当同层标签可见性变化时触发该回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名    | 类型   | 必填   | 说明                  |
| ------ | ------ | ---- | --------------------- |
| nativeEmbedVisibilityInfo | [NativeEmbedVisibilityInfo](#nativeembedvisibilityinfo12)  | 是 | 提供同层标签的可见性信息。 |

## WebElementType<sup>13+</sup>枚举说明

网页元素信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 名称       | 值 | 说明              |
| --------- | -- | ----------------- |
| IMAGE     | 1 | 网页元素为图像类型。 |

## WebResponseType<sup>13+</sup>枚举说明

菜单的响应类型。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 名称            | 值 | 说明                |
| -------------- | -- | ------------------  |
| LONG_PRESS     | 1 | 通过长按触发菜单弹出。 |

## SelectionMenuOptionsExt<sup>13+</sup>

自定义菜单扩展项。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 类型                                             | 必填    | 说明             |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| onAppear   | Callback\<void\>   | 否     | 自定义选择菜单弹出时回调。     |
| onDisappear | Callback\<void\>  | 否     | 自定义选择菜单关闭时回调。     |
| preview    | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)          | 否     | 自定义选择菜单的预览内容样式, 未配置时无预览内容。|
| menuType   | [MenuType](../apis-arkui/arkui-ts/ts-text-common.md#menutype13枚举说明)      | 否     | 自定义选择菜单类型。<br>默认值：MenuType.SELECTION_MENU     |