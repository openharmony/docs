# 全球化子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，全球化子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.i18n | Unicode  | static getType(char: string): string;                                                                            | 新增 |
| ohos.i18n | Unicode  | static isUpperCase(char: string): boolean;                                                                       | 新增 |
| ohos.i18n | Unicode  | static isLowerCase(char: string): boolean;                                                                       | 新增 |
| ohos.i18n | Unicode  | static isLetter(char: string): boolean;                                                                          | 新增 |
| ohos.i18n | Unicode  | static isIdeograph(char: string): boolean;                                                                       | 新增 |
| ohos.i18n | Unicode  | static isRTL(char: string): boolean;                                                                             | 新增 |
| ohos.i18n | Unicode  | static isWhitespace(char: string): boolean;                                                                      | 新增 |
| ohos.i18n | Unicode  | static isSpaceChar(char: string): boolean;                                                                       | 新增 |
| ohos.i18n | Unicode  | static isDigit(char: string): boolean;                                                                           | 新增 |
| ohos.i18n | I18NUtil | static getDateOrder(locale: string): string;                                                                     | 新增 |
| ohos.i18n | I18NUtil | static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string; | 新增 |
| ohos.i18n | Util | getDateOrder(locale: string): string; | 删除 |
| ohos.i18n | Character | getType(char: string): string;                                                                            | 废弃 |
| ohos.i18n | Character | isUpperCase(char: string): boolean;                                                                       | 废弃 |
| ohos.i18n | Character | isLowerCase(char: string): boolean;                                                                       | 废弃 |
| ohos.i18n | Character | isLetter(char: string): boolean;                                                                          | 废弃 |
| ohos.i18n | Character | isIdeograph(char: string): boolean;                                                                       | 废弃 |
| ohos.i18n | Character | isRTL(char: string): boolean;                                                                             | 废弃 |
| ohos.i18n | Character | isWhitespace(char: string): boolean;                                                                      | 废弃 |
| ohos.i18n | Character | isSpaceChar(char: string): boolean;                                                                       | 废弃 |
| ohos.i18n | Character | isDigit(char: string): boolean;                                                                           | 废弃 |
| ohos.i18n | Util      | unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string; | 废弃 |
