# MVVM (V2)

## Overview

During application development, UI updates need to be synchronized in real time with data state changes. This synchronization usually determines the performance and user experience of applications. To reduce the complexity of data and UI synchronization, ArkUI uses the Model-View-ViewModel (MVVM) architecture. The MVVM divides an application into three core parts: Model, View, and ViewModel to separate data, views, and logic. In this mode, the UI can be automatically updated with the state change without manual processing, thereby more efficiently managing the binding and update of data and views.

- Model: stores and manages application data and service logic without directly interacting with the UI. Generally, Model obtains data from back-end APIs and serves as the data basis of applications, which ensures data consistency and integrity.
- View: displays data on the UI and interacts with users. No service logic is contained. It dynamically updates the UI by binding the data provided by the ViewModel.
- ViewModel: manages UI state and interaction logic. As a bridge between Model and View, ViewModel monitors data changes in Model, notifies views to update the UI, processes user interaction events, and converts the events into data operations.


## Implementing ViewModel Through V2

In the MVVM mode, the ViewModel plays an important role in managing data state and automatically updating views when data changes. The state management of V2 (referred to as V2) in ArkUI provides various decorators and tools to help you share data between custom components and ensure that data changes are automatically synchronized to the UI. Common state management decorators include \@Local, \@Param, \@Event, \@ObservedV2, and \@Trace. In addition, V2 provides **AppStorageV2** and **PersistenceV2** as global state storage tools for state sharing between applications and persistent storage.

This section uses a simple to-do list as an example to introduce the decorators and tools of V2 and gradually extend functions based on a basic static to-do list. With step-by-step extension, you can gradually understand and grasp the usage of each decorator.

### Basic Example

First, start with the most basic static to-do list with no state change or dynamic interaction.

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

### Adding \@Local to Observe the Internal State of Components

After the static to-do list is displayed, it needs to respond to interactions and be dynamically updated so that users can change the task completion status. Therefore, the \@Local decorator is introduced to manage the internal state of the component. When the variable decorated by \@Local changes, the bound UI component is re-rendered.

In this example, the **isFinish** property decorated by \@Local is added to indicate whether the task is finished. Two icons, **finished.png** and **unfinished.png**, are provided to display the task status. When a user taps a to-do item, the **isFinish** state is switched to change the icon and add a strikethrough.

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
        // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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

### Adding \@Param to Enable Components to Receive External Input
After the local status of the task is switched, to enhance flexibility of the to-do list, a name of each task should be dynamically set, instead of being fixed in code. After the \@Param decorator is introduced, the decorated variable of the child component can receive the value passed by the parent component, implementing one-way data synchronization. By default, \@Param is read-only. To locally update the input value in the child component, use \@Param and \@Once.

In this example, each to-do item is abstracted as a **TaskItem** component. The **taskName** attribute decorated by \@Param passes the task name from the parent component **TodoList** so that the **TaskItem** component is flexible and reusable, and can receive and render different task names. After receiving the initial value, the **isFinish** property decorated by \@Param and \@Once can be updated in the child component.

```ts
// src/main/ets/pages/3-Param.ets

@ComponentV2
struct TaskItem {
  @Param taskName: string = '';
  @Param @Once isFinish: boolean = false;

  build() {
    Row() {
      // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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

### Adding \@Event to Enable Components to Output Externally

After the task name can be dynamically set, the content of the task list is still fixed. You need to add the functions of adding and deleting task items to dynamically expand the task list. Therefore, use the \@Event decorator to enable the child component to output data to the parent component.

In this example, the delete button is added to each task item, and the function of adding a new task is added to the bottom of the task list. When the delete button of the child component **TaskItem** is clicked, the **deleteTask** event is triggered and passed to the parent component **TodoList**. Then the parent component responds and removes the task from the list. By using \@Param and \@Event, the child component can receive data from and pass events back to the parent component to implement two-way data synchronization.

```ts
// src/main/ets/pages/4-Event.ets

@ComponentV2
struct TaskItem {
  @Param taskName: string = '';
  @Param @Once isFinish: boolean = false;
  @Event deleteTask: () => void = () => {};

