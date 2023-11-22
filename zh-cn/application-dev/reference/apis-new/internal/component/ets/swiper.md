# swiper    
滑块视图容器，提供子组件滑动轮播显示的能力。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SwiperController    
Swiper容器组件的控制器，可以将此对象绑定至Swiper组件，然后通过它控制翻页。  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### showNext    
翻至下一页。翻页带动效切换过程，时长通过duration指定。  
  
 **调用形式：**     
- showNext()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### showPrevious    
翻至上一页。翻页带动效切换过程，时长通过duration指定。  
  
 **调用形式：**     
- showPrevious()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### finishAnimation  
 **调用形式：**     
    
- finishAnimation(callback?: () => void)    
起始版本： 7  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 动画结束的回调。 |  
    
## Indicator<sup>(10+)</sup>    
设置导航点距离Swiper组件距离。  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### left<sup>(10+)</sup>    
设置导航点距离Swiper组件左边的距离。  
 **调用形式：**     
- left(value: Length): T  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Length | true | 默认值：0 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T |  |  
    
### top<sup>(10+)</sup>    
设置导航点距离Swiper组件顶部的距离。  
 **调用形式：**     
- top(value: Length): T  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Length | true | 默认值：0 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T |  |  
    
### right<sup>(10+)</sup>    
设置导航点距离Swiper组件右边的距离。  
 **调用形式：**     
- right(value: Length): T  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Length | true | 默认值：0 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T |  |  
    
### bottom<sup>(10+)</sup>    
设置导航点距离Swiper组件底部的距离。  
 **调用形式：**     
- bottom(value: Length): T  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Length | true | 默认值：0 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T |  |  
    
### dot<sup>(10+)</sup>  
 **调用形式：**     
- static dot(): DotIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DotIndicator |  |  
    
### digit<sup>(10+)</sup>  
 **调用形式：**     
- static digit(): DigitIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DigitIndicator |  |  
    
## DotIndicator<sup>(10+)</sup>    
圆点指示器属性及功能继承自Indicator。  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### itemWidth<sup>(10+)</sup>    
设置Swiper组件圆点导航指示器的宽，不支持设置百分比。  
 **调用形式：**     
- itemWidth(value: Length): DotIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Length | true | 默认值：6。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DotIndicator |  |  
    
### itemHeight<sup>(10+)</sup>    
设置Swiper组件圆点导航指示器的高，不支持设置百分比。  
 **调用形式：**     
- itemHeight(value: Length): DotIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Length | true | 默认值：6 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DotIndicator |  |  
    
### selectedItemWidth<sup>(10+)</sup>    
设置选中Swiper组件圆点导航指示器的宽，不支持设置百分比。  
  
 **调用形式：**     
- selectedItemWidth(value: Length): DotIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Length | true | 12 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DotIndicator |  |  
    
 **示例代码：**   
```ts    
设置选中Swiper组件圆点导航指示器的宽，不支持设置百分比。    
```    
  
    
### selectedItemHeight<sup>(10+)</sup>    
设置选中Swiper组件圆点导航指示器的高，不支持设置百分比。  
 **调用形式：**     
- selectedItemHeight(value: Length): DotIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Length | true | 默认值：6 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DotIndicator |  |  
    
### mask<sup>(10+)</sup>    
设置是否显示Swiper组件圆点导航指示器的蒙版样式。  
 **调用形式：**     
- mask(value: boolean): DotIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | boolean | true | 默认值：false |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DotIndicator |  |  
    
### color<sup>(10+)</sup>    
设置Swiper组件圆点导航指示器的颜色。  
 **调用形式：**     
- color(value: ResourceColor): DotIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ResourceColor | true | 默认值：'\#182431'（10%透明度） |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DotIndicator |  |  
    
### selectedColor<sup>(10+)</sup>    
设置选中Swiper组件圆点导航指示器的颜色。  
 **调用形式：**     
- selectedColor(value: ResourceColor): DotIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ResourceColor | true | 默认值：'\#007DFF' |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DotIndicator |  |  
    
## SwiperAutoFill<sup>(10+)</sup>    
自适应属性。  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| minSize<sup>(10+)</sup> | VP | false | true | 设置元素显示最小宽度。 |  
    
