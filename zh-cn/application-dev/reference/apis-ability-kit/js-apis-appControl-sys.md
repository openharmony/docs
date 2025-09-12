# @ohos.bundle.appControl (appControl模块)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供应用拦截能力。对应用设置处置状态后，应用会被禁止运行；用户点击桌面图标时，会根据应用的处置状态，跳转到对应的页面。本模块支持对应用的处置状态进行设置、获取、删除。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

``` ts
import { appControl } from '@kit.AbilityKit';
```

## appControl.setDisposedStatus

setDisposedStatus(appId: string, disposedWant: Want): Promise\<void>

设置应用的处置状态。使用Promise异步回调。成功返回null，失败返回对应错误信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 需要设置处置状态的应用的appId。<br> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。               |
| disposedWant | Want  | 是 | 对应用的处置意图。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';
import { appControl } from '@kit.AbilityKit';

let appId = "com.example.myapplication_xxxxx";
let want:Want = {bundleName: 'com.example.myapplication'};

try {
    appControl.setDisposedStatus(appId, want)
        .then(() => {
            console.info('setDisposedStatus success');
        }).catch((error: BusinessError) => {
            let message = (error as BusinessError).message;
            console.error('setDisposedStatus failed ' + message);
        });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('setDisposedStatus failed ' + message);
}
```

## appControl.setDisposedStatus

setDisposedStatus(appId: string, disposedWant: Want, callback: AsyncCallback\<void>): void;

设置应用的处置状态。使用callback异步回调。成功返回null，失败返回对应错误信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型                              | 必填   | 说明                                    |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| appId  | string | 是    | 需要设置处置的应用的appId。<br> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。                      |
| disposedWant | Want  | 是 | 对应用的处置意图。 |
| callback    | AsyncCallback\<void> | 是    | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当设置处置状态成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let appId = "com.example.myapplication_xxxxx";
let want: Want = {bundleName: 'com.example.myapplication'};

try {
  appControl.setDisposedStatus(appId, want, (error: BusinessError, data) => {
    if (error) {
      let message = (error as BusinessError).message;
      console.error('setDisposedStatus failed ' + message);
      return;
    }
    console.info('setDisposedStatus success');
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('setDisposedStatus failed ' + message);
}
```

## appControl.setDisposedStatusSync<sup>10+</sup>

setDisposedStatusSync(appId: string, disposedWant: Want): void;

以同步方法设置应用的处置状态。成功返回null，失败抛出对应异常。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl


**参数：**

| 参数名       | 类型                              | 必填   | 说明                                    |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| appId  | string | 是    | 需要设置处置的应用的appId。<br> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。                      |
| disposedWant | Want  | 是 | 对应用的处置意图。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let appId: string = "com.example.myapplication_xxxxx";
let want: Want = {bundleName: 'com.example.myapplication'};

try {
  appControl.setDisposedStatusSync(appId, want);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('setDisposedStatusSync failed ' + message);
}
```

## appControl.getDisposedStatus

getDisposedStatus(appId: string): Promise\<Want>;

获取指定应用已设置的处置状态。使用Promise异步回调，成功返回应用的处置状态，失败返回对应错误信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要查询的应用的appId。<br> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。  |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<Want> | Promise对象，返回应用的处置状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appId = "com.example.myapplication_xxxxx";

try {
  appControl.getDisposedStatus(appId)
    .then((data) => {
      console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
    }).catch((error: BusinessError) => {
    let message = (error as BusinessError).message;
    console.error('getDisposedStatus failed ' + message);
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getDisposedStatus failed ' + message);
}
```

## appControl.getDisposedStatus

getDisposedStatus(appId: string, callback: AsyncCallback\<Want>): void;

获取指定应用的处置状态。使用callback异步回调，成功返回应用的处置状态，失败返回对应错误信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                  |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要查询的应用的appId。<br> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。  |
| callback    | AsyncCallback\<Want> | 是    | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)。当获取应用的处置状态成功时，err为null，data为获取到的处置状态；否则为错误对象。                    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appId = "com.example.myapplication_xxxxx";

