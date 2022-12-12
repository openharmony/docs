# Buffer Error Codes

## 10200001 Value Out of Range

**Error Message**

The value of ${param} is out of range.

**Description**

The value of a parameter passed in the API exceeds the valid range.

**Possible Causes**

The parameter value exceeds the value range.

**Solution**

Check and modify the parameter value.

## 10200009 Incorrect Buffer Size

**Error Message**

Buffer size must be a multiple of ${size}

**Description**

The buffer size must be an integer multiple of 16 bits, 32 bits, or 64 bits.

**Possible Causes**

The buffer size is not an integer multiple of 16 bits, 32 bits, or 64 bits.

**Solution**

Check the buffer length.

## 10200013 Read-Only Properly

**Error Message**

Cannot set property ${propertyName} of Buffer which has only a getter.

**Description**

The buffer ${propertyName} is read-only and cannot be set.

**Possible Causes**

The ${propertyName} parameter is read-only and cannot be set.

**Solution**

${propertyName} cannot be set. Do not place it on the left of the equal sign (=).
