//
//  BMTestCell.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/3.
//

#import <UIKit/UIKit.h>
#import "BMMutliClickButton.h"
@class BMStreamModel;

NS_ASSUME_NONNULL_BEGIN

@interface BMTestCell : UICollectionViewCell
@property (nonatomic, weak) IBOutlet UILabel *lbText;
@property (nonatomic, weak) IBOutlet BMMutliClickButton *btnVideo;


@property (nonatomic, strong) BMStreamModel *streamModel;


- (void)setupUI;
- (void)willDisplayCell;
- (void)didEndDisplayingCell;
@end

NS_ASSUME_NONNULL_END
