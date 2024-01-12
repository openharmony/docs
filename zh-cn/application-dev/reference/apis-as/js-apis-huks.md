# @ohos.security.huks (通用密钥库系统)

向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。
HUKS所管理的密钥可以由应用导入或者由应用调用HUKS接口生成。

> **说明**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import huks from '@ohos.security.huks'
```

## HuksParam

调用接口使用的options中的properties数组中的param。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称 | 类型                                | 必填 | 说明         |
| ------ | ----------------------------------- | ---- | ------------ |
| tag    | [HuksTag](#hukstag)                 | 是   | 标签。       |
| value  | boolean\|number\|bigint\|Uint8Array | 是   | 标签对应值。 |

## HuksOptions

调用接口使用的options。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称     | 类型              | 必填 | 说明                     |
| ---------- | ----------------- | ---- | ------------------------ |
| properties | Array\<[HuksParam](#huksparam)> | 否   | 属性，用于存HuksParam的数组。 |
| inData     | Uint8Array        | 否   | 输入数据。               |

## HuksSessionHandle<sup>9+</sup>

huks Handle结构体。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称    | 类型       | 必填 | 说明                                                 |
| --------- | ---------- | ---- | ---------------------------------------------------- |
| handle    | number     | 是   | 表示handle值。                                       |
| challenge | Uint8Array | 否   | 表示[initSession](#huksinitsession9)操作之后获取到的challenge信息。 |

## HuksReturnResult<sup>9+</sup>

调用接口返回的result。

**系统能力**：SystemCapability.Security.Huks.Core



| 名称     | 类型                            | 必填 | 说明             |
| ---------- | ------------------------------- | ---- | ---------------- |
| outData    | Uint8Array                      | 否   | 表示输出数据。   |
| properties | Array\<[HuksParam](#huksparam)> | 否   | 表示属性信息。   |
| certChains | Array\<string>                  | 否   | 表示证书链数据。 |


## huks.generateKeyItem<sup>9+</sup>

generateKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void

生成密钥，使用Callback回调异步返回结果。

**系统能力**：SystemCapability.Security.Huks.Core

**参数：** 

| 参数名   | 类型                        | 必填 | 说明                                          |
| -------- | --------------------------- | ---- | --------------------------------------------- |
| keyAlias | string                      | 是   | 别名。                                        |
| options  | [HuksOptions](#huksoptions) | 是   | 用于存放生成key所需TAG。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |
| callback | AsyncCallback\<void>        | 是   | 回调函数。未捕获error时代表用户指定别名的密钥生成成功，基于密钥不出TEE原则，此接口不会返回密钥材料内容，若捕获error，则为生成阶段出现异常。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**示例：**

```ts
import huks from '@ohos.security.huks';
/* 以生成AES128密钥为例 */
class HuksProperties {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest
}
let keyAlias: string = 'keyAlias';
let properties: HuksProperties[] = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  },
  {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_GCM
  }
];
let options: huks.HuksOptions = {
    properties: properties
};
try {
    huks.generateKeyItem(keyAlias, options, (error, data) => {
        if (error) {
            console.error(`callback: generateKeyItem failed`);
        } else {
            console.info(`callback: generateKeyItem key success`);
        }
    });
} catch (error) {
    console.error(`callback: generateKeyItem input arg invalid`);
}
```

## huks.generateKeyItem<sup>9+</sup>

generateKeyItem(keyAlias: string, options: HuksOptions) : Promise\<void>

生成密钥，使用Promise方式异步返回结果。基于密钥不出TEE原则，通过promise不会返回密钥材料内容，只用于表示此次调用是否成功。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：** 

| 参数名   | 类型                        | 必填 | 说明                     |
| -------- | --------------------------- | ---- | ------------------------ |
| keyAlias | string                      | 是   | 密钥别名。               |
| options  | [HuksOptions](#huksoptions) | 是   | 用于存放生成key所需TAG。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**示例：**

```ts
/* 以生成AES128密钥为例 */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
class HuksProperties {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest 
}
let keyAlias = 'keyAlias';
let properties: HuksProperties[] = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  },
  {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_GCM
  }
];
let options: huks.HuksOptions = {
    properties: properties
};
try {
    huks.generateKeyItem(keyAlias, options)
        .then((data) => {
            console.info(`promise: generateKeyItem success`);
        })
        .catch((error: BusinessError) => {
            console.error(`promise: generateKeyItem failed`);
        });
} catch (error) {
    console.error(`promise: generateKeyItem input arg invalid`);
}
```

## huks.deleteKeyItem<sup>9+</sup>

deleteKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void

删除密钥，使用Callback回调异步返回结果。

**系统能力**：SystemCapability.Security.Huks.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                          |
| -------- | --------------------------- | ---- | --------------------------------------------- |
| keyAlias | string                      | 是   | 密钥别名，应为生成key时传入的别名。           |
| options  | [HuksOptions](#huksoptions) | 是   | 用于删除时指定密钥的属性TAG，比如删除的密钥范围（全量/单个），当删除单个时，TAG字段可传空。                      |
| callback | AsyncCallback\<void>        | 是   | 回调函数。不返回err值时表示接口使用成功，其他时为错误。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**示例：**

```ts
import huks from '@ohos.security.huks';
/* 此处options选择emptyOptions传空 */
let keyAlias = 'keyAlias';
let emptyOptions: huks.HuksOptions = {
    properties: []
};
try {
    huks.deleteKeyItem(keyAlias, emptyOptions, (error, data) => {
        if (error) {
            console.error(`callback: deleteKeyItem failed`);
        } else {
            console.info(`callback: deleteKeyItem key success`);
        }
    });
} catch (error) {
    console.error(`callback: deleteKeyItem input arg invalid`);
}
```

## huks.deleteKeyItem<sup>9+</sup>

deleteKeyItem(keyAlias: string, options: HuksOptions) : Promise\<void>

删除密钥，使用Promise方式异步返回结果。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                |
| -------- | --------------------------- | ---- | ----------------------------------- |
| keyAlias | string                      | 是   | 密钥别名，应为生成key时传入的别名。 |
| options  | [HuksOptions](#huksoptions) | 是   | 用于删除时指定密钥的属性TAG，比如删除的密钥范围（全量/单个），当删除单个时，TAG字段可传空。            |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**示例：**

```ts
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
/* 此处options选择emptyOptions传空 */
let keyAlias = 'keyAlias';
let emptyOptions: huks.HuksOptions = {
    properties: []
};
try {
    huks.deleteKeyItem(keyAlias, emptyOptions)
        .then ((data) => {
            console.info(`promise: deleteKeyItem key success`);
        })
        .catch((error: BusinessError) => {
            console.error(`promise: deleteKeyItem failed`);
        });
} catch (error) {
    console.error(`promise: deleteKeyItem input arg invalid`);
}
```

## huks.importKeyItem<sup>9+</sup>

importKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void

导入明文密钥，使用Callback方式回调异步返回结果 。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                          |
| -------- | --------------------------- | ---- | --------------------------------------------- |
| keyAlias | string                      | 是   | 密钥别名。                                    |
| options  | [HuksOptions](#huksoptions) | 是   | 用于导入时所需TAG和需要导入的密钥。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |
| callback | AsyncCallback\<void>        | 是   | 回调函数。不返回err值时表示接口使用成功，其他时为错误。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**示例：**

```ts
import huks from '@ohos.security.huks';
/* 以导入AES128密钥为例 */
class HuksProperties {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyPadding |
    huks.HuksCipherMode = huks.HuksKeyAlg.HUKS_ALG_ECC
}
let plainTextSize32 = makeRandomArr(32);
function makeRandomArr(size: number) {
    let arr = new Uint8Array(size);
    for (let i = 0; i < size; i++) {
        arr[i] = Math.floor(Math.random() * 10);
    }
    return arr;
};
let keyAlias = 'keyAlias';
let properties: HuksProperties[] = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  },
  {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_GCM
  }
];
let options: huks.HuksOptions = {
    properties: properties,
    inData: plainTextSize32
};
try {
    huks.importKeyItem(keyAlias, options, (error, data) => {
        if (error) {
            console.error(`callback: importKeyItem failed`);
        } else {
            console.info(`callback: importKeyItem success`);
        }
    });
} catch (error) {
    console.error(`callback: importKeyItem input arg invalid`);
}
```

## huks.importKeyItem<sup>9+</sup>

importKeyItem(keyAlias: string, options: HuksOptions) : Promise\<void>

导入明文密钥，使用Promise方式异步返回结果。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                |
| -------- | --------------------------- | ---- | ----------------------------------- |
| keyAlias | string                      | 是   | 密钥别名。                          |
| options  | [HuksOptions](#huksoptions) | 是   | 用于导入时所需TAG和需要导入的密钥。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**示例：**

```ts
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
/* 以导入AES128为例 */
class HuksProperties {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyPadding |
    huks.HuksCipherMode = huks.HuksKeyAlg.HUKS_ALG_ECC
}
let plainTextSize32 = makeRandomArr(32);
function makeRandomArr(size: number) {
    let arr = new Uint8Array(size);
    for (let i = 0; i < size; i++) {
        arr[i] = Math.floor(Math.random() * 10);
    }
    return arr;
};
/*第一步：生成密钥*/
let keyAlias = 'keyAlias';
let properties: HuksProperties[] = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  },
  {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_GCM
  }
];
let huksoptions: huks.HuksOptions = {
    properties: properties,
    inData: plainTextSize32
};
try {
    huks.importKeyItem(keyAlias, huksoptions)
        .then((data) => {
            console.info(`promise: importKeyItem success`);
        })
        .catch((error: BusinessError) => {
            console.error(`promise: importKeyItem failed`);
        });
} catch (error) {
    console.error(`promise: importKeyItem input arg invalid`);
}
```

## huks.hasKeyItem<sup>11+</sup>

hasKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>) : void

判断密钥是否存在，使用Callback回调异步返回结果 。

**系统能力**：SystemCapability.Security.Huks.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                     |
| -------- | --------------------------- | ---- |--------------------------------------------------------|
| keyAlias | string                      | 是   | 所需查找的密钥的别名。                                            |
| options  | [HuksOptions](#huksoptions) | 是   | 用于查询时指定密钥的属性TAG，如使用HuksAuthStorageLevel指定查询密钥的存储安全等级。可传空     |
| callback | AsyncCallback\<boolean>     | 是   | 回调函数。若密钥存在，data为true，若密钥不存在，data为false。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**示例：**

```ts
import huks from '@ohos.security.huks';
import promptAction from '@ohos.promptAction';
/* 此处options选择emptyOptions来传空 */
let keyAlias = 'keyAlias';
let emptyOptions: huks.HuksOptions = {
    properties: []
};

