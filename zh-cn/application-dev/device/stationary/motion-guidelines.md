# 获取用户动作开发指导
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--SE: @zou_ye-->
<!--TSE: @judan-->

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

 - 此功能如果设备不支持，将返回801错误码。

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

 - 此功能当前支持部分机型，若设置菜单中存在“握姿跟随”开关（可在“设置-系统”中查看），则表明该设备支持此功能，若无此开关，将返回801错误码。
 - 设备屏幕需处于亮屏且解锁状态。
 - 设备保护壳（若有）厚度不得超过3毫米。
 - 需以五指自然握持设备，同时掌心区域接触设备（或拇指外的四指及掌心区域接触）。
 - 握持时确保每根接触手指的接触面积尽可能大（理想情况下不低于30mm²）。
 - 佩戴手套会显著降低识别准确率。
 - 竖屏握持时，摄像头需朝上。
 - 支持横屏握持，但需要注意：应用横屏时竖屏握持（握持设备短边），应用竖屏时横屏握持（握持设备长边），均属异常姿态，无法保证识别成功。
 - 握持时屏幕需朝向握持人。
 - 握持时不得同时接触其他物体（如桌面、其他身体部位等）。
 - 未握持的识别依赖设备状态，设备非静止时无法保证识别成功。

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
