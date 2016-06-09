//
// Created by School on 6/8/16.
//

#include "gtest/gtest.h"
#include "syscalls.h"

/* some RGB color definitions                                                 */
#define Black           0x0000      /*   0,   0,   0 */
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255,   0 */
#define White           0xFFFF      /* 255, 255, 255 */
#define Orange          0xFD20      /* 255, 165,   0 */
#define GreenYellow     0xAFE5      /* 173, 255,  47 */

TEST(BasicTest, White) {
    ASSERT_EQ(Black, rgb(0, 0, 0));
    ASSERT_EQ(Navy, rgb(0, 0, 128));
    ASSERT_EQ(DarkGreen, rgb(0, 128, 0));
    ASSERT_EQ(DarkCyan, rgb(0, 128, 128));
    ASSERT_EQ(Maroon, rgb(128, 0, 0));
    ASSERT_EQ(Purple, rgb(128, 0, 128));
    ASSERT_EQ(Olive, rgb(128, 128, 0));
    ASSERT_EQ(LightGrey, rgb(192, 192, 192));
    ASSERT_EQ(DarkGrey, rgb(128, 128, 128));
    ASSERT_EQ(Blue, rgb(0, 0, 255));
    ASSERT_EQ(Green, rgb(0, 255, 0));
    ASSERT_EQ(Cyan, rgb(0, 255, 255));
    ASSERT_EQ(Red, rgb(255, 0, 0));
    ASSERT_EQ(Magenta, rgb(255, 0, 255));
    ASSERT_EQ(Yellow, rgb(255, 255, 0));
    ASSERT_EQ(White, rgb(255, 255, 255));
    ASSERT_EQ(Orange, rgb(255, 165, 0));
    ASSERT_EQ(GreenYellow, rgb(173, 255, 47));
}
