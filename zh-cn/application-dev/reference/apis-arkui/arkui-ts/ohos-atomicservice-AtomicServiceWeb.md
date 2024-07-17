# @ohos.atomicservice.AtomicServiceWeb（Web高阶组件）

为开发者提供满足定制化诉求的Web高阶组件，屏蔽原生Web组件中无需关注的接口，并提供JS扩展能力。

> **说明：**
>
> - 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## 需要权限

访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[声明权限](../../../security/AccessToken/declare-permissions.md)。

## 导入模块

```
import { AtomicServiceWeb } from '@kit.ArkUI';
```

## 子组件

无

## 属性

不支持[通用属性](ts-universal-attributes-size.md)

## AtomicServiceWeb

AtomicServiceWeb({
  src: ResourceStr,
  navPathStack?: NavPathStack,
  onMessage?: Callback\<OnMessageEvent\>,
  onErrorReceive?: Callback\<OnErrorReceiveEvent\>,
  onHttpErrorReceive?: Callback\<OnHttpErrorReceiveEvent\>,
  onPageBegin?: Callback\<OnPageBeginEvent\>,
  onPageEnd?: Callback\<OnPageEndEvent\>
})

**装饰器类型：**@Component

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 名称                 | 类型                                                                                      | 必填 | 描述                                                                                                                   |
|--------------------|-----------------------------------------------------------------------------------------|----|----------------------------------------------------------------------------------------------------------------------|
| src                | [ResourceStr](ts-types.md#resourcestr)                           | 是  | 网页资源地址，访问网络资源需要在AGC配置业务域名，访问本地资源仅支持包内文件（$rawfile）。不支持通过状态变量（例如@State）动态更新地址。加载的网页中支持通过JS SDK提供的接口调用系统能力，具体以JS SDK为准。 |
| navPathStack       | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | 否  | 路由栈信息。当使用NavDestination作为页面的根容器时，需传入NavDestination容器对应的NavPathStack处理页面路由。                                           |
| onMessage          | Callback\<[OnMessageEvent](#onmessageevent)\>                                           | 否  | H5页面通过JS SDK的postMessage()发送消息后，Web组件对应的页面返回或销毁时，触发该回调。                                                              |
| onErrorReceive     | Callback\<[OnErrorReceiveEvent](#onerrorreceiveevent)\>                                 | 否  | 网页加载遇到错误时触发该回调。出于性能考虑，建议此回调中尽量执行简单逻辑。在无网络的情况下，触发此回调。                                                                 |
| onHttpErrorReceive | Callback\<[OnHttpErrorReceiveEvent](#onhttperrorreceiveevent)\>                         | 否  | 网页加载资源遇到的HTTP错误（响应码>=400)时触发该回调。                                                                                     |
| onPageBegin        | Callback\<[OnPageBeginEvent](#onpagebeginevent)\>                                       | 否  | 网页开始加载时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。                                                              |
| onPageEnd          | Callback\<[OnPageEndEvent](#onpageendevent)\>                                           | 否  | 网页加载完成时触发该回调，且只在主frame触发。                                                                                            |

## OnMessageEvent

定义页面回退或销毁时触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型        | 必填 | 说明    |
|------|-----------|----|-------|
| data | Object[]	 | 是  | 消息列表。 |

## OnErrorReceiveEvent

定义网页加载遇到错误时触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                                                                                     | 必填 | 说明              |
|---------|----------------------------------------------------------------------------------------|----|-----------------|
| request | [WebResourceRequest](../../apis-arkweb/ts-basic-components-web.md#webresourcerequest)	 | 是  | 网页请求的封装信息。      |
| error   | [WebResourceError](../../apis-arkweb/ts-basic-components-web.md#webresourceerror)      | 是  | 网页加载资源错误的封装信息 。 |

## OnHttpErrorReceiveEvent

定义网页收到加载资源加载HTTP错误时触发。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型                                                                                      | 必填 | 说明         |
|----------|-----------------------------------------------------------------------------------------|----|------------|
| request  | [WebResourceRequest](../../apis-arkweb/ts-basic-components-web.md#webresourcerequest)	  | 是  | 网页请求的封装信息。 |
| response | [WebResourceResponse](../../apis-arkweb/ts-basic-components-web.md#webresourceresponse) | 是  | 资源响应的封装信息。 |

## OnPageBeginEvent

定义网页加载开始时触发的函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型     | 必填 | 说明        |
|-----|--------|----|-----------|
| url | string | 是  | 页面的URL地址。 |

## OnPageEndEvent

定义网页加载结束时触发的函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型     | 必填 | 说明        |
|-----|--------|----|-----------|
| url | string | 是  | 页面的URL地址。 |

## 事件

不支持[通用事件](ts-universal-events-click.md)

## 示例

### 示例1

加载本地网页。

```ts
// xxx.ets
import { AtomicServiceWeb } from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
  build() {
    Column() {
      AtomicServiceWeb({ src: $rawfile("index.html") })
    }
  }
}
```

### 示例2

加载在线网页。

```ts
// xxx.ets
import { AtomicServiceWeb } from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
    build() {
        Column() {
            AtomicServiceWeb({ src: 'https://www.example.com' })
        }
    }
}
```

### 示例3

NavDestination容器中加载网页。

```ts
// xxx.ets
import { AtomicServiceWeb } from '@kit.ArkUI';

@Builder
export function WebComponentBuilder(name: string, param: Object) {
  WebComponent()
}

@Component
struct WebComponent {
  navPathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      AtomicServiceWeb({ src: $rawfile("index.html"), navPathStack: this.navPathStack })
    }
    .onReady((context: NavDestinationContext) => {
      this.navPathStack = context.pathStack;
    })
  }
}
```

### 示例4

设置onMessage()事件回调。

```ts
// xxx.ets
import { AtomicServiceWeb, OnMessageEvent } from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
  build() {
    Column() {
      AtomicServiceWeb({
        src: $rawfile("index.html"),
        // H5页面点击“发送消息”后，再点击“返回上一页”，触发该回调
        onMessage: (event: OnMessageEvent) => {
          console.log(`[AtomicServiceWebLog] onMessage data=${JSON.stringify(event.data)}`);
        }
      })
    }
  }
}
```

```html
// index.html
<!DOCTYPE html>
<html>
<meta charset="utf-8">
<!-- 引入JS SDK文件 -->
<script src="../js/atomicservice-sdk.js" type="text/javascript"></script>
<body>
<h1>JS SDK - postMessage()</h1>
<br/>
<button type="button" onclick="postMessage({ name: 'Jerry', age: 18 });">发送消息</button>
<br/>
<button type="button" onclick="back();">返回上一页</button>
</body>
<script type="text/javascript">
    function postMessage(data) {
        // JS SDK提供的发送消息接口
        has.asWeb.postMessage({
            data: data,
            callback: (err, res) => {
                if (err) {
                    console.error('[AtomicServiceWebLog H5] postMessage error err=' + JSON.stringify(err));
                } else {
                    console.log('[AtomicServiceWebLog H5] postMessage success res=' + JSON.stringify(res));
                }
            }
        });
    }

    function back() {
        // JS SDK提供的Router路由回退接口
        has.router.back({
            delta: 1
        });
    }
</script>
</html>
```

### 示例5

设置网页加载事件回调。

```ts
// xxx.ets
import {
  AtomicServiceWeb,
  OnErrorReceiveEvent,
  OnHttpErrorReceiveEvent,
  OnPageBeginEvent,
  OnPageEndEvent
} from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
  build() {
    Column() {
      AtomicServiceWeb({
        src: $rawfile('index.html'),
        // 网页加载遇到错误时触发该回调
        onErrorReceive: (event: OnErrorReceiveEvent) => {
          console.log(`AtomicServiceWebLog onErrorReceive event=${JSON.stringify({
            requestUrl: event.request?.getRequestUrl(),
            requestMethod: event.request?.getRequestMethod(),
            errorCode: event.error?.getErrorCode(),
            errorInfo: event.error?.getErrorInfo()
          })}`);
        },
        // 网页加载遇到HTTP资源加载错误时触发该回调
        onHttpErrorReceive: (event: OnHttpErrorReceiveEvent) => {
          console.log(`AtomicServiceWebLog onHttpErrorReceive event=${JSON.stringify({
            requestUrl: event.request?.getRequestUrl(),
            requestMethod: event.request?.getRequestMethod(),
            responseCode: event.response?.getResponseCode(),
            responseData: event.response?.getResponseData(),
          })}`);
        },
        // 页面开始加载，触发该回调
        onPageBegin: (event: OnPageBeginEvent) => {
          console.log(`AtomicServiceWebLog onPageBegin event=${JSON.stringify({
            url: event.url
          })}`);
        },
        // 页面加载完成，触发该回调
        onPageEnd: (event: OnPageEndEvent) => {
          console.log(`AtomicServiceWebLog onPageEnd event=${JSON.stringify({
            url: event.url
          })}`);
        }
      })
    }
  }
}
```
