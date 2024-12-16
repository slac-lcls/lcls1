# data_test_access
Code to access big data xtc or other files from repository data_test deployed as /tmp/data_test

Command from repository git@github.com:slaclab/anarel-manage.git

bin/ana-rel-admin --force --cmd psana-conda-src --name 4.0.56 --basedir `pwd`

will clone data_test repo as
git clone git@github.com:lcls-psana/data_test /tmp/data_test

and code from data_test_access as regular psana repository:
git clone git@github.com:lcls-psana/data_test_access
