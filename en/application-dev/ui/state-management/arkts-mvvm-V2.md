# MVVM (V2)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @katabanga-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

## Overview

During application development, UI updates need to be synchronized in real time with data state changes. This synchronization usually determines the performance and user experience of applications. To reduce the complexity of data and UI synchronization, ArkUI uses the Model-View-ViewModel (MVVM) architecture. The MVVM divides an application into three core parts: Model, View, and ViewModel to separate data, views, and logic. In this mode, the UI can be automatically updated with the state change without manual processing, thereby more efficiently managing the binding and update of data and views.

- Model: stores and manages application data and service logic without directly interacting with the UI. Generally, Model obtains data from back-end APIs and serves as the data basis of applications, which ensures data consistency and integrity.
- View: displays data on the UI and interacts with users. No service logic is contained. It dynamically updates the UI by binding the data provided by the ViewModel.
- ViewModel: manages UI state and interaction logic. As a bridge between Model and View, ViewModel monitors data changes in Model, notifies views to update the UI, processes user interaction events, and converts the events into data operations.

## Implementing ViewModel Through V2

In the MVVM mode, ViewModel manages data state and automatically updates views when data changes. The state management of V2 (referred to as V2) in ArkUI provides various decorators and tools to help you share data between custom components and ensure that data changes are automatically synchronized to the UI. Common state management decorators include \@Local, \@Param, \@Event, \@ObservedV2, and \@Trace. In addition, V2 provides **AppStorageV2** and **PersistenceV2** as global state storage tools for state sharing between applications and persistent storage.

This section uses a simple to-do list as an example to introduce the decorators and tools of V2 and gradually extend functions based on a basic static to-do list. With step-by-step extension, you can gradually understand and grasp the usage of each decorator.

### Basic Example

First, start with a static to-do list with no state change or dynamic interaction.

**Example 1**

```ts
// src/main/ets/pages/1-Basic.ets

@Entry
@ComponentV2
struct TodoList {
  build() {
    Column() {
      Text('To-Dos')
        .fontSize(40)
        .margin({ bottom: 10 })
      Text('Task1')
      Text('Task2')
      Text('Task3')
    }
  }
}
```

### Implementing Component State Observation with \@Local

After the static to-do list is displayed, it needs to respond to interactions and be dynamically updated so that users can change the task completion status. To achieve this, the \@Local decorator is used to manage the component's internal state: When the variable decorated with \@Local changes, the bound UI component is re-rendered.

In Example 2, an \@Local decorated **isFinish** property is added to indicate whether the task is finished. Two icons, **finished.png** and **unfinished.png**, display the task status. When a user taps a to-do item, the **isFinish** state changes, updating the icon and adding a strikethrough to the task text.

**Example 2**

```ts 
// src/main/ets/pages/2-Local.ets

@Entry
@ComponentV2
struct TodoList {
  @Local isFinish: boolean = false;

  build() {
    Column() {
      Text('To-Dos')
        .fontSize(40)
        .margin({ bottom: 10 })
      Row() {
        // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
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

### Implementing Component Input with \@Param
After implementing local task status switching, you can enhance the to-do list's flexibility by dynamically setting each task's name (instead of hardcoding it). The \@Param decorator enables this purpose: Variables decorated with @Param in a child component can receive values passed from the parent component, implementing one-way data synchronization. By default, \@Param is read-only. To locally update the input value in the child component, combine \@Param with \@Once.

In Example 3, each to-do item is abstracted into a **TaskItem** component. The \@Param decorated **taskName** attribute receives the task name from the parent **TodoList** component. This makes the **TaskItem** component flexible and reusable, as it can accept and render different task names. In addition, the **isFinish** property, decorated with both \@Param and \@Once, can be updated locally in the child component after receiving its initial value.

**Example 3**

```ts
// src/main/ets/pages/3-Param.ets

@ComponentV2
struct TaskItem {
  @Param taskName: string = '';
  @Param @Once isFinish: boolean = false;

