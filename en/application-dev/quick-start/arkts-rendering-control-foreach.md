# ForEach: Rendering of Repeated Content


**ForEach** enables repeated content based on array-type data.


## API Description


```ts
ForEach(
  arr: any[], 
  itemGenerator: (item: any, index?: number) => void,
  keyGenerator?: (item: any, index?: number) => string 
)
```


| Name          | Type                                    | Mandatory  | Description                                    |
| ------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| arr           | Array                                    | Yes   | An array, which can be empty, in which case no child component is created. The functions that return array-type values are also allowed, for example, **arr.slice (1, 3)**. The set functions cannot change any state variables including the array itself, such as **Array.splice**, **Array.sort**, and **Array.reverse**.|
| itemGenerator | (item:&nbsp;any,&nbsp;index?:&nbsp;number)&nbsp;=&gt;&nbsp;void | Yes   | A lambda function used to generate one or more child components for each data item in an array. Each component and its child component list must be contained in parentheses.<br>**NOTE**<br>- The type of the child component must be the one allowed inside the parent container component of **ForEach**. For example, a **\<LitemItem>** child component is allowed only when the parent container component of **ForEach** is **\<List>**.<br>- The child build function is allowed to return an **if** or another **ForEach**. **ForEach** can be placed inside **if**.<br>- The optional **index** parameter should only be specified in the function signature if used in its body.|
| keyGenerator  | (item:&nbsp;any,&nbsp;index?:&nbsp;number)&nbsp;=&gt;&nbsp;string | No   | An anonymous function used to generate a unique and fixed key value for each data item in an array. This key-value generator is optional. However, for performance reasons, it is strongly recommended that the key-value generator be provided, so that the development framework can better identify array changes. For example, if no key-value generator is provided, a reverse of an array will result in rebuilding of all nodes in **ForEach**.<br>**NOTE**<br>- Two items inside the same array must never work out the same ID.<br>- If **index** is not used, an item's ID must not change when the item's position within the array changes. However, if **index** is used, then the ID must change when the item is moved within the array.<br>- When an item is replaced by a new one (with a different value), the ID of the replaced and the ID of the new item must be different.<br>- When **index** is used in the build function, it should also be used in the ID generation function.<br>- The ID generation function is not allowed to mutate any component state.|


## Restrictions

- **ForEach** must be used in container components.

- The type of the child component must be the one allowed inside the parent container component of **ForEach**. 

- The **itemGenerator** function can contain an **if/else** statement, and an **if/else** statement can contain **ForEach**.

- The call sequence of **itemGenerator** functions may be different from that of the data items in the array. During the development, do not assume whether or when the **itemGenerator** and **keyGenerator** functions are executed. For example, the following example may not run properly:

  ```ts
  ForEach(anArray.map((item1, index1) => { return { i: index1 + 1, data: item1 }; }), 
    item => Text(`${item.i}. item.data.label`),
    item => item.data.id.toString())
  ```


## Recommendations

- Make no assumption on the order of item build functions. The execution order may not be the order of items inside the array.

- Make no assumption either when items are built the first time. Currently initial render of **ForEach** builds all array items when the \@Component decorated component is rendered at the first time, but future framework versions might change this behaviour to a more lazy behaviour.

- Using the **index** parameter has severe negative impact on the UI update performance. Avoid using this parameter whenever possible.

- If the **index** parameter is used in the item generator function, it must also be used in the item index function. Otherwise, the framework counts in the index when generating the ID. By default, the index is concatenated to the end of the ID.


## Application Scenarios


### Simple ForEach Example

This example creates three **\<Text>** and **\<Divide>** components based on the **arr** data.


```ts
@Entry
@Component
struct MyComponent {
  @State arr: number[] = [10, 20, 30];

  build() {
    Column({ space: 5 }) {
      Button('Reverse Array')
        .onClick(() => {
          this.arr.reverse();
        })
      ForEach(this.arr, (item: number) => {
        Text(`item value: ${item}`).fontSize(18)
        Divider().strokeWidth(2)
      }, (item: number) => item.toString())
    }
  }
}
```


### Complex ForEach Example


