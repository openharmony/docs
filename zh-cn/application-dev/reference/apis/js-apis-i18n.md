# 国际化-I18n

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> - I18N模块包含国际化能力增强接口（未在ECMA 402中定义）。


## 导入模块

```
import i18n from '@ohos.i18n';
```


## 权限

无


## i18n.getDisplayLanguage

getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string

获取指定语言的本地化显示文本。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | language | string | 是 | 指定语言 |
  | locale | string | 是 | 显示指定语言的区域ID |
  | sentenceCase | boolean | 否 | 本地化显示文本是否要首字母大写 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 指定语言的本地化显示文本 |

- 示例：
  ```
  i18n.getDisplayLanguage("zh", "en-GB", true);
  i18n.getDisplayLanguage("zh", "en-GB");
  ```


## i18n.getDisplayCountry

getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string

获取指定国家的本地化显示文本。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | country | string | 是 | 指定国家 |
  | locale | string | 是 | 显示指定国家的区域ID |
  | sentenceCase | boolean | 否 | 本地化显示文本是否要首字母大写 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 指定国家的本地化显示文本 |

- 示例：
  ```
  i18n.getDisplayCountry("zh-CN", "en-GB", true);
  i18n.getDisplayCountry("zh-CN", "en-GB");
  ```


## i18n.getSystemLanguage

getSystemLanguage(): string

获取系统语言。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 系统语言ID |

- 示例：
  ```
  i18n.getSystemLanguage();
  ```


## i18n.getSystemRegion

getSystemRegion(): string

获取系统地区。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 系统地区ID |

- 示例：
  ```
  i18n.getSystemRegion();
  ```


## i18n.getSystemLocale

getSystemLocale(): string

获取系统区域。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 系统区域ID |

- 示例：
  ```
  i18n.getSystemLocale();
  ```