try {
    huks.hasKeyItem(keyAlias, emptyOptions, (error, data) => {
        if (data) {
            promptAction.showToast({
                message: "keyAlias: " + keyAlias +" is existed!",
                duration: 2500,
            })
        } else {
            promptAction.showToast({
                message: "find key failed",
                duration: 2500,
            })
        }
    });
} catch (error) {
    console.error(`callback: hasKeyItem input args may be invalid`);
}
```

## huks.hasKeyItem<sup>11+</sup>

hasKeyItem(keyAlias: string, options: HuksOptions) : Promise\<boolean>

判断密钥是否存在，使用Promise回调异步返回结果 。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                     |
| -------- | --------------------------- | ---- | ------------------------ |
| keyAlias | string                      | 是   | 所需查找的密钥的别名。   |
| options  | [HuksOptions](#huksoptions) | 是   | 用于查询时指定密钥的属性TAG，如使用HuksAuthStorageLevel指定查询密钥的存储安全等级。可传空     |

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<boolean> | Promise对象。若密钥存在，返回值为true，若密钥不存在，返回值为false。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**示例：**

```ts
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

/* 此处options选择emptyOptions来传空 */
let keyAlias = 'keyAlias';
let emptyOptions: huks.HuksOptions = {
    properties: []
};
huks.hasKeyItem(keyAlias, emptyOptions).then((data) => {
    if (data) {
        promptAction.showToast({
            message: "keyAlias: " + keyAlias +" is existed!",
            duration: 2500,
        })
    } else {
        promptAction.showToast({
            message: "find key failed",
            duration: 2500,
        })
    }
}).catch((error: BusinessError)=>{
    promptAction.showToast({
        message: "find key failed",
        duration: 6500,
    })
})
```

## huks.initSession<sup>9+</sup>

initSession(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksSessionHandle>) : void

initSession操作密钥接口，使用Callback回调异步返回结果。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**系统能力**：SystemCapability.Security.Huks.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                 |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------------------------- |
| keyAlias | string                                                  | 是   | initSession操作密钥的别名。                                 |
| options  | [HuksOptions](#huksoptions)                             | 是   | initSession操作的参数集合。                                 |
| callback | AsyncCallback\<[HuksSessionHandle](#hukssessionhandle9)> | 是   | 回调函数。将initSession操作返回的handle添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000010 | the number of sessions has reached limit. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

## huks.initSession<sup>9+</sup>

initSession(keyAlias: string, options: HuksOptions) : Promise\<HuksSessionHandle>

initSession操作密钥接口，使用Promise方式异步返回结果。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                             |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------ |
| keyAlias | string                                            | 是   | initSession操作密钥的别名。                             |
| options  | [HuksOptions](#huksoptions)                       | 是   | initSession参数集合。                                   |

**返回值**：

| 类型                                | 说明                                               |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksSessionHandle](#hukssessionhandle9)> | Promise对象。将initSession操作返回的handle添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000010 | the number of sessions has reached limit. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

## huks.updateSession<sup>9+</sup>

updateSession(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>) : void

updateSession操作密钥接口，使用Callback回调异步返回结果。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**系统能力**：SystemCapability.Security.Huks.Core

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                         |
| -------- | ---------------------------------------------------- | ---- | -------------------------------------------- |
| handle   | number                                               | 是   | updateSession操作的handle。                         |
| options  | [HuksOptions](#huksoptions)                          | 是   | updateSession的参数集合。                           |
| callback | AsyncCallback<[HuksReturnResult](#huksreturnresult9)> | 是   | 回调函数。将updateSession操作的结果添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000007 | this credential is already invalidated permanently. |
| 12000008 | verify authtoken failed. |
| 12000009 | authtoken is already timeout. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

## huks.updateSession<sup>9+</sup>

updateSession(handle: number, options: HuksOptions, token: Uint8Array, callback: AsyncCallback\<HuksReturnResult>) : void

updateSession操作密钥接口，使用Callback回调异步返回结果。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                         |
| -------- | ---------------------------------------------------- | ---- | -------------------------------------------- |
| handle   | number                                               | 是   | updateSession操作的handle。                         |
| options  | [HuksOptions](#huksoptions)                          | 是   | updateSession操作的参数集合。                       |
| token    | Uint8Array                                           | 是   | updateSession操作的token。                          |
| callback | AsyncCallback<[HuksReturnResult](#huksreturnresult9)> | 是   | 回调函数。将updateSession操作的结果添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000007 | this credential is already invalidated permanently. |
| 12000008 | verify authtoken failed. |
| 12000009 | authtoken is already timeout. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

## huks.updateSession<sup>9+</sup>

updateSession(handle: number, options: HuksOptions, token?: Uint8Array) : Promise\<HuksReturnResult>

updateSession操作密钥接口，使用Promise方式异步返回结果。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名  | 类型                                           | 必填 | 说明                                         |
| ------- | ---------------------------------------------- | ---- | -------------------------------------------- |
| handle  | number                                         | 是   | updateSession操作的handle。                         |
| options | [HuksOptions](#huksoptions)                    | 是   | updateSession操作的参数集合。                       |
| token   | Uint8Array                                     | 否   | updateSession操作的token。                          |

**返回值**：

| 类型                                | 说明                                               |
| ----------------------------------- | -------------------------------------------------- |
| Promise<[HuksReturnResult](#huksreturnresult9)> | Promise对象。将updateSession操作的结果添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000007 | this credential is already invalidated permanently. |
| 12000008 | verify authtoken failed. |
| 12000009 | authtoken is already timeout. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

## huks.finishSession<sup>9+</sup>

finishSession(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>) : void

finishSession操作密钥接口，使用Callback回调异步返回结果。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**系统能力**：SystemCapability.Security.Huks.Core

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                         |
| -------- | ---------------------------------------------------- | ---- | -------------------------------------------- |
| handle   | number                                               | 是   | finishSession操作的handle。                         |
| options  | [HuksOptions](#huksoptions)                          | 是   | finishSession的参数集合。                           |
| callback | AsyncCallback<[HuksReturnResult](#huksreturnresult9)> | 是   | 回调函数。将finishSession操作的结果添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000007 | this credential is already invalidated permanently. |
| 12000008 | verify authtoken failed. |
| 12000009 | authtoken is already timeout. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

## huks.finishSession<sup>9+</sup>

finishSession(handle: number, options: HuksOptions, token: Uint8Array, callback: AsyncCallback\<HuksReturnResult>) : void

finishSession操作密钥接口，使用Callback回调异步返回结果。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                         |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------- |
| handle   | number                                                | 是   | finishSession操作的handle。                         |
| options  | [HuksOptions](#huksoptions)                           | 是   | finishSession的参数集合。                           |
| token    | Uint8Array                                            | 是   | finishSession操作的token。                          |
| callback | AsyncCallback\<[HuksReturnResult](#huksreturnresult9)> | 是   | 回调函数。将finishSession操作的结果添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000007 | this credential is already invalidated permanently. |
| 12000008 | verify authtoken failed. |
| 12000009 | authtoken is already timeout. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

## huks.finishSession<sup>9+</sup>

finishSession(handle: number, options: HuksOptions, token?: Uint8Array) : Promise\<HuksReturnResult>

finishSession操作密钥接口，使用Promise方式异步返回结果。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名  | 类型                                            | 必填 | 说明                                |
| ------- | ----------------------------------------------- | ---- | ----------------------------------- |
| handle  | number                                          | 是   | finishSession操作的handle。                |
| options | [HuksOptions](#huksoptions)                     | 是   | finishSession操作的参数集合。              |
| token   | Uint8Array                                      | 否   | finishSession操作的token。                 |

**返回值**：

| 类型                                | 说明                                               |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksReturnResult](#huksreturnresult9)> | Promise对象，用于获取异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000007 | this credential is already invalidated permanently. |
| 12000008 | verify authtoken failed. |
| 12000009 | authtoken is already timeout. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

## huks.abortSession<sup>9+</sup>

abortSession(handle: number, options: HuksOptions, callback: AsyncCallback\<void>) : void

abortSession操作密钥接口，使用Callback回调异步返回结果 。

**系统能力**：SystemCapability.Security.Huks.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                        |
| -------- | --------------------------- | ---- | ------------------------------------------- |
| handle   | number                      | 是   | abortSession操作的handle。                         |
| options  | [HuksOptions](#huksoptions) | 是   | abortSession操作的参数集合。                       |
| callback | AsyncCallback\<void>        | 是   | 回调函数。将abortSession操作的结果添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**示例：**

```ts
import huks from '@ohos.security.huks';
/* huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用，当
 * huks.initSession和huks.updateSession
 * 以及huks.finishSession操作中的任一阶段发生错误时，
 * 都需要调用huks.abortSession来终止密钥的使用。
 *
 * 以下以AES128密钥的callback功能使用为例
 */
