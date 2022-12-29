# JS API Changes of the Globalization Subsystem

The table below lists the APIs changes of the globalization subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.i18n | Unicode  | static getType(char: string): string;                                                                            | Added|
| ohos.i18n | Unicode  | static isUpperCase(char: string): boolean;                                                                       | Added|
| ohos.i18n | Unicode  | static isLowerCase(char: string): boolean;                                                                       | Added|
| ohos.i18n | Unicode  | static isLetter(char: string): boolean;                                                                          | Added|
| ohos.i18n | Unicode  | static isIdeograph(char: string): boolean;                                                                       | Added|
| ohos.i18n | Unicode  | static isRTL(char: string): boolean;                                                                             | Added|
| ohos.i18n | Unicode  | static isWhitespace(char: string): boolean;                                                                      | Added|
| ohos.i18n | Unicode  | static isSpaceChar(char: string): boolean;                                                                       | Added|
| ohos.i18n | Unicode  | static isDigit(char: string): boolean;                                                                           | Added|
| ohos.i18n | I18NUtil | static getDateOrder(locale: string): string;                                                                     | Added|
| ohos.i18n | I18NUtil | static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string; | Added|
| ohos.i18n | Util | getDateOrder(locale: string): string; | Deleted|
| ohos.i18n | Character | getType(char: string): string;                                                                            | Deprecated|
| ohos.i18n | Character | isUpperCase(char: string): boolean;                                                                       | Deprecated|
| ohos.i18n | Character | isLowerCase(char: string): boolean;                                                                       | Deprecated|
| ohos.i18n | Character | isLetter(char: string): boolean;                                                                          | Deprecated|
| ohos.i18n | Character | isIdeograph(char: string): boolean;                                                                       | Deprecated|
| ohos.i18n | Character | isRTL(char: string): boolean;                                                                             | Deprecated|
| ohos.i18n | Character | isWhitespace(char: string): boolean;                                                                      | Deprecated|
| ohos.i18n | Character | isSpaceChar(char: string): boolean;                                                                       | Deprecated|
| ohos.i18n | Character | isDigit(char: string): boolean;                                                                           | Deprecated|
| ohos.i18n | Util      | unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string; | Deprecated|
