# HUKS开发指导

## 场景介绍

 HUKS（OpenHarmony Universal KeyStore，OpenHarmony通用密钥库系统）向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。HUKS所管理的密钥可以由应用导入或者由应用调用HUKS接口生成。 

## 基于JS的开发指导

1. 引入HUKS模块

   ```js
   import huks from '@ohos.security.huks'
   ```

2. 使用generateKey接口生成密钥。

   keyAlias为生成的密钥别名，options为生成密钥时使用到的参数，需根据具体需要到的算法设定options中的参数。

   generateKey接口会返回密钥的生成是否成功。

   ```js
   var alias = 'testAlias';
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_ECC
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_224
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[3] = {
     tag: huks.HuksTag.HUKS_TAG_DIGEST,
     value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
   };
   var options = {
     properties: properties
   }
   var resultA = huks.generateKey(alias, options);
   ```

3. 使用Init接口进行init操作。

   Alias为初始化密钥的别名，options为初始化密钥用的参数集合，需根据具体需要到的算法设定options中的参数。

   init接口会返回init操作是否成功。

   ```js
   var alias = 'test001'
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   huks.init(alias, options, function(err, data) {
       if (err.code !== 0) {
           console.log("test init err information: " + JSON.stringify(err));
       } else {
           console.log(`test init data: ${JSON.stringify(data)}`);
       }
   })
   ```

4. 使用Update接口进行update操作。

   handle为更新密钥的session id，options为更新密钥用的参数集合，需根据具体需要到的算法设定options中的参数。

   update接口会返回update操作是否成功。

   ```js
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   var result = huks.update(handle, options)
   ```

5. 使用Finish接口进行finish操作。

   handle为 结束密钥的session id，options为结束密钥用的参数集合，需根据具体需要到的算法设定options中的参数。

   finish接口会返回finish操作是否成功。

   ```js
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   var result = huks.finish(handle, options) 
   ```

## 基于ets的功能全集demo

### **密钥导入导出**

**功能定义：**

 可以使用 CNG 导入和导出 对称密钥和非对称密钥。 可以使用密钥导出和导入功能在计算机之间移动密钥。 

**测试流程**：1.生成密钥；2.导出密钥；3.导入密钥

**参数：** 

| 参数名            | 类型        | 必填 | 说明                     |
| ----------------- | ----------- | ---- | ------------------------ |
| srcKeyAlias       | string      | 是   | 生成密钥别名。           |
| srcKeyAliasSecond | string      | 是   | 导入密钥别名。           |
| HuksOptions       | HuksOptions | 是   | 用于存放生成key所需TAG。 |
| encryptOptions    | HuksOptions | 是   | 用于存放导入key所需TAG。 |

提示：参数类型可在docs\zh-cn\application-dev\reference\apis\js-apis-huks.md中查看

**示例：**

```ets
/* 以生成RSA512密钥为例 */
var srcKeyAlias = 'hukRsaKeyAlias';
var srcKeyAliasSecond = 'huksRsaKeyAliasSecond';

/* 集成生成密钥参数集 */
var properties = new Array();
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA,
}
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
}
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
}
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB,
}
properties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
}
properties[5] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
}
var HuksOptions = {
    properties: properties,
    inData: new Uint8Array(new Array())
}

/* 生成密钥 */
await huks.generateKey(srcKeyAlias, HuksOptions).then((data) => {
    console.info(`test generateKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test generateKey err information: ' + JSON.stringify(err));
});

/* 导出密钥 */
await huks.exportKey(srcKeyAlias, HuksOptions).then((data) => {
    console.info(`test ExportKey data: ${JSON.stringify(data)}`);
    exportKey = data.outData;
}).catch((err) => {
    console.info('test ImportKey err information: ' + JSON.stringify(err));
});

