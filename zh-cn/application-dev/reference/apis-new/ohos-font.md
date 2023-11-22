# @ohos.font    
本模块提供注册自定义字体。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import font from '@ohos.font'    
```  
    
## FontOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| familyName | string \| Resource | false | true | 设置注册的字体名称。 |  
| familySrc | string \| Resource | false | true | 设置注册字体文件的路径。 |  
    
## FontInfo<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| path<sup>(10+)</sup> | string | false | true | 系统字体的文件路径。 |  
| postScriptName<sup>(10+)</sup> | string | false | true | 系统字体的postScript名称。 |  
| fullName<sup>(10+)</sup> | string | false | true | 系统字体的名称。 |  
| family<sup>(10+)</sup> | string | false | true | 系统字体的字体家族。 |  
| subfamily<sup>(10+)</sup> | string | false | true | 系统字体的子字体家族。 |  
| weight<sup>(10+)</sup> | number | false | true | 系统字体的粗细程度。 |  
| width<sup>(10+)</sup> | number | false | true | 系统字体的宽窄风格属性。 |  
| italic<sup>(10+)</sup> | boolean | false | true | 系统字体是否倾斜。 |  
| monoSpace<sup>(10+)</sup> | boolean | false | true | 系统字体是否紧凑。 |  
| symbolic<sup>(10+)</sup> | boolean | false | true | 系统字体是否支持符号字体。 |  
    
## registerFont    
在字体管理中注册自定义字体。  
 **调用形式：**     
- registerFont(options: FontOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | FontOptions | true | 注册的自定义字体信息。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import font from '@ohos.font';  
  
@Entry  
@Component  
struct FontExample {  
  @State message: string = '你好，世界'  
  
  aboutToAppear() {  
    // familyName和familySrc都支持string  
    font.registerFont({  
      familyName: 'medium',  
      familySrc: '/font/medium.ttf' // font文件与pages目录同级  
    })  
  
    // familyName和familySrc都支持系统Resource  
    font.registerFont({  
      familyName: $r('app.string.mediumFamilyName'),  
      familySrc: $r('app.string.mediumFamilySrc')  
    })  
  
    // familySrc支持RawFile  
    font.registerFont({  
      familyName: 'mediumRawFile',  
      familySrc: $rawfile('font/medium.ttf')  
    })  
  }  
  
  build() {  
    Column() {  
      Text(this.message)  
        .align(Alignment.Center)  
        .fontSize(20)  
        .fontFamily('medium') // medium：注册自定义字体的名字（$r('app.string.mediumFamilyName')、'mediumRawFile'等已注册字体也能正常使用）  
        .height('100%')  
    }.width('100%')  
  }  
}  
    
```    
  
    
## getSystemFontList<sup>(10+)</sup>    
获取系统支持的字体名称列表。  
 **调用形式：**     
- getSystemFontList(): Array\<string>  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 系统的字体名列表。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import font from '@ohos.font';  
  
@Entry  
@Component  
struct FontExample {  
  fontList: Array<string> = new Array<string>();  
  build() {  
    Column() {  
      Button("getSystemFontList")  
        .width('60%')  
        .height('6%')  
        .onClick(()=>{  
          this.fontList = font.getSystemFontList()  
        })  
    }.width('100%')  
  }  
}  
    
```    
  
    
## getFontByName<sup>(10+)</sup>    
根据传入的系统字体名称获取系统字体的相关信息。  
 **调用形式：**     
- getFontByName(fontName: string): FontInfo  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fontName | string | true | 系统的字体名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FontInfo | 字体的详细信息 |  
