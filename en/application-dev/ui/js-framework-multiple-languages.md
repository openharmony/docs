# Multi-Language Capability

Applications designed based on the JS UI framework apply to different countries and regions. With the multi-language capability, you do not need to develop application versions in different languages, and your users can switch between various locales. This also facilitates project maintenance.


You only need to perform operations in [Defining Resource Files](#defining-resource-files) and [Referencing Resources](#referencing-resources) to use the multi-language capability of this framework. For details about how to obtain the current system language, see [Obtaining the Language](#obtaining-the-language).


## Defining Resource Files

Resource files store application content in multiple languages. This framework uses JSON files to store resource definitions.

Place the resource file of each locale in the i18n directory described in [File Organization](js-framework-file.md). Resource files should be named in _language-script-region_.json format. For example, the resource file for Hong Kong(China) in the traditional script is named zh-Hant-HK. You can omit the region, for example, zh-CN for simplified Chinese, or omit both the script and region, for example, zh for Chinese.  

```
language[-script-region].json
```

The following table describes the requirements for the qualifiers of resource file names.

Table 1 Requirements for qualifier values

| Qualifier Type| Description and Value Range                                 |
| ----- | ---------------------------------------- |
| Language   | Indicates the language used by the device. The value consists of two or three lowercase letters. For example, **zh** indicates Chinese, **en** indicates English, and **mai** indicates Maithili.<br>For details about the value range, refer to **ISO 639** (codes for the representation of names of languages).|
| Script   | Indicates the script type used by the device. The value starts with one uppercase letter followed by three lowercase letters. For example, **Hans** indicates simplified Chinese, and **Hant** indicates traditional Chinese.<br>For details about the value range, refer to **ISO 15924** (codes for the representation of names of scripts).|
| Country/Region| Indicates the country or region where the user is located. The value consists of two or three uppercase letters or three digits. For example, **CN** indicates China, and **GB** indicates the United Kingdom.<br>For details about the value range, refer to **ISO 3166-1** (codes for the representation of names of countries and their subdivisions).|

If there is no resource file of the locale that matches the system language, content in the **en-US.json** file will be used by default.

The format of the resource file content is as follows:

**en-US.json**

```json
{
    "strings": {
        "hello": "Hello world!",
        "object": "Object parameter substitution-{name}",
        "array": "Array type parameter substitution-{0}",
        "symbol": "@#$%^&*()_+-={}[]\\|:;\"'<>,./?"
    },

    "files": {
        "image": "image/en_picture.PNG"
    }
}
```


Different languages have different matching rules for singular and plural forms. In the resource file, **zero**, **one**, **two**, **few**, **many**, and **other** are used to define the string content in different singular and plural forms. For example, there is only the **other** scenario in Chinese since the language does not have singular and plural forms. **one** and **other** scenarios are applicable to English. All six scenarios are needed for Arabic.


The following example takes **en-US.json** and **ar-AE.json** as examples:

**en-US.json**

```json
{
    "strings": {
        "people": {
            "one": "one person",
            "other": "{count} people"
        }
    }
}
```


**ar-AE.json**

```json
{
    "strings": {
        "people": {
            "zero": "لا أحد",
            "one": "وحده",
            "two": "اثنان",
            "few": "ستة اشخاص",
            "many": "خمسون شخص",
            "other": "مائة شخص"
        }
    }
}
```


## Referencing Resources

Multi-language syntax used on application development pages (including simple formatting and singular-plural formatting) can be used in **.hml** or **.js** files.

- Simple formatting
  
Use the **$t** function to reference to resources of different locales. The **$t** function is available for both **.hml** and **.js** files. The system displays content based on a resource file path specified via **$t** and the specified resource file whose locale matches the current system language.
  
Table 2 Simple formatting
  
  | Attribute| Type    | Parameter             | Mandatory| Description                                                  |
  | ---- | -------- | ----------------- | ---- | ------------------------------------------------------ |
| $t   | Function | See Table 3.| Yes  | Sets the parameters based on the system language, for example, **this.$t('strings.hello')**.|
  
Table 3 $t function parameters
  
  | Parameter  | Type         | Mandatory| Description                                                        |
  | ------ | ------------- | ---- | ------------------------------------------------------------ |
  | path   | string        | Yes  | Path of the language resource key.                                                  |
| params | Array\|Object | No  | Content used to replace placeholders during runtime. There are two types of placeholders available:<br>- Named placeholder, for example, **{name}**. The actual content must be of the object type, for example, **$t('strings.object', {name:'Hello world'})**.<br> - Digit placeholder, for example, **{0}**. The actual content must be of the array type, for example, **$t('strings.array', [Hello world']**.|
  
- Example code for simple formatting
  ```html
  <!-- xxx.hml -->
  <div>
    <!-- Display Hello world! without using a placeholder. -->
    <text>{{ $t('strings.hello') }}</text>
    <!-- Replace named placeholder {name} with Hello world and display it. -->
    <text>{{ $t('strings.object', { name: 'Hello world' }) }}</text>
    <!-- Replace digit placeholder {0} with Hello world and display it. -->
    <text>{{ $t('strings.array', ['Hello world']) }}</text>
    <!-- Obtain the resource content from the .js file and display Hello world. -->
    <text>{{ hello }}</text>
    <!-- Obtain the resource content from the .js file, replace named placeholder {name} with Hello world, and display Substitution in an object: Hello world. -->
    <text>{{ replaceObject }}</text>
    <!-- Obtain the resource content from the .js file, replace digit placeholder {0} with Hello world, and display Substitution in an array: Hello world. -->
    <text>{{ replaceArray }}</text>
  
    <!-- Display the image in the specified file path. -->
    <image src="{{ $t('files.image') }}" class="image"></image>
    <!-- Obtain the image file path from the .js file and display the image. -->
    <image src="{{ replaceSrc }}" class="image"></image>
  </div>
  ```

  ```js
  // xxx.js
  // The following example uses the $t function in the .js file.
  export default {
    data: {
      hello: '',
      replaceObject: '',
      replaceArray: '',
      replaceSrc: '',
    },
    onInit() {
      this.hello = this.$t('strings.hello');
      this.replaceObject = this.$t('strings.object', { name: 'Hello world' });
      this.replaceArray = this.$t('strings.array', ['Hello world']);
      this.replaceSrc = this.$t('files.image');
    },   
  }
  ```

- Singular-plural formatting

  Table 4 Singular-plural formatting

  | Attribute| Type    | Parameter              | Mandatory| Description                                                        |
  | ---- | -------- | ------------------ | ---- | ------------------------------------------------------------ |
  | $tc  | Function | See Table 5.| Yes  | Converts between the singular and plural forms based on the system language, for example, **this.$tc('strings.people')**.<br>**NOTE**<br>The resource content is distinguished by the following JSON keys: **zero**, **one**, **two**, **few**, **many**, and **other**.|

  Table 5 $tc function parameters

  | Parameter | Type  | Mandatory| Description        |
  | ----- | ------ | ---- | ------------ |
  | path  | string | Yes  | Path of the language resource key.  |
  | count | number | Yes  | Number.|

- Example code for singular-plural formatting
  ```html
  <!--xxx.hml-->
  <div>
    <!-- When the value 0 is passed, "0 people" matches the Arabic string whose key is zero. -->
    <text>{{ $tc('strings.people', 0) }}</text>
    <!-- When the value 1 is passed, "1 person" matches the Arabic string whose key is one. -->
    <text>{{ $tc('strings.people', 1) }}</text>
    <!-- When the value 2 is passed, "2 people" matches the Arabic string whose key is two. -->
    <text>{{ $tc('strings.people', 2) }}</text>
    <!-- When the value 6 is passed, "6 people" matches the Arabic string whose key is few. -->
    <text>{{ $tc('strings.people', 6) }}</text>
    <!-- When the value 50 is passed, "50 people" matches the Arabic string whose key is many. -->
    <text>{{ $tc('strings.people', 50) }}</text>
    <!-- When the value 100 is passed, "100 people" matches the Arabic string whose key is other. -->
    <text>{{ $tc('strings.people', 100) }}</text>
  </div>
  ```


## Obtaining the Language

For details about how to obtain the language, see [@ohos.app.ability.Configuration (Configuration)](../reference/apis-ability-kit/js-apis-app-ability-configuration.md).
