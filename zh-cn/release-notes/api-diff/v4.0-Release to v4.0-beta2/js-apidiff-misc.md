| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：InputClient;<br>方法or属性：deleteForwardSync(length: number): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：deleteBackwardSync(length: number): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：insertTextSync(text: string): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getForwardSync(length: number): string;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getBackwardSync(length: number): string;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getEditorAttributeSync(): EditorAttribute;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：moveCursorSync(direction: number): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：selectByRangeSync(range: Range): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：selectByMovementSync(movement: Movement): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getTextIndexAtCursorSync(): number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getTime(isNanoseconds?: boolean): number;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getUptime(timeType: TimeType, isNanoseconds?: boolean): number;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getTimezoneSync(): string;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：TimeType;<br>方法or属性：STARTUP|@ohos.systemDateTime.d.ts|
|新增|NA|类名：TimeType;<br>方法or属性：ACTIVE|@ohos.systemDateTime.d.ts|
|废弃版本有变化|类名：PasteDataRecord;<br>方法or属性：convertToText(): Promise\<string>;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：convertToText(): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#convertToTextV9|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：clear(): Promise\<void>;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：clear(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#clearData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：getPasteData(): Promise\<PasteData>;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：getPasteData(): Promise\<PasteData>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#getData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：hasPasteData(): Promise\<boolean>;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：hasPasteData(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#hasData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：setPasteData(data: PasteData): Promise\<void>;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：setPasteData(data: PasteData): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#setData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：systemDateTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>新版本信息：10<br>代替接口： systemDateTime.setTime|@ohos.systemDateTime.d.ts|
|废弃版本有变化|类名：systemDateTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>新版本信息：10<br>代替接口： systemDateTime.setTime|@ohos.systemDateTime.d.ts|
|废弃版本有变化|类名：systemDateTime;<br>方法or属性：function getDate(callback: AsyncCallback\<Date>): void;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function getDate(callback: AsyncCallback\<Date>): void;<br>新版本信息：10<br>代替接口： new|@ohos.systemDateTime.d.ts|
|废弃版本有变化|类名：systemDateTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>新版本信息：10<br>代替接口： new|@ohos.systemDateTime.d.ts|
|错误码有变化|类名：PasteData;<br>方法or属性：addRecord(mimeType: string, value: ValueType): void;<br>旧版本信息：401,12900002|类名：PasteData;<br>方法or属性：addRecord(mimeType: string, value: ValueType): void;<br>新版本信息：401|@ohos.pasteboard.d.ts|
|type有变化|类名：pasteboard;<br>方法or属性：type ValueType = string \| image.PixelMap \| Want \| ArrayBuffer;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：type ValueType = string \| image.PixelMap \| Want \| ArrayBuffer;<br>新版本信息：string \| image.PixelMap \| Want \| ArrayBuffer|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：additions: {<br><br>      [key: string]: object<br><br>    }<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：additions: {<br><br>      [key: string]: object<br><br>    }<br>新版本信息：[key: string]: object|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：readonly mimeTypes: Array\<string>;<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：readonly mimeTypes: Array\<string>;<br>新版本信息：Array\<string>|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：tag: string;<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：tag: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：readonly timestamp: number;<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：readonly timestamp: number;<br>新版本信息：number|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：localOnly: boolean;<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：localOnly: boolean;<br>新版本信息：boolean|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：htmlText: string;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：htmlText: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：want: Want;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：want: Want;<br>新版本信息：Want|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：mimeType: string;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：mimeType: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：plainText: string;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：plainText: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：uri: string;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：uri: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
