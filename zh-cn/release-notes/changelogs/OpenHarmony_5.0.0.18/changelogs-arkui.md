# ArkUI子系统变更说明

## cl.arkui.1 Router默认转场动效变更

**访问级别**

公开接口

**变更原因**

ArkUI目前有两套路由框架，Router和Navigation。Navigation在实现时应用了最新UX转场动效的设计规格，为保证体验的一致性，Router也需要按UX转场动效设计规格调整动效时长。

**变更影响**

Router默认转场动效变更。

变更前：动效时长为300ms，效果如图所示。

![Router变更前默认转场动效图](figures/preRouterTransition.gif)

变更后：默认转场动效曲线设置为物理曲线，时长由物理曲线计算得出，约600ms，效果如图所示。

![Router变更后默认转场动效图](figures/curRouterTransition.gif)

**API Level**

起始支持版本为 API 8。

**变更发生版本**

从OpenHarmony SDK 5.0.0.18开始。

**适配指导**

系统默认样式变更调整，无需适配。

## cl.arkui.2 @observed、@track装饰器命名变更为@ObservedV2、@Trace

**访问级别**

公开接口

**变更原因**

新装饰器@observed、@track与旧装饰器@Observed、@Track十分相似不易区分，且由小写字母开头与其他现有装饰器风格不一致。现将@observed、@track装饰器更名为@ObservedV2、@Trace，以便开发者将新旧装饰器区分开来，同时保持装饰器命名风格的统一。

**变更影响**

原有使用@observed装饰器装饰的类需要更改为使用@ObservedV2装饰。

原有使用@track装饰器装饰的类中成员属性需要更改为使用@Trace装饰。

变更前：

```ts
@observed
class Info {
  @track name: string = "Tom";
  @track age: number = 25;
  id: number = 0;
}
@Entry
@Component
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Text("Name: " + this.info.name)
      Text("Age: " + this.info.age)
    }
  }
}
```

变更后：

```ts
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Trace age: number = 25;
  id: number = 0;
}
@Entry
@Component
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Text("Name: " + this.info.name)
      Text("Age: " + this.info.age)
    }
  }
}
```

**影响范围**

@observed装饰器、@track装饰器

**起始API Level**

@observed：API12

@track：API12

**变更发生版本**

从OpenHarmony SDK 5.0.0.18开始。

**适配指导**

使用@ObservedV2装饰类，@Trace装饰类中成员属性。

```ts
@ObservedV2
class Person {
  id: number = 0;
  @Trace age: number = 8;
}
@Entry
@Component
struct Index {
  person: Person = new Person();

  build() {
    Column() {
      Text(`${this.person.age}`)
    }
  }
}
```
