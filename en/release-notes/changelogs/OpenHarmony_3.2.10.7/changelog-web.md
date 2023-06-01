# Web Subsystem Changelog

Compared with earlier versions, OpenHarmony 3.2.10.7 has the following API changes in its web subsystem:

## cl.web.1 HitTestTypeV9 Name Change

Renamed the enum class **HitTestTypeV9** **WebHitTestType** to meet the naming conventions.

**Change Impact**

The enum class **HitTestTypeV9** and APIs that use **HitTestTypeV9** as a parameter or return value cannot be used in OpenHarmony 3.2.10.7 and later versions.

**Key API/Component Changes**

- Involved APIs:

  enum HitTestTypeV9

- Before change:

  ```ts
  enum HitTestTypeV9
  ```

- After change:

  ```ts
  enum WebHitTestType
  ```

**Adaptation Guide**

Replace **HitTestTypeV9** with **WebHitTestType**.

## cl.web.2 HeaderV9 Name Change

Renamed the struct **HeaderV9** **WebHeader** to meet the naming conventions.

**Change Impact**

The struct **HeaderV9** and APIs that use **HeaderV9** as a parameter or return value cannot be used in OpenHarmony 3.2.10.7 and later versions.

**Key API/Component Changes**

- Involved APIs:

  interface HeaderV9

- Before change:

  ```ts
  interface HeaderV9
  ```

- After change:

  ```ts
  interface WebHeader
  ```

**Adaptation Guide**

Replace **HeaderV9** with **WebHeader**.

## cl.web.3 Member Change of HitTestValue

Rename the member variable **HitTestTypeV9** in the **HitTestValue** struct **WebHitTestType** to meet the naming conventions.

**Change Impact**

The struct **HitTestValue** and APIs that use **HitTestValue** as a parameter or return value cannot be used in OpenHarmony 3.2.10.7 and later versions.

**Key API/Component Changes**

- Involved APIs:

  interface HitTestValue

- Before change:

  ```ts
  interface HitTestValue {

    /**
      * Get the hit test type.
      *
      * @since 9
      */
    type: HitTestTypeV9;

    /**
      * Get the hit test extra data.
      *
      * @since 9
      */
    extra: string;
  }
  ```

- After change:

  ```ts
  interface HitTestValue {

    /**
      * Get the hit test type.
      *
      * @since 9
      */
    type: WebHitTestType;

    /**
      * Get the hit test extra data.
      *
      * @since 9
      */
    extra: string;
  }
  ```

**Adaptation Guide**

Replace **HitTestTypeV9** with **WebHitTestType**.

## cl.web.4 Parameter Type Change of loadUrl

Changed the type of the **headers** parameter in **loadUrl** to **WebHeader** to meet the naming conventions.

**Change Impact**

The **loadUrl** API that uses the **headers** parameter cannot be used in OpenHarmony 3.2.10.7 and later versions.

**Key API/Component Changes**

- Involved APIs:

  loadUrl(url: string | Resource, headers?: Array\<HeaderV9>): void

- Before change:

  ```ts
  loadUrl(url: string | Resource, headers?: Array<HeaderV9>): void
  ```

- After change:

  ```ts
  loadUrl(url: string | Resource, headers?: Array<WebHeader>): void
  ```

**Adaptation Guide**

Change the type of the **headers** parameter in **loadUrl** from **HeaderV9** to **WebHeader**.

## cl.web.5 Return Value Type Change of getHitTest

Changed the return value type of the **getHitTest** API to **WebHitTest** to meet the naming conventions.

**Change Impact**

The **getHitTest** API cannot be used in OpenHarmony 3.2.10.7 and later versions.

**Key API/Component Changes**

- Involved APIs:

  getHitTest(): HitTestTypeV9

- Before change:

  ```ts
  getHitTest(): HitTestTypeV9
  ```

- After change:

  ```ts
  getHitTest(): WebHitTestType
  ```

**Adaptation Guide**

Change the return value type of the **getHitTest** API from **HitTestTypeV9** to **WebHitTestType**.

