# AppStorage与组件同步

在[管理组件拥有的状态](../ui/ts-component-states-state.md)中，我们已经定义了如何将组件的状态变量与父组件或祖先组件中的**@State**装饰的状态变量同步，主要包括**@Prop**、**@Link**、**@Consume**。


本章节将定义如何将组件变量与**AppStorage**同步，主要提供**@StorageLink**和**@StorageProp**装饰器。


## @StorageLink装饰器

组件通过使用**@StorageLink(key)**装饰的状态变量，将与**AppStorage**建立双向数据绑定，**key**为**AppStorage**中的属性键值。当创建包含**@StorageLink**的状态变量的组件时，该状态变量的值将使用**AppStorage**中的值进行初始化。在UI组件中对**@StorageLink**的状态变量所做的更改将同步到**AppStorage**，并从**AppStorage**同步到任何其他绑定实例中，如**PersistentStorage**或其他绑定的UI组件。


## @StorageProp装饰器

组件通过使用**@StorageProp(key)**装饰的状态变量，将于**AppStorage**建立单向数据绑定，**key**标识AppStorage中的属性键值。当创建包含**@StoageProp**的状态变量的组件时，该状态变量的值将使用**AppStorage**中的值进行初始化。**AppStorage**中的属性值更改会导致绑定的UI组件进行状态更新。


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
