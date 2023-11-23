# navigation    
Navigation组件一般作为Page页面的根容器，通过属性设置来展示页面的标题栏、工具栏、导航栏等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## NavigationCommonTitle<sup>(9+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| main<sup>(9+)</sup> | string | false | true | 设置主标题。<br/> |  
| sub<sup>(9+)</sup> | string | false | true | 设置副标题。<br/> |  
    
## NavigationCustomTitle<sup>(9+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| builder<sup>(9+)</sup> | CustomBuilder | false | true | 设置标题栏内容。<br/> |  
| height<sup>(9+)</sup> | TitleHeight \| Length | false | true | 设置标题栏高度。<br/> |  
    
## NavigationMode<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Stack | 0 | 导航栏与内容区独立显示，相当于两个页面。 |  
| Split | 1 | 导航栏与内容区分两栏显示。<br/>以下navBarWidthRange的值用[minNavBarWidth,maxNavBarWidth]表示<br/>1.当navBarWidth属性的值，在navBarWidthRange属性的值范围以外时，navBarWidth按如下规则显示：<br/>navBarWidth < minNavBarWidth时，navBarWidth修正为minNavBarWidth;<br/>navBarWidth > maxNavBarWidth，且组件宽度 - minContentWidth - 分割线宽度(1vp)大于maxNavBarWidth时，navBarWidth修正为maxNavBarWidth;<br/>navBarWidth > maxNavBarWidth，且组件宽度 - minContentWidth - 分割线宽度(1vp)小于minNavBarWidth时，navBarWidth修正为minNavBarWidth;<br/>navBarWidth > maxNavBarWidth，且组件宽度 - minContentWidth - 分割线宽度(1vp)在navBarWidthRange范围内，navBarWidth修正为组件宽度 - 分割线宽度(1vp) - minContentWidth。<br/>2.当navBarWidth属性的值，在navBarWidthRange属性的值范围以内时，navBarWidth按如下规则显示：<br/>minNavBarWidth + minContentWidth + 分割线宽度(1vp) >= 组件宽度时，navBarWidth修正为minNavBarWidth；<br/>minNavBarWidth + minContentWidth + 分割线宽度(1vp) < 组件宽度，且navBarWidth + minContentWidth + 分割线宽度(1vp) >= 组件宽度时，navBarWidth修正为组件宽度 - 分割线宽度(1vp) - minContentWidth;<br/>minNavBarWidth + minContentWidth + 分割线宽度(1vp) < 组件宽度，且navBarWidth + minContentWidth + 分割线宽度(1vp) < 组件宽度时，navBarWidth为设置的值。<br/>3.缩小组件尺寸时，先缩小内容区的尺寸至minContentWidth，然后再缩小导航栏的尺寸至minNavBarWidth。若继续缩小，先缩小内容区，内容区消失后再缩小导航栏。<br/>4.设置导航栏为固定尺寸时，若持续缩小组件尺寸，导航栏最后压缩显示。<br/>5.若只设置了navBarWidth属性，则导航栏宽度为navBarWidth，且分割线不可拖动。 |  
| Auto | 2 | API version 9之前：窗口宽度>=520vp时，采用Split模式显示；窗口宽度<520vp时，采用Stack模式显示。<br/>API version 10及以上：窗口宽度>=600vp时，采用Split模式显示；窗口宽度<600vp时，采用Stack模式显示，600vp等于minNavBarWidth(240vp) + minContentWidth (360vp)。 |  
    
## NavBarPosition<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Start | 0 | 双栏显示时，主列在主轴方向首部。 |  
| End | 1 | 双栏显示时，主列在主轴方向尾部。 |  
    
## NavigationTitleMode    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Free | 0 | 当内容为可滚动组件时，标题随着内容向上滚动而缩小（子标题的大小不变、淡出）。向下滚动内容到顶时则恢复原样。<br/>**说明：** <br/>标题随着内容滚动大小联动的动效在title设置为ResourceStr和NavigationCommonTitle时生效，设置成其余自定义节点类型时字体样式无法变化，下拉时只影响标题栏偏移。 |  
| Full | 1 | <span style="letter-spacing: 0px;">固定为大标题模式。</span> |  
| Mini | 2 | 固定为小标题模式。<br/> |  
    
## NavigationMenuItem    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value | string | false | true |  |  
| value<sup>(10+)</sup> | string | false | true | 不显示菜单栏单个选项的文本。<br/> |  
| icon | string | false | false | 菜单栏单个选项的图标资源路径。<br/> |  
| icon<sup>(10+)</sup> | string | false | false |  |  
| action | () => void | false | false | 当前选项被选中的事件回调。<br/> |  
| action<sup>(10+)</sup> | function | false | false |  |  
    
