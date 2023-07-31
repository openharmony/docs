| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：SecureDnsMode;<br>方法or属性：OFF = 0|@ohos.web.webview.d.ts|
|新增|NA|类名：SecureDnsMode;<br>方法or属性：AUTO = 1|@ohos.web.webview.d.ts|
|新增|NA|类名：SecureDnsMode;<br>方法or属性：SECURE_ONLY = 2|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：prefetchPage(url: string, additionalHeaders?: Array\<WebHeader>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：static prepareForPageLoad(url: string, preconnectable: boolean, numSockets: number): void;|@ohos.web.webview.d.ts|
|废弃版本有变化|类名：SecureDnsMode;<br>方法or属性：Off = 0<br>旧版本信息：|类名：SecureDnsMode;<br>方法or属性：Off = 0<br>新版本信息：10<br>代替接口： SecureDnsMode#OFF|@ohos.web.webview.d.ts|
|废弃版本有变化|类名：SecureDnsMode;<br>方法or属性：Auto = 1<br>旧版本信息：|类名：SecureDnsMode;<br>方法or属性：Auto = 1<br>新版本信息：10<br>代替接口： SecureDnsMode#AUTO|@ohos.web.webview.d.ts|
|废弃版本有变化|类名：SecureDnsMode;<br>方法or属性：SecureOnly = 2<br>旧版本信息：|类名：SecureDnsMode;<br>方法or属性：SecureOnly = 2<br>新版本信息：10<br>代替接口： SecureDnsMode#SECURE_ONLY|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebStorage;<br>方法or属性：static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void;<br>旧版本信息：|类名：WebStorage;<br>方法or属性：static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void;<br>新版本信息：401,17100012|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebStorage;<br>方法or属性：static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：WebStorage;<br>方法or属性：static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void;<br>新版本信息：401,17100011|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebStorage;<br>方法or属性：static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：WebStorage;<br>方法or属性：static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void;<br>新版本信息：401,17100011|@ohos.web.webview.d.ts|
|新增(错误码)|类名：GeolocationPermissions;<br>方法or属性：static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：GeolocationPermissions;<br>方法or属性：static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,17100011|@ohos.web.webview.d.ts|
|新增(错误码)|类名：GeolocationPermissions;<br>方法or属性：static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：GeolocationPermissions;<br>方法or属性：static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：401|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebCookieManager;<br>方法or属性：static saveCookieAsync(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：WebCookieManager;<br>方法or属性：static saveCookieAsync(callback: AsyncCallback\<void>): void;<br>新版本信息：401|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebviewController;<br>方法or属性：storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：WebviewController;<br>方法or属性：storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void;<br>新版本信息：401,17100001,17100003|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebviewController;<br>方法or属性：runJavaScript(script: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：WebviewController;<br>方法or属性：runJavaScript(script: string, callback: AsyncCallback\<string>): void;<br>新版本信息：401,17100001|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebviewController;<br>方法or属性：runJavaScriptExt(script: string, callback: AsyncCallback\<JsMessageExt>): void;<br>旧版本信息：|类名：WebviewController;<br>方法or属性：runJavaScriptExt(script: string, callback: AsyncCallback\<JsMessageExt>): void;<br>新版本信息：401,17100001|@ohos.web.webview.d.ts|
