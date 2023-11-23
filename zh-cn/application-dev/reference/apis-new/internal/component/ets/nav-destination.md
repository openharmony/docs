# nav_destination    
作为NavRouter组件的子组件，用于显示导航内容区。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## NavDestinationCommonTitle  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| main | string | false | true |  |  
| sub | string | false | true |  |  
    
## NavDestinationCustomTitle  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| builder | CustomBuilder | false | true |  |  
| height | TitleHeight \| Length | false | true |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- NavDestination()    
起始版本： 9    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| title |  string \| CustomBuilder \| NavDestinationCommonTitle \| NavDestinationCustomTitle |  |  
| hideTitleBar |  boolean |  |  
    
### onShown<sup>(deprecated)</sup>    
onShown(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onHidden<sup>(deprecated)</sup>    
onHidden(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onBackPressed<sup>(deprecated)</sup>    
onBackPressed(callback: () => boolean)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full  
