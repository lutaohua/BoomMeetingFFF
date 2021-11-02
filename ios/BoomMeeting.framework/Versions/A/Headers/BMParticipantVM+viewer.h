//
//  BMParticipantVM+viewer.h
//  BoomMeeting
//
//  Created by boom on 2021/3/30.
//

#import "BMParticipantVM.h"
#import "ServiceApi.h"
NS_ASSUME_NONNULL_BEGIN

@interface BMParticipantVM (viewer)


///短连接获取用户数据
- (void)getViewerListWithIndexPage:(NSString *)indexPage withRoomId:(NSString *)roomId isPullDown:(BOOL)isPullDown success:(SuccessCallback)success;

@end

NS_ASSUME_NONNULL_END
