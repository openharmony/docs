# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Behavior of JSON.parse in Invalid String Scenarios Changed

**Access Level**

Public API

**Reason for Change**

When **JSON.parse** is used to parse invalid strings, no JS exception is thrown. This symptom is different from the expectation and ECMA specifications.

**Change Impact**

This change is a non-compatible change.

```
const strData = `{"k1": "hello", "k2": 3}`;
const strErr = strData.substring(0, strData.length - 2); // `{"k1": "hello", "k2": `
JSON.parse(strErr);
```

Before change: **JSON.parse** can properly parse the invalid string **strErr**, and no JS exception is thrown.

After change: A JS exception is thrown when **JSON.parse** is used to parse the invalid string **strErr**.

**Start API Level**

12

**Change Since**

5.0 Beta3

**Key API/Component Changes**

JSON.parse/ASON.parse/util.json.parse

**Adaptation Guide**

When using **JSON.parse**, ensure that the input strings are valid or use **try-catch** to capture exceptions.

## cl.arkcompiler.2 Behavior of JSON.parse in Underflow Floating Point Number or -0 Scenario Changed

**Access Level**

Public API

**Reason for Change**

When the string parsed by **JSON.parse** contains an underflow floating point number or **-0**, the API behavior does not comply with the specifications.

**Change Impact**

This change is a non-compatible change.

Before change:

The statement **JSON.parse('123.456e-789');** returns **-Infinity**, which is an error result.

The statement **1/JSON.parse('-0');** returns **Infinity**, which is an error result.

After change:

The statement **JSON.parse('123.456e-789');** returns **0**, which is the correct result.

The statement **1/JSON.parse('-0');** returns **-Infinity**, which is the correct result.

**Start API Level**

12

**Change Since**

5.0 Beta3

**Key API/Component Changes**

JSON.parse/ASON.parse/util.json.parse

**Adaptation Guide**

Check whether an underflow floating-point number and **-0** is passed in to **JSON.parse**. If so, check whether the code logic can adapt to the correct value.

## cl.arkcompiler.3 Changes in TextEncoder.encodeInto()

**Access Level**

Public API

**Reason for Change**

When **TextEncoder.encodeInto** is used to encode a string, the length of the returned array incorrectly increases by 2 each time the character '\0' is added to the string.

**Change Impact**

This change is a non-compatible change.

```
const arr = encoder.encodeInto('\0ab');
arr.length;
```

Before change: For **arr = [0x00, 0x61, 0x62, 0x00]**, **arr.length** is 4.

After change: For **arr = [0x00, 0x61, 0x62]**, **arr.length** is 3.

**Start API Level**

9

**Change Since**

5.0 Beta3

**Key API/Component Changes**

TextEncoder.encodeInto

**Adaptation Guide**

When encoding a string using **TextEncoder.encodeInto**, pay attention to the length of the returned array.
