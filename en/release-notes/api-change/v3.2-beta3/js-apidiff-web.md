# JS API Changes of the Web Subsystem

The table below lists the APIs changes of the web subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.web.webview | WebCookieManager       | static deleteSessionCookie(): void;                                                                                                                                     | Added|
| ohos.web.webview | WebCookieManager       | static deleteEntireCookie(): void;                                                                                                                                      | Added|
| ohos.web.webview | WebCookieManager       | static existCookie(): boolean;                                                                                                                                          | Added|
| ohos.web.webview | WebCookieManager       | static putAcceptThirdPartyCookieEnabled(accept: boolean): void;                                                                                                         | Added|
| ohos.web.webview | WebCookieManager       | static isThirdPartyCookieAllowed(): boolean;                                                                                                                            | Added|
| ohos.web.webview | WebCookieManager       | static putAcceptCookieEnabled(accept: boolean): void;                                                                                                                   | Added|
| ohos.web.webview | WebCookieManager       | static isCookieAllowed(): boolean;                                                                                                                                      | Added|
| ohos.web.webview | WebCookieManager       | static saveCookieAsync(): Promise\<boolean>;<br>static saveCookieAsync(callback: AsyncCallback\<boolean>): void;                                                       | Added|
| ohos.web.webview | WebCookieManager       | static saveCookieSync(): boolean;                                                                                                                                       | Added|
| ohos.web.webview | WebCookieManager       | static setCookie(url: string, value: string): boolean;                                                                                                                  | Added|
| ohos.web.webview | WebCookieManager       | static getCookie(url: string): string;                                                                                                                                  | Added|
| ohos.web.webview | GeolocationPermissions | static getStoredGeolocation() : Promise\<Array\<string>>;<br>static getStoredGeolocation(callback : AsyncCallback\<Array\<string>>): void;                             | Added|
| ohos.web.webview | GeolocationPermissions | static getAccessibleGeolocation(origin: string): Promise\<boolean>;<br>static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void;       | Added|
| ohos.web.webview | GeolocationPermissions | static deleteAllGeolocation(): void;                                                                                                                                    | Added|
| ohos.web.webview | GeolocationPermissions | static deleteGeolocation(origin: string): void;                                                                                                                         | Added|
| ohos.web.webview | GeolocationPermissions | static allowGeolocation(origin: string): void;                                                                                                                          | Added|
| ohos.web.webview | WebAsyncController     | storeWebArchive(baseName: string, autoName: boolean): Promise\<string>;<br>storeWebArchive(baseName: string, autoName: boolean, callback : AsyncCallback\<string>): void; | Added|
| ohos.web.webview | WebAsyncController     | constructor(controller: WebController);                                                                                                                                 | Added|
| ohos.web.webview | WebDataBase            | static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void;                                                                  | Added|
| ohos.web.webview | WebDataBase            | static getHttpAuthCredentials(host: string, realm: string): Array\<string>;                                                                                             | Added|
| ohos.web.webview | WebDataBase            | static deleteHttpAuthCredentials(): void;                                                                                                                               | Added|
| ohos.web.webview | WebDataBase            | static existHttpAuthCredentials(): boolean;                                                                                                                             | Added|
| ohos.web.webview | WebStorage             | static getOriginUsage(origin : string) : Promise\<number> ;<br>static getOriginUsage(origin : string, callback : AsyncCallback\<number>) : void;                       | Added|
| ohos.web.webview | WebStorage             | static getOriginQuota(origin : string) : Promise\<number>;<br>static getOriginQuota(origin : string, callback : AsyncCallback\<number>) : void;                        | Added|
| ohos.web.webview | WebStorage             | static getOrigins() : Promise\<Array\<WebStorageOrigin>>;<br>static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>) : void;                             | Added|
| ohos.web.webview | WebStorage             | static deleteOrigin(origin : string): void;                                                                                                                             | Added|
| ohos.web.webview | WebStorage             | static deleteAllData() : void;                                                                                                                                          | Added|
| ohos.web.webview | WebStorageOrigin       | quota: number;                                                                                                                                                          | Added|
| ohos.web.webview | WebStorageOrigin       | usage: number;                                                                                                                                                          | Added|
| ohos.web.webview | WebStorageOrigin       | origin: string;                                                                                                                                                         | Added|
| ohos.web | WebDataBase      | static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void;                                         | Deleted|
| ohos.web | WebDataBase      | static getHttpAuthCredentials(host: string, realm: string): Array\<string>;                                                                    | Deleted|
| ohos.web | WebDataBase      | static deleteHttpAuthCredentials(): void;                                                                                                      | Deleted|
| ohos.web | WebDataBase      | static existHttpAuthCredentials(): boolean;                                                                                                    | Deleted|
| ohos.web | WebStorage       | static getOriginUsage(origin : string) : Promise\<number> ;<br>static getOriginUsage(origin : string, callback : AsyncCallback\<number>) : void; | Deleted|
| ohos.web | WebStorage       | static getOriginQuota(origin : string) : Promise\<number>;<br>static getOriginQuota(origin : string, callback : AsyncCallback\<number>) : void; | Deleted|
| ohos.web | WebStorage       | static getOrigins() : Promise\<Array\<WebStorageOrigin>>;<br>static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>) : void;    | Deleted|
| ohos.web | WebStorage       | static deleteOrigin(origin : string): void;                                                                                                    | Deleted|
| ohos.web | WebStorage       | static deleteAllData() : void;                                                                                                                 | Deleted|
| ohos.web | WebStorageOrigin | quota: number;                                                                                                                                 | Deleted|
| ohos.web | WebStorageOrigin | usage: number;                                                                                                                                 | Deleted|
| ohos.web | WebStorageOrigin | origin: string;                                                                                                                                | Deleted|
