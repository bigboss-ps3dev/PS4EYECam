/*
 *	PlayStation 4 Camera register list
 *	Copyright (C) 2013,2014 Antonio Jose Ramos Marquez (aka bigboss) @psxdev on twitter
 *
 *  Repository https://github.com/bigboss-ps3dev/PS4EYECam
 *
 *  Based on OV9713,AK5703 datasheets and PlayStation 4 Camera dumped firmware
 *  
 *  If someone has OV580 datasheet please contact with me on twitter
 *  
 *  This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public Licence as published by
 *	the Free Software Foundation; either version 2 of the Licence, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *	GNU General Public Licence for more details.
 *
 *	You should have received a copy of the GNU General Public Licence
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 *  If you redistribute this file in source form, modified or unmodified, you
 *  may:
 *  1) Leave this header intact and distribute it under the same terms,
 *  accompanying it with the GPL20 or later files, or
 *  In all cases you must keep the copyright notice intact
 *
 *  Binary distributions must follow the binary distribution requirements of
 *  license.
 *
 *
 */


/*OV9713 REGISTERS*/

/*General configuration and image size registers [0x0000-0x0387]*/
#define OV9713_MODE_SELECT                0x0100
#define OV9713_IMAGE_ORIENTATION          0x0101
#define OV9713_SOFTWARE_RESET             0x0103
#define OV9713_FAST_STANDBY_CTRL          0x0106
#define OV9713_CCI_ADDRESS_CONTROL_20     0x0107
#define OV9713_CCI_ADDRESS_CONTROL_6C     0x0108
#define OV9713_FRAME_LENGTH_LINES_HI      0x0340
#define OV9713_FRAME_LENGTH_LINES_LO      0x0341
#define OV9713_LINE_LENGTH_PCK_HI         0x0342
#define OV9713_LINE_LENGTH_PCK_LO         0x0343
#define OV9713_X_ADDR_START_HI            0x0344
#define OV9713_X_ADDR_START_LO            0x0345
#define OV9713_Y_ADDR_START_HI            0x0346
#define OV9713_Y_ADDR_START_LO            0x0347
#define OV9713_X_ADDR_END_HI              0x0348
#define OV9713_X_ADDR_END_LO              0x0349
#define OV9713_Y_ADDR_END_HI              0x034a
#define OV9713_Y_ADDR_END_LO              0x034b
#define OV9713_X_OUTPUT_SIZE_HI           0x034c
#define OV9713_X_OUTPUT_SIZE_LO           0x034d
#define OV9713_Y_OUTPUT_SIZE_HI           0x034e
#define OV9713_Y_OUTPUT_SIZE_LO           0x034f
#define OV9713_X_EVEN_INC                 0x0381
#define OV9713_X_ODD_INC                  0x0383
#define OV9713_Y_EVEN_INC                 0x0385
#define OV9713_Y_ODD_INC                  0x0387

/*System control [0x3001-0x30b8]*/
#define OV9713_PAD_CTRL                   0x3001
#define OV9713_PAD_OEN2                   0x3002
#define OV9713_PAD_OEN3                   0x3004
#define OV9713_PAD_OUT2                   0x3006
#define OV9713_PAD_OUT1                   0x3008
#define OV9713_PAD_OUT0                   0x3009
#define OV9713_CHIP_ID_HI                 0x300a
#define OV9713_CHIP_ID_LO                 0x300b
#define OV9713_SC_REG10                   0x3010
#define OV9713_SC_REG11                   0x3011
#define OV9713_A_MIPI_PK_1                0x3012
#define OV9713_A_MIPI_PK_2                0x3013
#define OV9713_MIPI_SC_O_1                0x3014
#define OV9713_MIPI_SC_O_2                0x3015
#define OV9713_CLK_RST_REG_0              0x3016
#define OV9713_CLK_RST_REG_1              0x3017
#define OV9713_CLK_RST_REG_2              0x3018
#define OV9713_CLK_RST_REG_3              0x3019
#define OV9713_CLK_RST_REG_4              0x301a
#define OV9713_CLK_RST_REG_5              0x301b
#define OV9713_CLK_RST_REG_6              0x301c
#define OV9713_CLK_RST_REG_7              0x301d
#define OV9713_CLK_RST_REG_8              0x301e
#define OV9713_MISC_CTRL                  0x301f
#define OV9713_MISC_CTRL1                 0x3020
#define OV9713_RSVD                       0x3022
#define OV9713_LOW_PWR_CTR                0x3023
#define OV9713_PAD_SEL2                   0x3024
#define OV9713_SC_REG25                   0x3025
#define OV9713_PAD_SEL1                   0x3026
#define OV9713_IO_Y_SEL_L                 0x3027
#define OV9713_SCCB_ID2                   0x302b
#define OV9713_AUTO_SLEEP_PERIOD_HI1      0x302c
#define OV9713_AUTO_SLEEP_PERIOD_HI0      0x302d
#define OV9713_AUTO_SLEEP_PERIOD_LO1      0x302e
#define OV9713_AUTO_SLEEP_PERIOD_LO0      0x302f
#define OV9713_SP_LP_CTRL0                0x3030
#define OV9713_PAD_OEN_SLEEP_2            0x3031
#define OV9713_PAD_OEN_SLEEP_1            0x3032
#define OV9713_RSVD_1                     0x3033
#define OV9713_PAD_OEN_PWDN_2             0x3034
#define OV9713_PAD_OEN_PWDN_1             0x3035
#define OV9713_RSVD_2                     0x3036
#define OV9713_CLKRST0                    0x3037
#define OV9713_FREX_RST_MASK0             0x3038
#define OV9713_SCREG3B                    0x303b
#define OV9713_CLKRST                     0x303f
#define OV9713_PLL_REG_0                  0x3081
#define OV9713_PLL_REG_1                  0x3082
#define OV9713_PLL_REG_2                  0x3083
#define OV9713_PLL_REG_3                  0x3084
#define OV9713_PLL10                      0x3090
#define OV9713_PLL11                      0x3091
#define OV9713_PLL12                      0x3092
#define OV9713_PLL13                      0x3093
#define OV9713_PLL14                      0x3094
#define OV9713_PLL_REG_5                  0x3095
#define OV9713_PLL_REG_6                  0x3096
#define OV9713_PLL_REG_7                  0x3097
#define OV9713_PLL_REG_8                  0x3098
#define OV9713_PLL_REG_9                  0x3099
#define OV9713_PLL1A                      0x309a
#define OV9713_PLL1B                      0x309b
#define OV9713_PLL1C                      0x309c
#define OV9713_PLL_REG_10                 0x309d
#define OV9713_PLL_REG_11                 0x309e
#define OV9713_PLL_REG_12                 0x309f
#define OV9713_PLL_REG_13                 0x30a0
#define OV9713_PLL_REG_14                 0x30a1
#define OV9713_PLL_REG_15                 0x30a2
#define OV9713_PLL23                      0x30a3
#define OV9713_PLL_REG_16                 0x30a4
#define OV9713_PLL25                      0x30a5
#define OV9713_PLL_MULTIPLIER_0           0x30b2
#define OV9713_PLL_MULTIPLIER_1           0x30b3
#define OV9713_PLL1_OP_PIX_CLK_DIV        0x30b5
#define OV9713_PLL1_OP_SYS_CLK_DIV        0x30b6
#define OV9713_PLL1_OP_2LINE_CLK_DIV      0x30b7
#define OV9713_PLL1_R_PREDIV              0x30b8

/*Group hold control registers [0x3200-0x320c]*/
#define OV9713_GROUP_ADDR0                0x3200
#define OV9713_GROUP_ADDR1                0x3201
#define OV9713_GROUP_ADDR2                0x3202
#define OV9713_GROUP_ADDR3                0x3203
#define OV9713_GROUP_LEN0                 0x3204
#define OV9713_GROUP_LEN1                 0x3205
#define OV9713_GROUP_LEN2                 0x3206
#define OV9713_GROUP_LEN3                 0x3207
#define OV9713_GROUP_ACCESS               0x3208
#define OV9713_GRP0_PERIOD                0x3209
#define OV9713_GRP1_PERIOD                0x320a
#define OV9713_GRP_SW_CTRL                0x320b
#define OV9713_SRAM_TEST                  0x320c

/*Manual AEC/AGC registers [0x3500-0x3a07, 0x5900-0x5910]*/
#define OV9713_EXPO0_HI                   0x3500
#define OV9713_EXPO0_ME                   0x3501
#define OV9713_EXPO0_LO                   0x3502
#define OV9713_AECPK_CTRL                 0x3503
#define OV9713_EXPO1_HI                   0x3504
#define OV9713_EXPO1_ME                   0x3505
#define OV9713_EXPO1_LO                   0x3506
#define OV9713_EXPO2_HI                   0x3507
#define OV9713_EXPO2_ME                   0x3508
#define OV9713_EXPO2_LO                   0x3509
#define OV9713_GAIN0_HI                   0x350a
#define OV9713_GAIN0_LO                   0x350b
#define OV9713_GAIN1_HI                   0x350c
#define OV9713_GAIN1_LO                   0x350d
#define OV9713_GAIN2_HI                   0x350e
#define OV9713_GAIN2_LO                   0x350f
#define OV9713_AEC_CTRL01                 0x3a01
#define OV9713_AEC_CTRL02                 0x3a02
#define OV9713_AEC_CTRL03                 0x3a03
#define OV9713_AEC_CTRL04                 0x3a04
#define OV9713_AEC_CTRL05                 0x3a05
#define OV9713_AEC_CTRL06                 0x3a06
#define OV9713_AEC_CTRL07                 0x3a07
#define OV9713_SUBWIN_XSTART_HI           0x5900
#define OV9713_SUBWIN_XSTART_LO           0x5901
#define OV9713_SUBWIN_YSTART_HI           0x5902
#define OV9713_SUBWIN_YSTART_LO           0x5903
#define OV9713_SUBWIN_HSIZE_HI            0x5904
#define OV9713_SUBWIN_HSIZE_LO            0x5905
#define OV9713_SUBWIN_VSIZE_HI            0x5906
#define OV9713_SUBWIN_VISIZE_LO           0x5907
#define OV9713_WEIGHT_001                 0x5908
#define OV9713_WEIGHT_023                 0x5909
#define OV9713_WEIGHT_101                 0x590a
#define OV9713_WEIGHT_123                 0x590b
#define OV9713_WEIGHT_201                 0x590c
#define OV9713_WEIGHT_223                 0x590d
#define OV9713_WEIGHT_301                 0x590e
#define OV9713_WEIGHT_323                 0x590f
#define OV9713_AGC_CTRL                   0x5910

/*Analog control registers [0x3600-0x3684]*/

