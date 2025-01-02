# 证书扩展信息对象的创建、解析和校验


以获取证书指定OID域段，并判断是否为CA证书为例，完成证书扩展信息对象的创建、解析和校验。


## 开发步骤

1. 导入[证书算法库框架模块](../../reference/apis-device-certificate-kit/js-apis-cert.md)。
   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. 解析证书扩展域段数据，调用[cert.createCertExtension](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatecertextension10)创建证书扩展域段对象。

3. 调用[CertExtension.getEntry](../../reference/apis-device-certificate-kit/js-apis-cert.md#getentry10)获取指定OID证书扩展域段信息。
   比如，证书扩展域段对象标识符列表，根据对象标识符获取具体数据等。

4. 调用[CertExtension.checkCA](../../reference/apis-device-certificate-kit/js-apis-cert.md#checkca10)判断证书是否为CA证书。

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

// 证书扩展数据，以下只是一个示例。需要根据具体业务来赋值
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

// 证书扩展示例
function certExtensionSample(): void {
  let textEncoder = new util.TextEncoder();
  let encodingBlob: cert.EncodingBlob = {
    data: extData,
    // 证书扩展格式，目前仅支持DER格式
    encodingFormat: cert.EncodingFormat.FORMAT_DER
  };

  // 创建一个证书扩展实例
  cert.createCertExtension(encodingBlob, (err, certExtension) => {
    if (err != null) {
      // 证书扩展实例创建失败
      console.error(`createCertExtension failed, errCode:${err.code}, errMsg:${err.message} `);
      return;
    }
    // 证书扩展实例创建成功
    console.log('createCertExtension success');

    try {
      // 根据OID获取证书扩展信息
      let oidData = '2.5.29.14';
      let oid: cert.DataBlob = {
        data: textEncoder.encodeInto(oidData),
      }
      let entry = certExtension.getEntry(cert.ExtensionEntryType.EXTENSION_ENTRY_TYPE_ENTRY, oid);

      // 检查证书是否为CA证书
      let pathLen = certExtension.checkCA();
      console.log('test cert extension success');
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`operation failed, message:${e.message} ,code:${e.code} `);
    }
  });
}
```