## cl.web.6 Moving of the WebMessagePort Class

Moved the **WebMessagePort** class to **@ohos.web.webview.d.ts** and added error throwing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed. In addition, be mindful of the error codes now that the APIs in the class support error code processing.

**Key API/Component Changes**

- Involved APIs:

  postMessageEvent(message: WebMessageEvent): void;
  onMessageEvent(callback: (result: string) => void): void;

- Before change:

  ```ts
  postMessageEvent(message: WebMessageEvent): void;
  onMessageEvent(callback: (result: string) => void): void;
  ```

- After change:

  ```ts
  postMessageEvent(message: WebMessage): void;
  onMessageEvent(callback: (result: WebMessage) => void): void;
  ```

**Adaptation Guide**

Instead of importing APIs from the original **WebMessagePort** class, import APIs from **@ohos.web.webview** as follows:

  ```ts
  import web_webview from '@ohos.web.webview';
  ```

## cl.web.7 Moving of the HitTestValue Class

Moved the **HitTestValue** class to **@ohos.web.webview.d.ts**; changed **HitTestValue** from a class to an API; changed the **getType** and **getExtra** from APIs to attributes.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed.

**Key API/Component Changes**

- Involved APIs:

  getType(): HitTestType;
  getExtra(): string;

- Before change:

  ```ts
  getType(): HitTestType;
  getExtra(): string;
  ```

- After change:

  ```ts
  type: WebHitTestType;
  extra: string;
  ```

**Adaptation Guide**

Instead of importing APIs from the original **HitTestValue** class, import APIs from **@ohos.web.webview** as follows:

  ```ts
  import web_webview from '@ohos.web.webview';
  ```

## cl.web.8 Moving of API Version 9 APIs Under WebCookie

Moved APIs of API version 9 in the **WebCookie** class to **web.webview.webview.WebCookieManager**
and added error throwing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed. In addition, be mindful of the error codes now that the APIs in the class support error code processing.
The APIs in the class are static.

**Key API/Component Changes**

- Involved APIs:

  isCookieAllowed(): boolean;
  isThirdPartyCookieAllowed(): boolean;
  putAcceptCookieEnabled(accept: boolean): void;
  putAcceptThirdPartyCookieEnabled(accept: boolean): void;
  setCookie(url: string, value: string): boolean;
  saveCookieSync(): boolean;
  getCookie(url: string): string;
  existCookie(): boolean;
  deleteEntireCookie(): void;
  deleteSessionCookie(): void;

- Before change:

  ```ts
  isCookieAllowed(): boolean;
  isThirdPartyCookieAllowed(): boolean;
  putAcceptCookieEnabled(accept: boolean): void;
  putAcceptThirdPartyCookieEnabled(accept: boolean): void;
  setCookie(url: string, value: string): boolean;
  saveCookieSync(): boolean;
  getCookie(url: string): string;
  existCookie(): boolean;
  deleteEntireCookie(): void;
  deleteSessionCookie(): void;
  ```

- After change:

  ```ts
  static isCookieAllowed(): boolean;
  static isThirdPartyCookieAllowed(): boolean;
  static putAcceptCookieEnabled(accept: boolean): void;
  static putAcceptThirdPartyCookieEnabled(accept: boolean): void;
  static setCookie(url: string, value: string): void;
  static saveCookieAsync(): Promise<void>;
  static saveCookieAsync(callback: AsyncCallback<void>): void;
  static getCookie(url: string): string;
  static existCookie(): boolean;
  static deleteEntireCookie(): void;
  static deleteSessionCookie(): void;
  ```

**Adaptation Guide**

Instead of importing APIs from the original **WebCookie** class, import APIs from **@ohos.web.webview** as follows:

  ```ts
  import web_webview from '@ohos.web.webview';
  ```

## cl.web.9 Moving of API Version 9 APIs Under WebController

