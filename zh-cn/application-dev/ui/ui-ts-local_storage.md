# **LocalStorage**

  说明：该功能从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

LocalStorage是应用程序中的存储单元，是为应用程序范围内的可变状态属性和非可变状态属性提供存储，可变状态属性和非可变状态属性是构建应用程序UI的特定部分。如一个Ability的UI。

应用层：一个应用程序可以创建多个LocalStorage实例，应用程序的每一个Ability对应一个LocalStorage实例。

Ability：一个Ability中@Entry的所有子代@Component中，最多可以分配一个LocalStorage实例。另外Ability中的所有子组件都将继承对此存储对象的访问权。（一个应用程序可拥有多个Ability）

一个@Component最多可以访问一个LocalStorage实例，一个LocalStorage对象可以分配给多个@Component。

LocalStorage的生命周期跟随其关联的Ability。

## @LocalStorageLink装饰器

组件通过使用@LocalStorageLink(key)装饰的状态变量（key值为LocalStorage中的属性键值），与LocalStorage建立双向数据绑定，当创建包含@LocalStorageLink的状态变量的组件时，该状态变量的值将会使用LocalStorage中的值进行初始化。（如果LocalStorage中未定义初始值，将使用@LocalStorageLink定义的初始值）。在UI组件中对@LocalStorageLink的状态变量所做的更改将同步到LocalStorage中，并从LocalStorage同步到Ability下的组件中。

## @LocalStorageProp装饰器

组件通过使用LocalStorageProp(key)装饰的状态变量（key值为LocalStorage中的属性键值），与LocalStorage建立单向数据绑定，当创建包含@LocalStorageProp的状态变量的组件时，该状态变量的值将使用LocalStorage中的值进行初始化。LocalStorage中的属性值的更改会导致当前Ability下的所有UI组件进行状态更新。

  注意：LocalStorage定义时没有给定默认值时，那么可以使用组件内@LocalStorageLink和@LocalStorageProp的默认值，如果定义时给定了默认值，那么不会再使用@LocalStorageLink和@LocalStorageProp的默认值。

## LocalStorage接口：

### Constructor  

constructor(initializingProperties?: Object)

创建一个新的LocalStorage对象，对对象进行初始化。

| 参数名                 | 类型   | 返回值 | 必填 | 默认值 | 参数描述                                                     |
| ---------------------- | ------ | ------ | :--: | ------ | ------------------------------------------------------------ |
| initializingProperties | Object | N/A    |  否  | -      | object.keys(obj)返回的所有对象属性及其值都将添加到LocalStorage。 |



### Has

has(propName: string): boolean

判断属性值是否存在。

#### 参数：

| 参数名   | 类型   | 必填 | 默认值 | 参数描述       |
| -------- | ------ | :--: | ------ | -------------- |
| propName | string |  是  | -      | 属性的属性值。 |

#### 返回值：

| 类型    | 描述                   |
| ------- | ---------------------- |
| boolean | 返回判断后的布尔类型。 |



### Get

get<T>(propName: string): T

获取对应key值的value。

#### 参数：

| 参数名   | 类型   | 必填 | 默认值 | 参数描述            |
| -------- | ------ | :--: | ------ | ------------------- |
| propName | string |  是  | -      | 要获取对应的key值。 |

#### 返回值：

| 类型           | 描述               |
| -------------- | ------------------ |
| T or undefined | 返回获得后的结果。 |



### Set

 set<T>(propName: string, newValue: T): boolean

存储对象值。

#### 参数：

| 参数名   | 类型   | 必填 | 默认值 | 参数描述          |
| -------- | ------ | :--: | ------ | ----------------- |
| propName | string |  是  | -      | 要设置的key值。   |
| newValue | T      |  是  | -      | 要设置的value值。 |

#### 返回值：

| 类型    | 描述                                                  |
| ------- | ----------------------------------------------------- |
| boolean | 如果存在key值，设置value值并返回true，否则返回false。 |



