# 网络子系统Changelog

## certVerification接口和certVerificationSync接口错误码2305001细化

**访问级别**

公开接口

**变更原因**

对2305001 - Unspecified error错误进行细化调整。

**变更影响**

该变更为不兼容变更。

变更前：输入上下文非法的证书及自验证证书返回错误码：2305001，错误信息：Unspecified error。

变更后：输入上下文非法的证书返回错误码：2305069，错误信息：Invalid certificate verification context；输入自验证证书返回错误码：2305018，错误信息：Self-signed certificate。

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.0.0.38开始。

**适配指导**
以下两个用例分别为错误码2305069和2305018的测试用例，测试时请将Verifying the 2305069 Error Code of the CertVerification用例中的'your Self-signed certificate data'替换为开发者真实使用的自签名证书内容。
```
import { describe, it, expect } from '@ohos/hypium';
import { BusinessError } from '@kit.BasicServicesKit';
import { networkSecurity } from '@kit.NetworkKit';

const expectFalse: (n: boolean, name: string) => void = (n: boolean, name: string) => {
  try {
    expect(n).assertFalse();
  }
  catch (err) {
    console.info(`${name}, test failed`);
  }
}

const expectTrue: (n: boolean, name: string) => void = (n: boolean, name: string) => {
  try {
    expect(n).assertTrue();
  } catch (err) {
    console.info(`${name}, test failed`);
  }
}

export default function netWorkSecurityTest() {
  describe('netWorkSecurityTest', () => {
    /**
     * @tc.name      : Verifying the 2305069 Error Code of the CertVerification Interface
     * @tc.desc      : Obtain system preset CA certificates and user installed CA certificates from certificate management, and verify the certificate chain passed in by the application.
     */
    it('Verifying the 2305069 Error Code of the CertVerification Interface', 0, async (done: Function) => {
      let caseName: string = 'Verifying the 2305069 Error Code of the CertVerification Interface';
      console.info(`${caseName} test start`);
      try {
        const cert: networkSecurity.CertBlob = {
          type: networkSecurity.CertType.CERT_TYPE_PEM,
          data: '-----BEGIN CERTIFICATE-----\n... (xxxx certificate data) ...\n-----END CERTIFICATE-----',
        };
        networkSecurity.certVerification(cert).then((result) => {
          console.info(`${caseName} Certificate verification result:, ${JSON.stringify(result)}`);
          expectFalse(true, caseName);
          done();
        }).catch((error: BusinessError) => {
          console.error(`${caseName} Certificate verification failed:', ${JSON.stringify(error)}`);
          expectTrue(error.code == 2305069, caseName);
          done();
        });
      } catch (err) {
        console.info(`${caseName}  err:${err}`);
        expectFalse(true, caseName);
        done();
      }
      console.info(`${caseName} test end`);
    });

    /**
     * @tc.name      : Verifying the 2305018 Error Code of the CertVerification Interface
     * @tc.desc      : Obtain system preset CA certificates and user installed CA certificates from certificate management, and verify the certificate chain passed in by the application.
     */
    it('Verifying the 2305018 Error Code of the CertVerification Interface', 0, async (done: Function) => {
      let caseName: string = 'Verifying the 2305018 Error Code of the CertVerification Interface';
      console.info(`${caseName} test start`);
      try {
        const cert: networkSecurity.CertBlob = {
          type: networkSecurity.CertType.CERT_TYPE_PEM,
          data: 'your Self-signed certificate data',
        };
        networkSecurity.certVerification(cert).then((result) => {
          console.info(`${caseName} Certificate verification result:, ${JSON.stringify(result)}`);
          expectFalse(true, caseName);
          done();
        }).catch((error: BusinessError) => {
          console.error(`${caseName} Certificate verification failed:', ${JSON.stringify(error)}`);
          expectTrue(error.code == 2305018, caseName);
          done();
        });
      } catch (err) {
        console.info(`${caseName}  err:${err}`);
        expectFalse(true, caseName);
        done();
      }
      console.info(`${caseName} test end`);
    });
  })
}

```
