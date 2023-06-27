# Web Subsystem Changelog

Compared with earlier versions, OpenHarmony 4.0.2.2 has the following API changes in its web subsystem:

## cl.web.1 Removal of webDebuggingAccess

The definition of the **webDebuggingAccess** API is inappropriate. This API should take effect for all **Web** instances. In light of this, it is removed and replaced by the new API **setWebDebuggingAccess**.

**Change Impacts**

This API must be deprecated and replaced with the **setWebDebuggingAccess** API.

**Key API/Component Changes**

| Class| API Type| Declaration| Change Type|
|  -- | -- | -- | -- |
|WebAttribute | method | webDebugggingAccess(webDebugggingAccess: boolean): WebAttribute| Deleted |

**Adaptation Guide**

Use the new API **setWebDebuggingAccess**.

## cl.web.2 Adding of setWebDebuggingAccess

Added the static API **setWebDebuggingAccess** to **WebviewController**. It sets whether to enable web debugging works for all **Web** instances.

**Change Impacts**

The original **webDebugggingAccess** API must be replaced with the new API in the application.

**Key API/Component Changes**

| Class| API Type| Declaration| Change Type|
|  -- | -- | -- | -- |
|webview.WebviewController | method | static setWebDebugggingAccess(webDebugggingAccess: boolean): void| Added|

**Adaptation Guide**

The following exemplifies how to enable web debugging:

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
