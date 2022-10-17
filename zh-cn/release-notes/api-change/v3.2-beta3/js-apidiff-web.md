# Web子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，Web子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.web.webview | WebCookieManager       | static deleteSessionCookie(): void;                                                                                                                                     | 新增 |
| ohos.web.webview | WebCookieManager       | static deleteEntireCookie(): void;                                                                                                                                      | 新增 |
| ohos.web.webview | WebCookieManager       | static existCookie(): boolean;                                                                                                                                          | 新增 |
| ohos.web.webview | WebCookieManager       | static putAcceptThirdPartyCookieEnabled(accept: boolean): void;                                                                                                         | 新增 |
| ohos.web.webview | WebCookieManager       | static isThirdPartyCookieAllowed(): boolean;                                                                                                                            | 新增 |
| ohos.web.webview | WebCookieManager       | static putAcceptCookieEnabled(accept: boolean): void;                                                                                                                   | 新增 |
| ohos.web.webview | WebCookieManager       | static isCookieAllowed(): boolean;                                                                                                                                      | 新增 |
| ohos.web.webview | WebCookieManager       | static saveCookieAsync(): Promise\<boolean>;<br>static saveCookieAsync(callback: AsyncCallback\<boolean>): void;                                                       | 新增 |
| ohos.web.webview | WebCookieManager       | static saveCookieSync(): boolean;                                                                                                                                       | 新增 |
| ohos.web.webview | WebCookieManager       | static setCookie(url: string, value: string): boolean;                                                                                                                  | 新增 |
| ohos.web.webview | WebCookieManager       | static getCookie(url: string): string;                                                                                                                                  | 新增 |
| ohos.web.webview | GeolocationPermissions | static getStoredGeolocation() : Promise\<Array\<string>>;<br>static getStoredGeolocation(callback : AsyncCallback\<Array\<string>>): void;                             | 新增 |
| ohos.web.webview | GeolocationPermissions | static getAccessibleGeolocation(origin: string): Promise\<boolean>;<br>static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void;       | 新增 |
| ohos.web.webview | GeolocationPermissions | static deleteAllGeolocation(): void;                                                                                                                                    | 新增 |
| ohos.web.webview | GeolocationPermissions | static deleteGeolocation(origin: string): void;                                                                                                                         | 新增 |
| ohos.web.webview | GeolocationPermissions | static allowGeolocation(origin: string): void;                                                                                                                          | 新增 |
| ohos.web.webview | WebAsyncController     | storeWebArchive(baseName: string, autoName: boolean): Promise\<string>;<br>storeWebArchive(baseName: string, autoName: boolean, callback : AsyncCallback\<string>): void; | 新增 |
| ohos.web.webview | WebAsyncController     | constructor(controller: WebController);                                                                                                                                 | 新增 |
| ohos.web.webview | WebDataBase            | static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void;                                                                  | 新增 |
| ohos.web.webview | WebDataBase            | static getHttpAuthCredentials(host: string, realm: string): Array\<string>;                                                                                             | 新增 |
| ohos.web.webview | WebDataBase            | static deleteHttpAuthCredentials(): void;                                                                                                                               | 新增 |
| ohos.web.webview | WebDataBase            | static existHttpAuthCredentials(): boolean;                                                                                                                             | 新增 |
| ohos.web.webview | WebStorage             | static getOriginUsage(origin : string) : Promise\<number> ;<br>static getOriginUsage(origin : string, callback : AsyncCallback\<number>) : void;                       | 新增 |
| ohos.web.webview | WebStorage             | static getOriginQuota(origin : string) : Promise\<number>;<br>static getOriginQuota(origin : string, callback : AsyncCallback\<number>) : void;                        | 新增 |
| ohos.web.webview | WebStorage             | static getOrigins() : Promise\<Array\<WebStorageOrigin>>;<br>static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>) : void;                             | 新增 |
| ohos.web.webview | WebStorage             | static deleteOrigin(origin : string): void;                                                                                                                             | 新增 |
| ohos.web.webview | WebStorage             | static deleteAllData() : void;                                                                                                                                          | 新增 |
| ohos.web.webview | WebStorageOrigin       | quota: number;                                                                                                                                                          | 新增 |
| ohos.web.webview | WebStorageOrigin       | usage: number;                                                                                                                                                          | 新增 |
| ohos.web.webview | WebStorageOrigin       | origin: string;                                                                                                                                                         | 新增 |
| ohos.web | WebDataBase      | static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void;                                         | 删除 |
| ohos.web | WebDataBase      | static getHttpAuthCredentials(host: string, realm: string): Array\<string>;                                                                    | 删除 |
| ohos.web | WebDataBase      | static deleteHttpAuthCredentials(): void;                                                                                                      | 删除 |
| ohos.web | WebDataBase      | static existHttpAuthCredentials(): boolean;                                                                                                    | 删除 |
| ohos.web | WebStorage       | static getOriginUsage(origin : string) : Promise\<number> ;<br>static getOriginUsage(origin : string, callback : AsyncCallback\<number>) : void; | 删除 |
| ohos.web | WebStorage       | static getOriginQuota(origin : string) : Promise\<number>;<br>static getOriginQuota(origin : string, callback : AsyncCallback\<number>) : void; | 删除 |
| ohos.web | WebStorage       | static getOrigins() : Promise\<Array\<WebStorageOrigin>>;<br>static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>) : void;    | 删除 |
| ohos.web | WebStorage       | static deleteOrigin(origin : string): void;                                                                                                    | 删除 |
| ohos.web | WebStorage       | static deleteAllData() : void;                                                                                                                 | 删除 |
| ohos.web | WebStorageOrigin | quota: number;                                                                                                                                 | 删除 |
| ohos.web | WebStorageOrigin | usage: number;                                                                                                                                 | 删除 |
| ohos.web | WebStorageOrigin | origin: string;                                                                                                                                | 删除 |

