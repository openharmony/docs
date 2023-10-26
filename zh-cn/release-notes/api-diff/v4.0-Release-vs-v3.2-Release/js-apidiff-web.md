| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：SecureDnsMode;<br>方法or属性：OFF = 0|@ohos.web.webview.d.ts|
|新增|NA|类名：SecureDnsMode;<br>方法or属性：AUTO = 1|@ohos.web.webview.d.ts|
|新增|NA|类名：SecureDnsMode;<br>方法or属性：SECURE_ONLY = 2|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageType;<br>方法or属性：NOT_SUPPORT|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageType;<br>方法or属性：NOT_SUPPORT|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageType;<br>方法or属性：STRING|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageType;<br>方法or属性：STRING|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageType;<br>方法or属性：NUMBER|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageType;<br>方法or属性：NUMBER|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageType;<br>方法or属性：BOOLEAN|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageType;<br>方法or属性：BOOLEAN|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageType;<br>方法or属性：ARRAY_BUFFER|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageType;<br>方法or属性：ARRAY_BUFFER|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageType;<br>方法or属性：ARRAY|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageType;<br>方法or属性：ARRAY|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageType;<br>方法or属性：ERROR|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：getType(): WebMessageType;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：getString(): string;|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageExt;<br>方法or属性：getString(): string;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：getNumber(): number;|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageExt;<br>方法or属性：getNumber(): number;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：getBoolean(): boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageExt;<br>方法or属性：getBoolean(): boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：getArrayBuffer(): ArrayBuffer;|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageExt;<br>方法or属性：getArrayBuffer(): ArrayBuffer;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：getArray(): Array\<string \| number \| boolean>;|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageExt;<br>方法or属性：getArray(): Array\<string \| number \| boolean>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：getError(): Error;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：setType(type: WebMessageType): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：setString(message: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：setNumber(message: number): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：setBoolean(message: boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：setArrayBuffer(message: ArrayBuffer): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：setArray(message: Array\<string \| number \| boolean>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessageExt;<br>方法or属性：setError(message: Error): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessagePort;<br>方法or属性：isExtentionType?: boolean;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessagePort;<br>方法or属性：postMessageEventExt(message: WebMessageExt): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebMessagePort;<br>方法or属性：onMessageEventExt(callback: (result: WebMessageExt) => void): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：JsMessageExt;<br>方法or属性：getType(): JsMessageType;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：static setHttpDns(secureDnsMode: SecureDnsMode, secureDnsConfig: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：runJavaScriptExt(script: string): Promise\<JsMessageExt>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：runJavaScriptExt(script: string, callback: AsyncCallback\<JsMessageExt>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getCertificate(): Promise\<Array\<cert.X509Cert>>;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getCertificate(callback: AsyncCallback\<Array\<cert.X509Cert>>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：setAudioMuted(mute: boolean): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：prefetchPage(url: string, additionalHeaders?: Array\<WebHeader>): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：static prepareForPageLoad(url: string, preconnectable: boolean, numSockets: number): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：setCustomUserAgent(userAgent: string): void;|@ohos.web.webview.d.ts|
|新增|NA|类名：WebviewController;<br>方法or属性：getCustomUserAgent(): string;|@ohos.web.webview.d.ts|
|废弃版本有变化|类名：WebAttribute;<br>方法or属性：password(password: boolean): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：password(password: boolean): WebAttribute;<br>新版本信息：10<br>代替接口：|web.d.ts|
|废弃版本有变化|类名：WebAttribute;<br>方法or属性：tableData(tableData: boolean): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：tableData(tableData: boolean): WebAttribute;<br>新版本信息：10<br>代替接口：|web.d.ts|
|废弃版本有变化|类名：WebAttribute;<br>方法or属性：wideViewModeAccess(wideViewModeAccess: boolean): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：wideViewModeAccess(wideViewModeAccess: boolean): WebAttribute;<br>新版本信息：10<br>代替接口：|web.d.ts|
|废弃版本有变化|类名：WebAttribute;<br>方法or属性：userAgent(userAgent: string): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：userAgent(userAgent: string): WebAttribute;<br>新版本信息：10<br>代替接口： ohos.web.webview.webview.WebviewController#setCustomUserAgent|web.d.ts|
|废弃版本有变化|类名：WebAttribute;<br>方法or属性：onUrlLoadIntercept(callback: (event?: { data: string \| WebResourceRequest }) => boolean): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：onUrlLoadIntercept(callback: (event?: { data: string \| WebResourceRequest }) => boolean): WebAttribute;<br>新版本信息：10<br>代替接口： ohos.web.WebAttribute#onLoadIntercept|web.d.ts|
|新增(错误码)|类名：WebStorage;<br>方法or属性：static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void;<br>旧版本信息：|类名：WebStorage;<br>方法or属性：static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void;<br>新版本信息：401,17100012|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebStorage;<br>方法or属性：static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：WebStorage;<br>方法or属性：static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void;<br>新版本信息：401,17100011|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebStorage;<br>方法or属性：static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：WebStorage;<br>方法or属性：static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void;<br>新版本信息：401,17100011|@ohos.web.webview.d.ts|
|新增(错误码)|类名：GeolocationPermissions;<br>方法or属性：static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：GeolocationPermissions;<br>方法or属性：static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,17100011|@ohos.web.webview.d.ts|
|新增(错误码)|类名：GeolocationPermissions;<br>方法or属性：static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：GeolocationPermissions;<br>方法or属性：static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：401|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebCookieManager;<br>方法or属性：static saveCookieAsync(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：WebCookieManager;<br>方法or属性：static saveCookieAsync(callback: AsyncCallback\<void>): void;<br>新版本信息：401|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebviewController;<br>方法or属性：storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：WebviewController;<br>方法or属性：storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void;<br>新版本信息：401,17100001,17100003|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebviewController;<br>方法or属性：runJavaScript(script: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：WebviewController;<br>方法or属性：runJavaScript(script: string, callback: AsyncCallback\<string>): void;<br>新版本信息：401,17100001|@ohos.web.webview.d.ts|
|新增(错误码)|类名：WebviewController;<br>方法or属性：hasImage(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebviewController;<br>方法or属性：hasImage(callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,17100001|@ohos.web.webview.d.ts|
|错误码有变化|类名：WebviewController;<br>方法or属性：createWebMessagePorts(isExtentionType?: boolean): Array\<WebMessagePort>;<br>旧版本信息：17100001|类名：WebviewController;<br>方法or属性：createWebMessagePorts(isExtentionType?: boolean): Array\<WebMessagePort>;<br>新版本信息：401,17100001|@ohos.web.webview.d.ts|
|type有变化|类名：Header;<br>方法or属性：headerKey: string;<br>旧版本信息：|类名：Header;<br>方法or属性：headerKey: string;<br>新版本信息：string|web.d.ts|
|type有变化|类名：Header;<br>方法or属性：headerValue: string;<br>旧版本信息：|类名：Header;<br>方法or属性：headerValue: string;<br>新版本信息：string|web.d.ts|
|type有变化|类名：WebOptions;<br>方法or属性：src: string \| Resource;<br>旧版本信息：|类名：WebOptions;<br>方法or属性：src: string \| Resource;<br>新版本信息：string \| Resource|web.d.ts|
|type有变化|类名：WebOptions;<br>方法or属性：controller: WebController \| WebviewController;<br>旧版本信息：(WebController \| WebviewController)|类名：WebOptions;<br>方法or属性：controller: WebController \| WebviewController;<br>新版本信息：WebController \| WebviewController|web.d.ts|
|type有变化|类名：WebAttribute;<br>方法or属性：javaScriptProxy(javaScriptProxy: { object: object, name: string, methodList: Array\<string>,<br>    controller: WebController \| WebviewController }): WebAttribute;<br>旧版本信息：controller : WebController \| WebviewController|类名：WebAttribute;<br>方法or属性：javaScriptProxy(javaScriptProxy: { object: object, name: string, methodList: Array\<string>,<br>    controller: WebController \| WebviewController }): WebAttribute;<br>新版本信息：|web.d.ts|
|函数有变化|类名：WebviewController;<br>方法or属性：createWebMessagePorts(): Array\<WebMessagePort>;|类名：WebviewController;<br>方法or属性：createWebMessagePorts(isExtentionType?: boolean): Array\<WebMessagePort>;|@ohos.web.webview.d.ts|
|跨平台能力有变化|类名：webview;<br>方法or属性：declare webview<br>旧版本信息：|类名：webview;<br>方法or属性：declare webview<br>新版本信息：crossplatform|@ohos.web.webview.d.ts|
|跨平台能力有变化|类名：WebHeader;<br>方法or属性：interface WebHeader<br>旧版本信息：|类名：WebHeader;<br>方法or属性：interface WebHeader<br>新版本信息：crossplatform|@ohos.web.webview.d.ts|
|跨平台能力有变化|类名：WebHeader;<br>方法or属性：headerKey: string;<br>旧版本信息：|类名：WebHeader;<br>方法or属性：headerKey: string;<br>新版本信息：crossplatform|@ohos.web.webview.d.ts|
|跨平台能力有变化|类名：WebHeader;<br>方法or属性：headerValue: string;<br>旧版本信息：|类名：WebHeader;<br>方法or属性：headerValue: string;<br>新版本信息：crossplatform|@ohos.web.webview.d.ts|
|跨平台能力有变化|类名：WebviewController;<br>方法or属性：class WebviewController<br>旧版本信息：|类名：WebviewController;<br>方法or属性：class WebviewController<br>新版本信息：crossplatform|@ohos.web.webview.d.ts|
|跨平台能力有变化|类名：WebviewController;<br>方法or属性：loadUrl(url: string \| Resource, headers?: Array\<WebHeader>): void;<br>旧版本信息：|类名：WebviewController;<br>方法or属性：loadUrl(url: string \| Resource, headers?: Array\<WebHeader>): void;<br>新版本信息：crossplatform|@ohos.web.webview.d.ts|
|跨平台能力有变化|类名：WebResourceRequest;<br>方法or属性：declare class WebResourceRequest<br>旧版本信息：|类名：WebResourceRequest;<br>方法or属性：declare class WebResourceRequest<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebResourceRequest;<br>方法or属性：constructor();<br>旧版本信息：|类名：WebResourceRequest;<br>方法or属性：constructor();<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebResourceError;<br>方法or属性：constructor();<br>旧版本信息：|类名：WebResourceError;<br>方法or属性：constructor();<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebResourceRequest;<br>方法or属性：getRequestUrl(): string;<br>旧版本信息：|类名：WebResourceRequest;<br>方法or属性：getRequestUrl(): string;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebResourceError;<br>方法or属性：declare class WebResourceError<br>旧版本信息：|类名：WebResourceError;<br>方法or属性：declare class WebResourceError<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebResourceError;<br>方法or属性：getErrorInfo(): string;<br>旧版本信息：|类名：WebResourceError;<br>方法or属性：getErrorInfo(): string;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebResourceError;<br>方法or属性：getErrorCode(): number;<br>旧版本信息：|类名：WebResourceError;<br>方法or属性：getErrorCode(): number;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebOptions;<br>方法or属性：declare interface WebOptions<br>旧版本信息：|类名：WebOptions;<br>方法or属性：declare interface WebOptions<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebOptions;<br>方法or属性：src: string \| Resource;<br>旧版本信息：|类名：WebOptions;<br>方法or属性：src: string \| Resource;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebOptions;<br>方法or属性：controller: WebController \| WebviewController;<br>旧版本信息：|类名：WebOptions;<br>方法or属性：controller: WebController \| WebviewController;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebInterface;<br>方法or属性：interface WebInterface<br>旧版本信息：|类名：WebInterface;<br>方法or属性：interface WebInterface<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebInterface;<br>方法or属性：(value: WebOptions): WebAttribute;<br>旧版本信息：|类名：WebInterface;<br>方法or属性：(value: WebOptions): WebAttribute;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebAttribute;<br>方法or属性：declare class WebAttribute<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：declare class WebAttribute<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebAttribute;<br>方法or属性：javaScriptAccess(javaScriptAccess: boolean): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：javaScriptAccess(javaScriptAccess: boolean): WebAttribute;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebAttribute;<br>方法or属性：zoomAccess(zoomAccess: boolean): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：zoomAccess(zoomAccess: boolean): WebAttribute;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebAttribute;<br>方法or属性：onPageEnd(callback: (event?: {<br>    /**<br>     * The url of page.<br>     *<br>     * @syscap SystemCapability.Web.Webview.Core<br>     * @crossplatform<br>     * @since 10<br>     */<br>    url: string<br>  }) => void): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：onPageEnd(callback: (event?: {<br>    /**<br>     * The url of page.<br>     *<br>     * @syscap SystemCapability.Web.Webview.Core<br>     * @crossplatform<br>     * @since 10<br>     */<br>    url: string<br>  }) => void): WebAttribute;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebAttribute;<br>方法or属性：onPageBegin(callback: (event?: {<br>    /**<br>     * The url of page.<br>     *<br>     * @syscap SystemCapability.Web.Webview.Core<br>     * @crossplatform<br>     * @since 10<br>     */<br>    url: string<br>  }) => void): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：onPageBegin(callback: (event?: {<br>    /**<br>     * The url of page.<br>     *<br>     * @syscap SystemCapability.Web.Webview.Core<br>     * @crossplatform<br>     * @since 10<br>     */<br>    url: string<br>  }) => void): WebAttribute;<br>新版本信息：crossplatform|web.d.ts|
|跨平台能力有变化|类名：WebAttribute;<br>方法or属性：onErrorReceive(callback: (event?: {<br>    /**<br>     * The url of error event.<br>     *<br>     * @syscap SystemCapability.Web.Webview.Core<br>     * @crossplatform<br>     * @since 10<br>     */<br>    request: WebResourceRequest,<br>    /**<br>     * The information of error event.<br>     *<br>     * @syscap SystemCapability.Web.Webview.Core<br>     * @crossplatform<br>     * @since 10<br>     */<br>    error: WebResourceError<br>  }) => void): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：onErrorReceive(callback: (event?: {<br>    /**<br>     * The url of error event.<br>     *<br>     * @syscap SystemCapability.Web.Webview.Core<br>     * @crossplatform<br>     * @since 10<br>     */<br>    request: WebResourceRequest,<br>    /**<br>     * The information of error event.<br>     *<br>     * @syscap SystemCapability.Web.Webview.Core<br>     * @crossplatform<br>     * @since 10<br>     */<br>    error: WebResourceError<br>  }) => void): WebAttribute;<br>新版本信息：crossplatform|web.d.ts|
