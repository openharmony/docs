# MVVM模式（状态管理V2）

## 概述

在应用开发中，UI的更新需要随着数据状态的变化进行实时同步，而这种同步往往决定了应用程序的性能和用户体验。为了解决数据与UI同步的复杂性，ArkUI采用了Model-View-ViewModel（MVVM）架构模式。MVVM将应用分为Model、View和ViewModel三个核心部分，实现数据、视图与逻辑的分离。通过这种模式，UI可以随着状态的变化自动更新，无需手动处理，从而更加高效地管理数据和视图的绑定与更新。

- Model：存储和管理应用数据及业务逻辑，不直接与用户界面交互。通常从后端接口获取数据，是应用程序的数据基础，确保数据的一致性和完整性。
- View：负责用户界面展示数据并与用户交互，不包含任何业务逻辑。它通过绑定ViewModel层提供的数据来动态更新UI。
- ViewModel：负责管理UI状态和交互逻辑。作为连接Model和View的桥梁，ViewModel监控Model数据的变化，通知View更新UI，同时处理用户交互事件并转换为数据操作。

## 通过状态管理V2版本实现ViewModel

在MVVM模式中，ViewModel负责管理数据状态，并在数据变化时自动更新视图。ArkUI的状态管理V2版本提供了丰富的装饰器和工具，帮助开发者在自定义组件之间共享数据，确保数据变化自动同步到UI。常用的状态管理装饰器包括\@Local、\@Param、\@Event、\@ObservedV2、\@Trace等等。此外，V2还提供了AppStorageV2和PersistenceV2作为全局状态存储工具，用于应用间的状态共享和持久化存储。

本节将通过一个简单的todolist示例，逐步引入和使用状态管理V2的装饰器及工具，从基础的静态任务列表开始，逐步扩展功能。每个步骤都基于上一步扩展，帮助开发者循序渐进地理解并掌握各个装饰器的使用方法。

### 基础示例

首先，从静态待办事项列表开始。在示例1中，任务是静态的，没有状态变化和动态交互。

**示例1**

```ts
// src/main/ets/pages/1-Basic.ets

@Entry
@ComponentV2
struct TodoList {
  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin({ bottom: 10 })
      Text('Task1')
      Text('Task2')
      Text('Task3')
    }
  }
}
```

### 添加\@Local，实现对组件内部状态观测

完成静态待办列表展示后，为了让用户能够更改任务的完成状态，需要使待办事项能够响应交互并动态更新显示。为此，引入\@Local装饰器管理组件内部的状态。被\@Local装饰的变量发生变化时，会触发绑定的UI组件刷新。

在示例2中，新增@Local装饰的isFinish属性代表任务是否完成。两个图标finished.png和unfinished.png用于展示任务完成或未完成的状态。点击待办事项时，isFinish状态切换，从而更新图标和文本删除线的效果。

**示例2**

```ts 
// src/main/ets/pages/2-Local.ets

@Entry
@ComponentV2
struct TodoList {
  @Local isFinish: boolean = false;

  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin({ bottom: 10 })
      Row() {
        // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
        Image(this.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
          .width(28)
          .height(28)
        Text('Task1')
          .decoration({ type: this.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      }
      .onClick(() => this.isFinish = !this.isFinish)
    }
  }
}
```

### 添加\@Param，实现组件接受外部输入
实现任务本地状态切换后，为增强待办事项列表的灵活性，需要能够动态设置每个任务的名称，而不是固定在代码中。引入\@Param装饰器后，子组件被装饰的变量可以接收父组件传入的值，实现单向数据同步。\@Param默认只读，使用\@Param \@Once可在子组件中对传入的值进行本地更新。

在示例3中，每个待办事项抽象为TaskItem组件。\@Param修饰的taskName属性从父组件TodoList传入任务名称，使TaskItem组件灵活且可复用，能够接收并渲染不同的任务名称。\@Param \@Once装饰的isFinish属性接收初始值后，可在子组件内更新。

**示例3**

```ts
// src/main/ets/pages/3-Param.ets

@ComponentV2
struct TaskItem {
  @Param taskName: string = '';
  @Param @Once isFinish: boolean = false;

  build() {
    Row() {
      // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
      Image(this.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.taskName)
        .decoration({ type: this.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
    }
    .onClick(() => this.isFinish = !this.isFinish)
  }
}

@Entry
@ComponentV2
struct TodoList {
  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin({ bottom: 10 })
      TaskItem({ taskName: 'Task 1', isFinish: false })
      TaskItem({ taskName: 'Task 2', isFinish: false })
      TaskItem({ taskName: 'Task 3', isFinish: false })
    }
  }
}
```

### 添加\@Event，实现组件对外输出

实现任务名称动态设置后，任务列表内容固定。为了实现任务列表的动态扩展，需要增加任务项的添加和删除功能。为此，引入\@Event装饰器，用于子组件向父组件输出数据。

在示例4中，每个TaskItem增加了删除按钮，同时任务列表底部增加了添加新任务的功能。点击子组件TaskItem的“删除”按钮时，deleteTask事件会被触发并传递给父组件TodoList，父组件响应并移除任务。通过使用\@Param和\@Event，子组件不仅能接收父组件的数据，还能够将事件传递回父组件，实现数据的双向同步。

