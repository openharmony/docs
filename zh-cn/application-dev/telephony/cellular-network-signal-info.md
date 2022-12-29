# 获取当前蜂窝网络信号信息


## 场景介绍

应用通常需要获取用户所在蜂窝网络下信号信息，以便获取当前驻网质量。开发者可以通过本业务，获取到用户指定SIM卡当前所在网络下的信号信息。


## 接口说明

radio模块提供了获取当前网络信号信息的方法。observer模块为开发者提供蜂窝网络状态订阅和取消订阅功能。具体接口说明如下表。

| 功能分类 | 接口名 | 描述 | 所需权限 |
| -------- | -------- | -------- | -------- |
| 信号强度信息 | radio.getSignalInformation​​() | 获取当前注册蜂窝网络信号强度信息 | 无 |
| 订阅蜂窝网络信号变化 | observer.on('signalInfoChange') | 订阅蜂窝网络信号变化 | 无 |
| 取消订阅蜂窝网络信号变化 | observer.off('signalInfoChange') | 取消订阅蜂窝网络信号变化 | 无 |


## 开发步骤

1. import需要的模块。

2. 调用getSignalInformation()方法，返回所有SignalInformation列表。

3. 遍历SignalInformation数组，并分别根据不同的signalType得到不同制式的信号强度。

4. 订阅蜂窝网络信号变化（可选）。
   
   ```js
   import radio from '@ohos.telephony.radio'
   import observer from '@ohos.telephony.observer';
   
   // 以获取卡1的信号强度为例
   let slotId = 0;
   radio.getSignalInformation(slotId, (err, data) => {
       if (!err) {
           console.log("get signal information success.");
           // 遍历数组，输出不同网络制式下的信号强度
           for (let j = 0; j < data.length; j++) {
               console.log("type:" + data[j].signalType + ", level:" + data[j].signalLevel);
           }
       } else {
           console.log("get signal information fail, err is:" + JSON.stringify(err));
       }
   });
   // 订阅蜂窝网络信号变化（可选）
   observer.on("signalInfoChange", (data) => {
       console.log("signal info change, data is:" + JSON.stringify(data));
   });
   ```

## 相关实例

针对蜂窝网络数据开发，有以下相关实例可供参考：
- [`MobileNetwork`：蜂窝数据（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/Telephony/MobileNetwork)