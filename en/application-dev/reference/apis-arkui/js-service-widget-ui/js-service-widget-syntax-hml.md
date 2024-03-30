# HML


HML is an HTML-like language that allows you to build pages based on components and events. HML pages provide advanced capabilities such as data binding, event binding, loop rendering, conditional rendering, and logic control.


## Page Structure


```html
<!-- xxx.hml -->
<div class="item-container">
  <text class="item-title">Image Show</text>
  <div class="item-content">
    <image src="/common/xxx.png" class="image"></image>
  </div>
</div>
```


## Data Binding


```html
<!-- xxx.hml -->
<div class="item-container">
  <text>{{content}}</text>            <!-- Display Hello World!-->
  <text>{{key1}} {{key2}}</text>       <!-- Display Hello World-->
  <text>key1 {{key1}}</text>           <!-- Display key1 Hello-->
  <text>{{flag1 && flag2}}</text>      <!-- Display false-->
  <text>{{flag1 || flag2}}</text>      <!-- Display true-->
  <text>{{!flag1}}</text>              <!-- Display false-->
</div>
```

Declare the variables used in the XML file for service widgets in the **data** field in the JSON file.

```json
{
  "data": {
    "content": "Hello World!",
    "key1": "Hello",
    "key2": "World",
    "flag1": true,
    "flag2": false
  }
}
```

>  **NOTE**
>  - When using data binding, you can use the object operator or array operator on a key to access the bound data, for example, **{{key.value}}** and **{{key[0]}}**.
>
>  - String concatenation, logical operations, and ternary expressions are supported.
>   - String concatenation:
>      - A variable can be followed by another variable, for example, **{{key1}}{{key2}}**.
>      - A variable can also be followed by a constant, for example, **"my name is {{name}}, i am from {{city}}."    "key1 {{key1}}"**.
>   - Logical operations:
>      - AND: {{flag1 && flag2}} (The AND operation can only be performed on two Boolean variables.)
>      - OR: {{flag1 || flag2}} (The OR operation can only be performed on two Boolean variables.)
>      - NOT: {{! flag1}} (The NOT operation can only be performed on a Boolean variable.)
>   - Ternary expressions:
>      - {{flag? key1: key2}} (**flag** is a Boolean variable. **key1** and **key2** can be variables or constants.)
>   - Notes
>      - The default value is **false** when a Boolean-specific operation is performed on a non-Boolean variable.
>      - The preceding variable and operation parsing do not support nesting.

## Event Binding

Declare the events for service widgets in the **actions** field in the JSON file. Service widgets support the common click event only. The event must be declared explicitly. The event definition must contain the **action** field to describe the event type. Service widgets support redirection events (**router**) and message events (**message**). A redirection event is used for switching to the application (the widget provider). A message event can transfer custom information to the widget provider. Event parameters can be variables, which are defined using **{{}}**. If the **params** field is defined in the redirection event, you can pass **params** to the **onStart** method (as **intent**) of the started application to access the value.

- Redirection event properties

  Define the **abilityName** and **params** fields to implement direct redirection to the target application.

  | Selector        | Example    | Default Value     | Description                                    |
  | ----------- | ------ | -------- | ---------------------------------------- |
  | action      | string | "router" | Event type.<br>- **"router"**: redirection event.<br>- **"message"**: message event.|
  | abilityName | string | -        | Name of the ability to redirect to.                             |
  | params      | Object | -        | Additional parameter passed during the redirection.                            |


  ```json
  {
    "data": {
      "mainAbility": "xxx.xxx.xxx"
    },
    "actions": {
      "routerEvent": { 
        "action": "router",
        "abilityName": "{{mainAbility}}",
        "params":{}
      } 
    }
  }
  ```

- Message event properties

  | Selector   | Example    | Default Value    | Description        |
  | ------ | ------ | ------- | ------------ |
  | action | string | message | Event type.     |
  | params | Object | -       | Additional parameter passed during the redirection.|


  ```json
  {
    "actions": {
      "activeEvent": { 
        "action": "message",
        "params": {}           
      } 
    }
  }
  ```

- The following example shows two styles for binding the redirection event and message event:

  ```html
  <!-- xxx.hml --> 
  <div> 
    <!-- Regular format --> 
    <div onclick="activeEvent"></div> 
    <!-- Abbreviation --> 
    <div @click="activeEvent"></div> 
  </div>
  ```


## Loop Rendering


```html
<!-- xxx.hml -->
<div class="array-container">
  <!-- div loop rendering -->
  <!-- By default, $item indicates the element in the array, and $idx indicates the index of the element in the array. -->
  <div for="{{array}}" tid="id">
    <text>{{$item.name}}</text>
  </div>
  <!-- Define the name for an element variable. -->
  <div for="{{value in array}}" tid="id">    
    <text>{{value.name}}</text>
  </div>
  <!-- Define an element variable and its index name. -->
  <div for="{{(index, value) in array}}" tid="id">    
    <text>{{value.name}}</text>
  </div>
</div>
```


```json
{
  "data": {
    "array": [
      {"id": 1, "name": "jack", "age": 18},
      {"id": 2, "name": "tony", "age": 18}
    ]
  }
}
```

The **tid** attribute accelerates the **for** loop and improves the re-rendering efficiency when data in a loop changes. The **tid** attribute specifies the unique ID of each element in the array. If it is not specified, the index of each element in the array is used as the ID. For example, **tid="id"** indicates that the **id** attribute of each element is its unique ID. The **for** loop supports the following statements:

- for="array": **array** is an array object, whose element variable is **$item** by default.

- for="v in array": **v** is a custom element variable, whose index is **$idx** by default.

- for="(i, v) in array": **i** indicates the element index, and **v** indicates the element variable. All elements of the array object will be looped through.

>  **NOTE**
>  - Each element in the array must have the data attribute specified by **tid**. Otherwise, an exception may occur.
>
>  - The attribute specified by **tid** in the array must be unique. Otherwise, performance loss occurs. In the above example, only **id** and **name** can be used as **tid** because they are unique fields.
>
>  - The **tid** field does not support expressions.
>
>  - Nested **for** loops are not supported.
>
>  - When you use the **for** loop, ensure that the objects contained in the array are of the same type.


## Conditional Rendering

There are two ways to implement conditional rendering: **if-elif-else** or **show**.

The **if-elif-else** statements must be used in sibling nodes. Otherwise, the compilation fails. The following example uses both ways to implement conditional rendering:


```html
<!-- xxx.hml -->
<div>
  <text if="{{show}}"> Hello-TV </text>
  <text elif="{{display}}"> Hello-Wearable </text>
  <text else> Hello-World </text>
</div>
```


```json
{
  "data": {
    "show": false,
    "display": true
  }
}
```

If **show** is **true**, the node is rendered properly; if it is **false**, the display style will be **none**.


```html
<!-- xxx.hml -->
<text show="{{visible}}"> Hello World </text>
```


```json
{
  "data": {
    "visible": false
  }
}
```


## Logic Control Block

**\<block>** makes loop rendering and conditional rendering more flexible. A **\<block>** will not be compiled as a real component. The **\<block>** supports the **if** attribute only.


```html
<!-- xxx.hml --> 
<div> 
  <block if="{{show}}"> 
    <text>Hello</text> 
    <text>World</text> 
  </block>
</div>
```


```json
{ 
  "data": { 
    "show": true
  } 
}
```
