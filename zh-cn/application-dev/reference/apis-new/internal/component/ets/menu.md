# menu    
以垂直列表形式显示的菜单。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Menu()    
起始版本： 9    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| fontSize<sup>(deprecated)</sup> |  Length |  |  
| font<sup>10+</sup> |  Font |  |  
| fontColor<sup>10+</sup> |  ResourceColor |  |  
| radius<sup>10+</sup> |  Dimension \| BorderRadiuses |  |  
    
 **示例代码：**   
```ts    
@Entry  
@Component  
struct Index {  
  @State select: boolean = true  
  private iconStr: ResourceStr = $r("app.media.view_list_filled")  
  private iconStr2: ResourceStr = $r("app.media.view_list_filled")  
  
  @Builder  
  SubMenu() {  
    Menu() {  
      MenuItem({ content: "复制", labelInfo: "Ctrl+C" })  
      MenuItem({ content: "粘贴", labelInfo: "Ctrl+V" })  
    }  
  }  
  
  @Builder  
  MyMenu(){  
    Menu() {  
      MenuItem({ startIcon: $r("app.media.icon"), content: "菜单选项" })  
      MenuItem({ startIcon: $r("app.media.icon"), content: "菜单选项" })  
        .enabled(false)  
      MenuItem({  
        startIcon: this.iconStr,  
        content: "菜单选项",  
        endIcon: $r("app.media.arrow_right_filled"),  
        builder: ():void=>this.SubMenu()  
      })  
      MenuItemGroup({ header: '小标题' }) {  
        MenuItem({ content: "菜单选项" })  
          .selectIcon(true)  
          .selected(this.select)  
          .onChange((selected) => {  
            console.info("menuItem select" + selected);  
            this.iconStr2 = $r("app.media.icon");  
          })  
        MenuItem({  
          startIcon: $r("app.media.view_list_filled"),  
          content: "菜单选项",  
          endIcon: $r("app.media.arrow_right_filled"),  
          builder: ():void=>this.SubMenu()  
        })  
      }  
      MenuItem({  
        startIcon: this.iconStr2,  
        content: "菜单选项",  
        endIcon: $r("app.media.arrow_right_filled")  
      })  
    }  
  }  
  
  build() {  
    Row() {  
      Column() {  
        Text('click to show menu')  
          .fontSize(50)  
          .fontWeight(FontWeight.Bold)  
      }  
      .bindMenu(this.MyMenu)  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
    
```    
  
![menu1](figures/menu1.png)  
