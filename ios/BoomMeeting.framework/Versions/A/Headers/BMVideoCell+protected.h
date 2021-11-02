//
//  BMVideoCell.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/25.
//

#import <UIKit/UIKit.h>
#import <BoomCore/BoomCore_i.h>
#import <BJLiveBase/BJLiveBase.h>
#import "BoomCoreAPI.h"
#import "BMStreamModel.h"
#import "BMMutliClickButton.h"
#import "UIColor+BM.h"
#import "UIImage+BM.h"
#import "BMUser.h"
#import "BMUserInfo.h"
#import "UIUtil.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMVideoCell ()<BCCanvasDelegate>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *dataList;
/// 头像包装类   在这个视图上面添加添加的控件, 将不接收点击事件.
@property (nonatomic, weak) UIView *wrapAvatorView;
/// 身份,mic, 昵称
@property (nonatomic) UIView *wrapRoleView;
@property (nonatomic) UIView *loadingV;
- (void)refreshDebugInfo:(NSArray *)dataList;

@end

NS_ASSUME_NONNULL_END
