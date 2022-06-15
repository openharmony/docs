# Encryption Algorithm

> **NOTE**<br>
>
> The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import cipher from '@system.cipher'
```


## cipher.rsa

rsa(Object): void

Encrypts or decrypts data using RSA.

**System capability**: SystemCapability.Security.Cipher

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | string | Yes| Action to perform. The options are as follows:<br>-&nbsp;encrypt<br>-&nbsp;decrypt|
| text | string | Yes| Text to be encrypted or decrypted.<br> The text to be encrypted must be common text that meets the following requirement:<br> Maximum text length = Key length/8 - 66<br>For example, if the key is of 1024 bytes, the text to be encrypted cannot exceed 62 bytes (1024/8 -66 = 62).<br> The text to be decrypted must be binary text encoded in Base64. The default format is used for Base64 encoding.|
| key | string | Yes| RSA key. The key is used as a public key in encryption and a private key in decryption.|
| transformation | string | No| RSA padding. The default value is **RSA/None/OAEPWithSHA256AndMGF1Padding**.|
| success | Function | No| Called when data is encrypted or decrypted successful.|
| fail | Function | No| Called when data fails to be encrypted or decrypted.|
| complete | Function | No| Called when the execution is complete.|

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
        'MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDc7GR2MrfAoefES+wrs1ns2afT\n' +            
        'eJXSfIkEHfPXG9fVFjaws1ho4KcZfsxlA0+SXvc83f2SVGCuzULmM2lxxRCtcUN/\n' +            
        'h7SoaYEeluhqFimL2AEjfSwINHCLqObJkcjCfoZpE1JCehPiDOJsyT50Auc08h/4\n' +            
        'jHQfanyC1nc62LqUCQIDAQAB',            
        success: function(data) {                
          console.log('handling success: ${data.text}');            
        },            
        fail: function(data, code) {               
          console.log(`### cipher.rsa encrypt fail ### ${code}: ${data}`);           
        }       
      });        
      cipher.rsa({            
        // Decrypt data.           
        action: 'decrypt',            
        // Text to be decrypted, which is binary text encoded in Base64. The decrypted text is "hello".           
        text:            
          'CUg3tTxTIdpCfreIxIBdws3uhd5qXLwcrVl3XDnQzZFVHyjVVCDHS16rjopaZ4C5xU2Tc8mSDzt7\n' +            
          'gp9vBfSwi7bMtSUvXG18DlncsKJFDkJpS5t0PkpS9YrJXrY80Gpe+ME6+6dN9bjgqMljbitDdBRf\n' +            
          'S/ZWNI4Q8Q0suNjNkGU=',            
           // Base64-encoded private key used for decryption.           
         key:            
           'MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBANzsZHYyt8Ch58RL\n' +            
           '7CuzWezZp9N4ldJ8iQQd89cb19UWNrCzWGjgpxl+zGUDT5Je9zzd/ZJUYK7NQuYz\n' +            
           'aXHFEK1xQ3+HtKhpgR6W6GoWKYvYASN9LAg0cIuo5smRyMJ+hmkTUkJ6E+IM4mzJ\n' +            
           'PnQC5zTyH/iMdB9qfILWdzrYupQJAgMBAAECgYEAkibhH0DWR13U0gvYJeD08Lfd\n' +            
           'Sw1PMHyquEqIcho9Yv7bF3LOXjOg2EEGPx09mvuwXFgP1Kp1e67XPytr6pQQPzK7\n' +            
           'XAPcLPx80R/ZjZs8vNFndDOd1HgD3vSVmYQarNzmKi72tOUWMPevsaFXPHo6Xx3X\n' +            
           '8x0wYb7XuBsQguRctTECQQD7GWX3JUiyo562iVrpTDPOXsrUxmzCrgz2OZildxMd\n' +            
           'Pp/PkyDrx7mEXTpk4K/XnQJ3GpJNi2iDSxDuPSAeJ/aPAkEA4Tw4+1Z43S/xH3C3\n' +            
           'nfulYBNyB4si6KEUuC0krcC1pDJ21Gd12efKo5VF8SaJI1ZUQOzguV+dqNsB/JUY\n' +            
           'OFfX5wJAB1dKv9r7MR3Peg6x9bggm5vx2h6i914XSuuMJupASM6X5X2rrLj+F3yS\n' +            
           'RHi9K1SPyeOg+1tkBtKfABgRZFBOyQJAbuTivUSe73AqTKuHjB4ZF0ubqgEkJ9sf\n' +            
           'Q2rekzm9dOFvxjZGPQo1qALX09qATMi1ZN376ukby8ZAnSafLSZ64wJBAM2V37go\n' +            
           'Sj44HF76ksRow8gecuQm48NCTGAGTicXg8riKog2GC9y8pMNHAezoR9wXJF7kk+k\n' +            
           'lz5cHyoMZ9mcd30=',            
           success: function(data) {                
             console.log('handling success: ${data.text}');            
           },            
           fail: function(data, code) {                
             console.log(`### cipher.rsa decrypt fail ### ${code}: ${data}`);            
           },        
       });    
   }
}
```


## cipher.aes

aes(Object): void

Encrypts or decrypts data using AES.

**System capability**: SystemCapability.Security.Cipher

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | string | Yes| Action to perform. The options are as follows:<br>-&nbsp;encrypt<br>-&nbsp;decrypt|
| text | string | Yes| Text to be encrypted or decrypted.<br> The text to be encrypted must be common text. The text to be decrypted must be binary text encoded in Base64. The default format is used for Base64 encoding.|
| key | string | Yes| Key used for encryption or decryption. It is a string encoded in Base64.|
| transformation | string | No| Encryption mode and padding of the AES algorithm. The default value is **AES/CBC/PKCS5Padding**.|
| iv | string | No| Initialization vector (IV) for AES-based encryption and decryption. The value is a string encoded in Base64. The default value is the key value.|
| ivOffset | string | No| Offset of the IV for AES-based encryption and decryption. The default value is **0**.|
| ivLen | string | No| Length of the IV for AES-based encryption and decryption, in bytes. The default value is **16**.|
| success | Function | No| Called when data is encrypted or decrypted successful.|
| fail | Function | No| Called when data fails to be encrypted or decrypted.|
| complete | Function | No| Called when the execution is complete.|

**Example**

```js
export default {    
  aes() {        
    cipher.aes({            
      // Encrypt data.           
      action: 'encrypt',            
      // Text to be encrypted.           
      text: 'hello',            
      // Base64-encoded key used for encryption.           
      key: 'NDM5Qjk2UjAzMEE0NzVCRjlFMkQwQkVGOFc1NkM1QkQ=',            
      transformation: 'AES/CBC/PKCS5Padding',            
      ivOffset: 0,            
      ivLen: 16,            
      success: (data) => {                
        console.log('handling success: ${data.text}');            
      },            
      fail: (data, code) => {                
        console.log(`### cipher.aes encrypt fail ### ${code}: ${data}`);            
      }        
    });        
    cipher.aes({            
      // Decrypt data.           
      action: 'decrypt',            
      // Text to be decrypted, which is binary text encoded in Base64.           
      text: 'CUg3tTxTIdpCfreIxIBdws3uhd5qXLwcrVl3XDnQzZFVHyjVVCDHS16rjopaZ4C5xU2Tc8mSDzt7\n' +            
      'gp9vBfSwi7bMtSUvXG18DlncsKJFDkJpS5t0PkpS9YrJXrY80Gpe+ME6+6dN9bjgqMljbitDdBRf\n' +            
      'S/ZWNI4Q8Q0suNjNkGU=',            
       // Base64-encoded key used for decryption.           
       key: 'NDM5Qjk2UjAzMEE0NzVCRjlFMkQwQkVGOFc1NkM1QkQ=',            
       transformation: 'AES/CBC/PKCS5Padding',            
       ivOffset: 0,            
       ivLen: 16,            
       success: (data) => {                
         this.dealTxt = data.text;            
       },            
       fail: (data, code) => {               
         prompt.showToast({                    
           message: (`### cipher.aes decrypt fail ### code = ${code}: ${data}`)                
         })            
       },        
    });    
  }
}

```
