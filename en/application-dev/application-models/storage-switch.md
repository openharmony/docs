# Storage Switching


| API in the FA Model| Corresponding .d.ts File in the Stage Model| Corresponding API in the Stage Model|
| -------- | -------- | -------- |
| GetStorageOptions | There is no corresponding API in the stage model.| The stage model uses **Prefereces** to replace **Storage** and has redesigned the input parameters.|
| SetStorageOptions | There is no corresponding API in the stage model.| The stage model uses **Prefereces** to replace **Storage** and has redesigned the input parameters.|
| ClearStorageOptions | There is no corresponding API in the stage model.| The stage model uses **Prefereces** to replace **Storage** and has redesigned the input parameters.|
| DeleteStorageOptions | There is no corresponding API in the stage model.| The stage model uses **Prefereces** to replace **Storage** and has redesigned the input parameters.|
| [static get(options: GetStorageOptions): void;](../reference/apis-arkdata/js-apis-system-storage.md#storageget) | \@ohos.data.preferences.d.ts | [get(key: string, defValue: ValueType, callback: AsyncCallback&lt;ValueType&gt;): void;](../reference/apis-arkdata/js-apis-data-preferences.md#get)<br>[get(key: string, defValue: ValueType): Promise&lt;ValueType&gt;;](../reference/apis-arkdata/js-apis-data-preferences.md#get-1) |
| [static set(options: SetStorageOptions): void;](../reference/apis-arkdata/js-apis-system-storage.md#storageset) | \@ohos.data.preferences.d.ts | [put(key: string, value: ValueType, callback: AsyncCallback&lt;void&gt;): void;](../reference/apis-arkdata/js-apis-data-preferences.md#put)<br>[put(key: string, value: ValueType): Promise&lt;void&gt;;](../reference/apis-arkdata/js-apis-data-preferences.md#put-1) |
| [static clear(options?: ClearStorageOptions): void;](../reference/apis-arkdata/js-apis-system-storage.md#storageclear) | \@ohos.data.preferences.d.ts | [clear(callback: AsyncCallback&lt;void&gt;): void;](../reference/apis-arkdata/js-apis-data-preferences.md#clear)<br>[clear(): Promise&lt;void&gt;;](../reference/apis-arkdata/js-apis-data-preferences.md#clear-1) |
| [static delete(options: DeleteStorageOptions): void;](../reference/apis-arkdata/js-apis-system-storage.md#storagedelete) | \@ohos.data.preferences.d.ts | [delete(key: string, callback: AsyncCallback&lt;void&gt;): void;](../reference/apis-arkdata/js-apis-data-preferences.md#delete)<br>[delete(key: string): Promise&lt;void&gt;;](../reference/apis-arkdata/js-apis-data-preferences.md#delete-1) |

 <!--no_check--> 