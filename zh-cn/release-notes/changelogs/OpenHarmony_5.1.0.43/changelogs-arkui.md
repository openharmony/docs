# ArkUI子系统Changelog

## cl.arkui.1 当使用双向绑定范式并给对应的@Event赋值时编译报错变更

**访问级别**

公开接口

**变更原因**

双向绑定语法和@Event接口不兼容，需要增加编译器校验。

**变更影响**

该变更为不兼容变更。

举例说明，执行以下用例：

```ts
@Entry
@ComponentV2
struct EventExample {
  @Local value: string = 'Hi !';

  build() {
    Column() {
      Text(this.value)
        .fontSize(50)
        .fontColor(Color.Red)
      Star({ value: this.value!!, $value: (val: string) => { this.value += val; }})
    }
  }
}

@ComponentV2
struct Star {
  @Param value: string = 'Hi !';
  @Event $value: (val: string) => void = (val: string) => {};

  build() {
    Column() {
      Text(this.value)
        .fontSize(50)
      Button('click me to change value')
        .onClick(() => {
          this.$value('hello');
        })
    }
  }
}
```

变更前：编译运行不报错，点击Button，父子组件的Text组件文本内容均变为"hello"，开发者传入的对应的@Event方法不生效。

变更后：检测到开发者使用了双向绑定范式并且给对应的@Event方法赋值，编译拦截报错。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.43开始。

**变更的接口/组件**

!!双向绑定语法，@Event装饰器。

**适配指导**

当使用双向绑定范式并给对应的@Event方法赋值时，编译报错，删掉给对应的@Event方法的传参即可解决。

修改前：

使用双向绑定范式this.value!!，同时给对应的$value方法传递参数$value: (val: string) => { this.value += val; }。

```ts
@Entry
@ComponentV2
struct EventExample {
  @Local value: string = 'Hi !';

  build() {
    Column() {
      Text(this.value)
        .fontSize(50)
        .fontColor(Color.Red)
      Star({ value: this.value!!, $value: (val: string) => { this.value += val; }})
    }
  }
}

@ComponentV2
struct Star {
  @Param value: string = 'Hi !';
  @Event $value: (val: string) => void = (val: string) => {};

  build() {
    Column() {
      Text(this.value)
        .fontSize(50)
      Button('click me to change value')
        .onClick(() => {
          this.$value('hello');
        })
    }
  }
}
```

修改后：

删除给对应的$value方法传递的参数。

```ts
@Entry
@ComponentV2
struct EventExample {
  @Local value: string = 'Hi !';

  build() {
    Column() {
      Text(this.value)
        .fontSize(50)
        .fontColor(Color.Red)
      Star({ value: this.value!! })
    }
  }
}

@ComponentV2
struct Star {
  @Param value: string = 'Hi !';
  @Event $value: (val: string) => void = (val: string) => {};

  build() {
    Column() {
      Text(this.value)
        .fontSize(50)
      Button('click me to change value')
        .onClick(() => {
          this.$value('hello');
        })
    }
  }
}
```