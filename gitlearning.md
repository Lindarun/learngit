git学习
18,4,6
mkdir filename 创建
cd filename 切换
pwd 显示当前目录
git init 变成可直接管理的库
添加文件：
1.git add<file>(反复多次使用，添加多个文件)
2.git commit -m "(本次提交的说明)"
18,4,7
git status 查看当前状态
git diff <file> 查询修改
版本回退：
git log 显示从最近到最远的提交日志(可添加--pretty=oneline 简洁输出)
HEAD 表示当前版本
HEAD^为上个版本(^^则为两个) HEAD~100为上一百个版本
git reset --hard <版本>
若想再恢复 必须找到版本的commit id
git reflog 查看命令

工作区：目录
版本库：.git，里面有stage master HEAD
暂存区：在版本库内
git diff HEAD -- readme.txt 查看工作区和版本库里面最新版本的区别

4,10
连接至远程仓库
1，在GitHub新建项目
2，填写name，项目名
3，得到sshkey
4，新建并变成版本库
5，右键gitbash
6，git add README.md 
7，touch README.md
8，git add README.md
9，git commit -m "first commit" 
10，git remote add origin <SSH地址>
 11，git push -u origin master