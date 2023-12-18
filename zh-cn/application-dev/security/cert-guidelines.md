# 证书开发指导

> **说明**
>
> 本开发指导需使用API version 9及以上版本SDK。

## 使用证书操作

**场景说明**

使用证书操作中，典型的场景有：

1. 解析X509证书数据生成证书对象。
2. 获取证书信息，比如：证书版本、证书序列号等。
3. 获取证书对象的序列化数据。
4. 获取证书公钥。
5. 证书验签。
6. 校验证书有效期。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cert.md)。

以上场景涉及的常用接口如下表所示：

| 实例名          | 接口名                                                       | 描述                                         |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| cryptoCert | createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void | 使用callback方式解析X509证书数据生成证书对象 |
| cryptoCert | createX509Cert(inStream : EncodingBlob) : Promise\<X509Cert>  | 使用promise方式解析X509证书数据生成证书对象  |
| X509Cert        | verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void  | 使用callback方式进行证书验签                 |
| X509Cert        | verify(key : cryptoFramework.PubKey) : Promise\<void>                         | 使用promise方式进行证书验签                  |
| X509Cert        | getEncoded(callback : AsyncCallback\<EncodingBlob>) : void    | 使用callback方式获取证书序列化数据           |
| X509Cert        | getEncoded() : Promise\<EncodingBlob>                         | 使用promise方式获取证书序列化数据            |
| X509Cert        | getPublicKey() : cryptoFramework.PubKey                       | 获取证书公钥                               |
| X509Cert        | checkValidityWithDate(date: string) : void                   | 校验证书有效期                              |
| X509Cert        | getVersion() : number                                        | 获取证书版本                                 |
| X509Cert | getCertSerialNumber() : bigint<sup>10+</sup> | 获取证书序列号 |
| X509Cert        | getIssuerName() : DataBlob                                   | 获取证书颁发者名称                           |
| X509Cert        | getSubjectName() : DataBlob                                  | 获取证书主体名称                             |
| X509Cert        | getNotBeforeTime() : string                                  | 获取证书有效期起始时间                       |
| X509Cert        | getNotAfterTime() : string                                   | 获取证书有效期截至时间                       |
| X509Cert        | getSignature() : DataBlob                                    | 获取证书签名                                 |
| X509Cert        | getSignatureAlgName() : string                               | 获取证书签名算法名称                         |
| X509Cert        | getSignatureAlgOid() : string                                | 获取证书签名算法OID                          |
| X509Cert        | getSignatureAlgParams() : DataBlob                           | 获取证书签名算法参数                         |
| X509Cert        | getKeyUsage() : DataBlob                                     | 获取证书秘钥用途                             |
| X509Cert        | getExtKeyUsage() : DataArray                                 | 获取证书扩展秘钥用途                         |
| X509Cert        | getBasicConstraints() : number                               | 获取证书基本约束                             |
| X509Cert        | getSubjectAltNames() : DataArray                             | 获取证书主体可选名称                         |
| X509Cert        | getIssuerAltNames() : DataArray                              | 获取证书颁发者可选名称                       |
| X509Cert        | getItem(itemType: CertItemType) : DataBlob<sup>10+</sup>          | 获取X509证书对应的字段                       |

**开发步骤**

