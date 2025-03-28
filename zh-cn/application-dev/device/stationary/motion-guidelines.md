# 获取用户动作开发指导

## 场景介绍

当应用需要获取用户动作时，可以调用motion模块，例如：需要判断用户当前使用左手还是右手在操作设备屏幕。

详细的接口介绍请参考[Motion接口](../../reference/apis-multimodalawareness-kit/js-apis-awareness-motion.md)。

## 接口说明

| 接口名                                                       | 描述                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'operatingHandChanged',callback:Callback&lt;OperatingHandStatus&gt;):void; | 订阅操作手感知，操作手结果通过callback返回。 |
| off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void; | 取消订阅操作手感知。                   |
| getRecentOperatingHandStatus(): OperatingHandStatus;         | 获取最新的操作手状态。                 |

## 约束与限制

设备需要支持触控屏，并且支持特定芯片。



## 开发步骤

1. 导入模块。

   ```ts
   import { motion } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 定义一个回调函数用来接收操作手结果

   ```
   callback(data:motion.OperatingHandStatus) {
     console.info('callback success' + data);
   }
   ```

3. 订阅操作手感知事件

   ```
   try {
      motion.on('operatingHandChanged', this.callback);  
      console.info("on succeeded");
   } catch (error:BusinessError) {
      console.error("Failed on and err code is " + err.code);
   }
   ```

4. 取消订阅操作手感知事件

   ```
   try {
      motion.off('operatingHandChanged');
      console.info("off succeeded");
   } catch (error:BusinessError) {
      console.error("Failed off and err code is " + err.code);
   }
   ```

5. 获取最新操作手状态

   ```
   try {
      let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
      console.info('get success' + data);
   } catch (error:BusinessError) {
      console.error("Failed get and err code is " + err.code);
   }
   ```

   

