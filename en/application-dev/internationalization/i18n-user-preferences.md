# User Preferences

## Use Cases

In addition to system locales and preferred languages, the system also supports user preference settings. Currently, it offers two such preferences: whether to use local digits and whether to adopt the 12/24-hour time format. User preference settings are saved to system locales and application preferred languages as part of the internationalization feature.

## How to Develop

For details about how to use related APIs, see [System](../reference/apis-localization-kit/js-apis-i18n.md#system9).

1. Import the **intl** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   import { BusinessError, commonEventManager } from '@kit.BasicServicesKit';
   ```

2. Obtain user preferences.
   ```ts
   // Check whether use of local digits is enabled.
   let usingLocalDigit: boolean = i18n.System.getUsingLocalDigit();

   // Check whether use of the 24-hour time format is enabled.
   let is24HourClock: boolean = i18n.System.is24HourClock();

   // Subscribe to COMMON_EVENT_TIME_CHANGED events to detect system time format changes.
   let subscriber: commonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.
   let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
     events: [commonEventManager.Support.COMMON_EVENT_TIME_CHANGED]
   };
   // Create a subscriber.
   commonEventManager.createSubscriber(subscribeInfo)
     .then((commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
       console.info("CreateSubscriber");
       subscriber = commonEventSubscriber;
       commonEventManager.subscribe(subscriber, (err, data) => {
         if (err) {
           console.error(`Failed to subscribe common event. error code: ${err.code}, message: ${err.message}.`);
           return;
         }
         // Distinguish between system time and system time format changes.
         if (data.data != undefined && data.data == '24HourChange') {
            console.info("The subscribed event has occurred."); // The system time format has changed.
          }
       })
     })
     .catch((err: BusinessError) => {
       console.error(`CreateSubscriber failed, code is ${err.code}, message is ${err.message}`);
     });
   ```

<!--Del-->
3. Enable use of local digits.
   ```ts
   try {
     i18n.System.setUsingLocalDigit(true); // Enable use of local digits.
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```

4. Enable use of the 24-hour time format.
   ```ts
   try {
     i18n.System.set24HourClock (true); // Set the system time to the 24-hour clock.
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```
<!--DelEnd-->
