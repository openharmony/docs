# Application Configuration

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> - The APIs of this module are no longer maintained since API version 7. It is recommended that you use [`@ohos.i18n`](js-apis-i18n.md) and [`@ohos.intl`](js-apis-intl.md) instead.
>
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import configuration from '@system.configuration';
```


## configuration.getLocale

getLocale(): &lt;LocaleResponse&gt;

Obtains the current locale of the application, which is the same as the system locale.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Return values**
**Table 1** LocaleResponse

| Name | Type | Description |
| -------- | -------- | -------- |
| language | string | Current&nbsp;language&nbsp;of&nbsp;the&nbsp;application,&nbsp;for&nbsp;example,&nbsp;**zh**. |
| countryOrRegion | string | Country&nbsp;or&nbsp;region,&nbsp;for&nbsp;example,&nbsp;**CN**. |
| dir | string | Text&nbsp;layout&nbsp;direction.&nbsp;Available&nbsp;values&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;**ltr**:&nbsp;The&nbsp;text&nbsp;direction&nbsp;is&nbsp;from&nbsp;left&nbsp;to&nbsp;right.<br/>-&nbsp;**rtl**:&nbsp;The&nbsp;text&nbsp;direction&nbsp;is&nbsp;from&nbsp;right&nbsp;to&nbsp;left. |
| unicodeSetting<sup>5+</sup> | string | Unicode&nbsp;key&nbsp;set&nbsp;determined&nbsp;by&nbsp;the&nbsp;locale.<br/>For&nbsp;example,&nbsp;**{"nu":"arab"}**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;current&nbsp;locale&nbsp;uses&nbsp;Arabic&nbsp;numerals.<br/>If&nbsp;the&nbsp;current&nbsp;locale&nbsp;does&nbsp;not&nbsp;have&nbsp;a&nbsp;specific&nbsp;key&nbsp;set,&nbsp;an&nbsp;empty&nbsp;set&nbsp;is&nbsp;returned. |

**Example**

```
export default {    
  getLocale() {        
    const localeInfo = configuration.getLocale();        
    console.info(localeInfo.language);    
  }
}
```