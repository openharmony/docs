# Web子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，Web子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 函数 | 变更类型 |
|---|---|---|---|
| ohos.web | WebDataBase | static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void; | 新增 |
| ohos.web | WebDataBase | static getHttpAuthCredentials(host: string, realm: string): Array\<string>; | 新增 |
| ohos.web | WebDataBase | static deleteHttpAuthCredentials(): void; | 新增 |
| ohos.web | WebDataBase | static existHttpAuthCredentials(): boolean; | 新增 |
| ohos.web | WebStorage | static getOriginUsage(origin: string): Promise\<number> ;<br>static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.web | WebStorage | static getOriginQuota(origin: string): Promise\<number>;<br>static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.web | WebStorage | static getOrigins(): Promise\<Array\<WebStorageOrigin>>;<br>static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void; | 新增 |
| ohos.web | WebStorage | static deleteOrigin(origin: string): void; | 新增 |
| ohos.web | WebStorage | static deleteAllData(): void; | 新增 |
| ohos.web | WebStorageOrigin | quota: number; | 新增 |
| ohos.web | WebStorageOrigin | usage: number; | 新增 |
| ohos.web | WebStorageOrigin | origin: string; | 新增 |
| Web | WebAttribute | onInterceptRequest(callback: (event?: { request: WebResourceRequest}) => WebResourceResponse): WebAttribute; | 新增 |
| Web | WebAttribute | onHttpAuthRequest(callback: (event?: { handler: HttpAuthHandler, host: string, realm: string }) => boolean): WebAttribute; | 新增 |
| Web | WebAttribute | onScaleChange(callback: (event: {oldScale: number, newScale: number}) => void): WebAttribute; | 新增 |
| Web | WebAttribute | onResourceLoad(callback: (event: {url: string}) => void): WebAttribute; | 新增 |
| Web | WebAttribute | onPrompt(callback: (event?: {url: string, message: string, value: string, result: JsResult }) => boolean): WebAttribute; | 新增 |
| Web | WebAttribute | initialScale(percent: number): WebAttribute; | 新增 |
| Web | WebController | backOrForward(step: number): void; | 新增 |
| Web | WebController | getPageHeight(): number; | 新增 |
| Web | WebController | getTitle(): string; | 新增 |
| Web | WebController | getDefaultUserAgent(): string; | 新增 |
| Web | WebController | getWebId(): number; | 新增 |
| Web | WebController | getHitTestValue(): HitTestValue; | 新增 |
| Web | WebController | zoomOut(): boolean; | 新增 |
| Web | WebController | zoomIn(): boolean; | 新增 |
| Web | WebResourceResponse | setResponseCode(code: number); | 新增 |
| Web | WebResourceResponse | setResponseHeader(header: Array\<Header>); | 新增 |
| Web | WebResourceResponse | setReasonMessage(reason: string); | 新增 |
| Web | WebResourceResponse | setResponseMimeType(mimeType: string); | 新增 |
| Web | WebResourceResponse | setResponseEncoding(encoding: string); | 新增 |
| Web | WebResourceResponse | setResponseData(data: string); | 新增 |