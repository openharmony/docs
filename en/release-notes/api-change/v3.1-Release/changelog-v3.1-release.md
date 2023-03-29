# Updates (OpenHarmony 3.1 Beta -> OpenHarmony 3.1 Release)

### Added Validity Verification for Color Values in Color.json

Validity verification is added for color values in the **color.json** file. The verification rules are as follows:

- The hexadecimal color code is used in any of the following formats:
    - #rgb: red(0-f) green(0-f) blue(0-f)
    - #argb: transparency(0-f) red(0-f) green(0-f) blue(0-f)
    - #rrggbb: red(00-ff) green(00-ff) blue(00-ff)
    - #aarrggbb: transparency(00-ff) red(00-ff) green(00-ff) blue(00-ff)
- The dollar sign ($) is used to reference resources defined in the application. The format is as follows:
    - $color:xxx

**Change Impacts**

If the verification rules are not met, an error is reported during compilation.

**Key API/Component Changes**

None

### Restrictions on Declaring Multiple Data Types of State Variables

If a **@State**, **@Provide**, **@Link**, or **@Consume** decorated state variable supports multiple data types, they must be all simple data types or references at one time.

Example:

```ts
@Entry
@Component
struct Index {
  // Incorrect: @State message: string | Resource = 'Hello World'
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(`${ this.message }`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

**Change Impacts**

When the defined state variable type contains both the simple data types and references, an error is reported during compilation.

**Key API/Component Changes**

If the defined state variable type contains both the simple data types and references, change the type to one of them, as shown in the preceding sample code.
