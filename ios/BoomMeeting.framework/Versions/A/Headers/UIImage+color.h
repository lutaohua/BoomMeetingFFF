//
//  UIImage+color.h
//  BoomMeeting
//
//  Created by  赵志丹 on 16/5/17.
//  Copyright © 2016年 BoomMeeting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (color)
/** 根据颜色和大小生成图片 */
+ (UIImage *)bmImageWithColor:(UIColor *)color size:(CGSize)size;

+ (UIImage *)generyImageWithColor:(UIColor *)color size:(CGSize)size;

- (UIImage *)imageByResizeToSize:(CGSize)size contentMode:(UIViewContentMode)contentMode;

+ (UIImage *)generyDotImg:(UIColor *)color size:(CGSize)size;

/// 把两张图片合成一张图片
- (UIImage *)mergeActityImages:(UIImage *)mergeImage margainRight:(CGFloat)margainRight margainBottom:(CGFloat)margainBottom;
@end
