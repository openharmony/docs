# ArkUI子系统变更说明

## cl.arkui.1@LocalStorageLink,@LocalStorageProp,@StorageProp(),@StorageLink,@Provide,@Consume,@Watch key值未定义校验

**访问级别**

公开接口

**变更原因**

该变更为不兼容性变更。

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


## cl.arkui.2 AppStorage,LocalStorage,PersistentStorage支持undefined和null

**访问级别**

公开接口

**变更影响**

AppStorage,LocalStorage,PersistentStorage的API方法支持null和undefined作为入参。@StorageLink，@StorageProp，@LocalStorageLink，@LocalStorageProp装饰器支持null和undefined类型。

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.13开始。

**适配指导**

LocalStorage支持undefined和null：

在下面的示例中，变量A的类型为Info | null，变量B的类型为Info | undefined。Text组件初始化分别显示为null和undefined，点击切换为字母，再次点击切换回null和undefined。

当状态变量设置undefined和null时，开发者要注意做判空保护。

```ts
class Info {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }
}


@Component
struct StorLink {
  @LocalStorageLink("AA") A: Info | null = null;
  @LocalStorageLink("BB") B: Info | undefined = undefined;

  build() {
    Column() {
      Text("@StorageLink接口初始化，@StorageLink取值")
      Text(`${this.A == null ? "null" : this.A.name}`).fontSize(20).onClick(() => {
        this.A ? this.A = null : this.A = new Info("A");
      })
      Text(`${this.B == undefined ? "undefined" : this.B.name}`).fontSize(20).onClick(() => {
        this.B ? this.B = undefined : this.B = new Info("B");
      })
    }
    .borderWidth(3).borderColor(Color.Red)

  }
}

@Component
struct StorProp {
  @LocalStorageProp("AAA") A: Info | null = null;
  @LocalStorageProp("BBB") B: Info | undefined = undefined;

  build() {
    Column() {
      Text("@StorageProp接口初始化，@StorageProp取值")
      Text(`${this.A == null ? "null" : this.A.name}`).fontSize(20).onClick(() => {
        this.A ? this.A = null : this.A = new Info("A");
      })
      Text(`${this.B == undefined ? "undefined" : this.B.name}`).fontSize(20).onClick(() => {
        this.B ? this.B = undefined : this.B = new Info("B");
      })
    }
    .borderWidth(3).borderColor(Color.Blue)
  }
}

@Entry
@Component
struct TestCase3 {
  build() {
    Row() {
      Column() {
        StorLink()
        StorProp()
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

AppStorage支持undefined和null：

在下面的示例中，变量A的类型为Info | null，变量B的类型为Info | undefined。Text组件初始化分别显示为null和undefined，点击切换为字母，再次点击切换回null和undefined。

当状态变量设置undefined和null时，开发者要注意做判空保护。

```ts
class Info {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }
}


@Component
struct StorLink {
  @StorageLink("AA") A: Info | null = null;
  @StorageLink("BB") B: Info | undefined = undefined;

  build() {
    Column() {
      Text("@StorageLink接口初始化，@StorageLink取值")
      Text(`${this.A == null ? "null" : this.A.name}`).fontSize(20).onClick(() => {
        this.A ? this.A = null : this.A = new Info("A");
      })
      Text(`${this.B == undefined ? "undefined" : this.B.name}`).fontSize(20).onClick(() => {
        this.B ? this.B = undefined : this.B = new Info("B");
      })
    }
    .borderWidth(3).borderColor(Color.Red)

  }
}

@Component
struct StorProp {
  @StorageProp("AAA") A: Info | null = null;
  @StorageProp("BBB") B: Info | undefined = undefined;

  build() {
    Column() {
      Text("@StorageProp接口初始化，@StorageProp取值")
      Text(`${this.A == null ? "null" : this.A.name}`).fontSize(20).onClick(() => {
        this.A ? this.A = null : this.A = new Info("A");
      })
      Text(`${this.B == undefined ? "undefined" : this.B.name}`).fontSize(20).onClick(() => {
        this.B ? this.B = undefined : this.B = new Info("B");
      })
    }
    .borderWidth(3).borderColor(Color.Blue)
  }
}

@Entry
@Component
struct TestCase3 {
  build() {
    Row() {
      Column() {
        StorLink()
        StorProp()
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

PersistentStorage支持undefined和null：

在下面的示例中，使用persistProp方法初始化"P"为undefined。通过@StorageLink("P")绑定变量p，类型为number | undefined | null，点击Button改变P的值，视图会随之刷新。且P的值被持久化存储。

```ts
PersistentStorage.persistProp("P", undefined);

@Entry
@Component
struct TestCase6 {
  @StorageLink("P") p: number | undefined | null = 10;

  build() {
    Row() {
      Column() {
        Text(this.p + "")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button("changeToNumber").onClick(() => {
          this.p = 10;
        })
        Button("changeTo undefined").onClick(() => {
          this.p = undefined;
        })
        Button("changeTo null").onClick(() => {
          this.p = null;
        })
      }  
      .width('100%')
    }
    .height('100%')
  }
}
```