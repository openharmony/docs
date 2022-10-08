# 跳转拨号界面

当应用需要跳转到拨号界面，并显示拨号的号码时，使用本业务。当开发者调用makeCall接口时，设备会自动跳转到拨号界面。和正常拨打电话一样，用户可以选择音频或视频呼叫，卡1或卡2拨出。


## 接口说明

call模块为开发者提供呼叫管理功能。observer模块为开发者提供订阅和取消订阅通话业务状态的功能。具体接口说明如下表。

| 功能分类 | 接口名 | 描述 | 所需权限 |
| -------- | -------- | -------- | -------- |
| 能力获取 | call.hasVoiceCapability() | 是否具有语音功能 | 无 |
| 跳转拨号界面 | call.makeCall() | 跳转到拨号界面，并显示拨号的号码 | 无 |
| 订阅通话业务状态变化 | observer.on('callStateChange') | 订阅通话业务状态变化 | ohos.permission.READ_CALL_LOG&nbsp;（获取通话号码需要该权限） |
| 取消订阅通话业务状态变化 | observer.off('callStateChange') | 取消订阅通话业务状态变化 | 无 |


## 开发步骤

1. import需要的模块。

2. 调用hasVoiceCapability()接口获取当前设备呼叫能力，如果支持继续下一步；如果不支持则无法发起呼叫。

3. 跳转到拨号界面，并显示拨号的号码。

4. （可选）订阅通话业务状态变化。
   
   ```js
   // import需要的模块
   import call from '@ohos.telephony.call';
   import observer from '@ohos.telephony.observer';
   
   // 调用查询能力接口
   let isSupport = call.hasVoiceCapability();
   if (!isSupport) {
       console.log("not support voice capability, return.");
       return;
   }
   // 如果设备支持呼叫能力，则继续跳转到拨号界面，并显示拨号的号码
   call.makeCall("13xxxx", (err)=> {
       if (!err) {
           console.log("make call success.");
       } else {
           console.log("make call fail, err is:" + JSON.stringify(err));
       }
   });
   // 订阅通话业务状态变化（可选）
   observer.on("callStateChange", (data) => {
       console.log("call state change, data is:" + JSON.stringify(data));
   });
   ```
