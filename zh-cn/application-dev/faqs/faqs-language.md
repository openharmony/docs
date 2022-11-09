# 开发语言常见问题

## TS语言在生成器函数中编译失败，有哪些使用限制

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

TS语言的使用在生成器函数中存在以下限制：

- 表达式仅允许在字符串(${expression})、if条件、ForEach的参数和组件的参数中使用；

- 这些表达式中的任何一个都不能导致任何应用程序状态变量（\@State、\@Link、\@Prop）的改变，否则会导致未定义和潜在不稳定的框架行为；

- 生成器函数内部不能有局部变量。

上述限制都不适用于事件处理函数（例如onClick）的匿名函数实现。

错误示例：

  
```
build() {
  let a: number = 1 // invalid: variable declaration not allowed
  Column() {
    Text('Hello ${this.myName.toUpperCase()}') // ok.
    ForEach(this.arr.reverse(), ..., ...) // invalid: Array.reverse modifies the @State array variable in place
  }
  buildSpecial()  // invalid: no function calls
  Text(this.calcTextValue()) // this function call is ok.
}
```

## 如何动态替换掉资源文件中的“%s”占位符

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

在应用中，通过"$r('app.string.xx')"的形式引用应用资源，$r的第二个参数可用于替换%s占位符。

  示例：
  
```
build() {
  //do something
  //引用的string资源,$r的第二个参数用于替换%s
  Text($r('app.string.entry_desc','aaa')) 
    .fontSize(100)
    .fontColor(Color.Black)
  //do something
}
```

## 如何读取Resource中的xml文件并转化为String类型

适用于：OpenHarmony SDK 3.2.2.5版本， API9 Stage模型

1. 通过resourceManager的RawFile接口获取Uint8Array格式数据。

2. 通过String.fromCharCode将Uint8Array格式数据转化为String类型。快快快

参考文档：[资源管理](../reference/apis/js-apis-resource-manager.md)

示例：

  
```
resourceManager.getRawFile(path, (error, value) => {
  if (error != null) {
    console.log("error is " + error);
  } else {
    let rawFile = value;
    let xml = String.fromCharCode.apply(null, rawFile)
  }
});
```

## 如何将Resource资源对象转成string类型

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

通过\@ohos.resourceManager模块 resourceManager.getString()方法获取字符串。

