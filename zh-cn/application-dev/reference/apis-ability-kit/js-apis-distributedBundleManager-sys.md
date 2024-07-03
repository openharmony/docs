# @ohos.bundle.distributedBundleManager (distributedBundleManager模块)(系统接口)

本模块提供分布式应用的管理能力。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

``` ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
```

## 系统能力

SystemCapability.BundleManager.DistributedBundleFramework

## 权限列表

| 权限                                       | 权限等级     | 说明               |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | 允许查询应用的基本信息和其他敏感信息。 |

权限等级参考[权限APL等级说明](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)。

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback\<RemoteAbilityInfo>): void

以异步方法获取由elementName指定的远程设备上的应用的AbilityInfo信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.DistributedBundleFramework

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| elementName | [ElementName](js-apis-bundleManager-elementName.md)          | 是   | ElementName信息。                                            |
| callback    | AsyncCallback<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)> | 是   | 回调函数，调用成功返回err为null，data为RemoteAbilityInfo对象；调用失败err为错误对象, data为undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                   |
|----------|--------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**示例：**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'EntryAbility'
        }, (err: BusinessError, data: distributedBundle.RemoteAbilityInfo) => {
            if (err) {
                console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
            } else {
                console.info('Operation succeed:' + JSON.stringify(data));
            }
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName): Promise\<RemoteAbilityInfo>

以异步方法获取由elementName指定的远程设备上的应用的AbilityInfo信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.DistributedBundleFramework

**参数：**

| 参数名       | 类型                                         | 必填 | 说明                    |
| ----------- | -------------------------------------------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | 是   | ElementName信息。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)> | Promise对象，调用成功返回RemoteAbilityInfo对象；调用失败返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                   |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**示例：**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'EntryAbility'
        }).then((data: distributedBundle.RemoteAbilityInfo) => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
            console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void

以异步方法获取由elementName指定的远程设备上的应用的AbilityInfo数组信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.DistributedBundleFramework

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)>   | 是   | ElementName信息,最大数组长度为10。                             |
| callback     | AsyncCallback\<Array\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)>> | 是   | 回调函数，调用成功返回err为null，data为RemoteAbilityInfo数组对象；调用失败err为错误对象, data为undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                   |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**示例：**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application1',
                abilityName: 'EntryAbility1'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'EntryAbility'
            }
        ], (err: BusinessError, data: distributedBundle.RemoteAbilityInfo[]) => {
          if (err) {
            console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
          } else {
            console.info('Operation succeed:' + JSON.stringify(data));
          }
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>): Promise\<Array\<RemoteAbilityInfo>>

以异步方法获取由elementName指定的远程设备上的应用的AbilityInfo数组信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.DistributedBundleFramework

**参数：**

| 参数名        | 类型                                                | 必填 | 说明                    |
| ------------ | --------------------------------------------------- | ---- | ----------------------- |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)> | 是   | ElementName信息，最大数组长度为10。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<Array<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)>> | Promise对象，调用成功返回RemoteAbilityInfo对象；调用失败返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                   |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**示例：**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application',
                abilityName: 'EntryAbility'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'EntryAbility'
            }
        ]).then((data: distributedBundle.RemoteAbilityInfo[]) => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
            console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName, locale: string, callback: AsyncCallback\<RemoteAbilityInfo>): void

以异步方法获取由elementName和locale指定的远程设备上的应用的AbilityInfo信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.DistributedBundleFramework

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                               |
| ----------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md)                 | 是   | ElementName信息。                            |
| locale  | string |是 | 语言地区。 |
| callback    | AsyncCallback<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)> | 是   | 回调函数，调用成功返回err为null，data为RemoteAbilityInfo对象；调用失败err为错误对象, data为undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                   |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**示例：**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'EntryAbility'
        }, 'zh-Hans-CN', (err: BusinessError, data: distributedBundle.RemoteAbilityInfo) => {
          if (err) {
            console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
          } else {
            console.info('Operation succeed:' + JSON.stringify(data));
          }
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName, locale: string): Promise\<RemoteAbilityInfo>

以异步方法获取由elementName和locale指定的远程设备上的应用的AbilityInfo信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.DistributedBundleFramework

**参数：**

| 参数名       | 类型                                         | 必填 | 说明                    |
| ----------- | -------------------------------------------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | 是   | ElementName信息。 |
| locale  | string |是 | 语言地区。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)> | Promise对象，调用成功返回RemoteAbilityInfo对象；调用失败返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                   |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**示例：**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'EntryAbility'
        }, 'zh-Hans-CN').then((data: distributedBundle.RemoteAbilityInfo) => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
            console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>, locale: string, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void

以异步方法获取由elementName和locale指定的远程设备上的应用的AbilityInfo数组信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.DistributedBundleFramework

**参数：**

| 参数名        | 类型                                                         | 必填 | 说明                                               |
| ------------ | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)>          | 是   | ElementName信息,最大数组长度为10。                   |
| locale  | string |是 | 语言地区。 |
| callback     | AsyncCallback\<Array\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)>> | 是   | 回调函数，调用成功返回err为null，data为RemoteAbilityInfo数组对象；调用失败err为错误对象, data为undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID        |    错误信息                   |
|---------------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**示例：**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application1',
                abilityName: 'EntryAbility1'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'EntryAbility'
            }
        ], 'zh-Hans-CN', (err: BusinessError, data: distributedBundle.RemoteAbilityInfo[]) => {
          if (err) {
           console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
          } else {
            console.info('Operation succeed:' + JSON.stringify(data));
          }
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>, locale: string): Promise\<Array\<RemoteAbilityInfo>>

以异步方法获取由elementName和locale指定的远程设备上的应用的AbilityInfo数组信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.DistributedBundleFramework

**参数：**

| 参数名        | 类型                                                | 必填 | 说明                    |
| ------------ | --------------------------------------------------- | ---- | ----------------------- |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)> | 是   | ElementName信息,最大数组长度为10。 |
| locale  | string |是 | 语言地区。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<Array<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)>> | Promise对象，调用成功返回RemoteAbilityInfo对象；调用失败返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                   |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**示例：**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application',
                abilityName: 'EntryAbility'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'EntryAbility'
            }
        ], 'zh-Hans-CN').then((data: distributedBundle.RemoteAbilityInfo[]) => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
            console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```
