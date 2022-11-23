# Configuration Policy

The **configPolicy** module provides APIs for obtaining the custom configuration directory and file path based on the predefined custom configuration level.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  The APIs provided by this module are system APIs.

## Modules to Import

```js
import configPolicy from '@ohos.configPolicy';
```

## getOneCfgFile

getOneCfgFile(relPath: string, callback: AsyncCallback&lt;string&gt;)

Obtains the path of a configuration file with the specified name and highest priority. This API uses an asynchronous callback to return the result.
For example, if the **config.xml** file is stored in **/system/etc/config.xml** and **/sys_pod/etc/config.xml** (in ascending order of priority), then **/sys_pod/etc/config.xml** is returned.

**System capability**: SystemCapability.Customization.ConfigPolicy

**Parameters**
| Name     | Type                         | Mandatory  | Description                   |
| -------- | --------------------------- | ---- | --------------------- |
| relPath  | string                      | Yes   | Name of the configuration file.                |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the path of the configuration file.|

**Example**
  ```js
  configPolicy.getOneCfgFile('etc/config.xml', (error, value) => {
      if (error == null) {
          console.log("value is " + value);
      } else {
          console.log("error occurs "+ error);
      }
  });
  ```


## getOneCfgFile

getOneCfgFile(relPath: string): Promise&lt;string&gt;

Obtains the path of a configuration file with the specified name and highest priority. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.ConfigPolicy

**Parameters**
| Name    | Type    | Mandatory  | Description   |
| ------- | ------ | ---- | ----- |
| relPath | string | Yes   | Name of the configuration file.|

**Return value**
| Type                   | Description          |
| --------------------- | ------------ |
| Promise&lt;string&gt; | Promise used to return the path of the configuration file.|

**Example**
  ```js
  configPolicy.getOneCfgFile('etc/config.xml').then(value => {
      console.log("value is " + value);
  }).catch(error => {
      console.log("getOneCfgFile promise " + error);
  });
  ```


## getCfgFiles

getCfgFiles(relPath: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;)

Obtains a list of configuration files with the specified name, sorted in ascending order of priority. This API uses an asynchronous callback to return the result.
For example, if the **config.xml** file is stored in **/system/etc/config.xml** and **/sys_pod/etc/config.xml** (in ascending order of priority), then **/system/etc/config.xml, /sys_pod/etc/config.xml** is returned.

**System capability**: SystemCapability.Customization.ConfigPolicy

**Parameters**
| Name     | Type                                      | Mandatory  | Description           |
| -------- | ---------------------------------------- | ---- | ------------- |
| relPath  | string                                   | Yes   | Name of the configuration file.        |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the file list.|

**Example**
  ```js
  configPolicy.getCfgFiles('etc/config.xml', (error, value) => {
      if (error == null) {
          console.log("value is " + value);
      } else {
          console.log("error occurs "+ error);
      }
  });
  ```


## getCfgFiles

getCfgFiles(relPath: string): Promise&lt;Array&lt;string&gt;&gt;

Obtains a list of configuration files with the specified name, sorted in ascending order of priority. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.ConfigPolicy

**Parameters**
| Name    | Type    | Mandatory  | Description   |
| ------- | ------ | ---- | ----- |
| relPath | string | Yes   | Name of the configuration file.|

**Return value**
| Type                                | Description  |
| ---------------------------------- | ---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the file list.|

**Example**
  ```js
  configPolicy.getCfgFiles('etc/config.xml').then(value => {
      console.log("value is " + value);
  }).catch(error => {
      console.log("getCfgFiles promise " + error);
  });
  ```


## getCfgDirList

getCfgDirList(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;)

Obtains the list of configuration level directories. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.ConfigPolicy

**Parameters**
| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the configuration level directory list.|

**Example**
  ```js
  configPolicy.getCfgDirList((error, value) => {
      if (error == null) {
          console.log("value is " + value);
      } else {
          console.log("error occurs "+ error);
      }
  });
  ```


## getCfgDirList

getCfgDirList(): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of configuration level directories. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.ConfigPolicy

**Return value**
| Type                                | Description      |
| ---------------------------------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the configuration level directory list.|

**Example**
  ```js
  configPolicy.getCfgDirList().then(value => {
      console.log("value is " + value);
  }).catch(error => {
      console.log("getCfgDirList promise " + error);
  });
  ```
