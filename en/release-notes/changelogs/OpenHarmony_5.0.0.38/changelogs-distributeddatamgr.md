# Distributed Data Management Changelog

## cl.distributeddatamgr.1 Change of Error Codes Returned When RelationalStore execute() and executeSync() Execute an Invalid SQL Statement

**Access Level**

Public API

**Reason for Change**

The change is made to improve accuracy of the error codes returned by APIs, which helps increase the fault locating efficiency.

**Change Impact**

This change is a non-compatible change.

Before the change:

If an invalid SQL statement is executed, error code 14800000 is reported.

After the change:

If an invalid SQL statement is executed, error code 14800021 is reported.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.38

**Key API/Component Changes**

|               Use Case              |      Error Code Before the Change     |      Error Code After the Change     |
| :------------------------------ | :--------------: | :--------------: |
|   An invalid SQL statement is executed by **execute()**.  | 14800000| 14800021|
| An invalid SQL statement is executed by **executeSync()**.| 14800000| 14800021|

**Adaptation Guide**

If error code 14800000 was used in **execute()** and **executeSync()**, change the error code to 14800021.

Before the change:

If an invalid SQL statement is executed by **execute()**, the error message is as follows:

```ts
try {
    await rdbStore.execute("COMMIT");
} catch (err) {
    if (err.code === 14800000) {
        console.log(`execute failed, code: ${err.code}`);
    }
}
```

After the change: 

If an invalid SQL statement is executed by **execute()**, the error message is as follows:

```ts
try {
    await rdbStore.execute("COMMIT");
} catch (err) {
    if (err.code === 14800021) {
        console.log(`execute failed, code: ${err.code}`);
    }
}
```

Before the change: 

If an invalid SQL statement is executed by **executeSync()**, the error message is as follows:

```ts
try {
    await rdbStore.executeSync("COMMIT");
} catch (err) {
    if (err.code === 14800000) {
        console.log(`execute failed, code: ${err.code}`);
    }
}
```

After the change: 

If an invalid SQL statement is executed by **executeSync()**, the error message is as follows:

```ts
try {
    await rdbStore.executeSync("COMMIT");
} catch (err) {
    if (err.code === 14800021) {
        console.log(`execute failed, code: ${err.code}`);
    }
}
```