## NavPathInfo<sup>(10+)</sup>    
路由页面信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(10+)</sup> | string | false | true | NavDestination页面名称。<br/> |  
| param<sup>(10+)</sup> | unknown | false | false | NavDestination页面详细参数。<br/> |  
    
## NavPathStack    
Navigation路由栈。    
### pushPath<sup>(10+)</sup>    
将info指定的NavDestination页面信息入栈。  
 **调用形式：**     
- pushPath(info: NavPathInfo): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info | NavPathInfo | true | NavDestination页面的信息。 |  
    
### pushPathByName<sup>(10+)</sup>    
将name指定的NavDestination页面信息入栈，传递的数据为param。  
 **调用形式：**     
- pushPathByName(name: string, param: unknown): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | NavDestination页面名称。 |  
| param | unknown | true | NavDestination页面详细参数。 |  
    
### pop<sup>(10+)</sup>    
弹出路由栈栈顶元素。  
 **调用形式：**     
- pop(): NavPathInfo | undefined  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NavPathInfo | undefined |  |  
    
### popToName<sup>(10+)</sup>    
回退路由栈到第一个名为name的NavDestination页面。  
 **调用形式：**     
- popToName(name: string): number  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | NavDestination页面名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 如果栈中存在名为name的NavDestination页面，则返回第一个名为name的NavDestination页面的索引，否则返回-1。 |  
    
### popToIndex<sup>(10+)</sup>    
回退路由栈到index指定的NavDestination页面。  
 **调用形式：**     
- popToIndex(index: number): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | NavDestination页面的位置索引。 |  
    
### moveToTop<sup>(10+)</sup>    
将第一个名为name的NavDestination页面移到栈顶。  
 **调用形式：**     
- moveToTop(name: string): number  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | NavDestination页面名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 如果栈中存在名为name的NavDestination页面，则返回第一个名为name的NavDestination页面的当前索引，否则返回-1 |  
    
### moveIndexToTop<sup>(10+)</sup>    
将index指定的NavDestination页面移到栈顶。  
 **调用形式：**     
- moveIndexToTop(index: number): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | NavDestination页面的位置索引。 |  
    
### clear<sup>(10+)</sup>    
清除栈中所有页面。  
  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### getAllPathName<sup>(10+)</sup>    
获取栈中所有NavDestination页面的名称。  
 **调用形式：**     
- getAllPathName(): Array\<string>  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 返回栈中所有NavDestination页面的名称。 |  
    
### getParamByIndex<sup>(10+)</sup>    
获取index指定的NavDestination页面的参数信息。  
 **调用形式：**     
- getParamByIndex(index: number): unknown | undefined  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | NavDestination页面的位置索引。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| unknown | undefined | 返回对应NavDestination页面的参数信息。传入index无效时返回undefined。 |  
    
### getParamByName<sup>(10+)</sup>    
获取全部名为name的NavDestination页面的参数信息。  
 **调用形式：**     
- getParamByName(name: string): Array\<unknown>  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | NavDestination页面名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<unknown> | 返回全部名为name的NavDestination页面的参数信息。 |  
    
### getIndexByName<sup>(10+)</sup>    
获取全部名为name的NavDestination页面的位置索引。  
 **调用形式：**     
- getIndexByName(name: string): Array\<number>  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | NavDestination页面名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<number> | 返回全部名为name的NavDestination页面的位置索引。 |  
    
### size<sup>(10+)</sup>    
获取栈大小。  
 **调用形式：**     
- size(): number  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回栈大小。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Navigation()    
起始版本： 8    
## ToolbarItemStatus<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NORMAL | 0 | 设置工具栏单个选项为NORMAL态，该选项显示默认样式，可以触发Hover，Press，Focus事件并显示对应的多态样式。 |  
| DISABLED | 1 | 设置工具栏单个选项为DISABLED态， 该选项显示DISABLED态样式，并且不可交互。 |  
| ACTIVE | 2 | 设置工具栏单个选项为ACTIVE态， 该选项通过点击事件可以将icon图标更新为activeIcon对应的图片资源。 |  
    
