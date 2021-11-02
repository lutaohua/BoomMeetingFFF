//
//  Util.h
//  BRTC-iDemo
//
//  Created by zhaozhidan on 2020/8/20.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIImage+BM.h"
#import "UIColor+BM.h"
#import "BMBundle.h"

#define BMDeviceHeight [[UIScreen mainScreen] bounds].size.height
#define BMDeviceWidth [[UIScreen mainScreen] bounds].size.width
#define BMScaleWidth (BMDeviceWidth/375 > 1.104 ? 1.104 : BMDeviceWidth/375)

NS_ASSUME_NONNULL_BEGIN

static inline BOOL is_iPhoneXSeries() {
    if (@available(iOS 11.0, *)) {
        static const CGFloat insetsLimit = 20.0;
        UIEdgeInsets insets = UIApplication.sharedApplication.delegate.window.safeAreaInsets;
        return (insets.top > insetsLimit
                || insets.left > insetsLimit
                || insets.right > insetsLimit
                || insets.bottom > insetsLimit);
    }
    return NO;
}

/// 是否是横屏
static inline BOOL BMIsLandscape() {
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    return orientation == UIDeviceOrientationLandscapeRight ||
    orientation == UIDeviceOrientationLandscapeLeft;
}

static inline UIEdgeInsets BMSafeAreaInsets() {
    if (@available(iOS 11.0, *)) {
        UIEdgeInsets insets = UIApplication.sharedApplication.delegate.window.safeAreaInsets;
        return insets;
    }
    return UIEdgeInsetsMake(0, 0, 0, 0);
}

static inline float BMSafeAreaInsetsTop() {
    return BMSafeAreaInsets().top;
}

static inline float safeAreaInsetsBottom() {
    return BMSafeAreaInsets().bottom;
}

@interface UIView (CornerRadius)
- (UIView *)clipCornerWithView:(UIView *)originView
                    andTopLeft:(BOOL)topLeft
                   andTopRight:(BOOL)topRight
                 andBottomLeft:(BOOL)bottomLeft
                andBottomRight:(BOOL)bottomRight;
@end


@interface UIUtil : NSObject
/// 设置竖屏
+ (void)lockToPortrait;
/// 设置横屏
+ (void)lockToLandscape;


/// 可以创建多个事件的 action
+ (UIAlertController *)setupActionSheet:(NSString *)title actionNames:(NSArray *)actionNames callback:(void (^)(NSString * _Nonnull))callback;

/// 修改昵称弹窗
+ (UIAlertController *)modifyNicknameAlert:(NSString *)title nickname:(NSString *)nickname callback:(void (^)(NSString * _Nullable input))callback;

+ (UIAlertController *)alertTips:(NSString *)title callback:(void (^)(BOOL isDone))callback;
+ (UIAlertController *)alertTips:(NSString *)title cancleTit:(NSString *)cancleTit doneTit:(NSString *)doneTit callback:(void (^)(BOOL isDone))callback;
+ (void)alertTips:(NSString *)title message:(NSString *)message cancleTit:(NSString *)cancleTit doneTit:(NSString *)doneTit callback:(void (^)(BOOL isDone))callback;

+ (UIAlertController *)alertSigleTips:(NSString *)title callback:(void (^)(void))callback;
+ (UIAlertController *)alertSigleTips:(NSString *)title message:(NSString *)message callback:(void (^)(void))callback;
+ (UIAlertController *)alertSigleDelayTips:(NSString *)title message:(NSString *)message callback:(void (^)(void))callback;

+ (UIAlertController *)alertTips:(NSString *)title message:(NSString *)message callback:(void (^)(BOOL isDone))callback;

+ (NSString *)roomDuration:(NSUInteger)timestamp;

/// 对会议号添加空格
+ (NSString *)encodeRoomNumber:(NSString *)roomNumber;
///
+ (NSString *)decodeRoomNumber:(NSString *)roomNumber;


+ (UIImage *)micLevelImage:(NSUInteger)volume;
+ (UIImage *)micLevelLightImage:(NSUInteger)volume;

+ (NSString *)roomCountdown:(NSUInteger)countdown;
@end

NS_ASSUME_NONNULL_END
