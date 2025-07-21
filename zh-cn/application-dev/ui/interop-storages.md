# ArkTS1.2与ArkTS1.1应用间状态存储互操作

## 概述

应用间状态存储互操作适用于[ArkTS1.2使用ArkTS1.1自定义组件](./interop-compatible-component.md)中应用间使用AppStorage，LocalStorage，PersistentStorage，Environment的场景。

## 架构原理

在互操作场景下，[占位组件](../reference/apis-arkui/arkui-ts/ts-interop-compatible-component.md)连接ArkTS1.2和ArkTS1.1的UI节点，构建完整的UI界面。通过建立统一数据存储机制，确保ArkTS1.2和ArkTS1.1访问相同数据管理对象，实现状态和数据互通。

## 设计理念

应用间状态存储互操作适用于主模块使用ArkTS1.2、子模块使用ArkTS1.1的场景。

- 渐进式迁移：逐步将ArkTS1.1组件迁移到新版本。

- 使用旧应用级别的状态存储：使用稳定的ArkTS1.1的AppStorage，LocalStorage，PersistentStorage，Environment。

## 参数传递规则

- 遵循ArkTS1.2使用ArkTS1.1自定义组件[约束与限制](./interop-compatible-component.md#约束与限制)。

- 遵循ArkTS1.1 AppStorage[限制条件](./state-management/arkts-appstorage.md#限制条件)。

- 遵循ArkTS1.1 LocalStorage[限制条件](./state-management/arkts-localstorage.md#限制条件)。

- 遵循ArkTS1.1 PersistentStorage[限制条件](./state-management/arkts-persiststorage.md#限制条件)。

- 遵循ArkTS1.1 Environment[限制条件](./state-management/arkts-environment.md#限制条件)。

## 开发场景

### ArkTS1.1使用ArkTS1.2AppStorage中的数据

使用ArkTS1.1自定义组件中的\@StorageLink与ArkTS1.2的AppStorage数据双向绑定；使用ArkTS1.1自定义组件中的\@StorageProp与ArkTS1.2的AppStorage数据单向绑定。

示例如下：
- 创建ArkTS1.1子模块`har1_1`，在`har1_1/src/main/ets/components`目录创建并导出自定义组件。

```TypeScript
// har1_1/src/main/ets/components/MainPage.ets

@Component
export struct MainPage {
  // 1.1绑定1.2AppStorage数据
  @StorageLink('LinkA') appLink: string = 'dynamicA';
  @StorageProp('LinkA') appProp: string = 'dynamicA';
  build() {
    Row() {
      Column() {
        Text('----- dynamic storagelink -----')
        Text(`Storage LinkA: ${this.appLink}`) // expect 333
        Button('change LinkA').backgroundColor('#FFFF00FF')
          .onClick((e: ClickEvent) => {
            this.appLink += 'b'; // 点击后同步更新1.1+1.2所有Text组件
          })
        Text('----- dynamic storageprop -----')
        Text(`Storage PropA: ${this.appProp}`) // expect 333
        Button('change PropA').backgroundColor('#FFFF00FF')
          .onClick((e: ClickEvent) => {
            this.appProp += 'b'; // 点击后仅更新当前Text组件
          })
      }
    }
  }
}
```

- 在主模块`entry`的`oh-package.json5`文件中配置子模块依赖。

```json
// entry/oh-package.json5

"dependencies": {
  "har1_1": "file:../har1_1"
}
```

- 在ArkTS1.2主模块中引入ArkTS1.1组件。

```TypeScript
'use static';

// entry/src/main/ets/pages/Index.ets
import { MainPage } from 'har1_1';
import { Entry, Text, Column, Component, Button, ClickEvent } from '@ohos.arkui.component';
import { AppStorage, StorageLink, StoragePropRef } from '@ohos.arkui.stateManagement';

@Entry
@Component
struct MyStateSample {
  // 1.2使用AppStorage，初始化key 'LinkA'
  linkAFlag: boolean = AppStorage.setOrCreate<string>('LinkA', '333', Type.from<string>());

  @StorageLink('LinkA') appLink: string = 'staticA';
  @StoragePropRef('LinkA') appProp: string = 'staticA';
  build() {
    Column() {
      Text('----- static storagelink -----')
      Text(`Storage LinkA: ${this.appLink}`)  // expect 333
      Button('change LinkA').backgroundColor('#FFFF00FF')
        .onClick((e: ClickEvent) => {
          this.appLink += 'a'; // 点击后同步更新1.1+1.2所有Text组件
        })
      Text('----- static storageprop -----')
      Text(`Storage PropA: ${this.appProp}`) // expect 333
      Button('change PropA').backgroundColor('#FFFF00FF')
        .onClick((e: ClickEvent) => {
          this.appProp += 'a'; // 点击后仅更新当前Text组件
        })
      MainPage()
    }
  }
}

```

### ArkTS1.1使用ArkTS1.2LocalStorage中的数据

使用ArkTS1.1自定义组件中的\@StorageLink与ArkTS1.2的LocalStorage数据双向绑定；使用ArkTS1.1自定义组件中的\@StorageProp与ArkTS1.2的LocalStorage数据单向绑定。

示例如下：
- 创建ArkTS1.1子模块`har1_1`，在`har1_1/src/main/ets/components`目录创建并导出自定义组件。

```TypeScript
// har1_1/src/main/ets/components/MainPage.ets

@Component
export struct MainPage {
  @LocalStorageLink('LinkA') localLink: string = 'dynamicA';
  @LocalStorageProp('LinkA') localProp: string = 'dynamicA';
  build() {
    Row() {
      Column() {
        Text('----- dynamic localstoragelink -----')
        Text(`LocalStorage LinkA: ${this.localLink}`)
        Button('change LinkA').backgroundColor('#FFFF00FF') // expect 'test'
          .onClick((e: ClickEvent) => {
            this.localLink += 'b'; // 点击后同步更新1.1+1.2所有Text组件
          })
        Text('----- dynamic localstorageprop -----')
        Text(`LocalStorage PropA: ${this.localProp}`) // expect 'test'
        Button('change PropA').backgroundColor('#FFFF00FF')
          .onClick((e: ClickEvent) => {
            this.localProp += 'b'; // 点击后仅更新当前Text组件
          })
      }
    }
  }
}
```

- 在主模块`entry`的`oh-package.json5`文件中配置子模块依赖。

```json
// entry/oh-package.json5

"dependencies": {
  "har1_1": "file:../har1_1"
}
```

- 在ArkTS1.2主模块中引入ArkTS1.1组件。

```TypeScript
'use static';

// entry/src/main/ets/pages/Index.ets
import { MainPage } from 'har1_1';
import { Entry, Text, Column, Component, Button, ClickEvent } from '@ohos.arkui.component';
import { LocalStorage, IStorageProperties, LocalStorageLink, LocalStoragePropRef } from '@ohos.arkui.stateManagement';

const para: Record<string, IStorageProperties> = {'LinkA': {value: 'test', ttype: Type.from<string>()}};
const storageInst = (): LocalStorage => new LocalStorage(para);

@Entry({ storage: 'storageInst' })
@Component
struct MyStateSample {
  @LocalStorageLink('LinkA') localLink: string = 'staticA';
  @LocalStoragePropRef('LinkA') localProp: string = 'staticA';
  build() {
    Column() {
      Text('----- static localstoragelink -----')
      Text(`LocalStorage LinkA: ${this.localLink}`) // expect test
      Button('change LinkA').backgroundColor('#FFFF00FF')
        .onClick((e: ClickEvent) => {
          this.localLink += 'a'; // 点击后同步更新1.1+1.2所有Text组件
        })
      Text('----- static localstorageprop -----')
      Text(`LocalStorage PropA: ${this.localProp}`) // expect test
      Button('change PropA').backgroundColor('#FFFF00FF')
        .onClick((e: ClickEvent) => {
          this.localProp += 'a'; // 点击后仅更新当前Text组件
        })
      MainPage()
    }
  }
}
```

### ArkTS1.1使用ArkTS1.2PersistentStorage中的数据

使用ArkTS1.1自定义组件中的\@StorageLink与ArkTS1.2的PersistentStorage数据双向绑定；使用ArkTS1.1自定义组件中的\@StorageProp与ArkTS1.2的PersistentStorage数据单向绑定。

示例如下：
- 创建ArkTS1.1子模块`har1_1`，在`har1_1/src/main/ets/components`目录创建并导出自定义组件。

```TypeScript
// har1_1/src/main/ets/components/MainPage.ets

@Component
export struct MainPage {
  // 1.1绑定1.2PersistentStorage数据
  @StorageLink('LinkA') persistLink: string = 'dynamicB';
  @StorageProp('LinkA') persistProp: string = 'dynamicB';
  build() {
    Row() {
      Column() {
        Text('----- dynamic storagelink -----')
        Text(`PersistentStorage LinkA: ${this.persistLink}`) // expect 'hello'，退出应用重新进入后修改保留
        Button('change LinkA').backgroundColor('#FFFF00FF')
          .onClick((e: ClickEvent) => {
            this.persistLink += 'b';  // 点击后同步更新1.1+1.2所有Text组件
          })
        Text('----- dynamic storageprop -----')
        Text(`PersistentStorage PropB: ${this.persistProp}`) // expect 'hello'，退出应用重新同步为LinkA的值
        Button('change PropB').backgroundColor('#FFFF00FF')
          .onClick((e: ClickEvent) => {
            this.persistProp += 'b'; // 点击后仅更新当前Text组件
          })
      }
    }
  }
}
```

- 在主模块`entry`的`oh-package.json5`文件中配置子模块依赖。

```json
// entry/oh-package.json5

"dependencies": {
  "har1_1": "file:../har1_1"
}
```

- 在ArkTS1.2主模块中引入ArkTS1.1组件。

```TypeScript
'use static';

// entry/src/main/ets/pages/Index.ets
import { MainPage } from 'har1_1';
import { Entry, Text, Column, Component, Button, ClickEvent } from '@ohos.arkui.component';
import { PersistentStorage, StorageLink, StoragePropRef } from '@ohos.arkui.stateManagement';

@Entry
@Component
struct MyStateSample {
  // 1.2使用PersistentStorage，初始化key 'LinkA'
  persistFlag: boolean = PersistentStorage.persistProp('LinkA', Type.from<string>(), 'hello');

  @StorageLink('LinkA') persistLink: string = 'staticB';
  @StoragePropRef('LinkA') persistProp: string = 'staticB';
  build() {
    Column() {
      Text('----- static storagelink -----')
      Text(`PersistentStorage LinkA: ${this.persistLink}`) // expect 'hello'，退出应用重新进入后修改保留
      Button('change LinkA').backgroundColor('#FFFF00FF')
        .onClick((e: ClickEvent) => {
          this.persistLink += 'a'; // 点击后同步更新1.1+1.2所有Text组件
        })
      Text('----- static storageprop -----')
      Text(`PersistentStorage PropB: ${this.persistProp}`) // expect 'hello'，退出应用重新同步为LinkA的值
      Button('change PropB').backgroundColor('#FFFF00FF')
        .onClick((e: ClickEvent) => {
          this.persistProp += 'a'; // 点击后仅更新当前Text组件
        })
      MainPage()
    }
  }
}
```

### ArkTS1.1使用ArkTS1.2Environment中的数据

使用ArkTS1.1自定义组件中的\@StorageLink与ArkTS1.2的Environment数据双向绑定；使用ArkTS1.1自定义组件中的\@StorageProp与ArkTS1.2的Environment数据单向绑定。

示例如下：
- 创建ArkTS1.1子模块`har1_1`，在`har1_1/src/main/ets/components`目录创建并导出自定义组件。

```TypeScript
// har1_1/src/main/ets/components/MainPage.ets

@Component
export struct MainPage {
  // 1.1绑定1.2Environment数据
  @StorageLink('fontScale') fontScaleLink: number = 4.0;
  @StorageProp('fontScale') fontScaleProp: number = 4.0;
  build() {
    Row() {
      Column() {
        Text('----- dynamic storagelink -----')
        Text(`Environment fontscale link: ${this.fontScaleLink}`) // expect 1
          .fontSize(this.fontScaleLink)
        Button('change fontscale link').backgroundColor('#FFFF00FF')
          .onClick((e: ClickEvent) => {
            this.fontScaleLink += 2.0; // 点击后同步更新1.1+1.2所有Text组件fontSize+2
          })
        Text('----- dynamic storageprop -----')
        Text(`Environment fontscale prop: ${this.fontScaleProp}`) // expect 1
          .fontSize(this.fontScaleProp)
        Button('change fontscale prop').backgroundColor('#FFFF00FF')
          .onClick((e: ClickEvent) => {
            this.fontScaleProp += 2.0; // 点击后仅更新当前Text组件fontSize+2
          })
      }
    }
  }
}
```

- 在主模块`entry`的`oh-package.json5`文件中配置子模块依赖。

```json
// entry/oh-package.json5

"dependencies": {
  "har1_1": "file:../har1_1"
}
```

- 在ArkTS1.2主模块中引入ArkTS1.1组件。

```TypeScript
'use static';

// entry/src/main/ets/pages/Index.ets
import { MainPage } from 'har1_1';
import { Entry, Text, Column, Component, Button, ClickEvent } from '@ohos.arkui.component';
import { Environment, StorageLink, StoragePropRef } from '@ohos.arkui.stateManagement';

@Entry
@Component
struct MyStateSample {
  // 1.2使用Environment，获取fontScale
  fontScaleFlag: boolean = Environment.envProp<number>('fontScale', 2.0);
  @StorageLink('fontScale') fontScaleLink: number = 3.0;
  @StoragePropRef('fontScale') fontScaleProp: number = 3.0;
  build() {
    Column() {
      Text('----- static storagelink -----')
      Text(`Environment fontscale link: ${this.fontScaleLink}`)
        .fontSize(this.fontScaleLink) // expect 1
      Button('change fontScale link').backgroundColor('#FFFF00FF')
        .onClick((e: ClickEvent) => {
          this.fontScaleLink += 1.0; // 点击后同步更新1.1+1.2所有Text组件
        })
      Text('----- static storageprop -----')
      Text(`Environment fontscale prop: ${this.fontScaleProp}`)
        .fontSize(this.fontScaleProp) // expect 1
      Button('change fontScale prop').backgroundColor('#FFFF00FF')
        .onClick((e: ClickEvent) => {
          this.fontScaleProp += 1.0; // 点击后仅更新当前Text组件
        })
      MainPage()
    }
  }
}
```

### 完整示例结构

```text
project/
├── entry/          # ArkTS1.2主模块
│   └── src/
│       └── main/
│           └── ets/
│               └── pages/
│                   └── Index.ets
│
└── har1_1/         # ArkTS1.1子模块
    └── src/
        └── main/
            └── ets/
                └── components/
                    └── MainPage.ets
```
