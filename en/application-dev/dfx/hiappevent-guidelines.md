# Development of Application Event Logging

## When to Use

The event logging function helps applications log various information generated during running.

## Available APIs

JS application event logging APIs are provided by the **hiAppEvent** module.

The following table provides only a brief description of related APIs. For details, see [HiAppEvent](../reference/apis/js-apis-hiappevent.md).

**Table 1** APIs for application event logging

| API                                                      | Description                                                |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| write(AppEventInfo info, AsyncCallback\<void> callback): void | Logs application events in asynchronous mode. This API uses an asynchronous callback to return the result.|
| write(AppEventInfo info): Promise\<void>                     | Logs application events in asynchronous mode. This API uses a promise to return the result. |

When an asynchronous callback is used, the return value can be processed directly in the callback.

If a promise is used, the return value can also be processed in the promise in a similar way.

For details about the result codes, see [Event Verification Result Codes](#event-verification-result-codes).

**Table 2** APIs for event logging configuration 

| API                                 | Description                                                |
| --------------------------------------- | ---------------------------------------------------- |
| configure(ConfigOption config): boolean | Sets the configuration options for application event logging.|

**Table 3** APIs for watcher management

| API                                            | Description                |
| -------------------------------------------------- | -------------------- |
| addWatcher(Watcher watcher): AppEventPackageHolder | Adds an event watcher.|
| removeWatcher(Watcher watcher): void               | Removes an event watcher.|

**Table 4** APIs for clearing logging data

| API           | Description                |
| ----------------- | -------------------- |
| clearData(): void | Clears local logging data.|

### Event Verification Result Codes

| Result Code| Cause                         | Verification Rules                                                    | Handling Method                                                  |
| ------ | ----------------------------- | ------------------------------------------------------------ | ---------------------------------------------------------- |
| 0      | N/A                           | Event verification is successful.                                                | Event logging is normal. No action is required.                                            |
| -1     | Invalid event name               | The name is not empty and contains a maximum of 48 characters.<br>The name consists of only the following characters: digits (0 to 9), letters (a to z), and underscore \(_).<br>The name does not start with a digit or underscore \(_).| Ignore this event and do not perform logging.                                  |
| -2     | Invalid event parameter type       | The event name must be a string.<br>The event type must be a number.<br>The event parameter must be an object.| Ignore this event and do not perform logging.                                  |
| -4     | Invalid event domain name           | The name is not empty and contains a maximum of 32 characters.<br>The name consists of only the following characters: digits (0 to 9), letters (a to z), and underscore \(_).<br>The name does not start with a digit or underscore \(_).| Ignore this event and do not perform logging.                                  |
| -99    | Application event logging disabled           | Application event logging is disabled.                                        | Ignore this event and do not perform logging.                                  |
| -100   | Unknown error                     | None.                                                        | Ignore this event and do not perform logging.                                  |
| 1      | Invalid key name            | The name is not empty and contains a maximum of 16 characters.<br>The name consists of only the following characters: digits (0 to 9), letters (a to z), and underscore \(_).<br>The name does not start with a digit or underscore \(_).<br>The name does not end with an underscore \(_).| Ignore the key-value pair and continue to perform logging.                        |
| 2      | Invalid key type            | The key must be a string.                                   | Ignore the key-value pair and continue to perform logging.                        |
| 3      | Invalid value type          | The supported value types vary depending on the programming language:<br>boolean, number, string, or Array [basic element]| Ignore the key-value pair and continue to perform logging.                        |
| 4      | Invalid length for values of the string type| For a value of the string type, the maximum length is 8*1024 characters.                    | Truncate the value with the first 8*1024 characters retained, and continue to perform logging.|
| 5      | Excess key-value pairs        | The number of key-value pairs must be less than or equal to 32.                     | Ignore the excess key-value pairs and continue to perform logging.                |
| 6      | Invalid number of elements in values of the array type | For a value of the array type, the number of elements must be less than or equal to 100.             | Truncate the array with the first 100 elements retained, and continue to perform logging.     |
| 7      | Invalid parameters in values of the array type | For a value of the array type, all the parameters must be of the same type, which can only be boolean, number, or string.| Ignore the key-value pair and continue to perform logging.                        |

## Development Procedure

The following uses a one-time event watcher as an example to illustrate the development procedure.

1. Create an ArkTS application project. In the displayed **Project** window, choose **entry** > **src** > **main** > **ets** > **pages** > **index.ets**, and double-click **index.ets**. Then, add three buttons to simulate the process of watching for application events. Wherein, button 1 is used to invoke application event logging, button 2 to add an event watcher that automatically triggers a callback, and button 3 to remove the watcher. The complete sample code is as follows:

   ```ts
   import hiAppEvent from '@ohos.hiAppEvent';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
   
           Button("1 writeTest").onClick(()=>{
             // Perform event logging based on the input event parameters.
             hiAppEvent.write({
               domain: "test_domain",
               name: "test_event",
               eventType: hiAppEvent.EventType.FAULT,
               params: {
                 int_data: 100,
                 str_data: "strValue"
               }
             }).then((value) => {
               console.log(`HiAppEvent success to write event: ${value}`);
             }).catch((err) => {
               console.error(`HiAppEvent failed to write event because ${err.code}`);
             });
           })
   
           Button("2 addWatcherTest").onClick(()=>{
             // Add an event watcher based on the input subscription parameters.
             hiAppEvent.addWatcher({
               name: "watcher1",
               appEventFilters: [{ domain: "test_domain" }],
               triggerCondition: {
                 row: 2,
                 size: 1000,
                 timeOut: 2
               },
               onTrigger: function (curRow, curSize, holder) {
                 // If the holder object is null, return an error after recording it in the log.
                 if (holder == null) {
                   console.error("HiAppEvent holder is null");
                   return;
                 }
                 // Set the size threshold to 1,000 bytes for obtaining an event package.
                 holder.setSize(1000);
                 let eventPkg = null;
                 // Obtain the event package based on the configured size threshold. If returned event package is null, all event data has been obtained.
                 while ((eventPkg = holder.takeNext()) != null) {
                   // Parse the obtained event package and display the result on the Log page.
                   console.info('HiAppEvent eventPkg.packageId=' + eventPkg.packageId);
                   console.info('HiAppEvent eventPkg.row=' + eventPkg.row);
                   console.info('HiAppEvent eventPkg.size=' + eventPkg.size);
                   // Traverse and parse event string arrays in the obtained event package.
                   for (const eventInfo of eventPkg.data) {
                     console.info('HiAppEvent eventPkg.data=' + eventInfo);
                   }
                 }
               }
             });
           })
   
           Button("3 removeWatcherTest").onClick(()=>{
             // Remove the specified event watcher.
             hiAppEvent.removeWatcher({
               name: "watcher1"
             })
           })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

2. Touch the run button on the IDE to run the project.

3. Touch button 1 on the application UI to start application event logging. If the logging is successful, you'll see the following message in the **Log** window:

   ```
   success to write event: 0
   ```

4. On the application UI, touch button 2 to add an event watcher, and touch button 1 for multiple times to perform application event logging. If any callback trigger condition (event count, event data size, and timeout duration) is met, the event watcher will invoke a callback and the event package obtained through the callback will be displayed in the **Log** window.

   ```
   HiAppEvent eventPkg.packageId=0
   HiAppEvent eventPkg.row=2
   HiAppEvent eventPkg.size=308
   HiAppEvent eventPkg.data={"domain_":"test_domain","name_":"test_event","type_":1,"time_":1502096107556,"tz_":"+0000","pid_":4204,"tid_":4223,"int_data":100,"str_data":"strValue"}
   ```

5. On the application UI, touch button 3 to remove the event watcher. Then, touch button 1 for multiple times to perform application event logging. In such a case, there will be no log information about the callback invoked by the event watcher.

## Samples

The following sample is provided to help you better understand how to develop the application event logging feature:

- [`JsDotTest` (JS) (API8)](https://gitee.com/openharmony/applications_app_samples/tree/master/DFX/JsDotTest)