/* 集成导入密钥参数集
var propertiesEncrypt = new Array();
propertiesEncrypt[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA,
}
propertiesEncrypt[1] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
}
propertiesEncrypt[2] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
}
propertiesEncrypt[3] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB,
}
propertiesEncrypt[4] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
}
propertiesEncrypt[5] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
}
var encryptOptions = {
    properties: propertiesEncrypt,
    inData: new Uint8Array(new Array())
}

/* 导入密钥 */
encryptOptions.inData = exportKey;
await huks.importKey(srcKeyAliasSecond, encryptOptions).then((data) => {
    console.info(`test ImportKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test ImportKey err information: ' + JSON.stringify(err));;
});
```

### 密钥加解密

**功能定义：** 发送和接收数据的双方使用相同的或对称的密钥对明文进行加密解密运算的加密方法。

**测试流程**：1.生成密钥；2.密钥加密；3.密钥解密；4.对比解密数据与密钥数据是否一致

**参数：** 

| 参数名         | 类型        | 必填 | 说明                     |
| -------------- | ----------- | ---- | ------------------------ |
| srcKeyAlias    | string      | 是   | 密钥别名。               |
| HuksOptions    | HuksOptions | 是   | 用于存放生成key所需TAG。 |
| encryptOptions | HuksOptions | 是   | 用于存放加密key所需TAG。 |
| decryptOptions | HuksOptions | 是   | 用于存放解密key所需TAG。 |

提示：参数类型可在docs\zh-cn\application-dev\reference\apis\js-apis-huks.md中查看

**示例：**

```ets
/* Cipher操作支持RSA、AES、SM4类型的密钥。
 *
 * 以下以SM4 128密钥的Promise操作使用为例
 */
function sm4CipherStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}
function sm4CipherUint8ArrayToString(fileData) {
    var dataString = '';
    for (var i = 0; i < fileData.length; i++) {
        dataString += String.fromCharCode(fileData[i]);
    }
    return dataString;
}

var handle;
var IV = '0000000000000000';
var cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string';
var srcKeyAlias = 'huksCipherSm4SrcKeyAlias';
var encryptUpdateResult = new Array();
var decryptUpdateResult = new Array();

/* 集成生成密钥参数集 & 加密参数集 */
var properties = new Array();
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM4,
}
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
}
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
}
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
}
properties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}
var HuksOptions = {
    properties: properties,
    inData: new Uint8Array(new Array())
}

var propertiesEncrypt = new Array();
propertiesEncrypt[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM4,
}
propertiesEncrypt[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
}
propertiesEncrypt[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
}
propertiesEncrypt[3] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}
propertiesEncrypt[4] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
}
propertiesEncrypt[5] = {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: sm4CipherStringToUint8Array(IV),
}
var encryptOptions = {
    properties: propertiesEncrypt,
    inData: new Uint8Array(new Array())
}

/* 生成密钥
await huks.generateKey(srcKeyAlias, HuksOptions).then((data) => {
    console.info(`test generateKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test generateKey err information: ' + JSON.stringify(err));
});

/* 进行密钥加密操作 */
await huks.init(srcKeyAlias, encryptOptions).then((data) => {
    console.info(`test init data: ${JSON.stringify(data)}`);
    handle = data.handle;
}).catch((err) => {
    console.info('test init err information: ' + JSON.stringify(err));
});
console.info(`leave init`);
encryptOptions.inData = sm4CipherStringToUint8Array(cipherInData);
await huks.update(handle, encryptOptions).then(async (data) => {
    console.info(`test update data ${JSON.stringify(data)}`);
    encryptUpdateResult = Array.from(data.outData);
}).catch((err) => {
    console.info('test update err information: ' + err);
});
encryptOptions.inData = new Uint8Array(new Array());
await huks.finish(handle, encryptOptions).then((data) => {
    console.info(`test finish data: ${JSON.stringify(data)}`);
    var finishData = sm4CipherUint8ArrayToString(new Uint8Array(encryptUpdateResult));
    if (finishData === cipherInData) {
        console.info('test finish encrypt err ');
    } else {
        console.info('test finish encrypt success');
    }
}).catch((err) => {
    console.info('test finish err information: ' + JSON.stringify(err));
});

/* 修改加密参数集为解密参数集 */
propertiesEncrypt.splice(1, 1, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
});
var decryptOptions = {
    properties: propertiesEncrypt,
    inData: new Uint8Array(new Array())
}

/* 进行解密操作 */
await huks.init(srcKeyAlias, decryptOptions).then((data) => {
    console.info(`test init data: ${JSON.stringify(data)}`);
    handle = data.handle;
}).catch((err) => {
    console.info('test init err information: ' + JSON.stringify(err));
});
decryptOptions.inData = new Uint8Array(encryptUpdateResult);
await huks.update(handle, decryptOptions).then(async (data) => {
    console.info(`test update data ${JSON.stringify(data)}`);
    decryptUpdateResult = Array.from(data.outData);
}).catch((err) => {
    console.info('test update err information: ' + err);
});
decryptOptions.inData = new Uint8Array(new Array());
await huks.finish(handle, decryptOptions).then((data) => {
    console.info(`test finish data: ${JSON.stringify(data)}`);
    var finishData = sm4CipherUint8ArrayToString(new Uint8Array(decryptUpdateResult));
    if (finishData === cipherInData) {
        console.info('test finish decrypt success ');
    } else {
        console.info('test finish decrypt err');
    }
}).catch((err) => {
    console.info('test finish err information: ' + JSON.stringify(err));
});

