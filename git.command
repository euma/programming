#git remote add origin git@git.com:euma/programming.git
git pull git@git.com:euma/programming.git
git push origin master #这里master可以不写
#git rm --cached 子模块文件夹名

#把你所关注的项目，下载到本地
git clone repository

#原作者的项目命名为upstream，方便以后长传更新！
git remote add upstream origin_repository

#删除对一个项目的简短命名
git remote rm shortName

#来查看远程项目的简短命名！
git remote -v

#把原作者对项目的最新修改版本下载下来，
#原作者的版本命名为upstream
git fetch upstream

#查看master分支的内容！
git checkout master

#把原作者的最新修改合并在你的本地项目中
git merge upstream/master
