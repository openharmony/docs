# Network Subsystem Changelog

## Error Code Change for the certVerification and certVerificationSync APIs

**Access Level**

Public API

**Reason for Change**

The error code of the **certVerification** and **certVerificationSync** APIs needs to be refined.

**Change Impact**

This change is a non-compatible change.

Before change: If a certificate with an invalid context or a self-signed certificate is specified, **2305001 Unspecified error** is displayed.

After change: If the context of a certificate is invalid, **2305069 Invalid certificate verification context** is returned. If the context of a self-signed certificate is invalid, **2305018 Self-signed certificate** is returned.

**Start API Level**

API 11

**Change Since**

OpenHarmony SDK 5.0.0.38

**Adaptation Guide**
The following two test cases of error codes 2305069 and 2305018 are for your reference. During the test, replace **your Self-signed certificate data** in the **Verifying the 2305069 Error Code of the CertVerification** test case with the actual self-signed certificate data.
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
