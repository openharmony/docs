# @ohos.security.huks    
向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。HUKS所管理的密钥可以由应用导入或者由应用调用HUKS接口生成。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import huks from '@ohos.security.huks'    
```  
    
## generateKey<sup>(deprecated)</sup>    
生成密钥，使用Callback回调异步返回结果。  
 **调用形式：**     
- generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.generateKeyItem。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 用于存放生成key所需TAG。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<HuksResult> | true | 回调函数。返回HUKS_SUCCESS时表示接口使用成功，其余结果请参考HuksResult进行错误码查询。 | |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';  
/* 以生成RSA512密钥为例 */  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose |  
    huks.HuksKeyDigest | huks.HuksKeyPadding = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
let keyAlias = 'keyAlias';  
let properties: HuksProperties[] = [  
    {  
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
        value: huks.HuksKeyAlg.HUKS_ALG_RSA  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value:  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PADDING,  
        value: huks.HuksKeyPadding.HUKS_PADDING_OAEP  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_DIGEST,  
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
    }  
];  
let options: huks.HuksOptions = {  
    properties: properties  
};  
huks.generateKey(keyAlias, options, (err, data) => {  
});  
    
```    
  
    
## generateKey<sup>(deprecated)</sup>    
生成密钥，使用Promise方式异步返回结果。  
 **调用形式：**     
- generateKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.generateKeyItem。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 密钥别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 用于存放生成key所需TAG。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<HuksResult> | Promise对象。返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';  
/* 以生成ECC256密钥为例 */  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose |  
    huks.HuksKeyDigest = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
  
let keyAlias = 'keyAlias';  
let properties: HuksProperties[] = [  
    {  
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
        value: huks.HuksKeyAlg.HUKS_ALG_ECC  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
        value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value:  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_DIGEST,  
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
    }  
];  
let options: huks.HuksOptions = {  
    properties: properties  
};  
let result = huks.generateKey(keyAlias, options);  
    
```    
  
    
## generateKeyItem<sup>(9+)</sup>    
生成密钥  
 **调用形式：**     
    
- generateKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- generateKeyItem(keyAlias: string, options: HuksOptions): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias | string | true | 别名。 |  
| options | HuksOptions | true | 用于存放生成key所需TAG。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。未捕获error时代表用户指定别名的密钥生成成功，基于密钥不出TEE原则，此接口不会返回密钥材料内容，若捕获error，则为生成阶段出现异常。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
    
 **示例代码1：**   
示例（callback）:  
```ts    
import huks from '@ohos.security.huks';  
/* 以生成ECC256密钥为例 */  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
let keyAlias: string = 'keyAlias';  
let properties: HuksProperties[] = [  
    {  
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
        value: huks.HuksKeyAlg.HUKS_ALG_ECC  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
        value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value:  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_DIGEST,  
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
    },  
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
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
/* 以生成ECC256密钥为例 */  
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
let keyAlias = 'keyAlias';  
let properties: HuksProperties[] = [  
    {  
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
        value: huks.HuksKeyAlg.HUKS_ALG_ECC  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
        value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value:  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_DIGEST,  
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
    },  
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
  
    
## deleteKey<sup>(deprecated)</sup>    
删除密钥，使用Callback回调异步返回结果。  
 **调用形式：**     
- deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.deleteKeyItem。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 密钥别名，应为生成key时传入的别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 空对象（此处传空即可）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<HuksResult> | true | 回调函数。返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';/* 此处options选择emptyOptions传空 */let keyAlias = 'keyAlias';let emptyOptions: huks.HuksOptions = {    properties: []};huks.deleteKey(keyAlias, emptyOptions, (err, data) => {});    
```    
  
    
## deleteKey<sup>(deprecated)</sup>    
删除密钥，使用Promise方式异步返回结果。  
 **调用形式：**     
- deleteKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.deleteKeyItem。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 密钥别名，应为生成key时传入的别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 空对象（此处传空即可）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<HuksResult> | Promise对象。返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';/* 此处options选择emptyOptions传空 */let keyAlias = 'keyAlias';let emptyOptions: huks.HuksOptions = {    properties: []};let result = huks.deleteKey(keyAlias, emptyOptions);    
```    
  
    
## deleteKeyItem<sup>(9+)</sup>    
删除密钥  
 **调用形式：**     
    
- deleteKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- deleteKeyItem(keyAlias: string, options: HuksOptions): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias | string | true | 密钥别名，应为生成key时传入的别名。 |  
| options | HuksOptions | true | 空对象（此处传空即可）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不返回err值时表示接口使用成功，其他时为错误。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | argument is invalid. |  
| 801 | api is not supported. |  
| 12000004 | operating file failed. |  
| 12000005 | IPC communication failed. |  
| 12000011 | queried entity does not exist. |  
| 12000012 | external error. |  
| 12000014 | memory is insufficient. |  
    
 **示例代码1：**   
示例（callback）:  
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
  
    
 **示例代码2：**   
示例（Promise）:  
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
  
    
## importKey<sup>(deprecated)</sup>    
导入明文密钥，使用Callback方式回调异步返回结果 。  
 **调用形式：**     
- importKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.importKeyItem。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 密钥别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 用于导入时所需TAG和需要导入的密钥。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<HuksResult> | true | 回调函数。返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';  
/* 以导入AES256密钥为例 */  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose |  
    huks.HuksKeyPadding | huks.HuksCipherMode = huks.HuksKeyAlg.HUKS_ALG_ECC  
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
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value:  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PADDING,  
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,  
        value: huks.HuksCipherMode.HUKS_MODE_ECB  
    }  
];  
let options: huks.HuksOptions = {  
    properties: properties,  
    inData: plainTextSize32  
};  
huks.importKey(keyAlias, options, (err, data) => {  
});  
    
```    
  
    
## importKey<sup>(deprecated)</sup>    
导入明文密钥，使用Promise方式异步返回结果。  
 **调用形式：**     
- importKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.importKeyItem。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 密钥别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 用于导入时所需TAG和需要导入的密钥。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<HuksResult> | Promise对象。返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';  
/* 以导入AES128为例 */  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose |  
    huks.HuksKeyPadding | huks.HuksCipherMode = huks.HuksKeyAlg.HUKS_ALG_ECC  
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
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,  
        value: huks.HuksCipherMode.HUKS_MODE_ECB  
    }  
];  
let huksoptions: huks.HuksOptions = {  
    properties: properties,  
    inData: plainTextSize32  
};  
let result = huks.importKey(keyAlias, huksoptions);  
    
```    
  
    
## importKeyItem<sup>(9+)</sup>    
导入明文密钥  
 **调用形式：**     
    
- importKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- importKeyItem(keyAlias: string, options: HuksOptions): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias | string | true | 密钥别名。 |  
| options | HuksOptions | true | 用于导入时所需TAG和需要导入的密钥。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不返回err值时表示接口使用成功，其他时为错误。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | argument is invalid. |  
| 801 | api is not supported. |  
| 12000001 | algorithm mode is not supported. |  
| 12000002 | algorithm param is missing. |  
| 12000003 | algorithm param is invalid |  
| 12000004 | operating file failed. |  
| 12000005 | IPC communication failed. |  
| 12000006 | error occured in crypto engine. |  
| 12000011 | queried entity does not exist. |  
| 12000012 | external error. |  
| 12000013 | queried credential does not exist. |  
| 12000014 | memory is insufficient. |  
| 12000015 | call service failed. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import huks from '@ohos.security.huks';  
/* 以导入AES256密钥为例 */  
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
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value:  
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PADDING,  
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,  
        value: huks.HuksCipherMode.HUKS_MODE_ECB  
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
  
    
 **示例代码2：**   
