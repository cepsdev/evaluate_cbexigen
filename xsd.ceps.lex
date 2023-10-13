%ext_xsd
%ignore_ws
%%


lexer read_transitions{
 [ * ] --> ident => t{Initial;$6; };. 
 ident --> ident => t{ $0  ;  $4  ;};.
 ident --> [ * ] => t{$0;Final; };. 
 any => .
}



lexer read_seq{
 </xs:sequence> => exit .
 <xs:element name=string type=string/> => element{name{$6;}; type{$9;};}; .
 any => .
}

lexer read_complex_type{
 </xs:complexType> => exit.
 <xs:sequence> => sequence{ call read_seq };.
 any => .   
}



BEGIN{
 <xs:complexType name=string> => 
 complexType{ 
    name{$6;}; definition{call read_complex_type}; 
 };.
 <xs:complexType name=string abstract="true"> => 
 complexTypeAbstract{ 
    name{$6;}; definition{call read_complex_type}; 
 };.
 any => .
}

%%