**示例4**

```ts
// src/main/ets/pages/4-Event.ets

@ComponentV2
struct TaskItem {
  @Param taskName: string = '';
  @Param @Once isFinish: boolean = false;
  @Event deleteTask: () => void = () => {};

  build() {
    Row() {
      // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
      Image(this.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.taskName)
        .decoration({ type: this.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('删除')
        .onClick(() => this.deleteTask())
    }
    .onClick(() => this.isFinish = !this.isFinish)
  }
}

@Entry
@ComponentV2
struct TodoList {
  @Local tasks: string[] = ['task1','task2','task3'];
  @Local newTaskName: string = '';
  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin({ bottom: 10 })
      ForEach(this.tasks, (task: string) => {
          TaskItem({
            taskName: task,
            isFinish: false,
            deleteTask: () => this.tasks.splice(this.tasks.indexOf(task), 1)
          })
      })
      Row() {
        TextInput({ placeholder: '添加新任务', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('增加事项')
          .onClick(() => {
            this.tasks.push(this.newTaskName);
            this.newTaskName = '';
          })
      }
    }
  }
}
```

### 添加Repeat，实现子组件复用

添加任务增删功能后，任务列表项增加，需要高效渲染多个结构相同的子组件，提高界面性能。引入Repeat方法，优化任务列表渲染。

Repeat支持两种场景：懒加载场景和非懒加载场景。
- 懒加载场景适用于大量数据的场景，在滚动类容器中按需加载组件，极大节省内存和提升渲染效率。
- 非懒加载场景适用于数据量较小的场景，一次性渲染所有组件，并在数据变化时仅更新需要变化的部分，避免整体重新渲染。

在示例5中，由于任务量较少，使用Repeat非懒加载场景。新建一个任务数组tasks，并使用Repeat方法迭代数组中的每一项，动态生成并复用TaskItem组件。在任务增删时，这种方式能高效复用已有组件，避免重复渲染，从而提高界面响应速度和性能。这种机制有效地提高了代码的复用性和渲染效率。

**示例5**

```ts
// src/main/ets/pages/5-Repeat.ets

@ComponentV2
struct TaskItem {
  @Param taskName: string = '';
  @Param @Once isFinish: boolean = false;
  @Event deleteTask: () => void = () => {};

  build() {
    Row() {
      // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
      Image(this.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.taskName)
        .decoration({ type: this.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('删除')
        .onClick(() => this.deleteTask())
    }
    .onClick(() => this.isFinish = !this.isFinish)
  }
}

@Entry
@ComponentV2
struct TodoList {
  @Local tasks: string[] = ['task1','task2','task3'];
  @Local newTaskName: string = '';
  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin({ bottom: 10 })
      Repeat<string>(this.tasks)
        .each((obj: RepeatItem<string>) => {
          TaskItem({
            taskName: obj.item,
            isFinish: false,
            deleteTask: () => this.tasks.splice(this.tasks.indexOf(obj.item), 1)
          })
        })
      Row() {
        TextInput({ placeholder: '添加新任务', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('增加事项')
          .onClick(() => {
            this.tasks.push(this.newTaskName);
            this.newTaskName = '';
          })
      }
    }
  }
}
```

### 添加\@ObservedV2，\@Trace，实现类属性观测变化

实现多个功能后，任务列表管理变得复杂。为了有效处理任务数据的变化，特别是在多层嵌套结构中，需要确保属性变化能够被深度观测并自动更新UI。为此，引入了\@ObservedV2和\@Trace装饰器。与仅能观测对象及其第一层变化的\@Local不同，\@ObservedV2和\@Trace适用于多层嵌套和继承等复杂场景。在\@ObservedV2装饰的类中，\@Trace装饰的属性变化时，会触发绑定的UI组件刷新。

在示例6中，任务（Task）被抽象为一个类，并用\@ObservedV2标记该类，用\@Trace标记isFinish属性。TodoList组件嵌套了TaskItem，TaskItem又嵌套了Task。在最外层的TodoList中，添加了"全部完成"和"全部未完成"的按钮，每次点击这些按钮都会直接更新最内层Task类的isFinish属性。\@ObservedV2和\@Trace确保可以观察到对应isFinish UI组件的刷新，从而实现了对嵌套类属性的深度观测。

**示例6**

```ts
// src/main/ets/pages/6-ObservedV2Trace.ets

@ObservedV2
class Task {
  taskName: string = '';
  @Trace isFinish: boolean = false;

  constructor (taskName: string, isFinish: boolean) {
    this.taskName = taskName;
    this.isFinish = isFinish;
  }
}

@ComponentV2
struct TaskItem {
  @Param task: Task = new Task('', false);
  @Event deleteTask: () => void = () => {};

  build() {
    Row() {
      // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('删除')
        .onClick(() => this.deleteTask())
    }
    .onClick(() => this.task.isFinish = !this.task.isFinish)
  }
}

@Entry
@ComponentV2
struct TodoList {
  @Local tasks: Task[] = [
    new Task('task1', false),
    new Task('task2', false),
    new Task('task3', false),
  ];
  @Local newTaskName: string = '';

  finishAll(ifFinish: boolean) {
    for (let task of this.tasks) {
      task.isFinish = ifFinish;
    }
  }

  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin({ bottom: 10 })
      Repeat<Task>(this.tasks)
        .each((obj: RepeatItem<Task>) => {
          TaskItem({
            task: obj.item,
            deleteTask: () => this.tasks.splice(this.tasks.indexOf(obj.item), 1)
          })
        })
      Row() {
        Button('全部完成')
          .onClick(() => this.finishAll(true))
        Button('全部未完成')
          .onClick(() => this.finishAll(false))
      }
      Row() {
        TextInput({ placeholder: '添加新任务', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('增加事项')
          .onClick(() => {
            this.tasks.push(new Task(this.newTaskName, false));
            this.newTaskName = '';
          })
      }
    }
  }
}
```

