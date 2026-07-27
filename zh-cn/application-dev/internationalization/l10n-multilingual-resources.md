# 多语言适配

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

## 功能介绍

当应用需要提供给不同国家和地区的用户使用时，为了满足这些用户在语言、文化方面的需求，需要将应用进行本地化定制，使应用加载和显示符合所在地域使用习惯的内容。本地化过程中需要对语言和地区名称、时间日期、数字单位、文本字符、图片、音频、视频等进行适配。

语言和地区名称、时间日期、数字单位的适配，建议使用国际化接口获取显示的内容。因为区域使用习惯可能会发生变化，国际化接口返回值也会随之变化，不建议进一步处理接口的返回值。

文本字符、图片、音频、视频的适配，建议创建多个不同的资源目录，配置多语言资源。当用户运行应用时，系统根据语言区域自动选择并加载与设备最匹配的资源。

## 国际化接口使用

- 本地化接口调用

  为了确保接口返回值与用户设置保持一致，通常需要在[国际化-I18n](../reference/apis-localization-kit/js-apis-i18n.md)和[国际化-Intl](../reference/apis-localization-kit/js-apis-intl.md)接口中传入系统区域ID或系统区域对象。系统区域ID和系统区域对象传入的示例如下：

  ``` TypeScript
  import { i18n } from '@kit.LocalizationKit';

  // 获取系统区域对象
  let locale = i18n.System.getSystemLocaleInstance();

  // 如果接口入参是区域ID（string类型），则通过toString()获取系统区域ID
  let dateTimeFormat = new Intl.DateTimeFormat(locale.toString());

  // 如果接口入参是区域对象（Intl.Locale类型），则直接使用系统区域对象
  let simpleDateTimeFormat = i18n.getSimpleDateTimeFormatBySkeleton('yMd', locale);
  ```

- 识别系统语言

  应用如果需要识别语言，应避免通过硬编码的方式直接比较语言码。推荐使用如下方式：

  ``` TypeScript
  import { i18n } from '@kit.LocalizationKit';

  let systemLanguage = i18n.System.getSimplifiedLanguage();
  // languagesList根据应用实际需要进行配置。例如，当应用不需要区分不同的繁体中文时，可将'zh-Hant-HK'和'zh-Hant-TW'合并成'zh-Hant'
  let languagesList = ['zh-Hans', 'zh-Hant-HK', 'zh-Hant-TW'];
  let matchedLanguage = i18n.I18NUtil.getBestMatchLocale(systemLanguage, languagesList);
  switch (matchedLanguage) {
    case 'zh-Hans':
      // 系统语言为简体中文
      break;
    case 'zh-Hant-HK':
      // 系统语言为繁体中文（香港）
      break;
    case 'zh-Hant-TW':
      // 系统语言为繁体中文（台湾）
      break;
    default:
      // 系统语言不属于languagesList中的任何一种
  }
  ```

## 多语言资源配置

为确保应用可以加载到不同国家和地区、不同语言等类型的内容，需要创建多个不同的资源目录，放置多种资源，当用户运行应用时，根据所在的语言区域自动选择并加载与设备最匹配的资源。为更好实现应用本地化，推荐做法是将本地化的内容与核心功能尽可能分开，本地化内容放置在资源目录下。

对于应用开发者，仅需关注资源配置，资源文件配置完成后，根据业务需求对资源进行访问。资源文件配置和资源匹配规则请参考[资源分类与访问](../quick-start/resource-categories-and-access.md)。

>**说明**
>
>如果设置了应用偏好语言，应用会优先加载应用偏好语言对应的资源。