Moved APIs of API version 9 in the **WebController** class to **web.webview.webview.WebviewController** and added error throwing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed. In addition, be mindful of the error codes now that the APIs in the class support error code processing.
The **getDefaultUserAgent** API is renamed **getUserAgent**.

**Key API/Component Changes**

- Involved APIs:

  zoomIn(): boolean;
  zoomOut(): boolean;
  createWebMessagePorts(): Array\<WebMessagePort>;
  postMessage(options: { message: WebMessageEvent, uri: string}): void;
  getHitTestValue(): HitTestValue;
  getWebId(): number;
  getDefaultUserAgent(): string;
  getTitle(): string;
  getPageHeight(): number;
  backOrForward(step: number): void;
  searchAllAsync(searchString: string): void;
  clearMatches(): void;
  searchNext(forward: boolean): void;
  clearSslCache(): void;
  clearClientAuthenticationCache(): void;
  getUrl(): string;

- Before change:

  ```ts
  zoomIn(): boolean;
  zoomOut(): boolean;
  createWebMessagePorts(): Array<WebMessagePort>;
  postMessage(options: { message: WebMessageEvent, uri: string}): void;
  getHitTestValue(): HitTestValue;
  getWebId(): number;
  getDefaultUserAgent(): string;
  getTitle(): string;
  getPageHeight(): number;
  backOrForward(step: number): void;
  searchAllAsync(searchString: string): void;
  clearMatches(): void;
  searchNext(forward: boolean): void;
  clearSslCache(): void;
  clearClientAuthenticationCache(): void;
  getUrl(): string;
  ```

- After change:

  ```ts
  zoomIn(): void;
  zoomOut(): void;
  createWebMessagePorts(): Array<WebMessagePort>;
  postMessage(name: string, ports: Array<WebMessagePort>, uri: string): void;
  getHitTestValue(): HitTestValue;
  getWebId(): number;
  getUserAgent(): string;
  getTitle(): string;
  getPageHeight(): number;
  backOrForward(step: number): void;
  searchAllAsync(searchString: string): void;
  clearMatches(): void;
  searchNext(forward: boolean): void;
  clearSslCache(): void;
  clearClientAuthenticationCache(): void;
  getUrl(): string;
  ```

**Adaptation Guide**

Instead of importing APIs from the original **WebController** class, import APIs from **@ohos.web.webview** as follows:

  ```ts
  import web_webview from '@ohos.web.webview';
  ```

## cl.web.10 Moving of the WebAsyncController Class

Moved the APIs in the **WebAsyncController** class to the **web.webview.webview.WebviewController** class and added error throwing.

**Change Impact**

If your application is developed based on earlier versions, pay attention to error code processing.

**Key API/Component Changes**

- Involved APIs:

  storeWebArchive(baseName: string, autoName: boolean): Promise\<string>;
  storeWebArchive(baseName: string, autoName: boolean, callback : AsyncCallback\<string>): void;

- Before change:

  ```ts
  storeWebArchive(baseName: string, autoName: boolean): Promise<string>;
  storeWebArchive(baseName: string, autoName: boolean, callback : AsyncCallback<string>): void;
  ```

- After change:

  ```ts
  storeWebArchive(baseName: string, autoName: boolean): Promise<string>;
  storeWebArchive(baseName: string, autoName: boolean, callback : AsyncCallback<string>): void;
  ```

**Adaptation Guide**

Example:

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

## cl.web.11 Removal of webDebuggingAccess

The definition of the **webDebuggingAccess** API is inappropriate. This API should take effect for all **Web** instances. In light of this, it is removed and replaced by the new API **setWebDebuggingAccess**.

**Change Impacts**

This API must be deprecated and replaced with the **setWebDebuggingAccess** API.

**Key API/Component Changes**

| Class| API Type| Declaration| Change Type| 
|  -- | -- | -- | -- |
|WebAttribute | method | webDebugggingAccess(webDebugggingAccess: boolean): WebAttribute| Deleted|

**Adaptation Guide**

Use the new API **setWebDebuggingAccess**.

## cl.web.12 Adding of setWebDebuggingAccess

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
```
