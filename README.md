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
