# Encryption Algorithm

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.


## Modules to Import


```
import cipher from '@system.cipher'
```


## cipher.rsa

rsa(Object): void

Encrypts or decrypts data using RSA.

**System capability**: SystemCapability.Security.Cipher

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| action | string | Yes | Action&nbsp;type.&nbsp;The&nbsp;options&nbsp;are&nbsp;as&nbsp;follows:<br/>1.&nbsp;**encrypt**:&nbsp;Encrypts&nbsp;data.<br/>2.&nbsp;**decrypt**:&nbsp;Decrypts&nbsp;data. |
| text | string | Yes | Text&nbsp;content&nbsp;to&nbsp;be&nbsp;encrypted&nbsp;or&nbsp;decrypted.&nbsp;The&nbsp;text&nbsp;to&nbsp;be&nbsp;encrypted&nbsp;must&nbsp;be&nbsp;a&nbsp;common&nbsp;text&nbsp;and&nbsp;cannot&nbsp;exceed&nbsp;the&nbsp;length&nbsp;calculated&nbsp;based&nbsp;on&nbsp;the&nbsp;formula&nbsp;(keySize/8&nbsp;-&nbsp;66).&nbsp;**keySize**&nbsp;indicates&nbsp;the&nbsp;key&nbsp;length.&nbsp;For&nbsp;example,&nbsp;if&nbsp;the&nbsp;key&nbsp;length&nbsp;is&nbsp;1024&nbsp;bytes,&nbsp;the&nbsp;text&nbsp;cannot&nbsp;exceed&nbsp;62&nbsp;bytes&nbsp;(1024/8&nbsp;-&nbsp;66&nbsp;=&nbsp;62).&nbsp;The&nbsp;text&nbsp;content&nbsp;to&nbsp;be&nbsp;decrypted&nbsp;must&nbsp;be&nbsp;a&nbsp;binary&nbsp;value&nbsp;encoded&nbsp;using&nbsp;Base64.&nbsp;The&nbsp;default&nbsp;format&nbsp;is&nbsp;used&nbsp;for&nbsp;Base64&nbsp;encoding. |
| key | string | Yes | Keys&nbsp;encrypted&nbsp;using&nbsp;RSA.&nbsp;During&nbsp;encryption,&nbsp;this&nbsp;parameter&nbsp;is&nbsp;a&nbsp;public&nbsp;key.&nbsp;During&nbsp;decryption,&nbsp;it&nbsp;is&nbsp;a&nbsp;private&nbsp;key. |
| transformation | string | No | RSA&nbsp;algorithm&nbsp;padding.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**RSA/None/OAEPWithSHA256AndMGF1Padding**. |
| success | Function | No | Called&nbsp;when&nbsp;data&nbsp;is&nbsp;encrypted&nbsp;or&nbsp;decrypted&nbsp;successfully. |
| fail | Function | No | Called&nbsp;when&nbsp;data&nbsp;fails&nbsp;to&nbsp;be&nbsp;encrypted&nbsp;or&nbsp;decrypted. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

**Example**

```
export default {    
  rsa() {        
    cipher.rsa({            
  // Encrypt data.
      action: 'encrypt',            
  // Text content to be encrypted
      text: 'hello',            
  // Base64-encoded public key used for encryption
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
  // The text to be decrypted is a Base64-encoded binary value, and the decrypted text is "hello".
        text:            
          'CUg3tTxTIdpCfreIxIBdws3uhd5qXLwcrVl3XDnQzZFVHyjVVCDHS16rjopaZ4C5xU2Tc8mSDzt7\n' +            
          'gp9vBfSwi7bMtSUvXG18DlncsKJFDkJpS5t0PkpS9YrJXrY80Gpe+ME6+6dN9bjgqMljbitDdBRf\n' +            
          'S/ZWNI4Q8Q0suNjNkGU=',            
  // Base64-encoded public key used for encryption
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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| action | string | Yes | Action&nbsp;type.&nbsp;The&nbsp;options&nbsp;are&nbsp;as&nbsp;follows:<br/>1.&nbsp;**encrypt**:&nbsp;Encrypts&nbsp;data.<br/>2.&nbsp;**decrypt**:&nbsp;Decrypts&nbsp;data. |
| text | string | Yes | Text&nbsp;content&nbsp;to&nbsp;be&nbsp;encrypted&nbsp;or&nbsp;decrypted.&nbsp;The&nbsp;text&nbsp;to&nbsp;be&nbsp;encrypted&nbsp;must&nbsp;be&nbsp;a&nbsp;common&nbsp;text.&nbsp;The&nbsp;text&nbsp;content&nbsp;to&nbsp;be&nbsp;decrypted&nbsp;must&nbsp;be&nbsp;a&nbsp;binary&nbsp;value&nbsp;encoded&nbsp;using&nbsp;Base64.&nbsp;The&nbsp;default&nbsp;format&nbsp;is&nbsp;used&nbsp;for&nbsp;Base64&nbsp;encoding. |
| key | string | Yes | Key&nbsp;used&nbsp;for&nbsp;encryption&nbsp;or&nbsp;decryption,&nbsp;which&nbsp;is&nbsp;a&nbsp;character&nbsp;string&nbsp;encrypted&nbsp;using&nbsp;Base64. |
| transformation | string | No | Encryption&nbsp;mode&nbsp;and&nbsp;padding&nbsp;of&nbsp;the&nbsp;AES&nbsp;algorithm.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**AES/CBC/PKCS5Padding**. |
| iv | string | No | Initial&nbsp;vector&nbsp;for&nbsp;AES-based&nbsp;encryption&nbsp;and&nbsp;decryption.&nbsp;The&nbsp;value&nbsp;is&nbsp;a&nbsp;character&nbsp;string&nbsp;encoded&nbsp;using&nbsp;Base64.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;the&nbsp;key&nbsp;value. |
| ivOffset | string | No | Offset&nbsp;of&nbsp;the&nbsp;initial&nbsp;vector&nbsp;for&nbsp;AES-based&nbsp;encryption&nbsp;and&nbsp;decryption.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**0**. |
| ivLen | string | No | Length&nbsp;of&nbsp;the&nbsp;initial&nbsp;vector&nbsp;for&nbsp;AES-based&nbsp;encryption&nbsp;and&nbsp;decryption.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**16**. |
| success | Function | No | Called&nbsp;when&nbsp;data&nbsp;is&nbsp;encrypted&nbsp;or&nbsp;decrypted&nbsp;successfully. |
| fail | Function | No | Called&nbsp;when&nbsp;data&nbsp;fails&nbsp;to&nbsp;be&nbsp;encrypted&nbsp;or&nbsp;decrypted. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

**Example**

```
export default {    
  aes() {        
    cipher.aes({            
  // Encrypt data.
      action: 'encrypt',            
  // Text content to be encrypted
      text: 'hello',            
  // Base64-encoded key used for encryption
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
  // Text to be decrypted, which is a Base64-encoded binary value
      text: 'CUg3tTxTIdpCfreIxIBdws3uhd5qXLwcrVl3XDnQzZFVHyjVVCDHS16rjopaZ4C5xU2Tc8mSDzt7\n' +            
      'gp9vBfSwi7bMtSUvXG18DlncsKJFDkJpS5t0PkpS9YrJXrY80Gpe+ME6+6dN9bjgqMljbitDdBRf\n' +            
      'S/ZWNI4Q8Q0suNjNkGU=',            
  // Base64-encoded key used for decryption
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