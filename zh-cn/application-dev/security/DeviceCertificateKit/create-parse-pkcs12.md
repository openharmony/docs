# 证书PKCS12的创建和解析

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

从API 18开始，支持解析PKCS12证书。

从API 21开始，支持创建PKCS12证书。

PKCS12是一种用于存储和传输用户私钥、证书及其相关证书链的标准格式。该格式通过密码保护，将多个密码学对象打包为一个加密的容器文件，支持存储私钥、公钥证书、证书颁发机构证书以及其他相关的密码学数据。PKCS12广泛应用于数字证书的安全存储、跨平台传输和证书备份场景，是实现证书管理和PKI应用的重要标准之一。

## 开发步骤

1. 导入[证书算法库框架模块](../../reference/apis-device-certificate-kit/js-apis-cert.md)。

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```
2. 调用[cert.createPkcs12](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatepkcs1221)创建PKCS12文件。

3. 调用[cert.parsePkcs12](../../reference/apis-device-certificate-kit/js-apis-cert.md#certparsepkcs1218)解析PKCS12文件。

- 异步方法示例：

  ```ts
  import { cert } from '@kit.DeviceCertificateKit';

  // string转Uint8Array。
  function stringToUint8Array(str: string): Uint8Array {
    let arr: number[] = [];
    for (let i = 0, j = str.length; i < j; i++) {
      arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
  }

  async function createX509Cert(certData: string): Promise<cert.X509Cert> {
    // 证书二进制数据，需业务自行赋值。
    let encodingBlob: cert.EncodingBlob = {
      data: stringToUint8Array(certData),
      // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
      encodingFormat: cert.EncodingFormat.FORMAT_PEM
    };

    let x509Cert: cert.X509Cert = {} as cert.X509Cert;
    try {
      x509Cert = await cert.createX509Cert(encodingBlob);
    } catch (err) {
      console.error(`createX509Cert failed: errCode: ${err.code}, message: ${err.message}`);
    }
    return x509Cert;
  }

  let priKey = '-----BEGIN PRIVATE KEY-----\n' +
    'MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQC9kBV6Cqd3vSi5\n' +
    'RuRAWjXEvsfD20ekCYyeJvnnSrHwnKodbF8VWFSv4sqYzMnxObpDLyQw0Uu08tbn\n' +
    'EQvxv0lOwnWkZR+Oc3M9Ow1uhDkm3eFbY5858mAmtY7Sqzhd0LS9k8Q57FRqOrQm\n' +
    '7ngHb0O+yjCIn/zmjyEuw51/cPDTM4h3P3di9nhbIg+UOMfkDbuSKRD7UvVV/JZi\n' +
    'BklF5ZrjFYgzYnWKv7N7XkYMGkaOx8+tue24eK06SapQWDLRnRPCVePV6xtoCmbN\n' +
    'A3ib/Uvr0qvRwPDCzGGOW9JvQdrI6Z/GD9nt5hqHB15iJVNxkDQtugv14qeDsFPS\n' +
    'IU8CtkCbAgMBAAECggEBAKbMmMlJhLCM5r+ZDJE/j55ujRLe6XwC1xP2keEeTdK9\n' +
    '18aKLGR41BPsSH8JfAxh0m75lSvLjoVLRSQPUOZIfjXqUF/2hzzug5F2W8xKVovH\n' +
    'o1uqHlp71nVZPrJK7Q9H7TH/SyP4uxK6UvkKzt0j34WLHgeqV3t8qCMhB34zIAWG\n' +
    'BcAuKJNRZGvMvjK99OSOh0SyvGQ5Yb5vyj1/znx3gM4z4deYXxDSyCO0m5I16jmM\n' +
    'gBEUG0UDUp8Xr2xs/EkhhWYRT1bkDlYZ9IuCbH/vB1YJJFdaO2tDivDUF6IObvNt\n' +
    'GaVuLlA/rSOJmJFBetrm7n+O2vNJxvoQmBYDKm3+qYkCgYEA9p5C1ZY5XfwwOcqi\n' +
    'KQ+Asd2NWLG2blhsII5wB8uPhFapjV0S9xTabScUD35AfxHgctafpZeQk4x5niRP\n' +
    'BHq7hpitaDdYs6A/jhZ7fdVYKb1KRTDt1LXmcg0qVmi/ANNvjhqjvyZM+pEj8yxM\n' +
    'aOl4isbBfUbzSsEbda3LcHi6+w8CgYEAxMYtkl3gbXJcgbAEdW+nMMQGoFDLkgyu\n' +
    'n0ZYuRRrWLnnUzZUyqNBwQUaZpwxHaAqi0OAEGSRSZBKRHz9IA2iP9YzcaJ0WtpB\n' +
    'CPqwBZjrCaVEpHldo2pIdujysXgiXRUiE+VR9ViDmftoVbdL6kttGS08jBBDVIV/\n' +
    'uQgC/q29UbUCgYAJHirMaMRwNB24VUSPjhItAUrzh4Z+J+i/f2Sm9SC2PNoB7vn/\n' +
    'hpbYyEQWmo1Z5VhOBp9aaPMgcWYhsaf2O29pd4WZv8oYwgj3gN9J9LRQvr3bNwbk\n' +
    'AWGmv9Pb4/2D001hjJyXOZxI+0q/99hPXKpnPxfyQMhH8EHKpQVLgDsxgwKBgEiH\n' +
    '+DJUci5Fkj2ngO08u7bo+rxLK85o6FEDYB7QnQT2eYMdqsGKzej1FZcvCZeu+x+c\n' +
    'QO9J8pfYHNgD7lXLULwRG6NOS29VtdU2en2FsVU72wJ5Tf+3ZICYOyUZcCk5afdF\n' +
    'dyFlgBTZK8s0pkH1jYBTQVcrg3X7Q2oTvu7bYcZlAoGAUwQI11mMR8oqfgWMoI/1\n' +
    'smOoq9qSMlutuWBjoPkbtJEGHEXAvjW1kgdBlPjUCwn6j+oIDLYu8DbfQRdiFQeP\n' +
    'rVCbbgOgayVpr+8Tv2DqB370GwBpOpuq0yiiN+c39Y0u03Yfve3icyl8+lN1t4h6\n' +
    'a20rj9HG4sb8tUIHPBv0dgY=\n' +
    '-----END PRIVATE KEY-----\n';

  let othercerts = '-----BEGIN CERTIFICATE-----\n' +
    'MIIDZTCCAk0CFAoqA7Irtoo7/3+sfOHy0s91pKkiMA0GCSqGSIb3DQEBCwUAMG8x\n' +
    'CzAJBgNVBAYTAkVOMQ0wCwYDVQQIDARURVNUMQ0wCwYDVQQHDAR4aWFuMQ8wDQYD\n' +
    'VQQKDAZodWF3ZWkxDTALBgNVBAsMBHhpYW4xDTALBgNVBAMMBHhpYW4xEzARBgkq\n' +
    'hkiG9w0BCQEWBHhpYW4wHhcNMjUwODE0MTE1NDM0WhcNMjYwODE0MTE1NDM0WjBv\n' +
    'MQswCQYDVQQGEwJFTjENMAsGA1UECAwEVEVTVDENMAsGA1UEBwwEeGlhbjEPMA0G\n' +
    'A1UECgwGaHVhd2VpMQ0wCwYDVQQLDAR4aWFuMQ0wCwYDVQQDDAR4aWFuMRMwEQYJ\n' +
    'KoZIhvcNAQkBFgR4aWFuMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n' +
    'wk4aByV5nOw+zIh/1agaN7rQyk+NFuXlYSwINrONRZt8zePSxhxz6gMq0XAb8ld0\n' +
    'DFC5onGQEI4ED8iP3v7C7yHqIAybTmIy22RWWk8c6h9S40Azp/YHujTTRs2XMe9G\n' +
    'A/iKed9DwLclbv6+m+WPmIvgFFAJlebtFI6X0E/zBxs/TknR8tJ2uk2G/CGCBlo5\n' +
    'bbSz5RIPfEmz93rR7prMxQLOsvfdNewNlhe82jxMKfzGEPXYXUj+Xwp8ep+aaUTr\n' +
    'Kb6Thvx7+uOBxgMM1crREepTKJM/4bsOpb2yIXXcOqclUPAZBvtzIjgs/DdKtCZo\n' +
    '0Jzr3gUbDJeE2xd+DcADxQIDAQABMA0GCSqGSIb3DQEBCwUAA4IBAQA5RyDOMYJV\n' +
    'AsdBUihPvnnakKfAY9CYN9I1tR0b9DaboeL+bONeIKzXyFdDrAj6eZLKZLUblFlH\n' +
    'BZnbP4lNwfYjmNgp4j7cqSIFVwd2Y+6T29pK6T6XYRsFGOaSp7wFzXplfbP8Ou1b\n' +
    'o2zTZWWWHbiExuXot4RfQkgH3Zhk5zjJGWvaOksvEhJUaufkWAXbRY2KHmH64dDB\n' +
    'Bgp50CPObTuc2a+5PAi7W5nj1se2OqKvepoeYLl8pfF/GFRqrvcII9kCm0oyMqBx\n' +
    '25R7aCNtSnENZnvRBspdYcX8zu6fR1qf0JmpLqLw5pPxJ2Puvq7g+33GWJ3Gq45f\n' +
    'ZcLXS+9LpW3a\n' +
    '-----END CERTIFICATE-----\n';

  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIDZzCCAk8CFCwQ5cxuFI+fsf/2fkG4gy8UT1gmMA0GCSqGSIb3DQEBCwUAMG8x\n' +
    'CzAJBgNVBAYTAkVOMQ0wCwYDVQQIDARURVNUMQ0wCwYDVQQHDAR4aWFuMQ8wDQYD\n' +
    'VQQKDAZodWF3ZWkxDTALBgNVBAsMBHhpYW4xDTALBgNVBAMMBHhpYW4xEzARBgkq\n' +
    'hkiG9w0BCQEWBHhpYW4wHhcNMjUwODE0MTE1NTQ1WhcNMjYwODE0MTE1NTQ1WjBx\n' +
    'MQswCQYDVQQGEwJHVDEPMA0GA1UECAwGaHVhd2VpMQ0wCwYDVQQHDAR4aWFuMQ8w\n' +
    'DQYDVQQKDAZodWF3ZWkxDTALBgNVBAsMBHhpYW4xDTALBgNVBAMMBHhpYW4xEzAR\n' +
    'BgkqhkiG9w0BCQEWBHhpYW4wggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIB\n' +
    'AQC9kBV6Cqd3vSi5RuRAWjXEvsfD20ekCYyeJvnnSrHwnKodbF8VWFSv4sqYzMnx\n' +
    'ObpDLyQw0Uu08tbnEQvxv0lOwnWkZR+Oc3M9Ow1uhDkm3eFbY5858mAmtY7Sqzhd\n' +
    '0LS9k8Q57FRqOrQm7ngHb0O+yjCIn/zmjyEuw51/cPDTM4h3P3di9nhbIg+UOMfk\n' +
    'DbuSKRD7UvVV/JZiBklF5ZrjFYgzYnWKv7N7XkYMGkaOx8+tue24eK06SapQWDLR\n' +
    'nRPCVePV6xtoCmbNA3ib/Uvr0qvRwPDCzGGOW9JvQdrI6Z/GD9nt5hqHB15iJVNx\n' +
    'kDQtugv14qeDsFPSIU8CtkCbAgMBAAEwDQYJKoZIhvcNAQELBQADggEBALuqlvql\n' +
    'q/5SVghmtdzVNlsif9JofSgJhmww3r8HblZ7zD7ALfR6JcxxbBJYdBIn6mf2eNx/\n' +
    'kTzwYs94D12PhyAP63AcDxS/4Sh7QhmnNIx2SGi/rbFdPm8cmkaFfwr5gQP+ouNB\n' +
    '1e7vVyNpSjr4F8YcfjOHPofoCdWaOaBPrM760h711y/BTVMjuYkdzn0D1bHZIBc+\n' +
    'tljIMWXKsTwR6wCIpnFRJbEATTBwV843Q071d62jYueLgdS2wT39Syqb3ao3aHAS\n' +
    'ZI8k9GgNNKD4qBAZUbQVCs6diTBbeUMaqJ2N+tcQfmGfnNZK+/olEF6Ue/H0LZzY\n' +
    'nZSOvPxc0c2O34k=\n' +
    '-----END CERTIFICATE-----\n';

  async function doTestCreatePkcs12() {
    const caCert = await createX509Cert(othercerts);
    const x509Cert = await createX509Cert(certData);

    let data : cert.Pkcs12Data = {
      privateKey : priKey,
      cert : x509Cert,
      otherCerts : [caCert]
    }

    let keyParam : cert.PbesParams = {
      saltLen : 16,
      iterations : 2048,
      encryptionAlgorithm : cert.PbesEncryptionAlgorithm.AES_192_CBC
    }

    let certParam : cert.PbesParams = {
      saltLen : 16,
      iterations : 2048,
      encryptionAlgorithm : cert.PbesEncryptionAlgorithm.AES_256_CBC
    }

    let config : cert.Pkcs12CreationConfig = {
      password : "123456",
      keyEncParams : keyParam,
      encryptCert : true,
      certEncParams : certParam,
      macSaltLen : 16,
      macIterations : 2048,
      macDigestAlgorithm : cert.Pkcs12MacDigestAlgorithm.SHA384
    }

    try {
      let p12 = await cert.createPkcs12(data, config);
      console.info("createPkcs12 succeed p12 = " + p12);
      let out: cert.Pkcs12Data = await cert.parsePkcs12(p12, "123456");
      console.info("parsePKCS12 succeed.");
      if (out.privateKey) {
        console.info("privateKey:" + out.privateKey.toString());
      }
      if (out.cert) {
        console.info("cert:" + out.cert.toString());
      }
      if (out.otherCerts && Array.isArray(out.otherCerts)) {
        console.info("otherCerts counts:", out.otherCerts.length);
        out.otherCerts.forEach((cert, idx) => {
          console.info(`otherCerts[${idx}]:\n${cert.toString()}`);
        });
      } else {
        console.info("otherCerts is empty or not an array.");
      }
    } catch (err) {
      console.error(`doTestCreatePkcs12 failed: errCode: ${err.code}, message: ${err.message}`);
    }
  }
  ```

- 同步方法示例：

  ```ts
  import { cert } from '@kit.DeviceCertificateKit';

  // string转Uint8Array。
  function stringToUint8Array(str: string): Uint8Array {
    let arr: number[] = [];
    for (let i = 0, j = str.length; i < j; i++) {
      arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
  }

  async function createX509Cert(certData: string): Promise<cert.X509Cert> {
    // 证书二进制数据，需业务自行赋值。
    let encodingBlob: cert.EncodingBlob = {
      data: stringToUint8Array(certData),
      // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
      encodingFormat: cert.EncodingFormat.FORMAT_PEM
    };

    let x509Cert: cert.X509Cert = {} as cert.X509Cert;
    try {
      x509Cert = await cert.createX509Cert(encodingBlob);
    } catch (err) {
      console.error(`doTestCreatePkcs12 failed: errCode: ${err.code}, message: ${err.message}`);
    }
    return x509Cert;
  }

  let priKey = '-----BEGIN PRIVATE KEY-----\n' +
    'MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQC9kBV6Cqd3vSi5\n' +
    'RuRAWjXEvsfD20ekCYyeJvnnSrHwnKodbF8VWFSv4sqYzMnxObpDLyQw0Uu08tbn\n' +
    'EQvxv0lOwnWkZR+Oc3M9Ow1uhDkm3eFbY5858mAmtY7Sqzhd0LS9k8Q57FRqOrQm\n' +
    '7ngHb0O+yjCIn/zmjyEuw51/cPDTM4h3P3di9nhbIg+UOMfkDbuSKRD7UvVV/JZi\n' +
    'BklF5ZrjFYgzYnWKv7N7XkYMGkaOx8+tue24eK06SapQWDLRnRPCVePV6xtoCmbN\n' +
    'A3ib/Uvr0qvRwPDCzGGOW9JvQdrI6Z/GD9nt5hqHB15iJVNxkDQtugv14qeDsFPS\n' +
    'IU8CtkCbAgMBAAECggEBAKbMmMlJhLCM5r+ZDJE/j55ujRLe6XwC1xP2keEeTdK9\n' +
    '18aKLGR41BPsSH8JfAxh0m75lSvLjoVLRSQPUOZIfjXqUF/2hzzug5F2W8xKVovH\n' +
    'o1uqHlp71nVZPrJK7Q9H7TH/SyP4uxK6UvkKzt0j34WLHgeqV3t8qCMhB34zIAWG\n' +
    'BcAuKJNRZGvMvjK99OSOh0SyvGQ5Yb5vyj1/znx3gM4z4deYXxDSyCO0m5I16jmM\n' +
    'gBEUG0UDUp8Xr2xs/EkhhWYRT1bkDlYZ9IuCbH/vB1YJJFdaO2tDivDUF6IObvNt\n' +
    'GaVuLlA/rSOJmJFBetrm7n+O2vNJxvoQmBYDKm3+qYkCgYEA9p5C1ZY5XfwwOcqi\n' +
    'KQ+Asd2NWLG2blhsII5wB8uPhFapjV0S9xTabScUD35AfxHgctafpZeQk4x5niRP\n' +
    'BHq7hpitaDdYs6A/jhZ7fdVYKb1KRTDt1LXmcg0qVmi/ANNvjhqjvyZM+pEj8yxM\n' +
    'aOl4isbBfUbzSsEbda3LcHi6+w8CgYEAxMYtkl3gbXJcgbAEdW+nMMQGoFDLkgyu\n' +
    'n0ZYuRRrWLnnUzZUyqNBwQUaZpwxHaAqi0OAEGSRSZBKRHz9IA2iP9YzcaJ0WtpB\n' +
    'CPqwBZjrCaVEpHldo2pIdujysXgiXRUiE+VR9ViDmftoVbdL6kttGS08jBBDVIV/\n' +
    'uQgC/q29UbUCgYAJHirMaMRwNB24VUSPjhItAUrzh4Z+J+i/f2Sm9SC2PNoB7vn/\n' +
    'hpbYyEQWmo1Z5VhOBp9aaPMgcWYhsaf2O29pd4WZv8oYwgj3gN9J9LRQvr3bNwbk\n' +
    'AWGmv9Pb4/2D001hjJyXOZxI+0q/99hPXKpnPxfyQMhH8EHKpQVLgDsxgwKBgEiH\n' +
    '+DJUci5Fkj2ngO08u7bo+rxLK85o6FEDYB7QnQT2eYMdqsGKzej1FZcvCZeu+x+c\n' +
    'QO9J8pfYHNgD7lXLULwRG6NOS29VtdU2en2FsVU72wJ5Tf+3ZICYOyUZcCk5afdF\n' +
    'dyFlgBTZK8s0pkH1jYBTQVcrg3X7Q2oTvu7bYcZlAoGAUwQI11mMR8oqfgWMoI/1\n' +
    'smOoq9qSMlutuWBjoPkbtJEGHEXAvjW1kgdBlPjUCwn6j+oIDLYu8DbfQRdiFQeP\n' +
    'rVCbbgOgayVpr+8Tv2DqB370GwBpOpuq0yiiN+c39Y0u03Yfve3icyl8+lN1t4h6\n' +
    'a20rj9HG4sb8tUIHPBv0dgY=\n' +
    '-----END PRIVATE KEY-----\n';

  let othercerts = '-----BEGIN CERTIFICATE-----\n' +
    'MIIDZTCCAk0CFAoqA7Irtoo7/3+sfOHy0s91pKkiMA0GCSqGSIb3DQEBCwUAMG8x\n' +
    'CzAJBgNVBAYTAkVOMQ0wCwYDVQQIDARURVNUMQ0wCwYDVQQHDAR4aWFuMQ8wDQYD\n' +
    'VQQKDAZodWF3ZWkxDTALBgNVBAsMBHhpYW4xDTALBgNVBAMMBHhpYW4xEzARBgkq\n' +
    'hkiG9w0BCQEWBHhpYW4wHhcNMjUwODE0MTE1NDM0WhcNMjYwODE0MTE1NDM0WjBv\n' +
    'MQswCQYDVQQGEwJFTjENMAsGA1UECAwEVEVTVDENMAsGA1UEBwwEeGlhbjEPMA0G\n' +
    'A1UECgwGaHVhd2VpMQ0wCwYDVQQLDAR4aWFuMQ0wCwYDVQQDDAR4aWFuMRMwEQYJ\n' +
    'KoZIhvcNAQkBFgR4aWFuMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n' +
    'wk4aByV5nOw+zIh/1agaN7rQyk+NFuXlYSwINrONRZt8zePSxhxz6gMq0XAb8ld0\n' +
    'DFC5onGQEI4ED8iP3v7C7yHqIAybTmIy22RWWk8c6h9S40Azp/YHujTTRs2XMe9G\n' +
    'A/iKed9DwLclbv6+m+WPmIvgFFAJlebtFI6X0E/zBxs/TknR8tJ2uk2G/CGCBlo5\n' +
    'bbSz5RIPfEmz93rR7prMxQLOsvfdNewNlhe82jxMKfzGEPXYXUj+Xwp8ep+aaUTr\n' +
    'Kb6Thvx7+uOBxgMM1crREepTKJM/4bsOpb2yIXXcOqclUPAZBvtzIjgs/DdKtCZo\n' +
    '0Jzr3gUbDJeE2xd+DcADxQIDAQABMA0GCSqGSIb3DQEBCwUAA4IBAQA5RyDOMYJV\n' +
    'AsdBUihPvnnakKfAY9CYN9I1tR0b9DaboeL+bONeIKzXyFdDrAj6eZLKZLUblFlH\n' +
    'BZnbP4lNwfYjmNgp4j7cqSIFVwd2Y+6T29pK6T6XYRsFGOaSp7wFzXplfbP8Ou1b\n' +
    'o2zTZWWWHbiExuXot4RfQkgH3Zhk5zjJGWvaOksvEhJUaufkWAXbRY2KHmH64dDB\n' +
    'Bgp50CPObTuc2a+5PAi7W5nj1se2OqKvepoeYLl8pfF/GFRqrvcII9kCm0oyMqBx\n' +
    '25R7aCNtSnENZnvRBspdYcX8zu6fR1qf0JmpLqLw5pPxJ2Puvq7g+33GWJ3Gq45f\n' +
    'ZcLXS+9LpW3a\n' +
    '-----END CERTIFICATE-----\n';

  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIDZzCCAk8CFCwQ5cxuFI+fsf/2fkG4gy8UT1gmMA0GCSqGSIb3DQEBCwUAMG8x\n' +
    'CzAJBgNVBAYTAkVOMQ0wCwYDVQQIDARURVNUMQ0wCwYDVQQHDAR4aWFuMQ8wDQYD\n' +
    'VQQKDAZodWF3ZWkxDTALBgNVBAsMBHhpYW4xDTALBgNVBAMMBHhpYW4xEzARBgkq\n' +
    'hkiG9w0BCQEWBHhpYW4wHhcNMjUwODE0MTE1NTQ1WhcNMjYwODE0MTE1NTQ1WjBx\n' +
    'MQswCQYDVQQGEwJHVDEPMA0GA1UECAwGaHVhd2VpMQ0wCwYDVQQHDAR4aWFuMQ8w\n' +
    'DQYDVQQKDAZodWF3ZWkxDTALBgNVBAsMBHhpYW4xDTALBgNVBAMMBHhpYW4xEzAR\n' +
    'BgkqhkiG9w0BCQEWBHhpYW4wggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIB\n' +
    'AQC9kBV6Cqd3vSi5RuRAWjXEvsfD20ekCYyeJvnnSrHwnKodbF8VWFSv4sqYzMnx\n' +
    'ObpDLyQw0Uu08tbnEQvxv0lOwnWkZR+Oc3M9Ow1uhDkm3eFbY5858mAmtY7Sqzhd\n' +
    '0LS9k8Q57FRqOrQm7ngHb0O+yjCIn/zmjyEuw51/cPDTM4h3P3di9nhbIg+UOMfk\n' +
    'DbuSKRD7UvVV/JZiBklF5ZrjFYgzYnWKv7N7XkYMGkaOx8+tue24eK06SapQWDLR\n' +
    'nRPCVePV6xtoCmbNA3ib/Uvr0qvRwPDCzGGOW9JvQdrI6Z/GD9nt5hqHB15iJVNx\n' +
    'kDQtugv14qeDsFPSIU8CtkCbAgMBAAEwDQYJKoZIhvcNAQELBQADggEBALuqlvql\n' +
    'q/5SVghmtdzVNlsif9JofSgJhmww3r8HblZ7zD7ALfR6JcxxbBJYdBIn6mf2eNx/\n' +
    'kTzwYs94D12PhyAP63AcDxS/4Sh7QhmnNIx2SGi/rbFdPm8cmkaFfwr5gQP+ouNB\n' +
    '1e7vVyNpSjr4F8YcfjOHPofoCdWaOaBPrM760h711y/BTVMjuYkdzn0D1bHZIBc+\n' +
    'tljIMWXKsTwR6wCIpnFRJbEATTBwV843Q071d62jYueLgdS2wT39Syqb3ao3aHAS\n' +
    'ZI8k9GgNNKD4qBAZUbQVCs6diTBbeUMaqJ2N+tcQfmGfnNZK+/olEF6Ue/H0LZzY\n' +
    'nZSOvPxc0c2O34k=\n' +
    '-----END CERTIFICATE-----\n';

  async function doTestCreatePkcs12Sync() {
    const caCert = await createX509Cert(othercerts);
    const x509Cert = await createX509Cert(certData);

    let data : cert.Pkcs12Data = {
      privateKey : priKey,
      cert : x509Cert,
      otherCerts : [caCert]
    }

    let keyParam : cert.PbesParams = {
      saltLen : 16,
      iterations : 2048,
      encryptionAlgorithm : cert.PbesEncryptionAlgorithm.AES_192_CBC
    }

    let certParam : cert.PbesParams = {
      saltLen : 16,
      iterations : 2048,
      encryptionAlgorithm : cert.PbesEncryptionAlgorithm.AES_256_CBC
    }

    let config : cert.Pkcs12CreationConfig = {
      password : "123456",
      keyEncParams : keyParam,
      encryptCert : true,
      certEncParams : certParam,
      macSaltLen : 16,
      macIterations : 2048,
      macDigestAlgorithm : cert.Pkcs12MacDigestAlgorithm.SHA384
    }

    try {
      let p12 = cert.createPkcs12Sync(data, config);
      console.info("createPkcs12Sync succeed p12 = " + p12);
      let conf: cert.Pkcs12ParsingConfig = {
        password: "123456",
        needsCert: true,
        needsPrivateKey: true,
        privateKeyFormat: cert.EncodingBaseFormat.PEM,
        needsOtherCerts: true,
      };
      let out: cert.Pkcs12Data = cert.parsePkcs12(p12, conf);
      console.info("parsePKCS12 succeed.");
      if (out.privateKey) {
        console.info("privateKey:" + out.privateKey.toString());
      }
      if (out.cert) {
        console.info("cert:" + out.cert.toString());
      }
      if (out.otherCerts && Array.isArray(out.otherCerts)) {
        console.info("otherCerts counts:", out.otherCerts.length);
        out.otherCerts.forEach((cert, idx) => {
          console.info(`otherCerts[${idx}]:\n${cert.toString()}`);
        });
      } else {
        console.info("otherCerts is empty or not an array.");
      }
    } catch (err) {
      console.error(`doTestCreatePkcs12 failed: errCode: ${err.code}, message: ${err.message}`);
    }
  }
  ```