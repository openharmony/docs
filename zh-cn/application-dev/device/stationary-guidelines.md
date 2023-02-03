# Stationary开发指导


## 场景介绍

当应用需要获取当前设备状态时，可以调用Stationary模块，例如：需要判断当前设备是否处于绝对静止状态，或者相对静止状态。

详细的接口介绍请参考[Stationary接口](../reference/apis/js-apis-stationary.md)。

## 参数常量说明

| 名称 | 描述 |
| -------- | -------- |
| still | 绝对静止。 |
| relativeStill | 相对静止。 |

## 参数枚举说明

| 变量                             | 值    | 说明                                       |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | 进入。   |
| EXIT | 2   | 退出。 |
| ENTER_EXIT | 3   | 进入和退出。 |

## 返回值枚举说明

| 变量                             | 值    | 说明                                       |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | 进入。   |
| EXIT | 2   | 退出。 |

## 接口说明

| 模块          | 接口名                                                       | 描述                                                         |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.stationary | on(activity: ActivityType, event: ActivityEvent, reportLatencyNs: number, callback: Callback&lt;ActivityResponse&gt;): void | 订阅绝对静止/相对静止状态的进入/退出/进入和退出事件，结果使用callback异步回调 |
| ohos.stationary | once(activity: ActivityType, callback: Callback&lt;ActivityResponse&gt;): void | 查询设备的绝对静止/相对静止状态，结果使用Callback异步回调。 |
| ohos.stationary | off(activity: ActivityType, event: ActivityEvent, callback?: Callback&lt;ActivityResponse&gt;): void | 取消订阅绝对静止/相对静止的进入/退出/进入和退出事件                                 |

## 约束与限制

设备需要支持加速度传感器

## 开发步骤

1. 订阅绝对静止的进入事件，1秒上报一次

   ```js
   import stationary from '@ohos.stationary';
   var reportLatencyNs = 1000000000;
   try {
      stationary.on('still', stationary.ActivityEvent.ENTER, reportLatencyNs, (data) => {
         console.log('data='+ JSON.stringify(data));
      })
   } catch (err) {
      console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
   }
   ```

2. 查询绝对静止状态的进入事件

   ```js
   import stationary from '@ohos.stationary';
   try {
      stationary.once('still', (data) => {
         console.log('data='+ JSON.stringify(data));
      })
   } catch (err) {
      console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
   }
   ```

3. 取消订阅绝对静止状态的进入事件

   ```js
   import stationary from '@ohos.stationary';
   try {
      stationary.off('still', stationary.ActivityEvent.ENTER, (data) => {
         console.log('data='+ JSON.stringify(data));
      })
   } catch (err) {
      console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
   }
   ```
