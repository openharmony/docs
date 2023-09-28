| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：webview;<br>方法or属性：function once(type: string, callback: Callback\<void>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：webview;<br>方法or属性：type WebMessage = ArrayBuffer \| string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHeader;<br>方法or属性：headerKey: string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHeader;<br>方法or属性：headerValue: string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHitTestType;<br>方法or属性：EditText|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHitTestType;<br>方法or属性：Email|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHitTestType;<br>方法or属性：HttpAnchor|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHitTestType;<br>方法or属性：HttpAnchorImg|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHitTestType;<br>方法or属性：Img|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHitTestType;<br>方法or属性：Map|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHitTestType;<br>方法or属性：Phone|@ohos.web.webview.d.ts|
|新增|NA|类名：WebHitTestType;<br>方法or属性：Unknown|@ohos.web.webview.d.ts|
|新增|NA|类名：HitTestValue;<br>方法or属性：type: WebHitTestType;|@ohos.web.webview.d.ts|
|新增|NA|类名：HitTestValue;<br>方法or属性：extra: string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCustomScheme;<br>方法or属性：schemeName: string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCustomScheme;<br>方法or属性：isSupportCORS: boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCustomScheme;<br>方法or属性：isSupportFetch: boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorageOrigin;<br>方法or属性：origin: string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorageOrigin;<br>方法or属性：usage: number;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorageOrigin;<br>方法or属性：quota: number;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorage;<br>方法or属性：static deleteAllData(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorage;<br>方法or属性：static deleteOrigin(origin: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorage;<br>方法or属性：static getOrigins(): Promise\<Array\<WebStorageOrigin>>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorage;<br>方法or属性：static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorage;<br>方法or属性：static getOriginQuota(origin: string): Promise\<number>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorage;<br>方法or属性：static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorage;<br>方法or属性：static getOriginUsage(origin: string): Promise\<number> ;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebStorage;<br>方法or属性：static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebDataBase;<br>方法or属性：static existHttpAuthCredentials(): boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebDataBase;<br>方法or属性：static deleteHttpAuthCredentials(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebDataBase;<br>方法or属性：static getHttpAuthCredentials(host: string, realm: string): Array\<string>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebDataBase;<br>方法or属性：static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：GeolocationPermissions;<br>方法or属性：static allowGeolocation(origin: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：GeolocationPermissions;<br>方法or属性：static deleteGeolocation(origin: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：GeolocationPermissions;<br>方法or属性：static deleteAllGeolocation(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：GeolocationPermissions;<br>方法or属性：static getAccessibleGeolocation(origin: string): Promise\<boolean>;|@ohos.web.webview.d.ts|
|新增|NA|类名：GeolocationPermissions;<br>方法or属性：static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：GeolocationPermissions;<br>方法or属性：static getStoredGeolocation(): Promise\<Array\<string>>;|@ohos.web.webview.d.ts|
|新增|NA|类名：GeolocationPermissions;<br>方法or属性：static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static getCookie(url: string): string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static setCookie(url: string, value: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static saveCookieAsync(): Promise\<void>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static saveCookieAsync(callback: AsyncCallback\<void>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static isCookieAllowed(): boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static putAcceptCookieEnabled(accept: boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static isThirdPartyCookieAllowed(): boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static putAcceptThirdPartyCookieEnabled(accept: boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static existCookie(): boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static deleteEntireCookie(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebCookieManager;<br>方法or属性：static deleteSessionCookie(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessagePort;<br>方法or属性：close(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessagePort;<br>方法or属性：postMessageEvent(message: WebMessage): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessagePort;<br>方法or属性：onMessageEvent(callback: (result: WebMessage) => void): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：HistoryItem;<br>方法or属性：icon: image.PixelMap;|@ohos.web.webview.d.ts|
|新增|NA|类名：HistoryItem;<br>方法or属性：historyUrl: string;|@ohos.web.webview.d.ts|
|新增|NA|类名：HistoryItem;<br>方法or属性：historyRawUrl: string;|@ohos.web.webview.d.ts|
|新增|NA|类名：HistoryItem;<br>方法or属性：title: string;|@ohos.web.webview.d.ts|
|新增|NA|类名：BackForwardList;<br>方法or属性：currentIndex: number;|@ohos.web.webview.d.ts|
|新增|NA|类名：BackForwardList;<br>方法or属性：size: number;|@ohos.web.webview.d.ts|
|新增|NA|类名：BackForwardList;<br>方法or属性：getItemAtIndex(index: number): HistoryItem;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：static initializeWebEngine(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：static setWebDebuggingAccess(webDebuggingAccess: boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：accessForward(): boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：accessBackward(): boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：accessStep(step: number): boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：forward(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：backward(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：clearHistory(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：onActive(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：onInactive(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：refresh(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：loadData(data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：loadUrl(url: string \| Resource, headers?: Array\<WebHeader>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getHitTest(): WebHitTestType;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：storeWebArchive(baseName: string, autoName: boolean): Promise\<string>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：zoom(factor: number): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：zoomIn(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：zoomOut(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getHitTestValue(): HitTestValue;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getWebId(): number;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getUserAgent(): string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getTitle(): string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getPageHeight(): number;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：backOrForward(step: number): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：requestFocus(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：createWebMessagePorts(): Array\<WebMessagePort>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：postMessage(name: string, ports: Array\<WebMessagePort>, uri: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：stop(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：registerJavaScriptProxy(object: object, name: string, methodList: Array\<string>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：deleteJavaScriptRegister(name: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：searchAllAsync(searchString: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：clearMatches(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：searchNext(forward: boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：clearSslCache(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：clearClientAuthenticationCache(): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：runJavaScript(script: string): Promise\<string>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：runJavaScript(script: string, callback: AsyncCallback\<string>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getUrl(): string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：pageUp(top:boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：pageDown(bottom:boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getOriginalUrl(): string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getFavicon(): image.PixelMap;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：setNetworkAvailable(enable: boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：hasImage(): Promise\<boolean>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：hasImage(callback: AsyncCallback\<boolean>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getBackForwardEntries(): BackForwardList;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：removeCache(clearRom: boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：scrollTo(x:number, y:number): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：scrollBy(deltaX:number, deltaY:number): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：slideScroll(vx:number, vy:number): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：serializeWebState(): Uint8Array;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：restoreWebState(state: Uint8Array): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：static customizeSchemes(schemes: Array\<WebCustomScheme>): void;|@ohos.web.webview.d.ts|
