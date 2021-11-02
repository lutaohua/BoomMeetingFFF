//
//  BMSpeakerVideoCell.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/1.
//

#import <UIKit/UIKit.h>
#import "BMVideoCell.h"

typedef void (^ClickSmallVideo)(BMStreamModel * _Nonnull streamModel);

NS_ASSUME_NONNULL_BEGIN

@interface BMSpeakerVideoCell : BMVideoCell

@property (nonatomic, strong) BMStreamModel *smallModel;
@property (nonatomic, copy) ClickSmallVideo clickSmallVideo;

- (void)updateSmallMicWithVolume;

@end

NS_ASSUME_NONNULL_END
