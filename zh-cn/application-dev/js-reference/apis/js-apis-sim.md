# SIM卡管理

>**说明：** 
>
>- 从 API Version 6 开始支持。
>- 标记<sup>7+</sup>的接口从API Version 7开始支持。

## 导入模块

```
import sim from '@ohos.telephony.sim';
```

## sim.getSimIccId<a name=sim.getSimIccId-callback></a>

getSimIccId\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的ICCID（Integrate Circuit Card Identity），使用callback方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

-   参数

    | 参数名   | 类型                        | 必填 | 说明                                   |
    | -------- | --------------------------- | ---- | -------------------------------------- |
    | slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
    | callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。                             |


-   示例

    ```
    sim.getSimIccId(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimIccId<a name=sim.getSimIccId-promise></a>

getSimIccId\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的ICCID（Integrate Circuit Card Identity），使用Promise方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

- 参数

    | 参数名 | 类型   | 必填 | 说明                                   |
    | ------ | ------ | ---- | -------------------------------------- |
    | slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

- 返回值

    | 类型                  | 说明                               |
    | --------------------- | ---------------------------------- |
    | Promise&lt;string&gt; | 以Promise形式返回指定卡槽的ICCID。 |

-   示例

    ```
    let promise = sim.getSimIccId(0);
    promise.then(data => {
        console.log(`getSimIccId success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimIccId fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sim.getDefaultVoiceSlotId<sup>7+</sup><a name= sim.getDefaultVoiceSlotId-callback></a>

getDefaultVoiceSlotId\(callback: AsyncCallback<number\>\): void

获取默认语音业务的卡槽ID，使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                        | 必填 | 说明       |
  | -------- | --------------------------- | ---- | ---------- |
  | callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。 |

-   示例

    ```
    sim.getDefaultVoiceSlotId((err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getDefaultVoiceSlotId<sup>7+</sup><a name=sim.getDefaultVoiceSlotId-promise></a>

getDefaultVoiceSlotId\(\): Promise<number\>

获取默认语音业务的卡槽ID，使用Promise方式作为异步方法。

- 返回值

  | 类型              | 说明                                    |
  | ----------------- | --------------------------------------- |
  | Promise\<number\> | 以Promise形式返回默认语音业务的卡槽ID。 |

-   示例

    ```
    let promise = sim.getDefaultVoiceSlotId();
    promise.then(data => {
        console.log(`getDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getDefaultVoiceSlotId fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sim.getISOCountryCodeForSim<a name=sim.getISOCountryCodeForSim-callback></a>

getISOCountryCodeForSim\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的ISO国家码，使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                    | 必填 | 说明                                     |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2   |
  | callback | AsyncCallback\<string\> | 是   | 回调函数。返回国家码，例如：CN（中国）。 |

-   示例

    ```
    sim.getISOCountryCodeForSim(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getISOCountryCodeForSim<a name=sim.getISOCountryCodeForSim-promise></a>

getISOCountryCodeForSim\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的ISO国家码，使用Promise方式作为异步方法。

- 参数

  | 参数名 | 类型   | 必填 | 说明                                   |
  | ------ | ------ | ---- | -------------------------------------- |
  | slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

- 返回值

  | 类型              | 说明                                                         |
  | ----------------- | ------------------------------------------------------------ |
  | Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的ISO国家码，例如：CN（中国）。 |

-   示例

    ```
    let promise = sim.getISOCountryCodeForSim(0);
    promise.then(data => {
        console.log(`getISOCountryCodeForSim success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getISOCountryCodeForSim fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sim.getSimOperatorNumeric<a name=sim.getSimOperatorNumeric-callback></a>

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号，使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                    | 必填 | 说明                                   |
  | -------- | ----------------------- | ---- | -------------------------------------- |
  | slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
  | callback | AsyncCallback\<string\> | 是   | 回调函数。                             |

-   示例

    ```
    sim.getSimOperatorNumeric(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimOperatorNumeric<a name=sim.getSimOperatorNumeric-promise></a>

getSimOperatorNumeric\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号，使用Promise方式作为异步方法。

- 参数

  | 参数名 | 类型   | 必填 | 说明                                   |
  | ------ | ------ | ---- | -------------------------------------- |
  | slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

- 返回值

  | 类型              | 说明                                             |
  | ----------------- | ------------------------------------------------ |
  | Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的归属PLMN号。 |

-   示例

    ```
    let promise = sim.getSimOperatorNumeric(0);
    promise.then(data => {
        console.log(`getSimOperatorNumeric success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimOperatorNumeric fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sim.getSimSpn<a name=sim.getSimSpn-callback></a>

getSimSpn\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN），使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                    | 必填 | 说明                                   |
  | -------- | ----------------------- | ---- | -------------------------------------- |
  | slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
  | callback | AsyncCallback\<string\> | 是   | 回调函数。                             |

-   示例

    ```
    sim.getSimSpn(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimSpn<a name=sim.getSimSpn-promise></a>

getSimSpn\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN），使用Promise方式作为异步方法。

- 参数

    | 参数名 | 类型   | 必填 | 说明                                   |
    | ------ | ------ | ---- | -------------------------------------- |
    | slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

- 返回值

    | 类型              | 说明                                      |
    | ----------------- | ----------------------------------------- |
    | Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的SPN。 |

-   示例

    ```
    let promise = sim.getSimSpn(0);
    promise.then(data => {
        console.log(`getSimSpn success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimSpn fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sim.getSimState<a name=sim.getSimState-callback></a>

getSimState\(slotId: number, callback: AsyncCallback<SimState\>\): void

获取指定卡槽的SIM卡状态，使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                                   | 必填 | 说明                                      |
  | -------- | -------------------------------------- | ---- | ----------------------------------------- |
  | slotId   | number                                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2    |
  | callback | AsyncCallback\<[SimState](#SimState)\> | 是   | 回调函数。参考[SimState](#SimState)。 |

-   示例

    ```
    sim.getSimState(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimState<a name=sim.getSimState-promise></a>

getSimState\(slotId: number\): Promise<SimState\>

获取指定卡槽的SIM卡状态，使用Promise方式作为异步方法。

- 参数

    | 参数名 | 类型   | 必填 | 说明                                   |
    | ------ | ------ | ---- | -------------------------------------- |
    | slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

- 返回值

    | 类型                             | 说明                                       |
    | -------------------------------- | ------------------------------------------ |
    | Promise\<[SimState](#SimState)\> | 以Promise形式返回获取指定卡槽的SIM卡状态。 |

-   示例

    ```
    let promise = sim.getSimState(0);
    promise.then(data => {
        console.log(`getSimState success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimState fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sim.getSimGid1<a name=sim.getSimGid1-callback></a>

getSimGid1\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的GID1\(Group Identifier Level 1\)，使用callback方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

- 参数

  | 参数名   | 类型                    | 必填 | 说明                                   |
  | -------- | ----------------------- | ---- | -------------------------------------- |
  | slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
  | callback | AsyncCallback\<string\> | 是   | 回调函数。                             |

-   示例

    ```
    sim.getSimGid1(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimGid1<a name=sim.getSimGid1-promise></a>

getSimGid1\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的GID1\(Group Identifier Level 1\)，使用Promise方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

- 参数

    | 参数名 | 类型   | 必填 | 说明                                   |
    | ------ | ------ | ---- | -------------------------------------- |
    | slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

- 返回值

    | 类型              | 说明                                                         |
    | ----------------- | ------------------------------------------------------------ |
    | Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的GID1(Group Identifier Level 1)。 |

-   示例

    ```
    let promise = sim.getSimGid1(0);
    promise.then(data => {
        console.log(`getSimGid1 success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimGid1 fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## SimState<a name=SimState></a>

SIM卡状态。

| 变量                  | 说明                                                       |
| --------------------- | ---------------------------------------------------------- |
| SIM_STATE_UNKNOWN     | SIM卡状态未知，即无法获取准确的状态。                      |
| SIM_STATE_NOT_PRESENT | 表示SIM卡处于not present状态，即卡槽中没有插入SIM卡。      |
| SIM_STATE_LOCKED      | 表示SIM卡处于locked状态，即SIM卡被PIN、PUK或网络锁锁定。   |
| SIM_STATE_NOT_READY   | 表示SIM卡处于not ready状态，即SIM卡在位但无法正常工作。    |
| SIM_STATE_READY       | 表示SIM卡处于ready状态，即SIM卡在位且工作正常。            |
| SIM_STATE_LOADED      | 表示SIM卡处于loaded状态，即SIM卡在位且所有卡文件加载完毕。 |