### SetOrCreate

 setOrCreate<T>(propName: string, newValue: T): boolean

创建或更新setOrCreate内部的值。

#### 参数：

| 参数名   | 类型   | 必填 | 默认值 | 参数描述                    |
| -------- | ------ | :--: | ------ | --------------------------- |
| propName | string |  是  | -      | 传入要更新或者创建的key值。 |
| newValue | T      |  是  | -      | 传入要更新或创建的value值。 |

#### 返回值：

| 类型    | 描述                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果已存在与给定键名字相同的属性，更新其值且返回true。如果不存在具有给定名称的属性，在LocalStorage中创建具有给定默认值的新属性，默认值必须是T类型。不允许undefined or null 返回true。 |



### Link

 link<T>(propName: string, linkUser?: T, subscribersName?: string): T

与localStorage双向数据绑定。

#### 参数：

| 参数名   | 类型   | 必填 | 默认值 | 参数描述               |
| -------- | ------ | :--: | ------ | ---------------------- |
| propName | string |  是  | -      | 要双向绑定的属性名称。 |

#### 返回值：

| 类型 | 描述                                                         |
| ---- | ------------------------------------------------------------ |
| T    | 如果存在具有给定键的属性，返回到此属性的双向绑定，该双向绑定意味着变量或者组件对数据的更改将同步到LocalStorage，然后通过LocalStorage实例同步到任何变量或组件。如果不存在给定键的属性，返回undefined。 |



### SetAndLink

 setAndLink<T>(propName: string, defaultValue: T, linkUser?: T, subscribersName?: string): T

与link接口类似，双向数据绑定localStorage。

#### 参数：

| 参数名       | 类型   | 必填 | 默认值 | 参数描述              |
| ------------ | ------ | :--: | ------ | --------------------- |
| propName     | string |  是  | -      | 传入要进行创建的key值 |
| defaultValue | T      |  是  | -      | 要进行设置的默认值    |

#### 返回值：

| 类型  | 描述                                                         |
| ----- | ------------------------------------------------------------ |
| @Link | 与Link接口类似，如果当前的key保存于LocalStorage，返回该key值对应的value值。如果该key值未被创建，则创建一个对应的defaultValue的Link返回。 |

 注：Link接口链接：https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/ui/ts-component-states-link.md



### Prop

prop<T>(propName: string, propUser?: T, subscribersName?: string): T

单向属性绑定的一种。更新组件的状态。

#### 参数：

| 参数名   | 类型   | 必填 | 默认值 | 参数描述                  |
| -------- | ------ | :--: | ------ | ------------------------- |
| propName | string |  是  | -      | 传入要单向数据绑定的key值 |

#### 返回值：

| 类型  | 描述                                                         |
| ----- | ------------------------------------------------------------ |
| @Prop | 如果存在具有给定键的属性，返回此属性的单向数据绑定。该单向绑定意味着只能通过LocalStorage将属性的更改同步到变量或组件。该方法返回的变量为不可变变量，适用于可变和不可变的状态变量。如果此键的属性不存在则返回undefined。 |



### SetAndProp

setAndProp<T>(propName: string, defaultValue: T, propUser?: T, subscribersName?: string): T

与Prop接口类似，存在localStorage的单向数据绑定prop值

#### 参数：

| 参数名       | 类型   | 必填 | 默认值 | 参数描述                    |
| ------------ | ------ | :--: | ------ | --------------------------- |
| propName     | string |  是  | -      | 要保存的的键值对中的key值。 |
| defaultValue | S      |  是  | -      | 创建的默认值。              |

#### 返回值：

| 类型  | 描述                                                         |
| ----- | ------------------------------------------------------------ |
| @Prop | 如果当前的key保存与LocalStorage，返回该key值对应的value值。如果该key值未被创建，则创建一个对应的defaultValue的Prop返回。 |

