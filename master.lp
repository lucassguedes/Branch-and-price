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
       + Lambda(63) + Lambda(64) + Lambda(65) + Lambda(66) + Lambda(67)
       + Lambda(68) + Lambda(69) + Lambda(70) + Lambda(71) + Lambda(72)
       + Lambda(73) + Lambda(74) + Lambda(75) + Lambda(76) + Lambda(77)
       + Lambda(78) + Lambda(79) + Lambda(80) + Lambda(81) + Lambda(82)
       + Lambda(83) + Lambda(84) + Lambda(85) + Lambda(86) + Lambda(87)
       + Lambda(88) + Lambda(89) + Lambda(90) + Lambda(91) + Lambda(92)
       + Lambda(93) + Lambda(94) + Lambda(95) + Lambda(96) + Lambda(97)
       + Lambda(98) + Lambda(99) + Lambda(100) + Lambda(101) + Lambda(102)
       + Lambda(103) + Lambda(104) + Lambda(105) + Lambda(106) + Lambda(107)
       + Lambda(108) + Lambda(109) + Lambda(110) + Lambda(111) + Lambda(112)
       + Lambda(113) + Lambda(114) + Lambda(115) + Lambda(116) + Lambda(117)
       + Lambda(118) + Lambda(119) + Lambda(120) + Lambda(121) + Lambda(122)
       + Lambda(123) + Lambda(124) + Lambda(125) + Lambda(126) + Lambda(127)
       + Lambda(128) + Lambda(129) + Lambda(130) + Lambda(131) + Lambda(132)
       + Lambda(133) + Lambda(134) + Lambda(135) + Lambda(136) + Lambda(137)
       + Lambda(138) + Lambda(139) + Lambda(140) + Lambda(141) + Lambda(142)
       + Lambda(143) + Lambda(144) + Lambda(145) + Lambda(146) + Lambda(147)
       + Lambda(148) + Lambda(149) + Lambda(150) + Lambda(151) + Lambda(152)
       + Lambda(153) + Lambda(154) + Lambda(155) + Lambda(156) + Lambda(157)
       + Lambda(158) + Lambda(159) + Lambda(160) + Lambda(161) + Lambda(162)
       + Lambda(163) + Lambda(164) + Lambda(165) + Lambda(166) + Lambda(167)
       + Lambda(168) + Lambda(169) + Lambda(170) + Lambda(171) + Lambda(172)
       + Lambda(173) + Lambda(174) + Lambda(175) + Lambda(176) + Lambda(177)
       + Lambda(178) + Lambda(179) + Lambda(180) + Lambda(181) + Lambda(182)
       + Lambda(183) + Lambda(184) + Lambda(185) + Lambda(186) + Lambda(187)
       + Lambda(188) + Lambda(189) + Lambda(190) + Lambda(191)
