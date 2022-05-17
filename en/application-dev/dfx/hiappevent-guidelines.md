# Development of Application Event Logging

## When to Use

The event logging function helps applications log various information generated during running.

## Available APIs

JS application event logging APIs are provided by the **hiAppEvent** module.

**APIs for Event Logging**

| API                                                          | Return Value   | Description                                                  |
| ------------------------------------------------------------ | -------------- | ------------------------------------------------------------ |
| write(string eventName, EventType type, object keyValues, AsyncCallback\<void> callback): void | void           | Logs application events in asynchronous mode. This method uses an asynchronous callback to return the result. |
| write(string eventName, EventType type, object keyValues): Promise\<void> | Promise\<void> | Logs application events in asynchronous mode. This method uses a promise to return the result. |

When an asynchronous callback is used, the return value can be processed directly in the callback. When a promise is used, the return value can also be processed in the promise in a similar way. For details about the result codes, see [Event Verification Result Codes](hiappevent-overview.md#Event Verification Result Codes).

**APIs for Event Logging Configuration**

| API                            | Return Value | Description                                                  |
| ------------------------------ | ------------ | ------------------------------------------------------------ |
| configure(ConfigOption config) | boolean      | Sets the configuration options for application event logging.<br>The value **true** indicates that the operation is successful, and value **false** indicates the opposite. |

## How to Develop

In this example, an application event is logged after the application startup execution page is loaded.

1. Create a JS application project. In the displayed Project window, choose **entry > src > main** > **js** > **default** > **pages > index**, and double-click index.js. Add the code to log the initial application event after page loading. The sample code is as follows:

   ```js
   import hiAppEvent from '@ohos.hiAppEvent'
   
   export default {
       data: {
           title: ""
       },
       onInit() {
           this.title = this.$t('strings.world');
   
           // 1. Callback mode
           hiAppEvent.write("start_event", hiAppEvent.EventType.BEHAVIOR, {"int_data":100, "str_data":"strValue"}, (err, value) => {
               if (err) {
                   console.error(`failed to write event because ${err.code}`);
                   return;
               }
               console.log(`success to write event: ${value}`);
           });
   
           // 2. Promise mode
           hiAppEvent.write("start_event", hiAppEvent.EventType.BEHAVIOR, {"int_data":100, "str_data":"strValue"})
               .then((value) => {
                   console.log(`success to write event: ${value}`);
               }).catch((err) => {
                   console.error(`failed to write event because ${err.code}`);
               });
    
           // 3. Set the application event logging switch.
           hiAppEvent.configure({
               disable: true
           });
   
           // 4. Set the maximum size of the event file storage directory. The default value is 10M.
           hiAppEvent.configure({
               maxStorage: '100M'
           });
       }
   }
   ```

2. Tap the run button on the application UI to run the project.

## Samples

The following sample is provided to help you better understand how to develop the application event logging feature:

- [`JsDotTest`: Event Logging Test (JavaScript) (API 8)](https://gitee.com/openharmony/app_samples/tree/master/DFX/JsDotTest)
