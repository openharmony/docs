# Multimedia Subsystem Changelog

## cl.multimedia.1 getValidCommandsSync Changed

**Access Level**

Public

**Reason for Change**

In earlier versions, the return value of **getValidCommandsSync()** is incorrectly defined as int. It is corrected to **AVControlCommandType**.

**Change Impact**

The change is not compatible with earlier versions. You are advised to use new APIs.

**Change Since**

OpenHarmony SDK 4.1.3.5

**Key API/Component Changes**

getValidCommandsSync(): Array<AVControlCommandType>

**Adaptation Guide**

Before change:

When you use a created **AVSession** object to obtain the commands supported by the controller, the return value is an int array.

let validCommands = avsession.getController().getValidCommandsSync();

For example, if the application registers only the **play** command callback, validCommands[0] is 0.

After change:

When you use a created **AVSession** object to obtain the commands supported by the controller, the return value is an array of **AVControlCommandType** strings.

let validCommands = avsession.getController().getValidCommandsSync();

For example, if the application registers only the **play** command callback, validCommands[0] is **'play'**.