## DigitIndicator<sup>(10+)</sup>    
数字指示器属性及功能继承自Indicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### fontColor<sup>(10+)</sup>    
设置Swiper组件数字导航点的字体颜色。  
 **调用形式：**     
- fontColor(value: ResourceColor): DigitIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ResourceColor | true | 默认值：'\#ff182431' |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DigitIndicator |  |  
    
### selectedFontColor<sup>(10+)</sup>    
设置选中Swiper组件数字导航点的字体颜色。  
 **调用形式：**     
- selectedFontColor(value: ResourceColor): DigitIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ResourceColor | true | 默认值：'\#ff182431' |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DigitIndicator |  |  
    
### digitFont<sup>(10+)</sup>    
设置Swiper组件数字导航点的字体样式：  
\- size：数字导航点指示器的字体大小，不支持设置百分比。  
 **调用形式：**     
- digitFont(value: Font): DigitIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Font | true | 默认值：14vp<br/>- weight：数字导航点指示器的字重。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DigitIndicator |  |  
    
### selectedDigitFont<sup>(10+)</sup>    
设置选中Swiper组件数字导航点的字体样式：  
\- size：数字导航点选中指示器的字体大小，不支持设置百分比。  
 **调用形式：**     
- selectedDigitFont(value: Font): DigitIndicator  
  
 **卡片能力:**     
从API version 10开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Font | true | 默认值：14vp<br/>- weight：数字导航点选中指示器的字重。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DigitIndicator |  |  
    
## ArrowStyle<sup>(10+)</sup>    
左右箭头属性。  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| showBackground<sup>(10+)</sup> | boolean | false | false | 设置箭头底板是否显示。<br/>默认值：false<br/> |  
| isSidebarMiddle<sup>(10+)</sup> | boolean | false | false | 设置箭头显示位置。<br/>默认值：false<br/>默认显示在导航点指示器两侧。<br/> |  
| backgroundSize<sup>(10+)</sup> | Length | false | false | 设置底板大小。<br/>在导航点两侧显示：<br/>默认值：24vp<br/>在组件两侧显示：<br/>默认值：32vp<br/>不支持设置百分比。<br/> |  
| backgroundColor<sup>(10+)</sup> | ResourceColor | false | false | 设置底板颜色。<br/>在导航点两侧显示：<br/>默认值：'#00000000'<br/>在组件两侧显示：<br/>默认值：'#19182431'<br/> |  
| arrowSize<sup>(10+)</sup> | Length | false | false | 设置箭头大小。<br/>在导航点两侧显示时：<br/>默认值：18vp<br/>在组件两侧显示时：<br/>默认值：24vp<br/><strong>说明：</strong><br/>showBackground为true时，arrowSize为backgroundSize的3/4。<br/>不支持设置百分比。<br/> |  
| arrowColor<sup>(10+)</sup> | ResourceColor | false | false | 设置箭头颜色。<br/>默认值：'\#182431' |  
    
## SwiperDisplayMode    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Stretch<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 10 开始废弃。建议使用SwiperDisplayMode#STRETCH替代。<br>Swiper滑动一页的宽度为Swiper组件自身的宽度。 |  
| AutoLinear<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 10 开始废弃。建议使用SwiperDisplayMode#AUTO_LINEAR替代。<br>Swiper滑动一页的宽度为子组件宽度中的最大值。 |  
| STRETCH<sup>(10+)</sup> | 2 | Swiper滑动一页的宽度为Swiper组件自身的宽度。 |  
| AUTO_LINEAR<sup>(10+)</sup> | 3 | Swiper滑动一页的宽度为视窗内最左侧子组件的宽度。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Swiper(controller?: SwiperController)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| controller | SwiperController | false | 给组件绑定一个控制器，用来控制组件翻页。<br/> |  
    
