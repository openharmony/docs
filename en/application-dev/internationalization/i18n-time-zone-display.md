# Time Zone Name Localization

## Use Cases

In a multi-language environment, time zones may be addressed by users in different regions in different ways. To this end, your application needs to localize time zone names to adapt to local user habits.

## How to Develop

For details about how to use related APIs, see [getDisplayName](../reference/apis-localization-kit/js-apis-i18n.md#getdisplayname8).

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Localize the time zone name, for example, **America/Sao_Paulo**.
   ```ts
   let timezone: i18n.TimeZone = i18n.getTimeZone('America/Sao_Paulo');
   let timeZoneName: string = timezone.getDisplayName ('zh-Hans', true); // timeZoneName ='Brasília Standard Time'
   ```
