# 杂散软件服务子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，杂散软件服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.wallpaper | RgbaColor | alpha: number; | 新增 |
| ohos.wallpaper | RgbaColor | blue: number; | 新增 |
| ohos.wallpaper | RgbaColor | green: number; | 新增 |
| ohos.wallpaper | RgbaColor | red: number; | 新增 |
| ohos.wallpaper | wallpaper | function off(type: 'colorChange', callback?: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void; | 新增 |
| ohos.wallpaper | wallpaper | function on(type: 'colorChange', callback: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void; | 新增 |
| ohos.wallpaper | wallpaper | function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>; | 新增 |
| ohos.wallpaper | wallpaper | function reset(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>function reset(wallpaperType: WallpaperType): Promise\<void>; | 新增 |
| ohos.wallpaper | wallpaper | function isOperationAllowed(callback: AsyncCallback\<boolean>): void;<br>function isOperationAllowed(): Promise\<boolean>; | 新增 |
| ohos.wallpaper | wallpaper | function isChangePermitted(callback: AsyncCallback\<boolean>): void;<br>function isChangePermitted(): Promise\<boolean>; | 新增 |
| ohos.wallpaper | wallpaper | function getMinWidth(callback: AsyncCallback\<number>): void;<br>function getMinWidth(): Promise\<number>; | 新增 |
| ohos.wallpaper | wallpaper | function getMinHeight(callback: AsyncCallback\<number>): void;<br>function getMinHeight(): Promise\<number>; | 新增 |
| ohos.wallpaper | wallpaper | function getFile(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>function getFile(wallpaperType: WallpaperType): Promise\<number>; | 新增 |
| ohos.wallpaper | wallpaper | function getId(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>function getId(wallpaperType: WallpaperType): Promise\<number>; | 新增 |
| ohos.wallpaper | wallpaper | function getColors(wallpaperType: WallpaperType, callback: AsyncCallback\<Array\<RgbaColor>>): void;<br>function getColors(wallpaperType: WallpaperType): Promise\<Array\<RgbaColor>>; | 新增 |
| ohos.wallpaper | WallpaperType | WALLPAPER_LOCKSCREEN | 新增 |
| ohos.wallpaper | WallpaperType | WALLPAPER_SYSTEM | 新增 |
| ohos.systemTime | systemTime | function getTimezone(callback: AsyncCallback\<string>): void;<br>function getTimezone(): Promise\<string>; | 新增 |
| ohos.systemTime | systemTime | function getDate(callback: AsyncCallback\<Date>): void;<br>function getDate(): Promise\<Date>; | 新增 |
| ohos.systemTime | systemTime | function getRealTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>function getRealTime(isNano?: boolean): Promise\<number>; | 新增 |
| ohos.systemTime | systemTime | function getRealActiveTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>function getRealActiveTime(isNano?: boolean): Promise\<number>; | 新增 |
| ohos.systemTime | systemTime | function getCurrentTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>function getCurrentTime(isNano?: boolean): Promise\<number>; | 新增 |
| ohos.screenLock | screenLock | function unlockScreen(callback: AsyncCallback\<void>): void;<br>function unlockScreen():Promise\<void>; | 新增 |
| ohos.screenLock | screenLock | function isSecureMode(callback: AsyncCallback\<boolean>): void;<br>function isSecureMode(): Promise\<boolean>; | 新增 |
| ohos.screenLock | screenLock | function isScreenLocked(callback: AsyncCallback\<boolean>): void;<br>function isScreenLocked(): Promise\<boolean>; | 新增 |
| ohos.request | UploadTask | remove(callback: AsyncCallback\<boolean>): void;<br>remove(): Promise\<boolean>; | 新增 |
| ohos.request | UploadTask | off(type: 'headerReceive', callback?: (header: object) => void): void; | 新增 |
| ohos.request | UploadTask | on(type: 'headerReceive', callback: (header: object) => void): void; | 新增 |
| ohos.request | UploadTask | off(type: 'progress', callback?: (uploadedSize: number, totalSize: number) => void): void; | 新增 |
| ohos.request | UploadTask | on(type: 'progress', callback: (uploadedSize: number, totalSize: number) => void): void; | 新增 |
| ohos.request | UploadConfig | data: Array\<RequestData>; | 新增 |
| ohos.request | UploadConfig | files: Array\<File>; | 新增 |
| ohos.request | UploadConfig | method: string; | 新增 |
| ohos.request | UploadConfig | header: Object; | 新增 |
| ohos.request | UploadConfig | url: string; | 新增 |
| ohos.request | RequestData | value: string; | 新增 |
| ohos.request | RequestData | name: string; | 新增 |
| ohos.request | File | type: string; | 新增 |
| ohos.request | File | uri: string; | 新增 |
| ohos.request | File | name: string; | 新增 |
| ohos.request | File | filename: string; | 新增 |
| ohos.request | DownloadTask | queryMimeType(callback: AsyncCallback\<string>): void;<br>queryMimeType(): Promise\<string>; | 新增 |
| ohos.request | DownloadTask | query(callback: AsyncCallback\<DownloadInfo>): void;<br>query(): Promise\<DownloadInfo>; | 新增 |
| ohos.request | DownloadTask | resume(callback: AsyncCallback\<void>): void;<br>resume(): Promise\<void>; | 新增 |
| ohos.request | DownloadTask | pause(callback: AsyncCallback\<void>): void;<br>pause(): Promise\<void>; | 新增 |
| ohos.request | DownloadTask | remove(callback: AsyncCallback\<boolean>): void;<br>remove(): Promise\<boolean>; | 新增 |
| ohos.request | DownloadTask | off(type: 'fail', callback?: (err: number) => void): void; | 新增 |
| ohos.request | DownloadTask | on(type: 'fail', callback: (err: number) => void): void; | 新增 |
| ohos.request | DownloadTask | off(type: 'complete' \| 'pause' \| 'remove', callback?: () => void): void; | 新增 |
| ohos.request | DownloadTask | off(type: 'complete' \| 'pause' \| 'remove', callback?: () => void): void; | 新增 |
| ohos.request | DownloadTask | off(type: 'complete' \| 'pause' \| 'remove', callback?: () => void): void; | 新增 |
| ohos.request | DownloadTask | on(type: 'complete' \| 'pause' \| 'remove', callback: () => void): void; | 新增 |
| ohos.request | DownloadTask | on(type: 'complete' \| 'pause' \| 'remove', callback: () => void): void; | 新增 |
| ohos.request | DownloadTask | on(type: 'complete' \| 'pause' \| 'remove', callback: () => void): void; | 新增 |
| ohos.request | DownloadTask | off(type: 'progress', callback?: (receivedSize: number, totalSize: number) => void): void; | 新增 |
| ohos.request | DownloadTask | on(type: 'progress', callback: (receivedSize: number, totalSize: number) => void): void; | 新增 |
| ohos.request | DownloadInfo | downloadTotalBytes: number; | 新增 |
| ohos.request | DownloadInfo | downloadTitle: string; | 新增 |
| ohos.request | DownloadInfo | targetURI: string; | 新增 |
| ohos.request | DownloadInfo | status: number; | 新增 |
| ohos.request | DownloadInfo | pausedReason: number; | 新增 |
| ohos.request | DownloadInfo | filePath: string; | 新增 |
| ohos.request | DownloadInfo | fileName: string; | 新增 |
| ohos.request | DownloadInfo | failedReason: number; | 新增 |
| ohos.request | DownloadInfo | downloadId: number; | 新增 |
| ohos.request | DownloadInfo | downloadedBytes: number; | 新增 |
| ohos.request | DownloadInfo | description: string; | 新增 |
| ohos.request | DownloadConfig | title?: string; | 新增 |
| ohos.request | DownloadConfig | filePath?: string; | 新增 |
| ohos.request | DownloadConfig | networkType?: number; | 新增 |
| ohos.request | DownloadConfig | description?: string; | 新增 |
| ohos.request | DownloadConfig | enableRoaming?: boolean; | 新增 |
| ohos.request | DownloadConfig | enableMetered?: boolean; | 新增 |
| ohos.request | DownloadConfig | header?: Object; | 新增 |
| ohos.request | DownloadConfig | url: string; | 新增 |
| ohos.request | request | function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>function upload(config: UploadConfig): Promise\<UploadTask>; | 新增 |
| ohos.request | request | function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>function download(config: DownloadConfig): Promise\<DownloadTask>; | 新增 |
| ohos.request | request | const SESSION_SUCCESSFUL: number; | 新增 |
| ohos.request | request | const SESSION_RUNNING: number; | 新增 |
| ohos.request | request | const SESSION_PENDING: number; | 新增 |
| ohos.request | request | const SESSION_PAUSED: number; | 新增 |
| ohos.request | request | const SESSION_FAILED: number; | 新增 |
| ohos.request | request | const PAUSED_WAITING_TO_RETRY: number; | 新增 |
| ohos.request | request | const PAUSED_WAITING_FOR_NETWORK: number; | 新增 |
| ohos.request | request | const PAUSED_UNKNOWN: number; | 新增 |
| ohos.request | request | const PAUSED_QUEUED_FOR_WIFI: number; | 新增 |
| ohos.request | request | const ERROR_UNKNOWN: number; | 新增 |
| ohos.request | request | const ERROR_UNHANDLED_HTTP_CODE: number; | 新增 |
| ohos.request | request | const ERROR_TOO_MANY_REDIRECTS: number; | 新增 |
| ohos.request | request | const ERROR_INSUFFICIENT_SPACE: number; | 新增 |
| ohos.request | request | const ERROR_HTTP_DATA_ERROR: number; | 新增 |
| ohos.request | request | const ERROR_FILE_ERROR: number; | 新增 |
| ohos.request | request | const ERROR_FILE_ALREADY_EXISTS: number; | 新增 |
| ohos.request | request | const ERROR_DEVICE_NOT_FOUND: number; | 新增 |
| ohos.request | request | const ERROR_CANNOT_RESUME: number; | 新增 |
| ohos.request | request | const NETWORK_WIFI: number; | 新增 |
| ohos.request | request | const NETWORK_MOBILE: number; | 新增 |
| ohos.pasteboard | SystemPasteboard | setPasteData(data: PasteData, callback: AsyncCallback\<void>): void;<br>setPasteData(data: PasteData): Promise\<void>; | 新增 |
| ohos.pasteboard | SystemPasteboard | hasPasteData(callback: AsyncCallback\<boolean>): void;<br>hasPasteData(): Promise\<boolean>; | 新增 |
| ohos.pasteboard | SystemPasteboard | getPasteData(callback: AsyncCallback\<PasteData>): void;<br>getPasteData(): Promise\<PasteData>; | 新增 |
| ohos.pasteboard | SystemPasteboard | clear(callback: AsyncCallback\<void>): void;<br>clear(): Promise\<void>; | 新增 |
| ohos.pasteboard | SystemPasteboard | off(type: 'update', callback?: () => void): void; | 新增 |
| ohos.pasteboard | SystemPasteboard | on(type: 'update', callback: () => void): void; | 新增 |
| ohos.pasteboard | PasteData | replaceRecordAt(index: number, record: PasteDataRecord): boolean; | 新增 |
| ohos.pasteboard | PasteData | removeRecordAt(index: number): boolean; | 新增 |
| ohos.pasteboard | PasteData | hasMimeType(mimeType: string): boolean; | 新增 |
| ohos.pasteboard | PasteData | getTag(): string; | 新增 |
| ohos.pasteboard | PasteData | getRecordCount(): number; | 新增 |
| ohos.pasteboard | PasteData | getRecordAt(index: number): PasteDataRecord; | 新增 |
| ohos.pasteboard | PasteData | getProperty(): PasteDataProperty; | 新增 |
| ohos.pasteboard | PasteData | getPrimaryUri(): string; | 新增 |
| ohos.pasteboard | PasteData | getPrimaryText(): string; | 新增 |
| ohos.pasteboard | PasteData | getPrimaryMimeType(): string; | 新增 |
| ohos.pasteboard | PasteData | getPrimaryWant(): Want; | 新增 |
| ohos.pasteboard | PasteData | getPrimaryHtml(): string; | 新增 |
| ohos.pasteboard | PasteData | getMimeTypes(): Array\<string>; | 新增 |
| ohos.pasteboard | PasteData | addUriRecord(uri: string): void; | 新增 |
| ohos.pasteboard | PasteData | addTextRecord(text: string): void; | 新增 |
| ohos.pasteboard | PasteData | addRecord(record: PasteDataRecord): void; | 新增 |
| ohos.pasteboard | PasteData | addWantRecord(want: Want): void; | 新增 |
| ohos.pasteboard | PasteData | addHtmlRecord(htmlText: string): void; | 新增 |
| ohos.pasteboard | PasteDataRecord | convertToText(callback: AsyncCallback\<string>): void;<br>convertToText(): Promise\<string>; | 新增 |
| ohos.pasteboard | PasteDataRecord | uri: string; | 新增 |
| ohos.pasteboard | PasteDataRecord | plainText: string; | 新增 |
| ohos.pasteboard | PasteDataRecord | mimeType: string; | 新增 |
| ohos.pasteboard | PasteDataRecord | want: Want; | 新增 |
| ohos.pasteboard | PasteDataRecord | htmlText: string; | 新增 |
| ohos.pasteboard | PasteDataProperty | localOnly: boolean; | 新增 |
| ohos.pasteboard | PasteDataProperty | readonly timestamp: number; | 新增 |
| ohos.pasteboard | PasteDataProperty | tag: string; | 新增 |
| ohos.pasteboard | PasteDataProperty | readonly mimeTypes: Array\<string>; | 新增 |
| ohos.pasteboard | PasteDataProperty | additions: {  [key: string]: object } | 新增 |
| ohos.pasteboard | pasteboard | function getSystemPasteboard(): SystemPasteboard; | 新增 |
| ohos.pasteboard | pasteboard | function createUriRecord(uri: string): PasteDataRecord; | 新增 |
| ohos.pasteboard | pasteboard | function createPlainTextRecord(text: string): PasteDataRecord; | 新增 |
| ohos.pasteboard | pasteboard | function createWantRecord(want: Want): PasteDataRecord; | 新增 |
| ohos.pasteboard | pasteboard | function createHtmlTextRecord(htmlText: string): PasteDataRecord; | 新增 |
| ohos.pasteboard | pasteboard | function createUriData(uri: string): PasteData; | 新增 |
| ohos.pasteboard | pasteboard | function createPlainTextData(text: string): PasteData; | 新增 |
| ohos.pasteboard | pasteboard | function createWantData(want: Want): PasteData; | 新增 |
| ohos.pasteboard | pasteboard | function createHtmlData(htmlText: string): PasteData; | 新增 |
| ohos.pasteboard | pasteboard | const MIMETYPE_TEXT_URI: string; | 新增 |
| ohos.pasteboard | pasteboard | const MIMETYPE_TEXT_PLAIN: string; | 新增 |
| ohos.pasteboard | pasteboard | const MIMETYPE_TEXT_WANT: string; | 新增 |
| ohos.pasteboard | pasteboard | const MIMETYPE_TEXT_HTML: string; | 新增 |
| ohos.pasteboard | pasteboard | const MAX_RECORD_NUM: number; | 新增 |
| ohos.inputmethodengine | KeyEvent | readonly keyAction: number; | 新增 |
| ohos.inputmethodengine | KeyEvent | readonly keyCode: number; | 新增 |
| ohos.inputmethodengine | EditorAttribute | readonly enterKeyType: number; | 新增 |
| ohos.inputmethodengine | EditorAttribute | readonly inputPattern: number; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'textChange', callback?: (text: string) => void): void; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'textChange', callback: (text: string) => void): void; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'cursorContextChange', callback: (x: number, y: number, height: number) => void): void; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void; | 新增 |
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void; | 新增 |
| ohos.inputmethodengine | TextInputClient | getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void;<br>getEditorAttribute(): Promise\<EditorAttribute>; | 新增 |
| ohos.inputmethodengine | TextInputClient | getBackward(length: number, callback: AsyncCallback\<string>): void;<br>getBackward(length: number): Promise\<string>; | 新增 |
| ohos.inputmethodengine | TextInputClient | getForward(length: number, callback: AsyncCallback\<string>): void;<br>getForward(length: number): Promise\<string>; | 新增 |
| ohos.inputmethodengine | TextInputClient | insertText(text: string, callback: AsyncCallback\<boolean>): void;<br>insertText(text: string): Promise\<boolean>; | 新增 |
| ohos.inputmethodengine | TextInputClient | deleteBackward(length: number, callback: AsyncCallback\<boolean>): void;<br>deleteBackward(length: number): Promise\<boolean>; | 新增 |
| ohos.inputmethodengine | TextInputClient | deleteForward(length: number, callback: AsyncCallback\<boolean>): void;<br>deleteForward(length: number): Promise\<boolean>; | 新增 |
| ohos.inputmethodengine | TextInputClient | sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void;<br>sendKeyFunction(action: number): Promise\<boolean>; | 新增 |
| ohos.inputmethodengine | InputMethodEngine | off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void; | 新增 |
| ohos.inputmethodengine | InputMethodEngine | off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void; | 新增 |
| ohos.inputmethodengine | InputMethodEngine | on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void; | 新增 |
| ohos.inputmethodengine | InputMethodEngine | on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void; | 新增 |
| ohos.inputmethodengine | InputMethodEngine | off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void; | 新增 |
| ohos.inputmethodengine | InputMethodEngine | on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void; | 新增 |
| ohos.inputmethodengine | KeyboardController | hideKeyboard(callback: AsyncCallback\<void>): void;<br>hideKeyboard(): Promise\<void>; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | function createKeyboardDelegate(): KeyboardDelegate; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | function getInputMethodEngine(): InputMethodEngine; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const OPTION_NO_FULLSCREEN: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const OPTION_MULTI_LINE: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const OPTION_AUTO_WORDS: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const OPTION_AUTO_CAP_SENTENCES: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const OPTION_AUTO_CAP_CHARACTERS: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const OPTION_NONE: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const OPTION_ASCII: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const DISPLAY_MODE_FULL: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const DISPLAY_MODE_PART: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const FLAG_SINGLE_LINE: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const FLAG_SELECTING: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_PASSWORD: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_URI: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_EMAIL: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_DATETIME: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_PHONE: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_NUMBER: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_TEXT: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_NULL: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_PREVIOUS: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_DONE: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_NEXT: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_SEND: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_SEARCH: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_GO: number; | 新增 |
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_UNSPECIFIED: number; | 新增 |
| ohos.inputmethod | InputMethodProperty | readonly methodId: string; | 新增 |
| ohos.inputmethod | InputMethodProperty | readonly packageName: string; | 新增 |
| ohos.inputmethod | InputMethodController | stopInput(callback: AsyncCallback\<boolean>): void;<br>stopInput(): Promise\<boolean>; | 新增 |
| ohos.inputmethod | InputMethodSetting | displayOptionalInputMethod(callback: AsyncCallback\<void>): void;<br>displayOptionalInputMethod(): Promise\<void>; | 新增 |
| ohos.inputmethod | InputMethodSetting | listInputMethod(callback: AsyncCallback\<Array\<InputMethodProperty>>): void;<br>listInputMethod(): Promise\<Array\<InputMethodProperty>>; | 新增 |
| ohos.inputmethod | inputMethod | function getInputMethodController(): InputMethodController; | 新增 |
| ohos.inputmethod | inputMethod | function getInputMethodSetting(): InputMethodSetting; | 新增 |
| ohos.inputmethod | inputMethod | const MAX_TYPE_NUM: number | 新增 |
