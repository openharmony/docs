# @ohos.telephony.vcard (VCard模块)（系统接口）

VCard是电子名片的文件格式标准,它可包含的信息有：姓名、地址资讯、电话号码、URL，logo，相片等。VCard模块提供了VCard能力，包括将VCard文件导入联系人数据库和将联系人数据导出为VCard文件等。

>**说明：**
>
>本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。<br />
>本模块为系统接口。

## 导入模块

```ts
import { vcard } from '@kit.TelephonyKit';
```

## vcard.importVCard<sup>11+</sup>

importVCard\(context: Context, filePath: string, callback: AsyncCallback\<void\>\): void

将VCard文件导入联系人数据库。使用callback异步回调。

**需要权限**：ohos.permission.WRITE_CONTACTS 和 ohos.permission.READ_CONTACTS

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| context   | Context                      | 是   | 应用上下文。 |
| filePath   | string                      | 是   | vcf文件地址。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，返回导入成功或失败的状态码。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { vcard } from '@kit.TelephonyKit';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        let filePath: string = "/data/storage/vcf/contacts.vcf";
        vcard.importVCard(this.context, filePath, (err: BusinessError) => {
            console.log(`callback: err->${JSON.stringify(err)}`);
        });
    }
}

```

## vcard.importVCard<sup>11+</sup>

importVCard\(context: Context,filePath: string, accountId: number, callback: AsyncCallback\<void\>\): void

将VCard文件导入联系人数据库。使用callback异步回调。

**需要权限**：ohos.permission.WRITE_CONTACTS 和 ohos.permission.READ_CONTACTS

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| context   | Context                      | 是   | 应用上下文。 |
| filePath   | string                      | 是   | vcf文件地址。 |
| accountId   | number                      | 是   | 联系人账户ID。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，返回导入成功或失败的状态码。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { vcard } from '@kit.TelephonyKit';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        let filePath: string = "/data/storage/vcf/contacts.vcf";
        let accountId: number = 0;
        vcard.importVCard(this.context, filePath, accountId, (err: BusinessError) => {
            console.log(`callback: err->${JSON.stringify(err)}`);
        });
    }
}

```

## vcard.importVCard<sup>11+</sup>

importVCard\(context: Context, filePath: string, accountId?: number\): Promise\<void\>

将VCard文件导入联系人数据库。使用Promise异步回调。

**需要权限**：ohos.permission.WRITE_CONTACTS 和 ohos.permission.READ_CONTACTS

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| context   | Context                      | 是   | 应用上下文。|
| filePath | string | 是   | vcf文件地址 。|
| accountId   | number | 否   | 联系人账户ID。 |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<void\> | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { vcard } from '@kit.TelephonyKit';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        let filePath: string = "/data/storage/vcf/contacts.vcf";
        let accountId: number = 0;
        vcard.importVCard(this.context, filePath, accountId).then(() => {
            console.log(`importVCard success.`);
        }).catch((err: BusinessError) => {
            console.log(`importVCard failed, promise: err->${JSON.stringify(err)}`);
        });
    }
}
```

## vcard.exportVCard<sup>11+</sup>

exportVCard\(context: Context, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<string\>\): void

将联系人导出为vcf文件。使用callback异步回调。

**需要权限**：ohos.permission.WRITE_CONTACTS 和 ohos.permission.READ_CONTACTS

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| context   | Context                      | 是   | 应用上下文。 |
| predicates   | dataSharePredicates.DataSharePredicates | 是   | 查询语句。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数 callback表示生成的vcf文件地址。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { vcard } from '@kit.TelephonyKit';
import { dataSharePredicates } from '@kit.ArkData';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        let predicates = new dataSharePredicates.DataSharePredicates();
        predicates.equalTo("NAME", "Rose");

        vcard.exportVCard(this.context, predicates, (err: BusinessError, data: string) => {
            console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
        });
    }
}

```

## vcard.exportVCard<sup>11+</sup>

exportVCard\(context: Context, predicates: dataSharePredicates.DataSharePredicates, options: VCardBuilderOptions, callback: AsyncCallback\<string\>\): void

将联系人导出为vcf文件。使用callback异步回调。

**需要权限**：ohos.permission.WRITE_CONTACTS 和 ohos.permission.READ_CONTACTS

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| context   | Context                      | 是   | 应用上下文。 |
| predicates   | dataSharePredicates.DataSharePredicates | 是   | 查询语句。 |
| options   | [VCardBuilderOptions](#vcardbuilderoptions11) | 是   | VCard版本与编码类型。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数 callback表示生成的vcf文件地址。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { vcard } from '@kit.TelephonyKit';
import { dataSharePredicates } from '@kit.ArkData';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        let predicates = new dataSharePredicates.DataSharePredicates();
        predicates.equalTo("NAME", "Rose");
        let options: vcard.VCardBuilderOptions = {
            cardType: vcard.VCardType.VERSION_21,
            charset: "UTF-8"
        };
        vcard.exportVCard(this.context, predicates, options, (err: BusinessError, data: string) => {
            console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
        });
    }
}
```

## vcard.exportVCard<sup>11+</sup>

exportVCard\(context: Context, predicates: dataSharePredicates.DataSharePredicates, options?: VCardBuilderOptions\): Promise\<string\>

将联系人导出为vcf文件。使用Promise异步回调。

**需要权限**：ohos.permission.WRITE_CONTACTS 和 ohos.permission.READ_CONTACTS

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| context   | Context                      | 是   | 应用上下文。 |
| predicates   | dataSharePredicates.DataSharePredicates | 是   | 查询语句。 |
| options   | [VCardBuilderOptions](#vcardbuilderoptions11) | 否   | VCard版本与编码类型。 |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<string\> | 以Promise形式异步返回生成的vcf文件夹地址。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { vcard } from '@kit.TelephonyKit';
import { dataSharePredicates } from '@kit.ArkData';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        let predicates = new dataSharePredicates.DataSharePredicates();
        predicates.equalTo("NAME", "Rose");
        let options: vcard.VCardBuilderOptions = {
            cardType: vcard.VCardType.VERSION_21,
            charset: "UTF-8"
        };
        vcard.exportVCard(this.context, predicates, options).then(() => {
            console.log(`exportVCard success.`);
        }).catch((err: BusinessError) => {
            console.log(`exportVCard failed, promise: err->${JSON.stringify(err)}`);
        });
    }
}

```

## VCardBuilderOptions<sup>11+</sup>

VCard版本和编码信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称         | 类型   | 必填 |    说明    |
| ------------ | ------ | ---- | ---------- |
| cardType     | [VCardType](#vcardtype11) |  否  | VCard版本类型 (默认值为VERSION_21)。     |
| charset       | string |  否  | VCard编码类型（默认值为'UTF-8'）。     |

## VCardType<sup>11+</sup>

VCard版本类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称            | 值   | 说明       |
| --------------- | ---- | ---------- |
| VERSION_21 | 0 | VCard2.1版本。 |
| VERSION_30 | 1 | VCard3.0版本。 |
| VERSION_40 | 2 | VCard4.0版本。 |
