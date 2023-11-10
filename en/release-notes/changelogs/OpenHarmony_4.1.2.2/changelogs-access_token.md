# Application Access Control Subsystem Changelog
## cl.access_token.1 Change of the Value Returned by getPermissionUsedRecord

**Change Impact**

Before the change, the permission access record returned by [getPermissionUsedRecord](../../../application-dev/reference/apis/js-apis-privacyManager.md#privacymanagergetpermissionusedrecord) includes the foreground and background status, access timestamp, and access duration.

After the change, the permission access record also includes **lockScreenStatus**, which is optional.

For details, see [UsedRecordDetail](../../../application-dev/reference/apis/js-apis-privacyManager.md#usedrecorddetail).

**Adaptation Guide**

For details, see [getPermissionUsedRecord](../../../application-dev/reference/apis/js-apis-privacyManager.md#privacymanagergetpermissionusedrecord).

For example, call **getPermissionUsedRecord** to obtain information about the permission usage and parse **lockScreenStatus**.

Sample code:
```ts
import privacyManager from '@ohos.privacyManager';

try {
    privacyManager.getPermissionUsedRecord({
        flag:1
    }, (err, data) => {
        try {
            let record = data.bundleRecords[0].permissionRecords[0];
            let access = record.accessRecords;
            let reject = record.rejectRecords;
            for (let i = 0; i < access.length; i++) {
                let detail = access[i];
                console.log(`access record detail lockscreen status: ` + detail.lockScreenStatus);
            }
            for (let i = 0; i < reject.length; i++) {
                let detail = reject[i];
                console.log(`reject record detail lockscreen status: ` + detail.lockScreenStatus);
            }
        } catch(err) {
            console.log(`catch err->${JSON.stringify(err)}`);
        }
    })
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```
