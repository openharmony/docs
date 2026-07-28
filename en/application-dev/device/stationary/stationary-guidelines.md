# Stationary Development

<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @saga2025-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=6f0a1695ab4f18a5c5302addc7947b60c1d6021e translatedAt=2026-07-28T02:37:11.928Z pushedAt=2026-07-28T06:28:15.686Z -->

## When to Use

An application can call the **Stationary** module to obtain the device status, for example, whether the device is absolutely or relatively still.

For detailed API introduction, refer to [@ohos.stationary (Device Status Awareness Framework)](../../reference/apis-multimodalawareness-kit/js-apis-stationary.md).

## Device Status Type Parameters

| Name| Description|
| -------- | -------- |
| still | Absolutely still.|
| relativeStill | Relatively still.|

## Parameters for Subscribing to Device Status Events

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | Event indicating entering device status.  |
| EXIT | 2   | Event indicating exiting device status.|
| ENTER_EXIT | 3   | Event indicating entering and exiting device status.|

## Returned Device Status Parameters

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | Returns the entering status.  |
| EXIT | 2   | Returns the exiting status. |

## API Description

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| on(activity: ActivityType, event: ActivityEvent, reportLatencyNs: number, callback: Callback&lt;ActivityResponse&gt;): void | Subscribes to the device status. This API uses an asynchronous callback to return the result.|
| once(activity: ActivityType, callback: Callback&lt;ActivityResponse&gt;): void | Obtains the device status. This API uses an asynchronous callback to return the result.|
| off(activity: ActivityType, event: ActivityEvent, callback?: Callback&lt;ActivityResponse&gt;): void | Unsubscribes from the device status.                                |

## Constraints

The device is required to support the acceleration sensor.

Currently, only the algorithm framework is provided. The API test framework returns the following result: data={"type":3,"value":-1}.

If the relative stationary and absolute stationary capabilities are required, you must implement them in **device_status/libs/src/algorithm**. The following code snippet is for reference:

   ```C++
   algoPara_.resultantAcc =
      sqrt((algoPara_.x * algoPara_.x) + (algoPara_.y * algoPara_.y) + (algoPara_.z * algoPara_.z));
   if ((algoPara_.resultantAcc > RESULTANT_ACC_LOW_THRHD) && (algoPara_.resultantAcc < RESULTANT_ACC_UP_THRHD)) {
      if (state_ == STILL) {
         return;
      }
      counter_--;
      if (counter_ == 0) {
         counter_ = COUNTER_THRESHOLD;
         UpdateStateAndReport(VALUE_ENTER, STILL, TYPE_ABSOLUTE_STILL);
      }
   } else {
      counter_ = COUNTER_THRESHOLD;
      if (state_ == UNSTILL) {
         return;
      }
      UpdateStateAndReport(VALUE_EXIT, UNSTILL, TYPE_ABSOLUTE_STILL);
   }
   ```

## How to Develop

1. Import the modules.

   <!-- @[import_the_stationary_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/Stationary/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   import { stationary } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Subscribe to the event indicating entering the absolute still state, and the event is reported once per second.

   <!-- @[stationary_subscribe](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/Stationary/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   let reportLatencyNs = 1000000000; // Unit: nanoseconds
   try {
     stationary.on('still', stationary.ActivityEvent.ENTER, reportLatencyNs, (data) => {
       console.info('data=' + JSON.stringify(data));
     })
     // ...
   } catch (error) {
     let message = (error as BusinessError).message;
     console.error('stationary on failed:' + message);
   }
   ```

3. Obtain the event indicating entering the absolute still state.

   <!-- @[stationary_getStatus](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/Stationary/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   try {
     stationary.once('still', (data) => {
       console.info('data=' + JSON.stringify(data));
     })
     // ...
   } catch (error) {
     let message = (error as BusinessError).message;
     console.error('stationary once failed:' + message);
   }
   ```

4. Unsubscribe from the event indicating entering the absolute still state.

   <!-- @[stationary_unsubscribe](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/Stationary/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   try {
     stationary.off('still', stationary.ActivityEvent.ENTER, (data) => {
       console.info('data=' + JSON.stringify(data));
     })
     // ...
   } catch (error) {
     let message = (error as BusinessError).message;
     console.error('stationary off failed:' + message);
   }
   ```