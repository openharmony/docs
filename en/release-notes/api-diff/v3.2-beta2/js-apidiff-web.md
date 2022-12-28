# JS API Changes of the Web Subsystem

The table below lists the APIs changes of the web subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.web | WebDataBase | static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void; | Added|
| ohos.web | WebDataBase | static getHttpAuthCredentials(host: string, realm: string): Array\<string>; | Added|
| ohos.web | WebDataBase | static deleteHttpAuthCredentials(): void; | Added|
| ohos.web | WebDataBase | static existHttpAuthCredentials(): boolean; | Added|
| ohos.web | WebStorage | static getOriginUsage(origin: string): Promise\<number> ;<br>static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void; | Added|
| ohos.web | WebStorage | static getOriginQuota(origin: string): Promise\<number>;<br>static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void; | Added|
| ohos.web | WebStorage | static getOrigins(): Promise\<Array\<WebStorageOrigin>>;<br>static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void; | Added|
| ohos.web | WebStorage | static deleteOrigin(origin: string): void; | Added|
| ohos.web | WebStorage | static deleteAllData(): void; | Added|
| ohos.web | WebStorageOrigin | quota: number; | Added|
| ohos.web | WebStorageOrigin | usage: number; | Added|
| ohos.web | WebStorageOrigin | origin: string; | Added|
| Web | WebAttribute | onInterceptRequest(callback: (event?: { request: WebResourceRequest}) => WebResourceResponse): WebAttribute; | Added|
| Web | WebAttribute | onHttpAuthRequest(callback: (event?: { handler: HttpAuthHandler, host: string, realm: string }) => boolean): WebAttribute; | Added|
| Web | WebAttribute | onScaleChange(callback: (event: {oldScale: number, newScale: number}) => void): WebAttribute; | Added|
| Web | WebAttribute | onResourceLoad(callback: (event: {url: string}) => void): WebAttribute; | Added|
| Web | WebAttribute | onPrompt(callback: (event?: {url: string, message: string, value: string, result: JsResult }) => boolean): WebAttribute; | Added|
| Web | WebAttribute | initialScale(percent: number): WebAttribute; | Added|
| Web | WebController | backOrForward(step: number): void; | Added|
| Web | WebController | getPageHeight(): number; | Added|
| Web | WebController | getTitle(): string; | Added|
| Web | WebController | getDefaultUserAgent(): string; | Added|
| Web | WebController | getWebId(): number; | Added|
| Web | WebController | getHitTestValue(): HitTestValue; | Added|
| Web | WebController | zoomOut(): boolean; | Added|
| Web | WebController | zoomIn(): boolean; | Added|
| Web | WebResourceResponse | setResponseCode(code: number); | Added|
| Web | WebResourceResponse | setResponseHeader(header: Array\<Header>); | Added|
| Web | WebResourceResponse | setReasonMessage(reason: string); | Added|
| Web | WebResourceResponse | setResponseMimeType(mimeType: string); | Added|
| Web | WebResourceResponse | setResponseEncoding(encoding: string); | Added|
| Web | WebResourceResponse | setResponseData(data: string); | Added|