await huks.deleteKey(srcKeyAlias, HuksOptions).then((data) => {
    console.info(`test deleteKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test deleteKey err information: ' + JSON.stringify(err));
});
```

### 密钥签名验签

**功能定义**： 签名：给我们将要发送的数据，做上一个唯一签名；验签： 对发送者发送过来的签名进行验证 。

**测试流程**：1.生成密钥；2.密钥签名；3.导出签名密钥；4.导入签名密钥；5.密钥验签

**参数：**

| 参数名               | 类型        | 必填 | 说明                     |
| -------------------- | ----------- | ---- | ------------------------ |
| srcRsaKeyAliasSign   | string      | 是   | 生成密钥别名。           |
| srcRsaKeyAliasVerify | string      | 是   | 导入密钥别名。           |
| rsaSignOptions       | HuksOptions | 是   | 用于存放生成key所需TAG。 |
| rsaSignOptionsSecond | HuksOptions | 是   | 用于存放签名key所需TAG。 |
| rsaVerifyOptions     | HuksOptions | 是   | 用于存放验签key所需TAG。 |

提示：参数类型可在docs\zh-cn\application-dev\reference\apis\js-apis-huks.md中查看

**示例：**

```ets
/* Sign/Verify操作支持RSA、ECC、SM2、ED25519、DSA类型的密钥。
 *
 * 以下以RSA512密钥的Promise操作使用为例
 */
function rsaSignVerifyStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

var rsaSignHandle;
var rsaSignVerifyInData = 'signVerifyInData';
var srcRsaKeyAliasSign = 'huksSignVerifySrcKeyAliasSign';
var srcRsaKeyAliasVerify = 'huksSignVerifySrcKeyAliasVerify';
var finishRsaSignData;
var rsaExportSignKey;

/* 集成生成密钥参数集 & 签名参数集 & 验签参数集 */
var rsaSignProperties = new Array();
rsaSignProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA,
}
rsaSignProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN,
}
rsaSignProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
}
rsaSignProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_MD5,
}
rsaSignProperties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
}
var rsaSignOptions = {
    properties: rsaSignProperties,
    inData: new Uint8Array(new Array())
}

var rsaPropertiesSign = new Array();
rsaPropertiesSign[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA,
}
rsaPropertiesSign[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
}
rsaPropertiesSign[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_MD5,
}
rsaPropertiesSign[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
}
rsaPropertiesSign[4] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
}
var rsaSignOptionsSecond = {
    properties: rsaPropertiesSign,
    inData: new Uint8Array(new Array())
}

var rsaPropertiesVerify = new Array();
rsaPropertiesVerify[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_RSA,
}
rsaPropertiesVerify[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
}
rsaPropertiesVerify[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_MD5,
}
rsaPropertiesVerify[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
}
rsaPropertiesVerify[4] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
}
var rsaVerifyOptions = {
    properties: rsaPropertiesVerify,
    inData: new Uint8Array(new Array())
}

/* 生成密钥 */
await huks.generateKey(srcRsaKeyAliasSign, rsaSignOptions).then((data) => {
    console.info(`test generateKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test generateKey err information: ' + JSON.stringify(err));
});

/* 对密钥进行签名操作 */
await huks.init(srcRsaKeyAliasSign, rsaSignOptionsSecond).then((data) => {
    console.info(`test init data: ${JSON.stringify(data)}`);
    rsaSignHandle = data.handle;
}).catch((err) => {
    console.info('test init err information: ' + JSON.stringify(err));
});
rsaSignOptionsSecond.inData = rsaSignVerifyStringToUint8Array(rsaSignVerifyInData)
await huks.update(rsaSignHandle, rsaSignOptionsSecond).then(async (data) => {
    console.info(`test update data ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test update err information: ' + err);
});
rsaVerifyOptions.inData = finishRsaSignData;
await huks.finish(rsaSignHandle, rsaSignOptionsSecond).then((data) => {
    console.info(`test finish data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test finish err information: ' + JSON.stringify(err));
});

/* 通过导出导入模拟获取一段密钥数据 */
await huks.exportKey(srcRsaKeyAliasSign, rsaSignOptions).then((data) => {
    console.info(`test exportKey data: ${JSON.stringify(data)}`);
    rsaExportSignKey = data.outData;
}).catch((err) => {
    console.info('test exportKey err information: ' + JSON.stringify(err));
});
rsaVerifyOptions.inData = rsaExportSignKey;
await huks.importKey(srcRsaKeyAliasVerify, rsaVerifyOptions).then((data) => {
    console.info(`test ImportKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test exportKey err information: ' + JSON.stringify(err));
});

/* 对密钥进行验签 */
await huks.init(srcRsaKeyAliasVerify, rsaVerifyOptions).then((data) => {
    console.info(`test init data: ${JSON.stringify(data)}`);
    rsaSignHandle = data.handle;
}).catch((err) => {
    console.info('test init err information: ' + JSON.stringify(err));
});
rsaVerifyOptions.inData = rsaSignVerifyStringToUint8Array(rsaSignVerifyInData);
await huks.update(rsaSignHandle, rsaVerifyOptions).then(async (data) => {
    console.info(`test update data ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test update err information: ' + err);
});
rsaVerifyOptions.inData = finishRsaSignData;
await huks.finish(rsaSignHandle, rsaVerifyOptions).then((data) => {
    console.info(`test finish data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test finish err information: ' + JSON.stringify(err));
});

await huks.deleteKey(srcRsaKeyAliasVerify, rsaVerifyOptions).then((data) => {
    console.info(`test deleteKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test deleteKey err information: ' + JSON.stringify(err));
});

await huks.deleteKey(srcRsaKeyAliasSign, rsaSignOptions).then((data) => {
    console.info(`test deleteKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test deleteKey err information: ' + JSON.stringify(err));
});
```

### 密钥协商

**功能定义**： 两个或多个实体协商，共同建立会话密钥，任何一个参与者均对结果产生影响，不需要任何可信的第三方（TTP） 。

**测试流程**：1.生成两个密钥；2.分别导出密钥；3.交叉进行密钥协商

**参数：**

| 参数名              | 类型        | 必填 | 说明                                   |
| ------------------- | ----------- | ---- | -------------------------------------- |
| srcKeyAliasFirst    | string      | 是   | 生成密钥别名。                         |
| srcKeyAliasSecond   | string      | 是   | 生成密钥别名，用于结果对比。           |
| HuksOptions         | HuksOptions | 是   | 用于存放生成key所需TAG。               |
| finishOptionsFrist  | HuksOptions | 是   | 用于存放协商key所需TAG。               |
| finishOptionsSecond | HuksOptions | 是   | 用于存放协商key所需TAG，用于结果对比。 |

提示：参数类型可在docs\zh-cn\application-dev\reference\apis\js-apis-huks.md中查看

**示例：**

```ets
/* agree操作支持ECDH、DH、X25519类型的密钥。
 *
 * 以下以X25519 256密钥的Promise操作使用为例
 */
function AgreeStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

var srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
var srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
var agreeX25519InData = 'AgreeX25519TestIndata';
var exportKeyFrist;
var exportKeySecond;

/* 集成生成密钥参数集 */
var properties = new Array();
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_X25519,
}
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE,
}
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256,
}
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
}
properties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}
properties[5] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
}
var HuksOptions = {
    properties: properties,
    inData: new Uint8Array(new Array())
}

/* 1.生成两个密钥并导出 */
await huks.generateKey(srcKeyAliasFirst, HuksOptions).then((data) => {
    console.info('test generateKey data = ' + JSON.stringify(data));
}).catch((err) => {
    console.info(`test generateKey err: " + ${JSON.stringify(err)}`);
});
await huks.generateKey(srcKeyAliasSecond, HuksOptions).then((data) => {
    console.info('test generateKey data = ' + JSON.stringify(data));
}).catch((err) => {
    console.info(`test generateKey err: " + ${JSON.stringify(err)}`);
});
await huks.exportKey(srcKeyAliasFirst, HuksOptions).then((data) => {
    console.info('test exportKey data = ' + JSON.stringify(data));
    exportKeyFrist = data.outData;
}).catch((err) => {
    console.info(`test exportKey err: " + ${JSON.stringify(err)}`);
});
await huks.exportKey(srcKeyAliasSecond, HuksOptions).then((data) => {
    console.info('test exportKey data = ' + JSON.stringify(data));
    exportKeySecond = data.outData;
}).catch((err) => {
    console.info(`test exportKey err: " + ${JSON.stringify(err)}`);
});

/* 集成第一个协商参数集 */
var finishProperties = new Array();
finishProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT,
}
finishProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
    value: true
}
finishProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
}
finishProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
}
finishProperties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
}
finishProperties[5] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
}
finishProperties[6] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: AgreeStringToUint8Array(srcKeyAliasFirst+ 'final'),
}
finishProperties[7] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}
finishProperties[8] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB,
}
var finishOptionsFrist = {
    properties: finishProperties,
    inData: AgreeStringToUint8Array(agreeX25519InData)
}

