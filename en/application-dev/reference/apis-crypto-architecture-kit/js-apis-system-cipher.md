# @system.cipher (Cipher Algorithm)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module are deprecated since API version 9. You are advised to use [@ohos.security.cryptoFramework Cipher](js-apis-cryptoFramework.md#cipher).

## Modules to Import


```js
import cipher from '@system.cipher';
```

## CipherResponse

Defines the response to the cipher interface called.

**System capability**: SystemCapability.Security.Cipher

| Name| Type  | Readable| Writable|Description        |
| ------ | ------ | ---- | ---- | ------------ |
| text   | string | Yes  | No  | Response content.|


## CipherRsaOptions

Defines the input parameters of **cipher.rsa()**.

**System capability**: SystemCapability.Security.Cipher

| Name        | Type                                | Mandatory| Description                                                        |
| -------------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| action         | string                               | Yes  | Action to perform. The options are as follows:<br>1. **encrypt**: Encrypts data.<br>2. **decrypt**: Decrypts data.|
| text           | string                               | Yes  | Text to be encrypted or decrypted.<br>The text to be encrypted must be a common text and cannot exceed the length calculated based on the formula (keySize/8 - 66). **keySize** indicates the key length. <br/>For example, if the key length is 1024 bytes, the text cannot exceed 62 bytes (1024/8 - 66 = 62). The text to be decrypted must be a binary value encoded in Base64. The default format is used for Base64 encoding. |
| key            | string                               | Yes  | RSA key. It is a public key in encryption and a private key in decryption.     |
| transformation | string                               | No  | RSA padding. The default value is **RSA/None/OAEPWithSHA256AndMGF1Padding**.|
| success        | (data: [CipherResponse](#cipherresponse)) => void       | No  | Called when data is encrypted or decrypted successfully.                                    |
| fail           | (data: string, code: number) => void | No  | Called when data fails to be encrypted or decrypted.                                    |
| complete       | () => void                           | No  | Called when the execution is complete.                                    |

## CipherAesOptions

Defines the input parameters of **cipher.aes()**.

**System capability**: SystemCapability.Security.Cipher

| Name        | Type                                | Mandatory| Description                                                        |
| -------------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| action         | string                               | Yes  | Action to perform. The options are as follows:<br>1. **encrypt**: Encrypts data.<br>2. **decrypt**: Decrypts data.|
| text           | string                               | Yes  | Text to be encrypted or decrypted.<br> The text to be encrypted must be common text. The text to be decrypted must be a binary value encoded in Base64. The default format is used for Base64 encoding.|
| key            | string                               | Yes  | Key used for encryption or decryption. It is a Base64 encoded string.|
| transformation | string                               | No  | Encryption mode and padding of the AES algorithm. The default value is **AES/CBC/PKCS5Padding**.         |
| iv             | string                               | No  | Initialization vector (IV) for AES-based encryption and decryption. The value is a string encoded in Base64. The default value is the key value.|
| ivOffset       | string                               | No  | Offset of the IV for AES-based encryption and decryption. The default value is **0**, which is the only value supported.                 |
| ivLen          | string                               | No  | Length of the IV, in bytes. This field is reserved. The default value is **16**, which is the only value supported.|
| success        | (data: [CipherResponse](#cipherresponse)) => void       | No  | Called when data is encrypted or decrypted successfully.                                    |
| fail           | (data: string, code: number) => void | No  | Called when data fails to be encrypted or decrypted.                                    |
| complete       | () => void                           | No  | Called when the execution is complete.                                    |

## cipher.rsa

rsa(options: CipherRsaOptions): void

Encrypts or decrypts data using RSA.

**System capability**: SystemCapability.Security.Cipher

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [CipherRsaOptions](#cipherrsaoptions) | Yes| Parameters set for RSA encryption or decryption.|

**Example**

```js
export default {
  rsa() {
    cipher.rsa({
      // Encrypt data.
      action: 'encrypt',
      // Text to be encrypted.
      text: 'hello',
      // Base64-encoded public key used for encryption.
      key:
     'MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCx414QSP3RsYWYzf9mkBMiBAXo\n' +
     '6S7Lpva1fKlcuVxjoFC1iMnzD4mC0uiL4k5MNi43J64c7dbqi3qAJjdAtuwQ6NZJ\n' +
     '+Enz0RzmVFh/4yk6lmqRzuEFQqhQqSZzaLq6sq2N2G0Sv2Xl3sLvqAfe2HNm2oBw\n' +
     'jBpApTJ3TeneOo6Z5QIDAQAB',
      success: function(data) {
        console.log(`handling success:${data.text}`);
      },
      fail: function(data, code) {
        console.log(`### cipher.rsa encrypt fail ### ${code}:${data}`);
      },
      complete: function() {
        console.log(`operation complete!`);
      }
      });
      cipher.rsa({
        // Decrypt data.
        action: 'decrypt',
        // Text to be decrypted, which is binary text encoded in Base64. The decrypted text is "hello".
        text:
       'EPeCFPib6ayKbA0M6oSywARvFZ8dFYfjQv3nY8ikZGtS9UHq2sLPvAfpeIzggSiCxqbWeCftP1XQ\n' +
       'Sa+jEpzFlT1qoSTunBbrYzugPTajIJDTg6R1IRsF/J+mmakn0POVPvi4jCo9wqavB324Bx0Wipnc\n' +
       'EU5WO0oBHo5l4x6dTpU=',
         // Base64-encoded private key used for decryption.
         key:
        'MIICXgIBAAKBgQCx414QSP3RsYWYzf9mkBMiBAXo6S7Lpva1fKlcuVxjoFC1iMnz\n' +
        'D4mC0uiL4k5MNi43J64c7dbqi3qAJjdAtuwQ6NZJ+Enz0RzmVFh/4yk6lmqRzuEF\n' +
        'QqhQqSZzaLq6sq2N2G0Sv2Xl3sLvqAfe2HNm2oBwjBpApTJ3TeneOo6Z5QIDAQAB\n' +
        'AoGBAKPNtoRQcklxqo+2wQP0j2m3Qqnib1DggjVEgb/8f/LNYQSI3U2QdROemryU\n' +
        'u3y6N3xacZ359PktTrRKfH5+8ohmHGhIuPAnefp6bLvAFUcl4t1xm74Cow62Kyw3\n' +
        'aSbmuTG98dxPA1sXD0jiprdtsq2wQ9CoKNyY7/d/pKoqxNuBAkEA4GytZ60NCTj9\n' +
        'w24jACFeko5YqCFY/TTLoc4SQvWtFMnimRPclLZhtUIK0P8dib71UFedx+AxklgL\n' +
        'A5gjcfo+2QJBAMrqiwyCh3OQ5DhyRPDwt87x1/jg5fy4hhete2ufSf2FoQCVqO+w\n' +
        'PKoljdXmJeS6rGgzGibstuHLrP3tcIho4+0CQD3ZFWzF/xq0jxKlrpWhnJuNCRfE\n' +
        'oO6e9yNvVA8J/5oEDSOcmqSNIp4+RhbUx8InUxnCG6Ryv5aSFu71pYcKrPkCQQCL\n' +
        'RUGcm3ZGTnslduB0knNF+V2ndwzDUQ7P74UXT+PjurTPhujFYiuxCEd6ORVnEOzG\n' +
        'M9TORIgdH8MjIbWsGnndAkEAw9yURDaorE8IYPLF2IEn09g1uzvWPs3phDb6smVx\n' +
        '8GfqIdUNf+aCG5TZK/kXBF1sqcsi7jXMAf4jBlejVbSVZg==',
         success: function(data) {
           console.log(`handling success:${data.text}`);
         },
         fail: function(data, code) {
           console.log(`### cipher.rsa encrypt fail ### ${code}:${data}`);
         },
         complete: function() {
           console.log(`operation complete!`);
         }
       });
   }
}
```


## cipher.aes

aes(options: CipherAesOptions): void

Encrypts or decrypts data using AES.

**System capability**: SystemCapability.Security.Cipher

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [CipherAesOptions](#cipheraesoptions) | Yes| Parameters set for AES encryption or decryption.|

**Example**

```js
export default {
  aes() {
    cipher.aes({
      // Encrypt data.
      action: 'encrypt',
      // Text to be encrypted.
      text: 'hello',
      // Base64-encoded key.
      key: 'NDM5Qjk2UjAzMEE0NzVCRjlFMkQwQkVGOFc1NkM1QkQ=',
      transformation: 'AES/CBC/PKCS5Padding',
      ivOffset: '0',
      ivLen: '16',
      success: function(data) {
        console.log(`handling success:${data.text}`);
        },
      fail: function(data, code) {
        console.log(`### cipher.rsa encrypt fail ### ${code}:${data}`);
        },
      complete: function() {
        console.log(`operation complete!`);
      }
    });
    cipher.aes({
      // Decrypt data.
      action: 'decrypt',
      // Text to be decrypted, which is binary text encoded in Base64.
      text: '1o0kf2HXwLxHkSh5W5NhzA==',
       // Base64-encoded key.
       key: 'NDM5Qjk2UjAzMEE0NzVCRjlFMkQwQkVGOFc1NkM1QkQ=',
       transformation: 'AES/CBC/PKCS5Padding',
       ivOffset: '0',
       ivLen: '16',
       success: function(data) {
         console.log(`handling success:${data.text}`);
        },
       fail: function(data, code) {
         console.log(`### cipher.aes encrypt fail ### ${code}:${data}`);
       },
       complete: function() {
         console.log(`operation complete!`);
        }
     });
  }
}

```
