//
//  BMMoreView+Conference.h
//  BoomMeeting
//
//  Created by boom on 2021/4/6.
//

#import "BMMoreView.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMMoreView (conference)
- (instancetype)initConferenceWithMaster:(BOOL)master withCreateConfig:(BMCreateRoomConfig *)config;

- (void)changeConferenceMasterForView:(BOOL)master isLock:(BOOL)isLock;

- (CGFloat)conferenceExpectHeight;
- (CGFloat)conferenceExpectWidth;
@end

NS_ASSUME_NONNULL_END
