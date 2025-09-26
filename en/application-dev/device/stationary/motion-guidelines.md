# Motion Awareness Development
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @zou_ye-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

## When to Use

An application can call the motion module to identify user actions, for example, whether the user is operating the device screen with the left hand or the right hand.

For details about the APIs, see [Motion API Reference](../../reference/apis-multimodalawareness-kit/js-apis-awareness-motion.md).

Operating hand status query is supported since API version 15. Holding hand status query is supported since API version 20.

## Operating Hand Status Query

### Available APIs

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
  
### Constraints

 - If the device does not support the age group detection function, error code 801 is returned.

 - Knuckle operations are not categorized as hand operations.

 - Multi-finger operations are not supported in window rotation scenarios.

 - The effective range does not include the area within 8 mm from the screen edge.

### How to Develop

1. Import the related modules.

   ```ts
   import { motion } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Define a callback to receive operating hand change results.

   ```
   let callback:Callback<motion.OperatingHandStatus> = (data:motion.OperatingHandStatus) => {
     console.info('callback succeeded' + data);
   };
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


## Holding Hand Status Query

### Available APIs

| API                                                      | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'holdingHandChanged',callback:Callback&lt;HoldingHandStatus&gt;): void; | Enables listening for holding hand status changes. This API uses a callback to return the result.|
| off(type: 'holdingHandChanged', callback?: Callback&lt;HoldingHandStatus&gt;): void; | Disables listening for holding hand status changes.                  |

### Required Permissions

To use the motion module to obtain the holding hand, you need to request the **ohos.permission.DETECT_GESTURE** permission. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.DETECT_GESTURE"
      }
    ]
  ```
  
### Constraints

 - Motion awareness is supported on some device models. If the smart reachability switch (accessible from **Settings** > **System**) is available, this function is supported. Otherwise, error code 801 will be returned.
 - The device screen must be on and unlocked.
 - The thickness of the device protective case (if any) must not exceed 3 mm.
 - You need to naturally hold the device with five fingers, while the palm area of your hand touches the device (or four fingers except the thumb and the palm area of your hand touch the device).
 - The contact area of each finger is as large as possible (at least 30 mm2 in ideal cases).
 - Wearing gloves can significantly reduce the recognition accuracy.
 - When holding the device in portrait mode, the camera must face upward.
 - If you hold the device in portrait mode (holding the short edge of the device) when the application uses the landscape mode or hold the device in landscape mode (holding the long edge of the device) when the application uses the portrait mode, the recognition may fail due to the abnormal posture.
 - You must face the screen when holding the device.
 - Do not touch any other objects (such as the table or other body parts) at the same time when holding the device.
 - The recognition of unholding depends on the device status. The recognition may fail if the device is not static.

### How to Develop

1. Import the related modules.

   ```ts
   import { motion } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Define a callback to receive the hand holding status change.

   ```
   let callback:Callback<motion.HoldingHandStatus> = (data:motion.HoldingHandStatus) => {
     console.info('callback succeeded' + data);
   };
   ```

3. Enable listening for holding hand status changes.

   ```
   try {
      motion.on('holdingHandChanged', callback);
      console.info("on succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed on and err code is " + error.code);
   }
   ```

4. Disable listening for holding hand status changes.

   ```
   try {
      motion.off('holdingHandChanged');
      console.info("off succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed off and err code is " + error.code);
   }
   ```
