# @ohos.distributedDeviceManager (设备管理)(系统接口)

本模块提供分布式设备管理能力。

应用可调用接口实现如下功能：

- 注册和解除注册设备上下线变化监听。
- 发现周边不可信设备。
- 认证和取消认证设备。
- 查询可信设备列表。
- 查询本地设备信息，包括设备名称，设备类型和设备标识等。


> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.distributedDeviceManager (设备管理)](js-apis-distributedDeviceManager.md)。


## 导入模块

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
```

### replyUiAction

replyUiAction(action: number, actionResult: string): void;

回复用户UI操作行为。此接口只能被devicemanager的PIN码hap使用。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | action        | number          | 是    | 用户操作动作。<br />-0：允许授权。<br />-1：取消授权。<br />-2：授权框用户操作超时。<br />-3：取消pin码框展示。<br />-4：取消pin码输入框展示。<br />-5：pin码输入框确定操作。     |
  | actionResult        | string          | 是    | 表示用户操作结果。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified actionResult is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[创建一个设备管理实例](js-apis-distributedDeviceManager.md#distributeddevicemanagercreatedevicemanager)。
<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

 try {
    /*
      action = 0 - 允许授权
      action = 1 - 取消授权
      action = 2 - 授权框用户操作超时
      action = 3 - 取消pin码框展示
      action = 4 - 取消pin码输入框展示
      action = 5 - pin码输入框确定操作
    */
    let operation = 0;
    dmInstance.replyUiAction(operation, 'extra');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyUiAction errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### on('replyResult')

on(type: 'replyResult', callback: Callback&lt;{ param: string;}&gt;): void;

回复UI操作结果回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名      | 类型                             | 必填 | 说明                            |
  | -------- | ------------------------------------ | ---- | ------------------------------ |
  | type     | string                                | 是  | 注册的设备管理器 UI 状态回调，以便在状态改变时通知应用，固定为replyResult。 |
  | callback | Callback&lt;{&nbsp;param:&nbsp;string;}&gt; | 是  | 指示要注册的设备管理器 UI 状态回调，返回UI状态。        |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[创建一个设备管理实例](js-apis-distributedDeviceManager.md#distributeddevicemanagercreatedevicemanager)。
<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    param: string = '';
  }

  interface TmpStr {
    verifyFailed: boolean;
  }

  try {
    dmInstance.on('replyResult', (data: Data) => {
      console.log('replyResult executed, dialog closed' + JSON.stringify(data));
      let tmpStr: TmpStr = JSON.parse(data.param);
      let isShow = tmpStr.verifyFailed;
      console.log('replyResult executed, dialog closed' + isShow);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyResult errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### off('replyResult')

off(type: 'replyResult', callback?: Callback&lt;{ param: string;}&gt;): void;

取消回复UI操作结果回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名      | 类型                              | 必填 | 说明                            |
  | -------- | ------------------------------------- | ---- | ------------------------------ |
  | type     | string                                | 是   | 取消注册的设备管理器 UI 状态回调，固定为replyResult。 |
  | callback | Callback&lt;{&nbsp;param:&nbsp;string;}&gt; | 否   | 指示要取消注册的设备管理器 UI 状态，返回UI状态。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[创建一个设备管理实例](js-apis-distributedDeviceManager.md#distributeddevicemanagercreatedevicemanager)。
<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    dmInstance.off('replyResult');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyResult errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

