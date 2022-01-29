# Synchronization Between AppStorage and Components<a name="EN-US_TOPIC_0000001166649261"></a>

In  [Managing Component States](ts-component-states-state.md), we have defined how to synchronize the state variables of the child components with the  **@State**  decorated variables in the parent component or ancestor component, including  **@Prop**,  **@Link**, and  **@Consume**.

In this section, we'll describe how to synchronize component variables with the  **AppStorage**  through the  **@StorageLink**  and  **@StorageProp**  decorators.

## @StorageLink Decorator<a name="en-us_topic_0000001149818715_section4857142710453"></a>

Two-way data binding can be established between components and the  **AppStorage**  through state variables decorated by  **@StorageLink\(_key_\)**. Wherein,  **key**  is the attribute key value in the  **AppStorage**. When a component containing the  **@StorageLink**  decorated variable is created, the variable is initialized using the value in the  **AppStorage**. Changes made to this variable in the component will be first synchronized to the  **AppStorage**, and then to other bound instances, such as  **PersistentStorage**  or other bound UI components.

## @StorageProp Decorator<a name="en-us_topic_0000001149818715_section7874173385112"></a>

One-way data binding can be established between components and the  **AppStorage**  through state variables decorated by  **@StorageProp\(_key_\)**. Wherein,  **key**  is the attribute key value in the  **AppStorage**. When a component containing the  **StorageProp**  decorated variable is created, the variable is initialized using the value in the  **AppStorage**. The change to the attribute value in the  **AppStorage**  will cause the bound UI component to update the state.

## Example<a name="en-us_topic_0000001149818715_section7991192013546"></a>

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
    this.label = (this.lang === 'en') ? 'Number' : 'Count'
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
            AppStorage.Set<string>('languageCode', 'en')
          }
          this.label = (this.lang === 'en') ? 'Number' : 'Count'
        })
    }
  }
}
```

Each time the user clicks the  **Count**  button, the value of  **this.varA**  will increase by 1. This variable is synchronized with  **varA**  in the  **AppStorage**. Each time the user clicks the language icon, the value of  **languageCode**  in the  **AppStorage**  will be changed, and the change will be synchronized to the  **this.lang**  variable.

