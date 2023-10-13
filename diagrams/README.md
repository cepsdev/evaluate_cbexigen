erDiagram
MessageHeaderType{
sessionIDType SessionID
unsignedLong TimeStamp
}
DisplayParametersType{
}
EVSEStatusType{
unsignedShort NotificationMaxDelay
evseNotificationType EVSENotification
}
RationalNumberType{
byte Exponent
short Value
}
MeterInfoType{
meterIDType MeterID
unsignedLong ChargedEnergyReadingWh
}
DetailedCostType{
RationalNumberType Amount
RationalNumberType CostPerUnit
}
DetailedTaxType{
numericIDType TaxRuleID
RationalNumberType Amount
}
ReceiptType{
unsignedLong TimeAnchor
}
ListOfRootCertificateIDsType{
}
