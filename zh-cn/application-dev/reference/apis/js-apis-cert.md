# 证书模块

crypto framework提供证书相关接口。其中，依赖加解密算法库框架的基础算法能力的部分，详细接口说明可参考[cryptoFramework API参考](./js-apis-cryptoFramework.md)。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。

## 导入模块

```javascript
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"
```

## CertResult

 表示执行结果的枚举。

 **系统能力：** SystemCapability.Security.Cert

| 名称                                  | 值   | 说明                          |
| --------------------------------------| -------- | -----------------------------|
| INVALID_PARAMS                        | 401      | 非法入参。                    |
| NOT_SUPPORT                           | 801      | 操作不支持。                  |
| ERR_OUT_OF_MEMORY                     | 19020001 | 内存错误。                    |
| ERR_RUNTIME_ERROR                     | 19020002 | 运行时外部错误。              |
| ERR_CRYPTO_OPERATION                  | 19030001 | 调用三方算法库API出错。       |
| ERR_CERT_SIGNATURE_FAILURE            | 19030002 | 证书签名验证错误。            |
| ERR_CERT_NOT_YET_VALID                | 19030003 | 证书尚未生效。                |
| ERR_CERT_HAS_EXPIRED                  | 19030004 | 证书过期。                   |
| ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY | 19030005 | 无法获取证书的颁发者。        |
| ERR_KEYUSAGE_NO_CERTSIGN              | 19030006 | 证书的秘钥用途不含证书签名。   |
| ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE     | 19030007 |  证书的秘钥用途不含数字签名。  |

## DataBlob
buffer数组。
 **系统能力：** SystemCapability.Security.Cert
| 名称           | 类型           | 可读 | 可写 | 说明              |
| -------------- | -------------- | ---- | ---- | ----------------|
| data           | Uint8Array     | 是   | 是   | 数据。    |

## DataArray

buffer数组的列表。
 **系统能力：** SystemCapability.Security.Cert
| 名称           | 类型           | 可读 | 可写 | 说明               |
| -------------- | -------------- | ---- | ---- | ----------------|
| data           | Uint8Array     | 是   | 是   | 数据列表。    |

## EncodingFormat

 表示证书编码格式的枚举。

 **系统能力：** SystemCapability.Security.Cert

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| FORMAT_DER | 0      | DER格式。 |
| FORMAT_PEM | 1      | PEM格式。 |


## EncodingBlob

带编码格式的证书二进制数组。

### 属性

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 可读 | 可写 | 说明                           |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------ |
| data           | Uint8Array                        | 是   | 是   | 传入的证书数据。 |
| encodingFormat | [EncodingFormat](#encodingformat) | 是   | 是   | 指明证书编码格式。             |


## CertChainData

证书链数据，在证书链校验时，作为入参传入。

### 属性

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 可读 | 可写 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| data           | Uint8Array                        | 是   | 是   | 证书数据，按照长度(2字节)-数据的形式传入，如：08ABCDEFGH07ABCDEFG,第一本证书，前2个字节表示证书的长度为8字节，后面附加8字节的证书数据；第2本证书前2个字节表示证书的长度为7字节，后面附加7字节的证书数据。 |
| count          | number                            | 是   | 是   | 传入的数据中，包含的证书数量。                               |
| encodingFormat | [EncodingFormat](#encodingformat) | 是   | 是   | 指明证书编码格式。                                           |


## cryptoCert.createX509Cert

createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void

表示创建X509证书对象。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明                       |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | X509证书序列化数据         |
| callback | AsyncCallback\<X509Cert>      | 是   | 回调函数。表示X509证书对象 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
    }
});
```

## cryptoCert.createX509Cert

createX509Cert(inStream : EncodingBlob) : Promise\<X509Cert>

表示创建X509证书对象。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明               |
| -------- | ----------------------------- | ---- | ------------------ |
| inStream | [EncodingBlob](#encodingblob) | 是   | X509证书序列化数据 |

**返回值：**

| 类型     | 说明             |
| ------- | ---------------- |
| Promise\<X509Cert> | 表示X509证书对象 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob).then(x509Cert => {
    console.log("createX509Cert success");
}, error => {
    console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

## X509Cert

X509证书类。

### verify

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

表示对证书验签。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| key      | cryptoFramework.PubKey     | 是   | 用于验签的公钥对象                                           |
| callback | AsyncCallback\<void> | 是   | 回调函数。使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，不为null表示失败 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        // 业务需通过AsyKeyGenerator生成PubKey或通过上级X509Cert证书对象的getPublicKey获取PubKey
		let pubKey = null;
        x509Cert.verify(pubKey, function (error, data) {
            if (error != null) {
                console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                console.log("verify success");
            }
        });
    }
});
```

