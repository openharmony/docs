# Multi-Language Capability 


Applications designed based on the development framework apply to different countries and regions. With the multi-language capability, you do not need to develop application versions in different languages, and your users can switch between various locales. This also facilitates project maintenance.


You only need to perform operations in [Defining Resource Files](#defining-resource-files) and [Referencing Resources](#referencing-resources) to use the multi-language capability of this framework. 


## Defining Resource Files

Resource files store application content in multiple languages. This framework uses JSON files to store resource definitions.

Place the resource file of each locale in the **i18n** directory described in [File Organization](js-service-widget-file.md). Resource files are named in *language-region***.json** format. For example, the resource file for English (United States) is named **en-US.json**. If there is no resource file of the locale that matches the system language, content in the **en-US.json** file will be used by default.

Different languages have different matching rules for singular and plural forms. In the resource file, **zero**, **one**, **two**, **few**, **many**, and **other** are used to define the string content in different singular and plural forms. For example, there is only the **other** scenario in Chinese since the language does not have singular and plural forms. **One** and **other** scenarios are applicable to English. All the preceding six scenarios are needed for Arabic.

 The following example takes **en-US.json** and **ar-AE.json** as examples:

```json
{
    "strings": {
        "hello": "Hello world!",
        "symbol": "@#$%^&*()_+-={}[]\\|:;\"'<>,./?",
        "plurals": {
            "one": "one person",
            "other": "other people"
        }
    },

    "files": {
        "image": "image/en_picture.PNG"
    }
}
```


```json
{
    "strings": {
        "plurals": {
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

    **Table 1** Simple formatting

  | Name  | Type      | Parameter      | Mandatory  | Description                                    |
  | ---- | -------- | -------- | ---- | -------------------------------------- |
  | $t   | Function | Described in **$t parameters**| Yes   | Sets the parameters based on the system language, for example, **this.$t('strings.hello')**.|

    **Table 2** $t parameters

  | Name  | Type    | Mandatory  | Description  |
  | ---- | ------ | ---- | ---- |
  | path | string | Yes   | Resource path.|

- Example code for simple formatting

  ```html
  <!-- xxx.hml -->
   <div> 
     <text>{{ $t('strings.hello') }}</text>  
     <image src="{{ $t('files.image') }}" class="image"></image> 
   </div>
  ```

- Singular-Plural Conversion

  **Table 3** Singular-plural conversion

  | Name  | Type      | Parameter       | Mandatory  | Description                                      |
  | ---- | -------- | --------- | ---- | ---------------------------------------- |
  | $tc  | Function | Described in **$tc parameters**| Yes   | Converts between the singular and plural forms based on the system language, for example, **this.$tc('strings.plurals')**.<br>The resource content is distinguished by the following JSON keys: **zero**, **one**, **two**, **few**, **many**, and **other**.|

  **Table 4** $tc parameters

  | Parameter   | Type    | Mandatory  | Description   |
  | ----- | ------ | ---- | ----- |
  | path  | string | Yes   | Resource path. |
  | count | number | Yes   | Number|

- Example code for converting between the singular and plural forms

  ```html
  <!--xxx.hml-->
  <div>
      <!-- When the value 0 is passed, "0 people" matches the Arabic string whose key is zero. -->
    <text>{{ $tc('strings.plurals', 0) }}</text>
      <!-- When the value 1 is passed, "1 person" matches the Arabic string whose key is one. -->
    <text>{{ $tc('strings.plurals', 1) }}</text>
      <!-- When the value 2 is passed, "2 people" matches the Arabic string whose key is two. -->
    <text>{{ $tc('strings.plurals', 2) }}</text>
      <!-- When the value 6 is passed, "6 people" matches the Arabic string whose key is few. -->
    <text>{{ $tc('strings.plurals', 6) }}</text>
      <!-- When the value 50 is passed, "50 people" matches the Arabic string whose key is many. -->
    <text>{{ $tc('strings.plurals', 50) }}</text>
      <!-- When the value 100 is passed, "100 people" matches the Arabic string whose key is other. -->
    <text>{{ $tc('strings.plurals', 100) }}</text>
  </div>
  ```
