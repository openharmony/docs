# Component ID


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| id | string | '' | Unique&nbsp;ID&nbsp;of&nbsp;the&nbsp;component.&nbsp;The&nbsp;uniqueness&nbsp;is&nbsp;ensured&nbsp;by&nbsp;the&nbsp;user. | 


## APIs


### getInspectorByKey

getInspectorByKey(id: string): string

Obtains all attributes of the component with the specified ID, excluding the information about child components.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | id | string | Yes | - | ID&nbsp;of&nbsp;the&nbsp;component&nbsp;whose&nbsp;attributes&nbsp;are&nbsp;to&nbsp;be&nbsp;obtained. | 

- Return value
    | Type | Description | 
  | -------- | -------- |
  | string | JSON&nbsp;string&nbsp;of&nbsp;the&nbsp;component&nbsp;attribute&nbsp;list. | 


### sendEventByKey

sendEventByKey(id: string, action: number, params: string): boolean

Sends an event to the component with the specified ID.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | id | string | Yes | - | ID&nbsp;of&nbsp;the&nbsp;component&nbsp;for&nbsp;which&nbsp;the&nbsp;event&nbsp;is&nbsp;to&nbsp;be&nbsp;sent. | 
  | action | number | Yes | - | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;be&nbsp;sent.&nbsp;The&nbsp;options&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;Click&nbsp;event:&nbsp;10.<br/>-&nbsp;LongClick:&nbsp;11. | 
  | params | string | Yes | - | Event&nbsp;parameters.&nbsp;If&nbsp;there&nbsp;is&nbsp;no&nbsp;parameter,&nbsp;pass&nbsp;an&nbsp;empty&nbsp;string&nbsp;**""**. | 

- Return value
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**false**&nbsp;if&nbsp;the&nbsp;component&nbsp;with&nbsp;the&nbsp;specified&nbsp;ID&nbsp;cannot&nbsp;be&nbsp;found;&nbsp;returns&nbsp;**true**&nbsp;otherwise. | 


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
