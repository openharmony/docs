



# **LocalStorage**

LocalStorage是框架的TS类。其目的是为可变和非可变状态属性提供存储，这些属性是构建应用程序UI的特定部分（如一个Ability的UI）。

应用程序可以创建多个LocalStorage实例，每一个Ability对应一个LocalStorage实例。

在有@Entry的所有@Component中，最多可以分配一个LocalStorage实例。另外它的所有子组件都将继承对此存储对象的访问权。

@Component最多可以访问一个LocalStorage实例，一个LocalStorage对象可以分配给多个@Component。

LocalStorage生命周期一般是跟随Ability的生命周期。

LocalStorage定义时没有给定默认值时，那么可以使用@LocalStorageLink和@LocalStorageProp的默认值，如果定义时给定了默认值，那么不会再使用@LocalStorageLink和@LocalStorageProp的默认值

### 属性：

| 方法        | 参数                            | 返回值                                | 定义                                                         |
| ----------- | ------------------------------- | ------------------------------------- | ------------------------------------------------------------ |
| constructor | obj? : Object                   | N/A                                   | 创建一个新的LocalStorage对象。（可选）使用给定对象进行初始化。object.keys(obj)返回的所有对象属性及其值都将添加到LocalStorage. |
| has         | key : String                    | boolean                               | 返回具有给定名称的属性的true存在于LocalStorage中。           |
| get         | key : String                    | T or undefined                        | 获取具有给定名称的属性。(如果存在)                           |
| set         | key : String , newValue : T     | boolean                               | 如果存在具有给定名称的属性，请设置其值并返回true。否则不要设置任何内容并返回false |
| setOrCreate | key : String , newValue？ : T   | boolean                               | 如果存在具有给定名称的属性：更新其值并返回true。如果不存在具有给定名称的属性：在LocalStorage中创建具有给定默认值的新属性。默认值必须是T类型。不允许undefined or null 返回true。 |
| link        | key ：String                    | ObservedPropertyAbstract \| undefined | 如果存在具有给定键的属性，返回对此属性的双向数据绑定。值更改将从using变量或者组件同步到LocalStorage，并从LocalStorage实例同步到任何变量或组件。如果不存在具有此键的属性，返回undefined，该函数具有其他可选属性，这些参数当前保留在框架内部使用的link/linkAndSet |
| setAndLink  | key : String , defaultValue : T | ObservedPropertyAbstract              | 如果存在具有给定键的属性，请确定为Link定义的返回值。如果属性不存在，请使用给定的默认类型和值defaultValue创建属性（参考setOrCrtare）,并返回该属性的值（参考link）。默认值必须为T类型。 |
| prop        | key：String                     | ObservedPropertyAbstract              | 如果存在具有给定键的属性，则返回对此属性的单向数据绑定，表示值更改将从LocalStorage同步到任何变量或组件。属性值为基本类型，该函数具有其他可选参数， |
| setAndProp  | key：String，defaultValue : S   | ObservedPropertyAbstract              | 如果存在具有给定键的属性，返回此属性的单向数据绑定（参考prop）。如果该属性不存在，请使用给定的默认值创建一个defaultValue（参考setOrCreate）并返回一个prop（参考prop）。默认值为S |
| delete      | key：String                     | boolean                               | 删除具有给定名称的属性并返回true，否则不执行任何操作并返回false |
| keys        | none                            | IterableIterator<string>              | 返回所有属性键的迭代器，参考Map.keys()                       |
| size        | none                            | number                                | 与Map.size()用法相同                                         |
| clear       | none                            | boolean                               | 删除所有的属性，如果当前有状态变量依旧引用此属性，返回false  |

### @LocalStorageLink装饰器

组件通过使用@LocalStorageLink(key)装饰的状态变量，key值为LocalStorage中的属性键值@LocalStorageLink是与LocalStorage建立双向数据绑定，用法请参考StorageLink

### @LocalStorageProp装饰器

组件通过使用LocalStorageProp(key)装饰的状态变量，key值为LocalStorage中的属性键值，@LocalStorageProp是与LocalStorage建立单向数据绑定，用法请参考StorageProps

### 示例1（在一个Ability创建的LocalStorage）：

```swift
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
//    Main window is created,set main page for this ability        		             
    windowStage.setUlContent(this.context,"pages/index",this.storage)    
  }    
  onWindowStageDestroy() {
//    Main window is destroyed,release Ul related resources  
    console.log("[Demo] MainAbility onWindoeStageDestroy")   
  }    
  onForeground() {
//    Ability has brought to foreground       
    console.log("[Demo] MainAbility onForeground")   
  }    
  onBackground() {
//    Ability has back to background       
    console.log("[Demo] MainAbility onBackground")    
  }
}
```

获取页面：

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