# Stationary Development


## When to Use

An application can call the **Stationary** module to obtain the device status, for example, whether the device is absolutely or relatively still.

For details about the APIs, see [Stationary](../../reference/apis-multimodalawareness-kit/js-apis-stationary.md).

## Device Status Type Parameters

| Name| Description|
| -------- | -------- |
| still | Absolutely still.|
| relativeStill | Relatively still.|

## Parameters for Subscribing to Device Status events

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | Event indicating entering device status.  |
| EXIT | 2   | Event indicating exiting device status.|
| ENTER_EXIT | 3   | Event indicating entering and exiting device status.|

## Returned Device Status Parameters

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | Entering device status.  |
| EXIT | 2   | Exiting device status.|

## Available APIs

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| on(activity: ActivityType, event: ActivityEvent, reportLatencyNs: number, callback: Callback&lt;ActivityResponse&gt;): void | Subscribes to the device status. This API uses an asynchronous callback to return the result.|
| once(activity: ActivityType, callback: Callback&lt;ActivityResponse&gt;): void | Obtains the device status. This API uses an asynchronous callback to return the result.|
| off(activity: ActivityType, event: ActivityEvent, callback?: Callback&lt;ActivityResponse&gt;): void | Unsubscribes from the device status.                                |

## Constraints

The device must support the acceleration sensor.
Currently, only the algorithm framework is provided. The API test framework returns the following result: data={"type":3,"value":-1}.
If the relative stationary and absolute stationary capabilities are required, you must implement them in **device_status/libs/src/algorithm**. The following code snippet is for reference:

   ```ts
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

1. Subscribe to the event indicating entering the absolute still state, and the event is reported every 1 second.

   ```ts
   import { stationary } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   let reportLatencyNs = 1000000000;
   try {
      stationary.on('still', stationary.ActivityEvent.ENTER, reportLatencyNs, (data) => {
         console.log('data='+ JSON.stringify(data));
      })
   } catch (error) {
      let message = (error as BusinessError).message;
      console.error('stationary on failed:' + message);
   }
   ```

2. Obtain the event indicating entering the absolute still state.

   ```ts
   import { stationary } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   try {
      stationary.once('still', (data) => {
         console.log('data='+ JSON.stringify(data));
      })
   } catch (error) {
      let message = (error as BusinessError).message;
      console.error('stationary once failed:' + message);
   }
   ```

3. Unsubscribe from the event indicating entering the absolute still state.

   ```ts
   import { stationary } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   try {
      stationary.off('still', stationary.ActivityEvent.ENTER, (data) => {
         console.log('data='+ JSON.stringify(data));
      })
   } catch (error) {
      let message = (error as BusinessError).message;
      console.error('stationary off failed:' + message);
   }
   ```
