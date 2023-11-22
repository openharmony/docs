# image    
Image为图片组件，常用于在应用中显示图片。Image支持加载[PixelMap](../apis/js-apis-image.md#pixelmap7)、[ResourceStr](ts-types.md#resourcestr)和[DrawableDescriptor](../apis/js-apis-arkui-drawableDescriptor.md#drawabledescriptor)类型的数据源，支持png、jpg、bmp、svg和gif类型的图片格式。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## DrawableDescriptor<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## ImageRenderMode    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Original | 0 | 原色渲染模式。 |  
| Template | 1 | 黑白渲染模式。 |  
    
## ImageInterpolation    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | 不使用图片插值。 |  
| Low | 1 | 低图片插值。 |  
| Medium | 2 | 中图片插值。 |  
| High | 3 | 高图片插值，插值质量最高，可能会影响图片渲染的速度。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Image(src: PixelMap | ResourceStr | DrawableDescriptor)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| alt |  string \| Resource |  |  
| matchTextDirection |  boolean |  |  
| fitOriginalSize |  boolean |  |  
| fillColor |  ResourceColor |  |  
| objectFit |  ImageFit |  |  
| objectRepeat |  ImageRepeat |  |  
| autoResize |  boolean |  |  
| renderMode |  ImageRenderMode |  |  
| interpolation |  ImageInterpolation |  |  
| sourceSize |  { width: number; height: number } |  |  
| syncLoad<sup>8+</sup> |  boolean |  |  
| colorFilter<sup>9+</sup> |  ColorFilter |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| copyOption<sup>9+</sup> |  CopyOptions |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| draggable<sup>9+</sup> |  boolean |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
    
### onComplete<sup>(deprecated)</sup>    
onComplete(     callback: (event?: {       width: number;       height: number;       componentWidth: number;       componentHeight: number;       loadingStatus: number;       contentWidth: number;       contentHeight: number;       contentOffsetX: number;       contentOffsetY: number;     }) => void,   )    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onError<sup>(deprecated)</sup>    
onError(callback: (event: {     /**      * Component width.      *      * @type { number }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      * @form      */     componentWidth: number;      /**      * Component height.      *      * @type { number }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      * @form      */     componentHeight: number   }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onFinish<sup>(deprecated)</sup>    
onFinish(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
 **示例代码1：**   
加载基本类型图片  
```ts    
@Entry  
@Component  
struct ImageExample1 {  
  build() {  
    Column() {  
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {  
        Row() {  
          // 加载png格式图片  
          Image($r('app.media.ic_camera_master_ai_leaf'))  
            .width(110).height(110).margin(15)  
            .overlay('png', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })  
          // 加载gif格式图片  
          Image($r('app.media.loading'))  
            .width(110).height(110).margin(15)  
            .overlay('gif', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })  
        }  
        Row() {  
          // 加载svg格式图片  
          Image($r('app.media.ic_camera_master_ai_clouded'))  
            .width(110).height(110).margin(15)  
            .overlay('svg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })  
          // 加载jpg格式图片  
          Image($r('app.media.ic_public_favor_filled'))  
            .width(110).height(110).margin(15)  
            .overlay('jpg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })  
        }  
      }  
    }.height(320).width(360).padding({ right: 10, top: 10 })  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载网络图片加载网络图片时，默认网络超时是5分钟，建议使用alt配置加载时的占位图。如果需要更灵活的网络配置，可以使用[HTTP](../../connectivity/http-request.md)工具包发送网络请求，接着将返回的数据解码为Image组件中的`PixelMap`，图片开发可参考[图片处理](../../media/image-overview.md)。使用网络图片时，需要申请权限ohos.permission.INTERNET。具体申请方式请参考[权限申请声明](../../security/accesstoken-guidelines.md)。  
```ts    
@Entry  
@Component  
struct ImageExample2 {  
  build() {  
    Column({ space: 10 }) {  
      Image("https://www.example.com/xxx.png")// 直接加载网络地址，请填写一个具体的网络图片地址  
        .alt($r('app.media.icon'))// 使用alt，在网络图片加载成功前使用占位图  
        .width(100)  
        .height(100)  
    }  
  }  
}  
    
```    
  
    
 **示例代码3：**   
为图片添加事件  
```ts    
class tmp{  
  width: number = 0  
  height: number = 0  
}  
let msg:tmp = new tmp()  
@Entry  
@Component  
struct ImageExample3 {  
  @State widthValue: number = 0;  
  @State heightValue: number = 0;  
  private on: Resource = $r('app.media.image_on');  
  private off: Resource = $r('app.media.image_off');  
  private on2off: Resource = $r('app.media.image_on2off');  
  private off2on: Resource = $r('app.media.image_off2on');  
  @State src: Resource = this.on;  
  
  build() {  
    Column() {  
      Row({ space: 20 }) {  
        Column() {  
          Image($r('app.media.img_example1'))  
            .alt($r('app.media.ic_public_picture'))  
            .sourceSize({  
              width: 900,  
              height: 900  
            })  
            .objectFit(ImageFit.Cover)  
            .height(180).width(180)  
            // 图片加载完成后，获取图片尺寸。  
            .onComplete(msg => {  
              if(msg){  
                this.widthValue = msg.width  
                this.heightValue = msg.height  
              }  
            })  
            .onError(() => {  
              console.log('load image fail')  
            })  
            .overlay('\nwidth: ' + String(this.widthValue) + ' height: ' + String(this.heightValue), {  
              align: Alignment.Bottom,  
              offset: { x: 0, y: 20 }  
            })  
        }  
        // 为图片添加点击事件，点击完成后加载特定图片  
        Image(this.src)  
          .width(120).height(120)  
          .onClick(() => {  
            if (this.src == this.on || this.src == this.off2on) {  
              this.src = this.on2off  
            } else {  
              this.src = this.off2on  
            }  
          })  
          .onFinish(() => {  
            if (this.src == this.off2on) {  
              this.src = this.on  
            } else {  
              this.src = this.off  
            }  
          })  
      }  
    }.width('100%')  
  }  
}  
    
```    
  
