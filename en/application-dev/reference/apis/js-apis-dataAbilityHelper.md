### DataAbilityHelper Module (JavaScript SDK APIs)

#### Applicable Devices

| API                                                          | Phone| Tablet| Smart TV| Wearable| Lite Wearable| SmartVision Device|
| ------------------------------------------------------------ | ---- | ---- | ------ | -------- | -------------- | ------------ |
| DataAbilityHelper.openFile(uri: string, mode: string, callback: AsyncCallback\<number>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.openFile(uri: string, mode: string)        | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array\<string>>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.getFileTypes(uri: string, mimeTypeFilter: string) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.getType(uri: string, callback: AsyncCallback\<string>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.getType(uri: string)                       | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.normalizeUri(uri: string, callback: AsyncCallback\<string>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.normalizeUri(uri: string)                  | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.denormalizeUri(uri: string, callback: AsyncCallback\<string>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.denormalizeUri(uri: string)                | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.notifyChange(uri: string, callback: AsyncCallback\<void>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.notifyChange(uri: string)                  | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.insert(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.insert(uri: string, valuesBucket: rdb.ValuesBucket) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>, callback: AsyncCallback\<number>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.delete(uri: string, predicates: dataAbility.DataAbilityPredicates) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>) | Yes| Yes| Yes| Yes| No| No|
| DataAbilityHelper.query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates) | Yes| Yes| Yes| Yes| No| No|

#### Modules to Import

```
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
import ohos_data_rdb from '@ohos.data.rdb'
```

#### DataAbilityHelper.openFile(uri: string, mode: string, callback: AsyncCallback\<number>)

- Functionality

  Opens a file with a specified URI. This method uses a callback to return the result.


* Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | -------------------- | ---- | ------------------------ |
  | uri      | Read-only| string               | Yes| URI of the file to open.|
  | mode     | Read-only| string               | Yes| Mode for opening the file. The value can be **rwt**.|
  | callback | Read-only| AsyncCallback\<void> | Yes| Callback used to return the result.|

* Return values

  Returns a file descriptor.

* Example

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

#### DataAbilityHelper.openFile(uri: string, mode: string)

- Functionality

  Opens a file with a specified URI. This method uses a promise to return the result.

* Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ---- | -------- | ------ | ---- | ------------------------ |
  | uri  | Read-only| string | Yes| URI of the file to open.|
  | mode | Read-only| string | Yes| Mode for opening the file. The value can be **rwt**.|

* Return values

  Returns a file descriptor.

* Example

```javascript
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var mode = "rwt";
DAHelper.openFile(
    "dataability:///com.example.DataAbility",
    mode).then((void) => {
		console.info("==========================>openFileCallback=======================>");
});
```

#### DataAbilityHelper.on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>)

- Functionality

  Registers an observer to observe data specified by a given URI. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | -------------------- | ---- | ------------------------ |
  | type     | Read-only| string               | Yes| Type of the event to observe. The value is **dataChange**.|
  | uri      | Read-only| string               | Yes| URI of the data.|
  | callback | Read-only| AsyncCallback\<void> | Yes| Callback invoked when the data is changed.|

- Return value

  void

- Example

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

#### DataAbilityHelper.off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>)

- Functionality

  Unregisters the observer used to observe data specified by a given URI. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | -------------------- | ---- | ------------------------ |
  | type     | Read-only| string               | Yes| Type of the event to observe. The value is **dataChange**.|
  | uri      | Read-only| string               | Yes| URI of the data.|
  | callback | Read-only| AsyncCallback\<void> | No| Callback used to return the result.|

- Return value

  void

- Example

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

#### DataAbilityHelper.getType(uri: string, callback: AsyncCallback\<string>)

- Functionality

  Obtains the MIME type of the data specified by a given URI. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | ---------------------- | ---- | ------------------------ |
  | uri      | Read-only| string                 | Yes| URI of the data.|
  | callback | Read-only| AsyncCallback\<string> | Yes| Callback used to return the result.|

- Return value

  Returns the MIME type that matches the data specified by the URI.

- Example

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

#### DataAbilityHelper.getType(uri: string)

- Functionality

  Obtains the MIME type of the data specified by a given URI. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ---- | -------- | ------ | ---- | ------------------------ |
  | uri  | Read-only| string | Yes| URI of the data.|

- Return value

  Returns the MIME type that matches the data specified by the URI.

- Example

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

#### DataAbilityHelper.getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array\<string>>)

- Functionality

  Obtains the supported MIME types of a specified file. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------------- | -------- | ------------------------------ | ---- | ---------------------------- |
  | uri            | Read-only| string                         | Yes| URI of the file.|
  | mimeTypeFilter | Read-only| string                         | Yes| MIME type of the file.|
  | callback       | Read-only| AsyncCallback\<Array\<string>> | Yes| Callback used to return the result.|

- Return value

  Returns a MIME type array.

- Example

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

#### DataAbilityHelper.getFileTypes(uri: string, mimeTypeFilter: string)

- Functionality

  Obtains the supported MIME types of a specified file. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------------- | -------- | ------ | ---- | ---------------------------- |
  | uri            | Read-only| string | Yes| URI of the file.|
  | mimeTypeFilter | Read-only| string | Yes| MIME type of the file.|

- Return value

  Returns a MIME type array.

- Example

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

#### DataAbilityHelper.normalizeUri(uri: string, callback: AsyncCallback\<string>)

- Functionality

  Converts the URI that refers to a Data ability into a normalized URI. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | ---------------------- | ---- | ----------------------- |
  | uri      | Read-only| string                 | Yes| URI object to normalize.|
  | callback | Read-only| AsyncCallback\<string> | Yes| Callback used to return the result.|

- Return value

  Returns the normalized URI object if the Data ability supports URI normalization; returns **null** otherwise.

- Example

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

#### DataAbilityHelper.normalizeUri(uri: string)

- Functionality

  Converts the URI that refers to a Data ability into a normalized URI. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ---- | -------- | ------ | ---- | ----------------------- |
  | uri  | Read-only| string | Yes| URI object to normalize.|

- Return value

  Returns the normalized URI object if the Data ability supports URI normalization; returns **null** otherwise.

- Example

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

#### DataAbilityHelper.denormalizeUri(uri: string, callback: AsyncCallback\<string>)

- Functionality

  Converts a normalized URI generated by **DataAbilityHelper.normalizeUri(uri: string, callback: AsyncCallback\<string>)** to a denormalized one. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | ---------------------- | ---- | ----------------------- |
  | uri      | Read-only| string                 | Yes| URI object to denormalize.|
  | callback | Read-only| AsyncCallback\<string> | Yes| Callback used to return the result.|

- Return value

  Returns the denormalized URI object.

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.denormalizeUri(
    "dataability:///com.example.DataAbility",,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

#### DataAbilityHelper.denormalizeUri(uri: string)

- Functionality

  Converts a normalized URI generated by **DataAbilityHelper.normalizeUri(uri: string)** to a denormalized one. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ---- | -------- | ------ | ---- | ----------------------- |
  | uri  | Read-only| string | Yes| URI object to denormalize.|

- Return value

  Returns the denormalized URI object.

- Example

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

#### DataAbilityHelper.notifyChange(uri: string, callback: AsyncCallback\<void>)

- Functionality

  Notifies the registered observer of a change to the data specified by the URI. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | -------- | -------- | -------------------- | ---- | ------------------------ |
  | uri      | Read-only| string               | Yes| URI of the data.|
  | callback | Read-only| AsyncCallback\<void> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var helper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
helper.notifyChange(
    "dataability:///com.example.DataAbility",,
    (err) => {
		console.info("==========================>Called=======================>");
});
```

#### DataAbilityHelper.notifyChange(uri: string)

- Functionality

  Notifies the registered observer of a change to the data specified by the URI. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ---- | -------- | ------ | ---- | ------------------------ |
  | uri  | Read-only| string | Yes| URI of the data.|

- Return value

  void

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.notifyChange(
    "dataability:///com.example.DataAbility",
	).then((void) => {
		console.info("==========================>notifyChangeCallback=======================>");
});
```

#### DataAbilityHelper.insert(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>)

- Functionality

  Inserts a single data record into the database. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ------------ | -------- | ---------------------- | ---- | ------------------------------------------------------ |
  | uri          | Read-only| string                 | Yes| URI of the data to insert.|
  | valuesBucket | Read-only| rdb.ValuesBucket       | Yes| Data record to insert. If this parameter is **null**, a blank row will be inserted.|
  | callback     | Read-only| AsyncCallback\<number> | Yes| Callback used to return the result.|

- Return value

  Returns the index of the inserted data record.

- Example

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

#### DataAbilityHelper.insert(uri: string, valuesBucket: rdb.ValuesBucket)

- Functionality

  Inserts a single data record into the database. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ------------ | -------- | ---------------- | ---- | ------------------------------------------------------ |
  | uri          | Read-only| string           | Yes| URI of the data to insert.|
  | valuesBucket | Read-only| rdb.ValuesBucket | Yes| Data record to insert. If this parameter is **null**, a blank row will be inserted.|

- Return value

  Returns the index of the inserted data record.

- Example

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

#### DataAbilityHelper.batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>, callback: AsyncCallback\<number>)

- Functionality

  Inserts multiple data records into the database. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ------------ | -------- | ----------------------- | ---- | ------------------------ |
  | uri          | Read-only| string                  | Yes| URI of the data to insert.|
  | valuesBucket | Read-only| Array<rdb.ValuesBucket> | Yes| Data records to insert.|
  | callback     | Read-only| AsyncCallback\<number>  | Yes| Callback used to return the result.|

- Return value

  Returns the number of inserted data records.

- Example

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

#### DataAbilityHelper.batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>)

- Functionality

  Inserts multiple data records into the database. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ------------ | -------- | ----------------------- | ---- | ------------------------ |
  | uri          | Read-only| string                  | Yes| URI of the data to insert.|
  | valuesBucket | Read-only| Array<rdb.ValuesBucket> | Yes| Data records to insert.|

- Return value

  Returns the number of inserted data records.

- Example

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

#### DataAbilityHelper.delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>)

- Functionality

  Deletes one or more data records from the database. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ------------ | -------- | --------------------------------- | ---- | ------------------------------------------------ |
  | uri          | Read-only| string                            | Yes| URI of the data to delete.|
  | valuesBucket | Read-only| dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|
  | callback     | Read-only| AsyncCallback\<number>            | Yes| Callback used to return the result.|

- Return value

  Returns the number of deleted data records.

- Example

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

#### DataAbilityHelper.delete(uri: string, predicates: dataAbility.DataAbilityPredicates)

- Functionality

  Deletes one or more data records from the database. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ------------ | -------- | --------------------------------- | ---- | ------------------------------------------------ |
  | uri          | Read-only| string                            | Yes| URI of the data to delete.|
  | valuesBucket | Read-only| dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|

- Return value

  Returns the number of deleted data records.

- Example

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

#### DataAbilityHelper.update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>)

- Functionality

  Updates data records in the database. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ------------ | -------- | --------------------------------- | ---- | ------------------------------------------------ |
  | uri          | Read-only| string                            | Yes| URI of the data to update.|
  | valuesBucket | Read-only| rdb.ValuesBucket                  | Yes| New values.|
  | predicates   | Read-only| dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|
  | callback     | Read-only| AsyncCallback\<number>            | Yes| Callback used to return the result.|

- Return value

  Returns the number of updated data records.

- Example

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

#### DataAbilityHelper.update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates)

- Functionality

  Updates data records in the database. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ------------ | -------- | --------------------------------- | ---- | ------------------------------------------------ |
  | uri          | Read-only| string                            | Yes| URI of the data to update.|
  | valuesBucket | Read-only| rdb.ValuesBucket                  | Yes| New values.|
  | predicates   | Read-only| dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|

- Return value

  Returns the number of updated data records.

- Example

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

#### DataAbilityHelper.query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>)

- Functionality

  Queries data in the database. This method uses a callback to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ---------- | -------- | --------------------------------- | ---- | ------------------------------------------------ |
  | uri        | Read-only| string                            | Yes| URI of the data to query.|
  | columns    | Read-only| rdb.ValuesBucket                  | Yes| Columns to query. If this parameter is **null**, all columns will be queried.|
  | predicates | Read-only| dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|
  | callback   | Read-only| AsyncCallback\<ResultSet>         | Yes| Callback used to return the result.|

- Return value

  Returns the data queried.

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars=new Array({"value1"}, {"value2"}, {"value3"}, {"value4"});
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.query(
    "dataability:///com.example.DataAbility",
    cars,
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```



#### DataAbilityHelper.query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates)

- Functionality

  Queries data in the database. This method uses a promise to return the result.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ---------- | -------- | --------------------------------- | ---- | ------------------------------------------------ |
  | uri        | Readable and writable| string                            | Yes| URI of the data to query.|
  | columns    | Readable and writable| rdb.ValuesBucket                  | Yes| Columns to query. If this parameter is **null**, all columns will be queried.|
  | predicates | Readable and writable| dataAbility.DataAbilityPredicates | Yes| Filter criteria. You should define the processing logic when this parameter is **null**.|

- Return value

  Returns the data queried.

- Example

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars=new Array({"value1"}, {"value2"}, {"value3"}, {"value4"});
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.query(
    "dataability:///com.example.DataAbility",
    cars,
    da
	).then((data) => {
		console.info("==========================>queryCallback=======================>");
});
```
