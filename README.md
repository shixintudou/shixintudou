2021/03/19
我是狮心土豆，我今天就要开始写实习任务了。现在正准备做一个复刻黑帝斯，好难啊呜呜呜。

2021/03/19
处理了一堆事务后终于有时间了，稍微试玩了一下黑帝斯，总之上下左右基本移动，空格冲刺，不同武器不同的攻击方式，主角和怪物会发出两种不同弹体，主角的弹体会随buff变化。
至于紧张的boss战，这是啥，boss呢，我已经菜到连boss都见不到了吗。

2021/03/20
4g大文件怎么都传不上github，我还是老老实实先用平面和方块吧。

2021/03/20
移动和镜头跟随很容易完成，但总感觉差那么点味道。感觉要好好调一下镜头才能实现原版那样刚好斜着走的效果。

2021/03/20
貌似问题不在镜头，而在场景？先看看把平面斜着搭怎么样。

2021/03/20
把平面转了45度，感觉好多了。

2021/03/20
要被github折磨疯了

2021/03/20
稍微搞清楚了PlayerController,墙壁的boxcolider,不能设置为触发器，角色移动用Move，终于不穿模了。

2021/03/20
冲刺效果算是做出来了，就是搞得和瞬移一样，研究一下怎么冲刺得更加平滑。

2021/03/20
运用deltatime计时，算是做出了比较平滑的冲刺。中途因为判定冲刺时间用了等于=0导致冲刺无法停止，改为绝对值小于0.05解决了问题。

2021/03/20
武器和弹体又给我整懵了。

2021/03/20
找了点武器资源，自己录了一个小动画，近战武器算是完成了。通过对摄像机渲染层的修改实现了武器的显示与消失，并且能够播放简单（简陋）的动画。修改渲染层竟然是位运算，头一次在实战用上。

2021/03/20
尝试编写敌人寻路ai。

2021/03/20
写了一点敌人路点，顺便做了个重击效果。近战类武器感觉都还好，不知道到时候远程武器要怎么弄。

2021/03/20
寻路出bug了，而且敌人走的时候碰撞体又消失了，貌似用translate移动不能触发碰撞。

2021/03/21
敌人寻路依然有问题，攻击判定目前做的也存在一些问题。啊啊啊啊星期天了还早八晚九。

2021/03/21
遇到了紧张刺激的boss战，不过这东西到底怎么做。

2021/03/21
代理设置的差不多了，就是感觉追主角时容易挤在一起，目前地图还是互通的平面，不过好歹这些家伙不会走到空气里面了。

2021/03/21
利用空物体设置路点，结合navmeshagent完成了随机行走，当与主角距离过近时会朝向主角行走。

2021/03/22
0.2版本终于上传完成，花了好长时间，接下来的版本上传应该不用再费这么大功夫了。

2021/03/22
之前代码写得比较乱，现在写伤害判定时逻辑比较混乱。

2021/03/22
逻辑实在是过于混乱，鉴于之前录了一个小小的大剑动画，动画帧事件貌似是一个不错的选择。

2021/03/22
确实是每播放一次动画调用一次方法，然而主角还是能一次打出几千的伤害。

2021/03/22
游戏程序的结构是游戏开发中很重要的一个因素，很明显我现在的程序就像一团乱麻。

2021/03/22
更改主角伤害方法，使其只改变敌人状态的受击的BooL变量，将敌人的降低HP判定写进FixedUpdate中，使得受击判定大大减少。

2021/03/22
重调动画帧事件的方法，终于是做到了发生一次动画调用一次受伤判定，但是感觉一环套一环，耦合度又提高了。

2021/03/22
敌人死亡并销毁后就开始报错，都是各种引用的问题，目前还没有什么头绪。

2021/03/22
尝试改变函数调用方式来解决问题。

2021/03/23
成功让死亡敌人正常消失。

2021/03/23
敌人受击变红效果显示正常。

2021/03/23
尝试利用碰撞检测制作敌人及主角的弹体攻击。

2021/03/23
没想到之前给敌人加的"shootable"标签还挺有用。

2021/03/23
感觉碰撞检测还是存在问题，弹体碰撞到敌人后也未能造成伤害。

2021/03/23
为什么给刚体施加力会让它飞起来。

2021/03/23
弹体不需要产生碰撞后的物理效果，似乎可以将弹体设置为触发器。

2021/03/23
关于刚体和碰撞体的文档仍需仔细阅读。

2021/03/23
弹体运动已经正常，不再出现出现鬼畜的碰撞效果，但碰撞检测依然存在问题。

2021/03/23
将弹体设置为运动触发刚体，但依然无法触发碰撞检测。

2021/03/24
主角远程攻击完成，之前一直没判定成功竟然是因为我把碰撞体加成了角色控制器。顺便修改了主角模型，更加容易判断主角站位方向。

2021/03/24
准备完善敌人的攻击。