#define OV9713_ANALOG_REGISTER0_0         0x3600
#define OV9713_ANALOG_REGISTER0_1         0x3601
#define OV9713_ANALOG_REGISTER0_2         0x3602
#define OV9713_ANALOG_REGISTER0_3         0x3603
#define OV9713_ANALOG_REGISTER0_4         0x3604
#define OV9713_ANALOG_REGISTER0_5         0x3605
#define OV9713_ANALOG_REGISTER0_6         0x3606
#define OV9713_ANALOG_REGISTER0_7         0x3607
#define OV9713_ANALOG_REGISTER0_8         0x3608
#define OV9713_ANALOG_REGISTER0_9         0x3609
#define OV9713_ANALOG_REGISTER0_10        0x360a
#define OV9713_ANALOG_REGISTER0_11        0x360b
#define OV9713_ANALOG_REGISTER0_12        0x360c
#define OV9713_ANALOG_REGISTER0_13        0x360d
#define OV9713_ANALOG_REGISTER0_14        0x360e
#define OV9713_ANALOG_REGISTER0_15        0x360f
#define OV9713_ANALOG_REGISTER1_0         0x3610
#define OV9713_ANALOG_REGISTER1_1         0x3611
#define OV9713_ANALOG_REGISTER1_2         0x3612
#define OV9713_ANALOG_REGISTER1_3         0x3613
#define OV9713_ANALOG_REGISTER1_4         0x3614
#define OV9713_ANALOG_REGISTER1_5         0x3615
#define OV9713_ANALOG_REGISTER1_6         0x3616
#define OV9713_ANALOG_REGISTER1_7         0x3617
#define OV9713_ANALOG_REGISTER1_8         0x3618
#define OV9713_ANALOG_REGISTER1_9         0x3619
#define OV9713_ANALOG_REGISTER1_10        0x361a
#define OV9713_ANALOG_REGISTER1_11        0x361b
#define OV9713_ANALOG_REGISTER1_12        0x361c
#define OV9713_ANALOG_REGISTER1_13        0x361d
#define OV9713_ANALOG_REGISTER1_14        0x361e
#define OV9713_ANALOG_REGISTER1_15        0x361f
#define OV9713_ANALOG_REGISTER2_0         0x3620
#define OV9713_ANALOG_REGISTER2_1         0x3621
#define OV9713_ANALOG_REGISTER2_2         0x3622
#define OV9713_ANALOG_REGISTER2_3         0x3623
#define OV9713_ANALOG_REGISTER2_4         0x3624
#define OV9713_ANALOG_REGISTER2_5         0x3625
#define OV9713_ANALOG_REGISTER2_6         0x3626
#define OV9713_ANALOG_REGISTER2_7         0x3627
#define OV9713_ANALOG_REGISTER2_8         0x3628
#define OV9713_ANALOG_REGISTER2_9         0x3629
#define OV9713_ANALOG_REGISTER2_10        0x362a
#define OV9713_ANALOG_REGISTER2_11        0x362b
#define OV9713_ANALOG_REGISTER2_12        0x362c
#define OV9713_ANALOG_REGISTER2_13        0x362d
#define OV9713_ANALOG_REGISTER2_14        0x362e
#define OV9713_ANALOG_REGISTER2_15        0x362f
#define OV9713_ANALOG_REGISTER3_0         0x3630
#define OV9713_ANALOG_REGISTER3_1         0x3631
#define OV9713_ANALOG_REGISTER3_2         0x3632
#define OV9713_ANALOG_REGISTER3_3         0x3633
#define OV9713_ANALOG_REGISTER3_4         0x3634
#define OV9713_ANALOG_REGISTER3_5         0x3635
#define OV9713_PWC_6                      0x3636
#define OV9713_ANALOG_REGISTER3_7         0x3637
#define OV9713_ANALOG_REGISTER3_8         0x3638
#define OV9713_ANALOG_REGISTER3_9         0x3639
#define OV9713_ANALOG_REGISTER3_10        0x363a
#define OV9713_ANALOG_REGISTER3_11        0x363b
#define OV9713_ANALOG_REGISTER3_12        0x363c
#define OV9713_ANALOG_REGISTER3_13        0x363d
#define OV9713_ANALOG_REGISTER3_14        0x363e
#define OV9713_ANALOG_REGISTER3_15        0x363f
#define OV9713_ANALOG_REGISTER4_0         0x3640
#define OV9713_ANALOG_REGISTER4_1         0x3641
#define OV9713_ANALOG_REGISTER4_2         0x3642
#define OV9713_ANALOG_REGISTER4_3         0x3643
#define OV9713_ANALOG_REGISTER4_4         0x3644
#define OV9713_ANALOG_REGISTER4_5         0x3645
#define OV9713_ANALOG_REGISTER4_6         0x3646
#define OV9713_ANALOG_REGISTER4_7         0x3647
#define OV9713_ANALOG_REGISTER4_8         0x3648
#define OV9713_ANALOG_REGISTER4_9         0x3649
#define OV9713_ANALOG_REGISTER4_10        0x364a
#define OV9713_ANALOG_REGISTER4_11        0x364b
#define OV9713_ANALOG_REGISTER4_12        0x364c
#define OV9713_ANALOG_REGISTER4_13        0x364d
#define OV9713_ANALOG_REGISTER4_14        0x364e
#define OV9713_ANALOG_REGISTER4_15        0x364f
#define OV9713_ANALOG_REGISTER5_0         0x3650
#define OV9713_ANALOG_REGISTER5_1         0x3651
#define OV9713_ANALOG_REGISTER5_2         0x3652
#define OV9713_ANALOG_REGISTER5_3         0x3653
#define OV9713_ANALOG_REGISTER5_4         0x3654
#define OV9713_ANALOG_REGISTER5_5         0x3655
#define OV9713_ANALOG_REGISTER5_6         0x3656
#define OV9713_ANALOG_REGISTER5_7         0x3657
#define OV9713_ANALOG_REGISTER5_8         0x3658
#define OV9713_ANALOG_REGISTER5_9         0x3659
#define OV9713_ANALOG_REGISTER5_10        0x365a
#define OV9713_ANALOG_REGISTER5_11        0x365b
#define OV9713_ANALOG_REGISTER5_12        0x365c
#define OV9713_ANALOG_REGISTER5_13        0x365d
#define OV9713_ANALOG_REGISTER5_14        0x365e
#define OV9713_ANALOG_REGISTER5_15        0x365f
#define OV9713_ANALOG_REGISTER6_0         0x3660
#define OV9713_ANALOG_REGISTER6_1         0x3661
#define OV9713_ANALOG_REGISTER6_2         0x3662
#define OV9713_ANALOG_REGISTER6_3         0x3663
#define OV9713_ANALOG_REGISTER6_4         0x3664
#define OV9713_ANALOG_REGISTER6_5         0x3665
#define OV9713_ANALOG_REGISTER6_6         0x3666
#define OV9713_CORE_7                     0x3667
#define OV9713_ANALOG_REGISTER6_8         0x3668
#define OV9713_ANALOG_REGISTER6_9         0x3669
#define OV9713_ANALOG_REGISTER6_10        0x366a
#define OV9713_ANALOG_REGISTER6_11        0x366b
#define OV9713_ANALOG_REGISTER6_12        0x366c
#define OV9713_ANALOG_REGISTER6_13        0x366d
#define OV9713_ANALOG_REGISTER6_14        0x366e
#define OV9713_ANALOG_REGISTER6_15        0x366f
#define OV9713_ANALOG_REGISTER7_0         0x3670
#define OV9713_ANALOG_REGISTER7_1         0x3671
#define OV9713_ANALOG_REGISTER7_2         0x3672
#define OV9713_ANALOG_REGISTER7_3         0x3673
#define OV9713_ANALOG_REGISTER7_4         0x3674
#define OV9713_ANALOG_REGISTER7_5         0x3675
#define OV9713_ANALOG_REGISTER7_6         0x3676
#define OV9713_ANALOG_REGISTER7_7         0x3677
#define OV9713_ANALOG_REGISTER7_8         0x3678
#define OV9713_ANALOG_REGISTER7_9         0x3679
#define OV9713_ANALOG_REGISTER7_10        0x367a
#define OV9713_ANALOG_REGISTER7_11        0x367b
#define OV9713_ANALOG_REGISTER7_12        0x367c
#define OV9713_ANALOG_REGISTER7_13        0x367d
#define OV9713_ANALOG_REGISTER7_14        0x367e
#define OV9713_ANALOG_REGISTER7_15        0x367f
#define OV9713_ANALOG_REGISTER8_0         0x3680
#define OV9713_ANALOG_REGISTER8_1         0x3681
#define OV9713_ANALOG_REGISTER8_2         0x3682
#define OV9713_ANALOG_REGISTER8_3         0x3683
#define OV9713_ANALOG_REGISTER8_4         0x3684

/*Sensor control registers [0x3700-0x374b]*/
#define OV9713_SENSOR_CTRL_REGISTER0_0    0x3700
#define OV9713_SENSOR_CTRL_REGISTER0_1    0x3701
#define OV9713_SENSOR_CTRL_REGISTER0_2    0x3702
#define OV9713_SENSOR_CTRL_REGISTER0_3    0x3703
#define OV9713_SENSOR_CTRL_REGISTER0_4    0x3704
#define OV9713_SENSOR_CTRL_REGISTER0_5    0x3705
#define OV9713_SENSOR_CTRL_REGISTER0_6    0x3706
#define OV9713_SENSOR_CTRL_REGISTER0_7    0x3707
#define OV9713_SENSOR_CTRL_REGISTER0_8    0x3708
#define OV9713_SENSOR_CTRL_REGISTER0_9    0x3709
#define OV9713_SENSOR_CTRL_REGISTER0_10   0x370a
#define OV9713_SENSOR_CTRL_REGISTER0_11   0x370b
#define OV9713_SENSOR_CTRL_REGISTER0_12   0x370c
#define OV9713_SENSOR_CTRL_REGISTER0_13   0x370d
#define OV9713_SENSOR_CTRL_REGISTER0_14   0x370e
#define OV9713_SENSOR_CTRL_REGISTER0_15   0x370f
#define OV9713_SENSOR_CTRL_REGISTER1_0    0x3710
#define OV9713_SENSOR_CTRL_REGISTER1_1    0x3711
#define OV9713_SENSOR_CTRL_REGISTER1_2    0x3712
#define OV9713_SENSOR_CTRL_REGISTER1_3    0x3713
#define OV9713_SENSOR_CTRL_REGISTER1_4    0x3714
#define OV9713_SENSOR_CTRL_REGISTER1_5    0x3715
#define OV9713_SENSOR_CTRL_REGISTER1_6    0x3716
#define OV9713_SENSOR_CTRL_REGISTER1_7    0x3717
#define OV9713_SENSOR_CTRL_REGISTER1_8    0x3718
#define OV9713_SENSOR_CTRL_REGISTER1_9    0x3719
#define OV9713_SENSOR_CTRL_REGISTER1_10   0x371a
#define OV9713_SENSOR_CTRL_REGISTER1_11   0x371b
#define OV9713_SENSOR_CTRL_REGISTER1_12   0x371c
#define OV9713_SENSOR_CTRL_REGISTER1_13   0x371d
#define OV9713_SENSOR_CTRL_REGISTER1_14   0x371e
#define OV9713_SENSOR_CTRL_REGISTER1_15   0x371f
#define OV9713_SENSOR_CTRL_REGISTER2_0    0x3720
#define OV9713_SENSOR_CTRL_REGISTER2_1    0x3721
#define OV9713_SENSOR_CTRL_REGISTER2_2    0x3722
#define OV9713_SENSOR_CTRL_REGISTER2_3    0x3723
#define OV9713_SENSOR_CTRL_REGISTER2_4    0x3724
#define OV9713_SENSOR_CTRL_REGISTER2_5    0x3725
#define OV9713_SENSOR_CTRL_REGISTER2_6    0x3726
#define OV9713_SENSOR_CTRL_REGISTER2_7    0x3727
#define OV9713_SENSOR_CTRL_REGISTER2_8    0x3728
#define OV9713_SENSOR_CTRL_REGISTER2_9    0x3729
#define OV9713_SENSOR_CTRL_REGISTER2_10   0x372a
#define OV9713_SENSOR_CTRL_REGISTER2_11   0x372b
#define OV9713_SENSOR_CTRL_REGISTER2_12   0x372c
#define OV9713_SENSOR_CTRL_REGISTER2_13   0x372d
#define OV9713_SENSOR_CTRL_REGISTER2_14   0x372e
#define OV9713_SENSOR_CTRL_REGISTER2_15   0x372f
#define OV9713_SENSOR_CTRL_REGISTER3_0    0x3730
#define OV9713_SENSOR_CTRL_REGISTER3_1    0x3731
#define OV9713_SENSOR_CTRL_REGISTER3_2    0x3732
#define OV9713_SENSOR_CTRL_REGISTER3_3    0x3733
#define OV9713_SENSOR_CTRL_REGISTER3_4    0x3734
#define OV9713_SENSOR_CTRL_REGISTER3_5    0x3735
#define OV9713_SENSOR_CTRL_REGISTER3_6    0x3736
#define OV9713_SENSOR_CTRL_REGISTER3_7    0x3737
#define OV9713_SENSOR_CTRL_REGISTER3_8    0x3738
#define OV9713_SENSOR_CTRL_REGISTER3_9    0x3739
#define OV9713_SENSOR_CTRL_REGISTER3_10   0x373a
#define OV9713_SENSOR_CTRL_REGISTER3_11   0x373b
#define OV9713_SENSOR_CTRL_REGISTER3_12   0x373c
#define OV9713_SENSOR_CTRL_REGISTER3_13   0x373d
#define OV9713_SENSOR_CTRL_REGISTER3_14   0x373e
#define OV9713_SENSOR_CTRL_REGISTER3_15   0x373f
#define OV9713_SENSOR_CTRL_REGISTER4_0    0x3740
#define OV9713_SENSOR_CTRL_REGISTER4_1    0x3741
#define OV9713_SENSOR_CTRL_REGISTER4_2    0x3742
#define OV9713_SENSOR_CTRL_REGISTER4_3    0x3743
#define OV9713_SENSOR_CTRL_REGISTER4_4    0x3744
#define OV9713_SENSOR_CTRL_REGISTER4_5    0x3745
#define OV9713_SENSOR_CTRL_REGISTER4_6    0x3746
#define OV9713_SENSOR_CTRL_REGISTER4_7    0x3747
#define OV9713_SENSOR_CTRL_REGISTER4_8    0x3748
#define OV9713_SENSOR_CTRL_REGISTER4_9    0x3749
#define OV9713_SENSOR_CTRL_REGISTER4_10   0x374a
#define OV9713_SENSOR_CTRL_REGISTER4_11   0x374b

/*Timing control registers [0x3800-0x3832]*/
#define OV9713_TIMING_CTRL_REGISTER0_0    0x3800
#define OV9713_TIMING_CTRL_REGISTER0_1    0x3801
#define OV9713_TIMING_CTRL_REGISTER0_2    0x3802
#define OV9713_TIMING_CTRL_REGISTER0_3    0x3803
#define OV9713_TIMING_CTRL_REGISTER0_4    0x3804
#define OV9713_TIMING_CTRL_REGISTER0_5    0x3805
#define OV9713_TIMING_CTRL_REGISTER0_6    0x3806
#define OV9713_TIMING_CTRL_REGISTER0_7    0x3807
#define OV9713_TIMING_CTRL_REGISTER0_8    0x3808
#define OV9713_TIMING_CTRL_REGISTER0_9    0x3809
#define OV9713_TIMING_CTRL_REGISTER0_10   0x380a
#define OV9713_TIMING_CTRL_REGISTER0_11   0x380b
#define OV9713_TIMING_CTRL_REGISTER0_12   0x380c
#define OV9713_TIMING_CTRL_REGISTER0_13   0x380d
#define OV9713_TIMING_CTRL_REGISTER0_14   0x380e
#define OV9713_TIMING_CTRL_REGISTER0_15   0x380f
#define OV9713_TIMING_CTRL_REGISTER1_0    0x3810
#define OV9713_TIMING_CTRL_REGISTER1_1    0x3811
#define OV9713_TIMING_CTRL_REGISTER1_2    0x3812
#define OV9713_TIMING_CTRL_REGISTER1_3    0x3813
#define OV9713_TIMING_CTRL_REGISTER1_4    0x3814
#define OV9713_TIMING_CTRL_REGISTER1_5    0x3815
#define OV9713_TIMING_CTRL_REGISTER1_6    0x3816
#define OV9713_TIMING_CTRL_REGISTER1_7    0x3817
#define OV9713_TIMING_CTRL_REGISTER1_8    0x3818
#define OV9713_TIMING_CTRL_REGISTER1_9    0x3819
#define OV9713_TIMING_CTRL_REGISTER1_10   0x381a
#define OV9713_TIMING_CTRL_REGISTER1_11   0x381b
#define OV9713_TIMING_CTRL_REGISTER1_12   0x381c
#define OV9713_TIMING_CTRL_REGISTER1_13   0x381d
#define OV9713_TIMING_CTRL_REGISTER1_14   0x381e
#define OV9713_TIMING_CTRL_REGISTER1_15   0x381f
#define OV9713_TIMING_CTRL_REGISTER2_0    0x3820
#define OV9713_TIMING_CTRL_REGISTER2_1    0x3821
#define OV9713_TIMING_CTRL_REGISTER2_2    0x3822
#define OV9713_REG23                      0x3823
#define OV9713_CS_RST_FSIN_HI             0x3824
#define OV9713_CS_RST_FSIN_LO             0x3825
#define OV9713_RS_RST_FSIN_HI             0x3826
#define OV9713_RS_RST_FSIN_LO             0x3827
#define OV9713_TIMING_CTRL_REGISTER2_8    0x3828
#define OV9713_TIMING_CTRL_REGISTER2_9    0x3829
#define OV9713_TIMING_CTRL_REGISTER2_10   0x382a
#define OV9713_TIMING_CTRL_REGISTER2_11   0x382b
#define OV9713_TIMING_CTRL_REGISTER2_12   0x382c
#define OV9713_TIMING_CTRL_REGISTER2_13   0x382d
#define OV9713_TIMING_CTRL_REGISTER2_14   0x382e
#define OV9713_TIMING_CTRL_REGISTER2_15   0x382f
#define OV9713_TIMING_CTRL_REGISTER3_0    0x3830
#define OV9713_TIMING_CTRL_REGISTER3_1    0x3831
#define OV9713_TIMING_CTRL_REGISTER3_2    0x3832

