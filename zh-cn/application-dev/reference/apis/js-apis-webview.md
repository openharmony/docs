

# Webview

提供web控制能力。

> **说明：**
>
> - 本模块接口从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。

## 需要权限
访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[权限申请声明](../../security/accesstoken-guidelines.md)。

## 导入模块

```ts
import web_webview from '@ohos.web.webview';
```
## WebMessagePort

通过WebMessagePort可以进行消息的发送以及接收。

### close

close(): void

关闭该消息端口。

**系统能力：**
SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  msgPort: WebMessagePort[] = null;

  build() {
    Column() {
      Button('close')
        .onClick(() => {
          this.msgPort[1].close();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### postMessageEvent

postMessageEvent(message: string): void

发送消息。完整示例代码参考[postMessage](#postmessage)

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型   | 必填 | 默认值 | 说明           |
| ------- | ------ | ---- | ------ | :------------- |
| message | string | 是   | -      | 要发送的消息。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100010 | Can not post message using this port. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[];

  build() {
    Column() {
      Button('postMessageEvent')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');
            this.ports[1].postMessageEvent("post message from ets to html5");
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onMessageEvent

onMessageEvent(callback: (result: string) => void): void

注册回调函数，接收HTML5侧发送过来的消息。完整示例代码参考[postMessage](#postmessage)

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型     | 必填 | 默认值 | 说明                 |
| -------- | -------- | ---- | ------ | :------------------- |
| callback | function | 是   | -      | 接收消息的回调函数。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                        |
| -------- | ----------------------------------------------- |
| 17100006 | Can not register message event using this port. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[];

  build() {
    Column() {
      Button('onMessageEvent')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            this.ports[1].onMessageEvent((msg) => {
              console.log("received message from html5, on message:" + msg);
            })
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebviewController

通过WebviewController可以控制Web组件各种行为。一个WebviewController对象只能控制一个Web组件，且必须在Web组件和WebviewController绑定后，才能调用WebviewController上的方法。

### 创建对象

```ts
controller: web_webview.WebviewController = new web_webview.WebviewController();
```

### loadUrl

loadUrl(url: string | Resource, headers?: Array\<HeaderV9>): void

加载指定的URL。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 类型             | 必填 | 默认值 | 说明                  |
| ------- | ---------------- | ---- | ------ | :-------------------- |
| url     | string           | 是   | -      | 需要加载的 URL。      |
| headers | Array\<[HeaderV9](#headerv9)> | 是   | -      | URL的附加HTTP请求头。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100002 | Invalid url.                                                 |
| 17100003 | Invalid resource.                                            |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadUrl')
        .onClick(() => {
          try {
            this.controller.loadUrl('www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### loadData

loadData(data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string): void

加载指定的数据。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：** 

| 参数名     | 类型   | 必填 | 默认值 | 说明                                                         |
| ---------- | ------ | ---- | ------ | ------------------------------------------------------------ |
| data       | string | 是   | -      | 按照”Base64“或者”URL"编码后的一段字符串。                    |
| mimeType   | string | 是   | -      | 媒体类型（MIME）。                                           |
| encoding   | string | 是   | -      | 编码类型，具体为“Base64"或者”URL编码。                       |
| baseUrl    | string | 否   | -      | 指定的一个URL路径（“http”/“https”/"data"协议），并由Web组件赋值给window.origin。 |
| historyUrl | string | 否   | -      | 历史记录URL。非空时，可被历史记录管理，实现前进后退功能。当baseUrl为空时，此属性无效。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：** 

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          try {
            this.controller.loadData(
              "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>",
              "text/html",
              "UTF-8"
            );
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### accessforward

accessForward(): boolean

当前页面是否可前进，即当前页面是否有前进历史记录。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：** 

| 类型    | 说明                              |
| ------- | --------------------------------- |
| boolean | 可以前进返回true，否则返回false。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：** 

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('accessForward')
        .onClick(() => {
          try {
            let result = this.controller.accessForward();
            console.log('result:' + result);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### forward

forward(): void

按照历史栈，前进一个页面。一般结合accessForward一起使用。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：** 

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('forward')
        .onClick(() => {
          try {
            this.controller.forward();
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### accessBackward

accessBackward(): boolean

当前页面是否可后退，即当前页面是否有返回历史记录。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                             |
| ------- | -------------------------------- |
| boolean | 可以后退返回true,否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('accessBackward')
        .onClick(() => {
          try {
            let result = this.controller.accessBackward();
            console.log('result:' + result);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### backward

backward(): void

按照历史栈，后退一个页面。一般结合accessBackward一起使用。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：** 

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('backward')
        .onClick(() => {
          try {
            this.controller.backward();
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onActive

onActive(): void

调用此接口通知Web组件进入前台激活状态。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('onActive')
        .onClick(() => {
          try {
            this.controller.onActive();
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### onInactive

onInactive(): void

调用此接口通知Web组件进入未激活状态。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('onInactive')
        .onClick(() => {
          try {
            this.controller.onInactive();
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### refresh
refresh(): void

调用此接口通知Web组件刷新网页。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('refresh')
        .onClick(() => {
          try {
            this.controller.refresh();
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### accessStep

accessStep(step: number): boolean

当前页面是否可前进或者后退给定的step步。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述                                   |
| ------ | -------- | ---- | ------ | ------------------------------------------ |
| step   | number   | 是   | -      | 要跳转的步数，正数代表前进，负数代表后退。 |

**返回值：**

| 类型    | 说明               |
| ------- | ------------------ |
| boolean | 页面是否前进或后退 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State steps: number = 2;

  build() {
    Column() {
      Button('accessStep')
        .onClick(() => {
          try {
            let result = this.controller.accessStep(this.steps);
            console.log('result:' + result);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearHistory

clearHistory(): void

删除所有前进后退记录。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearHistory')
        .onClick(() => {
          try {
            this.controller.clearHistory();
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getHitTest

getHitTest(): HitTestTypeV9

获取当前被点击区域的元素类型。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| [HitTestTypeV9](#hittesttypev9)| 被点击区域的元素类型。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getHitTest')
        .onClick(() => {
          try {
            let hitTestType = this.controller.getHitTest();
            console.log("hitTestType: " + hitTestType);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### registerJavaScriptProxy

registerJavaScriptProxy(object: object, name: string, methodList: Array\<string>): void

注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。注册后，须调用[refresh](#refresh)接口生效。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 参数类型       | 必填 | 默认值 | 参数描述                                                     |
| ---------- | -------------- | ---- | ------ | ------------------------------------------------------------ |
| object     | object         | 是   | -      | 参与注册的应用侧JavaScript对象。只能声明方法，不能声明属性 。其中方法的参数和返回类型只能为string，number，boolean |
| name       | string         | 是   | -      | 注册对象的名称，与window中调用的对象名一致。注册后window对象可以通过此名字访问应用侧JavaScript对象。 |
| methodList | Array\<string> | 是   | -      | 参与注册的应用侧JavaScript对象的方法。                       |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct Index {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  testObj = {
    test: (data) => {
      return "ArkUI Web Component";
    },
    toString: () => {
      console.log('Web Component toString');
    }
  }

  build() {
    Column() {
      Button('Register JavaScript To Window')
        .onClick(() => {
          try {
            this.controller.registerJavaScriptProxy(this.testObj, "objName", ["test", "toString"]);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
    }
  }
}
```

### runJavaScript

runJavaScript(script: string, callback : AsyncCallback\<string>): void

异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 参数类型                 | 必填 | 默认值 | 参数描述                                                     |
| -------- | ------------------------ | ---- | ------ | ------------------------------------------------------------ |
| script   | string                   | 是   | -      | JavaScript脚本。                                             |
| callback | AsyncCallback\<string> | 否   | -      | 回调执行JavaScript脚本结果。JavaScript脚本若执行失败或无返回值时，返回null。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State webResult: string = ''

  build() {
    Column() {
      Text(this.webResult).fontSize(20)
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .onPageEnd(e => {
          try {
            this.controller.runJavaScript(
              'test()',
              (error, result) => {
                if (error) {
                  console.info(`run JavaScript error: ` + JSON.stringify(error))
                  return;
                }
                if (result) {
                  this.webResult = result
                  console.info(`The test() return value is: ${result}`)
                }
              });
            console.info('url: ', e.url);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
    }
  }
}
```

### runJavaScript

runJavaScript(script: string): Promise\<string>

异步执行JavaScript脚本，并通过Promise方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述         |
| ------ | -------- | ---- | ------ | ---------------- |
| script | string   | 是   | -      | JavaScript脚本。 |

**返回值：** 

| 类型            | 说明                                                |
| --------------- | --------------------------------------------------- |
| Promise\<string> | Promise实例，返回脚本执行的结果，执行失败返回null。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State webResult: string = '';

  build() {
    Column() {
      Text(this.webResult).fontSize(20)
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .onPageEnd(e => {
          try {
            this.controller.runJavaScript('test()')
              .then(function (result) {
                console.log('result: ' + result);
              })
              .catch(function (error) {
                console.error("error: " + error);
              })
            console.info('url: ', e.url);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
    }
  }
}
```

### deleteJavaScriptRegister

deleteJavaScriptRegister(name: string): void

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。删除后立即生效，无须调用[refresh](#refresh)接口。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述                                                     |
| ------ | -------- | ---- | ------ | ------------------------------------------------------------ |
| name   | string   | 是   | -      | 注册对象的名称，可在网页侧JavaScript中通过此名称调用应用侧JavaScript对象。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |
| 17100008 | Cannot delete JavaScriptProxy.                               |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State name: string = 'Object';

  build() {
    Column() {
      Button('deleteJavaScriptRegister')
        .onClick(() => {
          try {
            this.controller.deleteJavaScriptRegister(this.name);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### zoom

zoom(factor: number): void

调整当前网页的缩放比例。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述                                                     |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| factor | number   | 是   | 基于当前网页所需调整的相对缩放比例，正值为放大，负值为缩小。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |
| 17100004 | Cannot delete JavaScriptProxy.                               |
| 17100009 | Cannot zoom in or zoom out.                                  |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State factor: number = 1;

  build() {
    Column() {
      Button('zoom')
        .onClick(() => {
          try {
            this.controller.zoom(this.factor);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### searchAllAsync

searchAllAsync(searchString: string): void

异步查找网页中所有匹配关键字'searchString'的内容并高亮，结果通过[onSearchResultReceive](../arkui-ts/ts-basic-components-web.md#onsearchresultreceive9)异步返回。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 参数类型 | 必填 | 默认值 | 参数描述       |
| ------------ | -------- | ---- | ------ | -------------- |
| searchString | string   | 是   | -      | 查找的关键字。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State searchString: string = "xxx";

  build() {
    Column() {
      Button('searchString')
        .onClick(() => {
          try {
            this.controller.searchAllAsync(this.searchString);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .onSearchResultReceive(ret => {
          console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +
          "[total]" + ret.numberOfMatches + "[isDone]" + ret.isDoneCounting);
        })
    }
  }
}
```

### clearMatches

clearMatches(): void

清除所有通过[searchAllAsync](#searchallasync)匹配到的高亮字符查找结果。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearMatches')
        .onClick(() => {
          try {
            this.controller.clearMatches();
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### searchNext

searchNext(forward: boolean): void

滚动到下一个匹配的查找结果并高亮。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名  | 参数类型 | 必填 | 默认值 | 参数描述               |
| ------- | -------- | ---- | ------ | ---------------------- |
| forward | boolean  | 是   | -      | 从前向后或者逆向查找。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('searchNext')
        .onClick(() => {
          try {
            this.controller.searchNext(true);
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearSslCache

clearSslCache(): void

清除Web组件记录的SSL证书错误事件对应的用户操作行为。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearSslCache')
        .onClick(() => {
          try {
            this.controller.clearSslCache();
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### clearClientAuthenticationCache

clearClientAuthenticationCache(): void

清除Web组件记录的客户端证书请求事件对应的用户操作行为。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('clearClientAuthenticationCache')
        .onClick(() => {
          try {
            this.controller.clearClientAuthenticationCache();
          } catch (error) {
            console.error(`Errorcode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### createWebMessagePorts

 createWebMessagePorts(): Array\<WebMessagePort>

创建Web消息端口。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：** 

| 类型                   | 说明              |
| ---------------------- | ----------------- |
| Array\<WebMessagePort> | web消息端口列表。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：** 

  ```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[];

  build() {
    Column() {
      Button('createWebMessagePorts')
        .onClick(() => {
          try {
            this.ports = this.controller.createWebMessagePorts();
            console.log("createWebMessagePorts size:" + this.ports.length)
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
  ```

### postMessage

postMessage(name: string, ports: Array\<WebMessagePort>, uri: string): void

发送Web消息端口到HTML5。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型                   | 必填 | 默认值 | 说明                             |
| ------ | ---------------------- | ---- | ------ | :------------------------------- |
| name   | string                 | 是   | -      | 要发送的消息，包含数据和消息端口。 |
| ports  | Array\<WebMessagePort> | 是   | -      | 接收该消息的URI。                |
| uri    | string                 | 是   | -      | 接收该消息的URI。                |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  ports: web_webview.WebMessagePort[];
  @State sendFromEts: string = 'Send this message from ets to HTML';
  @State receivedFromHtml: string = 'Display received message send from HTML';

  build() {
    Column() {
      // 展示接收到的来自HTML的内容
      Text(this.receivedFromHtml)
      // 输入框的内容发送到html
      TextInput({placeholder: 'Send this message from ets to HTML'})
        .onChange((value: string) => {
          this.sendFromEts = value;
      })

      Button('postMessage')
        .onClick(() => {
          try {
            // 1、创建两个消息端口
            this.ports = this.controller.createWebMessagePorts();
            // 2、将其中一个消息端口发送到HTML侧，由HTML侧保存并使用。
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');
            // 3、另一个消息端口在应用侧注册回调事件。
            this.ports[1].onMessageEvent((result: string) => {
                var msg = 'Got msg from HTML: ' + result;
                this.receivedFromHtml = msg;
              })
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })

      // 4、使用应用侧的端口给另一个已经发送到html的端口发送消息。
      Button('SendDataToHTML')
        .onClick(() => {
          try {
            this.ports[1].postMessageEvent("post message from ets to HTML");
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: $rawfile('xxx.html'), controller: this.controller })
    }
  }
}
```

```html
<!--xxx.html-->
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>WebView Message Port Demo</title>
</head>

  <body>
    <h1>WebView Message Port Demo</h1>
    <div>
        <input type="button" value="SendToEts" onclick="PostMsgToEts(msgFromJS.value);"/><br/>
        <input id="msgFromJs" type="text" value="send this message from HTML to ets"/><br/>
    </div>
    <p class="output">display received message send from ets</p>
  </body>
  <script src="xxx.js"></script>
</html>
```

```js
//xxx.js
var h5Port;
var output = document.querySelector('.output');
window.addEventListener('message', function (event) {
    if (event.data == '__init_port__') {
        if (event.ports[0] != null) {
            h5Port = event.ports[0]; // 1. 保存从ets侧发送过来的端口
            h5Port.onmessage = function (event) {
              // 2. 接收ets侧发送过来的消息.
              var msg = 'Got message from ets:' + event.data;
              output.innerHTML = msg;
            }
        }
    }
})

// 3. 使用h5Port往ets侧发送消息.
function PostMsgToEts(data) {
    h5Port.postMessage(data);
}
```

### requestFocus

requestFocus(): void

使当前web页面获取焦点。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('requestFocus')
        .onClick(() => {
          try {
            this.controller.requestFocus();
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        });
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### zoomIn

zoomIn(): void

调用此接口将当前网页进行放大，比例为20%。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enable.                                         |
| 17100009 | Cannot zoom in or zoom out.                                  |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('zoomIn')
        .onClick(() => {
          try {
            this.controller.zoomIn();
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### zoomOut

zoomOut(): void

调用此接口将当前网页进行缩小，比例为20%。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100004 | Function not enable.                                         |
| 17100009 | Cannot zoom in or zoom out.                                  |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('zoomOut')
        .onClick(() => {
          try {
            this.controller.zoomOut();
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getHitTestValue

getHitTestValue(): HitTestValue

获取当前被点击区域的元素信息。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型         | 说明                 |
| ------------ | -------------------- |
| [HitTestValue](#hittestvalue) | 点击区域的元素信息。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getHitTestValue')
        .onClick(() => {
          try {
            let hitValue = this.controller.getHitTestValue();
            console.log("hitType: " + hitValue.type);
            console.log("extra: " + hitValue.extra);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getWebId

getWebId(): number

获取当前Web组件的索引值，用于多个Web组件的管理。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                  |
| ------ | --------------------- |
| number | 当前Web组件的索引值。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getWebId')
        .onClick(() => {
          try {
            let id = this.controller.getWebId();
            console.log("id: " + id);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getUserAgent

getUserAgent(): string

获取当前默认用户代理。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| string | 默认用户代理。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getUserAgent')
        .onClick(() => {
          try {
            let userAgent = this.controller.getUserAgent();
            console.log("userAgent: " + userAgent);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getTitle

getTitle(): string

获取文件选择器标题。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 返回文件选择器标题。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例:**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getTitle')
        .onClick(() => {
          try {
            let title = this.controller.getTitle();
            console.log("title: " + title);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getPageHeight

getPageHeight(): number

获取当前网页的页面高度。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 当前网页的页面高度。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例:**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getPageHeight')
        .onClick(() => {
          try {
            let pageHeight = this.controller.getPageHeight();
            console.log("pageHeight : " + pageHeight);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### storeWebArchive

storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void

以回调方式异步保存当前页面。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 参数类型              | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| baseName | string                | 是   | 文件存储路径，该值不能为空。                                 |
| autoName | boolean               | 是   | 决定是否自动生成文件名。 如果为false，则将baseName作为文件存储路径。 如果为true，则假定baseName是一个目录，将根据当前页的Url自动生成文件名。 |
| callback | AsyncCallback\<string> | 是   | 返回文件存储路径，保持网页失败会返回null。                   |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('saveWebArchive')
        .onClick(() => {
          try {
            this.controller.storeWebArchive("/data/storage/el2/base/", true, (error, filename) => {
              if (error) {
                console.info(`save web archive error: ` + JSON.stringify(error))
                return;
              }
              if (filename != null) {
                console.info(`save web archive success: ${filename}`)
              }
            });
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### storeWebArchive

storeWebArchive(baseName: string, autoName: boolean): Promise\<string>

以Promise方式异步保存当前页面。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 参数类型 | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| baseName | string   | 是   | 文件存储路径，该值不能为空。                                 |
| autoName | boolean  | 是   | 决定是否自动生成文件名。 如果为false，则将baseName作为文件存储路径。 如果为true，则假定baseName是一个目录，将根据当前页的Url自动生成文件名。 |

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<string> | Promise实例，保存成功返回文件路径，保存失败返回null。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100003 | Invalid resource path or file type.                          |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('saveWebArchive')
        .onClick(() => {
          try {
            this.controller.storeWebArchive("/data/storage/el2/base/", true)
              .then(filename => {
                if (filename != null) {
                  console.info(`save web archive success: ${filename}`)
                }
              })
              .catch(error => {
                console.log('error: ' + JSON.stringify(error));
              })
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getUrl

getUrl(): string

获取当前页面的url地址。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型   | 说明                |
| ------ | ------------------- |
| string | 当前页面的url地址。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getUrl')
        .onClick(() => {
          try {
            let url = this.controller.getUrl();
            console.log("url: " + url);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### stop

stop(): void

停止页面加载。

**系统能力：**
SystemCapability.Web.Webview.Core

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('stop')
        .onClick(() => {
          try {
            this.controller.stop();
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        });
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### backOrForward

backOrForward(step: number): void

按照历史栈，前进或者后退指定步长的页面，当历史栈中不存在对应步长的页面时，不会进行页面跳转。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述               |
| ------ | -------- | ---- | ------ | ---------------------- |
| step   | number   | 是   | -      | 需要前进或后退的步长。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17100001 | Init error. The WebviewController must be associated with a Web component. |
| 17100007 | Invalid back or forward operation. |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  @State step: number = -2;

  build() {
    Column() {
      Button('backOrForward')
        .onClick(() => {
          try {
            this.controller.backOrForward(this.step);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebCookieManager

通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有web组件共享一个WebCookieManager实例。

###  getCookie

static getCookie(url: string): string

获取指定url对应cookie的值。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 默认值 | 说明                      |
| ------ | ------ | ---- | ------ | :------------------------ |
| url    | string | 是   | -      | 要获取的cookie所属的url。 |

**返回值：** 

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 指定url对应的cookie的值。 |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)
| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getCookie')
        .onClick(() => {
          try {
            let value = web_webview.WebCookieManager.getCookie('www.example.com');
            console.log("value: " + value);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  setCookie

static setCookie(url: string, value: string): void

为指定url设置单个cookie的值。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 默认值 | 说明                      |
| ------ | ------ | ---- | ------ | :------------------------ |
| url    | string | 是   | -      | 要设置的cookie所属的url。 |
| value  | string | 是   | -      | 要设置的cookie的值。      |

**错误码**：

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | Invalid url.                                           |
| 17100005 | Invaild cookie value.                                  |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('setCookie')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.setCookie('www.example.com', 'a=b');
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  saveCookieAsync

static saveCookieAsync(callback: AsyncCallback\<void>): void

将当前存在内存中的cookie异步保存到磁盘中。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 默认值 | 说明                                               |
| -------- | ---------------------- | ---- | ------ | :------------------------------------------------- |
| callback | AsyncCallback\<void> | 是   | -      | 返回cookie是否成功保存的布尔值作为回调函数的入参。 |


**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('saveCookieAsync')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.saveCookieAsync((error) => {
              if (error) {
                console.log("error: " + error);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  saveCookieAsync

static saveCookieAsync(): Promise\<void>

将当前存在内存中的cookie以Promise方法异步保存到磁盘中。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：** 

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise实例，用于获取cookie是否成功保存。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('saveCookieAsync')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.saveCookieAsync()
              .then(() => {
                console.log("saveCookieAsyncCallback success!");
              })
              .catch((error) => {
                console.error("error: " + error);
              });
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  putAcceptCookieEnabled

static putAcceptCookieEnabled(accept: boolean): void

设置WebCookieManager实例是否拥有发送和接收cookie的权限。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 默认值 | 说明                                 |
| ------ | ------- | ---- | ------ | :----------------------------------- |
| accept | boolean | 是   | -      | 设置是否拥有发送和接收cookie的权限。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('putAcceptCookieEnabled')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.putAcceptCookieEnabled(false);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  isCookieAllowed

static isCookieAllowed(): boolean

获取WebCookieManager实例是否拥有发送和接收cookie的权限。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：** 

| 类型    | 说明                             |
| ------- | -------------------------------- |
| boolean | 是否拥有发送和接收cookie的权限，默认为true。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('isCookieAllowed')
        .onClick(() => {
          let result = web_webview.WebCookieManager.isCookieAllowed();
          console.log("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  putAcceptThirdPartyCookieEnabled

static putAcceptThirdPartyCookieEnabled(accept: boolean): void

设置WebCookieManager实例是否拥有发送和接收第三方cookie的权限。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 默认值 | 说明                                       |
| ------ | ------- | ---- | ------ | :----------------------------------------- |
| accept | boolean | 是   | -      | 设置是否拥有发送和接收第三方cookie的权限。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('putAcceptThirdPartyCookieEnabled')
        .onClick(() => {
          try {
            web_webview.WebCookieManager.putAcceptThirdPartyCookieEnabled(false);
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  isThirdPartyCookieAllowed

static isThirdPartyCookieAllowed(): boolean

获取WebCookieManager实例是否拥有发送和接收第三方cookie的权限。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：** 

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | 是否拥有发送和接收第三方cookie的权限，默认为false。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('isThirdPartyCookieAllowed')
        .onClick(() => {
          let result = web_webview.WebCookieManager.isThirdPartyCookieAllowed();
          console.log("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  existCookie

static existCookie(): boolean

获取是否存在cookie。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：** 

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | 是否拥有发送和接收第三方cookie的权限。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('existCookie')
        .onClick(() => {
          let result = web_webview.WebCookieManager.existCookie();
          console.log("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  deleteEntireCookie

static deleteEntireCookie(): void

清除所有cookie。

**系统能力：**
SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteEntireCookie')
        .onClick(() => {
          web_webview.WebCookieManager.deleteEntireCookie();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

###  deleteSessionCookie

static deleteSessionCookie(): void

清除所有会话cookie。

**系统能力：**
SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview'

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteSessionCookie')
        .onClick(() => {
          web_webview.WebCookieManager.deleteSessionCookie();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## WebStorage

通过WebStorage可管理Web SQL数据库接口和HTML5 Web存储接口，每个应用中的所有Web组件共享一个WebStorage。

### deleteOrigin

static deleteOrigin(origin : string): void

清除指定源所使用的存储。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 默认值 | 说明                     |
| ------ | ------ | ---- | ------ | ------------------------ |
| origin | string | 是   | -      | 指定源的字符串索引. |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('deleteOrigin')
        .onClick(() => {
          try {
            web_webview.WebStorage.deleteOrigin(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOrigins

static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>) : void

以回调方式异步获取当前使用Web SQL数据库的所有源的信息。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 默认值 | 说明                                                   |
| -------- | -------------------------------------- | ---- | ------ | ------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[WebStorageOrigin](#webstorageorigin)>> | 是   | -      | 以数组方式返回源的信息，信息内容参考[WebStorageOrigin](#webstorageorigin)。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getOrigins')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOrigins((error, origins) => {
              if (error) {
                console.log('error: ' + error);
                return;
              }
              for (let i = 0; i < origins.length; i++) {
                console.log('origin: ' + origins[i].origin);
                console.log('usage: ' + origins[i].usage);
                console.log('quota: ' + origins[i].quota);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOrigins

static getOrigins() : Promise\<Array\<WebStorageOrigin>>

以Promise方式异步获取当前使用Web SQL数据库的所有源的信息。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型                             | 说明                                                         |
| -------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[WebStorageOrigin](#webstorageorigin)>> | Promise实例，用于获取当前所有源的信息，信息内容参考[WebStorageOrigin](#webstorageorigin)。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getOrigins')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOrigins()
              .then(origins => {
                for (let i = 0; i < origins.length; i++) {
                  console.log('origin: ' + origins[i].origin);
                  console.log('usage: ' + origins[i].usage);
                  console.log('quota: ' + origins[i].quota);
                }
              })
              .catch(e => {
                console.log('error: ' + e);
              })
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOriginQuota

static getOriginQuota(origin : string, callback : AsyncCallback\<number>) : void

使用callback回调异步获取指定源的Web SQL数据库的存储配额，配额以字节为单位。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                  | 必填 | 默认值 | 说明               |
| -------- | --------------------- | ---- | ------ | ------------------ |
| origin   | string                | 是   | -      | 指定源的字符串索引 |
| callback | AsyncCallback\<number> | 是   | -      | 指定源的存储配额   |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getOriginQuota')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginQuota(this.origin, (error, quota) => {
              if (error) {
                console.log('error: ' + error);
                return;
              }
              console.log('quota: ' + quota);
            })
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOriginQuota

static getOriginQuota(origin : string) : Promise\<number>

以Promise方式异步获取指定源的Web SQL数据库的存储配额，配额以字节为单位。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 默认值 | 说明               |
| ------ | ------ | ---- | ------ | ------------------ |
| origin | string | 是   | -      | 指定源的字符串索引 |

**返回值：**

| 类型            | 说明                                    |
| --------------- | --------------------------------------- |
| Promise\<number> | Promise实例，用于获取指定源的存储配额。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getOriginQuota')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginQuota(this.origin)
              .then(quota => {
                console.log('quota: ' + quota);
              })
              .catch(e => {
                console.log('error: ' + e);
              })
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOriginUsage

static getOriginUsage(origin : string, callback : AsyncCallback\<number>) : void

以回调方式异步获取指定源的Web SQL数据库的存储量，存储量以字节为单位。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                  | 必填 | 默认值 | 说明               |
| -------- | --------------------- | ---- | ------ | ------------------ |
| origin   | string                | 是   | -      | 指定源的字符串索引 |
| callback | AsyncCallback\<number> | 是   | -      | 指定源的存储量。   |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getOriginUsage')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginUsage(this.origin, (error, usage) => {
              if (error) {
                console.log('error: ' + error);
                return;
              }
              console.log('usage: ' + usage);
            })
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### getOriginUsage

static getOriginUsage(origin : string) : Promise\<number>

以Promise方式异步获取指定源的Web SQL数据库的存储量，存储量以字节为单位。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 默认值 | 说明               |
| ------ | ------ | ---- | ------ | ------------------ |
| origin | string | 是   | -      | 指定源的字符串索引 |

**返回值：**

| 类型            | 说明                                  |
| --------------- | ------------------------------------- |
| Promise\<number> | Promise实例，用于获取指定源的存储量。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 17100011 | Invalid permission origin.                            |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getOriginUsage')
        .onClick(() => {
          try {
            web_webview.WebStorage.getOriginUsage(this.origin)
              .then(usage => {
                console.log('usage: ' + usage);
              })
              .catch(e => {
                console.log('error: ' + e);
              })
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }

        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

### deleteAllData

static deleteAllData(): void

清除Web SQL数据库当前使用的所有存储。

**系统能力：**
SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteAllData')
        .onClick(() => {
          try {
            web_webview.WebStorage.deleteAllData();
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

## WebDataBase

web组件数据库管理对象。

### getHttpAuthCredentials

static getHttpAuthCredentials(host: string, realm: string): Array\<string>

检索给定主机和域的HTTP身份验证凭据，该方法为同步方法。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 默认值 | 说明                         |
| ------ | ------ | ---- | ------ | ---------------------------- |
| host   | string | 是   | -      | HTTP身份验证凭据应用的主机。 |
| realm  | string | 是   | -      | HTTP身份验证凭据应用的域。   |

**返回值：**

| 类型  | 说明                                         |
| ----- | -------------------------------------------- |
| Array\<string> | 包含用户名和密码的组数，检索失败返回空数组。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  host: string = "www.spincast.org";
  realm: string = "protected example";
  username_password: string[];

  build() {
    Column() {
      Button('getHttpAuthCredentials')
        .onClick(() => {
          try {
            this.username_password = web_webview.WebDataBase.getHttpAuthCredentials(this.host, this.realm);
            console.log('num: ' + this.username_password.length);
            ForEach(this.username_password, (item) => {
              console.log('username_password: ' + item);
            }, item => item)
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### saveHttpAuthCredentials

static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void

保存给定主机和域的HTTP身份验证凭据，该方法为同步方法。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型   | 必填 | 默认值 | 说明                         |
| -------- | ------ | ---- | ------ | ---------------------------- |
| host     | string | 是   | -      | HTTP身份验证凭据应用的主机。 |
| realm    | string | 是   | -      | HTTP身份验证凭据应用的域。   |
| username | string | 是   | -      | 用户名。                     |
| password | string | 是   | -      | 密码。                       |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  host: string = "www.spincast.org";
  realm: string = "protected example";

  build() {
    Column() {
      Button('saveHttpAuthCredentials')
        .onClick(() => {
          try {
            web_webview.WebDataBase.saveHttpAuthCredentials(this.host, this.realm, "Stromgol", "Laroche");
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### existHttpAuthCredentials

static existHttpAuthCredentials(): boolean

判断是否存在任何已保存的HTTP身份验证凭据，该方法为同步方法。存在返回true，不存在返回false。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 是否存在任何已保存的HTTP身份验证凭据。存在返回true，不存在返回false |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('existHttpAuthCredentials')
        .onClick(() => {
          try {
            let result = web_webview.WebDataBase.existHttpAuthCredentials();
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteHttpAuthCredentials

static deleteHttpAuthCredentials(): void

清除所有已保存的HTTP身份验证凭据，该方法为同步方法。

**系统能力：**
SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteHttpAuthCredentials')
        .onClick(() => {
          try {
            web_webview.WebDataBase.deleteHttpAuthCredentials();
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## GeolocationPermissions

web组件地理位置权限管理对象。

### allowGeolocation

static allowGeolocation(origin: string): void

允许指定来源使用地理位置接口。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 默认值 | 说明               |
| ------ | ------ | ---- | ------ | ------------------ |
| origin | string | 是   | -      | 指定源的字符串索引 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)
| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('allowGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.allowGeolocation(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteGeolocation

static deleteGeolocation(origin: string): void

清除指定来源的地理位置权限状态。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 默认值 | 说明               |
| ------ | ------ | ---- | ------ | ------------------ |
| origin | string | 是   | -      | 指定源的字符串索引 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('deleteGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.deleteGeolocation(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getAccessibleGeolocation

static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void

以回调方式异步获取指定源的地理位置权限状态。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 默认值 | 说明                                                         |
| -------- | ---------------------- | ---- | ------ | ------------------------------------------------------------ |
| origin   | string                 | 是   | -      | 指定源的字符串索引                                           |
| callback | AsyncCallback\<boolean> | 是   | -      | 返回指定源的地理位置权限状态。获取成功，true表示已授权，false表示拒绝访问。获取失败，表示不存在指定源的权限状态。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getAccessibleGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.getAccessibleGeolocation(this.origin, (error, result) => {
              if (error) {
                console.log('getAccessibleGeolocationAsync error: ' + JSON.stringify(error));
                return;
              }
              console.log('getAccessibleGeolocationAsync result: ' + result);
            });
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getAccessibleGeolocation

static getAccessibleGeolocation(origin: string): Promise\<boolean>

以Promise方式异步获取指定源的地理位置权限状态。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述             |
| ------ | -------- | ---- | ------ | -------------------- |
| origin | string   | 是   | -      | 指定源的字符串索引。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise实例，用于获取指定源的权限状态，获取成功，true表示已授权，false表示拒绝访问。获取失败，表示不存在指定源的权限状态。 |

**错误码：**

以下错误码的详细介绍请参见 [webview错误码](../errorcodes/errorcode-webview.md)

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid permission origin.                             |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  origin: string = "file:///";

  build() {
    Column() {
      Button('getAccessibleGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.getAccessibleGeolocation(this.origin)
              .then(result => {
                console.log('getAccessibleGeolocationPromise result: ' + result);
              }).catch(error => {
              console.log('getAccessibleGeolocationPromise error: ' + JSON.stringify(error));
            });
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getStoredGeolocation

static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void

以回调方式异步获取已存储地理位置权限状态的所有源信息。

**系统能力：**
SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                         | 必填 | 默认值 | 说明                                     |
| -------- | ---------------------------- | ---- | ------ | ---------------------------------------- |
| callback | AsyncCallback\<Array\<string>> | 是   | -      | 返回已存储地理位置权限状态的所有源信息。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getStoredGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.getStoredGeolocation((error, origins) => {
              if (error) {
                console.log('getStoredGeolocationAsync error: ' + JSON.stringify(error));
                return;
              }
              let origins_str: string = origins.join();
              console.log('getStoredGeolocationAsync origins: ' + origins_str);
            });
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getStoredGeolocation

static getStoredGeolocation(): Promise\<Array\<string>>

以Promise方式异步获取已存储地理位置权限状态的所有源信息。

**系统能力：**
SystemCapability.Web.Webview.Core

**返回值：**

| 类型                   | 说明                                                      |
| ---------------------- | --------------------------------------------------------- |
| Promise\<Array\<string>> | Promise实例，用于获取已存储地理位置权限状态的所有源信息。 |

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('getStoredGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.getStoredGeolocation()
              .then(origins => {
                let origins_str: string = origins.join();
                console.log('getStoredGeolocationPromise origins: ' + origins_str);
              }).catch(error => {
              console.log('getStoredGeolocationPromise error: ' + JSON.stringify(error));
            });
          } catch (error) {
            console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deleteAllGeolocation

static deleteAllGeolocation(): void

清除所有来源的地理位置权限状态。

**系统能力：**
SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  build() {
    Column() {
      Button('deleteAllGeolocation')
        .onClick(() => {
          try {
            web_webview.GeolocationPermissions.deleteAllGeolocation();
          } catch (error) {
            console.error(`ErrorCode: ${error.code}, Message: ${error.message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
## HeaderV9

Web组件返回的请求/响应头对象。

| 名称        | 类型   | 说明                 |
| ----------- | ------ | :------------------- |
| headerKey   | string | 请求/响应头的key。   |
| headerValue | string | 请求/响应头的value。 |

## HitTestTypeV9

| 名称          | 描述                                      |
| ------------- | ----------------------------------------- |
| EditText      | 可编辑的区域。                            |
| Email         | 电子邮件地址。                            |
| HttpAnchor    | 超链接，其src为http。                     |
| HttpAnchorImg | 带有超链接的图片，其中超链接的src为http。 |
| Img           | HTML::img标签。                           |
| Map           | 地理地址。                                |
| Phone           | 电话号码。                                |
| Unknown       | 未知内容。                                |

##  HitTestValue

提供点击区域的元素信息。示例代码参考getHitTestValue。

| 名称  | 类型          | 说明                                                         |
| ----- | ------------- | :----------------------------------------------------------- |
| type  | [HitTestTypeV9](#hittesttypev9) | 当前被点击区域的元素类型。                                   |
| extra | string        | 点击区域的附加参数信息。若被点击区域为图片或链接，则附加参数信息为其url地址。 |

## WebStorageOrigin

提供Web SQL数据库的使用信息。

**系统能力：**
SystemCapability.Web.Webview.Core

| 名称   | 类型   | 必填 | 说明                 |
| ------ | ------ | :--- | -------------------- |
| origin | string | 是   | 指定源的字符串索引。 |
| usage  | number | 是   | 指定源的存储量。     |
| quota  | number | 是   | 指定源的存储配额。   |