## ToolbarItem<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value<sup>(10+)</sup> | ResourceStr | false | true | 工具栏单个选项的显示文本。 |  
| icon<sup>(10+)</sup> | ResourceStr | false | false | 工具栏单个选项的图标资源路径。 |  
| action<sup>(10+)</sup> | function | false | false | 当前选项被选中的事件回调。 |  
| status<sup>(10+)</sup> | ToolbarItemStatus | false | false | 工具栏单个选项的状态。<br/>默认值：ToolbarItemStatus.NORMAL |  
| activeIcon<sup>(10+)</sup> | ResourceStr | false | false | 工具栏单个选项处于ACTIVE态时的图标资源路径。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| navBarWidth<sup>9+</sup> |  Length |  |  
| navBarPosition<sup>9+</sup> |  NavBarPosition |  |  
| navBarWidthRange<sup>10+</sup> |  [Dimension, Dimension] |  |  
| minContentWidth<sup>10+</sup> |  Dimension |  |  
| mode<sup>9+</sup> |  NavigationMode |  |  
| backButtonIcon<sup>9+</sup> |  string \| PixelMap \| Resource |  |  
| hideNavBar<sup>9+</sup> |  boolean |  |  
| title |  ResourceStr \| CustomBuilder \| NavigationCommonTitle \| NavigationCustomTitle |  |  
| subTitle<sup>(deprecated)</sup> |  string |  |  
| hideTitleBar |  boolean |  |  
| hideBackButton |  boolean |  |  
| titleMode |  NavigationTitleMode |  |  
| menus |  Array<NavigationMenuItem> \| CustomBuilder |  |  
| toolBar<sup>(deprecated)</sup> |  object \| CustomBuilder |  |  
| toolbarConfiguration<sup>10+</sup> |  Array<ToolbarItem> \| CustomBuilder |     
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
| hideToolBar |  boolean |  |  
| navDestination<sup>10+</sup> | null |  |  
    
