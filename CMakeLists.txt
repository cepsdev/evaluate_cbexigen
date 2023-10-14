cmake_minimum_required(VERSION 3.10)
project(v2g-example)

add_compile_options(-O  -Wall -MD  -std=c++2a  -fPIC -static -Wno-undef )


include_directories(v2gproc/)
include_directories(v2gproc/common)
include_directories(v2gproc/iso-20)
include_directories(v2gproc/v2gtp)


add_executable(v2g-example 
           src/v2g-example.cpp
           v2gproc/common/exi_basetypes.c
           v2gproc/common/exi_basetypes_encoder.c
           v2gproc/common/exi_header.c
           v2gproc/common/exi_basetypes_decoder.c
           v2gproc/common/exi_bitstream.c
           v2gproc/common/exi_types_decoder.c
           v2gproc/iso-20/iso20_AC_Datatypes.c
           v2gproc/iso-20/iso20_CommonMessages_Datatypes.c
           v2gproc/iso-20/iso20_DC_Datatypes.c
           v2gproc/iso-20/iso20_AC_Decoder.c
           v2gproc/iso-20/iso20_CommonMessages_Decoder.c
           v2gproc/iso-20/iso20_DC_Decoder.c
           v2gproc/iso-20/iso20_AC_Encoder.c
           v2gproc/iso-20/iso20_CommonMessages_Encoder.c
           v2gproc/iso-20/iso20_DC_Encoder.c
           v2gproc/v2gtp/exi_v2gtp.c           
)

target_link_libraries(v2g-example sctp pthread)
