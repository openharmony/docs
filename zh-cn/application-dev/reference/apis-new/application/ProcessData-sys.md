# ProcessData    
进程数据的对象定义。使用接口[registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8)注册生命周期变化监听后，当应用或组件的生命周期变化时，系统通过[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onProcessCreated等方法回调给开发者。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ProcessData    
。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | true | 应用包名。 |  
| pid | number | false | true | <span style="letter-spacing: 0px;">进程ID</span>。 |  
| uid | number | false | true | 应用的uid。 |  
| state<sup>(9+)</sup> | number | false | true | 应用的状态，取值及对应的状态为：<br>0 - 刚创建，<br>1 - 准备就绪，<br>2 - 前台，<br>4 - 后台，<br>5 - 已终止。 |  
| isContinuousTask<sup>(9+)</sup> | boolean | false | true | 是否为长时任务，true表示是，false表示不是 |  
| isKeepAlive<sup>(9+)</sup> | boolean | false | true | 是否为常驻进程，true表示是，false表示不是。 |  