/*Strobe control registers [0x3b00-0x3b05]*/
#define OV9713_RSTRB                      0x3b00
#define OV9713_STROBE_ADD_DUMMY_HI        0x3b02
#define OV9713_STROBE_ADD_DUMMY_LO        0x3b03
#define OV9713_STROBE_CTL1                0x3b04
#define OV9713_STROBE_WIDTH               0x3b05

/*OTP control registers [0x3d80-0x3d87]*/
#define OV9713_OTP_PGM_CTR                0x3d80
#define OV9713_OTP_LOAD_CTR               0x3d81
#define OV9713_OTP_PGM_PULSE              0x3d82
#define OV9713_OTP_LOAD_PULSE             0x3d83
#define OV9713_OTP_MODE_CTRL              0x3d84
#define OV9713_OTP_START_ADDRESS          0x3d85
#define OV9713_OTP_END_ADDRESS            0x3d86
#define OV9713_OTP_PS2_CS                 0x3d87

/*Frame control registers [0x4240-0x4243]*/
#define OV9713_ISP_FRAME_CTRL0            0x4240
#define OV9713_ISP_FRAME_ON_NUMBER        0x4241
#define OV9713_ISP_FRAME_OFF_NUMBER       0x4242
#define OV9713_ISP_FRAME_CTRL1            0x4243

/*Format control registers [0x4300-0x4316]*/
#define OV9713_CLIP_MAX_HI                0x4300
#define OV9713_CLIP_MIN_HI                0x4301
#define OV9713_CLIP_LO                    0x4302
#define OV9713_FORMAT_CTRL3_0             0x4303
#define OV9713_FORMAT_CTRL3_1             0x4304
#define OV9713_FORMAT_CTRL3_2             0x4305
#define OV9713_FORMAT_CTRL3_3             0x4306
#define OV9713_EMBED_CTRL                 0x4307
#define OV9713_TST_X_START_HIGH           0x4308
#define OV9713_TST_X_START_LOW            0x4309
#define OV9713_TST_Y_START_HIGH           0x430a
#define OV9713_TST_Y_START_LOW            0x430b
#define OV9713_TST_WIDTH_START_HIGH       0x430c
#define OV9713_TST_WIDTH_START_LOW        0x430d
#define OV9713_TST_HIGHT_START_HIGH       0x430e
#define OV9713_TST_HIGHT_START_LOW        0x430f
#define OV9713_FORMAT_RSVD                0x4310
#define OV9713_FORMAT_REG11               0x4311
#define OV9713_FORMAT_REG12               0x4312
#define OV9713_FORMAT_REG13               0x4313
#define OV9713_FORMAT_REG14               0x4314
#define OV9713_FORMAT_REG15               0x4315
#define OV9713_FORMAT_REG16               0x4316

/*VFIFO control registers [0x4500-0x460f]*/
#define OV9713_DEBUG_MODE_0               0x4500
#define OV9713_DEBUG_MODE_1               0x4501
#define OV9713_DEBUG_MODE_2               0x4502
#define OV9713_PSYNC_CTRL_13              0x4513
/* OV9713_DEBUG_MODE 0x4514-0x4607*/
#define OV9713_R_VFIFO_READ_START_HI      0x4600
#define OV9713_R_VFIFO_READ_START_LO      0x4601
#define OV9713_R2                         0x4602
#define OV9713_READ_START_H               0x4608
#define OV9713_READ_START_L               0x4609
#define OV9713_HSYNC_START_H              0x460a
#define OV9713_HSYNC_START_L              0x460b
#define OV9713_HSYNC_CTRL                 0x460c
#define OV9713_SRAM_TEST1                 0x460d
#define OV9713_MIPI_MODE2                 0x460e
#define OV9713_IR_DETC_CTRL               0x460f

/*MIPI control registers [0x4800-0x484f]*/
#define OV9713_MIPI_CTRL_00               0x4800
#define OV9713_MIPI_CTRL_01               0x4801
#define OV9713_MIPI_CTRL_02               0x4802
#define OV9713_MIPI_CTRL_04               0x4804
#define OV9713_MIPI_CTRL_05               0x4805
#define OV9713_MIPI_CTRL_07               0x4807
#define OV9713_MIPI_CTRL_08               0x4808
#define OV9713_FCNT_MAX_HI                0x4810
#define OV9713_FCNT_MAX_LO                0x4811
#define OV9713_MIPI_CTRL_13               0x4813
#define OV9713_MIPI_CTRL_14               0x4814
#define OV9713_MIPI_CTRL_15               0x4815
#define OV9713_EMB_DT                     0x4816
#define OV9713_YUV420_FUN                 0x4817
#define OV9713_HS_ZERO_MIN_HI             0x4818
#define OV9713_HS_ZERO_MIN_LO             0x4819
#define OV9713_HS_TRAIL_MIN_HI            0x481a
#define OV9713_HS_TRAIL_MIN_LO            0x481b
#define OV9713_CLK_ZERO_MIN_HI            0x481c
#define OV9713_CLK_ZERO_MIN_LO            0x481d
#define OV9713_CLK_PREPARE_MAX            0x481e
#define OV9713_CLK_PREPARE_MIN            0x481f
#define OV9713_CLK_POST_MIN_HI            0x4820
#define OV9713_CLK_POST_MIN_LO            0x4821
#define OV9713_CLK_TRAIL_MIN_HI           0x4822
#define OV9713_CLK_TRAIL_MIN_LO           0x4823
#define OV9713_CLK_LPX_P_MIN_HI           0x4824
#define OV9713_CLK_LPX_P_MIN_LO           0x4825
#define OV9713_HS_PREPARE_MIN             0x4826
#define OV9713_HS_PREPARE_MAX             0x4827
#define OV9713_HS_EXIT_MIN_HI             0x4828
#define OV9713_HS_EXIT_MIN_LO             0x4829
#define OV9713_UI_HS_ZERO_MIN             0x482a
#define OV9713_UI_HS_TRAIL_MIN            0x482b
#define OV9713_UI_CLK_ZERO_MIN            0x482c
#define OV9713_UI_CLK_PREPARE             0x482d
#define OV9713_UI_CLK_POST_MIN            0x482e
#define OV9713_UI_CLK_TRAIL_MIN           0x482f
#define OV9713_UI_LPX_P_MIN               0x4830
#define OV9713_UI_HS_PREPARE              0x4831
#define OV9713_UI_HS_EXIT_MIN             0x4832
#define OV9713_PCLK_PERIOD                0x4837
#define OV9713_MIPI_LP_GPIO_0             0x4838
#define OV9713_MIPI_LP_GPIO_1             0x4848
#define OV9713_MIPI_LP_GPIO_2             0x483a
#define OV9713_MIPI_LP_GPIO_3             0x483b
#define OV9713_MIPI_CTRL3C                0x483c
#define OV9713_MIPI_LP_GPIO_4             0x483d
#define OV9713_SEL_MIPI_CTRL4A            0x484a
#define OV9713_SEL_MIPI_CTRL4C            0x484c
#define OV9713_TEST_PATTEN_DATA           0x484d
#define OV9713_FE_DLY                     0x484e
#define OV9713_TEST_PATTEN_CK_DATA        0x484f

/*LVDS top control registers [0x4a00-0x4a0f]*/
#define OV9713_LVDS_R0                    0x4a00
#define OV9713_LVDS_DUMMY_DATA0_HI        0x4a02
#define OV9713_LVDS_DUMMY_DATA0_LO        0x4a03
#define OV9713_LVDS_DUMMY_DATA1_HI        0x4a04
#define OV9713_LVDS_DUMMY_DATA1_LO        0x4a05
#define OV9713_LVDS_R6                    0x4a06
#define OV9713_LVDS_R7                    0x4a07
#define OV9713_LVDS_R8                    0x4a08
#define OV9713_LVDS_R9                    0x4a09
#define OV9713_LVDS_RA                    0x4a0a
#define OV9713_LVDS_BLK_TIMES_HI          0x4a0c
#define OV9713_LVDS_BLK_TIMES_LO          0x4a0d
#define OV9713_LVDS_HTS_MAN_HI            0x4a0e
#define OV9713_LVDS_HTS_MAN_LO            0x4a0f

/*Frame HDR control registers [0x4580-0x4587]*/
#define OV9713_HDR_FRAME_REG0             0x4580
#define OV9713_HDR_FRAME_REG1             0x4581
#define OV9713_HDR_FRAME_REG2             0x4582
#define OV9713_HDR_FRAME_REG3             0x4583
#define OV9713_HDR_FRAME_REG4             0x4584
#define OV9713_HDR_FRAME_REG5             0x4585
#define OV9713_HDR_FRAME_REG6             0x4586
#define OV9713_HDR_FRAME_REG7             0x4587

/*BLC control registers [0x4000-0x401e]*/
#define OV9713_BLC_CTRL0                  0x4000
#define OV9713_START_LINE                 0x4001
#define OV9713_BLC_CTRL2                  0x4002
#define OV9713_BLC_CTRL3                  0x4003
#define OV9713_LINE_NUM                   0x4004
#define OV9713_BLC_CTRL5                  0x4005
#define OV9713_BLC_CTRL7                  0x4007
#define OV9713_BLC_TARGET_HI              0x4008
#define OV9713_BLC_TARGET_LO              0x4009
#define OV9713_BLC_REG_0c                 0x400c
#define OV9713_BLC_REG_0d                 0x400d
#define OV9713_BLC_REG_0e                 0x400e
#define OV9713_BLC_REG_0f                 0x400f
#define OV9713_BLC_REG_10                 0x4010
#define OV9713_BLC_REG_11                 0x4011
#define OV9713_BLC_REG_12                 0x4012
#define OV9713_BLC_REG_13                 0x4013
#define OV9713_BLC_REG_14                 0x4014
#define OV9713_BLC_REG_15                 0x4015
#define OV9713_BLC_REG_16                 0x4016
#define OV9713_BLC_REG_17                 0x4017
#define OV9713_BLC_REG_18                 0x4018
#define OV9713_BLC_REG_19                 0x4019
#define OV9713_BLC_REG_1a                 0x401a
#define OV9713_BLC_REG_1b                 0x401b
#define OV9713_BLC_REG_1c                 0x401c
#define OV9713_STABLE_RANGE               0x401d
#define OV9713_BLC_DEBUG_MODE             0x401e

/*Window control registers [0x5a00-0x5a2f]*/
#define OV9713_XSTART_MAN_HI              0x5a00
#define OV9713_XSTART_MAN_LO              0x5a01
#define OV9713_YSTART_MAN_HI              0x5a02
#define OV9713_YSTART_MAN_LO              0x5a03
#define OV9713_XWIN_MAN_HI                0x5a04
#define OV9713_XWIN_MAN_LO                0x5a05
#define OV9713_YWIN_MAN_HI                0x5a06
#define OV9713_YWIN_MAN_LO                0x5a07
#define OV9713_WINC_CTRL                  0x5a08
#define OV9713_WIN16_XSTART0_HI           0x5a10
#define OV9713_WIN16_XSTART0_LO           0x5a11
#define OV9713_WIN16_XSTART1_HI           0x5a12
#define OV9713_WIN16_XSTART1_LO           0x5a13
#define OV9713_WIN16_XSTART2_HI           0x5a14
#define OV9713_WIN16_XSTART2_LO           0x5a15
#define OV9713_WIN16_XSTART3_HI           0x5a16
#define OV9713_WIN16_XSTART3_LO           0x5a17
#define OV9713_WIN16_YSTART0_HI           0x5a18
#define OV9713_WIN16_YSTART0_LO           0x5a19
#define OV9713_WIN16_YSTART1_HI           0x5a1a
#define OV9713_WIN16_YSTART1_LO           0x5a1b
#define OV9713_WIN16_YSTART2_HI           0x5a1c
#define OV9713_WIN16_YSTART2_LO           0x5a1d
#define OV9713_WIN16_YSTART3_HI           0x5a1e
#define OV9713_WIN16_YSTART3_LO           0x5a1f
#define OV9713_WIN16_XWIN0_HI             0x5a20
#define OV9713_WIN16_XWIN0_LO             0x5a21
#define OV9713_WIN16_XWIN1_HI             0x5a22
#define OV9713_WIN16_XWIN1_LO             0x5a23
#define OV9713_WIN16_XWIN2_HI             0x5a24
#define OV9713_WIN16_XWIN2_LO             0x5a25
#define OV9713_WIN16_XWIN3_HI             0x5a26
#define OV9713_WIN16_XWIN3_LO             0x5a27
#define OV9713_WIN16_YWIN0_HI             0x5a28
#define OV9713_WIN16_YWIN0_LO             0x5a29
#define OV9713_WIN16_YWIN1_HI             0x5a2a
#define OV9713_WIN16_YWIN1_LO             0x5a2b
#define OV9713_WIN16_YWIN2_HI             0x5a2c
#define OV9713_WIN16_YWIN2_LO             0x5a2d
#define OV9713_WIN16_YWIN3_HI             0x5a2e
#define OV9713_WIN16_YWIN3_LO             0x5a2f

