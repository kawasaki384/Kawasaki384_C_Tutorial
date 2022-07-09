#ifndef BMP_HEADER_H_
#define BMP_HEADER_H_

#pragma pack(2)
typedef union BMP_Header{
    char bmpheader [54];
    struct {
        char Format[2];
        int FileSize;
        char reserved_0[2];
        char reserved_1[2];
        int HeaderSize;
        int InfomationHeaderSize;
        int width;
        int height;
        char plane[2];
        char ColorCount;
        int CompressFormat;
        int CompressSize;
        int HorizontalResolution;
        int VerticalResolution;
        int ColorNumber;
        int ImportantColorNumber;  
    };
} BMP_header;

#endif /*BMP_HEADER_H_*/