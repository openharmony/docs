# @system.configuration (Application Configuration)

> **NOTE**
> - The APIs of this module are deprecated since API version 7. You are advised to use [@ohos.i18n](../apis-localization-kit/js-apis-i18n.md) and [@ohos.intl](../apis-localization-kit/js-apis-intl.md) instead.
>
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```ts
import Configuration from '@system.configuration';
```


## configuration.getLocale

static getLocale(): LocaleResponse

Obtains the current locale of the application, which is the same as the system locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Return value**
| Type           | Description           |
| -------------- | ------------- |
| LocaleResponse | Current locale information. |

**Example**
  ```
  export default {    
    getLocale() {        
      const localeInfo = configuration.getLocale();        
      console.info(localeInfo.language);    
    }
  }
  ```


## LocaleResponse

Defines attributes of the current locale.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

| Name  | Type  | Readable  | Writable  | Description                                      |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| language | string | Yes   | No   | Language, for example, **zh**. |
| countryOrRegion | string | Yes   | No   | Country or region, for example, **CN** or **US**. |
| dir | string | Yes   | No   | Text layout direction. The value can be:<br>- **ltr**: from left to right<br>- **rtl**: from right to left |
