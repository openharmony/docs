# menu_item    
用来展示菜单Menu中具体的item菜单项。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## MenuItemOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| startIcon | ResourceStr | false | false |  |  
| content | ResourceStr | false | false |  |  
| endIcon | ResourceStr | false | false |  |  
| labelInfo | ResourceStr | false | false |  |  
| builder | CustomBuilder | false | false |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- MenuItem(value?: MenuItemOptions | CustomBuilder)    
起始版本： 9    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| selected |  boolean |  |  
| selectIcon |  boolean \| ResourceStr |  |  
| contentFont<sup>10+</sup> |  Font |  |  
| contentFontColor<sup>10+</sup> |  ResourceColor |  |  
| labelFont<sup>10+</sup> |  Font |  |  
| labelFontColor<sup>10+</sup> |  ResourceColor |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (selected: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full  
