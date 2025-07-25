# 获取用户动作开发指导

## 场景介绍

当应用需要获取用户动作时，可以调用motion模块，例如判断用户当前是用左手还是右手操作设备屏幕。

详细的接口介绍请参考[Motion接口](../../reference/apis-multimodalawareness-kit/js-apis-awareness-motion.md)。

## 获取操作手状态开发指导

### 接口说明

| 接口名                                                       | 描述                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'operatingHandChanged',callback:Callback&lt;OperatingHandStatus&gt;):void; | 订阅操作手感知，操作手结果通过callback返回。 |
| off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void; | 取消订阅操作手感知。                   |
| getRecentOperatingHandStatus(): OperatingHandStatus;         | 获取最新的操作手状态。                 |

### 约束与限制

 - 设备需支持触控屏并兼容特定芯片。

 - 指关节操作不属于使用手操作场景。

 - 窗口旋转场景，多指同时操作场景不支持。

 - 能力有效范围：不包含距离屏幕边缘8mm内区域。

### 开发步骤

1. 导入模块。

   ```ts
   import { motion } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 定义回调函数接收操作手结果

   ```
   callback(data:motion.OperatingHandStatus) {
     console.info('callback success' + data);
   };
   ```

3. 订阅操作手感知

   ```
   try {
      motion.on('operatingHandChanged', this.callback);
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
      console.info('get success' + data);
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed get and err code is " + error.code);
   }
   ```


## 获取握持手状态开发指导

### 接口说明

| 接口名                                                       | 描述                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'holdingHandChanged',callback:Callback&lt;HoldingHandStatus&gt;): void; | 订阅握持手感知，感知结果通过callback返回。 |
| off(type: 'holdingHandChanged', callback?: Callback&lt;HoldingHandStatus&gt;): void; | 取消订阅握持手感知。                   |

### 约束与限制

 - 设备需支持触控屏并兼容特定芯片。

 - 设备需要亮屏解锁。

 - 正常姿态握持手机，五指或拇指外的四指及掌心接触手机。

 - 竖屏握持时摄像头朝上，支持横屏握持，但需要注意应用横屏时握持手机长边及应用竖屏时握持手机短边属于异常场景，无法保证成功率，握持时屏幕需要朝向握持人方向。

 - 握持时设备不能同时接触其他物体。

### 开发步骤

1. 导入模块。

   ```ts
   import { motion } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 定义回调函数接收握持手结果

   ```
   callback(data:motion.HoldingHandStatus) {
     console.info('callback success' + data);
   };
   ```

3. 订阅握持手感知

   ```
   try {
      motion.on('holdingHandChanged', this.callback);
      console.info("on succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed on and err code is " + error.code);
   }
   ```

4. 取消订阅握持手感知

   ```
   try {
      motion.off('holdingHandChanged');
      console.info("off succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed off and err code is " + error.code);
   }
   ```
