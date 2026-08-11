# Multilingual Adaptation

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=8646aa1336046b33104c69d7005ba94aef0319fe translatedAt=2026-08-04T12:27:05.943Z pushedAt=2026-08-04T13:22:09.233Z -->

## Use Cases

When an app is to be provided to users in different countries and regions, the app needs to be localized to meet the language and cultural requirements of these users, so that it loads and displays content that conforms to local usage habits. During localization, adaptation is required for language and region names, dates and times, number units, text characters, images, audio, video, and other elements.

For the adaptation of language and region names, dates and times, and number units, you are advised to use internationalization interfaces to obtain the display content. Since regional usage habits may change, the return values of internationalization interfaces may also change accordingly. Do not further process the return values of these interfaces.

For the adaptation of text characters, images, audio, and video, you are advised to create multiple resource directories and configure multilingual resources. When a user runs the app, the system automatically selects and loads the resources that best match the device based on the locale.

## Using Internationalization Interfaces

- Calling localization interfaces

  To ensure that the interface return values are consistent with user settings, you usually need to pass the system locale ID or system locale object to the [@ohos.i18n (Internationalization-I18n)](../reference/apis-localization-kit/js-apis-i18n.md) and [@ohos.intl (Internationalization-Intl)](../reference/apis-localization-kit/js-apis-intl.md) interfaces. The following example shows how to pass the system locale ID and system locale object:

  ``` TypeScript
  import { i18n } from '@kit.LocalizationKit';

  // Obtain the system locale object.
  let locale = i18n.System.getSystemLocaleInstance();

  // If the API input parameter is a locale ID (string type), obtain the system locale ID through toString().
  let dateTimeFormat = new Intl.DateTimeFormat(locale.toString());

  // If the API input parameter is a locale object (Intl.Locale type), use the system locale object directly.
  let simpleDateTimeFormat = i18n.getSimpleDateTimeFormatBySkeleton('yMd', locale);
  ```

- Identifying the system language

  If an app needs to identify the language, avoid directly comparing language codes through hardcoding. The following approach is recommended:

  ``` TypeScript
  import { i18n } from '@kit.LocalizationKit';

  let systemLanguage = i18n.System.getSimplifiedLanguage();
  // languagesList is configured based on actual app requirements. For example, when the app does not need to distinguish between different Traditional Chinese variants, 'zh-Hant-HK' and 'zh-Hant-TW' can be merged into 'zh-Hant'.
  let languagesList = ['zh-Hans', 'zh-Hant-HK', 'zh-Hant-TW'];
  let matchedLanguage = i18n.I18NUtil.getBestMatchLocale(systemLanguage, languagesList);
  switch (matchedLanguage) {
    case 'zh-Hans':
      // The system language is Simplified Chinese.
      break;
    case 'zh-Hant-HK':
      // The system language is Traditional Chinese (Hong Kong).
      break;
    case 'zh-Hant-TW':
      // The system language is Traditional Chinese (Taiwan).
      break;
    default:
      // The system language does not belong to any language in languagesList.
  }
  ```

## Multilingual Resource Configuration

To ensure that an app can load content of different countries, regions, and languages, you need to create multiple resource directories and place various resources in them. When a user runs the app, the system automatically selects and loads the resources that best match the device based on the locale. To better implement app localization, the recommended practice is to separate the localized content from the core functions as much as possible and place the localized content in resource directories.

As an app developer, you only need to focus on resource configuration. After resource files are configured, access the resources based on your service requirements. For details about resource file configuration and resource matching rules, see [Resource Categories and Access](../quick-start/resource-categories-and-access.md).

> **NOTE**
>
> If an app preferred language is set, the app loads the resources corresponding to the app preferred language first.