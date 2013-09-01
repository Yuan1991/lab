import os
import time
from config import main_sleep

while True:
    start = time.time()
    os.system('python test_acmer.py')
    end = time.time()
    print '\n+---------------------+'
    print '|sum cost time %5d s|' % (int(end-start))
    print '|sleep         %5d s|' % (int(main_sleep))
    print '+---------------------+\n'
    #time.sleep(main_sleep)
