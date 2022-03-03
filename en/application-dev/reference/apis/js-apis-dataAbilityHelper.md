# DataAbilityHelper Module (JavaScript SDK APIs)

## Modules to Import

```
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
import ohos_data_rdb from '@ohos.data.rdb'
```

## DataAbilityHelper

### openFile

openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void

Opens a file with a specified URI. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------- | ---- | ---------------------------------- |
| uri      | string                 | Yes| URI of the file to open.|
| mode     | string                 | Yes| Mode for opening the file. The value can be **rwt**.|
| callback | AsyncCallback\<number> | Yes| Callback used to return the file descriptor.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var mode = "rwt";
DAHelper.openFile(
    "dataability:///com.example.DataAbility",
    mode,
    (err) => {
		console.info("==========================>Called=======================>");
});
```

### openFile

openFile(uri: string, mode: string): Promise\<number>

Opens a file with a specified URI. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes| URI of the file to open.|
| mode | string | Yes| Mode for opening the file. The value can be **rwt**.|

**Return value**
| Type| Description|
| ---------------- | ---------------- |
| Promise\<number> | Promise used to return the file descriptor.|

**Example**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var mode = "rwt";
DAHelper.openFile(
    "dataability:///com.example.DataAbility",
    mode).then((data) => {
		console.info("==========================>openFileCallback=======================>");
});
```

### on('dataChange')

on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void

Registers an observer to observe data specified by a given URI. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes| Type of the event to observe. The value is **dataChange**.|
| uri      | string               | Yes| URI of the data.|
| callback | AsyncCallback\<void> | Yes| Callback invoked when the data is changed.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var helper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
function onChangeNotify() {
    console.info("==========================>onChangeNotify=======================>");
};
helper.on(
    "dataChange",
    "dataability:///com.example.DataAbility",
    onChangeNotify
)
```

### off('dataChange')

off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>): void

Unregisters the observer used to observe data specified by a given URI. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes| Type of the event to observe. The value is **dataChange**.|
| uri      | string               | Yes| URI of the data.|
| callback | AsyncCallback\<void> | No| Callback used to return the result.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var helper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
function onChangeNotify() {
    console.info("==========================>onChangeNotify=======================>");
};
helper.off(
    "dataChange",
    "dataability:///com.example.DataAbility",
)
helper.off(
    "dataChange",
    "dataability:///com.example.DataAbility",
    onChangeNotify
)
```

### getType

getType(uri: string, callback: AsyncCallback\<string>): void

