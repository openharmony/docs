# Prompt

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import prompt from '@ohos.prompt'
```
## Required Permissions

None.

## prompt.showToast

showToast(options: ShowToastOptions): void

Shows the toast.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name    | Type                                   | Mandatory  | Description     |
| ------- | ------------------------------------- | ---- | ------- |
| options | [ShowToastOptions](#showtoastoptions) | Yes   | Toast options.|

**Example**
  ```
  export default {    
    showToast() {        
      prompt.showToast({            
        message: 'Message Info',
        duration: 2000,      
      });
    }
  }
  ```
## ShowToastOptions

Describes the options for showing the toast.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type            | Mandatory  | Description                                      |
| -------- | -------------- | ---- | ---------------------------------------- |
| message  | string         | Yes   | Text to display.                                |
| duration | number         | No   | Duration that the toast will remain on the screen. The default value is 1500 ms. The recommended value range is 1500 ms to 10000 ms. If a value less than 1500 ms is set, the default value is used.|
| bottom   | &lt;length&gt; | No   | Distance between the toast border and the bottom of the screen.                        |

## prompt.showDialog

showDialog(options: ShowDialogOptions): Promise&lt;ShowDialogSuccessResponse&gt;

Shows a dialog box. This API uses a promise to return the result synchronously.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name    | Type                                     | Mandatory  | Description    |
| ------- | --------------------------------------- | ---- | ------ |
| options | [ShowDialogOptions](#showdialogoptions) | Yes   | Dialog box options.|

**Return value**

| Type                                      | Description      |
| ---------------------------------------- | -------- |
| Promise&lt;[ShowDialogSuccessResponse](#showdialogsuccessresponse)&gt; | Promise used to return the dialog box response result.|

**Example**

  ```
  export default {
    showDialog() {
      prompt.showDialog({
        title: 'Title Info',
        message: 'Message Info',
        buttons: [
          {
             text: 'button1',
             color: '#000000',
          },
          {
             text: 'button2',
             color: '#000000',
          }
         ],
      })
      .then(data => {
        console.info('showDialog success, click button: ' + data.index);
      })
      .catch(err => {
        console.info('showDialog error: ' + err);
      })
    }
  }
  ```

## prompt.showDialog

showDialog(options: ShowDialogOptions, callback: AsyncCallback&lt;ShowDialogSuccessResponse&gt;):void 

Shows a dialog box. This API uses a callback to return the result asynchronously.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Parameters**
| Name     | Type                                      | Mandatory  | Description          |
| -------- | ---------------------------------------- | ---- | ------------ |
| options  | [ShowDialogOptions](#showdialogoptions)  | Yes   | Dialog box options.|
| callback | AsyncCallback&lt;[ShowDialogSuccessResponse](#showdialogsuccessresponse)&gt; | Yes   | Callback used to return the dialog box response result.  |

**Example**
  ```
  export default {
    callback(err, data) {
      if(err) {
        console.info('showDialog err: ' + err);
        return;
      }
      console.info('showDialog success callback, click button: ' + data.index);
    },
    showDialog() {
      prompt.showDialog({
        title: 'showDialog Title Info',
        message: 'Message Info',
        buttons: [
          {
            text: 'button1',
            color: '#000000',
          },
          {
            text: 'button2',
            color: '#000000',
          }
        ]
      }, this.callback);
    }
  }
  ```

## ShowDialogOptions

Describes the options for showing the dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type    | Mandatory  | Description                                      |
| ------- | ------ | ---- | ---------------------------------------- |
| title   | string | No   | Title of the text to display.                                   |
| message | string | No   | Text body.                                   |
| buttons | Array  | No   | Array of buttons in the dialog box. The array structure is **{text:'button',&nbsp;color:&nbsp;'\#666666'}**. One to three buttons are supported. The first button is of the **positiveButton** type, the second is of the **negativeButton** type, and the third is of the **neutralButton** type.|

## ShowDialogSuccessResponse 

Describes the dialog box response result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type    | Description                 |
| ----- | ------ | ------------------- |
| index | number | Index of the selected button in the array.|


## prompt.showActionMenu

showActionMenu(options: ActionMenuOptions, callback: AsyncCallback&lt;ActionMenuSuccessResponse&gt;):void

Shows an action menu. This API uses a callback to return the result asynchronously.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [ActionMenuOptions](#actionmenuoptions)  | Yes   | Action menu options.  |
| callback | AsyncCallback&lt;[ActionMenuSuccessResponse](#actionmenusuccessresponse)> | Yes   | Callback used to return the action menu response result.|


**Example**
  ```
  export default {
    callback(err, data) {
      if(err) {
        console.info('showActionMenu err: ' + err);
        return;
      }
      console.info('showActionMenu success callback, click button: ' + data.index);
    },
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
        ]
      }, this.callback)
    }
  }
  ```

## prompt.showActionMenu

showActionMenu(options: ActionMenuOptions): Promise\<ActionMenuSuccessResponse>

Shows an action menu. This API uses a promise to return the result synchronously.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name    | Type                                     | Mandatory  | Description     |
| ------- | --------------------------------------- | ---- | ------- |
| options | [ActionMenuOptions](#actionmenuoptions) | Yes   | Action menu options.|

**Return value**
| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise&lt;[ActionMenuSuccessResponse](#actionmenusuccessresponse)&gt; | Promise used to return the action menu response result.|

**Example**
  ```
  export default {
    showActionMenu() {
      prompt.showActionMenu({
        title: 'showActionMenu Title Info',
        buttons: [
          {
            text: 'item1',
            color: '#666666',
          },
          {
             text: 'item2',
             color: '#000000',
          },
        ]
      })
      .then(data => {
        console.info('showActionMenu success, click button: ' + data.index);
      })
      .catch(err => {
        console.info('showActionMenu error: ' + err);
      })
    }
  }
  ```
## ActionMenuOptions

Describes the options for showing the action menu.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type    | Mandatory  | Description                                      |
| ------- | ------ | ---- | ---------------------------------------- |
| title   | string | No   | Title of the text to display.                                   |
| buttons | Array  | Yes   | Array of menu items. The array structure is **{text:'button',&nbsp;color:&nbsp;'\#666666'}**. One to six items are supported. If there are more than six items, extra items will not be displayed.|

## ActionMenuSuccessResponse

Describes the action menu response result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type    | Mandatory  | Description                      |
| ----- | ------ | ---- | ------------------------ |
| index | number | No   | Index of the selected button in the array, starting from **0**.|
