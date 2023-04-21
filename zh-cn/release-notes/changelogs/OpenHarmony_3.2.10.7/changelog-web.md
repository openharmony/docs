# web子系统ChangeLog

OpenHarmony 3.2.10.7 版本相较于OpenHarmony 之前的版本，web的API变更如下。

## cl.web.1 HitTestTypeV9命名变更

枚举类HitTestTypeV9由于命名规范问题，名称变更为WebHitTestType。

**变更影响**

枚举类HitTestTypeV9，以及使用HitTestTypeV9作为参数或返回值的接口，在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  enum HitTestTypeV9

- 变更前：

  ```ts
  enum HitTestTypeV9
  ```

- 变更后：

  ```ts
  enum WebHitTestType
  ```

**适配指导**

请使用WebHitTestType替换HitTestTypeV9。

## cl.web.2 HeaderV9命名变更

结构体HeaderV9由于命名规范问题，名称变更为WebHeader。

**变更影响**

结构体HeaderV9，以及使用HeaderV9作为参数或返回值的接口，在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  interface HeaderV9

- 变更前：

  ```ts
  interface HeaderV9
  ```

- 变更后：

  ```ts
  interface WebHeader
  ```

**适配指导**

请使用WebHeader替换HeaderV9。

## cl.web.3 HitTestValue结构体成员类型变更

结构体HitTestValue中的成员变量HitTestTypeV9由于命名规范问题，名称变更为WebHitTestType。

**变更影响**

结构体HitTestValue，以及使用HitTestValue作为参数或返回值的接口，在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  interface HitTestValue

- 变更前：

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

- 变更后：

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

**适配指导**

请使用WebHitTestType替换HitTestTypeV9。

## cl.web.4 loadUrl参数类型变更

loadUrl接口中的参数headers，由于其类型的命名规范问题，类型变更为WebHeader。

**变更影响**

loadUrl接口若使用了headers参数，则在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  loadUrl(url: string | Resource, headers?: Array<HeaderV9>): void

- 变更前：

  ```ts
  loadUrl(url: string | Resource, headers?: Array<HeaderV9>): void
  ```

- 变更后：

  ```ts
  loadUrl(url: string | Resource, headers?: Array<WebHeader>): void
  ```

**适配指导**

在loadUrl中设置headers参数时，请使用WebHeader类型替换HeaderV9类型。

## cl.web.5 getHitTest返回值类型变更

getHitTest接口中的返回值,由于其类型的命名规范问题，变更为WebHitTest。

**变更影响**

getHitTest接口，在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  getHitTest(): HitTestTypeV9

- 变更前：

  ```ts
  getHitTest(): HitTestTypeV9
  ```

- 变更后：

  ```ts
  getHitTest(): WebHitTestType
  ```

**适配指导**

在使用getHitTest接口的返回值时，请使用WebHitTestType类型替换HitTestTypeV9类型。

## cl.web.6 WebMessagePort类迁移

WebMessagePort类迁移至@ohos.web.webview.d.ts,并新增错误码抛出。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现该类下接口支持错误码处理，需注意错误码处理的使用。

**关键的接口/组件变更**

- 涉及接口

  postMessageEvent(message: WebMessageEvent): void;
  onMessageEvent(callback: (result: string) => void): void;

- 变更前：

  ```ts
  postMessageEvent(message: WebMessageEvent): void;
  onMessageEvent(callback: (result: string) => void): void;
  ```

- 变更后：

  ```ts
  postMessageEvent(message: WebMessage): void;
  onMessageEvent(callback: (result: WebMessage) => void): void;
  ```

**适配指导**

原WebMessagePort类不需要import，现WebMessagePort类使用的是@ohos.web.webview，以下方式import:

  ```ts
  import web_webview from '@ohos.web.webview';
  ```

## cl.web.7 HitTestValue类迁移

HitTestValue类迁移至@ohos.web.webview.d.ts，HitTestValue类变更为接口，getType，getExtra变更为属性。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。

**关键的接口/组件变更**

- 涉及接口

  getType(): HitTestType;
  getExtra(): string;

- 变更前：

  ```ts
  getType(): HitTestType;
  getExtra(): string;
  ```

- 变更后：

  ```ts
  type: WebHitTestType;
  extra: string;
  ```

**适配指导**

原HitTestValue类不需要import，现HitTestValue类使用的是@ohos.web.webview，以下方式import:

  ```ts
  import web_webview from '@ohos.web.webview';
  ```

## cl.web.8 WebCookie类下api9接口迁移

WebCookie类下api9接口迁移，WebCookie类下api9接口迁移到web.webview.webview.WebCookieManager。
并新增接口错误码抛出。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现该类下接口支持错误码处理，需注意错误码处理的使用。
该类方法变为静态方法。

**关键的接口/组件变更**

- 涉及接口

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

- 变更前：

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

- 变更后：

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

**适配指导**

原WebCookie类不需要import，现WebCookieManager使用的是@ohos.web.webview，以下方式import:

  ```ts
  import web_webview from '@ohos.web.webview';
  ```

## cl.web.9 WebController类下api9接口迁移

WebController类下api9接口迁移至web.webview.webview.WebviewController，并新增接口错误码抛出。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现该类下接口支持错误码处理，需注意错误码处理的使用。
getDefaultUserAgent接口更名为getUserAgent。

**关键的接口/组件变更**

- 涉及接口

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

- 变更前：

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

- 变更后：

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

**适配指导**

原WebController类不需要import，现WebviewController类使用的是@ohos.web.webview，以下方式import:

  ```ts
  import web_webview from '@ohos.web.webview';
  ```

## cl.web.10 WebAsyncController类迁移

WebAsyncController类下接口迁移至web.webview.webview.WebviewController，并新增接口错误码抛出。

**变更影响**

基于此前版本开发的应用，需注意错误码处理的使用。

**关键的接口/组件变更**

- 涉及接口

  storeWebArchive(baseName: string, autoName: boolean): Promise<string>;
  storeWebArchive(baseName: string, autoName: boolean, callback : AsyncCallback<string>): void;

- 变更前：

  ```ts
  storeWebArchive(baseName: string, autoName: boolean): Promise<string>;
  storeWebArchive(baseName: string, autoName: boolean, callback : AsyncCallback<string>): void;
  ```

- 变更后：

  ```ts
  storeWebArchive(baseName: string, autoName: boolean): Promise<string>;
  storeWebArchive(baseName: string, autoName: boolean, callback : AsyncCallback<string>): void;
  ```

**适配指导**

使用示例：

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