注：Prop接口链接：https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/ui/ts-component-states-prop.md



### Delete

delete(propName: string): boolean

删除key指定的键值对

#### 参数：

| 参数名   | 类型   | 必填 | 默认值 | 参数描述              |
| -------- | ------ | :--: | ------ | --------------------- |
| propName | string |  是  | -      | 要删除的属性的key值。 |

#### 返回值：

| 类型    | 描述                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 删除key指定的键值对，如果存在且删除成功返回true，不存在或删除失败返回false。 |



### Keys

keys(): IterableIterator<string>

查找所有键

#### 参数：

| 参数名 | 类型 | 必填 | 默认值 | 参数描述 |
| ------ | ---- | :--: | ------ | -------- |
| none   | none |  是  | -      | 无       |

#### 返回值：

| 类型          | 描述                         |
| ------------- | ---------------------------- |
| array<string> | 返回包含所有键的字符串数组。 |



### Size

size(): number

存在的键值对的个数

#### 参数：

| 参数名 | 类型 | 必填 | 默认值 | 参数描述 |
| ------ | ---- | :--: | ------ | -------- |
| none   | none |  是  | -      | 无       |

#### 返回值：

| 类型   | 描述                   |
| ------ | ---------------------- |
| number | 与Map.size()用法相同。 |



### Clear

clear(): boolean

删除所有的属性

#### 参数：

| 参数名 | 类型 | 必填 | 默认值 | 参数描述 |
| ------ | ---- | :--: | ------ | -------- |
| none   | none |  是  | -      | 无       |

#### 返回值：

| 类型    | 描述                                                        |
| ------- | ----------------------------------------------------------- |
| boolean | 删除所有的属性，如果当前有状态变量依旧引用此属性，返回false |

### 示例1（在一个Ability创建的LocalStorage）：

```javascript
import Ability from '@ohos.appLication.Ability'
export default class MainAbility extends Ability {    
  storage : LocalStorage    
  onCreate(want) {    
    this.storage = new LocalStorage();
    this.storage.setOrCreate("storageSimpleProp",121);    
    console.log("[Demo MainAbility onCreate]");    
    globalThis.abilityWant = want;   
  }  
  onDestroy() {    
    console.log("[Demo MainAbility onDestroy]")  
  }    
  onWindowStageCreate(windowStage) {
    windowStage.setUIContent(this.context,"pages/index",this.storage)    
  }    
  onWindowStageDestroy() {
    console.log("[Demo] MainAbility onWindoeStageDestroy")   
  }    
  onForeground() {
    console.log("[Demo] MainAbility onForeground")   
  }    
  onBackground() {
    console.log("[Demo] MainAbility onBackground")    
  }
}
```

@Component组件获取数据：

```
let storage = LocalStorage.GetShared()
@Entry(storage)
@Component
struct LocalStorageComponent {
  @LocalStorageLink("storageSimpleProp") simpleVarName: number = 0
  build() {
    Column(){
      Text(this.simpleVarName.toString())
        .onClick(()=>{
          this.simpleVarName +=1;
        })
      Text(JSON.stringify(this.simpleVarName))
        .fontSize(50)
    }
    .height(500)
  }
}
```

### 示例2（在Entry页面定义LocalStorage）:

```
let storage = new LocalStorage({"PropA":47});
@Entry(storage)
@Component 
struct ComA {    
  @LocalStorageLink("PropA") storLink : number = 1;    
  build() {    
	Column() {        
	  Text(`Parent from LocalStorage $(this.storLink)`)            				                 
        .onClick(()=>this.storLink+=1)            
	    Child()    
 	  }    
  }
}


@Component
struct Child{    
  @LocalStorageLink("PropA") storLink : number = 1;    
  build() {    
	Text(`Parent from LocalStorage $(this.storLink)`)        
	  .onClick(()=>this.storLink1+=1)    
  }
}
```