# Programming Languages

## What are the restrictions on using generator functions in TypeScript?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Below are the restrictions on using generator functions in TypeScript:

- Expressions can be used only in character strings (in the ${expression} format), **if** conditions, **ForEach** parameters, and component parameters.

- No expressions should cause any application state variables (including **@State**, **@Link**, and **@Prop**) to change. Otherwise, undefined and potentially unstable framework behavior may occur.

- The generator function cannot contain local variables.

None of the above restrictions apply to anonymous function implementations of event handlers (such as **onClick**).

Negative example:

```
build() {
  let a: number = 1 // invalid: variable declaration not allowed
  Column() {
    Text('Hello ${this.myName.toUpperCase()}') // ok.
    ForEach(this.arr.reverse(), ..., ...) // invalid: Array.reverse modifies the @State array variable in place
  }
  buildSpecial()  // invalid: no function calls
  Text(this.calcTextValue()) // this function call is ok.
}
```

## How do I dynamically replace the %s placeholder in a resource file?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

In an application, you can replace the %s placeholder by using the second parameter in **$r('app.string.xx')**, which is used to reference application resources.

Example:

```
build() {
  //do something
  // The second parameter indicates the referenced string resource, which can be used to replace the %s placeholder.
  Text($r('app.string.entry_desc','aaa')) 
    .fontSize(100)
    .fontColor(Color.Black)
  //do something
}
```

## How do I read an XML file in Resource and convert data in it to the string type?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

1. Obtain Uint8Array data by calling the **RawFile** API of **resourceManager**.

2. Convert the Uint8Array data to strings by calling the **String.fromCharCode** API.

Reference: [Resource Manager](../reference/apis/js-apis-resource-manager.md)

Example:


```
resourceManager.getRawFile(path, (error, value) => {
  if (error != null) {
    console.log("error is " + error);
  } else {
    let rawFile = value;
    let xml = String.fromCharCode.apply(null, rawFile)
  }
});
```

## How do I convert a Resource object to the string type?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Use the **resourceManager.getString()** API of the **@ohos.resourceManager** module.

