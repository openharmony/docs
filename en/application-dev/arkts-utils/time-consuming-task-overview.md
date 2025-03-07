# Overview of Concurrency in Time-Consuming Tasks


Time-consuming tasks are those that take a long time to complete. If executed in the UI main thread, they can cause application lag, frame drops, and slow response times. Typical examples include CPU intensive tasks, I/O intensive tasks, and synchronous tasks.


The following describes typical service scenarios for time-consuming tasks.


| Service Scenario| Description| CPU Intensive Task| I/O intensive Task| Synchronous Task|
| -------- | -------- | -------- | -------- | -------- |
| Image/Video encoding and decoding| Encoding or decoding images or videos for display.| Supported| Supported| Not supported|
| Compression and decompression| Decompressing local archives or compressing local files.| Supported| Supported| Not supported|
| JSON parsing| Serializing and deserializing JSON strings.| Supported| Not supported| Not supported|
| Model computation| Performing data analysis using models.| Supported| Not supported| Not supported|
| Network download| Downloading resources, images, and files via intensive network requests.| Not supported| Supported| Not supported|
| Database operations| Saving data like chat records, page layouts, or music lists to the database, or reading from the database on application restart.| Not supported| Supported| Not supported|
