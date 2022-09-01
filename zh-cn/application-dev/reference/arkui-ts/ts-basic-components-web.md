# Web

提供具有网页显示能力的Web组件。

> **说明：** 
>
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表
访问在线网页时需添加网络权限：ohos.permission.INTERNET

## 子组件

无

## 接口

Web(options: { src: ResourceStr, controller: WebController })

表1 options参数说明

**参数：**
| 参数名     | 参数类型                                | 必填 | 默认值 | 参数描述       |
| ---------- | --------------------------------------- | ---- | ------ | -------------- |
| src        | [ResourceStr](ts-types.md#resourcestr8) | 是   | -      | 网页资源地址。 |
| controller | [WebController](#webcontroller)         | 否   | -      | 控制器。       |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
      }
    }
  }
  ```

> **说明：**
>
> - 不支持转场动画；
> - 不支持多实例；
> - 仅支持本地音视频播放。

## 属性

web组件的网络属性。

### domStorageAccess

domStorageAccess(domStorageAccess: boolean)

设置是否开启文档对象模型存储接口（DOM Storage API）权限，默认未开启。

**参数：**
| 参数名              | 参数类型    | 必填   | 默认值  | 参数描述                                 |
| ---------------- | ------- | ---- | ---- | ------------------------------------ |
| domStorageAccess | boolean | 是    | false    | 设置是否开启文档对象模型存储接口（DOM Storage API）权限。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .domStorageAccess(true)
      }
    }
  }
  ```

### fileAccess

fileAccess(fileAccess: boolean)

设置是否开启应用中文件系统的访问，默认启用。[$rawfile(filepath/filename)](../../ui/ts-resource-access.md)中rawfile路径的文件不受该属性影响而限制访问。

**参数：**
| 参数名        | 参数类型    | 必填   | 默认值  | 参数描述                                     |
| ---------- | ------- | ---- | ---- | ---------------------------------------- |
| fileAccess | boolean | 是    | true | 设置是否开启应用中文件系统的访问，默认启用。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
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
| imageAccess | boolean | 是    | true    | 设置是否允许自动加载图片资源。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .imageAccess(true)
      }
    }
  }
  ```

### javaScriptProxy

javaScriptProxy(javaScriptProxy: { object: object, name: string, methodList: Array\<string\>,
    controller: WebController })

注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。所有参数不支持更新。

**参数：**
| 参数名        | 参数类型            | 必填   | 默认值  | 参数描述                      |
| ---------- | --------------- | ---- | ---- | ------------------------- |
| object     | object          | 是    | -    | 参与注册的对象。只能声明方法，不能声明属性。    |
| name       | string          | 是    | -    | 注册对象的名称，与window中调用的对象名一致。 |
| methodList | Array\<string\> | 是    | -    | 参与注册的应用侧JavaScript对象的方法。  |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    testObj = {
      test: (data1, data2, data3) => {
        console.log("data1:" + data1);
        console.log("data2:" + data2);
        console.log("data3:" + data3);
        return "AceString";
      },
      toString: () => {
        console.log('toString' + "interface instead.");
      }
    }
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
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
| javaScriptAccess | boolean | 是    | true    | 是否允许执行JavaScript脚本。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .javaScriptAccess(true)
      }
    }
  }
  ```

### mixedMode

mixedMode(mixedMode: MixedMode)

设置是否允许加载超文本传输协议（HTTP）和超文本传输安全协议（HTTPS）混合内容，默认不允许加载HTTP和HTTPS混合内容。

**参数：**
| 参数名       | 参数类型                        | 必填   | 默认值  | 参数描述      |
| --------- | --------------------------- | ---- | ---- | --------- |
| mixedMode | [MixedMode](#mixedmode枚举说明) | 是    | None     | 要设置的混合内容。 |

**示例：**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    @State mode:MixedMode = MixedMode.All;
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .mixedMode(this.mode)
      }
    }
  }
  ```

onlineImageAccess(onlineImageAccess: boolean)

设置是否允许从网络加载图片资源（通过HTTP和HTTPS访问的资源），默认允许访问。

**参数：**
| 参数名               | 参数类型    | 必填   | 默认值  | 参数描述             |
| ----------------- | ------- | ---- | ---- | ---------------- |
| onlineImageAccess | boolean | 是    | true    | 设置是否允许从网络加载图片资源。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
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
| zoomAccess | boolean | 是    | true    | 设置是否支持手势进行缩放。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
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
| overviewModeAccess | boolean | 是    | true    | 设置是否使用概览模式加载网页。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .overviewModeAccess(true)
      }
    }
  }
  ```

