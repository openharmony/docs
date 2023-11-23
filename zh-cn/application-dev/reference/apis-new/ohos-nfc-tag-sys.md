# @ohos.nfc.tag    
本模块主要用于操作及管理NFC Tag。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import tag from '@ohos.nfc.tag'    
```  
    
## TagInfo    
NFC服务在读取到标签时给出的对象，通过改对象属性，应用知道该标签支持哪些技术类型，并使用匹配的技术类型来调用相关接口。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
### 属性    
 **需要权限：** ohos.permission.NFC_TAG    
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| extrasData<sup>(9+)</sup> | PacMap[] | false | true | 标签所支持技术的扩展属性值。<br>**系统接口：** 此接口为系统接口。<br/> |  
| tagRfDiscId<sup>(9+)</sup> | number | false | true | 标签发现时分配的ID值。<br>**系统接口：** 此接口为系统接口。  |  
| remoteTagService<sup>(9+)</sup> | rpc.RemoteObject | false | true |  NFC服务进程的远端对象，用于客户端和服务之间的接口通信。<br>**系统接口：** 此接口为系统接口。 |  