/*DPC control registers [0x5400-0x5426]*/
#define OV9713_DPC_CTRL0_0                0x5400
#define OV9713_DPC_CTRL0_1                0x5401
#define OV9713_DPC_CTRL0_2                0x5402
#define OV9713_DPC_CTRL0_3                0x5403
#define OV9713_DPC_CTRL0_4                0x5404
#define OV9713_DPC_CTRL0_5                0x5405
#define OV9713_DPC_CTRL0_6                0x5406
#define OV9713_DPC_CTRL0_7                0x5407
#define OV9713_DPC_CTRL0_8                0x5408
#define OV9713_DPC_CTRL0_9                0x5409
#define OV9713_DPC_CTRL0_10               0x540a
#define OV9713_DPC_CTRL0_11               0x540b
#define OV9713_DPC_CTRL0_12               0x540c
#define OV9713_DPC_CTRL0_13               0x540d
#define OV9713_DPC_CTRL0_14               0x540e
#define OV9713_DPC_CTRL0_15               0x540f
#define OV9713_DPC_CTRL1_0                0x5410
#define OV9713_DPC_CTRL1_1                0x5411
#define OV9713_DPC_CTRL1_2                0x5412
#define OV9713_DPC_CTRL1_3                0x5413
#define OV9713_DPC_CTRL1_4                0x5414
#define OV9713_DPC_CTRL1_5                0x5415
#define OV9713_DPC_CTRL1_6                0x5416
#define OV9713_DPC_CTRL1_7                0x5417
#define OV9713_DPC_CTRL1_8                0x5418
#define OV9713_DPC_CTRL1_9                0x5419
#define OV9713_DPC_CTRL1_10               0x541a
#define OV9713_DPC_CTRL1_11               0x541b
#define OV9713_DPC_CTRL1_12               0x541c
#define OV9713_DPC_CTRL1_13               0x541d
#define OV9713_DPC_CTRL1_14               0x541e
#define OV9713_DPC_CTRL1_15               0x541f
#define OV9713_DPC_CTRL2_0                0x5420
#define OV9713_DPC_CTRL2_1                0x5421
#define OV9713_DPC_CTRL2_2                0x5422
#define OV9713_DPC_CTRL2_3                0x5423
#define OV9713_DPC_CTRL2_4                0x5424
#define OV9713_DPC_CTRL2_5                0x5425
#define OV9713_DPC_CTRL2_6                0x5426

/*LENC control registers [0x5200-0521c]*/
#define OV9713_RED_X0_HI                  0x5200
#define OV9713_RED_X0_LO                  0x5201
#define OV9713_RED_Y0_HI                  0x5202
#define OV9713_RED_Y0_LO                  0x5203
#define OV9713_RED_A1                     0x5204
#define OV9713_RED_A2                     0x5205
#define OV9713_RED_B1                     0x5206
#define OV9713_RED_B2                     0x5207
#define OV9713_GRN_X0_HI                  0x5208
#define OV9713_GRN_X0_LO                  0x5209
#define OV9713_GRN_Y0_HI                  0x520a
#define OV9713_GRN_Y0_LO                  0x520b
#define OV9713_GRN_A1                     0x520b
#define OV9713_GRN_A2                     0x520d
#define OV9713_GRN_B1                     0x520e
#define OV9713_GRN_B2                     0x520f
#define OV9713_BLU_X0_HI                  0x5210
#define OV9713_BLU_X0_LO                  0x5211
#define OV9713_BLU_Y0_HI                  0x5212
#define OV9713_BLU_Y0_LO                  0x5213
#define OV9713_BLU_A1                     0x5214
#define OV9713_BLU_A2                     0x5215
#define OV9713_BLU_B1                     0x5216
#define OV9713_BLU_B2                     0x5217
#define OV9713_LENC_CTRL0                 0x5218
#define OV9713_COEF_TH                    0x5219
#define OV9713_GAIN_TH1                   0x521a
#define OV9713_GAIN_TH2                   0x521b
#define OV9713_COEF_MAN                   0x521c

/*ISP general control registers [0x5000-0500f,0x5080-0x5091]*/
#define OV9713_ISP_CTRL00                 0x5000
#define OV9713_ISP_CTRL01                 0x5001
#define OV9713_ISP_CTRL02                 0x5002
#define OV9713_ISP_CTRL03                 0x5003
#define OV9713_RED_GAIN_HI                0x5004
#define OV9713_RED_GAIN_LO                0x5005
#define OV9713_GRN_GAIN_HI                0x5006
#define OV9713_GRN_GAIN_LO                0x5007
#define OV9713_BLU_GAIN_HI                0x5008
#define OV9713_BLU_GAIN_LO                0x5009
#define OV9713_ISP_CTRL0A                 0x500a
#define OV9713_ISP_CTRL0B                 0x500b
#define OV9713_ISP_CTRL0C                 0x500c
#define OV9713_ISP_CTRL0D                 0x500d
#define OV9713_ISP_CTRL0E                 0x500e
#define OV9713_ISP_CTRL0F                 0x500f
#define OV9713_CTRL00                     0x5080
#define OV9713_CTRL01                     0x5081
#define OV9713_PRE_REG8_2                 0x5082
#define OV9713_PRE_REG8_3                 0x5083
#define OV9713_PRE_REG8_4                 0x5084
#define OV9713_PRE_REG8_5                 0x5085
#define OV9713_PRE_REG8_6                 0x5086
#define OV9713_PRE_REG8_7                 0x5087
#define OV9713_PRE_REG8_8                 0x5088
#define OV9713_PRE_REG8_9                 0x5089
#define OV9713_PRE_REG8_a                 0x508a
#define OV9713_PRE_REG8_b                 0x508b
#define OV9713_PRE_REG8_c                 0x508c
#define OV9713_PRE_REG8_d                 0x508d
#define OV9713_PRE_REG8_e                 0x508e
#define OV9713_PRE_REG8_f                 0x508f
#define OV9713_PRE_REG9_0                 0x5090
#define OV9713_PRE_REG9_1                 0x5091

/*LED control registers [0x3900-0x391c]*/
#define OV9713_LED_REG0                   0x3900
#define OV9713_LED_REG1                   0x3901
#define OV9713_LED_REG3                   0x3903
#define OV9713_LED_REG4                   0x3904
#define OV9713_LED_REG5                   0x3905
#define OV9713_LED_REG6                   0x3906
#define OV9713_LED_REG7                   0x3907
#define OV9713_LED_REG10                  0x3910
#define OV9713_LED_REG11                  0x3911
#define OV9713_LED_REG12                  0x3912
#define OV9713_LED_REG13                  0x3913
#define OV9713_LED_REG14                  0x3914
#define OV9713_LED_REG15                  0x3915
#define OV9713_LED_REG16                  0x3916
#define OV9713_LED_REG17                  0x3917
#define OV9713_LED_REG18                  0x3918
#define OV9713_LED_REG19                  0x3919
#define OV9713_LED_REG1A                  0x391a
#define OV9713_LED_REG1B                  0x391b
#define OV9713_LED_REG1C                  0x391c

/*AK5703 A/D converter REGISTERS*/

#define AK5703_POWER_MANAGEMENTA          0x00
#define AK5703_PLL_CONTROLA               0x01
#define AK5703_SIGNAL_MIC_GAIN_SELECTA    0x02
#define AK5703_MIC_GAIN_ADJUSTA0          0x03
#define AK5703_MIC_GAIN_ADJUSTA1          0x04
#define AK5703_FS_SELECT_FILTER_CONTROLA  0x05
#define AK5703_CLOCK_OUTPUT_SELECTA       0x06
#define AK5703_LCH_INPUT_VOLUME_CONTROLA  0x07
#define AK5703_RCH_INPUT_VOLUME_CONTROLA  0x08
#define AK5703_TIMER_SELECTA              0x09
#define AK5703_ALC_MODE_CONTROLA0         0x0a
#define AK5703_ALC_MODE_CONTROLA1         0x0b
#define AK5703_L1_CH_OUTPUT_DELAY_CONTROL 0x0c
#define AK5703_R1_CH_OUTPUT_DELAY_CONTROL 0x0d
#define AK5703_RESERVED0E                 0x0e
#define AK5703_RESERVED0F                 0x0f
#define AK5703_POWER_MANAGEMENTB          0x10
#define AK5703_RESERVED11                 0x11
#define AK5703_SIGNAL_MIC_GAIN_SELECTB    0x12
#define AK5703_MIC_GAIN_ADJUSTB0          0x13
#define AK5703_MIC_GAIN_ADJUSTB1          0x14
#define AK5703_FILTER_CONTROLB            0x15
#define AK5703_CLOCK_OUTPUT_SELECTB       0x16
#define AK5703_LCH_INPUT_VOLUME_CONTROLB  0x17
#define AK5703_RCH_INPUT_VOLUME_CONTROLB  0x18
#define AK5703_TIMER_SELECTB              0x19
#define AK5703_ALC_MODE_CONTROLB0         0x1a
#define AK5703_ALC_MODE_CONTROLB1         0x1b
#define AK5703_L2_CH_OUTPUT_DELAY_CONTROL 0x1c
#define AK5703_R2_CH_OUTPUT_DELAY_CONTROL 0x1d
#define AK5703_RESERVED1E                 0x1e
#define AK5703_RESERVED1F                 0x1f
#define AK5703_HPFA2_COEF_0               0x20
#define AK5703_HPFA2_COEF_1               0x21
#define AK5703_HPFA2_COEF_2               0x22
#define AK5703_HPFA2_COEF_3               0x23
#define AK5703_LPFA_COEF_0                0x24
#define AK5703_LPFA_COEF_1                0x25
#define AK5703_LPFA_COEF_2                0x26
#define AK5703_LPFA_COEF_3                0x27
#define AK5703_RESERVED28                 0x28
#define AK5703_RESERVED29                 0x29
#define AK5703_RESERVED2A                 0x2a
#define AK5703_RESERVED2B                 0x2b
#define AK5703_RESERVED2C                 0x2c
#define AK5703_RESERVED2D                 0x2d
#define AK5703_RESERVED2E                 0x2e
#define AK5703_RESERVED2F                 0x2f
#define AK5703_HPFB2_COEF_0               0x30
#define AK5703_HPFB2_COEF_1               0x31
#define AK5703_HPFB2_COEF_2               0x32
#define AK5703_HPFB2_COEF_3               0x33
#define AK5703_LPFB_COEF_0                0x34
#define AK5703_LPFB_COEF_1                0x35
#define AK5703_LPFB_COEF_2                0x36
#define AK5703_LPFB_COEF_3                0x37

/*USB bRequest AND DEVICES SUBADDRES*/
/*SEND WRITE FROM HOST TO DEVICE*/
#define SET_REGISTER                      0xa4
/*SEND READ FROM HOST TO DEVICE*/
#define GET_REGISTER_SEND                 0xa5
/*RECEIVING READ FROM DEVICE TO HOST*/
#define GET_REGISTER_RECEIVE              0xa6
/*SEND WRITE FROM HOST TO DEVICE WITH MULTIPLE REGISTERS WITH DIFFERENT SUBADDR?*/
#define SET_MULTI_REGISTER                0xa7

/*subaddress to read/write registers from/to camera sensors*/
#define OV9713_SENSOR1_SUBADDR            0x01
#define OV9713_SENSOR2_SUBADDR            0x02
#define OV9713_SENSORS_SUBADDR            0x03
/*subaddress to read/write registers from/to AK5703 A/D converter*/
#define AK5703_SUBADDR                    0x24
/*TODO DISCOVER WHICH DEVICE FOR THESE PERHAPS AC IS EEPROM 4G51A*/
#define UNKNOWN30_SUBADDR                 0x30
#define C4G51A_SUBADDR                    0xac
#define UNKNOWNFF_SUBADDR                 0xff  //? it seems ov580
#define UNKNOWN00_SUBADDR                 0x00  //? it seems ov580

//read general configuration and image size registers conf
static const uint16_t sensor_generalconf_imagesize_reg_read[26]={
	OV9713_MODE_SELECT,
	OV9713_IMAGE_ORIENTATION,
	OV9713_SOFTWARE_RESET,
	OV9713_FAST_STANDBY_CTRL,
	OV9713_CCI_ADDRESS_CONTROL_20,
	OV9713_CCI_ADDRESS_CONTROL_6C,
	OV9713_FRAME_LENGTH_LINES_HI,
	OV9713_FRAME_LENGTH_LINES_LO,
	OV9713_LINE_LENGTH_PCK_HI,
	OV9713_LINE_LENGTH_PCK_LO,
	OV9713_X_ADDR_START_HI,
	OV9713_X_ADDR_START_LO,
	OV9713_Y_ADDR_START_HI,
	OV9713_Y_ADDR_START_LO,
	OV9713_X_ADDR_END_HI,
	OV9713_X_ADDR_END_LO,
	OV9713_Y_ADDR_END_HI,
	OV9713_Y_ADDR_END_LO,
	OV9713_X_OUTPUT_SIZE_HI,
	OV9713_X_OUTPUT_SIZE_LO,
	OV9713_Y_OUTPUT_SIZE_HI,
	OV9713_Y_OUTPUT_SIZE_LO,
	OV9713_X_EVEN_INC,
	OV9713_X_ODD_INC,
	OV9713_Y_EVEN_INC,
	OV9713_Y_ODD_INC
};




/*
 02 00 00 00 00 00 00 00
 00 05 20 03
 3C 00 00 00
 00 05 20 03
 3C 00 04 00
 2A 00 2A 00
 00 00 00 00
 00 00 00 00
 00 00 00 00
 00 00 00 00
 00 00 00 00
 00 00 00 00
 00 00 00 00
 00 00 00 00
 00 00 00 00
 size 64*/

static const uint16_t reg_init[][3] = {
	{ OV9713_ISP_CTRL00, 0x20 , 0x03}, //enable OTP signal, rest disabled on both sensors
	{ 0x003c, 0x00 ,0x00 },
	{ OV9713_ISP_CTRL00, 0x20 , 0x03 },
	{ 0x003c, 0x04 ,0x00},
	{ 0x002a, 0x2a, 0x00 },
	{ 0x0000, 0x00, 0x00 },
	{ 0x0000, 0x00, 0x00 },
	{ 0x0000, 0x00, 0x00 },
	{ 0x0000, 0x00, 0x00 },
	{ 0x0000, 0x00, 0x00 },
	{ 0x0000, 0x00, 0x00 },
	{ 0x0000, 0x00, 0x00 },
	{ 0x0000, 0x00, 0x00 },
	{ 0x0000, 0x00, 0x00 }
};

/*read CHIP ID from sensor1 you will see why is ov9713 sensor :P*/
static const uint16_t sensor1_reg_read[2]={
	OV9713_CHIP_ID_HI,
	OV9713_CHIP_ID_LO
};
/*read CHIP ID from sensor2 you will see why is ov9713 sensor :P*/

static const uint16_t sensor2_reg_read[2]={
	OV9713_CHIP_ID_HI,
	OV9713_CHIP_ID_LO
};

/*read 0x0000 from UNKNOWN30 */
static const uint16_t unknown30_reg_read[1]={
	0x0000
};
/*read one by one from 0xfd80-0xff16 407 bytes from 4g5a subaddress AC*/
/*static const uint16_t 4g5a_reg_read[]={
 0xfd80,
 0xfd81,
 ...   ,
 ...   ,
 0xff16
 };*/


