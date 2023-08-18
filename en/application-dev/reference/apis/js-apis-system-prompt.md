# @system.prompt (Prompt)

The **PromptAction** module provides APIs for creating and showing toasts, dialog boxes, and action menus.

> **NOTE**
>
> - The APIs of this module are deprecated since API version 8. You are advised to use [@ohos.promptAction](js-apis-promptAction.md) instead.
>
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import prompt from '@system.prompt';
```

## prompt.showToast

showToast(options: ShowToastOptions): void

Shows the toast.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                   | Mandatory  | Description             |
| ------- | ------------------------------------- | ---- | --------------- |
| options | [ShowToastOptions](#showtoastoptions) | Yes   | Options for showing the toast.|

**Example**

```js
export default {    
  showToast() {        
    prompt.showToast({            
      message: 'Message Info',            
      duration: 2000,        
    });    
  }
}
```


## prompt.showDialog

showDialog(options: ShowDialogOptions): void

Shows the dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                     | Mandatory  | Description         |
| ------- | --------------------------------------- | ---- | ----------- |
| options | [ShowDialogOptions](#showdialogoptions) | Yes   | Options for showing the dialog box.|


**Example**

```js
export default {    
  showDialog() {       
    prompt.showDialog({           
      title: 'Title Info',            
      message: 'Message Info',           
      buttons: [                
        {                    
           text: 'button',                   
           color: '#666666',                
         },            
       ],            
       success: function(data) {                
         console.log('dialog success callback, click button : ' + data.index);           
       },            
       cancel: function() {                
         console.log('dialog cancel callback');            
       },
     });    
  }
}
```

## prompt.showActionMenu<sup>6+</sup>

showActionMenu(options: ShowActionMenuOptions): void

Shows the action menu.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description                  |
| ------- | ---------------------------------------- | ---- | -------------------- |
| options | [ShowActionMenuOptions](#showactionmenuoptions) | Yes   | Options for showing the action menu.|


**Example**

```js
export default {    
  showActionMenu() {        
    prompt.showActionMenu({            
      title: 'Title Info',            
      buttons: [                
        {                    
          text: 'item1',                    
          color: '#666666',                
        },                
        {                    
           text: 'item2',                    
           color: '#000000',                
        },            
      ],            
      success: function(tapIndex) {                
        console.log('dialog success callback, click button : ' + data.tapIndex);           
      },            
      fail: function(errMsg) {                
        console.log('dialog fail callback' + errMsg);            
      },       
    });    
  }
}
```
## ShowToastOptions

Describes the options for showing the toast.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                 | Type          | Mandatory  | Description                                      |
| ------------------- | -------------- | ---- | ---------------------------------------- |
| message             | string         | Yes   | Text to display.                                |
| duration            | number         | No   | Duration that the toast will remain on the screen. The default value is 1500 ms. The recommended value range is 1500 ms to 10000 ms. If a value less than 1500 ms is set, the default value is used.|
| bottom<sup>5+</sup> | string\|number | No   | Distance between the toast border and the bottom of the screen.                        |

## Button

Defines the prompt information of a button.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type  | Mandatory  | Description     |
| ----- | ------ | ---- | ------- |
| text  | string | Yes   | Text displayed on the button.|
| color | string | Yes   | Color of the button.|

## ShowDialogSuccessResponse

Defines the dialog box response result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type  | Mandatory  | Description        |
| ----- | ------ | ---- | ---------- |
| index | number | Yes   | Data index.|

## ShowDialogOptions

Describes the options for showing the dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type                                    | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| title    | string                                   | No   | Title of the text to display.                                   |
| message  | string                                   | No   | Text body.                                   |
| buttons  | [[Button](#button), [Button](#button)?, [Button](#button)?] | No   | Array of buttons in the dialog box. The array structure is **{text:'button', color: '\#666666'}**. One to six buttons are supported. If there are more than six buttons, extra buttons will not be displayed.|
| success  | (data: [ShowDialogSuccessResponse](#showdialogsuccessresponse)) => void | No   | Callback upon success.                            |
| cancel   | (data: string, code: string) => void     | No   | Callback upon failure.                            |
| complete | (data: string) => void                   | No   | Called when the API call is complete.                            |

## ShowActionMenuOptions<sup>6+</sup>

Describes the options for showing the action menu.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type                                    | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| title    | string                                   | No   | Title of the text to display.                                   |
| buttons  | [[Button](#button), [Button](#button)?, [Button](#button)?, [Button](#button)?, [Button](#button)?, [Button](#button)?] | Yes   | Array of buttons in the dialog box. The array structure is **{text:'button', color: '\#666666'}**. One to six buttons are supported.|
| success  | (tapIndex: number, errMsg: string) => void | No   | Invoked when a dialog box is displayed.                               |
| fail     | (errMsg: string) => void                 | No   | Callback upon failure.                            |
| complete | (data: string) => void                   | No   | Invoked when a dialog box is closed.                               |