class HuksProperties {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest |
    huks.HuksKeyPadding | huks.HuksCipherMode = huks.HuksKeyAlg.HUKS_ALG_ECC
}
let keyAlias = "HuksDemoAES";
let properties: HuksProperties[] = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  },
  {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_GCM
  }
];
let options: huks.HuksOptions = {
    properties: properties,
    inData: new Uint8Array(0)
};
let handle: number = 0;
async function huksAbort() {
    try {
        huks.generateKeyItem(keyAlias, options, (error, data) => {
            if (error) {
                console.error(`callback: generateKeyItem failed`);
            } else {
                console.info(`callback: generateKeyItem success`);
                huks.initSession(keyAlias, options, (error, data) => { // 以initSession阶段进行abortSession为例
                    if (error) {
                        console.error(`callback: initSession failed`);
                    } else {
                        console.info(`callback: initSession success, data = ${JSON.stringify(data)}`);
                        handle = data.handle;
                        huks.abortSession(handle, options, (error, data) => {
                            if (error) {
                                console.error(`callback: abortSession failed`);
                            } else {
                                console.info(`callback: abortSession success`);
                            }
                        });
                    }
                });
            }
        });
    } catch (error) {
        console.error(`callback: huksAbort failed`);
    }
}
```

## huks.abortSession<sup>9+</sup>

abortSession(handle: number, options: HuksOptions) : Promise\<void>;

abortSession操作密钥接口，使用Promise方式异步返回结果。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名  | 类型                        | 必填 | 说明                                        |
| ------- | --------------------------- | ---- | ------------------------------------------- |
| handle  | number                      | 是   | abortSession操作的handle。                         |
| options | [HuksOptions](#huksoptions) | 是   | abortSession操作的参数集合。                       |

**返回值**：

| 类型                                | 说明                                               |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<void>             | Promise对象。将abortSession操作的结果添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](../errorcodes/errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**示例：**

```ts
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
/* huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用，当
 * huks.initSession和huks.updateSession
 * 以及huks.finishSession操作中的任一阶段发生错误时，
 * 都需要调用huks.abortSession来终止密钥的使用。
 *
 * 以下以AES128密钥的promise功能使用为例
 */