```ts
@Component
struct CounterView {
  label: string;
  @State count: number = 0;

  build() {
    Button(`${this.label}-${this.count} click +1`)
      .width(300).height(40)
      .backgroundColor('#a0ffa0')
      .onClick(() => {
        this.count++;
      })
  }
}

@Entry
@Component
struct MainView {
  @State arr: number[] = Array.from(Array(10).keys()); // [0.,.9]
  nextUnused: number = this.arr.length;

  build() {
    Column() {
      Button(`push new item`)
        .onClick(() => {
          this.arr.push(this.nextUnused++)
        })
        .width(300).height(40)
      Button(`pop last item`)
        .onClick(() => {
          this.arr.pop()
        })
        .width(300).height(40)
      Button(`prepend new item (unshift)`)
        .onClick(() => {
          this.arr.unshift(this.nextUnused++)
        })
        .width(300).height(40)
      Button(`remove first item (shift)`)
        .onClick(() => {
          this.arr.shift()
        })
        .width(300).height(40)
      Button(`insert at pos ${Math.floor(this.arr.length / 2)}`)
        .onClick(() => {
          this.arr.splice(Math.floor(this.arr.length / 2), 0, this.nextUnused++);
        })
        .width(300).height(40)
      Button(`remove at pos ${Math.floor(this.arr.length / 2)}`)
        .onClick(() => {
          this.arr.splice(Math.floor(this.arr.length / 2), 1);
        })
        .width(300).height(40)
      Button(`set at pos ${Math.floor(this.arr.length / 2)} to ${this.nextUnused}`)
        .onClick(() => {
          this.arr[Math.floor(this.arr.length / 2)] = this.nextUnused++;
        })
        .width(300).height(40)
      ForEach(this.arr,
        (item) => {
          CounterView({ label: item.toString() })
        },
        (item) => item.toString()
      )
    }
  }
}
```

**MainView** has an \@State decorated array of numbers. Adding, deleting, and replacing array items are observed mutation events. Whenever one of these events occurs, **ForEach** in **MainView** is updated.

The item index function creates a unique and persistent ID for each array item. The ArkUI framework uses this ID to determine whether an item in the array changes. As long as the ID is the same, the item value is assumed to remain unchanged, but its index position may have changed. For this mechanism to work, different array items cannot have the same ID.

Using the item ID obtained through computation, the framework can distinguish newly created, removed, and retained array items.

1. The framework removes UI components for a removed array item.

2. The framework executes the item build function only for newly added array items.

3. The framework does not execute the item build function for retained array items. If the item index within the array has changed, the framework will just move its UI components according to the new order, but will not update that UI components.

The item index function is recommended, but optional. The generated IDs must be unique. This means that the same ID must not be computed for any two items within the array. The ID must be different even if the two array items have the same value.

If the array item value changes, the ID must be changed.
As mentioned earlier, the ID generation function is optional. The following example shows **ForEach** without the item index function:

  ```ts
  ForEach(this.arr,
    (item) => {
      CounterView({ label: item.toString() })
    }
  )
  ```

If no item ID function is provided, the framework attempts to intelligently detect array changes when updating **ForEach**. However, it might remove child components and re-execute the item build function for array items that have been moved (with indexes changed). In the preceding example, this changes the application behavior in regard to the **counter** state of **CounterView**. When a new **CounterView** instance is created, the value of **counter** is initialized with **0**.


### Example of ForEach Using \@ObjectLink

If your application needs to preserve the state of repeated child components, you can use \@ObjectLink to enable the state to be "pushed up the component tree."


