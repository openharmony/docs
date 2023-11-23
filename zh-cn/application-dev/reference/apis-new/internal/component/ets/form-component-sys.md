# form_component    
提供卡片组件，实现卡片的显示功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## FormDimension    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Dimension_1_2 | 0 | 1*2 卡片 |  
| Dimension_2_2 | 1 | 2*2 卡片。 |  
| Dimension_2_4 | 2 | 2*4 卡片 |  
| Dimension_4_4 | 3 | 4*4 卡片 |  
| Dimension_2_1<sup>(9+)</sup> | 4 | 2*1 卡片 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- FormComponent(value: {     id: number;     name: string;     bundle: string;     ability: string;     module: string;     dimension?: FormDimension;     temporary?: boolean;     want?: import('../api/@ohos.app.ability.Want').default;   })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | number | true | 卡片标识（新建卡片填0）。<br/><strong>说明：</strong><br/>不同使用方不可使用相同id。<br/>同一使用方使用相同id时，显示后添加的卡片。<br/> |  
| name | string | true | 卡片名称。<br/> |  
| bundle | string | true | 目标卡片包名。<br/> |  
| ability | string | true | 目标卡片Ability名称。<br/> |  
| module | string | true | 卡片模块名称。<br/> |  
| dimension | FormDimension | false | 卡片尺寸，支持2 * 2，4 * 4，4 * 2类型卡片。<br/>默认值：Dimension_2_2。<br/> |  
| temporary | boolean | false | 卡片是否为临时卡片。<br/> |  
| want | import('../api/@ohos.app.ability.Want').default | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
**系统接口：** 此接口为系统接口    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| size |  { width: number; height: number } |  |  
| moduleName |  string |  |  
| dimension |  FormDimension |  |  
| allowUpdate |  boolean |  |  
| visibility |  Visibility |  |  
    
### onAcquired<sup>(deprecated)</sup>    
onAcquired(callback: (info: { id: number }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onError<sup>(deprecated)</sup>    
onError(callback: (info: { errcode: number; msg: string }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onRouter<sup>(deprecated)</sup>    
onRouter(callback: (info: any) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onUninstall<sup>(deprecated)</sup>    
onUninstall(callback: (info: { id: number }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onLoad<sup>(deprecated)</sup>    
onLoad(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
//card.ets  
@Entry  
@Component  
struct CardExample {  
   @State formId:number = 0;  
  build() {  
    Column() {  
      Text('this is a card')  
        .fontSize(50)  
        .fontWeight(FontWeight.Bold)  
      FormComponent({  
        id:this.formId,  
        name:"Form1",  
        bundle:"com.example.cardexample",  
        ability:"FormAbility",  
        module:"entry",  
        dimension:FormDimension.Dimension_2_2,  
        temporary:false  
      })  
        .allowUpdate(true)  
        .size({width:360,height:360})  
        .visibility(Visibility.Visible)  
        .onAcquired((form)=>{  
          console.log(`form info : ${JSON.stringify(form)}`);  
          this.formId = form.id;  
        })  
        .onError((err)=>{  
          console.log(`fail to add form, err: ${JSON.stringify(err)}`);  
        })  
  
    }  
    .width('100%')  
    .height('100%')  
  }  
}  
    
```    
  
![Form](figures/form.png)  