/* 对第一个密钥进行协商 */
await huks.init(srcKeyAliasFirst, HuksOptions).then((data) => {
    console.info(`test init data: ${JSON.stringify(data)}`);
    handle = data.handle;
}).catch((err) => {
    console.info(`test init err: " + ${JSON.stringify(err)}`);
});
HuksOptions.inData = exportKeySecond;
await huks.update(handle, HuksOptions).then((data) => {
    console.info(`test update data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info(`test update err: " + ${JSON.stringify(err)}`);
});
await huks.finish(handle, finishOptionsFrist).then((data) => {
    console.info(`test finish data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test finish err information: ' + JSON.stringify(err));
});

/* 集成第二个协商参数集 */
var finishOptionsSecond = {
    properties: finishProperties,
    inData: AgreeStringToUint8Array(agreeX25519InData)
}
finishOptionsSecond.properties.splice(6, 1, {
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: AgreeStringToUint8Array(srcKeyAliasSecond + 'final'),
})
await huks.init(srcKeyAliasSecond, HuksOptions).then((data) => {
    console.info(`test init data: ${JSON.stringify(data)}`);
    handle = data.handle;
}).catch((err) => {
    console.info(`test init err: " + ${JSON.stringify(err)}`);
});

/* 对第二个密钥进行协商 */
HuksOptions.inData = exportKeyFrist;
await huks.update(handle, HuksOptions).then((data) => {
    console.info(`test update data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info(`test update err: " + ${JSON.stringify(err)}`);
});
await huks.finish(handle, finishOptionsSecond).then((data) => {
    console.info(`test finish data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test finish err information: ' + JSON.stringify(err));
});

await huks.deleteKey(srcKeyAliasFirst, HuksOptions).then((data) => {
    console.info(`test deleteKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test deleteKey err information: ' + JSON.stringify(err));
});
await huks.deleteKey(srcKeyAliasSecond, HuksOptions).then((data) => {
    console.info(`test deleteKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test deleteKey err information: ' + JSON.stringify(err));
});
```

### 密钥派生

**功能定义：** 从一个密钥产生出一个或者多个密钥。 

**测试流程**：1.生成密钥；2.密钥派生

**参数：**

| 参数名        | 类型        | 必填 | 说明             |
| ------------- | ----------- | ---- | ---------------- |
| srcKeyAlias   | string      | 是   | 生成密钥别名。   |
| HuksOptions   | HuksOptions | 是   | 生成密钥参数集。 |
| finishOptions | HuksOptions | 是   | 派生密钥参数集。 |

提示：参数类型可在docs\zh-cn\application-dev\reference\apis\js-apis-huks.md中查看

**示例：**

```ets
/* derive操作支持HKDF、pbdkf类型的密钥。
 *
 * 以下以HKDF256密钥的Promise操作使用为例
 */
function hkdfStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

var deriveHkdfInData = "deriveHkdfTestIndata";
var srcKeyAlias = "deriveHkdfKeyAlias";

/* 集成生成密钥参数集 */
var properties = new Array();
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
}
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DERIVE,
}
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
}
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
}
var HuksOptions = {
    properties: properties,
    inData: new Uint8Array(new Array())
}

/* 生成密钥 */
await huks.generateKey(srcKeyAlias, HuksOptions).then((data) => {
    console.info('test generateKey data = ' + JSON.stringify(data));
}).catch((err) => {
    console.info(`test init err: " + ${JSON.stringify(data)}`);
});

/* 调整init时的参数集 */
HuksOptions.properties.splice(0, 1, {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_HKDF,
});
HuksOptions.properties.splice(3, 1, {
    tag: huks.HuksTag.HUKS_TAG_DERIVE_KEY_SIZE,
    value: HuksKeyDERIVEKEYSIZE,
});

var finishProperties = new Array();
finishProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT,
}
finishProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
    value: true,
}
finishProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
}
finishProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
}
finishProperties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
}
finishProperties[5] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
}
finishProperties[6] = {
    // @ts-ignore
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: stringToUint8Array(srcKeyAlias),
}
finishProperties[7] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}
finishProperties[8] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB,
}
var finishOptions = {
    properties: finishProperties,
    inData: new Uint8Array(new Array())
}

