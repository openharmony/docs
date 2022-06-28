# JS API Changes of the Misc Services Subsystem

The table below lists the APIs changes of the Misc services subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.wallpaper | RgbaColor | alpha: number; | Added|
| ohos.wallpaper | RgbaColor | blue: number; | Added|
| ohos.wallpaper | RgbaColor | green: number; | Added|
| ohos.wallpaper | RgbaColor | red: number; | Added|
| ohos.wallpaper | wallpaper | function off(type: 'colorChange', callback?: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void; | Added|
| ohos.wallpaper | wallpaper | function on(type: 'colorChange', callback: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void; | Added|
| ohos.wallpaper | wallpaper | function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>; | Added|
| ohos.wallpaper | wallpaper | function reset(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>function reset(wallpaperType: WallpaperType): Promise\<void>; | Added|
| ohos.wallpaper | wallpaper | function isOperationAllowed(callback: AsyncCallback\<boolean>): void;<br>function isOperationAllowed(): Promise\<boolean>; | Added|
| ohos.wallpaper | wallpaper | function isChangePermitted(callback: AsyncCallback\<boolean>): void;<br>function isChangePermitted(): Promise\<boolean>; | Added|
| ohos.wallpaper | wallpaper | function getMinWidth(callback: AsyncCallback\<number>): void;<br>function getMinWidth(): Promise\<number>; | Added|
| ohos.wallpaper | wallpaper | function getMinHeight(callback: AsyncCallback\<number>): void;<br>function getMinHeight(): Promise\<number>; | Added|
| ohos.wallpaper | wallpaper | function getFile(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>function getFile(wallpaperType: WallpaperType): Promise\<number>; | Added|
| ohos.wallpaper | wallpaper | function getId(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>function getId(wallpaperType: WallpaperType): Promise\<number>; | Added|
| ohos.wallpaper | wallpaper | function getColors(wallpaperType: WallpaperType, callback: AsyncCallback\<Array\<RgbaColor>>): void;<br>function getColors(wallpaperType: WallpaperType): Promise\<Array\<RgbaColor>>; | Added|
| ohos.wallpaper | WallpaperType | WALLPAPER_LOCKSCREEN | Added|
| ohos.wallpaper | WallpaperType | WALLPAPER_SYSTEM | Added|
| ohos.systemTime | systemTime | function getTimezone(callback: AsyncCallback\<string>): void;<br>function getTimezone(): Promise\<string>; | Added|
| ohos.systemTime | systemTime | function getDate(callback: AsyncCallback\<Date>): void;<br>function getDate(): Promise\<Date>; | Added|
| ohos.systemTime | systemTime | function getRealTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>function getRealTime(isNano?: boolean): Promise\<number>; | Added|
| ohos.systemTime | systemTime | function getRealActiveTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>function getRealActiveTime(isNano?: boolean): Promise\<number>; | Added|
| ohos.systemTime | systemTime | function getCurrentTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>function getCurrentTime(isNano?: boolean): Promise\<number>; | Added|
| ohos.screenLock | screenLock | function unlockScreen(callback: AsyncCallback\<void>): void;<br>function unlockScreen():Promise\<void>; | Added|
| ohos.screenLock | screenLock | function isSecureMode(callback: AsyncCallback\<boolean>): void;<br>function isSecureMode(): Promise\<boolean>; | Added|
| ohos.screenLock | screenLock | function isScreenLocked(callback: AsyncCallback\<boolean>): void;<br>function isScreenLocked(): Promise\<boolean>; | Added|
| ohos.request | UploadTask | remove(callback: AsyncCallback\<boolean>): void;<br>remove(): Promise\<boolean>; | Added|
| ohos.request | UploadTask | off(type: 'headerReceive', callback?: (header: object) => void): void; | Added|
| ohos.request | UploadTask | on(type: 'headerReceive', callback: (header: object) => void): void; | Added|
| ohos.request | UploadTask | off(type: 'progress', callback?: (uploadedSize: number, totalSize: number) => void): void; | Added|
| ohos.request | UploadTask | on(type: 'progress', callback: (uploadedSize: number, totalSize: number) => void): void; | Added|
| ohos.request | UploadConfig | data: Array\<RequestData>; | Added|
| ohos.request | UploadConfig | files: Array\<File>; | Added|
| ohos.request | UploadConfig | method: string; | Added|
| ohos.request | UploadConfig | header: Object; | Added|
| ohos.request | UploadConfig | url: string; | Added|
| ohos.request | RequestData | value: string; | Added|
| ohos.request | RequestData | name: string; | Added|
| ohos.request | File | type: string; | Added|
| ohos.request | File | uri: string; | Added|
| ohos.request | File | name: string; | Added|
| ohos.request | File | filename: string; | Added|
| ohos.request | DownloadTask | queryMimeType(callback: AsyncCallback\<string>): void;<br>queryMimeType(): Promise\<string>; | Added|
| ohos.request | DownloadTask | query(callback: AsyncCallback\<DownloadInfo>): void;<br>query(): Promise\<DownloadInfo>; | Added|
| ohos.request | DownloadTask | resume(callback: AsyncCallback\<void>): void;<br>resume(): Promise\<void>; | Added|
| ohos.request | DownloadTask | pause(callback: AsyncCallback\<void>): void;<br>pause(): Promise\<void>; | Added|
| ohos.request | DownloadTask | remove(callback: AsyncCallback\<boolean>): void;<br>remove(): Promise\<boolean>; | Added|
| ohos.request | DownloadTask | off(type: 'fail', callback?: (err: number) => void): void; | Added|
| ohos.request | DownloadTask | on(type: 'fail', callback: (err: number) => void): void; | Added|
| ohos.request | DownloadTask | off(type: 'complete' \| 'pause' \| 'remove', callback?: () => void): void; | Added|
| ohos.request | DownloadTask | off(type: 'complete' \| 'pause' \| 'remove', callback?: () => void): void; | Added|
| ohos.request | DownloadTask | off(type: 'complete' \| 'pause' \| 'remove', callback?: () => void): void; | Added|
| ohos.request | DownloadTask | on(type: 'complete' \| 'pause' \| 'remove', callback: () => void): void; | Added|
| ohos.request | DownloadTask | on(type: 'complete' \| 'pause' \| 'remove', callback: () => void): void; | Added|
| ohos.request | DownloadTask | on(type: 'complete' \| 'pause' \| 'remove', callback: () => void): void; | Added|
| ohos.request | DownloadTask | off(type: 'progress', callback?: (receivedSize: number, totalSize: number) => void): void; | Added|
| ohos.request | DownloadTask | on(type: 'progress', callback: (receivedSize: number, totalSize: number) => void): void; | Added|
| ohos.request | DownloadInfo | downloadTotalBytes: number; | Added|
| ohos.request | DownloadInfo | downloadTitle: string; | Added|
| ohos.request | DownloadInfo | targetURI: string; | Added|
| ohos.request | DownloadInfo | status: number; | Added|
| ohos.request | DownloadInfo | pausedReason: number; | Added|
| ohos.request | DownloadInfo | filePath: string; | Added|
| ohos.request | DownloadInfo | fileName: string; | Added|
| ohos.request | DownloadInfo | failedReason: number; | Added|
| ohos.request | DownloadInfo | downloadId: number; | Added|
| ohos.request | DownloadInfo | downloadedBytes: number; | Added|
| ohos.request | DownloadInfo | description: string; | Added|
| ohos.request | DownloadConfig | title?: string; | Added|
| ohos.request | DownloadConfig | filePath?: string; | Added|
| ohos.request | DownloadConfig | networkType?: number; | Added|
| ohos.request | DownloadConfig | description?: string; | Added|
| ohos.request | DownloadConfig | enableRoaming?: boolean; | Added|
| ohos.request | DownloadConfig | enableMetered?: boolean; | Added|
| ohos.request | DownloadConfig | header?: Object; | Added|
| ohos.request | DownloadConfig | url: string; | Added|
| ohos.request | request | function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>function upload(config: UploadConfig): Promise\<UploadTask>; | Added|
| ohos.request | request | function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>function download(config: DownloadConfig): Promise\<DownloadTask>; | Added|
| ohos.request | request | const SESSION_SUCCESSFUL: number; | Added|
| ohos.request | request | const SESSION_RUNNING: number; | Added|
| ohos.request | request | const SESSION_PENDING: number; | Added|
| ohos.request | request | const SESSION_PAUSED: number; | Added|
| ohos.request | request | const SESSION_FAILED: number; | Added|
| ohos.request | request | const PAUSED_WAITING_TO_RETRY: number; | Added|
| ohos.request | request | const PAUSED_WAITING_FOR_NETWORK: number; | Added|
| ohos.request | request | const PAUSED_UNKNOWN: number; | Added|
| ohos.request | request | const PAUSED_QUEUED_FOR_WIFI: number; | Added|
| ohos.request | request | const ERROR_UNKNOWN: number; | Added|
| ohos.request | request | const ERROR_UNHANDLED_HTTP_CODE: number; | Added|
| ohos.request | request | const ERROR_TOO_MANY_REDIRECTS: number; | Added|
| ohos.request | request | const ERROR_INSUFFICIENT_SPACE: number; | Added|
| ohos.request | request | const ERROR_HTTP_DATA_ERROR: number; | Added|
| ohos.request | request | const ERROR_FILE_ERROR: number; | Added|
| ohos.request | request | const ERROR_FILE_ALREADY_EXISTS: number; | Added|
| ohos.request | request | const ERROR_DEVICE_NOT_FOUND: number; | Added|
| ohos.request | request | const ERROR_CANNOT_RESUME: number; | Added|
| ohos.request | request | const NETWORK_WIFI: number; | Added|
| ohos.request | request | const NETWORK_MOBILE: number; | Added|
| ohos.pasteboard | SystemPasteboard | setPasteData(data: PasteData, callback: AsyncCallback\<void>): void;<br>setPasteData(data: PasteData): Promise\<void>; | Added|
| ohos.pasteboard | SystemPasteboard | hasPasteData(callback: AsyncCallback\<boolean>): void;<br>hasPasteData(): Promise\<boolean>; | Added|
| ohos.pasteboard | SystemPasteboard | getPasteData(callback: AsyncCallback\<PasteData>): void;<br>getPasteData(): Promise\<PasteData>; | Added|
| ohos.pasteboard | SystemPasteboard | clear(callback: AsyncCallback\<void>): void;<br>clear(): Promise\<void>; | Added|
| ohos.pasteboard | SystemPasteboard | off(type: 'update', callback?: () => void): void; | Added|
| ohos.pasteboard | SystemPasteboard | on(type: 'update', callback: () => void): void; | Added|
| ohos.pasteboard | PasteData | replaceRecordAt(index: number, record: PasteDataRecord): boolean; | Added|
| ohos.pasteboard | PasteData | removeRecordAt(index: number): boolean; | Added|
| ohos.pasteboard | PasteData | hasMimeType(mimeType: string): boolean; | Added|
| ohos.pasteboard | PasteData | getTag(): string; | Added|
| ohos.pasteboard | PasteData | getRecordCount(): number; | Added|
| ohos.pasteboard | PasteData | getRecordAt(index: number): PasteDataRecord; | Added|
| ohos.pasteboard | PasteData | getProperty(): PasteDataProperty; | Added|
| ohos.pasteboard | PasteData | getPrimaryUri(): string; | Added|
| ohos.pasteboard | PasteData | getPrimaryText(): string; | Added|
| ohos.pasteboard | PasteData | getPrimaryMimeType(): string; | Added|
| ohos.pasteboard | PasteData | getPrimaryWant(): Want; | Added|
| ohos.pasteboard | PasteData | getPrimaryHtml(): string; | Added|
| ohos.pasteboard | PasteData | getMimeTypes(): Array\<string>; | Added|
| ohos.pasteboard | PasteData | addUriRecord(uri: string): void; | Added|
| ohos.pasteboard | PasteData | addTextRecord(text: string): void; | Added|
| ohos.pasteboard | PasteData | addRecord(record: PasteDataRecord): void; | Added|
| ohos.pasteboard | PasteData | addWantRecord(want: Want): void; | Added|
| ohos.pasteboard | PasteData | addHtmlRecord(htmlText: string): void; | Added|
| ohos.pasteboard | PasteDataRecord | convertToText(callback: AsyncCallback\<string>): void;<br>convertToText(): Promise\<string>; | Added|
| ohos.pasteboard | PasteDataRecord | uri: string; | Added|
| ohos.pasteboard | PasteDataRecord | plainText: string; | Added|
| ohos.pasteboard | PasteDataRecord | mimeType: string; | Added|
| ohos.pasteboard | PasteDataRecord | want: Want; | Added|
| ohos.pasteboard | PasteDataRecord | htmlText: string; | Added|
| ohos.pasteboard | PasteDataProperty | localOnly: boolean; | Added|
| ohos.pasteboard | PasteDataProperty | readonly timestamp: number; | Added|
| ohos.pasteboard | PasteDataProperty | tag: string; | Added|
| ohos.pasteboard | PasteDataProperty | readonly mimeTypes: Array\<string>; | Added|
| ohos.pasteboard | PasteDataProperty | additions: {  [key: string]: object } | Added|
| ohos.pasteboard | pasteboard | function getSystemPasteboard(): SystemPasteboard; | Added|
| ohos.pasteboard | pasteboard | function createUriRecord(uri: string): PasteDataRecord; | Added|
| ohos.pasteboard | pasteboard | function createPlainTextRecord(text: string): PasteDataRecord; | Added|
| ohos.pasteboard | pasteboard | function createWantRecord(want: Want): PasteDataRecord; | Added|
| ohos.pasteboard | pasteboard | function createHtmlTextRecord(htmlText: string): PasteDataRecord; | Added|
| ohos.pasteboard | pasteboard | function createUriData(uri: string): PasteData; | Added|
| ohos.pasteboard | pasteboard | function createPlainTextData(text: string): PasteData; | Added|
| ohos.pasteboard | pasteboard | function createWantData(want: Want): PasteData; | Added|
| ohos.pasteboard | pasteboard | function createHtmlData(htmlText: string): PasteData; | Added|
| ohos.pasteboard | pasteboard | const MIMETYPE_TEXT_URI: string; | Added|
| ohos.pasteboard | pasteboard | const MIMETYPE_TEXT_PLAIN: string; | Added|
| ohos.pasteboard | pasteboard | const MIMETYPE_TEXT_WANT: string; | Added|
| ohos.pasteboard | pasteboard | const MIMETYPE_TEXT_HTML: string; | Added|
| ohos.pasteboard | pasteboard | const MAX_RECORD_NUM: number; | Added|
| ohos.inputmethodengine | KeyEvent | readonly keyAction: number; | Added|
| ohos.inputmethodengine | KeyEvent | readonly keyCode: number; | Added|
| ohos.inputmethodengine | EditorAttribute | readonly enterKeyType: number; | Added|
| ohos.inputmethodengine | EditorAttribute | readonly inputPattern: number; | Added|
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'textChange', callback?: (text: string) => void): void; | Added|
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'textChange', callback: (text: string) => void): void; | Added|
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void; | Added|
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void; | Added|
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void; | Added|
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'cursorContextChange', callback: (x: number, y: number, height: number) => void): void; | Added|
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void; | Added|
| ohos.inputmethodengine | KeyboardDelegate | off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void; | Added|
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void; | Added|
| ohos.inputmethodengine | KeyboardDelegate | on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void; | Added|
| ohos.inputmethodengine | TextInputClient | getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void;<br>getEditorAttribute(): Promise\<EditorAttribute>; | Added|
| ohos.inputmethodengine | TextInputClient | getBackward(length: number, callback: AsyncCallback\<string>): void;<br>getBackward(length: number): Promise\<string>; | Added|
| ohos.inputmethodengine | TextInputClient | getForward(length: number, callback: AsyncCallback\<string>): void;<br>getForward(length: number): Promise\<string>; | Added|
| ohos.inputmethodengine | TextInputClient | insertText(text: string, callback: AsyncCallback\<boolean>): void;<br>insertText(text: string): Promise\<boolean>; | Added|
| ohos.inputmethodengine | TextInputClient | deleteBackward(length: number, callback: AsyncCallback\<boolean>): void;<br>deleteBackward(length: number): Promise\<boolean>; | Added|
| ohos.inputmethodengine | TextInputClient | deleteForward(length: number, callback: AsyncCallback\<boolean>): void;<br>deleteForward(length: number): Promise\<boolean>; | Added|
| ohos.inputmethodengine | TextInputClient | sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void;<br>sendKeyFunction(action: number): Promise\<boolean>; | Added|
| ohos.inputmethodengine | InputMethodEngine | off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void; | Added|
| ohos.inputmethodengine | InputMethodEngine | off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void; | Added|
| ohos.inputmethodengine | InputMethodEngine | on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void; | Added|
| ohos.inputmethodengine | InputMethodEngine | on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void; | Added|
| ohos.inputmethodengine | InputMethodEngine | off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void; | Added|
| ohos.inputmethodengine | InputMethodEngine | on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void; | Added|
| ohos.inputmethodengine | KeyboardController | hideKeyboard(callback: AsyncCallback\<void>): void;<br>hideKeyboard(): Promise\<void>; | Added|
| ohos.inputmethodengine | inputMethodEngine | function createKeyboardDelegate(): KeyboardDelegate; | Added|
| ohos.inputmethodengine | inputMethodEngine | function getInputMethodEngine(): InputMethodEngine; | Added|
| ohos.inputmethodengine | inputMethodEngine | const OPTION_NO_FULLSCREEN: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const OPTION_MULTI_LINE: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const OPTION_AUTO_WORDS: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const OPTION_AUTO_CAP_SENTENCES: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const OPTION_AUTO_CAP_CHARACTERS: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const OPTION_NONE: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const OPTION_ASCII: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const DISPLAY_MODE_FULL: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const DISPLAY_MODE_PART: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const FLAG_SINGLE_LINE: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const FLAG_SELECTING: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_PASSWORD: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_URI: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_EMAIL: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_DATETIME: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_PHONE: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_NUMBER: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_TEXT: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const PATTERN_NULL: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_PREVIOUS: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_DONE: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_NEXT: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_SEND: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_SEARCH: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_GO: number; | Added|
| ohos.inputmethodengine | inputMethodEngine | const ENTER_KEY_TYPE_UNSPECIFIED: number; | Added|
| ohos.inputmethod | InputMethodProperty | readonly methodId: string; | Added|
| ohos.inputmethod | InputMethodProperty | readonly packageName: string; | Added|
| ohos.inputmethod | InputMethodController | stopInput(callback: AsyncCallback\<boolean>): void;<br>stopInput(): Promise\<boolean>; | Added|
| ohos.inputmethod | InputMethodSetting | displayOptionalInputMethod(callback: AsyncCallback\<void>): void;<br>displayOptionalInputMethod(): Promise\<void>; | Added|
| ohos.inputmethod | InputMethodSetting | listInputMethod(callback: AsyncCallback\<Array\<InputMethodProperty>>): void;<br>listInputMethod(): Promise\<Array\<InputMethodProperty>>; | Added|
| ohos.inputmethod | inputMethod | function getInputMethodController(): InputMethodController; | Added|
| ohos.inputmethod | inputMethod | function getInputMethodSetting(): InputMethodSetting; | Added|
| ohos.inputmethod | inputMethod | const MAX_TYPE_NUM: number | Added|
