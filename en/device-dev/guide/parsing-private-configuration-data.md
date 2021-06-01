# Parsing Private Configuration Data<a name="EN-US_TOPIC_0000001158241889"></a>

You can obtain the sample code at  **./drivers/framework/model/input/driver/input\_config\_parser.c**.

The configuration parsing functions provided by the OSAL can parse the fields in the  **hcs**  file. For details, see the implementation of each function in  **input\_config\_parser.c**. If the provided template cannot meet business requirements, you need to add required information to the  **hcs**  file and then develop parsing functions based on the added fields.

```
static int32_t ParseAttr(struct DeviceResourceIface *parser, const struct DeviceResourceNode *attrNode, BoardAttrCfg *attr)
{
    int32_t ret;
    ret = parser->GetUint8(attrNode, "inputType", &attr->devType, 0);     // Obtain the inputType field and save it in the BoardAttrCfg structure.
    CHECK_PARSER_RET(ret, "GetUint8");
    ...
    return HDF_SUCCESS;
}
```

