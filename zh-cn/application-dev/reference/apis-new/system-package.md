# @system.package    
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import package from '@system.package';  
    
```  
    
## CheckPackageHasInstalledResponse<sup>(deprecated)</sup>    
指示应用包是否已安装。    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| result<sup>(deprecated)</sup> | boolean | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>指示应用是否已安装。 |  
    
## CheckPackageHasInstalledOptions<sup>(deprecated)</sup>    
指示应用包是否已安装。    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 9 开始废弃。<br>应用Bundle名称。 |  
| success<sup>(deprecated)</sup> | (data: CheckPackageHasInstalledResponse) => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: any, code: number) => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用失败的回调函数。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 9 开始废弃。<br>接口调用结束的回调函数。 |  
    
## Package<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### hasInstalled<sup>(deprecated)</sup>    
查询指定应用是否存在，或者原生应用是否安装。  
 **调用形式：**     
- static hasInstalled(options: CheckPackageHasInstalledOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | CheckPackageHasInstalledOptions | true | 选项参数。 |  
    
 **示例代码：**   
```js    
export default {  
  hasInstalled() {  
    package.hasInstalled({  
      bundleName: 'com.example.bundlename',  
      success: function(data) {  
        console.log('package has installed: ' + data);  
      },  
      fail: function(data, code) {  
        console.log('query package fail, code: ' + code + ', data: ' + data);  
      },  
    });  
  },  
}  
    
```    
  
