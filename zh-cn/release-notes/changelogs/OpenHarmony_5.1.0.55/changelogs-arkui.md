# ArkUI子系统Changelog

## cl.arkui.1 Repeat virtualScroll模式下，key不变&item改变的数据不刷新

**访问级别**

公开接口

**变更原因**

Repeat组件缓存复用能力优化。

**变更影响**

此变更涉及应用适配。

- 变更前：key不变，item改变，界面立即触发刷新，数据改变。

- 变更后：key不变，item改变，认为节点没有发生变化，界面不会立即触发刷新。

eg. 运行下面的Demo示例，进入页面后，点击“click”按钮改变数组项的值。

```ts
@ObservedV2
class RepeatData {
  @Trace id: string;
  @Trace msg: string;

  constructor(id: string, msg: string) {
    this.id = id;
    this.msg = msg;
  }
}

@Entry
@ComponentV2
struct RepeatRerender {
  @Local dataArr: Array<RepeatData> = [];

  aboutToAppear(): void {
    for (let i = 0; i < 10; i++) {
      this.dataArr.push(new RepeatData(`key${i}`, `data${i}`));
    }
  }

  build() {
    Column({ space: 20 }) {
      List() {
        Repeat<RepeatData>(this.dataArr)
          .each((ri: RepeatItem<RepeatData>) => {
            ListItem() {
              Text(ri.item.msg).fontSize(30)
            }
          })
          .key((item: RepeatData, index: number) => item.id)
          .virtualScroll()
      }
      .cachedCount(2)
      .width('100%')
      .height('40%')
      .border({ width: 1 })
      .backgroundColor(0xFAEEE0)

      Button('click').onClick(() => {
        this.dataArr[0].msg = 'new msg'; // 改变第一项数据对象的msg属性的值
      })
    }
  }
}
```

变更前：点击按钮后，节点数据发生变化，如下图所示。

![img](../../figures/cl.arkui.1_rerender.gif)

变更后：点击按钮后，节点数据没有变化。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.1.0.55开始。

**适配指导**

应用是否需要适配需要根据具体场景决定。如果开发者希望页面中的列表数据随着键值key的变化而变化（key不改变时页面不刷新），则无需更改`.key()`。

如果希望数据发生变化就触发页面刷新，第一种方法（建议）：去掉Repeat的`.key()`函数；第二种方法：`.key()`的值的变化和数据变化保持一致。以上面的Demo为例，两种修改方案分别如下。

第一种方案，去掉Repeat的`.key()`函数：

```ts
@ObservedV2
class RepeatData {
  @Trace id: string;
  @Trace msg: string;

  constructor(id: string, msg: string) {
    this.id = id;
    this.msg = msg;
  }
}

@Entry
@ComponentV2
struct RepeatRerender {
  @Local dataArr: Array<RepeatData> = [];

  aboutToAppear(): void {
    for (let i = 0; i < 10; i++) {
      this.dataArr.push(new RepeatData(`key${i}`, `data${i}`));
    }
  }

  build() {
    Column({ space: 20 }) {
      List() {
        Repeat<RepeatData>(this.dataArr)
          .each((ri: RepeatItem<RepeatData>) => {
            ListItem() {
              Text(ri.item.msg).fontSize(30)
            }
          })
          .virtualScroll() // 删除.key()函数
      }
      .cachedCount(2)
      .width('100%')
      .height('40%')
      .border({ width: 1 })
      .backgroundColor(0xFAEEE0)

      Button('click').onClick(() => {
        this.dataArr[0].msg = 'new msg'; // 改变第一项数据对象的msg属性的值
      })
    }
  }
}
```

第二种方案，修改`.key()`，使得`.key()`的值的变化和数据变化保持一致：

```ts
@ObservedV2
class RepeatData {
  @Trace id: string;
  @Trace msg: string;

  constructor(id: string, msg: string) {
    this.id = id;
    this.msg = msg;
  }
}

@Entry
@ComponentV2
struct RepeatRerender {
  @Local dataArr: Array<RepeatData> = [];

  aboutToAppear(): void {
    for (let i = 0; i < 10; i++) {
      this.dataArr.push(new RepeatData(`key${i}`, `data${i}`));
    }
  }

  build() {
    Column({ space: 20 }) {
      List() {
        Repeat<RepeatData>(this.dataArr)
          .each((ri: RepeatItem<RepeatData>) => {
            ListItem() {
              Text(ri.item.msg).fontSize(30)
            }
          })
          .key((item: RepeatData, index: number) => item.msg) // .key()的值的变化和数据变化保持一致，数据改变时key也会改变
          .virtualScroll()
      }
      .cachedCount(2)
      .width('100%')
      .height('40%')
      .border({ width: 1 })
      .backgroundColor(0xFAEEE0)

      Button('click').onClick(() => {
        this.dataArr[0].msg = 'new msg'; // 改变第一项数据对象的msg属性的值
      })
    }
  }
}
```