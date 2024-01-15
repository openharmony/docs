# Time Zone Name Localization

## Use Cases

In a multi-language environment, time zones may be addressed by users in different regions in different ways. Therefore, your application needs to localize time zone names to adapt to local user habits.

## How to Develop

For details about how to use related APIs, see [getDisplayName](../reference/apis/js-apis-i18n.md#getdisplayname8). The development procedure is as follows:

1. Import the **i18n** module.
   ```ts
   import I18n from '@ohos.i18n';
   ```

2. Localize the time zone name, for example, **America/Sao_Paulo**.
   ```ts
   let timezone = I18n.getTimeZone("America/Sao_Paulo");
   let timeZoneName = timezone.getDisplayName("zh-Hans", true); // Brasilia Standard Time
   ```
