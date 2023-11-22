# wantAgentInfo    
定义触发WantAgent所需要的信息，可以作为[getWantAgent](js-apis-app-ability-wantAgent.md#wantagentgetwantagent)的入参创建指定的WantAgent对象。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## WantAgentInfo  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| wants | Array<Want> | false | true | 将被执行的动作列表。wants数组为预留能力，当前只支持一个want。传入多个时只取wants数组的第一个成员。 |  
| operationType | wantAgent.OperationType | false | true | 动作类型。 |  
| requestCode | number | false | true | 使用者定义的一个私有值。 |  
| wantAgentFlags | Array<wantAgent.WantAgentFlags> | false | false | 动作执行属性。 |  
| extraInfo | object | false | false | 额外数据。 |  
