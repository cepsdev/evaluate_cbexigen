#include <iostream>
#include  <cstring>

#include "exi_basetypes.h"
#include "exi_basetypes_encoder.h"
#include "exi_error_codes.h"
#include "exi_types_decoder.h"
#include "exi_basetypes_decoder.h"
#include "exi_bitstream.h"
#include "exi_header.h"
#include "iso20_AC_Datatypes.h"  
#include "iso20_CommonMessages_Datatypes.h"  
#include "iso20_DC_Datatypes.h"
#include "iso20_AC_Decoder.h"    
#include "iso20_CommonMessages_Decoder.h"    
#include "iso20_DC_Decoder.h"
#include "iso20_AC_Encoder.h"
#include "iso20_CommonMessages_Encoder.h"
#include "iso20_DC_Encoder.h"
#include "exi_v2gtp.h"

int main() {
    using namespace std;
    exi_bitstream_t exi_bitstream{};
    size_t nbytes{1024};
    uint8_t data[1024] = {};
    exi_bitstream_init(&exi_bitstream, data, nbytes, 0, nullptr);
    iso20_dc_exiDocument doc{};
    doc.BPT_Dynamic_DC_CLResControlMode_isUsed = 1;
    init_iso20_dc_BPT_Dynamic_DC_CLResControlModeType(&doc.BPT_Dynamic_DC_CLResControlMode);
    doc.BPT_Dynamic_DC_CLResControlMode.DepartureTime_isUsed = 1;
    doc.BPT_Dynamic_DC_CLResControlMode.DepartureTime = 123;

    auto r{encode_iso20_dc_exiDocument(&exi_bitstream, &doc)};
    if ( r  == EXI_ERROR__NO_ERROR ) 
     cout << "Doc successfully encoded\n";
    else{
     cerr << "Failed to encode\n";
     return 1;
    }
    cout << "exi_bitstream.bit_count = "<< (int)exi_bitstream.bit_count << '\n';
    cout << "exi_bitstream.byte_pos = "<< (int)exi_bitstream.byte_pos << '\n';
    exi_bitstream.bit_count  = 0;
    exi_bitstream.byte_pos = 0;
    
    iso20_dc_exiDocument doc_decode{};
    auto rr{decode_iso20_dc_exiDocument(&exi_bitstream, &doc_decode)};
    if ( rr  == EXI_ERROR__NO_ERROR ) 
     cout << "Doc successfully decoded\n";
    else{
     cerr << "Failed to decode\n";
     return 2;
    }

    auto rrr{
        memcmp(&doc.BPT_Dynamic_DC_CLResControlMode,
               &doc_decode.BPT_Dynamic_DC_CLResControlMode,
               0)//sizeof(iso20_dc_exiDocument::BPT_Dynamic_DC_CLResControlMode))
        };
    cout << "doc.BPT_Dynamic_DC_CLResControlMode_isUsed = " << doc.BPT_Dynamic_DC_CLResControlMode_isUsed << '\n';
    cout << "doc.BPT_Dynamic_DC_CLResControlMode_isUsed = " << doc_decode.BPT_Dynamic_DC_CLResControlMode_isUsed << '\n';

    cout << "doc_decode.BPT_Dynamic_DC_CLResControlMode.DepartureTime = " <<    
             doc_decode.BPT_Dynamic_DC_CLResControlMode.DepartureTime << '\n';
    cout << "doc_decode.BPT_Dynamic_DC_CLResControlMode.DepartureTime_isUsed = " <<    
             doc_decode.BPT_Dynamic_DC_CLResControlMode.DepartureTime_isUsed << '\n';

    cout << "doc.BPT_Dynamic_DC_CLResControlMode.DepartureTime = " <<    
             doc.BPT_Dynamic_DC_CLResControlMode.DepartureTime << '\n';
    cout << "doc.BPT_Dynamic_DC_CLResControlMode.DepartureTime_isUsed = " <<    
             doc.BPT_Dynamic_DC_CLResControlMode.DepartureTime_isUsed << '\n';

    cout << "memcmp() = " << rrr << '\n';
    cout << sizeof(iso20_dc_exiDocument::BPT_Dynamic_DC_CLResControlMode) << '\n';
    if (rrr == 0) cout << "decode(encode(x)) == x\n";
    else cout << "decode(encode(x)) != x\n";

    return 0;
}