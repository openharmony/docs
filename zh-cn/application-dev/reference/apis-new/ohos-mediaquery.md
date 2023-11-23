# @ohos.mediaquery    
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import mediaquery from '@ohos.mediaquery'    
```  
    
## MediaQueryResult    
用于执行媒体查询操作。<span style="font-size: 14px; letter-spacing: 0px;">import mediaquery from 'pan>。    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| matches | boolean | true | true | 是否符合匹配条件。<br/> |  
| matches<sup>(10+)</sup> | boolean | true | true | 是否符合匹配条件。<br/> |  
| media | string | true | true | 媒体事件的匹配条件。<br/> |  
| media<sup>(10+)</sup> | string | true | true | 媒体事件的匹配条件。 |  
    
 **示例代码：**   
```ts    
import mediaquery from '@ohos.mediaquery'  
  
  
@Entry  
@Component  
struct MediaQueryExample {  
  @State color: string = '#DB7093'  
  @State text: string = 'Portrait'  
  listener = mediaquery.matchMediaSync('(orientation: landscape)')  
  
  onPortrait(mediaQueryResult:mediaquery.MediaQueryResult) {  
    if (mediaQueryResult.matches) {  
      this.color = '#FFD700'  
      this.text = 'Landscape'  
    } else {  
      this.color = '#DB7093'  
      this.text = 'Portrait'  
    }  
  }  
  
  aboutToAppear() {  
    let portraitFunc = (mediaQueryResult:mediaquery.MediaQueryResult):void=>this.onPortrait(mediaQueryResult)  // bind current js instance  
    this.listener.on('change', portraitFunc)  
  }  
  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {  
      Text(this.text).fontSize(24).fontColor(this.color)  
    }  
    .width('100%').height('100%')  
  }  
}  
    
```    
  
    
## MediaQueryListener    
媒体查询的句柄，并包含了申请句柄时的首次查询结果。  
    
### on('change')    
通过句柄向对应的查询条件注册回调，当媒体属性发生变更时会触发该回调。  
 **调用形式：**     
    
- on(type: 'change', callback: Callback\<MediaQueryResult>): void    
起始版本： 7    
- on(type: 'change', callback: Callback\<MediaQueryResult>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 必须填写字符串'change'。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 向媒体查询注册的回调 |  
    
### off('change')    
通过句柄向对应的查询条件去注册回调，当媒体属性发生变更时不在触发指定的回调。  
 **调用形式：**     
    
- off(type: 'change', callback?: Callback\<MediaQueryResult>): void    
起始版本： 7    
- off(type: 'change', callback?: Callback\<MediaQueryResult>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 必须填写字符串'change'。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要去注册的回调，如果参数缺省则去注册该句柄下所有的回调。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import mediaquery from '@ohos.mediaquery'  
    
  let listener = mediaquery.matchMediaSync('(orientation: landscape)'); //监听横屏事件  
  function onPortrait(mediaQueryResult:mediaquery.MediaQueryResult) {  
      if (mediaQueryResult.matches) {  
          // do something here  
      } else {  
          // do something here  
      }  
  }  
  listener.on('change', onPortrait) // 注册回调  
  listener.off('change', onPortrait) // 去注册回调  
    
```    
  
    
## matchMediaSync    
设置媒体查询的查询条件，并返回对应的监听句柄。<span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">import mediaquery from 'pan>。  
 **调用形式：**     
- matchMediaSync(condition: string): MediaQueryListener  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| condition | string | true | 媒体事件的匹配条件，具体可参考<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/ui/arkts-layout-development-media-query.md#%E8%AF%AD%E6%B3%95%E8%A7%84%E5%88%99">媒体查询语法规则</a>。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MediaQueryListener | 媒体事件监听句柄，用于注册和去注册监听回调。 |  
    
 **示例代码：**   
```ts    
import mediaquery from '@ohos.mediaquery'  
let listener:mediaquery.MediaQueryListener = mediaquery.matchMediaSync('(orientation: landscape)'); //监听横屏事件    
```    
  