## IndicatorStyle<sup>(deprecated)</sup>    
设置导航点样式    
从API version 8 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left<sup>(deprecated)</sup> | Length | false | false | 从API version 8 开始支持，从API version 10 开始废弃。<br>设置导航点距离Swiper组件左边的距离。<br/> |  
| top<sup>(deprecated)</sup> | Length | false | false | 从API version 8 开始支持，从API version 10 开始废弃。<br>设置导航点距离Swiper组件顶部的距离。<br/> |  
| right<sup>(deprecated)</sup> | Length | false | false | 从API version 8 开始支持，从API version 10 开始废弃。<br>设置导航点距离Swiper组件右边的距离。<br/> |  
| bottom<sup>(deprecated)</sup> | Length | false | false | 从API version 8 开始支持，从API version 10 开始废弃。<br>设置导航点距离Swiper组件底部的距离。<br/> |  
| size<sup>(deprecated)</sup> | Length | false | false | 从API version 8 开始支持，从API version 10 开始废弃。<br>设置导航点的直径，不支持设置百分比。默认值：6vp。<br/> |  
| mask<sup>(deprecated)</sup> | boolean | false | false | 从API version 8 开始支持，从API version 10 开始废弃。<br>设置是否显示导航点蒙层样式。<br/> |  
| color<sup>(deprecated)</sup> | ResourceColor | false | false | 从API version 8 开始支持，从API version 10 开始废弃。<br>设置导航点的颜色。<br/> |  
| selectedColor<sup>(deprecated)</sup> | ResourceColor | false | false | 从API version 8 开始支持，从API version 10 开始废弃。<br>设置选中的导航点的颜色。<br/> |  
    
