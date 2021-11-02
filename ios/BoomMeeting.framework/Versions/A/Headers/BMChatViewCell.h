//
//  BMChatViewCell.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/26.
//

#import <UIKit/UIKit.h>
@class BMMessageInfo;

NS_ASSUME_NONNULL_BEGIN

@interface BMChatViewCell : UITableViewCell

@property (nonatomic, strong) BMMessageInfo *message;
//- (instan)initW

@end

NS_ASSUME_NONNULL_END
