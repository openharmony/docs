# IPC Authentication Development<a name="EN-US_TOPIC_0000001058671861"></a>

## When to Use<a name="section18502174174019"></a>

System services registered with Samgr can be accessed by other processes through IPC APIs. When a process requests to access such an API, IPC authentication is triggered to check whether the process has the required permission. If the process does not have the required permission, the access request will be denied.

When developing a system service, you can use the IPC authentication component to configure access policies for APIs of the service. When other services access these APIs through IPC, Samgr calls APIs of the IPC authentication component to check whether the services have the access permission.

## Available APIs<a name="section1633115419401"></a>

The following table lists the APIs provided by IPC authentication \(intended for Samgr only\).

**Table  1**  APIs provided by IPC authentication

<a name="table10494122145517"></a>
<table><thead align="left"><tr id="row1494152195511"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p14941221135515"><a name="p14941221135515"></a><a name="p14941221135515"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p8494172116555"><a name="p8494172116555"></a><a name="p8494172116555"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1849482118555"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1414381815720"><a name="p1414381815720"></a><a name="p1414381815720"></a>int GetCommunicationStrategy(RegParams params, PolicyTrans **policies, unsigned int *policyNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p749582195510"><a name="p749582195510"></a><a name="p749582195510"></a>Obtains the access policies of a service API.</p>
</td>
</tr>
<tr id="row8495521115517"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p966319247576"><a name="p966319247576"></a><a name="p966319247576"></a>int IsCommunicationAllowed(AuthParams params)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p134951921115511"><a name="p134951921115511"></a><a name="p134951921115511"></a>Checks whether a process has the permission to access an API of another process.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section022611498210"></a>

This section uses BMS as an example to describe how to configure access policies for APIs provided by the IPC authentication component. In this example, the service registered by BMS with Samgr is  **bundlems**, and the feature registered for open APIs is  **BmsFeature**.

1.  <a name="li15901515152517"></a>On the OpenHarmony side, configure access policies in the  **base/security/permission/services/permission\_lite/ipc\_auth/include/policy\_preset.h**  file. On the device side, configure access policies in the  **vendor/hisilicon/_product name_/hals/security/permission\_lite/ipc\_auth/include/policy\_preset\_product.h**  file. After that, set  **POLICY\_PRODUCT**  in the header files to  **1**. Access policies are classified into the following three types:

    1.  **RANGE**: Processes with a specified range of UIDs can access BMS APIs.  **uidMin**  and  **uidMax**  must be specified.

    2.  **FIXED**: Processes with specified UIDs can access BMS APIs.  **fixedUid**  must be specified, and a maximum of eight UIDs are allowed.

    3.  **BUNDLENAME**: An application with a specified  **bundleName**  can access BMS APIs.

    ```
    FeaturePolicy bmsFeature[] = {
        {
            "BmsFeature",
            {
                {
                    .type=FIXED,    // Processes with specified UIDs can access BMS APIs.
                    .fixedUid={2, 3, 8}
                },
                {
                    .type=RANGE,    // Processes with a specified range of UIDs can access BMS APIs. 
                    .uidMin=100,
                    .uidMax=__INT_MAX__,
                },
            }
        },
        {
            "BmsInnerFeature",
            {
                {
                    .type=FIXED,     // Processes with specified UIDs can access BMS APIs.
                    .fixedUid={2, 3, 8}
                },
                {
                    .type=RANGE,
                    .uidMin=100,
                    .uidMax=999,
                },
            }
        },
    };
    ```

2.  Add the policies configured for the features in  [Step 1](#li15901515152517)  to the global policy settings. You need to set the number of features.

    ```
    static PolicySetting g_presetPolicies[] = {
        {"permissionms", pmsFeature, 1},
        {"abilityms", amsFeature, 2},
        {"bundlems", bmsFeature, 2},  // Add the policies configured for the two features in [Step 1](#li15901515152517) to the global policy settings.
        {"dtbschedsrv", dmsFeature, 1},
        {"samgr", samgrFeature, 1},
        {"appspawn", appspawnFeature, 1},
        {"WMS", wmsFeature, 1},
        {"bundle_daemon", bdsFeature, 1},
    };
    ```

3.  Register the  **BmsFeature**  defined in  [Step 1](#li15901515152517)  with Samgr.

    ```
    const char BMS_SERVICE[] = "bundlems";
    const char BMS_FEATURE[] = "BmsFeature";
    static void Init()
    {
        SamgrLite *sm = SAMGR_GetInstance();
        if (sm == nullptr) {
            return;
        }
        // Register the BmsFeature with Samgr.
        sm->RegisterFeature(BMS_SERVICE, reinterpret_cast<Feature *>(BundleMsFeature::GetInstance()));
        sm->RegisterFeatureApi(BMS_SERVICE, BMS_FEATURE,
            GetBmsFeatureApi(reinterpret_cast<Feature *>(BundleMsFeature::GetInstance())));
        HILOG_DEBUG(HILOG_MODULE_APP, "BundleMS feature start success");
    }
    APP_FEATURE_INIT(Init);
    ```


When you register a service with Samgr, Samgr calls the  **GetCommunicationStrategy**  function of the IPC authentication component to obtain access policies of the service. When other services or applications access this service through IPC, Samgr calls the  **IsCommunicationAllowed**  function of the IPC authentication component to check whether the services or applications have the access permission.

## FAQ<a name="section15729104510271"></a>

-   Registering a service with Samgr failed

    **Problem**

    During the startup of a new service, a message is displayed indicating that the service fails to be registered with Samgr.

    **Cause**

    The service UID is not configured in the IPC authentication component.

    **Solution**

    Configure a valid UID for the service in the  **base/security/permission/services/permission\_lite/ipc\_auth/src/ipc\_auth\_impl.c**  file.


