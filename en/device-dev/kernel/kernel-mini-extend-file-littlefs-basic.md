# Basic Concepts<a name="EN-US_TOPIC_0000001153060453"></a>

LittleFS is a small file system designed for flash. By combining the log-structured file system and the copy-on-write \(COW\) file system, LittleFS stores metadata in log structure and data in the COW structure. This special storage empowers LittleFS high power-loss resilience. LittleFS uses the statistical wear leveling algorithm when allocating COW data blocks, effectively prolonging the service life of flash devices. LittleFS is designed for small-sized devices with limited resources, such as ROM and RAM. All RAM resources are allocated through a buffer with the fixed size \(configurable\). That is, the RAM usage does not grow with the file system.

LittleFS is a good choice when you look for a flash file system that is power-cut resilient and has wear leveling support on a small device with limited resources.

