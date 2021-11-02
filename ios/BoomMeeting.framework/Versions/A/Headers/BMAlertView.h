//
//  BMAlertView.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/22.
//

#import <UIKit/UIKit.h>

/// 弹窗类型
/// - SimpleAlert: 简单样式   无按钮
/// - ConfirmAlert: 只有一个确认按钮的 弹窗样式
/// - CancelAndConfirmAlert: 有两个按钮的弹窗样式
typedef NS_ENUM(NSInteger, AlertStyle) {
    SimpleAlert = 0,
    ConfirmAlert,
    CancelAndConfirmAlert,
};

NS_ASSUME_NONNULL_BEGIN

@interface BMAlertView : UIView

- (instancetype)initWithStyle:(AlertStyle)style;

/**
 Description

 @param style style description
 @param width width description
 @return return value description
 */
- (instancetype)initWithStyle:(AlertStyle)style width:(CGFloat)width;

/**
 销毁页面
 */
- (void)exit;

/**
 确认按钮 block
 */
@property (nonatomic, copy) void(^confirm)(void);

/**
 取消按钮 block
 */
@property (nonatomic, copy) void(^cancel)(void);

/**
 主题
 */
@property (nonatomic,assign)UIColor *theme;

/**
 弹窗 view
 */
@property(nonatomic,strong)UIView *mainView;


/**
 弹窗内容的View
 */
@property (nonatomic,strong)UIView *contentView;
/// 头部的标题 label
@property(nonatomic,strong)UILabel *headerTitleLabel;

/// 弹窗内容 label
@property(nonatomic,strong)UILabel *contentTextLabel;

/**
 关闭按钮 button

 */
@property(nonatomic,strong)UIButton *closedButton;
/**
 确认按钮 button
 */
@property(nonatomic,strong)UIButton *confirmButton;

/**
 取消按钮 button
 */
@property(nonatomic,strong)UIButton *cancelButton;

/**
 点击背景是否可关闭弹窗
 */
@property (nonatomic,assign)BOOL isClickBackgroundCloseWindow;

+ (void)alertWillMuteSelfopen:(BOOL)selfopen doneCallback:(void (^)(BOOL))doneCallback;

/// 改名的弹窗
+ (void)alertWithChangeName:(NSString *)nickname callback:(void (^)(NSString *))callback;

@end

NS_ASSUME_NONNULL_END