### 添加\@Monitor，\@Computed，实现监听状态变量和计算属性

在当前任务列表功能基础上，为了提升体验，可以增加一些额外的功能，如任务状态变化的监听和未完成任务数量的动态计算。为此，引入\@Monitor和\@Computed装饰器。\@Monitor用于深度监听状态变量，在属性变化时触发自定义回调方法。\@Computed用于装饰getter方法，检测被计算的属性变化。在被计算的值变化时，仅会计算一次，减少重复计算开销。

在示例6中，使用\@Monitor装饰器深度监听TaskItem中task的isFinish属性。当任务完成状态变化时，触发onTasksFinished回调，记录任务完成状态的变化。同时，新增对todolist中未完成任务数量的记录。使用\@Computed装饰器定义tasksUnfinished，每当任务状态变化时自动重新计算。通过这两个装饰器，实现了状态变量的深度监听和高效的计算属性。

**示例7**

```ts
// src/main/ets/pages/7-MonitorComputed.ets

@ObservedV2
class Task {
  taskName: string = '';
  @Trace isFinish: boolean = false;

  constructor (taskName: string, isFinish: boolean) {
    this.taskName = taskName;
    this.isFinish = isFinish;
  }
}

@ComponentV2
struct TaskItem {
  @Param task: Task = new Task('', false);
  @Event deleteTask: () => void = () => {};
  @Monitor('task.isFinish')
  onTaskFinished(mon: IMonitor) {
    console.log('任务' + this.task.taskName + '的完成状态从' + mon.value()?.before + '变为了' + mon.value()?.now);
  }

  build() {
    Row() {
      // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('删除')
        .onClick(() => this.deleteTask())
    }
    .onClick(() => this.task.isFinish = !this.task.isFinish)
  }
}

@Entry
@ComponentV2
struct TodoList {
  @Local tasks: Task[] = [
    new Task('task1', false),
    new Task('task2', false),
    new Task('task3', false),
  ];
  @Local newTaskName: string = '';

  finishAll(ifFinish: boolean) {
    for (let task of this.tasks) {
      task.isFinish = ifFinish;
    }
  }

  @Computed
  get tasksUnfinished(): number {
    return this.tasks.filter(task => !task.isFinish).length;
  }

  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin({ bottom: 10 })
      Text(`未完成任务：${this.tasksUnfinished}`)
      Repeat<Task>(this.tasks)
        .each((obj: RepeatItem<Task>) => {
          TaskItem({
            task: obj.item,
            deleteTask: () => this.tasks.splice(this.tasks.indexOf(obj.item), 1)
          })
        })
      Row() {
        Button('全部完成')
          .onClick(() => this.finishAll(true))
        Button('全部未完成')
          .onClick(() => this.finishAll(false))
      }
      Row() {
        TextInput({ placeholder: '添加新任务', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('增加事项')
          .onClick(() => {
            this.tasks.push(new Task(this.newTaskName, false));
            this.newTaskName = '';
          })
      }
    }
  }
}
```

### 添加AppStorageV2，实现应用全局UI状态存储

随着待办事项功能的增强，应用可能涉及多个页面或功能模块，此时需要在这些页面之间共享全局状态。例如：在待办事项应用中，新增一个设置页面与主界面联动。为实现跨页面的状态共享，引入AppStorageV2，用于在多个UIAbility实例之间存储和共享应用的全局状态。

在这个示例中，新增了一个Ability，SettingAbility，用于加载设置页面SettingPage。SettingPage包含了一个Setting类，其中的showCompletedTask属性用于控制是否显示已完成的任务。用户可以通过一个开关切换该选项。两个Ability通过AppStorageV2共享设置数据，键为 "Setting"，对应的数据为Setting类。第一次通过connect连接Setting时，如果不存在存储的数据，会创建一个默认showCompletedTask为trueSetting实例。后续用户在设置页面修改设置后，主页面会根据这一设置更新任务列表的显示。通过AppStorageV2，实现了跨Ability、跨页面的数据共享。

**示例8**

