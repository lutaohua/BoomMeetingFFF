//
//  UIColor+BM.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/25.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (BM)

#pragma mark - 颜色函数
/// 使用十六进制数字生成颜色
///
/// @param hex hex，格式 0xFFEEDD
///
/// @return UIColor
+ (nonnull instancetype)bm_colorWithHex:(u_int32_t)hex;
+ (instancetype)bm_colorWithHex:(u_int32_t)hex alpha:(CGFloat)alpha;
/// 使用指定的 r / g / b 数值生成颜色
///
/// @param red   red
/// @param green green
/// @param blue  blue
///
/// @return UIColor
+ (instancetype)bm_colorWithRed:(u_int8_t)red green:(u_int8_t)green blue:(u_int8_t)blue alpha:(CGFloat)alpha;

/// 生成随机颜色
///
/// @return UIColor
+ (nonnull instancetype)bm_randomColor;

#pragma mark - 颜色值
/// 返回当前颜色的 red 的 0～255 值
- (u_int8_t)bm_redValue;
/// 返回当前颜色的 green 的 0～255 值
- (u_int8_t)bm_greenValue;
/// 返回当前颜色的 blue 的 0～255 值
- (u_int8_t)bm_blueValue;
/// 返回当前颜色的 alpha 值
- (CGFloat)bm_alphaValue;

@end

NS_ASSUME_NONNULL_END
