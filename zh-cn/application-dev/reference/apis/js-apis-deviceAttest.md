# @ohos.deviceAttest (设备证明)

该模块提供设备证明结果的查询接口。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```js
import deviceAttest from '@ohos.deviceAttest';
```

## deviceAttest.getAttestStatus

getAttestStatus(callback: AsyncCallback&lt;BatteryStatsInfo&gt;) : void

获取设备证明结果详细信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.XTS.DeviceAttest

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[AttestResultInfo](#AttestResultInfo)> | 是   | 回调函数。当获取设备证明结果详细信息成功，error为undefined，result为获取到的[AttestResultInfo](#AttestResultInfo)>；否则为错误对象。 |

**错误码：**

| 错误码ID  | 错误信息       |
|----------|----------------|
| 202      | 应用为非系统应用 |
| 401      | 入参检查失败     |
| 20000001 | 获取设备证明结果失败。 |

**示例：**

```js
try {
    deviceAttest.getAttestStatus((error, result) => {
        if (typeof err === 'undefined') {
            console.info("error code:" + error.code + " message:" + error.message);
        } else {
            console.info("auth:" + result.authResult + " software:" + result.softwareResult + " ticket:" + result.ticket);
            console.info("versionIdResult:" + result.softwareResultDetail[0],
                " patchlevelResult:" + result.softwareResultDetail[1],
                " roothashResult:" + result.softwareResultDetail[2],
                " PCIDResult:" + result.softwareResultDetail[3],
                " reserver:" + result.softwareResultDetail[4]);
        }
    })
} catch (error) {
    console.info("error code:" + error.code + " message:" + error.message);
}
```

## deviceAttest.getAttestStatus

getAttestStatus() : Promise&lt;AttestResultInfo&gt;

获取设备证明结果详细信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.XTS.DeviceAttest

**返回值：**

| 类型                                                  | 说明                            |
| ----------------------------------------------------- | ------------------------------- |
| Promise<[AttestResultInfo](#AttestResultInfo)> | Promise对象，返回设备证明结果详细信息。 |

**错误码：**

| 错误码ID  | 错误信息       |
|----------|----------------|
| 202      | 应用为非系统应用 |
| 401      | 入参检查失败     |
| 20000001 | 获取设备证明结果失败。 |

**示例：**

```js
try {
    deviceAttest.getAttestStatus().then((value) => {
        console.info("auth:" + result.authResult + " software:" + result.softwareResult + " ticket:" + result.ticket);
        console.info("versionIdResult:" + result.softwareResultDetail[0],
            " patchlevelResult:" + result.softwareResultDetail[1],
            " roothashResult:" + result.softwareResultDetail[2],
            " PCIDResult:" + result.softwareResultDetail[3],
            " reserver:" + result.softwareResultDetail[4]);
    }).catch((error) => {
        console.info("error code:" + error.code + " message:" + error.message);
    });
} catch (error) {
    console.info("error code:" + error.code + " message:" + error.message);
}
```

## deviceAttest.getAttestStatusSync

getAttestStatusSync() : AttestResultInfo

获取设备证明结果详细信息。使用同步调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.XTS.DeviceAttest

**返回值：**

| 类型                                                  | 说明                            |
| ----------------------------------------------------- | ------------------------------- |
| [AttestResultInfo](#AttestResultInfo) | 返回设备证明结果详细信息。 |

**错误码：**

| 错误码ID  | 错误信息       |
|----------|----------------|
| 202      | 应用为非系统应用 |
| 401      | 入参检查失败     |
| 20000001 | 获取设备证明结果失败。 |

**示例：**

```js
try {
    let attestResultInfo = deviceAttest.getAttestStatusSync();
    console.info("auth:" + result.authResult + " software:" + result.softwareResult + " ticket:" + result.ticket);
    console.info("versionIdResult:" + result.softwareResultDetail[0],
        " patchlevelResult:" + result.softwareResultDetail[1],
        " roothashResult:" + result.softwareResultDetail[2],
        " PCIDResult:" + result.softwareResultDetail[3],
        " reserver:" + result.softwareResultDetail[4]);
} catch (error) {
    console.info("error code:" + error.code + " message:" + error.message);
}
```

## AttestResultInfo

设备证明结果详细信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.XTS.DeviceAttest

### 属性

| 名称                  | 类型                  | 可读 | 可写 | 说明                   |
| --------------------- | --------------------- | ---- | ---- | ---------------------- |
| authResult            | number               | 是   | 否   | 设备硬件信息校验结果。    |
| softwareResult        | number               | 是   | 否   | 设备软件信息校验结果。    |
| softwareResultDetail  | Array&lt;number&gt;  | 是   | 否   | 设备软件信息校验结果详细说明  |
| ticket                | string               | 是   | 否   | 耗电的值，单位毫安时。 |

## softwareResultDetail

表示设备软件信息校验结果的详细说明。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.XTS.DeviceAttest

| 名称                         | 说明                        |
| --------------------------  | --------------------------- |
| softwareResultDetail[0]     | 版本Id的校验结果。        |
| softwareResultDetail[1]     | 安全补丁标签的校验结果。      |
| softwareResultDetail[2]     | 版本Hash的校验结果。      |
| softwareResultDetail[3]     | 系统能力集合的校验结果。 |
| softwareResultDetail[4]     | 保留位  |

