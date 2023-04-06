# web子系统ChangeLog

OpenHarmony 4.0.2.2 版本相较于OpenHarmony 之前的版本，web的API变更如下。

## cl.web.1 删除webDebuggingAccess接口

该接口定义不合理,该属性对所有web实例生效的，属于全局配置。用本次新增的接口setWebDebuggingAccess替换。

**变更影响**

该接口删除无法再使用，请使用新增的接口setWebDebuggingAccess替换。

**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 | 
|  -- | -- | -- | -- |
|WebAttribute | method | webDebugggingAccess(webDebugggingAccess: boolean): WebAttribute| 删除 |

**适配指导**

该接口删除无法再使用，请使用新增的接口setWebDebuggingAccess替换。

## cl.web.2 新增setWebDebuggingAccess接口

WebviewController提供静态方法来设置调试模式开关，该设置对所有web实例生效。

**变更影响**

原有webDebugggingAccess属性定义不合理，因此新增该静态接口来设置调试模式开关。应用侧需要使用该接口来打开调试模式开关。

**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 |
|  -- | -- | -- | -- |
|webview.WebviewController | method | static setWebDebugggingAccess(webDebugggingAccess: boolean): void| 新增 |

**适配指导**

以打开调试开关为例，示例代码如下：

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  controller: web_webview.WebviewController = new web_webview.WebviewController();

  aboutToAppear():void {
    try {
      web_webview.WebviewController.setWebDebuggingAccess(true);
    } catch(error) {
      console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
    }
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}