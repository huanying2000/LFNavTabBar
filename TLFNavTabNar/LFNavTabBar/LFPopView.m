//
//  LFPopView.m
//  TLFNavTabNar
//
//  Created by mac on 17/2/22.
//  Copyright © 2017年 mac. All rights reserved.
//

#import "LFPopView.h"
#import "CommonMacro.h"

//这个界面就是点击加号出来的界面
@implementation LFPopView



- (void) setItemNames:(NSArray *)itemNames {
    
    _itemNames = itemNames;
    NSArray *itemWidths = [self getButtonsWidthWithTitles:itemNames];
    //根据Button的宽度布局
    [self updateSubViewsWithItemWidths:itemWidths];
    
}

//根据每个title计算出每个button的宽度 并装进一个数组
- (NSArray *)getButtonsWidthWithTitles:(NSArray *)titles {
    
    NSMutableArray *widths = [@[] mutableCopy];
    //字体的大小 想要设置颜色 也可以在这里添加
    NSMutableDictionary *attributs = [[NSMutableDictionary alloc] init];
    attributs[NSFontAttributeName] = [UIFont systemFontOfSize:[UIFont systemFontSize]];
    for (NSString *title in titles) {
        CGSize size = [title sizeWithAttributes:attributs];
        NSNumber *width = [NSNumber numberWithFloat:(size.width + 40.0f)];
        [widths addObject:width];
    }
    return widths;
}

- (void)updateSubViewsWithItemWidths:(NSArray *)itemWidths {
    //从零开始
    CGFloat buttonX = DOT_COORDINATE;
    CGFloat buttonY = DOT_COORDINATE;
    for (NSInteger index = 0; index < itemWidths.count; index ++) {
        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
        button.tag = index;
        // ITEM_HEIGHT 44
        button.frame = CGRectMake(buttonX, buttonY, [itemWidths[index] floatValue], ITEM_HEIGHT);
        [button setTitle:_itemNames[index] forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button addTarget:self action:@selector(itemPressed:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:button];
        buttonX += [itemWidths[index] floatValue];
        
        @try {
            if ((buttonX + [itemWidths[index + 1] floatValue]) >= SCREEN_WIDTH) {
                buttonX = DOT_COORDINATE;
                buttonY += ITEM_HEIGHT;
            }
        } @catch (NSException *exception) {
            
        } @finally {
            
        }
    }
    
}

- (void)itemPressed:(UIButton *)button {
    [_delegate itemPressedWithIndex:button.tag];
}



@end
