# @ohos.distributedHardware.hardwareManager (分布式硬件管理)

分布式硬件管理模块提供控制分布式硬件的能力，包括暂停、恢复和停止被控端分布式硬件业务。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口为系统接口。

## 导入模块

```js
import hardwareManager from '@ohos.distributedHardware.hardwareManager';
```

## HardwareDescriptor

表示分布式硬件的描述信息。

**系统能力**：SystemCapability.DistributedHardware.DistributedHardwareFWK

| 名称         | 类型                                                | 必填 | 说明                                   |
| ------------ | --------------------------------------------------- | ---- | -------------------------------------- |
| type         | [DistributedHardwareType](#distributedhardwaretype) | 是   | 分布式硬件类型。                       |
| srcNetworkId | string                                              | 否   | 表示源端设备，缺省时表示所有源端设备。 |

## DistributedHardwareType

表示分布式硬件类型。

**系统能力**：SystemCapability.DistributedHardware.DistributedHardwareFWK

| 名称          | 值   | 说明                         |
| :------------ | ---- | ---------------------------- |
| ALL           | 0    | 表示所有分布式应用。         |
| CAMERA        | 1    | 表示分布式相机。             |
| SCREEN        | 8    | 表示分布式屏幕。             |
| MODEM_MIC     | 256  | 表示分布式移动通话的麦克风。 |
| MODEM_SPEAKER | 512  | 表示分布式移动通话的扬声器。 |
| MIC           | 1024 | 表示分布式麦克风。           |
| SPEAKER       | 2048 | 表示分布式扬声器。           |

## DistributedHardwareErrorCode

分布式硬件错误码的枚举。

**系统能力**：SystemCapability.DistributedHardware.DistributedHardwareFWK

| 名称                                      | 值       | 说明                   |
| ----------------------------------------- | -------- | ---------------------- |
| ERR_CODE_DISTRIBUTED_HARDWARE_NOT_STARTED | 24200101 | 表示分布式硬件未启动。 |
| ERR_CODE_DEVICE_NOT_CONNECTED             | 24200102 | 表示源端设备未连接。   |

## hardwareManager.pauseDistributedHardware

pauseDistributedHardware(description: HardwareDescriptor, callback: AsyncCallback<void>): void;

暂停被控端分布式硬件业务。使用callback异步回调。

**需要权限**：ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**系统能力**：SystemCapability.DistributedHardware.DistributedHardwareFWK

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| description | [HardwareDescriptor](#hardwaredescriptor) | 是    | 硬件描述信息。 |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 执行回调函数，方法执行成功时err为undefined，方法执行失败时为错误对象。 |

**示例：**

  ```ts
  import hardwareManager from '@ohos.distributedHardware.hardwareManager'
  import { BusinessError } from '@ohos.base';
  
  try {
    let description: hardwareManager.HardwareDescriptor = {
      type: hardwareManager.DistributedHardwareType.CAMERA
    };
    hardwareManager.pauseDistributedHardware(description, (error:BusinessError) => {
      if (error.code) {
        console.error('pauseDistributedHardware failed, cause: ' + JSON.stringify(error));
      }
      console.log('pause distributed hardware successfully');
    })
  } catch (error) {
    console.error('pause distributed hardware failed: ' + JSON.stringify(error))
  }
  ```
## hardwareManager.pauseDistributedHardware

pauseDistributedHardware(description: HardwareDescriptor): Promise&lt;void&gt;

暂停被控端分布式硬件业务。使用promise异步回调。

**需要权限**：ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**系统能力**：SystemCapability.DistributedHardware.DistributedHardwareFWK

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| description | [HardwareDescriptor](#hardwaredescriptor) | 是   | 硬件描述信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

  ```ts
  import hardwareManager from '@ohos.distributedHardware.hardwareManager'
  import { BusinessError } from '@ohos.base';
  
  try {
    let description: hardwareManager.HardwareDescriptor = {
      type: hardwareManager.DistributedHardwareType.CAMERA
    };
    hardwareManager.pauseDistributedHardware(description).then(()=>{
      console.log('pause distributed hardware successfully');
    }).catch((error: BusinessError) => {
      console.error('pause distributed hardware failed, cause:'+error);
    })
  } catch (error) {
    console.error('pause distributed hardware failed: ' + JSON.stringify(error))
  }
  ```

## hardwareManager.resumeDistributedHardware

resumeDistributedHardware(description: HardwareDescriptor, callback: AsyncCallback<void>): void;

恢复被控端分布式硬件业务。使用callback异步回调。

**需要权限**：ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**系统能力**：SystemCapability.DistributedHardware.DistributedHardwareFWK

**参数：**

| 参数名      | 类型                                      | 必填 | 说明                                                         |
| ----------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| description | [HardwareDescriptor](#hardwaredescriptor) | 是   | 硬件描述信息。                                               |
| callback    | AsyncCallback&lt;void&gt;                 | 是   | 执行回调函数，方法执行成功时err为undefined，方法执行失败时为错误对象。 |

**示例：**

  ```ts
import hardwareManager from '@ohos.distributedHardware.hardwareManager'
import { BusinessError } from '@ohos.base';

try {
  let description: hardwareManager.HardwareDescriptor = {
    type: hardwareManager.DistributedHardwareType.CAMERA
  };
  hardwareManager.resumeDistributedHardware(description, (error:BusinessError) => {
    if (error.code) {
      console.error('resumeDistributedHardware failed, cause: ' + JSON.stringify(error));
    }
    console.log('resume distributed hardware successfully');
  })
} catch (error) {
  console.error('resume distributed hardware failed: ' + JSON.stringify(error));
}
  ```

## hardwareManager.resumeDistributedHardware

resumeDistributedHardware(description: HardwareDescriptor): Promise&lt;void&gt;

恢复被控端分布式硬件业务。使用promise异步回调。

**需要权限**：ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**系统能力**：SystemCapability.DistributedHardware.DistributedHardwareFWK

**参数：**

| 参数名      | 类型                                      | 必填 | 说明           |
| ----------- | ----------------------------------------- | ---- | -------------- |
| description | [HardwareDescriptor](#hardwaredescriptor) | 是   | 硬件描述信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

  ```ts
import hardwareManager from '@ohos.distributedHardware.hardwareManager'
import { BusinessError } from '@ohos.base';

try {
  let description: hardwareManager.HardwareDescriptor = {
    type: hardwareManager.DistributedHardwareType.CAMERA
  };
  hardwareManager.resumeDistributedHardware(description).then(()=>{
    console.log('resume distributed hardware successfully');
  }).catch((error: BusinessError) => {
    console.error('resume distributed hardware failed, cause:'+error);
  })
} catch (error) {
  console.error('resume distributed hardware failed: ' + JSON.stringify(error));
}
  ```

## hardwareManager.stopDistributedHardware

stopDistributedHardware(description: HardwareDescriptor, callback: AsyncCallback<void>): void;

停止被控端分布式硬件业务。使用callback异步回调。

**需要权限**：ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**系统能力**：SystemCapability.DistributedHardware.hardwareManager

**参数：**

| 参数名      | 类型                                      | 必填 | 说明                                                         |
| ----------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| description | [HardwareDescriptor](#hardwaredescriptor) | 是   | 硬件描述信息。                                               |
| callback    | AsyncCallback&lt;void&gt;                 | 是   | 执行回调函数，方法执行成功时err为undefined，方法执行失败时为错误对象。 |

**示例：**

  ```ts
import hardwareManager from '@ohos.distributedHardware.hardwareManager'
import { BusinessError } from '@ohos.base';

try {
  let description: hardwareManager.HardwareDescriptor = {
    type: hardwareManager.DistributedHardwareType.CAMERA
  };
  hardwareManager.stopDistributedHardware(description, (error:BusinessError) => {
    if (error.code) {
      console.error('stopDistributedHardware failed, cause: ' + JSON.stringify(error));
    }
    console.log('stop distributed hardware successfully');
  })
} catch (error) {
  console.error('stop distributed hardware failed: ' + JSON.stringify(error));
}
  ```

## hardwareManager.stopDistributedHardware

stopDistributedHardware(description: HardwareDescriptor): Promise&lt;void&gt;

停止被控端分布式硬件业务。使用promise异步回调。

**需要权限**：ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**系统能力**：SystemCapability.DistributedHardware.hardwareManager

**参数：**

| 参数名      | 类型                                      | 必填 | 说明           |
| ----------- | ----------------------------------------- | ---- | -------------- |
| description | [HardwareDescriptor](#hardwaredescriptor) | 是   | 硬件描述信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

  ```ts
import hardwareManager from '@ohos.distributedHardware.hardwareManager'
import { BusinessError } from '@ohos.base';

try {
  let description: hardwareManager.HardwareDescriptor = {
    type: hardwareManager.DistributedHardwareType.CAMERA
  };
  hardwareManager.stopDistributedHardware(description).then(()=>{
    console.log('stop distributed hardware successfully');
  }).catch((error: BusinessError) => {
    console.error('stop distributed hardware failed, cause:'+error);
  })
} catch (error) {
  console.error('stop distributed hardware failed: ' + JSON.stringify(error));
}
  ```
