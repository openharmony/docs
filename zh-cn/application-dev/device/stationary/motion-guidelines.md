# 获取用户动作开发指导

## 场景介绍

当应用需要获取用户动作时，可以调用motion模块，例如判断用户当前是用左手还是右手操作设备屏幕。

详细的接口介绍请参考[Motion接口](../../reference/apis-multimodalawareness-kit/js-apis-awareness-motion.md)。

从API version 15开始，支持获取操作手状态。

## 接口说明

| 接口名                                                       | 描述                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'operatingHandChanged',callback:Callback&lt;OperatingHandStatus&gt;):void; | 订阅操作手感知，操作手结果通过callback返回。 |
| off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void; | 取消订阅操作手感知。                   |
| getRecentOperatingHandStatus(): OperatingHandStatus;         | 获取最新的操作手状态。                 |

### 需要权限

使用motion模块获取用户操作手时，需要权限：ohos.permission.ACTIVITY_MOTION 或 ohos.permission.DETECT_GESTURE，具体申请方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

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
  
## 约束与限制

 - 设备需支持触控屏并兼容特定芯片。

 - 指关节操作不属于使用手操作场景。

 - 窗口旋转场景，多指同时操作场景不支持。

 - 能力有效范围：不包含距离屏幕边缘8mm内区域。



## 开发步骤

1. 导入模块。

   ```ts
   import { motion } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 定义回调函数接收操作手结果

   ```
   let callback:Callback<motion.OperatingHandStatus> = (data:motion.OperatingHandStatus) => {
     console.info('callback succeeded' + data);
   }
   ```

3. 订阅操作手感知

   ```
   try {
      motion.on('operatingHandChanged', callback);  
      console.info("on succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed on and err code is " + error.code);
   }
   ```

4. 取消订阅操作手感知

   ```
   try {
      motion.off('operatingHandChanged');
      console.info("off succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed off and err code is " + error.code);
   }
   ```

5. 获取最新操作手状态

   ```
   try {
      let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
      console.info('get succeeded' + data);
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed get and err code is " + error.code);
   }
   ```

   