/* 进行派生操作 */
await huks.init(srcKeyAlias, HuksOptions).then((data) => {
    console.log(`test init data: ${JSON.stringify(data)}`);
    handle = data.handle;
}).catch((err) => {
    console.log(`test init err: " + ${JSON.stringify(err)}`);
});
HuksOptions.inData = hkdfStringToUint8Array(deriveHkdfInData);
await huks.update(handle, HuksOptions).then((data) => {
    console.log(`test update data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.log(`test update err: " + ${JSON.stringify(err)}`);
});
await huks.finish(handle, finishOptions).then((data) => {
    console.log(`test finish data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.log('test finish err information: ' + JSON.stringify(err));
});

HuksOptions.properties.splice(0, 1, {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
});
HuksOptions.properties.splice(3, 1, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
});

await huks.deleteKey(srcKeyAlias, HuksOptions).then((data) => {
    console.log(`test deleteKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.log('test deleteKey err information: ' + JSON.stringify(err));
});
```

### 密钥mac

 **功能定义**：消息认证码是基于密钥和消息摘要所获得的一个值，可用于数据源发认证和完整性校验。 

**系统能力**：SystemCapability.Security.Huks

**测试流程**：1.生成密钥；2.密钥mac

**参数：**

| 参数名      | 类型        | 必填 | 说明           |
| ----------- | ----------- | ---- | -------------- |
| srcKeyAlias | string      | 是   | 生成密钥别名。 |
| HuksOptions | HuksOptions | 是   | 密钥参数集。   |

提示：参数类型可在docs\zh-cn\application-dev\reference\apis\js-apis-huks.md中查看

**示例：**

```ets
/* mac操作支持HMAC、SM3类型的密钥。
 *
 * 以下以SM3 256密钥的Promise操作使用为例
 */
function macStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

var srcKeyAlias = "sm3KeyAlias";
var hmacInData = 'sm3TestIndata';
var handle;

/* 集成生成密钥参数集 */
var properties = new Array();
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM3,
}
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_MAC,
}
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3,
}
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
}
var HuksOptions = {
    properties:properties,
    inData:new Uint8Array(new Array())
}

