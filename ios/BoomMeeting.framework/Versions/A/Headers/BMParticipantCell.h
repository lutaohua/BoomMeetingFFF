//
//  BMParticipantCell.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/18.
//

#import <UIKit/UIKit.h>
@class BMUser;

NS_ASSUME_NONNULL_BEGIN

@interface BMParticipantCell : UITableViewCell
@property (nonatomic, strong) BMUser *user;

///初始化参会者cell
///param：isViewer是否是嘉宾标识
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier isViewer:(BOOL)isViewer;
@end


NS_ASSUME_NONNULL_END