Reference: [Resource Manager](../reference/apis/js-apis-resource-manager.md#getstring)

## What should I do if the global static variables of a class do not work?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Objects imported to abilities and pages are packaged into two different closures, that is, two global objects. In this case, a static variable referenced by the abilities is not the same object as that referenced by the pages. Therefore, global variables cannot be defined by defining static variables in the class. You are advised to use AppStorage to manage global variables.

Reference: [State Management with Application-level Variables](../quick-start/arkts-state-mgmt-application-level.md)

## How do I obtain resources in the stage model?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

The stage model allows an application to obtain a **ResourceManager** object based on **context** and call its resource management APIs without first importing the required bundle. This method, however, is not applicable to the FA model.

Example:


```
const context = getContext(this) as any
context 
  .resourceManager
  .getString($r('app.string.entry_desc').id)
  .then(value => {
    this.message = value.toString()
})
```

## How do I obtain data through an API before page loading?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

In the **aboutToAppear** function, use an asynchronous API to obtain page data and **@State** to decorate related variables. After the data is obtained, the page is automatically refreshed based on the variables.


```
@Entry
@Component
struct Test6Page {
  // After the data is obtained, the page is automatically refreshed.
  @State message: string = 'loading.....'
  aboutToAppear(){
    // Simulate an asynchronous API to obtain data.
    setTimeout(()=>{
      this.message = 'new msg'
    },3000)
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Do the worker thread and the main thread run in the same global context?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

No. The worker thread and the main thread are not in the same global context. They interact with each other in data communication mode.

## Which API is used for URL encoding in OpenHarmony?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

The global function **encodeURI** is used for URI encoding, and **decodeURI** is used for URI decoding. For example, a space character is encoded as %20.

## Does OpenHarmony provide any API for parsing XML files?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Yes. The **convert** API of the **convertxml** module can be used to convert XML text into JavaScript objects. Reference: [@ohos.convertxml](../reference/apis/js-apis-convertxml.md)

## How do I configure application icons to be used across devices?

Applicable to: OpenHarmony SDK 3.0, stage model of API version 9

Use resource qualifiers to configure application icons to be used across devices.

## Can placeholders be configured in the string.json file of the stage model?

Applicable to: OpenHarmony SDK 3.2.6.3, stage model of API version 9

The **string.json** file does not support placeholders. As an alternative, you can define variables on the target page and combine these variables and **Resource** objects.

## Is there any difference between the OpenHarmony API systemTime.getCurrentTime() and the JS API new Date().getTime() API?

Applicable to: OpenHarmony SDK 3.2.6.3, stage model of API version 9

Similar to **new Date().getTime()**, **systemTime.getCurrentTime(false)** returns the number of milliseconds that have elapsed since the Unix epoch. **systemTime.getCurrentTime(true)** returns the number of nanoseconds that have elapsed since the Unix epoch. The system time is used in both APIs.

## How do I define @BuilderParam decorated attributes based on the value assigned to them?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

If no parameter is passed when assigning a value to the **@BuilderParam** decorated attribute (for example, **content: this.specificParam**), define the type of the attribute as a function without a return value (for example, **@BuilderParam content: () =&gt; voi**). If any parameter is passed when assigning a value to the **@BuilderParam** decorated attribute (for example, **callContent: this.specificParam1("111")**), define the type of the attribute as **any** (for example, **@BuilderParam callContent: any**). For details, see [BuilderParam](../quick-start/arkts-dynamic-ui-elememt-building.md#builderparam8).

## How does ArkTS convert a string into a byte array?

Applicable to: all versions

Refer to the following code:


```
function stringToByte(str) {
  var bytes = new Array();
  var len,c;
  len = str.length;
  for(var i = 0;i<len;i++) {
    c = str.charCodeAt(i);
    if( c >= 0x010000 && c<= 0x10FFFF) {
      bytes.push(((c>>18) & 0x07) | 0xf0);
      bytes.push(((c>>12) & 0x3F) | 0x80);
      bytes.push(((c>>6) & 0x3f) | 0x80);
      bytes.push((c & 0x3F) | 0x80);
    } else if(c >= 0x000800 && c<= 0x00FFF){
      bytes.push(((c>>12) & 0x07) | 0xf0);
      bytes.push(((c>>6) & 0x3F) | 0x80);
      bytes.push((c & 0x3F) | 0x80);
    } else if(c >= 0x000800 && c<= 0x0007FF) {
      bytes.push(((c>>6) & 0x3F) | 0x80);
      bytes.push((c & 0x3F) | 0x80);
    } else {
      bytes.push(c & 0xFF)
    }
  }
  return bytes;
}
```

## What do I do if the "Too many wokers, the number of worker exceeds the maximum" message is displayed during worker creation?

Applicable to: OpenHarmony SDK 3.2.6.5

An application allows for a maximum of seven workers. Therefore, use the **termiate** API to release workers when they are not needed.

Reference: [@ohos.worker](../reference/apis/js-apis-worker.md#terminate)

## What is the recommended multithreading solution on OpenHarmony?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

OpenHarmony recommends that worker threads be used for multithreading.

Reference: [@ohos.worker](../reference/apis/js-apis-worker.md)

## What is the difference between a @Builder decorated method and other methods?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

If the **@Builder** decorated method uses a custom component, this component is re-created each time the method is called.

## Why is the callback registered through @Watch not triggered when the object attributes of an array change?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

As with **@State**, the callback registered through **@Watch** can be used to listen for only one layer of data changes. If the object attributes of the array changes at the inner layer, the callback will not be triggered.

## How do I listen for in-depth changes of @State decorated variables?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

To listen for in-depth changes of **@State** decorated variables, you can use **@Observed** and **@ObjectLink** decorators.

Reference: [@Observed and @ObjectLink](../quick-start/arkts-state-mgmt-page-level.md#observed-and-objectlink)

## How do I implement character string encoding and decoding?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

You can use **TextEncoder** and **TextDecoder** provided by the **util** module.

Reference: [TextEncoder](../reference/apis/js-apis-util.md#textencoder) and [TextDecoder](../reference/apis/js-apis-util.md#textdecoder)

## How do i import and export namespaces?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

- Exporting namespaces

  ```
  namespace Util{
      export function getTime(){
          return Date.now()
      }
  }
  export default Util
  ```

- Importing namespaces

  ```
  import Util from './util'
  Util.getTime()
  ```

## Can relational database operations be performed in the worker thread?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

No. Relational database operations cannot be performed in the worker thread.

<!--no_check-->  