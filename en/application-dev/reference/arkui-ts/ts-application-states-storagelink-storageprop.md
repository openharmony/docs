# Synchronization Between AppStorage and Components<a name="EN-US_TOPIC_0000001166649261"></a>

In  [Managing Component States](ts-component-states-state.md), we have defined how to synchronize the state variables of the component with the  **@State**  annotated variables in the parent component or ancestor component, including  **@Prop**,  **@Link**, and  **@Consume**.

This section describes how to synchronize component variables with the  **AppStorage**  and mainly covers the  **@StorageLink**  and  **@StorageProp**  decorators.

## @StorageLink Decorator<a name="en-us_topic_0000001149818715_section4857142710453"></a>

Components decorated by  **@StorageLink\(_key_\)**  have bidirectional data binding with the  **AppStorage**.  **key**  is the attribute key value in the  **AppStorage**. When a component containing the  **@StorageLink**  annotated variable is created, the value of the variable is initialized using the value in the  **AppStorage**. Changes made to the  **@StorageLink**  annotated variable in the UI component will be synchronized to the  **AppStorage**  and from the  **AppStorage**  to any other binding instance, such as  **PersistentStorage**  or other bound UI components.

## @StorageProp Decorator<a name="en-us_topic_0000001149818715_section7874173385112"></a>

Components decorated by  **@StorageProp\(_key_\)**  have unidirectional data binding with the  **AppStorage**.  **key**  is the attribute key value in the  **AppStorage**. When a component containing the  **StorageProp**  annotated variable is created, the value of the variable is initialized using the value in the  **AppStorage**. The change to the attribute value in the  **AppStorage**  will cause the bound UI component to update the state.

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
        this.label = (this.lang === 'zh') ? 'Number' : 'Count'
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
        this.label = (this.lang === 'zh') ? 'Number' : 'Count'
        })
    }
  }
}
```

Each time the user clicks the Count button, the value of  **this.varA**  increases. This variable is synchronized with  **varA**  in the  **AppStorage**. Each time the user clicks the icon indicating the current language, the value of  **languageCode**  in the  **AppStorage**  is changed. The change is synchronized to the  **this.lang**  variable.

