//
//  BMRaiseCell.h
//  BoomMeeting
//
//  Created by boom on 2021/3/26.
//

#import <UIKit/UIKit.h>
@class BMUser;

NS_ASSUME_NONNULL_BEGIN

@interface BMRaiseCell : UITableViewCell

@property(nonatomic,strong) UIImageView *imgvIcon;
@property(nonatomic,strong) UILabel *userName;
@property(nonatomic,strong) UILabel *userRole;

@property(nonatomic,strong) UIButton *refuseBtn;
@property(nonatomic,strong) UIButton *agreeBtn;


/// 主持人同意 or 拒绝 按钮回调
@property(nonatomic, copy) void(^agreeBtnClick)(BOOL isAgree, BMUser *user);
@property (nonatomic, strong) BMUser *user;

- (instancetype)initWithFrame:(CGRect)frame;
@end

NS_ASSUME_NONNULL_END