/*
 03 00 00 00 00 00 00 00
 06 27 00 FF
 00 27 F0 FF
 00 FF 03 FF
 01 FF 00 FF
 02 FF 50 FF
 80 FF 03 FF
 81 FF 00 FF
 82 FF 50 FF
 size 40*/
static const uint16_t ov580_reg_init0[][2] = {
	{ 0x2706, 0x00 },
	{ 0x2700, 0xf0 },
	{ 0xff00, 0x03 },//it seem that eeprom 4g5a can be written from subaddres FF and read from AC subaddres?
	{ 0xff01, 0x00 },
	{ 0xff02, 0x50 },
	{ 0xff80, 0x03 },
	{ 0xff81, 0x00 },
	{ 0xff82, 0x50 },
};
/*
 03 00 00 00 00 00 00 00
 06 27 01 FF
 00 27 F0 FF
 02 27 20 FF
 size 20*/
static const uint16_t ov580_reg_init1[][2] = {
	{ 0x2706, 0x01 }, //led on
	{ 0x2700, 0xf0 },
	{ 0x2702, 0x20 }
};
/*
 03 00 00 00 00 00 00 00
 01 30 01 03
 12 37 7A 03
 03 36 63 03
 33 36 14 03
 12 30 20 03
 14 30 84 03
 1F 30 83 03
 20 30 02 03
 03 31 00 03
 02 3F 14 03
 03 3F 66 03
 83 45 83 03
 size 56*/
static const uint16_t ov9713_reg_init0[][2] = {
	{ OV9713_PAD_CTRL, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER1_2, 0x7a },
	{ OV9713_ANALOG_REGISTER0_3, 0x63 },
	{ OV9713_ANALOG_REGISTER3_3, 0x14 },
	{ OV9713_A_MIPI_PK_1, 0x20 },
	{ OV9713_MIPI_SC_O_1, 0x84 },
	{ OV9713_MISC_CTRL, 0x83 },
	{ OV9713_MISC_CTRL1, 0x02 },
	{ 0x3103, 0x00 },
	{ 0x3f02, 0x14 },
	{ 0x3f03, 0x66 },
	{ OV9713_HDR_FRAME_REG3, 0x83 }
};

/*
 03 00 00 00 00 00 00 00
 37 48 10 03
 62 36 10 03
 04 3F D0 03
 24 36 CC 03
 22 36 66 03
 32 36 A9 03
 A3 30 1B 03
 0D 37 CC 03
 size 40*/
static const uint16_t ov9713_reg_init1[][2] = {
	{ OV9713_PCLK_PERIOD, 0x10 },
	{ OV9713_ANALOG_REGISTER6_2, 0x7a },
	{ 0x3f04, 0xd0 },
	{ OV9713_ANALOG_REGISTER2_4, 0xcc },
	{ OV9713_ANALOG_REGISTER2_2, 0x66 },
	{ OV9713_ANALOG_REGISTER3_2, 0xa9 },
	{ OV9713_PLL23, 0x1b },
	{ OV9713_SENSOR_CTRL_REGISTER0_13, 0xcc }
};
/*
 03 00 00 00 00 00 00 00
 86 11 0D FF
 87 11 10 FF
 88 11 0E FF
 89 11 74 FF
 8A 11 56 FF
 8B 11 8A FF
 8C 11 85 FF
 8D 11 45 FF
 8E 11 32 FF
 8F 11 66 FF
 90 11 4A FF
 91 11 F5 FF
 size 56*/
static const uint16_t ov580_reg_init2[][2] = {
	{ 0x1186, 0x0d },
	{ 0x1187, 0x10 },
	{ 0x1188, 0x0e },
	{ 0x1189, 0x74 },
	{ 0x118a, 0x56 },
	{ 0x118b, 0x8a },
	{ 0x118c, 0x85 },
	{ 0x118d, 0x45 },
	{ 0x118e, 0x32 },
	{ 0x118f, 0x66 },
	{ 0x1190, 0x4a },
	{ 0x1191, 0xf5 }
};

/*
 03 00 00 00 00 00 00 00
 92 11 0A FF
 81 11 58 FF
 size 16
 */
static const uint16_t ov580_reg_init3[][2] = {
	{ 0x1192, 0x0a },
	{ 0x1181, 0x58 }
};
/*
 03 00 00 00 00 00 00 00
 86 19 0D FF
 87 19 10 FF
 88 19 0E FF
 89 19 74 FF
 8A 19 56 FF
 8B 19 8A FF
 8C 19 85 FF
 8D 19 45 FF
 8E 19 32 FF
 8F 19 66 FF
 90 19 4A FF
 91 19 F5 FF
 size 56*/
static const uint16_t ov580_reg_init4[][2] = {
	{ 0x1986, 0x0d },
	{ 0x1987, 0x10 },
	{ 0x1988, 0x0e },
	{ 0x1989, 0x74 },
	{ 0x198a, 0x56 },
	{ 0x198b, 0x8a },
	{ 0x198c, 0x85 },
	{ 0x198d, 0x45 },
	{ 0x198e, 0x32 },
	{ 0x198f, 0x66 },
	{ 0x1990, 0x4a },
	{ 0x1991, 0xf5 }
};
/*
 03 00 00 00 00 00 00 00
 92 19 0A FF
 81 19 58 FF
 size 16
 */
static const uint16_t ov580_reg_init5[][2] = {
	{ 0x1992, 0x0a },
	{ 0x1981, 0x58 },
};
/*
 03 00 00 00 00 00 00 00
 00 11 16 FF
 01 11 14 FF
 02 11 11 FF
 03 11 12 FF
 04 11 15 FF
 05 11 1A FF
 06 11 0A FF
 07 11 05 FF
 08 11 03 FF
 09 11 04 FF
 0A 11 07 FF
 0B 11 0C FF
 size 56*/
static const uint16_t ov580_reg_init6[][2] = {
	{ 0x1100, 0x16 },
	{ 0x1101, 0x14 },
	{ 0x1102, 0x11 },
	{ 0x1103, 0x12 },
	{ 0x1104, 0x15 },
	{ 0x1105, 0x1a },
	{ 0x1106, 0x0a },
	{ 0x1107, 0x05 },
	{ 0x1108, 0x03 },
	{ 0x1109, 0x04 },
	{ 0x110a, 0x07 },
	{ 0x110b, 0x0c }
};
/*
 03 00 00 00 00 00 00 00
 0C 11 03 FF
 0D 11 01 FF
 0E 11 00 FF
 0F 11 00 FF
 10 11 02 FF
 11 11 05 FF
 12 11 03 FF
 13 11 01 FF
 14 11 00 FF
 15 11 00 FF
 16 11 02 FF
 17 11 05 FF
 size 56*/
static const uint16_t ov580_reg_init7[][2] = {
	{ 0x110c, 0x03 },
	{ 0x110d, 0x01 },
	{ 0x110e, 0x00 },
	{ 0x110f, 0x00 },
	{ 0x1110, 0x02 },
	{ 0x1111, 0x05 },
	{ 0x1112, 0x03 },
	{ 0x1113, 0x01 },
	{ 0x1114, 0x00 },
	{ 0x1115, 0x00 },
	{ 0x1116, 0x02 },
	{ 0x1117, 0x05 }
};
/*
 03 00 00 00 00 00 00 00
 18 11 09 FF
 19 11 05 FF
 1A 11 03 FF
 1B 11 04 FF
 1C 11 06 FF
 1D 11 0C FF
 1E 11 16 FF
 1F 11 13 FF
 20 11 10 FF
 21 11 11 FF
 22 11 14 FF
 23 11 18 FF
 size 56*/
static const uint16_t ov580_reg_init8[][2] = {
	{ 0x1118, 0x09 },
	{ 0x1119, 0x05 },
	{ 0x111a, 0x03 },
	{ 0x111b, 0x04 },
	{ 0x111c, 0x06 },
	{ 0x111d, 0x0c },
	{ 0x111e, 0x16 },
	{ 0x111f, 0x13 },
	{ 0x1120, 0x10 },
	{ 0x1121, 0x11 },
	{ 0x1121, 0x14 },
	{ 0x1123, 0x18 }
};
/*
 03 00 00 00 00 00 00 00
 24 11 09 FF
 25 11 19 FF
 26 11 19 FF
 27 11 19 FF
 28 11 07 FF
 29 11 27 FF
 2A 11 23 FF
 2B 11 22 FF
 2C 11 23 FF
 2D 11 17 FF
 2E 11 34 FF
 2F 11 31 FF
 size 56*/
static const uint16_t ov580_reg_init9[][2] = {
	{ 0x1124, 0x09 },
	{ 0x1115, 0x19 },
	{ 0x1126, 0x19 },
	{ 0x1127, 0x19 },
	{ 0x1128, 0x07 },
	{ 0x1129, 0x27 },
	{ 0x112a, 0x23 },
	{ 0x112b, 0x22 },
	{ 0x112c, 0x23 },
	{ 0x112d, 0x17 },
	{ 0x112e, 0x34 },
	{ 0x112f, 0x31 }
};
/*
 03 00 00 00 00 00 00 00
 30 11 30 FF
 31 11 31 FF
 32 11 34 FF
 33 11 27 FF
 34 11 33 FF
 35 11 32 FF
 36 11 33 FF
 37 11 37 FF
 38 11 1B FF
 39 11 1A FF
 3A 11 29 FF
 3B 11 2A FF
 size 56*/
static const uint16_t ov580_reg_init10[][2] = {
	{ 0x1130, 0x30 },
	{ 0x1131, 0x31 },
	{ 0x1132, 0x34 },
	{ 0x1133, 0x27 },
	{ 0x1134, 0x33 },
	{ 0x1135, 0x32 },
	{ 0x1136, 0x33 },
	{ 0x1137, 0x37 },
	{ 0x1138, 0x1b },
	{ 0x1139, 0x1a },
	{ 0x113a, 0x29 },
	{ 0x113b, 0x2a }
};
/*
 03 00 00 00 00 00 00 00
 3C 11 28 FF
 3D 11 DF FF
 00 19 16 FF
 01 19 14 FF
 02 19 11 FF
 03 19 12 FF
 04 19 15 FF
 05 19 1A FF
 06 19 0A FF
 07 19 05 FF
 08 19 03 FF
 09 19 04 FF
 size 56*/
static const uint16_t ov580_reg_init11[][2] = {
	{ 0x113c, 0x28 },
	{ 0x113d, 0xdf },
	{ 0x1900, 0x16 },
	{ 0x1901, 0x14 },
	{ 0x1902, 0x11 },
	{ 0x1903, 0x12 },
	{ 0x1904, 0x15 },
	{ 0x1905, 0x1a },
	{ 0x1906, 0x0a },
	{ 0x1907, 0x05 },
	{ 0x1908, 0x03 },
	{ 0x1909, 0x04 }
};
/*
 03 00 00 00 00 00 00 00
 0A 19 07 FF
 0B 19 0C FF
 0C 19 03 FF
 0D 19 01 FF
 0E 19 00 FF
 0F 19 00 FF
 10 19 02 FF
 11 19 05 FF
 12 19 03 FF
 13 19 01 FF
 14 19 00 FF
 15 19 00 FF
 size 56*/
static const uint16_t ov580_reg_init12[][2] = {
	{ 0x190a, 0x07 },
	{ 0x190b, 0x0c },
	{ 0x190c, 0x03 },
	{ 0x190d, 0x01 },
	{ 0x190e, 0x00 },
	{ 0x190f, 0x00 },
	{ 0x1910, 0x02 },
	{ 0x1911, 0x05 },
	{ 0x1912, 0x03 },
	{ 0x1913, 0x01 },
	{ 0x1914, 0x00 },
	{ 0x1915, 0x00 }
};
/*
 03 00 00 00 00 00 00 00
 16 19 02 FF
 17 19 05 FF
 18 19 09 FF
 19 19 05 FF
 1A 19 03 FF
 1B 19 04 FF
 1C 19 06 FF
 1D 19 0C FF
 1E 19 16 FF
 1F 19 13 FF
 20 19 10 FF
 21 19 11 FF
 size 56*/
static const uint16_t ov580_reg_init13[][2] = {
	{ 0x1916, 0x02 },
	{ 0x1917, 0x05 },
	{ 0x1918, 0x09 },
	{ 0x1919, 0x05 },
	{ 0x191a, 0x03 },
	{ 0x191b, 0x04 },
	{ 0x191c, 0x06 },
	{ 0x191d, 0x0c },
	{ 0x191e, 0x16 },
	{ 0x191f, 0x13 },
	{ 0x1920, 0x10 },
	{ 0x1921, 0x11 }
};
/*
 03 00 00 00 00 00 00 00
 22 19 14 FF
 23 19 18 FF
 24 19 09 FF
 25 19 19 FF
 26 19 19 FF
 27 19 19 FF
 28 19 07 FF
 29 19 27 FF
 2A 19 23 FF
 2B 19 22 FF
 2C 19 23 FF
 2D 19 17 FF
 size 56*/
static const uint16_t ov580_reg_init14[][2] = {
	{ 0x1922, 0x14 },
	{ 0x1923, 0x18 },
	{ 0x1924, 0x09 },
	{ 0x1925, 0x19 },
	{ 0x1926, 0x19 },
	{ 0x1927, 0x19 },
	{ 0x1928, 0x07 },
	{ 0x1928, 0x27 },
	{ 0x192a, 0x23 },
	{ 0x192b, 0x22 },
	{ 0x192c, 0x23 },
	{ 0x192d, 0x17 }
};
/*
 03 00 00 00 00 00 00 00
 2E 19 34 FF
 2F 19 31 FF
 30 19 30 FF
 31 19 31 FF
 32 19 34 FF
 33 19 27 FF
 34 19 33 FF
 35 19 32 FF
 36 19 33 FF
 37 19 37 FF
 38 19 1B FF
 39 19 1A FF
 size 56*/
static const uint16_t ov580_reg_init15[][2] = {
	{ 0x192e, 0x34 },
	{ 0x192f, 0x31 },
	{ 0x1930, 0x30 },
	{ 0x1931, 0x31 },
	{ 0x1932, 0x34 },
	{ 0x1933, 0x27 },
	{ 0x1934, 0x33 },
	{ 0x1935, 0x32 },
	{ 0x1936, 0x33 },
	{ 0x1937, 0x37 },
	{ 0x1938, 0x1b },
	{ 0x1939, 0x1a }
};
/*
 03 00 00 00 00 00 00 00
 3A 19 29 FF
 3B 19 2A FF
 3C 19 28 FF
 3D 19 DF FF
 size 24*/