参考文档：[资源管理](../reference/apis/js-apis-resource-manager.md#getstring)

## class全局静态变量无法使用的问题

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

Page和Ability打包后会对import的对象分别形成两个不同的闭包，即打包出两个Global对象。因此，所引用的静态变量并不是同一对象，所以无法通过class静态变量方式定义全局变量。建议使用AppStorage进行全局变量管理。

参考文档：[应用程序的数据存储](../ui/ts-application-states-appstorage.md)

## Stage模型下如何获取资源

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

Stage模型支持了通过context获取resourceManager对象的方式，再调用其内部获取资源的接口，无需再导入包，此方式FA模型不适用。

示例：

  
```
const context = getContext(this) as any
context 
  .resourceManager
  .getString($r('app.string.entry_desc').id)
  .then(value => {
    this.message = value.toString()
})
```

## 如何实现页面加载前从接口获取数据

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

aboutToAppear函数中使用异步接口获取页面数据，使用\@State修饰变量，数据获取完成后根据变量自动刷新页面。

  
```
@Entry
@Component
struct Test6Page {
  // 数据获取成功，会自动刷新页面
  @State message: string = 'loading.....'
  aboutToAppear(){
    // 模拟异步接口获取数据
    setTimeout(()=>{
      this.message = 'new msg'
    },3000)
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## worker线程与主线程是否运行在相同的全局上下文中

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

worker线程与主线程不在同一个上下文中，它们使用数据通信的方式交互。

## OpenHarmony上url编码使用哪个接口

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

使用全局函数encodeURI进行编码，使用decodeURI进行解码。例如空格字符，编码后为%20。

## OpenHarmony有解析xml的接口吗

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

使用ConvertXML的convert接口可以将xml文本解析为JavaScript对象。参考文档：[convertxml API文档](../reference/apis/js-apis-convertxml.md)

## 应用图标一多设置

适用于：OpenHarmony SDK3.0, API9 Stage模型

借助资源限定词能力，实现应用图标的一多配置，具体使用参考[资源使用](../key-features/multi-device-app-dev/resource-usage.md)

## Stage模型资源配置文件string.json文件中支持配置占位符吗

适用于：OpenHarmony SDK3.2.6.3, API9 Stage模型

资源配置文件string.json文件本身不支持配置占位符，可以在对应的页面中通过定义变量，在实际组件使用Resources和变量拼接的方式达到实现占位符的同等效果。

## OpenHarmony的systemTime.getCurrentTime()接口和JS的new Date().getTime()有区别吗

适用于：OpenHarmony SDK3.2.6.3, API9 Stage模型

systemTime.getCurrentTime(false)和new Date().getTime()一样，都是返回1970年1月1日至今的毫秒数；systemTime.getCurrentTime(true)返回1970年1月1日至今的纳秒数。两种方式都是系统时间。

## \@BuilderParam装饰器，组件传参问题

适用于：OpenHarmony SDK3.2.6.5, API9 Stage模型

对\@BuilderParam修饰的属性进行赋值时不带参数（如：content: this.specificParam），则此属性的类型需定义成无返回值的函数（如：\@BuilderParam content: () =&gt; void）；若带参数（如：callContent: this.specificParam1("111")），则此属性的类型需定义成any（如：\@BuilderParam callContent: any;），具体用法请参考[BuilderParam](../ui/ts-component-based-builder.md)。

## ArkTS如何把string转成byte数组

适用于：所有版本

参考如下代码实现，示例：

  
```
function stringToByte(str) {
  var bytes = new Array();
  var len,c;
  len = str.length;
  for(var i = 0;i<len;i++) {
    c = str.charCodeAt(i);
    if( c >= 0x010000 && c<= 0x10FFFF) {
      bytes.push(((c>>18) & 0x07) | 0xf0);
      bytes.push(((c>>12) & 0x3F) | 0x80);
      bytes.push(((c>>6) & 0x3f) | 0x80);
      bytes.push((c & 0x3F) | 0x80);
    } else if(c >= 0x000800 && c<= 0x00FFF){
      bytes.push(((c>>12) & 0x07) | 0xf0);
      bytes.push(((c>>6) & 0x3F) | 0x80);
      bytes.push((c & 0x3F) | 0x80);
    } else if(c >= 0x000800 && c<= 0x0007FF) {
      bytes.push(((c>>6) & 0x3F) | 0x80);
      bytes.push((c & 0x3F) | 0x80);
    } else {
      bytes.push(c & 0xFF)
    }
  }
  return bytes;
}
```

## 创建woker时报错“Too many wokers，the number of worker exceeds the maximum”如何处理

使用于：OpenHarmony SDK 3.2.6.5版本

这是因为每个应用的worker上限为7个，因此在worker使用完成后需要通过termiate方法释放worker。参考[worker开发指南](../reference/apis/js-apis-worker.md#terminate)。

## OpenHarmony推荐的多线程解决方案是什么

使用于：OpenHarmony SDK 3.2.6.5版本 API9 Stage模型

OpenHarmony推荐使用worker来处理多线程场景。

参考文档：[启动一个worker](../reference/apis/js-apis-worker.md)

## 使用\@Builder装饰包含自定义组件的方法与普通方法的区别是什么

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

\@Builder装饰的方法中使用了自定义组件，那么该方法每次被调用时，对应的自定义组件均会重新创建。

## 状态管理中\@Watch监听，数组内对象属性变化无法触发watch回调函数

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

使用\@Watch监听的对象，只能监听一层数据变化，多层次数据变更无法监听，同\@State状态管理机制一致

## 如何监听\@State深层数据变化

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

通过\@Observed配合\@ObjectLink装饰符实现。

参考文档：[Observed和ObjectLink数据管理](../ui/ts-other-states-observed-objectlink.md)

## 如何实现字符串编解码

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

通过util工具函数模块中的TextEncoder和TextDecoder进行解码。

参考文档：[TextEncoder](../reference/apis/js-apis-util.md#textencoder)、[TextDecoder](../reference/apis/js-apis-util.md#textdecoder)

## 如何导入和导出namespace命名空间

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

- namespace导出
    
  ```
  namespace Util{
      export function getTime(){
          return Date.now()
      }
  }
  export default Util
  ```

- namespace导入
    
  ```
  import Util from './util'
  Util.getTime()
  ```

## worker线程中能进行关系型数据库的操作吗

适用于：OpenHarmony SDK 3.2.5.5版本， API9 Stage模型

不支持。
