# 加密算法

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import cipher from '@system.cipher'
```


## cipher.rsa

rsa(Object): void

RSA 算法加解密。

**系统能力：** SystemCapability.Security.Cipher

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | string | 是 | 加密类型，可选项有：<br/>1.&nbsp;encrypt&nbsp;加密<br/>2.&nbsp;decrypt&nbsp;解密 |
| text | string | 是 | 待加密或解密的文本内容。待加密的文本内容应该是一段普通文本，长度不能超过&nbsp;keySize&nbsp;/&nbsp;8&nbsp;-&nbsp;66，其中&nbsp;keySize&nbsp;是密钥的长度（例如密钥长度为&nbsp;1024&nbsp;时，text&nbsp;不能超过&nbsp;62&nbsp;个字节）。待解密的文本内容应该是经过&nbsp;base64&nbsp;编码的一段二进制值。base64&nbsp;编码使用默认风格。 |
| key | string | 是 | 加密的密钥，RSA的密钥。加密时key为公钥，解密时key为私钥 |
| transformation | string | 否 | RSA算法的填充项，默认为RSA/None/OAEPWithSHA256AndMGF1Padding |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

**示例：**

```
export default {    
  rsa() {        
    cipher.rsa({            
      //加密            
      action: 'encrypt',            
      //待加密的文本内容            
      text: 'hello',            
      //base64编码后的加密公钥            
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
        //解密：            
        action: 'decrypt',            
        //待解密的内容，是base64编码后的一段二进制值，解密后是文本内容“hello”            
        text:            
          'CUg3tTxTIdpCfreIxIBdws3uhd5qXLwcrVl3XDnQzZFVHyjVVCDHS16rjopaZ4C5xU2Tc8mSDzt7\n' +            
          'gp9vBfSwi7bMtSUvXG18DlncsKJFDkJpS5t0PkpS9YrJXrY80Gpe+ME6+6dN9bjgqMljbitDdBRf\n' +            
          'S/ZWNI4Q8Q0suNjNkGU=',            
         //base64编码后的解密私钥            
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

AES 算法加解密。

**系统能力：** SystemCapability.Security.Cipher

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | string | 是 | 加密类型，可选项有：<br/>1.&nbsp;encrypt&nbsp;加密<br/>2.&nbsp;decrypt&nbsp;解密 |
| text | string | 是 | 待加密或解密的文本内容。待加密的文本内容应该是一段普通文本。待解密的文本内容应该是经过&nbsp;base64&nbsp;编码的一段二进制值。base64&nbsp;编码使用默认风格 |
| key | string | 是 | 加密或解密使用到的密钥，经过&nbsp;base64&nbsp;编码后生成的字符串 |
| transformation | string | 否 | AES算法的加密模式和填充项，默认AES/CBC/PKCS5Padding |
| iv | string | 否 | AES加解密的初始向量，经过base64编码后的字符串，默认值为key值 |
| ivOffset | string | 否 | AES加解密的初始向量偏移，默认值0 |
| ivLen | string | 否 | AES加解密的初始向量字节长度，默认值16 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

**示例：**

```
export default {    
  aes() {        
    cipher.aes({            
      //加密            
      action: 'encrypt',            
      //待加密的文本内容            
      text: 'hello',            
      //base64编码后的密钥            
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
      //解密：            
      action: 'decrypt',            
      //待解密的内容，是base64编码后的一段二进制值            
      text: 'CUg3tTxTIdpCfreIxIBdws3uhd5qXLwcrVl3XDnQzZFVHyjVVCDHS16rjopaZ4C5xU2Tc8mSDzt7\n' +            
      'gp9vBfSwi7bMtSUvXG18DlncsKJFDkJpS5t0PkpS9YrJXrY80Gpe+ME6+6dN9bjgqMljbitDdBRf\n' +            
      'S/ZWNI4Q8Q0suNjNkGU=',            
       //base64编码后的密钥            
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