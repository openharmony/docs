# \@ReusableV2 Decorator: Reusing Components

To reduce the performance overhead caused by repeated creation and destruction of custom components, you can use \@ReusableV2 to decorate \@ComponentV2 decorated custom components.

Before reading this topic, you are advised to read [\@Reusable Decorator: Reusing Components](./arkts-reusable.md).

>**NOTE**
>
>The \@ReusableV2 decorator is supported since API version 18.
>

## Overview

Using \@ReusableV2 to decorate the custom components of V2 indicates that these components are reusable.

- \@ReusableV2 can decorate only custom components of V2, that is, custom components decorated by \@ComponentV2. In addition, only \@ReusableV2 decorated custom components can be used as child components of custom components of V2.
- \@ReusableV2 also provides the **aboutToRecycle** and **aboutToReuse** callbacks, which are called respectively when a component is recycled and reused. However, different from \@Reusable, **aboutToReuse** has no input parameters.
- In the recycling phase, **aboutToRecycle** of all child components is recursively called (even if the child components are not reusable). In the reuse phase, so does **aboutToReuse** of all child components.
- The custom component decorated by \@ReusableV2 remains frozen during recycling. That is, the UI r-render and the \@Monitor callback cannot be triggered. Different from the **freezeWhenInactive** flag, the delayed re-render is not triggered after the \@ReusableV2 decorated custom component is unfrozen.
- When a \@ReusableV2 decorated custom component is reused, the value of its state variable is automatically reset, and the \@Computed and related \@Monitor in the component are recomputed. You are not advised to change the state variable of a component in **aboutToRecycle**. For details, see [Resetting State Variables in Components Before Reuse](#resetting-state-variables-in-components-before-reuse).
- The reusable components of V1 and V2 can be used together under certain rules. For details, see the second point in [Constraints](#constraints).
- Do not overuse the \@ReusableV2 decorator. Otherwise, the reuse efficiency may be undermined and the memory overhead may increase.

## Decorator Description

| \@ReusableV2 Decorator| Description                         |
| ------------------ | ----------------------------- |
| Parameters        | None                           |
| Decorable components      | \@ComponentV2 decorated custom components|
| Function        | Indicates that a component is reusable.           |

```ts
@ReusableV2 // Decorates @ComponentV2 decorated custom components.
@ComponentV2
struct ReusableV2Component {
  @Local message: string = 'Hello World';
  build () {
  	Column() {
  	  Text(this.message)
  	}
  }
}
```

## Available APIs

### ReuseIdCallback

**ReuseIdCallback** calculates **reuseId**, whose type is **() => string**.

### ReuseOptions

**ReuseOptions** stores the **reuseId** information, which is used in the **.reuse** attribute.

| Name   | Type           | Description                 |
| ------- | --------------- | --------------------- |
| reuseId | ReuseIdCallback | Callback used to obtain **reuseId**.|

### The reuse Attribute

The **reuse** attribute is used to specify a reuse ID for the custom component decorated by \@ReusableV2. Custom components with the same reuse ID will be reused. If reuse ID is not specified, the custom component name is used as reuse ID.

| Parameter   | Type        | Description                                                  |
| ------- | ------------ | ------------------------------------------------------ |
| options | ReuseOptions | Configuration options for **reuse**, for example, **{reuseId: () => 'reuseComponent'}**.|

```ts
@Entry
@ComponentV2
struct Index {
  build() {
    Column() {
      ReusableV2Component()
        .reuse({reuseId: () => 'reuseComponent'}) // Use 'reuseComponent' as reuseId.
      ReusableV2Component()
        .reuse({reuseId: () => ''}) // If an empty string is used, the component name 'ReusableV2Component' is used as reuseId by default.
      ReusableV2Component() // If reuseId is not specified, the component name 'ReusableV2Component' is used as reuseId by default.
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  build() {
  }
}
```

## Constraints

- Only \@ReusableV2 decorated custom components can be used as child components of custom components of V2. If a reusable component of V2 is used in the custom components of V1, an error is reported during compilation. In complex scenarios where verification cannot be performed during compilation, an error is reported during runtime.

  ```ts
  @Entry
  @ComponentV2
  struct Index {
    build() {
      Column() {
        ReusableV2Component() // Correct usage.
        V1Component()
      }
    }
  }
  @ReusableV2
  @ComponentV2
  struct ReusableV2Component {
    build() {
    }
  }
  @Builder
  function V2ReusableBuilder() {
    ReusableV2Component()
  }
  @Component
  struct V1Component {
    build() {
      Column() {
        ReusableV2Component() // Incorrect usage. An error is reported during compilation.
        V2ReusableBuilder() // Incorrect usage. An error is reported during runtime in complex scenarios.
      }
    }
  }
  ```

- The following describes some mixed use cases of V1 and V2.

  The mapping between a component and its type is listed in the table below.

  | Component      | Type                        |
  | ---------- | ------------------------------------ |
  | Common component of V1| @Component decorated struct              |
  | Common component of V2| @ComponentV2 decorated struct            |
  | Reusable component of V1| @Reusable and @Component decorated struct    |
  | Reusable component of V2| @ReusableV2 and @ComponentV2 decorated struct|

  The following table shows the mixed use support between V1 and V2, indicating whether components in the second to fifth columns can be used as child components of the parent components in the first column.

  For example, the common component of V1, common component of V2, and reusable component of V1 can be used as child components of the common component of V1 except the reusable component of V2.

  |            | Common Component of V1| Common Component of V2|               Reusable Component of V1              |    Reusable Component of V2   |
  | ---------- | :--------: | :--------: | :------------------------------------: | :--------------: |
  | Common component of V1|    Yes   |    Yes   |                  Yes                 | No. An error is reported during compilation.|
  | Common component of V2|    Yes   |    Yes   | No. An error is reported during compilation. The actual used child component is not created.|       Yes      |
  | Reusable component of V1|    Yes   |    Yes   |                  Yes                 | No. An error is reported during compilation.|
  | Reusable component of V2|    Yes   |    Yes   |            No. An error is reported during compilation.           |       Yes      |

  According to the preceding table, only 12 possible parent-child relationships are supported. You are advised not to highly nest reusable components, because it will reduce the reuse efficiency.

- The reusable components of V2 cannot be directly used in the **template** of **Repeat**, but can be used in the custom component of V2 in **template**.

  ```ts
  @Entry
  @ComponentV2
  struct Index {
    @Local arr: number[] = [1, 2, 3, 4, 5];
    build() {
      Column() {
        List() {
          Repeat(this.arr)
            .each(() => {})
            .virtualScroll()
            .templateId(() => 'a')
            .template('a', (ri) => {
              ListItem() {
                Column() {
                  ReusableV2Component({ val: ri.item}) // Usage not supported. An error is reported during compilation.
                  ReusableV2Builder(ri.item) // Usage not supported. An error is reported during runtime.
                  NormalV2Component({ val: ri.item}) // Reusable components of V2 can be used in common custom components of V2.             
                }
              }
            })
        }
      }
    }
  }
  @ComponentV2
  struct NormalV2Component {
    @Require @Param val: number;
    build() {
      ReusableV2Component({ val: this.val })
    }
  }
  @Builder
  function ReusableV2Builder(param: number) {
    ReusableV2Component({ val: param })
  }
  @ReusableV2
  @ComponentV2
  struct ReusableV2Component {
    @Require @Param val: number;
    build() {
      Column() {
        Text(`val: ${this.val}`)
      } 
    }
  }
  ```

## Lifecycle of Recycling and Reuse

\@ReusableV2 provides the **aboutToRecycle** and **aboutToReuse** callbacks, which are called respectively when a component is recycled and reused.

The following uses the **if** statement as an example:

```ts
@Entry
@ComponentV2
struct Index {
  @Local condition1: boolean = false;
  @Local condition2: boolean = true;
  build() {
    Column() {
      Button('step1. appear')
        .onClick(() => {
          this.condition1 = true;  
        })
      Button('step2. recycle')
        .onClick(() => {
          this.condition2 = false;  
        })
      Button('step3. reuse')
        .onClick(() => {
          this.condition2 = true;  
        })
      Button('step4. disappear')
        .onClick(() => {
          this.condition1 = false;  
        })
      if (this.condition1) {
        NormalV2Component({ condition: this.condition2 })
      }
    }
  }
}
@ComponentV2
struct NormalV2Component {
  @Require @Param condition: boolean;
  build() {
    if (this.condition) {
      ReusableV2Component()
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  aboutToAppear() {
    console.log('ReusableV2Component aboutToAppear called'); // Called when a component is created.
  }
  aboutToDisappear() {
    console.log('ReusableV2Component aboutToDisappear called'); // Called when a component is destroyed.
  }
  aboutToRecycle() {
    console.log('ReusableV2Component aboutToRecycle called'); // Called when a component is recycled.
  }
  aboutToReuse() {
    console.log('ReusableV2Component aboutToReuse called'); // Called when a component is reused.
  }
  build() {
    Column() {
      Text('ReusableV2Component')
    }
  }
}
```

You are advised to follow the steps below:

1. Click **step1. appear** to change the value of **condition1** to **true**. The **if** component in **Index** switches the branch and creates a **NormalV2Component**. Due to the initial value **true** of **condition2**, the **if** condition in **NormalV2Component** is met and the system attempts to create a **ReusableV2Component**. In this case, there is no element in the reuse pool. Therefore, **ReusableV2Component** is created, the **aboutToAppear** method is called back, and the log **ReusableV2Component aboutToAppear called** is output.
2. Click **step2. recycle** to change the value of **condition2** to **false** and synchronize this change to **NormalV2Component** through \@Param. The **if** condition is switched. Because **ReusableV2Component** uses \@ReusableV2, the component is recycled to the reuse pool instead of being destroyed. The **aboutToRecycle** method is called back and the log **ReusableV2Component aboutToRecycle called** is output.
3. Click **step3. reuse** to change the value of **condition2** to **true** and synchronize this change to **NormalV2Component** through \@Param. The **if** condition is switched. Because **ReusableV2Component** uses \@ReusableV2, the system attempts to search for the component in the reuse pool when creating the component. In this case, the component recycled in step 2 is reused from the reuse pool, the **aboutToReuse** method is called back, and the log **ReusableV2Component aboutToReuse called** is output.
4. Click **step4. disappear** to change the value of **condition1** to **false**. The **if** component in **Index** switches the branch and destroys **NormalV2Component**. In this case, **ReusableV2Component** is destroyed due to the destroyed parent component, the **aboutToDisappear** method is called back, and the log **ReusableV2Component aboutToDisappear called** is output.

If the reusable component has child components, **aboutToRecycle** and **aboutToReuse** of the child components are recursively called during recycling and reuse (irrelevant to whether the child components are marked for reuse) until all child components are traversed.

## Component Freezing in the Reuse Phase

In the previous reuse, components of V1 can still respond to updates in the reuse pool, which has a negative impact on performance. Therefore, you need to use the component freezing capability to resolve this issue. For this, V2 components are automatically frozen when reused and do not respond to changes that occur during recycling. For example, changes in **aboutToRecycle** are not updated to the UI, and \@Computed and \@Monitor are not triggered. The frozen state lasts until **aboutToReuse** and subsequent variables change. In this case, the UI re-render, \@Computed recalculation, and \@Monitor are triggered.

The following uses the **if** statement as an example:

```ts
@ObservedV2
class Info {
  @Trace age: number = 25;
}
const info: Info = new Info();
@Entry
@ComponentV2
struct Index {
  @Local condition: boolean = true;
  build() {
    Column() {
      Button('Reuse/Recycle').onClick(()=>{this.condition=!this.condition;})
      Button('Change value').onClick(()=>{info.age++;})
      if (this.condition) {
        ReusableV2Component()
      }
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Local info: Info = info; // This is used only for demonstration. You are not advised to assign a value to the global variable using @Local.
  @Monitor('info.age')
  onValChange() {
    console.log('info.age change');
  }
  aboutToRecycle() {
    console.log('aboutToRecycle');
    this.info.age++;
  }
  aboutToReuse() {
    console.log('aboutToReuse');
    this.info.age++;
  }
  onRender(): string {
    console.log('info.age onRender')
    return this.info.age.toString();
  }
  build() {
    Column() {
      Text(this.onRender())
    }
  }
}
```

You are advised to follow the steps below:

1. Click the **Change value** button to listen for the UI change. \@Monitor is triggered to output the logs **info.age change** and **info.age onRender**, indicating that the change can be listened for and the UI re-render can be triggered.
2. Click the **Reuse/Recycle** button to call the **aboutToRecycle** method and output the log of **aboutToRecycle**. However, \@Monitor is not triggered and the **onRender** method is not called back.
3. Click the **Change value** button. The UI is not re-rendered, \@Monitor is not triggered, and the **onRender** method is not called back.
4. Click the **Reuse/Recycle** button. The UI is re-rendered, \@Monitor is trigger to output the log **info.age change**, and the **onRender** method is called back to output the log **info.age onRender**.

If the auto-increment operation is removed from the **aboutToReuse** method, the \@Monitor callback is not triggered in step 4.

In complex mixed use scenarios, the rules for component freezing can be summarized as follows:

1. For Components of V1, component freezing is determined by **freezeWhenInactive**.
2. V2 components are automatically frozen.

## Resetting State Variables in Components Before Reuse

Different from \@Reusable, \@ReusableV2 resets the state variables and related \@Computed and \@Monitor content in components before reuse. During the reuse, all custom components of V2 are reset no matter whether they are decorated with \@ReusableV2.

The reset is performed based on the sequence of variables defined in the component according to the following rules.

| Decorator    | Method for Resetting                                                    |
| ---------- | ------------------------------------------------------------ |
| \@Local    | Use the initial value for reassignment.                            |
| \@Param    | Use external input value for reassignment. If there is no external input value, use the local initial value. Note that variables decorated by \@Once are also reset and initialized.|
| \@Event    | Use external input value for reassignment. If there is no external input value, use the local initial value. If there is no local initial value, the default empty implementation is generated.|
| \@Provider | Use the initial value for reassignment.                            |
| \@Consumer | If the corresponding \@Provider exists, use the value of \@Provider. Otherwise, use the local initial value for reassignment.|
| \@Computed | The latest value is used for recalculation. If the used variable is not reset, the value before the reset is used. Therefore, you are advised to define \@Computed after the used variable.|
| \@Monitor  | Triggered after all the preceding variables are reset. The variable change generated during the reset does not trigger the \@Monitor callback. Only the **before** value in **IMonitorValue** is updated. Values that do not change during the reset do not trigger the reset of \@Monitor.|
| Constant      | Read-only constants are included and are not reset.                                |

The following example shows some of the effects:

```ts
@ObservedV2
class Info {
  @Trace age: number;
  constructor(age: number) {
    this.age = age;
  }
}
@Entry
@ComponentV2
struct Index {
  @Local local: number = 0;
  @Provider('inherit') inheritProvider: number = 100;
  @Local condition: boolean = true;
  build() {
    Column() {
      Button('Recycle/Reuse').onClick(()=>{this.condition=!this.condition;})
      Column() {
        Text('Variables of parent component')
        Text(`local: ${this.local}`).onClick(()=>{this.local++;})
        Text(`inheritProvider: ${this.inheritProvider}`).onClick(()=>{this.inheritProvider++;})
      }.borderWidth(2)
      if (this.condition) {
        ReusableV2Component({
          paramOut: this.local,
          paramOnce: this.local,
          changeParam: () => {
            this.local++;  
          }
        })
      }
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Local val: number = 0;
  @Local info: Info = new Info(25);
  @Param paramLocal: number = 1;
  @Require @Param paramOut: number;
  @Require @Param @Once paramOnce: number;
  @Event changeParam: () => void;
  @Provider('selfProvider') selfProvider: number = 0;
  @Consumer('inherit') inheritConsumer: number = 0;
  @Consumer('selfConsumer') selfConsumer: number = 0;
  noDecoVariable: number = 0; // No decorator is used. It is used as a constant.
  noDecoInfo: Info = new Info(30); // No decorator is used. It is used as a constant.
  readonly readOnlyVariable: number = 0; // Read-only constant.
  @Computed
  get plusParam() {
    return this.paramLocal + this.paramOut + this.paramOnce;
  }
  @Monitor('val')
  onValChange(monitor: IMonitor) {
    console.log(`val change from ${monitor.value()?.before} to ${monitor.value()?.now}`);  
  }
  @Monitor('plusParam')
  onPlusParamChange(monitor: IMonitor) {
    console.log(`plusParam change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  build() {
    Column() {
	  Column() {
        Text('Variables reset to local initial values')
        Text(`val: ${this.val}`).onClick(()=>{this.val++;})
        Text(`info.age: ${this.info.age}`).onClick(()=>{this.info.age++;})
        Text(`paramLocal: ${this.paramLocal}`).onClick(()=>{/* Local without external input value fails to be changed locally. */})
        Text(`selfProvider: ${this.selfProvider}`).onClick(()=>{this.selfProvider++;})
        Text(`selfConsumer: ${this.selfConsumer}`).onClick(()=>{this.selfConsumer++;})
      }.borderWidth(2)
      Column() {
        Text('Reset to an external variable')
        Text(`paramOut: ${this.paramOut}`).onClick(()=>{this.changeParam();})
        Text(`paramOnce: ${this.paramOnce}`).onClick(()=>{this.paramOnce++;})
      }.borderWidth(2)
      Column() {
        Text ('Depending on the parent component')
        Text(`inheritConsumer: ${this.inheritConsumer}`).onClick(()=>{this.inheritConsumer++;})
        Text(`plusParam: ${this.plusParam}`)
      }.borderWidth(2)
      Column() {
        Text('Not reset')
        Text(`noDecoVariable: ${this.noDecoVariable}`)
        Text(`noDecoInfo.age: ${this.noDecoInfo.age}`).onClick(()=>{this.noDecoInfo.age++;}) // Update can be triggered but the variable is not reset when component is reused.
        Text(`readOnlyVariable: ${this.readOnlyVariable}`)
      }.borderWidth(2)
    }
  }
}
```

You can click each variable and click **Recycle/Reuse** to view the reset state after reuse.

In the preceding example, **noDecoInfo** is not reset. If a \@Monitor is used to listen for **noDecoInfo.age**, it will not be reset because **noDecoInfo** does not change. Therefore, when **noDecoInfo.age** is changed for the first time, the **before** value of **IMonitorValue** will not be reset, which is still the value before reuse.

The simplified example is as follows:

```ts
@ObservedV2
class Info {
  @Trace age: number;
  constructor(age: number) {
    this.age = age;
  }
}
@Entry
@ComponentV2
struct Index {
  @Local condition: boolean = true;
  build() {
    Column() {
      Button('Recycle/Reuse').onClick(()=>{this.condition=!this.condition;})
      if (this.condition) {
        ReusableV2Component()
      }
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  noDecoInfo: Info = new Info(30); // No decorator is used. It is used as a constant.
  @Monitor('noDecoInfo.age')
  onAgeChange(monitor: IMonitor) {
    console.log(`age change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  aboutToRecycle() {
    this.noDecoInfo.age = 25;
  }
  aboutToReuse() {
    this.noDecoInfo.age = 35;
  }
  build() {
    Column() {
	  Column() {
        Text(`noDecoInfo.age: ${this.noDecoInfo.age}`)
          .onClick(()=>{this.noDecoInfo.age++;}) // Update can be triggered but the variable is not reset.
      }
    }
  }
}
```

You are advised to follow the steps below:

1. Click **noDecoInfo.age: 30**. The UI is re-rendered to **noDecoInfo.age: 31** and \@Monitor is triggered to output the log **age change from 30 to 31**.
2. Click **Recycle/Reuse** twice. The UI is re-rendered to **noDecoInfo.age: 35** and \@Monitor is triggered to output the log **age change from 31 to 35**.
3. Click **noDecoInfo.age: 35**. The UI is re-rendered to **noDecoInfo.age: 36** and \@Monitor is triggered to output the log **age change from 35 to 36**.

Due to the freezing mechanism, the value change in **aboutToRecycle** is not listened by \@Monitor. After the variable is reset, a new value is assigned to the variable. Therefore, for the state variable in the component, the value assignment in **aboutToRecycle** does not have obvious effect. For the constant (such as **noDecoInfo**), due to the freezing mechanism, the change of **age** in **aboutToRecycle** is not observable and cannot be reset, therefore, the \@Monitor bound to **age** will not be reset. Finally, in \@Monitor called back in step 2, the value of **monitor.value()?.before** is **31** instead of the initial value **30** of **age**.

As such, you are advised to reduce the use of constant objects that contain the \@Trace attribute in reuse scenarios to ensure that the reuse meets expectations.

## When to Use

### Using in the if Component

Change the conditions of the **if** component to control component recycling or reuse.

```ts
@Entry
@ComponentV2
struct Index {
  @Local condition: boolean = true;
  build() {
    Column() {
      Button('Recycle/Reuse').onClick(()=>{this.condition=!this.condition;}) // Click to switch the recycle/reuse state.
      if (this.condition) {
        ReusableV2Component()
      }
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Local message: string = 'Hello World';
  aboutToRecycle() {
    console.log('ReusableV2Component aboutToRecycle'); // Called when a component is recycled.
  }
  aboutToReuse() {
    console.log('ReusableV2Component aboutToReuse'); // Called when a component is reused.
  }
  build() {
    Column() {
      Text(this.message)
    }
  }
}
```

### Using in the each Attribute of Repeat in the Non-virtualScroll Scenarios

In the non-virtualScroll scenarios of the **Repeat** component, recycling or reuse is triggered when a subtree is deleted or created.

```ts
@Entry
@ComponentV2
struct Index {
  @Local simpleList: number[] = [1, 2, 3, 4, 5];
  @Local condition: boolean = true;
  build() {
    Column() {
      Button('Delete/Create Repeat').onClick(()=>{this.condition=!this.condition;})
      Button('Add element').onClick(()=>{this.simpleList.push(this.simpleList.length+1);})
      Button('Delete element').onClick(()=>{this.simpleList.pop();})
      Button('Change element').onClick(()=>{this.simpleList[0]++;})
      if (this.condition) {
        List({ space: 10 }) {
          Repeat(this.simpleList)
            .each((obj: RepeatItem<number>) => {
              ListItem() {
                Column() {
                  ReusableV2Component({ num: obj.item })
                }
              }
            })
        }
      }
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Require @Param num: number;
  aboutToAppear() {
    console.log('ReusableV2Component aboutToAppear');
  }
  aboutToRecycle() {
    console.log('ReusableV2Component aboutToRecycle');
  }
  aboutToReuse() {
    console.log('ReusableV2Component aboutToReuse');
  }
  build() {
    Column() {
      Text(`${this.num}`)
    }
  }
}
```

### Using in the each Attribute of Repeat in the virtualScroll Scenarios

In the virtualScroll scenarios of the **Repeat** component, the cache pool of **Repeat** is preferentially used. In the normal sliding and update scenarios, component recycling and reuse are not involved. When the cache pool needs to be expanded, new child components are required from the custom components. In this case, if there are reusable nodes in the reuse pool, the nodes will be reused.

In the following example, click **Change condition** to add three nodes to the reuse pool. When you slide down the **List** component, you can see the log output **ReusableV2Component aboutToReuse**, indicating that **Repeat** can use the reuse pool of the custom component to fill its cache pool.

```ts
@Entry
@ComponentV2
struct Index {
  @Local condition: boolean = true;
  @Local simpleList: number[] = [];
  aboutToAppear(): void {
    for (let i = 0; i < 100; i++) {
      this.simpleList.push(i)
    }
  }
  build() {
    Column() {
      Button('Change condition').onClick(()=>{this.condition=!this.condition;})
      if (this.condition) {
        // This is only for demonstration. Fill three components in the reuse pool.
        ReusableV2Component({ num: 0})
        ReusableV2Component({ num: 0})
        ReusableV2Component({ num: 0})
      }
      List({ space: 10 }) {
        Repeat(this.simpleList)
          .virtualScroll()
          .each((obj: RepeatItem<number>) => {
            ListItem() {
              Column() {
                ReusableV2Component({ num: obj.item })
              }
            }
          })
      }.height('50%')
      .cachedCount(2)
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Require @Param num: number;
  aboutToAppear() {
    console.log('ReusableV2Component aboutToAppear');
  }
  aboutToRecycle() {
    console.log('ReusableV2Component aboutToRecycle');
  }
  aboutToReuse() {
    console.log('ReusableV2Component aboutToReuse');
  }
  build() {
    Column() {
      Text(`${this.num}`).fontSize(50)
    }
  }
}
```

### Using in ForEach
>**NOTE**
>
>You are advised to use the non-virtualScroll scenarios of **Repeat** to replace **ForEach**.

In the following example, ForEach is used to render multiple reusable components. Each time the **Click to change** button is clicked, the key value changes. Therefore, recycling and reuse are triggered from the second click. (When ForEach determines whether there is reusable nodes, the reuse pool is not initialized. Therefore, when ForEach is clicked for the first time, a new node is created. Then, the reuse pool is initialized from the second click and the node is recycled at the same time.)

```ts
@Entry
@ComponentV2
struct Index {
  @Local simpleList: number[] = [0, 1, 2, 3, 4, 5];
  build() {
    Column() {
      ForEach(this.simpleList, (num: number, index) => {
        Row() {
          Button('Click to change').onClick (()=>{this.simpleList[index]++;})
          ReusableV2Component({ num: num })
        }
      }) // The key changes from each click.
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Require @Param num: number;
  aboutToAppear() {
    console.log('ReusableV2Component aboutToAppear', this.num); // Triggered when the component is created.
  }
  aboutToRecycle() {
    console.log('ReusableV2Component aboutToRecycle', this.num); // Triggered when the component is recycled.
  }
  aboutToReuse() {
    console.log('ReusableV2Component aboutToReuse', this.num); // Triggered when the component is reused.
  }
  build() {
    Column() {
      Text(`child: ${this.num}`)
    }
  }
}
```


### Using in LazyForEach
>**NOTE**
>
>You are advised to use the virtualScroll scenarios of **Repeat** to replace **LazyForEach**.

In the following example, **LazyForEach** is used to render several reusable components. During sliding, component creation can be observed first. After all pre-loaded nodes are created, sliding triggers reuse and recycling.

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: StringData[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): StringData {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    })
  }

  notifyDatasetChange(operations: DataOperation[]): void {
    this.listeners.forEach(listener => {
      listener.onDatasetChange(operations);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: StringData[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): StringData {
    return this.dataArray[index];
  }

  public addData(index: number, data: StringData): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: StringData): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@ObservedV2
class StringData {
  @Trace message: string;
  constructor(message: string) {
    this.message = message;
  }
}

@Entry
@ComponentV2
struct Index {
  data: MyDataSource = new MyDataSource(); // Data source.

  aboutToAppear() {
    for (let i = 0; i <= 200; i++) {
      this.data.pushData(new StringData('Hello' + i));
    }
  }
  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: StringData, index: number) => {
        ListItem() {
          Column() {
            Text(item.message)
            ChildComponent({ data: item.message })
              .onClick(() => {
                item.message += '!'; // message is a variable decorated by @Trace and its change is observable.
              })
          }
        }
      })
    }.cachedCount(5)
  }
}

@ReusableV2
@ComponentV2
struct ChildComponent {
  @Param @Require data: string;
  aboutToAppear(): void {
    console.log('ChildComponent aboutToAppear', this.data)
  }
  aboutToDisappear(): void {
    console.log('ChildComponent aboutToDisappear', this.data)
  }
  aboutToReuse(): void {
    console.log('ChildComponent aboutToReuse', this.data) // Triggered when the component is reused.
  }
  aboutToRecycle(): void {
    console.log('ChildComponent aboutToRecycle', this.data) // Triggered when the component is recycled.
  }
  build() {
    Row() {
      Text(this.data).fontSize(50)
    }
  }
}
```
