import MySQLdb
from poj import poj
from hdoj import hdoj
from cf import cf
from config import mysql_conn
from config import update_poj
from config import update_hdoj
from config import update_cf
from threading import Timer
from multiprocessing import Process, Lock
from time import time


class acmer:

    def __init__(self):
        host = mysql_conn['host']
        user = mysql_conn['user']
        password = mysql_conn['password']
        conn=MySQLdb.connect(host=host,user=user,passwd=password)
        cur=conn.cursor()
        try:
            conn.select_db('acm_lab')
        except:
            print 'no database is acm_lab'
        self.conn = conn
        self.cur = cur


    def __log(self, oj='', name='', solved=''):
        s = '%6s, %10s, %6s' % (oj, name, solved)
        print s


    def update_poj(self):
        #1
        sql = 'select poj_name from acmer'
        self.cur.execute(sql)
        results=self.cur.fetchall()
        names = [result[0] for result in results]
        #2
        p = poj()
        name_solved = p.find_multi(names)
        #3
        solved_name = [(name_solved[name], name) for name in name_solved]
        print solved_name
        sql = 'update acmer set poj_solved=%s where poj_name=%s'
        self.cur.executemany(sql, solved_name)
        self.conn.commit()


    def update_hdoj(self):
        #1
        sql = 'select hdoj_name from acmer'
        self.cur.execute(sql)
        results=self.cur.fetchall()
        names = [result[0] for result in results]
        #2
        h = hdoj()
        name_solved = h.find_multi(names)
        #3
        solved_name = [(name_solved[name], name) for name in name_solved]
        print solved_name
        sql = 'update acmer set hdoj_solved=%s where hdoj_name=%s'
        self.cur.executemany(sql, solved_name)
        self.conn.commit()


    def update_cf(self):
        #1
        sql = 'select cf_name from acmer'
        self.cur.execute(sql)
        results=self.cur.fetchall()
        names = [result[0] for result in results]
        #2
        c = cf()
        name_solved = c.find_multi(names)
        #3
        solved_name = [(name_solved[name], name) for name in name_solved]
        print solved_name
        sql = 'update acmer set cf_rating=%s where cf_name=%s'
        self.cur.executemany(sql, solved_name)
        self.conn.commit()


    def update_sum_solved(self):
        #1 
        sql = 'select id, poj_solved, hdoj_solved from acmer'
        self.cur.execute(sql)
        results = self.cur.fetchall()
        now_day = int(time() / 86400)
        day29 = now_day % 30
        #2
        for line in results:
            id = line[0]
            poj_solved = line[1]
            hdoj_solved = line[2]
            sum_solved = poj_solved + hdoj_solved;
            sql = 'update sum_solved set day%s=%s where id=%s' % (day29, sum_solved, id)
            self.cur.execute(sql)
            self.conn.commit()


    def update_acmer_sum(self):
        #1
        sql = 'select * from sum_solved'
        self.cur.execute(sql)
        results = self.cur.fetchall()
        now_day = int(time() / 86400)
        day29 = now_day % 30
        day0 = (day29+1) % 30
        #2
        for line in results:
            id = line[0]
            days = [line[i] for i in range(1,31)]
            new_days = [days[(day0+i)%30] for i in range(0,30)]
            for i in range(1, 30):
                if new_days[i] < new_days[i-1]:
                    new_days[i] = new_days[i-1]
            every_day = [new_days[0]]
            for i in range(1, 30):
                every_day.append(new_days[i]-new_days[i-1])
            every_day_28 = every_day[2:30]
            sum30 = str(sum(every_day_28))
            #hack Orz == 40
            if id == 14:
                sum30 = '40'
            sql = 'update acmer set sum30="%s" where id="%s"' % (sum30, id)
            self.cur.execute(sql)
            sum_solved = ''
            for i in range(0, 28):
                sum_solved += str(every_day_28[i])
                if i != 27:
                    sum_solved += ','
            sql = 'update acmer set sum_solved="%s" where id=%s' % (sum_solved, id)
            self.cur.execute(sql)
            self.conn.commit()


    def update_mac(self):
        f = file('../mac/mac4.txt')
        sql = 'update acmer set online=0'
        self.cur.execute(sql)
        while True:
            line = f.readline()
            if len(line) == 0:
                break
            mac = str(line[0:-1])
            #1
            sql = 'select id, last_time, sum_time from acmer where mac="%s"' % (mac)
            self.cur.execute(sql)
            result = self.cur.fetchall()
            if result == ():
                continue
            #2
            result = result[0]
            print result
            id = result[0]
            print id
            sql = 'update acmer set online=1 where id=%s' % (id)
            self.cur.execute(sql)
            self.conn.commit()
            #3
            last_time = int(result[1])
            sum_time = int(result[2])
            now_time = int(time()/420)
            if last_time == now_time:
                continue
            now_time = str(now_time)
            sql = 'update acmer set last_time=%s where id=%s' % (now_time, id)
            self.cur.execute(sql)
            sum_time = str(7 + sum_time)
            sql = 'update acmer set sum_time=%s where id=%s' % (sum_time, id)
            self.cur.execute(sql)
            self.conn.commit()


    def update_all(self):
        if update_cf == True:
            self.update_cf()
        if update_poj == True:
            self.update_poj()
        if update_hdoj == True:
            self.update_hdoj()
        self.update_sum_solved()
        self.update_acmer_sum()
        self.update_mac()


    def __del__(self):
        self.cur.close()
        self.conn.close()


