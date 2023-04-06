# JS API Changes of the Web Subsystem

The table below lists the APIs changes of the web subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Function| Change Type|
|---|---|---|---|
| web | WebAttribute | onShowFileSelector(callback: (event?: { result: FileSelectorResult, fileSelector: FileSelectorParam }) => boolean): WebAttribute; | Added|
| web | WebAttribute | webDebuggingAccess(webDebuggingAccess: boolean): WebAttribute; | Added|
| web | WebAttribute | fileFromUrlAccess(fileFromUrlAccess: boolean): WebAttribute; | Added|
| web | WebAttribute | onRenderExited(callback: (event?: { renderExitReason: RenderExitReason }) => void): WebAttribute; | Added|
| web | WebController | getCookieManager() : WebCookie | Added|
| web | WebCookie | deleteExpiredCookie(): void; | Added|
| web | WebCookie | deleteSessionCookie(): void; | Added|
| web | WebCookie | deleteEntireCookie(): void; | Added|
| web | WebCookie | existCookie(): boolean; | Added|
| web | WebCookie | getCookie(url: string): string; | Added|
| web | WebCookie | saveCookieSync(): boolean; | Added|
| web | WebCookie | putAcceptFileURICookieEnabled(accept: boolean): void; | Added|
| web | WebCookie | putAcceptThirdPartyCookieEnabled(accept: boolean): void; | Added|
| web | WebCookie | putAcceptCookieEnabled(accept: boolean): void; | Added|
| web | WebCookie | isFileURICookieAllowed(): boolean; | Added|
| web | WebCookie | isThirdPartyCookieAllowed(): boolean; | Added|
| web | WebCookie | isCookieAllowed(): boolean; | Added|
| web | WebCookie | setCookie(url: string, value: string): boolean; | Added|
| web | FileSelectorResult | handleFileList(fileList: Array\<string>): void; | Added|
| web | FileSelectorResult | constructor(); | Added|
| web | FileSelectorParam | isCapture(): boolean; | Added|
| web | FileSelectorParam | getAcceptType(): Array\<string>; | Added|
| web | FileSelectorParam | getMode(): FileSelectorMode; | Added|
| web | FileSelectorParam | getTitle(): string; | Added|
| web | FileSelectorParam | constructor(); | Added|
| web | FileSelectorMode | FileSaveMode | Added|
| web | FileSelectorMode | FileOpenFolderMode | Added|
| web | FileSelectorMode | FileOpenMultipleMode | Added|
| web | FileSelectorMode | FileOpenMode | Added|
| web | RenderExitReason | ProcessExitUnknown | Added|
| web | RenderExitReason | ProcessOom | Added|
| web | RenderExitReason | ProcessCrashed | Added|
| web | RenderExitReason | ProcessWasKilled | Added|
| web | RenderExitReason | ProcessAbnormalTermination | Added|
| web | CacheMode | Default | Added|
| web | WebAttribute | onFileSelectorShow(callback: (event?: { callback: Function, fileSelector: object }) => void): WebAttribute; | Deprecated|
| web | WebAttribute | onSslErrorReceive(callback: (event?: { handler: Function, error: object }) => void): WebAttribute; | Deprecated|
| web | WebAttribute | onRenderExited(callback: (event?: { detail: object }) => boolean): WebAttribute; | Deprecated|
| web | WebCookie | saveCookie(); | Deprecated|
| web | WebCookie | setCookie(); | Deprecated|