```ts
// src/main/ets/pages/8-AppStorageV2.ets

import { AppStorageV2 } from '@kit.ArkUI';
import { common, Want } from '@kit.AbilityKit';
import { Setting } from './SettingPage';

@ObservedV2
class Task {
  taskName: string = '';
  @Trace isFinish: boolean = false;

  constructor (taskName: string, isFinish: boolean) {
    this.taskName = taskName;
    this.isFinish = isFinish;
  }
}

@ComponentV2
struct TaskItem {
  @Param task: Task = new Task('', false);
  @Event deleteTask: () => void = () => {};
  @Monitor('task.isFinish')
  onTaskFinished(mon: IMonitor) {
    console.log('任务' + this.task.taskName + '的完成状态从' + mon.value()?.before + '变为了' + mon.value()?.now);
  }

  build() {
    Row() {
      // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('删除')
        .onClick(() => this.deleteTask())
    }
    .onClick(() => this.task.isFinish = !this.task.isFinish)
  }
}

@Entry
@ComponentV2
struct TodoList {
  @Local tasks: Task[] = [
    new Task('task1', false),
    new Task('task2', false),
    new Task('task3', false),
  ];
  @Local newTaskName: string = '';
  @Local setting: Setting = AppStorageV2.connect(Setting, 'Setting', () => new Setting())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  finishAll(ifFinish: boolean) {
    for (let task of this.tasks) {
      task.isFinish = ifFinish;
    }
  }

  @Computed
  get tasksUnfinished(): number {
    return this.tasks.filter(task => !task.isFinish).length;
  }

  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin({ bottom: 10 })
      Text(`未完成任务：${this.tasksUnfinished}`)
      Repeat<Task>(this.tasks.filter(task => this.setting.showCompletedTask || !task.isFinish))
        .each((obj: RepeatItem<Task>) => {
          TaskItem({
            task: obj.item,
            deleteTask: () => this.tasks.splice(this.tasks.indexOf(obj.item), 1)
          })
        })
      Row() {
        Button('全部完成')
          .onClick(() => this.finishAll(true))
        Button('全部未完成')
          .onClick(() => this.finishAll(false))
        Button('设置')
          .onClick(() => {
            let wantInfo: Want = {
              deviceId: '', // deviceId为空表示本设备
              bundleName: 'com.samples.statemgmtv2mvvm', // 替换成AppScope/app.json5里的bundleName
              abilityName: 'SettingAbility',
            };
            this.context.startAbility(wantInfo);
          })
      }
      Row() {
        TextInput({ placeholder: '添加新任务', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('增加事项')
          .onClick(() => {
            this.tasks.push(new Task(this.newTaskName, false));
            this.newTaskName = '';
          })
      }
    }
  }
}
```

```ts
// SettingAbility的SettingPage页面代码
import { AppStorageV2 } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

@ObservedV2
export class Setting {
  @Trace showCompletedTask: boolean = true;
}

@Entry
@ComponentV2
struct SettingPage {
  @Local setting: Setting = AppStorageV2.connect(Setting, 'Setting', () => new Setting())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text('设置')
        .fontSize(40)
        .margin({ bottom: 10 })
      Row() {
        Text('显示已完成任务');
        Toggle({ type: ToggleType.Switch, isOn:this.setting.showCompletedTask })
          .onChange((isOn) => {
            this.setting.showCompletedTask = isOn;
          })
      }
      Button('返回待办')
        .onClick(()=>this.context.terminateSelf())
        .margin({ top: 10 })
    }
    .alignItems(HorizontalAlign.Start)
  }
}
```

### 添加PersistenceV2，实现持久化UI状态存储

为了保证用户在重新打开应用时仍然能够看到之前的任务状态，可以引入持久化存储方案。使用PersistenceV2能够将数据持久化保存在设备磁盘上。与AppStorageV2的运行时内存不同，PersistenceV2能确保即使应用关闭后再启动，数据依然保持不变。

在示例9中，创建了一个TaskList类，用于通过PersistenceV2持久化存储所有任务信息，键为"TaskList"，数据对应TaskList类。第一次通过connect连接TaskList时，如果没有数据，会创建一个默认tasks数组为空的新TaskList实例。在aboutToAppear生命周期函数中，连接到PersistenceV2的TaskList，若无存储任务数据，会从本地文件defaultTasks.json中加载任务并存储到PersistenceV2中。此后，每个任务的完成状态都会同步到PersistenceV2中。这样，即使应用关闭后再次打开，所有任务数据依旧保持不变，实现了持久化的应用状态存储功能。

**示例9**

