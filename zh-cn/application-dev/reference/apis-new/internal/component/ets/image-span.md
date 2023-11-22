# image_span    
[Text](ts-basic-components-text.md)组件的子组件，用于显示行内图片。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
<p>图片的数据源，支持本地图片和网络图片。<br/>当使用相对路径引用图片资源时，例如<code>ImageSpan("common/test.jpg")</code>，不支持跨包/跨模块调用该ImageSpan组件，建议使用<code>$r</code>方式来管理需全局使用的图片资源。<br/>- 支持的图片格式包括png、jpg、bmp、svg和gif。<br/>- 支持<code>Base64</code>字符串。格式<code>data:image/[png|jpeg|bmp|webp];base64,[base64 data]</code>, 其中<code>[base64 data]</code>为<code>Base64</code>字符串数据。<br/>- 支持file:///data/storage路径前缀的字符串，用于读取本应用安装目录下files文件夹下的图片资源。需要保证目录包路径下的文件有可读权限。<br/></p>  
    
 **调用形式**     
    
- ImageSpan(value: ResourceStr | PixelMap)    
起始版本： 10    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| verticalAlign |  ImageSpanAlignment |  |  
| objectFit |  ImageFit |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct SpanExample {  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start}) {  
      Text() {  
        Span('This is the Span and ImageSpan component').fontSize(25).textCase(TextCase.Normal)  
          .decoration({ type: TextDecorationType.None, color: Color.Pink })  
      }.width('100%').textAlign(TextAlign.Center)  
      Text() {  
        ImageSpan($r('app.media.icon'))  
          .width('200px')  
          .height('200px')  
          .objectFit(ImageFit.Fill)  
          .verticalAlign(ImageSpanAlignment.CENTER)  
        Span('I am LineThrough-span')  
          .decoration({ type: TextDecorationType.LineThrough, color: Color.Red }).fontSize(25)  
        ImageSpan($r('app.media.icon'))  
          .width('50px')  
          .height('50px')  
          .verticalAlign(ImageSpanAlignment.TOP)  
        Span('I am Underline-span')  
          .decoration({ type: TextDecorationType.Underline, color: Color.Red }).fontSize(25)  
        ImageSpan($r('app.media.icon'))  
          .size({width:'100px', height:'100px'})  
          .verticalAlign(ImageSpanAlignment.BASELINE)  
        Span('I am Underline-span')  
          .decoration({ type: TextDecorationType.Underline, color: Color.Red }).fontSize(25)  
        ImageSpan($r('app.media.icon'))  
          .width('70px')  
          .height('70px')  
          .verticalAlign(ImageSpanAlignment.BOTTOM)  
        Span('I am Underline-span')  
          .decoration({ type: TextDecorationType.Underline, color: Color.Red }).fontSize(50)  
      }  
      .width('100%')  
      .textIndent(50)  
    }.width('100%').height('100%').padding({ left: 0, right: 0, top: 0 })  
  }  
}  
    
```    
  
![imagespan](figures/imagespan.png)  
