# Certificate Chain Validator Development

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

A certificate chain is an ordered list of certificates, in which each certificate is signed by the entity identified by the next certificate in the chain.

As shown in the following figure, the certificate chain consists of three certificates. The root certificate is self-signed by GlobalSign, which signed the intermediate certificate held by GlobalSign RSA OV SSL CA 2018. GlobalSign RSA OV SSL CA 2018 (the holder of the intermediate certificate) signed the end certificate.

![](figures/certificate_chain_example.png)

You can refer to the following example to construct a certificate chain from multiple certificates.

## How to Develop

1. Import the [certFramework](../../reference/apis-device-certificate-kit/js-apis-cert.md) module.
   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Use [cert.createCertChainValidator](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatecertchainvalidator) to create a certificate chain validator (**CertChainValidator**) object.

3. Create a [CertChainData](../../reference/apis-device-certificate-kit/js-apis-cert.md#certchaindata) object.
   
   The certificate framework provides the **CertChainValidator** object to validate the root of the trust chain. The **CertChainValidator** object to be validated must comply with the data structure definition [CertChainData](../../reference/apis-device-certificate-kit/js-apis-cert.md#certchaindata).

4. Use [CertChainValidator.validate](../../reference/apis-device-certificate-kit/js-apis-cert.md#validate) to validate the certificate chain data.

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { util } from '@kit.ArkTS';

// CA data, which is only an example.
let caCertData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIDgTCCAmmgAwIBAgIGAXKnJjrAMA0GCSqGSIb3DQEBCwUAMFcxCzAJBgNVBAYT\n' +
  'AkNOMQ8wDQYDVQQIDAbpmZXopb8xDzANBgNVBAcMBuilv+WuiTEPMA0GA1UECgwG\n' +
  '5rWL6K+VMRUwEwYDVQQDDAzkuK3mlofmtYvor5UwHhcNMjUwMjIwMDI1NjMxWhcN\n' +
  'MzUwMjE4MDI1NjMxWjBXMQswCQYDVQQGEwJDTjEPMA0GA1UECAwG6ZmV6KW/MQ8w\n' +
  'DQYDVQQHDAbopb/lrokxDzANBgNVBAoMBua1i+ivlTEVMBMGA1UEAwwM5Lit5paH\n' +
  '5rWL6K+VMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAyY30ubE33Zmc\n' +
  'BBM4OIpD1UuDVKynC4xNBK4v79vnlc4ElmRZD4RjkS612DtpaUzt/yHMZXmJTdqg\n' +
  '2jq7UG4sQc0G3uNGIXdUpRZpnUYGVftuZMxHaNOb+IgDkZzaO3Dk33piOpH/X/Ke\n' +
  'OosCbm7eBL+y+wRhUsLSCEasEsIvW3edHuYLrfz3MzwY/9AmnwqDGdRJ5rPayODD\n' +
  'HH0yw9JuRkdMacN8omVX8jBfJeI8KafcQW8MJz+Y0qyQyiZ6A81AQSVfT+6Sk2U3\n' +
  'UqeSTmtdIL1u29HfYLwYGHey+1Ro2wxqnMsFKIdKu2dDMDQZx61pER/dFtPYFlS7\n' +
  '/uh3mi9HUQIDAQABo1MwUTAdBgNVHQ4EFgQUGDykmR825RPNFIEQaFzUqkr+CIow\n' +
  'HwYDVR0jBBgwFoAUGDykmR825RPNFIEQaFzUqkr+CIowDwYDVR0TAQH/BAUwAwEB\n' +
  '/zANBgkqhkiG9w0BAQsFAAOCAQEAXjlmYKjBz1ajWywZNlN+LVRXNx7bS4TYtOc2\n' +
  'ME4N1ls6yjWSLtBe4DdkBqZ2HwrVW4dg5xZdAS/T0v/rRiGbX6iUFRV9WCTdtLZB\n' +
  'HKNh7vU39F7mgTaaWXQK/+6NeLKMzwJENRRaESI/sXeKE6irfJgYuq3NH8GGFd+w\n' +
  'HnvVBHRb6WSlY2s5Li7t6lj40UbwOljnqzRQvBeX57rOnzJgVKND3oY9pex/05Oe\n' +
  '96x+qc2iqZbu54A6NYCTj/65EEKoj5rYxPXMV4FegV42ouaLJJoS+cEEY7w+ixcl\n' +
  '04TjtjEdhTZiJCmI0RK50H2SWC0t9qkFewM3CCWTHY5ygPtMGA==\n' +
  '-----END CERTIFICATE-----\n';

// Level-2 CA certificate data, which is only an example.
let secondCaCertData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIDgTCCAmmgAwIBAgIGAXKnJjrBMA0GCSqGSIb3DQEBCwUAMFcxCzAJBgNVBAYT\n' +
  'AkNOMQ8wDQYDVQQIDAbpmZXopb8xDzANBgNVBAcMBuilv+WuiTEPMA0GA1UECgwG\n' +
  '5rWL6K+VMRUwEwYDVQQDDAzkuK3mlofmtYvor5UwHhcNMjUwMjIwMDI1NjU3WhcN\n' +
  'MzUwMjE4MDI1NjU3WjBXMQswCQYDVQQGEwJDTjEPMA0GA1UECAwG6ZmV6KW/MQ8w\n' +
  'DQYDVQQHDAbopb/lrokxDzANBgNVBAoMBua1i+ivlTEVMBMGA1UEAwwM5Lit5paH\n' +
  '5rWL6K+VMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAxSL5L7fwMaRF\n' +
  'RiT1l7kpzaAqZe33/3lgexoMfGiIFarIhYyYJsmOJKes2uLSnPeqEtscrXmFQiIG\n' +
  '0srmwrriGgo3oxDp4/5i1FhCf3FqZUwD/RJhtVmkHT0HoYl4cpt/dJSF/e5vxt/J\n' +
  '2Z1eRIQOj9DzyqET6+ONQmfVOyzEH6xlpXHZLvykSZ7ytPp25LxULPWjTmpDOPRq\n' +
  'vkSMaH4H3mPw/Z9r0MVKP7DgAZMl2yVudHp785AMTVD0L9zWGHf3sek25ek5nv2r\n' +
  'SlB21MTBpvd8GC/iGns4V3Bvf75WAMgpGghAkRRyADeqt5Hw+x9BIb9FcfE+h6n+\n' +
  '6EF6FPa8GQIDAQABo1MwUTAdBgNVHQ4EFgQUjt2Crk/j6W8WCdHWyz4H+Q2/3PYw\n' +
  'HwYDVR0jBBgwFoAUGDykmR825RPNFIEQaFzUqkr+CIowDwYDVR0TAQH/BAUwAwEB\n' +
  '/zANBgkqhkiG9w0BAQsFAAOCAQEAksPHMuVF9e2GMVlaSe1Ao9D1KrJvKNaFZPCI\n' +
  'lQe2CDsX+Qu7sQj4SML5vvWFLtcAp6ZovqUyEM0PtZWVSjPCRTMJ3ofBPwnXvQ2N\n' +
  '7J7NCDA227MQabXeN3jMhkcAzlpdO5poTnobPF4xRqb39jM7otnNJsujvzdDab2l\n' +
  'LiP4eU5TrEaF2lwidBWJX0VoLrRpqzQhiWXGMpCBBugP5U+bFs20wezJBG19WYyc\n' +
  '2xKKfvyIcxrpmvjLZl8HddS7Ot1CKXyc8U9QZBGAlPwOXu8juppcEtjJyl36EnvF\n' +
  'YAcwrXOAtCiNpX3UnLUbG8GtpOOWQWCt+x1gKmA6V0jbqQmqcw==\n' +
  '-----END CERTIFICATE-----\n';

// Certificate chain validator. In this example, it validates a two-level certificate chain.
function certChainValidatorSample(): void {
  let textEncoder = new util.TextEncoder();
  // Certificate chain validator algorithm. Currently, only PKIX is supported.
  let algorithm = 'PKIX';

  // Create a CertChainValidator object.
  let validator = cert.createCertChainValidator(algorithm);

  // CA certificate data.
  let uint8ArrayOfCaCertData = textEncoder.encodeInto(caCertData);

  // Length of the CA certificate data.
  let uint8ArrayOfCaCertDataLen = new Uint8Array(new Uint16Array([uint8ArrayOfCaCertData.byteLength]).buffer);

  // Level-2 CA certificate data.
  let uint8ArrayOf2ndCaCertData =  textEncoder.encodeInto(secondCaCertData);

  // Length of the level-2 CA certificate data.
  let uint8ArrayOf2ndCaCertDataLen = new Uint8Array(new Uint16Array([uint8ArrayOf2ndCaCertData.byteLength]).buffer);

  // Binary data of the certificate chain in L-V format: Length of the level-2 CA certificate data + Level-2 CA certificate data + Length of the CA certificate data + CA certificate data.
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

  let certChainData: cert.CertChainData = {
    // Uint8Array in L-V format (certificate data length-certificate data).
    data: encodingData,
    // Number of certificates. In this example, there are two certificates in the certification chain.
    count: 2,
    // Certificate format. Only PEM and DER are supported. In this example, the certificate is in PEM format.
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  // Validate the certificate chain.
  validator.validate(certChainData, (err, data) => {
    if (err != null) {
      // Validation failed.
      console.error(`validate failed, errCode: ${err.code}, errMsg: ${err.message}`);
    } else {
      // Validation successful.
      console.log('validate success');
    }
  });
}
```
