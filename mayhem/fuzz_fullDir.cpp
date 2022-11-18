
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fuzzer/FuzzedDataProvider.h>
#include "utility/FileInfo.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    std::string str = provider.ConsumeRandomLengthString();

    psy::FileInfo fi(str);
    fi.fullDir();

    return 0;
}