%ext_xsd
%ignore_ws
%%


lexer read_transitions{
 [ * ] --> ident => t{Initial;$6; };. 
 ident --> ident => t{ $0  ;  $4  ;};.
 ident --> [ * ] => t{$0;Final; };. 
 any => .
}

lexer read_complex_type{
 </xs:complexType> => exit.
 any => .   
}


BEGIN{
 <xs:complexType name=string> => 
 complexType{ 
    name{}; definition{call read_complex_type}; 
 };.
 any => .
}

%%