try {
  appControl.getDisposedStatus(appId, (error, data) => {
    if (error) {
      let message = (error as BusinessError).message;
      console.error('getDisposedStatus failed ' + message);
      return;
    }
    console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getDisposedStatus failed ' + message);
}
```

## appControl.getDisposedStatusSync<sup>10+</sup>

getDisposedStatusSync(appId: string): Want;

以同步方法获取指定应用已设置的处置状态。成功返回应用的处置状态，失败抛出对应异常。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要查询的应用的appId。<br> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。  |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Want | 返回应用的处置状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let appId: string = "com.example.myapplication_xxxxx";
let want: Want;

try {
    want = appControl.getDisposedStatusSync(appId);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getDisposedStatusSync failed ' + message);
}
```

## appControl.deleteDisposedStatus

deleteDisposedStatus(appId: string): Promise\<void>

删除应用的处置状态。使用promise异步回调，成功返回null，失败返回对应错误信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要删除拦截规则的应用的appId或appIdentifier。使用appId设置的拦截规则只能通过appId删除，使用appIdentifier设置的同理。<br/>**说明：**<br/> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。<br> [appIdentifier](js-apis-bundleManager-bundleInfo.md#signatureinfo)也是应用的唯一标识，是AppGallery Connect创建应用时分配的APP ID，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。获取方法参见[获取应用的appIdentifier](#获取应用的appid和appidentifier)。  |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象，无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appId = "com.example.myapplication_xxxxx";

try {
  appControl.deleteDisposedStatus(appId)
    .then(() => {
      console.info('deleteDisposedStatus success');
    }).catch((error: BusinessError) => {
      let message = (error as BusinessError).message;
      console.error('deleteDisposedStatus failed ' + message);
  });
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('deleteDisposedStatus failed ' + message);
}
```

## appControl.deleteDisposedStatus

deleteDisposedStatus(appId: string, callback: AsyncCallback\<void>) : void

删除应用的处置状态。使用callback异步回调，成功返回null，失败返回对应错误信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要删除拦截规则的应用的appId或appIdentifier。使用appId设置的拦截规则只能通过appId删除，使用appIdentifier设置的同理。<br/>**说明：**<br/> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。<br> [appIdentifier](js-apis-bundleManager-bundleInfo.md#signatureinfo)也是应用的唯一标识，是AppGallery Connect创建应用时分配的APP ID，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。获取方法参见[获取应用的appIdentifier](#获取应用的appid和appidentifier)。  |
| callback    | AsyncCallback\<void> | 是    | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当设置处置状态成功时，err返回null。否则回调函数返回具体错误对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appId = "com.example.myapplication_xxxxx";
try {
  appControl.deleteDisposedStatus(appId, (error: BusinessError, data) => {
    if (error) {
      console.error('deleteDisposedStatus failed ' + error.message);
      return;
    }
    console.info('deleteDisposedStatus success');
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('deleteDisposedStatus failed ' + message);
}
```

## appControl.deleteDisposedStatusSync<sup>10+</sup>

deleteDisposedStatusSync(appId: string, appIndex:? number) : void

以同步方法删除指定应用或分身应用的处置状态。成功返回null，失败抛出对应异常。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要删除拦截规则的应用的appId或appIdentifier。使用appId设置的拦截规则只能通过appId删除，使用appIdentifier设置的同理。<br/>**说明：**<br/> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。<br> [appIdentifier](js-apis-bundleManager-bundleInfo.md#signatureinfo)也是应用的唯一标识，是AppGallery Connect创建应用时分配的APP ID，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。获取方法参见[获取应用的appIdentifier](#获取应用的appid和appidentifier)。  |
| appIndex<sup>12+</sup>   | number  | 否   | 表示分身应用的索引，默认值为0。<br> appIndex为0时，表示删除主应用的处置状态。appIndex大于0时，表示删除指定分身应用的处置状态。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |
| 17700061 | AppIndex is not in the valid range. |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appId: string = "com.example.myapplication_xxxxx";

try {
    appControl.deleteDisposedStatusSync(appId, 1);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('deleteDisposedStatusSync failed ' + message);
}
```

## 获取应用的appId和appIdentifier

appId是应用的唯一标识，由应用Bundle名称和签名信息决定，可以通过[getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo14)接口获取。<br>
[appIdentifier](js-apis-bundleManager-bundleInfo.md#signatureinfo)也是应用的唯一标识，是AppGallery Connect创建应用时分配的APP ID，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'com.example.myapplication';
let appId: string;
let appIdentifier: string;
try {
  bundleManager.getBundleInfo(bundleName, bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO)
    .then((data) => {
      appId = data.signatureInfo.appId;
      appIdentifier = data.signatureInfo.appIdentifier;
      console.info("appId is " + appId);
      console.info("appIdentifier is " + appIdentifier);
    }).catch((error: BusinessError) => {
      let message = (error as BusinessError).message;
      console.error("getBundleInfo failed " + message);
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error("getBundleInfo failed " + message);
}
```

## appControl.getDisposedRule<sup>11+</sup>

getDisposedRule(appId: string, appIndex:? number): DisposedRule

获取指定应用或分身应用已设置的拦截规则。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要获取拦截规则的应用的appId或appIdentifier。使用appId设置的拦截规则只能通过appId获取，使用appIdentifier设置的同理。<br/>**说明：**<br/> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。<br> [appIdentifier](js-apis-bundleManager-bundleInfo.md#signatureinfo)也是应用的唯一标识，是AppGallery Connect创建应用时分配的APP ID，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。获取方法参见[获取应用的appIdentifier](#获取应用的appid和appidentifier)。  |
| appIndex<sup>12+</sup>   | number  | 否   | 表示分身应用的索引，默认值为0。<br> appIndex为0时，表示获取主应用的拦截规则。appIndex大于0时，表示获取指定分身应用的拦截规则。    |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| [DisposedRule](#disposedrule11) | 对应用的拦截规则。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |
| 17700061 | AppIndex is not in the valid range. |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let appId = "com.example.myapplication_xxxxx";

try {
  let data = appControl.getDisposedRule(appId, 1);
  console.info('getDisposedRule successfully. Data: ' + JSON.stringify(data));
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('getDisposedRule failed ' + message);
}
```

## appControl.setDisposedRule<sup>11+</sup>

setDisposedRule(appId: string, rule: DisposedRule, appIndex:? number): void

设置指定应用或分身应用的拦截规则。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要被设置拦截规则应用的appId或appIdentifier。使用appId设置的拦截规则会覆盖使用appIdentifier设置的拦截规则，反之同理。<br/>**说明：**<br/> appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。<br> [appIdentifier](js-apis-bundleManager-bundleInfo.md#signatureinfo)也是应用的唯一标识，是AppGallery Connect创建应用时分配的APP ID，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。获取方法参见[获取应用的appIdentifier](#获取应用的appid和appidentifier)。  |
| rule | [DisposedRule](#disposedrule11) | 是 | 指示对应用的拦截规则。 |
| appIndex<sup>12+</sup>   | number  | 否   | 表示分身应用的索引，默认值为0。<br> appIndex为0时，表示设置主应用的拦截规则。appIndex大于0时，表示设置指定分身应用的拦截规则。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |
| 17700061 | AppIndex is not in the valid range. |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';
import { bundleManager } from '@kit.AbilityKit';

let appId = "com.example.myapplication_xxxxx";
let want: Want = {
  bundleName: "com.example.myapplication",
  moduleName: "entry",
  abilityName: "EntryAbility"
};
let elementName: bundleManager.ElementName = {
  bundleName: "com.example.myapplication",
  moduleName: "entry",
  abilityName: "EntryAbility"
};
let rule: appControl.DisposedRule = {
  want: want,
  componentType: appControl.ComponentType.UI_ABILITY,
  disposedType: appControl.DisposedType.BLOCK_APPLICATION,
  controlType: appControl.ControlType.ALLOWED_LIST,
  elementList: [
    elementName
  ],
  priority: 100
};

try {
  appControl.setDisposedRule(appId, rule, 1);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('setDisposedRule failed ' + message);
}
```

## appControl.setDisposedRules<sup>20+</sup>

setDisposedRules(disposedRuleConfigurations: Array\<DisposedRuleConfiguration\>): void

批量设置指定应用或分身应用的拦截规则。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名                     | 类型                                                         | 必填 | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| disposedRuleConfigurations | Array<[DisposedRuleConfiguration](#disposedruleconfiguration20)> | 是   | 表示批量设置拦截规则的配置，包括待拦截应用的appId、分身应用索引及拦截规则。每次设置拦截规则的数组的最大数量为1000。<br/>**说明：**<br/>1.如果数组中存在appId和appIndex相同的DisposedRuleConfiguration时，后面的DisposedRuleConfiguration会覆盖前面的。<br/>2.如果应用已设置过拦截规则，重新为该应用设置拦截规则，会覆盖之前的。appId和appIndex一致则表示同一应用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Permission denied. A non-system application is not allowed to call a system API. |
| 801      | Capability not supported.                                    |
| 17700005 | The specified app ID is invalid.                             |
| 17700061 | AppIndex is not in the valid range.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { appControl, Want, bundleManager } from '@kit.AbilityKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  moduleName: 'entry',
  abilityName: 'EntryAbility'
};
let elementName: bundleManager.ElementName = {
  bundleName: 'com.example.myapplication',
  moduleName: 'entry',
  abilityName: 'EntryAbility'
};
let rule: appControl.DisposedRule = {
  want: want,
  componentType: appControl.ComponentType.UI_ABILITY,
  disposedType: appControl.DisposedType.BLOCK_APPLICATION,
  controlType: appControl.ControlType.ALLOWED_LIST,
  elementList: [
    elementName
  ],
  priority: 100
};

let disposedRuleConfiguration: appControl.DisposedRuleConfiguration = {
  appId: 'com.example.myapplication_BInGTMPMdc6v55s/UFIJHL5NLREXjOuxm/DsyMhlFmLAZC9/Gk+ruqS9OZr/dvFuaIaQQL1pKolvzK/zYNHvJ/I=',
  appIndex: 0,
  disposedRule: rule,
};

let disposedRuleConfigurations: Array<appControl.DisposedRuleConfiguration> = [];
disposedRuleConfigurations.push(disposedRuleConfiguration);
@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('setDisposedRules', { type: ButtonType.Normal })
          .onClick(() => {
            try {
              appControl.setDisposedRules(disposedRuleConfigurations);
              console.info('setDisposedRules success');
            } catch (error) {
              let err: BusinessError = error as BusinessError;
              console.error(`setDisposedRules failed, errCode:${err.code}, message:${err.message}`);
            }
          });
      }
    }
  }
}
```

## appControl.setUninstallDisposedRule<sup>15+</sup>

setUninstallDisposedRule(appIdentifier: string, rule: UninstallDisposedRule, appIndex:? number): void

设置指定应用或分身应用的卸载处置规则。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appIdentifier  | string | 是    | 要设置卸载处置规则的应用的appIdentifier。<br> 如果应用没有appIdentifier可使用appId代替。appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid和appidentifier)。  |
| rule | [UninstallDisposedRule](#uninstalldisposedrule15) | 是 | 表示要设置的卸载处置规则。 |
| appIndex   | number  | 否   | 表示分身应用的索引，默认值为0。<br> appIndex为0时，表示设置主应用的卸载处置规则。appIndex大于0时，表示设置指定分身应用的卸载处置规则。        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied. A non-system application is not allowed to call a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | Capability not supported. |
| 17700061 | AppIndex is not in the valid range. |
| 17700074 | The specified appIdentifier is invalid. |
| 17700075 | The specified bundleName of want is not the same with caller. |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let appIdentifier = "com.example.myapplication_xxxxx";
let want: Want = {
  bundleName: "com.example.myapplication",
  moduleName: "entry",
  abilityName: "EntryAbility"
};
let rule: appControl.UninstallDisposedRule = {
  want: want,
  uninstallComponentType: appControl.UninstallComponentType.EXTENSION,
  priority: 100
};

try {
  appControl.setUninstallDisposedRule(appIdentifier, rule, 1);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('setUninstallDisposedRule failed ' + message);
}
```

## appControl.getUninstallDisposedRule<sup>15+</sup>

getUninstallDisposedRule(appIdentifier: string, appIndex:? number): UninstallDisposedRule

获取指定应用或分身应用已设置的卸载处置规则。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS 或 ohos.permission.GET_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appIdentifier  | string | 是    | 要获取卸载处置规则的应用的appIdentifier。<br> 如果应用没有appIdentifier可使用appId代替。appId是应用的唯一标识，由应用Bundle名称和签名信息决定，设置方法参见[获取应用的appId](#获取应用的appid和appidentifier)。  |
| appIndex   | number  | 否   | 表示分身应用的索引，默认值为0。<br> appIndex为0时，表示获取主应用的卸载处置规则。appIndex大于0时，表示获取指定分身应用的卸载处置规则。              |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| [UninstallDisposedRule](#uninstalldisposedrule15) | 表示应用的卸载处置规则。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied. A non-system application is not allowed to call a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | Capability not supported. |
| 17700061 | AppIndex is not in the valid range. |
| 17700074 | The specified appIdentifier is invalid. |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appIdentifier = "com.example.myapplication_xxxxx";

try {
  let data = appControl.getUninstallDisposedRule(appIdentifier, 1);
  console.info('getUninstallDisposedRule successfully. Data: ' + JSON.stringify(data));
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('getUninstallDisposedRule failed ' + message);
}
```

## appControl.deleteUninstallDisposedRule<sup>15+</sup>

deleteUninstallDisposedRule(appIdentifier: string, appIndex:? number): void

删除指定应用或分身应用的卸载处置规则。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appIdentifier  | string | 是    | 要删除卸载处置规则的应用的appIdentifier。<br> 如果应用没有appIdentifier可使用appId代替。appId是应用的唯一标识，由应用Bundle名称和签名信息决定，删除方法参见[获取应用的appId](#获取应用的appid和appidentifier)。  |
| appIndex   | number  | 否   | 表示分身应用的索引，默认值为0。<br> appIndex为0时，表示删除主应用的卸载处置规则。appIndex大于0时，表示删除指定分身应用的卸载处置规则。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied. A non-system application is not allowed to call a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | Capability not supported. |
| 17700061 | AppIndex is not in the valid range. |
| 17700074 | The specified appIdentifier is invalid. |

**示例：**

```ts
import { appControl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appIdentifier = "com.example.myapplication_xxxxx";

try {
  appControl.deleteUninstallDisposedRule(appIdentifier, 1);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('deleteUninstallDisposedRule failed ' + message);
}
```

## DisposedRule<sup>11+</sup>

标识拦截规则。

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl。

 **系统接口：** 此接口为系统接口。

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| want | [Want](js-apis-app-ability-want.md)     | 否   | 否   | 指定应用被拦截时，跳转到的页面。 |
| componentType | [ComponentType](#componenttype11)  | 否   | 否   | 拦截时将提升的能力的类型。 |
| disposedType | [DisposedType](#disposedrule11) | 否   | 否 | 对应用的拦截规则。 |
| controlType | [ControlType](#controltype11) | 否   | 否 | 拦截指定应用程序的不同策略。 |
| elementList | Array\<[ElementName](js-apis-bundleManager-elementName.md)> | 否   | 否 | 拦截指定应用程序能力的列表。 |
| priority | number | 否   | 否 | 拦截规则的优先级，用于规则列表查询结果排序。取值为整数，数值越小，排序越靠前。 |

### ComponentType<sup>11+</sup>

标识功能组件类型。

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl。

 **系统接口：** 此接口为系统接口。

| 名称    | 值   | 说明                 |
| ------- | ---- | -------------------- |
| UI_ABILITY | 1    | UI基础功能类型。 |
| UI_EXTENSION | 2    | UI扩展能力类型。 |

### DisposedType<sup>11+</sup>

标识拦截应用程序的方式，例如禁用应用的全部能力、禁用应用的指定能力、或者不禁用。

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl。

 **系统接口：** 此接口为系统接口。

| 名称    | 值   | 说明                 |
| ------- | ---- | -------------------- |
| BLOCK_APPLICATION | 1    | 应用所有能力都将被禁用。 |
| BLOCK_ABILITY | 2    | 应用指定的能力才会被禁用。 |
| NON_BLOCK | 3 | 应用所有能力不会被禁用。 |

### ControlType<sup>11+</sup>

标识拦截指定应用程序的不同策略。

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl。

 **系统接口：** 此接口为系统接口。

| 名称    | 值   | 说明                 |
| ------- | ---- | -------------------- |
| ALLOWED_LIST | 1    | 允许运行指定功能的列表。 |
| DISALLOWED_LIST | 2    | 不允许运行指定功能的列表。 |

## UninstallDisposedRule<sup>15+</sup>

标识卸载处置规则。

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl。

 **系统接口：** 此接口为系统接口。

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| want | [Want](js-apis-app-ability-want.md)     | 否   | 否   | 指定应用被拦截时，跳转到的页面。 |
| UninstallComponentType | [UninstallComponentType](#uninstallcomponenttype15)  | 否   | 否   | 拦截时将拉起能力的类型。 |
| priority | number | 否 | 否 | 拦截规则的优先级，用于规则列表查询结果排序。取值为整数，数值越小，排序越靠前。 |

### UninstallComponentType<sup>15+</sup>

标识卸载时功能组件类型。

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl。

 **系统接口：** 此接口为系统接口。

| 名称    | 值   | 说明                 |
| ------- | ---- | -------------------- |
| EXTENSION | 1    | 服务扩展能力类型。 |

## DisposedRuleConfiguration<sup>20+</sup>

标识批量设置拦截规则的配置。

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

 **系统接口：** 此接口为系统接口。

| 名称         | 类型                            | 只读 | 可选 | 说明                                                         |
| ------------ | ------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| appId        | string                          | 否   | 否   | 要被设置拦截规则应用的appId或appIdentifier。appId和appIdentifier可以标识同一个应用，因此针对同一应用如果用appIdentifier设置拦截规则，可以覆盖之前采用appId设置的，反之同理。<br/>**说明：**<br/>appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见[获取应用的appId](https://gitcode.com/openharmony/docs/blob/0a11b273485103fe78df3910fa607c2359ff5b2c/zh-cn/application-dev/reference/apis-ability-kit/js-apis-appControl-sys.md#获取应用的appid和appidentifier)。<br/>appIdentifier也是应用的唯一标识，是AppGallery Connect创建应用时分配的[APP ID](https://developer.huawei.com/consumer/cn/doc/app/agc-help-createharmonyapp-0000001945392297)，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。获取方法参见[获取应用的appIdentifier](https://gitcode.com/openharmony/docs/blob/0a11b273485103fe78df3910fa607c2359ff5b2c/zh-cn/application-dev/reference/apis-ability-kit/js-apis-appControl-sys.md#获取应用的appid和appidentifier)。 |
| appIndex     | number                          | 否   | 否   | 表示分身应用的索引，默认值为0。<br/> appIndex为0时，表示设置主应用的拦截规则。appIndex大于0时，表示设置指定分身应用的拦截规则。 |
| disposedRule | [DisposedRule](#disposedrule11) | 否   | 否   | 表示对应用的拦截规则，包括拦截时将拉起能力的类型等。         |