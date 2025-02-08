# 获取用户动作开发指导

## 场景介绍

当应用需要获取用户动作时，可以调用motion模块，例如：需要判断用户当前使用左手还是右手在操作设备屏幕。

详细的接口介绍请参考[Motion接口](../../reference/apis-multimodalawareness-kit/js-apis-awareness-motion.md)。

## 接口说明

| 接口名                                                       | 描述                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'operatingHandChanged',callback:Callback&lt;OperatingHandStatus&gt;):void; | 订阅操作手感知，结果通过callback返回。 |
| off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void; | 取消订阅操作手感知。                   |
| getRecentOperatingHandStatus(): OperatingHandStatus;         | 获取最新的操作手状态。                 |

## 约束与限制

设备需要支持触控屏，并且支持特定芯片。



## 开发步骤

```ts
import { motion } from '@kit.MultimodalAwarenessKit';
```

1. 订阅操作手感知事件

   ```
   motion.on('operatingHandChanged', (data:motion.OperatingHandStatus) => {
     console.info('on success' + data);
   })
   
   ```

2. 取消订阅操作手感知事件

   ```
   motion.off('operatingHandChanged', (data:motion.OperatingHandStatus) => {
     console.info('off success' + data);
   })
   
   ```

3. 获取最新操作手状态

   ```
   let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
   console.info('get success' + data);
   ```

   

