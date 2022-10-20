# Data Management Development



## How Do I Save PixelMap data to a database?

Applicable to: OpenHarmony SDK 3.2.3.5

You can convert a **PixelMap** into a **ArrayBuffer** and save the **ArrayBuffer** to your database.

Reference: [readPixelsToBuffer](../reference/apis/js-apis-image.md#readpixelstobuffer7-1)

## How Do I Obtain RDB Store Files?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Run the hdc_std command to copy the .db, .db-shm, and .db-wal files from **/data/app/el2/100/database/Bundle name/entry/db/**, and then use the SQLite tool to open the files.

Example:

  
```
 hdc_std file recv /data/app/el2/100/database/com.xxxx.xxxx/entry/db/test.db ./test.db
```
