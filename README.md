# 开发该系统的意义

   使用该系统的人们或开发者能够利用该系统快速寻找、创建和浏览实时投票,对于个人用户系统可以快速创建和分享投票并且观察实时投票反馈；对于开发者来说该系统可以利用已准备好的api接口、数据库、前端框架以缩短开发者自己宝贵的时间,有效的提高应用开发效率。（由于构思中为工程师提供api接口的部分与课程设计使用c++面向对象程序分析和设计的思想的要求相距较远，本次课程设计将侧重于客户端的实现，希望谅解。）

作为一个轻量化的实时投票可视化系统，用户可以便捷的发现、创建投票并实时查看反馈，不仅可以满足人们信息采集的需求也能作为人们观察世界、充实休闲时间的一个新颖的工具。

  

# 该系统的主要功能:

软件唤作“Univot”，其功能主要有以下三个：

1创建投票：根据所需，快速创建投票，系统将会记录用户的需求并为其分配唯一的“vid”并存入数据库以便推荐给其他用户和提取。

2发现投票：系统根据投票发布位置以及用户喜好和对用户历史行为的记录，比较投票兴趣和用户兴趣的相似度以及投票本身特性的竞价为用户在首页推荐或根据用户搜索的关键词在搜索区域为用户提供用户需要的投票信息。

3浏览投票：使用php中的POST()方法根据所传“vid”使用bootstrap、ChartJS和二维码生成类库PHPQRCode生成各投票实时信息和网页二维码。

  

# 系统的核心数据结构和算法

数据结构主要包括:

1.  Map：保存兴趣分类的id和名称；

2.  Map：存放json中的数据；

3.  Map：存放list不同序号的选项对应的vid；

4.  Btree：mysql数据库索引,提高键值id查询效率；

5.  各种数组：存放适合作为数组存放的结构体、QString、int等类型;

6.  SQL数据库中的数据结构，详见如下两个数据表的表结构。

  

# 页面设计

## 首页

      方法一：更新自身数据显示 使得首页头像显示、推荐显示、我的创建全部更新到最新数据。

      方法二：初始化各页面 新建所需窗口的同时建立信号与槽的连接。

      方法三：打开条目 创建含QAxWidget的网页浏览页面以浏览对应投票详情内容。

      方法四：搜索关键词 判断关键词属于vid还是投票标题后查询数据库得到所需信息。

## 设置页

       方法一：关闭程序 关闭所有窗口。

      方法二：查询ip所在位置 利用百度地图开放平台提供的普通ip定位服务api获取经纬度信息并保存于外部变量x、y用于发布投票时提交和基于地理位置进行个性推荐。

      方法三：在文本框显示位置信息 将json数据导入QVariantMap的数据以QString形式显示在文本框内。

      方法四：探测查询进度并反馈给进度条 在查询操作运行到各个时期时修改进度条的Value。

## 欢迎页

   方法一：获得本机ip 利用ipify.org提供的api获得本机ip数据。

   方法二：根据获取到的本机ip获取本机位置 调用设置页的查寻ip这一方法自动设置默认x、y值。

## 投票提交页

      方法一：去除下拉框2中下拉框1选择的那一项（int） 将兴趣列表按照key=兴趣id,value=兴趣名称存入QMap<int,qstring>，利用迭代器i.find(int)寻找已选中的那一项以去除框2中已在框1选中的条目，在定位迭代器i.begin(),遍历Qmap将每一项导入下拉框中。

      方法二：按照所选选项个数确定enable的选项输入框数量（int） 根据int的值用switch语句设定不同情况下六个输入框的可用性。

#   

# 系统核心算法

  

1\. 搜索框输入关键词性质判断:将输入的关键词temp转换为STL中String类temp.toStdString()遍历比较是否为纯数字，纯数字则作为vid在数据库中搜索反正则以名称搜索。

  

2\. 去除下拉框2中下拉框1选择的一项:生成与框1内容一致的map，在框1选中后使迭代器i.find(int)寻找已选中的那一项以去除框2中已在框1选中的条目，在定位迭代器i.begin(),遍历Qmap将每一项导入下拉框中。

  

3\. 登陆密码验证：查询数据库中是否有用户名存在一致的情况和是否有用户名且密码都存在一致的情况。若用户名存在密码错误则提示，若用户名不存在则以输入的密码为初始密码创建新账号。

  

4\. 计算投票的grade值:

php中新的grade变量为\\$new,以最多被选项目票数比总浏览量乘以100的积为其赋值\\$new=max(\\$o1n,\\$o2n,\\$o3n,\\$o4n,\\$o5n,\\$o6n)/\\$watch\\\*100，向数据库提交新的grade。

  

5\. 遍历数据表中的数据获取grade值最大的一项的vid:典型的寻找最大值做法，int

maxgrade初始为0，遍历每一个投票，获取每个投票的grade值并且依次判断：if(grade\\>maxgrade)则新vid为当前vid新maxgrade为当前grade最终vid即拥有最大grade的投票的vid。

  

6\. 统计用户兴趣方向实现基于内容的推荐:

  

通过设计三种分配情况在用户每次打开新投票详情页的时候获取，分析和更新用户的兴趣和每个兴趣相应的评分，数据库中用户兴趣interst2和interst3对应的兴趣评分为1和0.5，interst1评分为2。若只有一个符合一个的或符合一个符合两个的则直接选择符合最多的，但当数据库中有多个同时具有用户3个兴趣之2的投票时启动相似度算法。

  

系统分别为投票的兴趣1兴趣2赋评分2、1，为用户的三个兴趣赋分2、1、0.5。

  

（在数据库数据充足的情况下）系统利用欧几里得公式计算用户兴趣领域和投票兴趣领域之间的相似度，示例如下：

  

\------- ------------------- ---------------------- --------------------- ---------------------

兴趣1接近程度评分 兴趣2接近程度评分 兴趣3接近程度评分

  

投票1 2 1 0

  

投票2 1 2 0

  

投票3 1 0 2

  

用户 2 1 0.5

\------- ------------------- ---------------------- --------------------- ---------------------
