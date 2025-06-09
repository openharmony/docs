# 组件描述

提供具有网页显示能力的Web组件，[@ohos.web.webview](arkts-apis-webview.md)提供web控制能力。

> **说明：**
>
> - 该组件从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

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
| value        | [WebOptions](./arkts-basic-components-web-i.md#weboptions)   | 是    | 定义Web选项。 |

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