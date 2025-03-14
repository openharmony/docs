# 证书对象的创建、解析和校验

以校验证书有效性为例，完成证书对象的创建、解析和校验。

## 开发步骤

1. 导入[证书算法库框架模块](../../reference/apis-device-certificate-kit/js-apis-cert.md)。
   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. 基于已有的X509证书数据，调用[cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert)创建证书对象。

3. 解析证书的字段信息。
   此处以获取证书版本、证书序列号为例，更多字段信息获取接口请查看[API参考文档](../../reference/apis-device-certificate-kit/js-apis-cert.md#x509cert)。

4. 调用[X509Cert.getPublicKey](../../reference/apis-device-certificate-kit/js-apis-cert.md#getpublickey)获取证书中的公钥，并调用[X509Cert.verify](../../reference/apis-device-certificate-kit/js-apis-cert.md#verify)校验签名。
   示例为自验签场景，因此获取的是本证书中的公钥。应用须结合自身场景获取用于验签的公钥。

5. 调用[X509Cert.checkValidityWithDate](../../reference/apis-device-certificate-kit/js-apis-cert.md#checkvaliditywithdate)校验证书有效期。
   入参date用于确认此日期是否在X509证书有效期内。

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

// 此处仅为示例的证书二进制数据，需根据业务的不同对证书数据进行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// 证书示例
function certSample(): void {
  let textEncoder = new util.TextEncoder();
  let encodingBlob: cert.EncodingBlob = {
    // 将证书数据从string类型转换成Unit8Array。
    data: textEncoder.encodeInto(certData),
    // 证书格式，仅支持PEM和DER。在此示例中，证书为PEM格式。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  // 创建X509Cert实例。
  cert.createX509Cert(encodingBlob, (err, x509Cert) => {
    if (err != null) {
      // 创建X509Cert实例失败。
      console.error(`createX509Cert failed, errCode:${err.code}, errMsg:${err.message}`);
      return;
    }
    // X509Cert实例创建成功。
    console.log('createX509Cert success');

    // 获取证书版本。
    let version = x509Cert.getVersion();
    let serial = x509Cert.getCertSerialNumber();
    console.log(`X509 version: ${version} , X509 serial:${serial}`);

    // 使用上级证书对象的getPublicKey()方法或本（自签名）证书对象获取公钥对象。
    try {
      let pubKey = x509Cert.getPublicKey();
      // 验证证书签名。
      x509Cert.verify(pubKey, (err, data) => {
        if (err == null) {
          // 签名验证成功。
          console.log('verify success');
        } else {
          // 签名验证失败。
          console.error(`verify failed, errCode: ${err.code} , errMsg:${err.message}`);
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`getPublicKey failed, errCode: ${e.code} , errMsg:${e.message}`);
    }

    // 用一个字符串代表时间。
    let date = '20230930000001Z';

    // 验证证书的有效期。
    try {
      x509Cert.checkValidityWithDate(date);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`checkValidityWithDate failed, errCode: ${e.code}, errMsg:${e.message}`);
    }
  });
}
```
