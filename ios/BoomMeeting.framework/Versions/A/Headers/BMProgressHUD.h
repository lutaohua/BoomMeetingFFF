//
//  BMProgressHUD.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/3.
//

#import <UIKit/UIKit.h>
#import <BJLiveBase/BJLMBProgressHUD.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMProgressHUD : UIView
+ (void)showSuccess:(NSString *)success toView:(UIView *_Nullable)view;
+ (void)showError:(NSString *)error toView:(UIView *_Nullable)view;

+ (BJLMBProgressHUD *)showLoading:(NSString *)message toView:(UIView *_Nullable)view;


+ (void)showSuccess:(NSString *)success;
+ (void)showI18nSuccess:(NSString *)success;
+ (void)showSuccess:(NSString *)success afterDelay:(CGFloat)delay;
+ (void)showError:(NSString *)error;
+ (void)showError:(NSString *)error afterDelay:(CGFloat)delay;

+ (BJLMBProgressHUD *)showLoading:(NSString *)message;

+ (void)hideHUDForView:(UIView *_Nullable)view;
+ (void)hideHUD;
@end

NS_ASSUME_NONNULL_END
