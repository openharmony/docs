# Rdb_ProgressObserver

## Overview

Defines a struct for the observer for the device-cloud sync progress.

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name                                                        | Description                          |
| ------------------------------------------------------------ | ------------------------------ |
| void* context                                                | Context of the device-cloud sync progress observer.  |
| [Rdb_ProgressCallback](capi-relational-store-h.md#rdb_progresscallback) callback | Callback used to return the device-cloud sync progress.|