### databaseAccess

databaseAccess(databaseAccess: boolean)

设置是否开启数据库存储API权限，默认不开启。

**参数：**
| 参数名            | 参数类型    | 必填   | 默认值  | 参数描述              |
| -------------- | ------- | ---- | ---- | ----------------- |
| databaseAccess | boolean | 是    | false    | 设置是否开启数据库存储API权限。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .databaseAccess(true)
      }
    }
  }
  ```

### geolocationAccess

geolocationAccess(geolocationAccess: boolean)

设置是否开启获取地理位置权限，默认开启。

**参数：**
| 参数名            | 参数类型    | 必填   | 默认值  | 参数描述              |
| -------------- | ------- | ---- | ---- | ----------------- |
| geolocationAccess | boolean | 是    | true    | 设置是否开启获取地理位置权限。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .geolocationAccess(true)
      }
    }
  }
  ```

### cacheMode

cacheMode(cacheMode: CacheMode)

设置缓存模式。

**参数：**
| 参数名       | 参数类型                        | 必填   | 默认值  | 参数描述      |
| --------- | --------------------------- | ---- | ---- | --------- |
| cacheMode | [CacheMode](#cachemode枚举说明) | 是    | -    | 要设置的缓存模式。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    @State mode:CacheMode = CacheMode.None;
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .cacheMode(this.mode)
      }
    }
  }
  ```

### textZoomAtio

textZoomAtio(textZoomAtio: number)

设置页面的文本缩放百分比，默认为100%。

**参数：**
| 参数名          | 参数类型   | 必填   | 默认值  | 参数描述            |
| ------------ | ------ | ---- | ---- | --------------- |
| textZoomAtio | number | 是    | 100    | 要设置的页面的文本缩放百分比。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    @State atio:number = 150;
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .textZoomAtio(this.atio)
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
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    @State userAgent:string = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.71 Safari/537.36';
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
        .userAgent(this.userAgent)
      }
    }
  }
  ```

