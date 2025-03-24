# @ohos.app.businessAbilityRouter (业务路由模块)(系统接口)

本模块用于查询当前设备上安装的各种应用程序的路由ability信息。通过业务路由提供标准的业务模板和业务管理能力，开发者可以按照指定的业务类别注册标准业务，丰富的业务形成一个庞大的超市。系统应用或者三方应用可以从业务路由中获取所需业务，并选择合适的业务使用。同时业务路由提供统一的跳转管控规则，控制应用与业务之间的合理跳转，杜绝前后台任意的跳转行为，避免三方应用通过跳转变相分发，解决安全弱、体验差的问题。

> **说明：**
>
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>本模块接口为系统接口。

## 导入模块

``` ts
import businessAbilityRouter from '@ohos.app.businessAbilityRouter';
```

## 权限列表

| 权限                                       | 权限等级     | 描述                 |
| ------------------------------------------ | ------------ | -------------------- |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | 可查询所有应用信息。 |

权限等级参考[权限APL等级说明](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)。

## BusinessType

此枚举值用于标识过滤条件类型。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称        | 值   | 说明                                 |
| ----------- | ---- | ------------------------------------ |
| SHARE       | 0    | 标识具有共享类型的ability信息。 |
| UNSPECIFIED | 255  | 标识未指定类型的ability信息。   |

## BusinessAbilityFilter

此过滤值用于过滤查询的ability类型。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称         | 类型         | 只读 | 必填 | 说明                                   |
| ------------ | ------------ | ---- | ---- | -------------------------------------- |
| businessType | [BusinessType](#businesstype) | 否   | 是   | 标识ability信息的类型。           |
| mimeType     | string       | 否   | 否   | 标识支持mime类型的ability信息。 |
| uri          | string       | 否   | 否   | 标识ability信息支持的uri。        |

## businessAbilityRouter.queryBusinessAbilityInfo

queryBusinessAbilityInfo(filter: BusinessAbilityFilter, callback: AsyncCallback\<Array\<BusinessAbilityInfo\>\>): void;

通过给定的过滤条件查询ability信息。使用callback异步回调。成功返回查询到的路由ability信息，失败返回对应错误信息。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| filter | [BusinessAbilityFilter](#businessabilityfilter) | 是    | 支持按业务类型过滤的对象。 |
| callback | AsyncCallback\<Array\<[BusinessAbilityInfo](js-apis-bundleManager-businessAbilityInfo-sys.md#businessabilityinfo)\>\> | 是 | 回调函数。返回查询到的ability信息，否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |

**示例：**

```ts
import businessAbilityRouter from '@ohos.app.businessAbilityRouter';
import { BusinessError } from '@ohos.base';

let filter: businessAbilityRouter.BusinessAbilityFilter = {businessType: businessAbilityRouter.BusinessType.SHARE};

try {
    businessAbilityRouter.queryBusinessAbilityInfo(filter, (error, data) => {
        if (error) {
            console.error('queryBusinessAbilityInfo failed ' + error.message);
            return;
        }
        console.info('queryBusinessAbilityInfo success');
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('queryBusinessAbilityInfo failed ' + message);
}
```

## businessAbilityRouter.queryBusinessAbilityInfo

queryBusinessAbilityInfo(filter: BusinessAbilityFilter): Promise\<Array\<BusinessAbilityInfo\>\>;

通过给定的过滤条件查询ability信息。使用Promise异步回调，成功返回查询到的路由ability信息，失败返回对应错误信息。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名       | 类型                              | 必填   | 说明                                    |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| filter | [BusinessAbilityFilter](#businessabilityfilter) | 是    | 包含要查询的ability信息的筛选类型。  |

**返回值：**

| 类型                                                         | 说明                                        |
| ------------------------------------------------------------ | ------------------------------------------- |
| Promise\<Array\<[BusinessAbilityInfo](js-apis-bundleManager-businessAbilityInfo-sys.md#businessabilityinfo)\>\> | Promise对象，返回符合过滤条件的ability信息。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |

**示例：**

```ts
import businessAbilityRouter from '@ohos.app.businessAbilityRouter';
import { BusinessError } from '@ohos.base';

let filter: businessAbilityRouter.BusinessAbilityFilter = {businessType: businessAbilityRouter.BusinessType.SHARE};

try {
    businessAbilityRouter.queryBusinessAbilityInfo(filter)
        .then(() => {
            console.info('queryBusinessAbilityInfo success');
        }).catch((error: BusinessError) => {
            console.error('queryBusinessAbilityInfo failed ' + error.message);
        });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('queryBusinessAbilityInfo failed ' + message);
}
```
