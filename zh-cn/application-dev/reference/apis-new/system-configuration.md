# @system.configuration    
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import Configuration from '@system.configuration';  
    
```  
    
## LocaleResponse    
表示应用当前Locale的属性。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| language | string | false | true | 语言。例如：zh。 |  
| countryOrRegion | string | false | true | 国家或地区。例如：CN。 |  
| dir | "ltr" \| "rtl" | false | true | 文字布局方向。取值范围：<br/>-ltr：从左到右；<br/>-rtl：从右到左。 |  
    
## Configuration  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
### getLocale    
获取应用当前的语言和地区。默认与系统的语言和地区同步。  
 **调用形式：**     
- static getLocale(): LocaleResponse  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| LocaleResponse | 应用当前Locale相关信息。 |  
    
 **示例代码：**   
```js    
export default {      
    getLocale() {          
      const localeInfo = configuration.getLocale();          
      console.info(localeInfo.language);      
    }  
  }  
    
```    
  