  build() {
    Row() {
      // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
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
      Text('To-Dos')
        .fontSize(40)
        .margin({ bottom: 10 })
      TaskItem({ taskName: 'Task 1', isFinish: false })
      TaskItem({ taskName: 'Task 2', isFinish: false })
      TaskItem({ taskName: 'Task 3', isFinish: false })
    }
  }
}
```

### Implementing Component Output with \@Event

With dynamic task names now supported, the task list content remains fixed. To enable dynamic expansion of the task list, we need to add task creation and deletion functionality. This is where the \@Event decorator comes in. It allows child components to output data to parent components.

In Example 4, a delete button is added to each task item, and a feature to add new tasks is included at the bottom of the list. When the delete button in the child **TaskItem** component is clicked, a **deleteTask** event is triggered and passed to the parent **TodoList** component. The parent component then responds by removing the corresponding task from the list. By combining \@Param (for receiving data) and \@Event (for passing events), child components can achieve two-way data synchronization with parent components, receiving input and sending outputs.

**Example 4**

```ts
// src/main/ets/pages/4-Event.ets

@ComponentV2
struct TaskItem {
  @Param taskName: string = '';
  @Param @Once isFinish: boolean = false;
  @Event deleteTask: () => void = () => {};

  build() {
    Row() {
      // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
      Image(this.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.taskName)
        .decoration({ type: this.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('Delete')
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
      Text('To-Dos')
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
        TextInput({ placeholder: 'Add a new task', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('+')
          .onClick(() => {
            this.tasks.push(this.newTaskName);
            this.newTaskName = '';
          })
      }
    }
  }
}
```

### Implementing Component Reuse with Repeat

After the task creation and deletion functionality is added, you may want to efficiently render multiple identical child components as the task list grows. This is where **Repeat** comes in handy.

**Repeat** provides optimized list rendering with two distinct modes:
- Lazy loading mode: suitable for large datasets. It loads components on demand within scrollable containers, significantly reducing memory usage and improving rendering efficiency.
- Eager loading mode: ideal for small datasets. It renders all components at once and only updates changed items when data updates, avoiding unnecessary full re-renders.

In Example 5, the eager loading mode is used due to the small number of task items. A **tasks** array is created, and the **Repeat** method iterates over each item in the array to dynamically generate and reuse **TaskItem** components. This approach enables efficient reuse of existing components during task additions or deletions, reducing redundant re-renders and improving code reusability and rendering efficiency.

**Example 5**

```ts
// src/main/ets/pages/5-Repeat.ets

@ComponentV2
struct TaskItem {
  @Param taskName: string = '';
  @Param @Once isFinish: boolean = false;
  @Event deleteTask: () => void = () => {};

  build() {
    Row() {
      // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
      Image(this.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.taskName)
        .decoration({ type: this.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('Delete')
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
      Text('To-Dos')
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
        TextInput({ placeholder: 'Add a new task', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('+')
          .onClick(() => {
            this.tasks.push(this.newTaskName);
            this.newTaskName = '';
          })
      }
    }
  }
}
```

### Implementing Deep Property Observation with \@ObservedV2 and \@Trace

As more features are implemented, task list management becomes increasingly complex. To better handle task data changes—especially in multi-level nested structures—you must ensure that property changes can be deeply observed and trigger automatic UI re-renders. This is where the \@ObservedV2 and \@Trace decorators come into play. Unlike \@Local (which only observes changes to the object itself and its first-level properties), \@ObservedV2 and \@Trace are better suited for complex scenarios involving multi-level nesting and inheritance. In a class decorated with @ObservedV2, when a property decorated with @Trace changes, the UI component bound to that property is re-rendered automatically.

In Example 6, the **Task** class is abstracted and decorated with \@ObservedV2, while its **isFinish** property is decorated with \@Trace. The **Task** class is nested within the **TaskItem** component, which in turn is nested within the **TodoList** component. At the outermost **TodoList** level, **All Finished** and **All Unfinished** buttons are added. Clicking these buttons directly updates the **isFinish** property of the innermost **Task** class instances. Thanks to \@ObservedV2 and \@Trace, these changes are detected, triggering re-renders of the UI components bound to **isFinish**, thereby enabling deep observation of nested class properties.

**Example 6**

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
      // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('Delete')
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
      Text('To-Dos')
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
        Button('All Finished')
          .onClick(() => this.finishAll(true))
        Button('All Unfinished')
          .onClick(() => this.finishAll(false))
      }
      Row() {
        TextInput({ placeholder: 'Add a new task', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('+')
          .onClick(() => {
            this.tasks.push(new Task(this.newTaskName, false));
            this.newTaskName = '';
          })
      }
    }
  }
}
```

### Implementing State Listening and Computed Properties with \@Monitor and \@Computed

Building on the current task list functionality, you can enhance the user experience with additional features, such as listening for task status changes and dynamically calculating the number of unfinished tasks. This is where the \@Monitor and \@Computed decorators prove useful: \@Monitor is used to listen for deep changes in state variables, triggering custom callback methods when properties are modified. \@Computed decorates getter methods to detect changes in computed properties. It recalculates the value only once when dependencies change, reducing the overhead of redundant computations.

In Example 7, \@Monitor is applied to listen for deep changes in the **isFinish** property of the **task** object within **TaskItem**. When the task status changes, the **onTasksFinished** callback is invoked to log the update. In addition, the number of unfinished tasks in **TodoList** is recorded using \@Computed to decorate **tasksUnfinished**, whose value automatically recalculates whenever task statuses change. Together, these two decorators enable deep listening of state variables and efficient computation of derived properties.

**Example 7**

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
    console.log('The status of' + this.task.taskName + 'has changed from' + mon.value()?.before + 'to' + mon.value()?.now);
  }

  build() {
    Row() {
      // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('Delete')
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
      Text('To-Dos')
        .fontSize(40)
        .margin({ bottom: 10 })
      Text(`Unfinished: ${this.tasksUnfinished}`)
      Repeat<Task>(this.tasks)
        .each((obj: RepeatItem<Task>) => {
          TaskItem({
            task: obj.item,
            deleteTask: () => this.tasks.splice(this.tasks.indexOf(obj.item), 1)
          })
        })
      Row() {
        Button('All Finished')
          .onClick(() => this.finishAll(true))
        Button('All Unfinished')
          .onClick(() => this.finishAll(false))
      }
      Row() {
        TextInput({ placeholder: 'Add a new task', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('+')
          .onClick(() => {
            this.tasks.push(new Task(this.newTaskName, false));
            this.newTaskName = '';
          })
      }
    }
  }
}
```

### Implementing Global UI State Storage with AppStorageV2

As the to-do list functionality continues to expand, an application may involve multiple pages or functional modules that require access to shared global state. For example, a to-do list application might include a settings page linked to the home page, which requires cross-page state sharing. To address this, use AppStorageV2, which stores and shares an application's global state across multiple UIAbility instances.

In Example 8, a **SettingAbility** is added to load **SettingPage**, which contains a **Setting** class. This class includes a **showCompletedTask** property that controls whether finished tasks are displayed, with a switch allowing users to modify the setting. The two abilities share data through AppStorageV2 using the key **Setting**, where the corresponding data is an instance of the **Setting** class. When AppStorageV2 first connects to **Setting**, if no stored data exists, it creates a **Setting** instance by default, with **showCompletedTask** set to **true**. After users adjust settings on **SettingPage**, the task list on the home page updates accordingly. With **AppStorageV2**, data can be shared across abilities and pages.

**Example 8**

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
    console.log('The status of' + this.task.taskName + 'has changed from' + mon.value()?.before + 'to' + mon.value()?.now);
  }

  build() {
    Row() {
      // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('Delete')
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
      Text('To-Dos')
        .fontSize(40)
        .margin({ bottom: 10 })
      Text(`Unfinished: ${this.tasksUnfinished}`)
      Repeat<Task>(this.tasks.filter(task => this.setting.showCompletedTask || !task.isFinish))
        .each((obj: RepeatItem<Task>) => {
          TaskItem({
            task: obj.item,
            deleteTask: () => this.tasks.splice(this.tasks.indexOf(obj.item), 1)
          })
        })
      Row() {
        Button('All Finished')
          .onClick(() => this.finishAll(true))
        Button('All Unfinished')
          .onClick(() => this.finishAll(false))
        Button('Settings')
          .onClick(() => {
            let wantInfo: Want = {
              deviceId: '', // An empty deviceId indicates the local device.
              bundleName: 'com.samples.statemgmtv2mvvm', // Replace it with the bundle name in AppScope/app.json5.
              abilityName: 'SettingAbility',
            };
            this.context.startAbility(wantInfo);
          })
      }
      Row() {
        TextInput({ placeholder: 'Add a new task', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('+')
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
// SettingPage code of the SettingAbility
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
      Text('Settings')
        .fontSize(40)
        .margin({ bottom: 10 })
      Row() {
        Text('Show finished');
        Toggle({ type: ToggleType.Switch, isOn:this.setting.showCompletedTask })
          .onChange((isOn) => {
            this.setting.showCompletedTask = isOn;
          })
      }
      Button('Back')
        .onClick(()=>this.context.terminateSelf())
        .margin({ top: 10 })
    }
    .alignItems(HorizontalAlign.Start)
  }
}
```

### Implementing Persistent UI State with PersistenceV2

To ensure users can view their previous task states after restarting the application, a persistent storage solution is needed. PersistenceV2 enables data to be stored persistently on the device's disk. Unlike AppStorageV2, which uses runtime memory, PersistenceV2 ensures data remains intact even after the application is restarted.

In Example 9, a **TaskList** class is created to store all task information persistently through PersistenceV2, using the key **TaskList** (with the corresponding data being an instance of the **TaskList** class). When PersistenceV2 connects to **TaskList** for the first time, if no existing data is found, it initializes a **TaskList** instance with an empty tasks array by default. In the **aboutToAppear** lifecycle function, if **TaskList** connected to PersistenceV2 contains no task data, tasks are loaded from the local file **defaultTasks.json** and stored in PersistenceV2. Subsequent changes to each task's completion status are synchronized to PersistenceV2. This ensures all task data remains unchanged even after the application is restarted, achieving persistent storage of the application's state.

**Example 9**

```ts
// src/main/ets/pages/9-PersistenceV2.ets

import { AppStorageV2, PersistenceV2, Type } from '@kit.ArkUI';
import { common, Want } from '@kit.AbilityKit';
import { Setting } from './SettingPage';
import util from '@ohos.util';

@ObservedV2
class Task {
  // The constructor is not implemented because @Type does not support constructors with parameters.
  @Trace taskName: string = 'Todo';
  @Trace isFinish: boolean = false;
}

@ObservedV2
class TaskList {
  // For complex objects, use the @Type decorator to ensure successful serialization.
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
    console.log('The status of' + this.task.taskName + 'has changed from' + mon.value()?.before + 'to' + mon.value()?.now);
  }

  build() {
    Row() {
      // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
      Button('Delete')
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
      Text('To-Dos')
        .fontSize(40)
        .margin({ bottom: 10 })
      Text(`Unfinished: ${this.tasksUnfinished}`)
      Repeat<Task>(this.taskList.tasks.filter(task => this.setting.showCompletedTask || !task.isFinish))
        .each((obj: RepeatItem<Task>) => {
          TaskItem({
            task: obj.item,
            deleteTask: () => this.taskList.tasks.splice(this.taskList.tasks.indexOf(obj.item), 1)
          })
        })
      Row() {
        Button('All Finished')
          .onClick(() => this.finishAll(true))
        Button('All Unfinished')
          .onClick(() => this.finishAll(false))
        Button('Settings')
          .onClick(() => {
            let wantInfo: Want = {
              deviceId: '', // An empty deviceId indicates the local device.
              bundleName: 'com.samples.statemgmtv2mvvm', // Replace it with the bundle name in AppScope/app.json5.
              abilityName: 'SettingAbility',
            };
            this.context.startAbility(wantInfo);
          })
      }
      Row() {
        TextInput({ placeholder: 'Add a new task', text: this.newTaskName })
          .onChange((value) => this.newTaskName = value)
          .width('70%')
        Button('+')
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

The **defaultTasks.json** file is stored in **src/main/resources/rawfile** directory.
```json
[
  {"taskName": "Learn to develop in ArkTS", "isFinish": false},
  {"taskName": "Exercise", "isFinish": false},
  {"taskName": "Buy some fruits", "isFinish": true},
  {"taskName": "Take a delivery", "isFinish": true},
  {"taskName": "Study", "isFinish": true}
]
```

### Implementing Custom UI Components with \@Builder

As application features expand, repeated UI elements in the code can increase volume and complicate maintenance. To address this, you can use the \@Builder decorator to abstract repetitive UI components into independent builder methods, facilitating reuse and code modularization.

In Example 10, \@Builder is used to define an **ActionButton** API that unifies the management of text, styles, and touch events for various buttons. This simplifies the code and enhances maintainability. In addition, \@Builder enables adjustments to component layouts and styles, such as spacing, colors, and sizes, making the to-do list UI more visually appealing. The result is a fully functional to-do list application with a user-friendly UI.

**Example 10**

```ts
// src/main/ets/pages/10-Builder.ets

import { AppStorageV2, PersistenceV2, Type } from '@kit.ArkUI';
import { common, Want } from '@kit.AbilityKit';
import { Setting } from './SettingPage';
import util from '@ohos.util';

@ObservedV2
class Task {
  // The constructor is not implemented because @Type does not support constructors with parameters.
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
  // For complex objects, use the @Type decorator to ensure successful serialization.
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
    console.log('The status of' + this.task.taskName + 'has changed from' + mon.value()?.before + 'to' + mon.value()?.now);
  }

  build() {
    Row() {
      // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
        .margin({ left : 15, right : 10 })
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
        .fontSize(18)
      ActionButton('Delete', () => this.deleteTask())
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
      Text('To-Dos')
        .fontSize(40)
        .margin(10)
      Text(`Unfinished: ${this.tasksUnfinished}`)
        .margin({ left: 10, bottom: 10 })
      Repeat<Task>(this.taskList.tasks.filter(task => this.setting.showCompletedTask || !task.isFinish))
        .each((obj: RepeatItem<Task>) => {
          TaskItem({
            task: obj.item,
            deleteTask: () => this.taskList.tasks.splice(this.taskList.tasks.indexOf(obj.item), 1)
          }).margin(5)
        })
      Row() {
        ActionButton('All Finished', (): void => this.finishAll(true))
        ActionButton('All Unfinished', (): void => this.finishAll(false))
        ActionButton('Settings', (): void => {
          let wantInfo: Want = {
            deviceId: '', // An empty deviceId indicates the local device.
            bundleName: 'com.samples.statemgmtv2mvvm', // Replace it with the bundle name in AppScope/app.json5.
            abilityName: 'SettingAbility',
          };
          this.context.startAbility(wantInfo);
        })
      }
      .margin({ top: 10, bottom: 5 })
      Row() {
        TextInput({ placeholder: 'Add a new task', text: this.newTaskName })
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

### Display Effect
![todolist](./figures/MVVMV2-todolist.gif)

## Reconstructing Code to Comply with the MVVM Architecture

The previous examples implement data synchronization and UI re-rendering in the to-do list using an array of state management decorators. However, as application functionality grows more complex, the code structure becomes harder to maintain: The responsibilities of Model, View, and ViewModel are not fully separated, resulting in lingering coupling. To better organize the code and enhance maintainability, you can refactor the code using the MVVM pattern. This further separates the data layer (Model), logic layer (ViewModel), and presentation layer (View), creating a clearer, more maintainable architecture.

### Reconstructed Code Structure
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

### Model
The Model layer manages application data and its service logic, typically interacting with backends or data storage systems. In the to-do list application, the Model layer handles task data storage and task list loading, and provides data operation APIs, with no direct involvement in UI presentation.

- **TaskModel**: basic data structure of a single task, including the task name and completion status.

```ts
// src/main/ets/model/TaskModel.ets

export default class TaskModel {
  taskName: string = 'Todo';
  isFinish: boolean = false;
}
```

- **TaskListModel**: a set of tasks, which provides functionality to load task data from local storage.
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

### ViewModel

The ViewModel layer manages UI state and service logic, acting as a bridge between the Model and View layers. It monitors changes in Model data, processes application logic, and synchronizes data to the View layer, enabling automatic UI re-renders. This layer decouples data from views, enhancing code readability and maintainability.

- **TaskViewModel**: encapsulates the change logic of data and status of a single task, and listens for data changes through the state decorator.

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

- **TaskListViewModel**: encapsulates the task list and its management functionality, including loading tasks, updating task status in batches, adding tasks, and deleting tasks.

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

### View

The View layer is responsible for application UI rendering and user interactions. It focuses solely on how to display the UI and present data, with no inclusion of service logic. All data states and logic are derived from the ViewModel layer. By receiving and rendering state data passed from the ViewModel, the View ensures strict separation of view and data.

- **TitleView**: displays application titles and statistics about unfinished tasks.

```ts
// src/main/ets/view/TitleView.ets

@ComponentV2
export default struct TitleView {
  @Param tasksUnfinished: number = 0;

  build() {
    Column() {
      Text('To-Dos')
        .fontSize(40)
        .margin(10)
      Text(`Unfinished: ${this.tasksUnfinished}`)
        .margin({ left: 10, bottom: 10 })
    }
  }
}
```

- **ListView**: displays the task list and controls visibility of completed tasks based on settings. It depends on **TaskListViewModel** to obtain task data (including the task name, completion status, and delete button), which it renders using the **TaskItem** component. It also uses **TaskViewModel** and **TaskListViewModel** to handle user interactions, such as switching the task completion status and deleting a task.

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
    console.log('The status of' + this.task.taskName + 'has changed from' + mon.value()?.before + 'to' + mon.value()?.now);
  }

  build() {
    Row() {
      // To avoid runtime errors, you must add the finished.png and unfinished.png images to the src/main/resources/base/media directory.
      Image(this.task.isFinish ? $r('app.media.finished') : $r('app.media.unfinished'))
        .width(28)
        .height(28)
        .margin({ left: 15, right: 10 })
      Text(this.task.taskName)
        .decoration({ type: this.task.isFinish ? TextDecorationType.LineThrough : TextDecorationType.None })
        .fontSize(18)
      ActionButton('Delete', () => this.deleteTask());
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

- **BottomView**: provides buttons (**All Finished**, **All Unfinished**, and **Settings**) and the text box for adding a task. Clicking **All Finished** or **All Unfinished** triggers **TaskListViewModel** to update the status of all tasks. Clicking **Settings** opens the **SettingAbility** settings page. Adding a task through the text box triggers **TaskListViewModel** to add the task to the task list.

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
        ActionButton('All Finished', (): void => this.taskList.finishAll(true))
        ActionButton('All Unfinished', (): void => this.taskList.finishAll(false))
        ActionButton('Settings', (): void => {
          let wantInfo: Want = {
            deviceId: '', // An empty deviceId indicates the local device.
            bundleName: 'com.samples.statemgmtv2mvvm', // Replace it with the bundle name in AppScope/app.json5.
            abilityName: 'SettingAbility',
          };
          this.context.startAbility(wantInfo);
        })
      }
      .margin({ top: 10, bottom: 5 })
      Row() {
        TextInput({ placeholder: 'Add a new task', text: this.newTaskName })
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

- **TodoListPage**: represents the main page of the to-do list and integrates the preceding three **View** components (**TitleView**, **ListView**, and **BottomView**) to unify display of all to-do list sections.It manages the task list and settings by obtaining data from ViewModel, passing the data to each child **View** component for rendering, and using PersistenceV2 to persist task data, which ensures consistency after application restarts.

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

- **SettingPage**: represents the settings page for configuring whether to show finished tasks. It uses AppStorageV2 to store the global settings. The user can switch the status of **showCompletedTask** by using the toggle switch.

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
      Text('Settings')
        .fontSize(40)
        .margin({ bottom: 10 })
      Row() {
        Text('Show finished');
        Toggle({ type: ToggleType.Switch, isOn:this.setting.showCompletedTask })
          .onChange((isOn) => {
            this.setting.showCompletedTask = isOn;
          })
      }
      Button('Back')
        .onClick(()=>this.context.terminateSelf())
        .margin({ top: 10 })
    }
    .alignItems(HorizontalAlign.Start)
  }
}
```

## Summary

This guide uses a simple to-do list application to demonstrate the use of V2 decorators and the implementation of the MVVM architecture through code refactoring. By separating data, service logic, and views into distinct layers, you can achieve a clearer code structure that is easier to maintain. By correctly implementing the layered architecture of Model, View, and ViewModel, you can gain a clearer understanding of the MVVM pattern and apply it more effectively. This layered approach delivers multiple practical benefits in real-world projects: It boosts development efficiency, ensures consistent code quality, optimizes the synchronization mechanism between data and the UI, and ultimately streamlines the entire development workflow.
