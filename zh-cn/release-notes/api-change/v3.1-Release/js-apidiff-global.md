# 全球化子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，全球化子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| rawFileDescriptor | RawFileDescriptor | length: number; | 新增 |
| rawFileDescriptor | RawFileDescriptor | offset: number; | 新增 |
| rawFileDescriptor | RawFileDescriptor | fd: number; | 新增 |
| ohos.resourceManager | ResourceManager | release(); | 新增 |
| ohos.resourceManager | ResourceManager | closeRawFileDescriptor(path: string, callback: AsyncCallback\<void>): void;<br>closeRawFileDescriptor(path: string): Promise\<void>; | 新增 |
| ohos.resourceManager | ResourceManager | getRawFileDescriptor(path: string, callback: AsyncCallback\<RawFileDescriptor>): void;<br>getRawFileDescriptor(path: string): Promise\<RawFileDescriptor>; | 新增 |
| ohos.resourceManager | ResourceManager | getRawFile(path: string, callback: AsyncCallback\<Uint8Array>): void;<br>getRawFile(path: string): Promise\<Uint8Array>; | 新增 |
| ohos.resourceManager | resourceManager | getResourceManager(callback: AsyncCallback\<ResourceManager>): void;<br>getResourceManager(bundleName: string, callback: AsyncCallback\<ResourceManager>): void;<br>getResourceManager(): Promise\<ResourceManager>;<br>getResourceManager(bundleName: string): Promise\<ResourceManager>; | 新增 |
| ohos.intl | RelativeTimeFormat | resolvedOptions(): RelativeTimeFormatResolvedOptions; | 新增 |
| ohos.intl | RelativeTimeFormat | formatToParts(value: number, unit: string): Array\<object>; | 新增 |
| ohos.intl | RelativeTimeFormat | format(value: number, unit: string): string; | 新增 |
| ohos.intl | RelativeTimeFormat | constructor(); | 新增 |
| ohos.intl | RelativeTimeFormatResolvedOptions | numberingSystem: string; | 新增 |
| ohos.intl | RelativeTimeFormatResolvedOptions | numeric: string; | 新增 |
| ohos.intl | RelativeTimeFormatResolvedOptions | style: string; | 新增 |
| ohos.intl | RelativeTimeFormatResolvedOptions | locale: string; | 新增 |
| ohos.intl | RelativeTimeFormatInputOptions | style: string; | 新增 |
| ohos.intl | RelativeTimeFormatInputOptions | numeric: string; | 新增 |
| ohos.intl | RelativeTimeFormatInputOptions | localeMatcher: string; | 新增 |
| ohos.intl | PluralRules | select(n: number): string; | 新增 |
| ohos.intl | PluralRules | constructor(); | 新增 |
| ohos.intl | PluralRulesOptions | maximumSignificantDigits: number; | 新增 |
| ohos.intl | PluralRulesOptions | minimumSignificantDigits: number; | 新增 |
| ohos.intl | PluralRulesOptions | maximumFractionDigits: number; | 新增 |
| ohos.intl | PluralRulesOptions | minimumFractionDigits: number; | 新增 |
| ohos.intl | PluralRulesOptions | minimumIntegerDigits: number; | 新增 |
| ohos.intl | PluralRulesOptions | type: string; | 新增 |
| ohos.intl | PluralRulesOptions | localeMatcher: string; | 新增 |
| ohos.intl | Collator | resolvedOptions(): CollatorOptions; | 新增 |
| ohos.intl | Collator | compare(first: string, second: string): number; | 新增 |
| ohos.intl | Collator | constructor(); | 新增 |
| ohos.intl | CollatorOptions | caseFirst: string; | 新增 |
| ohos.intl | CollatorOptions | numeric: boolean; | 新增 |
| ohos.intl | CollatorOptions | collation: string; | 新增 |
| ohos.intl | CollatorOptions | ignorePunctuation: boolean; | 新增 |
| ohos.intl | CollatorOptions | sensitivity: string; | 新增 |
| ohos.intl | CollatorOptions | usage: string; | 新增 |
| ohos.intl | CollatorOptions | localeMatcher: string; | 新增 |
| ohos.intl | NumberOptions | unitUsage: string | 新增 |
| ohos.intl | LocaleOptions | caseFirst: string; | 新增 |
| ohos.intl | LocaleOptions | numeric: boolean; | 新增 |
| ohos.intl | LocaleOptions | numberingSystem: string; | 新增 |
| ohos.intl | LocaleOptions | hourCycle: string; | 新增 |
| ohos.intl | LocaleOptions | collation: string; | 新增 |
| ohos.intl | LocaleOptions | calendar: string; | 新增 |
| ohos.i18n | TimeZone | getOffset(date?: number): number; | 新增 |
| ohos.i18n | TimeZone | getRawOffset(): number; | 新增 |
| ohos.i18n | TimeZone | getDisplayName(locale?: string, isDST?: boolean): string; | 新增 |
| ohos.i18n | TimeZone | getID(): string; | 新增 |
| ohos.i18n | i18n | getTimeZone(zoneID?: string): TimeZone; | 新增 |
| ohos.i18n | i18n | getFirstPreferredLanguage(): string; | 新增 |
| ohos.i18n | i18n | getPreferredLanguageList(): Array\<string>; | 新增 |
| ohos.i18n | i18n | removePreferredLanguage(index: number): boolean; | 新增 |
| ohos.i18n | i18n | addPreferredLanguage(language: string, index?: number): boolean; | 新增 |
| ohos.i18n | i18n | set24HourClock(option: boolean): boolean; | 新增 |
| ohos.i18n | i18n | is24HourClock(): boolean; | 新增 |
| ohos.i18n | Character | getType(char: string): string; | 新增 |
| ohos.i18n | Character | isUpperCase(char: string): boolean; | 新增 |
| ohos.i18n | Character | isLowerCase(char: string): boolean; | 新增 |
| ohos.i18n | Character | isLetter(char: string): boolean; | 新增 |
| ohos.i18n | Character | isIdeograph(char: string): boolean; | 新增 |
| ohos.i18n | Character | isRTL(char: string): boolean; | 新增 |
| ohos.i18n | Character | isWhitespace(char: string): boolean; | 新增 |
| ohos.i18n | Character | isSpaceChar(char: string): boolean; | 新增 |
| ohos.i18n | Character | isDigit(char: string): boolean; | 新增 |
| ohos.i18n | IndexUtil | getIndex(text: string): string; | 新增 |
| ohos.i18n | IndexUtil | addLocale(locale: string): void; | 新增 |
| ohos.i18n | IndexUtil | getIndexList(): Array\<string>; | 新增 |
| ohos.i18n | i18n | getInstance(locale?:string): IndexUtil; | 新增 |
| ohos.i18n | BreakIterator | isBoundary(offset: number): boolean; | 新增 |
| ohos.i18n | BreakIterator | getLineBreakText(): string; | 新增 |
| ohos.i18n | BreakIterator | following(offset: number): number; | 新增 |
| ohos.i18n | BreakIterator | setLineBreakText(text: string): void; | 新增 |
| ohos.i18n | BreakIterator | previous(): number; | 新增 |
| ohos.i18n | BreakIterator | next(index?: number): number; | 新增 |
| ohos.i18n | BreakIterator | last(): number; | 新增 |
| ohos.i18n | BreakIterator | first(): number; | 新增 |
| ohos.i18n | BreakIterator | current(): number; | 新增 |
| ohos.i18n | i18n | getLineInstance(locale: string): BreakIterator; | 新增 |
| ohos.i18n | i18n | isRTL(locale: string): boolean; | 新增 |
| ohos.i18n | Calendar | isWeekend(date?: Date): boolean; | 新增 |
| ohos.i18n | Calendar | getDisplayName(locale: string): string; | 新增 |
| ohos.i18n | Calendar | get(field: string): number; | 新增 |
| ohos.i18n | Calendar | setMinimalDaysInFirstWeek(value: number): void; | 新增 |
| ohos.i18n | Calendar | getMinimalDaysInFirstWeek(): number; | 新增 |
| ohos.i18n | Calendar | setFirstDayOfWeek(value: number): void; | 新增 |
| ohos.i18n | Calendar | getFirstDayOfWeek(): number; | 新增 |
| ohos.i18n | Calendar | getTimeZone(): string; | 新增 |
| ohos.i18n | Calendar | setTimeZone(timezone: string): void; | 新增 |
| ohos.i18n | Calendar | set(year: number, month: number, date:number, hour?: number, minute?: number, second?: number): void; | 新增 |
| ohos.i18n | Calendar | setTime(date: Date): void;<br>setTime(time: number): void; | 新增 |
| ohos.i18n | i18n | getCalendar(locale: string, type?: string): Calendar; | 新增 |
| ohos.i18n | PhoneNumberFormat | format(number: string): string; | 新增 |
| ohos.i18n | PhoneNumberFormat | isValidNumber(number: string): boolean; | 新增 |
| ohos.i18n | PhoneNumberFormat | constructor(country: string, options?: PhoneNumberFormatOptions); | 新增 |
| ohos.i18n | PhoneNumberFormatOptions | type: string; | 新增 |
| ohos.i18n | UnitInfo | measureSystem: string | 新增 |
| ohos.i18n | UnitInfo | unit: string | 新增 |
| ohos.i18n | Util | unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string; | 新增 |
