# Development of Application Event Logging

## When to Use

The event logging function helps applications log various information generated during running.

## Available APIs

JS application event logging APIs are provided by the **hiAppEvent** module.

**APIs for event logging:**

| API                                                          | Return Value   | Description                                                  |
| ------------------------------------------------------------ | -------------- | ------------------------------------------------------------ |
| write(string eventName, EventType type, object keyValues, AsyncCallback\<void> callback): void | void           | Logs application events in asynchronous mode. This method uses an asynchronous callback to return the result. |
| write(string eventName, EventType type, object keyValues): Promise\<void> | Promise\<void> | Logs application events in asynchronous mode. This method uses a promise to return the result. |

- **eventName**: event name you customized. The event name can contain a maximum of 48 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter.

- **type**: event type enumerated by **EventType**.

  | Type      | Description       |
  | --------- | ----------------- |
  | FAULT     | Fault event       |
  | STATISTIC | Statistical event |
  | SECURITY  | Security event    |
  | BEHAVIOR  | Behavior event    |

- **keyValues**: event parameter key-value pair. For a variable-length parameter, enter each pair of parameter name and value in sequence. For a JSON parameter, enter the parameter name as the key and parameter value as the value.
  - A parameter name must be a string, and a parameter value must be a string, number, boolean, or array (which is a basic element).
  - The number of event parameters must be less than or equal to 32.
  - The parameter name can contain a maximum of 16 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter and cannot end with an underscore (\_).
  - A string value can contain a maximum of 8*1024 characters.
  - An array value can contain a maximum of 100 elements. Excess elements will be truncated.
- **callback**: callback function used to process the received return value. The value **0** indicates that the event parameter verification is successful, and the event will be written to the event file asynchronously. A value greater than **0** indicates that invalid parameters are present in the event, and the event will be written to the event file asynchronously after the invalid parameters are ignored. A value smaller than **0** indicates that the event parameter verification fails, and the event will not be written to the event file asynchronously.

When an asynchronous callback is used, the return value can be processed directly in the callback. When a promise is used, the return value can also be processed in the promise in a similar way. For details about the result codes, see [Event Verification Result Codes](hiappevent-overview.md#Event Verification Result Codes).

**APIs for event logging configuration:**

| API                            | Return Value | Description                                                  |
| ------------------------------ | ------------ | ------------------------------------------------------------ |
| configure(ConfigOption config) | boolean      | Sets the configuration options for application event logging.<br/>The value **true** indicates that the operation is successful, and value **false** indicates the opposite. |

- **config**: configuration options for application event logging.

   Configuration options for application event logging (**ConfigOption**)

  | Name       | Type    | Mandatory | Description                                                  |
  | ---------- | ------- | --------- | ------------------------------------------------------------ |
  | disable    | boolean | No        | Sets the application event logging switch. The value **true** means to disable the application event logging function, and value **false** means the opposite. |
  | maxStorage | string  | No        | Specifies the maximum size of the event file storage directory. The default value is 10M. |

**Predefined event name constants (Event)**:

| Constant                  | Type   | Description                                    |
| ------------------------- | ------ | ---------------------------------------------- |
| USER_LOGIN                | string | Name of the user login event.                  |
| USER_LOGOUT               | string | Name of the user logout event.                 |
| DISTRIBUTED_SERVICE_START | string | Name of the distributed service startup event. |



**Predefined parameter name constants (Param):**

| Constant                        | Type   | Description                      |
| ------------------------------- | ------ | -------------------------------- |
| USER_ID                         | string | Custom user ID.                  |
| DISTRIBUTED_SERVICE_NAME        | string | Distributed service name.        |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | Distributed service instance ID. |



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


