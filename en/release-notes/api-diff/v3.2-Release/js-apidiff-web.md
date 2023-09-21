| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: webview;<br>Method or attribute name: function once(type: string, callback: Callback\<void>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: webview;<br>Method or attribute name: type WebMessage = ArrayBuffer \| string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHeader;<br>Method or attribute name: headerKey: string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHeader;<br>Method or attribute name: headerValue: string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHitTestType;<br>Method or attribute name: EditText|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHitTestType;<br>Method or attribute name: Email|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHitTestType;<br>Method or attribute name: HttpAnchor|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHitTestType;<br>Method or attribute name: HttpAnchorImg|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHitTestType;<br>Method or attribute name: Img|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHitTestType;<br>Method or attribute name: Map|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHitTestType;<br>Method or attribute name: Phone|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebHitTestType;<br>Method or attribute name: Unknown|@ohos.web.webview.d.ts|
|Added|NA|Class name: HitTestValue;<br>Method or attribute name: type: WebHitTestType;|@ohos.web.webview.d.ts|
|Added|NA|Class name: HitTestValue;<br>Method or attribute name: extra: string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCustomScheme;<br>Method or attribute name: schemeName: string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCustomScheme;<br>Method or attribute name: isSupportCORS: boolean;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCustomScheme;<br>Method or attribute name: isSupportFetch: boolean;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorageOrigin;<br>Method or attribute name: origin: string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorageOrigin;<br>Method or attribute name: usage: number;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorageOrigin;<br>Method or attribute name: quota: number;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorage;<br>Method or attribute name: static deleteAllData(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorage;<br>Method or attribute name: static deleteOrigin(origin: string): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorage;<br>Method or attribute name: static getOrigins(): Promise\<Array\<WebStorageOrigin>>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorage;<br>Method or attribute name: static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorage;<br>Method or attribute name: static getOriginQuota(origin: string): Promise\<number>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorage;<br>Method or attribute name: static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorage;<br>Method or attribute name: static getOriginUsage(origin: string): Promise\<number> ;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebStorage;<br>Method or attribute name: static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebDataBase;<br>Method or attribute name: static existHttpAuthCredentials(): boolean;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebDataBase;<br>Method or attribute name: static deleteHttpAuthCredentials(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebDataBase;<br>Method or attribute name: static getHttpAuthCredentials(host: string, realm: string): Array\<string>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebDataBase;<br>Method or attribute name: static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: GeolocationPermissions;<br>Method or attribute name: static allowGeolocation(origin: string): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: GeolocationPermissions;<br>Method or attribute name: static deleteGeolocation(origin: string): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: GeolocationPermissions;<br>Method or attribute name: static deleteAllGeolocation(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: GeolocationPermissions;<br>Method or attribute name: static getAccessibleGeolocation(origin: string): Promise\<boolean>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: GeolocationPermissions;<br>Method or attribute name: static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: GeolocationPermissions;<br>Method or attribute name: static getStoredGeolocation(): Promise\<Array\<string>>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: GeolocationPermissions;<br>Method or attribute name: static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static getCookie(url: string): string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static setCookie(url: string, value: string): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static saveCookieAsync(): Promise\<void>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static saveCookieAsync(callback: AsyncCallback\<void>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static isCookieAllowed(): boolean;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static putAcceptCookieEnabled(accept: boolean): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static isThirdPartyCookieAllowed(): boolean;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static putAcceptThirdPartyCookieEnabled(accept: boolean): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static existCookie(): boolean;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static deleteEntireCookie(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebCookieManager;<br>Method or attribute name: static deleteSessionCookie(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebMessagePort;<br>Method or attribute name: close(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebMessagePort;<br>Method or attribute name: postMessageEvent(message: WebMessage): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebMessagePort;<br>Method or attribute name: onMessageEvent(callback: (result: WebMessage) => void): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: HistoryItem;<br>Method or attribute name: icon: image.PixelMap;|@ohos.web.webview.d.ts|
|Added|NA|Class name: HistoryItem;<br>Method or attribute name: historyUrl: string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: HistoryItem;<br>Method or attribute name: historyRawUrl: string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: HistoryItem;<br>Method or attribute name: title: string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: BackForwardList;<br>Method or attribute name: currentIndex: number;|@ohos.web.webview.d.ts|
|Added|NA|Class name: BackForwardList;<br>Method or attribute name: size: number;|@ohos.web.webview.d.ts|
|Added|NA|Class name: BackForwardList;<br>Method or attribute name: getItemAtIndex(index: number): HistoryItem;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: static initializeWebEngine(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: static setWebDebuggingAccess(webDebuggingAccess: boolean): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: accessForward(): boolean;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: accessBackward(): boolean;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: accessStep(step: number): boolean;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: forward(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: backward(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: clearHistory(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: onActive(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: onInactive(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: refresh(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: loadData(data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: loadUrl(url: string \| Resource, headers?: Array\<WebHeader>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getHitTest(): WebHitTestType;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: storeWebArchive(baseName: string, autoName: boolean): Promise\<string>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: zoom(factor: number): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: zoomIn(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: zoomOut(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getHitTestValue(): HitTestValue;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getWebId(): number;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getUserAgent(): string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getTitle(): string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getPageHeight(): number;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: backOrForward(step: number): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: requestFocus(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: createWebMessagePorts(): Array\<WebMessagePort>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: postMessage(name: string, ports: Array\<WebMessagePort>, uri: string): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: stop(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: registerJavaScriptProxy(object: object, name: string, methodList: Array\<string>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: deleteJavaScriptRegister(name: string): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: searchAllAsync(searchString: string): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: clearMatches(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: searchNext(forward: boolean): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: clearSslCache(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: clearClientAuthenticationCache(): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: runJavaScript(script: string): Promise\<string>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: runJavaScript(script: string, callback: AsyncCallback\<string>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getUrl(): string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: pageUp(top:boolean): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: pageDown(bottom:boolean): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getOriginalUrl(): string;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getFavicon(): image.PixelMap;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: setNetworkAvailable(enable: boolean): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: hasImage(): Promise\<boolean>;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: hasImage(callback: AsyncCallback\<boolean>): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: getBackForwardEntries(): BackForwardList;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: removeCache(clearRom: boolean): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: scrollTo(x:number, y:number): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: scrollBy(deltaX:number, deltaY:number): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: slideScroll(vx:number, vy:number): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: serializeWebState(): Uint8Array;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: restoreWebState(state: Uint8Array): void;|@ohos.web.webview.d.ts|
|Added|NA|Class name: WebviewController;<br>Method or attribute name: static customizeSchemes(schemes: Array\<WebCustomScheme>): void;|@ohos.web.webview.d.ts|