示例（Promise）:  
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
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_PADDING,  
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7  
    },  
    {  
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,  
        value: huks.HuksCipherMode.HUKS_MODE_ECB  
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
  
    
## importWrappedKeyItem<sup>(9+)</sup>    
导入加密密钥  
 **调用形式：**     
    
- importWrappedKeyItem(    keyAlias: string,    wrappingKeyAlias: string,    options: HuksOptions,    callback: AsyncCallback\<void>  ): void    
起始版本： 9    
- importWrappedKeyItem(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias | string | true | 密钥别名，存放待导入密钥的别名。 |  
| wrappingKeyAlias | string | true | 密钥别名，对应密钥用于解密加密的密钥数据。 |  
| options | HuksOptions | true | 用于导入时所需TAG和需要导入的加密的密钥数据。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不返回err值时表示接口使用成功，其他时为错误。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
    
 **示例代码1：**   
示例（callback）:  
```ts    
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose |  
    huks.HuksKeyDigest | huks.HuksKeyPadding | huks.HuksUnwrapSuite |  
    huks.HuksCipherMode | huks.HuksImportKeyType = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
let alias1 = "importAlias";  
let alias2 = "wrappingKeyAlias";  
async function TestGenFunc(alias: string, options: huks.HuksOptions) {  
    try {  
        await genKey(alias, options)  
            .then((data) => {  
                console.info(`callback: generateKeyItem success`);  
            })  
            .catch((error: BusinessError) => {  
                console.error(`callback: generateKeyItem failed`);  
            });  
    } catch (error) {  
        console.error(`callback: generateKeyItem input arg invalid`);  
    }  
}  
function genKey(alias: string, options: huks.HuksOptions) {  
    return new Promise<void>((resolve, reject) => {  
        try {  
            huks.generateKeyItem(alias, options, (error, data) => {  
                if (error) {  
                    reject(error);  
                } else {  
                    resolve(data);  
                }  
            });  
        } catch (error) {  
            throw (new Error(error));  
        }  
    });  
}  
async function TestExportFunc(alias: string, options: huks.HuksOptions) {  
    try {  
        await exportKey(alias, options)  
            .then((data) => {  
                console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);  
            })  
            .catch((error: BusinessError) => {  
                console.error(`callback: exportKeyItem failed`);  
            });  
    } catch (error) {  
        console.error(`callback: exportKeyItem input arg invalid`);  
    }  
}  
function exportKey(alias: string, options: huks.HuksOptions) {  
    return new Promise<huks.HuksReturnResult>((resolve, reject) => {  
        try {  
            huks.exportKeyItem(alias, options, (error, data) => {  
                if (error) {  
                    reject(error);  
                } else {  
                    resolve(data);  
                }  
            });  
        } catch (error) {  
            throw (new Error(error));  
        }  
    });  
}  
async function TestImportWrappedFunc(alias: string, wrappingAlias: string, options: huks.HuksOptions) {  
    try {  
        await importWrappedKey(alias, wrappingAlias, options)  
            .then((data) => {  
                console.info(`callback: importWrappedKeyItem success`);  
            })  
            .catch((error: BusinessError) => {  
                console.error(`callback: importWrappedKeyItem failed`);  
            });  
    } catch (error) {  
        console.error(`callback: importWrappedKeyItem input arg invalid`);  
    }  
}  
function importWrappedKey(alias: string, wrappingAlias: string, options: huks.HuksOptions) {  
    return new Promise<void>((resolve, reject) => {  
        try {  
            huks.importWrappedKeyItem(alias, wrappingAlias, options, (error, data) => {  
                if (error) {  
                    reject(error);  
                } else {  
                    resolve(data);  
                }  
            });  
        } catch (error) {  
            throw (new Error(error));  
        }  
    });  
}  
async function TestImportWrappedKeyFunc(  
        alias: string,  
        wrappingAlias: string,  
        genOptions: huks.HuksOptions,  
        importOptions: huks.HuksOptions  
) {  
    await TestGenFunc(wrappingAlias, genOptions);  
    await TestExportFunc(wrappingAlias, genOptions);  
  
    /* 以下操作不需要调用HUKS接口，此处不给出具体实现。  
     * 假设待导入的密钥为keyA  
     * 1.生成ECC公私钥keyB，公钥为keyB_pub, 私钥为keyB_pri  
     * 2.使用keyB_pri和wrappingAlias密钥中获取的公钥进行密钥协商，协商出共享密钥share_key  
     * 3.随机生成密钥kek，用于加密keyA，采用AES-GCM加密，加密过程中需要记录：nonce1、aad1、加密后的密文keyA_enc、加密后的tag1。  
     * 4.使用share_key加密kek，采用AES-GCM加密，加密过程中需要记录：nonce2、aad2、加密后的密文kek_enc、加密后的tag2。  
     * 5.拼接importOptions.inData字段，满足以下格式:  
     * keyB_pub的长度（4字节） + keyB_pub的数据 + aad2的长度（4字节） + aad2的数据 +  
     * nonce2的长度（4字节）   + nonce2的数据   + tag2的长度（4字节） + tag2的数据 +  
     * kek_enc的长度（4字节）  + kek_enc的数据  + aad1的长度（4字节） + aad1的数据 +  
     * nonce1的长度（4字节）   + nonce1的数据   + tag1的长度（4字节） + tag1的数据 +  
     * keyA长度占用的内存长度（4字节）  + keyA的长度     + keyA_enc的长度（4字节） + keyA_enc的数据  
     */  
    /* 该处为示例代码，实际运行过程中，应使用实际导入密钥数据。数据构造方式由上注释可见说明 */  
    let inputKey = new Uint8Array([0x02, 0x00, 0x00, 0x00]);  
    importOptions.inData = inputKey;  
    await TestImportWrappedFunc(alias, wrappingAlias, importOptions);  
}  
function makeGenerateOptions() {  
    let properties: HuksProperties[] = [  
        {  
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
            value: huks.HuksKeyAlg.HUKS_ALG_ECC  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
            value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_UNWRAP  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_DIGEST,  
            value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_IMPORT_KEY_TYPE,  
            value: huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR,  
        }  
    ];  
    let options: huks.HuksOptions = {  
        properties: properties  
    };  
    return options;  
};  
function makeImportOptions() {  
    let properties: HuksProperties[] = [  
        {  
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
            value: huks.HuksKeyAlg.HUKS_ALG_AES  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
            value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,  
            value: huks.HuksCipherMode.HUKS_MODE_CBC  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_PADDING,  
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_UNWRAP_ALGORITHM_SUITE,  
            value: huks.HuksUnwrapSuite.HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING  
        }  
    ];  
    let options: huks.HuksOptions = {  
        properties: properties  
    };  
    return options;  
};  
function huksImportWrappedKey() {  
    let genOptions = makeGenerateOptions();  
    let importOptions = makeImportOptions();  
    TestImportWrappedKeyFunc(  
        alias1,  
        alias2,  
        genOptions,  
        importOptions  
    );  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
/* 处理流程与callback类似，主要差异点为如下函数： */  
/* 该处为示例代码，实际运行过程中，应使用实际导入密钥数据。数据构造方式由上注释可见说明 */  
async function TestImportWrappedFunc(alias: string, wrappingAlias: string, options: huks.HuksOptions) {  
    try {  
        await huks.importWrappedKeyItem(alias, wrappingAlias, options)  
            .then ((data) => {  
                console.info(`promise: importWrappedKeyItem success`);  
            })  
            .catch((error: BusinessError) => {  
                console.error(`promise: importWrappedKeyItem failed`);  
            });  
    } catch (error) {  
        console.error(`promise: importWrappedKeyItem input arg invalid`);  
    }  
}  
    
```    
  
    
## exportKey<sup>(deprecated)</sup>    
导出密钥，使用Callback方式回调异步返回的结果。  
 **调用形式：**     
- exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.exportKeyItem。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 密钥别名，应与所用密钥生成时使用的别名相同。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 空对象（此处传空即可）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<HuksResult> | true | 回调函数。返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。outData：返回从密钥中导出的公钥。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';/* 此处options选择emptyOptions来传空 */let keyAlias = 'keyAlias';let emptyOptions: huks.HuksOptions = {    properties: []};huks.exportKey(keyAlias, emptyOptions, (err, data) => {});    
```    
  
    
## exportKey<sup>(deprecated)</sup>    
导出密钥，使用Promise方式回调异步返回的结果。  
 **调用形式：**     
- exportKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.exportKeyItem。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 密钥别名，应与所用密钥生成时使用的别名相同。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 空对象（此处传空即可）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<HuksResult> | Promise对象。返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。outData：返回从密钥中导出的公钥。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';/* 此处options选择emptyOptions来传空 */let keyAlias = 'keyAlias';let emptyOptions: huks.HuksOptions = {    properties: []};let result = huks.exportKey(keyAlias, emptyOptions);    
```    
  
    
## exportKeyItem<sup>(9+)</sup>    
导出密钥  
 **调用形式：**     
    
- exportKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>): void    
起始版本： 9    
- exportKeyItem(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias | string | true | 密钥别名，应与所用密钥生成时使用的别名相同。 |  
| options | HuksOptions | true | 空对象（此处传空即可）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不返回err值时表示接口使用成功，其他时为错误。outData：返回从密钥中导出的公钥。 |  
| Promise<HuksReturnResult> | Promise对象。不返回err值时表示接口使用成功，其他时为错误。outData：返回从密钥中导出的公钥。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
| 12000014 | memory is insufficient. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import huks from '@ohos.security.huks';  
/* 此处options选择emptyOptions来传空 */  
let keyAlias = 'keyAlias';  
let emptyOptions: huks.HuksOptions = {  
    properties: []  
};  
try {  
    huks.exportKeyItem(keyAlias, emptyOptions, (error, data) => {  
        if (error) {  
            console.error(`callback: exportKeyItem failed`);  
        } else {  
            console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);  
        }  
    });  
} catch (error) {  
    console.error(`callback: exportKeyItem input arg invalid`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
/* 此处options选择emptyOptions来传空 */  
let keyAlias = 'keyAlias';  
let emptyOptions: huks.HuksOptions = {  
    properties: []  
};  
try {  
    huks.exportKeyItem(keyAlias, emptyOptions)  
        .then ((data) => {  
            console.info(`promise: exportKeyItem success, data = ${JSON.stringify(data)}`);  
        })  
        .catch((error: BusinessError) => {  
            console.error(`promise: exportKeyItem failed`);  
        });  
} catch (error) {  
    console.error(`promise: exportKeyItem input arg invalid`);  
}  
    
```    
  
    
## getKeyProperties<sup>(deprecated)</sup>    
获取密钥属性，使用Callback回调异步返回结果。  
 **调用形式：**     
- getKeyProperties(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.getKeyItemProperties。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 密钥别名，应与所用密钥生成时使用的别名相同。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 空对象（此处传空即可）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<HuksResult> | true | 回调函数。errorCode：返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';/* 此处options选择emptyOptions来传空 */let keyAlias = 'keyAlias';let emptyOptions: huks.HuksOptions = {    properties: []};huks.getKeyProperties(keyAlias, emptyOptions, (err, data) => {});    
```    
  
    
## getKeyProperties<sup>(deprecated)</sup>    
获取密钥属性，使用Promise回调异步返回结果。  
 **调用形式：**     
- getKeyProperties(keyAlias: string, options: HuksOptions): Promise\<HuksResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.getKeyItemProperties。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 密钥别名，应与所用密钥生成时使用的别名相同。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 空对象（此处传空即可）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<HuksResult> | Promise对象。errorCode：返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。properties：返回值为生成密钥时所需参数。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';/* 此处options选择emptyOptions来传空 */let keyAlias = 'keyAlias';let emptyOptions: huks.HuksOptions = {    properties: []};let result = huks.getKeyProperties(keyAlias, emptyOptions);    
```    
  
    
## getKeyItemProperties<sup>(9+)</sup>    
获取密钥属性  
 **调用形式：**     
    
- getKeyItemProperties(    keyAlias: string,    options: HuksOptions,    callback: AsyncCallback\<HuksReturnResult>  ): void    
起始版本： 9    
- getKeyItemProperties(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias | string | true | 密钥别名，应与所用密钥生成时使用的别名相同。 |  
| options | HuksOptions | true | 空对象（此处传空即可）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不返回err值时表示接口使用成功，其他时为错误。properties：返回值为生成密钥时所需参数。 |  
| Promise<HuksReturnResult> | Promise对象。不返回err值时表示接口使用成功，其他时为错误。properties：返回值为生成密钥时所需参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
| 12000014 | memory is insufficient. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import huks from '@ohos.security.huks';  
/* 此处options选择emptyOptions来传空 */  
let keyAlias = 'keyAlias';  
let emptyOptions: huks.HuksOptions = {  
    properties: []  
};  
try {  
    huks.getKeyItemProperties(keyAlias, emptyOptions, (error, data) => {  
        if (error) {  
            console.error(`callback: getKeyItemProperties failed`);  
        } else {  
            console.info(`callback: getKeyItemProperties success, data = ${JSON.stringify(data)}`);  
        }  
    });  
} catch (error) {  
    console.error(`callback: getKeyItemProperties input arg invalid`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
/* 此处options选择emptyOptions来传空 */  
let keyAlias = 'keyAlias';  
let emptyOptions: huks.HuksOptions = {  
    properties: []  
};  
try {  
    huks.getKeyItemProperties(keyAlias, emptyOptions)  
        .then ((data) => {  
            console.info(`promise: getKeyItemProperties success, data = ${JSON.stringify(data)}`);  
        })  
        .catch((error: BusinessError) => {  
            console.error(`promise: getKeyItemProperties failed`);  
        });  
} catch (error) {  
    console.error(`promise: getKeyItemProperties input arg invalid`);  
}  
    
```    
  
    
## isKeyExist<sup>(deprecated)</sup>    
判断密钥是否存在，使用Callback回调异步返回结果 。  
 **调用形式：**     
- isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.isKeyItemExist。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 所需查找的密钥的别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 空对象（此处传空即可）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。false代表密钥不存在，true代表密钥存在。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';/* 此处options选择emptyOptions来传空 */let keyAlias = 'keyAlias';let emptyOptions: huks.HuksOptions = {    properties: []};huks.isKeyExist(keyAlias, emptyOptions, (err, data) => {});    
```    
  
    
## isKeyExist<sup>(deprecated)</sup>    
判断密钥是否存在，使用Promise回调异步返回结果 。  
 **调用形式：**     
- isKeyExist(keyAlias: string, options: HuksOptions): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.isKeyItemExist。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | 所需查找的密钥的别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | 空对象（此处传空即可）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。false代表密钥不存在，true代表密钥存在。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';/* 此处options选择emptyOptions来传空 */let keyAlias = 'keyAlias';let emptyOptions: huks.HuksOptions = {    properties: []};let result = huks.isKeyExist(keyAlias, emptyOptions);    
```    
  
    
## isKeyItemExist<sup>(9+)</sup>    
判断密钥是否存在  
 **调用形式：**     
    
- isKeyItemExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isKeyItemExist(keyAlias: string, options: HuksOptions): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias | string | true | 所需查找的密钥的别名。 |  
| options | HuksOptions | true | 空对象（此处传空即可）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。若密钥存在，data为true，若密钥不存在，则error中会输出密钥不存在的error |  
| Promise<boolean> | Promise对象。密钥存在时，可通过then进行密钥存在后的相关处理，若不存在，可通过error处理密钥不存在后的相关业务操作。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | argument is invalid. |  
| 801 | api is not supported. |  
| 12000002 | algorithm param is missing. |  
| 12000003 | algorithm param is invalid. |  
| 12000004 | operating file failed. |  
| 12000005 | IPC communication failed. |  
| 12000006 | error occured in crypto engine. |  
| 12000012 | external error. |  
| 12000014 | memory is insufficient. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import huks from '@ohos.security.huks';  
import promptAction from '@ohos.promptAction';  
/* 此处options选择emptyOptions来传空 */  
let keyAlias = 'keyAlias';  
let emptyOptions: huks.HuksOptions = {  
    properties: []  
};  
huks.isKeyItemExist(keyAlias, emptyOptions, (error, data) => {  
    if (data) {  
        promptAction.showToast({  
            message: "keyAlias: " + keyAlias +"is existed！",  
            duration: 2500,  
        })  
    } else {  
        promptAction.showToast({  
            message: "find key failed",  
            duration: 2500,  
        })  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
import promptAction from '@ohos.promptAction';  
  
/* 此处options选择emptyOptions来传空 */  
let keyAlias = 'keyAlias';  
let emptyOptions: huks.HuksOptions = {  
    properties: []  
};  
huks.isKeyItemExist(keyAlias, emptyOptions).then((data) => {  
    promptAction.showToast({  
        message: "keyAlias: " + keyAlias +"is existed！",  
        duration: 500,  
    })  
}).catch((error: BusinessError)=>{  
    promptAction.showToast({  
        message: "find key failed",  
        duration: 6500,  
    })  
})  
    
```    
  
    
## init<sup>(deprecated)</sup>    
init操作密钥接口，使用Callback回调异步返回结果。huks.init, huks.update, huks.finish为三段式接口，需要一起使用。  
 **调用形式：**     
- init(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksHandle>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.initSession。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | Init操作密钥的别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | Init操作的参数集合。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<HuksHandle> | true | 回调函数。将Init操作操作返回的handle添加到密钥管理系统的回调。 |  
    
## init<sup>(deprecated)</sup>    
<span style="letter-spacing: 0px;">init操作密钥接口，使用Promise方式异步返回结果。huks.init, huks.update, huks.finish为三段式接口，需要一起使用。</span>  
  
 **调用形式：**     
- init(keyAlias: string, options: HuksOptions): Promise\<HuksHandle>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.initSession。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias<sup>(deprecated)</sup> | string | true | Init操作密钥的别名。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | Init参数集合。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<HuksHandle> | Promise对象。将Init操作返回的handle添加到密钥管理系统的回调。 |  
    
## initSession<sup>(9+)</sup>    
initSession操作密钥接口  
 **调用形式：**     
    
- initSession(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksSessionHandle>): void    
起始版本： 9    
- initSession(keyAlias: string, options: HuksOptions): Promise\<HuksSessionHandle>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias | string | true | initSession操作密钥的别名。 |  
| options | HuksOptions | true | initSession操作的参数集合。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。将initSession操作返回的handle添加到密钥管理系统的回调。 |  
| Promise<HuksSessionHandle> | Promise对象。将initSession操作返回的handle添加到密钥管理系统的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
    
## update<sup>(deprecated)</sup>    
update操作密钥接口，使用Callback回调异步返回结果。huks.init, huks.update, huks.finish为三段式接口，需要一起使用。  
 **调用形式：**     
- update(handle: number, token?: Uint8Array, options: HuksOptions, callback: AsyncCallback\<HuksResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.updateSession。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| handle<sup>(deprecated)</sup> | number | true | Update操作的handle。 |  
| token<sup>(deprecated)</sup> | Uint8Array | false | Update操作的token。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | Update操作的参数集合。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<HuksResult> | true | 回调函数。将Update操作的结果添加到密钥管理系统的回调。 |  
    
## update<sup>(deprecated)</sup>    
update操作密钥接口，使用Promise方式异步返回结果。huks.init, huks.update, huks.finish为三段式接口，需要一起使用。  
 **调用形式：**     
- update(handle: number, token?: Uint8Array, options: HuksOptions): Promise\<HuksResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.updateSession。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| handle<sup>(deprecated)</sup> | number | true | Update操作的handle。 |  
| token<sup>(deprecated)</sup> | Uint8Array | false | Update操作的token。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | Update操作的参数集合。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<HuksResult> | Promise对象。将Update操作的结果添加到密钥管理系统的回调。 |  
    
## updateSession<sup>(9+)</sup>    
updateSession操作密钥接口。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。  
 **调用形式：**     
    
- updateSession(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>): void    
起始版本： 9    
- updateSession(    handle: number,    options: HuksOptions,    token: Uint8Array,    callback: AsyncCallback\<HuksReturnResult>  ): void    
起始版本： 9    
- updateSession(handle: number, options: HuksOptions, token?: Uint8Array): Promise\<HuksReturnResult>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| handle | number | true | updateSession操作的handle。 |  
| options | HuksOptions | true | updateSession的参数集合。 |  
| token | Uint8Array | true | updateSession操作的token。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。将updateSession操作的结果添加到密钥管理系统的回调。 |  
| Promise<HuksReturnResult> | Promise对象。将updateSession操作的结果添加到密钥管理系统的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
    
## finish<sup>(deprecated)</sup>    
finish操作密钥接口，使用Callback回调异步返回结果。huks.init, huks.update, huks.finish为三段式接口，需要一起使用。  
 **调用形式：**     
- finish(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.finishSession。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| handle<sup>(deprecated)</sup> | number | true | Finish操作的handle。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | Finish的参数集合。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<HuksResult> | true | 回调函数。将Finish操作的结果添加到密钥管理系统的回调。 |  
    
## finish<sup>(deprecated)</sup>    
  
finish操作密钥接口，使用Promise方式异步返回结果。huks.init, huks.update, huks.finish为三段式接口，需要一起使用。  
 **调用形式：**     
- finish(handle: number, options: HuksOptions): Promise\<HuksResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.finishSession。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| handle<sup>(deprecated)</sup> | number | true | Finish操作的handle。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | Finish操作的参数集合。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<HuksResult> | Promise对象，用于获取异步返回结果。 |  
    
## finishSession<sup>(9+)</sup>    
finishSession操作密钥接口。huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。  
 **调用形式：**     
    
- finishSession(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>): void    
起始版本： 9    
- finishSession(    handle: number,    options: HuksOptions,    token: Uint8Array,    callback: AsyncCallback\<HuksReturnResult>  ): void    
起始版本： 9    
- finishSession(handle: number, options: HuksOptions, token?: Uint8Array): Promise\<HuksReturnResult>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| handle | number | true | finishSession操作的handle。 |  
| options | HuksOptions | true | finishSession的参数集合。 |  
| token | Uint8Array | true | finishSession操作的token。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。将finishSession操作的结果添加到密钥管理系统的回调。 |  
| Promise<HuksReturnResult> | Promise对象，用于获取异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | argument is invalid. |  
| 801 | api is not supported |  
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
    
## abort<sup>(deprecated)</sup>    
abort操作密钥接口，使用Callback回调异步返回结果。  
 **调用形式：**     
- abort(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.abortSession。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| handle<sup>(deprecated)</sup> | number | true | Abort操作的handle。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | Abort操作的参数集合。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<HuksResult> | true | 回调函数。将Abort操作的结果添加到密钥管理系统的回调。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
/* huks.init, huks.update, huks.finish为三段式接口，需要一起使用，当huks.init和huks.update  
 * 以及huks.finish操作中的任一阶段发生错误时，都需要调用huks.abort来终止密钥的使用。  
 *  
 * 以下以RSA1024密钥的callback操作使用为例  
 */  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose |  
    huks.HuksKeyDigest | huks.HuksKeyPadding = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
let keyalias = "HuksDemoRSA";  
let properties: HuksProperties[] = [];  
let options: huks.HuksOptions = {  
    properties: properties,  
    inData: new Uint8Array(0)  
};  
let handle: number = 0;  
let resultMessage = "";  
async function generateKey() {  
    properties[0] = {  
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
        value: huks.HuksKeyAlg.HUKS_ALG_RSA  
    };  
    properties[1] = {  
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_1024  
    };  
    properties[2] = {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT  
    };  
    properties[3] = {  
        tag: huks.HuksTag.HUKS_TAG_PADDING,  
        value: huks.HuksKeyPadding.HUKS_PADDING_OAEP  
    };  
    properties[4] = {  
        tag: huks.HuksTag.HUKS_TAG_DIGEST,  
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
    };  
    huks.generateKey(keyalias, options);  
}  
function stringToUint8Array(str: string) {  
    let arr: number[] = [];  
    for (let i = 0, j = str.length; i < j; ++i) {  
        arr.push(str.charCodeAt(i));  
    }  
    let tmpUint8Array = new Uint8Array(arr);  
    return tmpUint8Array;  
}  
async function huksInit() {  
    await huks.init(keyalias, options).then((data) => {  
        console.log(`test init data: ${JSON.stringify(data)}`);  
        handle = data.handle;  
    }).catch((err: BusinessError) => {  
        console.log("test init err information: " + JSON.stringify(err))  
    })  
}  
async function huksUpdate() {  
    options.inData = stringToUint8Array("huksHmacTest");  
    await huks.update(handle, options.inData, options).then((data) => {  
        if (data.errorCode === 0) {  
            resultMessage += "update success!";  
        } else {  
            resultMessage += "update fail!";  
        }  
    });  
    console.log(resultMessage);  
}  
function huksFinish() {  
    options.inData = stringToUint8Array("HuksDemoHMAC");  
    huks.finish(handle, options).then((data) => {  
        if (data.errorCode === 0) {  
            resultMessage = "finish success!";  
        } else {  
            resultMessage = "finish fail errorCode: " + data.errorCode;  
        }  
    }).catch((err: BusinessError) => {  
        resultMessage = "finish fail， catch errorMessage:" + JSON.stringify(err)  
    });  
    console.log(resultMessage);  
}  
async function huksAbort() {  
    new Promise<huks.HuksResult>((resolve, reject) => {  
        huks.abort(handle, options, (err, data) => {  
            console.log(`Huks_Demo hmac huksAbort1 data ${JSON.stringify(data)}`);  
            console.log(`Huks_Demo hmac huksAbort1 err ${JSON.stringify(err)}`);  
        });  
    });  
}  
    
```    
  
    
## abort<sup>(deprecated)</sup>    
。  
 **调用形式：**     
- abort(handle: number, options: HuksOptions): Promise\<HuksResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.security.huks.abortSession。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| handle<sup>(deprecated)</sup> | number | true | Abort操作的handle。 |  
| options<sup>(deprecated)</sup> | HuksOptions | true | Abort操作的参数集合。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<HuksResult> | Promise对象。将Abort操作的结果添加到密钥管理系统的回调。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
/* huks.init, huks.update, huks.finish为三段式接口，需要一起使用，当huks.init和huks.update  
 * 以及huks.finish操作中的任一阶段发生错误时，都需要调用huks.abort来终止密钥的使用。  
 *  
 * 以下以RSA1024密钥的promise操作使用为例  
 */  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose |  
    huks.HuksKeyPadding | huks.HuksKeyDigest = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
let keyalias = "HuksDemoRSA";  
let properties: HuksProperties[] = [];  
let options: huks.HuksOptions = {  
    properties: properties,  
    inData: new Uint8Array(0)  
};  
let handle: number = 0;  
let resultMessage = "";  
  
function stringToUint8Array(str: string) {  
    let arr: number[] = [];  
    for (let i = 0, j = str.length; i < j; ++i) {  
        arr.push(str.charCodeAt(i));  
    }  
    let tmpUint8Array = new Uint8Array(arr);  
    return tmpUint8Array;  
}  
  
async function generateKey() {  
    properties[0] = {  
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
        value: huks.HuksKeyAlg.HUKS_ALG_RSA  
    };  
    properties[1] = {  
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_1024  
    };  
    properties[2] = {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT  
    };  
    properties[3] = {  
        tag: huks.HuksTag.HUKS_TAG_PADDING,  
        value: huks.HuksKeyPadding.HUKS_PADDING_OAEP  
    };  
    properties[4] = {  
        tag: huks.HuksTag.HUKS_TAG_DIGEST,  
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
    };  
    huks.generateKey(keyalias, options, (err, data) => {  
    });  
}  
  
async function huksInit() {  
    return new Promise<huks.HuksHandle>((resolve, reject) => {  
        huks.init(keyalias, options, async (err, data) => {  
            if (data.errorCode === 0) {  
                resultMessage = "init success!"  
                handle = data.handle;  
            } else {  
                resultMessage = "init fail errorCode: " + data.errorCode  
            }  
        });  
    });  
}  
  
async function huksUpdate() {  
    options.inData = stringToUint8Array("huksHmacTest");  
    new Promise<huks.HuksResult>((resolve, reject) => {  
        huks.update(handle, options.inData, options, (err, data) => {  
            if (data.errorCode === 0) {  
                resultMessage += "update success!";  
            } else {  
                resultMessage += "update fail!";  
            }  
        });  
    });  
    console.log(resultMessage);  
  
}  
  
async function huksFinish() {  
    options.inData = stringToUint8Array("0");  
    new Promise<huks.HuksResult>((resolve, reject) => {  
        huks.finish(handle, options, (err, data) => {  
            if (data.errorCode === 0) {  
                resultMessage = "finish success!";  
            } else {  
                resultMessage = "finish fail errorCode: " + data.errorCode;  
            }  
        });  
    });  
}  
  
function huksAbort() {  
    huks.abort(handle, options).then((data) => {  
        if (data.errorCode === 0) {  
            resultMessage = "abort success!";  
        } else {  
            resultMessage = "abort fail errorCode: " + data.errorCode;  
        }  
    }).catch((err: BusinessError) => {  
        resultMessage = "abort fail， catch errorMessage:" + JSON.stringify(err)  
    });  
    console.log(resultMessage);  
}  
    
```    
  
    
## abortSession<sup>(9+)</sup>    
abortSession操作密钥接口  
 **调用形式：**     
    
- abortSession(handle: number, options: HuksOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- abortSession(handle: number, options: HuksOptions): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| handle | number | true | v |  
| options | HuksOptions | true | abortSession操作的参数集合。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。将abortSession操作的结果添加到密钥管理系统的回调。 |  
| Promise<void> | Promise对象。将abortSession操作的结果添加到密钥管理系统的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | argument is invalid. |  
| 801 | api is not supported. |  
| 12000004 | operating file failed. |  
| 12000005 | IPC communication failed. |  
| 12000006 | error occured in crypto engine. |  
| 12000012 | external error. |  
| 12000014 | memory is insufficient. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import huks from '@ohos.security.huks';  
/* huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用，当  
 * huks.initSession和huks.updateSession  
 * 以及huks.finishSession操作中的任一阶段发生错误时，  
 * 都需要调用huks.abortSession来终止密钥的使用。  
 *  
 * 以下以RSA1024密钥的callback功能使用为例  
 */  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest |  
    huks.HuksKeyPadding | huks.HuksCipherMode = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
function stringToUint8Array(str: string) {  
    let arr: number[] = [];  
    for (let i = 0, j = str.length; i < j; ++i) {  
        arr.push(str.charCodeAt(i));  
    }  
    let tmpUint8Array = new Uint8Array(arr);  
    return tmpUint8Array;  
}  
let keyAlias = "HuksDemoRSA";  
let properties: HuksProperties[] = []  
let options: huks.HuksOptions = {  
    properties: properties,  
    inData: new Uint8Array(0)  
};  
let handle: number = 0;  
async function generateKey() {  
    properties[0] = {  
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
        value: huks.HuksKeyAlg.HUKS_ALG_RSA  
    };  
    properties[1] = {  
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_1024  
    };  
    properties[2] = {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT  
    };  
    properties[3] = {  
        tag: huks.HuksTag.HUKS_TAG_PADDING,  
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5  
    };  
    properties[4] = {  
        tag: huks.HuksTag.HUKS_TAG_DIGEST,  
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
    };  
    properties[5] = {  
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,  
        value: huks.HuksCipherMode.HUKS_MODE_ECB,  
    }  
    try {  
        await huks.generateKeyItem(keyAlias, options, (error, data) => {  
            if (error) {  
                console.error(`callback: generateKeyItem failed`);  
            } else {  
                console.info(`callback: generateKeyItem success`);  
            }  
        });  
    } catch (error) {  
        console.error(`callback: generateKeyItem input arg invalid`);  
    }  
}  
async function huksInit() {  
    console.log('enter huksInit');  
    try {  
        huks.initSession(keyAlias, options, (error, data) => {  
            if (error) {  
                console.error(`callback: initSession failed`);  
            } else {  
                console.info(`callback: initSession success, data = ${JSON.stringify(data)}`);  
                handle = data.handle;  
            }  
        });  
    } catch (error) {  
        console.error(`callback: initSession input arg invalid`);  
    }  
}  
async function huksUpdate() {  
    console.log('enter huksUpdate');  
    options.inData = stringToUint8Array("huksHmacTest");  
    try {  
        huks.updateSession(handle, options, (error, data) => {  
            if (error) {  
                console.error(`callback: updateSession failed`);  
            } else {  
                console.info(`callback: updateSession success, data = ${JSON.stringify(data)}`);  
            }  
        });  
    } catch (error) {  
        console.error(`callback: updateSession input arg invalid`);  
    }  
}  
async function huksFinish() {  
    console.log('enter huksFinish');  
    options.inData = new Uint8Array(0);  
    try {  
        huks.finishSession(handle, options, (error, data) => {  
            if (error) {  
                console.error(`callback: finishSession failed`);  
            } else {  
                console.info(`callback: finishSession success, data = ${JSON.stringify(data)}`);  
            }  
        });  
    } catch (error) {  
        console.error(`callback: finishSession input arg invalid`);  
    }  
}  
async function huksAbort() {  
    console.log('enter huksAbort');  
    try {  
        huks.abortSession(handle, options, (error, data) => {  
            if (error) {  
                console.error(`callback: abortSession failed`);  
            } else {  
                console.info(`callback: abortSession success`);  
            }  
        });  
    } catch (error) {  
        console.error(`callback: abortSession input arg invalid`);  
    }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
/* huks.initSession, huks.updateSession, huks.finishSession为三段式接口，需要一起使用，当  
 * huks.initSession和huks.updateSession  
 * 以及huks.finishSession操作中的任一阶段发生错误时，  
 * 都需要调用huks.abortSession来终止密钥的使用。  
 *  
 * 以下以RSA1024密钥的callback功能使用为例  
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
  
let keyAlias = "HuksDemoRSA";  
let properties: HuksProperties[] = []  
let options: huks.HuksOptions = {  
    properties: properties,  
    inData: new Uint8Array(0)  
};  
let handle: number = 0;  
  
async function generateKey() {  
    properties[0] = {  
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
        value: huks.HuksKeyAlg.HUKS_ALG_RSA  
    };  
    properties[1] = {  
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_1024  
    };  
    properties[2] = {  
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT  
    };  
    properties[3] = {  
        tag: huks.HuksTag.HUKS_TAG_PADDING,  
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5  
    };  
    properties[4] = {  
        tag: huks.HuksTag.HUKS_TAG_DIGEST,  
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
    };  
    properties[5] = {  
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,  
        value: huks.HuksCipherMode.HUKS_MODE_ECB,  
    }  
  
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
    
```    
  
    
## attestKeyItem<sup>(9+)</sup>    
获取密钥证书  
 **调用形式：**     
    
- attestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>): void    
起始版本： 9    
- attestKeyItem(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyAlias | string | true | 密钥别名，存放待获取证书密钥的别名。 |  
| options | HuksOptions | true | 用于获取证书时指定所需参数与数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不返回err值时表示接口使用成功，其他时为错误。 |  
| Promise<HuksReturnResult> | Promise对象。不返回err值时表示接口使用成功，其他时为错误。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | check permission failed. |  
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
| 12000014 | memory is insufficient. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import huks from '@ohos.security.huks';  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest |  
    huks.HuksKeyStorageType | huks.HuksKeyPadding | huks.HuksKeyGenerateType |  
    huks.HuksCipherMode | Uint8Array = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
let securityLevel = stringToUint8Array('sec_level');  
let challenge = stringToUint8Array('challenge_data');  
let versionInfo = stringToUint8Array('version_info');  
let keyAliasString = "key attest";  
function stringToUint8Array(str: string) {  
    let arr: number[] = [];  
    for (let i = 0, j = str.length; i < j; ++i) {  
        arr.push(str.charCodeAt(i));  
    }  
    let tmpUint8Array = new Uint8Array(arr);  
    return tmpUint8Array;  
}  
  
async function generateKeyThenattestKey(alias: string) {  
    let aliasString = keyAliasString;  
    let aliasUint8 = stringToUint8Array(aliasString);  
    let generateProperties: HuksProperties[] = [  
        {  
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
            value: huks.HuksKeyAlg.HUKS_ALG_RSA  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,  
            value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
            value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_DIGEST,  
            value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_PADDING,  
            value: huks.HuksKeyPadding.HUKS_PADDING_PSS  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_KEY_GENERATE_TYPE,  
            value: huks.HuksKeyGenerateType.HUKS_KEY_GENERATE_TYPE_DEFAULT  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,  
            value: huks.HuksCipherMode.HUKS_MODE_ECB  
        }  
    ];  
    let generateOptions: huks.HuksOptions = {  
        properties: generateProperties  
    };  
    let attestProperties: HuksProperties[] = [  
        {  
            tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,  
            value: securityLevel  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,  
            value: challenge  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,  
            value: versionInfo  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,  
            value: aliasUint8  
        }  
    ];  
    let attestOptions: huks.HuksOptions = {  
        properties: attestProperties  
    };  
    try {  
        huks.generateKeyItem(alias, generateOptions, (error, data) => {  
            if (error) {  
                console.error(`callback: generateKeyItem failed`);  
            } else {  
                console.info(`callback: generateKeyItem success`);  
                try {  
                    huks.attestKeyItem(aliasString, attestOptions, (error, data) => {  
                        if (error) {  
                            console.error(`callback: attestKeyItem failed`);  
                        } else {  
                            console.info(`callback: attestKeyItem success`);  
                        }  
                    });  
                } catch (error) {  
                    console.error(`callback: attestKeyItem input arg invalid`);  
                }  
            }  
        });  
    } catch (error) {  
        console.error(`callback: generateKeyItem input arg invalid`);  
    }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import huks from '@ohos.security.huks';  
import { BusinessError } from '@ohos.base';  
class HuksProperties {  
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM  
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest |  
    huks.HuksKeyStorageType | huks.HuksKeyPadding | huks.HuksKeyGenerateType |  
    huks.HuksCipherMode | Uint8Array = huks.HuksKeyAlg.HUKS_ALG_ECC  
}  
let securityLevel = stringToUint8Array('sec_level');  
let challenge = stringToUint8Array('challenge_data');  
let versionInfo = stringToUint8Array('version_info');  
let keyAliasString = "key attest";  
function stringToUint8Array(str: string) {  
    let arr: number[] = [];  
    for (let i = 0, j = str.length; i < j; ++i) {  
        arr.push(str.charCodeAt(i));  
    }  
    let tmpUint8Array = new Uint8Array(arr);  
    return tmpUint8Array;  
}  
async function generateKey(alias: string) {  
    let properties: HuksProperties[] = [  
        {  
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,  
            value: huks.HuksKeyAlg.HUKS_ALG_RSA  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,  
            value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,  
            value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,  
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_DIGEST,  
            value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_PADDING,  
            value: huks.HuksKeyPadding.HUKS_PADDING_PSS  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_KEY_GENERATE_TYPE,  
            value: huks.HuksKeyGenerateType.HUKS_KEY_GENERATE_TYPE_DEFAULT  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,  
            value: huks.HuksCipherMode.HUKS_MODE_ECB  
        }  
    ];  
    let options: huks.HuksOptions = {  
        properties: properties  
    };  
    try {  
        await huks.generateKeyItem(alias, options)  
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
async function attestKey() {  
    let aliasString = keyAliasString;  
    let aliasUint8 = stringToUint8Array(aliasString);  
    let properties: HuksProperties[] = [  
        {  
            tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,  
            value: securityLevel  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,  
            value: challenge  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,  
            value: versionInfo  
        },  
        {  
            tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,  
            value: aliasUint8  
        }  
    ];  
    let options: huks.HuksOptions = {  
        properties: properties  
    };  
    await generateKey(aliasString);  
    try {  
        await huks.attestKeyItem(aliasString, options)  
            .then((data) => {  
                console.info(`promise: attestKeyItem success`);  
            })  
            .catch((error: BusinessError) => {  
                console.error(`promise: attestKeyItem failed`);  
            });  
    } catch (error) {  
        console.error(`promise: attestKeyItem input arg invalid`);  
    }  
}  
    
```    
  
    
## getSdkVersion    
获取当前系统sdk版本。  
 **调用形式：**     
- getSdkVersion(options: HuksOptions): string  
  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | HuksOptions | true | 空对象，用于存放sdk版本。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回sdk版本。 |  
    
 **示例代码：**   
```ts    
import huks from '@ohos.security.huks';/* 此处options选择emptyOptions传空 */let emptyOptions: huks.HuksOptions = {    properties: []};let result = huks.getSdkVersion(emptyOptions);    
```    
  
    
## HuksParam    
调用接口使用的options中的properties数组中的param。  
 **系统能力:**  SystemCapability.Security.Huks.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| tag | HuksTag | false | true | 标签。 |  
| value | boolean \| number \| bigint \| Uint8Array | false | true | 标签对应值。 |  
    
## HuksHandle<sup>(deprecated)</sup>    
huks Handle结构体。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.security.huks.HuksSessionHandle替代。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| errorCode | number | false | true | 表示错误码。 |  
| handle | number | false | true | 表示handle值。 |  
| token | Uint8Array | false | false | 表示[init](#huksinitdeprecated)操作之后获取到的challenge信息。 |  
    
## HuksSessionHandle<sup>(9+)</sup>    
huks Handle结构体。  
 **系统能力:**  SystemCapability.Security.Huks.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| handle | number | false | true | 表示handle值。 |  
| challenge | Uint8Array | false | false | 表示[initSession](#huksinitsession9)操作之后获取到的challenge信息。 |  
    
## HuksOptions    
调用接口使用的options。  
 **系统能力:**  SystemCapability.Security.Huks.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| properties | Array<HuksParam> | false | false | 属性，用于存HuksParam的数组。 |  
| inData | Uint8Array | false | false | 输入数据。 |  
    
## HuksResult<sup>(deprecated)</sup>    
调用接口返回的result。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.security.huks.HuksReturnResult替代。  
 **系统能力:**  SystemCapability.Security.Huks.Extension    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| errorCode | number | false | true | 表示错误码。 |  
| outData | Uint8Array | false | false | 表示输出数据。 |  
| properties | Array<HuksParam> | false | false | 表示属性信息。 |  
| certChains | Array<string> | false | false | 表示证书链数据。 |  
    
## HuksReturnResult<sup>(9+)</sup>    
调用接口返回的result。  
 **系统能力:**  SystemCapability.Security.Huks.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| outData | Uint8Array | false | false | 表示输出数据。 |  
| properties | Array<HuksParam> | false | false | 表示属性信息。 |  
| certChains | Array<string> | false | false | 表示证书链数据。 |  
    
## HuksErrorCode<sup>(deprecated)</sup>    
表示错误码的枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.security.huks.HuksExceptionErrCode替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_SUCCESS | 0 | 表示成功。 |  
| HUKS_FAILURE | -1 | 表示失败。 |  
| HUKS_ERROR_BAD_STATE | -2 | 表示错误的状态。 |  
| HUKS_ERROR_INVALID_ARGUMENT | -3 | 表示无效的数据。 |  
| HUKS_ERROR_NOT_SUPPORTED | -4 | 表示不支持。 |  
| HUKS_ERROR_NO_PERMISSION | -5 | 表示没有许可。 |  
| HUKS_ERROR_INSUFFICIENT_DATA | -6 | 表示数据不足。 |  
| HUKS_ERROR_BUFFER_TOO_SMALL | -7 | 表示缓冲区太小。<span style="letter-spacing: 0px;">表示缓冲区太小。</span> |  
| HUKS_ERROR_INSUFFICIENT_MEMORY | -8 | 表示内存不足。 |  
| HUKS_ERROR_COMMUNICATION_FAILURE | -9 | 表示通讯失败。 |  
| HUKS_ERROR_STORAGE_FAILURE | -10 | 表示存储故障。 |  
| HUKS_ERROR_HARDWARE_FAILURE | -11 | 表示硬件故障。 |  
| HUKS_ERROR_ALREADY_EXISTS | -12 | 表示已经存在。 |  
| HUKS_ERROR_NOT_EXIST | -13 |  |  
| HUKS_ERROR_NULL_POINTER | -14 | 表示空指针。 |  
| HUKS_ERROR_FILE_SIZE_FAIL | -15 | 表示文件大小失败。 |  
| HUKS_ERROR_READ_FILE_FAIL | -16 | 表示读取文件失败。 |  
| HUKS_ERROR_INVALID_PUBLIC_KEY | -17 | 表示无效的公钥。 |  
| HUKS_ERROR_INVALID_PRIVATE_KEY | -18 | 表示无效的私钥。 |  
| HUKS_ERROR_INVALID_KEY_INFO | -19 | 表示无效的密钥信息。 |  
| HUKS_ERROR_HASH_NOT_EQUAL | -20 | 表示哈希不相等。 |  
| HUKS_ERROR_MALLOC_FAIL | -21 | 表示MALLOC 失败。 |  
| HUKS_ERROR_WRITE_FILE_FAIL | -22 | 表示写文件失败。 |  
| HUKS_ERROR_REMOVE_FILE_FAIL | -23 | 表示删除文件失败。 |  
| HUKS_ERROR_OPEN_FILE_FAIL | -24 | 表示打开文件失败。 |  
| HUKS_ERROR_CLOSE_FILE_FAIL | -25 | 表示关闭文件失败。 |  
| HUKS_ERROR_MAKE_DIR_FAIL | -26 | 表示创建目录失败。 |  
| HUKS_ERROR_INVALID_KEY_FILE | -27 | 表示无效的密钥文件。 |  
| HUKS_ERROR_IPC_MSG_FAIL | -28 | 表示IPC 信息失败。 |  
| HUKS_ERROR_REQUEST_OVERFLOWS | -29 | 表示请求溢出。 |  
| HUKS_ERROR_PARAM_NOT_EXIST | -30 | 表示参数不存在。 |  
| HUKS_ERROR_CRYPTO_ENGINE_ERROR | -31 | 表示CRYPTO ENGINE错误。 |  
| HUKS_ERROR_COMMUNICATION_TIMEOUT | -32 | 表示通讯超时。 |  
| HUKS_ERROR_IPC_INIT_FAIL | -33 | 表示IPC 初始化失败。 |  
| HUKS_ERROR_IPC_DLOPEN_FAIL | -34 | 表示IPC DLOPEN 失败。 |  
| HUKS_ERROR_EFUSE_READ_FAIL | -35 | 表示EFUSE 读取失败。 |  
| HUKS_ERROR_NEW_ROOT_KEY_MATERIAL_EXIST | -36 | 表示存在新的根密钥材料。 |  
| HUKS_ERROR_UPDATE_ROOT_KEY_MATERIAL_FAIL | -37 | 表示更新根密钥材料失败。 |  
| HUKS_ERROR_VERIFICATION_FAILED | -38 | 表示验证证书链失败。 |  
| HUKS_ERROR_CHECK_GET_ALG_FAIL | -100 | 表示检查获取 ALG 失败。 |  
| HUKS_ERROR_CHECK_GET_KEY_SIZE_FAIL | -101 | 表示检查获取密钥大小失败。 |  
| HUKS_ERROR_CHECK_GET_PADDING_FAIL | -102 | 表示检查获取填充失败。 |  
| HUKS_ERROR_CHECK_GET_PURPOSE_FAIL | -103 | 表示检查获取目的失败。 |  
| HUKS_ERROR_CHECK_GET_DIGEST_FAIL | -104 | 表示检查获取摘要失败。 |  
| HUKS_ERROR_CHECK_GET_MODE_FAIL | -105 | 表示检查获取模式失败。 |  
| HUKS_ERROR_CHECK_GET_NONCE_FAIL | -106 | 表示检查获取随机数失败。 |  
| HUKS_ERROR_CHECK_GET_AAD_FAIL | -107 | 表示检查获取 AAD 失败。 |  
| HUKS_ERROR_CHECK_GET_IV_FAIL | -108 | 表示检查 GET IV 失败。 |  
| HUKS_ERROR_CHECK_GET_AE_TAG_FAIL | -109 | 表示检查获取 AE 标记失败。 |  
| HUKS_ERROR_CHECK_GET_SALT_FAIL | -110 | |表示检查获取SALT失败。 |  
| HUKS_ERROR_CHECK_GET_ITERATION_FAIL | -111 | 表示检查获取迭代失败。 |  
| HUKS_ERROR_INVALID_ALGORITHM | -112 | 表示无效的算法。 |  
| HUKS_ERROR_INVALID_KEY_SIZE | -113 | 表示无效的密钥大小。 |  
| HUKS_ERROR_INVALID_PADDING | -114 | 表示无效的填充。 |  
| HUKS_ERROR_INVALID_PURPOSE | -115 | 表示无效的目的。 |  
| HUKS_ERROR_INVALID_MODE | -116 | 表示无效模式。 |  
| HUKS_ERROR_INVALID_DIGEST | -117 | 表示无效的摘要。 |  
| HUKS_ERROR_INVALID_SIGNATURE_SIZE | -118 | 表示签名大小无效。 |  
| HUKS_ERROR_INVALID_IV | -119 | 表示无效的 IV。 |  
| HUKS_ERROR_INVALID_AAD | -120 | 表示无效的 AAD。 |  
| HUKS_ERROR_INVALID_NONCE | -121 | 表示无效的随机数。 |  
| HUKS_ERROR_INVALID_AE_TAG | -122 | 表示无效的 AE 标签。 |  
| HUKS_ERROR_INVALID_SALT | -123 | 表示无效SALT。 |  
| HUKS_ERROR_INVALID_ITERATION | -124 | 表示无效的迭代。 |  
| HUKS_ERROR_INVALID_OPERATION | -125 | 表示无效操作。<span style="letter-spacing: 0px;">表示内部错误。</span> |  
| HUKS_ERROR_INTERNAL_ERROR | -999 |  |  
| HUKS_ERROR_UNKNOWN_ERROR | -1000 | 表示未知错误。 |  
    
## HuksExceptionErrCode<sup>(9+)</sup>    
表示错误码的枚举以及对应的错误信息， 错误码表示错误类型，错误信息展示错误详情。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_ERR_CODE_PERMISSION_FAIL | 201 | 权限错误导致失败。 |  
| HUKS_ERR_CODE_ILLEGAL_ARGUMENT | 401 | 参数错误导致失败。 |  
| HUKS_ERR_CODE_NOT_SUPPORTED_API | 801 | 不支持的API。 |  
| HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED | 12000001 | 不支持的功能/特性。 |  
| HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT | 12000002 | 缺少密钥算法参数。 |  
| HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT | 12000003 | 无效密钥算法参数。 |  
| HUKS_ERR_CODE_FILE_OPERATION_FAIL | 12000004 | 文件操作失败。 |  
| HUKS_ERR_CODE_COMMUNICATION_FAIL | 12000005 | 通信失败。 |  
| HUKS_ERR_CODE_CRYPTO_FAIL | 12000006 | 算法库操作失败。 |  
| HUKS_ERR_CODE_KEY_AUTH_PERMANENTLY_INVALIDATED | 12000007 | 密钥访问失败-密钥访问失效。 |  
| HUKS_ERR_CODE_KEY_AUTH_VERIFY_FAILED | 12000008 | 密钥访问失败-密钥认证失败。 |  
| HUKS_ERR_CODE_KEY_AUTH_TIME_OUT | 12000009 | 密钥访问失败-密钥访问超时。 |  
| HUKS_ERR_CODE_SESSION_LIMIT | 12000010 | 密钥操作会话数已达上限。 |  
| HUKS_ERR_CODE_ITEM_NOT_EXIST | 12000011 | 目标对象不存在。 |  
| HUKS_ERR_CODE_EXTERNAL_ERROR | 12000012 | 外部错误。 |  
| HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST | 12000013 | 缺失所需凭据。 |  
| HUKS_ERR_CODE_INSUFFICIENT_MEMORY | 12000014 | 内存不足。 |  
| HUKS_ERR_CODE_CALL_SERVICE_FAILED | 12000015 | 调用其他系统服务失败。 |  
    
## HuksKeyPurpose    
表示密钥用途。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_KEY_PURPOSE_ENCRYPT | 1 | 表示密钥用于对明文进行加密操作。 |  
| HUKS_KEY_PURPOSE_DECRYPT | 2 | 表示密钥用于对密文进行解密操作。 |  
| HUKS_KEY_PURPOSE_SIGN | 4 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥用于对数据进行签名。 |  
| HUKS_KEY_PURPOSE_VERIFY | 8 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥用于验证签名后的数据。 |  
| HUKS_KEY_PURPOSE_DERIVE | 16 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥用于派生密钥。 |  
| HUKS_KEY_PURPOSE_WRAP | 32 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥用于加密导出。 |  
| HUKS_KEY_PURPOSE_UNWRAP | 64 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥加密导入。 |  
| HUKS_KEY_PURPOSE_MAC | 128 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥用于生成mac消息验证码。 |  
| HUKS_KEY_PURPOSE_AGREE | 256 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥用于进行密钥协商。。 |  
    
## HuksKeyDigest    
表示摘要算法。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_DIGEST_NONE | 0 | 表示无摘要算法。 |  
| HUKS_DIGEST_MD5 | 1 | 表示MD5摘要算法。 |  
| HUKS_DIGEST_SM3<sup>(9+)</sup> | 2 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示SM3摘要算法。 |  
| HUKS_DIGEST_SHA1 | 10 | 表示SHA1摘要算法。 |  
| HUKS_DIGEST_SHA224 | 11 | 表示SHA224摘要算法。 |  
| HUKS_DIGEST_SHA256 | 12 | 表示SHA256摘要算法。 |  
| HUKS_DIGEST_SHA384 | 13 | 表示SHA384摘要算法。 |  
| HUKS_DIGEST_SHA512 | 14 | 表示SHA512摘要算法。 |  
    
## HuksKeyPadding    
表示补齐算法。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_PADDING_NONE | 0 | 表示不使用补齐算法。。 |  
| HUKS_PADDING_OAEP | 1 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用OAEP补齐算法。 <br> **系统能力：** SystemCapability.Security.Huks.Extension |  
| HUKS_PADDING_PSS | 2 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用PSS补齐算法。 <br> **系统能力：** SystemCapability.Security.Huks.Extension |  
| HUKS_PADDING_PKCS1_V1_5 | 3 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用PKCS1_V1_5补齐算法。 <br> **系统能力：** SystemCapability.Security.Huks.Extension |  
| HUKS_PADDING_PKCS5 | 4 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用PKCS5补齐算法。 |  
| HUKS_PADDING_PKCS7 | 5 | 表示使用PKCS7补齐算法。 |  
    
## HuksCipherMode    
表示加密模式。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_MODE_ECB | 1 | 表示使用ECB加密模式。 |  
| HUKS_MODE_CBC | 2 | 表示使用CBC加密模式。 |  
| HUKS_MODE_CTR | 3 | 表示使用CTR加密模式。 |  
| HUKS_MODE_OFB | 4 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用OFB加密模式。 |  
| HUKS_MODE_CCM | 31 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用CCM加密模式。 |  
| HUKS_MODE_GCM | 32 | 表示使用GCM加密模式。 |  
    
## HuksKeySize    
表示密钥长度。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_RSA_KEY_SIZE_512 | 512 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用RSA算法的密钥长度为512bit。 |  
| HUKS_RSA_KEY_SIZE_768 | 768 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用RSA算法的密钥长度为768bit。 |  
| HUKS_RSA_KEY_SIZE_1024 | 1024 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用RSA算法的密钥长度为1024bit。 |  
| HUKS_RSA_KEY_SIZE_2048 | 2048 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用RSA算法的密钥长度为2048bit。 |  
| HUKS_RSA_KEY_SIZE_3072 | 3072 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用RSA算法的密钥长度为3072bit。 |  
| HUKS_RSA_KEY_SIZE_4096 | 4096 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用RSA算法的密钥长度为4096bit。 |  
| HUKS_ECC_KEY_SIZE_224 | 224 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用ECC算法的密钥长度为224bit。 |  
| HUKS_ECC_KEY_SIZE_256 | 256 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用ECC算法的密钥长度为256bit。 |  
| HUKS_ECC_KEY_SIZE_384 | 384 | 系统能力：SystemCapability.Security.Huks.Extension |  
| HUKS_ECC_KEY_SIZE_521 | 521 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用ECC算法的密钥长度为521bit。 |  
| HUKS_AES_KEY_SIZE_128 | 128 | 表示使用AES算法的密钥长度为128bit。 |  
| HUKS_AES_KEY_SIZE_192 | 192 | 表示使用AES算法的密钥长度为192bit。 |  
| HUKS_AES_KEY_SIZE_256 | 256 | 表示使用AES算法的密钥长度为256bit。 |  
| HUKS_AES_KEY_SIZE_512 | 512 | 表示使用AES算法的密钥长度为512bit。 |  
| HUKS_CURVE25519_KEY_SIZE_256 | 256 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用CURVE25519算法的密钥长度为256bit。 |  
| HUKS_DH_KEY_SIZE_2048 | 2048 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用DH算法的密钥长度为2048bit。 |  
| HUKS_DH_KEY_SIZE_3072 | 3072 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用DH算法的密钥长度为3072bit。 |  
| HUKS_DH_KEY_SIZE_4096 | 4096 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用DH算法的密钥长度为4096bit。 |  
| HUKS_SM2_KEY_SIZE_256<sup>(9+)</sup> | 256 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示SM2算法的密钥长度为256bit。 |  
| HUKS_SM4_KEY_SIZE_128<sup>(9+)</sup> | 128 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示SM4算法的密钥长度为128bit。 |  
    
## HuksKeyAlg    
表示密钥使用的算法。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_ALG_RSA | 1 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用RSA算法。 |  
| HUKS_ALG_ECC | 2 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用ECC算法。 |  
| HUKS_ALG_DSA | 3 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用DSA算法。 |  
| HUKS_ALG_AES | 20 | 表示使用AES算法。 |  
| HUKS_ALG_HMAC | 50 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用HMAC算法。 |  
| HUKS_ALG_HKDF | 51 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用HKDF算法。 |  
| HUKS_ALG_PBKDF2 | 52 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用PBKDF2算法。 |  
| HUKS_ALG_ECDH | 100 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用ECDH算法。 |  
| HUKS_ALG_X25519 | 101 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用X25519算法。 |  
| HUKS_ALG_ED25519 | 102 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用ED25519算法。 |  
| HUKS_ALG_DH | 103 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用DH算法。 |  
| HUKS_ALG_SM2<sup>(9+)</sup> | 150 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用SM2算法。 |  
| HUKS_ALG_SM3<sup>(9+)</sup> | 151 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用SM3算法。 |  
| HUKS_ALG_SM4<sup>(9+)</sup> | 152 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示使用SM4算法。 |  
    
## HuksUnwrapSuite<sup>(9+)</sup>    
表示导入加密密钥的算法套件。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING | 1 | 导入加密密钥时，X25519密钥协商后使用AES-256 GCM加密 |  
| HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING | 2 | 导入加密密钥时，ECDH密钥协商后使用AES-256 GCM加密。 |  
    
## HuksKeyGenerateType    
表示生成密钥的类型。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_KEY_GENERATE_TYPE_DEFAULT | 0 | 默认生成的密钥。 |  
| HUKS_KEY_GENERATE_TYPE_DERIVE | 1 | 派生生成的密钥。 |  
| HUKS_KEY_GENERATE_TYPE_AGREE | 2 | 协商生成的密钥。 |  
    
## HuksKeyFlag    
表示密钥的产生方式。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_KEY_FLAG_IMPORT_KEY | 1 | 表示通过导入公钥接口导入的密钥。 |  
| HUKS_KEY_FLAG_GENERATE_KEY | 2 | 表示通过生成密钥接口生成的密钥。 |  
| HUKS_KEY_FLAG_AGREE_KEY | 3 | 表示通过生成密钥协商接口生成的密钥。 |  
| HUKS_KEY_FLAG_DERIVE_KEY | 4 | 表示通过生成密钥派生接口生成的密钥。 |  
    
## HuksKeyStorageType    
表示密钥存储方式。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_STORAGE_TEMP<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 10 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>表示通过本地直接管理密钥。 |  
| HUKS_STORAGE_PERSISTENT<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 10 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>表示通过HUKS service管理密钥。 |  
| HUKS_STORAGE_ONLY_USED_IN_HUKS<sup>(10+)</sup> | 2 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示主密钥派生的密钥存储于huks中，由HUKS进行托管。 |  
| HUKS_STORAGE_KEY_EXPORT_ALLOWED<sup>(10+)</sup> | 3 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示主密钥派生的密钥直接导出给业务方，HUKS不对其进行托管服务。 |  
    
## HuksImportKeyType<sup>(9+)</sup>    
表示导入密钥的密钥类型，默认为导入公钥，导入对称密钥时不需要该字段。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_KEY_TYPE_PUBLIC_KEY | 0 | 表示导入的密钥类型为公钥。 |  
| HUKS_KEY_TYPE_PRIVATE_KEY | 1 | 表示导入的密钥类型为私钥。 |  
| HUKS_KEY_TYPE_KEY_PAIR | 2 | 表示导入的密钥类型为公私钥对。 |  
    
## HuksRsaPssSaltLenType<sup>(10+)</sup>    
表示Rsa在签名验签、padding为pss时需指定的salt_len类型。    
    
 **系统能力:**  SystemCapability.Security.Huks.Extension    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_RSA_PSS_SALT_LEN_DIGEST | 0 | 表示以摘要长度设置salt_len。 |  
| HUKS_RSA_PSS_SALT_LEN_MAX | 1 | 表示以最大长度设置salt_len。 |  
    
## HuksUserAuthType<sup>(9+)</sup>    
表示用户认证类型。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_USER_AUTH_TYPE_FINGERPRINT | 1 << 0 | 表示用户认证类型为指纹。 |  
| HUKS_USER_AUTH_TYPE_FACE | 1 << 1 | 表示用户认证类型为人脸 |  
| HUKS_USER_AUTH_TYPE_PIN | 1 << 2 | 表示用户认证类型为PIN码。 |  
    
## HuksAuthAccessType<sup>(9+)</sup>    
表示安全访问控制类型。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_AUTH_ACCESS_INVALID_CLEAR_PASSWORD | 1 << 0 | 表示安全访问控制类型为清除密码后密钥无效。 |  
| HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL | 1 << 1 | 表示安全访问控制类型为新录入生物特征后密钥无效。 |  
| HUKS_AUTH_ACCESS_ALWAYS_VALID<sup>(11+)</sup> | 1 << 2 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示安全访问控制类型为该密钥总是有效。 |  
    
## HuksChallengeType<sup>(9+)</sup>    
表示密钥使用时生成challenge的类型。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_CHALLENGE_TYPE_NORMAL | 0 | 表示challenge为普通类型，默认32字节。 |  
| HUKS_CHALLENGE_TYPE_CUSTOM | 1 | 表示challenge为用户自定义类型。支持使用多个密钥仅一次认证。 |  
| HUKS_CHALLENGE_TYPE_NONE | 2 | 表示免challenge类型。 |  
    
## HuksChallengePosition<sup>(9+)</sup>    
表示challenge类型为用户自定义类型时，生成的challenge有效长度仅为8字节连续的数据，且仅支持4种位置 。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_CHALLENGE_POS_0 | 0 | 表示0~7字节为当前密钥的有效challenge。 |  
| HUKS_CHALLENGE_POS_1 | 1 | 表示8~15字节为当前密钥的有效challenge。 |  
| HUKS_CHALLENGE_POS_2 | 2 | 表示16~23字节为当前密钥的有效challenge。 |  
| HUKS_CHALLENGE_POS_3 | 3 | 表示24~31字节为当前密钥的有效challenge。 |  
    
## HuksSecureSignType<sup>(9+)</sup>    
表示生成或导入密钥时，指定该密钥的签名类型    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_SECURE_SIGN_WITH_AUTHINFO | 1 | 表示签名类型为携带认证信息。生成或导入密钥时指定该字段，则在使用密钥进行签名时，对待签名的数据添加认证信息后进行签名。 |  
    
## HuksSendType    
表示发送Tag的方式。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_SEND_TYPE_ASYNC | 0 | 表示异步发送TAG。 |  
| HUKS_SEND_TYPE_SYNC | 1 | 表示同步发送TAG。 |  
    
## HuksTagType    
表示Tag的数据类型。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_TAG_TYPE_INVALID | 0 << 28 | 表示非法的Tag类型。 |  
| HUKS_TAG_TYPE_INT | 1 << 28 | 表示该Tag的数据类型为int类型的number。 |  
| HUKS_TAG_TYPE_UINT | 2 << 28 | 表示该Tag的数据类型为uint类型的number。 |  
| HUKS_TAG_TYPE_ULONG | 3 << 28 | 表示该Tag的数据类型为uint类型的number。 |  
| HUKS_TAG_TYPE_BOOL | 4 << 28 | 表示该Tag的数据类型为boolean。 |  
| HUKS_TAG_TYPE_BYTES | 5 << 28 | 表示该Tag的数据类型为Uint8Array。 |  
    
## HuksTag    
表示调用参数的Tag。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HUKS_TAG_INVALID<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_INVALID | 0 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>表示非法的Tag。从API version 9开始废弃。 |  
| HUKS_TAG_ALGORITHM | HuksTagType.HUKS_TAG_TYPE_UINT | 1 | 表示算法的Tag。 |  
| HUKS_TAG_PURPOSE | HuksTagType.HUKS_TAG_TYPE_UINT | 2 | 表示密钥用途的Tag。 |  
| HUKS_TAG_KEY_SIZE | HuksTagType.HUKS_TAG_TYPE_UINT | 3 | 表示密钥长度的Tag。 |  
| HUKS_TAG_DIGEST | HuksTagType.HUKS_TAG_TYPE_UINT | 4 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示摘要算法的Tag。 |  
| HUKS_TAG_PADDING | HuksTagType.HUKS_TAG_TYPE_UINT | 5 | 表示补齐算法的Tag。 |  
| HUKS_TAG_BLOCK_MODE | HuksTagType.HUKS_TAG_TYPE_UINT | 6 | 表示加密模式的Tag。 |  
| HUKS_TAG_KEY_TYPE | HuksTagType.HUKS_TAG_TYPE_UINT | 7 | 表示密钥类型的Tag。 |  
| HUKS_TAG_ASSOCIATED_DATA | HuksTagType.HUKS_TAG_TYPE_BYTES | 8 | 表示附加身份验证数据的Tag。 |  
| HUKS_TAG_NONCE | HuksTagType.HUKS_TAG_TYPE_BYTES | 9 | 表示密钥加解密的字段。 |  
| HUKS_TAG_IV | HuksTagType.HUKS_TAG_TYPE_BYTES | 10 | 表示密钥初始化的向量。 |  
| HUKS_TAG_INFO | HuksTagType.HUKS_TAG_TYPE_BYTES | 11 | 表示密钥派生时的info。 |  
| HUKS_TAG_SALT | HuksTagType.HUKS_TAG_TYPE_BYTES | 12 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥派生时的盐值。 |  
| HUKS_TAG_PWD<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 13 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>表示密钥派生时的password。从API version 9开始废弃。 |  
| HUKS_TAG_ITERATION | HuksTagType.HUKS_TAG_TYPE_UINT | 14 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥派生时的迭代次数。 |  
| HUKS_TAG_KEY_GENERATE_TYPE | HuksTagType.HUKS_TAG_TYPE_UINT | 15 | 表示生成密钥类型的Tag。 |  
| HUKS_TAG_DERIVE_MAIN_KEY<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 16 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥派生时的主密钥。从API version 9开始废弃。 |  
| HUKS_TAG_DERIVE_FACTOR<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 17 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br><span style="letter-spacing: 0px;">表示密钥派生时的派生因子。从API version 9开始废弃。</span> |  
| HUKS_TAG_DERIVE_ALG<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 18 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥派生时的算法类型。从API version 9开始废弃。 |  
| HUKS_TAG_AGREE_ALG | HuksTagType.HUKS_TAG_TYPE_UINT | 19 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥协商时的算法类型。 |  
| HUKS_TAG_AGREE_PUBLIC_KEY_IS_KEY_ALIAS | HuksTagType.HUKS_TAG_TYPE_BOOL | 20 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥协商时的公钥别名。 |  
| HUKS_TAG_AGREE_PRIVATE_KEY_ALIAS | HuksTagType.HUKS_TAG_TYPE_BYTES | 21 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥协商时的私钥别名。 |  
| HUKS_TAG_AGREE_PUBLIC_KEY | HuksTagType.HUKS_TAG_TYPE_BYTES | 22 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥协商时的公钥。 |  
| HUKS_TAG_KEY_ALIAS | HuksTagType.HUKS_TAG_TYPE_BYTES | 23 | 表示密钥别名。 |  
| HUKS_TAG_DERIVE_KEY_SIZE | HuksTagType.HUKS_TAG_TYPE_UINT | 24 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示派生密钥的大小。 |  
| HUKS_TAG_IMPORT_KEY_TYPE<sup>(9+)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 25 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示导入的密钥类型。 |  
| HUKS_TAG_UNWRAP_ALGORITHM_SUITE<sup>(9+)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 26 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示导入加密密钥的套件。 |  
| HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG<sup>(10+)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 29 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示派生密钥/协商密钥的存储类型。 |  
| HUKS_TAG_RSA_PSS_SALT_LEN_TYPE<sup>(10+)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 30 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示rsa_pss_salt_length的类型。 |  
| HUKS_TAG_ACTIVE_DATETIME<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_ULONG | 201 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>原为证书业务预留字段，当前证书管理已独立，此字段废弃，不再预留。 |  
| HUKS_TAG_ORIGINATION_EXPIRE_DATETIME<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_ULONG | 202 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>原为证书业务预留字段，当前证书管理已独立，此字段废弃，不再预留。 |  
| HUKS_TAG_USAGE_EXPIRE_DATETIME<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_ULONG | 203 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>原为证书业务预留字段，当前证书管理已独立，此字段废弃，不再预留。 |  
| HUKS_TAG_CREATION_DATETIME<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_ULONG | 204 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>原为证书业务预留字段，当前证书管理已独立，此字段废弃，不再预留。 |  
| HUKS_TAG_ALL_USERS | HuksTagType.HUKS_TAG_TYPE_BOOL | 301 | 系统能力：SystemCapability.Security.Huks.Extension<br>预留 |  
| HUKS_TAG_USER_ID | HuksTagType.HUKS_TAG_TYPE_UINT | 302 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示当前密钥属于哪个userID |  
| HUKS_TAG_NO_AUTH_REQUIRED | HuksTagType.HUKS_TAG_TYPE_BOOL | 303 | 系统能力：SystemCapability.Security.Huks.Extension<br>预留。 |  
| HUKS_TAG_USER_AUTH_TYPE | HuksTagType.HUKS_TAG_TYPE_UINT | 304 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示用户认证类型。从[HuksUserAuthType](#huksuserauthtype9)中选择，需要与安全访问控制类型同时设置。支持同时指定两种用户认证类型，如：安全访问控制类型指定为HKS_SECURE_ACCESS_INVALID_NEW_BIO_ENROLL时，密钥访问认证类型可以指定以下三种： HKS_USER_AUTH_TYPE_FACE 、HKS_USER_AUTH_TYPE_FINGERPRINT、HKS_USER_AUTH_TYPE_FACE \| HKS_USER_AUTH_TYPE_FINGERPRINT |  
| HUKS_TAG_AUTH_TIMEOUT | HuksTagType.HUKS_TAG_TYPE_UINT | 305 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示authtoken单次有效期。 |  
| HUKS_TAG_AUTH_TOKEN | HuksTagType.HUKS_TAG_TYPE_BYTES | 306 | 系统能力：SystemCapability.Security.Huks.Extension<br>用于传入authToken的字段 |  
| HUKS_TAG_KEY_AUTH_ACCESS_TYPE<sup>(9+)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 307 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示安全访问控制类型。从[HuksAuthAccessType](#huksauthaccesstype9)中选择，需要和用户认证类型同时设置。 |  
| HUKS_TAG_KEY_SECURE_SIGN_TYPE<sup>(9+)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 308 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示生成或导入密钥时，指定该密钥的签名类型。 |  
| HUKS_TAG_CHALLENGE_TYPE<sup>(9+)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 309 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥使用时生成的challenge类型。从[HuksChallengeType](#hukschallengetype9)中选择 |  
| HUKS_TAG_CHALLENGE_POS<sup>(9+)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 310 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示challenge类型为用户自定义类型时，huks产生的challenge有效长度仅为8字节连续的数据。从[HuksChallengePosition](#hukschallengeposition9)中选择。 |  
| HUKS_TAG_KEY_AUTH_PURPOSE<sup>(10+)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 311 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥认证用途的tag |  
| HUKS_TAG_ATTESTATION_CHALLENGE | HuksTagType.HUKS_TAG_TYPE_BYTES | 501 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示attestation时的挑战值。 |  
| HUKS_TAG_ATTESTATION_APPLICATION_ID | HuksTagType.HUKS_TAG_TYPE_BYTES | 502 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示attestation时拥有该密钥的application的Id。 |  
| HUKS_TAG_ATTESTATION_ID_BRAND<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 503 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示设备的品牌。从API version 9开始废弃。 |  
| HUKS_TAG_ATTESTATION_ID_DEVICE<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 504 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br><span style="letter-spacing: 0px;">表示设备的设备ID。从API version 9开始废弃。</span> |  
| HUKS_TAG_ATTESTATION_ID_PRODUCT<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 505 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示设备的产品名。从API version 9开始废弃。  |  
| HUKS_TAG_ATTESTATION_ID_SERIAL<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 506 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示设备的SN号。从API version 9开始废弃。 |  
| HUKS_TAG_ATTESTATION_ID_IMEI<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 507 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示设备的IMEI号。从API version 9开始废弃。 |  
| HUKS_TAG_ATTESTATION_ID_MEID<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 508 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示设备的MEID号。从API version 9开始废弃。 |  
| HUKS_TAG_ATTESTATION_ID_MANUFACTURER<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 509 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示设备的制造商。从API version 9开始废弃。 |  
| HUKS_TAG_ATTESTATION_ID_MODEL<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 510 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示设备的型号。从API version 9开始废弃。 |  
| HUKS_TAG_ATTESTATION_ID_ALIAS | HuksTagType.HUKS_TAG_TYPE_BYTES | 511 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示attestation时的密钥别名。 |  
| HUKS_TAG_ATTESTATION_ID_SOCID<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 512 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示设备的SOCID。从API version 9开始废弃。 |  
| HUKS_TAG_ATTESTATION_ID_UDID<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 513 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示设备的UDID。从API version 9开始废弃。 |  
| HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO | HuksTagType.HUKS_TAG_TYPE_BYTES | 514 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示attestation时的安全凭据。 |  
| HUKS_TAG_ATTESTATION_ID_VERSION_INFO | HuksTagType.HUKS_TAG_TYPE_BYTES | 515 | 系统能力：SystemCapability.Security.Huks.Extension<br>表示attestation时的版本号。 |  
| HUKS_TAG_IS_KEY_ALIAS | HuksTagType.HUKS_TAG_TYPE_BOOL | 1001 |  <span style="letter-spacing: 0px;">表示是否使用生成key时传入的别名的Tag。</span><br/> |  
| HUKS_TAG_KEY_STORAGE_FLAG | HuksTagType.HUKS_TAG_TYPE_UINT | 1002 | 表示密钥存储方式的Tag。 |  
| HUKS_TAG_IS_ALLOWED_WRAP | HuksTagType.HUKS_TAG_TYPE_BOOL | 1003 | 系统能力：SystemCapability.Security.Huks.Extension<br>预留。 |  
| HUKS_TAG_KEY_WRAP_TYPE | HuksTagType.HUKS_TAG_TYPE_UINT | 1004 | 系统能力：SystemCapability.Security.Huks.Extension<br>预留。 |  
| HUKS_TAG_KEY_AUTH_ID | HuksTagType.HUKS_TAG_TYPE_BYTES | 1005 | 系统能力：SystemCapability.Security.Huks.Extension<br>预留。 |  
| HUKS_TAG_KEY_ROLE | HuksTagType.HUKS_TAG_TYPE_UINT | 1006 | 系统能力：SystemCapability.Security.Huks.Extension<br>预留。 |  
| HUKS_TAG_KEY_FLAG | HuksTagType.HUKS_TAG_TYPE_UINT | 1007 | 表示密钥标志的Tag。 |  
| HUKS_TAG_IS_ASYNCHRONIZED | HuksTagType.HUKS_TAG_TYPE_UINT | 1008 | 系统能力：SystemCapability.Security.Huks.Extension<br>预留。 |  
| HUKS_TAG_SECURE_KEY_ALIAS<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BOOL | 1009 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>原为预留字段，从API version 9开始废弃。 |  
| HUKS_TAG_SECURE_KEY_UUID<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 1010 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>原为预留字段，从API version 9开始废弃。 |  
| HUKS_TAG_KEY_DOMAIN | HuksTagType.HUKS_TAG_TYPE_UINT | 1011 | 预留。 |  
| HUKS_TAG_PROCESS_NAME<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 10001 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>表示进程名称的Tag。从API version 9开始废弃。 |  
| HUKS_TAG_PACKAGE_NAME<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_BYTES | 10002 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>原为预留字段，从API version 9开始废弃。 |  
| HUKS_TAG_ACCESS_TIME<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 10003 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>原为预留字段，从API version 9开始废弃。 |  
| HUKS_TAG_USES_TIME<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 10004 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>原为预留字段，从API version 9开始废弃。 |  
| HUKS_TAG_CRYPTO_CTX<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_ULONG | 10005 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>原为预留字段，从API version 9开始废弃。 |  
| HUKS_TAG_KEY | HuksTagType.HUKS_TAG_TYPE_BYTES | 10006 | 预留。 |  
| HUKS_TAG_KEY_VERSION<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 10007 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>表示密钥版本的Tag。从API version 9开始废弃。 |  
| HUKS_TAG_PAYLOAD_LEN<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 10008 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Extension<br>原为预留字段，从API version 9开始废弃。 |  
| HUKS_TAG_AE_TAG | HuksTagType.HUKS_TAG_TYPE_BYTES | 10009 | 用于传入GCM模式中的AEAD数据的字段。 |  
| HUKS_TAG_IS_KEY_HANDLE<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_ULONG | 10010 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>原为预留字段，从API version 9开始废弃。<br/> |  
| HUKS_TAG_OS_VERSION<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 10101 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>表示操作系统版本的Tag。从API version 9开始废弃。 |  
| HUKS_TAG_OS_PATCHLEVEL<sup>(deprecated)</sup> | HuksTagType.HUKS_TAG_TYPE_UINT | 10102 | 从API version 8 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.Security.Huks.Core<br>表示操作系统补丁级别的Tag。从API version 9开始废弃。 |  
| HUKS_TAG_SYMMETRIC_KEY_DATA | HuksTagType.HUKS_TAG_TYPE_BYTES | 20001 | 预留。 |  
| HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA | HuksTagType.HUKS_TAG_TYPE_BYTES | 20002 | 系统能力：SystemCapability.Security.Huks.Extension<br>预留。 |  
| HUKS_TAG_ASYMMETRIC_PRIVATE_KEY_DATA | HuksTagType.HUKS_TAG_TYPE_BYTES | 20003 | 系统能力：SystemCapability.Security.Huks.Extension<br>预留。 |  
