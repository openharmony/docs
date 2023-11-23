# ability_component    
独立显示Ability的容器。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
  
<p>独立显示Ability的容器。<br/></p>  
    
 **调用形式**     
    
- AbilityComponent(value: { want: import('../api/@ohos.app.ability.Want').default })    
起始版本： 9    
废弃版本： 10    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want<sup>(deprecated)</sup> | import('../api/nt').default | true | 默认加载的Ability描述。 |  
    
### onConnect    
onConnect(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | () => void | true |  |  
    
### onDisconnect    
onDisconnect(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | () => void | true |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct MyComponent {  
  
  build() {  
      Column() {  
          AbilityComponent({  
              want: {  
                  bundleName: '',  
                  abilityName: ''  
              },  
          })  
          .onConnect(() => {  
              console.log('AbilityComponent connect')  
          })  
          .onDisconnect(() => {  
              console.log('AbilityComponent disconnect')  
          })  
      }  
  }  
}  
    
```    
  
