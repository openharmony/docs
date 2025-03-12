# Motion Sensing Development

## When to Use

An application can call the motion module to identify user actions, for example, whether the user is operating the device screen with the left hand or the right hand.

For details about the APIs, see [Motion API Reference](../../reference/apis-multimodalawareness-kit/js-apis-awareness-motion.md).

## Available APIs

| API                                                      | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'operatingHandChanged',callback:Callback&lt;OperatingHandStatus&gt;):void; | Subscribes to operating hand change events. This API uses an asynchronous callback to return the result.|
| off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void; | Unsubscribes from operating hand change events.                  |
| getRecentOperatingHandStatus(): OperatingHandStatus;         | Obtains the latest operating hand status.                |

## Constraints

The device has a touchscreen and supports specific chips.



## How to Develop

```ts
import { motion } from '@kit.MultimodalAwarenessKit';
```

1. Subscribe to operating hand change events.

   ```
   motion.on('operatingHandChanged', (data:motion.OperatingHandStatus) => {
     console.info('on success' + data);
   })
   
   ```

2. Unsubscribe from operating hand change events.

   ```
   motion.off('operatingHandChanged', (data:motion.OperatingHandStatus) => {
     console.info('off success' + data);
   })
   
   ```

3. Obtain the latest operating hand status.

   ```
   let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
   console.info('get success' + data);
   ```

   