Subject To
 UNIQUE_PATTERN(1):  Lambda(1) + Lambda(155) + Lambda(166)  = 1
 UNIQUE_PATTERN(2):  Lambda(2) + Lambda(147) + Lambda(164)  = 1
 UNIQUE_PATTERN(3):  Lambda(3) + Lambda(168)  = 1
 UNIQUE_PATTERN(4):  Lambda(4) + Lambda(169)  = 1
 UNIQUE_PATTERN(5):  Lambda(5) + Lambda(167)  = 1
 UNIQUE_PATTERN(6):  Lambda(6) + Lambda(176) + Lambda(177) + Lambda(178)
                     + Lambda(187)  = 1
 UNIQUE_PATTERN(7):  Lambda(7) + Lambda(173) + Lambda(175) + Lambda(191)  = 1
 UNIQUE_PATTERN(8):  Lambda(8) + Lambda(171) + Lambda(172) + Lambda(189)  = 1
 UNIQUE_PATTERN(9):  Lambda(9) + Lambda(160) + Lambda(161) + Lambda(190)  = 1
 UNIQUE_PATTERN(10): Lambda(10) + Lambda(153) + Lambda(159)  = 1
 UNIQUE_PATTERN(11): Lambda(11) + Lambda(145) + Lambda(152) + Lambda(188)  = 1
 UNIQUE_PATTERN(12): Lambda(12) + Lambda(137) + Lambda(138) + Lambda(139)
                     + Lambda(158)  = 1
 UNIQUE_PATTERN(13): Lambda(13) + Lambda(133) + Lambda(134) + Lambda(144)
                     + Lambda(186)  = 1
 UNIQUE_PATTERN(14): Lambda(14) + Lambda(130) + Lambda(132)  = 1
 UNIQUE_PATTERN(15): Lambda(15) + Lambda(120) + Lambda(129) + Lambda(181)  = 1
 UNIQUE_PATTERN(16): Lambda(16) + Lambda(126) + Lambda(127) + Lambda(142)
                     + Lambda(149) + Lambda(174)  = 1
 UNIQUE_PATTERN(17): Lambda(17) + Lambda(123) + Lambda(124) + Lambda(135)
                     + Lambda(141) + Lambda(150) + Lambda(156) + Lambda(184)
                      = 1
 UNIQUE_PATTERN(18): Lambda(18) + Lambda(117) + Lambda(118) + Lambda(146)
                     + Lambda(170)  = 1
 UNIQUE_PATTERN(19): Lambda(19) + Lambda(111) + Lambda(112) + Lambda(114)
                     + Lambda(125) + Lambda(140) + Lambda(165)  = 1
 UNIQUE_PATTERN(20): Lambda(20) + Lambda(106) + Lambda(108) + Lambda(131)  = 1
 UNIQUE_PATTERN(21): Lambda(21) + Lambda(107) + Lambda(109) + Lambda(110)
                     + Lambda(121) + Lambda(122) + Lambda(163)  = 1
 UNIQUE_PATTERN(22): Lambda(22) + Lambda(102) + Lambda(103) + Lambda(105)
                     + Lambda(143) + Lambda(182)  = 1
 UNIQUE_PATTERN(23): Lambda(23) + Lambda(97) + Lambda(98) + Lambda(100)
                     + Lambda(104) + Lambda(115) + Lambda(162) + Lambda(179)
                     + Lambda(183)  = 1
 UNIQUE_PATTERN(24): Lambda(24) + Lambda(93) + Lambda(94) + Lambda(95)
                     + Lambda(96) + Lambda(180) + Lambda(185)  = 1
 UNIQUE_PATTERN(25): Lambda(25) + Lambda(79) + Lambda(92) + Lambda(96)
                     + Lambda(151) + Lambda(185)  = 1
 UNIQUE_PATTERN(26): Lambda(26) + Lambda(86) + Lambda(91) + Lambda(92)
                     + Lambda(95)  = 1
 UNIQUE_PATTERN(27): Lambda(27) + Lambda(83) + Lambda(85) + Lambda(86)
                     + Lambda(113) + Lambda(119) + Lambda(148) + Lambda(151)
                     + Lambda(154) + Lambda(157) + Lambda(180)  = 1
 UNIQUE_PATTERN(28): Lambda(28) + Lambda(81) + Lambda(83) + Lambda(90)
                     + Lambda(116) + Lambda(122) + Lambda(179) + Lambda(182)
                      = 1
 UNIQUE_PATTERN(29): Lambda(29) + Lambda(80) + Lambda(81) + Lambda(84)
                     + Lambda(105) + Lambda(128)  = 1
 UNIQUE_PATTERN(30): Lambda(30) + Lambda(75) + Lambda(78) + Lambda(79)
                     + Lambda(99) + Lambda(115) + Lambda(163)  = 1
 UNIQUE_PATTERN(31): Lambda(31) + Lambda(73) + Lambda(75) + Lambda(86)
                     + Lambda(89) + Lambda(101) + Lambda(106) + Lambda(136)
                      = 1
 UNIQUE_PATTERN(32): Lambda(32) + Lambda(71) + Lambda(72) + Lambda(73)
                     + Lambda(76) + Lambda(88) + Lambda(119) + Lambda(128)
                     + Lambda(131) + Lambda(136) + Lambda(183)  = 1
 UNIQUE_PATTERN(33): Lambda(33) + Lambda(62) + Lambda(66) + Lambda(67)
                     + Lambda(68) + Lambda(69) + Lambda(70) + Lambda(71)
                     + Lambda(77) + Lambda(78) + Lambda(88) + Lambda(113)
                     + Lambda(140)  = 1
 UNIQUE_PATTERN(34): Lambda(34) + Lambda(60) + Lambda(62) + Lambda(63)
                     + Lambda(65) + Lambda(69) + Lambda(74) + Lambda(82)
                     + Lambda(85) + Lambda(90) + Lambda(110) + Lambda(120)
                     + Lambda(130)  = 1
 UNIQUE_PATTERN(35): Lambda(35) + Lambda(58) + Lambda(59) + Lambda(60)
                     + Lambda(61) + Lambda(74) + Lambda(76) + Lambda(77)
                     + Lambda(87) + Lambda(99) + Lambda(100) + Lambda(116)
                     + Lambda(127) + Lambda(132) + Lambda(146) + Lambda(148)
                     + Lambda(156)  = 1
 UNIQUE_PATTERN(36): Lambda(36) + Lambda(56) + Lambda(57) + Lambda(58)
                     + Lambda(59) + Lambda(63) + Lambda(64) + Lambda(77)
                     + Lambda(80) + Lambda(99) + Lambda(104) + Lambda(129)
                     + Lambda(184)  = 1
 UNIQUE_PATTERN(37): Lambda(37) + Lambda(54) + Lambda(55) + Lambda(56)
                     + Lambda(57) + Lambda(61) + Lambda(72) + Lambda(82)
                     + Lambda(91) + Lambda(94) + Lambda(101) + Lambda(116)
                     + Lambda(123) + Lambda(138) + Lambda(154) + Lambda(165)
                      = 1
 UNIQUE_PATTERN(38): Lambda(38) + Lambda(53) + Lambda(54) + Lambda(55)
                     + Lambda(65) + Lambda(66) + Lambda(70) + Lambda(74)
                     + Lambda(82) + Lambda(84) + Lambda(87) + Lambda(88)
                     + Lambda(97) + Lambda(109) + Lambda(117) + Lambda(125)
                     + Lambda(145) + Lambda(157)  = 1
 UNIQUE_PATTERN(39): Lambda(39) + Lambda(53) + Lambda(54) + Lambda(55)
                     + Lambda(64) + Lambda(68) + Lambda(69) + Lambda(80)
                     + Lambda(89) + Lambda(90) + Lambda(101) + Lambda(102)
                     + Lambda(107) + Lambda(112) + Lambda(124) + Lambda(126)
                     + Lambda(133) + Lambda(148) + Lambda(150) + Lambda(171)
                     + Lambda(177)  = 1
 UNIQUE_PATTERN(40): Lambda(40) + Lambda(52) + Lambda(53) + Lambda(57)
                     + Lambda(61) + Lambda(64) + Lambda(66) + Lambda(73)
                     + Lambda(87) + Lambda(89) + Lambda(93) + Lambda(98)
                     + Lambda(103) + Lambda(108) + Lambda(113) + Lambda(121)
                     + Lambda(139) + Lambda(147)  = 1
 UNIQUE_PATTERN(41): Lambda(41) + Lambda(51) + Lambda(53) + Lambda(57)
                     + Lambda(58) + Lambda(65) + Lambda(67) + Lambda(68)
                     + Lambda(72) + Lambda(76) + Lambda(81) + Lambda(93)
                     + Lambda(108) + Lambda(109) + Lambda(111) + Lambda(118)
                     + Lambda(135) + Lambda(142) + Lambda(149) + Lambda(161)
                     + Lambda(191)  = 1
 UNIQUE_PATTERN(42): Lambda(42) + Lambda(51) + Lambda(52) + Lambda(54)
                     + Lambda(59) + Lambda(60) + Lambda(63) + Lambda(67)
                     + Lambda(78) + Lambda(87) + Lambda(89) + Lambda(91)
                     + Lambda(93) + Lambda(94) + Lambda(98) + Lambda(114)
                     + Lambda(118) + Lambda(141) + Lambda(157) + Lambda(160)
                     + Lambda(162) + Lambda(166) + Lambda(173) + Lambda(189)
                      = 1
 UNIQUE_PATTERN(43): Lambda(43) + Lambda(51) + Lambda(52) + Lambda(56)
                     + Lambda(59) + Lambda(61) + Lambda(62) + Lambda(75)
                     + Lambda(84) + Lambda(85) + Lambda(102) + Lambda(111)
                     + Lambda(114) + Lambda(117) + Lambda(126) + Lambda(135)
                     + Lambda(136) + Lambda(152) + Lambda(157) + Lambda(158)
                     + Lambda(159) + Lambda(172) + Lambda(175) + Lambda(176)
                     + Lambda(181) + Lambda(188) + Lambda(190)  = 1
 UNIQUE_PATTERN(44): Lambda(44) + Lambda(51) + Lambda(52) + Lambda(55)
                     + Lambda(58) + Lambda(61) + Lambda(63) + Lambda(64)
                     + Lambda(65) + Lambda(67) + Lambda(68) + Lambda(70)
                     + Lambda(76) + Lambda(84) + Lambda(92) + Lambda(97)
                     + Lambda(103) + Lambda(112) + Lambda(128) + Lambda(134)
                     + Lambda(137) + Lambda(141) + Lambda(149) + Lambda(154)
                     + Lambda(155)  = 1
 UNIQUE_PATTERN(45): Lambda(45) + Lambda(51) + Lambda(52) + Lambda(56)
                     + Lambda(60) + Lambda(64) + Lambda(67) + Lambda(70)
                     + Lambda(71) + Lambda(79) + Lambda(82) + Lambda(84)
                     + Lambda(98) + Lambda(101) + Lambda(107) + Lambda(121)
                     + Lambda(125) + Lambda(137) + Lambda(143) + Lambda(144)
                     + Lambda(154)  = 1
 UNIQUE_PATTERN(46): Lambda(46) + Lambda(51) + Lambda(52) + Lambda(55)
                     + Lambda(58) + Lambda(62) + Lambda(63) + Lambda(66)
                     + Lambda(71) + Lambda(72) + Lambda(75) + Lambda(86)
                     + Lambda(87) + Lambda(100) + Lambda(103) + Lambda(107)
                     + Lambda(114) + Lambda(128) + Lambda(133) + Lambda(142)
                     + Lambda(146) + Lambda(151) + Lambda(175) + Lambda(181)
                      = 1
 UNIQUE_PATTERN(47): Lambda(47) + Lambda(51) + Lambda(52) + Lambda(56)
                     + Lambda(60) + Lambda(65) + Lambda(66) + Lambda(68)
                     + Lambda(72) + Lambda(74) + Lambda(78) + Lambda(83)
                     + Lambda(86) + Lambda(96) + Lambda(121) + Lambda(124)
                     + Lambda(134) + Lambda(152) + Lambda(158) + Lambda(159)
                     + Lambda(172) + Lambda(178)  = 1
 UNIQUE_PATTERN(48): Lambda(48) + Lambda(51) + Lambda(52) + Lambda(55)
                     + Lambda(57) + Lambda(59) + Lambda(60) + Lambda(62)
                     + Lambda(68) + Lambda(70) + Lambda(74) + Lambda(80)
                     + Lambda(83) + Lambda(87) + Lambda(89) + Lambda(91)
                     + Lambda(97) + Lambda(100) + Lambda(111) + Lambda(119)
                     + Lambda(121) + Lambda(123) + Lambda(139) + Lambda(148)
                     + Lambda(149) + Lambda(152) + Lambda(153) + Lambda(160)
                      = 1
 UNIQUE_PATTERN(49): Lambda(49) + Lambda(51) + Lambda(52) + Lambda(55)
                     + Lambda(58) + Lambda(62) + Lambda(64) + Lambda(65)
                     + Lambda(66) + Lambda(67) + Lambda(69) + Lambda(73)
                     + Lambda(79) + Lambda(97) + Lambda(102) + Lambda(108)
                     + Lambda(112) + Lambda(127) + Lambda(135) + Lambda(150)
                     + Lambda(152) + Lambda(157) + Lambda(158) + Lambda(159)
                     + Lambda(160) + Lambda(171) + Lambda(176) + Lambda(178)
                     + Lambda(181) + Lambda(184)  = 1
 UNIQUE_PATTERN(50): Lambda(50) + Lambda(51) + Lambda(52) + Lambda(54)
                     + Lambda(58) + Lambda(62) + Lambda(64) + Lambda(65)
                     + Lambda(68) + Lambda(70) + Lambda(71) + Lambda(74)
                     + Lambda(77) + Lambda(85) + Lambda(90) + Lambda(91)
                     + Lambda(93) + Lambda(109) + Lambda(111) + Lambda(114)
                     + Lambda(119) + Lambda(124) + Lambda(132) + Lambda(134)
                     + Lambda(137) + Lambda(142) + Lambda(145) + Lambda(160)
                     + Lambda(175) + Lambda(176) + Lambda(189) + Lambda(190)
                     + Lambda(191)  = 1
End
