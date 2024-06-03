# Resource Manager Development


## How do I read an XML file in rawfile and convert the data in it to the string type? (API 9)

**Solution**

Call **getRawFileContent** of the **ResourceManager** module to obtain the data in the XML file, and then use **String.fromCharCode** to convert the data to the string type.

**Example**

```
resourceManager.getRawFileContent('test.xml', (error, value) => {
  if (error != null) {
    console.log("error is " + error);
  } else {
    let rawFile = value;
    let xml = String.fromCharCode.apply(null, rawFile)
  }
});
```

**Reference Link**

[ResourceManager \(Resource Management\)](../reference/apis-localization-kit/js-apis-resource-manager.md)


## How do I obtain resources in the stage model? (API 9)

**Solution**

The stage model allows an application to obtain a **ResourceManager** object based on **context** and call its resource management APIs without first importing the required bundle. This mode does not apply to the FA model.

**Example**

```
const context = getContext(this) as any
context 
  .resourceManager
  .getString($r('app.string.entry_desc').id)
  .then(value => {
    this.message = value.toString()
})
```


## How do I obtain the path of the resource directory by using an API? (API 9)?

**Symptom**

How do I obtain the path of the **resource** directory so that I can manage the files in it by using the file management API?

**Solution**

Because the application is installed in HAP mode and the HAP package is not decompressed after the installation is complete, the resource path cannot be obtained when the program is running.

To obtain the path of the **resource** directory, try either of the following ways:

1. Use **$r** or **$rawfile** for access. This method applies to static access, during which the **resource** directory remains unchanged when the application is running.

2. Use **ResourceManager** for access. This method applies to dynamic access, during which the **resource** directory dynamically changes when the application is running.

**Reference Link**

[Resource Categories and Access](../quick-start/resource-categories-and-access.md) and [ResourceManager \(Resource Management\)](../reference/apis-localization-kit/js-apis-resource-manager.md)


## Why does getPluralString return an incorrect value? (API 9)

**Symptom**

The value obtained by the **getPluralString** is **other**, which is incorrect.

**Solution**

The **getPluralString** API is effective only when the system language is English.


## How do I obtain the customized string fields in the resources directory? (API 9)

**Solution**

Use **getStringValue** of the **ResourceManager** module.

**Reference Link**

[ResourceManager \(Resource Management\)](../reference/apis-localization-kit/js-apis-resource-manager.md#getstringvalue9)


## How do I reference resources such as images and text in AppScope? (API 9)

**Solution**

Resources are referenced in the **$r('app.type.name')** format. Where, **type** indicates the resource type, such as color, string, and media, and **name** indicates the resource name.


## How do I convert resources to strings? (API 9)

**Solution**

If the resource type is set to **string**, the qualifier directory can be set as **this.context.resourceManager.getStringSync($r('app.string.test').id)** and can be converted synchronously. The **$r('app.string.test', 2)** mode is not supported.

**Reference Link**

[ResourceManager \(Resource Management\)](../reference/apis-localization-kit/js-apis-resource-manager.md#getstringsync9)


## Can $ be used to reference constants in the form\_config.json file? (API 9)

In the **form_config.json** file, **$** cannot be used to reference constants.


## How does ArkTS parse XML files? (API 9)

**Solution**

1. Create the following XML file in the **rawfile** directory:

   ```
   <?xml version="1.0" encoding="utf-8"?>
   <user>
       <name>Jacky</name>
       <age>18</age>
   </user>
   ```

2. Use **resourceManager.getRawFileContent** to obtain the byte arrays of the XML file.

   ```
   import resourceManager from '@ohos.resourceManager';
   resourceManager.getRawFileContent("test.xml", (error, value) => {
     if (error != null) {
       console.log("error is " + error);
       return
     }
     let arrayBuffer = value.buffer; // unit8Array
     var xmpParser = new xml.XmlPullParser(arrayBuffer);
     var tagName = ""
     //do something
   }
   ```
