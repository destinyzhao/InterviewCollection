//
//  InterviewQA.h
//  InterviewCollection
//
//  Created by Alex on 15/11/4.
//  Copyright © 2015年 Alex. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface InterviewQA : NSObject

/*
Q:@property 后面可以有哪些修饰符？
A:
原子性分为nonatomic和atomic,
读写分为readonly和readwrite,
内存管理方式分为assign, weak, strong, copy, unsafe_unretained
方法指定为:getter=XXX, setter=XXX
 
 
Q:什么情况使用 weak 关键字，相比 assign 有什么不同？
A:
assign 用于非指针变量用于基础数据类型,是指针赋值，不对引用计数操作，使用之后如果没有置为nil，
 可能就会产生野指针；而weak一旦不进行使用后，永远不会使用了，就不会产生野指针！
 
 
Q:copy 和 retain 的区别
A:copy： 建立一个索引计数为1的对象，然后释放旧对象
 retain：释放旧的对象，将旧对象的值赋予输入对象，再提高输入对象的索引计数为1
 
 
Q:怎么用 copy 关键字？
A:当一个指针指向的对象属性值发生改变时，不影响另一个对象的时候使用Copy


Q:这个写法会出什么问题： @property (copy) NSMutableArray *array;
A:外面不管传值为NSMutableArray和NSArray对象，array都是NSArray，
 编译器编译时还是会认为是NSMutableArray,调用addObject就会崩溃
 

Q:如何让自己的类用 copy 修饰符？如何重写带 copy 关键字的 setter？

 
Q:@property 的本质是什么？ivar、getter、setter 是如何生成并添加到这个类中的
A: @property的本质应该是告诉编译器, 按照给定的管理方式来生成属性的getter和setter方法: getter是直接生成属性同名的方法, setter是加上set前缀, 大写属性第一个字母并需要传入属性类型的变量的方法
 关于ivar, 应该是直接在类的结构体中, 加入到ivars的list中就好了

 
Q:runtime 如何实现 weak 属性
A:首先会调用objc_initWeak(&obj1, obj);
 在一系列检查之后会调用objc_storeWeak(id location, id value);
 storeweak操作会调用unregister移除旧对象在weak表中的指向信息(如有)
 最后location = newObj; 然后register新对象的weak表中的指向信息

 
Q:weak属性需要在dealloc中置nil么？
A:不需要, weak并不引用指向对象
 
 
Q:@synthesize和@dynamic分别有什么作用？
A: @synthesize原来用作生成getter和setter方法
   @dynamic是告诉编译器不需要由它来声明getter和setter方法, 要自己实现, 常见于coredata


Q:ARC下，不显示指定任何属性关键字时，默认的关键字都有哪些？
A:内存管理方式应该是编译器会根据属性类型来加上不同的管理策略, 如果是对象类型的, 则默认是strong, 如果不是,
 则会是简单是assign.

 
Q:用@property声明的NSString（或NSArray，NSDictionary）经常使用copy关键字，为什么？
 如果改用strong关键字，可能造成什么问题？
A:防止这些属性在不知情的情况下被修改, 这种情况比较难DEBUG, 使用strong会暴露这个问题
 

Q:在有了自动合成属性实例变量之后，@synthesize还有哪些使用场景？
A: 如果不爽@property给你自定义的加“_”的方式, 可以自己指定
 实现一个协议, 这个协议里面有@property, 但是不会自动synthesize, 所以要自己写@synthesize (propertyName) = _(propertyName)
 
 
Q:objc中向一个nil对象发送消息将会发生什么？
A: 直接返回nil, 因为发送消息底层是调用objc_msgSend(), 如果对象为空, 会直接返回nil
 

Q:objc中向一个对象发送消息[obj foo]和objc_msgSend()函数之间有什么关系？
A: 发送消息底层由objc_msgSend()实现.


Q:什么时候会报unrecognized selector的异常？
A:头文件或者delegate中声明了某个方法却没有被实现

 
Q:一个objc对象的isa的指针指向什么？有什么作用？
A: 指向这个类的类型本身, 保存对象的类型信息
 

Q:使用runtime Associate方法关联的对象，需要在主对象dealloc的时候释放么？
A: 不需要, 会在对象生命周期结束后自动释放;
 

Q:runtime如何实现weak变量的自动置nil？
A:runtime对注册的类会进行布局, 对于weak对象会放入到一张hash表中. 用weak对象地址作为key, 
 当对象的引用计数器为0的时候会dealloc, 进而在这个weak表中找到此对象地址为键的所有weak对象, 从而设置为nil
 

Q:runloop的mode作用是什么？
A:runloop mode是一组需要监听的输入源和定时器以及一组要被通知runloop的观察者
 

Q:以+ scheduledTimerWithTimeInterval...的方式触发的timer，在滑动页面上的列表时，timer会暂定回调，为什么？如何解决？
A: 与runloop的mode有关, NSTimer运行在Default Mode下, 而滑动页面列表会让主线程的runloop设置为TrackingRunLoopMode, 这个时候NSTimer是不能fire的.
 
 
Q:ARC通过什么方式帮助开发者管理内存？
A: 编译器在恰当的地方增加retain release方法
 

Q:BAD_ACCESS在什么情况下出现？
A: 访问已经释放对象的成员变量或者发消息
 

Q:在block内如何修改block外部变量？
A: 在变量前加上__block关键字
 
 
Q:使用系统的某些block api（如UIView的block版本写动画时），是否也考虑引用循环问题？
A: 不需要, 因为对象并没有持有这个block
 
 
 
 
 
 
 
 
 
 
 
 

*/

@end