static const uint16_t ov580_reg_init16[][2] = {
	{ 0x193a, 0x29 },
	{ 0x193b, 0x2a },
	{ 0x193c, 0x2b },
	{ 0x193d, 0xdf }
};
/*
 03 00 00 00 00 00 00 00
 80 14 03 FF
 81 14 DE FF
 82 14 00 FF
 83 14 58 FF
 84 14 01 FF
 85 14 B9 FF
 86 14 00 FF
 87 14 F4 FF
 88 14 00 FF
 89 14 4F FF
 8A 14 04 FF
 8B 14 4F FF
 size 56*/
static const uint16_t ov580_reg_init17[][2] = {
	{ 0x1480, 0x03 },
	{ 0x1481, 0xde },
	{ 0x1482, 0x00 },
	{ 0x1483, 0x58 },
	{ 0x1484, 0x01 },
	{ 0x1485, 0xb9 },
	{ 0x1486, 0x00 },
	{ 0x1487, 0xf4 },
	{ 0x1488, 0x00 },
	{ 0x1489, 0x4f },
	{ 0x148a, 0x04 },
	{ 0x148b, 0x4f }
};
/*
 03 00 00 00 00 00 00 00
 8C 14 06 FF
 8D 14 A5 FF
 8E 14 00 FF
 8F 14 77 FF
 90 14 01 FF
 91 14 4E FF
 92 14 01 FF
 93 14 C7 FF
 94 14 00 FF
 95 14 6D FF
 96 14 04 FF
 97 14 AD FF
 size 56*/
static const uint16_t ov580_reg_init18[][2] = {
	{ 0x148c, 0x06 },
	{ 0x148d, 0xa5 },
	{ 0x148e, 0x00 },
	{ 0x148f, 0x77 },
	{ 0x1490, 0x01 },
	{ 0x1491, 0x4e },
	{ 0x1492, 0x01 },
	{ 0x1493, 0xc7 },
	{ 0x1494, 0x00 },
	{ 0x1495, 0x6d },
	{ 0x1496, 0x04 },
	{ 0x1497, 0xad }
};
/*
 03 00 00 00 00 00 00 00
 98 14 03 FF
 99 14 E2 FF
 9A 14 00 FF
 9B 14 B4 FF
 9C 14 00 FF
 9D 14 B1 FF
 9E 14 01 FF
 9F 14 D5 FF
 A0 14 00 FF
 A1 14 84 FF
 A2 14 05 FF
 A3 14 4B FF
 size 56*/
static const uint16_t ov580_reg_init19[][2] = {
	{ 0x1498, 0x03 },
	{ 0x1499, 0xe2 },
	{ 0x149a, 0x00 },
	{ 0x149b, 0xb4 },
	{ 0x149c, 0x00 },
	{ 0x149d, 0xb1 },
	{ 0x149e, 0x01 },
	{ 0x149f, 0xd5 },
	{ 0x14a0, 0x00 },
	{ 0x14a1, 0x84 },
	{ 0x14a2, 0x05 },
	{ 0x14a3, 0x4b }
};
/*
 03 00 00 00 00 00 00 00
 AE 14 10 FF
 AF 14 00 FF
 B0 14 00 FF
 80 1C 03 FF
 81 1C DE FF
 82 1C 00 FF
 83 1C 58 FF
 84 1C 01 FF
 85 1C B9 FF
 86 1C 00 FF
 87 1C F4 FF
 88 1C 00 FF
 size 56*/
static const uint16_t ov580_reg_init20[][2] = {
	{ 0x14ae, 0x10 },
	{ 0x14af, 0x00 },
	{ 0x14b0, 0x00 },
	{ 0x1c80, 0x03 },
	{ 0x1c81, 0xde },
	{ 0x1c82, 0x00 },
	{ 0x1c83, 0x58 },
	{ 0x1c84, 0x01 },
	{ 0x1c85, 0xb9 },
	{ 0x1c86, 0x00 },
	{ 0x1c87, 0xf4 },
	{ 0x1c88, 0x00 }
};
/*
 03 00 00 00 00 00 00 00
 89 1C 4F FF
 8A 1C 04 FF
 8B 1C 4F FF
 8C 1C 06 FF
 8D 1C A5 FF
 8E 1C 00 FF
 8F 1C 77 FF
 90 1C 01 FF
 91 1C 4E FF
 92 1C 01 FF
 93 1C C7 FF
 94 1C 00 FF
 size 56*/
static const uint16_t ov580_reg_init21[][2] = {
	{ 0x1c89, 0x4f },
	{ 0x1c8a, 0x04 },
	{ 0x1c8b, 0x4f },
	{ 0x1c8c, 0x06 },
	{ 0x1c8d, 0xa5 },
	{ 0x1c8e, 0x00 },
	{ 0x1c8f, 0x77 },
	{ 0x1c90, 0x01 },
	{ 0x1c91, 0x4e },
	{ 0x1c92, 0x01 },
	{ 0x1c93, 0xc7 },
	{ 0x1c94, 0x00 }
};
/*
 03 00 00 00 00 00 00 00
 95 1C 6D FF
 96 1C 04 FF
 97 1C AD FF
 98 1C 03 FF
 99 1C E2 FF
 9A 1C 00 FF
 9B 1C B4 FF
 9C 1C 00 FF
 9D 1C B1 FF
 9E 1C 01 FF
 9F 1C D5 FF
 A0 1C 00 FF
 size 56*/
static const uint16_t ov580_reg_init22[][2] = {
	{ 0x1c95, 0x6d },
	{ 0x1c96, 0x04 },
	{ 0x1c97, 0xad },
	{ 0x1c98, 0x03 },
	{ 0x1c99, 0xe2 },
	{ 0x1c9a, 0x00 },
	{ 0x1c9b, 0xb4 },
	{ 0x1c9c, 0x00 },
	{ 0x1c9d, 0xb1 },
	{ 0x1c9e, 0x01 },
	{ 0x1c9f, 0xd5 },
	{ 0x1ca0, 0x00 }
};
/*
 03 00 00 00 00 00 00 00
 A1 1C 84 FF
 A2 1C 05 FF
 A3 1C 4B FF
 AE 1C 10 FF
 AF 1C 00 FF
 B0 1C 00 FF
 size 32*/
static const uint16_t ov580_reg_init23[][2] = {
	{ 0x1ca1, 0x84 },
	{ 0x1ca2, 0x05 },
	{ 0x1ca3, 0x4b },
	{ 0x1cae, 0x10 },
	{ 0x1caf, 0x00 },
	{ 0x1cb0, 0x00 }
};
/*
 03 00 00 00 00 00 00 00
 40 15 06 FF
 41 15 0E FF
 42 15 22 FF
 43 15 4B FF
 44 15 59 FF
 45 15 66 FF
 46 15 72 FF
 47 15 7C FF
 48 15 84 FF
 49 15 8C FF
 4A 15 9A FF
 4B 15 A5 FF
 size 56*/
static const uint16_t ov580_reg_init24[][2] = {
	{ 0x1540, 0x06 },
	{ 0x1541, 0x0e },
	{ 0x1542, 0x22 },
	{ 0x1543, 0x4b },
	{ 0x1544, 0x59 },
	{ 0x1545, 0x66 },
	{ 0x1546, 0x72 },
	{ 0x1547, 0x7c },
	{ 0x1548, 0x84 },
	{ 0x1549, 0x8c },
	{ 0x154a, 0x9a },
	{ 0x154b, 0xa5 }
};
/*
 03 00 00 00 00 00 00 00
 4C 15 B5 FF
 4D 15 C3 FF
 4E 15 D6 FF
 00 15 06 FF
 01 15 0E FF
 02 15 22 FF
 03 15 4B FF
 04 15 59 FF
 05 15 66 FF
 06 15 72 FF
 07 15 7C FF
 08 15 84 FF
 size 56*/
static const uint16_t ov580_reg_init25[][2] = {
	{ 0x154c, 0xb5 },
	{ 0x154d, 0xc3 },
	{ 0x154e, 0xd6 },
	{ 0x1500, 0x06 },
	{ 0x1501, 0x0e },
	{ 0x1502, 0x22 },
	{ 0x1503, 0x4b },
	{ 0x1504, 0x59 },
	{ 0x1505, 0x66 },
	{ 0x1506, 0x72 },
	{ 0x1507, 0x7c },
	{ 0x1508, 0x84 }
};
/*
 03 00 00 00 00 00 00 00
 09 15 8C FF
 0A 15 9A FF
 0B 15 A5 FF
 0C 15 B5 FF
 0D 15 C3 FF
 0E 15 D6 FF
 40 1D 06 FF
 41 1D 0E FF
 42 1D 22 FF
 43 1D 4B FF
 44 1D 59 FF
 45 1D 66 FF
 size 56*/
static const uint16_t ov580_reg_init26[][2] = {
	{ 0x1509, 0x8c },
	{ 0x150a, 0x9a },
	{ 0x150b, 0xa5 },
	{ 0x150c, 0xb5 },
	{ 0x150d, 0xc3 },
	{ 0x150e, 0xd6 },
	{ 0x1d40, 0x06 },
	{ 0x1d41, 0x0e },
	{ 0x1d42, 0x22 },
	{ 0x1d43, 0x4b },
	{ 0x1d44, 0x59 },
	{ 0x1d45, 0x66 }
};
/*
 03 00 00 00 00 00 00 00
 46 1D 72 FF
 47 1D 7C FF
 48 1D 84 FF
 49 1D 8C FF
 4A 1D 9A FF
 4B 1D A5 FF
 4C 1D B5 FF
 4D 1D C3 FF
 4E 1D D6 FF
 00 1D 06 FF
 01 1D 0E FF
 02 1D 22 FF
 size 56*/
static const uint16_t ov580_reg_init27[][2] = {
	{ 0x1d46, 0x72 },
	{ 0x1d47, 0x7c },
	{ 0x1d48, 0x84 },
	{ 0x1d49, 0x8c },
	{ 0x1d4a, 0x9a },
	{ 0x1d4b, 0xa5 },
	{ 0x1d4c, 0xb5 },
	{ 0x1d4d, 0xc3 },
	{ 0x1d4e, 0xd6 },
	{ 0x1d00, 0x06 },
	{ 0x1d01, 0x0e },
	{ 0x1d02, 0x22 }
};
/*
 03 00 00 00 00 00 00 00
 03 1D 4B FF
 04 1D 59 FF
 05 1D 66 FF
 06 1D 72 FF
 07 1D 7C FF
 08 1D 84 FF
 09 1D 8C FF
 0A 1D 9A FF
 0B 1D A5 FF
 size 44*/
static const uint16_t ov580_reg_init28[][2] = {
	{ 0x1d03, 0x4b },
	{ 0x1d04, 0x59 },
	{ 0x1d05, 0x66 },
	{ 0x1d06, 0x72 },
	{ 0x1d07, 0x7c },
	{ 0x1d08, 0x84 },
	{ 0x1d09, 0x8c },
	{ 0x1d0a, 0x9a },
	{ 0x1d0b, 0xa5 }
};
/*
 03 00 00 00 00 00 00 00
 0C 1D B5 FF
 0D 1D C3 FF
 0E 1D D6 FF
 size 20*/
static const uint16_t ov580_reg_init29[][2] = {
	{ 0x1d0c, 0xb5 },
	{ 0x1d0d, 0xc3 },
	{ 0x1d0e, 0xd6 }
};

/*
 0F 00 00 00 00 00 00 00
 10 00 0B 30
 11 00 1E 30
 size 16*/
static const uint16_t unknow30_reg_init0[][2] = {
	{ 0x0010, 0x0b },
	{ 0x0011, 0x1e }
};
static const uint16_t unknow30_reg_read1[3] = {
    0x0010 ,
    0x0011 ,
    0x0013
};
/*
 0B 00 00 00 00 00 00 00
 00 00 0F 24
 size 12
 */
static const uint16_t ak5703_reg_init0[][2] = {
	{ AK5703_POWER_MANAGEMENTA, 0x0f }
};
/*read AK5703_POWER_MANAGEMENTA after write*/
/*
 0B 00 00 00 00 00 00 00
 00 00 00 24
 10 00 00 24
 size 16*/
static const uint16_t ak5703_reg_init1[][2] = {
	{ AK5703_POWER_MANAGEMENTA, 0x00 },
	{ AK5703_POWER_MANAGEMENTB, 0x00 },
};

/*
 0B 00 00 00 00 00 00 00
 01 00 09 24
 02 00 C0 24
 03 00 C4 24
 04 00 04 24
 05 00 0B 24
 06 00 00 24
 07 00 A8 24
 08 00 A8 24
 09 00 84 24
 0A 00 00 24
 0B 00 E1 24
 0C 00 00 24
 size 56*/
static const uint16_t ak5703_reg_init2[][2] = {
	{ AK5703_PLL_CONTROLA, 0x09 },
	{ AK5703_SIGNAL_MIC_GAIN_SELECTA, 0xc0 },
	{ AK5703_MIC_GAIN_ADJUSTA0, 0xc4 },
	{ AK5703_MIC_GAIN_ADJUSTA1, 0x04 },
	{ AK5703_FS_SELECT_FILTER_CONTROLA, 0x0b },
	{ AK5703_CLOCK_OUTPUT_SELECTA, 0x00 },
	{ AK5703_LCH_INPUT_VOLUME_CONTROLA, 0xa8 },
	{ AK5703_RCH_INPUT_VOLUME_CONTROLA, 0xa8 },
	{ AK5703_TIMER_SELECTA, 0x84 },
	{ AK5703_ALC_MODE_CONTROLA0, 0x00 },
	{ AK5703_ALC_MODE_CONTROLA1, 0xe1 },
	{ AK5703_L1_CH_OUTPUT_DELAY_CONTROL, 0x00 }
};
/*
 0B 00 00 00 00 00 00 00
 0D 00 00 24
 0E 00 00 24
 0F 00 00 24
 11 00 00 24
 12 00 C0 24
 13 00 04 24
 14 00 04 24
 15 00 00 24
 16 00 00 24
 17 00 A8 24
 18 00 A8 24
 19 00 80 24
 size 56*/