### onTitleModeChange<sup>(deprecated)</sup>    
onTitleModeChange(callback: (titleMode: NavigationTitleMode) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onNavBarStateChange<sup>(deprecated)</sup>    
onNavBarStateChange(callback: (isVisible: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码1：**   
```ts    
// xxx.ets  
class A {  
  text: string = ''  
  num: number = 0  
}  
  
@Entry  
@Component  
struct NavigationExample {  
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]  
  @State currentIndex: number = 0  
  
  @Builder NavigationTitle() {  
    Column() {  
      Text('Title')  
        .fontColor('#182431')  
        .fontSize(30)  
        .lineHeight(41)  
        .fontWeight(700)  
      Text('subtitle')  
        .fontColor('#182431')  
        .fontSize(14)  
        .lineHeight(19)  
        .opacity(0.4)  
        .margin({ top: 2, bottom: 20 })  
    }.alignItems(HorizontalAlign.Start)  
  }  
  
  @Builder NavigationMenus() {  
    Row() {  
      Image('common/ic_public_add.svg')  
        .width(24)  
        .height(24)  
      Image('common/ic_public_add.svg')  
        .width(24)  
        .height(24)  
        .margin({ left: 24 })  
      Image('common/ic_public_more.svg')  
        .width(24)  
        .height(24)  
        .margin({ left: 24 })  
    }  
  }  
  
  build() {  
    Column() {  
      Navigation() {  
        TextInput({ placeholder: 'search...' })  
          .width('90%')  
          .height(40)  
          .backgroundColor('#FFFFFF')  
          .margin({ top: 8 })  
  
        List({ space: 12, initialIndex: 0 }) {  
          ForEach(this.arr, (item: number) => {  
            ListItem() {  
              Text('' + item)  
                .width('90%')  
                .height(72)  
                .backgroundColor('#FFFFFF')  
                .borderRadius(24)  
                .fontSize(16)  
                .fontWeight(500)  
                .textAlign(TextAlign.Center)  
            }.editable(true)  
          }, (item: number) => item.toString())  
        }  
        .height(324)  
        .width('100%')  
        .margin({ top: 12, left: '10%' })  
      }  
      .title(this.NavigationTitle)  
      .menus(this.NavigationMenus)  
      .titleMode(NavigationTitleMode.Full)  
      .toolbarConfiguration([  
        {  
          value: $r("app.string.navigation_toolbar_add"),  
          icon: $r("app.media.ic_public_highlightsed")  
        },  
        {  
          value: $r("app.string.navigation_toolbar_app"),  
          icon: $r("app.media.ic_public_highlights")  
        },  
        {  
          value: $r("app.string.navigation_toolbar_collect"),  
          icon: $r("app.media.ic_public_highlights")  
        }  
      ])  
      .hideTitleBar(false)  
      .hideToolBar(false)  
      .onTitleModeChange((titleModel: NavigationTitleMode) => {  
        console.info('titleMode' + titleModel)  
      })  
    }.width('100%').height('100%').backgroundColor('#F1F3F5')  
  }  
}  
    
```    
  
![zh-cn_image_navigation](figures/zh-cn_image_navigation.png)  
    
 **示例代码2：**   
```ts    
// Index.ets  
import { pageOneTmp } from './pageOne'  
import { pageTwoTmp } from './pageTwo'  
import { pages }  from './pageTwo'  
  
@Entry  
@Component  
struct NavigationExample {  
  @Provide('pageInfos') pageInfos: NavPathStack = new NavPathStack()  
  
  @Builder  
  PageMap(name: string) {  
    if (name === 'pageOne') {  
      pageOneTmp()  
    } else if (name === 'pageTwo') {  
      pageTwoTmp({ names: name, values: this.pageInfos } as pages)  
    }  
  }  
  
  build() {  
    Navigation(this.pageInfos) {  
      Column() {  
        Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })  
          .width('80%')  
          .height(40)  
          .margin(20)  
          .onClick(() => {  
            this.pageInfos.pushPath({ name: 'pageOne' }) //将name指定的NavDestination页面信息入栈  
          })  
      }  
    }.title('NavIndex').navDestination(this.PageMap)  
  }  
}  
    
```    
  
    
 **示例代码3：**   
```ts    
// pageOne.ets  
class tmpClass{  
count:number=10  
}  
@Component  
export struct pageOneTmp {  
@Consume('pageInfos') pageInfos: NavPathStack;  
  
build() {  
NavDestination() {  
Column() {  
Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })  
.width('80%')  
.height(40)  
.margin(20)  
.onClick(() => {  
let tmp = new tmpClass()  
this.pageInfos.pushPathByName('pageTwo', tmp) //将name指定的NavDestination页面信息入栈，传递的数据为param  
})  
Button('popToname', { stateEffect: true, type: ButtonType.Capsule })  
.width('80%')  
.height(40)  
.margin(20)  
.onClick(() => {  
this.pageInfos.popToName('pageTwo') //回退路由栈到第一个名为name的NavDestination页面  
console.log('popToName' + JSON.stringify(this.pageInfos), '返回值' + JSON.stringify(this.pageInfos.popToName('pageTwo')))  
})  
Button('popToIndex', { stateEffect: true, type: ButtonType.Capsule })  
.width('80%')  
.height(40)  
.margin(20)  
.onClick(() => {  
this.pageInfos.popToIndex(1) // 回退路由栈到index指定的NavDestination页面  
console.log('popToIndex' + JSON.stringify(this.pageInfos))  
})  
Button('moveToTop', { stateEffect: true, type: ButtonType.Capsule })  
.width('80%')  
.height(40)  
.margin(20)  
.onClick(() => {  
this.pageInfos.moveToTop('pageTwo') // 将第一个名为name的NavDestination页面移到栈顶  
console.log('moveToTop' + JSON.stringify(this.pageInfos), '返回值' + JSON.stringify(this.pageInfos.moveToTop('pageTwo')))  
})  
Button('moveIndexToTop', { stateEffect: true, type: ButtonType.Capsule })  
.width('80%')  
.height(40)  
.margin(20)  
.onClick(() => {  
this.pageInfos.moveIndexToTop(1) // 将index指定的NavDestination页面移到栈顶  
console.log('moveIndexToTop' + JSON.stringify(this.pageInfos))  
})  
Button('clear', { stateEffect: true, type: ButtonType.Capsule })  
.width('80%')  
.height(40)  
.margin(20)  
.onClick(() => {  
this.pageInfos.clear() //清除栈中所有页面  
})  
Button('get', { stateEffect: true, type: ButtonType.Capsule })  
.width('80%')  
.height(40)  
.margin(20)  
.onClick(() => {  
console.log('-------------------')  
console.log('获取栈中所有NavDestination页面的名称', JSON.stringify(this.pageInfos.getAllPathName()))  
console.log('获取index指定的NavDestination页面的参数信息', JSON.stringify(this.pageInfos.getParamByIndex(1)))  
console.log('获取全部名为name的NavDestination页面的参数信息', JSON.stringify(this.pageInfos.getParamByName('pageTwo')))  
console.log('获取全部名为name的NavDestination页面的位置索引', JSON.stringify(this.pageInfos.getIndexByName('pageOne')))  
console.log('获取栈大小', JSON.stringify(this.pageInfos.size()))  
})  
}.width('100%').height('100%')  
}.title('pageOne')  
.onBackPressed(() => {  
this.pageInfos.pop() // 弹出路由栈栈顶元素  
console.log('pop' + '返回值' + JSON.stringify(this.pageInfos.pop()))  
return true  
})  
}  
}  
    
```    
  
    
 **示例代码4：**   
```ts    
// pageTwo.ets  
  
export class pages {  
names: string = ""  
values: NavPathStack | null = null  
}  
  
@Builder  
export function pageTwoTmp(info: pages) {  
NavDestination() {  
Column() {  
Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })  
.width('80%')  
.height(40)  
.margin(20)  
.onClick(() => {  
(info.values as NavPathStack).pushPathByName('pageOne', null)  
})  
}.width('100%').height('100%')  
}.title('pageTwo')  
.onBackPressed(() => {  
(info.values as NavPathStack).pop()  
return true  
})  
}  
    
```    
  
![navigation.gif](figures/navigation.gif)  