### verify

verify(key : cryptoFramework.PubKey) : Promise\<void>

表示对证书验签。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| key    | cryptoFramework.PubKey | 是   | 用于验签的公钥对象 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob).then(x509Cert => {
    console.log("createX509Cert success");
    // 业务需通过AsyKeyGenerator生成PubKey或通过上级X509Cert证书对象的getPublicKey获取PubKey
	let pubKey = null;
    x509Cert.verify(pubKey).then(result => {
        console.log("verify success");
    }, error => {
        console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书序列化数据。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                             |
| -------- | --------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数。表示X509证书序列化数据 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        x509Cert.getEncoded(function (error, data) {
           if (error != null) {
               console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               console.log("getEncoded success");
           }
        });
    }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书序列化数据。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                   |
| --------------------------------------- | ---------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示X509证书序列化数据 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob).then(x509Cert => {
    console.log("createX509Cert success");
    x509Cert.getEncoded().then(result => {
        console.log("getEncoded success");
    }, error => {
        console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getPublicKey

getPublicKey() : cryptoFramework.PubKey

表示获取X509证书公钥。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| cryptoFramework.PubKey | X509证书公钥对象 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let pubKey = null;
        try {
            pubKey = x509Cert.getPublicKey();
        } catch (error) {
            console.log("getPublicKey failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    }
});
```

### checkValidityWithDate

checkValidityWithDate(date: string) : void

表示检查X509证书有效期。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型            | 必填 | 说明        |
| -------- | -------------- | ---- | ---------- |
| date     | string         | 是   | 日期        |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let date = "150527000001Z";
        
        // 校验证书有效期
        try {
            x509Cert.checkValidityWithDate(date);
        } catch (error) {
            console.log("checkValidityWithDate failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    }
});
```

### getVersion

getVersion() : number

表示获取X509证书版本。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| number | 表示X509证书版本 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let version = x509Cert.getVersion();
    }
});
```

### getSerialNumber

getSerialNumber() : number

表示获取X509证书序列号。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| number | 表示X509证书序列号 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let serialNumber = x509Cert.getSerialNumber();
    }
});
```

### getIssuerName

getIssuerName() : DataBlob

表示获取X509证书颁发者名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                   |
| --------------------- | ---------------------- |
| [DataBlob](#datablob) | 表示X509证书颁发者名称 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let issuerName = x509Cert.getIssuerName();
    }
});
```

### getSubjectName

getSubjectName() : DataBlob

表示获取X509证书主体名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                 |
| --------------------- | -------------------- |
| [DataBlob](#datablob) | 表示X509证书主体名称 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let subjectName = x509Cert.getSubjectName();
    }
});
```

### getNotBeforeTime

getNotBeforeTime() : string

表示获取X509证书有效期起始时间。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                       |
| ------ | -------------------------- |
| string | 表示X509证书有效期起始时间 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let notBefore = x509Cert.getNotBeforeTime();
    }
});
```

### getNotAfterTime

getNotAfterTime() : string

表示获取X509证书有效期截止时间。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                       |
| ------ | -------------------------- |
| string | 表示X509证书有效期截止时间 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let notAfter = x509Cert.getNotAfterTime();
    }
});
```

