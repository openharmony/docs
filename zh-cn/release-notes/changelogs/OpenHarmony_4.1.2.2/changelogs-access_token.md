# 程序访问控制子系统ChangeLog
## cl.access_token.1 通过getPermissionUsedRecord获取权限访问记录时的返回结果变更

**变更影响**

变更前，通过调用[getPermissionUsedRecord](../../../application-dev/reference/apis/js-apis-privacyManager.md#privacymanagergetpermissionusedrecord)接口获取权限访问记录时的返回结果，包括访问时的前后台状态、访问时的时间戳、访问时长数据。

变更后，获取权限访问记录时的返回结果中将新增一条可选结果，访问时的锁屏状态。

具体变更内容参考[UsedRecordDetail](../../../application-dev/reference/apis/js-apis-privacyManager.md#usedrecorddetail)单条权限访问记录新增访问时的锁屏状态。

**适配指导**

使用和接口描述等信息参考[getPermissionUsedRecord](../../../application-dev/reference/apis/js-apis-privacyManager.md#privacymanagergetpermissionusedrecord)

调用getPermissionUsedRecord获取权限访问记录，解析对应权限访问记录的锁屏状态。

示例代码:
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
