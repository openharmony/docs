# ArkUI子系统changelog

## cl.arkui.1 状态变量支持undefined和null

**变更影响**

API version 9：状态变量不支持undefined和null，当开发者给状态变量设置undefined或者null时，设置失败，即状态变量还是上一次的值。

API version 10：状态变量支持undefined和null，当开发者给状态变量设置undefined和null时，ArkUI框架会接受该值，即下一次读状态变量的是undefined和null，开发者要注意做判空保护。

**适配指导**

API version 9，当开发者给状态变量设置undefined时，设置无效，会导致开发者忽略对undefined的校验。
```ts
@Entry
@Component
struct Page3 {
  @State messages: string[] = ['Hello World']

  aboutToAppear() {
    // AppStorage里没有对应的key，返回undefined
    // API version 9：赋值不生效，ArkUI框架会拒绝undefined，this.messages还为其初始值['Hello World']
    // API version 10: 赋值生效，ArkUI框架会接受undefined，this.messages为undefined
    this.messages = AppStorage.Get("aProp")
  }

  build() {
    Row() {
      Column() {
        // API version 9: 应用没有crash，length为1 
        // API version 10：应用crash, Error message: Cannot read property length of undefined
        Text(`the messages length: ${this.messages.length}`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

对于上述情况，当每一次给状态变量赋值undefined和null时，需要对状态变量是否为undefined做校验。

```ts
Text(`the messages length: ${this.messages?.length}`)
```

API version 10，ArkUI框架增强对状态变量类型和初始化的校验，ArkUI框架会抛出运行时报错。具体有以下两种情况：
1. @Link必须被父组件初始化。

对于以下示例，当前会抛出运行时报错，提示开发者需要初始化@Link。
```ts
@Entry
@Component
struct Page3 {
  @State aProp: boolean = true

  build() {
    Row() {
      Column() {
        // crash: SynchedPropertyObjectTwoWayPU[9, 'linkProp']: constructor @Link/@Consume source variable in
        // parent/ancestor @Component must be defined. Application error!
        LinkChild()
        // 错误的用常规变量初始化linkProp，ArkUI框架无认为没有初始化，和上述一样的报错
        LinkChild({ aProp: false })
        // 正确，用状态变量this.aProp初始化@Link
        LinkChild({ aProp: this.aProp })
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Component
struct LinkChild {
  @Link aProp: boolean

  build() {
    Text(`linkProp: ${this.aProp}`)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
  }
}
```

2. 校验状态变量不支持的类型。

状态变量对于不支持的类型，比如function，抛出运行时报错来提示开发者。
```ts
@Entry
@Component
struct Page3 {
  // API version 10：运行时报错：@Component 'Page3': Illegal variable value error with decorated variable @State/@Provide 'functionProp': failed
  // validation: 'undefined, null, number, boolean, string, or Object but not function, attempt to assign value type: 'function', 
  @State functionProp: () => void = () => {
    console.info("123")
  }

  aboutToAppear() {
    this.functionProp()
  }

  build() {
    Row() {
      Column() {
        Text("hello")
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## cl.arkui.2 更新4.0.10.x sdk后，出现组件功能异常的适配指导
更新4.0.10.x sdk之后，如果设备未使用配套的镜像版本，应用代码中调用UI组件时，会无法正常显示。

**示例：**

```
@Entry
@Component
struct Index { // 自定义组件
  build() {
    Text('Hello, world') // 基础组件
  }
}
```

**变更影响**

更新4.0.10.x sdk之后，如果设备未使用配套的镜像版本，应用代码中调用UI组件时，
运行到设备上会出现`this.observeComponentCreation2 is not callable`的报错。

**关键的接口/组件变更**

不涉及。

**适配指导**

更新SDK配套的设备镜像。