### getSignature

getSignature() : DataBlob

表示获取X509证书签名数据。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                 |
| --------------------- | -------------------- |
| [DataBlob](#datablob) | 表示X509证书签名数据 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let signature = x509Cert.getSignature();
    }
});
```

### getSignatureAlgName

getSignatureAlgName() : string

表示获取X509证书签名算法名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 表示X509证书签名算法名称 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let sigAlgName = x509Cert.getSignatureAlgName();
    }
});
```

### getSignatureAlgOid

getSignatureAlgOid() : string

表示获取X509证书签名算法的对象标志符OID(Object Identifier)。OID是由国际标准组织(ISO)的名称注册机构分配。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                              |
| ------ | --------------------------------- |
| string | 表示X509证书签名算法对象标志符OID |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let sigAlgOid = x509Cert.getSignatureAlgOid();
    }
});
```

### getSignatureAlgParams

getSignatureAlgParams() : DataBlob

表示获取X509证书签名算法参数。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | 表示X509证书签名算法参数 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let sigAlgParams = x509Cert.getSignatureAlgParams();
    }
});
```

### getKeyUsage

getKeyUsage() : DataBlob

表示获取X509证书秘钥用途。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                 |
| --------------------- | -------------------- |
| [DataBlob](#datablob) | 表示X509证书秘钥用途 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let keyUsage = x509Cert.getKeyUsage();
    }
});
```

### getExtKeyUsage

getExtKeyUsage() : DataArray

表示获取X509证书扩展秘钥用途。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                    | 说明                     |
| ----------------------- | ------------------------ |
| [DataArray](#dataarray) | 表示X509证书扩展秘钥用途 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let extKeyUsage = x509Cert.getExtKeyUsage();
    }
});
```

### getBasicConstraints

getBasicConstraints() : number

表示获取X509证书基本约束。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 表示X509证书基本约束 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let basicConstraints = x509Cert.getBasicConstraints();
    }
});
```

### getSubjectAltNames

getSubjectAltNames() : DataArray

表示获取X509证书主体可选名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                    | 说明                     |
| ----------------------- | ------------------------ |
| [DataArray](#dataarray) | 表示X509证书主体可选名称 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let subjectAltNames = x509Cert.getSubjectAltNames();
    }
});
```

### getIssuerAltNames

getIssuerAltNames() : DataArray

表示获取X509证书颁发者可选名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                    | 说明                       |
| ----------------------- | -------------------------- |
| [DataArray](#dataarray) | 表示X509证书颁发者可选名称 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let issuerAltNames = x509Cert.getIssuerAltNames();
    }
});
```

## cryptoCert.createX509Crl

createX509Crl(inStream : EncodingBlob, callback : AsyncCallback\<X509Crl>) : void

表示创建X509证书吊销列表的对象。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                          | 必填 | 说明                           |
| -------- | ----------------------------- | ---- | ------------------------------ |
| inStream | [EncodingBlob](#encodingblob) | 是   | 表示证书吊销列表序列化数据     |
| callback | AsyncCallback\<X509Crl>       | 是   | 回调函数。表示证书吊销列表对象 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
    }
});
```

## cryptoCert.createX509Crl

createX509Crl(inStream : EncodingBlob) : Promise\<X509Crl>

表示创建X509证书吊销列表的对象。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                          | 必填 | 说明                       |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | 表示证书吊销列表序列化数据 |

**返回值**：

