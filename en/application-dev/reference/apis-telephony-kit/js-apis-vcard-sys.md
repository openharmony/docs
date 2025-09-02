# @ohos.telephony.vcard (VCard) (System API)

VCard is a file format standard for electronic business cards. It contains information such as names, addresses, phone numbers, URLs, logos, and photos. The VCard module provides the VCard management functions, including importing VCard files to the contact database and exporting contact data to VCard files.

>**NOTE**
>
>The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.<br>
>The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { vcard } from '@kit.TelephonyKit';
```

## vcard.importVCard<sup>11+</sup>

importVCard\(context: Context, filePath: string, callback: AsyncCallback\<void\>\): void

Imports a VCard file (that is, **.vcf** file) to the contact database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_CONTACTS and ohos.permission.READ_CONTACTS

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| context   | Context                      | Yes  | Application context.|
| filePath   | string                      | Yes  | Address of the **.vcf** file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

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

Imports a VCard file (that is, **.vcf** file) to the contact database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_CONTACTS and ohos.permission.READ_CONTACTS

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| context   | Context                      | Yes  | Application context.|
| filePath   | string                      | Yes  | Address of the **.vcf** file.|
| accountId   | number                      | Yes  | Contact account ID.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

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

Imports a VCard file (that is, **.vcf** file) to the contact database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_CONTACTS and ohos.permission.READ_CONTACTS

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| context   | Context                      | Yes  | Application context.|
| filePath | string | Yes  | Address of the **.vcf** file.|
| accountId   | number | No  | Account ID. If this parameter is not passed, the default value **undefined** is used.|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

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

Exports contacts to a **.vcf** file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_CONTACTS and ohos.permission.READ_CONTACTS

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| context   | Context                      | Yes  | Application context.|
| predicates   | dataSharePredicates.DataSharePredicates | Yes  | Query statement.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result, which is the address of the **.vcf** file.                            |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

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

Exports contacts to a **.vcf** file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_CONTACTS and ohos.permission.READ_CONTACTS

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| context   | Context                      | Yes  | Application context.|
| predicates   | dataSharePredicates.DataSharePredicates | Yes  | Query statement.|
| options   | [VCardBuilderOptions](#vcardbuilderoptions11) | Yes  | VCard version and encoding type.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result, which is the address of the **.vcf** file.                            |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

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

Exports contacts to a **.vcf** file. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_CONTACTS and ohos.permission.READ_CONTACTS

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| context   | Context                      | Yes  | Application context.|
| predicates   | dataSharePredicates.DataSharePredicates | Yes  | Query statement.|
| options   | [VCardBuilderOptions](#vcardbuilderoptions11) | No  | VCard version and encoding type.|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<string\> | Promise used to return the result, which is the address of the **.vcf** file.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

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

Defines the VCard information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name        | Type  | Mandatory|    Description   |
| ------------ | ------ | ---- | ---------- |
| cardType     | [VCardType](#vcardtype11) |  No | VCard version. The default value is **VERSION_21**.    |
| charset       | string |  No | VCard encoding type. The default value is **UTF-8**.    |

## VCardType<sup>11+</sup>

Enumerates VCard versions.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name           | Value  | Description      |
| --------------- | ---- | ---------- |
| VERSION_21 | 0 | VCard 2.1.|
| VERSION_30 | 1 | VCard 3.0.|
| VERSION_40 | 2 | VCard 4.0.|
