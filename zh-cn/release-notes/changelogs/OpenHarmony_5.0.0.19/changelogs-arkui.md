# ArkUI子系统变更说明

## cl.arkui.1 promptAction.showDialog、promptAction.openCustomDialog、AlertDialog、ActionSheet、DatePickerDialog、TimePickerDialog、TextPickerDialog、CustomDialog 显示样式变更

**访问级别**

公开接口

**变更原因**

该变更为兼容性变更。

**变更影响**

promptAction.showDialog、promptAction.openCustomDialog、AlertDialog、ActionSheet、DatePickerDialog、TimePickerDialog、TextPickerDialog、CustomDialog 显示样式变更。

变更前：弹窗蒙层显示区域未延伸至底部导航条；在showInSubwindow为true或应用配置为沉浸式时，未避让顶部状态栏与底部导航条。

变更后：弹窗蒙层显示区域默认延伸至底部导航条；在showInSubwindow为true或应用配置为沉浸式时，默认避让顶部状态栏与底部导航条。

如下图所示为设置Alignment为Bottom时变更前后效果对比：

![dialog change](figures/dialog_changelog.png)

**API Level**

AlertDialog、CustomDialog 起始支持版本为 API 7，ActionSheet、DatePickerDialog、TimePickerDialog、TextPickerDialog 起始支持版本为 API 8，promptAction.showDialog 起始支持版本为 API 9，promptAction.openCustomDialog 起始支持版本为 API 11。

**变更发生版本**

从OpenHarmony SDK 5.0.0.19开始。

**适配指导**

默认样式变更调整，无需适配。

## cl.arkui.2 linearGradient、sweepGradient、radialGradient通用属性及LinearGradient interface中的colors参数类型从Array&lt;any&gt;变更为Array&lt;[ResourceColor, number]&gt;

**访问级别**

公开接口

**变更原因**

any类型过于宽泛，从api上没有引导开发者使用正确的参数类型。

**变更影响**

该变更为非兼容性变更。

变更前：允许将linearGradient、sweepGradient、radialGradient通用属性及LinearGradient interface中的colors参数定义为Array&lt;any&gt;类型。

变更后：如果使用了与Array&lt;[ResourceColor, number]&gt;不兼容的colors参数类型，如Array&lt;any&gt;，编译报错。

**API Level**

linearGradient、sweepGradient、radialGradient通用属性的起始支持版本为API 7，LinearGradient interface中的起始支持版本为API 9。

**变更发生版本**

从OpenHarmony SDK 5.0.0.19开始。

**适配指导**

如果需要定义linearGradient、sweepGradient、radialGradient接口中使用的变量，colors参数的类型应准确定义为与Array&lt;[ResourceColor, number]&gt;兼容的类型。

## cl.arkui.3 sweepGradient、radialGradient通用属性的center参数类型从Array&lt;any&gt;变更为[Length, Length]

**访问级别**

公开接口

**变更原因**

any类型过于宽泛，从api上没有引导开发者使用正确的参数类型，也没有从api上约束center的长度为2。

**变更影响**

该变更为非兼容性变更。

变更前：允许将sweepGradient、radialGradient通用属性的center参数类型定义为Array&lt;any&gt;类型。

变更后：如果使用了与[Length, Length]不兼容的center参数类型，编译报错。

**API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.0.0.19开始。

**适配指导**

如果需要定义sweepGradient、radialGradient接口中使用的变量，center参数的类型应准确定义为与[Length, Length]兼容的类型。

## cl.arkui.4 快捷键接口keyboardShortcut匹配规则变更为严格匹配，匹配成功后拦截后续按键事件处理

**访问级别**

公开接口

**变更原因**

快捷键匹配原则过于宽松，例如绑定了CTRL+A的快捷键事件，实际使用CTRL+SHIFT+A依然能成功触发该事件。
快捷键事件被匹配并消费后依然会继续下发，并可能触发后续按键事件，例如被输入法响应。

**变更影响**

该变更为非兼容性变更。

变更前：绑定的快捷键是当前已触发按键的子集，即可触发快捷键。触发快捷键后，按键事件会继续触发`onKeyEvent`事件等其他按键事件。

变更后：绑定的快捷键必须与当前触发的按键完全一致，方能触发快捷键。触发快捷键即视为按键已消费，不再触发其他按键事件。

**API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.19开始。

**适配指导**

快捷键的按键集合严格对应所需要的按键。

## cl.arkui.5 TextInput、TextArea、Search文本手柄颜色和文本选中底板颜色显示样式变更

**访问级别**

公开接口

**变更原因**

该变更为兼容性变更。

**变更影响**

a) TextInput、TextArea、Search文本手柄颜色，显示样式变更

变更前：TextInput、TextArea、Search文本手柄颜色，显示为默认颜色。

变更后：TextInput、TextArea、Search文本手柄颜色，显示为光标颜色。

b) TextInput、TextArea、Search文本选中底板颜色显示样式变更

变更前：TextInput、TextArea、Search文本选中底板颜色，未设置颜色，显示为默认颜色，默认透明度20%。

变更后：TextInput、TextArea、Search文本选中底板颜色，未设置颜色，显示为光标颜色，透明度在光标颜色透明度的基础上叠加20%。

如下图所示为变更前后效果对比：

![handler color change](figures/handler_color_changelog.png)

**API Level**

TextInput起始支持版本为 API 7，TextArea、Search起始支持版本为 API 8

**变更发生版本**

从OpenHarmony SDK 5.0.0.19开始。

**适配指导**

默认样式变更调整，无需适配。


## cl.arkui.6 @observed、@track装饰器命名变更为@ObservedV2、@Trace

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

从OpenHarmony SDK 5.0.0.19开始。

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