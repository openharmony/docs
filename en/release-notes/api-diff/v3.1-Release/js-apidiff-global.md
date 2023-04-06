# JS API Changes of the Globalization Subsystem

The table below lists the APIs changes of the globalization subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| rawFileDescriptor | RawFileDescriptor | length: number; | Added|
| rawFileDescriptor | RawFileDescriptor | offset: number; | Added|
| rawFileDescriptor | RawFileDescriptor | fd: number; | Added|
| ohos.resourceManager | ResourceManager | release(); | Added|
| ohos.resourceManager | ResourceManager | closeRawFileDescriptor(path: string, callback: AsyncCallback\<void>): void;<br>closeRawFileDescriptor(path: string): Promise\<void>; | Added|
| ohos.resourceManager | ResourceManager | getRawFileDescriptor(path: string, callback: AsyncCallback\<RawFileDescriptor>): void;<br>getRawFileDescriptor(path: string): Promise\<RawFileDescriptor>; | Added|
| ohos.resourceManager | ResourceManager | getRawFile(path: string, callback: AsyncCallback\<Uint8Array>): void;<br>getRawFile(path: string): Promise\<Uint8Array>; | Added|
| ohos.resourceManager | resourceManager | getResourceManager(callback: AsyncCallback\<ResourceManager>): void;<br>getResourceManager(bundleName: string, callback: AsyncCallback\<ResourceManager>): void;<br>getResourceManager(): Promise\<ResourceManager>;<br>getResourceManager(bundleName: string): Promise\<ResourceManager>; | Added|
| ohos.intl | RelativeTimeFormat | resolvedOptions(): RelativeTimeFormatResolvedOptions; | Added|
| ohos.intl | RelativeTimeFormat | formatToParts(value: number, unit: string): Array\<object>; | Added|
| ohos.intl | RelativeTimeFormat | format(value: number, unit: string): string; | Added|
| ohos.intl | RelativeTimeFormat | constructor(); | Added|
| ohos.intl | RelativeTimeFormatResolvedOptions | numberingSystem: string; | Added|
| ohos.intl | RelativeTimeFormatResolvedOptions | numeric: string; | Added|
| ohos.intl | RelativeTimeFormatResolvedOptions | style: string; | Added|
| ohos.intl | RelativeTimeFormatResolvedOptions | locale: string; | Added|
| ohos.intl | RelativeTimeFormatInputOptions | style: string; | Added|
| ohos.intl | RelativeTimeFormatInputOptions | numeric: string; | Added|
| ohos.intl | RelativeTimeFormatInputOptions | localeMatcher: string; | Added|
| ohos.intl | PluralRules | select(n: number): string; | Added|
| ohos.intl | PluralRules | constructor(); | Added|
| ohos.intl | PluralRulesOptions | maximumSignificantDigits: number; | Added|
| ohos.intl | PluralRulesOptions | minimumSignificantDigits: number; | Added|
| ohos.intl | PluralRulesOptions | maximumFractionDigits: number; | Added|
| ohos.intl | PluralRulesOptions | minimumFractionDigits: number; | Added|
| ohos.intl | PluralRulesOptions | minimumIntegerDigits: number; | Added|
| ohos.intl | PluralRulesOptions | type: string; | Added|
| ohos.intl | PluralRulesOptions | localeMatcher: string; | Added|
| ohos.intl | Collator | resolvedOptions(): CollatorOptions; | Added|
| ohos.intl | Collator | compare(first: string, second: string): number; | Added|
| ohos.intl | Collator | constructor(); | Added|
| ohos.intl | CollatorOptions | caseFirst: string; | Added|
| ohos.intl | CollatorOptions | numeric: boolean; | Added|
| ohos.intl | CollatorOptions | collation: string; | Added|
| ohos.intl | CollatorOptions | ignorePunctuation: boolean; | Added|
| ohos.intl | CollatorOptions | sensitivity: string; | Added|
| ohos.intl | CollatorOptions | usage: string; | Added|
| ohos.intl | CollatorOptions | localeMatcher: string; | Added|
| ohos.intl | NumberOptions | unitUsage: string | Added|
| ohos.intl | LocaleOptions | caseFirst: string; | Added|
| ohos.intl | LocaleOptions | numeric: boolean; | Added|
| ohos.intl | LocaleOptions | numberingSystem: string; | Added|
| ohos.intl | LocaleOptions | hourCycle: string; | Added|
| ohos.intl | LocaleOptions | collation: string; | Added|
| ohos.intl | LocaleOptions | calendar: string; | Added|
| ohos.i18n | TimeZone | getOffset(date?: number): number; | Added|
| ohos.i18n | TimeZone | getRawOffset(): number; | Added|
| ohos.i18n | TimeZone | getDisplayName(locale?: string, isDST?: boolean): string; | Added|
| ohos.i18n | TimeZone | getID(): string; | Added|
| ohos.i18n | i18n | getTimeZone(zoneID?: string): TimeZone; | Added|
| ohos.i18n | i18n | getFirstPreferredLanguage(): string; | Added|
| ohos.i18n | i18n | getPreferredLanguageList(): Array\<string>; | Added|
| ohos.i18n | i18n | removePreferredLanguage(index: number): boolean; | Added|
| ohos.i18n | i18n | addPreferredLanguage(language: string, index?: number): boolean; | Added|
| ohos.i18n | i18n | set24HourClock(option: boolean): boolean; | Added|
| ohos.i18n | i18n | is24HourClock(): boolean; | Added|
| ohos.i18n | Character | getType(char: string): string; | Added|
| ohos.i18n | Character | isUpperCase(char: string): boolean; | Added|
| ohos.i18n | Character | isLowerCase(char: string): boolean; | Added|
| ohos.i18n | Character | isLetter(char: string): boolean; | Added|
| ohos.i18n | Character | isIdeograph(char: string): boolean; | Added|
| ohos.i18n | Character | isRTL(char: string): boolean; | Added|
| ohos.i18n | Character | isWhitespace(char: string): boolean; | Added|
| ohos.i18n | Character | isSpaceChar(char: string): boolean; | Added|
| ohos.i18n | Character | isDigit(char: string): boolean; | Added|
| ohos.i18n | IndexUtil | getIndex(text: string): string; | Added|
| ohos.i18n | IndexUtil | addLocale(locale: string): void; | Added|
| ohos.i18n | IndexUtil | getIndexList(): Array\<string>; | Added|
| ohos.i18n | i18n | getInstance(locale?:string): IndexUtil; | Added|
| ohos.i18n | BreakIterator | isBoundary(offset: number): boolean; | Added|
| ohos.i18n | BreakIterator | getLineBreakText(): string; | Added|
| ohos.i18n | BreakIterator | following(offset: number): number; | Added|
| ohos.i18n | BreakIterator | setLineBreakText(text: string): void; | Added|
| ohos.i18n | BreakIterator | previous(): number; | Added|
| ohos.i18n | BreakIterator | next(index?: number): number; | Added|
| ohos.i18n | BreakIterator | last(): number; | Added|
| ohos.i18n | BreakIterator | first(): number; | Added|
| ohos.i18n | BreakIterator | current(): number; | Added|
| ohos.i18n | i18n | getLineInstance(locale: string): BreakIterator; | Added|
| ohos.i18n | i18n | isRTL(locale: string): boolean; | Added|
| ohos.i18n | Calendar | isWeekend(date?: Date): boolean; | Added|
| ohos.i18n | Calendar | getDisplayName(locale: string): string; | Added|
| ohos.i18n | Calendar | get(field: string): number; | Added|
| ohos.i18n | Calendar | setMinimalDaysInFirstWeek(value: number): void; | Added|
| ohos.i18n | Calendar | getMinimalDaysInFirstWeek(): number; | Added|
| ohos.i18n | Calendar | setFirstDayOfWeek(value: number): void; | Added|
| ohos.i18n | Calendar | getFirstDayOfWeek(): number; | Added|
| ohos.i18n | Calendar | getTimeZone(): string; | Added|
| ohos.i18n | Calendar | setTimeZone(timezone: string): void; | Added|
| ohos.i18n | Calendar | set(year: number, month: number, date:number, hour?: number, minute?: number, second?: number): void; | Added|
| ohos.i18n | Calendar | setTime(date: Date): void;<br>setTime(time: number): void; | Added|
| ohos.i18n | i18n | getCalendar(locale: string, type?: string): Calendar; | Added|
| ohos.i18n | PhoneNumberFormat | format(number: string): string; | Added|
| ohos.i18n | PhoneNumberFormat | isValidNumber(number: string): boolean; | Added|
| ohos.i18n | PhoneNumberFormat | constructor(country: string, options?: PhoneNumberFormatOptions); | Added|
| ohos.i18n | PhoneNumberFormatOptions | type: string; | Added|
| ohos.i18n | UnitInfo | measureSystem: string | Added|
| ohos.i18n | UnitInfo | unit: string | Added|
| ohos.i18n | Util | unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string; | Added|
