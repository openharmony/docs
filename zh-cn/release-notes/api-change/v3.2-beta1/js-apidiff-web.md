# Web子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，Web子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 函数 | 变更类型 |
|---|---|---|---|
| web | WebAttribute | onShowFileSelector(callback: (event?: { result: FileSelectorResult, fileSelector: FileSelectorParam }) => boolean): WebAttribute; | 新增 |
| web | WebAttribute | webDebuggingAccess(webDebuggingAccess: boolean): WebAttribute; | 新增 |
| web | WebAttribute | fileFromUrlAccess(fileFromUrlAccess: boolean): WebAttribute; | 新增 |
| web | WebAttribute | onRenderExited(callback: (event?: { renderExitReason: RenderExitReason }) => void): WebAttribute; | 新增 |
| web | WebController | getCookieManager() : WebCookie | 新增 |
| web | WebCookie | deleteExpiredCookie(): void; | 新增 |
| web | WebCookie | deleteSessionCookie(): void; | 新增 |
| web | WebCookie | deleteEntireCookie(): void; | 新增 |
| web | WebCookie | existCookie(): boolean; | 新增 |
| web | WebCookie | getCookie(url: string): string; | 新增 |
| web | WebCookie | saveCookieSync(): boolean; | 新增 |
| web | WebCookie | putAcceptFileURICookieEnabled(accept: boolean): void; | 新增 |
| web | WebCookie | putAcceptThirdPartyCookieEnabled(accept: boolean): void; | 新增 |
| web | WebCookie | putAcceptCookieEnabled(accept: boolean): void; | 新增 |
| web | WebCookie | isFileURICookieAllowed(): boolean; | 新增 |
| web | WebCookie | isThirdPartyCookieAllowed(): boolean; | 新增 |
| web | WebCookie | isCookieAllowed(): boolean; | 新增 |
| web | WebCookie | setCookie(url: string, value: string): boolean; | 新增 |
| web | FileSelectorResult | handleFileList(fileList: Array\<string>): void; | 新增 |
| web | FileSelectorResult | constructor(); | 新增 |
| web | FileSelectorParam | isCapture(): boolean; | 新增 |
| web | FileSelectorParam | getAcceptType(): Array\<string>; | 新增 |
| web | FileSelectorParam | getMode(): FileSelectorMode; | 新增 |
| web | FileSelectorParam | getTitle(): string; | 新增 |
| web | FileSelectorParam | constructor(); | 新增 |
| web | FileSelectorMode | FileSaveMode | 新增 |
| web | FileSelectorMode | FileOpenFolderMode | 新增 |
| web | FileSelectorMode | FileOpenMultipleMode | 新增 |
| web | FileSelectorMode | FileOpenMode | 新增 |
| web | RenderExitReason | ProcessExitUnknown | 新增 |
| web | RenderExitReason | ProcessOom | 新增 |
| web | RenderExitReason | ProcessCrashed | 新增 |
| web | RenderExitReason | ProcessWasKilled | 新增 |
| web | RenderExitReason | ProcessAbnormalTermination | 新增 |
| web | CacheMode | Default | 新增 |
| web | WebAttribute | onFileSelectorShow(callback: (event?: { callback: Function, fileSelector: object }) => void): WebAttribute; | 废弃 |
| web | WebAttribute | onSslErrorReceive(callback: (event?: { handler: Function, error: object }) => void): WebAttribute; | 废弃 |
| web | WebAttribute | onRenderExited(callback: (event?: { detail: object }) => boolean): WebAttribute; | 废弃 |
| web | WebCookie | saveCookie(); | 废弃 |
| web | WebCookie | setCookie(); | 废弃 |