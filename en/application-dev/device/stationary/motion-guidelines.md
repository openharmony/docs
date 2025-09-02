# Motion Sensing Development

## When to Use

An application can call the motion module to identify user actions, for example, whether the user is operating the device screen with the left hand or the right hand.

For details about the APIs, see [Motion API Reference](../../reference/apis-multimodalawareness-kit/js-apis-awareness-motion.md).

## Available APIs

| API                                                      | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'operatingHandChanged',callback:Callback&lt;OperatingHandStatus&gt;):void; | Subscribes to operating hand change events. This API uses a callback to return the result.|
| off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void; | Unsubscribes from operating hand change events.                  |
| getRecentOperatingHandStatus(): OperatingHandStatus;         | Obtains the latest operating hand status.                |

### Required Permissions

To use the motion module to obtain the operating hand, you need to request the **ohos.permission.ACTIVITY_MOTION** or **ohos.permission.DETECT_GESTURE** permission. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.ACTIVITY_MOTION"
      },
      {
        "name" : "ohos.permission.DETECT_GESTURE"
      }
    ]
  ```
  
## Constraints

 - The device must support the touchscreen and be compatible with specific chips.

 - Knuckle operations are not categorized as hand operations.

 - Multi-finger operations are not supported in window rotation scenarios.

 - The effective range does not include the area within 8 mm from the screen edge.



## How to Develop

1. Import the related modules.

   ```ts
   import { motion } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Callback } from '@ohos.base';
   ```

2. Define a callback to receive operating hand change results.

   ```
   let callback:Callback<motion.OperatingHandStatus> = (data:motion.OperatingHandStatus) => {
     console.info('callback succeeded' + data);
   }
   ```

3. Subscribe to operating hand change results.

   ```
   try {
      motion.on('operatingHandChanged', callback);  
      console.info("on succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed on and err code is " + error.code);
   }
   ```

4. Unsubscribe from operating hand change events.

   ```
   try {
      motion.off('operatingHandChanged');
      console.info("off succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed off and err code is " + error.code);
   }
   ```

5. Obtain the latest operating hand status.

   ```
   try {
      let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
      console.info('get succeeded' + data);
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed get and err code is " + error.code);
   }
   ```

   
