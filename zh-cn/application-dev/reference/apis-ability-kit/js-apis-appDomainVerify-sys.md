# @ohos.bundle.appDomainVerify (应用域名校验)(系统接口)

本模块提供应用域名校验能力，支持查询应用与域名之间的映射关系。

> **说明：**
>
> 本模块首批接口从API version 13开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { appDomainVerify } from '@kit.AbilityKit';
```

## 权限列表

| 权限                                    | 权限等级    | 描述             |
| --------------------------------------- | ----------- | ---------------- |
| ohos.permission.GET_APP_DOMAIN_BUNDLE_INFO | system_basic | 允许应用访问应用和域名的映射关系的权限。 |

权限等级参考[权限APL等级说明](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)。

## appDomainVerify.queryAssociatedDomains

queryAssociatedDomains(bundleName: string): string[]

通过应用的包名查询其关联的网站域名列表。

**需要权限：** ohos.permission.GET_APP_DOMAIN_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.AppDomainVerify

**系统接口：**  此接口为系统接口。

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | 是    | 需要查询的应用包名。       |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| string[] | 返回包名关联的网站域名列表，若无关联的域名，则返回空数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle.appDomainVerify错误码](errorcode-appDomainVerify.md.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error.|
| 29900001 | System internal error. |

**示例：**

```ts
import { appDomainVerify } from '@kit.AbilityKit';

// 获取包名为"com.example.app1"的应用所关联的域名列表
let bundleName = "com.example.app1";
let domains = appDomainVerify.queryAssociatedDomains(bundleName);
domains.forEach(domain => {
  console.log(`app:${bundleName} associate with domain:${domain}`);
});
```

## appDomainVerify.queryAssociatedBundleNames

queryAssociatedBundleNames(domain: string): string[]

通过网站域名查询其关联的应用包名列表。

**需要权限：** ohos.permission.GET_APP_DOMAIN_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.AppDomainVerify

**系统接口：**  此接口为系统接口。

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| domain  | string | 是    | 需要查询的网站域名。       |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| string[] | 返回网站域名关联的应用包名列表，若无关联的应用，则返回空数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle.appDomainVerify错误码](errorcode-appDomainVerify.md.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error.|
| 29900001 | System internal error. |

**示例：**

```ts
import { appDomainVerify } from '@kit.AbilityKit';

// 获取域名"example.com"应用所关联的包名列表
let domain = "example.com";
let bundleNames = appDomainVerify.queryAssociatedBundleNames(domain);
bundleNames.forEach(bundleName => {
  console.log(`domain:${domain} associate with app:${bundleName}`);
});
```
