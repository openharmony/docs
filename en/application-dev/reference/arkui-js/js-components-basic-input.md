# input

The **\<input>** component provides an interactive interface to receive user input. It can be a radio button, check box, button, single-line text box, and more.

## Required Permissions

None

## Child Component

Not supported

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name                  | Type                                               | Default Value | Mandatory | Triggered when                                               |
| --------------------- | -------------------------------------------------- | ------------- | --------- | ------------------------------------------------------------ |
| type                  | string                                             | text          | No        | Type of the input component. Available values include **text**, **email**, **date**, **time**, **number**, **password**, **button**, **checkbox**, and **radio**.The **text**, **email**, **date**, **time**, **number**, and **password** types can be dynamically switched and modified.The **button**, **checkbox**, and **radio** types cannot be dynamically modified. Available values include:<br>-**button**: a button that can be clicked<br>-**checkbox**: a check box<br>-**radio**: a radio button that allows users to select one from multiple others with the same name<br>-**text**: a single-line text field<br>-**email**: a field used for an email address<br>-**date**: date control, including the year, month, and day, but excluding time<br>-**time**: time control, without the time zone<br>-**number**: field for entering digits<br>-**password**: password field, in which characters will be shieldedNOTE:For wearables, only **button**, **radio**, and **checkbox** types are supported. |
| checked               | boolean                                            | false         | No        | Whether the **\<input>** component is selected. This attribute is valid only when **type** is set to **checkbox** or **radio**. |
| name                  | string                                             | -             | No        | Name of the input component.                                 |
| value                 | string                                             | -             | No        | Value of the input component. When **type** is **radio**, this attribute is mandatory and the value must be unique for radio buttons with the same name. |
| placeholder           | string                                             | -             | No        | Content of the hint text. This attribute is available only when the component type is set to **text**, **email**, **date**, **time**, **number**, or **password**. |
| maxlength             | number                                             | -             | No        | Maximum number of characters that can be entered in the input box. If no value is specified, the number of characters is not limited. |
| enterkeytype          | string                                             | default       | No        | Dynamic modification is not supported.Available values include:<br/>-default<br/>-next<br/>-go<br/>-done<br/>-send<br/>-Search<br/>NOTE:The soft keyboard is automatically collapsed after you click the **Enter** button, except when **next** is displayed for the button. |
| headericon            | string                                             | -             | No        | Icon resource path before text input. This icon does not support click events and is unavailable for **button**, **checkbox**, and **radio** types. The supported icon image formats are JPG, PNG, and SVG. |
| showcounter5+         | boolean                                            | false         | No        | Whether to display the character counter for an input box. This attribute takes effect only when **maxlength** is set. |
| menuoptions5+         | Array\<[MenuOption](js-components-basic-input.md)> | -             | No        | Menu options displayed after users touch the **More** button. |
| autofocus6+           | boolean                                            | false         | No        | Whether to automatically obtain the focus.NOTE:This attribute setting does not take effect on the application home page. You can enable a text box on the home page to automatically obtain focus, by delaying the **focus** method call (for about 100–500 ms) in **onActive**. |
| selectedstart6+       | number                                             | -1            | No        | Start position for text selection.                           |
| selectedend6+         | number                                             | -1            | No        | End position for text selection.                             |
| softkeyboardenabled6+ | boolean                                            | true          | No        | Whether to display the soft keyboard during editing.         |
| showpasswordicon6+    | boolean                                            | true          | No        | Whether to display the icon at the end of the password text box. The setting is valid only when **type** is set to **password**. |

**Table 1** MenuOption5+



| Name    | Type   | Triggered when                      |
| ------- | ------ | ----------------------------------- |
| icon    | string | Path of the icon for a menu option. |
| content | string | Text content of a menu option.      |

## Styles

In addition to the styles in [Universal Styles](js-components-common-styles.md), the following styles are supported.



| Name              | Type             | Default Value | Mandatory | Triggered when                                               |
| ----------------- | ---------------- | ------------- | --------- | ------------------------------------------------------------ |
| color             | \<color>          | #e6000000     | No        | Font color of the single-line text box or button.            |
| font-size         | \<length>         | 16px          | No        | Font size of the single-line text box or button.             |
| allow-scale       | boolean          | true          | No        | Whether the font size changes with the system's font size settings.NOTE:If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart. |
| placeholder-color | \<color>          | #99000000     | No        | Color of the hint text in the single-line text box. This attribute is available when the component type is set to **text**, **email**, **date**, **time**, **number**, or **password**. |
| font-weight       | number \| string | normal        | No        | Font weight of the single-line text box or button. For details, see [font-weight](js-components-basic-text.md) of the **text** component. |
| caret-color6+     | \<color>          | -             | No        | Color of the input cursor.                                   |

## Events

In addition to the events in [Universal Events](js-components-common-events.md), the following events are supported.

