# AppStateData    
定义应用状态信息，可以通过[getForegroundApplications](js-apis-app-ability-appManager.md#appmanagergetforegroundapplications)获取当前应用的相关信息。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## AppStateData    
定义应用状态信息，可以通过[getForegroundApplications](js-apis-app-ability-appManager.md#appmanagergetforegroundapplications)获取当前应用的相关信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | true | Bundle名称。 |  
| uid | number | false | true | 应用程序的uid。 |  
| state | number | false | true | 应用状态。<br>0：初始化状态，应用正在初始化<br>1：就绪状态，应用已初始化完毕<br>2：前台状态，应用位于前台<br>3：获焦状态。（预留状态，当前暂不支持）<br>4：后台状态，应用位于后台<br>5：退出状态，应用已退出 |  