| 类型              | 说明                 |
| ----------------- | -------------------- |
| Promise\<X509Crl> | 表示证书吊销列表对象 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob).then(x509Crl => {
    console.log("createX509Crl success");
}, error => {
    console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

## X509Crl

X509证书吊销列表对象。

### isRevoked

isRevoked(cert : X509Cert) : boolean

表示检查证书是否吊销。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型     | 必填 | 说明                 |
| ------ | -------- | ---- | -------------------- |
| cert   | X509Cert | 是   | 表示被检查的证书对象 |

**返回值**：

| 类型      | 说明                                           |
| --------- | --------------------------------------------- |
| boolean   | 表示证书吊销状态，true表示已吊销，false表示未吊销 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        // 业务需自行生成X509Cert证书对象
        let x509Cert = null;
        try {
            let revokedFlag = x509Crl.isRevoked(x509Cert);
        } catch (error) {
           console.log("isRevoked failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    }
});
```

### getType

getType() : string

表示获取证书吊销列表类型。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 表示证书吊销列表类型 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let type = x509Crl.getType();
    }
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书吊销列表的序列化数据。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                         | 必填 | 说明                                       |
| -------- | ---------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<EncodingBlob> | 是   | 回调函数，表示X509证书吊销列表的序列化数据 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        x509Crl.getEncoded(function (error, data) {
           if (error != null) {
               console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               console.log("getEncoded success");
           }
        });
    }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书吊销列表的序列化数据。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                   | 说明                             |
| ---------------------- | -------------------------------- |
| Promise\<EncodingBlob> | 表示X509证书吊销列表的序列化数据 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob).then(x509Crl => {
    console.log("createX509Crl success");
    x509Crl.getEncoded().then(result => {
        console.log("getEncoded success");
    }, error => {
        console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### verify

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

表示对X509证书吊销列表进行验签。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| key      | cryptoFramework.PubKey               | 是   | 表示用于验签的公钥对象                                       |
| callback | AsyncCallback\<void> | 是   | 回调函数,使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，error不为null表示失败。 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        // 业务需通过AsyKeyGenerator生成PubKey
        let pubKey = null;
        x509Crl.verify(pubKey, function (error, data) {
           if (error != null) {
               console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               console.log("verify success");
           }
        });
    }
});
```

### verify

verify(key : cryptoFramework.PubKey) : Promise\<void>

表示对X509证书吊销列表进行验签。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| key    | cryptoFramework.PubKey | 是   | 表示用于验签的公钥对象 |

**返回值**：

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob).then(x509Crl => {
    console.log("createX509Crl success");
    // 业务需通过AsyKeyGenerator生成PubKey
    let pubKey = null;
    x509Crl.verify(pubKey).then(result => {
        console.log("verify success");
    }, error => {
        console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getVersion

getVersion() : number

表示获取X509证书吊销列表的版本号。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| number | 表示获取X509证书吊销列表的版本号 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let version = x509Crl.getVersion();
    }
});
```

### getIssuerName

getIssuerName() : DataBlob

表示获取X509证书吊销列表颁发者名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表颁发者名称 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let issuerName = x509Crl.getIssuerName();
    }
});
```

### getLastUpdate

getLastUpdate() : string

表示获取X509证书吊销列表最后一次更新日期。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表最后一次更新日期 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let lastUpdate = x509Crl.getLastUpdate();
    }
});
```

### getNextUpdate

getNextUpdate() : string

表示获取证书吊销列表下一次更新的日期。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表下一次更新的日期 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let nextUpdate = x509Crl.getNextUpdate();
    }
});
```

### getRevokedCert

getRevokedCert(serialNumber : number) : X509CrlEntry

表示通过指定证书序列号获取被吊销X509证书对象。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名       | 类型   | 必填 | 说明           |
| ------------ | ------ | ---- | -------------- |
| serialNumber | number | 是   | 表示证书序列号 |

**返回值**:

