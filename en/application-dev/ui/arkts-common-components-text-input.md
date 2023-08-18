# Text Input (TextInput/TextArea)


The **\<TextInput>** and **\<TextArea>** components are input components typically used to accept input from the user, such as comments, chat messages, and table content. They can be used in combination with other components to meet more diversified purposes, for example, login and registration. For details, see [TextInput](../reference/arkui-ts/ts-basic-components-textinput.md) and [TextArea](../reference/arkui-ts/ts-basic-components-textarea.md).


## Creating a Text Box

The **\<TextInput>** component provides single-line text input, while the **\<TextArea>** component provides multi-line text input. To create these components, use the following APIs:


```ts
TextArea(value?:{placeholder?: ResourceStr, text?: ResourceStr, controller?: TextAreaController})
```



```ts
TextInput(value?:{placeholder?: ResourceStr, text?: ResourceStr, controller?: TextInputController})
```


- Single-line text box

  ```ts
  TextInput()
  ```

  ![en-us_image_0000001511580844](figures/en-us_image_0000001511580844.png)


- Multi-line text box

  ```ts
  TextArea()
  ```

  ![en-us_image_0000001562940481](figures/en-us_image_0000001562940481.png)

  The **\<TextArea>** component automatically wraps text so that each line does not have more than the width of the component.


  ```ts
  TextArea({text:"I am TextArea I am TextArea I am TextArea"}).width(300)
  ```

  ![en-us_image_0000001511580836](figures/en-us_image_0000001511580836.png)


## Setting the Input Box Type

The **\<TextInput>** component comes in five types. You can specify its type by setting the **type** parameter to any of the following: **Normal**, **Password**, **Email**, **Number**, and **PhoneNumber**.  


- Normal type (default type)

  ```ts
  TextInput()
    .type(InputType.Normal)
  ```

  ![en-us_image_0000001562820765](figures/en-us_image_0000001562820765.png)

- Password type

  ```ts
  TextInput()
    .type(InputType.Password)
  ```

  ![en-us_image_0000001511580840](figures/en-us_image_0000001511580840.png)


## Setting Styles

- Set the placeholder text displayed when there is no input.
  TextInput({placeholder:'I am placeholder text'})


  ```ts
  TextInput({placeholder:'I am placeholder text'})
  ```

  ![en-us_image_0000001511900400](figures/en-us_image_0000001511900400.png)


- Set the current text input.

  ```ts
  TextInput({placeholder:'I am placeholder text',text:'I am current text input'})
  ```

  ![en-us_image_0000001562820761](figures/en-us_image_0000001562820761.png)

- Use **backgroundColor** to set the background color of the text box.

  ```ts
  TextInput({placeholder:'I am placeholder text',text:'I am current text input'})
    .backgroundColor(Color.Pink)
  ```

  ![en-us_image_0000001511740444](figures/en-us_image_0000001511740444.png)

  More styles can be implemented by leveraging the [universal attributes](../reference/arkui-ts/ts-universal-attributes-size.md).


## Adding Events

You can add the **onChange** event for the text box to obtain its content changes. You can also add the universal events to implement user interactions.



```ts
TextInput()
  .onChange((value: string) => {
    console.info(value);
  })
  .onFocus(() => {
    console.info ('Get Focus');
  })
```


## Example Scenario

In this example, the text box is used to submit forms on the user login or registration page.



```ts
@Entry
@Component
struct TextInputSample {
  build() {
    Column() {
      TextInput({ placeholder: 'input your username' }).margin({ top: 20 })
        .onSubmit((EnterKeyType)=>{
          console.info(EnterKeyType+'Enter key type')
        })
      TextInput({ placeholder: 'input your password' }).type(InputType.Password).margin({ top: 20 })
        .onSubmit((EnterKeyType)=>{
          console.info(EnterKeyType+'Enter key type')
        })
      Button('Sign in').width(150).margin({ top: 20 })
    }.padding(20)
  }
}
```


![TextInputGIF](figures/TextInputGIF.gif)
