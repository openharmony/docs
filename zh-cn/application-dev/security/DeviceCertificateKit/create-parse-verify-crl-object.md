# 证书吊销列表对象的创建、解析和校验


以校验证书是否已吊销为例，完成证书吊销列表对象的创建、解析和校验。若证书已被吊销，将打印被吊销日期。


## 开发步骤

1. 导入[证书算法库框架模块](../../reference/apis-device-certificate-kit/js-apis-cert.md)和[加解密算法库模块](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md)。
   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   import { cryptoFramework } from '@kit.CryptoArchitectureKit';
   ```

2. 基于已有的CRL数据，调用[cert.createX509CRL](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509crl11)创建X509证书吊销列表的对象。

3. 解析证书吊销列表信息。

   此处以获取证书吊销列表版本、证书吊销列表类型为例，更多字段信息获取接口请查看[API参考文档](../../reference/apis-device-certificate-kit/js-apis-cert.md#x509crl11)。

4. 基于已有公钥信息，创建PublicKey公钥对象。

   具体可参考[加解密算法库框架-指定二进制数据生成非对称密钥对](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3)。

5. 调用[X509CRL.verify](../../reference/apis-device-certificate-kit/js-apis-cert.md#verify11)校验签名合法性。

6. 基于已有的X509证书数据，调用[cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert)创建证书对象。

7. 调用[X509CRL.isRevoked](../../reference/apis-device-certificate-kit/js-apis-cert.md#isrevoked11)判断X509证书是否已被吊销。

8. 调用[X509CRL.getRevokedCert](../../reference/apis-device-certificate-kit/js-apis-cert.md#getrevokedcert11)获取被吊销证书对象。

9.  调用[X509CRLEntry.getRevocationDate](../../reference/apis-device-certificate-kit/js-apis-cert.md#getrevocationdate11)获取被吊销日期。

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

// CRL数据，以下只是一个示例，需要根据具体业务来赋值
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

// CRL示例
function crlSample(): void {
  let textEncoder = new util.TextEncoder();
  let encodingBlob: cert.EncodingBlob = {
    // 将CRL数据从string转为Unit8Array
    data: textEncoder.encodeInto(crlData),
    // CRL格式，仅支持PEM和DER格式。在这个例子中，CRL用的是PEM格式
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  // 创建X509CRL实例
  cert.createX509CRL(encodingBlob, (err, x509Crl) => {
    if (err != null) {
      // 创建X509CRL实例失败
      console.error(`createX509Crl failed, errCode: ${err.code}, errMsg:${err.message} `);
      return;
    }
    // 创建X509CRL实例成功
    console.log('createX509CRL success');

    // 获取CRL的版本
    let version = x509Crl.getVersion();
    let revokedType = x509Crl.getType();
    console.log(`X509 CRL version: ${version}, type :${revokedType}`);

    // 公钥的二进制数据需要传入@ohos.security.cryptoFramework的convertKey()方法去获取公钥对象
    try {
      let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
      console.log('createAsyKeyGenerator success');
      let pubEncodingBlob: cryptoFramework.DataBlob = {
        data: pubKeyData,
      };
      keyGenerator.convertKey(pubEncodingBlob, null, (e, keyPair) => {
        if (e == null) {
          console.log('convert key success');
          x509Crl.verify(keyPair.pubKey, (err, data) => {
            if (err == null) {
              // 签名验证成功
              console.log('verify success');
            } else {
              // 签名验证失败
              console.error(`verify failed, errCode: ${err.code}, errMsg: ${err.message}`);
            }
          });
        } else {
          console.error(`convert key failed, message: ${e.message}, code: ${e.code} `);
        }
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`get pubKey failed, errCode: ${e.code}, errMsg: ${e.message}` );
    }

    // 使用certFramework的createX509Cert()方法创建一个X509Cert实例
    let certBlob: cert.EncodingBlob = {
      data: textEncoder.encodeInto(certData),
      encodingFormat: cert.EncodingFormat.FORMAT_PEM
    };
    let revokedFlag = true;
    let serial:bigint = BigInt('0');
    cert.createX509Cert(certBlob, (err, cert) => {
      serial = cert.getCertSerialNumber();
      if (err == null) {
        try {
          // 检查证书是否被吊销
          revokedFlag = x509Crl.isRevoked(cert);
          console.log(`revokedFlag is: ${revokedFlag}`);
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error(`isRevoked failed, errCode: ${e.code}, errMsg:${e.message}`);
        }
      } else {
        console.error(`create x509 cert failed, errCode: ${err.code}, errMsg: ${err.message}`);
      }
    })
    if (!revokedFlag) {
        console.log('the given cert is not revoked.');
        return;
    }

    // 根据序列号来获取被吊销的证书
    try {
      let crlEntry = x509Crl.getRevokedCert(serial);
      console.log('get getRevokedCert success');
      let serialNumber = crlEntry.getSerialNumber();
      console.log(`crlEntry serialNumber is: ${serialNumber}`);

      // 获取被吊销证书的吊销日期
      let date = crlEntry.getRevocationDate();
      console.log(`revocation date is: ${date}`);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`getRevokedCert failed, errCode: ${e.code}, errMsg: ${e.message}`);
    }
  });
}
```
