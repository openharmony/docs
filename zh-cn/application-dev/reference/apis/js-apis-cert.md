# @ohos.security.cert (证书模块)

证书算法库框架提供证书相关接口。其中，依赖加解密算法库框架的基础算法能力的部分，详细接口说明可参考[cryptoFramework API参考](js-apis-cryptoFramework.md)。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';
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
| FORMAT_PKCS7<sup>11+</sup> | 2 | PKCS7格式。 |

## CertItemType<sup>10+</sup>

 表示获取证书字段的枚举。

 **系统能力：** SystemCapability.Security.Cert

| 名称                             | 值   | 说明                           |
| -------------------------------- | ---- | ------------------------------ |
| CERT_ITEM_TYPE_TBS               | 0    | 表示获取证书的待签名信息。     |
| CERT_ITEM_TYPE_PUBLIC_KEY        | 1    | 表示获取证书的公钥信息。       |
| CERT_ITEM_TYPE_ISSUER_UNIQUE_ID  | 2    | 表示获取证书的颁发者唯一编号。 |
| CERT_ITEM_TYPE_SUBJECT_UNIQUE_ID | 3    | 表示获取证书的主体唯一编号。   |
| CERT_ITEM_TYPE_EXTENSIONS        | 4    | 表示获取证书的扩展域信息。     |

## ExtensionOidType<sup>10+</sup>

 表示获取扩展域中对象标识符类型的枚举。

 **系统能力：** SystemCapability.Security.Cert

| 名称                          | 值   | 说明                                          |
| ----------------------------- | ---- | --------------------------------------------- |
| EXTENSION_OID_TYPE_ALL        | 0    | 表示获取扩展域中所有的对象标识符。            |
| EXTENSION_OID_TYPE_CRITICAL   | 1    | 表示获取扩展域中critical为true的对象标识符。  |
| EXTENSION_OID_TYPE_UNCRITICAL | 2    | 表示获取扩展域中critical为false的对象标识符。 |

## ExtensionEntryType<sup>10+</sup>

 表示获取扩展域中对象类型的枚举。

 **系统能力：** SystemCapability.Security.Cert

| 名称                                | 值   | 说明                         |
| ----------------------------------- | ---- | ---------------------------- |
| EXTENSION_ENTRY_TYPE_ENTRY          | 0    | 表示获取整个对象。           |
| EXTENSION_ENTRY_TYPE_ENTRY_CRITICAL | 1    | 表示获取对象的critical属性。 |
| EXTENSION_ENTRY_TYPE_ENTRY_VALUE    | 2    | 表示获取对象的数据。         |

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

## X509CertMatchParameters<sup>11+</sup>

