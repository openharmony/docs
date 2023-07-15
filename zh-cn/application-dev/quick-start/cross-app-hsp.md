# 应用间HSP开发指导

应用间`HSP`用于不同应用间的代码、资源共享。
应用间`HSP`的宿主应用是一种特殊状态的应用，只能由一个`HSP`组成，不会独立运行在设备上，而是被普通应用模块的依赖项引用。当普通应用运行时，通过动态调用的方式使用应用间`HSP`提供的能力，从而实现应用自身所需要的功能。

## 注意事项
1. 应用间`HSP`的代码会运行在开发者应用的进程中，调用相关代码时，需要做好异常捕获与容错处理，防止由于应用间`HSP`功能异常导致的稳定性问题。
2. 一个应用可以同时依赖多个应用间`HSP`。
3. 应用间`HSP`会影响开发者应用自身的启动时间，依赖过多的应用间`HSP`可能会导致启动时延发生明显的劣化，建议将依赖的数目控制在16个以内。
4. 应用间`HSP`安装时需要对特权权限进行校验，如果想要开发应用间`HSP`，需要配置allowAppShareLibrary应用特权，具体配置方式参考[应用特权配置指南](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)。

## 应用间HSP的使用
应用间HSP会分为两部分对外发布：

一部分为[HAR](har-package.md)，`HAR`包中不会包含具体的功能实现代码，而仅仅包含导出的对象与方法，所以体积很小。应用开发者将`HAR`包集成到自身的工程中，然后就可以通过调用`HAR`包中提供的对象与方法完成自身的应用功能。

另外一部分为HSP，这部分为应用间`HSP`的具体实现，里面包含js/ts代码、C++库、资源和配置文件。这部分会上架到应用市场或者集成到系统版本中。

### 集成应用间HSP的HAR
`HAR`中的`index.ets`文件是应用间`HSP`导出的声明文件的入口，所有需要导出的接口，统一在`index.ets`文件中定义。`index.ets`文件路径如下：
```
liba
├── src
│   └── main
│       ├── ets
│       │   ├── pages
│       │   └── index.ets
│       ├── resources
│       └── module.json5
└── oh-package.json5
```
对外暴露的接口，需要在入口文件`index.ets`中声明：

`index.ets`内容样例如下：

```ts
// liba/src/main/ets/index.ets
export { hello, foo1, foo2, nativeMulti, UIComponent } from './ui/MyUIComponent'
```
其中UIComponent为导出的ArkUI组件，`hello()`、`foo1()`与`foo2()`为应用间HSP导出的ts方法，`nativeMulti()`方法为应用间HSP导出的native方法。具体实现如下：
#### **ArkUI组件**
在`HSP`中ArkUI组件的具体实现样例：
```ts
// liba/src/main/ets/ui/MyUIComponent.ets
@Component
export struct UIComponent {
  @State message: string = 'Hello World'
  build() {
    Column() {
      Text(this.message)
        .fontSize(32)
        .padding(8)
        .fontColor(0xffffff)
        .backgroundColor(0x0000ff)
    }.padding(8).width('100%')
  }
}
```

#### **ts方法**
在`HSP`中ts方法的具体实现：
```ts
// liba/src/main/ets/ui/MyUIComponent.ets
export function hello(name: string): string {
  return "hello + " + name;
}

export function foo1() {
  return "foo1";
}

export function foo2() {
  return "foo2";
}

```
#### **native方法**
在`HSP`中也可以包含`C++`编写的`so`。对于`so`中的`native`方法，`HSP`通过间接的方式导出，以导出`libnative.so`的乘法接口`multi`为例：

```ts
// liba/src/main/ets/ui/MyUIComponent.ets
import native from "libnative.so"

export function nativeMulti(a: number, b: number) {
    return native.multi(a, b);
}
```

### 使用HAR导出的能力
引用`HAR`前，需要先配置对`HAR`的依赖，配置方式可参考[文档](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/creating_har_api9-0000001518082393-V3#section611662614153)。`HAR`配置成功后，在配置模块的`module.json5`中会生成相关依赖项信息，如下所示：
```json
"dependencies": [
      {
        "bundleName": "com.share.liba",
        "moduleName": "liba",
        "versionCode": 10001
      }
]
```
其中`bundleName`为应用间`HSP`的`bundle`名称，`moduleName`为应用间`HSP`的模块名称，`versionCode`为应用间`HSP`的版本号。
#### **使用HAR中的ArkUI组件**
`HAR`的依赖配置成功后，可以引用`HAR`的ArkUI组件。ArkUI组件的导入方式与ts的导入方式一致，通过`import`引入`HAR`导出的ArkUI组件，示例如下所示：
``` ts
import { UIComponent } from 'liba'

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      // 引用HAR的ArkUI组件
      UIComponent()
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

#### **使用HAR中的ts方法**
通过`import`引用`HAR`导出的ts类和方法，示例如下所示：
``` ts
import { foo1 } from 'liba'
import { foo2 } from 'liba'

@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('Button')
          .onClick(()=>{
            // 引用HAR的ts方法
            foo1();
            foo2();
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
#### **使用HAR中的native方法**
通过`import`引用`HAR`导出的native方法，示例如下所示：
``` ts
import { nativeMulti } from 'liba'

@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('Button')
          .onClick(()=>{
            // 引用HAR的native方法
            nativeMulti();
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 应用间HSP的分发方式（仅对系统应用开放）
应用间`HSP`由于并未直接完整的集成到开发者应用中去，所以需要提前预置在系统版本中或者随开发者应用同步安装到设备上，主要有以下两种形式：
1. 随系统发布，部分常用应用间`HSP`会预置在系统版本中。
2. 随应用发布，即用户在应用市场下载应用时，如果应用依赖了一个或者多个应用间`HSP`，同时设备上没有安装这个其依赖的应用间`HSP`时，应用市场会为用户同时下载普通应用以及其依赖的应用间`HSP`。从而保证普通应用能够正常使用共享库的功能。

### 应用间HSP的调试方式
开发者本地调试应用间`HSP`相关的功能时，可能并不具备上述分发的条件，此时可以通过`bm`相关指令本地完成应用间`HSP`的分发，主要步骤如下：
1. 获取到应用间`HSP`的安装包。
2. 通过`bm`指令先安装应用间`HSP`的安装包。
```
bm install -s sharebundle.hsp
```
3. 通过`bm`指令后安装开发者自身的应用`hap`。
```
bm install -p feature.hap
```
4. 启动开发者自身的应用，调试相关功能。

**注意**：步骤2和步骤3不可以颠倒，否则会由于缺少必要的应用间`HSP`导致开发者的应用安装失败。更多`bm`相关指令可以参考[文档](https://gitee.com/openharmony/bundlemanager_bundle_tool#bm工具命令)。