/* 生成密钥 */
await huks.generateKey(srcKeyAlias, HuksOptions).then((data) => {
    console.info('test generateKey data = ' + JSON.stringify(data));
}).catch((err) => {
    console.info(`test init err: " + ${JSON.stringify(err)}`);
});

/* 修改init时的参数集并进行mac操作 */
HuksOptions.properties.splice(3, 3);
await huks.init(srcKeyAlias, HuksOptions).then((data) => {
    console.info(`test init data: ${JSON.stringify(data)}`);
    handle = data.handle;
}).catch((err) => {
    console.info(`test init err: " + ${JSON.stringify(err)}`);
});
HuksOptions.inData = macStringToUint8Array(hmacInData);
await huks.update(handle, HuksOptions).then((data) => {
    console.info(`test init data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info(`test init err: " + ${JSON.stringify(err)}`);
});
HuksOptions.inData = new Uint8Array(new Array());
await huks.finish(handle, HuksOptions).then((data) => {
    console.info(`test update data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test update err information: ' + JSON.stringify(err));
});

HuksOptions.properties.splice(1, 0, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
});

await huks.deleteKey(srcKeyAlias, HuksOptions).then((data) => {
    console.info(`test deleteKey data: ${JSON.stringify(data)}`);
}).catch((err) => {
    console.info('test deleteKey err information: ' + JSON.stringify(err));
});
```

### AttestID

**功能定义**：测试获取udid等证书信息，并打印相关信息。

**测试流程**：1.生成证书；2.获取证书信息

**参数：**

| 参数名   | 类型        | 必填 | 说明                                 |
| -------- | ----------- | ---- | ------------------------------------ |
| keyAlias | string      | 是   | 密钥别名，存放待获取证书密钥的别名。 |
| options  | HuksOptions | 是   | 用于获取证书时指定所需参数与数据。   |

提示：参数类型可在docs\zh-cn\application-dev\reference\apis\js-apis-huks.md中查看

**示例：**

```ets
/* 证书AttestID操作示例如下*/
function stringToUint8Array(str) {
    var arr = [];
  	for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
  	}
  	var tmpUint8Array = new Uint8Array(arr);
  	return tmpUint8Array;
}

function printLog(...data) {
    console.error(data.toString());
}

let securityLevel = stringToUint8Array('sec_level');
let challenge = stringToUint8Array('challenge_data');
let versionInfo = stringToUint8Array('version_info');
let udid = stringToUint8Array('udid');
let serial = stringToUint8Array('serial');
let deviceId = stringToUint8Array('device_id');
let idAliasString = "id attest";

/* 集成生成密钥参数集 & 生成密钥 */
function generateKey(alias) {
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA
    };
  	properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
        value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT
  	};
  	properties[2] = {
   	    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
    };
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
    };
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    };
    properties[5] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PSS
    };
    properties[6] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_GENERATE_TYPE,
        value: huks.HuksKeyGenerateType.HUKS_KEY_GENERATE_TYPE_DEFAULT
    };
    properties[7] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB
    };
    let options = {
        properties: properties
    };
    huks.generateKey(alias, options);
}

async function attestId() {
    let aliasString = idAliasString;
    let aliasUint8 = stringToUint8Array(aliasString);

    /* 集成证书参数集 */
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
        value: securityLevel
    };
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
        value: challenge
    };
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
        value: versionInfo
    };
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
        value: aliasUint8
    };
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_UDID,
        value: udid
    };
    properties[5] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SERIAL,
        value: serial
    };
    properties[6] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_DEVICE,
        value: deviceId
    };
    let options = {
    properties: properties
    };

    generateKey(aliasString);
    setTimeout(()=>huks.attestKey(aliasString, options, function (err, data) {
        printLog(`key attest result : ${JSON.stringify(data)}`);
    }), 1000);
}
```

### AttestKey

**功能定义**：测试获取密钥证书，并打印相关信息。

**测试流程**：1.生成证书；2.获取证书信息

**参数：**

| 参数名   | 类型        | 必填 | 说明                                 |
| -------- | ----------- | ---- | ------------------------------------ |
| keyAlias | string      | 是   | 密钥别名，存放待获取证书密钥的别名。 |
| options  | HuksOptions | 是   | 用于获取证书时指定所需参数与数据。   |

提示：参数类型可在docs\zh-cn\application-dev\reference\apis\js-apis-huks.md中查看

**示例：**

```ets
/* 证书AttestKey操作示例如下*/
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
  	}
  	var tmpUint8Array = new Uint8Array(arr);
  	return tmpUint8Array;
}

function printLog(...data) {
    console.error(data.toString());
}

let securityLevel = stringToUint8Array('sec_level');
let challenge = stringToUint8Array('challenge_data');
let versionInfo = stringToUint8Array('version_info');
let keyAliasString = "key attest";

/* 集成生成密钥参数集 & 生成密钥 */
function generateKey(alias) {
  	let properties = new Array();
  	properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA
     };
  	properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
        value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT
  	};
  	properties[2] = {
   	    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  	};
  	properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
 	};
  	properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    };
    properties[5] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PSS
    };
    properties[6] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_GENERATE_TYPE,
        value: huks.HuksKeyGenerateType.HUKS_KEY_GENERATE_TYPE_DEFAULT
    };
    properties[7] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB
    };
    let options = {
        properties: properties
    };
    huks.generateKey(alias, options);
}

async function attestKey() {
    let aliasString = keyAliasString;
    let aliasUint8 = stringToUint8Array(aliasString);

    /* 集成证书参数集 */
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
        value: securityLevel
    };
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
        value: challenge
    };
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
        value: versionInfo
    };
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
        value: aliasUint8
    };
        let options = {
        properties: properties
    };
    generateKey(aliasString);
    setTimeout(()=>huks.attestKey(aliasString, options, function (err, data) {
        printLog(`key attest result : ${JSON.stringify(data)}`);
    }), 1000);
}
```

### 

