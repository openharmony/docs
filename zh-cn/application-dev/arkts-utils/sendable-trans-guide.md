# Sendable对象改造实践
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

## 简介

本文介绍[TurboTrans](https://gitcode.com/openharmony-sig/turbo_trans)三方库中@hadss/turbo-trans-json（下文简称**TurboTransJSON**）与@hadss/turbo-trans-protobuf（下文简称**TurboTransProtobuf**）在ArkTS中操作Sendable对象的典型用法：

- 使用**TurboTransJSON**将JSON字符串反序列化为对象，并转换为Sendable对象在并发实例间传递，适用于将普通对象或JSON字符串转换为Sendable对象，详细可参考[使用TurboTransJSON序列化/反序列化并生成Sendable对象](#使用turbotransjson序列化反序列化并生成sendable对象)。
- 使用**TurboTransProtobuf**通过.proto生成@Sendable的消息类，并进行编码/解码，详细可参考[使用TurboTransProtobuf生成Sendable对象并编解码](#使用turbotransprotobuf生成sendable对象并编解码)。
- 使用TurboTransJSON或TurboTransProtobuf转换生成Sendable对象后，如果还需要绑定UI进行组件刷新的话，可以阅读[使用makeObserved将Sendable对象转换为可观察对象](#使用makeobserved将sendable对象转换为可观察对象)章节。

## 使用TurboTrans三方库操作Sendable对象

### 使用TurboTransJSON序列化/反序列化并生成Sendable对象

1. 环境配置

   引入TurboTrans三方库。

   <!-- @[transferableObject_jsonPlugin](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/TurboTrans/hvigor/hvigor-config.json5) -->
   
   ``` JSON5
     "dependencies": {
   // ...
       "@hadss/turbo-trans-json-plugin": "latest",
     },
   ```

   在工程目录或模块下使用ohpm方式安装三方库。

   ```shell
   ohpm install @hadss/turbo-trans-core @hadss/turbo-trans-json
   ```

   插件生效还需在工程根目录hvigorfile.ts添加相关插件配置。

   <!-- @[transferableObject_configPlugin](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/TurboTrans/hvigorfile.ts) --> 
   
   ``` TypeScript
   import { turboTransJsonPlugin } from '@hadss/turbo-trans-json-plugin';
   import { hvigor } from '@ohos/hvigor';
   import { appTasks } from '@ohos/hvigor-ohos-plugin';
   
   export default {
     system: appTasks, /* Built-in plugin of Hvigor. It cannot be modified. */
     plugins: [
       turboTransJsonPlugin(hvigor, {
         ignoreModuleNames: ['TurboTransCore' , 'TurboTransJSON',  'PerformanceBaseline','TurboTransProtobuf'], // 忽略的模块
         scanDir: ['src/main/ets'], // 扫描目录
         deserializationMode: 'performance', // 反序列化模式
       }),
     ]       /* Custom plugin to extend the functionality of Hvigor. */
   }
   ```


2. 定义可序列化模型。
   
   通过@Serializable装饰器标记需序列化的类，添加generateSendable属性，并利用`@SerialName()`完成属性的定制化配置，其中：
   
   - `@Serializable({ generateSendable: true })`：表示需要生成与该模型对应的Sendable类型与转换方法。
   - `@SerialName({ name: 'xxx' })`：将类属性与JSON字段名绑定。

     <!-- @[transferableObject_Layout](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/TurboTrans/entry/src/main/ets/turbotrans_JSON/layout.ets) --> 
     
     ``` TypeScript
     import { Serializable, SerialName } from '@hadss/turbo-trans-core';
     // ...
     
     @Serializable({ generateSendable: true})
     export class Layout {
       @SerialName({ name: 'type'})
       public type: string = '';
       @SerialName({ name: 'arr'})
       public arr: number[] = [];
     }
     
     @Sendable
     export class LayoutS {
       public type: string = '';
       public arr: collections.Array<number> = new collections.Array();
     }
     ```

3. 从JSON字符串反序列化为普通对象（TJSON.fromString）。

   使用`TJSON.fromString<Model>(jsonStr, Model)`从JSON字符串反序列化为普通对象，可用`ArkTSUtils.isSendable(obj)`进行校验。工程示例演示了两种输入来源，并在反序列化后继续将普通对象转换为Sendable对象，形成“JSON字符串 -> 普通对象 -> Sendable对象”的前半段链路。

   - testJSON1方法是将普通对象通过`JSON.stringify()`序列化为JSON字符串后，再将JSON字符串反序列化为普通对象，最后再转换为Sendable对象的过程。
   - testJSON2方法是将手写的JSON字符串反序列化为普通对象，然后再转换为Sendable对象的过程。

     <!-- @[transferableObject_testJSON](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/TurboTrans/entry/src/main/ets/turbotrans_JSON/test1.ets) --> 
     
     ``` TypeScript
     import { TJSON } from '@hadss/turbo-trans-json';
     import { Layout, LayoutS } from 'entry/ets/turbotrans_JSON/layout';
     import type { ITSerializable } from '@hadss/turbo-trans-json';
     import { ArkTSUtils } from '@kit.ArkTS';
     
     export function testJSON1(): LayoutS {
       let obj = new Layout();
       obj.type = 'Test';
       obj.arr = [3, 4];
       let str = JSON.stringify(obj);
       let layoutNormal = TJSON.fromString<Layout>(str, Layout);
       console.info('111 layout arr: ' + layoutNormal.arr);
       let layoutSendable = (layoutNormal as object as ITSerializable).toSendable();
       if (ArkTSUtils.isSendable(layoutSendable)) {
         console.info('expect layout from JSON string is Sendable');
       } else {
         console.error('test occur error');
       }
       let layoutS = layoutSendable as LayoutS;
       return layoutS;
     }
     
     export function testJSON2(): LayoutS {
       let layoutStr = '{"type":"Text","arr":[3,4]}';
       let layoutNormal = TJSON.fromString<Layout>(layoutStr, Layout);
       console.info('222 layout arr: ' + layoutNormal.arr);
       let layoutSendable = (layoutNormal as object as ITSerializable).toSendable();
       if (ArkTSUtils.isSendable(layoutSendable)) {
         console.info('expect layout from simple string is Sendable');
       } else {
         console.error('test occur error');
       }
       let layoutS = layoutSendable as LayoutS;
       return layoutS;
     }
     ```

4. 将普通对象转换为Sendable对象（toSendable）。

   当`generateSendable: true`生效后，构建产物中会生成`toSendable()`，将普通对象转换为Sendable对象。其关键点在于会对普通对象做必要的容器转换，例如把`number[]`转换为`collections.Array<number>`。以下代码为编译时工具自动生成的，文件位于entry/src/generated/ets/turbotrans_JSON目录下。

   ``` TypeScript
   import { collections } from '@kit.ArkTS';

   toSendable(): SendableLayout {
     const sendable = new SendableLayout();
   
     // 非构造函数属性赋值
     sendable.type = this.type;
     sendable.arr = new collections.Array(...this.arr);
   
     return sendable;
   }
   ```

   同时，生成的Sendable类型通常会提供`toOrigin()`，用于在需要继续按普通对象处理、复用原有逻辑或重新序列化时，将Sendable对象还原为普通对象。以下代码为编译时工具自动生成的，文件位于entry/src/generated/ets/turbotrans_JSON目录下。

   ``` TypeScript
   @Sendable
   export class SendableLayout implements lang.ISendable {
     public type: string = '';
     public arr: collections.Array<number> = new collections.Array();

     toOrigin(): Layout {
       const origin = new Layout();
       origin.type = this.type;
       origin.arr = new Array(...this.arr);
       return origin;
     }
   }
   ```
   
   JSON路径就形成了完整闭环：

   JSON字符串 -> `TJSON.fromString()` -> 普通对象 -> `toSendable()` -> Sendable对象 -> `toOrigin()` -> 普通对象。

### 使用TurboTransProtobuf生成Sendable对象并编解码

1. 环境配置

   引入TurboTrans三方库。

   ```ts
   "dependencies": {
       // ...
       "@hadss/turbo-trans-protobuf-plugin": "latest"
   },
   ```

   在工程目录或者模块下使用ohpm方式安装三方库。

   ```shell
   ohpm install @hadss/turbo-trans-protobuf
   ```

   插件生效还需要在工程根目录的hvigorfile.ts文件中添加相关插件配置。

   ```ts
   import { turboTransProtobufPlugin } from '@hadss/turbo-trans-protobuf-plugin';
   import { hvigor } from '@ohos/hvigor';
   import { appTasks } from '@ohos/hvigor-ohos-plugin';
   
   export default {
     system: appTasks, /* Built-in plugin of Hvigor. It cannot be modified. */
     plugins: [
       turboTransProtobufPlugin({
         saveDir: 'src/main/ets/protobuf', // 保存生成代码的目录
         ignoreModuleNames: ['TurboTransCore', 'PerformanceBaseline', 'TurboTransProtobufCommon'], // 忽略的模块
         sendable: true, // 是否开启sendable
         debug: false, // 是否开启debug
         scanDir: ['protobuf'], // 扫描目录
       }),
     ]       /* Custom plugin to extend the functionality of Hvigor. */
   }
   ```

2. 编写proto文件。

   .proto文件需要放置在工程根目录的hvigorfile.ts文件中turboTransProtobufPlugin插件配置的scanDir扫描目录下才能生效，如示例工程中.proto位于`entry/protobuf/test_pb.proto`。

   ```proto
   syntax = "proto3";
   
   message test_pb {
       int32 value_int32 = 1;
       int64 value_int64 = 2;
       uint32 value_uint32 = 3;
       uint64 value_uint64 = 4;
       sint32 value_sint32 = 5;
       sint64 value_sint64 = 6;
       fixed32 value_fixed32 = 7;
       fixed64 value_fixed64 = 8;
       sfixed32 value_sfixed32 = 9;
       sfixed64 value_sfixed64 = 10;
       float value_float = 11;
       double value_double = 12;
       bool value_bool = 13;
       string value_string = 14;
       bytes value_bytes = 15;
   }
   ```

3. 构建生成Sendable消息类。

   构建后，在工程根目录的hvigorfile.ts文件中turboTransProtobufPlugin插件配置的saveDir结果目录下生成Sendable消息类。如示例工程中会生成entry/src/main/ets/protobuf/test_pb.ets。

   - `test_pb.create()`：创建实例。
   - `test_pb.encode(message)`：将实例编码为ArrayBuffer。
   - `test_pb.decode(buffer)`：将二进制数据解码回test_pb。

4. 创建Sendable消息对象并进行编码与解码。

   使用生成类提供的encode/decode完成二进制序列化/反序列化并且解码后得到的消息对象仍可继续作为Sendable对象向后传递。test_pb经过编解码后仍然保留Sendable特性，因此也可以像JSON路径生成的Sendable对象一样，继续作为并发任务的返回值进入UI绑定流程。以下示例中testProtobuf方法先创建test_pb实例，再编码为二进制，最后解码回test_pb并校验其仍为Sendable对象。

   ```ts
   import { test_pb } from '../protobuf/test_pb'
   import { ArkTSUtils, collections } from '@kit.ArkTS';
   
   function testCreate() {
     const obj = test_pb.create();
     obj.value_int32 = 1;
     obj.value_int64 = 2;
     obj.value_uint32 = 3;
     obj.value_uint64 = 4;
     obj.value_sint32 = 5;
     obj.value_sint64 = 6;
     obj.value_fixed32 = 7;
     obj.value_fixed64 = 8;
     obj.value_sfixed32 = 9;
     obj.value_sfixed64 = 10;
     obj.value_float = 11;
     obj.value_double = 12;
     obj.value_bool = true;
     obj.value_string = `TestProtobuf_Success`;
     obj.value_bytes?.fill(13);
   
     if (ArkTSUtils.isSendable(obj)) {
       console.info("create a sendable object");
     }
   
     return obj;
   }
   
   function testencode(obj: test_pb) {
     return test_pb.encode(obj);
   }
   
   function testdecode(data: ArrayBuffer | collections.ArrayBuffer) {
     let obj = test_pb.decode(data);
     console.info(`expect value_int32 ${obj?.value_int32} = 1`);
     console.info(`expect value_double ${obj?.value_double} = 12`);
     if (ArkTSUtils.isSendable(obj)) {
       console.info("decode a sendable object");
     }
   }
   
   export function testProtobuf(): test_pb {
     let obj = testCreate();
     let buf = testencode(obj);
     if (buf) {
       testdecode(buf);
     }
     return obj;
   }
   ```

## 使用makeObserved将Sendable对象转换为可观察对象

使用[UIUtils.makeObserved()](../reference/apis-arkui/js-apis-stateManagement.md#makeobserved)方法可以将Sendable对象转换为可观察对象。

- 定义并发任务。
- 使用`taskpool.execute()`获取并发任务返回的Sendable对象，再通过`UIUtils.makeObserved()`转为可观察对象。
- 当可观察对象的属性发生变化时，绑定的UI组件会自动刷新显示。

### 定义并发任务

定义observeJSON1与observeJSON2并发任务

<!-- @[transferableObject_observeJSON](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/TurboTrans/entry/src/main/ets/pages/concurrentFunc.ets) -->

``` TypeScript
import { LayoutS } from '../turbotrans_JSON/layout';
import { testJSON1, testJSON2 } from '../turbotrans_JSON/test1';

@Concurrent
export function observeJSON1(): LayoutS {
  return testJSON1();
}

@Concurrent
export function observeJSON2(): LayoutS {
  return testJSON2();
}
```

定义observeProtobuf并发任务

``` TypeScript
import { testProtobuf } from '../turbotrans_protobuf/test1'

@Concurrent
export function observeProtobuf(): test_pb {
  return testProtobuf();
}
```

### 通过taskpool执行异步任务并将Sendable对象转换为可观察对象

`runTests()`中通过`taskpool.execute()`执行并发任务，拿到返回的Sendable对象后，再用`UIUtils.makeObserved()`包装为可观察对象并写回UI状态。这样数据链路就变成了“并发任务返回 -> 转换为可观察对象 -> 组件自动刷新”。

执行observeJSON1并发任务返回Sendable对象工程示例如下：

<!-- @[transferableObject_makeObserved](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/TurboTrans/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
runTests() {
  taskpool.execute(observeJSON1).then((res) => {
    this.layout = UIUtils.makeObserved(res as LayoutS);
  })
}
```

执行observeProtobuf并发任务返回Sendable对象工程示例如下：

``` TypeScript
runTestsPb() {
  taskpool.execute(observeProtobuf).then((res) => {
    this.pb = UIUtils.makeObserved(res as test_pb);
  })
}
```

### 创建UI组件实时观察Sendable对象属性变化

Index.ets中通过`@Local`状态保存任务返回值，再由Text组件绑定`pb.value_string`和`layout.type`。其中，pb存储的是observeProtobuf返回的Sendable对象（test_pb类型），layout存储的是observeJSON1返回的Sendable对象（LayoutS类型）。

observeJSON1返回的Sendable对象工程示例如下：

<!-- @[transferableObject_Text](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/TurboTrans/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { LayoutS } from '../turbotrans_JSON/layout';
import { taskpool } from '@kit.ArkTS';
import { observeJSON1 } from './concurrentFunc';
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local message: string = 'Hello World';
  // 替换成 pb: test_pb = test_pb.create(); 则用于observeProtobuf返回Sendable对象的场景
  @Local layout: LayoutS = new LayoutS();

  build() {
    Column() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
        .margin({ top: 20 })

      Button('运行TaskPool测试')
        .width('80%')
        .height(50)
        .margin({ top: 20, bottom: 20 })
        .onClick(() => {
          this.runTests();
        })
        .id('button')

      Scroll() {
        Column() {

          Text(`TestJSON: ${this.layout.type}`)
            .fontSize(24)
            .textAlign(TextAlign.Start)
            .backgroundColor(Color.White)
            .padding(10)
            .borderRadius(8)
            .margin({ bottom: 10 })
            .width('100%')
        }
        .width('100%')
        .padding(10)
      }
      .height('60%')
      .width('100%')
    }
    .height('100%')
    .width('100%')
    .padding(20)
    .backgroundColor('#F5F5F5')
  }

// ...
}
```