  build() {
    Row() {
      // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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

### Adding Repeat to Implement Child Component Reuse

As the number of task list items increases after the function of adding or deleting tasks is added, a method for efficiently rendering multiple child components with the same structure is required to improve the performance of the UI. Therefore, the **Repeat** method is introduced to optimize the rendering process of the task list. **Repeat** supports two modes: virtualScroll is applicable to scenarios with a large amount of data. It loads components as required in scrolling containers, greatly saving memory and improving rendering efficiency; non-virtualScroll is applicable to scenarios with a small amount of data. All components are rendered at a time, and only the changed data is updated, avoiding overall re-rendering.

In this example, the non-virtualScroll mode is selected because of few task items. Create an array **tasks**, use the **Repeat** method to iterate each item in the array, and dynamically generate and reuse the **TaskItem** component. In this way, you can efficiently reuse existing components when adding or deleting a task to avoid repeated component renderings, improving code reusability and rendering efficiency.

```ts
// src/main/ets/pages/5-Repeat.ets

@ComponentV2
struct TaskItem {
  @Param taskName: string = '';
  @Param @Once isFinish: boolean = false;
  @Event deleteTask: () => void = () => {};

  build() {
    Row() {
      // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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

### Adding \@ObservedV2 and \@Trace to Observe Changes of Class Properties

After multiple functions are implemented, the management of the task list becomes more and more complex. To better process task data changes, especially in multi-level nested structures, you should ensure that property changes can be deeply observed and the UI can be automatically re-rendered. In this case, the \@ObservedV2 and \@Trace decorators are introduced. Compared with \@Local, which can only observe the changes of the object itself and its first level, \@ObservedV2 and \@Trace are more suitable for complex structure scenarios such as multi-level nesting and inheritance. In the \@ObservedV2 decorated class, when the \@Trace decorated property changes, the UI component bound to the attribute is re-rendered.

In this example, **Task** is abstracted as a class and marked by \@ObservedV2. \@Trace is used to mark the **isFinish** property. **Task** is nested in **TaskItem** when the later is nested in the **TodoList** component. In the outermost **TodoList**, the "All finished" and "All unfinished" buttons are added. Each time these buttons are clicked, the **isFinish** property of the innermost **Task** class is directly updated. \@ObservedV2 and \@Trace ensure that the re-render of the corresponding UI component of **isFinish** can be observed, thereby implementing in-depth observation of nested class properties.

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
      // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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

### Adding \@Monitor and \@Computed to Listen for State Variables and Computation Properties

Based on the current task list function, some additional functions can be added to improve user experience, such as listening for task status changes and dynamic computation of the number of unfinished tasks. Therefore, the \@Monitor and \@Computed decorators are introduced. \@Monitor is used to listen for in-depth state variables and trigger the custom callback method when the property changes. \@Computed is used to decorate the **get** method and detect the changes of computed properties. When the value changes, it is computed only once to reduce the overhead of repeated computation.

In this example, \@Monitor is used to listen for the in-depth **isFinish** property of **task** in **TaskItem**. When the task status changes, the **onTasksFinished** callback is invoked to output a log to record the change. In addition, the number of unfinished tasks in the **TodoList** is recorded. Use \@Computed to decorate **tasksUnfinished**. The value is automatically recomputed when the task status changes. The two decorators are used to implement in-depth listening and efficient computation of state variables.

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
      // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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
      Text('Unfinished: ${this.tasksUnfinished}')
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

### Adding AppStorageV2 to Store Global UI State of Applications

With continuous enhancement of a to-do list function, an application may involve a plurality of pages or function modules. In this case, a global state needs to be shared with multiple pages. For example, in a to-do list application, you can add a settings page to link with the home page. To implement cross-page state sharing, **AppStorageV2** is introduced to store and share the global state of an application among multiple UIAbility instances.

In this example, **SettingAbility** is added to load **SettingPage**. **SettingPage** contains a **Setting** class, in which the **showCompletedTask** property is used to control whether to display finished tasks. Users can switch the option by using a switch. Two abilities share the data through **AppStorageV2** with the key **Setting**, and the corresponding data is of the **Setting** class. When **AppStorageV2** connects to **Setting** for the first time, if no stored data exists, a **Setting** instance whose **showCompletedTask** is **true** is created by default. After you change the settings on the settings page, the task list on the home page is updated accordingly. With **AppStorageV2**, data can be shared across abilities and pages.

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
      // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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
  private context = getContext(this) as common.UIAbilityContext;

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
      Text('Unfinished: ${this.tasksUnfinished}')
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
// SettingPage code of the SettingAbility.
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
  private context = getContext(this) as common.UIAbilityContext;

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

### Adding PersistenceV2 to Implement Persistent UI State Storage

To ensure that the user can still view the previous task status when the application is restarted, a persistent storage solution can be introduced. **PersistenceV2** can persistently store data on device disks. Different from the runtime memory of **AppStorageV2**, **PersistenceV2** ensures that data remains unchanged even if an application is closed and restarted.

In this example, a **TaskList** class is created to persistently store all task information through **PersistenceV2** with the key **TaskList**, and the corresponding data is of the **TaskList** class. When **PersistenceV2** connects to the **TaskList** for the first time, if there is no data, a **TaskList** instance whose array **tasks** is empty by default. In the **aboutToAppear** lifecycle function, if **TaskList** connected to **PersistenceV2** does not store task data, tasks are loaded from the local file **defaultTasks.json** and stored in **PersistenceV2**. After that, the completion status of each task is synchronized to **PersistenceV2**. In this way, even if the application is closed and restarted, all task data remains unchanged, thereby storing application status persistently.

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
  // Complex objects need to be decorated by @Type to ensure successful serialization.
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
      // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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
  private context = getContext(this) as common.UIAbilityContext;

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
      Text('Unfinished: ${this.tasksUnfinished}')
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

### Adding \@Builder to Customize a Constructor

As application functions gradually expand, some UI elements in the code start to be repeated, increasing the code volume and making maintenance more complex. To solve this problem, you can use the \@Builder decorator to abstract repeated UI components into an independent **builder** method, facilitating reuse and code modularization.

In this example, \@Builder is used to define the **ActionButton** method to manage the text, style, and touch events of various buttons in a unified manner, making the code simpler and improving the code maintainability. On this basis, \@Builder adjusts the layout and style, such as spacing, color, and size of the components, to make the to-do list UI more attractive and present a to-do list application with complete functions and a user-friendly UI.

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
  // Complex objects need to be decorated by @Type to ensure successful serialization.
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
      // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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
  private context = getContext(this) as common.UIAbilityContext;

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
      Text('Unfinished: ${this.tasksUnfinished}')
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

The preceding example uses a series of state management decorators to implement data synchronization and UI re-render in the to-do list. However, as application functions become more complex, the code structure becomes difficult to maintain. The responsibilities of Model, View, and ViewModel are not completely separated, and there is still some coupling. To better organize code and improve maintainability, the MVVM mode is used to reconstruct code to further separate the data layer (Model), logic layer (ViewModel), and display layer (View).

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
The Model layer manages application data and its service logic, and usually interacts with the backend or data storage. In the To-Do-List application, the Model layer is used to store task data, load the task list, and provide APIs for data operations, without involving UI display.

- **TaskModel**: basic data structure of a single task, including the task name and completion status.

```ts
// src/main/ets/model/TaskModel.ets

export default class TaskModel {
  taskName: string = 'Todo';
  isFinish: boolean = false;
}
```

- **TaskListModel**: a set of tasks, which provides the function of loading task data from the local host.
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

The ViewModel layer manages the UI state and service logic, and functions as a bridge between Model and View. ViewModel monitors Model data changes, processes application logic, and synchronizes data to the View layer to implement automatic UI re-render. This layer decouples data from views, improving code readability and maintainability.

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

- **TaskListViewModel**: encapsulates the task list and management functions, including loading tasks, updating task status in batches, and adding and deleting tasks.

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

The View layer is responsible for UI display of applications and interaction with users. It focuses only on how to render the UI and display data without containing service logic. All data state and logic come from the ViewModel layer. View receives the state data passed by ViewModel for rendering, ensuring that the view and data are separated.

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
      Text('Unfinished: ${this.tasksUnfinished}')
        .margin({ left: 10, bottom: 10 })
    }
  }
}
```

- **ListView**: displays the task list and determines whether to show finished tasks based on the settings. It depends on **TaskListViewModel** to obtain task data and renders the data, including the task name, completion status, and delete button, through the **TaskItem** component. In addition, **TaskViewModel** and **TaskListViewModel** are used to implement user interaction, such as switching the task completion status and deleting a task.

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
      // Add the finished.png and unfinished.png images to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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

- **BottomView**: provides buttons (**All Finished**, **All Unfinished**, and **Settings**) and the text box for adding a task. When a user clicks **All Finished** or **All Unfinished**, **TaskListViewModel** will change the status of all tasks. When a user clicks **Settings**, the settings page of the SettingAbility is displayed. When a user adds a task, **TaskListViewModel** will add the task to the task list.

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
  private context = getContext() as common.UIAbilityContext;

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

- **TodoListPage**: main page of the to-do list, which contains the preceding three **View** components (**TitleView**, **ListView**, and **BottomView**) and is used to display all parts of the to-do list in a unified manner and manage the task list and settings. It obtains data from ViewModel, passes the data to each child component of View for rendering, and persists task data through **PersistenceV2** to ensure data consistency after the application is restarted.

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
  private context = getContext(this) as common.UIAbilityContext;

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

- **SettingPage**: settings page, which is used to set whether to show finished tasks. It uses **AppStorageV2** to store the global settings. The user can switch the status of **showCompletedTask** by using the toggle switch.

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
  private context = getContext(this) as common.UIAbilityContext;

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

This guide uses a simple to-do list application as an example to introduce decorators of V2 and implement the MVVM architecture through code reconstruction. Finally, data, logic, and views are layered to provide a clearer code structure and easier maintenance. Proper use of Model, View, and ViewModel helps efficiently synchronize data with the UI, simplify the development process, and reduce complexity. It is hoped that you can better understand the MVVM mode and flexibly apply it to your application development, thereby improving the development efficiency and code quality.

## Sample Code
[Complete Source Code](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/StateMgmtV2MVVM/entry)