class HuksProperties {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose |
    huks.HuksKeyDigest | huks.HuksKeyPadding | huks.HuksKeyGenerateType |
    huks.HuksCipherMode = huks.HuksKeyAlg.HUKS_ALG_ECC
}

function stringToUint8Array(str: string) {
    let arr: number[] = [];
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    let tmpUint8Array = new Uint8Array(arr);
    return tmpUint8Array;
}

let keyAlias = "HuksDemoAES";
let properties: HuksProperties[] = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  },
  {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_GCM
  }
];
let options: huks.HuksOptions = {
    properties: properties,
    inData: new Uint8Array(0)
};
let handle: number = 0;

async function generateKey() {
    try {
        await huks.generateKeyItem(keyAlias, options)
            .then((data) => {
                console.info(`promise: generateKeyItem success`);
            })
            .catch((error: BusinessError) => {
                console.error(`promise: generateKeyItem failed`);
            });
    } catch (error) {
        console.error(`promise: generateKeyItem input arg invalid`);
    }
}

async function huksInit() {
    console.log('enter huksInit');
    try {
        await huks.initSession(keyAlias, options)
            .then((data) => {
                console.info(`promise: initSession success, data = ${JSON.stringify(data)}`);
                handle = data.handle;
            })
            .catch((error: BusinessError) => {
                console.error(`promise: initSession key failed`);
            });
    } catch (error) {
        console.error(`promise: initSession input arg invalid`);
    }
}