```ts
// src/main/ets/pages/9-PersistenceV2.ets

import { AppStorageV2, PersistenceV2, Type } from '@kit.ArkUI';
import { common, Want } from '@kit.AbilityKit';
import { Setting } from './SettingPage';
import util from '@ohos.util';

@ObservedV2
class Task {
  // 未实现构造函数，因为@Type当前不支持带参数的构造函数
  @Trace taskName: string = 'Todo';
  @Trace isFinish: boolean = false;
}

@ObservedV2
class TaskList {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(Task)
  @Trace tasks: Task[] = [];

  constructor(tasks: Task[]) {
    this.tasks = tasks;
  }

  async loadTasks(context: common.UIAbilityContext) {
    let getJson = await context.resourceManager.getRawFileContent('defaultTasks.json');
    let textDecoderOptions: util.TextDecoderOptions = { ignoreBOM : true };
    let textDecoder = util.TextDecoder.create('utf-8',textDecoderOptions);
    let result = textDecoder.decodeToString(getJson);
    this.tasks =JSON.parse(result).map((task: Task)=>{
      let newTask = new Task();
      newTask.taskName = task.taskName;
      newTask.isFinish = task.isFinish;
      return newTask;
    });
  }
}

@ComponentV2
struct TaskItem {
  @Param task: Task = new Task();
  @Event deleteTask: () => void = () => {};
  @Monitor('task.isFinish')
  onTaskFinished(mon: IMonitor) {
    console.log('任务' + this.task.taskName + '的完成状态从' + mon.value()?.before + '变为了' + mon.value()?.now);
  }

  build() {
    Row() {
      // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('删除')
        .onClick(() => this.deleteTask())
    }
    .onClick(() => this.task.isFinish = !this.task.isFinish)
  }
}

@Entry
@ComponentV2
struct TodoList {
  @Local taskList: TaskList = PersistenceV2.connect(TaskList, 'TaskList', () => new TaskList([]))!;
  @Local newTaskName: string = '';
  @Local setting: Setting = AppStorageV2.connect(Setting, 'Setting', () => new Setting())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  async aboutToAppear() {
    this.taskList = PersistenceV2.connect(TaskList, 'TaskList', () => new TaskList([]))!;
    if (this.taskList.tasks.length === 0) {
      await this.taskList.loadTasks(this.context);
    }
  }

  finishAll(ifFinish: boolean) {
    for (let task of this.taskList.tasks) {
      task.isFinish = ifFinish;
    }
  }

  @Computed
  get tasksUnfinished(): number {
    return this.taskList.tasks.filter(task => !task.isFinish).length;
  }

  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin({ bottom: 10 })
      Text(`未完成任务：${this.tasksUnfinished}`)
      Repeat<Task>(this.taskList.tasks.filter(task => this.setting.showCompletedTask || !task.isFinish))
        .each((obj: RepeatItem<Task>) => {
          TaskItem({
            task: obj.item,
            deleteTask: () => this.taskList.tasks.splice(this.taskList.tasks.indexOf(obj.item), 1)
          })
        })
      Row() {
        Button('全部完成')
          .onClick(() => this.finishAll(true))
        Button('全部未完成')
          .onClick(() => this.finishAll(false))
        Button('设置')
          .onClick(() => {
            let wantInfo: Want = {
              deviceId: '', // deviceId为空表示本设备
              bundleName: 'com.samples.statemgmtv2mvvm', // 替换成AppScope/app.json5里的bundleName
              abilityName: 'SettingAbility',
            };
            this.context.startAbility(wantInfo);
          })
      }
      Row() {
        TextInput({ placeholder: '添加新任务', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('增加事项')
          .onClick(() => {
            let newTask = new Task();
            newTask.taskName = this.newTaskName;
            this.taskList.tasks.push(newTask);
            this.newTaskName = '';
          })
      }
    }
  }
}
```

JSON文件存放在src/main/resources/rawfile/defaultTasks.json路径下。
```json
[
  {"taskName": "学习ArkTS开发", "isFinish": false},
  {"taskName": "健身", "isFinish": false},
  {"taskName": "买水果", "isFinish": true},
  {"taskName": "取快递", "isFinish": true},
  {"taskName": "刷题", "isFinish": true}
]
```

### 添加\@Builder，实现自定义构建函数

随着应用功能逐步扩展，代码中的某些UI元素开始重复，这不仅增加了代码量，也让维护变得复杂。为了解决这一问题，可以使用\@Builder装饰器，将重复的UI组件抽象成独立的构建方法，便于复用和代码的模块化。

在示例10中，使用\@Builder定义了ActionButton方法，统一管理按钮的文字、样式和点击事件，使代码更简洁、结构更清晰，提升了代码的可维护性。在此基础上，调整了待办事项界面的布局和样式，例如组件的间距、颜色和大小，使UI界面更美观，最终呈现一个功能完善、界面简洁的待办事项应用。

**示例10**