用于匹配证书的过滤参数。如果参数中任一项都未指定，则匹配所有证书。

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 必填 | 说明               |
| -------------- | --------------------------------- | ---- | ------------------ |
| x509Cert | [X509Cert](#x509cert)    | 否 |  指定具体的证书对象。  |
| validDate | string    | 否  |  指定证书有效期。  |
| issuer | Uint8Array | 否  | 指定证书颁发者，为DER编码格式。 |
| keyUsage | Array\<boolean> | 否  | 指定密钥用途。 |
| serialNumber | bigint    | 否  |  指定证书的序列号。  |
| subject | Uint8Array | 否  | 指定证书主题，DER编码格式。 |
| publicKey | [DataBlob](#datablob) | 否  | 指定证书公钥，DER编码格式。 |
| publicKeyAlgID | string | 否  | 指定证书公钥的算法。 |

## X509CRLMatchParameters<sup>11+</sup>

用于匹配证书吊销列表的过滤参数。如果参数中任一项都未指定，则匹配所有证书吊销列表。


**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 必填 | 说明               |
| -------------- | --------------------------------- | ---- | ------------------ |
| issuer | Array\<Uint8Array> | 否  | 指定颁发者作为过滤条件, 至少要匹配到其中一个issuer。 |
| x509Cert | [X509Cert](#x509cert)        | 否  | 指定具体的证书对象作为过滤条件, 判断该证书是否在CRL列表中。 |

## X509TrustAnchor<sup>11+</sup>

表示X509信任锚，用于校验证书链。使用信任锚中的证书或者公钥作为可信根，对证书链进行校验。

**系统能力：** SystemCapability.Security.Cert

| 名称      | 类型                  | 可读 | 可写 | 说明                        |
| --------- | --------------------- | ---- | ---- | --------------------------- |
| CACert    | [X509Cert](#x509cert) | 是   | 是   | 信任的CA证书。              |
| CAPubKey  | Uint8Array            | 是   | 是   | 信任的CA证书公钥, DER格式。 |
| CASubject | Uint8Array            | 是   | 是   | 信任的CA证书主题, DER格式。 |

## CertChainValidationParameters<sup>11+</sup>

表示证书链校验的参数。

**系统能力：** SystemCapability.Security.Cert

| 名称         | 类型                                              | 必填 | 说明                                   |
| ------------ | ------------------------------------------------- | ---- | -------------------------------------- |
| date         | string                                            | 否   | 表示需要校验证书的有效期。             |
| trustAnchors | Array\<[X509TrustAnchor](#x509trustanchor11)>     | 是   | 表示信任锚列表。                       |
| certCRLs     | Array\<[CertCRLCollection](#certcrlcollection11)> | 否   | 表示需要校验证书是否在证书吊销列表中。 |

## CertChainValidationResult<sup>11+</sup>

表示证书链校验的返回值。

**系统能力：** SystemCapability.Security.Cert

| 名称        | 类型                                  | 可读 | 可写 | 说明           |
| ----------- | ------------------------------------- | ---- | ---- | -------------- |
| trustAnchor | [X509TrustAnchor](#x509trustanchor11) | 是   | 否   | 表示信任锚。   |
| entityCert  | [X509Cert](#x509cert)                 | 是   | 否   | 表示实体证书。 |

## cryptoCert.createX509Cert

createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void

表示创建X509证书对象，使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)         | 是   | X509证书序列化数据         |
| callback | AsyncCallback\<[X509Cert](#x509cert)> | 是   | 回调函数。表示X509证书对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
  }
});
```

## cryptoCert.createX509Cert

createX509Cert(inStream : EncodingBlob) : Promise\<X509Cert>

表示创建X509证书对象，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明               |
| -------- | ----------------------------- | ---- | ------------------ |
| inStream | [EncodingBlob](#encodingblob) | 是   | X509证书序列化数据 |

**返回值：**

| 类型     | 说明             |
| ------- | ---------------- |
| Promise\<[X509Cert](#x509cert)> | 表示X509证书对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob).then(x509Cert => {
  console.log('createX509Cert success');
}).catch((error: BusinessError) => {
  console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## X509Cert

X509证书类。

### verify

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

表示对证书验签，使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| key      | cryptoFramework.PubKey     | 是   | 用于验签的公钥对象                                           |
| callback | AsyncCallback\<void> | 是   | 回调函数。使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，不为null表示失败 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 19030001 | crypto operation error.      |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');

    // 业务需通过上级X509Cert证书对象（或当前证书对象为自签名的证书）的getPublicKey获取PubKey
    try {
      let pubKey = x509Cert.getPublicKey();

      // 验证证书签名
      x509Cert.verify(pubKey, (err, data) => {
        if (err == null) {
          console.log('verify success');
        } else {
          console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getPublicKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### verify

verify(key : cryptoFramework.PubKey) : Promise\<void>

表示对证书验签，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| key    | cryptoFramework.PubKey | 是   | 用于验签的公钥对象 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 19030001 | crypto operation error.      |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob).then(x509Cert => {
  console.log('createX509Cert success');

  try {
    // 业务需通过上级X509Cert证书对象（或当前证书对象为自签名的证书）的getPublicKey获取PubKey
    let pubKey = x509Cert.getPublicKey();
    x509Cert.verify(pubKey).then(result => {
      console.log('verify success');
    }).catch((error: BusinessError) => {
      console.error('verify failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    });
  } catch (err) {
    console.error('get public key failed');
  }
}).catch((error: BusinessError) => {
  console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书序列化数据，使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                             |
| -------- | --------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数。表示X509证书序列化数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    x509Cert.getEncoded((error, data) => {
      if (error != null) {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getEncoded success');
      }
    });
  }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书序列化数据，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                   |
| --------------------------------------- | ---------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示X509证书序列化数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// 证书二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};
certFramework.createX509Cert(encodingBlob).then(x509Cert => {
  console.log('createX509Cert success');
  x509Cert.getEncoded().then(result => {
    console.log('getEncoded success');
  }).catch((error: BusinessError) => {
    console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getPublicKey

getPublicKey() : cryptoFramework.PubKey

表示获取X509证书公钥。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| cryptoFramework.PubKey | X509证书公钥对象：仅用于X509Cert的verify接口 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let pubKey = x509Cert.getPublicKey();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getPublicKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
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
| date     | string         | 是   | 日期（格式：YYMMDDHHMMSSZ 或 YYYYMMDDHHMMSSZ，时间必须以Z结尾：表示标准时间） |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19030001 | crypto operation error.|
| 19030003 | the certificate has not taken effect.                                     |
| 19030004 | the certificate has expired.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');

    let date = '231001000001Z';
    // Verify the certificate validity period.
    try {
      x509Cert.checkValidityWithDate(date);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('checkValidityWithDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
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

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};
certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    let version = x509Cert.getVersion();
  }
});
```

### getSerialNumber<sup>(deprecated)</sup>

getSerialNumber() : number

表示获取X509证书序列号。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[getCertSerialNumber](#getcertserialnumber10)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| number | 表示X509证书序列号 |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    let serialNumber = x509Cert.getSerialNumber();
  }
});
```

### getCertSerialNumber<sup>10+</sup>

getCertSerialNumber() : bigint

表示获取X509证书序列号。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| bigint | 表示X509证书序列号 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020002 | runtime error.                                    |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let serialNumber = x509Cert.getCertSerialNumber();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getCertSerialNumber failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let issuerName = x509Cert.getIssuerName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let subjectName = x509Cert.getSubjectName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSubjectName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNotBeforeTime

getNotBeforeTime() : string

表示获取X509证书有效期起始时间。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 表示X509证书有效期起始时间（格式：YYMMDDHHMMSSZ 或 YYYYMMDDHHMMSSZ，时间以Z结尾：表示标准时间） |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let notBefore = x509Cert.getNotBeforeTime();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNotAfterTime

getNotAfterTime() : string

表示获取X509证书有效期截止时间。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 表示X509证书有效期截止时间（格式：YYMMDDHHMMSSZ 或 YYYYMMDDHHMMSSZ，时间以Z结尾：表示标准时间） |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';

import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let notAfter = x509Cert.getNotAfterTime();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNotAfterTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';

import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let signature = x509Cert.getSignature();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignature failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';

import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let sigAlgName = x509Cert.getSignatureAlgName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let sigAlgOid = x509Cert.getSignatureAlgOid();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgOid failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let sigAlgParams = x509Cert.getSignatureAlgParams();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgParams failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let keyUsage = x509Cert.getKeyUsage();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getKeyUsage failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let extKeyUsage = x509Cert.getExtKeyUsage();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let subjectAltNames = x509Cert.getSubjectAltNames();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSubjectAltNames failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let issuerAltNames = x509Cert.getIssuerAltNames();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerAltNames failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getItem<sup>10+</sup>

getItem(itemType: CertItemType) : DataBlob

表示获取X509证书对应的字段。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| [DataBlob](#datablob) | 表示X509证书对应的字段，返回值为DER格式。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let tbs = x509Cert.getItem(certFramework.CertItemType.CERT_ITEM_TYPE_TBS);
      let pubKey = x509Cert.getItem(certFramework.CertItemType.CERT_ITEM_TYPE_PUBLIC_KEY);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getItem failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```
### match<sup>11+</sup>

match(param: X509CertMatchParameters): boolean

判断证书是否与输入参数匹配。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | ------------------------------------------ |
| param | [X509CertMatchParameters](#x509certmatchparameters11) | 是   | 表示需要匹配的参数。 |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| boolean | 当参数匹配时，该方法返回true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function matchX509Cert() {
  const x509Cert = await createX509Cert();
  try {
    // 需业务自行赋值
    const param: certFramework.X509CertMatchParameters = {
      x509Cert,
      validDate: '20231121074700Z',
      issuer: new Uint8Array([0x30, 0x64, 0x31]), // 数据需要业务自行赋值
      keyUsage: [false, false, false, false, false, false, true, true, true],
      serialNumber: BigInt('232100834349818463'),
      subject: new Uint8Array([0x30, 0x6c, 0x31]), // 数据需要业务自行赋值
      publicKey: {
        data: new Uint8Array([0x30, 0x82, 0x01]) // 数据需要业务自行赋值
      },
      publicKeyAlgID: '1.2.840.113549.1.1.1'
    };
    const result = x509Cert.match(param);
    console.log('call x509Cert match success');
  } catch (err) {
    console.error('call x509Cert match failed');
  }
}
```
## cryptoCert.createCertExtension<sup>10+</sup>

createCertExtension(inStream : EncodingBlob, callback : AsyncCallback\<CertExtension>) : void

表示创建证书扩展域段的对象，使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)                     | 是   | 表示证书扩展域段序列化数据 |
| callback | AsyncCallback\<[CertExtension](#certextension10)> | 是   | 回调函数。表示扩展域段对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// 证书扩展域段二进制数据，需业务自行赋值
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
  }
});
```

## cryptoCert.createCertExtension<sup>10+</sup>

createCertExtension(inStream : EncodingBlob) : Promise\<CertExtension>

表示创建证书扩展域段的对象，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                          | 必填 | 说明                       |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | 表示证书扩展域段序列化数据 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<[CertExtension](#certextension10)> | 表示证书扩展域段对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// 证书扩展域段二进制数据，需业务自行赋值
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob).then(certExt => {
  console.log('createCertExtension success');
}).catch((error: BusinessError) => {
  console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## CertExtension<sup>10+</sup>

证书扩展域段类。

### getEncoded<sup>10+</sup>

getEncoded() : EncodingBlob

表示获取证书扩展域段序列化数据。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                          | 说明                         |
| ----------------------------- | ---------------------------- |
| [EncodingBlob](#encodingblob) | 表示证书扩展域段序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// 证书扩展域段二进制数据，需业务自行赋值
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    try {
      let extEncodedBlob = certExt.getEncoded();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext getEncoded failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getOidList<sup>10+</sup>

getOidList(valueType : ExtensionOidType) : DataArray

表示获取证书扩展域段对象标识符列表。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                                  | 必填 | 说明                           |
| --------- | ------------------------------------- | ---- | ------------------------------ |
| valueType | [ExtensionOidType](#extensionoidtype) | 是   | 表示证书扩展域段对象标识符类型 |

**返回值**：

| 类型                    | 说明                             |
| ----------------------- | -------------------------------- |
| [DataArray](#dataarray) | 表示证书扩展域段对象标识符列表。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// 证书扩展域段二进制数据，需业务自行赋值
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    try {
      let oidList = certExt.getOidList(certFramework.ExtensionOidType.EXTENSION_OID_TYPE_ALL);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext getOidList failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getEntry<sup>10+</sup>

getEntry(valueType: ExtensionEntryType, oid : DataBlob) : DataBlob

表示获取证书扩展域段对象信息。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                                      | 必填 | 说明                             |
| --------- | ----------------------------------------- | ---- | -------------------------------- |
| valueType | [ExtensionEntryType](#extensionentrytype) | 是   | 表示证书扩展域段获取的类型       |
| oid       | [DataBlob](#datablob)                     | 是   | 表示证书扩展域段获取的对象标识符 |

**返回值**：

| 类型                  | 说明                         |
| --------------------- | ---------------------------- |
| [DataBlob](#datablob) | 表示证书扩展域段对象的数据。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// 证书扩展域段二进制数据，需业务自行赋值
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    let oid = new Uint8Array([0x32, 0x2e, 0x35, 0x2e, 0x32, 0x39, 0x2e, 0x31, 0x35]);
    let oidBlob: certFramework.DataBlob = {
      data: oid
    }
    try {
      let entry = certExt.getEntry(certFramework.ExtensionEntryType.EXTENSION_ENTRY_TYPE_ENTRY, oidBlob);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext getEntry failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```


### checkCA<sup>10+</sup>

checkCA() : number

表示校验证书是否为CA证书。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 当证书扩展域段中密钥用途包含签名用途，并且基本约束中cA字段为true时，表示证书为CA证书。如果不是CA，则返回-1；否则返回基本约束中的路径长度。如果证书是CA证书，但是基本约束中未给定路径长度，则返回-2，表示无路径长度限制。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// 证书扩展域段二进制数据，需业务自行赋值
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};
certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    try {
      let res = certExt.checkCA();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext checkCA failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### hasUnsupportedCriticalExtension<sup>11+</sup>

hasUnsupportedCriticalExtension(): boolean

判断是否存在不支持的关键扩展。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                    |
| ------- | ------------------------------------------------------- |
| boolean | 当存在不支持的关键扩展时，该方法返回true；否则返回false |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import cert from "@ohos.security.cert";
import { BusinessError } from '@ohos.base';

const encodingData = [
  0x30, 0x40, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04,
  0x05, 0x30, 0x03, 0x01, 0x01, 0xff, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x1d, 0x0f,
];
let encodingBlob: cert.EncodingBlob = {
  data: new Uint8Array(encodingData),
  encodingFormat: cert.EncodingFormat.FORMAT_DER
};

cert.createCertExtension(encodingBlob).then((extensionObj) => {
  console.log('createCertExtension success!');
  const result = extensionObj.hasUnsupportedCriticalExtension()
  console.log('has unsupported critical extension result is:' + result);
}).catch((err: BusinessError) => {
  console.error('createCertExtension failed');
});
```

## cryptoCert.createX509Crl<sup>(deprecated)</sup>

createX509Crl(inStream : EncodingBlob, callback : AsyncCallback\<X509Crl>) : void

表示创建X509证书吊销列表的对象，使用Callback回调异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[cryptoCert.createX509CRL](#cryptocertcreatex509crl11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                | 必填 | 说明                           |
| -------- | ----------------------------------- | ---- | ------------------------------ |
| inStream | [EncodingBlob](#encodingblob)       | 是   | 表示证书吊销列表序列化数据     |
| callback | AsyncCallback\<[X509Crl](#x509crl)> | 是   | 回调函数。表示证书吊销列表对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
  }
});
```

## cryptoCert.createX509Crl<sup>(deprecated)</sup>

createX509Crl(inStream : EncodingBlob) : Promise\<X509Crl>

表示创建X509证书吊销列表的对象，使用Promise方式异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[cryptoCert.createX509CRL](#cryptocertcreatex509crl11-1)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                          | 必填 | 说明                       |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | 表示证书吊销列表序列化数据 |

**返回值**：

| 类型                          | 说明                 |
| ----------------------------- | -------------------- |
| Promise\<[X509Crl](#x509crl)> | 表示证书吊销列表对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## cryptoCert.createX509CRL<sup>11+</sup>

createX509CRL(inStream : EncodingBlob, callback : AsyncCallback\<X509CRL>) : void

表示创建X509证书吊销列表的对象，使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| inStream | [EncodingBlob](#encodingblob)         | 是   | 表示证书吊销列表序列化数据     |
| callback | AsyncCallback\<[X509CRL](#x509crl11)> | 是   | 回调函数。表示证书吊销列表对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, X509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
  }
});
```

## cryptoCert.createX509CRL<sup>11+</sup>

createX509CRL(inStream : EncodingBlob) : Promise\<X509CRL>

表示创建X509证书吊销列表的对象，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                          | 必填 | 说明                       |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | 表示证书吊销列表序列化数据 |

**返回值**：

| 类型                            | 说明                 |
| ------------------------------- | -------------------- |
| Promise\<[X509CRL](#x509crl11)> | 表示证书吊销列表对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob).then(X509CRL => {
  console.log('createX509CRL success');
}).catch((error: BusinessError) => {
  console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## X509Crl<sup>(deprecated)</sup>

X509证书吊销列表对象。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL](#x509crl11)替代。

### isRevoked<sup>(deprecated)</sup>

isRevoked(cert : X509Cert) : boolean

表示检查证书是否吊销。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.isRevoked](#isrevoked11)替代。

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

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

let certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    // Create an X509Cert instance.
    certFramework.createX509Cert(certEncodingBlob, (error, x509Cert) => {
      if (error == null) {
        try {
          let revokedFlag = x509Crl.isRevoked(x509Cert);
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error('isRevoked failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
      }
    });
  }
});
```

### getType<sup>(deprecated)</sup>

getType() : string

表示获取证书吊销列表类型。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getType](#gettype11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 表示证书吊销列表类型 |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let type = x509Crl.getType();
  }
});
```

### getEncoded<sup>(deprecated)</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书吊销列表的序列化数据，使用Callback回调异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getEncoded](#getencoded11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                         | 必填 | 说明                                       |
| -------- | ---------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<EncodingBlob> | 是   | 回调函数，表示X509证书吊销列表的序列化数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    x509Crl.getEncoded((error, data) => {
      if (error != null) {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getEncoded success');
      }
    });
  }
});
```

### getEncoded<sup>(deprecated)</sup>

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书吊销列表的序列化数据，使用Promise方式异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getEncoded](#getencoded11-1)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                   | 说明                             |
| ---------------------- | -------------------------------- |
| Promise\<EncodingBlob> | 表示X509证书吊销列表的序列化数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');
  x509Crl.getEncoded().then(result => {
    console.log('getEncoded success');
  }).catch((error: BusinessError) => {
    console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### verify<sup>(deprecated)</sup>

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

表示对X509证书吊销列表进行验签，使用Callback回调异步返回结果。验签支持RSA算法。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.verify](#verify11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| key      | cryptoFramework.PubKey | 是   | 表示用于验签的公钥对象                                       |
| callback | AsyncCallback\<void> | 是   | 回调函数,使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，error不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
  0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67, 0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C,
  0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20, 0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66,
  0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4, 0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0,
  0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23, 0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C,
  0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22, 0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65,
  0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14, 0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA,
  0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91, 0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01,
  0x00, 0x01
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
  0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE, 0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67,
  0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C, 0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20,
  0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66, 0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4,
  0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0, 0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23,
  0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C, 0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22,
  0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65, 0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14,
  0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA, 0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91,
  0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x81, 0x80, 0x5A, 0xCF, 0x0F,
  0xF5, 0xA6, 0x1C, 0x19, 0x65, 0x8C, 0x94, 0x40, 0xF6, 0x84, 0x28, 0x74, 0x40, 0x42, 0x34, 0xDE,
  0xC3, 0x00, 0x5E, 0x72, 0x4D, 0x96, 0xE9, 0x4C, 0xBD, 0xC9, 0xDB, 0x14, 0x9F, 0xD5, 0xBB, 0xA9,
  0x0C, 0x20, 0xC2, 0xBE, 0x7A, 0x80, 0x89, 0xEC, 0x99, 0x04, 0xF0, 0xEE, 0x7B, 0x83, 0x20, 0x1D,
  0x37, 0x19, 0x55, 0x85, 0xF6, 0x8E, 0x3B, 0xFB, 0x16, 0xF3, 0xD3, 0x6F, 0xEE, 0x73, 0x12, 0x53,
  0xCA, 0x77, 0xD7, 0x6C, 0x29, 0xF5, 0x08, 0xA3, 0x09, 0x01, 0x0B, 0x00, 0x05, 0x57, 0xAD, 0x4D,
  0xF0, 0x92, 0xB2, 0x5A, 0x8B, 0x19, 0x09, 0x81, 0x86, 0xFE, 0x66, 0xB9, 0x33, 0x88, 0x28, 0xF3,
  0x37, 0x73, 0x09, 0x5F, 0xD7, 0xC9, 0xC6, 0xFA, 0x13, 0x74, 0xFE, 0xAE, 0x53, 0xA9, 0x71, 0x67,
  0xCE, 0x3A, 0xE6, 0x8D, 0x35, 0xD1, 0xB8, 0xFD, 0x6F, 0x0D, 0x43, 0xC2, 0xD1, 0x02, 0x41, 0x00,
  0xF7, 0x33, 0xE5, 0x6C, 0x29, 0x5A, 0x30, 0x58, 0xA4, 0x52, 0x65, 0xA0, 0x39, 0xC2, 0xE8, 0xAE,
  0x5F, 0xA3, 0x2D, 0x0C, 0x65, 0xB1, 0x7B, 0xFD, 0x92, 0xBF, 0x47, 0x87, 0x97, 0x40, 0xCB, 0x54,
  0xF9, 0xBB, 0x50, 0x27, 0x70, 0x51, 0xD0, 0xD8, 0x48, 0x0D, 0xC6, 0x47, 0x60, 0xF8, 0x4E, 0x0A,
  0x32, 0x76, 0x6D, 0xA4, 0xBA, 0x40, 0xE5, 0x58, 0xF8, 0x4A, 0x39, 0x4E, 0xF8, 0x3F, 0x4E, 0x2D,
  0x02, 0x41, 0x00, 0xE4, 0x23, 0x2A, 0x5F, 0x59, 0xCF, 0x7C, 0x91, 0x24, 0x0D, 0xA2, 0x44, 0x17,
  0xCD, 0x37, 0xDE, 0x1F, 0x53, 0x4D, 0x33, 0x9F, 0x90, 0x4D, 0xD9, 0x72, 0x64, 0x25, 0xBA, 0xAB,
  0x47, 0x91, 0xC4, 0x99, 0x95, 0x86, 0xB5, 0x8A, 0xEA, 0x77, 0xF7, 0x64, 0x72, 0x5E, 0xB7, 0xBB,
  0x16, 0xA1, 0x64, 0xA4, 0xE1, 0x2D, 0x76, 0x6D, 0xEF, 0xB1, 0x5E, 0xD6, 0x17, 0xE8, 0xAA, 0xB6,
  0xA0, 0xD9, 0x85, 0x02, 0x41, 0x00, 0xDF, 0xC8, 0x5B, 0x28, 0x4F, 0x47, 0x15, 0xFD, 0x28, 0xC4,
  0x6E, 0xBB, 0x5D, 0x8E, 0xD4, 0x95, 0x06, 0x7E, 0xF1, 0x89, 0x07, 0x86, 0x64, 0x78, 0x69, 0x20,
  0x3F, 0xE0, 0xBF, 0x4C, 0x28, 0xC6, 0x04, 0x4D, 0x4D, 0x82, 0x66, 0x6B, 0xAA, 0x64, 0x20, 0xD6,
  0x57, 0x68, 0xC6, 0xA0, 0x02, 0x05, 0xB9, 0x28, 0xFC, 0x98, 0xE3, 0x03, 0x5C, 0x9B, 0xEE, 0x29,
  0x43, 0x37, 0xFA, 0x03, 0x55, 0x01, 0x02, 0x40, 0x69, 0x5B, 0x7C, 0x24, 0x10, 0xDB, 0xEB, 0x91,
  0x33, 0xEF, 0x3F, 0xF2, 0xE6, 0x73, 0x15, 0xCB, 0xF4, 0xF7, 0x89, 0x7D, 0xBF, 0xC0, 0xEA, 0xD2,
  0xF3, 0x2B, 0x20, 0xE9, 0x76, 0x54, 0x55, 0x13, 0x50, 0x42, 0x67, 0xB5, 0xCB, 0x73, 0xC0, 0xF7,
  0x75, 0x62, 0x04, 0x30, 0x21, 0xAC, 0xAF, 0xD8, 0x44, 0xF4, 0xE1, 0x04, 0x02, 0x7D, 0x61, 0x92,
  0x84, 0x99, 0x02, 0x10, 0x64, 0xCB, 0x1F, 0xE9, 0x02, 0x41, 0x00, 0xAB, 0x4B, 0x7D, 0x90, 0x7C,
  0x57, 0x08, 0x6B, 0xC0, 0x43, 0x72, 0x09, 0x8A, 0x18, 0x35, 0x36, 0x64, 0x9D, 0x84, 0x8D, 0xF1,
  0x84, 0x94, 0x48, 0xC6, 0x80, 0x9D, 0xB9, 0xA2, 0x58, 0x0A, 0x4D, 0x0A, 0xCA, 0x1E, 0xD6, 0x05,
  0x55, 0x5B, 0xFE, 0xD7, 0xAA, 0x70, 0xED, 0x76, 0xB3, 0x40, 0x2E, 0xA0, 0xB3, 0x32, 0x37, 0xB0,
  0xA0, 0xB9, 0x96, 0x2D, 0xC4, 0x70, 0xE9, 0x99, 0x10, 0x67, 0x8D
]);

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      // Generate the public key by AsyKeyGenerator.
      let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
      console.log('createAsyKeyGenerator success');
      let priEncodingBlob: cryptoFramework.DataBlob = {
        data: priKeyData,
      };
      let pubEncodingBlob: cryptoFramework.DataBlob = {
        data: pubKeyData,
      };
      keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob, (e, keyPair) => {
        if (e == null) {
          console.log('convert key success');
          x509Crl.verify(keyPair.pubKey, (err, data) => {
            if (err == null) {
              console.log('verify success');
            } else {
              console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
            }
          });
        } else {
          console.error('convert key failed, message: ' + e.message + 'code: ' + e.code);
        }
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### verify<sup>(deprecated)</sup>

verify(key : cryptoFramework.PubKey) : Promise\<void>

表示对X509证书吊销列表进行验签，使用Promise方式异步返回结果。验签支持RSA算法。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.verify](#verify11-1)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| key    | cryptoFramework.PubKey | 是   | 表示用于验签的公钥对象。 |

**返回值**：

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework'
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
  0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67, 0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C,
  0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20, 0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66,
  0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4, 0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0,
  0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23, 0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C,
  0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22, 0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65,
  0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14, 0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA,
  0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91, 0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01,
  0x00, 0x01
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
  0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE, 0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67,
  0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C, 0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20,
  0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66, 0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4,
  0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0, 0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23,
  0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C, 0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22,
  0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65, 0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14,
  0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA, 0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91,
  0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x81, 0x80, 0x5A, 0xCF, 0x0F,
  0xF5, 0xA6, 0x1C, 0x19, 0x65, 0x8C, 0x94, 0x40, 0xF6, 0x84, 0x28, 0x74, 0x40, 0x42, 0x34, 0xDE,
  0xC3, 0x00, 0x5E, 0x72, 0x4D, 0x96, 0xE9, 0x4C, 0xBD, 0xC9, 0xDB, 0x14, 0x9F, 0xD5, 0xBB, 0xA9,
  0x0C, 0x20, 0xC2, 0xBE, 0x7A, 0x80, 0x89, 0xEC, 0x99, 0x04, 0xF0, 0xEE, 0x7B, 0x83, 0x20, 0x1D,
  0x37, 0x19, 0x55, 0x85, 0xF6, 0x8E, 0x3B, 0xFB, 0x16, 0xF3, 0xD3, 0x6F, 0xEE, 0x73, 0x12, 0x53,
  0xCA, 0x77, 0xD7, 0x6C, 0x29, 0xF5, 0x08, 0xA3, 0x09, 0x01, 0x0B, 0x00, 0x05, 0x57, 0xAD, 0x4D,
  0xF0, 0x92, 0xB2, 0x5A, 0x8B, 0x19, 0x09, 0x81, 0x86, 0xFE, 0x66, 0xB9, 0x33, 0x88, 0x28, 0xF3,
  0x37, 0x73, 0x09, 0x5F, 0xD7, 0xC9, 0xC6, 0xFA, 0x13, 0x74, 0xFE, 0xAE, 0x53, 0xA9, 0x71, 0x67,
  0xCE, 0x3A, 0xE6, 0x8D, 0x35, 0xD1, 0xB8, 0xFD, 0x6F, 0x0D, 0x43, 0xC2, 0xD1, 0x02, 0x41, 0x00,
  0xF7, 0x33, 0xE5, 0x6C, 0x29, 0x5A, 0x30, 0x58, 0xA4, 0x52, 0x65, 0xA0, 0x39, 0xC2, 0xE8, 0xAE,
  0x5F, 0xA3, 0x2D, 0x0C, 0x65, 0xB1, 0x7B, 0xFD, 0x92, 0xBF, 0x47, 0x87, 0x97, 0x40, 0xCB, 0x54,
  0xF9, 0xBB, 0x50, 0x27, 0x70, 0x51, 0xD0, 0xD8, 0x48, 0x0D, 0xC6, 0x47, 0x60, 0xF8, 0x4E, 0x0A,
  0x32, 0x76, 0x6D, 0xA4, 0xBA, 0x40, 0xE5, 0x58, 0xF8, 0x4A, 0x39, 0x4E, 0xF8, 0x3F, 0x4E, 0x2D,
  0x02, 0x41, 0x00, 0xE4, 0x23, 0x2A, 0x5F, 0x59, 0xCF, 0x7C, 0x91, 0x24, 0x0D, 0xA2, 0x44, 0x17,
  0xCD, 0x37, 0xDE, 0x1F, 0x53, 0x4D, 0x33, 0x9F, 0x90, 0x4D, 0xD9, 0x72, 0x64, 0x25, 0xBA, 0xAB,
  0x47, 0x91, 0xC4, 0x99, 0x95, 0x86, 0xB5, 0x8A, 0xEA, 0x77, 0xF7, 0x64, 0x72, 0x5E, 0xB7, 0xBB,
  0x16, 0xA1, 0x64, 0xA4, 0xE1, 0x2D, 0x76, 0x6D, 0xEF, 0xB1, 0x5E, 0xD6, 0x17, 0xE8, 0xAA, 0xB6,
  0xA0, 0xD9, 0x85, 0x02, 0x41, 0x00, 0xDF, 0xC8, 0x5B, 0x28, 0x4F, 0x47, 0x15, 0xFD, 0x28, 0xC4,
  0x6E, 0xBB, 0x5D, 0x8E, 0xD4, 0x95, 0x06, 0x7E, 0xF1, 0x89, 0x07, 0x86, 0x64, 0x78, 0x69, 0x20,
  0x3F, 0xE0, 0xBF, 0x4C, 0x28, 0xC6, 0x04, 0x4D, 0x4D, 0x82, 0x66, 0x6B, 0xAA, 0x64, 0x20, 0xD6,
  0x57, 0x68, 0xC6, 0xA0, 0x02, 0x05, 0xB9, 0x28, 0xFC, 0x98, 0xE3, 0x03, 0x5C, 0x9B, 0xEE, 0x29,
  0x43, 0x37, 0xFA, 0x03, 0x55, 0x01, 0x02, 0x40, 0x69, 0x5B, 0x7C, 0x24, 0x10, 0xDB, 0xEB, 0x91,
  0x33, 0xEF, 0x3F, 0xF2, 0xE6, 0x73, 0x15, 0xCB, 0xF4, 0xF7, 0x89, 0x7D, 0xBF, 0xC0, 0xEA, 0xD2,
  0xF3, 0x2B, 0x20, 0xE9, 0x76, 0x54, 0x55, 0x13, 0x50, 0x42, 0x67, 0xB5, 0xCB, 0x73, 0xC0, 0xF7,
  0x75, 0x62, 0x04, 0x30, 0x21, 0xAC, 0xAF, 0xD8, 0x44, 0xF4, 0xE1, 0x04, 0x02, 0x7D, 0x61, 0x92,
  0x84, 0x99, 0x02, 0x10, 0x64, 0xCB, 0x1F, 0xE9, 0x02, 0x41, 0x00, 0xAB, 0x4B, 0x7D, 0x90, 0x7C,
  0x57, 0x08, 0x6B, 0xC0, 0x43, 0x72, 0x09, 0x8A, 0x18, 0x35, 0x36, 0x64, 0x9D, 0x84, 0x8D, 0xF1,
  0x84, 0x94, 0x48, 0xC6, 0x80, 0x9D, 0xB9, 0xA2, 0x58, 0x0A, 0x4D, 0x0A, 0xCA, 0x1E, 0xD6, 0x05,
  0x55, 0x5B, 0xFE, 0xD7, 0xAA, 0x70, 0xED, 0x76, 0xB3, 0x40, 0x2E, 0xA0, 0xB3, 0x32, 0x37, 0xB0,
  0xA0, 0xB9, 0x96, 0x2D, 0xC4, 0x70, 0xE9, 0x99, 0x10, 0x67, 0x8D
]);

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');

  try {
    // 生成公钥对象
    let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
    console.log('createAsyKeyGenerator success');
    let priEncodingBlob: cryptoFramework.DataBlob = {
      data: priKeyData,
    };
    let pubEncodingBlob: cryptoFramework.DataBlob = {
      data: pubKeyData,
    };
    keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob).then((keyPair) => {
      console.log('convert key success');
      x509Crl.verify(keyPair.pubKey).then(result => {
        console.log('verify success');
      }).catch((error: BusinessError) => {
        console.error('verify failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    }).catch((error: BusinessError) => {
      console.error('convert key failed, message: ' + error.message + 'code: ' + error.code);
    });
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getVersion<sup>(deprecated)</sup>

getVersion() : number

表示获取X509证书吊销列表的版本号。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getVersion](#getversion11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| number | 表示获取X509证书吊销列表的版本号 |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let version = x509Crl.getVersion();
  }
});
```

### getIssuerName<sup>(deprecated)</sup>

getIssuerName() : DataBlob

表示获取X509证书吊销列表颁发者名称。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getIssuerName](#getissuername11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表颁发者名称 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let issuerName = x509Crl.getIssuerName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getLastUpdate<sup>(deprecated)</sup>

getLastUpdate() : string

表示获取X509证书吊销列表最后一次更新日期。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getLastUpdate](#getlastupdate11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表最后一次更新日期 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let lastUpdate = x509Crl.getLastUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getLastUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNextUpdate<sup>(deprecated)</sup>

getNextUpdate() : string

表示获取证书吊销列表下一次更新的日期。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getNextUpdate](#getnextupdate11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表下一次更新的日期 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let nextUpdate = x509Crl.getNextUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNextUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCert<sup>(deprecated)</sup>

getRevokedCert(serialNumber : number) : X509CrlEntry

表示通过指定证书序列号获取被吊销X509证书对象。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getRevokedCert](#getrevokedcert11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名       | 类型   | 必填 | 说明           |
| ------------ | ------ | ---- | -------------- |
| serialNumber | number | 是   | 表示证书序列号 |

**返回值**:

| 类型                   | 说明                   |
| ---------------------- | --------------------- |
| [X509CrlEntry](#x509crlentry) | 表示被吊销X509证书对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let serialNumber = 1000;
    try {
      let entry = x509Crl.getRevokedCert(serialNumber);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCertWithCert<sup>(deprecated)</sup>

getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry

表示通过指定证书对象获取被吊销X509证书对象。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getRevokedCertWithCert](#getrevokedcertwithcert11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型                  | 必填 | 说明         |
| ------ | --------------------- | ---- | ------------ |
| cert   | [X509Cert](#x509cert) | 是   | 表示证书对象 |

**返回值**:

| 类型         | 说明                  |
| ------------ | -------------------- |
| [X509CrlEntry](#x509crlentry) | 表示被吊销X509证书对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n'
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n'
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n'
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n'
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n'
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n'
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n'
  'Qw==\n'
  '-----END CERTIFICATE-----\n';

let certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    // 创建X509证书对象.
    certFramework.createX509Cert(certEncodingBlob).then((x509Cert) => {
      try {
        let entry = x509Crl.getRevokedCertWithCert(x509Cert);
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error('getRevokedCertWithCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }).catch((error: BusinessError) => {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    })
  }
});
```

### getRevokedCerts<sup>(deprecated)</sup>

getRevokedCerts(callback : AsyncCallback<Array\<X509CrlEntry>>) : void

表示获取被吊销X509证书列表，使用Callback回调异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getRevokedCerts](#getrevokedcerts11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                                 | 必填 | 说明                             |
| -------- | ---------------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback<Array\<[X509CrlEntry](#x509crlentry)>> | 是   | 回调函数。表示被吊销X509证书列表 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    x509Crl.getRevokedCerts((error, array) => {
      if (error != null) {
        console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getRevokedCerts success');
      }
    });
  }
});
```

### getRevokedCerts<sup>(deprecated)</sup>

getRevokedCerts() : Promise<Array\<X509CrlEntry>>

表示获取被吊销X509证书列表，使用Promise方式异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getRevokedCerts](#getrevokedcerts11-1)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                                           | 说明                   |
| ---------------------------------------------- | ---------------------- |
| Promise<Array\<[X509CrlEntry](#x509crlentry)>> | 表示被吊销X509证书列表 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');
  x509Crl.getRevokedCerts().then(array => {
    console.log('getRevokedCerts success');
  }).catch((error: BusinessError) => {
    console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getTbsInfo<sup>(deprecated)</sup>

getTbsInfo() : DataBlob

表示获取证书吊销列表的tbsCertList信息。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getTBSInfo](#gettbsinfo11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| [DataBlob](#datablob) | 表示证书吊销列表的tbsCertList信息 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let tbsInfo = x509Crl.getTbsInfo();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getTbsInfo failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignature<sup>(deprecated)</sup>

getSignature() : DataBlob

表示获取X509证书吊销列表的签名数据。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getSignature](#getsignature11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表的签名数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let signature = x509Crl.getSignature();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignature failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgName<sup>(deprecated)</sup>

getSignatureAlgName() : string

表示获取X509证书吊销列表签名的算法名称。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getSignatureAlgName](#getsignaturealgname11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| string | 表示X509证书吊销列表签名的算法名 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let sigAlgName = x509Crl.getSignatureAlgName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgOid<sup>(deprecated)</sup>

getSignatureAlgOid() : string

表示获取X509证书吊销列表签名算法的对象标志符OID(Object Identifier)。OID是由国际标准组织(ISO)的名称注册机构分配。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getSignatureAlgOid](#getsignaturealgoid11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                          |
| ------ | --------------------------------------------- |
| string | 表示X509证书吊销列表签名算法的对象标志符OID。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let sigAlgOid = x509Crl.getSignatureAlgOid();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgOid failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgParams<sup>(deprecated)</sup>

getSignatureAlgParams() : DataBlob

表示获取X509证书吊销列表签名的算法参数。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getSignatureAlgParams](#getsignaturealgparams11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| [DataBlob](#datablob) | 表示X509证书吊销列表签名的算法参数 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let sigAlgParams = x509Crl.getSignatureAlgParams();
    } catch (err) {
      let e: BusinessError = error as BusinessError;
      console.error('getSignatureAlgParams failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```
## X509CRL<sup>11+</sup>

被吊销证书列表对象。

### isRevoked<sup>11+</sup>

isRevoked(cert : X509Cert) : boolean

表示检查证书是否吊销。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型     | 必填 | 说明                 |
| ------ | -------- | ---- | -------------------- |
| cert   | [X509Cert](#x509cert) | 是   | 表示被检查的证书对象 |

**返回值**：

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| boolean | 表示证书吊销状态，true表示已吊销，false表示未吊销 |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

let certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    // Create an X509Cert instance.
    certFramework.createX509Cert(certEncodingBlob, (error, x509Cert) => {
      if (error == null) {
        try {
          let revokedFlag = x509CRL.isRevoked(x509Cert);
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error('isRevoked failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
      }
    });
  }
});
```

### getType<sup>11+</sup>

getType() : string

表示获取证书吊销列表类型。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 表示证书吊销列表类型 |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    let type = x509CRL.getType();
  }
});
```

### getEncoded<sup>11+</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书吊销列表的序列化数据，使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数，表示X509证书吊销列表的序列化数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    x509CRL.getEncoded((error, data) => {
      if (error != null) {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getEncoded success');
      }
    });
  }
});
```

### getEncoded<sup>11+</sup>

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书吊销列表的序列化数据，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                             |
| --------------------------------------- | -------------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示X509证书吊销列表的序列化数据 |
**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob).then(x509CRL => {
  console.log('createX509CRL success');
  x509CRL.getEncoded().then(result => {
    console.log('getEncoded success');
  }).catch((error: BusinessError) => {
    console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### verify<sup>11+</sup>

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

表示对X509证书吊销列表进行验签，使用Callback回调异步返回结果。验签支持RSA算法。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | [cryptoFramework.PubKey](js-apis-cryptoFramework.md#pubkey) | 是   | 表示用于验签的公钥对象                                       |
| callback | AsyncCallback\<void>                                        | 是   | 回调函数,使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，error不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
]);

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      // Generate the public key by AsyKeyGenerator.
      let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
      console.log('createAsyKeyGenerator success');
      let priEncodingBlob: cryptoFramework.DataBlob = {
        data: priKeyData,
      };
      let pubEncodingBlob: cryptoFramework.DataBlob = {
        data: pubKeyData,
      };
      keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob, (e, keyPair) => {
        if (e == null) {
          console.log('convert key success');
          x509CRL.verify(keyPair.pubKey, (err, data) => {
            if (err == null) {
              console.log('verify success');
            } else {
              console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
            }
          });
        } else {
          console.error('convert key failed, message: ' + e.message + 'code: ' + e.code);
        }
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### verify<sup>11+</sup>

verify(key : cryptoFramework.PubKey) : Promise\<void>

表示对X509证书吊销列表进行验签，使用Promise方式异步返回结果。验签支持RSA算法。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型                                                        | 必填 | 说明                     |
| ------ | ----------------------------------------------------------- | ---- | ------------------------ |
| key    | [cryptoFramework.PubKey](js-apis-cryptoFramework.md#pubkey) | 是   | 表示用于验签的公钥对象。 |

**返回值**：

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework'
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
]);

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob).then(x509CRL => {
  console.log('createX509Crl success');

  try {
    // 生成公钥对象
    let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
    console.log('createAsyKeyGenerator success');
    let priEncodingBlob: cryptoFramework.DataBlob = {
      data: priKeyData,
    };
    let pubEncodingBlob: cryptoFramework.DataBlob = {
      data: pubKeyData,
    };
    keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob).then((keyPair) => {
      console.log('convert key success');
      x509CRL.verify(keyPair.pubKey).then(result => {
        console.log('verify success');
      }).catch((error: BusinessError) => {
        console.error('verify failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    }).catch((error: BusinessError) => {
      console.error('convert key failed, message: ' + error.message + 'code: ' + error.code);
    });
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getVersion<sup>11+</sup>

getVersion() : number

表示获取X509证书吊销列表的版本号。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| number | 表示获取X509证书吊销列表的版本号 |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    let version = x509CRL.getVersion();
  }
});
```

### getIssuerName<sup>11+</sup>

getIssuerName() : DataBlob

表示获取X509证书吊销列表颁发者名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表颁发者名称 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let issuerName = x509CRL.getIssuerName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getLastUpdate<sup>11+</sup>

getLastUpdate() : string

表示获取X509证书吊销列表最后一次更新日期。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表最后一次更新日期 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let lastUpdate  = x509CRL.getLastUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getLastUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNextUpdate<sup>11+</sup>

getNextUpdate() : string

表示获取证书吊销列表下一次更新的日期。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表下一次更新的日期 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let nextUpdate = x509CRL.getNextUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNextUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCert<sup>11+</sup>

getRevokedCert(serialNumber : bigint) : X509CRLEntry

表示通过指定证书序列号获取被吊销X509证书对象。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名       | 类型   | 必填 | 说明           |
| ------------ | ------ | ---- | -------------- |
| serialNumber | bigint | 是   | 表示证书序列号 |

**返回值**:

| 类型                            | 说明                   |
| ------------------------------- | ---------------------- |
| [X509CRLEntry](#x509crlentry11) | 表示被吊销X509证书对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    let serialNumber = BigInt(1000);
    try {
      let entry = x509CRL.getRevokedCert(serialNumber);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCertWithCert<sup>11+</sup>

getRevokedCertWithCert(cert : X509Cert) : X509CRLEntry

表示通过指定证书对象获取被吊销X509证书对象。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型                  | 必填 | 说明         |
| ------ | --------------------- | ---- | ------------ |
| cert   | [X509Cert](#x509cert) | 是   | 表示证书对象 |

**返回值**:

| 类型                            | 说明                   |
| ------------------------------- | ---------------------- |
| [X509CRLEntry](#x509crlentry11) | 表示被吊销X509证书对象 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书二进制数据，需业务自行赋值
let certData = '-----BEGIN CERTIFICATE-----\n'
'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n'
'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n'
'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n'
'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n'
'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n'
'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n'
'Qw==\n'
'-----END CERTIFICATE-----\n';

let certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    // 创建X509证书对象.
    certFramework.createX509Cert(certEncodingBlob).then((x509Cert) => {
      try {
        let entry = x509CRL.getRevokedCertWithCert(x509Cert);
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error('getRevokedCertWithCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }).catch((error: BusinessError) => {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    })
  }
});
```

### getRevokedCerts<sup>11+</sup>

getRevokedCerts(callback : AsyncCallback<Array\<X509CRLEntry>>) : void

表示获取被吊销X509证书列表，使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                                   | 必填 | 说明                             |
| -------- | ------------------------------------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback<Array\<[X509CRLEntry](#x509crlentry11)>> | 是   | 回调函数。表示被吊销X509证书列表 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    x509CRL.getRevokedCerts((error, array) => {
      if (error != null) {
        console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getRevokedCerts success');
      }
    });
  }
});
```

### getRevokedCerts<sup>11+</sup>

getRevokedCerts() : Promise<Array\<X509CRLEntry>>

表示获取被吊销X509证书列表，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                                             | 说明                   |
| ------------------------------------------------ | ---------------------- |
| Promise<Array\<[X509CRLEntry](#x509crlentry11)>> | 表示被吊销X509证书列表 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob).then(x509CRL => {
  console.log('createX509CRL success');
  x509CRL.getRevokedCerts().then(array => {
    console.log('getRevokedCerts success');
  }).catch((error: BusinessError) => {
    console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getSignature<sup>11+</sup>

getSignature() : DataBlob

表示获取X509证书吊销列表的签名数据。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表的签名数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let signature = x509CRL.getSignature();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignature failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgName<sup>11+</sup>

getSignatureAlgName() : string

表示获取X509证书吊销列表签名的算法名称。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| string | 表示X509证书吊销列表签名的算法名 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let sigAlgName = x509CRL.getSignatureAlgName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgOid<sup>11+</sup>

getSignatureAlgOid() : string

表示获取X509证书吊销列表签名算法的对象标志符OID(Object Identifier)。OID是由国际标准组织(ISO)的名称注册机构分配。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                          |
| ------ | --------------------------------------------- |
| string | 表示X509证书吊销列表签名算法的对象标志符OID。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let sigAlgOid = x509CRL.getSignatureAlgOid();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgOid failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgParams<sup>11+</sup>

getSignatureAlgParams() : DataBlob

表示获取X509证书吊销列表签名的算法参数。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| [DataBlob](#datablob) | 表示X509证书吊销列表签名的算法参数 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let sigAlgParams = x509CRL.getSignatureAlgParams();
    } catch (err) {
      let e: BusinessError = error as BusinessError;
      console.error('getSignatureAlgParams failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getTBSInfo<sup>11+</sup>

getTBSInfo() : DataBlob

表示获取证书吊销列表的tbsCertList信息。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| [DataBlob](#datablob) | 表示证书吊销列表的tbsCertList信息 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let tbsInfo = x509CRL.getTBSInfo();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getTBSInfo failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getExtensions<sup>11+</sup>

getExtensions(): DataBlob

表示获取CRL的扩展。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                |
| --------------------- | ------------------- |
| [DataBlob](#datablob) | 表示X509CRL扩展用途 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let extensions = x509CRL.getExtensions();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getExtensions failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### match<sup>11+</sup>

match(param: X509CRLMatchParameters): boolean

判断证书吊销列表是否与输入参数匹配。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | ------------------------------------------ |
| param | [X509CRLMatchParameters](#x509crlmatchparameters11)| 是   | 表示需要匹配的参数。 |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| boolean | 当参数匹配时，该方法返回true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 19020001 | memory error.  |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值
let crlEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

const certData = "-----BEGIN CERTIFICATE-----\r\n" +
  "MIIC8TCCAdmgAwIBAgIIFB75m06RTHwwDQYJKoZIhvcNAQELBQAwWDELMAkGA1UE\r\n" +
  "BhMCQ04xEDAOBgNVBAgTB0ppYW5nc3UxEDAOBgNVBAcTB05hbmppbmcxCzAJBgNV\r\n" +
  "BAoTAnRzMQswCQYDVQQLEwJ0czELMAkGA1UEAxMCdHMwHhcNMjMxMTIzMDMzMjAw\r\n" +
  "WhcNMjQxMTIzMDMzMjAwWjBhMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHSmlhbmdz\r\n" +
  "dTEQMA4GA1UEBxMHTmFuamluZzEMMAoGA1UEChMDdHMxMQwwCgYDVQQLEwN0czEx\r\n" +
  "EjAQBgNVBAMTCTEyNy4wLjAuMTAqMAUGAytlcAMhALsWnY9cMNC6jzduM69vI3Ej\r\n" +
  "pUlgHtEHS8kRfmYBupJSo4GvMIGsMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFNSg\r\n" +
  "poQvfxR8A1Y4St8NjOHkRpm4MAsGA1UdDwQEAwID+DAnBgNVHSUEIDAeBggrBgEF\r\n" +
  "BQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEyNy4wLjAuMTAR\r\n" +
  "BglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0\r\n" +
  "ZTANBgkqhkiG9w0BAQsFAAOCAQEAfnLmPF6BtAUCZ9pjt1ITdXc5M4LJfMw5IPcv\r\n" +
  "fUAvhdaUXtqBQcjGCWtDdhyb1n5Xp+N7oKz/Cnn0NGFTwVArtFiQ5NEP2CmrckLh\r\n" +
  "Da4VnsDFU+zx2Bbfwo5Ms7iArxyx0fArbMZzN9D1lZcVjiIxp1+3k1/0sdCemcY/\r\n" +
  "y7mw5NwkcczLWLBZl1/Ho8b4dlo1wTA7TZk9uu8UwYBwXDrQe6S9rMcvMcRKiJ9e\r\n" +
  "V4SYZIO7ihr8+n4LQDQP+spvX4cf925a3kyZrftfvGCJ2ZNwvsPhyumYhaBqAgSy\r\n" +
  "Up2BImymAqPi157q9EeYcQz170TtDZHGmjYzdQxhOAHRb6/IdQ==\r\n" +
  "-----END CERTIFICATE-----\r\n";
const certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM,
};

async function crlMatch() {
  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(certEncodingBlob);
    console.log('createX509Cert success');
  } catch (err) {
    console.error('createX509Cert failed');
  }

  certFramework.createX509CRL(crlEncodingBlob, (error, x509CRL) => {
    if (error != null) {
      console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
      console.log('createX509CRL success');
      try {
        const param: certFramework.X509CRLMatchParameters = {
          issuer: [new Uint8Array([0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x4A, 0x69, 0x61, 0x6E, 0x67, 0x73, 0x75, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x4E, 0x61, 0x6E, 0x6A, 0x69, 0x6E, 0x67, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x02, 0x74, 0x73])],
          x509Cert: x509Cert
        }
        const result = x509CRL.match(param);
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error('x509CRL match failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }
  });
}
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

try {
  let validator = certFramework.createCertChainValidator('PKIX');
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('createCertChainValidator failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```

## CertChainValidator

证书链校验器对象。


### 属性

**系统能力：** SystemCapability.Security.Cert

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | -------------------------- |
| algorithm  | string | 是   | 否   | X509证书链校验器算法名称。 |


### validate

validate(certChain : CertChainData, callback : AsyncCallback\<void>) : void

表示校验X509证书链，使用Callback回调异步返回结果。
由于端侧系统时间不可信，证书链校验不包含对证书有效时间的校验。如果需要检查证书的时间有效性，可使用X509证书的[checkValidityWithDate](#checkvaliditywithdate)方法进行检查。详见[证书规格](../../security/cert-overview.md#证书规格)

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| certChain | [CertChainData](#certchaindata) | 是   | 表示X509证书链序列化数据                                     |
| callback  | AsyncCallback\<void>            | 是   | 回调函数。使用AsyncCallback的第一个error参数判断是否校验成功，error为null表示成功，error不为null表示失败 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.                           |
| 19030002 | the certificate signature verification failed.    |
| 19030003 | the certificate has not taken effect.             |
| 19030004 | the certificate has expired.                      |
| 19030005 | failed to obtain the certificate issuer.          |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.     |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// 证书链二进制数据，需业务自行赋值
let certChainBuff = new Uint8Array([0x30, 0x82, 0x44]);

let certChainData: certFramework.CertChainData = {
  data: certChainBuff,
  // 证书链包含的证书个数，需业务自行赋值
  count: 2,
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

try {
  let validator = certFramework.createCertChainValidator('PKIX');
  validator.validate(certChainData, (error, data) => {
    if (error != null) {
      console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
      console.log('validate success');
    }
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```

### validate

validate(certChain : CertChainData) : Promise\<void>

表示校验X509证书链，使用Promise方式异步返回结果。
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

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.                           |
| 19030002 | the certificate signature verification failed.    |
| 19030003 | the certificate has not taken effect.             |
| 19030004 | the certificate has expired.                      |
| 19030005 | failed to obtain the certificate issuer.          |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.     |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// 证书链二进制数据，需业务自行赋值
let certChainBuff = new Uint8Array([0x30, 0x82, 0x44]);

let certChainData: certFramework.CertChainData = {
  data: certChainBuff,
  // 证书链包含的证书个数，需业务自行赋值
  count: 2,
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

try {
  let validator = certFramework.createCertChainValidator('PKIX');
  validator.validate(certChainData).then(result => {
    console.log('validate success');
  }).catch((error: BusinessError) => {
    console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
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

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

try {
  let validator = certFramework.createCertChainValidator('PKIX');
  let algorithm = validator.algorithm;
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('createCertChainValidator failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```

## X509CrlEntry<sup>(deprecated)</sup>

被吊销证书对象。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CrlEntry](#x509crlentry11)替代。

### getEncoded<sup>(deprecated)</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取被吊销证书的序列化数据，使用Callback回调异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getEncoded](#getencoded11-2)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                                 |
| -------- | --------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数。表示被吊销证书的序列化数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      crlEntry.getEncoded((error, data) => {
        if (error != null) {
          console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
        } else {
          console.log('getEncoded success');
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getEncoded<sup>(deprecated)</sup>

getEncoded() : Promise\<EncodingBlob>

表示获取被吊销证书的序列化数据，使用Promise方式异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getEncoded](#getencoded11-3)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示被吊销证书的序列化数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      crlEntry.getEncoded().then(result => {
        console.log('getEncoded success');
      }).catch((error: BusinessError) => {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getSerialNumber<sup>(deprecated)</sup>

getSerialNumber() : number

表示获取被吊销证书的序列号。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getSerialNumber](#getserialnumber11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 表示被吊销证书的序列号 |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      serialNumber = crlEntry.getSerialNumber();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getSerialNumber failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getCertIssuer<sup>(deprecated)</sup>

getCertIssuer() : DataBlob

表示获取被吊销证书的颁发者信息。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getCertIssuer](#getcertissuer11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                     |
| --------------------- | ----------------------- |
| [DataBlob](#datablob) | 表示被吊销证书的颁发者信息 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 19020001 | memory error.  |
| 19020002 | runtime error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      let issuer = crlEntry.getCertIssuer();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getCertIssuer failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getRevocationDate<sup>(deprecated)</sup>

getRevocationDate() : string

表示获取证书被吊销的日期。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getRevocationDate](#getrevocationdate11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                |
| ------ | ------------------ |
| string | 表示证书被吊销的日期 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      let date = crlEntry.getRevocationDate();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getRevocationDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

## X509CRLEntry<sup>11+</sup>

被吊销证书对象。

### getEncoded<sup>11+</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取被吊销证书的序列化数据，使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                                 |
| -------- | --------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数。表示被吊销证书的序列化数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      crlEntry.getEncoded((error, data) => {
        if (error != null) {
          console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
        } else {
          console.log('getEncoded success');
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getEncoded<sup>11+</sup>

getEncoded() : Promise\<EncodingBlob>

表示获取被吊销证书的序列化数据，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示被吊销证书的序列化数据 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      crlEntry.getEncoded().then(result => {
        console.log('getEncoded success');
      }).catch((error: BusinessError) => {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getSerialNumber<sup>11+</sup>

getSerialNumber() : bigint

表示获取被吊销证书的序列号。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                   |
| ------ | ---------------------- |
| bigint | 表示被吊销证书的序列号 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      serialNumber = crlEntry.getSerialNumber();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getSerialNumber failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getCertIssuer<sup>11+</sup>

getCertIssuer() : DataBlob

表示获取被吊销证书的颁发者信息。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                       |
| --------------------- | -------------------------- |
| [DataBlob](#datablob) | 表示被吊销证书的颁发者信息 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let issuer = crlEntry.getCertIssuer();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getCertIssuer failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getRevocationDate<sup>11+</sup>

getRevocationDate() : string

表示获取证书被吊销的日期。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 表示证书被吊销的日期 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let date = crlEntry.getRevocationDate();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getRevocationDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getExtensions<sup>11+</sup>

getExtensions(): DataBlob

表示获取CRL的扩展。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | 表示X509CRLEntry扩展用途 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let extensions = crlEntry.getExtensions();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getExtensions failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### hasExtensions<sup>11+</sup>

hasExtensions(): boolean

表示判断CRL Entry是否有扩展。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                 |
| ------- | ---------------------------------------------------- |
| boolean | 返回true则表示CRL Entry有扩展，返回false则表示无扩展 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let hasExtensions = crlEntry.hasExtensions();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or hasExtensions failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```
## cryptoCert.createCertCRLCollection<sup>11+</sup>

createCertCRLCollection(certs: Array\<X509Cert>, crls?: Array\<X509CRL>): CertCRLCollection

表示创建证书和证书吊销列表集合对象，并返回相应的结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| certs | Array\<[X509Cert](#x509cert)>    | 是   |  X509Cert数组。  |
| crls | Array\<[X509CRL](#x509crl11)>     | 否   |  X509CRL数组。  |

**返回值**：

| 类型               | 说明                 |
| ------------------ | -------------------- |
| [CertCRLCollection](#certcrlcollection11) | 表示证书和证书吊销列表集合对象。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CRL(): Promise<certFramework.X509CRL> {
  let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
    'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
    'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
    'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
    '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
    'eavsH0Q3\n' +
    '-----END X509 CRL-----\n';

  // 证书吊销列表二进制数据，需业务自行赋值
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(crlData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CRL: certFramework.X509CRL = {} as certFramework.X509CRL;
  try {
    x509CRL = await certFramework.createX509CRL(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CRL;
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function createCollection() {
  const x509Cert = await createX509Cert();
  const x509CRL = await createX509CRL();
  try {
    const collection: certFramework.CertCRLCollection = certFramework.createCertCRLCollection([x509Cert], [x509CRL]);
    console.log('createCertCRLCollection success');
  } catch (err) {
    console.error('createCertCRLCollection failed');
  }
}
```

## CertCRLCollection<sup>11+</sup>

证书和证书吊销列表集合对象。

### selectCerts<sup>11+</sup>

selectCerts(param: X509CertMatchParameters): Promise\<Array\<X509Cert>>

查找证书和证书吊销列表集合中所有与参数匹配的证书对象，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明      |
| --------- | ------------------------------- | ---- | ------------ |
| param | [X509CertMatchParameters](#x509certmatchparameters11) | 是   | 表示证书需匹配的参数。  |

**返回值**：

| 类型                                    | 说明                                    |
| --------------------------------------- | --------------------------------------- |
| Promise\<Array\<[X509Cert](#x509cert)>> | Promise对象。表示匹配到的证书对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function selectCerts() {
  const x509Cert = await createX509Cert();
  const collection = certFramework.createCertCRLCollection([x509Cert]);

  try {
    const param: certFramework.X509CertMatchParameters = {
      x509Cert,
      validDate: '20231121074700Z',
      issuer: new Uint8Array([0x30, 0x64, 0x31]), // 数据需要业务自行赋值      
      keyUsage: [false, false, false, false, false, false, true, true, true],
      serialNumber: BigInt('232100834349818463'),
      subject: new Uint8Array([0x30, 0x6c, 0x31]), // 数据需要业务自行赋值
      publicKey: {
        data: new Uint8Array([0x30, 0x82, 0x01]) // 数据需要业务自行赋值
      },
      publicKeyAlgID: '1.2.840.113549.1.1.1'
    };
    const certs = await collection.selectCerts(param);
    console.log('call selectCerts success');
  } catch (err) {
    console.error('call selectCerts failed');
  }
}
```

### selectCerts<sup>11+</sup>

selectCerts(param: X509CertMatchParameters, callback: AsyncCallback\<Array\<X509Cert>>): void

查找证书和证书吊销列表集合中所有与参数匹配的证书对象, 使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明            |
| --------- | ------------------------------- | ---- | ----------------- |
| param | [X509CertMatchParameters](#x509certmatchparameters11) | 是   | 表示证书需匹配的参数。   |
| callback  | AsyncCallback\<Array\<[X509Cert](#x509cert)>>    | 是   | 回调函数。表示匹配到的证书对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function selectCerts() {
  const x509Cert = await createX509Cert();
  const collection = certFramework.createCertCRLCollection([x509Cert]);
  // 需业务自行赋值
  const param: certFramework.X509CertMatchParameters = {
    x509Cert,
    validDate: '20231121074700Z',
    issuer: new Uint8Array([0x30, 0x64, 0x31]), // 数据需要业务自行赋值
    keyUsage: [false, false, false, false, false, false, true, true, true],
    serialNumber: BigInt('232100834349818463'),
    subject: new Uint8Array([0x30, 0x6c, 0x31]), // 数据需要业务自行赋值
    publicKey: {
      data: new Uint8Array([0x30, 0x82, 0x01]) // 数据需要业务自行赋值
    },
    publicKeyAlgID: '1.2.840.113549.1.1.1'
  };
  collection.selectCerts(param, (err, certs) => {
    if (err != null) {
      console.error('selectCerts failed, errCode: ' + err.code + ', errMsg: ' + err.message);
    } else {
      console.log('selectCerts success');
    }
  });
}
```

### selectCRLs<sup>11+</sup>

selectCRLs(param: X509CRLMatchParameters): Promise\<Array\<X509CRL>>

查找证书和证书吊销列表集合中所有与参数匹配的证书吊销列表对象, 使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明      |
| --------- | ------------------------------- | ---- | ------------ |
| param | [X509CRLMatchParameters](#x509crlmatchparameters11) | 是   | 表示证书吊销列表需匹配的参数。   |

**返回值**：

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<Array\<[X509CRL](#x509crl)>> | Promise对象。表示匹配到的证书吊销列表对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CRL(): Promise<certFramework.X509CRL> {
  let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
    'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
    'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
    'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
    '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
    'eavsH0Q3\n' +
    '-----END X509 CRL-----\n';

  // 证书吊销列表二进制数据，需业务自行赋值
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(crlData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CRL: certFramework.X509CRL = {} as certFramework.X509CRL;
  try {
    x509CRL = await certFramework.createX509CRL(encodingBlob);
  } catch (err) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CRL;
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  const certData = "-----BEGIN CERTIFICATE-----\r\n" +
    "MIIC8TCCAdmgAwIBAgIIFB75m06RTHwwDQYJKoZIhvcNAQELBQAwWDELMAkGA1UE\r\n" +
    "BhMCQ04xEDAOBgNVBAgTB0ppYW5nc3UxEDAOBgNVBAcTB05hbmppbmcxCzAJBgNV\r\n" +
    "BAoTAnRzMQswCQYDVQQLEwJ0czELMAkGA1UEAxMCdHMwHhcNMjMxMTIzMDMzMjAw\r\n" +
    "WhcNMjQxMTIzMDMzMjAwWjBhMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHSmlhbmdz\r\n" +
    "dTEQMA4GA1UEBxMHTmFuamluZzEMMAoGA1UEChMDdHMxMQwwCgYDVQQLEwN0czEx\r\n" +
    "EjAQBgNVBAMTCTEyNy4wLjAuMTAqMAUGAytlcAMhALsWnY9cMNC6jzduM69vI3Ej\r\n" +
    "pUlgHtEHS8kRfmYBupJSo4GvMIGsMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFNSg\r\n" +
    "poQvfxR8A1Y4St8NjOHkRpm4MAsGA1UdDwQEAwID+DAnBgNVHSUEIDAeBggrBgEF\r\n" +
    "BQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEyNy4wLjAuMTAR\r\n" +
    "BglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0\r\n" +
    "ZTANBgkqhkiG9w0BAQsFAAOCAQEAfnLmPF6BtAUCZ9pjt1ITdXc5M4LJfMw5IPcv\r\n" +
    "fUAvhdaUXtqBQcjGCWtDdhyb1n5Xp+N7oKz/Cnn0NGFTwVArtFiQ5NEP2CmrckLh\r\n" +
    "Da4VnsDFU+zx2Bbfwo5Ms7iArxyx0fArbMZzN9D1lZcVjiIxp1+3k1/0sdCemcY/\r\n" +
    "y7mw5NwkcczLWLBZl1/Ho8b4dlo1wTA7TZk9uu8UwYBwXDrQe6S9rMcvMcRKiJ9e\r\n" +
    "V4SYZIO7ihr8+n4LQDQP+spvX4cf925a3kyZrftfvGCJ2ZNwvsPhyumYhaBqAgSy\r\n" +
    "Up2BImymAqPi157q9EeYcQz170TtDZHGmjYzdQxhOAHRb6/IdQ==\r\n" +
    "-----END CERTIFICATE-----\r\n";
  const certEncodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM,
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(certEncodingBlob);
    console.log('createX509Cert success');
  } catch (err) {
    console.error('createX509Cert failed');
  }
  return x509Cert;
}

async function selectCRLs() {
  const x509CRL = await createX509CRL();
  const x509Cert = await createX509Cert();
  const collection = certFramework.createCertCRLCollection([], [x509CRL]);

  const param: certFramework.X509CRLMatchParameters = {
    issuer: [new Uint8Array([0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x4A, 0x69, 0x61, 0x6E, 0x67, 0x73, 0x75, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x4E, 0x61, 0x6E, 0x6A, 0x69, 0x6E, 0x67, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x02, 0x74, 0x73])],
    x509Cert: x509Cert
  }
  try {
    const crls = await collection.selectCRLs(param);
    console.log('selectCRLs success');
  } catch (err) {
    console.error('selectCRLs failed');
  }
}
```

### selectCRLs<sup>11+</sup>

selectCRLs(param: X509CRLMatchParameters, callback: AsyncCallback\<Array\<X509CRL>>): void

查找证书和证书吊销列表集合中所有与参数匹配的证书吊销列表对象, 使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明            |
| --------- | ------------------------------- | ---- | ----------------- |
| param | [X509CRLMatchParameters](#x509crlmatchparameters11) | 是   | 表示证书吊销列表需匹配的参数对象。 |
| callback  | AsyncCallback\<Array\<[X509CRL](#x509crl)>>    | 是   | 回调函数。表示匹配到的证书吊销列表对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CRL(): Promise<certFramework.X509CRL> {
  let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
    'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
    'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
    'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
    '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
    'eavsH0Q3\n' +
    '-----END X509 CRL-----\n';

  // 证书吊销列表二进制数据，需业务自行赋值
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(crlData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CRL: certFramework.X509CRL = {} as certFramework.X509CRL;
  try {
    x509CRL = await certFramework.createX509CRL(encodingBlob);
  } catch (err) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CRL;
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  const certData = "-----BEGIN CERTIFICATE-----\r\n" +
    "MIIC8TCCAdmgAwIBAgIIFB75m06RTHwwDQYJKoZIhvcNAQELBQAwWDELMAkGA1UE\r\n" +
    "BhMCQ04xEDAOBgNVBAgTB0ppYW5nc3UxEDAOBgNVBAcTB05hbmppbmcxCzAJBgNV\r\n" +
    "BAoTAnRzMQswCQYDVQQLEwJ0czELMAkGA1UEAxMCdHMwHhcNMjMxMTIzMDMzMjAw\r\n" +
    "WhcNMjQxMTIzMDMzMjAwWjBhMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHSmlhbmdz\r\n" +
    "dTEQMA4GA1UEBxMHTmFuamluZzEMMAoGA1UEChMDdHMxMQwwCgYDVQQLEwN0czEx\r\n" +
    "EjAQBgNVBAMTCTEyNy4wLjAuMTAqMAUGAytlcAMhALsWnY9cMNC6jzduM69vI3Ej\r\n" +
    "pUlgHtEHS8kRfmYBupJSo4GvMIGsMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFNSg\r\n" +
    "poQvfxR8A1Y4St8NjOHkRpm4MAsGA1UdDwQEAwID+DAnBgNVHSUEIDAeBggrBgEF\r\n" +
    "BQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEyNy4wLjAuMTAR\r\n" +
    "BglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0\r\n" +
    "ZTANBgkqhkiG9w0BAQsFAAOCAQEAfnLmPF6BtAUCZ9pjt1ITdXc5M4LJfMw5IPcv\r\n" +
    "fUAvhdaUXtqBQcjGCWtDdhyb1n5Xp+N7oKz/Cnn0NGFTwVArtFiQ5NEP2CmrckLh\r\n" +
    "Da4VnsDFU+zx2Bbfwo5Ms7iArxyx0fArbMZzN9D1lZcVjiIxp1+3k1/0sdCemcY/\r\n" +
    "y7mw5NwkcczLWLBZl1/Ho8b4dlo1wTA7TZk9uu8UwYBwXDrQe6S9rMcvMcRKiJ9e\r\n" +
    "V4SYZIO7ihr8+n4LQDQP+spvX4cf925a3kyZrftfvGCJ2ZNwvsPhyumYhaBqAgSy\r\n" +
    "Up2BImymAqPi157q9EeYcQz170TtDZHGmjYzdQxhOAHRb6/IdQ==\r\n" +
    "-----END CERTIFICATE-----\r\n";
  const certEncodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM,
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(certEncodingBlob);
    console.log('createX509Cert success');
  } catch (err) {
    console.error('createX509Cert failed');
  }
  return x509Cert;
}

async function selectCRLs() {
  const x509CRL = await createX509CRL();
  const x509Cert = await createX509Cert();
  const collection = certFramework.createCertCRLCollection([], [x509CRL]);

  const param: certFramework.X509CRLMatchParameters = {
    issuer: [new Uint8Array([0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x4A, 0x69, 0x61, 0x6E, 0x67, 0x73, 0x75, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x4E, 0x61, 0x6E, 0x6A, 0x69, 0x6E, 0x67, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x02, 0x74, 0x73])],
    x509Cert: x509Cert
  }
  collection.selectCRLs(param, (err, crls) => {
    if (err != null) {
      console.error('selectCRLs failed, errCode: ' + err.code + ', errMsg: ' + err.message);
    } else {
      console.log('selectCRLs success');
    }
  });
}
```

## cryptoCert.createX509CertChain<sup>11+</sup>

createX509CertChain(inStream: EncodingBlob): Promise\<X509CertChain>

表示创建X509证书链对象，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明                 |
| -------- | ----------------------------- | ---- | -------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | X509证书序列化数据。 |

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| Promise\<[X509CertChain](#x509certchain11)> | 表示X509证书链对象。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CertChain(): Promise<certFramework.X509CertChain> {
  let certChainData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
    "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
    "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
    "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
    "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
    "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
    "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
    "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
    "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
    "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
    "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
    "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
    "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
    "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
    "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
    "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
    "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
    "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
    "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
    "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
    "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n" +
    "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
    "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
    "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
    "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
    "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
    "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
    "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
    "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
    "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
    "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
    "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
    "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
    "uKPWR9dKBA==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n"  +
    "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
    "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
    "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
    "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
    "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
    "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
    "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
    "xjoE\n" +
    "-----END CERTIFICATE-----\n";

  // 证书链二进制数据，需业务自行赋值
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certChainData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CertChain: certFramework.X509CertChain = {} as certFramework.X509CertChain;
  try {
    x509CertChain = await certFramework.createX509CertChain(encodingBlob);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CertChain;
}

createX509CertChain();
```

## cryptoCert.createX509CertChain<sup>11+</sup>

createX509CertChain(inStream: EncodingBlob, callback: AsyncCallback\<X509CertChain>): void

表示创建X509证书链对象，使用Callback回调异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)         | 是   | X509证书序列化数据。        |
| callback | AsyncCallback\<[X509CertChain](#x509certchain11)> | 是   | 回调函数。表示X509证书链对象。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = "-----BEGIN CERTIFICATE-----\n" +
  "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
  "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
  "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
  "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
  "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
  "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
  "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
  "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
  "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
  "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
  "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
  "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
  "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
  "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
  "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
  "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
  "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
  "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
  "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
  "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
  "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n" +
  "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
  "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
  "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
  "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
  "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
  "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
  "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
  "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
  "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
  "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
  "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
  "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
  "uKPWR9dKBA==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n"  +
  "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
  "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
  "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
  "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
  "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
  "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
  "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
  "xjoE\n" +
  "-----END CERTIFICATE-----\n";

// 证书链二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CertChain(encodingBlob, (err, certChain) => {
  if (err != null) {
    console.error('createX509CertChain failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('createX509CertChain success');
  }
});
```

## cryptoCert.createX509CertChain<sup>11+</sup>

createX509CertChain(certs: Array\<X509Cert>): X509CertChain

表示使用X509Cert数组方式创建X509证书链对象，并同步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                  | 必填 | 说明                       |
| -------- | -------------------- | ---- | -------------------------- |
| certs    | Array\<[X509Cert](#x509cert)> | 是   | X509证书对象数组。 |

**返回值：**

| 类型                              | 说明                 |
| --------------------------------- | -------------------- |
| [X509CertChain](#x509certchain11) | 表示X509证书链对象。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  // 证书二进制数据，需业务自行赋值
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function createX509CertChain(): Promise<certFramework.X509CertChain> {
  const x509Cert = await createX509Cert();
  let x509CertChain: certFramework.X509CertChain = {} as certFramework.X509CertChain;
  try {
    x509CertChain = certFramework.createX509CertChain([x509Cert]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CertChain;
}

createX509CertChain();
```

## X509CertChain<sup>11+</sup>

X509证书链对象。

### getCertList<sup>11+</sup>

getCertList(): Array\<X509Cert>

获取X509证书列表。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型           | 说明        |
| -------------- | ----------- |
| Array\<[X509Cert](#x509cert)> | X509证书数组。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = "-----BEGIN CERTIFICATE-----\n" +
  "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
  "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
  "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
  "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
  "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
  "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
  "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
  "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
  "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
  "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
  "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
  "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
  "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
  "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
  "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
  "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
  "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
  "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
  "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
  "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
  "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n" +
  "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
  "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
  "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
  "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
  "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
  "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
  "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
  "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
  "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
  "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
  "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
  "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
  "uKPWR9dKBA==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n"  +
  "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
  "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
  "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
  "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
  "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
  "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
  "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
  "xjoE\n" +
  "-----END CERTIFICATE-----\n";

// 证书链二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CertChain(encodingBlob, (err, certChain) => {
  if (err != null) {
    console.error('createX509CertChain failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('createX509CertChain success');
    try {
      let certList = certChain.getCertList();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('X509CertChain getCertList failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### validate<sup>11+</sup>

validate(param: CertChainValidationParameters): Promise\<CertChainValidationResult>

校验证书链，并使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明            |
| --------- | ------------------------------- | ---- | ----------------- |
| param | [CertChainValidationParameters](#certchainvalidationparameters11) | 是   | 表示校验X509证书链的参数。 |

**返回值**：

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[CertChainValidationResult](#certchainvalidationresult11)> | Promise对象，返回证书链校验结果。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error. |
| 19030001 | crypto operation error.           |
| 19030002 | the certificate signature verification failed. |
| 19030003 | the certificate has not taken effect.           |
| 19030004 | the certificate has expired. |
| 19030005 | failed to obtain the certificate issuer.           |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.      |

**示例：**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CertChain(): Promise<certFramework.X509CertChain> {
  let certChainData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
    "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
    "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
    "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
    "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
    "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
    "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
    "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
    "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
    "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
    "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
    "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
    "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
    "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
    "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
    "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
    "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
    "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
    "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
    "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
    "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n" +
    "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
    "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
    "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
    "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
    "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
    "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
    "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
    "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
    "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
    "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
    "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
    "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
    "uKPWR9dKBA==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n"  +
    "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
    "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
    "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
    "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
    "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
    "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
    "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
    "xjoE\n" +
    "-----END CERTIFICATE-----\n";

  // 证书链二进制数据，需业务自行赋值
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certChainData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CertChain: certFramework.X509CertChain = {} as certFramework.X509CertChain;
  try {
    x509CertChain = await certFramework.createX509CertChain(encodingBlob);
  }
  catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CertChain;
}

async function validate() {
  const certChain = await createX509CertChain();
  // 证书链校验数据，需业务自行赋值
  const param: certFramework.CertChainValidationParameters = {
    date: '20231212080000Z',
    trustAnchors: [{
        CAPubKey: new Uint8Array([0x30, 0x2a, 0x30, 0x05, 0x06, 0x03, 0x2b, 0x65, 0x70, 0x03, 0x21, 0x00, 0xbb, 0x16,0x9d, 0x8f, 0x5c, 0x30, 0xd0, 0xba, 0x8f, 0x37, 0x6e, 0x33, 0xaf, 0x6f, 0x23, 0x71, 0x23, 0xa5, 0x49, 0x60,0x1e, 0xd1, 0x07, 0x4b, 0xc9, 0x11, 0x7e, 0x66, 0x01, 0xba, 0x92, 0x52]),
        CASubject: new Uint8Array([0x30, 0x5a, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x45,0x4e, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x45, 0x6e, 0x67, 0x6c, 0x61, 0x6e,0x64, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x06, 0x4c, 0x6f, 0x6e, 0x64, 0x6f, 0x6e,0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a,0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04,0x03, 0x13, 0x03, 0x74, 0x73, 0x31]),
    }]
  }
  try {
    const validationRes = await certChain.validate(param);
    console.log('X509CertChain validate success');
  }
  catch (err) {
    console.error('X509CertChain validate failed');
  }
}

validate();
```

### validate<sup>11+</sup>

validate(param: CertChainValidationParameters, callback: AsyncCallback\<CertChainValidationResult>): void

使用校验参数校验证书链并使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明      |
| --------- | ------------------------------- | ---- | ------------ |
| param | [CertChainValidationParameters](#certchainvalidationparameters11) | 是   | 表示校验X509证书链的参数。 |
| callback  | AsyncCallback\<[CertChainValidationResult](#certchainvalidationresult11)> | 是   | 回调函数。返回证书链校验结果。 |

**错误码：**

以下错误码的详细介绍请参见[cert错误码](../errorcodes/errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error. |
| 19030001 | crypto operation error.           |
| 19030002 | the certificate signature verification failed. |
| 19030003 | the certificate has not taken effect.           |
| 19030004 | the certificate has expired. |
| 19030005 | failed to obtain the certificate issuer.           |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.      |

**示例：**

```ts
import certFramework from '@ohos.security.cert';

// string转Uint8Array
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = "-----BEGIN CERTIFICATE-----\n" +
  "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
  "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
  "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
  "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
  "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
  "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
  "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
  "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
  "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
  "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
  "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
  "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
  "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
  "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
  "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
  "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
  "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
  "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
  "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
  "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
  "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n" +
  "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
  "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
  "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
  "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
  "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
  "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
  "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
  "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
  "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
  "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
  "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
  "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
  "uKPWR9dKBA==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n"  +
  "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
  "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
  "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
  "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
  "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
  "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
  "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
  "xjoE\n" +
  "-----END CERTIFICATE-----\n";

// 证书链二进制数据，需业务自行赋值
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

// 证书链校验数据，需业务自行赋值
let param: certFramework.CertChainValidationParameters = {
  date: '20231212080000Z',
  trustAnchors: [{
    CAPubKey: new Uint8Array([0x30, 0x2a, 0x30, 0x05, 0x06, 0x03, 0x2b, 0x65, 0x70, 0x03, 0x21, 0x00, 0xbb, 0x16,0x9d, 0x8f, 0x5c, 0x30, 0xd0, 0xba, 0x8f, 0x37, 0x6e, 0x33, 0xaf, 0x6f, 0x23, 0x71, 0x23, 0xa5, 0x49, 0x60,0x1e, 0xd1, 0x07, 0x4b, 0xc9, 0x11, 0x7e, 0x66, 0x01, 0xba, 0x92, 0x52]),
    CASubject: new Uint8Array([0x30, 0x5a, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x45,0x4e, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x45, 0x6e, 0x67, 0x6c, 0x61, 0x6e,0x64, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x06, 0x4c, 0x6f, 0x6e, 0x64, 0x6f, 0x6e,0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a,0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04,0x03, 0x13, 0x03, 0x74, 0x73, 0x31]),
  }]
};

certFramework.createX509CertChain(encodingBlob, (err, certChain) => {
  if (err != null) {
    console.error('createX509CertChain failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('createX509CertChain success');
    certChain.validate(param, (error, validationRes) => {
      if (error != null) {
        console.error('X509CertChain validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('X509CertChain validate success');
      }
    });
  }
});
```