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



## cl.arkui.2 @Watch删除key值只能为字符串校验

**访问级别**

公开接口。

**变更原因**

该变更为非兼容性变更。

**变更影响**

@Watch key值不是字符串时，不再校验。

**变更发生版本**

从OpenHarmony SDK 5.0.0.13 开始。

**示例：**

```
let watchString: string = 'onWatch';
@Entry
@Component
struct ComA {
  @State @Watch(watchString) watch: number = 0;
  onWatch() {

  }
  build() {

  }
}
```

**变更的接口/组件**

不涉及。

**适配指导**

 @Watch key值可以传入定义字符串key值变量或字符串，当传入自定义字符串key值变量时，需保证变量定义的字符串名称和监听函数名称一致，否则编译阶段不报错。