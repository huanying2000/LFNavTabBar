//
//  LFNavTabBar.h
//  TLFNavTabNar
//
//  Created by mac on 17/2/22.
//  Copyright © 2017年 mac. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LFNavTabBarDelegate <NSObject>

@optional

- (void)itemDidSelectedWithIndex:(NSInteger)index;

- (void)shouldPopNavgationItemMenu:(BOOL)pop height:(CGFloat)height;

@end


@interface LFNavTabBar : UIView

@property (nonatomic,weak) id <LFNavTabBarDelegate>delegate;

@property (nonatomic,assign) NSInteger currentItemIndex;

@property (nonatomic,strong) NSArray *itemTitles;

@property (nonatomic,strong) UIColor *lineClolr;

@property (nonatomic,strong) UIImage *arrowImage;

- (id)initWithFrame:(CGRect)frame showArrowButton:(BOOL)show;

- (void)updateData;

- (void)refresh;

@end
