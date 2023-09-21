# ArkUI Subsystem Changelog

## cl.arkui.1 undefined and null Value Support for State Variables

**Change Impact**

API version 9: State variables do not accept **undefined** or **null** as values. If a state variable is set to **undefined** or **null**, it will remain at its original value.

API version 10: State variables accept **undefined** and **null** as values. You need to check whether a state variable is **undefined**.

**Adaptation Guide**

Since API version 10, you need to take measures to check whether a state variable is **undefined**.
```ts
@Entry
@Component
struct Page3 {
  @State messages: string[] = ['Hello World']

  aboutToAppear() {
    // If AppStorage does not contain the specified key, undefined is returned.
    // API version 9: The ArkUI framework rejects undefined as the assigned value, and this.messages is still at its initial value ['Hello World'].
    // API version 10: The ArkUI framework accepts undefined as the assigned value, and this.messages is undefined.
    this.messages = AppStorage.Get("aProp")
  }

  build() {
    Row() {
      Column() {
        // API version 9: The application does not crash, and the value of length is 1.
        // API version 10: The application crashes, and the following error message is displayed: Cannot read property length of undefined.
        Text(`the messages length: ${this.messages.length}`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

In the preceding scenario, each time **undefined** or **null** is assigned to a state variable, a check for **undefined** state variables is required.

```ts
Text(`the messages length: ${this.messages?.length}`)
```

In API version 10, the ArkUI framework verifies the initialization and value types of state variables, and reports errors found during running. Specifically, there are the following two cases:
1. @Link initialization from the parent component

   In the following example, a runtime error is reported, prompting you to initialize @Link.
   ```ts
   @Entry
   @Component
   struct Page3 {
     @State aProp: boolean = true

     build() {
       Row() {
         Column() {
           // crash: SynchedPropertyObjectTwoWayPU[9, 'linkProp']: constructor @Link/@Consume source variable in
           // parent/ancestor @Component must be defined. Application error!
           LinkChild()
           // Incorrect: linkProp is initialized from a regular variable. In this case, the ArkUI framework considers linkProp as not initialized and reports an error.
           LinkChild({ aProp: false })
           // Correct: @Link is initialized from the state variable this.aProp.
           LinkChild({ aProp: this.aProp })
         }
         .width('100%')
       }
       .height('100%')
     }
   }

   @Component
   struct LinkChild {
     @Link aProp: boolean

     build() {
       Text(`linkProp: ${this.aProp}`)
         .fontSize(50)
         .fontWeight(FontWeight.Bold)
     }
   }
   ```

2. Value type support of state variables

   If a state variable is assigned a value in an unsupported type, for example, function, a runtime error is reported.
   ```ts
   @Entry
   @Component
   struct Page3 {
     // API version 10: A runtime error is reported: @Component 'Page3': Illegal variable value error with decorated variable @State/@Provide 'functionProp': failed
     // validation: 'undefined, null, number, boolean, string, or Object but not function, attempt to assign value type: 'function', 
     @State functionProp: () => void = () => {
       console.info("123")
     }

     aboutToAppear() {
       this.functionProp()
     }

     build() {
       Row() {
         Column() {
           Text("hello")
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

## cl.arkui.2 Adaptation to Component Exceptions After Updating to SDK 4.0.10.x
After the SDK is updated to 4.0.10.x, the UI components cannot be properly displayed if the device is not using the matching image version.

**Example**

```
@Entry
@Component
struct Index { // Custom component
  build() {
    Text('Hello, world') // Basic component
  }
}
```

**Change Impact**

If the device where your application runs is not using the matching image version, calling a UI component in the application code will cause the error message "this.observeComponentCreation2 is not callable".

**Key API/Component Changes**

N/A

**Adaptation Guide**

Use the matching image on the device.
