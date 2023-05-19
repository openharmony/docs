# @ohos.resourceschedule.deviceStandby（设备待机空闲部件功能）
本模块提供设备待机空闲部件管理功能
API使用场景：
如果用户长时间没有主动使用设备，且屏幕已关闭，则系统会使设备进入待机低功耗续航模式。待机续航模式会延迟应用后台CPU和网络活动，从而延长电池续航时间。 包括：
1、应用限网：限制后台应用访问网络
2、Work待机任务：延迟应用的work任务响应
3、running_lock锁：临时释放应用的background running_lock锁
4、Timer响应：延迟应用的timer响应
5、待规划：停止wifi扫描、停止蓝牙扫描、云同步账户等
>  **说明：**
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块
```js
import deviceStandby from '@ohos.resourceschedule.deviceStandby';
```
## deviceStandby.isDeviceInStandby
function isDeviceInStandby(callback: AsyncCallback<boolean>): void;
当前设备是否进入待机低功耗续航模式
**系统能力:** SystemCapability.ResourceSchedule.DeviceStandby
**参数**：

| 参数名      | 类型                   | 必填   | 说明                             |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | Callback&lt;void&gt; | 是    | 延迟即将超时的回调函数，一般在超时前6秒通过此回调通知应用。 |

**错误码**：
以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed when applying for efficiency resources. |

## deviceStandby.isDeviceInStandby
function isDeviceInStandby(): Promise&lt;boolean&gt;
当前设备是否进入待机低功耗续航模式
**系统能力:** SystemCapability.ResourceSchedule.DeviceStandby
**返回值**：

| 类型                    | 说明                                       |
| --------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | 指定的Promise回调方法。返回是否进入待机低功耗续航模式。|

**错误码**：
以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed when applying for efficiency resources. |

## deviceStandby.getExemptedApps
function getExemptedApps(resourceTypes: number, callback: AsyncCallback<Array&lt;ExemptedAppInfo&gt;>): void;
返回豁免应用名单
**系统能力:** SystemCapability.ResourceSchedule.DeviceStandby
**系统API:** 此接口为系统接口。

**参数**：

| 参数名      | 类型                   | 必填   | 说明                             |
| -------- | -------------------- | ---- | ------------------------------ |
| resourceTypes |number | 是    | 资源类型，具体结构见文末枚举 |
| callback | AsyncCallback<Array&lt;ExemptedAppInfo&gt;> | 是    | 回调函数，具体结构见文末 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed when applying for efficiency resources. |
## deviceStandby.getExemptedApps
function getExemptedApps(resourceTypes: number): Promise<Array&lt;ExemptedAppInfo&gt;>;
返回豁免应用名单
**系统能力:** SystemCapability.ResourceSchedule.DeviceStandby
**系统API:** 此接口为系统接口。
**参数**：

| 参数名      | 类型                   | 必填   | 说明                             |
| -------- | -------------------- | ---- | ------------------------------ |
| resourceTypes |number | 是    | 资源类型。 |

**返回值**：

| 类型                    | 说明                                       |
| --------------------- | ---------------------------------------- |
| Promise<Array&lt;ExemptedAppInfo&gt;> | 指定的Promise回调方法。返回豁免应用名单，具体结构见文末|

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed when applying for efficiency resources. |

## deviceStandby.requestExemptionResource
function requestExemptionResource(request: ResourceRequest): void;
订阅申请豁免
**系统能力:** SystemCapability.ResourceSchedule.DeviceStandby.Exemption
**系统API:** 此接口为系统接口。
**参数**：

| 参数名      | 类型                   | 必填   | 说明                             |
| -------- | -------------------- | ---- | ------------------------------ |
| request |ResourceRequest | 是    | 请求豁免应用信息数据结构，具体结构见文末请求体 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed when applying for efficiency resources. |

## deviceStandby.releaseExemptionResource
function releaseExemptionResource(request: ResourceRequest): void;
去除订阅申请豁免
**系统能力:** SystemCapability.ResourceSchedule.DeviceStandby.Exemption
**系统API:** 此接口为系统接口。

**参数**：

| 参数名      | 类型                   | 必填   | 说明                             |
| -------- | -------------------- | ---- | ------------------------------ |
| request |ResourceRequest | 是    | 请求豁免应用信息数据结构，具体结构见文末请求体 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed when applying for efficiency resources. |

## 枚举类和请求体
### ResourceType
The resource type of exemption application.
<br>

|名称   |枚举值   |说明|
| ------------ | ------------ |--------------|
|NETWORK    |1   |The resource for non-standby network access.|
|RUNNING_LOCK    |1 << 1   |The resource for non-standby cpu-runninglock.|
|TIMER     |1 << 2   |The resource for non-standby timer.|
|WORK_SCHEDULER     |1 << 3   |The resource for non-standby workscheduler.|
|AUTO_SYNC      |1 << 4   |The resource for non-standby Automatic synchronization.|
|PUSH     |1 << 5   |The resource for non-standby pushkit.|
|FREEZE       |1 << 6   |The resource for non-standby freezing application.|

### ExemptedAppInfo 
The information of exemption application.
<br>

|对象名   |类型   |说明   |
| ------------ | ------------ | ------------ |
|resourceTypes   | number  |The set of resource types that app wants to apply.   |
|name   |string   |  The app name.  |
|duration   | number  | The exemption duration. |

### ResourceRequest
The request of standby resources.
<br>

|对象名   |类型   |说明   |
| ------------ | ------------ | ------------ |
|resourceTypes   | number  |The set of resource types that app wants to apply.   |
|uid   | number  |The app uid.   |
|name   |string   |  The app name.  |
|duration   | number  | The exemption duration. |
|reason   |string   |  The apply reason.  |