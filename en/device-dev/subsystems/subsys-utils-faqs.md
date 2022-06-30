# Utils FAQ<a name="EN-US_TOPIC_0000001058735275"></a>

## 1. Failed to run the KV store on the LiteOS Cortex-A kernel \(Hi3516 or Hi3518\) due to incorrect path setting for the KV store<a name="section2041345718513"></a>

**Symptom**

When the LiteOS Cortex-A kernel \(Hi3516 or Hi3518 platform\) directly calls the API provided by the KV store, the compiled executable program fails to run.

**Possible Causes**

The compiled executable program is run directly without being converted to an application using **AbilityKit** APIs. In this case, the Bundle Manager Service \(BMS\) cannot correctly set the path for storing application data during application installation. As a result, the KV store fails to run.

**Solution**

Call the **UtilsSetEnv** function of the KV store to set the data storage path.

```
UtilsSetEnv("/storage/com.example.kv");
```