- When the input component type is set to **text**, **email**, **date**, **time**, **number**, or **password**, the following events are supported.

  

  | Name           | Parameter                                  | Triggered when                                               |
  | -------------- | ------------------------------------------ | ------------------------------------------------------------ |
  | change         | { value:inputValue }                       | Triggered when the content entered in the text box changes. The most recent text entered by the user is returned.NOTE:If you change the **value** attribute directly, this event will not be triggered. |
  | enterkeyclick  | { value:enterKey }                         | Triggered when the **Enter** key on a soft keyboard is pressed. The type of the **Enter** key is returned, which is of the number type. Available values are as follows:<br>-**2**: returned if **enterkeytype** is **go**.<br>-**3**: returned if **enterkeytype** is **search**.<br>-**4**: returned if **enterkeytype** is **send**.<br>-**5**: returned if **enterkeytype** is **next**.<br>-**6**: returned if **enterkeytype** is **default**, **done**, or is not set.<br/> |
  | translate5+    | { value: selectedText }                    | Triggered when users click the translate button in the pop menu displayed after they select a text segment. The selected text content is returned. |
  | share5+        | { value: selectedText }                    | Triggered when users click the share button in the pop menu displayed after they select a text segment. The selected text content is returned. |
  | search5+       | { value: selectedText }                    | Triggered when users click the search button in the pop menu displayed after they select a text segment. The selected text content is returned. |
  | optionselect5+ | { index:optionIndex, value: selectedText } | Triggered when users click a menu option in the pop menu displayed after they select a text segment. This event is valid only when the **menuoptions** attribute is set. The option index and selected text content are returned. |
  | selectchange6+ | { start: number, end: number }             | Triggered when the text selection changes.                   |

- When the input component type is set to **checkbox** or **radio**, the following events are supported.

  

  | Name   | Parameter                 | Triggered when                                               |
  | ------ | ------------------------- | ------------------------------------------------------------ |
  | change | { checked:true \| false } | Triggered when the checked status of the **checkbox** or **radio** button changes. |

## Methods

In addition to the methods in [Universal Methods](js-components-common-methods.md), the following events are supported.



| Name      | Parameter                                                    | Triggered when                                               |
| --------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| focus     | {focus:true\|false}: If **focus** is not passed, the default value **true** is used. | Obtains or loses the focus of a component. When the component type is set to text, email, date, time, number, or password, the input method can be displayed or collapsed. |
| showError | { error: string }                                            | Displays the error message. This attribute is available when the component type is set to text, email, date, time, number, or password. |
| delete6+  | -                                                            | Deletes the text content based on the current cursor position when the input component type is set to **text**, **email**, **date**, **time**, **number**, or **password**. If the current input component does not have a cursor, the last character is deleted and the cursor is displayed by default. |

## Example Code

1. Single-line text box

   ```
   <!-- xxx.hml -->
   <div class="content">
     <input id="input" class="input" type="text" value="" maxlength="20" enterkeytype="send"
       headericon="/common/search.svg" placeholder="Please input text" onchange="change"
       onenterkeyclick="enterkeyClick">
     </input>
     <input class="button" type="button" value="Submit" onclick="buttonClick"></input>
   </div>
   ```

   ```
   /* xxx.css */
   .content {
     width: 60%;
     flex-direction: column;
     align-items: center;
   }
   .input {
     placeholder-color: gray;
   }
   .button {
     background-color: gray;
     margin-top: 20px;
   }
   ```

   ```
   // xxx.js
   import prompt from '@system.prompt'
   export default {
     change(e){
       prompt.showToast({
         message: "value: " + e.value,
         duration: 3000,
       });
     },
     enterkeyClick(e){
       prompt.showToast({
         message: "enterkey clicked",
         duration: 3000,
       });
     },
     buttonClick(e){
       this.$element("input").showError({
         error: 'error text'
       });
     },
   }
   ```

   ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/reference/arkui-js/figures/1-2.png)

2. Common button

   ```
   <!-- xxx.hml -->
   <div class="div-button">
     <input class="button" type="button" value="Input-Button"></input>
   </div>
   ```

   ```
   /* xxx.css */
   .div-button {
     flex-direction: column;
     align-items: center;
     
     
   }
   .button {
     margin-top: 30px;
     width: 280px;
   }
   ```

   ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/reference/arkui-js/figures/en-us_image_0000001198898293.png)

3. Check box

   ```
   <!-- xxx.hml -->
   <div class="content">
     <input onchange="checkboxOnChange" checked="true" type="checkbox"></input>
     
   </div>
   ```

   ```
   /* xxx.css */
   .content{
     width: 100%;
     height: 200px;
     
     
     align-items: center; 
     justify-content: center;   
   }
   ```

   ```
   // xxx.js
   import prompt from '@system.prompt'
   export default {
     checkboxOnChange(e) {
       prompt.showToast({
         message:'checked: ' + e.checked,
         duration: 3000,
       });
     }
   }
   ```

   ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/reference/arkui-js/figures/en-us_image_0000001173324749.png)

4. Radio button

   ```
   <!-- xxx.hml -->
   <div class="content">
     <input type="radio" checked='true' name="radioSample" value="radio1" onchange="onRadioChange('radio1')"></input>
     <input type="radio" checked='false' name="radioSample" value="radio2" onchange="onRadioChange('radio2')"></input>
     <input type="radio" checked='false' name="radioSample" value="radio3" onchange="onRadioChange('radio3')"></input>
   </div>
   ```

   ```
   /* xxx.css */
   .content{
     width: 100%;
     height: 200px;
     justify-content: center;
     align-items: center;
   }
   ```

   ```
   // xxx.js
   import prompt from '@system.prompt'
   export default {
     onRadioChange(inputValue, e) {
       if (inputValue === e.value) {
         prompt.showToast({
           message: 'The chosen radio is ' + e.value,
           duration: 3000,
         });
       }
     }
   }
   ```

   ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/reference/arkui-js/figures/1-3.png)