| 类型                   | 说明                   |
| ---------------------- | --------------------- |
| X509CrlEntry | 表示被吊销X509证书对象 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        // 业务需赋值为对应证书的序列号
        let serialNumber = 1000;
        try {
            let entry = x509Crl.getRevokedCert(serialNumber);
        } catch (error) {
           console.log("getRevokedCert failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    }
});
```

### getRevokedCertWithCert

getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry

表示通过指定证书对象获取被吊销X509证书对象。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型     | 必填 | 说明         |
| ------ | -------- | ---- | ------------ |
| cert   | X509Cert | 是   | 表示证书对象 |

**返回值**:

| 类型         | 说明                  |
| ------------ | -------------------- |
| X509CrlEntry | 表示被吊销X509证书对象 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        // 业务需自行生成X509Cert证书对象
        let x509Cert = null;
        try {
            let entry = x509Crl.getRevokedCertWithCert(x509Cert);
        } catch (error) {
           console.log("getRevokedCertWithCert failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    }
});
```

### getRevokedCerts

getRevokedCerts(callback : AsyncCallback<Array\<X509CrlEntry>>) : void

表示获取被吊销X509证书列表。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                | 必填 | 说明                             |
| -------- | ----------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback<Array\<X509CrlEntry>> | 是   | 回调函数。表示被吊销X509证书列表 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        x509Crl.getRevokedCerts(function (error, array) {
            if (error != null) {
                console.log("getRevokedCerts failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                console.log("getRevokedCerts success");
            }
        });
    }
});
```

### getRevokedCerts

getRevokedCerts() : Promise<Array\<X509CrlEntry>>

表示获取被吊销X509证书列表。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                          | 说明                   |
| ----------------------------- | ---------------------- |
| Promise<Array\<X509CrlEntry>> | 表示被吊销X509证书列表 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob).then(x509Crl => {
    console.log("createX509Crl success");
    x509Crl.getRevokedCerts().then(array => {
        console.log("getRevokedCerts success");
    }, error => {
        console.log("getRevokedCerts failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getTbsInfo

getTbsInfo() : DataBlob

表示获取证书吊销列表的tbsCertList信息。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| [DataBlob](#datablob) | 表示证书吊销列表的tbsCertList信息 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        try {
            let tbsInfo = x509Crl.getTbsInfo();
        } catch (error) {
           console.log("getTbsInfo failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    }
});
```

### getSignature

getSignature() : DataBlob

表示获取X509证书吊销列表的签名数据。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表的签名数据 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let signature = x509Crl.getSignature();
    }
});
```

### getSignatureAlgName

getSignatureAlgName() : string

表示获取X509证书吊销列表签名的算法名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| string | 表示X509证书吊销列表签名的算法名 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let sigAlgName = x509Crl.getSignatureAlgName();
    }
});
```

### getSignatureAlgOid

getSignatureAlgOid() : string

表示获取X509证书吊销列表签名算法的对象标志符OID(Object Identifier)。OID是由国际标准组织(ISO)的名称注册机构分配。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                          |
| ------ | --------------------------------------------- |
| string | 表示X509证书吊销列表签名算法的对象标志符OID。 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let sigAlgOid = x509Crl.getSignatureAlgOid();
    }
});
```

### getSignatureAlgParams

getSignatureAlgParams() : DataBlob

表示获取X509证书吊销列表签名的算法参数。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| [DataBlob](#datablob) | 表示X509证书吊销列表签名的算法参数 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let sigAlgParams = x509Crl.getSignatureAlgParams();
    }
});
```

## cryptoCert.createCertChainValidator

createCertChainValidator(algorithm :string) : CertChainValidator

表示创建证书链校验器对象。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | ------------------------------------------ |
| algorithm | string | 是   | 表示证书链校验器算法。当前仅支持输入“PKIX” |

**返回值**：

| 类型               | 说明                 |
| ------------------ | -------------------- |
| CertChainValidator | 表示证书链校验器对象 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