```ts
// src/main/ets/pages/10-Builder.ets

import { AppStorageV2, PersistenceV2, Type } from '@kit.ArkUI';
import { common, Want } from '@kit.AbilityKit';
import { Setting } from './SettingPage';
import util from '@ohos.util';

@ObservedV2
class Task {
  // 未实现构造函数，因为@Type当前不支持带参数的构造函数
  @Trace taskName: string = 'Todo';
  @Trace isFinish: boolean = false;
}

@Builder function ActionButton(text: string, onClick:() => void) {
  Button(text, { buttonStyle: ButtonStyleMode.NORMAL })
    .onClick(onClick)
    .margin({ left: 10, right: 10, top: 5, bottom: 5 })
}

@ObservedV2
class TaskList {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(Task)
  @Trace tasks: Task[] = [];

  constructor(tasks: Task[]) {
    this.tasks = tasks;
  }

  async loadTasks(context: common.UIAbilityContext) {
    let getJson = await context.resourceManager.getRawFileContent('defaultTasks.json');
    let textDecoderOptions: util.TextDecoderOptions = { ignoreBOM : true };
    let textDecoder = util.TextDecoder.create('utf-8',textDecoderOptions);
    let result = textDecoder.decodeToString(getJson);
    this.tasks =JSON.parse(result).map((task: Task)=>{
      let newTask = new Task();
      newTask.taskName = task.taskName;
      newTask.isFinish = task.isFinish;
      return newTask;
    });
  }
}

@ComponentV2
struct TaskItem {
  @Param task: Task = new Task();
  @Event deleteTask: () => void = () => {};
  @Monitor('task.isFinish')
  onTaskFinished(mon: IMonitor) {
    console.log('任务' + this.task.taskName + '的完成状态从' + mon.value()?.before + '变为了' + mon.value()?.now);
  }

  build() {
    Row() {
      // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
        .margin({ left : 15, right : 10 })
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
        .fontSize(18)
      ActionButton('删除', () => this.deleteTask())
    }
    .height('7%')
    .width('90%')
    .backgroundColor('#90f1f3f5')
    .borderRadius(25)
    .onClick(() => this.task.isFinish = !this.task.isFinish)
  }
}

@Entry
@ComponentV2
struct TodoList {
  @Local taskList: TaskList = PersistenceV2.connect(TaskList, 'TaskList', () => new TaskList([]))!;
  @Local newTaskName: string = '';
  @Local setting: Setting = AppStorageV2.connect(Setting, 'Setting', () => new Setting())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  async aboutToAppear() {
    this.taskList = PersistenceV2.connect(TaskList, 'TaskList', () => new TaskList([]))!;
    if (this.taskList.tasks.length === 0) {
      await this.taskList.loadTasks(this.context);
    }
  }

  finishAll(ifFinish: boolean) {
    for (let task of this.taskList.tasks) {
      task.isFinish = ifFinish;
    }
  }

  @Computed
  get tasksUnfinished(): number {
    return this.taskList.tasks.filter(task => !task.isFinish).length;
  }

  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin(10)
      Text(`未完成任务：${this.tasksUnfinished}`)
        .margin({ left: 10, bottom: 10 })
      Repeat<Task>(this.taskList.tasks.filter(task => this.setting.showCompletedTask || !task.isFinish))
        .each((obj: RepeatItem<Task>) => {
          TaskItem({
            task: obj.item,
            deleteTask: () => this.taskList.tasks.splice(this.taskList.tasks.indexOf(obj.item), 1)
          }).margin(5)
        })
      Row() {
        ActionButton('全部完成', (): void => this.finishAll(true))
        ActionButton('全部未完成', (): void => this.finishAll(false))
        ActionButton('设置', (): void => {
          let wantInfo: Want = {
            deviceId: '', // deviceId为空表示本设备
            bundleName: 'com.samples.statemgmtv2mvvm', // 替换成AppScope/app.json5里的bundleName
            abilityName: 'SettingAbility',
          };
          this.context.startAbility(wantInfo);
        })
      }
      .margin({ top: 10, bottom: 5 })
      Row() {
        TextInput({ placeholder: '添加新任务', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        ActionButton('+', (): void => {
          let newTask = new Task();
          newTask.taskName = this.newTaskName;
          this.taskList.tasks.push(newTask);
          this.newTaskName = '';
        })
      }
    }
    .height('100%')
    .width('100%')
    .alignItems(HorizontalAlign.Start)
    .margin({ left: 15 })
  }
}
```

### 效果图展示
![todolist](./figures/MVVMV2-todolist.gif)

## 重构代码以符合MVVM架构

前面的例子通过使用一系列的状态管理装饰器，实现了todolist中的数据同步与UI更新。然而，随着应用功能的复杂化，代码的结构变得难以维护，Model、View和ViewModel的职责没有完全分离，存在耦合。为了更好地组织代码和提升可维护性，使用MVVM模式重构代码，进一步将数据层（Model）、逻辑层（ViewModel）和展示层（View）分离。

### 重构后的代码结构
```
/src
├── /main
│   ├── /ets
│   │   ├── /entryability
│   │   ├── /model
│   │   │   ├── TaskListModel.ets
│   │   │   └── TaskModel.ets
│   │   ├── /pages
│   │   │   ├── SettingPage.ets
│   │   │   └── TodoListPage.ets
│   │   ├── /settingability
│   │   ├── /view
│   │   │   ├── BottomView.ets
│   │   │   ├── ListView.ets
│   │   │   └── TitleView.ets
│   │   ├── /viewmodel
│   │   │   ├── TaskListViewModel.ets
│   │   │   └── TaskViewModel.ets
│   └── /resources
│       ├── ...
├─── ... 
```

### Model层
Model层负责管理应用的数据及其业务逻辑，通常与后端或数据存储进行交互。在todolist应用中，Model层的主要职责是存储任务数据、加载任务列表，并提供数据操作的接口，而不直接涉及UI展示。

- TaskModel：单个任务的基本数据结构，包含任务名称和完成状态。

```ts
// src/main/ets/model/TaskModel.ets

export default class TaskModel {
  taskName: string = 'Todo';
  isFinish: boolean = false;
}
```

- TaskListModel：任务的集合，提供从本地加载任务数据的功能。
```ts
// src/main/ets/model/TaskListModel.ets

import { common } from '@kit.AbilityKit';
import util from '@ohos.util';
import TaskModel from'./TaskModel';

export default class TaskListModel {
  tasks: TaskModel[] = [];

  constructor(tasks: TaskModel[]) {
    this.tasks = tasks;
  }

  async loadTasks(context: common.UIAbilityContext){
    let getJson = await context.resourceManager.getRawFileContent('defaultTasks.json');
    let textDecoderOptions: util.TextDecoderOptions = { ignoreBOM : true };
    let textDecoder = util.TextDecoder.create('utf-8',textDecoderOptions);
    let result = textDecoder.decodeToString(getJson);
    this.tasks =JSON.parse(result).map((task: TaskModel)=>{
      let newTask = new TaskModel();
      newTask.taskName = task.taskName;
      newTask.isFinish = task.isFinish;
      return newTask;
    });
  }
}
```

