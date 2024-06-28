# ArkUI子系统Changelog

## cl.arkui.1 @Component和@ComponentV2修饰的自定义组件使用@Observed或者@ObservedV2修饰的类增加相关校验

**访问级别**

公开接口

**变更原因**

该变更为非兼容性变更。

1.在@Component修饰的自定义组件中通过@State、@Prop、@Link、@Provide、@Consume、@StorageLink、@StorageProp、LocalStorageLink、@LocalStorageProp修饰并使用@ObservedV2修饰的变量类型时，进行校验并输出错误信息。

简化示例如下：

```ts
@ObservedV2
class TmpA{}

@Entry
@Component
struct testTmp {
  @State value_string: TmpA = new TmpA()
  build() {
    Column(){

    }
  }
}
```

2.在@ComponentV2修饰的自定义组件中通过@Param、@Local、@Event、@Provide()、@Consumer()修饰并使用@Observed修饰的类时，进行校验并输出错误信息。

简化示例如下：

```ts
@Observed
class TmpA{}

@Entry
@ComponentV2
struct testTmp {
  @Param value_string: TmpA = new TmpA()
  build() {
    Column(){

    }
  }
}
```

3.以上的变量类型联合使用时，也会进行校验并输出错误信息。

示例如下：

```ts
@ObservedV2
class TmpA{}

@Observed
class TmpB{}

@Entry
@Component
struct testTmp {
  @State value_string: TmpA | TmpB = new TmpA()
  build() {
    Column(){

    }
  }
}
```

**变更影响**

变更前无报错。

变更后报错：

1.The type of the @State property can not be a class decorated with @ObservedV2.

2.The type of the @Param property can not be a class decorated with @Observed.

3.The type of the @State property can not be a class decorated with @ObservedV2.

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**适配指导**

如果开发者不按规范使用对应范式，则需按日志提示信息进行修改。