async function huksUpdate() {
    console.log('enter huksUpdate');
    options.inData = stringToUint8Array("huksHmacTest");
    try {
        await huks.updateSession(handle, options)
            .then((data) => {
                console.info(`promise: updateSession success, data = ${JSON.stringify(data)}`);
            })
            .catch((error: BusinessError) => {
                console.error(`promise: updateSession failed`);
            });
    } catch (error) {
        console.error(`promise: updateSession input arg invalid`);
    }
}

async function huksFinish() {
    console.log('enter huksFinish');
    options.inData = new Uint8Array(0);
    try {
        await huks.finishSession(handle, options)
            .then((data) => {
                console.info(`promise: finishSession success, data = ${JSON.stringify(data)}`);
            })
            .catch((error: BusinessError) => {
                console.error(`promise: finishSession failed`);
            });
    } catch (error) {
        console.error(`promise: finishSession input arg invalid`);
    }
}

async function huksAbort() {
    console.log('enter huksAbort');
    try {
        await huks.abortSession(handle, options)
            .then((data) => {
                console.info(`promise: abortSession success`);
            })
            .catch((error: BusinessError) => {
                console.error(`promise: abortSession failed`);
            });
    } catch (error) {
        console.error(`promise: abortSession input arg invalid`);
    }
}