>  **说明：**
>
>  通用属性仅支持[width](ts-universal-attributes-size.md#属性)、[height](ts-universal-attributes-size.md#属性)、[padding](ts-universal-attributes-size.md#属性)、[margin](ts-universal-attributes-size.md#属性)、[border](ts-universal-attributes-border.md#属性)。

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
| boolean | 当回调返回false时，触发默认弹窗。当回调返回true时，系统应用可以调用系统弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller:WebController = new WebController();
    build() {
      Column() {
        Web({ src:'www.example.com', controller:this.controller })
          .onAlert((event) => {
            AlertDialog.show({
              title: 'title',
              message: 'text',
              confirm: {
                value: 'onAlert',
                action: () => {
                  event.result.handleConfirm()
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true;
          })
      }
    }
  }
  ```

### onBeforeUnload

onBeforeUnload(callback: (event?: { url: string; message: string; result: JsResult }) => boolean)

刷新或关闭场景下，在即将离开当前页面时触发此回调。

**参数：**
| 参数名     | 参数类型                  | 参数描述            |
| ------- | --------------------- | --------------- |
| url     | string                | 当前显示弹窗所在网页的URL。 |
| message | string                | 弹窗中显示的信息。       |
| result  | [JsResult](#jsresult) | 通知Web组件用户操作行为。  |

**返回值：**
| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 当回调返回false时，触发默认弹窗。当回调返回true时，系统应用可以调用系统弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件最终是否离开当前页面。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onBeforeUnload((event) => {
            console.log("event.url:" + event.url);
            console.log("event.message:" + event.message);
            console.log("event.result:" + event.result);
            return false;
          })
      }
    }
  }
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
| boolean | 当回调返回false时，触发默认弹窗。当回调返回true时，系统应用可以调用系统弹窗能力（包括确认和取消），并且需要根据用户的确认或取消操作调用JsResult通知Web组件。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onConfirm((event) => {
            console.log("event.url:" + event.url);
            console.log("event.message:" + event.message);
            console.log("event.result:" + event.result);
            AlertDialog.show({
              title: 'title',
              message: 'text',
              confirm: {
                value: 'onConfirm',
                action: () => {
                  event.result.handleConfirm()
                }
              },
              cancel: () => {
                event.result.handleCancel()
              }
            })
            return true;
          })
      }
    }
  }
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
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onConsole((event) => {
            console.log('getMessage:' + event.message.getMessage());
            console.log('getSourceId:' + event.message.getSourceId());
            console.log('getLineNumber:' + event.message.getLineNumber());
            console.log('getMessageLevel:' + event.message.getMessageLevel());
            return false;
          })
      }
    }
  }
  ```

### onDownloadStart

onDownloadStart(callback: (event?: { url: string, userAgent: string, contentDisposition: string, mimetype: string, contentLength: number }) => void)

**参数：**
| 参数名                | 参数类型          | 参数描述                                |
| ------------------ | ------------- | ----------------------------------- |
| url                | string        | 文件下载的URL。                           |
| contentDisposition | string        | 服务器返回的 Content-Disposition响应头，可能为空。 |
| mimetype           | string        | 服务器返回内容媒体类型（MIME）信息。                |
| contentLength      | contentLength | 服务器返回文件的长度。                         |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onDownloadStart((event) => {
            console.log('url:' + event.url);
            console.log('userAgent:' + event.userAgent);
            console.log('contentDisposition:' + event.contentDisposition);
            console.log('contentLength:' + event.contentLength);
            console.log('mimetype:' + event.mimetype);
          })
      }
    }
  }
  ```

### onErrorReceive

onErrorReceive(callback: (event?: { request: WebResourceRequest, error: WebResourceError }) => void)

网页加载遇到错误时触发该回调。出于性能考虑，建议此回调中尽量执行简单逻辑。

**参数：**
| 参数名     | 参数类型                                     | 参数描述            |
| ------- | ---------------------------------------- | --------------- |
| request | [WebResourceRequest](#webresourcerequest) | 网页请求的封装信息。      |
| error   | [WebResourceError](#webresourceerror)    | 网页加载资源错误的封装信息 。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onErrorReceive((event) => {
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
| error   | [WebResourceError](#webresourceerror)    | 网页加载资源错误的封装信息 。 |

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onHttpErrorReceive((event) => {
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
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onPageBegin((event) => {
            console.log('url:' + event.url);
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
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onPageEnd((event) => {
            console.log('url:' + event.url);
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
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
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
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
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

onRefreshAccessedHistory(callback: (event?: { url: string, refreshed: boolean }) => void)

加载网页页面完成时触发该回调，用于应用更新其访问的历史链接。

**参数：**
| 参数名         | 参数类型    | 参数描述                              |
| ----------- | ------- | --------------------------------- |
| url         | string  | 访问的url。                           |
| refreshed | boolean | true表示该页面是被重新加载的，false表示该页面是新加载的。 |

  **示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onRefreshAccessedHistory((event) => {
            console.log('url:' + event.url + ' isReload:' + event.refreshed);
          })
      }
    }
  }
  ```

### onUrlLoadIntercept

onUrlLoadIntercept(callback: (event?: { data:string | WebResourceRequest }) => boolean)

当Web组件加载url之前触发该回调，用于是否阻止此次访问。

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
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onUrlLoadIntercept((event) => {
            console.log('onUrlLoadIntercept ' + event.data.toString())
            return true;
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

## WebController

通过WebController可以控制Web组件各种行为。一个WebController对象只能控制一个Web组件，且必须在Web组件和WebController绑定后，才能调用WebController上的方法。

### 创建对象

```
webController: WebController = new WebController()
```

### accessBackward

accessBackward(): boolean

当前页面是否可后退，即当前页面是否有返回历史记录。

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
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('accessBackward')
          .onClick(() => {
            let result = this.controller.accessBackward();
            console.log('result:' + result);
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessForward

accessForward(): boolean

当前页面是否可前进，即当前页面是否有前进历史记录。

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
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('accessForward')
          .onClick(() => {
            let result = this.controller.accessForward();
            console.log('result:' + result);
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessStep

accessStep(step: number): boolean

当前页面是否可前进或者后退给定的step步。

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
    controller: WebController = new WebController();
    @State steps: number = 2;
  
    build() {
      Column() {
        Button('accessStep')
          .onClick(() => {
            let result = this.controller.accessStep(this.steps);
            console.log('result:' + result);
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### backward

backward(): void

按照历史栈，后退一个页面。一般结合accessBackward一起使用。

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('backward')
          .onClick(() => {
            this.controller.backward();
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### forward

forward(): void

按照历史栈，前进一个页面。一般结合accessForward一起使用。

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('forward')
          .onClick(() => {
            this.controller.forward();
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteJavaScriptRegister

deleteJavaScriptRegister(name: string)

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。删除后立即生效，无须调用[refresh](#refresh)接口。

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
    controller: WebController = new WebController();
    @State name: string = 'Object';
  
    build() {
      Column() {
        Button('deleteJavaScriptRegister')
          .onClick(() => {
            this.controller.deleteJavaScriptRegister(this.name);
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getHitTest

getHitTest(): HitTestType

获取当前被点击区域的元素类型。	

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
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('getHitTest')
          .onClick(() => {
            let hitType = this.controller.getHitTest();
            console.log("hitType: " + hitType);
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### requestFocus

requestFocus()

使当前web页面获取焦点。

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('requestFocus')
          .onClick(() => {
            this.controller.requestFocus();
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### loadData

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string })

baseUrl为空时，通过”data“协议加载指定的一段字符串。

当baseUrl为”data“协议时，编码后的data字符串将被Web组件作为”data"协议加载。

当baseUrl为“http/https"协议时，编码后的data字符串将被Web组件以类似loadUrl的方式以非编码字符串处理。

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
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('loadData')
          .onClick(() => {
            this.controller.loadData({
              data: "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>",
              mimeType: "text/html",
              encoding: "UTF-8"
            });
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### loadUrl

loadUrl(options: { url: string | Resource, headers?: Array\<Header\> })

使用指定的http头加载指定的URL。

通过loadUrl注入的对象只在当前document有效，即通过loadUrl导航到新的页面会无效。

而通过registerJavaScriptProxy注入的对象，在loadUrl导航到新的页面也会有效。

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
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('loadUrl')
          .onClick(() => {
            this.controller.loadUrl({ url: 'www.example.com' });
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### onActive

onActive(): void

调用此接口通知Web组件进入前台激活状态。

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('onActive')
          .onClick(() => {
            this.controller.onActive();
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### onInactive

onInactive(): void

调用此接口通知Web组件进入未激活状态。

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('onInactive')
          .onClick(() => {
            this.controller.onInactive();
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### refresh

refresh()

调用此接口通知Web组件刷新网页。

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('refresh')
          .onClick(() => {
            this.controller.refresh();
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### registerJavaScriptProxy

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> })

注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。注册后，须调用[refresh](#refresh)接口生效。

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
        return "ArkUI Web Component";
      },
      toString: () => {
        console.log('Web Component toString');
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
            });
          })
        }
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .javaScriptAccess(true)
      }
    }
  }
  ```

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
          str = objName.test("test function");
          console.log('objName.test result:'+ str);
      }
  </script>
  </html>
  
  ```

### runJavaScript

runJavaScript(options: { script: string, callback?: (result: string) => void })

异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。

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
    controller: WebController = new WebController();
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
            }});
          console.info('url: ', e.url);
        })
      }
    }
  }
  ```

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
        console.log('Ark WebComponent');
        return "This value is from index.html"
    }
    </script>
  </html>

  ```

### stop

stop()

停止页面加载。

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('stop')
          .onClick(() => {
            this.controller.stop();
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### zoom
zoom(factor: number): void

调整当前网页的缩放比例。

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
    controller: WebController = new WebController();
    @State factor: number = 1;
  
    build() {
      Column() {
        Button('zoom')
          .onClick(() => {
            this.controller.zoom(this.factor);
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### clearHistory

clearHistory(): void

删除所有前进后退记录。

**示例：**
  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
  
    build() {
      Column() {
        Button('clearHistory')
          .onClick(() => {
            this.controller.clearHistory();
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

## MessageLevel枚举说明

| 名称    | 描述    |
| ----- | :---- |
| Debug | 调试级别。 |
| Error | 错误级别。 |
| Info  | 消息级别。 |
| Log   | 日志级别。 |
| Warn  | 警告级别。 |

## MixedMode枚举说明

| 名称         | 描述                                 |
| ---------- | ---------------------------------- |
| All        | 允许加载HTTP和HTTPS混合内容。所有不安全的内容都可以被加载。 |
| Compatible | 混合内容兼容性模式，部分不安全的内容可能被加载。           |
| None       | 不允许加载HTTP和HTTPS混合内容。               |


## CacheMode枚举说明
| 名称      | 描述                                   |
| ------- | ------------------------------------ |
| None    | 加载资源使用cache，如果cache中无该资源则从网络中获取。     |
| Online  | 加载资源不使用cache，全部从网络中获取。               |
| Only    | 只从cache中加载资源。                        |

 ## HitTestType枚举说明

| 名称          | 描述                                      |
| ------------- | ----------------------------------------- |
| EditText      | 可编辑的区域。                            |
| Email         | 电子邮件地址。                            |
| HttpAnchor    | 超链接，其src为http。                     |
| HttpAnchorImg | 带有超链接的图片，其中超链接的src为http。 |
| Img           | HTML::img标签。                           |
| Map           | 地理地址。                                |
| Unknown       | 未知内容。                                |