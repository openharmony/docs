# arkui子系统ChangeLog


## cl.arkui.1 编译拦截@Extend/@AnimatableExtend参数个数不符合预期

@Extend/@AnimatableExtend装饰器参数有且仅能有一个。

**变更影响**

当@Extend/@AnimatableExtend装饰器参数有多个时，编译报错。

**错误示例：**

```ts
// xxx.ets

@Extend(Text, Button)  // 编译报错： @Extend should have one and only one parameter
function fancy() {
  .width(100)
}

@AnimatableExtend(Text, Polyline)  // 编译报错： @AnimatableExtend should have one and only one parameter
function fancy2() {
  .height(100)
}

@Entry
@Component
struct Example {
  build() {
    Column() {
      Text('text')
        .fancy()
        .fancy2()
    }
  }
}
```

**关键接口/组件变更**

不涉及

**适配指导**

@Extend和AnimatableExtend装饰器仅能传一个参数。

参考代码如下：
```ts
// xxx.ets

@Extend(Text)
function fancy() {
  .width(100)
}

@AnimatableExtend(Text)
function fancy2() {
  .height(100)
}

@Entry
@Component
struct Example {
  build() {
    Column() {
      Text('text')
        .fancy()
        .fancy2()
    }
  }
}
```

## cl.arkui.2 编译拦截@Link/@ObjectLink成员变量未从父组件传值

子组件的@Link/@ObjectLink成员变量需要从父组件传值。

**变更影响**

子组件的@Link/@ObjectLink当没有从父组件传值时，编译报错。

**错误示例：**

```ts
// xxx.ets

@Observed
class Count {
  message: string = 'count'
}

@Entry
@Component
struct Parent {
  @State state1: string = 'state1';
  @State state2: Count = new Count();
  build() {
    Column() {
      Child()  // 编译报错：Property 'link' in the custom component 'Child' is missing (mandatory to specify).
               // 编译报错：Property 'objectLink' in the custom component 'Child' is missing (mandatory to specify).
    }
  }
}

@Component
struct Child {
  @Link link: string;
  @ObjectLink objectLink: Count;
  build() {
    Column() {
      Text(this.link)
        .fontSize(50)
      Text(this.objectLink.message)
        .fontSize(50)
    }
  }
}
```

**关键接口/组件变更**

不涉及

**适配指导**

子组件的@Link/@ObjectLink成员变量需要从父组件传值。

参考代码如下：
```ts
// xxx.ets

@Observed
class Count {
  message: string = 'count'
}

@Entry
@Component
struct Parent {
  @State state1: string = 'state1';
  @State state2: Count = new Count();
  build() {
    Column() {
      Child({link: $state1, objectLink: this.state2})
    }
  }
}

@Component
struct Child {
  @Link link: string;
  @ObjectLink objectLink: Count;
  build() {
    Column() {
      Text(this.link)
        .fontSize(50)
      Text(this.objectLink.message)
        .fontSize(50)
    }
  }
}
```
