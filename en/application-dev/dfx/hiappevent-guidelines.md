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

When an asynchronous callback is used, the return value can be processed directly in the callback. When a promise is used, the return value can also be processed in the promise in a similar way. For details about the result codes, see [Event Verification Result Codes](#event-verification-result-codes).

**APIs for Event Logging Configuration**

| API                            | Return Value | Description                                                  |
| ------------------------------ | ------------ | ------------------------------------------------------------ |
| configure(ConfigOption config) | boolean      | Sets the configuration options for application event logging.<br>The value **true** indicates that the operation is successful, and value **false** indicates the opposite. |

## Event Verification Result Codes

| Result Code | Cause                              | Check Rule                                                   | Processing Method                                            |
| ----------- | ---------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 0           | None                               | Event verification is successful.                            | Event logging is normal. No action is required.              |
| -1          | Invalid event name                 | The event name is not empty and contains a maximum of 48 characters.<br/>The event name consists of only the following characters: digits (0 to 9), letters (a to z), and underscore (\_).<br/>The event name does not start with a digit or underscore (_). | Ignore this event and do not perform logging.                |
| -2          | Invalid event parameter type       | The event name must be a string.<br/>The event type must be a number.<br/>The key value must be an object. | Ignore this event and do not perform logging.                |
| -99         | Application event logging disabled | The application event logging function is disabled.          | Ignore this event and do not perform logging.                |
| -100        | Unknown error                      | None                                                         | Ignore this event and do not perform logging.                |
| 1           | Invalid key name                   | The key name is not empty and contains a maximum of 16 characters.<br/>The key name consists of only the following characters: digits (0 to 9), letters (a to z), and underscore (\_).<br/>The key name does not start with a digit or underscore (\_).<br/>The key name does not end with an underscore (_). | Ignore the key-value pair and continue to perform logging.   |
| 2           | Invalid key type                   | The key must be a string.                                    | Ignore the key-value pair and continue to perform logging.   |
| 3           | Invalid value type                 | The supported value types vary depending on the programming language:<br/>boolean, number, string, or Array [basic element] | Ignore the key-value pair and continue to perform logging.   |
| 4           | Value too long                     | The value can contain a maximum of 8*1024 characters.        | Ignore the key-value pair and continue to perform logging.   |
| 5           | Excess key-value pairs             | The number of key-value pairs must be less than or equal to 32. | Ignore the excess key-value pairs and continue to perform logging. |
| 6           | Excess elements in a list value    | The number of elements in a list value must be less than or equal to 100. | Truncate the list with only the first 100 elements retained, and continue to perform logging. |
| 7           | Invalid list value                 | A list value can only be a basic element.<br/>The elements in a list value must be of the same type. | Ignore the key-value pair and continue to perform logging.   |


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
