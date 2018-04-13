# GIT和Github学习
[TOC]
## Git
### 1 Git介绍和配置
#### 1.1 Git简介
Git是目前世界上最先进的分布式版本控制系统（没有之一）。  
那什么是分布式版本控制系统呢？  
  
如果你用Microsoft Word写过长篇大论，那你一定有这样的经历：

想删除一个段落，又怕将来想恢复找不回来怎么办？有办法，先把当前文件“另存为……”一个新的Word文件，再接着改，改到一定程度，再“另存为……”一个新文件，这样一直改下去，最后你将有几个大致内容相同的文档。

好麻烦啊，看着这些杂乱无章的文档，又不敢删生怕什么时候会用到。**就不能存储我所修改的地方的记录**，节省我的空间吗？



情景更改一下，当你和人合作编写一段代码，你将文件通过数种方式传给他，然后你继续修改，过了几天他再把文件传给你，此时，你必须想想，发给他之后到你收到他的文件期间，你作了哪些改动，得把你的改动和他的部分手动合并，真麻烦。就不能有个东西**能自动帮我管理，可以让我和同事协作编辑**而不用这样大费周章去搞这些无用功吗？


没错Git就是有上述的两种功能，介绍完毕。

#### 1.2 Git安装
##### Windows安装
[访问Git网站](http://msysgit.github.io/)，并点击Download  
安装完成后，在开始菜单里找到“Git”->“Git Bash”，蹦出一个类似命令行窗口的东西，就说明Git安装成功！  
安装完成后，还需要最后一步设置，在命令行输入：  
```
$ git config --global user.name "username"*
$ git config --global user.email "username@example.com"  
```
注意```git config```命令的```--global```参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置，当然也可以对某个仓库指定不同的用户名和Email地址。  

如果你忘记了这一步，在你首次提交时，Git将其是你提供这些信息。  

### 2 Git的使用
#### 2.1 配置版本库  
什么是版本库呢？版本库又名仓库，英文名repository，你可以简单理解成一个目录，这个目录里面的所有文件都可以被Git管理起来，每个文件的修改、删除，Git都能跟踪，以便任何时刻都可以追踪历史，或者在将来某个时刻可以“还原”。  
  
首先，在一个合适的地方创建一个空目录。
```
mkdir git
cd git
pwd
>> /e/git
``` 
其中```mkdir```命令用于新建文档（这里也可以手动建立），```pwd```命令用于查看当前目录，```cd```用于切换目录。  

 第二步，通过```git init```命令把这个目录变成Git可以管理的仓库：  
 
 ``` 
 git init
>> Initialized empty Git repository in /e/git
```
瞬间Git就把仓库建好了，而且告诉你是一个空的仓库（empty Git repository），细心的读者可以发现当前目录下多了一个.git的目录，这个目录是Git来跟踪管理版本库的，没事千万不要手动修改这个目录里面的文件，不然改乱了，就把Git仓库给破坏了。

如果你没有看到.git目录，那是因为这个目录默认是隐藏的，用```ls -ah```命令就可以看见。

#### 2.2 忽略文件
扩展名为```.pyc```的文件是自动生成的，我们无须让git跟踪他们。这些文件存在目录__pycache__中。为了让Git忽略这个目录，创建一个**名为.gitignore**的特殊文件，并在其中添加下面一行内容：
```
__pycache__/
```
这让Git忽略掉目录__pycache__中的所有文件，避免混乱，开发起来更容易。
#### 2.3 添加文件
一定要先将所要提交的文件放在**版本库**下（子目录也行），放到其他地方Git再厉害也找不到这个文件。  

第一步，用命令```git add```告诉Git，把文件添加到仓库：
```
git add filename.txt
```
执行上面的命令，没有任何显示，这就对了.  

第二步，用命令```git commit```告诉Git，把文件提交到仓库：
```
git commit -m"my first commit"
>>[master (root-commit) cb926e7] my first commit
 1 file changed, 2 insertions(+)
 create mode 100644 filename.txt
```
简单解释一下```git commit```命令，```-m```后面输入的是本次提交的说明，可以输入任意内容，当然最好是有意义的，这样你就能从历史记录里方便地找到改动记录。  

为了不麻烦```add.```可一次性提交所有文件，```commit```命令自动将添加的文件全部提交。

#### 2.4 检查状态
修改并添加filename.txt的内容，运行```git status```命令查看状态：
```
git states
# On branch master
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#    modified:   filename.txt
#
```
从这里的输出可知，我们位于分支maser上，指出了未跟踪文件，文件是否被修改。  

若要查看修改的内容，使用命令```git diff filename.txt```便可得到其修改。  
提交后用```git status```查看状态
```
# On branch master
nothing to commit (working directory clean)
```
Git告诉我们当前没有需要提交的修改，而且，工作目录是干净（working directory clean）的。

#### 2.5 查看提交历史
命令```git log```可查看提交的历史。
```
$ git log
commit 516469e5c8766eed89ec1f1b9239948253f30ba7 (HEAD -> master, origin/master)
Author: ldr233 <1426727991@qq.com>
Date:   Wed Apr 11 00:01:48 2018 +0800

    learning git

commit 16a44b3d4aff6840bc28b27a54b14a9e8a1fb978
Author: ldr233 <1426727991@qq.com>
Date:   Tue Apr 10 23:53:48 2018 +0800

    commit training

commit df64c2978815a2e0f77270dd561eb6dcb890536e
Author: ldr233 <1426727991@qq.com>
Date:   Tue Apr 10 23:50:49 2018 +0800

    first commit

```
每次提交时，Git都会生成一个包含40个字符的独一无二的引用ID。它记录提交者，提交时间以及提交指定的信息。可用```git log --pretty=oneline```打印出更简单的版本：
```
$ git log --pretty=oneline
516469e5c8766eed89ec1f1b9239948253f30ba7 (HEAD -> master, origin/master) learning git
16a44b3d4aff6840bc28b27a54b14a9e8a1fb978 commit training
df64c2978815a2e0f77270dd561eb6dcb890536e first commit
```
指定显示两项最重要的信息：引用ID和提交信息。

#### 2.6 版本回退
在Git中，用```HEAD```表示当前版本，也就是最新的提交。
则上个版本表示为```HEAD^```,上两个版本为```HEAD^^```,上一百个版本表示为```HEAD~100```

使用```git reset```命令回退版本：
```
$ git reset --hard HEAD^
HEAD is now at ea34578 add distributed
```
查看是否已经回退
```
$ cat filename.txt
<文本内容>
```

通过前面所说的引用ID（前六位），重新返回最新版本
```
$ git reset --hard 3628164
HEAD is now at 3628164 <commit info>
```
此图显示了版本回退原理

![avatar](https://cdn.liaoxuefeng.com/cdn/files/attachments/001384907584977fc9d4b96c99f4b5f8e448fbd8589d0b2000/0)

![avatar](https://cdn.liaoxuefeng.com/cdn/files/attachments/001384907594057a873c79f14184b45a1a66b1509f90b7a000/0)

#### 2.6 查看每一次命令
命令```git reflog```
```
$ git reflog
516469e (HEAD -> master, origin/master) HEAD@{0}: commit: learning git
16a44b3 HEAD@{1}: commit: commit training
df64c29 HEAD@{2}: commit (initial): first commit

```
#### 2.7 工作区和版本库的关系（一图流）
![avatar](https://cdn.liaoxuefeng.com/cdn/files/attachments/001384907702917346729e9afbf4127b6dfbae9207af016000/0)

#### 2.8 撤销修改
用了```git status```会发现，它告诉了你可以用```git checkout -- filename.txt```在工作区的修改全部撤销
```
$ git checkout -- filename.txt
```
```git checkout -- file```命令中的```--```很重要，没有```--```，就变成了“切换到另一个分支”的命令，我们在后面的分支管理中会再次遇到```git checkout```命令。

#### 2.9 删除文件
一般情况下，你通常直接在文件管理器中把没用的文件删了，或者用```rm```命令删了：
```
$ rm filename.txt
```
这个时候，Git知道你删除了文件，因此，工作区和版本库就不一致了，```git status```命令会立刻告诉你哪些文件被删除了：
```
$ git status
# On branch master
# Changes not staged for commit:
#   (use "git add/rm <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#       deleted:    filename.txt
#
no changes added to commit (use "git add" and/or "git commit -a")
```

现在你有两个选择：  
1，从版本库删除文件，使用命令```git rm```,并提交修改。
```
$ git rm filename.txt
rm 'filename.txt'
$ git commit -m "filename.txt"
[master d17efd8] remove filename.txt
 1 file changed, 1 deletion(-)
 delete mode 100644 test.txt
 ```
 2，你是删错了，需要恢复，使用撤销修改命令  
 ```
 git checkout -- filename.txt
 ```
 ```git checkout```其实是用版本库里的版本替换工作区的版本，无论工作区是修改还是删除，都可以“一键还原”。
 
 
### 3 远程仓库
#### 3.1 将远程仓库和仓库链接
1，注册GitHub账号，并从右上点开“new repository”
2，填写相关信息后，得到sshkey
3，根据GitHub提示，在本地的仓库下运行命令
```
$ git remote add origin git@github.com:ldr233/learngit.git
```
添加后，远程库的名字就是```origin```，这是Git默认的叫法，也可以改成别的，但是```origin```这个名字一看就知道是远程库。

#### 3.2 将本地仓库内容推送至远程库上
把本地库的内容推送到远程，用```git push```命令，实际上是把当前分支master推送到远程。

由于远程库是空的，我们第一次推送```master```分支时，加上了```-u```参数，Git不但会把本地的master分支内容推送的远程新的master分支，还会把本地的master分支和远程的master分支关联起来，在以后的推送或者拉取时就可以简化命令。

推送成功后，可以立刻在GitHub页面中看到远程库的内容已经和本地一模一样。  

从现在起，只要本地作了提交，就可以通过命令：
```
$ git push origin master
```
把本地```master```分支的最新修改推送至GitHub。

#### 3.3 SSH警告
当你第一次使用Git的```clone```或者```push```命令连接GitHub时，会得到一个警告：
```
The authenticity of host 'github.com (xx.xx.xx.xx)' can't be established.
RSA key fingerprint is xx.xx.xx.xx.xx.
Are you sure you want to continue connecting (yes/no)?
```
这是因为Git使用SSH连接，而SSH连接在第一次验证GitHub服务器的Key时，需要你确认GitHub的Key的指纹信息是否真的来自GitHub的服务器，输```yes```回车即可。

Git会输出一个警告，告诉你已经把GitHub的Key添加到本机的一个信任列表里了：
```
Warning: Permanently added 'github.com' (RSA) to the list of known hosts.
```
这个警告只会出现一次，后面的操作就不会有任何警告了。