### ViewModel层

ViewModel层管理UI状态和业务逻辑，连接Model和View。通过监控Model数据变化，处理应用逻辑，将数据同步到View层，从而实现UI的自动更新。使用ViewModel实现数据与视图解耦，提高代码可读性和可维护性。

- TaskViewModel：封装单个任务的数据和状态变更逻辑，通过状态装饰器监控数据的变化。

```ts
// src/main/ets/viewmodel/TaskViewModel.ets

import TaskModel from '../model/TaskModel';

@ObservedV2
export default class TaskViewModel {
  @Trace taskName: string = 'Todo';
  @Trace isFinish: boolean = false;

  updateTask(task: TaskModel) {
    this.taskName = task.taskName;
    this.isFinish = task.isFinish;
  }

  updateIsFinish(): void {
    this.isFinish = !this.isFinish;
  }
}
```

- TaskListViewModel：封装了任务列表以及管理功能，包括加载任务、批量更新任务状态，以及添加和删除任务。

```ts
// src/main/ets/viewmodel/TaskListViewModel.ets

import { common } from '@kit.AbilityKit';
import { Type } from '@kit.ArkUI';
import TaskListModel from '../model/TaskListModel';
import TaskViewModel from'./TaskViewModel';

@ObservedV2
export default class TaskListViewModel {
  @Type(TaskViewModel)
  @Trace tasks: TaskViewModel[] = [];

  async loadTasks(context: common.UIAbilityContext) {
    let taskList = new TaskListModel([]);
    await taskList.loadTasks(context);
    for(let task of taskList.tasks){
      let taskViewModel = new TaskViewModel();
      taskViewModel.updateTask(task);
      this.tasks.push(taskViewModel);
    }
  }

  finishAll(ifFinish: boolean): void {
    for(let task of this.tasks){
      task.isFinish = ifFinish;
    }
  }

  addTask(newTask: TaskViewModel): void {
    this.tasks.push(newTask);
  }

  removeTask(removedTask: TaskViewModel): void {
    this.tasks.splice(this.tasks.indexOf(removedTask), 1)
  }
}
```

### View层

View层负责应用程序的UI展示和与用户的交互。它只关注如何渲染用户界面和展示数据，不包含业务逻辑。所有的数据状态和逻辑都来自ViewModel层，View层通过接收ViewModel传递的状态数据进行渲染，确保视图和数据分离。

- TitleView：负责展示应用的标题和未完成任务的统计信息。

```ts
// src/main/ets/view/TitleView.ets

@ComponentV2
export default struct TitleView {
  @Param tasksUnfinished: number = 0;

  build() {
    Column() {
      Text('待办')
        .fontSize(40)
        .margin(10)
      Text(`未完成任务：${this.tasksUnfinished}`)
        .margin({ left: 10, bottom: 10 })
    }
  }
}
```

- ListView：负责展示任务列表，并根据Setting中的设置筛选是否显示已完成的任务。它依赖于TaskListViewModel来获取任务数据，并通过TaskItem组件进行渲染，包括任务的名称、完成状态以及删除按钮。通过TaskViewModel和TaskListViewModel实现用户的交互，如切换任务完成状态和删除任务。

```ts
// src/main/ets/view/ListView.ets

import TaskViewModel from '../viewmodel/TaskViewModel';
import TaskListViewModel from '../viewmodel/TaskListViewModel';
import { Setting } from '../pages/SettingPage';
import { ActionButton } from './BottomView';

@ComponentV2
struct TaskItem {
  @Param task: TaskViewModel = new TaskViewModel();
  @Event deleteTask: () => void = () => {};
  @Monitor('task.isFinish')
  onTaskFinished(mon: IMonitor) {
    console.log('任务' + this.task.taskName + '的完成状态从' + mon.value()?.before + '变为了' + mon.value()?.now);
  }

  build() {
    Row() {
      // 请开发者自行在src/main/resources/base/media路径下添加finished.png和unfinished.png两张图片，否则运行时会因资源缺失而报错
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
        .margin({ left: 15, right: 10 })
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
        .fontSize(18)
      ActionButton('删除', () => this.deleteTask());
    }
    .height('7%')
    .width('90%')
    .backgroundColor('#90f1f3f5')
    .borderRadius(25)
    .onClick(() => this.task.updateIsFinish())
  }
}

@ComponentV2
export default struct ListView {
  @Param taskList: TaskListViewModel = new TaskListViewModel();
  @Param setting: Setting = new Setting();

  build() {
    Repeat<TaskViewModel>(this.taskList.tasks.filter(task => this.setting.showCompletedTask || !task.isFinish))
      .each((obj: RepeatItem<TaskViewModel>) => {
        TaskItem({
          task: obj.item,
          deleteTask: () => this.taskList.removeTask(obj.item)
        }).margin(5)
      })
  }
}
```

