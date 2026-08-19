# @ohos.dlpSetDlpFeature (设置数据防泄露入口)(系统接口)
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--Designer: @QRF-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

本模块提供数据防泄露（Data Loss Prevention，简称为DLP）特性开关的控制能力，包括开启和关闭DLP特性开关、返回特性开关设置结果等，帮助企业满足数据安全合规要求，实现机密文件的访问控制和加密保护。

**使用场景**： 
- 需要满足数据安全合规要求的场景。
- 对机密文件进行访问控制和加密保护。
> **说明：**
>
> - 本模块首批接口从API version 26.0.0 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 关键Class/Interface介绍

### 核心枚举类型

- **DlpFeatureStatus**：DLP特性开关状态枚举，用于控制DLP功能的启用状态。

### 核心接口类型

- **StatusInfoResult**：DLP特性开关状态设置的结果信息接口，包含DLP特性开关状态。

## 导入模块

```ts
import { dlpSetDlpFeature } from '@kit.DataProtectionKit';
```

## dlpSetDlpFeature.setDlpFeature

setDlpFeature(status: DlpFeatureStatus): Promise&lt;StatusInfoResult&gt;

设置DLP特性开关状态。使用Promise异步回调。调用成功后，DLP特性开关将设置为指定状态，系统将根据该状态启用或禁用DLP保护功能。

当特性开关处于开启状态时，右键单击支持加密的文件，右键菜单中会显示“加密保护”选项。可加密类型包括：.txt、.pdf、.xls、.xlsx、.ppt、.pptx、.doc和.docx。

企业策略开启或关闭数据防泄露功能时使用此接口。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| status | [DlpFeatureStatus](#dlpfeaturestatus) | 是 | DLP特性开关状态。ENABLED_FEATURE用于开启DLP特性，菜单中显示"加密保护"选项；NOT_ENABLED_FEATURE用于关闭DLP特性，菜单中不显示"加密保护"选项。超出此范围抛出错误码401。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[StatusInfoResult](#statusinforesult)&gt; | Promise对象。设置DLP特性开关状态，返回DLP特性开关状态设置的结果信息。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpSetDlpFeature } from '@kit.DataProtectionKit';

async function exampleFunction() {
  let statusInfoResult: dlpSetDlpFeature.StatusInfoResult =
    await dlpSetDlpFeature.setDlpFeature(dlpSetDlpFeature.DlpFeatureStatus.ENABLED_FEATURE);
  console.info('setDlpFeature result: ', JSON.stringify(statusInfoResult)); 
} // 设置DLP特性开关状态。

exampleFunction();
```

## StatusInfoResult

DLP特性开关状态设置的结果信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| isSuccess | boolean | 否 | 否 | DLP特性开关状态是否设置成功。true表示设置成功；false表示设置失败。 |

## DlpFeatureInfo

DLP特性开关的状态信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| dlpFeatureStatus | [DlpFeatureStatus](#dlpfeaturestatus) | 否 | 否 | DLP特性开关的状态，包含NOT_ENABLED_FEATURE和ENABLED_FEATURE。 |

## DlpFeatureStatus

DLP特性开关状态的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NOT_ENABLED_FEATURE | 0 | 表示关闭DLP特性开关。 |
| ENABLED_FEATURE | 1 | 表示开启DLP特性开关。 |
