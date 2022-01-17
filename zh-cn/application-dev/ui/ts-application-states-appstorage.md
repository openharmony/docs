# 应用程序的数据存储

**AppStorage**是应用程序中的单例对象，由UI框架在应用程序启动时创建。它的目的是为可变应用程序状态属性提供中央存储。**AppStorage**包含整个应用程序中需要访问的所有状态属性。只要应用程序保持运行，**AppStorage**存储就会保留所有属性及其值，属性值可以通过唯一的键值进行访问。


UI组件可以通过装饰器将应用程序状态数据与**AppStorage**进行同步。应用业务逻辑的实现也可以通过接口访问**AppStorage**。


AppStorage的选择状态属性可以与不同的数据源或数据接收器同步。这些数据源和接收器可以是设备上的本地或远程，并具有不同的功能，如数据持久性。这样的数据源和接收器可以独立于UI在业务逻辑中实现。


默认情况下，**AppStorage**中的属性是可变的，**AppStorage**还可使用不可变（只读）属性。


## AppStorage接口说明

| 方法 | 参数说明 | 返回值 | 定义 |
| -------- | -------- | -------- | -------- |
| Link | key:&nbsp;string | \@Link | 如果存在具有给定键的数据，则返回到此属性的双向数据绑定，该双向绑定意味着变量或者组件对数据的更改将同步到**AppStorage**，通过**AppStorage**对数据的修改将同步到变量或者组件。如果具有此键的属性不存在或属性为只读，则返回**undefined**。 |
| SetAndLink | key&nbsp;:&nbsp;String<br/>defaultValue:&nbsp;T | \@Link | 与Link接口类似。如果当前的key在AppStorage有保存，则返回此key对应的value。如果此key未被创建，则创建一个对应default值的Link返回。 |
| Prop | key:&nbsp;string | \@Prop | 如果存在具有给定键的属性，则返回到此属性的单向数据绑定。该单向绑定意味着只能通过**AppStorage**将属性的更改同步到变量或者组件。该方法返回的变量为不可变变量，适用于可变和不可变的状态属性，如果具有此键的属性不存在则返回**undefined**。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;prop方法对应的属性值类型为简单类型。 |
| SetAndProp | key&nbsp;:&nbsp;string<br/>defaultValue:&nbsp;S | \@Prop | 与Prop接口类似。如果当前的key在AppStorage有保存，则返回此key对应的value。如果此key未被创建，则创建一个对应default值的Prop返回。 |
| Has | key:&nbsp;string | boolean | 判断对应键值的属性是否存在。 |
| Keys | void | array&lt;string&gt; | 返回包含所有键的字符串数组。 |
| Get | string | T或undefined | 通过此接口获取对应此key值的value |
| Set | string,&nbsp;&nbsp;newValue&nbsp;：T | void | 对已保存的key值，替换其value值。 |
| SetOrCreate | string,&nbsp;&nbsp;newValue&nbsp;：T | boolean | 如果相同名字的属性存在：如果此属性可以被更改返回true，否则返回false<br/>如果相同名字的属性不存在：创建第一个赋值为defaultValue的属性，不支持null和undefined |
| Delete | key&nbsp;:&nbsp;string | boolean | 删除属性，如果存在返回true，不存在返回false |
| Clear | none | boolean | 删除所有的属性，如果当前有状态变量依旧引用此属性，则返回false |
| IsMutable | key:&nbsp;string |  | 返回此属性是否存在并且是否可以改变。 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 当前接口当前仅可以处理基础类型数据，对于修改object中某一个值尚未支持。


## 示例

```
let link1 = AppStorage.Link('PropA')let link2 = AppStorage.Link('PropA')let prop = AppStorage.Prop('PropA')

link1 = 47  // causes link1 == link2 == prop == 47
link2 = link1 + prop  // causes link1 == link2 == prop == 94
prop = 1  // error, prop is immutable
```
