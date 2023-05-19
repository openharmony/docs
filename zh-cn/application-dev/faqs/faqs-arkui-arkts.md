# ArkTS语法使用常见问题

## ArkUI如何通过代码动态创建组件

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

ArkUI使用ArkTS声明式开发范式，开发者无法持有组件实例，在声明时通过渲染控制语法以及动态构建UI元素的方式，控制组件的创建。

**代码示例**

```
// 条件渲染语句创建组件
if(this.isTrue) {
  Text("创建文本组件").fontSize(30)
}
// 循环渲染语句创建组件
ForEach(this.nums,(item) => {
  Text(item + '').fontSize(30)
},item => JSON.stringify(item))
```

**参考链接**

[渲染控制语法](../quick-start/arkts-rendering-control-overview.md)

## 使用@Builder装饰器包含自定义组件的方法与普通方法的区别是什么

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

@Builder装饰的方法中使用了自定义组件，那么该方法每次被调用时，对应的自定义组件均会重新创建，普通方法中不使用@builder装饰，无法容纳自定义组件。

**参考链接**

[@BuilderParam](../quick-start/arkts-builderparam.md)

## 如何使用@BuilderParam装饰器进行组件传参

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

-   不带参数

    对@BuilderParam修饰的属性进行赋值时不带参数（如：content: this.specificParam），则此属性的类型需定义成无返回值的函数（如：@BuilderParam content: \(\) =\> void）。

-   带参数

    对@BuilderParam修饰的属性进行赋值时带参数（如：callContent: this.specificParam1\("111"\)），则此属性的类型需定义成any（如：@BuilderParam callContent: any）。


**参考链接**

[@BuilderParam](../quick-start/arkts-builderparam.md)

## 如何监听数组内对象属性变化

适用于：OpenHarmony 3.2 Beta5 API9 

**问题现象**

数组内存储对象示例，需要对对象的属性变化进行监听。

**解决措施**

通过@Observed配合@ObjectLink装饰符实现。@Observed用于类，@ObjectLink用于变量。

**代码示例**

1.  在类上使用@Observed。

    ```
    @Observed
    class ClassA {
      public name: string
      public c: number
      public id: number
    
      constructor(c: number, name: string = 'OK') {
        this.name = name
        this.c = c
      }
    }
    ```

2.  在组件变量使用@ObjectLink。

    ```
    @Component
    struct ViewA {
      label: string = 'ViewA1'
      @ObjectLink a: ClassA
    
      build() {
        Row() {
          Button(`ViewA [${this.label}] this.a.c= ${this.a.c} +1`)
            .onClick(() => {
              this.a.c += 1
            })
        }.margin({ top: 10 })
      }
    }
    ```


**参考链接**

[Observed和ObjectLink数据管理](../quick-start/arkts-observed-and-objectlink.md)

## 子组件使用@Link修饰成员变量时，如何通过父组件传值

适用于：OpenHarmony 3.2 Beta5 API 9 

**解决措施**

子组件使用@Link接受父组件的值时，需要使用'$'建立变量之间的引用关系。才能实现同步。

**代码示例**

\@Link语义是从'$'操作符引出，即\$isPlaying是this.isPlaying内部状态的双向数据绑定。当单击子组件PlayButton中的按钮时，\@Link变量更改，PlayButton与父组件中的Text和Button将同时进行刷新，同样地，当点击父组件中的Button修改this.isPlaying时，子组件PlayButton与父组件中的Text和Button也将同时刷新。

1.  在父组件使用\@State装饰器，传递数据使用\$符创建引用。

    ```
    @Entry
    @Component
    struct Player {
      @State isPlaying: boolean = false
      build() {
        Column() {
          PlayButton({ buttonPlaying: $isPlaying })
          Text(`Player is ${this.isPlaying ? '' : 'not'} playing`).fontSize(18)
          Button('Parent:' + this.isPlaying)
            .margin(15)
            .onClick(() => {
              this.isPlaying = !this.isPlaying
            })
        }
      }
    }
    
    
    ```