示例：解析X509证书数据生成证书对象，并调用对象方法（包含场景1-6）

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Certificate data, which is only an example. The certificate data varies with the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// Convert the certificate data form a string to a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate example
function certSample(): void {
  let encodingBlob: certFramework.EncodingBlob = {
    // Convert the certificate data string to a Uint8Array.
    data: stringToUint8Array(certData),
    // Certificate format. Only PEM and DER are supported. In this example, the certificate is in PEM format.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  // Create an X509Cert instance.
  certFramework.createX509Cert(encodingBlob, (err, x509Cert) => {
    if (err != null) {
      // Failed to create the X509Cert instance.
      console.error('createX509Cert failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      return;
    }
    // The X509Cert instance is successfully created.
    console.log('createX509Cert success');

    // Obtain the certificate version.
    let version = x509Cert.getVersion();

    // Obtain the serialized data of the certificate.
    x509Cert.getEncoded((err, data) => {
      if (err != null) {
        // Failed to obtain the serialized data of the certificate.
        console.error('getEncoded failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      } else {
        // The serialized data of the certificate is successfully obtained.
        console.log('getEncoded success');
      }
    });

    // Obtain the public key object using the getPublicKey() of the upper-level certificate object or this (self-signed) certificate object.
    try {
      let pubKey = x509Cert.getPublicKey();

      // Verify the certificate signature.
      x509Cert.verify(pubKey, (err, data) => {
        if (err == null) {
          // The signature verification is successful.
          console.log('verify success');
        } else {
          // The signature verification failed.
          console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getPublicKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }


    // Time represented in a string.
    let date = '20230930000001Z';

    // Verify the certificate validity period.
    try {
      x509Cert.checkValidityWithDate(date);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('checkValidityWithDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  });
}
```

## 使用证书扩展域段操作

> **说明**
>
> 本场景基于API version 10，OH SDK版本4.0.9及以上。

**场景说明**

使用证书扩展域段操作中，典型的场景有：

1. 解析证书扩展域段数据生成证书扩展域段对象。
2. 获取证书扩展域段信息，比如：证书扩展域段对象标识符列表，根据对象标识符获取具体数据等。
3. 校验证书是否为CA证书。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cert.md)。

以上场景涉及的常用接口如下表所示：

| 实例名        | 接口名                                                       | 描述                                   |
| ------------- | ------------------------------------------------------------ | -------------------------------------- |
| cryptoCert    | createCertExtension(inStream : EncodingBlob, callback : AsyncCallback) : void | 使用callback方式创建证书扩展域段的对象 |
| cryptoCert    | createCertExtension(inStream : EncodingBlob) : Promise       | 使用promise方式创建证书扩展域段的对象  |
| CertExtension | getEncoded() : EncodingBlob                                  | 获取证书扩展域段序列化数据             |
| CertExtension | getOidList(valueType : ExtensionOidType) : DataArray         | 获取证书扩展域段对象标识符列表         |
| CertExtension | getEntry(valueType: ExtensionEntryType, oid : DataBlob) : DataBlob | 获取证书扩展域段对象信息               |
| CertExtension | checkCA() : number                                           | 校验证书是否为CA证书                   |
| CertExtension | hasUnsupportedCriticalExtension(): boolean<sup>11+</sup>                | 判断证书是否存在不支持的关键扩展                   |

**开发步骤**

示例：解析X509证书扩展域段数据生成证书扩展域段对象，并调用对象方法（包含场景1-3）

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Certificate extension data, which is only an example. Set it based on service requirements.
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

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate extension example.
function certExtensionSample(): void {
  let encodingBlob: certFramework.EncodingBlob = {
    data: extData,
    // Certificate extension format. Currently, only the DER format is supported.
    encodingFormat: certFramework.EncodingFormat.FORMAT_DER
  };

  // Create a CerExtension instance.
  certFramework.createCertExtension(encodingBlob, (err, certExtension) => {
    if (err != null) {
      // The CerExtension instance fails to be created.
      console.error('createCertExtension failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      return;
    }
    // A CerExtension instance is created.
    console.log('createCertExtension success');

    try {
      // Obtain the serialized data of the CerExtension instance.
      let encodedData = certExtension.getEncoded();

      // Obtain the OIDs of the certificate extensions.
      let oidList = certExtension.getOidList(certFramework.ExtensionOidType.EXTENSION_OID_TYPE_ALL);

      // Obtain the certificate extension information based on a OID.
      let oidData = '2.5.29.14';
      let oid: certFramework.DataBlob = {
        data: stringToUint8Array(oidData),
      }
      let entry = certExtension.getEntry(certFramework.ExtensionEntryType.EXTENSION_ENTRY_TYPE_ENTRY, oid);

      // Check whether the certificate is a CA certificate.
      let pathLen = certExtension.checkCA();

      let hasUnsupportedCriticalExtension = certExtension.hasUnsupportedCriticalExtension();
      console.log('test cert extension success');
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('operation failed, message: ' + e.message + ' code: ' + e.code);
    }
  });
}
```

## 使用证书吊销列表操作

**场景说明**

使用证书吊销列表操作中，典型的场景有：

1. 解析X509证书吊销列表数据生成吊销列表对象。
2. 获取证书吊销列表信息，比如：证书吊销列表版本、证书吊销列表类型等。
3. 获取证书吊销列表对象的序列化数据。
4. 检查证书是否被吊销。
5. 证书吊销列表验签。
6. 获取被吊销证书。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cert.md)。

以上场景涉及的常用接口如下表所示：

| 实例名          | 接口名                                                       | 描述                                                         |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| cryptoCert | createX509CRL(inStream : EncodingBlob, callback : AsyncCallback\<X509CRL>) : void<sup>11+</sup> | 使用callback方式解析X509证书吊销列表数据生成证书吊销列表对象 |
| cryptoCert | createX509CRL(inStream : EncodingBlob) : Promise\<X509CRL><sup>11+</sup>    | 使用promise方式解析X509证书吊销列表数据生成证书吊销列表对象  |
| X509CRL         | isRevoked(cert : X509Cert) : boolean<sup>11+</sup>                     |  检查证书是否被吊销                            |
| X509CRL         | getType() : string<sup>11+</sup>                                           | 获取证书吊销列表类型                                        |
| X509CRL         | getEncoded(callback : AsyncCallback\<EncodingBlob>) : void<sup>11+</sup>    | 使用callback方式获取证书吊销列表序列化数据                   |
| X509CRL         | getEncoded() : Promise\<EncodingBlob><sup>11+</sup>                         | 使用promise方式获取证书吊销列表序列化数据                    |
| X509CRL         | verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void<sup>11+</sup>  | 使用callback方式进行证书吊销列表验签        |
| X509CRL         | verify(key : cryptoFramework.PubKey) : Promise\<void><sup>11+</sup>                         | 使用Promise方式进行证书吊销列表验签         |
| X509CRL         | getVersion() : number<sup>11+</sup>                                        | 获取证书吊销列表版本                                        |
| X509CRL         | getIssuerName() : DataBlob<sup>11+</sup>                                   | 获取证书吊销列表颁发者名称                                   |
| X509CRL         | getLastUpdate() : string<sup>11+</sup>                                     | 获取证书吊销列表lastUpdate日期                               |
| X509CRL         | getNextUpdate() : string<sup>11+</sup>                                     | 获取证书吊销列表nextUpdate日期                               |
| X509CRL         | getRevokedCert(serialNumber : bigint) : X509CRLEntry<sup>11+</sup>         | 通过序列号获取证书吊销列表中的被吊销证书                       |
| X509CRL         | getRevokedCertWithCert(cert : X509Cert) : X509CRLEntry<sup>11+</sup>         | 通过X509证书获取证书吊销列表中的被吊销证书                   |
| X509CRL         | getRevokedCerts(callback : AsyncCallback\<Array\<X509CRLEntry>>) : void<sup>11+</sup> | 使用callback方式获取证书吊销列表的所有被吊销证书    |
| X509CRL         | getRevokedCerts() : Promise\<Array\<X509CRLEntry>><sup>11+</sup>             | 使用Promise方式获取证书吊销列表的所有被吊销证书              |
| X509CRL         | getTBSInfo() : DataBlob<sup>11+</sup>                                      | 获取证书吊销列表的tbsCertList                                |
| X509CRL         | getSignature() : DataBlob<sup>11+</sup>                                    | 获取证书吊销列表的签名                                       |
| X509CRL         | getSignatureAlgName() : string<sup>11+</sup>                               | 获取证书吊销列表的签名算法名称                                |
| X509CRL         | getSignatureAlgOid() : string<sup>11+</sup>                                | 获取证书吊销列表的签名算法OID                                 |
| X509CRL         | getSignatureAlgParams() : DataBlob<sup>11+</sup>                           | 获取证书吊销列表的签名算法参数                                |
| X509CRL         | getExtensions(): DataBlob<sup>11+</sup>                                    | 获取CRL的扩展                                |

**开发步骤**

示例：解析X509证书吊销列表数据生成证书吊销列表对象，并调用对象方法（包含场景1-6）

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// CRL data, which is only an example. The CRL data varies with the service.
let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'


let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

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

// Convert the certificate data form a string to a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Example of a X509CRL.
function sampleCRL(): void {
  let encodingBlob: certFramework.EncodingBlob = {
    // Convert the CRL data from a string to a Uint8Array.
    data: stringToUint8Array(crlData),
    // CRL format. Only PEM and DER are supported. In this example, the CRL is in PEM format.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  // Create an X509Crl instance.
  certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
    if (err != null) {
      // Failed to create the X509Crl instance.
      console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      return;
    }
    // The X509Crl instance is successfully created.
    console.log('createX509CRL success');

    // Obtain the CRL version.
    let version = x509CRL.getVersion();

    // Obtain the serialized data of the CRL.
    x509CRL.getEncoded((err, data) => {
      if (err != null) {
        // Failed to obtain the serialized data of the certificate.
        console.error('getEncoded failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      } else {
        // The serialized data of the certificate is successfully obtained.
        console.log('getEncoded success');
      }
    });

    // Create an X509Cert instance by using createX509Cert() of certFramework.
    let certBlob: certFramework.EncodingBlob = {
      data: stringToUint8Array(certData),
      encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
    };
    certFramework.createX509Cert(certBlob, (err, cert) => {
      if (err == null) {
        try {
          // Check whether the certificate is revoked.
          let revokedFlag = x509CRL.isRevoked(cert);
          console.log('revokedFlag is: ' + revokedFlag);
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error('isRevoked failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
      } else {
        console.error('create x509 cert failed errCode: ' + err.code + ', errMsg: ' + err.message);
      }
    })

    // The binary data of the public key needs to be passed to convertKey() of @ohos.security.cryptoFramework to obtain the PubKey object. The process is omitted here.
    try {
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
              // The signature verification is successful.
              console.log('verify success');
            } else {
              // The signature verification failed.
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

    // Certificate serial number, which must be set based on the service.
    let serialNumber = BigInt(1000);

    // Obtain the revoked certificate based on the serial number.
    try {
      let entry = x509CRL.getRevokedCert(serialNumber);
      console.log('get getRevokedCert success');
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  });
}
```

## 使用证书链校验器操作

**场景说明**

使用证书链校验器操作中，典型的场景：证书链校验。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cert.md)。

以上场景涉及的常用接口如下表所示：

| 实例名             | 接口名                                                       | 描述                             |
| ------------------ | ------------------------------------------------------------ | -------------------------------- |
| cryptoCert | createCertChainValidator(algorithm :string) : CertChainValidator | 使用指定算法生成证书链校验器对象 |
| CertChainValidator | validate(certChain : CertChainData, callback : AsyncCallback\<void>) : void | 使用callback方式校验证书链   |
| CertChainValidator | validate(certChain : CertChainData) : Promise\<void>          | 使用promise方式校验证书链        |
| CertChainValidator | algorithm : string                                           | 证书链校验器算法名称             |

**开发步骤**

示例：创建证书链校验器对象，并对证书链数据进行校验（场景1）

```ts
import certFramework from '@ohos.security.cert';

// CA certificate data, which is only an example. The CA certificate data varies with the service.
let caCertData = '-----BEGIN CERTIFICATE-----\n' +
  '...\n' +
  '...\n' +
  '...\n' +
  '-----END CERTIFICATE-----\n';

// End-entity certificate data, which is only an example. The certificate data varies with the service.
let secondCaCertData = '-----BEGIN CERTIFICATE-----\n' +
  '...\n' +
  '...\n' +
  '...\n' +
  '-----END CERTIFICATE-----\n';

// Convert the certificate data form a string to a Uint8Array..
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate chain validator example. In this example, a two-level certificate chain is verified.
function certChainValidatorSample(): void {
  // Certificate chain validator algorithm. Currently, only PKIX is supported.
  let algorithm = 'PKIX';

  // Create a CertChainValidator instance.
  let validator = certFramework.createCertChainValidator(algorithm);

  // CA certificate data.
  let uint8ArrayOfCaCertData = stringToUint8Array(caCertData);

  // Length of the CA certificate data.
  let uint8ArrayOfCaCertDataLen = new Uint8Array(new Uint16Array([uint8ArrayOfCaCertData.byteLength]).buffer);

  // End-entity certificate data.
  let uint8ArrayOf2ndCaCertData = stringToUint8Array(secondCaCertData);

  // Length of the end-entity certificate data.
  let uint8ArrayOf2ndCaCertDataLen = new Uint8Array(new Uint16Array([uint8ArrayOf2ndCaCertData.byteLength]).buffer);

  // Certificate chain binary data: end-entity certificate data length + end-entity certificate data + CA certificate data length + CA certificate data (in L-V format).
  let encodingData = new Uint8Array(uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length +
  uint8ArrayOfCaCertDataLen.length + uint8ArrayOfCaCertData.length);
  for (let i = 0; i < uint8ArrayOf2ndCaCertDataLen.length; i++) {
    encodingData[i] = uint8ArrayOf2ndCaCertDataLen[i];
  }
  for (let i = 0; i < uint8ArrayOf2ndCaCertData.length; i++) {
    encodingData[uint8ArrayOf2ndCaCertDataLen.length + i] = uint8ArrayOf2ndCaCertData[i];
  }
  for (let i = 0; i < uint8ArrayOfCaCertDataLen.length; i++) {
    encodingData[uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length + i] = uint8ArrayOfCaCertDataLen[i];
  }
  for (let i = 0; i < uint8ArrayOfCaCertData.length; i++) {
    encodingData[uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length +
    uint8ArrayOfCaCertDataLen.length + i] = uint8ArrayOfCaCertData[i];
  }

  let certChainData: certFramework.CertChainData = {
    // Uint8Array type: L-V format (certificate data length-certificate data)
    data: encodingData,
    // Number of certificates. It is 2 in this example.
    count: 2,
    // Certificate format. Only PEM and DER are supported. In this example, the certificate is in PEM format.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  // Verify the certificate chain.
  validator.validate(certChainData, (err, data) => {
    if (err != null) {
      // The operation fails.
      console.error('validate failed, errCode: ' + err.code + ', errMsg: ' + err.message);
    } else {
      // The operation is successful.
      console.log('validate success');
    }
  });
}
```

## 使用被吊销证书操作

**场景说明**

使用被吊销证书操作中，典型的场景有：

1. 获取被吊销证书对象。
2. 获取被吊销证书信息，比如：序列号、证书颁发者、证书吊销日期。
3. 获取被吊销证书对象的序列化数据。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cert.md)。

以上场景涉及的常用接口如下表所示：

| 实例名       | 接口名                                                      | 描述                                      |
| ------------ | ----------------------------------------------------------- | ---------------------------------------- |
| X509CRLEntry | getEncoded(callback : AsyncCallback\<EncodingBlob>) : void<sup>11+</sup>;  | 使用callback方式获取被吊销证书的序列化数据 |
| X509CRLEntry | getEncoded() : Promise\<EncodingBlob><sup>11+</sup>;                       | 使用promise方式获取被吊销证书的序列化数据  |
| X509CRLEntry | getSerialNumber() : bigint<sup>11+</sup>;                                  | 获取被吊销证书的序列号                    |
| X509CRLEntry | getCertIssuer() : DataBlob<sup>11+</sup>;                                  | 获取被吊销证书颁发者                     |
| X509CRLEntry | getRevocationDate() : string<sup>11+</sup>;                                | 获取被吊销证书的吊销日期                  |
| X509CRLEntry | hasExtensions(): boolean<sup>11+</sup>;                                  | 判断CRLEntry是否有扩展                      |
| X509CRLEntry | getExtensions(): DataBlob<sup>11+</sup>;                                | 获取CRLEntry的扩展                  |


**开发步骤**

示例：获取被吊销证书对象，并调用对象方法（包含场景1-3）

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

// Convert the certificate data form a string to a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Example of a revoked certificate.
function sampleCrlEntry(): void {
  // Create an **X509Crl** instance by using createX509Crl() of certFramework.
  let encodingBlob: certFramework.EncodingBlob = {
    // Convert the CRL data from a string to a Uint8Array.
    data: stringToUint8Array(crlData),
    // CRL format. Only PEM and DER are supported. In this example, the CRL is in PEM format.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  // Create an X509Crl instance.
  certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
    if (err != null) {
      // Failed to create the X509Crl instance.
      console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      return;
    }
    console.log('create x509 CRL success');

    // Obtain a revoked certificate instance. In this example, the instance is obtained by using getRevokedCert().
    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);

      // Obtain the serial number of the revoked certificate.
      serialNumber = crlEntry.getSerialNumber();
      console.log('serialNumber is: ', serialNumber);

      // Obtain the revocation date of the revoked certificate.
      let date = crlEntry.getRevocationDate();
      console.log('revocation date is: ', date);

      // Obtain the serialized data of the revoked certificate instance.
      crlEntry.getEncoded((err, data) => {
        if (err != null) {
          // Failed to obtain the serialized data of the certificate.
          console.error('getEncoded failed, errCode: ' + err.code + ', errMsg: ' + err.message);
        } else {
          // The serialized data of the certificate is successfully obtained.
          console.log('getEncoded success');
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  })
}
```
## 使用证书集合及证书吊销列表集合操作

> **说明**
>
> 本场景基于API version 11，OH SDK版本4.1.5.3及以上。


**场景说明**

使用证书集合及证书吊销列表集合操作中，典型的场景：从输入的证书集合和证书吊销列表集合中选择满足条件的证书或者证书吊销列表。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cert.md)。

以上场景涉及的常用接口如下表所示：

| 实例名             | 接口名                                                       | 描述                             |
| ------------------ | ------------------------------------------------------------ | -------------------------------- |
| cryptoCert | createCertCRLCollection(certs: Array\<X509Cert>, crls?: Array\<X509CRL>): CertCRLCollection | 表示创建CertCRLCollection的对象，并返回相应的结果 |
| CertCRLCollection | selectCerts(param: X509CertMatchParameters): Promise\<Array\<X509Cert>> | 查找所有与X509CertMatchParameters匹配的证书对象数组, 使用Promise方式异步返回结果 |
| CertCRLCollection | selectCerts(param: X509CertMatchParameters, callback: AsyncCallback\<Array\<X509Cert>>): void          | 查找所有与X509CertMatchParameters匹配的证书对象数组, 使用Callback回调异步返回结果 |
| CertCRLCollection | selectCRLs(param: X509CRLMatchParameters): Promise\<Array\<X509CRL>> | 查找所有与X509CRLMatchParameters匹配的证书吊销列表数组, 使用Promise方式异步返回结果 |
| CertCRLCollection | selectCRLs(param: X509CRLMatchParameters, callback: AsyncCallback\<Array\<X509CRL>>): void         | 查找所有与X509CRLMatchParameters匹配的证书吊销列表数组, 使用Callback回调异步返回结果 |

**开发步骤**

示例：创建证书及证书吊销列表集合对象，从中选择满足条件的证书或者证书吊销列表。

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

async function sample() {
  const x509Cert = await createX509Cert();
  const x509CRL = await createX509CRL();
  let collection: certFramework.CertCRLCollection = {} as certFramework.CertCRLCollection;
  try {
    collection = certFramework.createCertCRLCollection([x509Cert], [x509CRL]);
    console.log('createCertCRLCollection success');
  } catch (err) {
    console.error('createCertCRLCollection failed');
  }

  const certParam: certFramework.X509CertMatchParameters = {
    validDate: '231128000000Z'
  }
  try {
    let certs: certFramework.X509Cert[] = await collection.selectCerts(certParam);
  } catch (err) {
    console.error('selectCerts failed');
  }

  const crlParam: certFramework.X509CRLMatchParameters = {
    updateDateTime: '231128000000Z'
  }
  try {
    let crls: certFramework.X509CRL[] = await collection.selectCRLs(crlParam);
    console.error('selectCRLs success');
  } catch (err) {
    console.error('selectCRLs failed');
  }
}
```
## 相关实例

针对证书开发，有以下相关实例可供参考：

- [证书算法库框架（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/CertificateFramework)