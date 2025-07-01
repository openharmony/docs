# Styled String Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 170001 Conversion Error

**Error Message**

Convert Error.

**Description**

This error code is reported when the **fromHtml** API failed to convert the input string into a corresponding styled string.

**Possible Causes**

The provided string is empty or does not comply with the HTML format.

**Solution**

N/A

<!--Del-->
## 170002 Styled String Decoding Error

**Error Message**

Styled string decode error.

**Description**

This error code is reported when the **unmarshalling** API failed to unmarshal the input byte stream into a valid styled string.

**Possible Causes**

The input byte stream does not conform to the serialization format of the styled string.

**Solution**

N/A
<!--DelEnd-->

## 180101 Invalid Styled String

**Error Message**

Invalid styled string.

**Description**

This error code is reported when the **ArkUI_StyledString_Descriptor** object in the styled string serialization C API is null.

**Possible Causes**

The styled string passed in the parameter is incorrect.

**Solution**

Check that the styled string is correctly passed in the parameter.