2.  在子组件使用\@Link接受数据。

    ```
    @Component
    struct PlayButton {
      @Link buttonPlaying: boolean
    
      build() {
        Column() {
          Button(this.buttonPlaying ? 'pause' : 'play')
            .margin(20)
            .onClick(() => {
              this.buttonPlaying = !this.buttonPlaying
            })
        }
      }
    }
    ```


**参考链接**

[@Link](../quick-start/arkts-link.md)

## 父组件如何与孙子组件进行状态同步

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

-   方式一（推荐）：使用@Provide和@Consume装饰器。在父组件使用@Provide，在孙子组件使用@Consume，可以实现父组件和孙子组件进行双向数据绑定。

-   方式二：使用@State和@Link装饰器。在父组件使用@State，在每一层子组件（子组件和孙子组件）都使用@Link。

**代码示例一**

1.  父组件中使用子组件，通过Provide提供reviewVote参数，供跨级传递给孙子组件。

    ```
    @Entry
    @Component
    struct Father{
      @Provide("reviewVote") reviewVotes: number = 0;
    
      build() {
        Column() {
          Son()
          Button(`Father: ${this.reviewVotes}`)
            ...
        }
      }
    }
    ```

2.  子组件中使用孙组件。

    ```
    @Component
    struct Son{
      build() {
        Column() {
          GrandSon()
        }
      }
    }
    ```

3.  孙子组件中使用Consume来接受reviewVote的参数。

    ```
    @Component
    struct GrandSon{
      @Consume("reviewVote") reviewVotes: number
    
      build() {
        Column() {
          Button(`GrandSon: ${this.reviewVotes}`)
            ...
        }.width('100%')
      }
    }
    ```


**代码示例二**

1.  父组件Father使用@State绑定数据reviewVote。

    ```
    @Entry
    @Component
    struct Father {
      @State reviewVotes: number = 0;
    
      build() {
        Column() {
          Son({reviewVotes:$reviewVotes})
          Button(`Father: ${this.reviewVotes}`)
            ...
        }
      }
    }
    ```

2.  子组件Son中使用@Link接受由父组件Father传递的参数reviewVote。

    ```
    @Component
    struct Son{
      @Link reviewVotes: number;
      build() {
        Column() {
          Grandson({reviewVotes:$reviewVotes})
        }
      }
    }
    
    
    ```

3.  孙子组件GrandSon使用@Link接受由Son组件传递的参数reviewVote。

    ```
    @Component
    struct Grandson{
      @Link reviewVotes: number;
    
      build() {
        Column() {
          Button(`Grandson: ${this.reviewVotes}`)
            ...
        }.width('100%')
      }
    }
    ```


## Js如何定义callback函数

适用于：OpenHarmony 3.2 Beta5 API 9 

**解决措施**

定义个callback函数的样例，**示例如下：**

1.  定义回调函数

    ```
    // 页面中定义个2个参数,空返回的callback函数
    myCallback: (a:number,b:string) => void
    ```

2.  在使用时进行初始化赋值

    ```
    aboutToAppear() {
      // callback函数初始化
      this.myCallback= (a,b)=>{
        console.info(`handle myCallback a=${a},b=${b}`)
      }}
    ```


## 组件需要多次更新时如何优化性能

适用于：OpenHarmony 3.2 Beta5 API 9 

**解决措施**

使用状态管理模块，目前已经支持最小化更新，当数据依赖变化时，不再是重新刷新整个自定义组件，而是只更新依赖数据的视图内容。

## 对象中函数的this如何指向外层

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

通过箭头函数实现。

**代码示例**

```
const obj = {
  start:() => {
    return this.num
  }
}
```

## 如何实现页面加载前从接口获取数据

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

页面生命周期相关问题，在页面渲染前从接口获取数据，渲染时将数据渲染到页面上。

**解决措施**

在声明周期函数aboutToAppear中使用异步接口获取页面数据，数据变量使用@State修饰，数据获取完成后根据变量自动刷新页面。

**代码示例**

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

## 如何将传感器的数据实时显示在UI的Text中

适用于：Openharmony 3.2 Beta5 API9

**解决措施**

传感器返回数据类型为double，可将double转为string，再显示在text中。

