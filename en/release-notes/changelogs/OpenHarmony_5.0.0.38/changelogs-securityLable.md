# File Subsystem Changelog

## cl.CoreFileKit.1 setSecurityLabel() Behavior Change

**Access Level**

Public API

**Reason for Change**

The **setSecurityLabel()** method does not verify the security label passed in. Changing the security label from a higher level to a lower one poses security risks.

**Change Impact**

This change is a non-compatible change.

Before the change: 

The application data security label can be changed to a lower level by using the following API after being set.

After the change: 

If the application data security label is set to a lower lever, error 13900020 will be thrown.

```ts
import {fileIo,securityLabel} from '@kit.CoreFileKit';
try {
     let path = getContext().filesDir + '/text.txt';
     let file = fileIo.openSync(path,fileIo.OpenMode.CREATE);
     securityLabel.setSecurityLabelSync(file.path, "s4");
     securityLabel.setSecurityLabelSync(file.path, "s3");
     console.log( "set security label s3 success");
} catch (err) {
    console.log( "set security label s3  fail, " + err.message + err.code);
}
```

**Start API Level**

API 9

**Change Since**

OpenHarmony SDK 5.0.0.38

**Key API/Component Changes**

| API| Before the Change| After the Change|
| ------------------------------------------------------------ | --------- | ------ |
| setSecurityLabel(path:string, type:DataLevel):Promise&lt;void&gt; | The data security label can be changed from a higher level to a lower one.| An error will be thrown if the data security label is changed from a higher level to a lower one.|
| setSecurityLabel(path:string, type:DataLevel, callback: AsyncCallback&lt;void&gt;):void          | The data security label can be changed from a higher level to a lower one.| An error will be thrown if the data security label is changed from a higher level to a lower one.|
| setSecurityLabelSync(path:string, type:DataLevel):void       | The data security label can be changed from a higher level to a lower one.| An error will be thrown if the data security label is changed from a higher level to a lower one.|

**Adaptation Guide**

If your application does not need to set the data security label frequently, no adaptation is required. Otherwise, ensure that the data security label settings comply with security specifications. An error will be thrown if the API is used to set the security label from a higher level to a lower one.

## cl.CoreFileKit.2 getSecurityLabel() Behavior Change

**Access Level**

Public API

**Reason for Change**

If no security label has been set for application data, calling **getSecurityLabel** returns an empty string, which does not comply with the security design. After the change, **s3** is returned.

**Change Impact**

This change is a non-compatible change.

Before the change: 

If **getSecurityLabel()** is called for the data without any security label, an empty string is returned by default. After the following code is executed, **label** in the log is an empty string.

After the change: 

If **getSecurityLabel()** is called for the data without any security label, **s3** will be returned by default. After the following code is executed, **label** in the log is **s3**.

```ts
import {fileIo,securityLabel} from '@kit.CoreFileKit';
try {
     let path = getContext().filesDir + '/text.txt';
     let file = fileIo.openSync(path,fileIo.OpenMode.CREATE);
     let label = securityLabel.getSecurityLabelSync(file.path);
     console.log( "get security label success, label is" + label);
} catch (err) {
    console.log( "get security label fail, " + err.message + err.code);
}
```

**Start API Level**

API 9

**Change Since**

OpenHarmony SDK 5.0.0.38

**Key API/Component Changes**

| API| Before the Change| After the Change|
| ------------------------------------------------------------ | --------- | ------ |
| getSecurityLabel(path:string, callback:AsyncCallback&lt;string&gt;): void | By default, an empty string is returned.| **s3** is returned by default.|
| getSecurityLabel(path:string):Promise&lt;string&gt; | By default, an empty string is returned.| **s3** is returned by default.|
| getSecurityLabelSync(path:string):string | By default, an empty string is returned.| **s3** is returned by default.|

**Adaptation Guide**

This change is a bugfix and no adaptation is required for the application. When **getSecurityLabel()** is used to obtain the data security label, **s3** is returned if no security label has been set.
