# Device Status Awareness Development

<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @zou_ye-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=24d0c1aa42218ea8ba805438c64b5ad4e385aee6 translatedAt=2026-07-28T02:37:01.799Z pushedAt=2026-07-28T06:04:28.473Z -->

The **DeviceStatus** module provides device status awareness capabilities. It can be used to obtain device information, such as the steady standing state (stand mode).

For details about the APIs, see [@ohos.multimodalAwareness.deviceStatus (Device Status Awareness)](../../reference/apis-multimodalawareness-kit/js-apis-awareness-deviceStatus.md).

## Concepts

Understanding the following concepts would be helpful for you in device status awareness development:

- Stand mode

    A device enters stand mode when it is stationary, and its screen is at an angle between 45 and 135 degrees relative to the horizontal plane. For a foldable, it must be in a folded state or fully unfolded state.

## How to Develop

### Overview

During development, you can subscribe to steady standing state change events and obtain the current state through the callback passed in during subscription.

This function is supported since API version 18.

### Constraints

The device must support accelerometers.

### APIs

| API                                                      | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type: 'steadyStandingDetect', callback: Callback&lt;SteadyStandingStatus&gt;): void; | Subscribes to steady standing state change events. This API returns the result through a callback.|
| off(type: 'steadyStandingDetect', callback?: Callback&lt;SteadyStandingStatus&gt;): void; | Unsubscribes from steady standing state change events. |

### Development Procedure

1. Import the **deviceStatus** module.

  <!-- @[import_the_device_status_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/DeviceStatus/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   import { deviceStatus } from '@kit.MultimodalAwarenessKit';
   ```

2. Subscribe to steady standing state change events.

  <!-- @[device_status_subscribe](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/DeviceStatus/entry/src/main/ets/pages/Index.ets) -->  

   ``` TypeScript
   try {
     deviceStatus.on('steadyStandingDetect', (data:deviceStatus.SteadyStandingStatus) => {
       console.info('succeed to get status, now status = ' + data);
     });
     // ...
   } catch (err) {
     console.error('on failed, err = ' + err);
     // ...
   }
   ```

3. Unsubscribe from all steady standing state change events subscribed by this client.

  <!-- @[device_status_unsubscribe_all](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/DeviceStatus/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   try {
     deviceStatus.off('steadyStandingDetect');
     // ...
   } catch (err) {
     console.error('off failed, err = ' + err);
     // ...
   }
   ```

4. Unsubscribe from the specific callback of steady standing state change events.

  <!-- @[device_status_unsubscribe](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/DeviceStatus/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   // Define the callback variable.
   let callback : Callback<deviceStatus.SteadyStandingStatus> = (data : deviceStatus.SteadyStandingStatus) => {
     console.info('succeed to get status, now status = ' + data);
   };
   // Subscribe to the device stationary posture perception (steady standing) event using the callback.
   try {
     deviceStatus.on('steadyStandingDetect', callback);
     // ...
   } catch (err) {
     console.error('on failed, err = ' + err);
     // ...
   }
   // Unsubscribe the specific callback for the device stationary posture perception (steady standing) event on this client.
   try {
     deviceStatus.off('steadyStandingDetect', callback);
     // ...
   } catch (err) {
     console.error('off failed, err = ' + err);
     // ...
   }
   ```