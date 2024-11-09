# Skill

skill标签对象，三方应用可以通过[bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取skill信息,其中入参bundleFlags至少包含GET_BUNDLE_INFO_WITH_HAP_MODULE和GET_BUNDLE_INFO_WITH_ABILITY和GET_BUNDLE_INFO_WITH_SKILL。

> **说明：**
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## Skill

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core
| 名称     | 类型   | 可读 | 可写 | 说明       |
| -------- | ------ | ---- | ---- | ---------- |
| actions     | Array\<string> | 是   | 否   | Skill接收的Action集合。 |
| entities    | Array\<string> | 是   | 否   | Skill接收的Entity集合。   |
| uris | Array<\<SkillUri>> | 是   | 否   | Want匹配的Uri集合。 |
| domainVerify     | boolean | 是   | 否   | Skill接收的DomainVerify值, 仅在AbilityInfo中存在。 |

## SkillUri

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core
| 名称            | 类型   | 可读 | 可写 | 说明                                                        |
| --------------- | ------ | ---- | ---- | ----------------------------------------------------------- |
| scheme          | string | 是   | 否   | 标识 URI 协议名，常见的有http、https、file、ftp等。          |
| host            | string | 是   | 否   | 标识 URI 主机地址部分，仅当 scheme 存在时有意义。            |
| port            | number | 是   | 否   | 标识 URI 端口部分，仅当 scheme 和 host 同时存在时有意义。   |
| path            | string | 是   | 否   | 标识 URI 路径部分，仅当 scheme 和 host 同时存在时有意义。   |
| pathStartWith   | string | 是   | 否   | 标识 URI 路径部分，用于前缀匹配，仅当 scheme 和 host 同时存在时有意义。 |
| pathRegex       | string | 是   | 否   | 标识 URI 路径部分，用于正则匹配，仅当 scheme 和 host 同时存在时有意义。 |
| type            | string | 是   | 否   | 标识与Want相匹配的数据类型，使用MIME（Multipurpose Internet Mail Extensions）类型规范。 |
| utd             | string | 是   | 否   | 标识与 Want 相匹配的 URI 的标准化数据类型，适用于分享等场景。 |
| maxFileSupported | number   | 是   | 否   | 对于指定类型的文件，标识一次能接收或打开的最大数量。 |
| linkFeature     | string | 是   | 否   | 标识 URI 提供的功能类型，用于实现应用间跳转, 仅在AbilityInfo中存在。 |