- BottomView：负责提供与任务操作相关的按钮和输入框，如"全部完成"、"全部未完成"，"设置"三个按钮，以及添加新任务的输入框。点击"全部完成"和"全部未完成"时，通过TaskListViewModel更改所有任务的状态。点击"设置"按钮时，会导航到SettingAbility的设置页面。添加新任务时，通过TaskListViewModel新增任务到任务列表中。

```ts
// src/main/ets/view/BottomView.ets

import { common, Want } from '@kit.AbilityKit';
import TaskViewModel from '../viewmodel/TaskViewModel';
import TaskListViewModel from '../viewmodel/TaskListViewModel';

@Builder export function ActionButton(text: string, onClick:() => void) {
  Button(text, { buttonStyle: ButtonStyleMode.NORMAL })
    .onClick(onClick)
    .margin({ left: 10, right: 10, top: 5, bottom: 5 })
}

@ComponentV2
export default struct BottomView {
  @Param taskList: TaskListViewModel = new TaskListViewModel();
  @Local newTaskName: string = '';
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Row() {
        ActionButton('全部完成', (): void => this.taskList.finishAll(true))
        ActionButton('全部未完成', (): void => this.taskList.finishAll(false))
        ActionButton('设置', (): void => {
          let wantInfo: Want = {
            deviceId: '', // deviceId为空表示本设备
            bundleName: 'com.samples.statemgmtv2mvvm', // 替换成AppScope/app.json5里的bundleName
            abilityName: 'SettingAbility',
          };
          this.context.startAbility(wantInfo);
        })
      }
      .margin({ top: 10, bottom: 5 })
      Row() {
        TextInput({ placeholder: '添加新任务', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        ActionButton('+', (): void => {
          let newTask = new TaskViewModel();
          newTask.taskName = this.newTaskName;
          this.taskList.addTask(newTask);
          this.newTaskName = '';
        })
      }
    }
  }
}
```

- TodoListPage：todolist的主页面，包含以上的三个View组件（TitleView、ListView、BottomView），用于统一展示待办事项的各个部分，管理任务列表和用户设置。TodoListPage负责从ViewModel中获取数据，并将数据传递给各个子View组件进行渲染，通过PersistenceV2持久化任务数据，确保数据在应用重启后仍能保持一致。

```ts
// src/main/ets/pages/TodoListPage.ets

import TaskListViewModel from '../viewmodel/TaskListViewModel';
import { common } from '@kit.AbilityKit';
import { AppStorageV2, PersistenceV2 } from '@kit.ArkUI';
import { Setting } from '../pages/SettingPage';
import TitleView from '../view/TitleView';
import ListView from '../view/ListView';
import BottomView from '../view/BottomView';

@Entry
@ComponentV2
struct TodoList {
  @Local taskList: TaskListViewModel = PersistenceV2.connect(TaskListViewModel, 'TaskList', () => new TaskListViewModel())!;
  @Local setting: Setting = AppStorageV2.connect(Setting, 'Setting', () => new Setting())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  async aboutToAppear() {
    this.taskList = PersistenceV2.connect(TaskListViewModel, 'TaskList', () => new TaskListViewModel())!;
    if (this.taskList.tasks.length === 0) {
      await this.taskList.loadTasks(this.context);
    }
  }

  @Computed
  get tasksUnfinished(): number {
    return this.taskList.tasks.filter(task => !task.isFinish).length;
  }

  build() {
    Column() {
      TitleView({ tasksUnfinished: this.tasksUnfinished })
      ListView({ taskList: this.taskList, setting: this.setting });
      BottomView({ taskList: this.taskList });
    }
    .height('100%')
    .width('100%')
    .alignItems(HorizontalAlign.Start)
    .margin({ left: 15 })
  }
}
```

- SettingPage：设置页面，负责管理是否显示已完成任务的设置。通过AppStorageV2应用全局存储用户的设置，用户通过Toggle开关切换showCompletedTask状态。

```ts
// src/main/ets/pages/SettingPage.ets

import { AppStorageV2 } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

@ObservedV2
export class Setting {
  @Trace showCompletedTask: boolean = true;
}

@Entry
@ComponentV2
struct SettingPage {
  @Local setting: Setting = AppStorageV2.connect(Setting, 'Setting', () => new Setting())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build(){
    Column(){
      Text('设置')
        .fontSize(40)
        .margin({ bottom: 10 })
      Row() {
        Text('显示已完成任务');
        Toggle({ type: ToggleType.Switch, isOn:this.setting.showCompletedTask })
          .onChange((isOn) => {
            this.setting.showCompletedTask = isOn;
          })
      }
      Button('返回待办')
        .onClick(()=>this.context.terminateSelf())
        .margin({ top: 10 })
    }
    .alignItems(HorizontalAlign.Start)
  }
}
```

## 总结

本教程通过待办事项应用示例，引入状态管理V2装饰器，通过代码重构实现MVVM架构。最终，将数据、逻辑和视图分层，使得代码结构更加清晰、易于维护。合理地使用Model、View和ViewModel，可以帮助开发者更好地理解MVVM模式，并能将其灵活应用到自己项目的开发中，从而提高开发效率和代码质量，实现高效的数据与UI同步，简化开发流程。

## 代码示例
[完整源码](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/StateMgmtV2MVVM/entry)