Obtains the MIME type of the data specified by a given URI. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------- | ---- | --------------------------------------------- |
| uri      | string                 | Yes| URI of the data.|
| callback | AsyncCallback\<string> | Yes| Callback used to return the MIME type.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getType(
    "dataability:///com.example.DataAbility",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

### getType

getType(uri: string): Promise\<string>

Obtains the MIME type of the data specified by a given URI. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes| URI of the data.|

**Return value**
| Type| Description|
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the MIME type.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getType(
    "dataability:///com.example.DataAbility"
	).then((data) => {
		console.info("==========================>getTypeCallback=======================>");
});
```

### getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array\<string>>): void

Obtains the supported MIME types of a specified file. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------------- | ------------------------------ | ---- | ---------------------------------- |
| uri            | string                         | Yes| URI of the file.|
| mimeTypeFilter | string                         | Yes| MIME type of the file.|
| callback       | AsyncCallback\<Array\<string>> | Yes| Callback used to return the supported MIME types.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getFileTypes(
    "dataability:///com.example.DataAbility",
    "image/*",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```



### getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string): Promise\<Array\<string>>

Obtains the supported MIME types of a specified file. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------------- | ------ | ---- | ---------------------------- |
| uri            | string | Yes| URI of the file.|
| mimeTypeFilter | string | Yes| MIME type of the file.|

**Return value**
| Type| Description|
| ------------------------ | ------------------------ |
| Promise\<Array\<string>> | Promise used to return the supported MIME types.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getFileTypes(
    "dataability:///com.example.DataAbility",
    "image/*"
	).then((data) => {
		console.info("==========================>getFileTypesCallback=======================>");
});
```

### normalizeUri

normalizeUri(uri: string, callback: AsyncCallback\<string>): void

Converts the URI that refers to a Data ability into a normalized URI. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                 | Yes| URI object to normalize.|
| callback | AsyncCallback\<string> | Yes| Callback used to return the normalized URI object if the Data ability supports URI normalization. If the Data ability does not support URI normalization, **null** is returned.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.normalizeUri(
    "dataability:///com.example.DataAbility",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

### normalizeUri

normalizeUri(uri: string): Promise\<string>

Converts the URI that refers to a Data ability into a normalized URI. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ------ | ---- | ----------------------- |
| uri  | string | Yes| URI object to normalize.|

**Return value**
| Type| Description|
| ---------------- | ------------------------------------------------------ |
| Promise\<string> | Promise used to return the normalized URI object if the Data ability supports URI normalization. If the Data ability does not support URI normalization, **null** is returned.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.normalizeUri(
    "dataability:///com.example.DataAbility",
	).then((data) => {
		console.info("==========================>normalizeUriCallback=======================>");
});
```

### denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback\<string>): void

Converts a normalized URI generated by **DataAbilityHelper.normalizeUri(uri: string, callback: AsyncCallback\<string>)** to a denormalized one. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | Yes| URI object to normalize.|
| callback | AsyncCallback\<string> | Yes| Callback used to return the denormalized URI object.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.denormalizeUri(
    "dataability:///com.example.DataAbility",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```



### denormalizeUri

denormalizeUri(uri: string): Promise\<string>

Converts a normalized URI generated by **DataAbilityHelper.normalizeUri(uri: string)** to a denormalized one. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ------ | ---- | ----------------------- |
| uri  | string | Yes| URI object to normalize.|

**Return value**
| Type| Description|
| ---------------- | ----------------------------------------- |
| Promise\<string> | Promise used to return the denormalized URI object.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.denormalizeUri(
    "dataability:///com.example.DataAbility",
	).then((data) => {
		console.info("==========================>denormalizeUriCallback=======================>");
});
```

### notifyChange

notifyChange(uri: string, callback: AsyncCallback\<void>): void

Notifies the registered observer of a change to the data specified by the URI. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | Yes| URI of the data.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var helper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
helper.notifyChange(
    "dataability:///com.example.DataAbility",
    (err) => {
		console.info("==========================>Called=======================>");
});
```

### notifyChange

notifyChange(uri: string): Promise\<void>

Notifies the registered observer of a change to the data specified by the URI. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes| URI of the data.|

**Return value**
| Type| Description|
| -------------- | --------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.notifyChange(
    "dataability:///com.example.DataAbility",
	).then(() => {
		console.info("==========================>notifyChangeCallback=======================>");
});
```

### insert

insert(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void

Inserts a single data record into the database. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ---------------------- | ---- | ------------------------------------------------------ |
| uri          | string                 | Yes| URI of the data to insert.|
| valuesBucket | rdb.ValuesBucket       | Yes| Data record to insert. If this parameter is **null**, a blank row will be inserted.|
| callback     | AsyncCallback\<number> | Yes| Callback used to return the index of the inserted data record.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
    "blobType": u8,
}
DAHelper.insert(
    "dataability:///com.example.DataAbility",
    valueBucket,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

### insert

insert(uri: string, valuesBucket: rdb.ValuesBucket): Promise\<number>

Inserts a single data record into the database. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ---------------- | ---- | ------------------------------------------------------ |
| uri          | string           | Yes| URI of the data to insert.|
| valuesBucket | rdb.ValuesBucket | Yes| Data record to insert. If this parameter is **null**, a blank row will be inserted.|

**Return value**
| Type| Description|
| ---------------- | ------------------------ |
| Promise\<number> | Promise used to return the index of the inserted data record.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const valueBucket = {
    "name": "rose1",
    "age": 221,
    "salary": 20.5,
    "blobType": u8,
}
DAHelper.insert(
    "dataability:///com.example.DataAbility",
    valueBucket
	).then((data) => {
		console.info("==========================>insertCallback=======================>");
});
```

### batchInsert

batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void

Inserts multiple data records into the database. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ----------------------- | ---- | -------------------------------- |
| uri          | string                  | Yes| URI of the data to insert.|
| valuesBucket | Array<rdb.ValuesBucket> | Yes| Data records to insert.|
| callback     | AsyncCallback\<number>  | Yes| Callback used to return the number of inserted data records.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": u8,})
DAHelper.batchInsert(
    "dataability:///com.example.DataAbility",
    cars,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

### batchInsert

batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>): Promise\<number>

Inserts multiple data records into the database. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ----------------------- | ---- | ------------------------ |
| uri          | string                  | Yes| URI of the data to insert.|
| valuesBucket | Array<rdb.ValuesBucket> | Yes| Data record to insert.|

**Return value**
| Type| Description|
| ---------------- | ---------------------- |
| Promise\<number> | Promise used to return the number of inserted data records.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": u8,})
DAHelper.batchInsert(
    "dataability:///com.example.DataAbility",
    cars
	).then((data) => {
		console.info("==========================>batchInsertCallback=======================>");
});
```

### delete

delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

Deletes one or more data records from the database. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes| URI of the data to delete.|
| valuesBucket | dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback     | AsyncCallback\<number>            | Yes| Callback used to return the number of deleted data records.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.delete(
    "dataability:///com.example.DataAbility",
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

### delete

delete(uri: string, predicates: dataAbility.DataAbilityPredicates): Promise\<number>

Deletes one or more data records from the database. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes| URI of the data to delete.|
| valuesBucket | dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|

**Return value**
| Type| Description|
| ---------------- | ------------------------ |
| Promise\<number> | Promise used to return the number of deleted data records.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.delete(
    "dataability:///com.example.DataAbility",
    da
	).then((data) => {
		console.info("==========================>deleteCallback=======================>");
});
```

### update

update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

Updates data records in the database. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes| URI of the data to update.|
| valuesBucket | rdb.ValuesBucket                  | Yes| New values.|
| predicates   | dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback     | AsyncCallback\<number>            | Yes| Callback used to return the number of updated data records.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": u8,
}
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.update(
    "dataability:///com.example.DataAbility",
    va,
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

### update

update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates): Promise\<number>

Updates data records in the database. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes| URI of the data to update.|
| valuesBucket | rdb.ValuesBucket                  | Yes| New values.|
| predicates   | dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|

**Return value**
| Type| Description|
| ---------------- | -------------------------------------------- |
| Promise\<number> | Promise used to return the number of updated data records.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": u8,
}
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.update(
    "dataability:///com.example.DataAbility",
    va,
    da
	).then((data) => {
		console.info("==========================>updateCallback=======================>");
});
```

### query

query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void

Queries data in the database. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes| URI of the data to query.|
| columns    | rdb.ValuesBucket                  | Yes| Columns to query. If this parameter is **null**, all columns will be queried.|
| predicates | dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback   | AsyncCallback\<ResultSet>         | Yes| Callback used to return the data queried.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars=new Array("value1", "value2", "value3", "value4");
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.query(
    "dataability:///com.example.DataAbility",
    cars,
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```



### query

query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates): Promise\<ResultSet>

Queries data in the database. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes| URI of the data to query.|
| columns    | rdb.ValuesBucket                  | Yes| Columns to query. If this parameter is **null**, all columns will be queried.|
| predicates | dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|

**Return value**
| Type| Description|
| ------------------- | -------------- |
| Promise\<ResultSet> | Promise used to return the data queried.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars=new Array("value1", "value2", "value3", "value4");
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.query(
    "dataability:///com.example.DataAbility",
    cars,
    da
	).then((data) => {
		console.info("==========================>queryCallback=======================>");
});
```
