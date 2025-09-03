# Setting User Preferences

## Use Cases

In addition to system locales and application preferred languages, the system supports setting of user preferences. Currently, the system supports two user preferences: whether to use local digits and whether to use the 12/24-hour format. User preference settings are saved to system locales and application preferred languages as part of the internationalization feature.

## How to Develop

For details about how to use the APIs, see [System](../reference/apis-localization-kit/js-apis-i18n.md#system9).


   ```ts
   import { i18n } from '@kit.LocalizationKit';
   import { BusinessError, commonEventManager } from '@kit.BasicServicesKit';
   ```

2. Obtain user preferences.
   ```ts
   // Check whether the system is using local digits.
   let usingLocalDigit: boolean = i18n.System.getUsingLocalDigit();

   // Check whether the system is using a 24-hour clock.
   let is24HourClock: boolean = i18n.System.is24HourClock();

   // Listen for the common event COMMON_EVENT_TIME_CHANGED to detect changes in the system's time format.
   let subscriber: commonEventManager.CommonEventSubscriber; //  This will hold the subscriber object once it is created.
   let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
     events: [commonEventManager.Support.COMMON_EVENT_TIME_CHANGED]
   };
   // Create the subscriber.
   commonEventManager.createSubscriber(subscribeInfo)
     .then((commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
       console.info("CreateSubscriber");
       subscriber = commonEventSubscriber;
       commonEventManager.subscribe(subscriber, (err, data) => {
         if (err) {
           console.error(`Failed to subscribe common event. error code: ${err.code}, message: ${err.message}.`);
           return;
         }
         // Check whether the event data indicates a 24-hour format change.
         if (data.data != undefined && data.data == '24HourChange') {
            console.info("The subscribed event has occurred."); // This runs when the system time format changes.
          }
       })
     })
     .catch((err: BusinessError) => {
       console.error(`CreateSubscriber failed, code is ${err.code}, message is ${err.message}`);
     });
   ```

<!--Del-->
3. Enable display of local digits on the application page.
   ```ts
   try {
     i18n.System.setUsingLocalDigit(true); // Enable use of local digits.
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```

4. Set the 24-hour clock format.
   ```ts
   try {
     i18n.System.set24HourClock (true); // Set the system time to the 24-hour clock.
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```
<!--DelEnd-->
