# File compression system using Huffman Algorithm
Blog: [Coming soon]\
A compression system that uses the Huffman algorithm to compress text(.txt) files into binary(.bin) files reducing the filesize by ~50%. 
The binary(.bin) files can then be decompressed back into the original text files without loss of data.\
## File Structure
```
.
├── .idea                 
├── cmake-build-debug     
├── Compressed            # generated compressed files
├── Decompressed          # decompressed output files
├── HeaderFiles           # header files
│   ├── reader.h
│   ├── encoder.h
│   └── decoder.h
└── src                   # source code
    ├── main.cpp
    ├── reader.cpp
    ├── encoder.cpp
    └── decoder.cpp
```

