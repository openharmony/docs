# Multi-Language Capability

Applications designed based on the development framework apply to different countries and regions. With the multi-language capability, you do not need to develop application versions in different languages, and your users can switch between various locales. This also facilitates project maintenance.

You only need to perform operations in [Defining Resource Files](#defining-resource-files) and [Referencing Resources](#referencing-resources) to use the multi-language capability of this framework. For details about how to obtain the current system language, see [Obtaining the Language](#obtaining-the-language).

## Defining Resource Files

Resource files store application content in multiple languages. This framework uses JSON files to store resource definitions.

Place the resource definition file of each locale in the **i18n** folder specified in [Directory Structure](js-lite-framework-file.md). Name the resource files in _language-region_.json format. For example, name the resource file for English (United States) **en-US.json**. If there is no resource file of the locale that matches the system language, content in the **en-US.json** file will be used by default.

The format of the resource file content is as follows:

en-US.json

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

## Referencing Resources

- Use the **$t** function to reference to resources of different locales. The **$t** function is available for both **.hml** and **.js** files. The system displays content based on a resource file path specified via **$t** and the specified resource file whose locale matches the current system language.

  | Parameter  | Type         | Mandatory| Description                                                        |
  | ------ | ------------- | ---- | ------------------------------------------------------------ |
  | path   | string        | Yes  | Resource path.                                                    |
  | params | Array\|Object | No  | Content used to replace placeholders during runtime. There are two types of placeholders available:<br>- Named placeholder, for example, {name}. The actual content must be of the object type, for example, **$t('strings.object', { name: 'Hello world' })**.<br>- Digit placeholder, for example, **{0}**. The actual content must be of the array type, for example, **$t('strings.array', ['Hello world']**. |

- Example

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

  ```javascript
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

  

## Obtaining the Language

For details about how to obtain the language, see [Application Configuration](../js-apis-system-configuration.md).
