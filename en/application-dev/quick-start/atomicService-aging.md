# Atomic Service Space Management (for System Applications Only)

Space management for atomic services is necessary from two aspects. On the one hand, users are unaware of the installation of atomic services and do not proactively uninstall them. On the other hand, atomic services have the [installation-free](../reference/apis/js-apis-freeInstall.md) feature, but they are not actually free of installation. This topic describes how to manage the space usage of atomic services for better system space usage.

## Managing Quota for Atomic Service Data Directories

Set a storage quota for the data sandbox directory of an atomic service. This quota can be obtained through the system parameter **persist.sys.bms.aging.policy.atomicservice.datasize.threshold**. The default value is 50 MB. When the quota is used up, writing data will return an error message.

You can run the [param get/set](../../device-dev/subsystems/subsys-boot-init-plugin.md) command to view and set system parameters.

## Proactively Destroying Atomic Services

To proactively destroy an atomic service, call the [uninstall](../reference/apis/js-apis-installer.md#bundleinstalleruninstall) API.

**Example**

```ts
import installer from '@ohos.bundle.installer';
let bundleName = 'com.ohos.demo';
let installParam = {
    userId: 100
};

try {
    installer.getBundleInstaller().then(data => {
        data.uninstall(bundleName, installParam, err => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## Automatically Destroying Atomic Services

### Automatic Destruction Time

Automatic destruction of atomic services can be triggered in any of the following conditions:

- When a timer is set and the given interval has elapsed. The timer interval can be obtained through the system parameter **persist.sys.bms.aging.policy.timer.interval**, which is 8 hours by default. The remaining battery level must be greater than or equal to the value of **persist.sys.bms.aging.policy.battery.threshold**, which is 10% by default.
- When an atomic service is installed.
- When the clearance flag of an atomic service is modified.

### Destruction Conditions

#### Prerequisites

- [isHapModuleRemovable](../reference/apis/js-apis-freeInstall.md#ishapmoduleremovable) is set to **true**.
- The atomic service is not running.

#### Condition for Starting Destruction

The space occupied by all atomic services (including their installation and data directories) is greater than the value of **persist.sys.bms.aging.policy.data.size.threshold**, which is 500 MB by default.

#### Condition for Ending Destruction

The space occupied by all atomic services (including the installation and data directories) is less than 80% of the value of **persist.sys.bms.aging.policy.data.size.threshold**.

### Automatic Destruction Sequence

- Atomic services that can be destroyed are classified into different time slots based on the last used time, for example, [0, 10), [10, 20), [20, 30), [30, ~). The time slot unit can be obtained from the system parameter **persist.sys.bms.aging.policy.recently.used.threshold**, which is 1 day by default.
- For any two atomic services that can be destroyed, if they are in the same time slot, the atomic service that is less used is destroyed first; if they are in different time slots, the atomic service that is not used for a longer time is destroyed first.

### Automatic Destruction by Level

- When the condition for starting automatic destruction is met, the cache directories of the atomic services are destroyed first based on the destruction sequence. If the condition for ending destruction is met, the destruction is ended.
- If the condition for ending destruction is not met, the other directories of the atomic service are destroyed based on the destruction sequence.