```ts
let NextID: number = 0;

@Observed
class MyCounter {
  public id: number;
  public c: number;

  constructor(c: number) {
    this.id = NextID++;
    this.c = c;
  }
}

@Component
struct CounterView {
  @ObjectLink counter: MyCounter;
  label: string = 'CounterView';

  build() {
    Button(`CounterView [${this.label}] this.counter.c=${this.counter.c} +1`)
      .width(200).height(50)
      .onClick(() => {
        this.counter.c += 1;
      })
  }
}

@Entry
@Component
struct MainView {
  @State firstIndex: number = 0;
  @State counters: Array<MyCounter> = [new MyCounter(0), new MyCounter(0), new MyCounter(0),
    new MyCounter(0), new MyCounter(0)];

  build() {
    Column() {
      ForEach(this.counters.slice(this.firstIndex, this.firstIndex + 3),
        (item) => {
          CounterView({ label: `Counter item #${item.id}`, counter: item })
        },
        (item) => item.id.toString()
      )
      Button(`Counters: shift up`)
        .width(200).height(50)
        .onClick(() => {
          this.firstIndex = Math.min(this.firstIndex + 1, this.counters.length - 3);
        })
      Button(`counters: shift down`)
        .width(200).height(50)
        .onClick(() => {
          this.firstIndex = Math.max(0, this.firstIndex - 1);
        })
    }
  }
}
```

When the value of **firstIndex** is increased, **ForEach** within **Mainview** is updated, and the **CounterView** child component associated with the item ID **firstIndex-1** is removed. For the array item whose ID is **firstindex + 3**, a new** CounterView** child component instance is created. The value of the state variable **counter** of the **CounterView** child component is preserved by the **Mainview** parent component. Therefore, **counter** is not rebuilt when the **CounterView** child component instance is rebuilt.

> **NOTE**
>
> The most common mistake application developers make in connection with **ForEach** is that the ID generation function returns the same value for two array items, especially in the Array\<number> scenario.


### Nested Use of ForEach

While nesting **ForEach** inside another **ForEach** in the same component is allowed, it is not recommended. It is better to split the component into two and have each build function include just one ForEach. The following is a poor example of nested use of **ForEach**.


```ts
class Month {
  year: number;
  month: number;
  days: number[];

  constructor(year: number, month: number, days: number[]) {
    this.year = year;
    this.month = month;
    this.days = days;
  }
}
@Component
struct CalendarExample {
  // Simulate with six months.
  @State calendar : Month[] = [
    new Month(2020, 1, [...Array(31).keys()]),
    new Month(2020, 2, [...Array(28).keys()]),
    new Month(2020, 3, [...Array(31).keys()]),
    new Month(2020, 4, [...Array(30).keys()]),
    new Month(2020, 5, [...Array(31).keys()]),
    new Month(2020, 6, [...Array(30).keys()])
  ]
  build() {
    Column() {
      Button() {
        Text('next month')
      }.onClick(() => {
        this.calendar.shift()
        this.calendar.push(new Month(year: 2020, month: 7, days: [...Array(31).keys()]))
      })
      ForEach(this.calendar,
        (item: Month) => {
          ForEach(item.days,
            (day : number) => {
              // Build a date block.
            },
            (day : number) => day.toString()
          )// Inner ForEach
        },
        (item: Month) => (item.year * 12 + item.month).toString() // This field is used together with the year and month as the unique ID of the month.
      )// Outer ForEach
    }
  }
}
```

The preceding example has two issues:

1. The code readability is poor.

2. For a data structure of months and days of a year, the framework cannot observe the attribute changes to **Month** objects, including any changes to the **days** array. As a result, the inner **ForEach** will not update the date.

The recommended application design is to split **Calendar** into **Year**, **Month**, and **Day** child components. Define a **Day** model class to hold information about a day and decorate the class with \@Observed. The **DayView** component uses an \@ObjectLink decorated variable to link to the data about a day. Perform the same operations on the **MonthView** and **Month** model classes.


### Example of Using the Optional index Parameter in ForEach

You can use the optional **index** parameter in item build and ID generation functions.


```ts
@Entry
@Component
struct ForEachWithIndex {
  @State arr: number[] = [4, 3, 1, 5];

  build() {
    Column() {
      ForEach(this.arr,
        (it, indx) => {
          Text(`Item: ${indx} - ${it}`)
        },
        (it, indx) => {
          return `${indx} - ${it}`
        }
      )
    }
  }
}
```

The correct construction of the ID generation function is essential. When **index** is used in the item generation function, it should also be used in the ID generation function to produce unique IDs and an ID for given source array item that changes when its index position within the array changes.

This example also illustrates that the **index** parameter can cause significant performance degradation. If an item is moved in the source array without modification, the dependent UI still requires rebuilding because of the changed index. For example, with the use of index sorting, the array only requires the unmodified child UI node of **ForEach** to be moved to the correct slot, which is a lightweight operation for the framework. When **index** is used, all child UI nodes need to be rebuilt, which is much more heavy weight.
