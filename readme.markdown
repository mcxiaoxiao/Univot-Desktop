**哈尔滨理工大学**

**软件与微电子学院**

**《课程实践（程序设计基础）》**

**项目实践报告**

  ---------------- ------------------------------------------------------
  **题 目**        ：实时投票可视化系统的设计与实现

  **班 级**        ：数据22-1班

  **专 业**        ：数据科学与大数据技术

  **姓名**         ：郭子铭

  **学号**         ：2204050108

  **指导教师**     ：叶子

  **日期**         ：2023年2月14日
  ---------------- ------------------------------------------------------

**目录**

[一、 需求分析 2](#需求分析)

[系统的开发背景 2](#系统的开发背景)

[开发该系统的意义 2](#开发该系统的意义)

[该系统的主要功能: 3](#该系统的主要功能)

[二、系统设计 4](#二系统设计)

[（一）系统的概要设计 4](#一系统的概要设计)

[（二）系统的详细设计 5](#二系统的详细设计)

[总体设计 6](#__RefHeading___Toc127703000)

[首页 7](#__RefHeading___Toc127703001)

[设置页 7](#__RefHeading___Toc127703002)

[欢迎页 7](#__RefHeading___Toc127703003)

[投票提交页 7](#__RefHeading___Toc127703004)

[三、系统实现、测试和维护 8](#三系统实现测试和维护)

[（一）系统开发相关资源 8](#一系统开发相关资源)

[（二）系统的核心数据结构和算法 8](#二系统的核心数据结构和算法)

[五、总结 26](#五总结)

# 需求分析

## 系统的开发背景

首先，随着社会的发展,民主政治的扩展,人们对信息的需求量也会日益曾多。面对庞大的信息量我们需要有在线投票系统来提高工作的效率。通过投票的系统可以做到信息采集和调查、能科学的统计和快速查询、投票等,从而减少信息采集方面的工作量。

其次，"信息茧房"的概念近几年频频受到关注。"信息茧房"是指人们关注的信息领域会习惯性地被自己的兴趣所引导，从而将自己的生活桎梏于像蚕茧一般的"茧房"中的现象。由于信息技术提供了更自我的思想空间和任何领域的巨量知识，一些人还可能进一步逃避社会中的种种矛盾，成为与世隔绝的孤立者。在社群内的交流更加高效的同时，社群之间的沟通并不见得一定会比信息匮乏的时代更加顺畅和有效。投票社区为深陷现代网络社群的桎梏的人们提供了一个"开眼看世界"的工具，人们可以通过投票平台看到不同种族、不同文化背景、不同宗教信仰、不同国家或不同区域的人们之间观念的区别。

另外，投票类社区所得到的关注也在日益增加，许多网站、平台（例如微博、知乎、抖音、qq、bilibili）选择开发投票功能作为社区功能的补充。由此可见投票系统在今天的互联网有着重要的作用。

## 开发该系统的意义

使用该系统的人们或开发者能够利用该系统快速寻找、创建和浏览实时投票,对于个人用户系统可以快速创建和分享投票并且观察实时投票反馈；对于开发者来说该系统可以利用已准备好的api接口、数据库、前端框架以缩短开发者自己宝贵的时间,有效的提高应用开发效率。（由于构思中为工程师提供api接口的部分与课程设计使用c++面向对象程序分析和设计的思想的要求相距较远，本次课程设计将侧重于客户端的实现，希望谅解。）

作为一个轻量化的实时投票可视化系统，用户可以便捷的发现、创建投票并实时查看反馈，不仅可以满足人们信息采集的需求也能作为人们观察世界、充实休闲时间的一个新颖的工具。

## 该系统的主要功能:

软件唤作"Univot"，其功能主要有以下三个：

> 1创建投票：根据所需，快速创建投票，系统将会记录用户的需求并为其分配唯一的"vid"并存入数据库以便推荐给其他用户和提取。
>
> 2发现投票：系统根据投票发布位置以及用户喜好和对用户历史行为的记录，比较投票兴趣和用户兴趣的相似度以及投票本身特性的竞价为用户在首页推荐或根据用户搜索的关键词在搜索区域为用户提供用户需要的投票信息。
>
> 3浏览投票：使用php中的POST()方法根据所传"vid"使用bootstrap、ChartJS和二维码生成类库PHPQRCode生成各投票实时信息和网页二维码。

软件功能如下图1所示。

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image2.png){width="3.7402777777777776in"
height="3.129166666666667in"}

图1 投票系统**功能模块图**

# 二、系统设计

## （一）系统的概要设计

类之间的关系如图 2所示，系统模块之间关系以及运行先后顺序如图 3所示。

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image3.png){width="6.044444444444444in"
height="0.9881944444444445in"}

图2 类之间的关系图

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image4.png){width="5.595138888888889in"
height="5.134722222222222in"}

图3 系统模块之间关系以及运行先后顺序图

## （二）系统的详细设计

各类包含方法和属性及关系如图4所示，系统总流程图如图 5
所示![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image5.png){width="6.988888888888889in"
height="4.613888888888889in"}

图4 各类包含方法和属性及关系

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image6.png){width="5.899305555555555in"
height="3.688888888888889in"}

图5 系统总流程图

[]{#__RefHeading___Toc127703000 .anchor}总体设计

考虑到软件作为休闲社区的定位以及对软件易用性的要求，软件中几乎所有组件在设计上都选用更容易接受的无边框样式，ui尽可能轻简、扁平化，因而才能在首页同时呈现系统的三个主要功能的同时不至于让软件显得臃肿。软件界面风格如图6所示。

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image7.png){width="4.361111111111111in"
height="2.3944444444444444in"}

图6 软件界面风格示例

为了实现实时数据可视的要求，软件不仅要用到数据库而且也要拥有跨平台浏览实时信息的能力以真正实现实时可视的现实要求，因此系统满足跨平台呈现投票详情的时候会用到php和前端框架以及几个web开发工具。

在软件图标方面修改.pro工程文件，加入RC_FILE +=
app.rc，利用.rc文件给win平台的程序增加图标信息。图标如图7所示。

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image8.png){width="0.8326388888888889in"
height="0.8326388888888889in"}![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image9.png){width="3.6666666666666665in"
height="0.8291666666666667in"}

图7 软件图标

同时为了能够更准确得为用户提供用户需要的投票内容，软件中会有一些简易的推荐算法。首先是**基于内容的推荐算法**，根据用户过去喜欢的条目，为用户推荐和他过去喜欢的物品相似的物品。而关键就在于这里的物品相似性的度量，这是这个算法运用过程中的核心。另外随着GPS技术的发展和相关工具的完善软件使用了**基于位置的推荐算法**，由于投票平台中的话题可能更容易出现很多倾向于本地生活的内容，这种推荐方式也有重要作用。

[]{#__RefHeading___Toc127703001 .anchor}首页

方法一：更新自身数据显示
使得首页头像显示、推荐显示、我的创建全部更新到最新数据。

方法二：初始化各页面 新建所需窗口的同时建立信号与槽的连接。

方法三：打开条目 创建含QAxWidget的网页浏览页面以浏览对应投票详情内容。

方法四：搜索关键词
判断关键词属于vid还是投票标题后查询数据库得到所需信息。

[]{#__RefHeading___Toc127703002 .anchor}设置页

方法一：关闭程序 关闭所有窗口。

方法二：查询ip所在位置
利用百度地图开放平台提供的普通ip定位服务api获取经纬度信息并保存于外部变量x、y用于发布投票时提交和基于地理位置进行个性推荐。

方法三：在文本框显示位置信息
将json数据导入QVariantMap的数据以QString形式显示在文本框内。

方法四：探测查询进度并反馈给进度条
在查询操作运行到各个时期时修改进度条的Value。

[]{#__RefHeading___Toc127703003 .anchor}欢迎页

方法一：获得本机ip 利用ipify.org提供的api获得本机ip数据。

方法二：根据获取到的本机ip获取本机位置
调用设置页的查寻ip这一方法自动设置默认x、y值。

[]{#__RefHeading___Toc127703004 .anchor}投票提交页

方法一：去除下拉框2中下拉框1选择的那一项（int）
将兴趣列表按照key=兴趣id,value=兴趣名称存入QMap\<int,qstring\>，利用迭代器i.find(int)寻找已选中的那一项以去除框2中已在框1选中的条目，在定位迭代器i.begin(),遍历Qmap将每一项导入下拉框中。

方法二：按照所选选项个数确定enable的选项输入框数量（int）
根据int的值用switch语句设定不同情况下六个输入框的可用性。

# 三、系统实现、测试和维护

## （一）系统开发相关资源

1.  Qt,一个跨平台 C++图形用户界面应用程序开发框架;

2.  QtAssistant,作为使用 Qt 时的一个文档查找工具;

3.  ProcessOn:创作思维导图,流程图和表格的工具;

4.  百度脑图: 创作类图的工具;

5.  Github: 开源社区,git仓库;

6.  CSDN: 中文IT技术交流平台;

7.  HeidiSQL:数据库管理工具;

8.  PhpMyAdmin:数据库管理工具;

9.  B 站:学习 Qt 的使用;

10. MarriDB:MySQL分支版本，数据库;

11. Dreamweaver:网站开发工具;

12. Bootstrap:web前端框架;

13. Phpqrcode:php二维码生成工具;

14. Chart.js:数据可视化工具;

15. Apache: Web服务器软件;

16. Xampp: PHP服务端环境搭建工具;

## （二）系统的核心数据结构和算法

数据结构主要包括:

1.  Map：保存兴趣分类的id和名称；

2.  Map：存放json中的数据；

3.  Map：存放list不同序号的选项对应的vid；

4.  Btree：mysql数据库索引,提高键值id查询效率；

5.  各种数组：存放适合作为数组存放的结构体、QString、int等类型;

6.  SQL数据库中的数据结构，详见如下两个数据表的表结构。

> ![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image10.png){width="1.9527777777777777in"
> height="4.99375in"}
>
> 表1 投票数据表结构
>
> ![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image11.png){width="2.1625in"
> height="1.9215277777777777in"}
>
> 表2 用户数据表结构

系统核心算法包括:

1.  搜索框输入关键词性质判断:将输入的关键词temp转换为STL中String类temp.toStdString()遍历比较是否为纯数字，纯数字则作为vid在数据库中搜索反正则以名称搜索。

2.  去除下拉框2中下拉框1选择的一项:生成与框1内容一致的map，在框1选中后使迭代器i.find(int)寻找已选中的那一项以去除框2中已在框1选中的条目，在定位迭代器i.begin(),遍历Qmap将每一项导入下拉框中。

3.  登陆密码验证：查询数据库中是否有用户名存在一致的情况和是否有用户名且密码都存在一致的情况。若用户名存在密码错误则提示，若用户名不存在则以输入的密码为初始密码创建新账号。

4.  计算投票的grade值:
    php中新的grade变量为\$new,以最多被选项目票数比总浏览量乘以100的积为其赋值\$new=max(\$o1n,\$o2n,\$o3n,\$o4n,\$o5n,\$o6n)/\$watch\*100，向数据库提交新的grade。

5.  遍历数据表中的数据获取grade值最大的一项的vid:典型的寻找最大值做法，int
    maxgrade初始为0，遍历每一个投票，获取每个投票的grade值并且依次判断：if(grade\>maxgrade)则新vid为当前vid新maxgrade为当前grade最终vid即拥有最大grade的投票的vid。

6.  统计用户兴趣方向实现基于内容的推荐:

> 通过设计三种分配情况在用户每次打开新投票详情页的时候获取，分析和更新用户的兴趣和每个兴趣相应的评分，数据库中用户兴趣interst2和interst3对应的兴趣评分为1和0.5，interst1评分为2。若只有一个符合一个的或符合一个符合两个的则直接选择符合最多的，但当数据库中有多个同时具有用户3个兴趣之2的投票时启动相似度算法。
>
> 系统分别为投票的兴趣1兴趣2赋评分2、1，为用户的三个兴趣赋分2、1、0.5。

（在数据库数据充足的情况下）系统利用欧几里得公式计算用户兴趣领域和投票兴趣领域之间的相似度，示例如下：

  ------- ------------------- ---------------------- ---------------------
          兴趣1接近程度评分   兴趣2接近程度评分      兴趣3接近程度评分

  投票1   2                   1                      0

  投票2   1                   2                      0

  投票3   1                   0                      2

  用户    2                   1                      0.5
  ------- ------------------- ---------------------- ---------------------

> 下面分别利用欧几里得公式计算用户1和投票1、2、3的相似度

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image12.png){width="3.2381944444444444in"
height="0.43472222222222223in"}

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image13.png){width="3.0in"
height="0.43472222222222223in"}

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image14.png){width="3.2444444444444445in"
height="0.43472222222222223in"}

> 从计算结果可知，投票1的兴趣趋向和用户最为接近，更符合用户胃口。

若多项投票相似度相同则通过sort方法利用自定义比较规则

> bool **cmp**(selected a,selected b)
>
> 将结构体struct **selected**{int vid;int vi1;int vi2;double
> similarity;int
> gra;}pre\[100\];进行排序。通过对用户历史行为的记录和对用户兴趣和投票兴趣相似度之间的比较，系统得出用户最有可能喜欢看的投票并排序以供选择。

7.  选择距离用户最近的投票实现基于位置的推荐:

> 通过系统获取的用户所在位置经纬度依次与数据库中各（公开位置的）投票进行比对，利用二分法（通过比较中间值与最终值的大小来改变中间值，最终在满足某个精度的情况下返回这个中间值作为最终结果）设置所需精度进行快速开更计算位置间的直线距离并显示在首页。这部分代码如下(顺便尝试了下函数模板)：

template\<typename T\>

T **sqrt2**(T c)

{

if(c==0.0)return 0;

T a = 0,b = c+0.25;

T m;

while(1)

{

//取区间\[a,b\]的中点

m = (a+b)/2;

//控制精度退出

if(b - m \< PRESCION\|\|m - a \<PRESCION)

break;

//选择区间

if((m\*m - c)\*(b\*b - c)\<0)

a = m;

else

b = m;

}

return m;

> }
>
> 通过遍历每一个距离选出最近的显示并将其对应的vid和网址赋值给对应变量。

（三）系统各模块具体实现

1.  用户登录功能模块：未输入内容前登录页面如图8所示，若用户若输入正确的账号而未能输入正确的密码则页面如图9所示，若账密正确则发出信号"go"使得首页数据得到更新，同时关闭登录页。若账户不存在则自动创建账号也发出信号"go"，同时关闭登录页。登录页面同时会获取用户本机ip。因而在main.cpp中创建完登录页后也连接了登录页的两个信号和它们分别对应的槽。

QObject::connect(&w,&MainWindow::go,&ww,&index::changename);

> QObject::connect(&w,&MainWindow::ipready,&ipconfig,&Diainfo::autoip);
>
> ![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image15.png){width="3.9791666666666665in"
> height="2.1881944444444446in"}

图8 初始页面

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image16.png){width="3.9583333333333335in"
height="2.1770833333333335in"}

图9 密码出错时的登录页

此功能呈现在代码上即：

if(sql.next() == true)

{

QString a1= sql.value(0).toString();

QString b1= sql.value(1).toString();

QString c1= sql.value(2).toString();

QString d1= sql.value(3).toString();

QString e1= sql.value(4).toString();

QString f1= sql.value(5).toString();

QString g1= sql.value(6).toString();

QString h1= sql.value(7).toString();

qDebug()\<\<\"有这个账号\"\<\<a1\<\<\"密码\"\<\<b1\<\<\"1\"\<\<c1\<\<\"2\"\<\<d1\<\<\"3\"\<\<e1\<\<\"cre\"\<\<f1\<\<\"id\"\<\<g1\<\<\"profile\"\<\<h1\<\<endl;

uniname=a1;

int1=c1;

int2=d1;

int3=e1;

uniid=g1;

profilenum=h1;

qDebug() \<\< \"go\" \<\< endl;

emit this-\>go();

this-\>hide();

}else

{ if(sql.exec(str_sql_select1) == true&&(sql.next() ==
true)){ui-\>label_9-\>setText(\"密码错误\");}else{

qDebug()\<\<\"没有这个账号\";

QDateTime dateTime= QDateTime::currentDateTime();

QString str = dateTime .toString(\"Mdhhmmss\");

QString str_sql_insert = QString(\"INSERT INTO \`univot\`.\`user\`
(\`name\`, \`pw\`,\`id\`) VALUES (\'%1\', \'%2\',\'%3\');\")

.arg(login)

.arg(password)

.arg(str);

if(sql.exec(str_sql_insert) == false)

{

qDebug() \<\< \"创建新账号失败\" \<\< endl;

}

else

{

qDebug() \<\< \"创建新账号成功\" \<\< endl;

qDebug() \<\< \"go\" \<\< endl;

uniname=login;

int1=\"0\";

int2=\"0\";

int3=\"0\";

uniid=str;

emit this-\>go();

this-\>hide();

}

}

}

至于获取本机ip，其主要代码为：

QNetworkAccessManager\* m_manager = new QNetworkAccessManager;

QNetworkRequest request;
request.setUrl(QUrl(QString(\"http://api64.ipify.org/?format=json\")));

m_manager-\>get(request);

connect(m_manager, SIGNAL(finished(QNetworkReply\*)),
this,SLOT(dealMsg(QNetworkReply\*)));

其中dealMsg()是用来处理收集来的数据成为字符串且发出ipready信号的方法。账号11登录成功后效果如图10所示。

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image17.png){width="3.5625in"
height="1.9590277777777778in"}

图10 登录成功后的主页

2.  浏览投票内容功能模块：

> 软件中提供的投票浏览入口为第一栏、第二栏中的搜索结果栏、第三栏中的已创建页面，无论是以何种方式，具体的投票页面都由在不同情况下软件给出的vid有关，利用php的post方法给php程序提供需要查询的数据对应的vid，用网页的形式表现实时数据，弹出页面如图11所示。

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image18.png){width="5.770833333333333in"
height="3.173611111111111in"}

图11 双击条目弹出的投票详情页

双击条目实现生成链接用于打开网页的代码主要如下：

void index::**on_listView_doubleClicked**(const QModelIndex &index)

{

qDebug()\<\<index.row();

int choose=index.row();

qDebug()\<\<vidlist1\[choose\];

urlnow=QString(\"http://localhost/gwnb/chart.php?vid=%1\")

.arg(vidlist1\[choose\]);

vote \*test=new vote();

test-\>show();}

> 对于Vote类则使其获得urlnow的数据并显示网页，于是主要代码如下：

this-\>setWindowFlags(Qt::WindowCloseButtonHint);

this-\>setWindowTitle(QStringLiteral(\"投票详情\"));

QString webStr = urlnow;

this-\>ui-\>axWidget-\>setControl(QString::fromUtf8(\"{8856F961-340A-11D0-A96B-00C04FD705A2}\"));//注册组件ID

this-\>ui-\>axWidget-\>setProperty(\"DisplayAlerts\",false);//不显示警告信息

this-\>ui-\>axWidget-\>setProperty(\"DisplayScrollBars\",true);//不显示滚动条

this-\>ui-\>axWidget-\>dynamicCall(\"Navigate(const
QString&)\",webStr);//显示网页

ui-\>axWidget-\>dynamicCall(\"Navigate(const QString&)\",webStr);

> 至于对已创建的投票的操作和数据呈现将会在网页中进行，如图12.

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image19.png){width="1.5798611111111112in"
height="3.5659722222222223in"}

图12 完整的投票详情页

由于网页使用了chart.js提供的分布图，程序主要需要将根据vid从数据库获取的各项数据输入barChartData即可，代码如下：

var barChartData = {\"labels\":\[\"\<?php echo \$o1?\>\",\"\<?php echo
\$o2?\>\",\"\<?php echo \$o3?\>\",\"\<?php echo \$o4?\>\",\"\<?php echo
\$o5?\>\",\"\<?php echo
\$o6?\>\"\],\"datasets\":\[{\"label\":\"得票\",\"data\":\[\<?php echo
\$o1n?\>,\<?php echo \$o2n?\>,\<?php echo \$o3n?\>,\<?php echo
\$o4n?\>,\<?php echo \$o5n?\>,\<?php echo
\$o6n?\>\],\"backgroundColor\":\[\"rgb(236, 94, 105)\",\"rgb(0, 112,
224)\",\"rgb(241, 194, 5)\",\"rgb(50, 150, 51)\",\"rgb(120, 24,
254)\",\"rgb(0, 255, 200)\"\]}\]};

3.  搜索投票功能模块：

> 用户在可以通过搜索vid（如图13）或直接搜索标题（如图14）得到同一结果，双击所得条目即可打开。

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image20.png){width="2.7381944444444444in"
height="3.3895833333333334in"}

图13 vid搜索结果

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image21.png){width="2.765972222222222in"
height="3.6458333333333335in"}

图14 投票名称搜索结果

> 搜索按钮按下后判断输入关键词的类型的判断结果，用以选择在数据库搜索的关键词类型，而后使用使用sql命令搜索并呈现，其代码主要如下：

void index::**on_pushButton_3\_released**()

{

QString temp=ui-\>lineEdit-\>text(),aim;

string search=temp.toStdString();

if(isNumeric(search)){

qDebug()\<\<\"搜素id\";

aim=\"id\";

}else{

qDebug()\<\<\"搜素title\";

aim=\"title\";

}

QSqlQuery query;

QString select = QString(\"select \* from watch where %2 = \'%1\';\")

.arg(temp)

.arg(aim);

query.exec(select);

vidlist1.clear();

int n=0;

while(query.next())

{

int id = query.value(3).toInt();

QString name = query.value(0).toString();

qDebug() \<\< id \<\< name;

QString insert = QString(\"vid-%1 %2\")

.arg(id)

.arg(name);

QStringList list1;

vidlist1.insert(n++,id);

list1 \<\<insert;

model1=new QStringListModel(this);

model1-\>setStringList(list1);

ui-\>listView-\>*setModel*(model1);

ui-\>listView-\>setEditTriggers(QAbstractItemView::AnyKeyPressed);

}

}

4.  设置头像模块

> 点击头像则弹出头像选择页面如图15，选择完毕后首页即刻更新新头像，如图16。
>
> 为了使得新头像选中后即可启用，系统在创建新页面的时候已经做好了信号和槽的连接，代码如下：
>
> QObject::connect(&www, &Dialog::newnum, this, &index::changename);
>
> 当按下任意一个头像时上传页发出finish信号例如：

void Dialog::**on_pushButton_released**()

{

creat(1);//用于沟通数据库

this-\>close();

emit this-\>newnum();

}

> 使得首页重新从数据库获取数据以更新到最新数据。

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image22.png){width="5.769444444444445in"
height="3.1729166666666666in"}

图15 头像选择页面

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image23.png){width="5.5in"
height="2.1875in"}

图16 新头像已显示

5.  信息设置模块

> 在首页点击设置即可打开，为配合信息模块的退出账户的功能，当收到设置页面发出的退出信号时首页也将一同退出，建立连接代码如下：

connect(&wwww,&Diainfo::relogin,this,&QWidget::close);

按钮按下后显示设置页面，如图17所示。

当退出账号按钮按下时发送信号relogin并关闭自身，代码如下：

void Diainfo::**on_pushButton_3\_released**()

{

emit this-\>relogin();

this-\>close();}

> 若是自定义提交ip，则在按下"检测并重置"按钮后系统利用百度地图api获取所设ip的位置信息并显示在文本框（如图18）并将获取的经纬度赋值给xcode、ycode、city。主要代码如下：

void Diainfo::**on_queryButton_clicked**()

{

const QString txt=ui-\>lineEdit-\>text();

if(txt==\"\"){

QMessageBox::warning(this,QStringLiteral(\"提示\"),QStringLiteral(\"请输入IP地址或域名！\"));

return;

}

ui-\>plainTextEdit-\>clear();

QHostInfo::lookupHost(txt,this,SLOT(onHostLookedUp(QHostInfo)));

}

void Diainfo::**onHostLookedUp**(const QHostInfo &host)

{

if(host.error()!=QHostInfo::NoError){

QMessageBox::information(this,QStringLiteral(\"提示\"),host.errorString());

return;

}

QList\<QHostAddress\> adds = host.addresses();

if(adds.size()){

const QHostAddress& addr = adds.first();

queryLocationOfIP(addr.toString());

qDebug()\<\<addr.toString();

ui-\>progress-\>setValue(30);

}

}

void Diainfo::**queryLocationOfIP**(const QString &strIp)

{

const QString&
strUrl=QString(\"http://api.map.baidu.com/location/ip?ak=%1&ip=%2&coor=bd09ll\").

arg(AK_STR).arg(strIp);

QNetworkRequest request;

request.setHeader(QNetworkRequest::ContentTypeHeader,\"application/json\");

request.setUrl(QUrl(strUrl));

QNetworkReply\* reply =m_pNet-\>get(request);

connect(reply,SIGNAL(finished()),this,SLOT(replyFinished()));

ui-\>progress-\>setValue(50);

}

void Diainfo::**replyFinished**()

{

QNetworkReply\* reply=qobject_cast\<QNetworkReply \*\>(sender());

if(reply-\>error()!=QNetworkReply::NoError){

QMessageBox::information(this,QStringLiteral(\"提示\"),QStringLiteral(\"请求出错:%1\").arg(reply-\>errorString()));

}

const QByteArray& bytes=reply-\>readAll();

const QVariantMap& varMap=parseLocationData(bytes);

ui-\>progress-\>setValue(80);

showLocation(varMap);

reply-\>deleteLater();

}

QVariantMap Diainfo::**parseLocationData**(const QByteArray &data)

{

QJsonParseError error;

QJsonDocument doc=QJsonDocument::fromJson(data,&error);

ui-\>progress-\>setValue(90);

if(error.error!=QJsonParseError::NoError){

QMessageBox::information(this,QStringLiteral(\"提示\"),QStringLiteral(\"JSON:数据结构有问题！\"));

return QVariantMap();

}

QJsonObject obj=doc.object();

int status=obj.value(\"status\").toInt();

if(status!=0){

QMessageBox::information(this,QStringLiteral(\"提示\"),QStringLiteral(\"状态码：%1\").arg(status));

return QVariantMap();

}

QJsonObject contentObj=obj.value(\"content\").toObject();

qDebug()\<\<contentObj.value(\"address\").toString();

return contentObj.toVariantMap();

}

void Diainfo::**showLocation**(const QVariantMap &varMap)

{

const QString& addrStr=varMap.value(\"address\").toString();

const QVariantMap& ptMap=varMap.value(\"point\").toMap() ;

const QString& longitudeStr=ptMap.value(\"x\").toString();

const QString& latitudeStr=ptMap.value(\"y\").toString();

const QString& txt=QStringLiteral(\"城市：%1 \\n经度：%2
纬度：%3\").arg(addrStr).arg(longitudeStr).arg(latitudeStr);

ui-\>plainTextEdit-\>setPlainText(txt);

city=addrStr;

xcode=longitudeStr;

ycode=latitudeStr;

ui-\>progress-\>setValue(100);

qDebug()\<\<xcode;

qDebug()\<\<ycode;

}

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image24.png){width="2.1368055555555556in"
height="3.5854166666666667in"}

图17 设置页面

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image25.png){width="3.3819444444444446in"
height="2.3506944444444446in"}

图18 自定义ip且显示结果

6.  推荐模块

> 软件中的推荐有发现栏目中的推荐比较简单，即：遍历每条投票数据的grade值，选择grade值最高的一个投票，在label框显示其vid和名称为搜索提供参考，代码如下：

ui-\>label_19-\>setText(maxname);

ui-\>label_20-\>setText(finallayout);

> 显示效果如下

![](vertopal_eb56bf43d5254f149d502e697d6c4065/media/image26.png){width="4.0784722222222225in"
height="4.7340277777777775in"}

图19 按位置推荐效果

而基于位置的推荐则较为复杂，系统遍历每条投票的位置和用户位置比对，选出最近的距离，用零点定理和二分法算出一定精度下的度数距离显示在首页以便选择。

基于内容的推荐首先比较是否有符合用户兴趣一到两个的投票，若只有一个符合一个的或符合一个符合两个的则直接选择符合最多的，若同时有多个符合两个的则利用欧几里得公式进行相似度计算选择最接近的一项并显示在首页供用户选择。

四、系统测试以及维护

**表1 系统测试用例及问题解决方法**

  ------------------------------ -------------------------------------- ---------------------------------------------------------------- -------------------------------------------------------------------------------------------------------------
  **测试数据**                   **运行结果**                           **运行bug**                                                      **解决方法**

  **连接数据库失败**             **调试器找不到libmysql.dll**           **系统没有自带相应dll文件且**MarriDB**没有自带相应文件**         **下载对应dll放入Qt的中mingw文件夹的bin文件夹中**

  **在首页打开新头像设置页**     **新页面闪退**                         **按钮按下方法运行结束后占用内存清空，页面随之被释放**           **利用dialog类的exec方法开启一个对dialog类页面返回值的类似while循环的等待功能以加长按钮按下方法运行时间。**

  **打开设置页**                 **设置页闪退**                         **随着按钮按下功能结束而被释放，声明变量和动态内存分配的区别**   **使用new来创建设置页避免被释放。**

  **修改makefile文件后编译**     **makefile报错：missing separator**    **Qt自带编辑器中的Tab格式在保存时自动保存为空格造成**            **用vscode重新编辑makefile**

  **选择创建的投票属性**         **创建投票时发布模式选项顺序错乱**     **在qt的设计页面已插入两条选项,Insert顺序错乱**                  **Insert操作统一进行**

  **检查首页发现栏目推荐**       **推荐内容错误**                       **由于前期测试考虑不周全产生Grade\>=100的投票**                  **加入if(grade\<100)判断**

  **发现栏目随机选择图片功能**   **图片自动选择错误**                   **Qt自带Qrand跟随系统随机种子**                                  **依据时间自定义随机种子**

  **重设头像**                   **头像设置完毕后首页相应图片不更新**   **按钮按下后首页没有执行初始化**                                 **为头像选择页创建信号，为对应信号和首页初始化槽函数建立连接按钮按下后首页初始化**

  **扫码**                       **打不开网页**                         **手机没有处于电脑同一局域网内**                                 **关闭数据连接打开WLAN连接同一局域网**

  **删除不需要的资源文件**       **报错no rule to make target XXX       **.pro文件内容没有重新加载新的qrc文件**                          **剪切相关的声明（Resources栏目）然后重新编译一次，粘贴相应qrc文件名重新编译**
                                 needed by XXX**                                                                                         

  **发布版连接数据库失败**       **报错连接失败**                       **没有libmysql**                                                 **将缺少的libmysql一并打包**
  ------------------------------ -------------------------------------- ---------------------------------------------------------------- -------------------------------------------------------------------------------------------------------------

# 五、总结

该系统,名为"实时投票可视化系统",顾名思义,该系统的主要需要实现的目的有两个,一个是实时投票系统,另一个是数据的可视化，两者的结合也产生了实时可视化的推荐功能。

投票系统的实时功能,是使得用户提交的投票能得到及时的状态反馈的要求，这一点是投票平台的基本需要。而可视化功能则是方便用户快速得知该投票要素。数据可视化的意义是帮助人更好的分析数据，信息的质量很大程度上依赖于其表达方式。因此为了提高系统的使用体验我为软件设计了更耐看更简洁的ui。另外为了加快开发进程和提高系统的更新潜力,减少未来本项目过多存在重用代码的可能性，为开发者节省时间和精力，我选用了Qt、Bootstrap、chartjs分别作为GUI程序开发框架，网站CSS/HTML框架，JavaScript
可视化框架数据可视化框架为执行繁琐的代码提供预建模块。

用户在使用该投票系统的时候可以创建自己的账号，为自己的账号选择头像，查看自己发布的投票记录，搜索数据库中存在的投票，发现推荐算法推荐的条目，浏览投票信息，分享自己或他人发布的投票。

在具体操作方法上，软件尽力实现去除所有冗杂内容，各项功能直奔主题，在用户体验上传达系统的轻量、可靠、便捷这些特性。比如在头像选择上用户只需要点击自己当前头像，直接就可以在新页面中选择新头像并直接返回首页；登录时输入用户密码完毕后只需要按下按钮即可进入首页；提交投票时只需要编辑投票标题、投票内容（可不写）、选项数量（默认为2项）、选项内容（最少两项）、领域（两项）、公开模式（默认公开ip）；浏览投票时若直接通过推荐进入则只需一键即可进入对应投票页面，若通过手动搜索则只需输入搜索投票vid或标题点击搜索按钮（enter也可）即可。通过如上设计软件真正实现了系统所有功能五次点击（或enter）内直达完成，将软件的轻量化做到极致。

在软件的推荐算法上，系统通过收集用户浏览习惯和用户所在位置为每个用户量身定制首页个性推荐和系统实时检索的最具争议的投票。从而减轻投票发布者缺少浏览的痛点和满足用户日常消遣的需要，其中ip定位更是将定位精度提高到了地级市（实际最高精准度可以达到街道级别，但由于系统运行初期流量较少，而定位过于精准不利于开发维护，所以只上传城市中心经纬度）而此时处于国内的约300座地级市之一的一位用户可以拥有6,840种基于兴趣的推荐以及基于位置的推荐，这不仅便利了投票发布者获取精准流量的需求也为普通用户提供了对其兴趣的精准推荐，同时流量引导这一主要功能也为投票系统这一平台带来了盈利潜质（出售投票展示权重和扩大推荐范围）。

上述是对整个系统所实现的简单介绍,在系统设计的过程当中,我收获颇多。

首先"Univot"是我构思已久的一个创意想法，在高中期间就已展开一些基础的开发工作如web端的数据库构建，社区系统的构建，也为此浅浅学习了android开发的相关知识，通过此次课程设计我学会了Qt的基本使用方法，为系统提供了可用的Windows客户端，也算是一次很有成就感且别致的作业体验。

首先我关注了作业文档里对开发工具的推荐，一一查阅相关资料后我选择了几乎支持所有的平台，接口简单,容易上手,页面好看，简化内存回收机制，开发效率高的Qt，开启了我的自学Qt之路。

通过对Qt的学习，我掌握了继VB,易语言之后的另一种用户界面应用程序开发框架，通过对Qt的学习我学习和巩固了面向对象编程的方法和体会到了Qt和这一编程方式的优势。同时我也学习和巩固了关于STL、lambda表达、函数模板的知识。

通过对整个程序的设计和实现我提高了通过网络获取知识的能力，比较各开发工具优劣和是否合适自己并做出选择的能力以及发现相关论文文章的能力。

总之，这一课设的完成大大提高了我个人的工程能力。

这一次作业的完成,我收获颇丰,同时也不会忘记在完成这次作业的过程中,帮助过我的那些人。

首先是可可爱爱超受欢迎的叶子老师。叶子老师在我学习Qt的那几天回答了我有关加入实验室的一些问题，通过老师的话我也收获不少。通过老师对我的提问我提高了对开发框架的重视程度，同时也引发了我对叶老师提到的"工程能力"的思考。

工程能力是一项综合能力,对个人和团队都非常有意义。个人的工程能力包含心智因素、判断主次和先后的逻辑思维能力、持续将事情做好的能力等要素。我自从小学就希望成为一个务实严谨且具有创造力的工科生或是工程师，这一次作业无疑是又一次加深了我对自己和对工程的认识的经历。

王光耀也是超级棒的友友啊,他是一个具有工程能力且高效务实有思想的完美搭档。他为我提供了许多极其重要的资料和学习Qt的资源和学习Qt进程中的不少指导和思路（可以说没有他的帮助我的作品效果会大打折扣），他务实自律的品质和丰富的开发经验也很值得我学习。

另外这次作业本身也是一个很棒的体验（我在内蒙的县图书馆、宁波图书馆、区图书馆、吉林省图、黑龙江省图、长春的几个精美书店、开往哈市的高铁上完成了这个作业），与其说是一次作业的完成，不如说是我两个月暑假旅行乐章的一条带给我某种充实感的一条暗线，我感谢所有为我提供做作业的栖息地的所有人。

关于我未来专业学习的目标,它是纯粹简单的。

作为一个立志成为好工程师的工科生，我有如下思考：

印度导演塔森在谈及"创意人的身价"曾说：你出的价钱，不只买到我的导演能力，而是买到我喝过的每一口酒、品过的每一杯咖啡、吃过的每一餐美食、看过的每一本书、坐过的每一把椅子、谈过的每一次恋爱、眼里看到过的美丽女子和风景、去过的每一个地方......你买的是我全部生命的精华，并将其化成为30秒的广告，怎么会不贵？"
我想，工程师的成就感也大抵如此：成就感来自我钻研的每一点知识、踩过的每一个坑、解决的每一个问题、全力奔跑的每一个瞬间、独守台灯的每一个夜晚、用心做过的每一个工程......它是我全部生命的精华。

未来的学业规划，无非也是用心过好每一个充实的日日夜夜。

至于更细的考试、竞赛、科研等等，能做到止于至善，全力以赴就好。