static const uint16_t ak5703_reg_init3[][2] = {
	{ AK5703_R1_CH_OUTPUT_DELAY_CONTROL, 0x00 },
	{ AK5703_RESERVED0E, 0x00 },
	{ AK5703_RESERVED0F, 0x00 },
	{ AK5703_RESERVED11, 0x00 },
	{ AK5703_SIGNAL_MIC_GAIN_SELECTB, 0xc0 },
	{ AK5703_MIC_GAIN_ADJUSTB0, 0x04 },
	{ AK5703_MIC_GAIN_ADJUSTB1, 0x04 },
	{ AK5703_FILTER_CONTROLB, 0x00 },
	{ AK5703_CLOCK_OUTPUT_SELECTB, 0x00 },
	{ AK5703_LCH_INPUT_VOLUME_CONTROLB, 0xa8 },
	{ AK5703_RCH_INPUT_VOLUME_CONTROLB, 0xa8 },
	{ AK5703_TIMER_SELECTB, 0x80 }
};
/*
 0B 00 00 00 00 00 00 00
 1A 00 00 24
 1B 00 E1 24
 1C 00 00 24
 1D 00 00 24
 1E 00 00 24
 1F 00 00 24
 20 00 A9 24
 21 00 1F 24
 22 00 AD 24
 23 00 20 24
 24 00 00 24
 25 00 00 24
 size 56*/
static const uint16_t ak5703_reg_init4[][2] = {
	{ AK5703_ALC_MODE_CONTROLB0, 0x00 },
	{ AK5703_ALC_MODE_CONTROLB1, 0xe1 },
	{ AK5703_L2_CH_OUTPUT_DELAY_CONTROL, 0x00 },
	{ AK5703_R2_CH_OUTPUT_DELAY_CONTROL, 0x00 },
	{ AK5703_RESERVED1E, 0x00 },
	{ AK5703_RESERVED1F, 0x00 },
	{ AK5703_HPFA2_COEF_0, 0xa9 },
	{ AK5703_HPFA2_COEF_1, 0x1f },
	{ AK5703_HPFA2_COEF_2, 0xad },
	{ AK5703_HPFA2_COEF_3, 0x20 },
	{ AK5703_LPFA_COEF_0, 0x00 },
	{ AK5703_LPFA_COEF_1, 0x00 }
};
/*
 0B 00 00 00 00 00 00 00
 26 00 00 24
 27 00 00 24
 28 00 00 24
 29 00 00 24
 2A 00 00 24
 2B 00 00 24
 2C 00 00 24
 2D 00 00 24
 2E 00 00 24
 2F 00 00 24
 30 00 A9 24
 31 00 1F 24
 size 56*/
static const uint16_t ak5703_reg_init5[][2] = {
	{ AK5703_LPFA_COEF_2, 0x00 },
	{ AK5703_LPFA_COEF_3, 0x00 },
	{ AK5703_RESERVED28, 0x00 },
	{ AK5703_RESERVED28, 0x00 },
	{ AK5703_RESERVED2A, 0x00 },
	{ AK5703_RESERVED2B, 0x00 },
	{ AK5703_RESERVED2C, 0x00 },
	{ AK5703_RESERVED2D, 0x00 },
	{ AK5703_RESERVED2E, 0xad },
	{ AK5703_RESERVED2F, 0x00 },
	{ AK5703_HPFB2_COEF_0, 0x09 },
	{ AK5703_HPFB2_COEF_1, 0x1f }
};

/*
 0B 00 00 00 00 00 00 00
 32 00 AD 24
 33 00 20 24
 34 00 00 24
 35 00 00 24
 36 00 00 24
 37 00 00 24
 01 00 08 24
 03 00 C4 24
 05 00 0B 24
 00 00 04 24
 size 48
 */
static const uint16_t ak5703_reg_init6[][2] = {
	{ AK5703_HPFB2_COEF_2, 0x0d },
	{ AK5703_HPFB2_COEF_3, 0x20 },
	{ AK5703_LPFB_COEF_0, 0x00 },
	{ AK5703_LPFB_COEF_1, 0x00 },
	{ AK5703_LPFB_COEF_2, 0x00 },
	{ AK5703_LPFB_COEF_3, 0x00 },
	{ AK5703_PLL_CONTROLA, 0x08 },
	{ AK5703_MIC_GAIN_ADJUSTA0, 0xc4 },
	{ AK5703_FS_SELECT_FILTER_CONTROLA, 0x0b },
	{ AK5703_POWER_MANAGEMENTA, 0x04 }
};

/*
 0B 00 00 00 00 00 00 00
 01 00 09 24
 size 12*/
static const uint16_t ak5703_reg_init7[][2] = {
	{ AK5703_PLL_CONTROLA, 0x09 }
};
/*
 0B 00 00 00 00 00 00 00
 00 00 0C 24
 10 00 08 24
 size 16*/
static const uint16_t ak5703_reg_init8[][2] = {
	{ AK5703_POWER_MANAGEMENTA, 0x0c },
	{ AK5703_POWER_MANAGEMENTB, 0x08 }
};
/*
 0B 00 00 00 00 00 00 00
 02 00 C0 24
 07 00 A8 24
 08 00 A8 24
 12 00 C0 24
 17 00 A8 24
 18 00 A8 24
 00 00 0F 24
 10 00 0B 24
 size 40*/
static const uint16_t ak5703_reg_init9[][2] = {
	{ AK5703_SIGNAL_MIC_GAIN_SELECTA, 0xc0 },
	{ AK5703_LCH_INPUT_VOLUME_CONTROLA, 0xa8 },
	{ AK5703_RCH_INPUT_VOLUME_CONTROLA, 0xa8 },
	{ AK5703_SIGNAL_MIC_GAIN_SELECTB, 0xc0 },
	{ AK5703_LCH_INPUT_VOLUME_CONTROLB, 0xa8 },
	{ AK5703_RCH_INPUT_VOLUME_CONTROLB, 0xa8 },
	{ AK5703_POWER_MANAGEMENTA, 0x0f },
	{ AK5703_POWER_MANAGEMENTB, 0x0b }
};

static const uint16_t ak5703_reg_read[32]={
	AK5703_POWER_MANAGEMENTA,
	AK5703_PLL_CONTROLA,
	AK5703_SIGNAL_MIC_GAIN_SELECTA,
	AK5703_MIC_GAIN_ADJUSTA0,
	AK5703_MIC_GAIN_ADJUSTA1,
	AK5703_FS_SELECT_FILTER_CONTROLA,
	AK5703_CLOCK_OUTPUT_SELECTA,
	AK5703_LCH_INPUT_VOLUME_CONTROLA,
	AK5703_RCH_INPUT_VOLUME_CONTROLA,
	AK5703_TIMER_SELECTA,
	AK5703_ALC_MODE_CONTROLA0,
	AK5703_ALC_MODE_CONTROLA1,
	AK5703_L1_CH_OUTPUT_DELAY_CONTROL,
	AK5703_R1_CH_OUTPUT_DELAY_CONTROL,
	AK5703_RESERVED0E,
	AK5703_RESERVED0F,
	AK5703_POWER_MANAGEMENTB,
	AK5703_RESERVED11,
	AK5703_SIGNAL_MIC_GAIN_SELECTB,
	AK5703_MIC_GAIN_ADJUSTB0,
	AK5703_MIC_GAIN_ADJUSTB1,
	AK5703_FILTER_CONTROLB,
	AK5703_CLOCK_OUTPUT_SELECTB,
	AK5703_LCH_INPUT_VOLUME_CONTROLB,
	AK5703_RCH_INPUT_VOLUME_CONTROLB,
	AK5703_TIMER_SELECTB,
	AK5703_ALC_MODE_CONTROLB0,
	AK5703_ALC_MODE_CONTROLB1,
	AK5703_L2_CH_OUTPUT_DELAY_CONTROL,
	AK5703_R2_CH_OUTPUT_DELAY_CONTROL,
	AK5703_RESERVED1E,
	AK5703_RESERVED1F
};

static const uint16_t ak5703_reg_read1[22]={
	AK5703_POWER_MANAGEMENTA,
	AK5703_PLL_CONTROLA,
	AK5703_SIGNAL_MIC_GAIN_SELECTA,
	AK5703_MIC_GAIN_ADJUSTA0,
	AK5703_MIC_GAIN_ADJUSTA1,
	AK5703_FS_SELECT_FILTER_CONTROLA,
	//AK5703_CLOCK_OUTPUT_SELECTA,
	AK5703_LCH_INPUT_VOLUME_CONTROLA,
	AK5703_RCH_INPUT_VOLUME_CONTROLA,
	AK5703_TIMER_SELECTA,
	AK5703_ALC_MODE_CONTROLA0,
	//AK5703_ALC_MODE_CONTROLA1,
	AK5703_L1_CH_OUTPUT_DELAY_CONTROL,
	AK5703_R1_CH_OUTPUT_DELAY_CONTROL,
	//AK5703_RESERVED0E,
	//AK5703_RESERVED0F,
	//AK5703_POWER_MANAGEMENTB,
	//AK5703_RESERVED11,
	AK5703_SIGNAL_MIC_GAIN_SELECTB,
	AK5703_MIC_GAIN_ADJUSTB0,
	AK5703_MIC_GAIN_ADJUSTB1,
	AK5703_FILTER_CONTROLB,
	//AK5703_CLOCK_OUTPUT_SELECTB,
	AK5703_LCH_INPUT_VOLUME_CONTROLB,
	AK5703_RCH_INPUT_VOLUME_CONTROLB,
	AK5703_TIMER_SELECTB,
	AK5703_ALC_MODE_CONTROLB0,
	//AK5703_ALC_MODE_CONTROLB1,
	AK5703_L2_CH_OUTPUT_DELAY_CONTROL,
	AK5703_R2_CH_OUTPUT_DELAY_CONTROL,
	//AK5703_RESERVED1E,
	//AK5703_RESERVED1F
};
/*
 03 00 00 00 00 00 00 00
 C6 15 20 FF
 size 12*/

static const uint16_t ov580_reg_init30[][2] = {
	{ 0x15c6, 0x20 }
};
/*
 03 00 00 00 00 00 00 00
 00 FF 03 FF
 size 12*/
static const uint16_t ov580_reg_init31[][2] = {
	{ 0xff00, 0x03 }
};
/*
 03 00 00 00 00 00 00 00
 C2 15 02 FF
 C1 15 7F FF
 C8 15 01 FF
 size 20*/
static const uint16_t ov580_reg_init32[][2] = {
	{ 0x15c2, 0x02 },
	{ 0x15c1, 0x7f },
	{ 0x15c8, 0x01 }
};
/*
 03 00 00 00 00 00 00 00
 C3 15 40 FF
 C4 15 40 FF
 size 16*/
static const uint16_t ov580_reg_init33[][2] = {
	{ 0x15c3, 0x40 },
	{ 0x15c4, 0x40 }
};
/*
 03 00 00 00 00 00 00 00
 00 10 FF FF
 01 10 FF FF
 00 13 18 FF
 size 20*/
static const uint16_t ov580_reg_init34[][2] = {
	{ 0x1000, 0xff },
	{ 0x1001, 0xff },
	{ 0x1300, 0x18 }
};
/*
 03 00 00 00 00 00 00 00
 00 15 06 FF
 01 15 0E FF
 02 15 22 FF
 03 15 4B FF
 04 15 59 FF
 05 15 66 FF
 06 15 72 FF
 07 15 7C FF
 08 15 84 FF
 09 15 8C FF
 0A 15 9A FF
 0B 15 A5 FF
 size 56*/
static const uint16_t ov580_reg_init35[][2] = {
	{ 0x1500, 0x06 },
	{ 0x1501, 0x0e },
	{ 0x1502, 0x22 },
	{ 0x1503, 0x4b },
	{ 0x1504, 0x59 },
	{ 0x1505, 0x66 },
	{ 0x1506, 0x72 },
	{ 0x1507, 0x7c },
	{ 0x1508, 0x84 },
	{ 0x1509, 0x8c },
	{ 0x150a, 0x9a },
	{ 0x150b, 0xa5 }
};
/*
 03 00 00 00 00 00 00 00
 0C 15 B5 FF
 0D 15 C3 FF
 0E 15 D6 FF
 40 15 06 FF
 41 15 0E FF
 42 15 22 FF
 43 15 4B FF
 44 15 59 FF
 45 15 66 FF
 46 15 72 FF
 47 15 7C FF
 48 15 84 FF
 size 56*/
static const uint16_t ov580_reg_init36[][2] = {
	{ 0x150c, 0xb5 },
	{ 0x150d, 0xc3 },
	{ 0x150e, 0xd6 },
	{ 0x1540, 0x06 },
	{ 0x1541, 0x0e },
	{ 0x1542, 0x22 },
	{ 0x1543, 0x4b },
	{ 0x1544, 0x59 },
	{ 0x1545, 0x66 },
	{ 0x1546, 0x72 },
	{ 0x1547, 0x7c },
	{ 0x1548, 0x84 }
};
/*
 03 00 00 00 00 00 00 00
 49 15 8C FF
 4A 15 9A FF
 4B 15 A5 FF
 4C 15 B5 FF
 4D 15 C3 FF
 4E 15 D6 FF
 size 32*/
static const uint16_t ov580_reg_init37[][2] = {
	{ 0x1549, 0x8c },
	{ 0x154a, 0x9a },
	{ 0x154b, 0xa5 },
	{ 0x154c, 0xb5 },
	{ 0x154d, 0xc3 },
	{ 0x154e, 0xd6 }
};
/*
 03 00 00 00 00 00 00 00
 0A 14 00 FF
 0B 14 08 FF
 00 14 70 FF
 0C 14 80 FF
 0D 14 FF FF
 0E 14 80 FF
 0F 14 81 FF
 size 36*/
static const uint16_t ov580_reg_init38[][2] = {
	{ 0x140a, 0x00 },
	{ 0x140b, 0x08 },
	{ 0x1400, 0x70 },
	{ 0x140c, 0x80 },
	{ 0x140d, 0xff },
	{ 0x140e, 0x80 },
	{ 0x140f, 0x81 }
};
/*
 03 00 00 00 00 00 00 00
 00 FF 03 FF
 size 12*/
static const uint16_t ov580_reg_init39[][2] = {
	{ 0xff00, 0x03 }
};
/*
 03 00 00 00 00 00 00 00
 C6 15 20 FF
 size 12*/
static const uint16_t ov580_reg_init40[][2] = {
	{ 0x15c6, 0x20 }
};
/*
 03 00 00 00 00 00 00 00
 00 FF 03 FF
 size 12*/
