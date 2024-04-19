# ArkUI子系统变更说明

## cl.arkui.1@LocalStorageLink,@LocalStorageProp,@StorageProp(),@StorageLink,@Provide,@Consume,@Watch key值未定义校验

**访问级别**

公开接口

**变更原因**

部分状态变量装饰器的key值在使用未定义的变量时并未被校验，不符合TS语法规则，为了匹配TS语法规则，需要对这些状态变量装饰器的key值启动语法校验。

涉及的装饰器包括：

@LocalStorageLink,@LocalStorageProp,@StorageProp,@StorageLink,@Provide,@Consume,@Watch。

**变更影响**

@LocalStorageLink,@LocalStorageProp,@StorageProp,@StorageLink,@Provide,@Consume,@Watch key值不存在时，编译报错。

该变更为非兼容性修改。

**起始API Level**

@LocalStorageLink：API9，

@LocalStorageProp：API9，

@StorageProp：API7，

@StorageLink：API7，

@Provide：API7，

@Consume：API7，

@Watch：API7。



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

 @LocalStorageLink,@LocalStorageProp,@StorageProp,@StorageLink,@Provide,@Consume,@Watch key值需要准确定义。

```
// test.ts
export let oneKey = 'string';
```



```

// index.ets
import { oneKey } from './test';
@Entry
@Component
struct ComA {
  @StorageProp(oneKey) storageProp: string = 'storageProp';
  @StorageLink(oneKey) storageLink: string = 'storageLink';
  @LocalStorageLink(oneKey) localStorageLink: string = 'localStorageLink';
  @LocalStorageProp(oneKey) localStorageProp: string = 'localStorageProp';
  @Provide(oneKey) provide: string = 'provide';
  @Consume(oneKey) consume: number;

  build() {
  }
}
```




## cl.arkui.2 AppStorage,LocalStorage,PersistentStorage支持undefined和null

**访问级别**

公开接口

**变更影响**

AppStorage,LocalStorage,PersistentStorage的API方法支持null和undefined作为入参。@StorageLink，@StorageProp，@LocalStorageLink，@LocalStorageProp装饰器支持null和undefined类型。

以@StorageLink为例，当前应用存在误用null和undefined作为初始值或目标值在AppStorage中保存的情况。在更改前的语义中，null和undefined作为初始值或目标值的调用并不会生效，并给出warning。在更改后的语义中，支持了使用null和undefined作为初始值或目标值在AppStorage中保存。该更改使得以下场景中，原有应用代码运行崩溃。

更改前

```ts
class PropA {
  num: number = 100;
}

AppStorage.setOrCreate("PropA", null);
AppStorage.has("PropA");// 不支持设置null或undefined，会返回false

@Entry
@Component
struct TestPage {
  @StorageLink('PropA') propA: PropA = new PropA();

  build() {
    Column() {
      Text(this.propA.num.toString()) //使用propA本地初始化的值为100
    }
  }
}
```

更改后

```ts
class PropA {
  num: number = 100;
}

AppStorage.setOrCreate("PropA", null);
AppStorage.has("PropA");// 支持设置null或undefined，会返回true

@Entry
@Component
struct TestPage {
  @StorageLink('PropA') propA: PropA = new PropA();

  build() {
    Column() {
      Text(this.propA.num.toString()) //使用AppStorage初始化的值 ‘null’ ,调用时触发JsCrash
    }
  }
}
```

**变更涉及接口**

AppStorage：set，setOrCreate，setAndLink，setAndProp

LocalStorage：set，setOrCreate，setAndLink，setAndProp

PersistentStorage：persistProp


**起始API Level**

该变更从API12开始生效，API11及之前不受影响。

AppStorage

set：API10，

setOrCreate：API10，

setAndLink：API10，

setAndProp：API10

LocalStorage

set：API9，

setOrCreate：API9，

setAndLink：API9，

setAndProp：API9

PersistentStorage

persistProp：API10

**变更发生版本**

从OpenHarmony SDK 5.0.0.13开始。

**适配指导**

1、在初始化值的时候不使用null或者undefined的值来初始化，使用有意义的值来初始化。

2、将原有的值改为null或undefined会触发UI刷新。

3、在调用的地方增加判空。

```ts
class PropA {
  num: number = 100;
}

AppStorage.setOrCreate("PropA", null);
AppStorage.has("PropA"); // 支持设置null或undefined，会返回true

@Entry
@Component
struct TestPage {
  @StorageLink('PropA') propA: PropA | null | undefined = new PropA();

  build() {
    Column() {
      Text(this.propA?.num.toString())//使用时进行判空，防止调用时为null和undefined的情况造成crash。
        .fontSize(20)
      Button("Set propA to null")
        .margin(10)
        .onClick(() => {
          this.propA = null;
        })
      Button("Set propA to undefined")
        .margin(10)
        .onClick(() => {
          this.propA = undefined;
        })
      Button("Assign new PropA")
        .margin(10)
        .onClick(() => {
          this.propA = new PropA();
        })
    }
  }
}
```