async function testAbort() {
    await generateKey();
    await huksInit(); // 以initSession阶段进行abortSession为例
    await huksAbort();
}
```


## HuksExceptionErrCode<sup>9+</sup>

表示错误码的枚举以及对应的错误信息， 错误码表示错误类型，错误信息展示错误详情。

关于错误码的具体信息，可在[错误码参考文档](../errorcodes/errorcode-huks.md)中查看。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称                                           | 值 |  说明                        |
| ---------------------------------------------- | -------- |--------------------------- |
| HUKS_ERR_CODE_PERMISSION_FAIL                  | 201      | 权限错误导致失败。<br> **系统能力：** SystemCapability.Security.Huks.Core          |
| HUKS_ERR_CODE_ILLEGAL_ARGUMENT                 | 401      | 参数错误导致失败。<br> **系统能力：** SystemCapability.Security.Huks.Core          |
| HUKS_ERR_CODE_NOT_SUPPORTED_API                | 801      | 不支持的API。<br> **系统能力：** SystemCapability.Security.Huks.Core               |
| HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED            | 12000001 | 不支持的功能/特性。<br> **系统能力：** SystemCapability.Security.Huks.Core         |
| HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT      | 12000002 | 缺少密钥算法参数。<br> **系统能力：** SystemCapability.Security.Huks.Core          |
| HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT      | 12000003 | 无效密钥算法参数。<br> **系统能力：** SystemCapability.Security.Huks.Core          |
| HUKS_ERR_CODE_FILE_OPERATION_FAIL              | 12000004 | 文件操作失败。<br> **系统能力：** SystemCapability.Security.Huks.Core              |
| HUKS_ERR_CODE_COMMUNICATION_FAIL               | 12000005 | 通信失败。<br> **系统能力：** SystemCapability.Security.Huks.Core                  |
| HUKS_ERR_CODE_CRYPTO_FAIL                      | 12000006 | 算法库操作失败。<br> **系统能力：** SystemCapability.Security.Huks.Core            |
| HUKS_ERR_CODE_KEY_AUTH_PERMANENTLY_INVALIDATED | 12000007 | 密钥访问失败-密钥访问失效。<br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_ERR_CODE_KEY_AUTH_VERIFY_FAILED           | 12000008 | 密钥访问失败-密钥认证失败。<br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_ERR_CODE_KEY_AUTH_TIME_OUT                | 12000009 | 密钥访问失败-密钥访问超时。<br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_ERR_CODE_SESSION_LIMIT                    | 12000010 | 密钥操作会话数已达上限。<br> **系统能力：** SystemCapability.Security.Huks.Core    |
| HUKS_ERR_CODE_ITEM_NOT_EXIST                   | 12000011 | 目标对象不存在。<br> **系统能力：** SystemCapability.Security.Huks.Core            |
| HUKS_ERR_CODE_EXTERNAL_ERROR                   | 12000012 | 外部错误。<br> **系统能力：** SystemCapability.Security.Huks.Core                  |
| HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST             | 12000013 | 缺失所需凭据。<br> **系统能力：** SystemCapability.Security.Huks.Core              |
| HUKS_ERR_CODE_INSUFFICIENT_MEMORY              | 12000014 | 内存不足。<br> **系统能力：** SystemCapability.Security.Huks.Core                  |
| HUKS_ERR_CODE_CALL_SERVICE_FAILED              | 12000015 | 调用其他系统服务失败。<br> **系统能力：** SystemCapability.Security.Huks.Core      |

## HuksKeyPurpose

表示密钥用途。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称                     | 值   | 说明                             |
| ------------------------ | ---- | -------------------------------- |
| HUKS_KEY_PURPOSE_ENCRYPT | 1    | 表示密钥用于对明文进行加密操作。 <br> **系统能力：** SystemCapability.Security.Huks.Core|
| HUKS_KEY_PURPOSE_DECRYPT | 2    | 表示密钥用于对密文进行解密操作。 <br> **系统能力：** SystemCapability.Security.Huks.Core|

## HuksKeyPadding

表示补齐算法。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称                   | 值   | 说明                                     |
| ---------------------- | ---- | ---------------------------------------- |
| HUKS_PADDING_NONE | 0    | 表示不使用补齐算法。 <br> **系统能力：** SystemCapability.Security.Huks.Core|

## HuksCipherMode

表示加密模式。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称          | 值   | 说明                  |
| ------------- | ---- | --------------------- |
| HUKS_MODE_GCM | 32   | 表示使用GCM加密模式。 <br> **系统能力：** SystemCapability.Security.Huks.Core|

## HuksKeySize

表示密钥长度。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称                               | 值   | 说明                                       |
| ---------------------------------- | ---- | ------------------------------------------ |
| HUKS_AES_KEY_SIZE_128              | 128  | 表示使用AES算法的密钥长度为128bit。 <br> **系统能力：** SystemCapability.Security.Huks.Core|
| HUKS_AES_KEY_SIZE_192              | 192  | 表示使用AES算法的密钥长度为192bit。  <br> **系统能力：** SystemCapability.Security.Huks.Core|
| HUKS_AES_KEY_SIZE_256              | 256  | 表示使用AES算法的密钥长度为256bit。  <br> **系统能力：** SystemCapability.Security.Huks.Core|

## HuksKeyAlg

表示密钥使用的算法。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称                      | 值   | 说明                  |
| ------------------------- | ---- | --------------------- |
| HUKS_ALG_AES              | 20   | 表示使用AES算法。  <br> **系统能力：** SystemCapability.Security.Huks.Core|

## HuksSecureSignType<sup>9+</sup>

表示生成或导入密钥时，指定该密钥的签名类型。

**系统能力**：SystemCapability.Security.Huks.Extension

| 名称                           | 值   | 说明                                                         |
| ------------------------------ | ---- | ------------------------------------------------------------ |
| HUKS_SECURE_SIGN_WITH_AUTHINFO | 1    | 表示签名类型为携带认证信息。生成或导入密钥时指定该字段，则在使用密钥进行签名时，对待签名的数据添加认证信息后进行签名。 |

## HuksAuthStorageLevel<sup>11+</sup>

表示生成或导入密钥时，指定该密钥的存储安全等级。

**系统能力**：SystemCapability.Security.Huks.Extension

| 名称                           | 值   | 说明                                                         |
| ------------------------------ | ---- | ------------------------------------------------------------ |
| HUKS_AUTH_STORAGE_LEVEL_DE | 0    | 表示密钥仅在开机后可访问。 |
| HUKS_AUTH_STORAGE_LEVEL_CE | 1    | 表示密钥仅在首次解锁后可访问。 |
| HUKS_AUTH_STORAGE_LEVEL_ECE | 2    | 表示密钥仅在解锁状态时可访问。 |

## HuksTagType

表示Tag的数据类型。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称                  | 值      | 说明                                    |
| --------------------- | ------- | --------------------------------------- |
| HUKS_TAG_TYPE_INVALID | 0 << 28 | 表示非法的Tag类型。                     |
| HUKS_TAG_TYPE_INT     | 1 << 28 | 表示该Tag的数据类型为int类型的number。  |
| HUKS_TAG_TYPE_UINT    | 2 << 28 | 表示该Tag的数据类型为uint类型的number。 |
| HUKS_TAG_TYPE_ULONG   | 3 << 28 | 表示该Tag的数据类型为bigint。           |
| HUKS_TAG_TYPE_BOOL    | 4 << 28 | 表示该Tag的数据类型为boolean。          |
| HUKS_TAG_TYPE_BYTES   | 5 << 28 | 表示该Tag的数据类型为Uint8Array。       |

## HuksTag

表示调用参数的Tag。

**系统能力**：SystemCapability.Security.Huks.Core

| 名称                                                        | 值                                       | 说明                                                         |
| ----------------------------------------------------------- | ---------------------------------------- | ------------------------------------------------------------ |
| HUKS_TAG_ALGORITHM                                          | HuksTagType.HUKS_TAG_TYPE_UINT \| 1      | 表示算法的Tag。    <br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_TAG_PURPOSE                                            | HuksTagType.HUKS_TAG_TYPE_UINT \| 2      | 表示密钥用途的Tag。    <br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_TAG_KEY_SIZE                                           | HuksTagType.HUKS_TAG_TYPE_UINT \| 3      | 表示密钥长度的Tag。   <br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_TAG_DIGEST                                             | HuksTagType.HUKS_TAG_TYPE_UINT \| 4      | 表示摘要算法的Tag。    <br> **系统能力：** SystemCapability.Security.Huks.Extension |
| HUKS_TAG_PADDING                                            | HuksTagType.HUKS_TAG_TYPE_UINT \| 5      | 表示补齐算法的Tag。    <br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_TAG_BLOCK_MODE                                         | HuksTagType.HUKS_TAG_TYPE_UINT \| 6      | 表示加密模式的Tag。     <br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_TAG_KEY_TYPE                                           | HuksTagType.HUKS_TAG_TYPE_UINT \| 7      | 表示密钥类型的Tag。     <br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_TAG_ASSOCIATED_DATA                                    | HuksTagType.HUKS_TAG_TYPE_BYTES \| 8     | 表示附加身份验证数据的Tag。    <br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_TAG_NONCE                                              | HuksTagType.HUKS_TAG_TYPE_BYTES \| 9     | 表示密钥加解密的字段。     <br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_TAG_KEY_ALIAS                                          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 23    | 表示密钥别名。        <br> **系统能力：** SystemCapability.Security.Huks.Core |
| HUKS_TAG_AE_TAG                                             | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10009 | 用于传入GCM模式中的AEAD数据的字段。      <br> **系统能力：** SystemCapability.Security.Huks.Core |