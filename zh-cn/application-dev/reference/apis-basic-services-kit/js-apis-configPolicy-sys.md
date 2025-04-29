# @ohos.configPolicy (配置策略)(系统接口)

配置策略提供按预先定义的定制配置层级获取对应定制配置目录和文件路径的能力。

>  **说明：**
>
>  本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  本模块接口均为系统接口。

## 导入模块

```ts
import configPolicy from '@ohos.configPolicy';
```

## getOneCfgFile

getOneCfgFile(relPath: string, callback: AsyncCallback&lt;string&gt;)

使用callback形式返回指定文件名的最高优先级配置文件路径。
例如，config.xml在设备中存在以下路径（优先级从低到高）：/system/etc/config.xml、/sys_pod/etc/config.xml，最终返回/sys_pod/etc/config.xml。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                       |
| -------- | --------------------------- | ---- | ------------------------------------------ |
| relPath  | string                      | 是   | 配置文件名。                                 |
| callback | AsyncCallback&lt;string&gt; | 是   | 异步回调，用于返回最高优先级配置文件的路径。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    configPolicy.getOneCfgFile(relpath, (error: BusinessError, value: string) => {
      if (error == null) {
        console.log('value is ' + value);
      } else {
        console.log('error occurs ' + error);
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getOneCfgFile

getOneCfgFile(relPath: string): Promise&lt;string&gt;

使用Promise形式返回指定文件名的最高优先级配置文件路径。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名  | 类型   | 必填 | 说明       |
| ------- | ------ | ---- | ---------- |
| relPath | string | 是   | 配置文件名。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**返回值：**

| 类型                   | 说明                     |
| ---------------------- | ------------------------ |
| Promise&lt;string&gt;  | 返回最高优先级配置文件的路径。 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    configPolicy.getOneCfgFile(relpath).then((value: string) => {
      console.log('value is ' + value);
    }).catch((error: BusinessError) => {
      console.log('getOneCfgFile promise ' + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getCfgFiles

getCfgFiles(relPath: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;)

按优先级从低到高，使用callback形式返回指定文件名所有的文件列表。
例如，config.xml在设备中存在以下路径（优先级从低到高）：/system/etc/config.xml、/sys_pod/etc/config.xml，最终返回/system/etc/config.xml, /sys_pod/etc/config.xml。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                       |
| -------- | ---------------------------------------- | ---- | -------------------------- |
| relPath  | string                                   | 是   | 配置文件名。                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 异步回调，用于返回文件列表。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    configPolicy.getCfgFiles('etc/config.xml', (error: BusinessError, value: Array<string>) => {
      if (error == null) {
        console.log('value is ' + value);
      } else {
        console.log('error occurs ' + error);
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getCfgFiles

getCfgFiles(relPath: string): Promise&lt;Array&lt;string&gt;&gt;

按优先级从低到高，使用Promise形式返回指定文件名所有的文件列表。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名  | 类型   | 必填 | 说明       |
| ------- | ------ | ---- | ---------- |
| relPath | string | 是   | 配置文件名。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**返回值：**

| 类型                               | 说明     |
| ---------------------------------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | 返回文件列表。 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    configPolicy.getCfgFiles(relpath).then((value: Array<string>) => {
      console.log('value is ' + value);
    }).catch((error: BusinessError) => {
      console.log('getCfgFiles promise ' + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getCfgDirList

getCfgDirList(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;)

使用callback形式返回配置层级目录列表。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                               |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 异步回调，用于返回配置层级目录列表。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    configPolicy.getCfgDirList((error: BusinessError, value: Array<string>) => {
      if (error == null) {
        console.log('value is ' + value);
      } else {
        console.log('error occurs ' + error);
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getCfgDirList

getCfgDirList(): Promise&lt;Array&lt;string&gt;&gt;

使用Promise形式返回配置层级目录列表。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**返回值：**

| 类型                               | 说明             |
| ---------------------------------- | ---------------- |
| Promise&lt;Array&lt;string&gt;&gt; | 返回配置层级目录列表。 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    configPolicy.getCfgDirList().then((value: Array<string>) => {
      console.log('value is ' + value);
    }).catch((error: BusinessError) => {
      console.log('getCfgDirList promise ' + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getOneCfgFile<sup>11+</sup>

getOneCfgFile(relPath: string, followMode: FollowXMode, callback: AsyncCallback&lt;string&gt;)

根据提供的跟随模式获取指定文件名的最高优先级配置文件路径，并使用callback形式返回。
例如，config.xml在设备中存在以下路径（优先级从低到高）：/system/etc/config.xml、/sys_pod/etc/config.xml、/sys_pod/etc/carrier/46060/etc/config.xml，且设备默认卡opkey为46060，设置的followMode为configPolicy.FollowXMode.SIM_DEFAULT，最终返回/sys_pod/etc/carrier/46060/etc/config.xml。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名     | 类型                          | 必填 | 说明                                       |
| ---------- | ----------------------------- | ---- | ------------------------------------------ |
| relPath    | string                        | 是   | 配置文件名。                                 |
| followMode | [FollowXMode](#followxmode11) | 是   | 跟随模式。                                   |
| callback   | AsyncCallback&lt;string&gt;   | 是   | 异步回调，用于返回最高优先级配置文件的路径。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    configPolicy.getOneCfgFile(relpath, configPolicy.FollowXMode.SIM_DEFAULT,
      (error: BusinessError, value: string) => {
      if (error == null) {
        console.log('value is ' + value);
      } else {
        console.log('error occurs ' + error);
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getOneCfgFile<sup>11+</sup>

getOneCfgFile(relPath: string, followMode: FollowXMode, extra: string, callback: AsyncCallback&lt;string&gt;)

根据提供的跟随模式获取指定文件名的最高优先级配置文件路径，并使用callback形式返回。
例如，config.xml在设备中存在以下路径（优先级从低到高）：/system/etc/config.xml、/sys_pod/etc/config.xml、/sys_pod/etc/carrier/46060/etc/config.xml，且设备卡1的opkey为46060，设置的followMode为configPolicy.FollowXMode.USER_DEFINED，自定义跟随规则为"etc/carrier/${telephony.sim.opkey0}"，最终返回/sys_pod/etc/carrier/46060/etc/config.xml。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名     | 类型                          | 必填 | 说明                                                   |
| ---------- | ----------------------------- | ---- | ------------------------------------------------------ |
| relPath    | string                        | 是   | 配置文件名。                                             |
| followMode | [FollowXMode](#followxmode11) | 是   | 跟随模式。                                               |
| extra      | string                        | 是   | 用户自定义跟随规则，仅在followMode为USER_DEFINED时有效。 |
| callback   | AsyncCallback&lt;string&gt;   | 是   | 异步回调，用于返回最高优先级配置文件的路径。             |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    let extra: string = 'etc/carrier/${telephony.sim.opkey0}';
    configPolicy.getOneCfgFile(relpath, configPolicy.FollowXMode.USER_DEFINED, extra,
      (error: BusinessError, value: string) => {
      if (error == null) {
        console.log('value is ' + value);
      } else {
        console.log('error occurs ' + error);
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getOneCfgFile<sup>11+</sup>

getOneCfgFile(relPath: string, followMode: FollowXMode, extra?: string): Promise&lt;string&gt;

根据提供的跟随模式获取指定文件名的最高优先级配置文件路径，并使用Promise形式返回。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名     | 类型                          | 必填 | 说明                                                   |
| ---------- | ----------------------------- | ---- | ------------------------------------------------------ |
| relPath    | string                        | 是   | 配置文件名。                                             |
| followMode | [FollowXMode](#followxmode11) | 是   | 跟随模式。                                               |
| extra      | string                        | 否   | 用户自定义跟随规则，仅在followMode为USER_DEFINED时必填。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.|

**返回值：**

| 类型                   | 说明                     |
| ---------------------- | ------------------------ |
| Promise&lt;string&gt;  | 返回最高优先级配置文件的路径。 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    let extra: string = 'etc/carrier/${telephony.sim.opkey0}';
    configPolicy.getOneCfgFile(relpath, configPolicy.FollowXMode.SIM_DEFAULT, extra).then((value: string) => {
      console.log('value is ' + value);
    }).catch((error: BusinessError) => {
      console.log('getOneCfgFile promise ' + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getOneCfgFileSync<sup>11+</sup>

getOneCfgFileSync(relPath: string, followMode?: FollowXMode, extra?: string): string

根据提供的跟随模式返回指定文件名的最高优先级配置文件路径。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名     | 类型                          | 必填 | 说明                                                 |
| ---------- | ----------------------------- | ---- | ----------------------------------------------------|
| relPath    | string                        | 是   | 配置文件名。                                           |
| followMode | [FollowXMode](#followxmode11) | 否   | 跟随模式，不设置时，默认使用DEFAULT。                    |
| extra      | string                        | 否   | 用户自定义跟随规则，仅在followMode为USER_DEFINED时必填。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.|

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 返回最高优先级配置文件的路径。 |


**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    let extra: string = 'etc/carrier/${telephony.sim.opkey0}';
    let result: string = configPolicy.getOneCfgFileSync(relpath, configPolicy.FollowXMode.USER_DEFINED, extra);
    console.log('result is ' + result);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getCfgFiles<sup>11+</sup>

getCfgFiles(relPath: string, followMode: FollowXMode, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;)

按优先级从低到高，根据提供的跟随模式获取指定文件名所有的文件列表，并使用callback形式返回。
例如，config.xml在设备中存在以下路径（优先级从低到高）：/system/etc/config.xml、/sys_pod/etc/config.xml、/sys_pod/etc/carrier/46060/etc/config.xml，且设备默认卡opkey为46060，设置的followMode为configPolicy.FollowXMode.SIM_DEFAULT，最终返回/system/etc/config.xml, /sys_pod/etc/config.xml, /sys_pod/etc/carrier/46060/etc/config.xml。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名     | 类型                                     | 必填 | 说明                       |
| ---------- | ---------------------------------------- | ---- | -------------------------- |
| relPath    | string                                   | 是   | 配置文件名。                 |
| followMode | [FollowXMode](#followxmode11)            | 是   | 跟随模式。                   |
| callback   | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 异步回调，用于返回文件列表。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    configPolicy.getCfgFiles(relpath, configPolicy.FollowXMode.SIM_DEFAULT,
      (error: BusinessError, value: Array<string>) => {
      if (error == null) {
        console.log('value is ' + value);
      } else {
        console.log('error occurs ' + error);
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getCfgFiles<sup>11+</sup>

getCfgFiles(relPath: string, followMode: FollowXMode, extra: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;)

按优先级从低到高，根据提供的跟随模式获取指定文件名所有的文件列表，并使用callback形式返回。
例如，config.xml在设备中存在以下路径（优先级从低到高）：/system/etc/config.xml、/sys_pod/etc/config.xml、/sys_pod/etc/carrier/46060/etc/config.xml，且设备卡1的opkey为46060，设置的followMode为configPolicy.FollowXMode.USER_DEFINED，自定义跟随规则为"etc/carrier/${telephony.sim.opkey0}"，最终返回/system/etc/config.xml, /sys_pod/etc/config.xml, /sys_pod/etc/carrier/46060/etc/config.xml。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名     | 类型                                     | 必填 | 说明                                                   |
| ---------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| relPath    | string                                   | 是   | 配置文件名。                                             |
| followMode | [FollowXMode](#followxmode11)            | 是   | 跟随模式。                                               |
| extra      | string                                   | 是   | 用户自定义跟随规则，仅在followMode为USER_DEFINED时有效。 |
| callback   | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 异步回调，用于返回文件列表。                             |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    let extra: string = 'etc/carrier/${telephony.sim.opkey0}';
    configPolicy.getCfgFiles(relpath, configPolicy.FollowXMode.SIM_DEFAULT, extra,
      (error: BusinessError, value: Array<string>) => {
      if (error == null) {
        console.log('value is ' + value);
      } else {
        console.log('error occurs ' + error);
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getCfgFiles<sup>11+</sup>

getCfgFiles(relPath: string, followMode: FollowXMode, extra?: string): Promise&lt;Array&lt;string&gt;&gt;

根据提供的跟随模式按优先级从低到高，获取指定文件名所有的文件列表，并使用Promise形式返回。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名     | 类型                          | 必填 | 说明                                                   |
| ---------- | ----------------------------- | ---- | ------------------------------------------------------ |
| relPath    | string                        | 是   | 配置文件名。                                             |
| followMode | [FollowXMode](#followxmode11) | 是   | 跟随模式。                                               |
| extra      | string                        | 否   | 用户自定义跟随规则，仅在followMode为USER_DEFINED时必填。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.|

**返回值：**

| 类型                               | 说明     |
| ---------------------------------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | 返回文件列表。 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    let extra: string = 'etc/carrier/${telephony.sim.opkey0}';
    configPolicy.getCfgFiles(relpath, configPolicy.FollowXMode.SIM_DEFAULT, extra).then((value: Array<string>) => {
      console.log('value is ' + value);
    }).catch((error: BusinessError) => {
      console.log('getCfgFiles promise ' + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getCfgFilesSync<sup>11+</sup>

getCfgFilesSync(relPath: string, followMode?: FollowXMode, extra?: string): Array&lt;string&gt;

根据提供的跟随模式返回指定文件名所有的文件列表。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：**

| 参数名     | 类型                          | 必填 | 说明                                                   |
| ---------- | ----------------------------- | ---- | ------------------------------------------------------ |
| relPath    | string                        | 是   | 配置文件名。                                             |
| followMode | [FollowXMode](#followxmode11) | 否   | 跟随模式，不设置时，默认使用DEFAULT。                    |
| extra      | string                        | 否   | 用户自定义跟随规则，仅在followMode为USER_DEFINED时必填。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.|

**返回值：**

| 类型                | 说明     |
| ------------------- | -------- |
| Array&lt;string&gt; | 返回文件列表。 |


**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let relpath: string = 'etc/config.xml';
    let extra: string = 'etc/carrier/${telephony.sim.opkey0}';
    let result: Array<string> = configPolicy.getCfgFilesSync(relpath, configPolicy.FollowXMode.USER_DEFINED, extra);
    console.log('result is ' + result);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## getCfgDirListSync<sup>11+</sup>

getCfgDirListSync(): Array&lt;string&gt;

返回配置层级目录列表。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**返回值：**

| 类型                | 说明             |
| ------------------- | ---------------- |
| Array&lt;string&gt; | 返回配置层级目录列表。 |


**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let result: Array<string> = configPolicy.getCfgDirListSync();
    console.log('result is ' + result);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.log('error:' + code + ',' + message);
  }
  ```

## FollowXMode<sup>11+</sup>

**系统能力:** SystemCapability.Customization.ConfigPolicy

| 名称             | 值  | 说明                                                                                                                       |
| ---------------- | --- | -------------------------------------------------------------------------------------------------------------------------- |
| DEFAULT          | 0   | 默认模式，此模式下会根据各配置层级下的followx_file_list.cfg文件配置的跟随规则进行文件查找。                                |
| NO_RULE_FOLLOWED | 1   | 不跟随模式，此模式下不会使用任何跟随规则，即使存在followx_file_list.cfg文件。                                              |
| SIM_DEFAULT      | 10  | 跟随默认卡模式，此模式下会根据默认卡的opkey在各配置层级下的etc/carrier/${opkey}下查找文件。                                |
| SIM_1            | 11  | 跟随卡1模式，此模式下会根据卡1的opkey在各配置层级下的etc/carrier/${opkey}下查找文件。                                      |
| SIM_2            | 12  | 跟随卡2模式，此模式下会根据卡2的opkey在各配置层级下的etc/carrier/${opkey}下查找文件。                                      |
| USER_DEFINED     | 100 | 用户自定义模式，此模式会根据入参extra提供的跟随规则进行配置文件获取。此模式会忽略各配置层级下的followx_file_list.cfg文件。 |
