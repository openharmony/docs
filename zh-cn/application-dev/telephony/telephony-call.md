# 拨打电话

## 场景介绍

开发者可以通过以下方式实现拨打电话的功能：
<!--Del-->
- 对于系统应用，开发者可以使用dialCall接口，直接进行音频/视频呼叫，在应用界面显示对应的通话。
<!--DelEnd-->
- 对于三方应用，开发者可以使用makeCall接口，拉起系统电话应用，用户可以自行呼出通话。

## 基本概念

- 通话状态码
  将当前的通话状态上报给app，可以根据当前的通话状态去做一些逻辑处理。例如在当前没有正在进行呼叫的时候，可以正常拨打新的一通电话。

  | 名称               | 值   | 说明                                                         |
  | ------------------ | ---- | ------------------------------------------------------------ |
  | CALL_STATE_UNKNOWN | -1   | 无效状态，当获取呼叫状态失败时返回。                         |
  | CALL_STATE_IDLE    | 0    | 表示没有正在进行的呼叫。                                     |
  | CALL_STATE_RINGING | 1    | 表示来电正在振铃或等待。                                     |
  | CALL_STATE_OFFHOOK | 2    | 表示至少有一个呼叫处于拨号、通话中或呼叫保持状态，并且没有新的来电振铃或等待。 |

## 约束与限制

1. 仅支持在标准系统上运行。
2. 设备需插入可用的SIM卡。


## 接口说明

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用callback函数，更多方式可以查阅[API参考](../reference/apis-telephony-kit/js-apis-call.md)。

|                                  接口名                                             | 描述                                                         |
| ----------------------------------------------------------------------------------- | ------------------------------------------------------------ |
| hasVoiceCapability(): boolean;                                                      | 判断是否具有语音功能。                                        |
|<!--DelRow--> dialCall(phoneNumber: string, callback: AsyncCallback&lt;void&gt;): void;                 | 拨号。该接口为系统接口。                                      |
| makeCall(phoneNumber: string, callback: AsyncCallback&lt;void&gt;): void;                 | 转到拨号屏幕，显示被叫号码。                                  |

observer模块为开发者提供订阅和取消订阅通话业务状态的功能。具体API说明详见[接口文档](../reference/apis-telephony-kit/js-apis-observer.md)。

| 接口名                                                       | 描述               |
| ------------------------------------------------------------ | ------------------ |
| on(type: 'callStateChange', options: { slotId: number }, callback: Callback<{ state: CallState, number: string }>): void; | 监听通话状态变化。 |

## 开发步骤

<!--Del-->
### 使用dialCall拨打电话（仅供系统应用使用）

1. 声明接口调用所需要的权限：ohos.permission.PLACE_CALL。
此权限级别为system_basic，在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)声明对应权限。
1. 导入call和observer模块。
2. 调用hasVoiceCapability，确认当前设备是否支持拨号。
3. 调用dialCall接口，拨打电话。
4. （可选）订阅通话业务状态变化。
   ```ts
    // import需要的模块
    import { call, observer } from '@kit.TelephonyKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    // 调用查询能力接口
    let isSupport = call.hasVoiceCapability();
    if (isSupport) {
        // 如果设备支持呼叫能力，调用以下接口进行拨号
        call.dialCall("13xxxx", (err: BusinessError) => {
            console.log(`callback: dial call err->${JSON.stringify(err)}`);
        })

        // 订阅通话业务状态变化（可选）
        class SlotId {slotId: number = 0}
        class CallStateCallback {
            state: call.CallState = call.CallState.CALL_STATE_UNKNOWN;
            number: string = "";
        }
        let slotId: SlotId = {slotId: 0}
        observer.on("callStateChange", slotId, (data: CallStateCallback) => {
            console.log("call state change, data is:" + JSON.stringify(data));
        });
    }
   ```
<!--DelEnd-->
### 使用makeCall拨打电话

1. 导入call和observer模块。
2. 调用hasVoiceCapability，确认当前设备是否支持拨号。
3. 调用makeCall接口，跳转到拨号界面并显示待拨号的号码。
4. （可选）订阅通话业务状态变化。

   ```ts
    // import需要的模块
    import { call, observer } from '@kit.TelephonyKit';
    import { BusinessError } from '@kit.BasicServicesKit';
   
    // 调用查询能力接口
    let isSupport = call.hasVoiceCapability();
    if (isSupport) {
        // 如果设备支持呼叫能力，则继续跳转到拨号界面，并显示拨号的号码
        call.makeCall("13xxxx", (err: BusinessError) => {
            if (!err) {
                console.log("make call success.");
            } else {
                console.log("make call fail, err is:" + JSON.stringify(err));
            }
        });
        // 订阅通话业务状态变化（可选）
        class SlotId {slotId: number = 0}
        class CallStateCallback {
            state: call.CallState = call.CallState.CALL_STATE_UNKNOWN;
            number: string = "";
        }
        let slotId: SlotId = {slotId: 0}
        observer.on("callStateChange", slotId, (data: CallStateCallback) => {
            console.log("call state change, data is:" + JSON.stringify(data));
        });
    }
   ```

## 相关实例

针对拨打电话，有以下相关实例可供参考：

- [拨打电话（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.1-Release/code/SystemFeature/Telephony/Call)
