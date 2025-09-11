# Rdb_ProgressDetails
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines a struct for statistics of the overall device-cloud sync (upload and download) tasks of an RDB store.

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name               | Description                                   |
| ------------------- | --------------------------------------- |
| int version         | Version of the **OH_TableDetails** struct.|
| int schedule        | Device-cloud sync process.                     |
| int code            | Device-cloud sync state.               |
| int32_t tableLength | Number of the tables synced between the device and cloud.               |
