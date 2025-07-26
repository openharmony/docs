# Overview of Concurrency in Time-Consuming Tasks


Time-consuming tasks are those that take a long time to complete. If executed in the UI main thread, they can cause application lag, frame drops, and slow response times. Typical examples include CPU intensive tasks, I/O intensive tasks, and synchronous tasks.


Typical service scenarios are as follows:


| Service Scenario| Description| Is CPU Intensive Task| Is I/O Intensive Task| Is Synchronous Task|
| -------- | -------- | -------- | -------- | -------- |
| Image/Video encoding and decoding| Encoding or decoding images or videos for display.| Yes| Yes| No|
| Compression and decompression| Decompressing local archives or compressing local files.| Yes| Yes| No|
| JSON parsing| Serializing and deserializing JSON strings.| Yes| No| No|
| Model computation| Performing data analysis using models.| Yes| No| No|
| Network download| Downloading resources, images, and files via intensive network requests.| No| Yes| No|
| Database operations| Saving data like chat records, page layouts, or music lists to the database, or reading from the database on application restart.| No| Yes| No|
