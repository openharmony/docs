# 应用程序的数据存储

AppStorage是应用程序中的单例对象，由UI框架在应用程序启动时创建，在应用程序退出时销毁，为应用程序范围内的可变状态属性提供中央存储。AppStorage包含整个应用程序中需要访问的所有状态属性，只要应用程序保持运行，AppStorage就会保存所有属性及属性值，属性值可以通过唯一的键值进行访问。


UI组件可以通过装饰器将应用程序状态数据与AppStorage进行同步，应用业务逻辑的实现也可以通过接口访问AppStorage。


AppStorage的选择状态属性可以与不同的数据源或数据接收器同步，这些数据源和接收器可以是设备上的本地或远程，并具有不同的功能，如数据持久性。这样的数据源和接收器可以独立于UI在业务逻辑中实现。


默认情况下，AppStorage中的属性是可变的，AppStorage还可使用不可变（只读）属性。


## AppStorage接口

| 方法 | 参数说明 | 返回值 | 定义 |
| -------- | -------- | -------- | -------- |
| SetAndLink | key:&nbsp;string,<br/>defaultValue:&nbsp;T | @Link | 与Link接口类似，如果当前的key保存于AppStorage，则返回该key对应的value。如果该key未被创建，则创建一个对应default值的Link返回。 |
| Set | key:&nbsp;string,<br/>newValue:&nbsp;T | void | 对已保存的key值，替换其value值。 |
| Link | key:&nbsp;string | @Link | 如果存在具有给定键的数据，则返回到此属性的双向数据绑定，该双向绑定意味着变量或者组件对数据的更改将同步到AppStorage，通过AppStorage对数据的修改将同步到变量或者组件。如果具有此键的属性不存在或属性为只读，则返回undefined。 |
| SetAndProp | propName:&nbsp;string,<br/>defaultValue:&nbsp;S | @Prop | 与Prop接口类似，如果当前的key保存于AppStorage，则返回该key对应的value。如果该key未被创建，则创建一个对应default值的Prop返回。 |
| Prop | key:&nbsp;string | @Prop | 如果存在具有给定键的属性，则返回此属性的单向数据绑定。该单向绑定意味着只能通过AppStorage将属性的更改同步到变量或者组件。该方法返回的变量为不可变变量，适用于可变和不可变的状态属性，如果具有此键的属性不存在则返回undefined。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;prop方法对应的属性值类型为简单类型。 |
| SetOrCreate | key:&nbsp;string,<br/>newValue:&nbsp;T | boolean | 如果已存在与给定键名字相同的属性，如果此属性可以被更改则替换其value值且返回true，否则不替换且返回false。<br/>如果不存在存在与给定键名字相同的属性,&nbsp;则创建一个键为key,&nbsp;值为newValue的属性，属性值不支持null和undefined。 |
| Get | key:&nbsp;string | T或undefined | 通过此接口获取对应key值的value。 |
| Has | propName:&nbsp;string | boolean | 判断对应键值的属性是否存在。 |
| Keys | void | array&lt;string&gt; | 返回包含所有键的字符串数组。 |
| Delete | key:&nbsp;string | boolean | 删除key指定的键值对，如果存在且删除成功返回true，不存在或删除失败返回false。 |
| Clear | void | boolean | 删除所有的属性，如果当前有状态变量依旧引用此属性，则返回false。 |
| IsMutable | key:&nbsp;string | boolean | 返回此属性是否存在并且是否可以改变。 |


## AppStorage与组件同步

在[管理组件拥有的状态](ts-component-states-state.md)中，已经定义了如何将组件的状态变量与父组件或祖先组件中的@State装饰的状态变量同步，主要包括@Prop、@Link、@Consume。

本章节定义如何将组件变量与AppStorage同步，主要提供@StorageLink和@StorageProp装饰器。


### @StorageLink装饰器

组件通过使用@StorageLink(key)装饰的状态变量，与AppStorage建立双向数据绑定，key为AppStorage中的属性键值。当创建包含@StorageLink的状态变量的组件时，该状态变量的值将使用AppStorage中的值进行初始化。在UI组件中对@StorageLink的状态变量所做的更改将同步到AppStorage，并从AppStorage同步到任何其他绑定实例中，如PersistentStorage或其他绑定的UI组件。


### @StorageProp装饰器

组件通过使用@StorageProp(key)装饰的状态变量，将与AppStorage建立单向数据绑定，key标识AppStorage中的属性键值。当创建包含@StoageProp的状态变量的组件时，该状态变量的值将使用AppStorage中的值进行初始化。AppStorage中的属性值的更改会导致绑定的UI组件进行状态更新。


## 示例

```
let varA = AppStorage.Link('varA')
let envLang = AppStorage.Prop('languageCode')

@Entry
@Component
struct ComponentA {
  @StorageLink('varA') varA: number = 2
  @StorageProp('languageCode') lang: string = 'en'
  private label: string = 'count'

  private aboutToAppear() {
    this.label = (this.lang === 'zh') ? '数' : 'Count'
  }

  build() {
    Row({ space: 20 }) {

      Button(`${this.label}: ${this.varA}`)
        .onClick(() => {
          AppStorage.Set<number>('varA', AppStorage.Get<number>('varA') + 1)
        })
      Button(`lang: ${this.lang}`)
        .onClick(() => {
          if (this.lang === 'zh') {
            AppStorage.Set<string>('languageCode', 'en')
          } else {
            AppStorage.Set<string>('languageCode', 'zh')
          }
          this.label = (this.lang === 'zh') ? '数' : 'Count'
        })
    }
  }
}
```

每次用户单击Count按钮时，this.varA变量值都会增加，此变量与AppStorage中的varA同步。每次用户单击当前语言按钮时，修改AppStorage中的languageCode，此修改会同步给this.lang变量。