## SwiperAnimationEvent<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| currentOffset<sup>(10+)</sup> | number | false | true |  |  
| targetOffset<sup>(10+)</sup> | number | false | true |  |  
| velocity<sup>(10+)</sup> | number | false | true |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| index |  number |  |  
| autoPlay |  boolean |  |  
| interval |  number |  |  
| indicator |  DotIndicator \| DigitIndicator \| boolean |  |  
| displayArrow<sup>10+</sup> |  ArrowStyle \| boolean, isHoverShow?: boolean |  |  
| loop |  boolean |  |  
| duration |  number |  |  
| vertical |  boolean |  |  
| itemSpace |  number \| string |  |  
| displayMode |  SwiperDisplayMode |  |  
| cachedCount<sup>8+</sup> |  number |  |  
| displayCount<sup>8+</sup> |  number \| string \| SwiperAutoFill |  |  
| effectMode<sup>8+</sup> |  EdgeEffect |  |  
| disableSwipe<sup>8+</sup> |  boolean |  |  
| curve<sup>8+</sup> |  Curve \| string \| ICurve |  |  
| indicatorStyle<sup>(deprecated)</sup> | null |  |  
| prevMargin<sup>10+</sup> |  Length |  |  
| nextMargin<sup>10+</sup> |  Length |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(event: (index: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (index: number) => void | true |  |  
    
### onAnimationStart<sup>(deprecated)</sup>    
onAnimationStart(event: (index: number, targetIndex: number, extraInfo: SwiperAnimationEvent) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(9+)</sup> | (index: number, targetIndex: number, extraInfo: SwiperAnimationEvent) => void | true |  |  
    
### onAnimationEnd<sup>(deprecated)</sup>    
onAnimationEnd(event: (index: number, extraInfo: SwiperAnimationEvent) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(9+)</sup> | (index: number, extraInfo: SwiperAnimationEvent) => void | true |  |  
    
### onGestureSwipe<sup>(deprecated)</sup>    
onGestureSwipe(event: (index: number, extraInfo: SwiperAnimationEvent) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | (index: number, extraInfo: SwiperAnimationEvent) => void | true |  |  
    
 **示例代码1：**   
```ts    
class MyDataSource implements IDataSource {  
  private list: number[] = []  
  
  constructor(list: number[]) {  
    this.list = list  
  }  
  
  totalCount(): number {  
    return this.list.length  
  }  
  
  getData(index: number): number {  
    return this.list[index]  
  }  
  
  registerDataChangeListener(listener: DataChangeListener): void {  
  }  
  
  unregisterDataChangeListener() {  
  }  
}  
  
@Entry  
@Component  
struct SwiperExample {  
  private swiperController: SwiperController = new SwiperController()  
  private data: MyDataSource = new MyDataSource([])  
  
  aboutToAppear(): void {  
    let list: number[] = []  
    for (let i = 1; i <= 10; i++) {  
      list.push(i);  
    }  
    this.data = new MyDataSource(list)  
  }  
  
  build() {  
    Column({ space: 5 }) {  
      Swiper(this.swiperController) {  
        LazyForEach(this.data, (item: string) => {  
          Text(item.toString())  
            .width('90%')  
            .height(160)  
            .backgroundColor(0xAFEEEE)  
            .textAlign(TextAlign.Center)  
            .fontSize(30)  
        }, (item: string) => item)  
      }  
      .cachedCount(2)  
      .index(1)  
      .autoPlay(true)  
      .interval(4000)  
      .indicator(true)  
      .loop(true)  
      .duration(1000)  
      .itemSpace(0)  
      .displayArrow({  
        showBackground: true,  
        isSidebarMiddle: true,  
        backgroundSize: 24,  
        backgroundColor: Color.White,  
        arrowSize: 18,  
        arrowColor: Color.Blue  
      }, false)  
      .curve(Curve.Linear)  
      .onChange((index: number) => {  
        console.info(index.toString())  
      })  
      .onGestureSwipe((index: number, extraInfo: SwiperAnimationEvent) => {  
        console.info("index: " + index)  
        console.info("current offset: " + extraInfo.currentOffset)  
      })  
      .onAnimationStart((index: number, targetIndex: number, extraInfo: SwiperAnimationEvent) => {  
        console.info("index: " + index)  
        console.info("targetIndex: " + targetIndex)  
        console.info("current offset: " + extraInfo.currentOffset)  
        console.info("target offset: " + extraInfo.targetOffset)  
        console.info("velocity: " + extraInfo.velocity)  
      })  
      .onAnimationEnd((index: number, extraInfo: SwiperAnimationEvent) => {  
        console.info("index: " + index)  
        console.info("current offset: " + extraInfo.currentOffset)  
      })  
  
      Row({ space: 12 }) {  
        Button('showNext')  
          .onClick(() => {  
            this.swiperController.showNext()  
          })  
        Button('showPrevious')  
          .onClick(() => {  
            this.swiperController.showPrevious()  
          })  
      }.margin(5)  
    }.width('100%')  
    .margin({ top: 5 })  
  }  
}  
    
```    
  
![swiper](figures/swiper.gif)  
    
 **示例代码2：**   
```ts    
class MyDataSource implements IDataSource {  
  private list: number[] = []  
  
  constructor(list: number[]) {  
    this.list = list  
  }  
  
  totalCount(): number {  
    return this.list.length  
  }  
  
  getData(index: number): number {  
    return this.list[index]  
  }  
  
  registerDataChangeListener(listener: DataChangeListener): void {  
  }  
  
  unregisterDataChangeListener() {  
  }  
}  
  
@Entry  
@Component  
struct SwiperExample {  
  private swiperController: SwiperController = new SwiperController()  
  private data: MyDataSource = new MyDataSource([])  
  
  aboutToAppear(): void {  
    let list: number[] = []  
    for (let i = 1; i <= 10; i++) {  
      list.push(i);  
    }  
    this.data = new MyDataSource(list)  
  }  
  
  build() {  
    Column({ space: 5 }) {  
      Swiper(this.swiperController) {  
        LazyForEach(this.data, (item: string) => {  
          Text(item.toString())  
            .width('90%')  
            .height(160)  
            .backgroundColor(0xAFEEEE)  
            .textAlign(TextAlign.Center)  
            .fontSize(30)  
        }, (item: string) => item)  
      }  
      .cachedCount(2)  
      .index(1)  
      .autoPlay(true)  
      .interval(4000)  
      .indicator(Indicator.dot()  
        .itemWidth(15)  
        .itemHeight(15)  
        .selectedItemWidth(15)  
        .selectedItemHeight(15)  
        .color(Color.Gray)  
        .selectedColor(Color.Blue))  
      .loop(true)  
      .duration(1000)  
      .itemSpace(0)  
      .displayArrow(true, true)  
  
      Row({ space: 12 }) {  
        Button('showNext')  
          .onClick(() => {  
            this.swiperController.showNext()  
          })  
        Button('showPrevious')  
          .onClick(() => {  
            this.swiperController.showPrevious()  
          })  
      }.margin(5)  
    }.width('100%')  
    .margin({ top: 5 })  
  }  
}  
```  
![swiper](figures/swiper-dot.gif)  
  
### 示例3  
```ts  
// xxx.ets  
class MyDataSource implements IDataSource {  
  private list: number[] = []  
  
  constructor(list: number[]) {  
    this.list = list  
  }  
  
  totalCount(): number {  
    return this.list.length  
  }  
  
  getData(index: number): number {  
    return this.list[index]  
  }  
  
  registerDataChangeListener(listener: DataChangeListener): void {  
  }  
  
  unregisterDataChangeListener() {  
  }  
}  
  
@Entry  
@Component  
struct SwiperExample {  
  private swiperController: SwiperController = new SwiperController()  
  private data: MyDataSource = new MyDataSource([])  
  
  aboutToAppear(): void {  
    let list: number[] = []  
    for (let i = 1; i <= 10; i++) {  
      list.push(i);  
    }  
    this.data = new MyDataSource(list)  
  }  
  
  build() {  
    Column({ space: 5 }) {  
      Swiper(this.swiperController) {  
        LazyForEach(this.data, (item: string) => {  
          Text(item.toString())  
            .width('90%')  
            .height(160)  
            .backgroundColor(0xAFEEEE)  
            .textAlign(TextAlign.Center)  
            .fontSize(30)  
        }, (item: string) => item)  
      }  
      .cachedCount(2)  
      .index(1)  
      .autoPlay(true)  
      .interval(4000)  
      .indicator(Indicator.digit()  
        .right("43%")  
        .top(200)  
        .fontColor(Color.Gray)  
        .selectedFontColor(Color.Gray)  
        .digitFont({ size: 20, weight: FontWeight.Bold })  
        .selectedDigitFont({ size: 20, weight: FontWeight.Normal }))  
      .loop(true)  
      .duration(1000)  
      .itemSpace(0)  
      .displayArrow(true, false)  
  
      Row({ space: 12 }) {  
        Button('showNext')  
          .onClick(() => {  
            this.swiperController.showNext()  
          })  
        Button('showPrevious')  
          .onClick(() => {  
            this.swiperController.showPrevious()  
          })  
      }.margin(5)  
    }.width('100%')  
    .margin({ top: 5 })  
  }  
}  
    
```    
  
![swiper](figures/swiper-dot.gif)  
    
 **示例代码3：**   
```ts    
// xxx.ets  
class MyDataSource implements IDataSource {  
  private list: number[] = []  
  
  constructor(list: number[]) {  
    this.list = list  
  }  
  
  totalCount(): number {  
    return this.list.length  
  }  
  
  getData(index: number): number {  
    return this.list[index]  
  }  
  
  registerDataChangeListener(listener: DataChangeListener): void {  
  }  
  
  unregisterDataChangeListener() {  
  }  
}  
  
@Entry  
@Component  
struct SwiperExample {  
  private swiperController: SwiperController = new SwiperController()  
  private data: MyDataSource = new MyDataSource([])  
  
  aboutToAppear(): void {  
    let list: number[] = []  
    for (let i = 1; i <= 10; i++) {  
      list.push(i);  
    }  
    this.data = new MyDataSource(list)  
  }  
  
  build() {  
    Column({ space: 5 }) {  
      Swiper(this.swiperController) {  
        LazyForEach(this.data, (item: string) => {  
          Text(item.toString())  
            .width('90%')  
            .height(160)  
            .backgroundColor(0xAFEEEE)  
            .textAlign(TextAlign.Center)  
            .fontSize(30)  
        }, (item: string) => item)  
      }  
      .cachedCount(2)  
      .index(1)  
      .autoPlay(true)  
      .interval(4000)  
      .indicator(Indicator.digit()  
        .right("43%")  
        .top(200)  
        .fontColor(Color.Gray)  
        .selectedFontColor(Color.Gray)  
        .digitFont({ size: 20, weight: FontWeight.Bold })  
        .selectedDigitFont({ size: 20, weight: FontWeight.Normal }))  
      .loop(true)  
      .duration(1000)  
      .itemSpace(0)  
      .displayArrow(true, false)  
  
      Row({ space: 12 }) {  
        Button('showNext')  
          .onClick(() => {  
            this.swiperController.showNext()  
          })  
        Button('showPrevious')  
          .onClick(() => {  
            this.swiperController.showPrevious()  
          })  
      }.margin(5)  
    }.width('100%')  
    .margin({ top: 5 })  
  }  
}  
    
```    
  
![swiper](figures/swiper-digit.gif)  