static const uint16_t ov580_reg_init41[][2] = {
	{ 0xff00, 0x03 }
};
/*
 03 00 00 00 00 00 00 00
 C2 15 02 FF
 C1 15 7F FF
 C8 15 01 FF
 size 20*/
static const uint16_t ov580_reg_init42[][2] = {
	{ 0x15c2, 0x02 },
	{ 0x15c1, 0x7f },
	{ 0x15c8, 0x01 }
};
/*
 03 00 00 00 00 00 00 00
 C3 15 40 FF
 C4 15 40 FF
 size 16*/
static const uint16_t ov580_reg_init43[][2] = {
	{ 0x15c3, 0x40 },
	{ 0x15c4, 0x40 }
};
/*
 03 00 00 00 00 00 00 00
 00 10 FF FF
 01 10 FF FF
 00 13 18 FF
 size 20*/
static const uint16_t ov580_reg_init44[][2] = {
	{ 0x1000, 0xff },
	{ 0x1001, 0xff },
	{ 0x1300, 0x18 }
};
/*
 03 00 00 00 00 00 00 00
 00 15 06 FF
 01 15 0E FF
 02 15 22 FF
 03 15 4B FF
 04 15 59 FF
 05 15 66 FF
 06 15 72 FF
 07 15 7C FF
 08 15 84 FF
 09 15 8C FF
 0A 15 9A FF
 0B 15 A5 FF
 size 56*/
static const uint16_t ov580_reg_init45[][2] = {
	{ 0x1500, 0x06 },
	{ 0x1501, 0x0e },
	{ 0x1502, 0x22 },
	{ 0x1503, 0x4b },
	{ 0x1504, 0x59 },
	{ 0x1505, 0x66 },
	{ 0x1506, 0x72 },
	{ 0x1507, 0x7c },
	{ 0x1508, 0x84 },
	{ 0x1509, 0x8c },
	{ 0x150a, 0x9a },
	{ 0x150b, 0xa5 }
};
/*
 03 00 00 00 00 00 00 00
 0C 15 B5 FF
 0D 15 C3 FF
 0E 15 D6 FF
 40 15 06 FF
 41 15 0E FF
 42 15 22 FF
 43 15 4B FF
 44 15 59 FF
 45 15 66 FF
 46 15 72 FF
 47 15 7C FF
 48 15 84 FF
 size 56*/
static const uint16_t ov580_reg_init46[][2] = {
	{ 0x150c, 0xb5 },
	{ 0x150d, 0xc3 },
	{ 0x150e, 0xd6 },
	{ 0x1540, 0x06 },
	{ 0x1541, 0x0e },
	{ 0x1542, 0x22 },
	{ 0x1543, 0x4b },
	{ 0x1544, 0x59 },
	{ 0x1545, 0x66 },
	{ 0x1546, 0x72 },
	{ 0x1547, 0x7c },
	{ 0x1548, 0x84 }
};
/*
 03 00 00 00 00 00 00 00
 49 15 8C FF
 4A 15 9A FF
 4B 15 A5 FF
 4C 15 B5 FF
 4D 15 C3 FF
 4E 15 D6 FF
 size 32*/
static const uint16_t ov580_reg_init47[][2] = {
	{ 0x1549, 0x8c },
	{ 0x154a, 0x9a },
	{ 0x154b, 0xa5 },
	{ 0x154c, 0xb5 },
	{ 0x154d, 0xc3 },
	{ 0x154e, 0xd6 }
};
/*
 03 00 00 00 00 00 00 00
 0A 14 00 FF
 0B 14 08 FF
 00 14 70 FF
 0C 14 80 FF
 0D 14 FF FF
 0E 14 80 FF
 0F 14 81 FF
 size 36*/
static const uint16_t ov580_reg_init48[][2] = {
	{ 0x140a, 0x00 },
	{ 0x140b, 0x08 },
	{ 0x1400, 0x70 },
	{ 0x140c, 0x80 },
	{ 0x140d, 0xff },
	{ 0x140e, 0x80 },
	{ 0x140f, 0x81 }
};
/*
 03 00 00 00 00 00 00 00
 00 FF 03 FF
 size 12*/
static const uint16_t ov580_reg_init49[][2] = {
	{ 0xff00, 0x03 }
};
static const uint16_t ov580_reg_stream_r[1]={
	0xff71
};

static const uint16_t ov580_reg_stream_w0[][2] = {
	{ 0xff70, 0xf1 }
};
static const uint16_t ov580_reg_stream_w1[][2] = {
	{ 0xff71, 0x01 }
};


/* VIDEO MODES*/
/* register list to check and read actual congiguration*/
static const uint16_t ov9713_video_mode_registers[29]={
	OV9713_X_EVEN_INC,
	OV9713_X_ODD_INC,
	OV9713_Y_EVEN_INC,
	OV9713_Y_ODD_INC,
	OV9713_SENSOR_CTRL_REGISTER0_14,
	OV9713_SENSOR_CTRL_REGISTER0_10,
	OV9713_TIMING_CTRL_REGISTER2_0,
	OV9713_TIMING_CTRL_REGISTER2_1,
	0x4144,
	OV9713_DEBUG_MODE_2,
	0x4142,
	OV9713_START_LINE,
	OV9713_BLC_CTRL2,
	OV9713_LINE_NUM,
	OV9713_FRAME_LENGTH_LINES_HI,
	OV9713_FRAME_LENGTH_LINES_LO,
	OV9713_LINE_LENGTH_PCK_HI,
	OV9713_LINE_LENGTH_PCK_LO,
	OV9713_Y_ADDR_END_LO,
	OV9713_X_OUTPUT_SIZE_HI,
	OV9713_X_OUTPUT_SIZE_LO,
	OV9713_Y_OUTPUT_SIZE_HI,
	OV9713_Y_OUTPUT_SIZE_LO,
	OV9713_TIMING_CTRL_REGISTER1_1,
	OV9713_TIMING_CTRL_REGISTER1_3,
	OV9713_PLL11,
	OV9713_PLL12,
	OV9713_PLL13,
	OV9713_PLL14
};
/*initialization video modes for OV9713 sensors*/
/* mode_select to 0 to stop suspend streaming*/
/* set registers*/
/* mode_select to 1 to resume suspend streaming*/
/* pll registers check datasheet fig 2-17*/
/* all of this reversed from firmware check sniffer dumps*/
/* Use uvc_set_video function instead. These registers are only for testing purposes*/


static const uint16_t ov9713_video_mode_0[][2]= {
    //mode 1280x804 frame lines vert 1112 horiz 1500 pll 5 6 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144,0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x58 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x06 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_1[][2]= {
    //mode 1280x804 frame lines vert 1112 horiz 1500 pll 5 3 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x58 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_2[][2]= {
    //mode 1280x804 frame lines vert 1112 horiz 1500 pll 5 3 2 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x58 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_3[][2]= {
    //mode 1280x804 frame lines vert 1112 horiz 1500 pll 5 3 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x58 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_4[][2]= {
    //mode 640x404 frame lines vert 556 horiz 1500 pll 5 3 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x03 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x73 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x42 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x2C },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x02 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x80 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x94 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x08 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_5[][2]= {
    //mode 320x196 frame lines vert 278 horiz 1500 pll 5 3 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x07 },
	{ OV9713_Y_EVEN_INC, 0x05 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0xF4 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x32 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x01 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x16 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x17 },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x40 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0xC4 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x04 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_6[][2]= {
    //mode 1280x804 frame lines vert 1064 horiz 1500 pll 5 6 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x28 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x06 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_7[][2]= {
    //mode 1280x804 frame lines vert 1064 horiz 1500 pll 5 3 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x28 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_8[][2]= {
    //mode 1280x804 frame lines vert 1064 horiz 1500 pll 5 3 2 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x28 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_9[][2]= {
    //mode 1280x804 frame lines vert 1064 horiz 1500 pll 5 3 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0024 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x28 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_10[][2]= {
    //mode 640x404 frame lines vert 532 horiz 1500 pll 5 3 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x03 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x73 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x42 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x14 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x02 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x80 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x94 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x08 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_11[][2]= {
    //mode 320x196 frame lines vert 266 horiz 1500 pll 5 3 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x07 },
	{ OV9713_Y_EVEN_INC, 0x05 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0xF4 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x32 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x01 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x0A },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x17 },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x40 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0xC4 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x04 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_12[][2]= {
    //mode 1280x804 frame lines vert 888 horiz 1500 pll 5 6 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x03 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x78 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x06 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_13[][2]= {
    //mode 1280x804 frame lines vert 888 horiz 1500 pll 5 3 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x03 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x78 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_14[][2]= {
    //mode 1280x804 frame lines vert 888 horiz 1500 pll 5 3 2 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x03 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x78 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_15[][2]= {
    //mode 1280x804 frame lines vert 888 horiz 1500 pll 5 3 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x03 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x78 },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2F },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_16[][2]= {
    //mode 1280x804 frame lines vert 828 horiz 1352 pll 7 a 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x03 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x3C },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0x48 },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x07 },
	{ OV9713_PLL12, 0x0A },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_17[][2]= {
    //mode 1280x804 frame lines vert 828 horiz 1352 pll 7 a 1 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x03 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x3C },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0x48 },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x07 },
	{ OV9713_PLL12, 0x0A },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_18[][2]= {
    //mode 1280x804 frame lines vert 828 horiz 1352 pll 7 a 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x03 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x3C },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0x48 },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x07 },
	{ OV9713_PLL12, 0x0A },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_19[][2]= {
    //mode 1280x804 frame lines vert 828 horiz 1352 pll 7 5 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x01 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x01 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x80 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x31 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x00 },
	{ 0x4144, 0x54 },
	{ OV9713_DEBUG_MODE_2, 0x60 },
	{ 0x4142, 0x24 },
	{ OV9713_START_LINE, 0x06 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x04 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x03 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0x3C },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0x48 },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x05 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x03 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x24 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x10 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x02 },
	{ OV9713_PLL11, 0x07 },
	{ OV9713_PLL12, 0x05 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_20[][2]= {
    //mode 640x404 frame lines vert 444 horiz 1500 pll 5 c 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x03 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x73 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x42 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142 , 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x01 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0xBC },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x02 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x80 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x94 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x08 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x0C },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_21[][2]= {
    //mode 640x404 frame lines vert 444 horiz 1500 pll 5 6 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x03 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x73 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x42 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x01 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0xBC },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x02 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x80 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x94 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x08 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x06 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_22[][2]= {
    //mode 640x404 frame lines vert 444 horiz 1500 pll 5 3 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x03 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x73 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x42 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x01 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0xBC },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x02 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x80 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x94 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x08 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_23[][2]= {
    //mode 640x404 frame lines vert 444 horiz 1500 pll 5 3 2 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x03 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x73 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x42 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x01 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0xBC },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x02 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x80 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x94 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x08 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_24[][2]= {
    //mode 640x404 frame lines vert 444 horiz 1500 pll 5 3 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x03 },
	{ OV9713_Y_EVEN_INC, 0x01 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0x73 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x42 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x01 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0xBC },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x2B },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x02 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x80 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0x94 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x08 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_25[][2]= {
    //mode 320x196 frame lines vert 222 horiz 1500 pll 5 6 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x07 },
	{ OV9713_Y_EVEN_INC, 0x05 },
	{ OV9713_Y_ODD_INC,0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0xF4 },
	{ OV9713_TIMING_CTRL_REGISTER2_0,  0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1,  0x01 },
	{ 0x4144, 0x32 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x00 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0xDE },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x17 },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x40 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0xC4 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x04 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x06 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_26[][2]= {
    //mode 320x196 frame lines vert 222 horiz 1500 pll 5 3 2 3
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x07 },
	{ OV9713_Y_EVEN_INC, 0x05 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0xF4 },
	{ OV9713_TIMING_CTRL_REGISTER2_0,  0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1,  0x01 },
	{ 0x4144, 0x32 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x00 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0xDE },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x17 },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x40 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0xC4 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x04 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x03 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_27[][2]= {
    //mode 320x196 frame lines vert 222 horiz 1500 pll 5 3 2 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x07 },
	{ OV9713_Y_EVEN_INC, 0x05 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0xF4 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x32 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x00 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0xDE },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x17 },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x40 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0xC4 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x04 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x02 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};

static const uint16_t ov9713_video_mode_28[][2]= {
    //mode 320x196 frame lines vert 222 horiz 1500 pll 5 3 1 2
	{ OV9713_MODE_SELECT, 0x00 },
	{ OV9713_X_EVEN_INC, 0x01 },
	{ OV9713_X_ODD_INC, 0x07 },
	{ OV9713_Y_EVEN_INC, 0x05 },
	{ OV9713_Y_ODD_INC, 0x03 },
	{ OV9713_SENSOR_CTRL_REGISTER0_14, 0x88 },
	{ OV9713_SENSOR_CTRL_REGISTER0_10, 0xF4 },
	{ OV9713_TIMING_CTRL_REGISTER2_0, 0x80 },
	{ OV9713_TIMING_CTRL_REGISTER2_1, 0x01 },
	{ 0x4144, 0x32 },
	{ OV9713_DEBUG_MODE_2, 0x68 },
	{ 0x4142, 0x14 },
	{ OV9713_START_LINE, 0x03 },
	{ OV9713_BLC_CTRL2, 0x45 },
	{ OV9713_LINE_NUM, 0x02 },
	{ OV9713_FRAME_LENGTH_LINES_HI, 0x00 },
	{ OV9713_FRAME_LENGTH_LINES_LO, 0xDE },
	{ OV9713_LINE_LENGTH_PCK_HI, 0x05 },
	{ OV9713_LINE_LENGTH_PCK_LO, 0xDC },
	{ OV9713_Y_ADDR_END_LO, 0x17 },
	{ OV9713_X_OUTPUT_SIZE_HI, 0x01 },
	{ OV9713_X_OUTPUT_SIZE_LO, 0x40 },
	{ OV9713_Y_OUTPUT_SIZE_HI, 0x00 },
	{ OV9713_Y_OUTPUT_SIZE_LO, 0xC4 },
	{ OV9713_TIMING_CTRL_REGISTER1_1, 0x04 },
	{ OV9713_TIMING_CTRL_REGISTER1_3, 0x00 },
	{ OV9713_PLL11, 0x05 },
	{ OV9713_PLL12, 0x03 },
	{ OV9713_PLL13, 0x01 },
	{ OV9713_PLL14, 0x02 },
	{ OV9713_MODE_SELECT, 0x01 }
};
