# \@ReusableV2装饰器：组件复用

为了降低反复创建销毁自定义组件带来的性能开销，开发者可以使用\@ReusableV2装饰\@ComponentV2装饰的自定义组件，达成组件复用的效果。

在阅读本文前，建议提前阅读：[\@Reusable装饰器：组件复用](./arkts-reusable.md)。

>**说明：**
>
>从API version 18开始，可以使用\@ReusableV2装饰\@ComponentV2装饰的自定义组件。
>

## 概述

\@ReusableV2用于装饰V2的自定义组件，表明该自定义组件具有被复用的能力：

- \@ReusableV2仅能装饰V2的自定义组件，即\@ComponentV2装饰的自定义组件。并且仅能将\@ReusableV2装饰的自定义组件作为V2自定义组件的子组件使用。
- \@ReusableV2同样提供了aboutToRecycle和aboutToReuse的生命周期，在组件被回收时调用aboutToRecycle，在组件被复用时调用aboutToReuse，但与\@Reusable不同的是，aboutToReuse没有入参。
- 在回收阶段，会递归地调用所有子组件的aboutToRecycle回调（即使子组件未被标记可复用）；在复用阶段，会递归地调用所有子组件的aboutToReuse回调（即使子组件未被标记可复用）。
- \@ReusableV2装饰的自定义组件会在被回收期间保持冻结状态，即无法触发UI刷新、无法触发\@Monitor回调，与freezeWhenInactive标记位不同的是，在解除冻结状态后，不会触发延后的刷新。
- \@ReusableV2装饰的自定义组件会在复用时自动重置组件内状态变量的值、重新计算组件内\@Computed以及与之相关的\@Monitor。不建议开发者在aboutToRecycle中更改组件内状态变量，详见[复用前的组件内状态变量重置](#复用前的组件内状态变量重置)。
- V1和V2的复用组件可在一定规则下混用，详见[使用限制](#使用限制)第二点。
- 不建议开发者嵌套滥用\@ReusableV2装饰器，这可能会导致复用效率降低以及内存开销变大。

## 装饰器说明

| \@ReusableV2装饰器 | 说明                          |
| ------------------ | ----------------------------- |
| 装饰器参数         | 无                            |
| 可装饰的组件       | \@ComponentV2装饰的自定义组件 |
| 装饰器作用         | 表明该组件可被复用            |

```ts
@ReusableV2 // 装饰ComponentV2的自定义组件
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

## 接口说明

### ReuseIdCallback

ReuseIdCallback用于计算reuseId，类型为() => string。

### ReuseOptions

ReuseOptions保存了reuseId信息，用于.reuse属性中。

| 属性    | 类型            | 说明                  |
| ------- | --------------- | --------------------- |
| reuseId | ReuseIdCallback | 获取reuseId的回调函数 |

### reuse属性

reuse属性用于\@ReusableV2装饰的自定义组件，给组件指定reuseId。相同reuseId的自定义组件会被互相复用。如果未指定reuseId，则使用自定义组件名作为reuseId。

| 参数    | 类型         | 说明                                                   |
| ------- | ------------ | ------------------------------------------------------ |
| options | ReuseOptions | reuse的配置选项，例如{reuseId: () => 'reuseComponent'} |

```ts
@Entry
@ComponentV2
struct Index {
  build() {
    Column() {
      ReusableV2Component()
        .reuse({reuseId: () => 'reuseComponent'}) // 使用'reuseComponent'作为reuseId
      ReusableV2Component()
        .reuse({reuseId: () => ''}) // 使用空字符串将默认使用组件名'ReusableV2Component'作为reuseId
      ReusableV2Component() // 未指定reuseId将默认使用组件名'ReusableV2Component'作为reuseId
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

## 使用限制

- 仅能将\@ReusableV2装饰的自定义组件作为V2自定义组件的子组件使用。如果在V1的自定义组件中使用V2的复用组件将导致编译期报错，编译期无法校验到的复杂场景下将会有运行时报错。

  ```ts
  @Entry
  @ComponentV2
  struct Index {
    build() {
      Column() {
        ReusableV2Component() // 正确用法
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
        ReusableV2Component() // 错误用法，编译报错
        V2ReusableBuilder() // 错误用法，较复杂场景，运行时报错
      }
    }
  }
  ```

- V1和V2支持部分混用场景。

  下文提到的描述对应关系如下表：

  | 描述       | 对应组件类型                         |
  | ---------- | ------------------------------------ |
  | V1普通组件 | @Component装饰的struct               |
  | V2普通组件 | @ComponentV2装饰的struct             |
  | V1复用组件 | @Reusable @Component装饰的struct     |
  | V2复用组件 | @ReusableV2 @ComponentV2装饰的struct |

  下面的表展示了V1和V2的混用支持关系，每行的含义为第一列作为父组件，能否将后面列的组件作为子组件。

  以第一行V1普通组件为例，可以将V1普通组件、V2普通组件以及V1复用组件作为子组件，但无法将V2复用组件作为子组件。

  |            | V1普通组件 | V2普通组件 |               V1复用组件               |    V2复用组件    |
  | ---------- | :--------: | :--------: | :------------------------------------: | :--------------: |
  | V1普通组件 |    支持    |    支持    |                  支持                  | 不支持，编译报错 |
  | V2普通组件 |    支持    |    支持    | 不支持，编译告警，实际使用子组件不创建 |       支持       |
  | V1复用组件 |    支持    |    支持    |                  支持                  | 不支持，编译报错 |
  | V2复用组件 |    支持    |    支持    |            不支持，编译报错            |       支持       |

  根据上表，仅支持12种可能的父子关系，不推荐开发者高度嵌套可复用组件，这会造成复用效率降低。

- V2的复用组件当前不支持直接用于Repeat的template中，但是可以用在template中的V2自定义组件中。

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
                  ReusableV2Component({ val: ri.item}) // 暂不支持，编译期报错
                  ReusableV2Builder(ri.item) // 暂不支持，运行时报错
                  NormalV2Component({ val: ri.item}) // 支持普通V2自定义组件下面包含V2复用组件              
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

## 回收与复用的生命周期

\@ReusableV2提供了aboutToRecycle以及aboutToReuse的生命周期，当组件被回收时触发aboutToRecycle，当组件被复用时触发aboutToReuse。

以if的使用场景为例：

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
    console.log('ReusableV2Component aboutToAppear called'); // 组件创建时调用
  }
  aboutToDisappear() {
    console.log('ReusableV2Component aboutToDisappear called'); // 组件销毁时调用
  }
  aboutToRecycle() {
    console.log('ReusableV2Component aboutToRecycle called'); // 组件回收时调用
  }
  aboutToReuse() {
    console.log('ReusableV2Component aboutToReuse called'); // 组件复用时调用
  }
  build() {
    Column() {
      Text('ReusableV2Component')
    }
  }
}
```

建议按下面顺序进行操作：

1. 点击`step1. appear`，此时`condition1`变为true，`Index`中的if组件切换分支，创建出`NormalV2Component`，由于`condition2`初始值为true，所以`NormalV2Component`中的if条件满足，尝试创建`ReusableV2Component`。此时复用池中无元素，因此会创建`ReusableV2Component`，并回调`aboutToAppear`的方法，输出`ReusableV2Component aboutToAppear called`的日志。
2. 点击`step2. recycle`，此时`condition2`变为false，通过\@Param同步给`NormalComponent`，if条件切换，由于`ReusableV2Component`使用了\@ReusableV2，因此会将该组件回收至复用池而不是销毁，回调`aboutToRecycle`的方法并输出`ReusableV2Component aboutToRecycle called`的日志。
3. 点击`step3. reuse`，此时`condition2`变为true，通过\@Param传递给`NormalComponent`，if条件切换，由于`ReusableV2Component`使用了\@ReusableV2，因此在创建该组件时尝试去复用池中寻找。此时复用池中有第二步放入的组件实例，因此从复用池中取出复用，回调`aboutToReuse`方法并输出`ReusableV2Component aboutToReuse called`的日志。
4. 点击`step4. disappear`，此时`condition1`变为false，`Index`组件中的if组件切换分支，销毁`NormalComponent`，此时`ReusableV2Component`因为父组件销毁，所以会被一起销毁，回调`aboutToDisappear`的方法并输出`ReusableV2Component aboutToDisappear called`的日志。

倘若该复用组件下有子组件时，会在回收和复用时递归调用子组件的aboutToRecycle和aboutToReuse（与子组件是否被标记复用无关），直到遍历完所有的孩子组件。

## 复用阶段的冻结

在之前的复用中，V1组件在复用池中仍能响应更新，这会对性能带来一定的负面影响，需要开发者使用组件冻结能力，才能够使V1组件在复用池中时不响应更新。针对这一点，V2组件在复用时将会被自动冻结，不会响应在回收期间发生的变化。这一个期间包括`aboutToRecycle`，即`aboutToRecycle`中的修改不会刷新到UI上，也不会触发\@Computed以及\@Monitor。冻结状态将持续到aboutToReuse前，即`aboutToReuse`及之后的变量更改，才会正常触发UI刷新、\@Computed重新计算以及\@Monitor的调用。

以if的使用场景为例：

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
      Button('复用/回收').onClick(()=>{this.condition=!this.condition;})
      Button('改值').onClick(()=>{info.age++;})
      if (this.condition) {
        ReusableV2Component()
      }
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Local info: Info = info; // 仅做演示使用，并不建议@Local赋值全局变量
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

建议按如下步骤进行操作：

1. 点击`改值`按钮，可以观察到UI变化，\@Monitor触发并输出日志`info.age change`以及`info.age onRender`，说明此时能够正常监听到变化以及触发UI刷新。
2. 点击`复用/回收`按钮，此时调用`aboutToRecycle`回调并输出`aboutToRecycle`的日志，但\@Monitor不被触发，且`onRender`方法不被回调。
3. 点击`改值`按钮，UI无变化，\@Monitor不触发且`onRender`方法不被回调。
4. 点击`复用/回收`按钮，此时UI变化，\@Monitor触发并输出日志`info.age change`且`onRender`方法回调输出`info.age onRender`。

如果去掉`aboutToReuse`方法中的自增操作，则上述第四步不会触发\@Monitor回调。

在复杂的混用场景中，是否冻结的规则可以总结为以下两点：

1. V1的组件根据是否开启组件冻结freezeWhenInactive决定。
2. V2的组件自动被冻结。

## 复用前的组件内状态变量重置

与\@Reusable不同的是，\@ReusableV2在复用前会重置组件中的状态变量以及相关的\@Computed、\@Monitor的内容。在复用的过程当中，所有的V2自定义组件，无论是否被标记了\@ReusableV2，都会经历这一个重置过程。

重置会按照变量在组件中定义的顺序按照下面的规则依次进行：

| 装饰器     | 重置方法                                                     |
| ---------- | ------------------------------------------------------------ |
| \@Local    | 直接使用定义时的初始值重新赋值。                             |
| \@Param    | 如果有外部传入则使用外部传入值重新赋值，否则用本地初始值重新赋值。注意：\@Once装饰的变量同样会被重置初始化一次。 |
| \@Event    | 如果有外部传入则使用外部传入值重新赋值，否则用本地初始值重新赋值。如果本地没有初始值，则生成默认的空实现。 |
| \@Provider | 直接使用定义时的初始值重新赋值。                             |
| \@Consumer | 如果有对应的\@Provider则直接使用\@Provider对应的值，否则使用本地初始值重新赋值。 |
| \@Computed | 使用当前最新的值重新计算一次，如果使用到的变量还未被重置，将会使用重置前的值，因此推荐开发者将\@Computed定义在所使用的变量之后。 |
| \@Monitor  | 在上述所有变量重置完成之后触发。重置过程中产生的变量变化不会触发\@Monitor回调，仅更新IMonitorValue中的before值。重置过程中不产生变化的赋值不会触发\@Monitor的重置。 |
| 常量       | 包括readonly的常量，不重置。                                 |

下面的例子展示了重置的一些效果：

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
      Button('回收/复用').onClick(()=>{this.condition=!this.condition;})
      Column() {
        Text('父组件变量')
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
  noDecoVariable: number = 0; // 未加装饰器，被视作常量
  noDecoInfo: Info = new Info(30); // 未加装饰器，被视作常量
  readonly readOnlyVariable: number = 0; // readonly常量
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
        Text('重置为本地初始值的变量')
        Text(`val: ${this.val}`).onClick(()=>{this.val++;})
        Text(`info.age: ${this.info.age}`).onClick(()=>{this.info.age++;})
        Text(`paramLocal: ${this.paramLocal}`).onClick(()=>{/* 无外部传入的Local无法本地修改 */})
        Text(`selfProvider: ${this.selfProvider}`).onClick(()=>{this.selfProvider++;})
        Text(`selfConsumer: ${this.selfConsumer}`).onClick(()=>{this.selfConsumer++;})
      }.borderWidth(2)
      Column() {
        Text('重置为外部传入的变量')
        Text(`paramOut: ${this.paramOut}`).onClick(()=>{this.changeParam();})
        Text(`paramOnce: ${this.paramOnce}`).onClick(()=>{this.paramOnce++;})
      }.borderWidth(2)
      Column() {
        Text('根据父组件情况决定')
        Text(`inheritConsumer: ${this.inheritConsumer}`).onClick(()=>{this.inheritConsumer++;})
        Text(`plusParam: ${this.plusParam}`)
      }.borderWidth(2)
      Column() {
        Text('不被重置')
        Text(`noDecoVariable: ${this.noDecoVariable}`)
        Text(`noDecoInfo.age: ${this.noDecoInfo.age}`).onClick(()=>{this.noDecoInfo.age++;}) // 能够触发刷新但是复用时不会被重置
        Text(`readOnlyVariable: ${this.readOnlyVariable}`)
      }.borderWidth(2)
    }
  }
}
```

开发者可以尝试点击各个变量，并点击`回收/复用`按钮查看复用后的重置情况。

需要注意的是，上面的例子中`noDecoInfo`未被重置，如果存在监听`noDecoInfo.age`的\@Monitor，因为noDecoInfo本身未产生变化，所以该\@Monitor也不会被重置，因此在后续第一次更改`noDecoInfo.age`时，`IMonitorValue`的`before`值将不会被重置，仍是复用前的值。

将上面的例子简化可得下面的例子：

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
      Button('回收/复用').onClick(()=>{this.condition=!this.condition;})
      if (this.condition) {
        ReusableV2Component()
      }
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  noDecoInfo: Info = new Info(30); // 未加装饰器，被视作常量
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
          .onClick(()=>{this.noDecoInfo.age++;}) // 能够触发刷新但是不会被重置
      }
    }
  }
}
```

建议按照下列步骤进行操作：

1. 点击`noDecoInfo.age: 30`，UI刷新为`noDecoInfo.age: 31`，\@Monitor触发并输出日志`age change from 30 to 31`。
2. 点击`回收/复用`两次，UI刷新为`noDecoInfo.age: 35`，\@Monitor触发并输出日志`age change from 31 to 35`。
3. 点击`noDecoInfo.age: 35`，UI刷新为`noDecoInfo.age: 36`，\@Monitor触发并输出日志`age change from 35 to 36`。

由于冻结机制的存在，在aboutToRecycle中赋值不会被\@Monitor观察到。而在经历完变量重置后，变量又会被赋予新的值，因此对于组件内状态变量来说，在aboutToRecycle中赋值不会有明显的效果；而常量（例如上面的`noDecoInfo`）由于冻结机制的存在，在aboutToRecycle中更改`age`也不会被观察到，并且因为不会被重置，所以相关的\@Monitor也不会被重置，即这里的`age`值本身未被重置，也就不会重置与之绑定的\@Monitor。最终表现出来的现象即：第二步回调的\@Monitor中，`monitor.value()?.before`得到的值为31，而非age的初始值30。

针对这一现象，推荐开发者在复用的场景减少使用类似的常量对象包含\@Trace属性的写法，以确保复用场景的功能符合预期。

## 使用场景

### 在if组件中使用

通过改变if组件的条件可以控制组件回收/复用。

```ts
@Entry
@ComponentV2
struct Index {
  @Local condition: boolean = true;
  build() {
    Column() {
      Button('回收/复用').onClick(()=>{this.condition=!this.condition;}) // 点击切换回收/复用状态
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
    console.log('ReusableV2Component aboutToRecycle'); // 回收时被调用
  }
  aboutToReuse() {
    console.log('ReusableV2Component aboutToReuse'); // 复用时被调用
  }
  build() {
    Column() {
      Text(this.message)
    }
  }
}
```

### 在Repeat组件non-virtualScroll场景的each属性中使用

Repeat组件non-virtualScroll场景中，会在删除/创建子树时触发回收/复用。

```ts
@Entry
@ComponentV2
struct Index {
  @Local simpleList: number[] = [1, 2, 3, 4, 5];
  @Local condition: boolean = true;
  build() {
    Column() {
      Button('删除/创建Repeat').onClick(()=>{this.condition=!this.condition;})
      Button('增加元素').onClick(()=>{this.simpleList.push(this.simpleList.length+1);})
      Button('删除元素').onClick(()=>{this.simpleList.pop();})
      Button('更改元素').onClick(()=>{this.simpleList[0]++;})
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

### 在Repeat组件virtualScroll场景的each属性中使用

Repeat组件virtualScroll场景中，将会优先使用Repeat组件的缓存池，正常滑动场景、更新场景不涉及组件的回收与复用。当Repeat的缓存池需要扩充时将会向自定义组件要求新的子组件，此时如果复用池中有可复用的节点，将会进行复用。

下面的例子中，先点击`改变condition`会让3个节点进入复用池，而后向下滑动List组件时，可以观察到日志输出`ReusableV2Component aboutToReuse`，表明Repeat可以使用自定义组件的复用池填充自己的缓存池。

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
      Button('改变condition').onClick(()=>{this.condition=!this.condition;})
      if (this.condition) {
        // 此处仅做演示使用，让复用池中填充3个组件
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

### 在ForEach组件中使用
>**说明：**
>
>推荐开发者使用Repeat组件的non-virtualScroll场景代替ForEach组件

下面的例子中使用了ForEach组件渲染了数个可复用组件，由于每次点击`点击修改`按钮时key值都会发生变化，因此从第二次点击开始都会触发回收与复用（由于ForEach先判断有无可复用节点时复用池仍未初始化，因此第一次点击会创建新的节点，而后初始化复用池同时回收节点）。

```ts
@Entry
@ComponentV2
struct Index {
  @Local simpleList: number[] = [0, 1, 2, 3, 4, 5];
  build() {
    Column() {
      ForEach(this.simpleList, (num: number, index) => {
        Row() {
          Button('点击修改').onClick(()=>{this.simpleList[index]++;})
          ReusableV2Component({ num: num })
        }
      }) // 每次修改完key发生变化
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  @Require @Param num: number;
  aboutToAppear() {
    console.log('ReusableV2Component aboutToAppear', this.num); // 创建时触发
  }
  aboutToRecycle() {
    console.log('ReusableV2Component aboutToRecycle', this.num); // 回收时触发
  }
  aboutToReuse() {
    console.log('ReusableV2Component aboutToReuse', this.num); // 复用时触发
  }
  build() {
    Column() {
      Text(`child: ${this.num}`)
    }
  }
}
```


### 在LazyForEach组件中使用
>**说明：**
>
>推荐开发者使用Repeat组件的virtualScroll场景代替LazyForEach组件

下面的例子中使用了LazyForEach渲染了数个可复用组件，在滑动时可以先观察到组件创建，直到预加载节点全部创建完成之后，再滑动则触发复用和回收。

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
  data: MyDataSource = new MyDataSource(); // 数据源

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
                item.message += '!'; // message为@Trace装饰的变量，可观察变化
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
    console.log('ChildComponent aboutToReuse', this.data) // 复用时触发
  }
  aboutToRecycle(): void {
    console.log('ChildComponent aboutToRecycle', this.data) // 回收时触发
  }
  build() {
    Row() {
      Text(this.data).fontSize(50)
    }
  }
}
```

