//
//  LFPopView.h
//  TLFNavTabNar
//
//  Created by mac on 17/2/22.
//  Copyright © 2017年 mac. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LFPopViewDelagte <NSObject>

@optional

- (void) viewHeight:(CGFloat) height;

- (void)itemPressedWithIndex:(NSInteger)index;

@end


@interface LFPopView : UIView


@property (nonatomic,weak) id <LFPopViewDelagte>delegate;

@property (nonatomic,strong) NSArray *itemNames;

@end
