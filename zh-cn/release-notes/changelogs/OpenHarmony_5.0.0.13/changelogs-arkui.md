# ArkUI子系统变更说明

## cl.arkui.1@LocalStorageLink,@LocalStorageProp,@StorageProp(),@StorageLink,@Provide,@Consume,@Watch key值未定义校验

**访问级别**

公开接口

**变更原因**

该变更为兼容性变更。

**变更影响**

@LocalStorageLink,@LocalStorageProp,@StorageProp(),@StorageLink,@Provide,@Consume,@Watch key值不存在时，编译报错。

**变更发生版本**

从OpenHarmony SDK 5.0.0.13开始。

示例： 

```
@Entry
@Component
struct ComA {
  // ERROR: Cannot find name 'aaa'.
  @StorageProp(aaa) storageProp: string = 'storageProp';
  // ERROR: Cannot find name 'aaa'.
  @StorageLink(aaa) storageLink: string = 'storageLink';
  // ERROR: Cannot find name 'aaa'.
  @LocalStorageLink(aaa) localStorageLink: string = 'localStorageLink';
  // ERROR: Cannot find name 'aaa'.
  @LocalStorageProp(aaa) localStorageProp: string = 'localStorageProp';
  // ERROR: Cannot find name 'aaa'.
  @Provide(aaa) provide: string = 'provide';
  // ERROR: Cannot find name 'aaa'.
  @Consume(aaa) consume: number;
  // ERROR: Cannot find name 'aaa'.
  @State @Watch(aaa) watch: number = 0;

  build() {
  }
}

```

**适配指导**

 @LocalStorageLink,@LocalStorageProp,@StorageProp(),@StorageLink,@Provide,@Consume,@Watch key值需要准确定义。
 

 ## cl.arkui.2 装饰器状态变量编译转换变更的兼容性修改

**变更原因**

当装饰器变量是object，并且被a.b(this.object)形式调用，this.object不应该被ObservedObject.GetRawObject方法封装。

**变更影响**

该变更会存在，存量应用原先在方法内修改变量对象属性值不会触发UI组件更新，
而取消ObservedObject.GetRawObject方法封装后，修改对象属性值会触发UI组件更新。
示例中this.innerFuncVal被ObservedObject.GetRawObject方法封装后传递，在innerFunc方法内修改innerFuncVal对象属性的值，不会触发UI组件的更新，
但是当没有被ObservedObject.GetRawObject方法封装时，例如在globalFunc方法内修改globalFuncVal对象属性的值，则会触发UI组件的更新。
编译转换逻辑修改，不涉及开发者：
![GetRawObject](figures/demoImg.png)

示例：
```ts
class DateClass {
  count: number = 0;
}

function globalFunc(data: DateClass) {
  data.count += 1;
}

@Entry
@Component
struct GetRawObjectDemo {
  @State globalFuncVal: DateClass = new DateClass();
  @State innerFuncVal: DateClass = new DateClass();
  innerFunc(data: DateClass) {
    data.count += 1;
  }
  build() {
    Row() {
      Column() {
        Text(`globalFunc更新UI  count：${ this.globalFuncVal.count }`)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            globalFunc(this.globalFuncVal)
          })
        Text(`this.innerFunc更新UI  count：${ this.innerFuncVal.count }`)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            this.innerFunc(this.innerFuncVal)
          })
      }
    }
  }
}
```

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.13 版本开始。

**变更的接口/组件**

编译转换变更前：

![GetRawObject](figures/demoImgBeFor.png)

编译转换变更后：

![GetRawObject](figures/demoImgAfter.png)


**适配指导**

编译生成产物逻辑修改，不涉及适配。