let validator = cryptoCert.createCertChainValidator("PKIX");
```

## CertChainValidator

证书链校验器对象。


### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | -------------------------- |
| algorithm  | string | 是   | 否   | X509证书链校验器算法名称。 |


### validate

validate(certChain : CertChainData, callback : AsyncCallback\<void>) : void

表示校验X509证书链。
由于端侧系统时间不可信，证书链校验不包含对证书有效时间的校验。如果需要检查证书的时间有效性，可使用X509证书的[checkValidityWithDate](#checkvaliditywithdate)方法进行检查。详见[证书规格](../../security/cert-overview.md#证书规格)

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| certChain | [CertChainData](#certchaindata) | 是   | 表示X509证书链序列化数据                                     |
| callback  | AsyncCallback\<void>            | 是   | 回调函数。使用AsyncCallback的第一个error参数判断是否校验成功，error为null表示成功，error不为null表示失败 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';

let validator = cryptoCert.createCertChainValidator("PKIX");
// 证书链二进制数据，需业务自行赋值
let encodingData = null;
// 证书链包含的证书个数，需业务自行赋值
let certCount = 2;
let certChainData = {
    data: encodingData,
    count: certCount,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM 
};
validator.validate(certChainData, function (error, data) {
    if (error != null) {
        console.log("validate failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("validate success");
    }
});
```

### validate

validate(certChain : CertChainData) : Promise\<void>

表示校验X509证书链。
由于端侧系统时间不可信，证书链校验不包含对证书有效时间的校验。如果需要检查证书的时间有效性，可使用X509证书的[checkValidityWithDate](#checkvaliditywithdate)方法进行检查。详见[证书规格](../../security/cert-overview.md#证书规格)

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明                       |
| --------- | ------------------------------- | ---- | -------------------------- |
| certChain | [CertChainData](#certchaindata) | 是   | 表示X509证书链序列化数据。 |

**返回值**：

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

let validator = cryptoCert.createCertChainValidator("PKIX");
// 证书链二进制数据，需业务自行赋值
let encodingData = null;
// 证书链包含的证书个数，需业务自行赋值
let certCount = 2;
let certChainData = {
    data: encodingData,
    count: certCount,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM 
};
validator.validate(certChainData).then(result => {
    console.log("validate success");
}, error => {
    console.log("validate failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### algorithm

algorithm : string

表示X509证书链校验器算法名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 表示证书链校验器算法名称 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

let validator = cryptoCert.createCertChainValidator("PKIX");
let algorithm = validator.algorithm;
```

## X509CrlEntry

被吊销证书对象。

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取被吊销证书的序列化数据。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                                 |
| -------- | --------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数。表示被吊销证书的序列化数据 |


**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
x509CrlEntry.getEncoded(function (error, data) {
    if (error != null) {
        console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("getEncoded success");
    }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

表示获取被吊销证书的序列化数据。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示被吊销证书的序列化数据 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
x509CrlEntry.getEncoded().then(result => {
    console.log("getEncoded success");
}, error => {
    console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getSerialNumber

getSerialNumber() : number

表示获取被吊销证书的序列号。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 表示被吊销证书的序列号 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
let serialNumber = x509CrlEntry.getSerialNumber();
```

### getCertIssuer

getCertIssuer() : DataBlob

表示获取被吊销证书的颁发者信息。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                     |
| --------------------- | ---------------------- - |
| [DataBlob](#datablob) | 表示被吊销证书的颁发者信息 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
try {
    let issuer = x509CrlEntry.getCertIssuer();
} catch (error) {
    console.log("getCertIssuer failed, errCode: " + error.code + ", errMsg: " + error.message);
}
```

### getRevocationDate

getRevocationDate() : string

表示获取证书被吊销的日期。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                |
| ------ | ------------------ |
| string | 表示证书被吊销的日期 |

**示例：**

```js
import cryptoCert from '@ohos.security.cert';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
try {
    let date = x509CrlEntry.getRevocationDate();
} catch (error) {
    console.log("getRevocationDate failed, errCode: " + error.code + ", errMsg: " + error.message);
}
```
