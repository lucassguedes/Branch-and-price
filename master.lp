\ENCODING=ISO-8859-1
\Problem name: IloCplex

Minimize
 obj1: 1000000 Lambda(1) + 1000000 Lambda(2) + 1000000 Lambda(3)
       + 1000000 Lambda(4) + 1000000 Lambda(5) + 1000000 Lambda(6)
       + 1000000 Lambda(7) + 1000000 Lambda(8) + 1000000 Lambda(9)
       + 1000000 Lambda(10) + 1000000 Lambda(11) + 1000000 Lambda(12)
       + 1000000 Lambda(13) + 1000000 Lambda(14) + 1000000 Lambda(15)
       + 1000000 Lambda(16) + 1000000 Lambda(17) + 1000000 Lambda(18)
       + 1000000 Lambda(19) + 1000000 Lambda(20) + 1000000 Lambda(21)
       + 1000000 Lambda(22) + 1000000 Lambda(23) + 1000000 Lambda(24)
       + 1000000 Lambda(25) + 1000000 Lambda(26) + 1000000 Lambda(27)
       + 1000000 Lambda(28) + 1000000 Lambda(29) + 1000000 Lambda(30)
       + 1000000 Lambda(31) + 1000000 Lambda(32) + 1000000 Lambda(33)
       + 1000000 Lambda(34) + 1000000 Lambda(35) + 1000000 Lambda(36)
       + 1000000 Lambda(37) + 1000000 Lambda(38) + 1000000 Lambda(39)
       + 1000000 Lambda(40) + 1000000 Lambda(41) + 1000000 Lambda(42)
       + 1000000 Lambda(43) + 1000000 Lambda(44) + 1000000 Lambda(45)
       + 1000000 Lambda(46) + 1000000 Lambda(47) + 1000000 Lambda(48)
       + 1000000 Lambda(49) + 1000000 Lambda(50) + Lambda(51) + Lambda(52)
       + Lambda(53) + Lambda(54) + Lambda(55) + Lambda(56) + Lambda(57)
       + Lambda(58) + Lambda(59) + Lambda(60) + Lambda(61) + Lambda(62)
       + Lambda(63) + Lambda(64) + Lambda(65)
Subject To
 UNIQUE_PATTERN(1):  Lambda(1)  = 1
 UNIQUE_PATTERN(2):  Lambda(2)  = 1
 UNIQUE_PATTERN(3):  Lambda(3)  = 1
 UNIQUE_PATTERN(4):  Lambda(4)  = 1
 UNIQUE_PATTERN(5):  Lambda(5)  = 1
 UNIQUE_PATTERN(6):  Lambda(6)  = 1
 UNIQUE_PATTERN(7):  Lambda(7)  = 1
 UNIQUE_PATTERN(8):  Lambda(8)  = 1
 UNIQUE_PATTERN(9):  Lambda(9)  = 1
 UNIQUE_PATTERN(10): Lambda(10)  = 1
 UNIQUE_PATTERN(11): Lambda(11)  = 1
 UNIQUE_PATTERN(12): Lambda(12)  = 1
 UNIQUE_PATTERN(13): Lambda(13)  = 1
 UNIQUE_PATTERN(14): Lambda(14)  = 1
 UNIQUE_PATTERN(15): Lambda(15)  = 1
 UNIQUE_PATTERN(16): Lambda(16)  = 1
 UNIQUE_PATTERN(17): Lambda(17)  = 1
 UNIQUE_PATTERN(18): Lambda(18)  = 1
 UNIQUE_PATTERN(19): Lambda(19)  = 1
 UNIQUE_PATTERN(20): Lambda(20)  = 1
 UNIQUE_PATTERN(21): Lambda(21)  = 1
 UNIQUE_PATTERN(22): Lambda(22)  = 1
 UNIQUE_PATTERN(23): Lambda(23)  = 1
 UNIQUE_PATTERN(24): Lambda(24)  = 1
 UNIQUE_PATTERN(25): Lambda(25)  = 1
 UNIQUE_PATTERN(26): Lambda(26)  = 1
 UNIQUE_PATTERN(27): Lambda(27)  = 1
 UNIQUE_PATTERN(28): Lambda(28)  = 1
 UNIQUE_PATTERN(29): Lambda(29)  = 1
 UNIQUE_PATTERN(30): Lambda(30)  = 1
 UNIQUE_PATTERN(31): Lambda(31)  = 1
 UNIQUE_PATTERN(32): Lambda(32)  = 1
 UNIQUE_PATTERN(33): Lambda(33)  = 1
 UNIQUE_PATTERN(34): Lambda(34)  = 1
 UNIQUE_PATTERN(35): Lambda(35)  = 1
 UNIQUE_PATTERN(36): Lambda(36)  = 1
 UNIQUE_PATTERN(37): Lambda(37)  = 1
 UNIQUE_PATTERN(38): Lambda(38)  = 1
 UNIQUE_PATTERN(39): Lambda(39)  = 1
 UNIQUE_PATTERN(40): Lambda(40)  = 1
 UNIQUE_PATTERN(41): Lambda(41)  = 1
 UNIQUE_PATTERN(42): Lambda(42) + Lambda(51) + Lambda(53) + Lambda(54)
                     + Lambda(55) + Lambda(56) + Lambda(57) + Lambda(58)
                     + Lambda(59) + Lambda(60) + Lambda(61) + Lambda(62)
                     + Lambda(63) + Lambda(64) + Lambda(65)  = 1
 UNIQUE_PATTERN(43): Lambda(43)  = 1
 UNIQUE_PATTERN(44): Lambda(44) + Lambda(51) + Lambda(52) + Lambda(54)
                     + Lambda(60) + Lambda(61)  = 1
 UNIQUE_PATTERN(45): Lambda(45) + Lambda(51) + Lambda(52) + Lambda(55)
                     + Lambda(60) + Lambda(63)  = 1
 UNIQUE_PATTERN(46): Lambda(46) + Lambda(51) + Lambda(52) + Lambda(57)
                     + Lambda(60) + Lambda(65)  = 1
 UNIQUE_PATTERN(47): Lambda(47) + Lambda(51) + Lambda(52) + Lambda(58)
                     + Lambda(60) + Lambda(64)  = 1
 UNIQUE_PATTERN(48): Lambda(48) + Lambda(51) + Lambda(52) + Lambda(59)
                     + Lambda(61) + Lambda(62) + Lambda(63) + Lambda(64)
                     + Lambda(65)  = 1
 UNIQUE_PATTERN(49): Lambda(49) + Lambda(51) + Lambda(52) + Lambda(56)
                     + Lambda(60) + Lambda(62)  = 1
 UNIQUE_PATTERN(50): Lambda(50) + Lambda(52) + Lambda(53) + Lambda(54)
                     + Lambda(55) + Lambda(56) + Lambda(57) + Lambda(58)
                     + Lambda(59) + Lambda(60) + Lambda(61) + Lambda(62)
                     + Lambda(63) + Lambda(64) + Lambda(65)  = 1
End
