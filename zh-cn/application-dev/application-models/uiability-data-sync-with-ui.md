# UIAbility组件与UI的数据同步


基于OpenHarmony的应用模型，可以通过以下几种方式来实现UIAbility组件与UI之间的数据同步。

- [使用EventHub进行数据通信](#使用eventhub进行数据通信)：在基类Context中提供了EventHub对象，可以通过发布订阅方式来实现事件的传递。在事件传递前，订阅者需要先进行订阅，当发布者发布事件时，订阅者将接收到事件并进行相应处理。
- [使用globalThis进行数据同步](#使用globalthis进行数据同步)：在ArkTS引擎实例内部，globalThis是一个全局对象，可以被ArkTS引擎实例内的UIAbility组件、ExtensionAbility组件和ArkUI页面（Page）访问。
- [使用AppStorage/LocalStorage进行数据同步](#使用appstorage/localstorage进行数据同步)：ArkUI提供了AppStorage和LocalStorage两种应用级别的状态管理方案，可用于实现应用级别和UIAbility级别的数据同步。


## 使用EventHub进行数据通信

[EventHub](../reference/apis/js-apis-inner-application-eventHub.md)为UIAbility组件提供了事件机制，使它们能够进行订阅、取消订阅和触发事件等数据通信能力。

在[基类Context](application-context-stage.md)中，提供了EventHub对象，可用于在UIAbility组件实例内通信。使用EventHub实现UIAbility与UI之间的数据通信需要先获取EventHub对象，本章节将以此为例进行说明。

1. 在UIAbility中调用[`eventHub.on()`](../reference/apis/js-apis-inner-application-eventHub.md#eventhubon)方法注册一个自定义事件“event1”，[`eventHub.on()`](../reference/apis/js-apis-inner-application-eventHub.md#eventhubon)有如下两种调用方式，使用其中一种即可。

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';

   const TAG: string = '[Example].[Entry].[EntryAbility]';

   export default class EntryAbility extends UIAbility {
     func1(...data) {
       // 触发事件，完成相应的业务操作
       console.info(TAG, '1. ' + JSON.stringify(data));
     }

     onCreate(want, launch) {
       // 获取eventHub
       let eventhub = this.context.eventHub;
       // 执行订阅操作
       eventhub.on('event1', this.func1);
       eventhub.on('event1', (...data) => {
         // 触发事件，完成相应的业务操作
         console.info(TAG, '2. ' + JSON.stringify(data));
       });
     }
   }
   ```

2. 在UI中通过[eventHub.emit()](../reference/apis/js-apis-inner-application-eventHub.md#eventhubemit)方法触发该事件，在触发事件的同时，根据需要传入参数信息。

   ```ts
   import common from '@ohos.app.ability.common';

   @Entry
   @Component
   struct Index {
     private context = getContext(this) as common.UIAbilityContext;

     eventHubFunc() {
       // 不带参数触发自定义“event1”事件
       this.context.eventHub.emit('event1');
       // 带1个参数触发自定义“event1”事件
       this.context.eventHub.emit('event1', 1);
       // 带2个参数触发自定义“event1”事件
       this.context.eventHub.emit('event1', 2, 'test');
       // 开发者可以根据实际的业务场景设计事件传递的参数
     }

     // 页面展示
     build() {
       ...
     }
   }
   ```

3. 在UIAbility的注册事件回调中可以得到对应的触发事件结果，运行日志结果如下所示。

   ```ts
   []

   [1]

   [2,'test']
   ```

4. 在自定义事件“event1”使用完成后，可以根据需要调用[eventHub.off()](../reference/apis/js-apis-inner-application-eventHub.md#eventhuboff)方法取消该事件的订阅。

   ```ts
   // context为UIAbility实例的AbilityContext
   this.context.eventHub.off('event1');
   ```


## 使用globalThis进行数据同步

globalThis是[ArkTS引擎实例](thread-model-stage.md)内部的一个全局对象，引擎内部的UIAbility/ExtensionAbility/Page都可以使用，因此可以使用globalThis对象进行数据同步。

**图1** 使用globalThis进行数据同步
![globalThis1](figures/globalThis1.png)


如上图所示，下面从如下三个场景和一个注意点来介绍globalThis的使用：

- [UIAbility和Page之间使用globalThis](#uiability和page之间使用globalthis)
- [UIAbility和UIAbility之间使用globalThis](#uiability和uiability之间使用globalthis)
- [UIAbility和ExtensionAbility之间使用globalThis](#uiability和extensionability之间使用globalthis)
- [globalThis使用的注意事项](#globalthis使用的注意事项)

### UIAbility和Page之间使用globalThis

通过在globalThis对象上绑定属性/方法，可以实现UIAbility组件与UI之间的数据同步。例如在UIAbility组件中绑定want参数，即可在UIAbility对应的UI上使用want参数信息。

1. 调用[`startAbility()`](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)方法启动一个UIAbility实例时，被启动的UIAbility创建完成后会进入[`onCreate()`](../reference/apis/js-apis-app-ability-uiAbility.md#uiabilityoncreate)生命周期回调，且在[`onCreate()`](../reference/apis/js-apis-app-ability-uiAbility.md#uiabilityoncreate)生命周期回调中能够接受到传递过来的want参数，可以将want参数绑定到globalThis上。

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';

   export default class EntryAbility extends UIAbility {
     onCreate(want, launch) {
       globalThis.entryAbilityWant = want;
       ...
     }

     ...
   }
   ```

2. 在UI中即可通过globalThis获取到want参数信息。

   ```ts
   let entryAbilityWant;

   @Entry
   @Component
   struct Index {
     aboutToAppear() {
       entryAbilityWant = globalThis.entryAbilityWant;
     }

     // 页面展示
     build() {
       ...
     }
   }
   ```


### UIAbility和UIAbility之间使用globalThis

在同一个应用中，UIAbility与UIAbility之间的数据传递可以通过将数据绑定到全局变量globalThis上进行同步。例如，在UIAbilityA中将数据保存在globalThis对象中，然后跳转到UIAbilityB中就可以获取该数据。

1. UIAbilityA中保存数据一个字符串数据并挂载到globalThis上。

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class UIAbilityA extends UIAbility {
     onCreate(want, launch) {
       globalThis.entryAbilityStr = 'UIAbilityA'; // UIAbilityA存放字符串“UIAbilityA”到globalThis
       ...
     }
   }
   ```

2. UIAbilityB中获取对应的数据。

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class UIAbilityB extends UIAbility {
     onCreate(want, launch) {
       // UIAbilityB从globalThis读取name并输出
       console.info('name from entryAbilityStr: ' + globalThis.entryAbilityStr);
       ...
     }
   }
   ```


### UIAbility和ExtensionAbility之间使用globalThis

在同一个应用中，UIAbility和ExtensionAbility之间的数据传递也可以通过将数据绑定到全局变量globalThis上进行同步。例如，在UIAbilityA中保存数据，在ServiceExtensionAbility中就可以获取该数据。

1. UIAbilityA中保存数据一个字符串数据并挂载到globalThis上。

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class UIAbilityA extends UIAbility {
     onCreate(want, launch) {
       // UIAbilityA存放字符串“UIAbilityA”到globalThis
       globalThis.entryAbilityStr = 'UIAbilityA';
       ...
     }
   }
   ```

2. ExtensionAbility中获取数据。

   ```ts
   import Extension from '@ohos.app.ability.ServiceExtensionAbility'

   export default class ServiceExtAbility extends Extension {
     onCreate(want) {
       // ServiceExtAbility从globalThis读取name并输出
       console.info('name from entryAbilityStr: ' + globalThis.entryAbilityStr);
       ...
     }
   }
   ```


### globalThis使用的注意事项

**图2** globalThis注意事项
![globalThis2](figures/globalThis2.png)

- Stage模型下进程内的UIAbility组件共享ArkTS引擎实例，使用globalThis时需要避免存放相同名称的对象。例如UIAbilityA和UIAbilityB可以使用globalThis共享数据，在存放相同名称的对象时，先存放的对象会被后存放的对象覆盖。

- globalThis不支持跨进程使用，不同进程的UIAbility组件和ExtensionAbility组件无法使用globalThis共享数据，进程模型及进程间通信机制见[进程模型概述](./process-model-stage.md#进程模型概述)。

- FA模型因为每个UIAbility组件之间引擎隔离，不会存在该问题。

- 对于绑定在globalThis上的对象，其生命周期与ArkTS虚拟机实例相同，建议在使用完成之后将其赋值为null，以减少对应用内存的占用。

Stage模型上同名对象覆盖导致问题的场景举例说明。

1. 在UIAbilityA文件中使用globalThis中存放了[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)。

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class UIAbilityA extends UIAbility {
     onCreate(want, launch) {
       globalThis.context = this.context; // UIAbilityA存放context到globalThis
       ...
     }
   }
   ```

2. 在UIAbilityA的页面中获取该[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)并进行使用。使用完成后将UIAbilityA实例切换至后台。

   ```ts
   @Entry
   @Component
   struct Index {
     onPageShow() {
       let ctx = globalThis.context; // 页面中从globalThis中取出context并使用
     }
     // 页面展示
     build() {
       ...
     }
   }
   ```

3. 在UIAbilityB文件中使用globalThis中存放了[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)，并且命名为相同的名称。

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class UIAbilityB extends UIAbility {
     onCreate(want, launch) {
       // UIAbilityB覆盖了UIAbilityA在globalThis中存放的context
       globalThis.context = this.context;
       ...
     }
   }
   ```

4. 在UIAbilityB的页面中获取该[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)并进行使用。此时获取到的globalThis.context已经表示为UIAbilityB中赋值的[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)内容。

   ```ts
   @Entry
   @Component
   struct Index {
     onPageShow() {
       let ctx = globalThis.context; // Page中从globalThis中取出context并使用
     }
     // 页面展示
     build() {
       ...
     }
   }
   ```

5. 在UIAbilityB实例切换至后台，将UIAbilityA实例从后台切换回到前台。此时UIAbilityA的onCreate生命周期不会再次进入。

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class UIAbilityA extends UIAbility {
     onCreate(want, launch) { // UIAbilityA从后台进入前台，不会再走这个生命周期
       globalThis.context = this.context;
       ...
     }
   }
   ```

6. 在UIAbilityA的页面再次回到前台时，其获取到的globalThis.context表示的为UIAbilityB的[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)，而不是UIAbilityA的[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)，在UIAbilityA的页面中使用则会出错。

   ```ts
   @Entry
   @Component
   struct Index {
     onPageShow() {
       let ctx = globalThis.context; // 这时候globalThis中的context是UIAbilityB的context
     }
     // 页面展示
     build() {
       ...
     }
   }
   ```

## 使用AppStorage/LocalStorage进行数据同步

ArkUI提供了AppStorage和LocalStorage两种应用级别的状态管理方案，可用于实现应用级别和UIAbility级别的数据同步。使用这些方案可以方便地管理应用状态，提高应用性能和用户体验。其中，AppStorage是一个全局的状态管理器，适用于多个UIAbility共享同一状态数据的情况；而LocalStorage则是一个局部的状态管理器，适用于单个UIAbility内部使用的状态数据。通过这两种方案，开发者可以更加灵活地控制应用状态，提高应用的可维护性和可扩展性。详细请参见[应用级变量的状态管理](../quick-start/arkts-application-state-management-overview.md)。