## 如何监听屏幕旋转

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

屏幕旋转可使用媒体查询接口进行监听。

```
import mediaquery from '@ohos.mediaquery'
let listener = mediaquery.matchMediaSync('(orientation: landscape)'); //监听横屏事件
function onPortrait(mediaQueryResult) {
  if (mediaQueryResult.matches) {
   // do something here
  } else {
   // do something here
  }
}
listener.on('change', onPortrait) // 注册回调
listener.off('change', onPortrait) // 去注册回调
```

**参考链接**

[媒体查询](../reference/apis/js-apis-mediaquery.md)

## 创建的单例换了页面后不生效问题

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

单例只有在同一个流程中才有效，换了页面后之前的实例都全是undefined。

**解决措施**

对于每个Page都会生成一个js文件，定义的单例会在每个js中都生成一份，所以单例的作用范围只是Page的范围。

如果想共享一个实例，创建范围需要提升至UIAbility或者App级别。

## 如何将时间格式的字符串string转换为Date对象

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

如果字符string满足格式“yyyy-MM-dd”格式，则可直接使用函数new Date\("yyyy-MM-dd"\)来获取对应的Date对象。

```
new Date("2021-05-23");
new Date("2020/2/29");
new Date("2020-14-03");
new Date("14-02-2021");
```

其他格式字符串可使用new Date\(year:number,month:number,day?:number,hour?:number,mintue?:number,second?:number,ms?:number\)方法来获取Date对象。

```
// 根据参数创建日期的语法：
new Date(yearValue, IndexOfMonth, dayValue, hours, minutes, seconds)
```

其中每一个参数换算为对应时间参数传入即可。

-   yearValue：应符合 ISO 8061 YYYY 格式。例如 2021。如果我们以 YY 格式指定一个值，它将会被错误地接受。例如，仅将 2021 提到 21 会被认为是 1921 年而不是 2021 年。
-   IndexOfMonth：从索引 0 开始。因此，从 Month 值中减去 1。例如，对于 3 月，该值为 3，但 monthIndex 将为 2（即 3-1 = 2）。本月指数通常应在 0-11 范围内
-   dayValue：表示一个月中的某天。它应在 1-31 范围内，具体取决于一个月中的天数。例如：对于 21-05-2021，日期值为 21
-   hours：一天中的小时。例如 10 点。
-   minutes：过去一个小时的分钟数
-   seconds：保留超过一分钟的秒数。

## ArkTS如何把string转为byte数组

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

参考如下代码实现，示例：

```
stringToArray(str:string) {
  var arr = [];
  for(var i = 0,j = str.length;i<j;++i) {
 arr.push(str.charCodeAt(i))
  }
  return arr;
}
```

## ArkTS如何实现字符串编解码

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

通过util工具函数模块中的TextEncoder和TextDecoder进行解码。

**参考链接**

