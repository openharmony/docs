# Component ID


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes

  | Name | Type | Default Value | Description | 
| -------- | -------- | -------- | -------- |
| id | string | '' | Unique ID of the component. The uniqueness is ensured by the user. | 


## APIs


### getInspectorByKey

getInspectorByKey(id: string): string

Obtains all attributes of the component with the specified ID, excluding the information about child components.

- Parameters
    | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | id | string | Yes | - | ID of the component whose attributes are to be obtained. | 

- Return value
    | Type | Description | 
  | -------- | -------- |
  | string | JSON string of the component attribute list. | 


### sendEventByKey

sendEventByKey(id: string, action: number, params: string): boolean

Sends an event to the component with the specified ID.

- Parameters
    | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | id | string | Yes | - | ID of the component for which the event is to be sent. | 
  | action | number | Yes | - | Type of the event to be sent. The options are as follows:<br/>- Click event: 10.<br/>- LongClick: 11. | 
  | params | string | Yes | - | Event parameters. If there is no parameter, pass an empty string **""**. | 

- Return value
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns **false** if the component with the specified ID cannot be found; returns **true** otherwise. | 


## Example

  
```
@Entry
@Component
struct IdExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button() {
        Text('click')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }
      .type(ButtonType.Capsule)
      .margin({
        top: 20
      }).onClick(() => {
        console.info(getInspectorByKey("click"))
        console.info(getInspectorTree())
        setTimeout(() => {
          sendEventByKey("longclick", 11, "")
        }, 2000)
      }).id('click')

      Button() {
        Text('longclick')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }
      .type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .backgroundColor('#0D9FFB')
      .gesture(
        LongPressGesture().onActionEnd(() => {
          console.info('long clicked')
        }))
      .id('longclick')
    }
    .width('100%')
    .height('100%')
  }
}
```