[TextEncoder](../reference/apis/js-apis-util.md#textencoder)、[TextDecoder](../reference/apis/js-apis-util.md#textdecoder)

## 如何导入和导出namespace命名空间

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

通过export和import导入导出

-   namespace导数据库出

    ```
    namespace Util{
        export function getTime(){
            return Date.now()
        }
    }
    export default Util
    ```

-   namespace导入

    ```
    import Util from './util'
    Util.getTime()
    ```

## worker线程中能否进行关系型数据库的操作

适用于：Openharmony 3.2 Beta5 API 9

当前不支持将UI主线程中的rdb数据库对象发送给Worker线程后进行操作。Worker线程中使用rdb数据库，需要重新获取rdb数据库的对象。

## 如何获取应用resource目录下的文件

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

-   方式一：使用\$r或者\$rawfile访问。适合静态访问，程序运行时不改变资源路径。
-   方式二：使用ResourceManage访问。适合动态访问，程序运行时可动态改变资源路径。

**参考链接**

[资源访问](../quick-start/resource-categories-and-access.md)与[资源管理](../reference/apis/js-apis-resource-manager.md#getstring)

## XML格式如何转为JSON格式

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

服务端返回的数据是通过base64编码后XML格式，需要转为JSON格式进行后续的处理。

**解决措施**

使用util工具中的base64相关接口进行解码操作，然后使用convertxml组件解析XML格式数据。

**代码示例**

```
import convertxml from '@ohos.convertxml';
import util from '@ohos.util';

@Entry
@Component
struct Faq_4_31 {
  @State message: string = 'base64转json'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            /* 原数据，GBK编码
            <?xml version="1.0" encoding="GBK"?>
            <data>
            <asset_no>xxxxx</asset_no>
            <machine_sn>xxxx</machine_sn>
            <bios_id>xxxx</bios_id>
            <responsible_emp_name><![CDATA[xxxx]]></responsible_emp_name>
            <responsible_account><![CDATA[xxxx xxxx]]></responsible_account>
            <responsible_emp_no>xxxx</responsible_emp_no>
            <responsible_dept><![CDATA[xxxx]]></responsible_dept>
            <user_dept><![CDATA[xxxx]]></user_dept>
            <user_name><![CDATA[xxx]]></user_name>
            <cur_domain_account>xxxx</cur_domain_account>
            <asset_loc><![CDATA[--]]></asset_loc>
            <asset_loc_cur><![CDATA[]]></asset_loc_cur>
            <asset_type>1</asset_type>
            <asset_use>For Outsourcing Staff/xxxx</asset_use>
            <overdue_date></overdue_date>
            <asset_status>xxxx</asset_status>
            <asset_period>xxxx</asset_period>
            <license></license>
            </data>
             */
            let src = 'PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iR0JLIj8+CjxkYXRhPgo8YXNzZXRfbm8+eHh4eHg8L2Fzc2V0X25vPgo8bWFjaGluZV9zbj54eHh4PC9tYWNoaW5lX3NuPgo8Ymlvc19pZD54eHh4PC9iaW9zX2lkPgo8cmVzcG9uc2libGVfZW1wX25hbWU+PCFbQ0RBVEFbeHh4eF1dPjwvcmVzcG9uc2libGVfZW1wX25hbWU+CjxyZXNwb25zaWJsZV9hY2NvdW50PjwhW0NEQVRBW3h4eHggeHh4eF1dPjwvcmVzcG9uc2libGVfYWNjb3VudD4KPHJlc3BvbnNpYmxlX2VtcF9ubz54eHh4PC9yZXNwb25zaWJsZV9lbXBfbm8+CjxyZXNwb25zaWJsZV9kZXB0PjwhW0NEQVRBW3h4eHhdXT48L3Jlc3BvbnNpYmxlX2RlcHQ+Cjx1c2VyX2RlcHQ+PCFbQ0RBVEFbeHh4eF1dPjwvdXNlcl9kZXB0Pgo8dXNlcl9uYW1lPjwhW0NEQVRBW3h4eF1dPjwvdXNlcl9uYW1lPgo8Y3VyX2RvbWFpbl9hY2NvdW50Pnh4eHg8L2N1cl9kb21haW5fYWNjb3VudD4KPGFzc2V0X2xvYz48IVtDREFUQVstLV1dPjwvYXNzZXRfbG9jPgo8YXNzZXRfbG9jX2N1cj48IVtDREFUQVtdXT48L2Fzc2V0X2xvY19jdXI+Cjxhc3NldF90eXBlPjE8L2Fzc2V0X3R5cGU+Cjxhc3NldF91c2U+Rm9yIE91dHNvdXJjaW5nIFN0YWZmL3h4eHg8L2Fzc2V0X3VzZT4KPG92ZXJkdWVfZGF0ZT48L292ZXJkdWVfZGF0ZT4KPGFzc2V0X3N0YXR1cz54eHh4PC9hc3NldF9zdGF0dXM+Cjxhc3NldF9wZXJpb2Q+eHh4eDwvYXNzZXRfcGVyaW9kPgo8bGljZW5zZT48L2xpY2Vuc2U+CjwvZGF0YT4='
            let base64 = new util.Base64Helper();
            // base解码
            let src_uint8Array = base64.decodeSync(src);
            // 解码为utf-8的字符串
            let textDecoder = util.TextDecoder.create("utf-8",{ignoreBOM: true})
            let src_str = textDecoder.decodeWithStream(src_uint8Array)
            //替换encoding字段
            src_str = src_str.replace("GBK","utf-8")
            console.log('Test src_str: ' + JSON.stringify(src_str));
            // 转换 xml-> json
            let conv = new convertxml.ConvertXML();
            let options = {trim : false, declarationKey:"_declaration",
              instructionKey : "_instruction", attributesKey : "_attributes",
              textKey : "_text", cdataKey:"_cdata", doctypeKey : "_doctype",
              commentKey : "_comment", parentKey : "_parent", typeKey : "_type",
              nameKey : "_name", elementsKey : "_elements"}
            let src_json = JSON.stringify(conv.convertToJSObject(src_str, options));
            console.log('Test json: ' + JSON.stringify(src_json));
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 在生成器函数中编译TS语言有哪些使用限制

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

TS语言的使用在生成器函数中存在以下限制：

-   表达式仅允许在字符串\(\$\{expression\}\)、if条件、ForEach的参数和组件的参数中使用。
-   这些表达式中的任何一个都不能导致任何应用程序状态变量（@State、@Link、@Prop）的改变，否则会导致未定义和潜在不稳定的框架行为。
-   生成器函数内部不能有局部变量。

上述限制都不适用于事件处理函数（例如onClick）的匿名函数实现。

## 如何设置一张图片上面四个角都分别有一个角标

适用于 OpenHarmony 3.2 Beta5

**问题现象**

应用需求，在一张图片上面四个角分别设置一个角标。

**解决措施**

可以使用绝对定位，设置元素锚点相对于父容器顶部起点的偏移位置。在布局容器中，设置该属性不影响父容器布局。

示例：

```
@Entry
@Component
struct PositionExample2 {
  build() {
    Column({ space: 20 }) {
      Stack({ alignContent: Alignment.TopStart }) {
        Row()
          .size({ width: '100', height: '100' })
          .backgroundColor(0xdeb887)
        Image($r('app.media.app_icon'))
          .size({ width: 25, height: 25 })
          .markAnchor({ x: 0, y: 0 })
        Image($r('app.media.app_icon'))
          .size({ width: 25, height: 25 })
          .markAnchor({ x: 25, y: 25 })
          .position({ x: '100%', y: '100%' }) 
      }.margin({ top: 25 }).width('100').height('100')
    }
    .width('100%').margin({ top: 25 })
  }
}
```

## util.generateRandomUUID参数问题

适用于 OpenHarmony 3.2 Beta5

**解决措施**

generateRandomUUID底层使用Node.js crypto.randomUUID\(\)接口，传递参数为false时会生成uuid，并缓存到系统里，参数为true时使用系统已缓存的UUID。

参考文档：[util.generateRandomUUID](../reference/apis/js-apis-util.md#utilgeneraterandomuuid9)

## worker线程与主线程是否运行在相同的全局上下文中

适用于 OpenHarmony 3.2 Beta5

**解决措施**

worker线程与主线程不在同一个上下文中，它们使用数据通信的方式交互。

**参考链接**

worker：[启动一个Worker](../reference/apis/js-apis-worker.md)

## 应用图标一多设置

适用于：OpenHarmony 3.2 Beta5 API 9

**问题现象**

希望可以按照设备的不同类型，显示相应的应用图标

**解决措施**

借助资源限定词能力，可以实现应用图标的一多配置

**示例代码**

1.创建资源目录，并在资源目录中添加资源文件，以Tablet为例，在src/main/resources下创建tablet资源目录，在tablet目录下创建media资源文件夹

```
├─base
│  ├─element
│  ├─media
│  └─profile
├─rawfile
├─tablet
│  ├─element
│  └─media
```

2.在1中创建的media文件夹下添加设备类型为tablet时希望显示的图标文件，在UI界面进行引用

```
@Entry @Component struct Index { build() {
   Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
     Text($r("app.string.my_string"))
       .fontSize($r("app.float.my_float"))
       .fontColor($r("app.color.my_color"))
     Image($r("app.media.my_image"))
       .width(100)
       .height(100)
   }
   .width('100%')
   .height('100%') } }
```

**参考链接**

[资源使用](../key-features/multi-device-app-dev/resource-usage.md)

## 调用方法的时候，如何解决方法内部的this变成undefined？ 

适用于：OpenHarmony SDK 3.2，API 9

**问题现象**

ArkTS里的this指向

**解决措施**

方式一：在调用方法的时候加上.bind\(this\)；

方式二：使用箭头函数。

## OpenHarmony的systemTime.getCurrentTime\(\)接口和JS的new Date\(\).getTime\(\)有区别吗

适用于：OpenHarmony SDK 3.2，API 9

**解决措施**

systemTime.getCurrentTime\(false\)和new Date\(\).getTime\(\)一样，都是返回1970年1月1日至今的毫秒数；systemTime.getCurrentTime\(true\)返回1970年1月1日至今的纳秒数。两种方式都是系统时间。

## 如何实现类似js中的slot插槽功能

适用于：OpenHarmony SDK 3.2，API 9

**解决措施**

适用于：OpenHarmony SDK3.2.5.5, API9 Stage模型

该功能在ArkTS中使用@Build和@BuilderParam方式来实现，具体可参考文档：[@BuilderParam：引用@Builder函数](../quick-start/arkts-builderparam.md)

## 加上lineHeight，Text垂直不居中的原因

适用于 OpenHarmony 3.2 Beta5  API 9

**原因分析**

Text组件不用设置lineHeight属性，默认就是居中的。绘制文本是从底部开始绘制的，设置合适的lineHeight可以让文本有居中效果，但如果lineHeight设置的过高，文本就会显得偏下一些，一般lineHeight属性用来联合padding属性调整Text内的上下行间距。

**参考链接**

[Text](../reference/arkui-ts/ts-basic-components-text.md#示例1)

## SideBarContainer如何设置controlButton属性

适用于 OpenHarmony 3.2 Beta5，API9

**解决措施**

示例代码：

```
@Entry
@Component
struct SideBarContainerExample {
  normalIcon : Resource = $r("app.media.icon")
  selectedIcon: Resource = $r("app.media.icon")
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1

  build() {
    SideBarContainer(SideBarContainerType.Embed)
    {
      Column() {
        ForEach(this.arr, (item, index) => {
          Column({ space: 5 }) {
            Image(this.current === item ? this.selectedIcon : this.normalIcon).width(64).height(64)
            Text("Index0" + item)
              .fontSize(25)
              .fontColor(this.current === item ? '#0A59F7' : '#999')
              .fontFamily('source-sans-pro,cursive,sans-serif')
          }
          .onClick(() => {
            this.current = item
          })
        }, item => item)
      }.width('100%')
      .justifyContent(FlexAlign.SpaceEvenly)
      .backgroundColor('#19000000')


      Column() {
        Text('SideBarContainer content text1').fontSize(25)
        Text('SideBarContainer content text2').fontSize(25)
      }
      .margin({ top: 50, left: 20, right: 30 })
    }
    .sideBarWidth(150)
    .minSideBarWidth(50)
    .controlButton({left:32,
      top:32,
      width:32,
      height:32, 
      icons:{shown: $r("app.media.icon"),
        hidden: $r("app.media.icon"),
        switching: $r("app.media.icon")}})
    .maxSideBarWidth(300)
    .onChange((value: boolean) => {
      console.info('status:' + value)
    })
  }
}
```

## Grid如何实现拖拽功能

适用于 OpenHarmony 3.2 Beta5 ，API9

**解决措施**

1.  grid组件下设置属性editMode\(true\)设置Grid是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部GridItem
2.  在[onItemDragStart](../reference/arkui-ts/ts-container-grid.md#事件)回调中设置拖拽过程中显示的图片
3.  在[onItemDrop](../reference/arkui-ts/ts-container-grid.md#事件)中获取拖拽起始位置，和拖拽插入位置，在[onDrag](../reference/arkui-ts/ts-universal-events-drag-drop.md#事件)回调中完成交换数组位置逻辑。示例代码：

    ```
    @Entry
    @Component
    struct GridExample {
      @State numbers: String[] = []
      scroller: Scroller = new Scroller()
      @State text: string = 'drag'
    
      @Builder pixelMapBuilder() { //拖拽过程样式
        Column() {
          Text(this.text)
            .fontSize(16)
            .backgroundColor(0xF9CF93)
            .width(80)
            .height(80)
            .textAlign(TextAlign.Center)
        }
      }
    
      aboutToAppear() {
        for (let i = 1;i <= 15; i++) {
          this.numbers.push(i + '')
        }
      }
    
      changeIndex(index1: number, index2: number) { //交换数组位置
        [this.numbers[index1], this.numbers[index2]] = [this.numbers[index2], this.numbers[index1]];
      }
    
      build() {
        Column({ space: 5 }) {
          Grid(this.scroller) {
            ForEach(this.numbers, (day: string) => {
              GridItem() {
                Text(day)
                  .fontSize(16)
                  .backgroundColor(0xF9CF93)
                  .width(80)
                  .height(80)
                  .textAlign(TextAlign.Center)
                  .onTouch((event: TouchEvent) => {
                    if (event.type === TouchType.Up) {
                      this.text = day
                    }
                  })
              }
            })
          }
          .columnsTemplate('1fr 1fr 1fr')
          .columnsGap(10)
          .rowsGap(10)
          .onScrollIndex((first: number) => {
            console.info(first.toString())
          })
          .width('90%')
          .backgroundColor(0xFAEEE0)
          .height(300)
          .editMode(true) //设置Grid是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部GridItem
          .onItemDragStart((event: ItemDragInfo, itemIndex: number) => { //第一次拖拽此事件绑定的组件时，触发回调。
            return this.pixelMapBuilder() //设置拖拽过程中显示的图片。
          })
          .onItemDrop((event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => { //绑定此事件的组件可作为拖拽释放目标，当在本组件范围内停止拖拽行为时，触发回调。
            console.info('beixiang' + itemIndex + '', insertIndex + '') //itemIndex拖拽起始位置，insertIndex拖拽插入位置
            this.changeIndex(itemIndex, insertIndex)
          })
        }.width('100%').margin({ top: 5 })
      }
    }
    ```


## 使用什么接口进行url编码

适用于：OpenHarmony 3.2 Beta5，API9

**解决措施**

使用全局函数encodeURI进行编码，使用decodeURI进行解码。例如空格字符““，编码后为%20。

```
let a = encodeURI(" ")
console.log(a) // %20
```

## 如何解析xml

适用于：OpenHarmony 3.2 Beta5，API9

**解决措施**

使用ConvertXML的convert接口可以将xml文本解析为JavaScript对象。

参考文档：[转换xml](../reference/apis/js-apis-convertxml.md)

## 使用Styles装饰器，编译报错.stateStyles doesn't conform standard

适用于：OpenHarmony 3.2 Beta5，API9

**原因分析**

Styles装饰器内部只支持通用属性，使用了非通用属性作为Style的代码

**解决措施**

去掉非通用属性，或者使用Builder来提取公共组件。

## Radio组件\$\$双向绑定

适用于：OpenHarmony 3.2 Beta5，API9

**解决措施**

Radio组件使用\$\$绑定的变量变更时，仅渲染当前组件，提高渲染速度。

当Radio组件的状态发生改变时，不会自动修改绑定的变量。

参考：[内置组件双向绑定](../quick-start/arkts-two-way-sync.md)

## ForEach组件在真机上无法执行

适用于：OpenHarmony 3.2 beta5，API9

**问题现象**

ForEach组件预览器可以正常执行，但在真机上无法执行。

**原因分析**

真机上系统版本大于等于3.2beta5版本，真机会默认开启最小化更新策略。

旧版IDE默认没有开启最小化更新，导致组件运行异常。

**解决措施**

module.json5添加"metadata"配置项：

```
{
  "module": {
    "metadata": [
      {
        "name": "ArkTSPartialUpdate",
        "value": "true"
      }
  }
}
```
